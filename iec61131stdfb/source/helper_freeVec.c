/*
*   Copyright (C) 2011
*   Chair of Process Control Engineering,
*   D-52056 Aachen, Germany.
*   All rights reserved.
*
*
*   This file is part of the ACPLT/OV Package 
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*
*       http://www.apache.org/licenses/LICENSE-2.0
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
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
#include "ov_ov.h"
#include "ov_macros.h"

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