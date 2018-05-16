%/*
% *  Hamlib Interface - RPC definitions
% *  Copyright (c) 2000-2002 by Stephane Fillod and Frank Singleton
% *  Contributed by Francois Retief <fgretief@sun.ac.za>
% *
% *
% *   This library is free software; you can redistribute it and/or
% *   modify it under the terms of the GNU Lesser General Public
% *   License as published by the Free Software Foundation; either
% *   version 2.1 of the License, or (at your option) any later version.
% *
% *   This library is distributed in the hope that it will be useful,
% *   but WITHOUT ANY WARRANTY; without even the implied warranty of
% *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
% *   Lesser General Public License for more details.
% *
% *   You should have received a copy of the GNU Lesser General Public
% *   License along with this library; if not, write to the Free Software
% *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
% *
% */

% #if (__GNUC__ == 4 && 3 <= __GNUC_MINOR__) || 4 < __GNUC__
% /* rpcgen produces code containing unused variables.  hush that... */
% # pragma GCC diagnostic ignored "-Wunused-variable"
% #endif

/* This gets stuffed into the source files. */
#if RPC_HDR
%#ifdef HAVE_CONFIG_H
%#include "config.h"
%#endif
%#include <rpc/xdr.h>
%#include <hamlib/rotator.h>
#endif

%#if __APPLE__
%static int _rpcsvcdirty;
%#endif

/* ************************************************************************* */

typedef unsigned int model_x;
typedef float azimuth_x;
typedef float elevation_x;
typedef unsigned int rot_reset_x;

/* ************************************************************************* */

struct position_arg {
	azimuth_x az;
	elevation_x el;
};

struct move_s {
    int direction;
    int speed;
};

/* ************************************************************************* */

struct position_s {
	azimuth_x az;
	elevation_x el;
};
union position_res switch (int rotstatus) {
case 0:
	position_s pos;
default:
	void;
};

/* ************************************************************************* */

struct rotstate_s {
	azimuth_x az_min;
	azimuth_x az_max;
	elevation_x el_min;
	elevation_x el_max;
};
union rotstate_res switch (int rotstatus) {
case 0:
	rotstate_s state;
default:
	void;
};

/* ************************************************************************* */

program ROTPROG {
	version ROTVERS {
		model_x GETMODEL(void) = 1;
		rotstate_res GETROTSTATE(void) = 3;

		int SETPOSITION(position_s) = 10;
		position_res GETPOSITION(void) = 11;
		int STOP(void) = 12;
		int RESET(rot_reset_x) = 13;
		int PARK(void) = 14;
        int MOVE(move_s) = 15;
	} = 1;
} = 0x20000999;

/* ************************************************************************* */
/* end of file */

