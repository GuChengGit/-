#ifndef  __LB_HOSPITAL_DAO_H__
#define  __LB_HOSPITAL_DAO_H__

#include "lb_headdef.h"
LB_BEGIN_DECL

#define LB_HOSPITAL_INPATIENT_EXT_CNT			20
#define LB_HOSPITAL_INPATIENT_FLAG_CNT			10
#define LB_HOSPITAL_INPATIENT_PREDISPLAY_CNT	(LB_HOSPITAL_INPATIENT_EXT_CNT + LB_HOSPITAL_INPATIENT_FLAG_CNT * 3)

/* @method ���ʼ���ӿ�
* @param mstNum ������
* @param db_path ���ݿ�·��
*/
LB_EXPORT int lb_hospital_dao_init(char *db_path);

/* @method �����ٽӿ�
* @param void
*/
LB_EXPORT int lb_hospital_dao_destory(void);

// ������չ��Ϣ
typedef struct _LB_HOSPITAL_INPATIENT_EXT_INFO
{
	char	*vContent;			// ��չ�ֶ�����

}LB_HOSPITAL_INPATIENT_EXT_INFO;

// ���߻����ʶ��Ϣ
typedef struct _LB_HOSPITAL_INPATIENT_LEVEL_INFO
{
	char	*flagName;			// �����ʶ��
	char	*flagColor;			// �����ʶ��ɫ
	char	*flagFontColor;		// �����ʶ������ɫ

}LB_HOSPITAL_INPATIENT_LEVEL_INFO;

// ������Ϣ
typedef struct _LB_HOSPITAL_INPATIENT_INFO
{
	char	*patientCode;		// ���߱��	
	char	*hosNumber;			// סԺ��(ע���󲿷�ҽԺ�ñ���뻼�߱��һ�£���ʱ�����ֶο��Բ�ʹ��)
	char	*name;				// ����
	char	*sex;				// �Ա�
	char	*birthday;			// ����
	char	*doctorCode;		// ҽ�����
	char	*nurseCode;			// ��ʿ��� 
	char	*condition;			// ����
	char	*advice;			// ҽ��
	char	*newInpatient;		// ����Ժ��ʶ
	char	*checkInDate;		// ��Ժʱ��
	char	*lastModify;		// ������ʱ��

	LB_HOSPITAL_INPATIENT_EXT_INFO inpatientExtInfo[LB_HOSPITAL_INPATIENT_EXT_CNT];
	LB_HOSPITAL_INPATIENT_LEVEL_INFO inpatientFlagInfo[LB_HOSPITAL_INPATIENT_FLAG_CNT];

}LB_HOSPITAL_INPATIENT_INFO;

/* @method ��ȡָ���ֻ��Ļ�����Ϣ
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @param **inpatientInfo ������Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_get_inpatient_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_HOSPITAL_INPATIENT_INFO **inpatientInfo);

/* @method ��ȡָ���ֻ��Ļ�������
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @return -1 ʧ�ܣ� >=0 ���ߵ�ǰ����
*/
LB_EXPORT int lb_hospital_get_inpatient_age(int accId, int areaId, int master_number, int slave_number, int devRegType);

/* @method ��ȡָ���ֻ��Ļ�����Ժ����
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @param *year ��
* @param *month ��
* @param *day ��
* @return -1 ʧ�ܣ� 0�ɹ�
*/
LB_EXPORT int lb_hospital_get_inpatient_checkInDate(int accId, int areaId, int master_number, int slave_number, int devRegType, int *year, int *month, int *day);

/* @method ����ָ���ֻ��Ļ�����Ϣ
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @param *inpatientInfo ������Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_set_inpatient_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_HOSPITAL_INPATIENT_INFO *inpatientInfo);

/* @method ɾ��������Ϣ
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_delete_inpatient_info(int accId, int areaId, int master_number, int slave_number, int devRegType);

/* @method ���ٻ�����Ϣ
* @param *inpatientInfo ������Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_destory_inpatient_info(LB_HOSPITAL_INPATIENT_INFO *inpatientInfo);

typedef struct _LB_HOSPITAL_KEY_NAME
{
	int		vSn;
	char	*keyName;

}LB_HOSPITAL_KEY_NAME;

/* @method ��ȡ��չ�ֶα�����Ϣ
* @param vSn �ֶ���ţ�1~LB_HOSPITAL_INPATIENT_PREDISPLAY_CNT��
* @param *keyNameInfo ��չ�ֶα�����Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_get_key_name(int vSn, char *keyName);

/* @method ������չ�ֶα�����Ϣ
* @param *reNameInfo ��չ�ֶα�����Ϣ
* @param cnt ��չ�ֶα�������
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_set_key_name(LB_HOSPITAL_KEY_NAME *keyNameInfo, int cnt);

/* @method ������չ�ֶα�����Ϣ
* @param *reNameInfo ��չ�ֶα�����Ϣ
* @param cnt ��չ�ֶα�������
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_destory_key_name(LB_HOSPITAL_KEY_NAME *keyNameInfo, int cnt);

typedef struct _LB_HSOPITAL_PREDISPLAY
{
	int		vSn;
	char	*keyName;

}LB_HOSPITAL_PREDISPLAY;

/* @method ��ȡ������ʾ�ֶ���Ϣ
* @param vSn ������ʾ�ֶ����(1~LB_HOSPITAL_INPATIENT_PREDISPLAY_CNT)
* @param *preDisplayInfo ������ʾ�ֶ���Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_get_predisplay_info(int vSn, char *keyName);

/* @method ����������ʾ�ֶ���Ϣ
* @param *preDisplayInfo ������ʾ�ֶ���Ϣ
* @param cnt ������ʾ�ֶ���
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_set_predisplay_info(LB_HOSPITAL_PREDISPLAY *preDisplayInfo, int cnt);

/* @method ����������ʾ�ֶ���Ϣ
* @param *preDisplayInfo ������ʾ�ֶ���Ϣ
* @param cnt ������ʾ�ֶ���
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_destory_predisplay_info(LB_HOSPITAL_PREDISPLAY *preDisplayInfo, int cnt);


// ������Ϣ
typedef struct _LB_HOSPITAL_DEPARTMENT_INFO
{
	char *code;
	char *name;

}LB_HOSPITAL_DEPARTMENT_INFO;

/* @method ��ȡ������Ϣ�ڵ���
* @return -1 δ��ʼ����0 �޿�����Ϣ, >1 ���ؿ�����Ϣ����ڵ���
*/
LB_EXPORT int lb_hospital_get_department_info_cnt(void);

/* @method ��ȡ������Ϣ
* @param **departmentInfo ������Ϣ
* @return 0 �ɹ���-1 ʧ��, >1 ���ؿ�����Ϣ����ڵ���
*/
LB_EXPORT int lb_hospital_get_department_info(LB_HOSPITAL_DEPARTMENT_INFO **departmentInfo);

/* @method ���ÿ�����Ϣ
* @param *departmentInfo ������Ϣ
* @param departmentCnt ��������
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_set_department_info(LB_HOSPITAL_DEPARTMENT_INFO *departmentInfo, int departmentCnt);

/* @method ���ٿ�����Ϣ
* @param **departmentInfo ������Ϣ
* @param departmentCnt ��������
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_destory_department_info(LB_HOSPITAL_DEPARTMENT_INFO *departmentInfo, int departmentCnt);

// ��Ա��Ϣ
typedef struct _LB_HOSPITAL_EMPLOYEER_INFO
{
	char *code;
	char *departmentCode;
	char *name;
	char *sex;
	char *occupation;
	char *title;

}LB_HOSPITAL_EMPLOYEER_INFO;

/* @method ��ȡ��Ա��Ϣ
* @param **employeerInfo ��Ա��Ϣ
* @return 0 �ɹ���-1 ʧ��, >1 ���ع�Ա��Ϣ����ڵ���
*/
LB_EXPORT int lb_hospital_get_employeer_info(LB_HOSPITAL_EMPLOYEER_INFO **employeerInfo);

/* @method ���ݱ�Ż�ȡ��Ա��Ϣ
* @param *employeerInfo ָ���Ĺ�Ա��Ϣ
* @param *code ��Ա���
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_get_employeer_info_from_code(LB_HOSPITAL_EMPLOYEER_INFO **employeerInfo, char *code);

/* @method ���ù�Ա��Ϣ
* @param *employeerInfo ��Ա��Ϣ
* @param employeerCnt ��Ա����
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_set_employeer_info(LB_HOSPITAL_EMPLOYEER_INFO *employeerInfo, int employeerCnt);

/* @method ���ٹ�Ա��Ϣ
* @param **employeerInfo ��Ա��Ϣ
* @param employeerCnt ��Ա����
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_hospital_destory_employeer_info(LB_HOSPITAL_EMPLOYEER_INFO *employeerInfo, int employeerCnt);


LB_END_DECL

#endif
