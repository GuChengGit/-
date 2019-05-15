#ifndef _LB_INITIAL_LONBON_H
#define _LB_INITIAL_LONBON_H
#include "lb_headdef.h"
#include "lb_initial.h"
#include "lb_bc.h"
#include "lb_info.h"

LB_BEGIN_DECL
typedef enum _lbSdk_mstTp_e
{
	LBSDK_MSTTP_COMM=0,
	LBSDK_MSTTP_TRIAGEMST,
	LBSDK_MSTTP_TRIAGEMST_NOSIP,
}lbSdk_mstTp_e;

LB_EXPORT int lb_ipIntercom_start_lonbon(lb_runLevel runLvl,int displayNum,char *sn,char *sipAcc,char *sipPwd,fun_ua2ui_event_callback fun,
										 void *cfgSetFun,
										 void *cfgGetFun,
										 void *cfgSaveFun);    //displayNum==0,则从配置中读取编号

LB_EXPORT int lb_ipIntercom_start_lonbon_ext(lbSdk_mstTp_e mstTp,lb_runLevel runLvl,int displayNum,char *sn,char *sipAcc,char *sipPwd,fun_ua2ui_event_ext_callback fun_ext,
										 void *cfgSetFun,
										 void *cfgGetFun,
										 void *cfgSaveFun);    //displayNum==0,则从配置中读取编号

LB_EXPORT int lb_ipIntercom_start_lonbon_ext2(int displayNum,void *deviceInfo,fun_ua2ui_event_ext_callback fun_ext,
											 void *cfgSetFun,
											 void *cfgGetFun,
											 void *cfgSaveFun);    //displayNum==0,则从配置中读取编号

LB_EXPORT int lb_info_getTerminalInfo_withQuery(int displayNum,int areaId,int devRegType,lb_terminalInfo_s *info);

LB_EXPORT void lb_fun_playKeyTone(void);

LB_EXPORT int lb_fun_startPartBc_withDestIp(lbBc_mode_e mode,lbBc_propert_e bcPropert,int bcVol,char **destIpList,int destCount,char **file,int fileCount,int playIndex);

LB_EXPORT int lb_init_set_needQueryExtnRegType(int devRegType);

LB_EXPORT int lb_info_getGpDevInfo_fromDisplayNum_withQuery(int devRegType,int displayNum,int *groupNum,int *devNum);
LB_EXPORT int lb_info_getGpDevInfo_fromGpDevNum_withQuery(int devRegType,int groupNum,int devNum,int *displayNum);


LB_EXPORT int lb_ipIntercom_start_lonbon_NoSip(lbSdk_mstTp_e mstTp,int displayNum,char *sn,char *sipAcc,char *sipPwd,fun_ua2ui_event_ext_callback fun_ext,
											   void *cfgSetFun,
											   void *cfgGetFun,
											   void *cfgSaveFun);    //displayNum==0,则从配置中读取编号
LB_EXPORT int lb_ipIntercom_stop_lonbon_NoSip(void);

LB_EXPORT int lb_fun_stdSip_call(char *sipAcc);
LB_EXPORT int lb_fun_stdSip_answer(int call_id);
LB_EXPORT int lb_fun_stdSip_hungup(int call_id);

LB_EXPORT int lb_ipIntercom_debugInfo_printf(char *info);

typedef struct _lb_wavDevInfo
{
	unsigned short wMid;
	unsigned short wPid;
	char devName[64];
} lb_wavDevInfo_s;

LB_EXPORT int lb_devCtr_getAudioInputDevInfoList(lb_wavDevInfo_s *infoList, int listCnt, int *devCnt);
LB_EXPORT int lb_devCtr_getActiveAudioInputDevInfo(lb_wavDevInfo_s *info);

LB_EXPORT int lb_devCtr_getAudioOutputDevInfoList(lb_wavDevInfo_s *infoList, int listCnt, int *devCnt);
LB_EXPORT int lb_devCtr_getActiveAudioOutputDevInfo(lb_wavDevInfo_s *info);

typedef enum _lbCallType
{
	LBCALLTP_UNDEF,
	LBCALLTP_GENERAL,
	LBCALLTP_NSALARM,
	LBCALLTP_EMERGENCY,
	LBCALLTP_INFUSIONALARM,
	LBCALLTP_REQREINFORCE,
	LBCALLTP_PENDING,
	LBCALLTP_DOCTOR,
	LBCALLTP_APPLYSPEAK,     //会议模式或指挥模式申请发言
	LBCALLTP_RMALARM,		   //防拆报警
	LBCALLTP_WARDALARM,	   //门口机报警
} lbCallType_e;

LB_EXPORT int lb_fun_synSystemTime(void);  //同步地址盒时间，

LB_EXPORT BOOL lb_info_getDeviceInfoLicense(void);  //获取设备扫描信息是否合法，底层如果用到SS_DeviceInfo，返回SS_DeviceInfo中的“isGoodLicense”，否则返回PJ_TRUE。

LB_EXPORT int lb_info_getNKVersion(char *versionBuf,int bufSize);  //获取NK版本信息
LB_EXPORT int lb_info_getDeviceInfoModelName(char *modelBuf, int modelBufSize, char *customizedModelBuf, int customizedModelBufSize, char *nameBuf, int nameBufSize);  //获取型号,定制型号和名称，可以只获取其中一个或两个，不获取的buf给NULL即可

#ifdef NET_INIT_STEP
LB_EXPORT int lb_ipIntercom_start_lonbon_local(int displayNum, void *deviceInfo, fun_ua2ui_event_ext_callback fun_stdcall,
	void *cfgSetFun, void *cfgGetFun, void *cfgSaveFun);

LB_EXPORT int lb_ipIntercom_start_lonbon_network();
#endif

typedef enum _lb_setting_key_internal
{
    LBSETTING_INTERNAL_KEY_BASE = 1000,
    LBSETTING_INTERNAL_KEY_AUDIOCODEC_PRIORITY,			//音频编解码优先级
    LBSETTING_INTERNAL_KEY_VIDEO_FRAMERATE,				//视频编解码帧率
    LBSETTING_INTERNAL_KEY_ALARM_OUTPUT,			    //报警输出
} lb_setting_internal_key_e;

//android主机初始化接口
LB_EXPORT int lb_ipIntercom_start_android(void *deviceInfo, fun_ua2ui_event_ext_callback fun_stdcall, void *cfgSetFun, void *cfgGetFun, void *cfgSaveFun);

//修改config配置和temp记录路径
LB_EXPORT int lb_ipIntercom_fileDirectory_set(char *conPath, char *temPath);

#ifdef NET_INIT_STEP
LB_EXPORT int lb_ipIntercom_start_local(void *deviceInfo, fun_ua2ui_event_ext_callback fun_ext,
	void *cfgSetFun, void *cfgGetFun, void *cfgSaveFun);

LB_EXPORT int lb_ipIntercom_start_network();
#endif

LB_EXPORT int lb_ipIntercom_iphone_register(char *ip, int regPort);		//手机注册

typedef struct _lb_atmTermInfo
{
	int termNum;
	char desc[64];
}lb_atmTermInfo_s;

//获取分机的ATM终端列表信息，extnDisplayNum为6为接线箱分机编号，可以先将atmTermInfoList为NULL或者cnt为0调用一次，函数会返回非0，cnt会返回实际个数，一个分机的ATM终端数量不会超过30个
LB_EXPORT int lb_info_getAtmTerList_belongExtn(int extnDisplayNum, int areaId, int devRegType, lb_atmTermInfo_s *atmTermInfoList, int *cnt);

//设置终端描述信息，extnDisplayNum为6为接线箱分机编号，atmTermInfoList->termNum为9位编号，只能一次设置一个接线箱分机下的终端的信息
LB_EXPORT int lb_info_extnAtmTerm_setTermDesc(int extnDisplayNum, int areaId, int devRegType, lb_atmTermInfo_s *atmTermInfoList, int cnt); 

//获取终端描述信息，term_displayNum为9位编号，可以先将descBuf为NULL或者bufSize为0调用一次，函数会返回非0，bufSize会返回实际长度,descBuf返回没有'\0'结束符
LB_EXPORT int lb_info_extnAtmTerm_getTermDesc(int term_displayNum, int areaId, int devRegType, char *descBuf, int *bufSize);

//获取通话对方绑定的IPC的地址信息
LB_EXPORT int lb_info_getRmtIPCAddrInfo(int call_id, char *IPCAddrInfo, int *bufSize);


/*
* setting io output type
* @type: io output type (lb_keyevent_output_type)
* @value: setting value.
* @return 0 success, other failed
*/
LB_EXPORT int lb_fun_setOutput_value(int type , int value);

/*
* get io input value
* @type: io input type(lb_keyevent_input_type)
* @val: io value
* @return 0 success, other failed
*/
LB_EXPORT int lb_fun_get_input_value(int type, int *value);

/*  get temperature and humidity
 *  @return 0 success, other failed
*/
LB_EXPORT int lb_fun_get_temperature_humidity(void);

LB_END_DECL
#endif