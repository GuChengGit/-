#ifndef _SS_USER_SERVICE_H_
#define _SS_USER_SERVICE_H_
#ifdef __linux__

#include "ss_base/ss_def.h"
#include "ss_base/ss_thread.h"
#include "ss_base/ss_socket.h"

typedef struct _LB_UserServer
{
	SS_Socket* listenerSocket;
	ss_mutex_t	lock;
	ss_thread_t	dispatcherThread;
	BOOL isServerRunning;
	int port;
	struct sockaddr_in* bind_address;
}LB_UserServer;

SS_API void LB_UserServer_stop(int code);
SS_API int LB_UserServer_start();
SS_API LB_UserServer * LB_UserServer_getInstance();
SS_API int LB_UserClient_createUser(const char*username,const char*password,const int space);
SS_API int LB_UserClient_updateUser(const char*username,const char*password,const int space);
SS_API int LB_UserClient_deleteUser(const char*username);

#endif
#endif //_SS_USER_SERVICE_H_

