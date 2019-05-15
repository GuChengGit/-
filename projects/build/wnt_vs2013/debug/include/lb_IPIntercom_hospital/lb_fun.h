#ifndef _LB_FUN_H
#define _LB_FUN_H
#include "lb_headdef.h"

LB_BEGIN_DECL

// 更新医院主机病人信息到托管主机
LB_EXPORT int lb_fun_notifyRepMst_updatePatientInfo(char *info);

// 更新医院主机病人信息到上级主机
LB_EXPORT int lb_fun_notifyHeaderMst_updatePatientInfo(char *info);

// 更新医院主机病人信息到附加主机
LB_EXPORT int lb_fun_notifyAdtlMst_updatePatientInfo(char *info);

// 从地址盒获取病人信息
LB_EXPORT int lb_fun_getPatientInfo_belongToMaster(int mstNum, int areaId, int devRegType);

// 从地址盒获取病人信息（分机）
LB_EXPORT int lb_fun_getPatientInfo_belongToSlave(int mstNum, int slaveNum, int areaId, int devRetType);

// 从地址盒获取责任医生列表
LB_EXPORT int lb_fun_getDutyDoctor_belongToMaster(int mstNum, int areaId, int devRegType);

// 从地址盒获取责任护士列表
LB_EXPORT int lb_fun_getDutyNurse_belongToMaster(int mstNum, int areaId, int devRegType);

LB_EXPORT int lb_fun_getAllPatientInfoFormHis();

LB_EXPORT int lb_fun_notifyExtnBackLightStatus(BOOL bState);

// 呼叫护工
LB_EXPORT int lb_fun_callOrderlie(BOOL bState);

// 换药/提醒
LB_EXPORT int lb_fun_dress(BOOL bState);

LB_END_DECL
#endif