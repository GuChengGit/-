#ifndef _LB_INFO_H
#define _LB_INFO_H
#if defined(_WIN32_WCE) || defined(WIN32) || defined(__WIN32__) || defined(WIN64)
#include <windows.h>
#endif
#include "lb_headdef.h"
#include "lb_setting.h"

LB_BEGIN_DECL
typedef struct _lb_localInfo_s
{
	char ip[32];
	char mask[32];
	char gateway[32];
	char acc[16];
	char sn[16];
}lb_localInfo_s;

typedef struct _lb_terminalInfo_s
{
	int displayNum;              //���
	char ip[32];                 //IP��ַ
	char acc[16];                //sip�˺�
	char sn[16];                 //���к�
}lb_terminalInfo_s;

typedef struct _lb_extnVoiceRingInfo_s
{
	int mstNum;
	int slaveNum;
	int roomNum;
	int bedNum;
	int devType;
	int level;
}lb_extnVoiceRingInfo;

typedef struct _lb_remote_property_s
{
	int cameraNum;			//����ͷ����
	BOOL douTrack;			//˫����
}lb_remote_property_s;

/* ��ȡԶ���豸�������*/
LB_EXPORT int lb_info_getRmtProperty(lb_remote_property_s *rmtInfo);

LB_EXPORT int lb_info_getLocalInfo(lb_localInfo_s *localInfo);
LB_EXPORT int lb_info_displayNum_decode(const int displayNum,int *mstNum,int *extnNum,int *attachNum);
LB_EXPORT int lb_info_displayNum_build(int mstNum,int extnNum);
LB_EXPORT int lb_info_displayNum_build2(int mstNum,int extnNum,int attachNum);
LB_EXPORT BOOL lb_info_terminalIsMaster(int displayNum);

/*��ȡ���ΪdisplayNum���ն˵���Ϣ������ֵ��0 ��ʾ�ɹ���-1 ��ʾʧ�ܣ�ʧ�ܿ�����displayNum���Ϸ����߱���û�л�ȡ�����ն˵���Ϣ*/
LB_EXPORT int lb_info_getTerminalInfo(int displayNum,lb_terminalInfo_s *info);

LB_EXPORT int lb_info_getMstCnt(void);
LB_EXPORT int lb_info_getMstDisplayNumList(int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getExtnCnt_belongOneMst(const int mstDisplayNum);
LB_EXPORT int lb_info_getExtnDisplayNumList_belongOneMst(const int mstDisplayNum,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getMyExtnCnt(void);
LB_EXPORT int lb_info_getMyExtnDisplayNumList(int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getBeManagedMstCnt(void);
LB_EXPORT int lb_info_getBeManagedMstDisplayNumList(int *numList,int listCnt,int *numCnt);

/*�жϵ�ǰͨ���ĶԷ��Ƿ�������ͷ*/
LB_EXPORT BOOL lb_info_isRmtSupportVideo(int call_id);

/*�жϵ�ǰͨ���ĶԷ��Ƿ������ʾ��Ƶ*/
LB_EXPORT BOOL lb_info_isRmtVideoShowEna(int call_id);

/*�жϵ�ǰͨ���ĶԷ���Ƶ�Ƿ�ת*/
LB_EXPORT BOOL lb_info_isRmtVideoFlip(int call_id);

/*�жϵ�ǰͨ���ĶԷ�����ͷ�Ƿ��ǿɿصģ��е��豸������ͷ�ǿ��Կ��ƿ����͹رյģ���������������ͷ����֮ͨ������������Ҫ��Ҳ���ܣ�����������ͷ������رգ�
  ���е��豸������ͷ�ǲ��ɿصģ�������ӷֻ�����֮ͨ����������Ҫ�����������ͷ�ſ��Կ�����Ƶ*/
LB_EXPORT BOOL lb_info_isRmtVideoCtrEna(int call_id);

/*�жϵ�ǰͨ���ĶԷ��Ƿ���ATM����Ƶ���ߺ�*/
LB_EXPORT BOOL lb_info_isRmtProperty_ATMExtn(int call_id);  

/*��ȡ�����ܹ�Ͻ�ķֻ���������*/
LB_EXPORT int lb_info_getMaxExtnCntBelongMst(const int mstDispalyNum);
LB_EXPORT int lb_info_getMyExtnMaxCnt(void);

typedef void (LB_STDCALL *fp_extnDescriptInfo_notify)(int displayNum,char *info,int infoLen);
typedef void (LB_STDCALL *fp_extnCallInVoiceRingInfo_notify)(int displayNum,int rp_Num,int rp_hsptbedNum,int rp_hsptExtnType,int rp_hsptCareLvl);

LB_EXPORT int lb_info_extnDescriptInfo_decode(int mstDisplayNum,char *buf,fp_extnDescriptInfo_notify proFun);
LB_EXPORT int lb_info_extnCallInVoiceRingInfo_decode(int mstDisplayNum,char *buf,fp_extnCallInVoiceRingInfo_notify proFun);

LB_EXPORT int lb_info_extnDescriptInfo_package(char *buf,int bufSize,int extnNum,char *descInfo);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_prisonMode(int displayNum,int prisonRoomNum);
LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo_prisonMode(int displayNum,int *prisonRoomNum);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_universalMode(int displayNum,int universalNum);
LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo_universalMode(int displayNum,int *universalNum);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_userDefMode(int displayNum,int userDefNum);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo(int displayNum, int rp_Num, int rp_hsptbedNum, int rp_hsptExtnType, int rp_hsptCareLvl);

LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo(int displayNum,lb_voiceRing_mode_e *ringMode,int *rp_Num,int *rp_hsptbedNum,int *rp_hsptExtnType,int *rp_hsptCareLvl);

LB_EXPORT int lb_info_getMstReportMode(int mstDisplayNum,lb_voiceRing_mode_e *ringMode);

LB_EXPORT int lb_info_get_userManagePassWord(char *passW, int bufSize);    //��ȡ�û��������룬Ϊ�գ���ȶԱ�������кź���λ������ͱȶԻ�ȡ�����룬��ȡ�������Ǿ���MD5���ܵ�

//ϵͳ��ǰ������״̬�����ܶ����ϣ�����ͨ���У������зֻ����ں��룻
#define	LB_SYSWORKST_IDLE                           0x0000     //����
#define	LB_SYSWORKST_BC                             0x0001     //�㲥
#define	LB_SYSWORKST_CRCLISTEN                      0x0002     //ѭ������
#define	LB_SYSWORKST_CALLIN_RINGON                  0x0004     //��������
#define	LB_SYSWORKST_CALLOUT_PROG                   0x0008     //��������û�л���
#define	LB_SYSWORKST_CALLOUT_RINGBACK               0x0010     //���������Ѿ�����
#define	LB_SYSWORKST_CONNECTED                      0x0020     //����ͨ��

LB_EXPORT int lb_info_getSysWorkState(void);

LB_END_DECL
#endif