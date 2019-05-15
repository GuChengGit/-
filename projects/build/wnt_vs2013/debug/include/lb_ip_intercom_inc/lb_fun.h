#ifndef _LB_FUN_H
#define _LB_FUN_H
#include "lb_headdef.h"

LB_BEGIN_DECL
LB_EXPORT int lb_fun_call(int displayNum);
LB_EXPORT int lb_fun_answer(int displayNum);
LB_EXPORT int lb_fun_answer_onOrder(void);    //按呼入顺序接听，接听先呼入的
LB_EXPORT int lb_fun_hungup(int displayNum);
LB_EXPORT int lb_fun_hungup_curConnectedCall(void);   //挂断当前接通的通话

LB_EXPORT int lb_fun_crcListen_start(int mstDisplayNum);
LB_EXPORT int lb_fun_crcListen_stop(int mstDisplayNum);

LB_EXPORT int lb_fun_openExtnLock(int displayNum,int lock);

LB_EXPORT int lb_fun_beAgent_request(BOOL bOn);
LB_EXPORT int lb_fun_agent_response(int beAgentMstNum,BOOL bOn);

LB_EXPORT int lb_fun_localVideo_switch(BOOL bOn);
LB_EXPORT int lb_fun_notifyRmtVideo_on(void);

/*呼叫大堂经理*/
LB_EXPORT int lb_fun_call_lobby_manager(BOOL bOn);

/* 控制本地摄像头开关
 * @param bOn 开关控制
 * @param index 摄像头序号
*/
LB_EXPORT int lb_fun_localVideo_switch_ext(BOOL bOn, int index);

/* 控制音频开关，开启(关闭)onvif
 * @param bOn 开关控制
 * @return 0成功，其他失败
*/
LB_EXPORT int lb_fun_audio_onvif_switch(BOOL bOn);

/* 调整音量大小
 * @param chip 内外喇叭(0为内喇叭，1位外喇叭)
 * @param data 硬件整数值（FCF33B230D****）
 * @return 0成功， 其他失败
*/
LB_EXPORT int lb_fun_audio_set_vol(int chip, unsigned short nVol);

/*
* 设置1288芯片输入是否可用
* @param chip 内外喇叭(0为内喇叭，1位外喇叭)
* @param enable  false表示静音
* @return 0成功， 其他失败
*/
LB_EXPORT int lb_fun_audio_chip_mic_in_enable(int chip, BOOL enable);

/* 设置工作模式（网络对讲模式和窗口对讲模式）
 * @param mode 工作模式(0为网络对讲模式，1为窗口对讲模式)
 * @return 0成功， 其他失败
*/
LB_EXPORT int lb_fun_audio_set_mode(int mode);

/* 是否恢复出厂设置
*/
LB_EXPORT int lb_fun_restore_get();

/* 设置分机的左右声道控制
 * @param index 声道选择(左声道[0]、右声道[1])
 * @param flag 采集和播放选择(0为同时设置,1为采集音量，2为播放音量)
 * @param vol 声道音量(0~100)
 * @return 0成功，其他失败
*/
LB_EXPORT int lb_fun_notifyExtnSetVol(int index, int flag, int vol);

// 更新普通主机分机描述信息到托管主机
LB_EXPORT int lb_fun_notifyRepMst_updateExtnDescribeInfo(char *info);
LB_EXPORT int lb_fun_notifyRepMst_updateExtnCallinVoiceRingInfo(void);

LB_EXPORT int lb_fun_notifyHeaderMst_updateExtnDescribeInfo(char *info);
LB_EXPORT int lb_fun_notifyHeaderMst_updateExtnCallInVoiceRingInfo(void);

// 更新医院主机病人信息到附加主机
LB_EXPORT int lb_fun_notifyAdtlMst_updateExtnDescribeInfo(char *info);
LB_EXPORT int lb_fun_notifyAdtlMst_updateExtnCallInVoiceRingInfo(void);

LB_EXPORT int lb_fun_notifyCallTransfer(int displayNum,int transDestNum);

LB_EXPORT int lb_fun_pushToTalk(void);
LB_EXPORT int lb_fun_releaseToListen(void);

LB_EXPORT int lb_fun_notifyExtnDrSenserPyAd(BOOL bEna);

LB_EXPORT int lb_fun_selectATMTer(int terNum);

LB_EXPORT int lb_fun_myExtnOffLineVoiceNty_stop(int displayNum);

LB_EXPORT int lb_fun_plsyFileToRemote_onTalk_start(char *fileName);
LB_EXPORT int lb_fun_plsyFileToRemote_onTalk_stop(void);

LB_EXPORT int lb_fun_multiTalk_conference_start(int *membersList,int memberCnt,int vol);
LB_EXPORT int lb_fun_multiTalk_conference_stop(void);

LB_EXPORT int lb_fun_multiTalk_conduct_start(int *membersList,int memberCnt,int vol);
LB_EXPORT int lb_fun_multiTalk_conduct_stop(void);

LB_EXPORT int lb_fun_multiTalk_member_applySpeak(void);
LB_EXPORT int lb_fun_multiTalk_member_stopSpeak(void);

LB_EXPORT int lb_fun_multiTalk_cutOff_spk(int speakerDisplayNum);
LB_EXPORT int lb_fun_multiTalk_vol_adjust(int vol);

LB_EXPORT int lb_fun_multiTalk_memberVideo_view_start(int displayNum);
LB_EXPORT int lb_fun_multiTalk_memberVideo_view_stop(int displayNum);

LB_EXPORT int lb_fun_sendDTMF_onTalking(char cha);
LB_EXPORT int lb_fun_rebootAllExtn(void);

LB_EXPORT int lb_fun_video_session_start(int *membersList, int memberCnt, int vol);
LB_EXPORT int lb_fun_video_session_stop(void);

/* 声音控制(软件控制Sound_Port)
* @param bOn 播放Or采集
* @param index 声道序号(从0开始)
* @param vol 音量控制
*/
LB_EXPORT int lb_fun_audio_control(BOOL bOn, int index, int vol);

/* 获取相关信息
* @param str 字符数组
* @param cnt 字符数组大小
*/
LB_EXPORT int lb_fun_get_phone_agentInfo(char *str, int *size);

/*
* set register valule
* @param chip : chip index(default 0)
* @param data : write data
* @param len :data len
* @return 0 success , other failed
*/
LB_EXPORT int lb_fun_set_hardware_register(int chip, void *data, int len);

/*
* standard sip answer
*/
LB_EXPORT int lb_fun_stdSip_answer(int call_id);

/*
* standard sip hungup
*/
LB_EXPORT int lb_fun_stdSip_hungup(int call_id);

/* allow call upload or not
* @param enable	true allow upload false not allow
*/
LB_EXPORT int lb_fun_set_call_upload(BOOL enable);

LB_END_DECL
#endif