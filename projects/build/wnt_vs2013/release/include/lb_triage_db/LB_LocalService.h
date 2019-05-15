#ifndef _LB_LOCALSERVICE_H
#define _LB_LOCALSERVICE_H
#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include <ss_db/ss_db.h>

#include <lb_dashboard.h>

typedef struct _LB_LocalService
{
	ss_mutex_t	lock;
	ss_db_t *ss_db;
	BOOL isRunning;
	int port;
	ss_thread_t	hisThread;
	ss_threadpool_t *pool;
    char wsdl[MAX_PATH];
	BOOL isWsdlExist;
	LB_DASHBOARD_t *pDashboard;
	char photo_path_doctor[MAX_PATH];
	char photo_path_nurse[MAX_PATH];
}LB_LocalService;


SS_API void LB_LocalService_start(ss_db_t *ss_db,int port);
SS_API void LB_LocalService_stop();
SS_API LB_LocalService * LB_LocalService_getInstance();

#endif //_LB_LOCALSERVICE_H
