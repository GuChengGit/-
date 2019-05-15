#ifndef _LB_DASHBOARD_H_
#define _LB_DASHBOARD_H_

#define LB_DASHBOARD_MAX_AREA_NUMBER			7
#define LB_DASHBOARD_MAX_KEYVALUE_NUMBER		4

#define LB_DASHBOARD_MAX_MESSAGE_LENGTH			1024
#define LB_DASHBOARD_MAX_TITLE_LENGTH			16
#define LB_DASHBOARD_MAX_KEY_LENGTH				16
#define LB_DASHBOARD_MAX_VALUE_LENGTH			16

#define LB_DASHBOARD_AREA_INDEX_ALL				-1
#define LB_DASHBOARD_AREA_INDEX_MESSAGE			99

#define LB_DASHBOARD_SIZE_INDEX			(sizeof(int))
#define LB_DASHBOARD_SIZE_AREA			(LB_DASHBOARD_MAX_TITLE_LENGTH+(LB_DASHBOARD_MAX_KEY_LENGTH+LB_DASHBOARD_MAX_VALUE_LENGTH)*LB_DASHBOARD_MAX_KEYVALUE_NUMBER)
#define LB_DASHBOARD_SIZE_ALLAREA		(LB_DASHBOARD_SIZE_AREA*LB_DASHBOARD_MAX_AREA_NUMBER)
#define LB_DASHBOARD_SIZE_MESSAGEAREA	(LB_DASHBOARD_MAX_TITLE_LENGTH+LB_DASHBOARD_MAX_MESSAGE_LENGTH)
#define LB_DASHBOARD_SIZE_ALLDATA		(LB_DASHBOARD_SIZE_INDEX+LB_DASHBOARD_SIZE_ALLAREA+LB_DASHBOARD_SIZE_MESSAGEAREA)

#define LB_DASHBOARD_OFFSET_INDEX		0
#define LB_DASHBOARD_OFFSET_AREA		(LB_DASHBOARD_OFFSET_INDEX+LB_DASHBOARD_SIZE_INDEX)
#define LB_DASHBOARD_OFFSET_MESSAGE		(LB_DASHBOARD_OFFSET_AREA+LB_DASHBOARD_SIZE_ALLAREA)


typedef enum _LB_DASHBOARD_DATASOURCE{
	LB_DASHBOARD_DATASOURCE_LOCAL           = 0,  	/*本地数据源*/
	LB_DASHBOARD_DATASOURCE_HIS_DATA,				/*HIS数据源(不含本地留言)*/ 
	LB_DASHBOARD_DATASOURCE_HIS_ALL,				/*HIS数据源(含本地留言)*/ 
}LB_DASHBOARD_DATASOURCE_t;

typedef const char* (*_fn_lb_dashboard_get_area_t) (struct _LB_DASHBOARD*,unsigned int areaIndex,unsigned int keyIndex);
typedef void (*_fn_lb_dashboard_set_area_t) (struct _LB_DASHBOARD*,unsigned int areaIndex,unsigned int keyIndex,char * keyValue);
typedef const char* (*_fn_lb_dashboard_get_area_title_t) (struct _LB_DASHBOARD*,unsigned int areaIndex);
typedef void (*_fn_lb_dashboard_set_area_title_t) (struct _LB_DASHBOARD*,unsigned int areaIndex,char * keyValue);

typedef const char* (*_fn_lb_dashboard_get_interserverip)(struct _LB_DASHBOARD*);
typedef void (*_fn_lb_dashboard_set_interserverip)(struct _LB_DASHBOARD*,char *interserverip);
typedef const char* (*_fn_lb_dashboard_get_t) (struct _LB_DASHBOARD*);
typedef void (*_fn_lb_dashboard_set_t) (struct _LB_DASHBOARD*,char * msg);

typedef int (*_fn_lb_dashboard_t) (struct _LB_DASHBOARD*);

typedef LB_DASHBOARD_DATASOURCE_t (*_fn_lb_dashboard_get_source_t) (struct _LB_DASHBOARD*);
typedef void (*_fn_lb_dashboard_set_source_t) (struct _LB_DASHBOARD*,LB_DASHBOARD_DATASOURCE_t);

typedef int (*_fn_lb_dashboard_get_current_area_t) (struct _LB_DASHBOARD*);
typedef void (*_fn_lb_dashboard_set_current_area_t) (struct _LB_DASHBOARD*,int);

typedef struct _LB_DASHBOARD_KEYVALUE {
	char key[LB_DASHBOARD_MAX_KEY_LENGTH];
	char value[LB_DASHBOARD_MAX_VALUE_LENGTH];
} LB_DASHBOARD_KEYVALUE_t;

typedef struct _LB_DASHBOARD_AREA {
	char title[LB_DASHBOARD_MAX_TITLE_LENGTH];
	LB_DASHBOARD_KEYVALUE_t data[LB_DASHBOARD_MAX_KEYVALUE_NUMBER];
} LB_DASHBOARD_AREA_t;

typedef struct _LB_DASHBOARD_DATA{
	int currentArea;
	LB_DASHBOARD_AREA_t area[LB_DASHBOARD_MAX_AREA_NUMBER];
	char message_title[LB_DASHBOARD_MAX_TITLE_LENGTH];
	char message[LB_DASHBOARD_MAX_MESSAGE_LENGTH];
} LB_DASHBOARD_DATA_t;

typedef struct _LB_DASHBOARD {
	LB_DASHBOARD_DATA_t data;
	LB_DASHBOARD_DATASOURCE_t data_source;
	char interServerIP[20];
	ss_mutex_t	lock;
	_fn_lb_dashboard_get_area_t getKey;
	_fn_lb_dashboard_set_area_t setKey;
	_fn_lb_dashboard_get_area_t getValue;
	_fn_lb_dashboard_set_area_t setValue;
	_fn_lb_dashboard_get_area_title_t getTitle;
	_fn_lb_dashboard_set_area_title_t setTitle;
	_fn_lb_dashboard_get_interserverip getInterserverIP;
	_fn_lb_dashboard_set_interserverip setInterserverIP;

	_fn_lb_dashboard_get_t getMessageTitle;
	_fn_lb_dashboard_get_t getMessage;
	_fn_lb_dashboard_set_t setMessageTitle;
	_fn_lb_dashboard_set_t setMessage;
	_fn_lb_dashboard_get_source_t getDataSource;
	_fn_lb_dashboard_set_source_t setDataSource;
	_fn_lb_dashboard_get_current_area_t getCurrentArea;
	_fn_lb_dashboard_set_current_area_t setCurrentArea;
	_fn_lb_dashboard_t load;
	_fn_lb_dashboard_t save;
} LB_DASHBOARD_t;

SS_API LB_DASHBOARD_t * LB_DASHBOARD_new();
SS_API void LB_DASHBOARD_destroy(LB_DASHBOARD_t *pInst);
SS_API int LB_DASHBOARD_fromBuff(LB_DASHBOARD_t *pInst,char *buff,int size);
SS_API int LB_DASHBOARD_toBuff(LB_DASHBOARD_t *pInst,char *buff,int size);

#endif
