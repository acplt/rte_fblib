
/******************************************************************************
*
*   FILE
*   ----
*   setVar.c
*
*   History
*   -------
*   2013-05-18   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_fbcomlib
#define OV_COMPILE_LIBRARY_fbcomlib
#endif


#include "fbcomlib.h"
#include "ov_macros.h"
#include "config.h"
#include "ksapi_commonFuncs.h"

OV_DLLFNCEXPORT OV_RESULT fbcomlib_setVar_sendVar_set(
    OV_INSTPTR_fbcomlib_setVar          pobj,
    const OV_ANY*  value
) {
	if(!(pobj->v_doSend)){
		return Ov_SetAnyValue(&(pobj->v_sendVar), value);
	}
	else{
		return OV_ERR_NOACCESS;
	}
}

OV_DLLFNCEXPORT OV_BOOL fbcomlib_setVar_doReset_get(
    OV_INSTPTR_fbcomlib_setVar          pobj
) {
    return pobj->v_doReset;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_setVar_doReset_set(
    OV_INSTPTR_fbcomlib_setVar          pobj,
    const OV_BOOL  value
) {
    OV_INSTPTR_fbcomlib_pkgSetVariable fbcomlibVar = NULL;
    if(value)
    {
    	if(pobj->p_apiSet.v_Reset)
    		ksapi_KSApiCommon_Reset_set((OV_INSTPTR_ksapi_KSApiCommon)&(pobj->p_apiSet), FALSE);
    	ksapi_KSApiCommon_Reset_set((OV_INSTPTR_ksapi_KSApiCommon)&(pobj->p_apiSet), TRUE);
    	fbcomlib_FBComCommon_resetAbstract(Ov_StaticPtrCast(fbcomlib_FBComCommon, pobj));
    	Ov_ForEachChildEx(ov_containment, pobj, fbcomlibVar, fbcomlib_pkgSetVariable)
    	{
    		fbcomlibVar->p_apiVar.v_order = 0;
    	}
    	Ov_ForEachChildEx(fbcomlib_PkgVar, pobj, fbcomlibVar, fbcomlib_pkgSetVariable)
    	{
    		fbcomlibVar->p_apiVar.v_order = 0;
    	}
    }

    return OV_ERR_OK;
}

OV_DLLFNCEXPORT void fbcomlib_setVar_startup(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */

    /* do what the base class does first */
    fb_functionblock_startup(pobj);

    /* do what */


    return;
}

OV_DLLFNCEXPORT void fbcomlib_setVar_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_fbcomlib_setVar pinst = Ov_StaticPtrCast(fbcomlib_setVar, pfb);
    OV_VTBLPTR_ksapi_setVar pVtblSetVar = (OV_VTBLPTR_ksapi_setVar) pclass_ksapi_setVar->v_pvtable;
    OV_RESULT result;

    if(pinst->v_state == FBCOMLIB_STATE_WAITING)
    {	/*	waiting: calculate timeouts and check ksapi-object for answer	*/

    	if(pinst->p_apiSet.v_status == KSAPI_COMMON_REQUESTCOMPLETED)
    	{	/*	ksapi-request completed --> get answer	*/
    		pinst->v_opResult = pinst->p_apiSet.v_result;
    		pinst->v_varResult = pinst->p_apiSet.v_varRes;
    		fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_OK);
    		pinst->v_errorCode = OV_ERR_OK;
    	}
    	else if(pinst->p_apiSet.v_status == KSAPI_COMMON_INTERNALERROR)
    	{
    		fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_KSAPI_ERROR);
    		pinst->v_errorCode = pinst->p_apiSet.v_result;
    		return;
    	}
    	else if(pinst->p_apiSet.v_status == KSAPI_COMMON_EXTERNALERROR)
    	{
    		fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_EXTERNAL_ERROR);
    		pinst->v_errorCode = OV_ERR_GENERIC;
    		return;
    	}
    	else if(pinst->p_apiSet.v_status == KSAPI_COMMON_WAITINGFORANSWER)
    	{
    		if(pltc->secs > (pinst->v_requestSendTime.secs + pinst->v_timeout))
    		{
    			fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_TIMEOUT);
    			return;
    		}
    		return;
    	}
    }

    if((pinst->v_state == FBCOMLIB_STATE_OK) || (pinst->v_state == FBCOMLIB_STATE_INIT))
    {	/*	ready to start	*/
    	if(pinst->v_sendRequested)
    	{	/*	single send requested	*/
    		result = ov_string_setvalue(&(pinst->p_apiSet.v_serverHost), pinst->v_host);
    		if(Ov_Fail(result))
    		{
    			pinst->v_errorCode = result;
    			fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_INTERNAL_ERROR);
    			return;
    		}
    		result = ov_string_setvalue(&(pinst->p_apiSet.v_serverName), pinst->v_server);
    		if(Ov_Fail(result))
    		{
    			pinst->v_errorCode = result;
    			fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_INTERNAL_ERROR);
    			return;
    		}
    		result = ov_string_setvalue(&(pinst->p_apiSet.v_path), pinst->v_path);
    		if(Ov_Fail(result))
    		{
    			pinst->v_errorCode = result;
    			fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_INTERNAL_ERROR);
    			return;
    		}
    	}
    	if(pinst->v_sendRequested || pinst->v_doCyclic)
    	{	/*	send Requested or cyclic sending requested	*/
    		if(pinst->v_doCyclic)
    			pinst->p_apiSet.v_holdConnection = TRUE;
    		else
    			pinst->p_apiSet.v_holdConnection = FALSE;
    		result = Ov_SetAnyValue(&(pinst->p_apiSet.v_varValue), &(pinst->v_sendVar));
    		if(Ov_Fail(result))
    		{
    			pinst->v_errorCode = result;
    			fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_INTERNAL_ERROR);
    			return;
    		}

    		pVtblSetVar->m_submit(Ov_StaticPtrCast(ksapi_KSApiCommon, &(pinst->p_apiSet)));
    		fbcomlib_FBComCommon_state_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), FBCOMLIB_STATE_WAITING);
    		pinst->v_requestSendTime = *pltc;
    		pinst->v_sendRequested = FALSE;
    		return;

    	}
    	return;
    }
    else if(pinst->v_state != FBCOMLIB_STATE_WRONGINPUT)
    {
    	if(pinst->v_doCyclic && pinst->v_retryAfter)
    	{
    		if(pltc->secs > (pinst->v_requestSendTime.secs + pinst->v_retryAfter))
    		{
    			if(pinst->v_doReset)
    				fbcomlib_setVar_doReset_set(pinst, FALSE);
    			fbcomlib_setVar_doReset_set(pinst, TRUE);
    			fbcomlib_setVar_doReset_set(pinst, FALSE);
    			fbcomlib_FBComCommon_doCyclic_set(Ov_StaticPtrCast(fbcomlib_FBComCommon, pinst), TRUE);
    		}

    	}
    }
    return;
}

OV_DLLFNCEXPORT OV_RESULT fbcomlib_setVar_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*
    *   local variables
    */
    OV_INSTPTR_fbcomlib_setVar pinst = Ov_StaticPtrCast(fbcomlib_setVar, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = fbcomlib_FBComCommon_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */

    pinst->v_sendVar.value.vartype = OV_VT_VOID;
    pinst->v_sendVar.value.valueunion.val_double = 0.0;

   return OV_ERR_OK;
}
