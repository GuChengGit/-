#ifndef _LONBON_WEBSERVICE_H_
#define _LONBON_WEBSERVICE_H_
//gsoapopt t

//gsoap lb service name:		lonbonservice
//gsoap lb service location:	http://localhost:5080
//gsoap lb service namespace:	http://localhost/lonbonservice.wsdl
//gsoap lb schema namespace:	http://localhost/lb.xsd


typedef char *	xsd__string;
typedef wchar_t *	xsd__wstring;

// C++ alternative for xsd:boolean:
// typedef bool	xsd__boolean;
// pure C alternative is:
typedef enum {false_, true_} xsd__boolean;
typedef int	xsd__int;
typedef double	xsd__double;

struct xsd__base64Binary
{	
	unsigned char *__ptr;
	int			   __size;
};

/************************************************************************/
/*    ͨ�÷���ӿڶ���								                    */
/************************************************************************/

//General Webservice Call

int lb__wsPing(int *pingok);

struct lb__Pair
{
	xsd__string key;
	xsd__string value;
};

struct LB_PairArray
{
	int __size;
	struct lb__Pair *__ptr;
};

struct LB_PairArrayArray
{
	int __size;
	struct LB_PairArray *__ptr;
};

struct lb__Response
{
	struct LB_PairArray* resp;
	struct LB_PairArrayArray* events;
};
int lb__action(struct LB_PairArray *cmd,struct lb__Response ** resp);

//getSystemInfo
struct lb__SystemInfo{
	xsd__wstring name;
	xsd__string model;
	xsd__string sn;
	xsd__string hard_version;
	xsd__string soft_version;
	xsd__string kernel_version;
	xsd__string mac;
	xsd__string ip;
	xsd__string netmask;
	xsd__string gateway;
	xsd__string dns1;
	xsd__string dns2;
};

int lb__getSystemInfo(struct lb__SystemInfo ** info);
//Call log


struct lb__CallLog{
	xsd__int    master_number;
	xsd__int    slave_number;
	xsd__wstring	calling_status;
	xsd__string calling_begin;
	xsd__string calling_time;
	xsd__string talking_begin;
	xsd__string talking_time;
	xsd__string recording_file;
	xsd__wstring description;
};
struct LB_CallLogArray
{
	int __size;
	struct lb__CallLog *__ptr;
};

struct lb__CallLogInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_CallLogArray* data;
};
struct lb__CallLogQuery
{
	xsd__int    master_number;
	xsd__int    slave_number;
	xsd__string date_from;
	xsd__string date_to;
};

int lb__getCallLogInfo(struct lb__CallLogQuery* query,struct lb__CallLogInfoResponse ** info);

/************************************************************************/
/*     �����Ŀ��Ϣ��ͼ                                                     */
/************************************************************************/
struct lb__Item{
	xsd__string code;
	xsd__string name;
};
struct LB_ItemArray
{
	int __size;
	struct lb__Item *__ptr;
};

struct lb__ItemInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_ItemArray*	data;
};

/************************************************************************/
/*     �����Ŀ������Ϣ��ͼ                                                     */
/************************************************************************/
struct lb__InspPatient{
	xsd__string charge_code;
	xsd__string code;
	xsd__string name;
	xsd__string abbr;
	xsd__string item_code;
	xsd__string device_code;
	xsd__string last_modify;
};
struct LB_InspPatientArray
{
	int __size;
	struct lb__InspPatient *__ptr;
};

struct lb__InspPatientInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_InspPatientArray*	data;
	xsd__string last_query_time;
};

/************************************************************************/
/*    ������������Ϣ��ͼ                                                  */
/************************************************************************/
struct lb__InspRoom{
	xsd__string code;
	xsd__string name;
};

struct LB_InspRoomArray
{
	int __size;
	struct lb__InspRoom *__ptr;
};

struct lb__InspRoomInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_InspRoomArray*	data;
};
/************************************************************************/
/*    �������豸��Ϣ��ͼ                                                  */
/************************************************************************/
struct lb__InspDevice{
	xsd__string code;
	xsd__string name;
};

struct LB_InspDeviceArray
{
	int __size;
	struct lb__InspDevice *__ptr;
};

struct lb__InspDeviceInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_InspDeviceArray*	data;
};




/************************************************************************/
/*     ������Ϣ��ͼ                                                     */
/************************************************************************/
struct lb__Department{
	xsd__string code;
	xsd__string name;
	xsd__string abbr;
};
struct LB_DepartmentArray
{
	int __size;
	struct lb__Department *__ptr;
};

struct lb__DepartmentInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_DepartmentArray*	data;
};

/************************************************************************/
/*    �Һ������Ϣ��ͼ                                                  */
/************************************************************************/
struct lb__Type{
	xsd__string code;
	xsd__string name;
	xsd__string abbr;
	xsd__string department_code;
};
struct LB_TypeArray
{
	int __size;
	struct lb__Type *__ptr;
};

struct lb__TypeInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_TypeArray*	data;
};
/************************************************************************/
/*     ҽ����Ϣ��ͼ                                                     */
/************************************************************************/
struct lb__Doctor{
	xsd__string code;
	xsd__string name;
	xsd__string abbr;
	xsd__string username;
	xsd__string password;
	xsd__string department_code;
	xsd__string title;
	xsd__string sex;
};
struct LB_DoctorArray
{
	int __size;
	struct lb__Doctor *__ptr;
};

struct lb__DoctorInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_DoctorArray*	data;
};

/************************************************************************/
/*     ��ʿ��Ϣ��ͼ                                                     */
/************************************************************************/
struct lb__Nurse{
	xsd__string code;
	xsd__string name;
	xsd__string title;
	xsd__string sex;
	xsd__string department_code;
};
struct LB_NurseArray
{
	int __size;
	struct lb__Nurse *__ptr;
};

struct lb__NurseInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_NurseArray*	data;
};

/************************************************************************/
/*    �Ű���Ϣ��ͼ                                                  */
/************************************************************************/
struct lb__Duty{
	xsd__string doctor_code;
	xsd__int dayofweek;
	xsd__int timeofday;
	xsd__string type_code;
	xsd__int room_number;
	xsd__string room_name;
};

struct LB_DutyArray
{
	int __size;
	struct lb__Duty *__ptr;
};

struct lb__DutyInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_DutyArray*	data;
};

/************************************************************************/
/*     ������Ϣ��ͼ                                                     */
/************************************************************************/
struct lb__Patient{
	xsd__string code;
	xsd__string name;
	xsd__string abbr;
	xsd__string type_code;
	xsd__string department_code;
	xsd__string doctor_code;
	xsd__string ticket_number;
	xsd__int	ticket_order;
	xsd__string ticket_time;
	xsd__string register_time;
	xsd__string last_modify;
	xsd__string sn;
	xsd__string sex;
	xsd__string sscard;
	xsd__int	state;
	xsd__string type_name;
};
struct LB_PatientArray
{
	int __size;
	struct lb__Patient *__ptr;
};

struct lb__PatientInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_PatientArray*	data;
	xsd__string last_query_time;
};



/************************************************************************/
/*     ��Ϣ��ͼ                                                     */
/************************************************************************/
struct lb__InpatientKey{
	xsd__string number;
	xsd__string name;
};
struct LB_InpatientKeyArray
{
	int __size;
	struct lb__InpatientKey *__ptr;
};

struct lb__InpatientKeyInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_InpatientKeyArray*	data;
};


int lb__getDepartmentInfo(struct lb__DepartmentInfoResponse ** info);
int lb__getTypeInfo(struct lb__TypeInfoResponse ** info);
int lb__getDoctorInfo(struct lb__DoctorInfoResponse ** info);
int lb__getNurseInfo(struct lb__NurseInfoResponse ** info);
int lb__getDutyInfo(struct lb__DutyInfoResponse ** info);
int lb__getPatientInfo(char *last_query_time,char *department_list,int department_size,struct lb__PatientInfoResponse ** info);

int lb__getItemInfo(struct lb__ItemInfoResponse ** info);
int lb__getInspPatientInfo(char *last_query_time,char *item_list,int item_size, struct lb__InspPatientInfoResponse ** InspPatientInfo);
int lb__getInspRoomInfo(struct lb__InspRoomInfoResponse ** info);
int lb__getInspDeviceInfo(struct lb__InspDeviceInfoResponse ** info);
int lb__getInpatientKeyInfo(struct lb__InpatientKeyInfoResponse ** info);

/************************************************************************/
/*  ������ͼ����ҽ����Ϣ�Խ�ϵͳ                                        */
/************************************************************************/

/*******************************************************************/
/*     סԺ������Ϣ��ͼ                                            */
/*******************************************************************/
struct lb__Inpatient{
	xsd__string code;           /* ���˱�� */
	xsd__string name;           /* �������� */
	xsd__string abbr;           /* ƴ����д��û�еĻ�ϵͳ���Զ����� */
	xsd__int    sex;            /* �Ա�1--��, 2--Ů*/
	xsd__string birthday;       /* �������� */
	xsd__string checkin_date;   /* ��Ժ���� */
	xsd__string checkout_date;  /* ��Ժ���� */
	xsd__int	zone_number;	/* ������ */
	xsd__string room_number;    /* ������ */
	xsd__string bed_number;     /* ������ */
	xsd__string doctor;         /* ����ҽ��  */
	xsd__int    care_level;     /* ������1--һ������2--�������� */
	xsd__string condition;      /* ���ز�Σ����һ�㼲������д */
	xsd__string note;           /* ����ע������ */
	xsd__string last_modify;    /* ������ʱ�� */
	xsd__string v1;
	xsd__string v2;
	xsd__string v3;
	xsd__string v4;
	xsd__string v5;
	xsd__string v6;
	xsd__string v7;
	xsd__string v8;
	xsd__string v9;
	xsd__string v10;
	xsd__string v11;
	xsd__string v12;
	xsd__string v13;
	xsd__string v14;
	xsd__string v15;
	xsd__string v16;
	xsd__string v17;
	xsd__string v18;
	xsd__string v19;
	xsd__string v20;
};

struct LB_InpatientArray
{
	int __size;
	struct lb__Inpatient *__ptr;
};

struct lb__InpatientInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_InpatientArray*	data;
	xsd__string last_query_time;
};

struct lb__InpatientIdInfo{
	xsd__string code;           /* ���˱�� */
	//xsd__int	zone_number;	/* ������ */
	xsd__string room_number;    /* ������ */
	xsd__string bed_number;     /* ������ */
};

struct LB_InpatientIdArray
{
	int __size;
	struct lb__InpatientIdInfo *__ptr;
};

struct lb__InpatientIdResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_InpatientIdArray*	data;
	xsd__string last_query_time;
};

int lb__getInpatientInfo(char *last_query_time,struct lb__InpatientInfoResponse ** info);
int lb__getZoneInpatientInfo(char *last_query_time,int zone_number,struct lb__InpatientInfoResponse ** info);
int lb__getRoomInpatientInfo(char *last_query_time,int zone_number,char *room_number_list,int room_number_size,struct lb__InpatientInfoResponse ** info);
int lb__getBedInpatientInfo(char *last_query_time,int zone_number,char *bed_number_list,int bed_number_size,struct lb__InpatientInfoResponse ** info);
int lb__getZoneAllInpatientInfo(int zone_number,struct lb__InpatientInfoResponse ** info);
int lb__getAllRoomInpatientInfo(int zone_number,char *room_number_list,int room_number_size,struct lb__InpatientInfoResponse ** info);
int lb__getAllBedInpatientInfo(int zone_number,char *bed_number_list,int bed_number_size,struct lb__InpatientInfoResponse ** info);
int lb__getZoneAllInpatientId(int zone_number, struct lb__InpatientIdResponse ** info);
int lb__getAllRoomInpatientId(int zone_number,char *room_number_list,int room_number_size,struct lb__InpatientIdResponse ** info);
int lb__getAllBedInpatientId(int zone_number,char *bed_number_list,int bed_number_size,struct lb__InpatientIdResponse ** info);

//����һ����
typedef struct lb__InpatientAdditionalInfo{
	xsd__int masterNum;        //������
	xsd__int childNum;         //�ֻ���
	xsd__int type;             //��������
	xsd__int measure;		   //����
	xsd__int diet;		       //��ʳ
	xsd__int isolation;		   //����
	xsd__int allergy;		   //����
};

typedef struct lb__InpatientlistInfo
{
	xsd__int							id;		  //���
	struct lb__Inpatient				*base_info;
	struct lb__InpatientAdditionalInfo	*additional_info;
}patient_info;
struct LB_InpatientlistArray
{
	int __size;
	struct lb__InpatientlistInfo *__ptr;
};

struct lb__InpatientlistInfoResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_InpatientlistArray*	data;
};


//��Ϣ����--����
struct lb__DashboardDataInfo{
	xsd__int area;           /* ���� */
	xsd__string title;
	xsd__string k1;
	xsd__string v1;
	xsd__string k2;
	xsd__string v2;
	xsd__string k3;
	xsd__string v3;
	xsd__string k4;
	xsd__string v4;
};

struct LB_DashboardDataArray
{
	int __size;
	struct lb__DashboardDataInfo *__ptr;
};

struct lb__DashboardDataResponse
{
	xsd__int	code;
	xsd__string msg;
	struct LB_DashboardDataArray*	data;
};
int lb__getAllDashboardData(struct lb__DashboardDataResponse ** info);

//��Ϣ����--����
struct lb__DashboardMessageInfo{
	xsd__string title;
	xsd__string message;
};

struct lb__DashboardMessageArray
{
	int __size;
	struct lb__DashboardMessageInfo *__ptr;
};

struct lb__DashboardMessageResponse
{
	xsd__int	code;
	xsd__string msg;
	struct lb__DashboardMessageArray*	data;
};
int lb__getAllDashboardMessage(struct lb__DashboardMessageResponse ** info);

#endif /*_LONBON_WEBSERVICE_H_*/
