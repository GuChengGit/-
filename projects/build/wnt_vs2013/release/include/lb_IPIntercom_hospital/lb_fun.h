#ifndef _LB_FUN_H
#define _LB_FUN_H
#include "lb_headdef.h"

LB_BEGIN_DECL

// ����ҽԺ����������Ϣ���й�����
LB_EXPORT int lb_fun_notifyRepMst_updatePatientInfo(char *info);

// ����ҽԺ����������Ϣ���ϼ�����
LB_EXPORT int lb_fun_notifyHeaderMst_updatePatientInfo(char *info);

// ����ҽԺ����������Ϣ����������
LB_EXPORT int lb_fun_notifyAdtlMst_updatePatientInfo(char *info);

// �ӵ�ַ�л�ȡ������Ϣ
LB_EXPORT int lb_fun_getPatientInfo_belongToMaster(int mstNum, int areaId, int devRegType);

// �ӵ�ַ�л�ȡ������Ϣ���ֻ���
LB_EXPORT int lb_fun_getPatientInfo_belongToSlave(int mstNum, int slaveNum, int areaId, int devRetType);

// �ӵ�ַ�л�ȡ����ҽ���б�
LB_EXPORT int lb_fun_getDutyDoctor_belongToMaster(int mstNum, int areaId, int devRegType);

// �ӵ�ַ�л�ȡ���λ�ʿ�б�
LB_EXPORT int lb_fun_getDutyNurse_belongToMaster(int mstNum, int areaId, int devRegType);

LB_EXPORT int lb_fun_getAllPatientInfoFormHis();

LB_EXPORT int lb_fun_notifyExtnBackLightStatus(BOOL bState);

// ���л���
LB_EXPORT int lb_fun_callOrderlie(BOOL bState);

// ��ҩ/����
LB_EXPORT int lb_fun_dress(BOOL bState);

LB_END_DECL
#endif