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
	int areaId;                //�������ݽ�����ͨѶ����ַ�����ɵģ������޸ģ�Ψһ
	int areaNum;               //������ʾ���߲��ţ������û�ʶ���û������ڵ�ַ�������ã��༭
	char areaDesc[32];         //���������ƻ���������Ϣ
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

/*��ȡ���ΪdisplayNum���ն˵���Ϣ������ֵ��0 ��ʾ�ɹ���-1 ��ʾʧ�ܣ�ʧ�ܿ�����displayNum���Ϸ����߱���û�л�ȡ�����ն˵���Ϣ*/
LB_EXPORT int lb_info_getTerminalInfo_ext(int displayNum,int areaId,int devRegType,lb_terminalInfo_s *info);

LB_EXPORT int lb_info_getMstCnt_ext(int areaId);
LB_EXPORT int lb_info_getMstDisplayNumList_ext(int areaId,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getExtnCnt_belongOneMst_ext(const int mstDisplayNum,int areaId,int devRegType);
LB_EXPORT int lb_info_getExtnDisplayNumList_belongOneMst_ext(const int mstDisplayNum,int areaId,int devRegType,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getMyExtnCnt_ext(int devRegType);
LB_EXPORT int lb_info_getMyExtnDisplayNumList_ext(int devRegType,int *numList,int listCnt,int *numCnt);
LB_EXPORT int lb_info_getBeManagedMstDisplayNumList_ext(lb_devNum_s *infoList,int listCnt,int *infoCnt);

/*��ȡ�����ܹ�Ͻ�ķֻ���������*/
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

/* @method ��������������Ϣ
* @param displayNum �ֻ���ʾ��
* @param areaId ���� (Ĭ�� 0)
* @param devRegType �豸����
* @param *ringMode ��������ģʽ
* @param *rp_num �����
* @param *rp_hsptbedNum ��λ��
* @param *rp_hsptExtnType �豸���� 0-�����ֻ� 1-ϴ�ּ�ֻ�
* @param *rp_hsptCareLvl ������
* @return 0-�ɹ��� -1-ʧ��
*/
LB_EXPORT int lb_info_setExtnCallInVoiceRingInfo_ext2(int displayNum, int areaId, int devRegType, char *rp_num, char *rp_hsptbedNum, int rp_hsptExtnType, char *rp_hsptCareLvl);

/* @method ��ȡ����������Ϣ
* @param displayNum �ֻ���ʾ��
* @param areaId ���� (Ĭ�� 0)
* @param devRegType �豸����
* @param *ringMode ��������ģʽ
* @param *rp_num �����
* @param *rp_hsptbedNum ��λ��
* @param *rp_hsptExtnType �豸���� 0-�����ֻ� 1-ϴ�ּ�ֻ�
* @param *rp_hsptCareLvl ������
* @return 0-�ɹ��� -1-ʧ��
*/
LB_EXPORT int lb_info_getExtnCallInVoiceRingInfo_ext2(int displayNum, int areaId, int devRegType, lb_voiceRing_mode_e *ringMode, char *rp_num, char *rp_hsptbedNum, int *rp_hsptExtnType, char *rp_hsptCareLvl);

LB_EXPORT int lb_info_getExtnCallInVoiceRingInfoCnt(int mstDisplayNum, int areaId, int devRegType);

LB_EXPORT int lb_info_getExtnCallInVoiceRingInfoList(int mstDisplayNum, int areaId, int devRegType, lb_extnVoiceRingInfo *info, int infoCnt, int *extnCnt);

LB_EXPORT int lb_info_clearExtnCallInVoiceRingInfo_withMaster(int mstDisplayNum, int areaId, int devRegType);

typedef struct _lb_info_ext{
	int mstNum;				//������
	int slaveNum;			//�ֻ���
	char *PrisonCellNum;	//��ֺ�
	char *PrisonCellNumExt;	//��չ��
	char *des;				//������Ϣ
}lb_info_ext;

LB_EXPORT int lb_info_registerExtnInfo(int mstNum, int extnNum, int areaId, int devRegType, lb_info_ext *info);

LB_EXPORT int lb_info_getUserDefineCnt(int oddNum);

LB_EXPORT int lb_info_getUserDefineList(int oddNum, int *extnList, int *userList, int listCnt, int *cnt);

//��ȡ�ֻ��Զ��尴ť������Ϣ	
LB_EXPORT char* lb_info_getBtnReportInfo_ext(int displayNum, int areaId, int devRegType);

LB_END_DECL
#endif