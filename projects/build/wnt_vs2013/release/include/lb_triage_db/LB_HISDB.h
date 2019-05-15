#ifndef _LB_HISDB_H_
#define _LB_HISDB_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "LB_HisOption.h"

typedef int (*_lb_fn_hisdb)(struct _LB_HISDB*);

typedef union _LB_HISDBConnUnion{
	struct _LB_DBClient *db;
	struct _LB_WebServiceClient* ws;
}LB_HISDBConnUnion;

typedef struct _LB_HISDB
{
	ss_mutex_t	lock;
	LB_HISDBConnUnion conn;
	LB_HisOption *opt;
	BOOL	isConnected;
	_lb_fn_hisdb LB_connect;
	_lb_fn_hisdb LB_disconnect;
}LB_HISDB;

SS_API LB_HISDB* LB_HISDB_new(LB_HisOption *opt);
SS_API void LB_HISDB_destroy(LB_HISDB *hisDB);

#endif //_LB_HISDB_H_
