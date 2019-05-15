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

// ����������Ϣ
typedef struct _lb_patient_info
{
	int id;				// ���
	int masterNum;		// ������	
	int doorNum;		// �ſڻ���
	int childNum;		// �ֻ���
	int type;			// �ֻ�����	
	char *room_number;	// ������
	char *bed_number;	// ������
	char *code;			// ���˱��
	char *name;			// ����
	char *abbr;			// ��д
	int sex;			// �Ա�
	char *birthday;		// ��������
	char *checkin_date;	// ��Ժ����
	char *checkout_date;// ��Ժ����
	char *doctor;		// ҽ������
	char *condition;	// ����
	char *note;			// ҽ��
	int care_level;		// ������
	int measure;		// ����
	int diet;			// ��ʳ
	int isolation;		// ����
	int allergy;		// ����
	char *last_modify;	// ������ʱ��
	char *nurse;		// ��ʿ����
	char *newInFlag;	// ����Ժ��ʶ
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

/* @method �߼��������й����������������������ն˽��������Ϣ
* @param mstNum ������
* @param areaId ������
* @param devRegType �豸����
* @param *buf ��Ϣ������
* @param proFun ��Ϣ����ص�����
* @return 0-�ɹ��� -1-ʧ��
*/
LB_EXPORT int lb_info_hospital_extnPatientInfo_decode2(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnPatientInfo_notify2 proFun);

/* @method Ϊ�߼��������й������������������������Ϣ
* @param *buf ���ݻ�����
* @param extnNum �ſڻ���
* @param childNum �����ֻ���
* @param *patientInfo ������Ϣ
* @return 0-�ɹ��� -1-ʧ��
*/
LB_EXPORT int lb_info_hospital_extnPatientInfo_package2(char *buf, int extnNum, int childNum, lb_patient_info *patientInfo);

typedef void (LB_STDCALL *fp_extnDutyDoctor_fromAddress_notify)(int displayNum, int areaId, int devRegType, char **name, int len);
LB_EXPORT int lb_info_hospital_extnDutyDoctor_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnDutyDoctor_fromAddress_notify proFun);

typedef void (LB_STDCALL *fp_extnDutyNurse_fromAddress_notify)(int displayNum, int areaId, int devRegType,  char **name, int len);
LB_EXPORT int lb_info_hospital_extnDutyNurse_fromAddress_decode(int mstDisplayNum, int areaId, int devRegType, char *buf, fp_extnDutyNurse_fromAddress_notify proFun);


// ���������źͷֻ��Ż�ȡ�ſڻ��Žӿ�(����NNģʽ)
LB_EXPORT int lb_info_hospital_getDoorMachineNum(int mstNum, int slaveNum, int areaId, int devRegType);
// ���ݲ��������Ż�ȡ�ֻ���
LB_EXPORT int lb_info_hospital_getChildNumFromRoomBedNum(int roomNum, int bedNum);
LB_EXPORT int lb_info_hospital_getDisplayNumCnt_fromReportInfo(int roomNum, int bedNum);
LB_EXPORT int lb_info_hospital_getDisplayNumList_fromRoomReportInfo(int roomNum, int bedNum, int *list, int listCnt, int *cnt);
LB_EXPORT int lb_info_hospital_getChildNumCnt_belongPriADExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType);
LB_EXPORT int lb_info_hospital_getChildNumList_belongPriADExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType, int *childNum, int cnt, int *lstCnt);
LB_EXPORT int lb_info_hospital_getRoomNum_fromExtn(int mstDisplayNum, int slaveNum, int areaId, int devRegType, char *roomNum, int rLen);

// ���ݲ��������Ż�ȡ�ֻ���
LB_EXPORT int lb_info_hospital_getChildNumFromRoomBedNum_ext(char *roomNum, char *bedNum);

//��ȡ�ֻ�������Ϣ
LB_EXPORT int lb_info_hospital_getSlaveInfo(int displayNum, int areaId, int devRegType, char *info, int *len);


// ��ȡ�����ʶ�Զ����־
LB_EXPORT int lb_info_getCareInfoUserDefineState();
// ���û����ʶ�Զ����־,��ʶ�����ʶ��Ϣ�û��Զ��幦���Ƿ�����
LB_EXPORT int lb_info_setCareInfoUserDefineState(int state);

typedef enum _CareLevelInfoItem
{
	CARE_LEVEL_INFO_CARE_DESC = 0, //��������������
	CARE_LEVEL_INFO_CARE_LEVEL, // ������������Ϣ 
	CARE_LEVEL_INFO_MEASURE, // ����������Ϣ
	CARE_LEVEL_INFO_DIET,  // ������ʳ��Ϣ
	CARE_LEVEL_INFO_ISOLATION, //����������Ϣ
	CARE_LEVEL_INFO_ALLERGY //����������Ϣ
}CareLevelInfoItem;

// ��ȡ������ص���Ϣ
LB_EXPORT int lb_info_getCareLevelInfo(int level, CareLevelInfoItem item, char *value, int len, int *color);
// ���û�����ص���Ϣ
LB_EXPORT int lb_info_setCareLevelInfo(int level, CareLevelInfoItem item, char *value, int color);

LB_END_DECL
#endif