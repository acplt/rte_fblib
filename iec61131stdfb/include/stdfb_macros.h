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
/***********************************************************************
*
*	File
*	-----
*	stdfb_macros.h
*
*	Autoren:
*	--------
*	LE						Lars Evertz <l.evertz@plt.rwth-aachen.de>
*
*	
*	Historie:
*	--------
*	14-December-2010		LE
*		-	file created
*
***********************************************************************/


#ifndef OV_STDFB_MACROS
#define OV_STDFB_MACROS




#include <float.h>

/*****Speicher von vektor freigeben und union nullen (pointer!); benötig iterator i******/
/**************** Neu als Funktion aufgesetzt um speicherbedarf zu verringern OV_RESULT iec61131stdfb_freeVec(OV_ANY* pobj) ***/

#define STDFB_FREE_VEC(pobj) \
switch(pobj.value.vartype & OV_VT_KSMASK) { \
	case OV_VT_BYTE_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_byte_vec, NULL, 0, BYTE); \
	break;	\
	case OV_VT_BOOL_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_bool_vec, NULL, 0, BOOL); \
	break;	\
	case OV_VT_INT_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_int_vec, NULL, 0, INT); \
	break;	\
	case OV_VT_UINT_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_uint_vec, NULL, 0, UINT); \
	break;	\
	case OV_VT_SINGLE_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_single_vec, NULL, 0, SINGLE); \
	break;	\
	case OV_VT_DOUBLE_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_double_vec, NULL, 0, DOUBLE); \
	break;	\
	case OV_VT_STRING_VEC:	\
		for(i=0; i<pobj.value.valueunion.val_string_vec.veclen; i++)	\
			ov_string_setvalue(&pobj.value.valueunion.val_string_vec.value[i], "");	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_string_vec, NULL, 0, STRING);	\
	break;	\
	case OV_VT_TIME_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_time_vec, NULL, 0, TIME); \
	break;	\
	case OV_VT_TIME_SPAN_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_time_span_vec, NULL, 0, TIME_SPAN); \
	break;	\
	case OV_VT_STATE_VEC:	\
		Ov_SetDynamicVectorValue(&pobj.value.valueunion.val_state_vec, NULL, 0, STATE); \
	break;	\
	case OV_VT_STRING:	\
		ov_string_setvalue(&pobj.value.valueunion.val_string, "");	\
	break;	\
	}	\
	pobj.value.valueunion.val_double = 0;
	
/*************Umwandlung double in single mit wertebereichsprüfung*****/
	
#define STDFB_CONV_DBL_FLT(dbl, flt)	\
	if(dbl > FLT_MAX)	\
	{	\
		flt = (OV_SINGLE) HUGE_VAL;	\
		ov_logfile_error("%s: Value exceeds range of single", pinst->v_identifier);	\
	}	\
	else if(dbl < - FLT_MAX)	\
	{	\
		flt = (OV_SINGLE) -HUGE_VAL;	\
		ov_logfile_error("%s: Value exceeds range of single", pinst->v_identifier);	\
	}	\
	else	\
		flt = (OV_SINGLE) dbl;
		
		

		
/************** Statusbehandlung für 2 inputs; kommentare siehe state_2in.c********************************/

#define STDFB_STATES_2_INPUTS	\
	if((pinst->v_IN1.value.vartype & OV_VT_HAS_STATE)	\
			&& (pinst->v_IN2.value.vartype & OV_VT_HAS_STATE))		\
		{	\
			pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_STATE;	\
			if(pinst->v_IN1.state == pinst->v_IN2.state)	\
				pinst->v_OUT.state = pinst->v_IN1.state;	\
			if((pinst->v_IN1.state == OV_ST_BAD)	\
				|| (pinst->v_IN2.state == OV_ST_BAD))	\
				pinst->v_OUT.state = OV_ST_BAD;	\
			else	\
				if((pinst->v_IN1.state == OV_ST_QUESTIONABLE)	\
					|| (pinst->v_IN2.state == OV_ST_QUESTIONABLE))	\
					pinst->v_OUT.state = OV_ST_QUESTIONABLE;	\
					else	\
						if((pinst->v_IN1.state == OV_ST_UNKNOWN)	\
							|| (pinst->v_IN2.state == OV_ST_UNKNOWN))	\
							pinst->v_OUT.state = OV_ST_UNKNOWN;	\
						else	\
							if((pinst->v_IN1.state == OV_ST_NOTSUPPORTED)	\
								|| (pinst->v_IN2.state == OV_ST_NOTSUPPORTED))	\
								pinst->v_OUT.state = OV_ST_UNKNOWN;	\
		}	\
		else	\
		{	\
			if(pinst->v_IN1.value.vartype & OV_VT_HAS_STATE)	\
			{	\
				pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_STATE;	\
				pinst->v_OUT.state = pinst->v_IN1.state;	\
			}	\
			else	\
			if(pinst->v_IN2.value.vartype & OV_VT_HAS_STATE)	\
			{	\
				pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_STATE;	\
				pinst->v_OUT.state = pinst->v_IN2.state;	\
			}	\
		}			
		
		
/***************** zeitstempelbehandlung für 2 inputs, kommentare siehe state_2in.c ************************/

#define STDFB_TIMESTAMP_2_INPUTS	\
		if((pinst->v_IN1.value.vartype & OV_VT_HAS_TIMESTAMP)	\
			&& (pinst->v_IN2.value.vartype & OV_VT_HAS_TIMESTAMP))	\
		{	\
			pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_TIMESTAMP;	\
			if((pinst->v_IN1.time.secs < pinst->v_IN2.time.secs)	\
				|| ((pinst->v_IN1.time.secs == pinst->v_IN2.time.secs) && (pinst->v_IN1.time.usecs < pinst->v_IN2.time.usecs)))	\
			{	\
				pinst->v_OUT.time.secs = pinst->v_IN1.time.secs;	\
				pinst->v_OUT.time.usecs = pinst->v_IN1.time.usecs;	\
			}	\
			else	\
			{	\
				if((pinst->v_IN2.time.secs < pinst->v_IN1.time.secs)	\
					|| ((pinst->v_IN2.time.secs == pinst->v_IN1.time.secs) && (pinst->v_IN2.time.usecs < pinst->v_IN1.time.usecs)))	\
				{	\
					pinst->v_OUT.time.secs = pinst->v_IN2.time.secs;	\
					pinst->v_OUT.time.usecs = pinst->v_IN2.time.usecs;	\
				}	\
				else	\
				{	\
					pinst->v_OUT.time.secs = pinst->v_IN1.time.secs;	\
					pinst->v_OUT.time.usecs = pinst->v_IN1.time.usecs;	\
				}	\
			}	\
		}	\
		else	\
		{	\
			if(pinst->v_IN1.value.vartype & OV_VT_HAS_TIMESTAMP)	\
			{	\
				pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_TIMESTAMP;	\
				pinst->v_OUT.time.secs = pinst->v_IN1.time.secs;	\
				pinst->v_OUT.time.usecs = pinst->v_IN1.time.usecs;	\
			}	\
			else	\
			{	\
				if(pinst->v_IN2.value.vartype & OV_VT_HAS_TIMESTAMP)	\
				{	\
					pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_TIMESTAMP;	\
					pinst->v_OUT.time.secs = pinst->v_IN2.time.secs;	\
					pinst->v_OUT.time.usecs = pinst->v_IN2.time.usecs;	\
				}	\
			}	\
		}
		
	
/************** Statusbehandlung für einen Input ********************************/
#ifdef STDFB_STATE_CHECK

#define STDFB_STATE(num_in)	\
	if(STDFB_bad_operation)	\
		pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_STATE;	\
		pinst->v_OUT.state = OV_ST_BAD;	\

#else

	#define STDFB_STATE(num_in)	;
	
#endif
		
/*	else	\
	if(pinst->v_##num_in.value.vartype & OV_VT_HAS_STATE)	\
	{	\
		pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_STATE;	\
		pinst->v_OUT.state = pinst->v_##num_in.state;	\
	}*/		//states are not passed on

	
/***************** Zeitstempelbehandlung für einen input ************************/

#define STDFB_TIMESTAMP(num_in)	\
	if(pinst->v_##num_in.value.vartype & OV_VT_HAS_TIMESTAMP)	\
	{	\
		pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_TIMESTAMP;	\
		pinst->v_OUT.time.secs = pinst->v_##num_in.time.secs;	\
		pinst->v_OUT.time.usecs = pinst->v_##num_in.time.usecs;	\
	}
		
/***************** Zeitstempelbehandlung für neu generierung ************************/

#define STDFB_TIMESTAMP_NEW	\
	if((pinst->v_IN1.value.vartype & OV_VT_HAS_TIMESTAMP) || (pinst->v_IN1.value.vartype & OV_VT_HAS_TIMESTAMP))	\
	{	\
		pinst->v_OUT.value.vartype = pinst->v_OUT.value.vartype | OV_VT_HAS_TIMESTAMP;	\
		ov_time_gettime(&pinst->v_OUT.time);	\
	}

/************************ vergleich von zeitspannen *********************************************/

#define STDFB_LE_TIME_SPAN(one, two)	\
	((one.secs < two.secs) || ((one.secs == two.secs ) && (one.usecs <= two.usecs)))
	
/************* Einschließen der weiteren Macro-dateien**************/		



#include "stdfb_numeric_macros.h"
#include "stdfb_bitwise_macros.h"
#include "stdfb_select_macros.h"
#include "stdfb_comp_macros.h"
#include "stdfb_convert_macros.h"


	
#endif

