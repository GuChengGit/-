#ifndef _LB_INFO_EXT_H
#define _LB_INFO_EXT_H
#if defined(_WIN32_WCE) || defined(WIN32) || defined(__WIN32__) || defined(WIN64)
#include <windows.h>
#endif
#include "lb_info.h"
#include "lb_headdef.h"

LB_BEGIN_DECL

typedef struct _lb_areaNumInfo_s
{
	int areaId;                //用于数据交互和通讯，地址盒生成的，不可修改，唯一
	int areaNum;               //用于显示或者拨号，便于用户识别，用户可以在地址盒上设置，编辑
	char areaDesc[32];         //该区的名称或者描述信息
} lb_areaNumInfo_s;

typedef struct _lb_devNum_s
{
	int areaId;
	int devRegType;
	int displayNum;
} lb_devNum_s;

LB_EXPORT int lb_info_getAareaCnt(void);
LB_EXPORT int lb_info_getAreaNumInfoList(lb_areaNumInfo_s *areaNumInfoList,int bufListCnt,int *areaCnt);
LB_EXPORT int lb_info_getAreaNum_fromAreaId(int areaId);
LB_EXPORT int lb_info_getAreaId_fromAreaNum(int areaNum);
LB_EXPORT char *lb_info_getAreaDesc_fromAreaId(int areaId,char *descBuf,int bufSize);
LB_EXPORT int lb_info_setAreaDesc_fromAreaId(int areaId,char *desc);

/*获取编号为displayNum的终端的信息，返回值：0 表示成功；-1 表示失败，失败可能是displayNum不合法或者本地没有获取到该终端的信息*/
LB_EXPORT int lb_info_getTerminalInfo_ext(int displayNum,int areaId,int devRegType,lb_terminalInfo_s *info);

LB_EXPORT int lb_info_getMstCnt_ext(int areaId);
LB_EXPORT int lb_info_getMstDisplayNumList_ext(int areaId,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getExtnCnt_belongOneMst_ext(const int mstDisplayNum,int areaId,int devRegType);
LB_EXPORT int lb_info_getExtnDisplayNumList_belongOneMst_ext(const int mstDisplayNum,int areaId,int devRegType,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getMyExtnCnt_ext(int devRegType);
LB_EXPORT int lb_info_getMyExtnDisplayNumList_ext(int devRegType,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getBeManagedMstDisplayNumList_ext(lb_devNum_s *infoList,int listCnt,int *infoCnt);

/*获取主机能管辖的分机的最大个数*/
LB_EXPORT int lb_info_getMaxExtnCntBelongMst_ext(const int mstDispalyNum,int areaId,int devRegType);

typedef void (LB_STDCALL *fp_extnDescriptInfo_notify_ext)(int displayNum,int areaId,int devRegType,char *info,int infoLen);
typedef void (LB_STDCALL *fp_extnCallInVoiceRingInfo_notify_ext)(int displayNum,int areaId,int devRegType,int rp_Num,int rp_hsptbedNum,int rp_hsptExtnType,int rp_hsptCareLvl);

LB_EXPORT int lb_info_extnDescriptInfo_decode_ext(int mstDisplayNum,int areaId,int devRegType,char *buf,fp_extnDescriptInfo_notify_ext proFun);
LB_EXPORT int lb_info_extnInfo_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnDescriptInfo_notify_ext proFun);
LB_EXPORT int lb_info_extnCallInVoiceRingInfo_decode_ext(int mstDisplayNum,int areaId,int devRegType,char *buf,fp_extnCallInVoiceRingInfo_notify_ext proFun);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_userDefMode_ext(int displayNum,int areaId,int devRegType,int userDefNum);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_prisonMode_ext(int displayNum, int areaId, int devRegType, int prisonRoomNum);
LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo_prisonMode_ext(int displayNum, int areaId, int devRegType, int *prisonRoomNum);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_universalMode_ext(int displayNum, int areaId, int devRegType, int universalNum);
LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo_universalMode_ext(int displayNum, int areaId, int devRegType, int *universalNum);

LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_ext(int displayNum, int areaId, int devRegType, int rp_Num, int rp_hsptbedNum, int rp_hsptExtnType, int rp_hsptCareLvl);

LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo_ext(int displayNum, int areaId, int devRegType, lb_voiceRing_mode_e *ringMode, int *rp_Num, int *rp_hsptbedNum, int *rp_hsptExtnType, int *rp_hsptCareLvl);
LB_EXPORT int lb_info_getMstReportMode_ext(int mstDisplayNum, int areaId, int devRegType, lb_voiceRing_mode_e *ringMode);

/* @method 设置语音播报信息
* @param displayNum 分机显示号
* @param areaId 区号 (默认 0)
* @param devRegType 设备类型
* @param *ringMode 语音播报模式
* @param *rp_num 房间号
* @param *rp_hsptbedNum 床位号
* @param *rp_hsptExtnType 设备类型 0-病床分机 1-洗手间分机
* @param *rp_hsptCareLvl 护理级别
* @return 0-成功， -1-失败
*/
LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_ext2(int displayNum, int areaId, int devRegType, char *rp_num, char *rp_hsptbedNum, int rp_hsptExtnType, char *rp_hsptCareLvl);

/* @method 获取语音播报信息
* @param displayNum 分机显示号
* @param areaId 区号 (默认 0)
* @param devRegType 设备类型
* @param *ringMode 语音播报模式
* @param *rp_num 房间号
* @param *rp_hsptbedNum 床位号
* @param *rp_hsptExtnType 设备类型 0-病床分机 1-洗手间分机
* @param *rp_hsptCareLvl 护理级别
* @return 0-成功， -1-失败
*/
LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo_ext2(int displayNum, int areaId, int devRegType, lb_voiceRing_mode_e *ringMode, char *rp_num, char *rp_hsptbedNum, int *rp_hsptExtnType, char *rp_hsptCareLvl);

LB_EXPORT int lb_info_getExtnCallInVoiceRingInfoCnt(int mstDisplayNum, int areaId, int devRegType);

LB_EXPORT int lb_info_getExtnCallInVoiceRingInfoList(int mstDisplayNum, int areaId, int devRegType, lb_extnVoiceRingInfo *info, int infoCnt, int *extnCnt);

LB_EXPORT int lb_info_clearExtnCallInVoiceRingInfo_withMaster(int mstDisplayNum, int areaId, int devRegType);

typedef struct _lb_info_ext{
	int mstNum;				//主机号
	int slaveNum;			//分机号
	char *PrisonCellNum;	//监仓号
	char *PrisonCellNumExt;	//扩展号
	char *des;				//描述信息
}lb_info_ext;

LB_EXPORT int lb_info_registerExtnInfo(int mstNum, int extnNum, int areaId, int devRegType, lb_info_ext *info);

LB_EXPORT int lb_info_getUserDefineCnt(int oddNum);

LB_EXPORT int lb_info_getUserDefineList(int oddNum, int *extnList, int *userList, int listCnt, int *cnt);

//获取分机自定义按钮播报信息	
LB_EXPORT char* lb_info_getBtnReportInfo_ext(int displayNum, int areaId, int devRegType);

LB_END_DECL
#endif