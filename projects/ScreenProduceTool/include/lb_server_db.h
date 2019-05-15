#ifndef _LB_SERVER_DB_H_
#define _LB_SERVER_DB_H_
#include <ss_db/ss_db.h>


#define LB_SERVER_DB_TYPE        HIS_TYPE_MYSQL
#define LB_SERVER_DB_VERSION     HIS_MYSQL_GE5
#define LB_SERVER_DB_USERNAME    "root"
#define LB_SERVER_DB_PASSWORD    "lonbon"
#define LB_SERVER_DB_PORT        3306

#define LB_VISIT_SERVER_DB_USER_NAME	"lb_visit"
#define LB_VISIT_SERVER_DB_PASSWORD		"lonbon"
#define LB_VISIT_SERVER_DB_PORT			3306

#define LB_VISIT_LOCAL_DB_NAME   "lonbon_visit"

#define LB_OPENSIPS_SERVER_DB_USER_NAME  "root"
#define LB_OPENSIPS_SERVER_DB_PASSWORD  "lonbon"
#define LB_OPENSIPS_SERVER_DB_PORT        3306

#define LB_MYSQL_START_TRANSACTION    "START TRANSACTION;"
#define LB_MYSQL_COMMIT               "COMMIT;"
#define LB_MYSQL_ROLLBACK             "ROLLBACK;"

typedef int  (*_fn_lb_server_db_open_t)    (ss_db_t *ss_db);
typedef void (*_fn_lb_server_db_close_t)   (ss_db_t *ss_db);
typedef int  (*_fn_lb_server_db_check_t)   (ss_db_t *ss_db);
typedef int  (*_fn_lb_server_db_execute_t) (ss_db_t *ss_db, const char *sql);
typedef int  (*_fn_lb_server_db_query_t)   (ss_db_t *ss_db, const char *sql, ss_db_result_t **result);

typedef struct _lb_server_db_
{
	ss_db_t *pData;

	_fn_lb_server_db_open_t open;                   // 连接
	_fn_lb_server_db_close_t close;                 // 关闭
	_fn_lb_server_db_check_t check;                 // 检查连接是否可用
	_fn_lb_server_db_execute_t execute;             // 执行
	_fn_lb_server_db_query_t query;                 // 查询
}lb_server_db_t;

lb_server_db_t* lb_local_server_db_init(const char *dbname, ss_db_charset_t charset);
lb_server_db_t* lb_visit_server_db_init(const char *dbname, ss_db_charset_t charset);
lb_server_db_t* lb_opensips_server_db_init(const char *dbname, ss_db_charset_t charset);
lb_server_db_t* lb_server_db_init(char *url, ss_db_charset_t charset);
void lb_server_db_destroy(lb_server_db_t *server_db);

int lb_db_get_str_value(ss_db_result_t* pResult, int nRow, int nCol, char* szOutput, int nLen);
int lb_db_get_str_value_by_col(ss_db_result_t* pResult, int nRow, const char* szColName, char* szOutput, int nLen);
int lb_db_get_int_value(ss_db_result_t* pResult, int nRow, int nCol, int* nValue);
int lb_db_get_int_value_by_col(ss_db_result_t* pResult, int nRow, const char* szColName, int* nValue);


#endif // end of _LB_SERVER_DB_H_
