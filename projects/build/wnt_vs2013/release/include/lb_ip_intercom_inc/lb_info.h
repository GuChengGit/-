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
	int displayNum;              //编号
	char ip[32];                 //IP地址
	char acc[16];                //sip账号
	char sn[16];                 //序列号
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
	int cameraNum;			//摄像头个数
	BOOL douTrack;			//双声道
}lb_remote_property_s;

/* 获取远程设备相关属性*/
LB_EXPORT int lb_info_getRmtProperty(lb_remote_property_s *rmtInfo);

LB_EXPORT int lb_info_getLocalInfo(lb_localInfo_s *localInfo);
LB_EXPORT int lb_info_displayNum_decode(const int displayNum,int *mstNum,int *extnNum,int *attachNum);
LB_EXPORT int lb_info_displayNum_build(int mstNum,int extnNum);
LB_EXPORT int lb_info_displayNum_build2(int mstNum,int extnNum,int attachNum);
LB_EXPORT BOOL lb_info_terminalIsMaster(int displayNum);

/*获取编号为displayNum的终端的信息，返回值：0 表示成功；-1 表示失败，失败可能是displayNum不合法或者本地没有获取到该终端的信息*/
LB_EXPORT int lb_info_getTerminalInfo(int displayNum,lb_terminalInfo_s *info);

LB_EXPORT int lb_info_getMstCnt(void);
LB_EXPORT int lb_info_getMstDisplayNumList(int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getExtnCnt_belongOneMst(const int mstDisplayNum);
LB_EXPORT int lb_info_getExtnDisplayNumList_belongOneMst(const int mstDisplayNum,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getMyExtnCnt(void);
LB_EXPORT int lb_info_getMyExtnDisplayNumList(int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getBeManagedMstCnt(void);
LB_EXPORT int lb_info_getBeManagedMstDisplayNumList(int *numList,int listCnt,int *numCnt);

/*判断当前通话的对方是否有摄像头*/
LB_EXPORT BOOL lb_info_isRmtSupportVideo(int call_id);

/*判断当前通话的对方是否可以显示视频*/
LB_EXPORT BOOL lb_info_isRmtVideoShowEna(int call_id);

/*判断当前通话的对方视频是否翻转*/
LB_EXPORT BOOL lb_info_isRmtVideoFlip(int call_id);

/*判断当前通话的对方摄像头是否是可控的，有的设备的摄像头是可以控制开启和关闭的，例如主机的摄像头，与之通话，本机不需要（也不能）控制其摄像头开启或关闭；
  而有的设备的摄像头是不可控的，例如可视分机，与之通话的主机需要控制其打开摄像头才可以看到视频*/
LB_EXPORT BOOL lb_info_isRmtVideoCtrEna(int call_id);

/*判断当前通话的对方是否是ATM音视频接线盒*/
LB_EXPORT BOOL lb_info_isRmtProperty_ATMExtn(int call_id);  

/*获取主机能管辖的分机的最大个数*/
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

LB_EXPORT int lb_info_get_userManagePassWord(char *passW, int bufSize);    //获取用户管理密码，为空，则比对本身的序列号后四位，否则就比对获取的密码，获取的密码是经过MD5加密的

//系统当前所处的状态，可能多个组合，例如通话中，可能有分机正在呼入；
#define	LB_SYSWORKST_IDLE                           0x0000     //待机
#define	LB_SYSWORKST_BC                             0x0001     //广播
#define	LB_SYSWORKST_CRCLISTEN                      0x0002     //循环监听
#define	LB_SYSWORKST_CALLIN_RINGON                  0x0004     //呼入振铃
#define	LB_SYSWORKST_CALLOUT_PROG                   0x0008     //呼出，但没有回铃
#define	LB_SYSWORKST_CALLOUT_RINGBACK               0x0010     //呼出并且已经振铃
#define	LB_SYSWORKST_CONNECTED                      0x0020     //正在通话

LB_EXPORT int lb_info_getSysWorkState(void);

LB_END_DECL
#endif