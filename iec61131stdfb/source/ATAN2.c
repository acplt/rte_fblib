/*
*   Copyright (C) 2010
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
*   ATAN2.c
*
*   History
*   -------
*   2010-11-23   File created
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
#include "stdfb_macros.h"
#include "ov_macros.h"
#include "ov_logfile.h"
#include "helper.h"


#include <math.h>


OV_RESULT
iec61131stdfb_ATAN2_setType
(OV_INSTPTR_iec61131stdfb_ATAN2 pobj, OV_VAR_TYPE type)
{
  if (iec61131stdfb_isConnected (Ov_PtrUpCast (fb_functionblock, pobj)))
    return OV_ERR_NOACCESS;
  else
  {
    switch(type & OV_VT_KSMASK)
	{
		case OV_VT_INT:
		case OV_VT_UINT:
		case OV_VT_BYTE:
		case OV_VT_SINGLE:
			pobj->v_IN1.value.vartype = type;
			pobj->v_IN2.value.vartype = type;
			pobj->v_OUT.value.vartype = OV_VT_SINGLE;
			return OV_ERR_OK;
		case OV_VT_INT_VEC:
		case OV_VT_UINT_VEC:
		case OV_VT_BYTE_VEC:
		case OV_VT_SINGLE_VEC:
			pobj->v_IN1.value.vartype = type;
			pobj->v_IN2.value.vartype = type;
			pobj->v_OUT.value.vartype = OV_VT_SINGLE_VEC;
			return OV_ERR_OK;
		case OV_VT_DOUBLE:
		case OV_VT_DOUBLE_VEC:
			pobj->v_IN1.value.vartype = type;
			pobj->v_IN2.value.vartype = type;
			pobj->v_OUT.value.vartype = type;
			return OV_ERR_OK;

		default:
			return OV_ERR_BADPARAM;
	}
		return OV_ERR_GENERIC;
  }
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ATAN2_IN1_set(
    OV_INSTPTR_iec61131stdfb_ATAN2          pobj,
    const OV_ANY*  value
) {
    OV_RESULT res;
  
	  if ((value->value.vartype & OV_VT_KSMASK) == (pobj->v_IN1.value.vartype & OV_VT_KSMASK))
		return ov_variable_setanyvalue (&pobj->v_IN1, value);
	  else
	  {
		iec61131stdfb_freeVec(&pobj->v_IN1);
		iec61131stdfb_freeVec(&pobj->v_IN2);
		iec61131stdfb_freeVec(&pobj->v_OUT);		//free memory of preexisting out-vector
		res = iec61131stdfb_ATAN2_setType (pobj, value->value.vartype); 
		if (Ov_OK (res))
		  return ov_variable_setanyvalue (&pobj->v_IN1, value);
		else return res;
	  }
	
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ATAN2_IN2_set(
    OV_INSTPTR_iec61131stdfb_ATAN2          pobj,
    const OV_ANY*  value
) {
    OV_RESULT res;
  
	  if ((value->value.vartype & OV_VT_KSMASK) == (pobj->v_IN2.value.vartype & OV_VT_KSMASK))
		return ov_variable_setanyvalue (&pobj->v_IN2, value);
	  else
	  {
		iec61131stdfb_freeVec(&pobj->v_IN1);
		iec61131stdfb_freeVec(&pobj->v_IN2);
		iec61131stdfb_freeVec(&pobj->v_OUT);		//free memory of preexisting out-vector
		res = iec61131stdfb_ATAN2_setType (pobj, value->value.vartype); 
		if (Ov_OK (res))
		  return ov_variable_setanyvalue (&pobj->v_IN2, value);
		else return res;
	  }
}

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_ATAN2_OUT_get(
    OV_INSTPTR_iec61131stdfb_ATAN2          pobj
) {
    return &pobj->v_OUT;
}


OV_DLLFNCEXPORT void iec61131stdfb_ATAN2_destructor(OV_INSTPTR_ov_object pobj) {

	
	OV_INSTPTR_iec61131stdfb_ATAN2 pinst = Ov_StaticPtrCast(iec61131stdfb_ATAN2, pobj);
	
	iec61131stdfb_freeVec(&pinst->v_IN1);
	iec61131stdfb_freeVec(&pinst->v_IN2);
	iec61131stdfb_freeVec(&pinst->v_OUT);
	fb_functionblock_destructor(pobj);
}


OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_ATAN2_constructor(OV_INSTPTR_ov_object pobj) {

	OV_RESULT res;
	OV_INSTPTR_iec61131stdfb_ATAN2 pinst = Ov_StaticPtrCast(iec61131stdfb_ATAN2, pobj);
	
	res = fb_functionblock_constructor(pobj);
	
	if(Ov_OK(res))
	{
		pinst->v_IN1.value.valueunion.val_double = 0;
		pinst->v_IN2.value.valueunion.val_double = 0;
		pinst->v_OUT.value.valueunion.val_double = 0;
		pinst->v_IN1.value.vartype = OV_VT_SINGLE;
		pinst->v_IN2.value.vartype = OV_VT_SINGLE;
		pinst->v_OUT.value.vartype = OV_VT_SINGLE;
		return OV_ERR_OK;
	}
	else
		return res;
}


OV_DLLFNCEXPORT void iec61131stdfb_ATAN2_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	const double Pi = 3.14159265358979323846;
	unsigned int i;
	
    OV_INSTPTR_iec61131stdfb_ATAN2 pinst = Ov_StaticPtrCast(iec61131stdfb_ATAN2, pfb);
	
	iec61131stdfb_freeVec(&pinst->v_OUT);		//free memory of preexisting out-vector
	if(!(pinst->v_IN1.value.vartype & OV_VT_ISVECTOR))
	{
		switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
		{
			
			case OV_VT_INT:
				ov_logfile_warning("%s: atan2 of integers, setting out to single to prevent data loss", pinst->v_identifier);
				pinst->v_OUT.value.vartype = OV_VT_SINGLE;
				if((pinst->v_IN1.value.valueunion.val_int))
					pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_int / pinst->v_IN1.value.valueunion.val_int);
				else
					if(pinst->v_IN2.value.valueunion.val_int < 0)
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (-0.5 * Pi);
					else
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
			break;
			
			case OV_VT_UINT:
				ov_logfile_warning("%s: atan2 of unsigned integers, setting out to single to prevent data loss", pinst->v_identifier);
				pinst->v_OUT.value.vartype = OV_VT_SINGLE;
				if((pinst->v_IN1.value.valueunion.val_uint))
					pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_uint / pinst->v_IN1.value.valueunion.val_uint);
				else
					pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
			break;
			
			case OV_VT_SINGLE:
				pinst->v_OUT.value.vartype = OV_VT_SINGLE;
				if((pinst->v_IN1.value.valueunion.val_single))
					pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_single / pinst->v_IN1.value.valueunion.val_single);
				else
					if(pinst->v_IN2.value.valueunion.val_single < 0)
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (-0.5 * Pi);
					else
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
			break;
			
			case OV_VT_DOUBLE:
				pinst->v_OUT.value.vartype = OV_VT_DOUBLE;
				if((pinst->v_IN1.value.valueunion.val_double))
					pinst->v_OUT.value.valueunion.val_double = atan(pinst->v_IN2.value.valueunion.val_double / pinst->v_IN1.value.valueunion.val_double);
				else
					if(pinst->v_IN2.value.valueunion.val_double < 0)
						pinst->v_OUT.value.valueunion.val_double = -0.5 * Pi;
					else
						pinst->v_OUT.value.valueunion.val_double = 0.5 * Pi;
			break;

			case OV_VT_BYTE:
				ov_logfile_warning("%s: atan2 of bitstrings, setting out to single to prevent data loss", pinst->v_identifier);
				pinst->v_OUT.value.vartype = OV_VT_SINGLE;
				if((pinst->v_IN1.value.valueunion.val_byte))
					pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) atan(pinst->v_IN2.value.valueunion.val_byte / pinst->v_IN1.value.valueunion.val_byte);
				else
					if(pinst->v_IN2.value.valueunion.val_byte < 0)
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (-0.5 * Pi);
					else
						pinst->v_OUT.value.valueunion.val_single = (OV_SINGLE) (0.5 * Pi);
				
			break;
			
			default:
				pinst->v_OUT.value.vartype = OV_VT_BOOL;
				pinst->v_OUT.value.valueunion.val_bool = FALSE;
				ov_logfile_alert("%s: atan2 of given datatypes senseless", pinst->v_identifier);
			break;
		}
	}
	else
	{
		switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
		{
			
			case OV_VT_INT_VEC:
				ov_logfile_warning("%s: arctan2 of integers requested, setting out to single to prevent data loss", pinst->v_identifier);
				STDFB_VEC_ATAN2(INT, int);
			break;
			
			case OV_VT_UINT_VEC:
				ov_logfile_warning("%s: arctan2 of unsigned integers requested, setting out to single to prevent data loss", pinst->v_identifier);
				STDFB_VEC_ATAN2(UINT, uint);
			break;
			
			case OV_VT_SINGLE_VEC:
				STDFB_VEC_ATAN2(SINGLE, single);
			break;
			
			case OV_VT_DOUBLE_VEC:
				STDFB_VEC_ATAN2_D(DOUBLE, double);
			break;

			case OV_VT_BYTE_VEC:
				ov_logfile_warning("%s: arctan2 of bitstrings requested, setting out to single to prevent data loss", pinst->v_identifier);
				STDFB_VEC_ATAN2(BYTE, byte);
			break;
			
			default:
				pinst->v_OUT.value.vartype = OV_VT_BOOL;
				pinst->v_OUT.value.valueunion.val_bool = FALSE;
				ov_logfile_alert("%s: arctan2 of given datatypes senseless", pinst->v_identifier);
			break;
		}
	}
	
/************** handling states and timesdtamps ********************************/
		
#include "state_2in.c"	
	

    return;
}

