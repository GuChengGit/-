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
* 获取交互服务器系统信息
*
* @param servAddr		交互服务器地址
* @param systemInfo		获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getSystemInfo(char *ip, lb_webServ_SystemInfo &systemInfo);

/**
* 获取交互服务器系统信息
*
* @param servAddr		交互服务器地址
* @param systemInfo		获取信息后存入类对象
* @param port			交互服务器端口
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getSystemInfo_withPort(char *ip, int port, lb_webServ_SystemInfo &systemInfo);

/**
* 获取交互服务器指定时间以后的所有病人信息
*
* @param servAddr				 交互服务器地址
* @param last_query_time		 获取这个时间以后的数据
* @param patientResponeseArray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getInpatientInfo(const char *servAddr, char *last_query_time, lb_webServ_InpatientArray &patientResponseAarray);

/**
* 获取交互服务器指定时间以后指定病区的所有病人信息
*
* @param servAddr				 交互服务器地址
* @param last_query_time		 获取这个时间以后的数据
* @param zone_number			 指定病区
* @param patientResponeseArray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getZoneInpatientInfo(const char *servAddr, char *last_query_time, int zone_number, lb_webServ_InpatientArray &patientResponseAarray);

/**
* 获取交互服务器指定时间以后、指定定病区病房的所有病人信息
*
* @param servAddr				 交互服务器地址
* @param last_query_time		 获取这个时间以后的数据
* @param zone_number			 指定病区
* @param room_number_list		 指定房号列表
* @param room_number_size		 列表长度
* @param patientResponeseArray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getRoomInpatientInfo(const char *servAddr, char *last_query_time, int zone_number, char *room_number_list, int room_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* 获取交互服务器指定时间以后、指定定病区病床的所有病人信息
*
* @param servAddr				 交互服务器地址
* @param last_query_time		 获取这个时间以后的数据
* @param zone_number			 指定病区
* @param bed_number_list		 指定房号列表
* @param bed_number_size		 列表长度
* @param patientResponeseArray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getBedInpatientInfo(const char *servAddr, char *last_query_time, int zone_number, char *bed_number_list, int bed_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* 获取交互服务器所有病人信息
*
* @param servAddr				 交互服务器地址
* @param zone_number			 区号
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getZoneAllInpatientInfo(const char *servAddr, int zone_number, lb_webServ_InpatientArray &patientResponseAarray);

/**
* 获取交互服务器指定病区指定病房病人信息
*
* @param servAddr				 交互服务器地址
* @param zone_number			 区号
* @param room_number_list		 指定房号列表
* @param room_number_size		 列表长度
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getAllRoomInpatientInfo(const char *servAddr, int zone_number, char *room_number_list, int room_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* 获取交互服务器指定病区指定病床病人信息
*
* @param servAddr				 交互服务器地址
* @param zone_number			 区号
* @param bed_number_list		 指定床号列表
* @param bed_number_size		 列表长度
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getAllBedInpatientInfo(const char *servAddr, int zone_number, char *bed_number_list, int bed_number_size, lb_webServ_InpatientArray &patientResponseAarray);

/**
* 获取交互服务器病人扩展字段信息
*
* @param servAddr				 交互服务器地址
* @param inpatientExpendInfoResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getInpatientExpendInfo(const char *servAddr, lb_webServ_ExpendInfoArray &inpatientExpendInfoResponseAarray);

/**
* 上传护理定位事件到交互服务器
*
* @param servAddr				 交互服务器地址
* @param positionEventArray		 上传事件组合
* @param positionEventResponse	 返回结果
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_uploadPositionCardInfo(const char *servAddr, lb_webServ_UploadPositionEventInfoArray &positionEventArray, lb_webServ_UploadPositionEventResponse &positionEventResponse);

/**
* 获取交互服务器病人护理定位工牌信息
*
* @param servAddr				 交互服务器地址
* @param positionCardResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getPositionCardInfo(const char *servAddr, lb_webServ_PositionCardArray &positionCardResponseAarray);

/**
* 获取交互服务器病人药品信息
*
* @param servAddr				 交互服务器地址
* @param patient_code			 病人编号
* @param start_query_date		 起始时间
* @param end_query_date			 结束时间
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getInpatientMedicineInfo(const char *servAddr, char *patient_code, char *start_query_date, char *end_query_date, lb_webServ_InpatientMedicineArray &inpatientMedicineInfoResponseAarray);

/**
* 获取交互服务器病人清单信息
*
* @param servAddr				 交互服务器地址
* @param patient_code			 病人编号
* @param start_query_date		 起始时间
* @param end_query_date			 结束时间
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getInpatientDailyCostInfo(const char *servAddr, char *patient_code, char *start_query_date, char *end_query_date, lb_webServ_InpatientDailyCostArray &inpatientDailyCostInfoResponseAarray);

/**
* 获取交互服务器病人总费用信息
*
* @param servAddr				 交互服务器地址
* @param patient_code			 病人编号
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getInpatientTotalCostInfo(const char *servAddr, char *patient_code, lb_webServ_InpatientTotalCostArray &inpatientTotalCostInfoResponseAarray);

/**
* 获取交互服务器病人状态信息
*
* @param servAddr				 交互服务器地址
* @param zone_number			 病区编号
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getInpatientStatsInfo(const char *servAddr, char *zone_number, lb_webServ_InpatientStatsArray &inpatientStatsInfoResponseAarray);

/**
* 获取交互服务器指定病区所有病人ID
*
* @param servAddr				 交互服务器地址
* @param zone_number			 区号
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getZoneAllInpatientIdInfo(const char *servAddr, int zone_number, lb_webServ_InpatientIdArray &patientIdResponseAarray);

/**
* 获取交互服务器指定病区病房所有病人ID
*
* @param servAddr				 交互服务器地址
* @param zone_number			 区号
* @param room_number_list		 指定房号列表
* @param room_number_size		 列表长度
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getAllRoomInpatientIdInfo(const char *servAddr, int zone_number, char *room_number_list, int room_number_size, lb_webServ_InpatientIdArray &patientIdResponseAarray);

/**
* 获取交互服务器指定病区病床所有病人ID
*
* @param servAddr				 交互服务器地址
* @param zone_number			 区号
* @param bed_number_list		 指定病床列表
* @param bed_number_size		 列表长度
* @param patientResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getAllBedInpatientIdInfo(const char *servAddr, int zone_number, char *bed_number_list, int bed_number_size, lb_webServ_InpatientIdArray &patientIdResponseAarray);

/**
* 获取交互服务器所有病人ID
*
* @param servAddr					 交互服务器地址
* @param departmentResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getDepartmentInfo(const char *servAddr, lb_webServ_DepartmentArray &departmentResponseAarray);

/**
* 获取交互服务器扩展字段描述信息
*
* @param servAddr				 交互服务器地址
* @param inpatientKeyResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getInpatientKeyInfo(const char *servAddr, lb_webServ_InpatientKeyArray &inpatientKeyResponseAarray);

/**
* 获取交互服务器医生信息
*
* @param servAddr				 交互服务器地址
* @param doctorResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getDoctorInfo(const char *servAddr, lb_webServ_DoctorArray &doctorResponseAarray);

/**
* 获取交互服务器护士信息
*
* @param servAddr				 交互服务器地址
* @param nurseResponseAarray	 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getNurseInfo(const char *servAddr, lb_webServ_NurseArray &nurseResponseAarray);

/**
* 获取交互服务器排班信息
*
* @param servAddr				 交互服务器地址
* @param dutyResponseAarray		 获取信息后存入类对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getDutyInfo(const char *servAddr, lb_webServ_DutyArray &dutyResponseAarray);

/**
* 从交互服务器获取指定code医生照片
*
* @param servAddr				 交互服务器地址
* @param code					 医生编号
* @param photoResponseArray		 获取照片后返回对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getDoctorPhotoInfo(const char *servAddr, char *code, lb_webServ_PhotoArray &photoResponseArray);

/**
* 从交互服务器获取指定code护士照片
*
* @param servAddr				 交互服务器地址
* @param code					 医生编号
* @param photoResponseArray		 获取照片后返回对象
*
* @return				LB_SUCCESS：成功 LB_FAIL：出现参数错误
*/
int lb_webServ_getNursePhotoInfo(const char *servAddr, char *code, lb_webServ_PhotoArray &photoResponseArray);