#ifndef _LB_EXTNDVPINF_H
#define _LB_EXTNDVPINF_H

#include "lb_headdef.h"
#include "lb_communicate.h"

LB_BEGIN_DECL
typedef enum _lbSdk_extnTp_e
{
	LBSDK_EXTNTP_COMM=0,
	LBSDK_EXTNTP_TRIAGE,
}lbSdk_extnTp_e;

typedef enum _lb_ipIntercom_param_key
{
	LB_INIT_PARAM_DISPLAYNUM = 0,
	LB_INIT_PARAM_SERVER_ADDR,

}lb_ipIntercom_param_key;

LB_EXPORT int lb_ipIntercom_extn_start(lbSdk_extnTp_e extnTp,int displayNum,char *sn,char *sipAcc,char *sipPwd,fun_ua2ui_event_callback fun,
									   void *cfgSetFun,
									   void *cfgGetFun,
									   void *cfgSaveFun);

LB_EXPORT int lb_ipIntercom_extn_start2(int displayNum, void *deviceInfo, fun_ua2ui_event_stdcall_callback fun_stdcall,
										void *cfgSetFun,
										void *cfgGetFun,
										void *cfgSaveFun);

LB_EXPORT int lb_ipIntercom_extn_start3(fun_ua2ui_event_stdcall_callback fun_stdcall,
										void *cfgSetFun,
										void *cfgGetFun,
										void *cfgSaveFun);

LB_EXPORT int lb_ipIntercom_extn_start_android(void *deviceInfo, fun_ua2ui_event_ext_callback fun_stdcall,
	void *cfgSetFun,
	void *cfgGetFun,
	void *cfgSaveFun);

#ifdef NET_INIT_STEP
LB_EXPORT int lb_ipIntercom_extn_start_local(void *deviceInfo, fun_ua2ui_event_ext_callback fun_stdcall,
	void *cfgSetFun,
	void *cfgGetFun,
	void *cfgSaveFun);

LB_EXPORT int lb_ipIntercom_extn_start_network(void);

LB_EXPORT int lb_ipIntercom_initParameter_set(int key, char *value);

#endif

LB_EXPORT int lb_ipIntercom_extn_stop(void);

/*分机呼叫*/
/*呼叫主机：extnNum=0；单按钮分机呼叫时使用*/
/*呼叫同一主机下的分机：extnNum范围 1-998；*/
LB_EXPORT int lb_extn_call(int extnNum);

/*分机咨询呼叫，双按钮分机使用*/
LB_EXPORT int lb_extn_consultCall(void);

/*分机紧急报警，双按钮分机使用*/
LB_EXPORT int lb_extn_emergencyCall(void);

/*分机接听呼入*/
LB_EXPORT int lb_extn_answer(void);

/*分机挂断当前的通话或者取消呼出*/
LB_EXPORT int lb_extn_hungup(void);

/*分机获取直属主机的编号*/
LB_EXPORT int lb_extn_info_getMyMstDisplayNum(void);

/*分机请求增援*/
LB_EXPORT int lb_extn_requestReinforce(void);
/*分机取消请求增援*/
LB_EXPORT int lb_extn_requestReinforce_cancel(void);
/*分机输液报警*/
LB_EXPORT int lb_extn_infusionAlarm(void);
/*分机取消输液报警*/
LB_EXPORT int lb_extn_infusionAlarm_cancel(void);


/*分机是否是保密分机*/
LB_EXPORT BOOL lb_extn_info_isSecretDev(void);

/*分机获取是否开启Onvif功能*/
LB_EXPORT BOOL lb_ext_get_ONVIFEna(void);

/*分机设置是否开启onvif功能*/
LB_EXPORT int lb_ext_set_ONVIFEna(BOOL ena);

/*分机本地开锁,lock=1：开锁1，lock=2：开锁2*/
LB_EXPORT int lb_extn_openLock_local(int lock);

LB_END_DECL
#endif