#pragma once

class lb_webServ_SystemInfo
{
public:
	char *name;	
	char *model;	
	char *sn;	
	char *hard_version;	
	char *soft_version;
	char *kernel_version;
	char *mac;
	char *ip;
	char *netmask;
	char *gateway;
	char *dns1;
	char *dns2;
	
	lb_webServ_SystemInfo();
	~lb_webServ_SystemInfo();
};

class lb_webServ_Inpatient
{
public:
	char *code;
	char *name;
	char *abbr;
	int sex;
	char *birthday;
	char *checkin_date;
	char *checkout_date;
	int zone_number;
	char *room_number;
	char *bed_number;
	char *doctor;
	char *nurse;
	int care_level;
	char *condition;
	char *note;
	char *last_modify;
	char *v1;
	char *v2;
	char *v3;
	char *v4;
	char *v5;
	char *v6;
	char *v7;
	char *v8;
	char *v9;
	char *v10;
	char *v11;
	char *v12;
	char *v13;
	char *v14;
	char *v15;
	char *v16;
	char *v17;
	char *v18;
	char *v19;
	char *v20;
	char *new_inpatient_flag;
	char *nurse_level;
	char *nurse_level_color;
	char *nurse_level_font_color;
	char *nurse_measure;
	char *nurse_measure_color;
	char *nurse_measure_font_color;
	char *nurse_diet;
	char *nurse_diet_color;
	char *nurse_diet_font_color;
	char *nurse_isolation;
	char *nurse_isolation_color;
	char *nurse_isolation_font_color;
	char *nurse_allergy;
	char *nurse_allergy_color;
	char *nurse_allergy_font_color;

	lb_webServ_Inpatient();
	~lb_webServ_Inpatient();
};

class lb_webServ_InpatientArray
{
public:
	int code;
	char *msg;
	char *last_query_time;

	int size;
	lb_webServ_Inpatient **item;

	lb_webServ_InpatientArray();
	~lb_webServ_InpatientArray();
};

class lb_webServ_InpatientId
{
public:
	char *code;
	char *room_number;
	char *bed_number;

	lb_webServ_InpatientId();
	~lb_webServ_InpatientId();
};

class lb_webServ_InpatientIdArray
{
public:
	int code;
	char *msg;
	char *last_query_time;

	int size;
	lb_webServ_InpatientId **item;
	
	lb_webServ_InpatientIdArray();
	~lb_webServ_InpatientIdArray();
};

class lb_webServ_Department
{
public:
	char *code;
	char *name;
	char *abbr;

	lb_webServ_Department();
	~lb_webServ_Department();
};

class lb_webServ_DepartmentArray
{
public:
	int code;
	char *msg;
	
	int size;
	lb_webServ_Department **item;
	
	lb_webServ_DepartmentArray();
	~lb_webServ_DepartmentArray();
};

class lb_webServ_InpatientKey
{
public:
	int number;
	char *name;

	lb_webServ_InpatientKey();
	~lb_webServ_InpatientKey();
};

class lb_webServ_InpatientKeyArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_InpatientKey **item;

	lb_webServ_InpatientKeyArray();
	~lb_webServ_InpatientKeyArray();
};

class lb_webServ_Doctor
{
public:
	char *code;
	char *name;
	char *abbr;
	char *username;
	char *password;
	char *department_code;
	char *title;
	char *sex;

	lb_webServ_Doctor();
	~lb_webServ_Doctor();
};

class lb_webServ_DoctorArray
{
public:
	int code;
	char *msg;
	
	int size;
	lb_webServ_Doctor **item;

	lb_webServ_DoctorArray();
	~lb_webServ_DoctorArray();
};

class lb_webServ_Nurse
{
public:
	char *code;
	char *name;
	char *title;
	char *sex;
	char *department_code;

	lb_webServ_Nurse();
	~lb_webServ_Nurse();
};

class lb_webServ_NurseArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_Nurse **item;

	lb_webServ_NurseArray();
	~lb_webServ_NurseArray();
};

class lb_webServ_Duty
{
public:
	char *doctor_code;
	int dayofweek;
	int timeofday;
	char *type_code;
	int room_number;
	char *room_name;

	lb_webServ_Duty();
	~lb_webServ_Duty();
};

class lb_webServ_DutyArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_Duty **item;

	lb_webServ_DutyArray();
	~lb_webServ_DutyArray();
};

class lb_webServ_base64Binary
{
public:
	unsigned char *ptr;
	int size;
	char *id;
	char *type;
	char *options;

	lb_webServ_base64Binary();
	~lb_webServ_base64Binary();
};

class lb_webServ_Photo
{
public:
	char *code;
	char *name;
	
	lb_webServ_base64Binary *buff;

	lb_webServ_Photo();
	~lb_webServ_Photo();
};

class lb_webServ_PhotoArray
{
public:
	int code;
	char *msg;
	
	int size;
	lb_webServ_Photo **item;
	
	lb_webServ_PhotoArray();
	~lb_webServ_PhotoArray();
};

class lb_webServ_ExpendInfo
{
public:
	char *code;
	char *expend_name;
	char *text;
	char *color;
	char *font_color;

	lb_webServ_ExpendInfo();
	~lb_webServ_ExpendInfo();
};

class lb_webServ_ExpendInfoArray
{
public:
	int code;
	char *msg;
	char *last_query_time;

	int size;
	lb_webServ_ExpendInfo **item;

	lb_webServ_ExpendInfoArray();
	~lb_webServ_ExpendInfoArray();
};

class lb_webServ_PositionEvent
{
public:
	char *position_card;
	char *zone_num;
	char *room_num;
	char *bed_num;
	int event_type;
	char *start_time;
	char *end_time;

	lb_webServ_PositionEvent();
	~lb_webServ_PositionEvent();
};

class lb_webServ_UploadPositionEventInfoArray
{
public:
	int size;
	lb_webServ_PositionEvent **item;

	lb_webServ_UploadPositionEventInfoArray();
	~lb_webServ_UploadPositionEventInfoArray();
};

class lb_webServ_UploadPositionEventResponse
{
public:
	int code;
	char *msg;

	lb_webServ_UploadPositionEventResponse();
	~lb_webServ_UploadPositionEventResponse();
};

class lb_webServ_PositionCard
{
public:
	char *user_code;
	int user_type;
	char *position_card;

	lb_webServ_PositionCard();
	~lb_webServ_PositionCard();
};

class lb_webServ_PositionCardArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_PositionCard **item;

	lb_webServ_PositionCardArray();
	~lb_webServ_PositionCardArray();
};

class lb_webServ_InpatientMedicineInfo
{
public:
	char *code;
	char *date;
	char *medicine;
	char *spec;
	char *unit;
	int num;
	char *price;
	char *subtotal;

	lb_webServ_InpatientMedicineInfo();
	~lb_webServ_InpatientMedicineInfo();
};

class lb_webServ_InpatientMedicineArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_InpatientMedicineInfo **item;

	lb_webServ_InpatientMedicineArray();
	~lb_webServ_InpatientMedicineArray();
};

class lb_webServ_InpatientDailyCostInfo
{
public:
	char *code;
	char *date;
	char *project;
	char *cost;

	lb_webServ_InpatientDailyCostInfo();
	~lb_webServ_InpatientDailyCostInfo();
};

class lb_webServ_InpatientDailyCostArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_InpatientDailyCostInfo **item;

	lb_webServ_InpatientDailyCostArray();
	~lb_webServ_InpatientDailyCostArray();
};

class lb_webServ_InpatientTotalCostInfo
{
public:
	char *code;
	char *total;
	char *paid;
	char *rest;

	lb_webServ_InpatientTotalCostInfo();
	~lb_webServ_InpatientTotalCostInfo();
};

class lb_webServ_InpatientTotalCostArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_InpatientTotalCostInfo **item;

	lb_webServ_InpatientTotalCostArray();
	~lb_webServ_InpatientTotalCostArray();
};

class lb_webServ_InpatientStatsInfo
{
public:
	char *zone_number;
	char *project;
	char *number;
	char *unit;

	lb_webServ_InpatientStatsInfo();
	~lb_webServ_InpatientStatsInfo();
};

class lb_webServ_InpatientStatsArray
{
public:
	int code;
	char *msg;

	int size;
	lb_webServ_InpatientStatsInfo **item;

	lb_webServ_InpatientStatsArray();
	~lb_webServ_InpatientStatsArray();
};

/**
* ��ȡ����������ϵͳ��Ϣ
*
* @param servAddr		������������ַ
* @param systemInfo		��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getSystemInfo(char *ip, lb_webServ_SystemInfo &systemInfo);

/**
* ��ȡ����������ϵͳ��Ϣ
*
* @param servAddr		������������ַ
* @param systemInfo		��ȡ��Ϣ����������
* @param port			�����������˿�
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getSystemInfo_withPort(char *ip, int port, lb_webServ_SystemInfo &systemInfo);

/**
* ��ȡ����������ָ��ʱ���Ժ�����в�����Ϣ
*
* @param servAddr				 ������������ַ
* @param last_query_time		 ��ȡ���ʱ���Ժ������
* @param patientResponeseArray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getInpatientInfo(const char *servAddr, char *last_query_time, lb_webServ_InpatientArray &patientResponseAarray);

/**
* ��ȡ����������ָ��ʱ���Ժ�ָ�����������в�����Ϣ
*
* @param servAddr				 ������������ַ
* @param last_query_time		 ��ȡ���ʱ���Ժ������
* @param zone_number			 ָ������
* @param patientResponeseArray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getZoneInpatientInfo(const char *servAddr, char *last_query_time, int zone_number, lb_webServ_InpatientArray &patientResponseAarray);

/**
* ��ȡ����������ָ��ʱ���Ժ�ָ�����������������в�����Ϣ
*
* @param servAddr				 ������������ַ
* @param last_query_time		 ��ȡ���ʱ���Ժ������
* @param zone_number			 ָ������
* @param room_number_list		 ָ�������б�
* @param room_number_size		 �б���
* @param patientResponeseArray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getRoomInpatientInfo(const char *servAddr, char *last_query_time, int zone_number, char *room_number_list, int room_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* ��ȡ����������ָ��ʱ���Ժ�ָ�����������������в�����Ϣ
*
* @param servAddr				 ������������ַ
* @param last_query_time		 ��ȡ���ʱ���Ժ������
* @param zone_number			 ָ������
* @param bed_number_list		 ָ�������б�
* @param bed_number_size		 �б���
* @param patientResponeseArray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getBedInpatientInfo(const char *servAddr, char *last_query_time, int zone_number, char *bed_number_list, int bed_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* ��ȡ�������������в�����Ϣ
*
* @param servAddr				 ������������ַ
* @param zone_number			 ����
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getZoneAllInpatientInfo(const char *servAddr, int zone_number, lb_webServ_InpatientArray &patientResponseAarray);

/**
* ��ȡ����������ָ������ָ������������Ϣ
*
* @param servAddr				 ������������ַ
* @param zone_number			 ����
* @param room_number_list		 ָ�������б�
* @param room_number_size		 �б���
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getAllRoomInpatientInfo(const char *servAddr, int zone_number, char *room_number_list, int room_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* ��ȡ����������ָ������ָ������������Ϣ
*
* @param servAddr				 ������������ַ
* @param zone_number			 ����
* @param bed_number_list		 ָ�������б�
* @param bed_number_size		 �б���
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getAllBedInpatientInfo(const char *servAddr, int zone_number, char *bed_number_list, int bed_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* ��ȡ����������������չ�ֶ���Ϣ
*
* @param servAddr				 ������������ַ
* @param inpatientExpendInfoResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getInpatientExpendInfo(const char *servAddr, lb_webServ_ExpendInfoArray &inpatientExpendInfoResponseAarray);

/**
* �ϴ�����λ�¼�������������
*
* @param servAddr				 ������������ַ
* @param positionEventArray		 �ϴ��¼����
* @param positionEventResponse	 ���ؽ��
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_uploadPositionCardInfo(const char *servAddr, lb_webServ_UploadPositionEventInfoArray &positionEventArray, lb_webServ_UploadPositionEventResponse &positionEventResponse);

/**
* ��ȡ�������������˻���λ������Ϣ
*
* @param servAddr				 ������������ַ
* @param positionCardResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getPositionCardInfo(const char *servAddr, lb_webServ_PositionCardArray &positionCardResponseAarray);

/**
* ��ȡ��������������ҩƷ��Ϣ
*
* @param servAddr				 ������������ַ
* @param patient_code			 ���˱��
* @param start_query_date		 ��ʼʱ��
* @param end_query_date			 ����ʱ��
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getInpatientMedicineInfo(const char *servAddr, char *patient_code, char *start_query_date, char *end_query_date, lb_webServ_InpatientMedicineArray &inpatientMedicineInfoResponseAarray);

/**
* ��ȡ���������������嵥��Ϣ
*
* @param servAddr				 ������������ַ
* @param patient_code			 ���˱��
* @param start_query_date		 ��ʼʱ��
* @param end_query_date			 ����ʱ��
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getInpatientDailyCostInfo(const char *servAddr, char *patient_code, char *start_query_date, char *end_query_date, lb_webServ_InpatientDailyCostArray &inpatientDailyCostInfoResponseAarray);

/**
* ��ȡ���������������ܷ�����Ϣ
*
* @param servAddr				 ������������ַ
* @param patient_code			 ���˱��
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getInpatientTotalCostInfo(const char *servAddr, char *patient_code, lb_webServ_InpatientTotalCostArray &inpatientTotalCostInfoResponseAarray);

/**
* ��ȡ��������������״̬��Ϣ
*
* @param servAddr				 ������������ַ
* @param zone_number			 �������
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getInpatientStatsInfo(const char *servAddr, char *zone_number, lb_webServ_InpatientStatsArray &inpatientStatsInfoResponseAarray);

/**
* ��ȡ����������ָ���������в���ID
*
* @param servAddr				 ������������ַ
* @param zone_number			 ����
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getZoneAllInpatientIdInfo(const char *servAddr, int zone_number, lb_webServ_InpatientIdArray &patientIdResponseAarray);

/**
* ��ȡ����������ָ�������������в���ID
*
* @param servAddr				 ������������ַ
* @param zone_number			 ����
* @param room_number_list		 ָ�������б�
* @param room_number_size		 �б���
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getAllRoomInpatientIdInfo(const char *servAddr, int zone_number, char *room_number_list, int room_number_size, lb_webServ_InpatientIdArray &patientIdResponseAarray);

/**
* ��ȡ����������ָ�������������в���ID
*
* @param servAddr				 ������������ַ
* @param zone_number			 ����
* @param bed_number_list		 ָ�������б�
* @param bed_number_size		 �б���
* @param patientResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getAllBedInpatientIdInfo(const char *servAddr, int zone_number, char *bed_number_list, int bed_number_size, lb_webServ_InpatientIdArray &patientIdResponseAarray);

/**
* ��ȡ�������������в���ID
*
* @param servAddr					 ������������ַ
* @param departmentResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getDepartmentInfo(const char *servAddr, lb_webServ_DepartmentArray &departmentResponseAarray);

/**
* ��ȡ������������չ�ֶ�������Ϣ
*
* @param servAddr				 ������������ַ
* @param inpatientKeyResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getInpatientKeyInfo(const char *servAddr, lb_webServ_InpatientKeyArray &inpatientKeyResponseAarray);

/**
* ��ȡ����������ҽ����Ϣ
*
* @param servAddr				 ������������ַ
* @param doctorResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getDoctorInfo(const char *servAddr, lb_webServ_DoctorArray &doctorResponseAarray);

/**
* ��ȡ������������ʿ��Ϣ
*
* @param servAddr				 ������������ַ
* @param nurseResponseAarray	 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getNurseInfo(const char *servAddr, lb_webServ_NurseArray &nurseResponseAarray);

/**
* ��ȡ�����������Ű���Ϣ
*
* @param servAddr				 ������������ַ
* @param dutyResponseAarray		 ��ȡ��Ϣ����������
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getDutyInfo(const char *servAddr, lb_webServ_DutyArray &dutyResponseAarray);

/**
* �ӽ�����������ȡָ��codeҽ����Ƭ
*
* @param servAddr				 ������������ַ
* @param code					 ҽ�����
* @param photoResponseArray		 ��ȡ��Ƭ�󷵻ض���
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getDoctorPhotoInfo(const char *servAddr, char *code, lb_webServ_PhotoArray &photoResponseArray);

/**
* �ӽ�����������ȡָ��code��ʿ��Ƭ
*
* @param servAddr				 ������������ַ
* @param code					 ҽ�����
* @param photoResponseArray		 ��ȡ��Ƭ�󷵻ض���
*
* @return				LB_SUCCESS���ɹ� LB_FAIL�����ֲ�������
*/
int lb_webServ_getNursePhotoInfo(const char *servAddr, char *code, lb_webServ_PhotoArray &photoResponseArray);