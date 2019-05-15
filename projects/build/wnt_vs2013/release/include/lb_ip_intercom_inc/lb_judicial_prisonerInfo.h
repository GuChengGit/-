#ifndef _LB_JUDICIAL_PRISONERINFO_H
#define _LB_JUDICIAL_PRISONERINFO_H

#include "lb_headdef.h"

LB_BEGIN_DECL

#define MAX_DOOR_CELL_NUM           10  // 门口机上绑定最大分机数量

/**********************************在押人员信息************************************/
typedef struct _lb_prisonInfo{
	int mstNum;			// 主机号 
	int slaveNum;			// 分机号
	int devRegType;			// 设备类型
	int areaId;				// 区号

	int  iRoomNum;          // 监仓号
	char *pCode;			// 在押人员编号
	char *pBedNum;          // 床号
	char *pRoomNum;         // 监仓号
	char *pName;			// 在押人员姓名
	char *pBranchCode;		// 所属监区编号
	char *pLevel;			// 服刑级别
	char *pSex;				// 性别
	char *pBirthday;		// 出生日期
	char *pNation;			// 民族
	char *pIDCard;			// 身份证号码
	char *pICCard;			// IC卡号
	char *pBirthAddress;	// 籍贯
	char *pAddress;			// 户籍
	char *pCrime;			// 罪名
	char *pCriminalRecord;	// 犯罪记录
	char *pPenalRecord;		// 服刑记录
	char *pJailTime;		// 入监时间
	char *pJailState;		// 在押状态
	char *pTerm;			// 刑期
	int  iRegisteredState;	// 注册状态
	int  iUpdateState;      // 更新状态
}lb_prisonInfo;

typedef struct _lb_extRelationInfo{
	int  childNum;          // 分机号
	int  slaveNum;          // 门口机号
	int  roomNum;           // X号监仓
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
	char strCode[32];			// 在押人员编号
	char strCheckInTime[20];     //签到时间 格式：2016-09-20 20:58:08  严格按照这种格式
}lb_prisonerCheckIn_info_s;

typedef struct _lb_prisonerCheckIn_state
{
	char strCode[32];			// 在押人员编号
	unsigned char  bState;     //签到状态
}lb_prisonerCheckIn_state_s;

LB_EXPORT int lb_judicial_prisonDev_init(int devRegType);

LB_EXPORT int lb_judicial_prisonerInfo_get(int extn_displayNum, int devRegType, int areaId, lb_prisonInfo_list **prisonerInfoList);
LB_EXPORT int lb_judicial_prisonerInfoList_destroy(lb_prisonInfo_list *prisonerInfoList);

LB_EXPORT int lb_judicial_extn2DoorMach_relationship_get(int DoorMach_displayNum, int devRegType, int areaId, lb_extRelationInfo_list **extnRelationInfoList);
LB_EXPORT int lb_judicial_extn2DoorMach_relationshipList_destroy(lb_extRelationInfo_list *extnRelationInfoList);
//主机绑定门口机与分机的关系
LB_EXPORT int lb_judicial_extn2DoorMach_relationship_set(int doorMachDisplayNum, int devRegType, int *extnDisplayNumList, int extnCnt);

LB_EXPORT int lb_judicial_prisonerCheckIn_notify(int dest_displayNum, int devRegType, int areaId, int extn_displayNum, lb_prisonerCheckIn_info_s *prisonerCheckInInfo, int cnt);

//监仓分机获取本机的监仓号
LB_EXPORT int lb_judicial_extn_prisonRoomNum_get(void);

//获取监区号
LB_EXPORT int lb_judicial_prisonBranch_get(char *branch_buf, int bufSize);

//门口机处警
LB_EXPORT int lb_judicial_fun_doorMach_handleEmergency(void);

LB_END_DECL
#endif // !_LB_JUDICIAL_PRISONERINFO_H
