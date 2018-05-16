/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpcrig.h"
/*
 *  Hamlib Interface - RPC definitions
 *  Copyright (c) 2000-2002 by Stephane Fillod and Frank Singleton
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
 #if (5 == 4 && 3 <= 4) || 4 < 5
 /* rpcgen produces code containing unused variables.  hush that... */
 # pragma GCC diagnostic ignored "-Wunused-variable"
 #endif

bool_t
xdr_model_x (XDR *xdrs, model_x *objp)
{
	register int32_t *buf;

	 if (!xdr_u_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_vfo_x (XDR *xdrs, vfo_x *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_freq_x (XDR *xdrs, freq_x *objp)
{
	register int32_t *buf;

	 if (!xdr_double (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_rmode_x (XDR *xdrs, rmode_x *objp)
{
	register int32_t *buf;

	 if (!xdr_u_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_pbwidth_x (XDR *xdrs, pbwidth_x *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_split_x (XDR *xdrs, split_x *objp)
{
	register int32_t *buf;

	 if (!xdr_u_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ptt_x (XDR *xdrs, ptt_x *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_dcd_x (XDR *xdrs, dcd_x *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_vfo_op_x (XDR *xdrs, vfo_op_x *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_shortfreq_x (XDR *xdrs, shortfreq_x *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_setting_x (XDR *xdrs, setting_x *objp)
{
	register int32_t *buf;

	 if (!xdr_u_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ant_x (XDR *xdrs, ant_x *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ann_x (XDR *xdrs, ann_x *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_rptr_shift_x (XDR *xdrs, rptr_shift_x *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_tone_x (XDR *xdrs, tone_x *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_scan_x (XDR *xdrs, scan_x *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_reset_x (XDR *xdrs, reset_x *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_powerstat_x (XDR *xdrs, powerstat_x *objp)
{
	register int32_t *buf;

	 if (!xdr_long (xdrs, objp))
		 return FALSE;
	return TRUE;
}
#if __APPLE__
static int _rpcsvcdirty;
#endif

bool_t
xdr_mode_s (XDR *xdrs, mode_s *objp)
{
	register int32_t *buf;

	 if (!xdr_rmode_x (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_pbwidth_x (xdrs, &objp->width))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_value_s (XDR *xdrs, value_s *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->i))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->f))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_freq_arg (XDR *xdrs, freq_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_freq_x (xdrs, &objp->freq))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_freq_res (XDR *xdrs, freq_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_freq_x (xdrs, &objp->freq_res_u.freq))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_mode_arg (XDR *xdrs, mode_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_mode_s (xdrs, &objp->mw))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_mode_res (XDR *xdrs, mode_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_mode_s (xdrs, &objp->mode_res_u.mw))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_vfo_res (XDR *xdrs, vfo_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_vfo_x (xdrs, &objp->vfo_res_u.vfo))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_powerstat_res (XDR *xdrs, powerstat_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_powerstat_x (xdrs, &objp->powerstat_res_u.powerstat))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_split_arg (XDR *xdrs, split_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_split_x (xdrs, &objp->split))
		 return FALSE;
	 if (!xdr_vfo_x (xdrs, &objp->tx_vfo))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_split_res (XDR *xdrs, split_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_split_arg (xdrs, &objp->split_res_u.split))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_ptt_arg (XDR *xdrs, ptt_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_ptt_x (xdrs, &objp->ptt))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ptt_res (XDR *xdrs, ptt_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_ptt_x (xdrs, &objp->ptt_res_u.ptt))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_dcd_res (XDR *xdrs, dcd_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_dcd_x (xdrs, &objp->dcd_res_u.dcd))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_setting_arg (XDR *xdrs, setting_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->setting))
		 return FALSE;
	 if (!xdr_value_s (xdrs, &objp->val))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_val_res (XDR *xdrs, val_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_value_s (xdrs, &objp->val_res_u.val))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_vfo_op_arg (XDR *xdrs, vfo_op_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_vfo_op_x (xdrs, &objp->vfo_op))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_rptrshift_res (XDR *xdrs, rptrshift_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_rptr_shift_x (xdrs, &objp->rptrshift_res_u.rptrshift))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_rptrshift_arg (XDR *xdrs, rptrshift_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_rptr_shift_x (xdrs, &objp->rptrshift))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_shortfreq_res (XDR *xdrs, shortfreq_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_shortfreq_x (xdrs, &objp->shortfreq_res_u.shortfreq))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_shortfreq_arg (XDR *xdrs, shortfreq_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_shortfreq_x (xdrs, &objp->shortfreq))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_tone_res (XDR *xdrs, tone_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_tone_x (xdrs, &objp->tone_res_u.tone))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_tone_arg (XDR *xdrs, tone_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_tone_x (xdrs, &objp->tone))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ant_res (XDR *xdrs, ant_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_ant_x (xdrs, &objp->ant_res_u.ant))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_ant_arg (XDR *xdrs, ant_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_ant_x (xdrs, &objp->ant))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_ch_res (XDR *xdrs, ch_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_int (xdrs, &objp->ch_res_u.ch))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_ch_arg (XDR *xdrs, ch_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ch))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_scan_s (XDR *xdrs, scan_s *objp)
{
	register int32_t *buf;

	 if (!xdr_scan_x (xdrs, &objp->scan))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ch))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_scan_res (XDR *xdrs, scan_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_scan_s (xdrs, &objp->scan_res_u.scan))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

bool_t
xdr_scan_arg (XDR *xdrs, scan_arg *objp)
{
	register int32_t *buf;

	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_scan_x (xdrs, &objp->scan))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ch))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_freq_range_s (XDR *xdrs, freq_range_s *objp)
{
	register int32_t *buf;

	 if (!xdr_freq_x (xdrs, &objp->start))
		 return FALSE;
	 if (!xdr_freq_x (xdrs, &objp->end))
		 return FALSE;
	 if (!xdr_rmode_x (xdrs, &objp->modes))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->low_power))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->high_power))
		 return FALSE;
	 if (!xdr_vfo_x (xdrs, &objp->vfo))
		 return FALSE;
	 if (!xdr_ant_x (xdrs, &objp->ant))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_tuning_step_s (XDR *xdrs, tuning_step_s *objp)
{
	register int32_t *buf;

	 if (!xdr_rmode_x (xdrs, &objp->modes))
		 return FALSE;
	 if (!xdr_shortfreq_x (xdrs, &objp->ts))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_filter_s (XDR *xdrs, filter_s *objp)
{
	register int32_t *buf;

	 if (!xdr_rmode_x (xdrs, &objp->modes))
		 return FALSE;
	 if (!xdr_pbwidth_x (xdrs, &objp->width))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_channel_cap_x (XDR *xdrs, channel_cap_x *objp)
{
	register int32_t *buf;

	 if (!xdr_u_int (xdrs, &objp->caps))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->funcs))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->levels))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_chan_s (XDR *xdrs, chan_s *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->start))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->end))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->type))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->start);
		IXDR_PUT_LONG(buf, objp->end);
		IXDR_PUT_U_LONG(buf, objp->type);
		}
		 if (!xdr_channel_cap_x (xdrs, &objp->mem_caps))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->start))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->end))
				 return FALSE;
			 if (!xdr_u_int (xdrs, &objp->type))
				 return FALSE;

		} else {
		objp->start = IXDR_GET_LONG(buf);
		objp->end = IXDR_GET_LONG(buf);
		objp->type = IXDR_GET_U_LONG(buf);
		}
		 if (!xdr_channel_cap_x (xdrs, &objp->mem_caps))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->start))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->end))
		 return FALSE;
	 if (!xdr_u_int (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_channel_cap_x (xdrs, &objp->mem_caps))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_rigstate_s (XDR *xdrs, rigstate_s *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_int (xdrs, &objp->itu_region))
			 return FALSE;
		 if (!xdr_shortfreq_x (xdrs, &objp->max_rit))
			 return FALSE;
		 if (!xdr_shortfreq_x (xdrs, &objp->max_xit))
			 return FALSE;
		 if (!xdr_shortfreq_x (xdrs, &objp->max_ifshift))
			 return FALSE;
		 if (!xdr_ann_x (xdrs, &objp->announces))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_get_func))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_set_func))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_get_level))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_set_level))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_get_parm))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_set_parm))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( MAXDBLSTSIZ  + MAXDBLSTSIZ ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->preamp, MAXDBLSTSIZ,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->attenuator, MAXDBLSTSIZ,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->preamp;
				i < MAXDBLSTSIZ; ++i) {
				IXDR_PUT_LONG(buf, *genp++);
			}
		}
		{
			register int *genp;

			for (i = 0, genp = objp->attenuator;
				i < MAXDBLSTSIZ; ++i) {
				IXDR_PUT_LONG(buf, *genp++);
			}
		}
		}
		 if (!xdr_vector (xdrs, (char *)objp->rx_range_list, FRQRANGESIZ,
			sizeof (freq_range_s), (xdrproc_t) xdr_freq_range_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->tx_range_list, FRQRANGESIZ,
			sizeof (freq_range_s), (xdrproc_t) xdr_freq_range_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->tuning_steps, TSLSTSIZ,
			sizeof (tuning_step_s), (xdrproc_t) xdr_tuning_step_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->filters, FLTLSTSIZ,
			sizeof (filter_s), (xdrproc_t) xdr_filter_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->chan_list, CHANLSTSIZ,
			sizeof (chan_s), (xdrproc_t) xdr_chan_s))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_int (xdrs, &objp->itu_region))
			 return FALSE;
		 if (!xdr_shortfreq_x (xdrs, &objp->max_rit))
			 return FALSE;
		 if (!xdr_shortfreq_x (xdrs, &objp->max_xit))
			 return FALSE;
		 if (!xdr_shortfreq_x (xdrs, &objp->max_ifshift))
			 return FALSE;
		 if (!xdr_ann_x (xdrs, &objp->announces))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_get_func))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_set_func))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_get_level))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_set_level))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_get_parm))
			 return FALSE;
		 if (!xdr_setting_x (xdrs, &objp->has_set_parm))
			 return FALSE;
		buf = XDR_INLINE (xdrs, ( MAXDBLSTSIZ  + MAXDBLSTSIZ ) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_vector (xdrs, (char *)objp->preamp, MAXDBLSTSIZ,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->attenuator, MAXDBLSTSIZ,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;

		} else {
		{
			register int *genp;

			for (i = 0, genp = objp->preamp;
				i < MAXDBLSTSIZ; ++i) {
				*genp++ = IXDR_GET_LONG(buf);
			}
		}
		{
			register int *genp;

			for (i = 0, genp = objp->attenuator;
				i < MAXDBLSTSIZ; ++i) {
				*genp++ = IXDR_GET_LONG(buf);
			}
		}
		}
		 if (!xdr_vector (xdrs, (char *)objp->rx_range_list, FRQRANGESIZ,
			sizeof (freq_range_s), (xdrproc_t) xdr_freq_range_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->tx_range_list, FRQRANGESIZ,
			sizeof (freq_range_s), (xdrproc_t) xdr_freq_range_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->tuning_steps, TSLSTSIZ,
			sizeof (tuning_step_s), (xdrproc_t) xdr_tuning_step_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->filters, FLTLSTSIZ,
			sizeof (filter_s), (xdrproc_t) xdr_filter_s))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->chan_list, CHANLSTSIZ,
			sizeof (chan_s), (xdrproc_t) xdr_chan_s))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->itu_region))
		 return FALSE;
	 if (!xdr_shortfreq_x (xdrs, &objp->max_rit))
		 return FALSE;
	 if (!xdr_shortfreq_x (xdrs, &objp->max_xit))
		 return FALSE;
	 if (!xdr_shortfreq_x (xdrs, &objp->max_ifshift))
		 return FALSE;
	 if (!xdr_ann_x (xdrs, &objp->announces))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->has_get_func))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->has_set_func))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->has_get_level))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->has_set_level))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->has_get_parm))
		 return FALSE;
	 if (!xdr_setting_x (xdrs, &objp->has_set_parm))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->preamp, MAXDBLSTSIZ,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->attenuator, MAXDBLSTSIZ,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->rx_range_list, FRQRANGESIZ,
		sizeof (freq_range_s), (xdrproc_t) xdr_freq_range_s))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->tx_range_list, FRQRANGESIZ,
		sizeof (freq_range_s), (xdrproc_t) xdr_freq_range_s))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->tuning_steps, TSLSTSIZ,
		sizeof (tuning_step_s), (xdrproc_t) xdr_tuning_step_s))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->filters, FLTLSTSIZ,
		sizeof (filter_s), (xdrproc_t) xdr_filter_s))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->chan_list, CHANLSTSIZ,
		sizeof (chan_s), (xdrproc_t) xdr_chan_s))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_rigstate_res (XDR *xdrs, rigstate_res *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->rigstatus))
		 return FALSE;
	switch (objp->rigstatus) {
	case 0:
		 if (!xdr_rigstate_s (xdrs, &objp->rigstate_res_u.state))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}