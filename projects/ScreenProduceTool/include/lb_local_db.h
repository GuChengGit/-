#ifndef _LB_LOCAL_DB_H_
#define _LB_LOCAL_DB_H_

#include <ss_db/ss_db.h>

typedef int  (*_fn_lb_local_db_open_t)    (struct _lb_local_db_ *db);
typedef void (*_fn_lb_local_db_close_t)   (struct _lb_local_db_ *db);
typedef int  (*_fn_lb_local_db_check_t)   (struct _lb_local_db_ *db);
typedef int  (*_fn_lb_local_db_execute_t) (struct _lb_local_db_ *db, const char *sql);
typedef int  (*_fn_lb_local_db_query_t)   (struct _lb_local_db_ *db, const char *sql, ss_db_result_t **result);

typedef int (*_fn_lb_local_db_start_keepalive_t) (struct _lb_local_db_* db);
typedef int (*_fn_lb_local_db_stop_keepalive_t) (struct _lb_local_db_* db);

typedef struct _lb_local_db_
{
	ss_db_t *p_db;
	BOOL    is_keep_alive;
	ss_thread_t p_thread;
	ss_mutex_t lock;

	_fn_lb_local_db_open_t open;                   // 连接
	_fn_lb_local_db_close_t close;                 // 关闭
	_fn_lb_local_db_check_t check;                 // 检查连接是否可用
	_fn_lb_local_db_execute_t execute;             // 执行
	_fn_lb_local_db_query_t query;                 // 查询
	_fn_lb_local_db_start_keepalive_t start_keepalive;    
	_fn_lb_local_db_stop_keepalive_t stop_keepalive;
}lb_local_db_t;

lb_local_db_t* lb_local_db_init(const char *name, ss_db_charset_t charset);
void lb_local_db_destroy(lb_local_db_t *db);

#endif