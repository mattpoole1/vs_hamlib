/*
 *  Hamlib Rotator backend - M2 RC2800
 *
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License, or (at your option) any later version.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

#include "hamlib/rotator.h"
#include "serial.h"
#include "misc.h"
#include "register.h"
#include "num_stdio.h"

#include "rc2800.h"

#define CR "\x0d"
#define LF "\x0a"
#define SC ";"

#define BUFSZ 128

/*
  The continuous output of some of the RC2800
  models can be a nuisance.  Even if we flush
  the input stream before sending the command,
  there may be partial sentence in the stream
  ahead of the data we want.

*/


/*rc2800_parse

  Parse output from the rotator controller 
  We want to recognise the following format:
  IS<fff.f>
  Where I = ID Byte and can take the values:
    A = Azimuth controller
    E = Elevation controller
    Note: These ID Bytes can be changed in the M2    
          Setup Utility
  Where S = Status Byte and can take the values:
    S = Stopped / Idle
    R = Running (Motor in motion)
    C = Calibration in Process
    O = Offline (Controller not in Mode 0)
    E = Error
  Where <ff.f> is the floating point heading value in   
  degrees (Azimuth) or decidegrees (Elevation) (12.5 
  degrees = 125)

  Written by Matt Poole 9th April 2018 to replace 
  rc2800_parse given by Hamlib for the amateur RC2800 
  M2 Positioner
*/

static int rc2800_parse (char *s, char *device, char *state, float *value) 
{
  int i;
  rig_debug(RIG_DEBUG_TRACE, "%s: device return->%s", __func__, s);
  int len = strlen(s);
  if (len ==0 ) 
  {
    return -RIG_EPROTO;
  } 

  if (len > 5)
  {
    if (*s == 'A' || *s == 'E')
    {
      *device = *s;

      if (s[1] == 'E')
      {
         return -RIG_EINVAL;
      }
      *state = s[1];
      i = num_sscanf(s+2, "%f", value);
      if (i == ';' || i == EOF)
      {
        return -RIG_EINVAL;
      }
      rig_debug(RIG_DEBUG_TRACE, "%s: device=%c state =%c value=%3.1f\n", __func__, *device, *state, *value);
      return RIG_OK;     

    } 
  }
  return -RIG_EPROTO;
 
}

/**
 * rc2800_transaction
 *
 * cmdstr - Command to be sent to the rig.
 * data - Buffer for reply string.  Can be NULL, indicating that no reply is
 *        is needed, but answer will still be read.
 * data_len - in: Size of buffer. It is the caller's responsibily to provide
 *            a large enough buffer for all possible replies for a command.
 *
 * returns:
 *   RIG_OK  -  if no error occured.
 *   RIG_EIO  -  if an I/O error occured while sending/receiving data.
 *   RIG_ETIMEOUT  -  if timeout expires without any characters received.
 */
static int
rc2800_transaction (ROT *rot, const char *cmdstr,
                    char *data, size_t data_len)
{
    struct rot_state *rs;
    int retval;
    int retry_read = 0;
    char replybuf[BUFSZ];

    rs = &rot->state;

transaction_write:
    rig_debug(RIG_DEBUG_TRACE, "Entered transaction_write\n");
    rig_debug(RIG_DEBUG_TRACE, "Value of RIG_OK: %d\n", RIG_OK);
    serial_flush(&rs->rotport);

    if (cmdstr) {
        rig_debug(RIG_DEBUG_TRACE, "Happy with cmdstr: %s\n", cmdstr);
        retval = write_block(&rs->rotport, cmdstr, strlen(cmdstr));
        rig_debug(RIG_DEBUG_TRACE, "Transmission returned: %d\n", retval);
        if (retval != RIG_OK)
            /*Not getting here - good*/
            goto transaction_quit;
    }

    /* Always read the reply to know whether the cmd went OK */
    if (!data)
        data = replybuf;
    if (!data_len)
        data_len = BUFSZ;


    memset(data,0,data_len);
    rig_debug(RIG_DEBUG_TRACE, "Data is: %s and data length is: %d\n", data, data_len);
    retval = read_string(&rs->rotport, data, data_len, SC, strlen(SC));
    rig_debug(RIG_DEBUG_TRACE, "Read String and got return value: %d\n", retval);
    if (retval < 0 && retval != -5) {
        if (retry_read++ < rot->state.rotport.retry)
            goto transaction_write;
        goto transaction_quit;
    }

    retval = RIG_OK;
transaction_quit:
    return retval;
}


static int
rc2800_rot_set_az(ROT *rot, azimuth_t az, elevation_t el)
{
  char cmdstr[64];
  int retval1;
  rig_debug(RIG_DEBUG_TRACE, "%s called: %f %f\n", __func__, az);
  
  num_sprintf(cmdstr, "APn%3.1f\r"SC, az);
  rig_debug(RIG_DEBUG_TRACE, "Happy with cmdstr: %s\n", cmdstr);
  retval1 = rc2800_transaction(rot, cmdstr, NULL, 0);
  
  return (retval1);
}

static int
rc2800_rot_set_el(ROT *rot, azimuth_t az, elevation_t el)
{
  char cmdstr[64];
  int retval1;
  rig_debug(RIG_DEBUG_TRACE, "%s called: %f %f\n", __func__, el);
  
  num_sprintf(cmdstr, "APn%3.1f\r"SC, el);
  rig_debug(RIG_DEBUG_TRACE, "Happy with cmdstr: %s\n", cmdstr);
  retval1 = rc2800_transaction(rot, cmdstr, NULL, 0);
  
  return (retval1);
}

static int
rc2800_rot_get_az(ROT *rot, azimuth_t *az)
{
  char posbuf[32];
  int retval;
  char device;
  char state;
  float value;
  rig_debug(RIG_DEBUG_TRACE, "%s called\n", __func__);
  retval = rc2800_transaction(rot, "Bin" SC, posbuf, sizeof(posbuf));
  if (retval != RIG_OK || strlen(posbuf) < 5) {
    rig_debug(RIG_DEBUG_TRACE, "Returned value of rc2800_transaction: %s\n", retval);
    return retval < 0 ? retval : -RIG_EPROTO;
  }

  if (rc2800_parse(posbuf, &device, &state, &value) == RIG_OK) {
    if (device == 'A'){
      *az = (azimuth_t) value;
    }
    else
      return -RIG_EPROTO;
  }

  rig_debug(RIG_DEBUG_TRACE, "%s: az = %.1f\n",
            __func__, *az);

  return RIG_OK;
}

static int
rc2800_rot_get_el(ROT *rot, azimuth_t *az, elevation_t *el)
{
  char posbuf[32];
  int retval;
  char device;
  char state;
  float value;
  rig_debug(RIG_DEBUG_TRACE, "%s called\n", __func__);
  retval = rc2800_transaction(rot, "Bin" SC, posbuf, sizeof(posbuf));
  if (retval != RIG_OK || strlen(posbuf) < 5) {
    rig_debug(RIG_DEBUG_TRACE, "Returned value of rc2800_transaction: %s\n", retval);
    return retval < 0 ? retval : -RIG_EPROTO;
  }

  if (rc2800_parse(posbuf, &device, &state, &value) == RIG_OK) {
    if (device == 'E'){
      *el = (elevation_t) value;
      *az = (azimuth_t) 0.0;
    }
    else
      return -RIG_EPROTO;
  }

  rig_debug(RIG_DEBUG_TRACE, "%s: el = %.1f\n",
            __func__, *el);

  return RIG_OK;
}

static int
rc2800_rot_get_status(ROT *rot, status_t *status)
{
  char posbuf[32];
  int retval;
  char device;
  char state;
  float value;
  rig_debug(RIG_DEBUG_TRACE, "%s called\n", __func__);
  retval = rc2800_transaction(rot, "Bin" SC, posbuf, sizeof(posbuf));
  if (retval != RIG_OK || strlen(posbuf) < 5) {
    rig_debug(RIG_DEBUG_TRACE, "Returned value of rc2800_transaction: %s\n", retval);
    return retval < 0 ? retval : -RIG_EPROTO;
  }

  if (rc2800_parse(posbuf, &device, &state, &value) == RIG_OK) {
    if ((device == 'E') || (device == 'A')){
      *status = (status_t) state;
      
    }
    else
      return -RIG_EPROTO;
  }

  rig_debug(RIG_DEBUG_TRACE, "%s: State = %c\n",
            __func__, *status);
  
  return RIG_OK;
}
static int
rc2800_rot_calibrate(ROT *rot)
{
  int retval;
  rig_debug(RIG_DEBUG_TRACE, "%s called\n", __func__);
  retval = rc2800_transaction(rot, "C1n"SC, NULL, 0);
  return retval;
}

static int
rc2800_rot_stop(ROT *rot)
{
  int retval;

  rig_debug(RIG_DEBUG_TRACE, "%s called\n", __func__);

  /* TODO: check each return value (do we care?) */

  /* Stop AZ*/
  retval = rc2800_transaction(rot, "A" CR, NULL, 0); /* select AZ */
  retval = rc2800_transaction(rot, "S" CR, NULL, 0); /* STOP */

  /* do not overwhelm the MCU? */
  usleep(200*1000);

  /* Stop EL*/
  retval = rc2800_transaction(rot, "E" CR, NULL, 0); /* select EL */
  retval = rc2800_transaction(rot, "S" CR, NULL, 0); /* STOP */

  return retval;
}




/* ************************************************************************* */
/*
 * M2 RC2800 rotator capabilities.
 *
 * Protocol documentation: http://www.confluentdesigns.com/files/PdfFiles/devguide_24.pdf
 */

const struct rot_caps rc2800_az_rot_caps = {
  .rot_model =      ROT_MODEL_RC2800_AZ,
  .model_name =     "RC2800 Az",
  .mfg_name =       "M2",
  .version =        "0.1.1",
  .copyright = 	    "LGPL",
  .status =         RIG_STATUS_BETA,
  .rot_type =       ROT_TYPE_AZEL,
  .port_type =      RIG_PORT_SERIAL,
  .serial_rate_min  = 9600,
  .serial_rate_max  = 9600,
  .serial_data_bits = 8,
  .serial_stop_bits = 1,
  .serial_parity    = RIG_PARITY_NONE,
  .serial_handshake = RIG_HANDSHAKE_NONE,
  .write_delay      = 0,
  .post_write_delay = 0,
  .timeout          = 1000,
  .retry            = 3,

  .min_az = 	0.0,
  .max_az =  	360.0,
  .min_el = 	0.0,
  .max_el =  	90.0,
  
  .get_position = rc2800_rot_get_az,
  .set_position = rc2800_rot_set_az,
  .calibrate    = rc2800_rot_calibrate,
  .get_status   = rc2800_rot_get_status,
  .stop         = rc2800_rot_stop,
};

const struct rot_caps rc2800_el_rot_caps = {
  .rot_model =      ROT_MODEL_RC2800_EL,
  .model_name =     "RC2800 El",
  .mfg_name =       "M2",
  .version =        "0.1.1",
  .copyright = 	    "LGPL",
  .status =         RIG_STATUS_BETA,
  .rot_type =       ROT_TYPE_AZEL,
  .port_type =      RIG_PORT_SERIAL,
  .serial_rate_min  = 9600,
  .serial_rate_max  = 9600,
  .serial_data_bits = 8,
  .serial_stop_bits = 1,
  .serial_parity    = RIG_PARITY_NONE,
  .serial_handshake = RIG_HANDSHAKE_NONE,
  .write_delay      = 0,
  .post_write_delay = 0,
  .timeout          = 1000,
  .retry            = 3,

  .min_az = 	0.0,
  .max_az =  	360.0,
  .min_el = 	0.0,
  .max_el =  	90.0,

  .get_position = rc2800_rot_get_el,
  .set_position = rc2800_rot_set_el,
  .calibrate    = rc2800_rot_calibrate,
  .get_status   = rc2800_rot_get_status,
  .stop         = rc2800_rot_stop,
};

/* ************************************************************************* */

DECLARE_INITROT_BACKEND(m2)
{
  rig_debug(RIG_DEBUG_VERBOSE, "%s called\n", __FUNCTION__);

  rot_register(&rc2800_az_rot_caps);
  rot_register(&rc2800_el_rot_caps);

  return RIG_OK;
}

/* ************************************************************************* */
/* end of file */

