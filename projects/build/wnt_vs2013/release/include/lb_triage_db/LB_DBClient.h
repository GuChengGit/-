#ifndef _LB_DBCLIENT_H_
#define _LB_DBCLIENT_H_
#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "LB_HisOption.h"

typedef int (*_lb_fn_db)(struct _LB_DBClient*);
typedef int (*_lb_fn_set_max_records)(struct _LB_DBClient*,int);

typedef struct _LB_DBClient{
	ss_mutex_t	lock;
	ss_db_t *ss_db;
	BOOL isConnected;
	LB_HisOption *opt;
	_lb_fn_db LB_connect;
	_lb_fn_db LB_disconnect;
}LB_DBClient;

SS_API LB_DBClient* LB_DBClient_new(LB_HisOption *opt);
SS_API void LB_DBClient_destroy(LB_DBClient *client);

#endif //_LB_DBCLIENT_H_
