#ifndef _LB_INFO_HOSPITAL_H
#define _LB_INFO_HOSPITAL_H
#if defined(_WIN32_WCE) || defined(WIN32) || defined(__WIN32__) || defined(WIN64)
#include <windows.h>
#endif
#include "lb_headdef.h"
#include "lb_setting.h"

LB_BEGIN_DECL

typedef struct _lb_patient_level_info
{

	char *name;
	char *color;
	char *fontColor;

}lb_patient_level_info;

// 单条病人信息
typedef struct _lb_patient_info
{
	int id;				// 序号
	int masterNum;		// 主机号	
	int doorNum;		// 门口机号
	int childNum;		// 分机号
	int type;			// 分机类型	
	char *room_number;	// 病房号
	char *bed_number;	// 病床号
	char *code;			// 病人编号
	char *name;			// 姓名
	char *abbr;			// 缩写
	int sex;			// 性别
	char *birthday;		// 出生日期
	char *checkin_date;	// 入院日期
	char *checkout_date;// 出院日期
	char *doctor;		// 医生姓名
	char *condition;	// 病情
	char *note;			// 医嘱
	int care_level;		// 护理级别
	int measure;		// 计量
	int diet;			// 饮食
	int isolation;		// 隔离
	int allergy;		// 过敏
	char *last_modify;	// 最后更新时间
	char *nurse;		// 护士姓名
	char *newInFlag;	// 新入院标识
	char *extInfo[20];
	lb_patient_level_info patientLevel[10];
}lb_patient_info;

LB_EXPORT int lb_info_hospital_registerPatientInfo(int mstNum, int extnNum, int areaId, int devRegType, lb_patient_info *info);

typedef struct _lb_responDoctorAndNurse{
	char doctor[4][32];
	char nurse[4][32];
}lb_responDoctorAndNurse;

LB_EXPORT int lb_info_hospital_registerResponDoctorAndNurse(int mstNum, int slaveNum, int areaId, int devRegType, lb_responDoctorAndNurse *info);

typedef void (LB_STDCALL *fp_bedExtnInfo_notify)(int displayNum, int areaId, int devRegType, int roomNum, int bedNum, int devType, char *name, int sex, int age, int year, int month, int day, char *doctor, char *condition, char *note, int level);
typedef void (LB_STDCALL *fp_extnPatientInfo_notify)(int displayNum, int areaId, int devRegType, char *name, int sex, int age, int year, int month, int day, char *doctor, char *condition, char *note, int level);

LB_EXPORT int lb_info_hospital_bedExtnInfo_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_bedExtnInfo_notify proFun);
LB_EXPORT int lb_info_hospital_extnPatientInfo_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnPatientInfo_notify proFun);
LB_EXPORT int lb_info_hospital_extnPatientInfo_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnPatientInfo_notify proFun);

typedef void (LB_STDCALL *fp_bedExtnInfo_fromAddress_notify)(lb_patient_info *patientInfo);
LB_EXPORT int lb_info_hospital_bedExtnInfo_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_bedExtnInfo_fromAddress_notify proFun);

LB_EXPORT int lb_info_hospital_extnPatientInfo_package(char *buf,int bufSize, int extnNum,int childNum, int roomNum, int devType, int bedNum, char *name, int sex, char *age, int year, int month, int day, char *doctor, char *condation, char *note, int level);


typedef void (LB_STDCALL *fp_extnPatientInfo_notify2)(int mstNum, int slaveNum, int childNum, int areaId, int devRegType, lb_patient_info *info);

/* @method 高级主机、托管主机、附加主机、智能终端解包病人信息
* @param mstNum 主机号
* @param areaId 病区号
* @param devRegType 设备类型
* @param *buf 信息缓存区
* @param proFun 信息处理回调函数
* @return 0-成功， -1-失败
*/
LB_EXPORT int lb_info_hospital_extnPatientInfo_decode2(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnPatientInfo_notify2 proFun);

/* @method 为高级主机、托管主机、附加主机打包病人信息
* @param *buf 内容缓存区
* @param extnNum 门口机号
* @param childNum 病床分机号
* @param *patientInfo 病人信息
* @return 0-成功， -1-失败
*/
LB_EXPORT int lb_info_hospital_extnPatientInfo_package2(char *buf, int extnNum, int childNum, lb_patient_info *patientInfo);

typedef void (LB_STDCALL *fp_extnDutyDoctor_fromAddress_notify)(int displayNum, int areaId, int devRegType, char **name, int len);
LB_EXPORT int lb_info_hospital_extnDutyDoctor_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnDutyDoctor_fromAddress_notify proFun);

typedef void (LB_STDCALL *fp_extnDutyNurse_fromAddress_notify)(int displayNum, int areaId, int devRegType,  char **name, int len);
LB_EXPORT int lb_info_hospital_extnDutyNurse_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnDutyNurse_fromAddress_notify proFun);


// 根据主机号和分机号获取门口机号接口(用于NN模式)
LB_EXPORT int lb_info_hospital_getDoorMachineNum(int mstNum, int slaveNum, int areaId, int devRegType);
// 根据病房病床号获取分机号
LB_EXPORT int lb_info_hospital_getChildNumFromRoomBedNum(int roomNum, int bedNum);
LB_EXPORT int lb_info_hospital_getDisplayNumCnt_fromReportInfo(int roomNum, int bedNum);
LB_EXPORT int lb_info_hospital_getDisplayNumList_fromRoomReportInfo(int roomNum, int bedNum, int *list, int listCnt, int *cnt);
LB_EXPORT int lb_info_hospital_getChildNumCnt_belongPriADExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType);
LB_EXPORT int lb_info_hospital_getChildNumList_belongPriADExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType, int *childNum, int cnt, int *lstCnt);
LB_EXPORT int lb_info_hospital_getRoomNum_fromExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType, char *roomNum, int rLen);

// 根据病房病床号获取分机号
LB_EXPORT int lb_info_hospital_getChildNumFromRoomBedNum_ext(char *roomNum, char *bedNum);

//获取分机呼叫信息
LB_EXPORT int lb_info_hospital_getSlaveInfo(int displayNum, int areaId, int devRegType, char *info, int *len);


// 获取护理标识自定义标志
LB_EXPORT int lb_info_getCareInfoUserDefineState();
// 设置护理标识自定义标志,标识护理标识信息用户自定义功能是否启用
LB_EXPORT int lb_info_setCareInfoUserDefineState(int state);

typedef enum _CareLevelInfoItem
{
	CARE_LEVEL_INFO_CARE_DESC = 0, //单个护理项描述
	CARE_LEVEL_INFO_CARE_LEVEL, // 单个护理级别信息 
	CARE_LEVEL_INFO_MEASURE, // 单个计量信息
	CARE_LEVEL_INFO_DIET,  // 单个饮食信息
	CARE_LEVEL_INFO_ISOLATION, //单个隔离信息
	CARE_LEVEL_INFO_ALLERGY //单个过敏信息
}CareLevelInfoItem;

// 获取护理相关的信息
LB_EXPORT int lb_info_getCareLevelInfo(int level, CareLevelInfoItem item, char *value, int len, int *color);
// 设置护理相关的信息
LB_EXPORT int lb_info_setCareLevelInfo(int level, CareLevelInfoItem item, char *value, int color);

LB_END_DECL
#endif