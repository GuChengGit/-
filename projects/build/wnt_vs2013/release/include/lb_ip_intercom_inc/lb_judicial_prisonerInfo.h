#ifndef _LB_JUDICIAL_PRISONERINFO_H
#define _LB_JUDICIAL_PRISONERINFO_H

#include "lb_headdef.h"

LB_BEGIN_DECL

#define MAX_DOOR_CELL_NUM           10  // �ſڻ��ϰ����ֻ�����

/**********************************��Ѻ��Ա��Ϣ************************************/
typedef struct _lb_prisonInfo{
	int mstNum;			// ������ 
	int slaveNum;			// �ֻ���
	int devRegType;			// �豸����
	int areaId;				// ����

	int  iRoomNum;          // ��ֺ�
	char *pCode;			// ��Ѻ��Ա���
	char *pBedNum;          // ����
	char *pRoomNum;         // ��ֺ�
	char *pName;			// ��Ѻ��Ա����
	char *pBranchCode;		// �����������
	char *pLevel;			// ���̼���
	char *pSex;				// �Ա�
	char *pBirthday;		// ��������
	char *pNation;			// ����
	char *pIDCard;			// ���֤����
	char *pICCard;			// IC����
	char *pBirthAddress;	// ����
	char *pAddress;			// ����
	char *pCrime;			// ����
	char *pCriminalRecord;	// �����¼
	char *pPenalRecord;		// ���̼�¼
	char *pJailTime;		// ���ʱ��
	char *pJailState;		// ��Ѻ״̬
	char *pTerm;			// ����
	int  iRegisteredState;	// ע��״̬
	int  iUpdateState;      // ����״̬
}lb_prisonInfo;

typedef struct _lb_extRelationInfo{
	int  childNum;          // �ֻ���
	int  slaveNum;          // �ſڻ���
	int  roomNum;           // X�ż��
}lb_extRelationInfo;

typedef struct _lb_prisonInfo_list{
	int				prisonInfoCnt;
	lb_prisonInfo	*prisonInfo;
}lb_prisonInfo_list;

typedef struct _lb_prisionCode
{
	char     *code;
}lb_prisionCode;

typedef struct _lb_prisionCode_list
{
	int                count;
	lb_prisionCode     *prisionCode;
}lb_prisionCode_list;

typedef struct _lb_extRelationInfo_list{
	int				    extRelationCnt;
	lb_extRelationInfo	*extRelationInfo;
}lb_extRelationInfo_list;

typedef struct _lb_branchInfo
{
	char *code;
	char *name;
}lb_branchInfo;

typedef struct _lb_branchInfo_list
{
	int            branchCnt;
	lb_branchInfo  *branchInfo;
}lb_branchInfo_list;

typedef struct _lb_doormach_extn_relation_info_list
{
	int old_slaveNum[600];
	int old_roomNum[600];
	int childNum[600];
	int count;
}lb_doormach_extn_relation_list;

typedef struct tagCellNumInfo
{
	int cellNum[MAX_DOOR_CELL_NUM];
	int childNum[MAX_DOOR_CELL_NUM];
	int count;
}lb_extCellNumInfo_list;

typedef struct _lb_prisonerCheckIn_info
{
	char strCode[32];			// ��Ѻ��Ա���
	char strCheckInTime[20];     //ǩ��ʱ�� ��ʽ��2016-09-20 20:58:08  �ϸ������ָ�ʽ
}lb_prisonerCheckIn_info_s;

typedef struct _lb_prisonerCheckIn_state
{
	char strCode[32];			// ��Ѻ��Ա���
	unsigned char  bState;     //ǩ��״̬
}lb_prisonerCheckIn_state_s;

LB_EXPORT int lb_judicial_prisonDev_init(int devRegType);

LB_EXPORT int lb_judicial_prisonerInfo_get(int extn_displayNum, int devRegType, int areaId, lb_prisonInfo_list **prisonerInfoList);
LB_EXPORT int lb_judicial_prisonerInfoList_destroy(lb_prisonInfo_list *prisonerInfoList);

LB_EXPORT int lb_judicial_extn2DoorMach_relationship_get(int DoorMach_displayNum, int devRegType, int areaId, lb_extRelationInfo_list **extnRelationInfoList);
LB_EXPORT int lb_judicial_extn2DoorMach_relationshipList_destroy(lb_extRelationInfo_list *extnRelationInfoList);
//�������ſڻ���ֻ��Ĺ�ϵ
LB_EXPORT int lb_judicial_extn2DoorMach_relationship_set(int doorMachDisplayNum, int devRegType, int *extnDisplayNumList, int extnCnt);

LB_EXPORT int lb_judicial_prisonerCheckIn_notify(int dest_displayNum, int devRegType, int areaId, int extn_displayNum, lb_prisonerCheckIn_info_s *prisonerCheckInInfo, int cnt);

//��ַֻ���ȡ�����ļ�ֺ�
LB_EXPORT int lb_judicial_extn_prisonRoomNum_get(void);

//��ȡ������
LB_EXPORT int lb_judicial_prisonBranch_get(char *branch_buf, int bufSize);

//�ſڻ�����
LB_EXPORT int lb_judicial_fun_doorMach_handleEmergency(void);

LB_END_DECL
#endif // !_LB_JUDICIAL_PRISONERINFO_H
