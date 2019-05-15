#ifndef _LB_FUN_H
#define _LB_FUN_H
#include "lb_headdef.h"

LB_BEGIN_DECL
LB_EXPORT int lb_fun_call(int displayNum);
LB_EXPORT int lb_fun_answer(int displayNum);
LB_EXPORT int lb_fun_answer_onOrder(void);    //������˳������������Ⱥ����
LB_EXPORT int lb_fun_hungup(int displayNum);
LB_EXPORT int lb_fun_hungup_curConnectedCall(void);   //�Ҷϵ�ǰ��ͨ��ͨ��

LB_EXPORT int lb_fun_crcListen_start(int mstDisplayNum);
LB_EXPORT int lb_fun_crcListen_stop(int mstDisplayNum);

LB_EXPORT int lb_fun_openExtnLock(int displayNum,int lock);

LB_EXPORT int lb_fun_beAgent_request(BOOL bOn);
LB_EXPORT int lb_fun_agent_response(int beAgentMstNum,BOOL bOn);

LB_EXPORT int lb_fun_localVideo_switch(BOOL bOn);
LB_EXPORT int lb_fun_notifyRmtVideo_on(void);

/*���д��þ���*/
LB_EXPORT int lb_fun_call_lobby_manager(BOOL bOn);

/* ���Ʊ�������ͷ����
 * @param bOn ���ؿ���
 * @param index ����ͷ���
*/
LB_EXPORT int lb_fun_localVideo_switch_ext(BOOL bOn, int index);

/* ������Ƶ���أ�����(�ر�)onvif
 * @param bOn ���ؿ���
 * @return 0�ɹ�������ʧ��
*/
LB_EXPORT int lb_fun_audio_onvif_switch(BOOL bOn);

/* ����������С
 * @param chip ��������(0Ϊ�����ȣ�1λ������)
 * @param data Ӳ������ֵ��FCF33B230D****��
 * @return 0�ɹ��� ����ʧ��
*/
LB_EXPORT int lb_fun_audio_set_vol(int chip, unsigned short nVol);

/*
* ����1288оƬ�����Ƿ����
* @param chip ��������(0Ϊ�����ȣ�1λ������)
* @param enable  false��ʾ����
* @return 0�ɹ��� ����ʧ��
*/
LB_EXPORT int lb_fun_audio_chip_mic_in_enable(int chip, BOOL enable);

/* ���ù���ģʽ������Խ�ģʽ�ʹ��ڶԽ�ģʽ��
 * @param mode ����ģʽ(0Ϊ����Խ�ģʽ��1Ϊ���ڶԽ�ģʽ)
 * @return 0�ɹ��� ����ʧ��
*/
LB_EXPORT int lb_fun_audio_set_mode(int mode);

/* �Ƿ�ָ���������
*/
LB_EXPORT int lb_fun_restore_get();

/* ���÷ֻ���������������
 * @param index ����ѡ��(������[0]��������[1])
 * @param flag �ɼ��Ͳ���ѡ��(0Ϊͬʱ����,1Ϊ�ɼ�������2Ϊ��������)
 * @param vol ��������(0~100)
 * @return 0�ɹ�������ʧ��
*/
LB_EXPORT int lb_fun_notifyExtnSetVol(int index, int flag, int vol);

// ������ͨ�����ֻ�������Ϣ���й�����
LB_EXPORT int lb_fun_notifyRepMst_updateExtnDescribeInfo(char *info);
LB_EXPORT int lb_fun_notifyRepMst_updateExtnCallinVoiceRingInfo(void);

LB_EXPORT int lb_fun_notifyHeaderMst_updateExtnDescribeInfo(char *info);
LB_EXPORT int lb_fun_notifyHeaderMst_updateExtnCallInVoiceRingInfo(void);

// ����ҽԺ����������Ϣ����������
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

/* ��������(�������Sound_Port)
* @param bOn ����Or�ɼ�
* @param index �������(��0��ʼ)
* @param vol ��������
*/
LB_EXPORT int lb_fun_audio_control(BOOL bOn, int index, int vol);

/* ��ȡ�����Ϣ
* @param str �ַ�����
* @param cnt �ַ������С
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