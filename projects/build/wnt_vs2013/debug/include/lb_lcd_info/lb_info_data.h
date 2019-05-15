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

#define LBINFO_VALUE_ERASE			-1								// 删除信息
#define LBINFO_VALUE_ADD			0								// 添加信息

typedef enum _LB_INFO_INDEX{
	LBINDEX_NUMBER           = 0,  	/*票号*/     
	LBINDEX_NAME                ,  	/*姓名*/     
	LBINDEX_DEPARTMENT          ,  	/*科室*/     
	LBINDEX_PRISON_SECTITON     ,  	/*监区*/     
	LBINDEX_TYPE                ,  	/*门诊类别*/ 
	LBINDEX_DOCTOR              ,  	/*医生*/     
	LBINDEX_FAMILY              ,  	/*家属*/     
	LBINDEX_ROOM_CODE           ,  	/*诊室编号*/     
	LBINDEX_WINDOW              ,  	/*窗口*/     
	LBINDEX_STATE               ,  	/*状态*/     
	LBINDEX_DESCRIPTION         ,  	/*备注*/     
	LBINDEX_WAITING_PATIENT     ,  	/*等待人员*/ 
	LBINDEX_WAITING_COUNT       ,  	/*等待人数*/ 
	LBINDEX_MESSAGE             ,  	/*信息*/    
	LBINDEX_SENTRY_STATE		,	/*状态－－－－－岗亭显示屏*/
	LBINDEX_PRISONER			,	/*犯人*/
	LBINDEX_TITLES				,	/*职称*/
	LBINDEX_TOBEPATIENT_NUMBER	,	/*待诊票号*/
	LBINDEX_DEPARTMENT_DOCTOR	,	/*科室医生*/
	LBINDEX_ROOM_NAME			,	/*诊室名称*/
	LBINDEX_WAIT_DESCRIPTION    ,   /*等待备注*/
	LBINDEX_BED_NUMBER		    ,   /*床号*/
	LBINDEX_TOTAL_BED_NUMBER    ,   /*总床号*/
	LBINDEX_IS_INIT_DISPLAY     ,   /*是否初始化显示屏*/
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