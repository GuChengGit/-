#ifndef _LB_INFO_DATA_H_
#define _LB_INFO_DATA_H_
#include <ss_base/ss_base.h>

#define LBINDEX_MAX					32

#define LBINFO_ACTION_LBINFO		"LBINFO"
#define LBINFO_ACTION_LBINFO_OK		"LBINFO_OK"
#define LBINFO_ACTION_ERASE			"LBINFO_ERASE"
#define LBINFO_ACTION_ERASE_OK		"LBINFO_ERASE_OK"

#define LBINFO_KEY_ACTION			"Action"
#define LBINFO_KEY_TEMPLATE			"Template"
#define LBINFO_KEY_ID				"ID"
#define LBINFO_KEY_SEQUENCE			"Sequence"
#define LBINFO_VALUE_NULL			"__NULL__"
#define LBINFO_DATATYPE				"DataType"

#define LBINFO_VALUE_ERASE			-1								// ɾ����Ϣ
#define LBINFO_VALUE_ADD			0								// �����Ϣ

typedef enum _LB_INFO_INDEX{
	LBINDEX_NUMBER           = 0,  	/*Ʊ��*/     
	LBINDEX_NAME                ,  	/*����*/     
	LBINDEX_DEPARTMENT          ,  	/*����*/     
	LBINDEX_PRISON_SECTITON     ,  	/*����*/     
	LBINDEX_TYPE                ,  	/*�������*/ 
	LBINDEX_DOCTOR              ,  	/*ҽ��*/     
	LBINDEX_FAMILY              ,  	/*����*/     
	LBINDEX_ROOM_CODE           ,  	/*���ұ��*/     
	LBINDEX_WINDOW              ,  	/*����*/     
	LBINDEX_STATE               ,  	/*״̬*/     
	LBINDEX_DESCRIPTION         ,  	/*��ע*/     
	LBINDEX_WAITING_PATIENT     ,  	/*�ȴ���Ա*/ 
	LBINDEX_WAITING_COUNT       ,  	/*�ȴ�����*/ 
	LBINDEX_MESSAGE             ,  	/*��Ϣ*/    
	LBINDEX_SENTRY_STATE		,	/*״̬������������ͤ��ʾ��*/
	LBINDEX_PRISONER			,	/*����*/
	LBINDEX_TITLES				,	/*ְ��*/
	LBINDEX_TOBEPATIENT_NUMBER	,	/*����Ʊ��*/
	LBINDEX_DEPARTMENT_DOCTOR	,	/*����ҽ��*/
	LBINDEX_ROOM_NAME			,	/*��������*/
	LBINDEX_WAIT_DESCRIPTION    ,   /*�ȴ���ע*/
	LBINDEX_BED_NUMBER		    ,   /*����*/
	LBINDEX_TOTAL_BED_NUMBER    ,   /*�ܴ���*/
	LBINDEX_IS_INIT_DISPLAY     ,   /*�Ƿ��ʼ����ʾ��*/
}LB_INFO_INDEX_t;

typedef const char* (*_fn_lb_info_data_get_t) (struct _LB_INFO_DATA*,LB_INFO_INDEX_t);
typedef void  (*_fn_lb_info_data_set_null_t) (struct _LB_INFO_DATA*,LB_INFO_INDEX_t);
typedef void  (*_fn_lb_info_data_set_t) (struct _LB_INFO_DATA*,LB_INFO_INDEX_t,const char*);
typedef char* (*_fn_lb_info_data_format_t) (struct _LB_INFO_DATA*,const int,const unsigned int,const unsigned int );

typedef struct _LB_INFO_DATA {
	char** values;
	char* id;						
	_fn_lb_info_data_get_t get;
	_fn_lb_info_data_set_t set;
	_fn_lb_info_data_set_null_t set_empty;
	_fn_lb_info_data_format_t format;
} LB_INFO_DATA_t;

SS_API LB_INFO_DATA_t *LB_INFO_DATA_new(const char* id);
SS_API void LB_INFO_DATA_destroy(LB_INFO_DATA_t *data);
#endif //_LB_INFO_DATA_H_