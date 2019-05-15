#ifndef _LB_TRIAGEQUEUE_H_
#define _LB_TRIAGEQUEUE_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "LB_TriageDB.h"
#include "LB_HISDB.h"

#define QUEUE_DEVIATION_TIME 10*60
#define INSP_QUEUE_DEVIATION_TIME 10*60

typedef enum _lb_triage_event_id
{
	/** Unidentified event. */
	LB_TRIAGE_EVENT_UNKNOWN =0,

	/** initialize finished. */
	LB_TRIAGE_EVENT_BASEINFO_LOADED,

	/** New patient added. */
	LB_TRIAGE_EVENT_NEW_PATIENT,

	/** HIS����ʧ��*/
	LB_TRIAGE_EVENT_HIS_CONNECT_FAILED,

	/** New inpatient added. */
	LB_TRIAGE_EVENT_NEW_INPATIENT,

	LB_TRIAGE_ENENT_NEW_INSP_PATIENT,
	
	/** HIS���ӳɹ�*/
	LB_TRIAGE_EVENT_HIS_CONNECT_OK,

	LBQY_EVENT_DISPENSARY_BASEINFO,
	LBQY_EVENT_DOCTOR_NEW,
	LBQY_EVENT_PATIENT_NEW,
	
	LB_DASHBOARD_UPDATE,
	LB_TRIAGE_EVENT_BASEINFO_MODIFY, //������Ϣ���޸�

} lb_triage_event_id;

typedef int (*_lb_fn_event_callback)(lb_triage_event_id e,void* data);

extern int g_IsBaseInfoChanged;

typedef struct _LB_TriageQueue
{
	ss_mutex_t	lock;
	LB_TriageDB *localDB;
	LB_HISDB *hisDB;

	char *actived_item_list;
	int actived_item_length;
	char last_query_time_insp_patient[DEFAULT_TIME_STRING_LENGTH+1];
	char last_query_filename_insp_patient[MAX_PATH];

	char *actived_department_list;
	int actived_department_length;
	char last_query_time[DEFAULT_TIME_STRING_LENGTH+1];
	char last_query_filename[MAX_PATH];
	char last_query_time_inpatient[DEFAULT_TIME_STRING_LENGTH+1];
	char last_query_filename_inpatient[MAX_PATH];
	ss_thread_t loadingThread;
	ss_thread_t patinetUpdateThread;
	BOOL isHisRunning;
	BOOL isLocalDBReady;
	BOOL isLoading;	//�ֶ�������¶�ȡ������Ϣʱ�øñ�־Ϊ1
	BOOL isForceLoading;
	BOOL isReLoadPatient;
	_lb_fn_event_callback event_cb;
}LB_TriageQueue;

#ifndef _LB_TRIAGE_HIS_CONNECT_
#define LB_TRIAGE_HIS_CONNECT(queue) \
	do{\
	SS_LOCK(queue);\
	if((queue)->hisDB->LB_connect((queue)->hisDB)==0)\
{if(LB_HISDB_CONN_DB == queue->hisDB->opt->hisDBConnType) (queue)->event_cb(LB_TRIAGE_EVENT_HIS_CONNECT_OK,NULL);}\
		else if(LB_HISDB_CONN_DB == queue->hisDB->opt->hisDBConnType) (queue)->event_cb(LB_TRIAGE_EVENT_HIS_CONNECT_FAILED,NULL);\
		SS_UNLOCK(queue);\
	} while(0)

#define LB_TRIAGE_HIS_DISCONNECT(queue) (queue)->hisDB->LB_disconnect((queue)->hisDB)

#define LB_TRIAGE_TRANSACTION_START(queue) (queue)->localDB->transaction_start((queue)->localDB)
#define LB_TRIAGE_TRANSACTION_COMMIT(queue) (queue)->localDB->transaction_commit((queue)->localDB)
#define LB_TRIAGE_TRANSACTION_ROLLBACK(queue) (queue)->localDB->transaction_rollback((queue)->localDB)

#endif

SS_API int lb_triage_start(LB_HisOption *opt);
SS_API int lb_triage_stop();

SS_API  LB_TriageQueue * lb_triage_get_instance();

SS_API int lb_triage_execute(const char* sql);
SS_API int lb_triage_query(const char* sql,ss_db_result_t **result);

SS_API BOOL lb_triage_is_ready();
SS_API BOOL lb_triage_is_HIS_ready();
SS_API int  lb_triage_set_event_callback(_lb_fn_event_callback cb);
SS_API int lb_triage_load_his_baseinfo(void);

SS_API int lb_triage_save_department(LB_Department *lb_department);
SS_API int lb_triage_set_actived_departments(const int *ids,const int size);
SS_API int lb_triage_get_all_departments(ss_db_result_t **result);
SS_API int lb_triage_get_department(unsigned int id,LB_Department *lb_department);

SS_API int lb_triage_save_type(LB_Type *lb_type);
SS_API int lb_triage_get_departments_types(unsigned int department_id,ss_db_result_t **result);
SS_API int lb_triage_get_all_types(ss_db_result_t **result);

SS_API int lb_triage_save_doctor(LB_Doctor *lb_doctor);
SS_API int lb_triage_get_department_doctors(unsigned int department_id,ss_db_result_t **result);
SS_API int lb_triage_get_all_doctors(ss_db_result_t **result);

SS_API int lb_triage_save_room(LB_Room *lb_room);

SS_API int lb_triage_save_duty(LB_Duty *lb_duty);

SS_API int lb_triage_save_patinet(LB_Patient *lb_patient);
SS_API int lb_triage_get_patinets(const char* start_register_time,const char* end_register_time,ss_db_result_t **result);

SS_API int lb_triage_set_actived_items(const int *ids,const int size);

void __update_last_query_time(LB_HisDateFormat dateInfo,char *last_query_filename,char *last_query_time,char *time_now);
int _load_lbqy_dispensary(LB_TriageQueue* queue);
 int clearHostoryPatientData(void);
//��ȡ���Ʊ��
//���룺department_id������id��type_id ���ID��max_ticketnumber �������Ʊ��
// ��department_id ��type_id Ϊ0ʱ��ֻ�鵱������Ʊ��
//SS_API int getMaxTicketNumber(int department_id,int type_id,char *max_ticketnumber);
 //���ܣ���ȡ���order
 //���룺department_id������id��type_id ���ID��
 //����ֵ�����order
 // ��department_id ��type_id Ϊ0ʱ��ֻ�鵱������Ʊ��
 //��doctor_id��Ϊ0ʱ�����Ҹ�ҽ�������order
 SS_API int getMaxTickeOrder(int department_id,int type_id,int doctor_id);
//����ȡ����ʱ���ʹ��Ϊ00��00
//���ڿ����¶�ȡ���ˣ�����ɾ����ǰ�ŶӲ�����Ϣ
//����ֵ �ɹ���TRUE ʧ�� FALSE
SS_API int resetLastQueueTempFile(void);
//����ֵ �ɹ���TRUE ʧ�� FALSE
//��յ������в������ݣ������¶�ȡ������Ϣ
SS_API int EmptyTodayPatientData(void);
SS_API int HisConnect(void);
SS_API int HisDisConnect(void);
SS_API ss_db_result_t* his_query(char *sql);
//��ȡ���Ʊ��
//���룺device_id ��item_id��Ϊ0ʱ�����ص������Ʊ��
//device_id ��Ϊ0ʱ ����device_id �����Ʊ��
//item_id��Ϊ0ʱ������device_id �����Ʊ��
SS_API int lbinsp_GetMaxTicketNumber(int item_id,int device_id);

int ticketnumber2int(char *str);
#endif //_LB_TRIAGEQUEUE_H_
