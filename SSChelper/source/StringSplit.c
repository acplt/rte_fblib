
/******************************************************************************
*
*   FILE
*   ----
*   StringSplit.c
*
*   History
*   -------
*   2018-06-22   File created
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


OV_DLLFNCEXPORT void SSChelper_StringSplit_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_SSChelper_StringSplit pinst = Ov_StaticPtrCast(SSChelper_StringSplit, pfb);

    if(pinst->v_IN != NULL && pinst->v_DELIM != NULL){

    	OV_STRING *plist = NULL;
    	OV_UINT len = 0;
    	plist = ov_string_split(pinst->v_IN, pinst->v_DELIM, &len);
    	if(plist != NULL && len > 0){
    		pinst->v_FOUND = TRUE;
    		pinst->v_LEN = len;
    		Ov_SetDynamicVectorValue(&pinst->v_OUT, plist, len, STRING);
    		ov_string_setvalue(&pinst->v_OUT1, plist[0]);
    		ov_string_setvalue(&pinst->v_OUT2, len ==1 ? NULL : plist[1]);
    		ov_string_setvalue(&pinst->v_OUT3, len ==1 ? NULL : plist[len-1]);
    	}else{
        	pinst->v_FOUND = FALSE;
        	pinst->v_LEN = 0;
        	ov_string_setvalue(&pinst->v_OUT1, NULL);
        	ov_string_setvalue(&pinst->v_OUT2, NULL);
        	ov_string_setvalue(&pinst->v_OUT3, NULL);
        	Ov_SetDynamicVectorLength(&pinst->v_OUT,0,STRING);
    	}
    	if(plist!= NULL)ov_string_freelist(plist);
    }else{
    	pinst->v_FOUND = FALSE;
    	pinst->v_LEN = 0;
    	ov_string_setvalue(&pinst->v_OUT1, NULL);
    	ov_string_setvalue(&pinst->v_OUT2, NULL);
    	ov_string_setvalue(&pinst->v_OUT3, NULL);
    	Ov_SetDynamicVectorLength(&pinst->v_OUT,0,STRING);
    }

    return;
}

