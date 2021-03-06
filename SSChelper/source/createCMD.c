
/******************************************************************************
*
*   FILE
*   ----
*   createCMD.c
*
*   History
*   -------
*   2017-11-12   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_SSChelper
#define OV_COMPILE_LIBRARY_SSChelper
#endif


#include "SSChelper.h"
#include "ov_macros.h"


OV_DLLFNCEXPORT void SSChelper_createCMD_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_SSChelper_createCMD pinst = Ov_StaticPtrCast(SSChelper_createCMD, pfb);
    OV_RESULT result = OV_ERR_OK;

    //Reset trigger out
    pinst->v_trigger = FALSE;

	if (pinst->v_start == TRUE) {
		result = ov_string_print(&pinst->v_CMD,"%s;%s;%s",
				pinst->v_sender ? pinst->v_sender:"",
				pinst->v_order  ? pinst->v_order :"",
				pinst->v_param  ? pinst->v_param :"");
		if(Ov_OK(result)) {
			pinst->v_trigger = TRUE;
			pinst->v_start = FALSE;
		}
	}
    return;
}

