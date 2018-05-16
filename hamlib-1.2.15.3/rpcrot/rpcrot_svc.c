/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "rpcrot.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif
/*
 *  Hamlib Interface - RPC definitions
 *  Copyright (c) 2000-2002 by Stephane Fillod and Frank Singleton
 *  Contributed by Francois Retief <fgretief@sun.ac.za>
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
#if __APPLE__
static int _rpcsvcdirty;
#endif

void
rotprog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		position_s setposition_1_arg;
		rot_reset_x reset_1_arg;
		move_s move_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case GETMODEL:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_model_x;
		local = (char *(*)(char *, struct svc_req *)) getmodel_1_svc;
		break;

	case GETROTSTATE:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_rotstate_res;
		local = (char *(*)(char *, struct svc_req *)) getrotstate_1_svc;
		break;

	case SETPOSITION:
		_xdr_argument = (xdrproc_t) xdr_position_s;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) setposition_1_svc;
		break;

	case GETPOSITION:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_position_res;
		local = (char *(*)(char *, struct svc_req *)) getposition_1_svc;
		break;

	case STOP:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) stop_1_svc;
		break;

	case RESET:
		_xdr_argument = (xdrproc_t) xdr_rot_reset_x;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) reset_1_svc;
		break;

	case PARK:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) park_1_svc;
		break;

	case MOVE:
		_xdr_argument = (xdrproc_t) xdr_move_s;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) move_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}