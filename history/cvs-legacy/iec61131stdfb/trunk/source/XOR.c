
/******************************************************************************
*
*   FILE
*   ----
*   XOR.c
*
*   History
*   -------
*   2010-11-30   File created
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
#include "libov/ov_macros.h"
#include "libov/ov_logfile.h"


OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_XOR_IN1_set(
    OV_INSTPTR_iec61131stdfb_XOR          pobj,
    const OV_ANY*  value
) {
    return ov_variable_setanyvalue(&pobj->v_IN1, value);
}

OV_DLLFNCEXPORT OV_RESULT iec61131stdfb_XOR_IN2_set(
    OV_INSTPTR_iec61131stdfb_XOR          pobj,
    const OV_ANY*  value
) {
    return ov_variable_setanyvalue(&pobj->v_IN2, value);
}

OV_DLLFNCEXPORT OV_ANY* iec61131stdfb_XOR_OUT_get(
    OV_INSTPTR_iec61131stdfb_XOR          pobj
) {
    return &pobj->v_OUT;
}


OV_DLLFNCEXPORT void iec61131stdfb_XOR_shutdown(OV_INSTPTR_ov_object pobj) {

	unsigned int i;
	
	OV_INSTPTR_iec61131stdfb_XOR pinst = Ov_StaticPtrCast(iec61131stdfb_XOR, pobj);
	
	STDFB_FREE_VEC(pinst->v_IN1);
	STDFB_FREE_VEC(pinst->v_IN2);
	STDFB_FREE_VEC(pinst->v_OUT);
	ov_object_shutdown(pobj);
}


OV_DLLFNCEXPORT void iec61131stdfb_XOR_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
	
	unsigned int i;
	
    OV_INSTPTR_iec61131stdfb_XOR pinst = Ov_StaticPtrCast(iec61131stdfb_XOR, pfb);
	
	if((pinst->v_IN1.value.vartype & OV_VT_KSMASK) == (pinst->v_IN2.value.vartype & OV_VT_KSMASK))
	{
		
		STDFB_FREE_VEC(pinst->v_OUT);		//free memory of preexisting out-vector
		if(!(pinst->v_IN1.value.vartype & OV_VT_ISVECTOR))
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				case OV_VT_BOOL:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = pinst->v_IN1.value.valueunion.val_bool ^ pinst->v_IN2.value.valueunion.val_bool;
				break;
				
				case OV_VT_UINT:
					pinst->v_OUT.value.vartype = OV_VT_UINT;
					pinst->v_OUT.value.valueunion.val_uint = pinst->v_IN1.value.valueunion.val_uint ^ pinst->v_IN2.value.valueunion.val_uint;
				break;
				
				case OV_VT_BYTE:
					pinst->v_OUT.value.vartype = OV_VT_BYTE;
					pinst->v_OUT.value.valueunion.val_byte = pinst->v_IN1.value.valueunion.val_byte ^ pinst->v_IN2.value.valueunion.val_byte;
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL;
					pinst->v_OUT.value.valueunion.val_bool = FALSE;
					ov_logfile_alert("%s: logic XOR of given datatypes senseless", pinst->v_identifier);
				break;
			}
		}
		else
		{
			switch(pinst->v_IN1.value.vartype & OV_VT_KSMASK)
			{
				
				case OV_VT_BOOL_VEC:
					STDFB_VEC_XOR(BOOL, bool);
				break;
				
				case OV_VT_UINT_VEC:
					STDFB_VEC_XOR(UINT, uint);
				break;
				
				case OV_VT_BYTE_VEC:
					STDFB_VEC_XOR(BYTE, byte);
				break;
				
				default:
					pinst->v_OUT.value.vartype = OV_VT_BOOL_VEC;
					Ov_SetDynamicVectorLength(&pinst->v_OUT.value.valueunion.val_bool_vec, 0, BOOL);
					ov_logfile_alert("%s: logic XOR of given datatypes senseless", pinst->v_identifier);
				break;
			}
		}
	
		/************** handling states and timestamps ********************************/
		
#include "state_2in.c"	
	
	}
	else
	{
		pinst->v_OUT.value.vartype = OV_VT_BOOL;
		pinst->v_OUT.value.valueunion.val_bool = FALSE;
		STDFB_FREE_VEC(pinst->v_OUT);
		ov_logfile_error("%s: trying to use inputs of different types for XOR-block", pinst->v_identifier); 
	}
	
    return;
}

