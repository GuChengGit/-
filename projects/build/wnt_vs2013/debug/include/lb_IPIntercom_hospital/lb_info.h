#ifndef _LB_INFO_H
#define _LB_INFO_H
#if defined(_WIN32_WCE) || defined(WIN32) || defined(__WIN32__) || defined(WIN64)
#include <windows.h>
#endif
#include "lb_headdef.h"
#include "lb_info_hospital.h"

LB_BEGIN_DECL

LB_EXPORT int lb_info_registerPatientInfo(int mstNum, int extnNum, int areaId, int devRegType, lb_patient_info *info);

LB_EXPORT int lb_info_registerResponDoctorAndNurse(int mstNum, int slaveNum, int areaId, int devRegType, lb_responDoctorAndNurse *info);

LB_EXPORT int lb_info_bedExtnInfo_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_bedExtnInfo_notify proFun);
LB_EXPORT int lb_info_extnPatientInfo_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnPatientInfo_notify proFun);
LB_EXPORT int lb_info_extnPatientInfo_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnPatientInfo_notify proFun);

LB_EXPORT int lb_info_hospital_bedExtnInfo_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_bedExtnInfo_fromAddress_notify proFun);

LB_EXPORT int lb_info_extnPatientInfo_package(char *buf,int bufSize, int extnNum,int childNum, int roomNum, int devType, int bedNum, char *name, int sex, char *age, int year, int month, int day, char *doctor, char *condation, char *note, int level);

LB_EXPORT int lb_info_hospital_extnDutyDoctor_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnDutyDoctor_fromAddress_notify proFun);

LB_EXPORT int lb_info_extnDutyNurse_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnDutyNurse_fromAddress_notify proFun);


// 根据主机号和分机号获取门口机号接口(用于NN模式)
LB_EXPORT int lb_info_getDoorMachineNum(int mstNum, int slaveNum, int areaId, int devRegType);
// 根据病房病床号获取分机号
LB_EXPORT int lb_info_getChildNumFromRoomBedNum(int roomNum, int bedNum);
LB_EXPORT int lb_info_getDisplayNumCnt_fromReportInfo(int roomNum, int bedNum);
LB_EXPORT int lb_info_getDisplayNumList_fromRoomReportInfo(int roomNum, int bedNum, int *list, int listCnt, int *cnt);
LB_EXPORT int lb_info_getChildNumCnt_belongPriADExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType);
LB_EXPORT int lb_info_getChildNumList_belongPriADExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType, int *childNum, int cnt, int *lstCnt);
LB_EXPORT int lb_info_getRoomNum_fromExtn(int mstNum, int slaveNum, int areaId, int devRegType);


LB_END_DECL
#endif