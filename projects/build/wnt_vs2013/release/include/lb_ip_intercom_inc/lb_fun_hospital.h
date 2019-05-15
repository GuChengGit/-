#ifndef _LB_FUN_HOSPITAL_H
#define _LB_FUN_HOSPITAL_H
#include "lb_headdef.h"

LB_BEGIN_DECL

// ����ҽԺ����������Ϣ���й�����
LB_EXPORT int lb_fun_hospital_notifyRepMst_updatePatientInfo(char *info);

// ����ҽԺ����������Ϣ���ϼ�����
LB_EXPORT int lb_fun_hospital_notifyHeaderMst_updatePatientInfo(char *info);

// ����ҽԺ����������Ϣ����������
LB_EXPORT int lb_fun_hospital_notifyAdtlMst_updatePatientInfo(char *info);

// �ӵ�ַ�л�ȡ������Ϣ
LB_EXPORT int lb_fun_hospiatl_getPatientInfo_belongToMaster(int mstNum, int areaId, int devRegType);

// �ӵ�ַ�л�ȡ������Ϣ���ֻ���
LB_EXPORT int lb_fun_hospital_getPatientInfo_belongToSlave(int mstNum, int slaveNum, int areaId, int devRetType);

// �ӵ�ַ�л�ȡ����ҽ���б�
LB_EXPORT int lb_fun_hospital_getDutyDoctor_belongToMaster(int mstNum, int areaId, int devRegType);

// �ӵ�ַ�л�ȡ���λ�ʿ�б�
LB_EXPORT int lb_fun_hospital_getDutyNurse_belongToMaster(int mstNum, int areaId, int devRegType);

LB_EXPORT int lb_fun_hospital_getAllPatientInfoFormHis();

LB_EXPORT int lb_fun_hospital_notifyExtnBackLightStatus(BOOL bState);

// ���л���
LB_EXPORT int lb_fun_hospital_callOrderlie(BOOL bState);

// ��ҩ/����
LB_EXPORT int lb_fun_hospital_dress(BOOL bState);

//--------------------------------------Anyjune------------------------------
/*	user login in
* @param login	�û�����
* @return 0 success or other failed
*/
LB_EXPORT int lb_fun_phone_login(char *login, char *password);

/*	user login out
* @param login �û�����
* @return 0 success or other failed
*/
LB_EXPORT int lb_fun_phone_logout(char *login);

/*	query user ID
* @param	login �û�����
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