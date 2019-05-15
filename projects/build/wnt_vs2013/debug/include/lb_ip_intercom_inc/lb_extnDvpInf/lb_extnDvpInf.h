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

/*�ֻ�����*/
/*����������extnNum=0������ť�ֻ�����ʱʹ��*/
/*����ͬһ�����µķֻ���extnNum��Χ 1-998��*/
LB_EXPORT int lb_extn_call(int extnNum);

/*�ֻ���ѯ���У�˫��ť�ֻ�ʹ��*/
LB_EXPORT int lb_extn_consultCall(void);

/*�ֻ�����������˫��ť�ֻ�ʹ��*/
LB_EXPORT int lb_extn_emergencyCall(void);

/*�ֻ���������*/
LB_EXPORT int lb_extn_answer(void);

/*�ֻ��Ҷϵ�ǰ��ͨ������ȡ������*/
LB_EXPORT int lb_extn_hungup(void);

/*�ֻ���ȡֱ�������ı��*/
LB_EXPORT int lb_extn_info_getMyMstDisplayNum(void);

/*�ֻ�������Ԯ*/
LB_EXPORT int lb_extn_requestReinforce(void);
/*�ֻ�ȡ��������Ԯ*/
LB_EXPORT int lb_extn_requestReinforce_cancel(void);
/*�ֻ���Һ����*/
LB_EXPORT int lb_extn_infusionAlarm(void);
/*�ֻ�ȡ����Һ����*/
LB_EXPORT int lb_extn_infusionAlarm_cancel(void);


/*�ֻ��Ƿ��Ǳ��ֻܷ�*/
LB_EXPORT BOOL lb_extn_info_isSecretDev(void);

/*�ֻ���ȡ�Ƿ���Onvif����*/
LB_EXPORT BOOL lb_ext_get_ONVIFEna(void);

/*�ֻ������Ƿ���onvif����*/
LB_EXPORT int lb_ext_set_ONVIFEna(BOOL ena);

/*�ֻ����ؿ���,lock=1������1��lock=2������2*/
LB_EXPORT int lb_extn_openLock_local(int lock);

LB_END_DECL
#endif