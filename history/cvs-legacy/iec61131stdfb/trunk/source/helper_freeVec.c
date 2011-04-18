/*
*	Copyright (C) 2011
*	Chair of Process Control Engineering,
*	Aachen University of Technology.
*	All rights reserved.
*
*	Redistribution and use in source and binary forms, with or without
*	modification, are permitted provided that the following conditions
*	are met:
*	1. Redistributions of source code must retain the above copyright
*	   notice, this list of conditions and the following disclaimer.
*	2. Redistributions in binary form must print or display the above
*	   copyright notice either during startup or must have a means for
*	   the user to view the copyright notice.
*	3. Redistributions in binary form must reproduce the above copyright
*	   notice, this list of conditions and the following disclaimer in
*		the documentation and/or other materials provided with the
*		distribution.
*	4. Neither the name of the Chair of Process Control Engineering nor
*		the name of the Aachen University of Technology may be used to
*		endorse or promote products derived from this software without
*		specific prior written permission.
*
*	THIS SOFTWARE IS PROVIDED BY THE CHAIR OF PROCESS CONTROL ENGINEERING
*	``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE CHAIR OF
*	PROCESS CONTROL ENGINEERING BE LIABLE FOR ANY DIRECT, INDIRECT,
*	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*	BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
*	OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
*	AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*	LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
*	WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*	POSSIBILITY OF SUCH DAMAGE.
*/
/******************************************************************************
*
*   FILE
*   ----
*   helper_freeVec.c
*
*   History
*   -------
*   2010-11-03   File created
*
*******************************************************************************
*
*   This file is generated by the 'fb_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_iec61131stdfb
#define OV_COMPILE_LIBRARY_iec61131stdfb
#endif



#include "iec61131stdfb.h"
#include "fb.h"
#include "libov/ov_ov.h"
#include "libov/ov_macros.h"

OV_RESULT iec61131stdfb_freeVec(OV_ANY* pobj)
{
	unsigned int i;
	OV_RESULT res = OV_ERR_OK;
	
	switch(pobj->value.vartype & OV_VT_KSMASK) {
		case OV_VT_BYTE_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_byte_vec, NULL, 0, BYTE);
		break;
		case OV_VT_BOOL_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_bool_vec, NULL, 0, BOOL);
		break;
		case OV_VT_INT_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_int_vec, NULL, 0, INT);
		break;
		case OV_VT_UINT_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_uint_vec, NULL, 0, UINT);
		break;
		case OV_VT_SINGLE_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_single_vec, NULL, 0, SINGLE);
		break;
		case OV_VT_DOUBLE_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_double_vec, NULL, 0, DOUBLE);
		break;
		case OV_VT_STRING_VEC:
			for(i=0; i<pobj->value.valueunion.val_string_vec.veclen; i++)
				ov_string_setvalue(&pobj->value.valueunion.val_string_vec.value[i], "");
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_string_vec, NULL, 0, STRING);
		break;
		case OV_VT_TIME_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_time_vec, NULL, 0, TIME);
		break;
		case OV_VT_TIME_SPAN_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_time_span_vec, NULL, 0, TIME_SPAN);
		break;
		case OV_VT_STATE_VEC:
			res = Ov_SetDynamicVectorValue(&pobj->value.valueunion.val_state_vec, NULL, 0, STATE);
		break;
		case OV_VT_STRING:
			res = ov_string_setvalue(&pobj->value.valueunion.val_string, "");
		break;
		}
		pobj->value.valueunion.val_double = 0;
		
		return res;
}