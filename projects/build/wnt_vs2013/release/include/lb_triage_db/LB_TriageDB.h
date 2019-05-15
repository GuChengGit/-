#ifndef _LB_TRIAGEDB_H_
#define _LB_TRIAGEDB_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "lbinsp_item.h"
#include "lbinsp_room.h"
#include "lbinsp_patient.h"
#include "lbqy_dispensary.h"

#define LB_MAX_LENGTH_CODE	20
#define LB_MAX_LENGTH_NAME	32
#define LB_MAX_LENGTH_ABBR	10
#define LB_MAX_LENGTH_USERNAME	20
#define LB_MAX_LENGTH_PASSWORD	20
#define LB_MAX_LENGTH_TICKET_PREFIX	4
#define LB_MAX_LENGTH_MESSAGE	20
#define LB_MAX_LENGTH_TICKET	20
#define LB_MAX_LENGTH_TITLE	20
#define LB_MAX_LENGTH_SEX	4

//#define LB_NUMBER_OF_COLUMNS_DEPARTMENT			7
//#define LB_NUMBER_OF_COLUMNS_TYPE				5
//#define LB_NUMBER_OF_COLUMNS_DOCTOR				9
//#define LB_NUMBER_OF_COLUMNS_ROOM				5
//#define LB_NUMBER_OF_COLUMNS_DUTY				7
//#define LB_NUMBER_OF_COLUMNS_PATIENT			14


typedef struct _LBINSP_item_ops{
	int (*save)(struct _LB_TriageDB* triageDB,LBINSP_item *lbinsp_item);
	int (*get)(struct _LB_TriageDB* triageDB,unsigned int id, LBINSP_item *lbinsp_item);
	int (*get_all_item)(struct _LB_TriageDB* triageDB,ss_db_result_t **result);
	int (*get_actived_items_str)(struct _LB_TriageDB *triageDB,char**actived_items_str,int *number_of_actived_items);
	int (*set_actived_items) (struct _LB_TriageDB* triageDB,const int *ids,const int size);
}LBINSP_item_ops;

typedef struct _LB_Department
{
	unsigned int id;
	char code[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	char ticket_prefix[LB_MAX_LENGTH_TICKET_PREFIX+1];
	int is_actived;
	int nAreaID;												// ÇøºÅ
}LB_Department;

typedef struct _LB_Type{
	unsigned int id;
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	char department_code[LB_MAX_LENGTH_CODE+1];
	unsigned int  department_id;
	unsigned int isExpert;
}LB_Type;

typedef struct _LB_Doctor{
	unsigned int id;
	char code[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	char title[LB_MAX_LENGTH_NAME+1];
	char sex[LB_MAX_LENGTH_NAME+1];
	char username[LB_MAX_LENGTH_USERNAME+1];
	char password[LB_MAX_LENGTH_PASSWORD+1];
	int login_state;
}LB_Doctor;

typedef struct _LB_Room{
	unsigned int id;
	int number;
	char name[LB_MAX_LENGTH_NAME+1];
	char message[LB_MAX_LENGTH_MESSAGE+1];
	unsigned int  area_id;
}LB_Room;

typedef struct _LB_Duty{
	unsigned int id;
	unsigned int  caller_address;   /*½ÐºÅÆ÷±àºÅ */
	unsigned int  doctor_id;
	int dayofweek;
	int timeofday;
	unsigned int  type_id;
	unsigned int  room_id;
	unsigned int department_id;
}LB_Duty;

typedef struct _LB_Patient{
	unsigned int id;
	char sn[LB_MAX_LENGTH_CODE+1];
	char code[LB_MAX_LENGTH_CODE+1];
	char sscard[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	unsigned int  department_id;
	unsigned int  type_id;
	unsigned int  doctor_id;
	char register_time[DEFAULT_TIME_STRING_LENGTH+1];
	int state;
	char ticket_number[LB_MAX_LENGTH_TICKET+1];
	int ticket_order;
	char ticket_time[DEFAULT_TIME_STRING_LENGTH+1];
	char call_time[DEFAULT_TIME_STRING_LENGTH+1];
	char treat_time[DEFAULT_TIME_STRING_LENGTH+1];
	int reg_state;
	int queue_ahead;
	int calling_doctorid;
}LB_Patient;

typedef struct _LB_Audio
{
	int area_id;
	char audio_ip[16];
	int department_id;
}LB_Audio;

typedef struct _LBINSP_Item
{
	unsigned int id;
	char code[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_CODE+1];
	unsigned int is_actived;
}LBINSP_Item;

typedef struct _LBINSP_room
{
	unsigned int id;
	char code[LBINSP_MAX_LENGTH_CODE];
	char name[LBINSP_MAX_LENGTH_NAME];
	char abbr[LB_MAX_LENGTH_ABBR];
	unsigned int number;
}LBINSP_room;

typedef struct _LBINSP_patient
{
	unsigned int id;
	char charge_code[LBINSP_MAX_LENGTH_CODE];
	char code[LBINSP_MAX_LENGTH_CODE];
	char name[LBINSP_MAX_LENGTH_NAME];
	char abbr[LB_MAX_LENGTH_ABBR];
	unsigned int item_id;
	unsigned int device_id;
	char last_modify[DEFAULT_TIME_STRING_LENGTH+1];
	char ticket_number[LB_MAX_LENGTH_TICKET+1];
	char ticket_time[DEFAULT_TIME_STRING_LENGTH+1];
	char call_time[DEFAULT_TIME_STRING_LENGTH+1];
	char end_time[DEFAULT_TIME_STRING_LENGTH+1];
	unsigned int state;
	
}LBINSP_patient;

typedef struct _LB_DashboardData
{
	unsigned int area;
	char title[16];
	char k1[16];
	char v1[16];
	char k2[16];
	char v2[16];
	char k3[16];
	char v3[16];
	char k4[16];
	char v4[16];
}LB_DashboardData;

typedef struct _LB_DashboardMessage
{
	char title[16];
	char message[1024];
}LB_DashboardMessage;

typedef int (*_lb_fn_)(struct _LB_TriageDB* );
typedef int (*_lb_fn_execute)(struct _LB_TriageDB* triageDB, const char* sql);
typedef int (*_lb_fn_query)(struct _LB_TriageDB* triageDB,const char* sql,ss_db_result_t **result);
typedef int (*_lb_fn_get_next_id)(struct _LB_TriageDB* triageDB,const char* table_name);
typedef int (*_lb_fn_get_id)(struct _LB_TriageDB* triageDB,const char* tablename,const char* fieldname,const char* fieldvalue);
typedef int (*_lb_fn_get_records_of_table)(struct _LB_TriageDB* triageDB, const char* tablename);
typedef int (*_lb_fn_get_next_ticketnumber)(struct _LB_TriageDB* triageDB, const char* tablename,const char* code);

typedef struct _LB_Department_ops{
	int (*save)(struct _LB_TriageDB* triageDB,LB_Department *lb_department);
	int (*get)(struct _LB_TriageDB* triageDB,unsigned int id, LB_Department *lb_department);
    int (*get_actived_departments_str) (struct _LB_TriageDB* triageDB,char**actived_departments_str,int *number_of_actived_departments);
	int (*set_actived_departments) (struct _LB_TriageDB* triageDB,const int *ids,const int size);
	int (*get_all_departments)(struct _LB_TriageDB* triageDB,ss_db_result_t **result);
}LB_Department_ops;

typedef struct _LB_Type_ops{
	int (*save)(struct _LB_TriageDB* triageDB,LB_Type *lb_type);
	int (*get) (struct _LB_TriageDB* triageDB,unsigned int id, LB_Type *lb_type);
	int (*get_department_types)(struct _LB_TriageDB *triageDB,unsigned int department_id,ss_db_result_t **result);
	int (*get_all_types)(struct _LB_TriageDB *triageDB, ss_db_result_t **result);
}LB_Type_ops;

typedef struct _LB_Doctor_ops{
	int (*save)(struct _LB_TriageDB* triageDB,LB_Doctor *lb_doctor);
	int (*get)(struct _LB_TriageDB *triageDB,unsigned int id, LB_Doctor *lb_doctor);
	int (*get_department_doctors)(struct _LB_TriageDB *triageDB,unsigned int department_id,ss_db_result_t **result);
	int (*get_all_doctors)(struct _LB_TriageDB *triageDB,ss_db_result_t **result);
}LB_Doctor_ops;

typedef struct _LB_Duty_ops{
	int (*save)(struct _LB_TriageDB* triageDB,LB_Duty *lb_duty);
	int (*get)(struct _LB_TriageDB *triageDB,unsigned int id,LB_Duty *lb_duty);
}LB_Duty_ops;

typedef struct _LB_Room_ops{
	int (*save)(struct _LB_TriageDB* triageDB,LB_Room *lb_room);
	int (*get)(struct _LB_TriageDB *triageDB,unsigned int id,LB_Room *lb_room);
	int (*get_room_id)(struct _LB_TriageDB* triageDB,const int number,const char* name,const int area_id);
}LB_Room_ops;

typedef struct _LB_Patient_ops{
	int (*save)(struct _LB_TriageDB* triageDB,LB_Patient *lb_patient);
	int (*get)(struct _LB_TriageDB *triageDB,unsigned int id,LB_Patient *lb_patient);
	int (*get_patients)(struct _LB_TriageDB* triageDB,const char* start_register_time,const char* end_register_time,ss_db_result_t **result);
}LB_Patient_ops;

typedef struct _LB_HIS_ops{

	int (*import_lbinsp_item)(struct _LB_TriageDB *triageDB, 
		const char* code, 
		const char* name,  
		BOOL isForce);

	int (*import_lbinsp_room)(struct _LB_TriageDB *triageDB, 
		const char* code, 
		const char* name,  
		BOOL isForce);

	int (*import_lbinsp_device)(struct _LB_TriageDB * triageDB,
		const char *code,
		const char *name,
		BOOL isForce);

	int (*import_lbinsp_patient)(struct _LB_TriageDB *triageDB,
		const char * charge_code,
		const char* code,
		const char* name,
		const char* abbr,
		const char* item_code,
		const char* device_code ,
		const char* last_modify);

	int (*import_lb_department)(LB_HISDBConnType hisDBConnType,
								struct _LB_TriageDB* triageDB,
								const char* code, 
								const char* name, 
								BOOL isForce);
	int (*import_lb_type)(LB_HISDBConnType hisDBConnType,
						struct _LB_TriageDB* triageDB, 
						const char* name,
						const char* department_code,
						BOOL isForce);
	int (*import_lb_doctor)(LB_HISDBConnType hisDBConnType,
							struct _LB_TriageDB* triageDB,
							const char* code,
							const char* name,
							const char* title,
							const char* sex,
							const char* department_code,
							BOOL isForce);
	int (*import_lb_nurse)(LB_HISDBConnType hisDBConnType,
							struct _LB_TriageDB* triageDB,
								const char* code,
								const char* name,
								const char* title,
								const char* sex,
								const char* department_code,
								BOOL isForce);
	//int (*import_lb_duty)(struct _LB_TriageDB* triageDB,
	//						const char* doctor_code,
	//						const int dayofweek,
	//						const int timeofday,
	//						const char* type_code,
	//						const int room_number,
	//						const char* room_name,
	//						BOOL isForce);
	int (*import_lb_patient)(LB_HISDBConnType hisDBConnType,
		struct _LB_TriageDB *triageDB,
		const char* sn,
		const char* code,
		const char* sscard,
		const char* name,
		const char* department_code,
		const char* type_code ,
		const char* doctor_code,
		const char* register_time,
		const char* ticket_number,
		const int ticket_order,
		const int state);
	int (*import_lb_inpatient)( struct _LB_TriageDB *triageDB,
								const char *code,         
								const char *name,        
								const char *abbr,        
								const int   sex,          
								const char *birthday,     
								const char *checkin_date, 
								const char *checkout_date,
								const int   zone_number,
								const char *room_number,  
								const char *bed_number,  
								const char *doctor,       
								const int   care_level,   
								const char *condition,   
								const char *note,         
								const char *last_modify);

	int (*import_lb_dashboard_data)(struct _LB_TriageDB *triageDB,
		const int area,         
		const char *title,         
		const char *k1,
		const char *v1,
		const char *k2,
		const char *v2,
		const char *k3,
		const char *v3,
		const char *k4,
		const char *v4);
	int (*import_lb_dashboard_message)(struct _LB_TriageDB *triageDB,
		const char *title,         
		const char *message);
}LB_HIS_ops;


typedef struct _LB_TriageDB{
	ss_mutex_t	lock;
	ss_db_t *ss_db;
	/*
	* Callback function for Execute any INSERT,DELETE,UPDATE statements
	* @params triageDB - LB_TriageDB instance
	*         sql - any INSERT,DELETE,UPDATE statements
	* @return the number of rows affected by an UPDATE, INSERT, or DELETE statement;
	*          -1 if a error occurs
	*/
	_lb_fn_execute execute;

	/*
	* Callback function for Execute any SELECT statements.
	* @params triageDB - LB_TriageDB instance
	*         sql - any SELECT statements
	*         result - ss_db_result_t** result will be saved here
	* @return the number of records by an SELECT statement
	*         -1 if a error occurs
	*/
	_lb_fn_query query;

	/*
	* Callback function for start transaction.
	* @params triageDB - LB_TriageDB instance
	* @return 0 if OK
	*         -1 if a error occurs
	*/
	_lb_fn_ transaction_start;

	/*
	* Callback function for rollback transaction.
	* @params triageDB - LB_TriageDB instance
	* @return 0 if OK
	*         -1 if a error occurs
	*/
	_lb_fn_ transaction_rollback;

	/*
	* Callback function for commit transaction.
	* @params triageDB - LB_TriageDB instance
	* @return 0 if OK
	*         -1 if a error occurs
	*/
	_lb_fn_ transaction_commit;

	_lb_fn_get_next_id get_next_id;

	_lb_fn_get_id get_id;

	/*
	* Callback function for clean triage queue database.
	* No lock needed, lock inside
	* @params triageDB - LB_TriageDB instance
	* @return 0 if OK
	*         -1 if a error occurs
	*/
	_lb_fn_ clean_db_triage;
	_lb_fn_ clean_db_insp_triage; 
	_lb_fn_ clean_db_inpatient;
	_lb_fn_ clean_db_lbqy_dispensary;
	_lb_fn_ clean_db_lbqy_doctor;
	_lb_fn_ clean_db_lbqy_patient;
	_lb_fn_ clean_db_lb_dashboard;

	_lb_fn_get_records_of_table get_records_of_table;
	_lb_fn_get_next_ticketnumber get_next_ticketnumber;

	const LBINSP_item_ops	*lbinsp_item_ops;
	const LB_Department_ops *lb_department_ops; 
	const LB_Type_ops		*lb_type_ops; 
	const LB_Doctor_ops		*lb_doctor_ops; 
	const LB_Duty_ops		*lb_duty_ops; 
	const LB_Room_ops		*lb_room_ops; 
	const LB_Patient_ops	*lb_patient_ops; 
	const LB_HIS_ops		*lb_his_ops; 
}LB_TriageDB;

SS_API LB_TriageDB* LB_TriageDB_new(LB_HISDBConnType hisDBConnType,const char* localDBName);
SS_API void LB_TriageDB_destroy(LB_TriageDB *triageDB);

#endif //_LB_TRIAGEDB_H_
