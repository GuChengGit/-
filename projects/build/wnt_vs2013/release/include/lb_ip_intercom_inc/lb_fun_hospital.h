#ifndef _LB_FUN_HOSPITAL_H
#define _LB_FUN_HOSPITAL_H
#include "lb_headdef.h"

LB_BEGIN_DECL

// 更新医院主机病人信息到托管主机
LB_EXPORT int lb_fun_hospital_notifyRepMst_updatePatientInfo(char *info);

// 更新医院主机病人信息到上级主机
LB_EXPORT int lb_fun_hospital_notifyHeaderMst_updatePatientInfo(char *info);

// 更新医院主机病人信息到附加主机
LB_EXPORT int lb_fun_hospital_notifyAdtlMst_updatePatientInfo(char *info);

// 从地址盒获取病人信息
LB_EXPORT int lb_fun_hospiatl_getPatientInfo_belongToMaster(int mstNum, int areaId, int devRegType);

// 从地址盒获取病人信息（分机）
LB_EXPORT int lb_fun_hospital_getPatientInfo_belongToSlave(int mstNum, int slaveNum, int areaId, int devRetType);

// 从地址盒获取责任医生列表
LB_EXPORT int lb_fun_hospital_getDutyDoctor_belongToMaster(int mstNum, int areaId, int devRegType);

// 从地址盒获取责任护士列表
LB_EXPORT int lb_fun_hospital_getDutyNurse_belongToMaster(int mstNum, int areaId, int devRegType);

LB_EXPORT int lb_fun_hospital_getAllPatientInfoFormHis();

LB_EXPORT int lb_fun_hospital_notifyExtnBackLightStatus(BOOL bState);

// 呼叫护工
LB_EXPORT int lb_fun_hospital_callOrderlie(BOOL bState);

// 换药/提醒
LB_EXPORT int lb_fun_hospital_dress(BOOL bState);

//--------------------------------------Anyjune------------------------------
/*	user login in
* @param login	用户工号
* @return 0 success or other failed
*/
LB_EXPORT int lb_fun_phone_login(char *login, char *password);

/*	user login out
* @param login 用户工号
* @return 0 success or other failed
*/
LB_EXPORT int lb_fun_phone_logout(char *login);

/*	query user ID
* @param	login 用户工号
* @return 0 success or other failed
*/
LB_EXPORT int lb_fun_phone_querySlaveNum(char *login);

/*	get current bed list
* @return 0 success or other failed
*/
LB_EXPORT int lb_fun_phone_getBedList(char *bedList, int *size);

/* call other phone
* @param displayNum	  other device num
* @param areaId		Area displayNum(default 0)
* @param devRetType		device type (default 0)
* @return 0 success or other failed
*/
LB_EXPORT int lb_fun_phone_call(int displayNum, int areaId, int devRegType);

//--------------------------------------Anyjune------------------------------

LB_END_DECL
#endif