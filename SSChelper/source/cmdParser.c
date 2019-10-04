
/******************************************************************************
*
*   FILE
*   ----
*   cmdParser.c
*
*   History
*   -------
*   2017-11-10   File created
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


OV_DLLFNCEXPORT void SSChelper_cmdParser_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_SSChelper_cmdParser pinst = Ov_StaticPtrCast(SSChelper_cmdParser, pfb);
    OV_STRING senderID = (pinst->v_id == NULL) ? "" : pinst->v_id;
    OV_STRING order = (pinst->v_order == NULL) ? "" : pinst->v_order;
    OV_STRING params = NULL;

    for (size_t i = 0 ; i < pinst->v_params.veclen ; i++){
        	if(pinst->v_params.value[i] != NULL){
        		ov_string_append(&params, pinst->v_params.value[i]);
        		if(i < pinst->v_params.veclen-1)
        			ov_string_append(&params, ",");
        	}
    }
    params = (params) ? params : "";

    ov_string_setvalue(&pinst->v_cmd, "");
    ov_string_print(&pinst->v_cmd,"%s;%s;%s", senderID, order, params);

    ov_string_setvalue(&params, NULL);

    return;
}

