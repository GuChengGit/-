#ifndef _SS_HIS_H_
#define _SS_HIS_H_
#include "ss_base/ss_def.h"
#include "ss_base/ss_thread.h"

#define LBHIS_CONFIG_FILE_SECTION          	"LB_CONFIG"

#define STR_HIS_ENABLED          			"HIS_ENABLED" //是否激活医院的信息系统(HIS)连接
#define STR_HIS_TYPE          				"HIS_TYPE"
#define STR_HIS_VERSION          			"HIS_VERSION"
#define STR_HIS_SERVICE_PORT        	  	"HIS_SERVICE_PORT"
#define STR_HIS_IP          				"HIS_IP"
#define STR_HIS_PORT          				"HIS_PORT"
#define STR_HIS_USER          				"HIS_USER"
#define STR_HIS_PASSWORD          			"HIS_PASSWORD"
#define STR_HIS_NAME         				"HIS_NAME"
#define STR_HIS_CHANGED        				"HIS_CHANGED"
#define STR_HIS_RECONNECT        			"HIS_RECONNECT"
#define STR_HIS_STATUS						"HIS_STATUS"

#define DEFAULT_HIS_SERVICE_PORT    	    5080
#define LB_HIS_DSN_NAME						"LBHISdsn"
#define LB_HIS_DSN_DRIVER_SQLSERVER			"SQL Server"
//#define LB_HIS_DSN_DRIVER_ORACLE			"Microsoft ODBC for Oracle"
#define LB_HIS_DSN_DRIVER_ORACLE		"Oracle in OraClient11g_home1"

typedef void (* fn_his)(struct _HISInfo_t *);
typedef BOOL (* fn_his_check)();
typedef void (* fn_his_connect)();
typedef void (* fn_his_reconnect)();

typedef enum {
	HIS_TYPE_UNKNOW=-1,
	HIS_TYPE_SQLSERVER=0,
	HIS_TYPE_SYSBASE,
	HIS_TYPE_MYSQL,
	HIS_TYPE_ORACLE,
	HIS_TYPE_DEMO
} HISType;

typedef enum {
	HIS_SQLSERVER_6_5=0,
	HIS_SQLSERVER_7,
	HIS_SQLSERVER_2000,
	HIS_SQLSERVER_2005,
	HIS_SQLSERVER_2008
} SQLSERVER_Version;

typedef enum {
	HIS_ORACLE_8i=0,
	HIS_ORACLE_9i,
	HIS_ORACLE_10g,
	HIS_ORACLE_11g
} ORACLE_Version;

typedef enum {
	HIS_SYSBASE_LT10=0,
	HIS_SYSBASE_GE10
} SYSBASE_Version;

typedef enum {
	HIS_MYSQL_GE5=0
} MYSQL_Version;

typedef union{
	SQLSERVER_Version ver_sqlserver;
	SYSBASE_Version ver_sysbase;
	MYSQL_Version ver_mysql;
	ORACLE_Version ver_oracle;
}HISVersion;

typedef struct _HISInfo_t{
	BOOL isEnabled;
	HISType type;
	HISVersion version;
	unsigned int service_port;
	char ip[16];
	unsigned int port;
	char user[32];
	char password[32];
	char database[32];
	fn_his save;
	fn_his_check isConnected;
	fn_his_connect connect;
	fn_his_reconnect reConnect;
	BOOL isRunning;
	ss_mutex_t	lock;
	ss_thread_t checkThread;
} HISInfo_t;

SS_API HISInfo_t *HISInfo_new(BOOL info_isEnabled,
					   HISType info_type,
					   HISVersion info_version,
					   unsigned int info_service_port,
					   char * info_ip,
					   unsigned int info_port,
					   char *info_user,
					   char *info_password,
					   char *info_database);

SS_API void HISInfo_destroy(HISInfo_t *info);
SS_API char* HISInfo_toString(HISInfo_t *info);
SS_API void HISInfo_dump(HISInfo_t *info);
SS_API void* _HISInfo_checkProc(void* pArg);

#endif

