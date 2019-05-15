#ifndef _SS_TCPFILE_H_
#define _SS_TCPFILE_H_
#include "ss_base/ss_def.h"
#include "ss_base/ss_socket.h"
#include "ss_base/ss_thread.h"

#define  SS_TCPFILE_MAX_BUFFSIZE					2048

typedef int (*_ss_fn_filesock_get_)(struct _SS_FileSocket* );

typedef struct _SS_FileSocket{
	SS_Socket	*sock;
	ss_mutex_t	lock;
	BOOL isRunning;
	BOOL isServer;
	FILE *fp;
	ss_thread_t fileHandlerThread; /*Server side only */
	int fileSize;
	int transfered;
	char fileName[260];
	char buff[SS_TCPFILE_MAX_BUFFSIZE];
	_ss_fn_filesock_get_ getReadState;
	_ss_fn_filesock_get_ getWriteState;
	_ss_fn_filesock_get_ getTransferPercent;
}SS_FileSocket;

typedef struct _SS_TcpFileServer{
	SS_Socket	*listenerSocket;
	ss_mutex_t	lock;
	ss_thread_t	dispatcherThread;
	BOOL isRunning;
	int currentConnected;
	int maxConnection;
	SS_FileSocket **fileSockets;
}SS_TcpFileServer;

typedef struct _SS_TcpFileClient{
	SS_FileSocket *fileSocket;
}SS_TcpFileClient;


SS_API SS_TcpFileServer* SS_TcpFileServer_start(int port,int maxConnection);
SS_API void SS_TcpFileServer_stop(SS_TcpFileServer* pServer);

SS_API SS_TcpFileClient* SS_TcpFileClient_new(const char* ip,const int port);
SS_API void SS_TcpFileClient_destroy(SS_TcpFileClient *client);

SS_API int SS_TcpFileClient_putFile(SS_TcpFileClient *pClient,const char* localname,const char *remotename);
SS_API int SS_TcpFileClient_getFile(SS_TcpFileClient *pClient,const char* localname,const char *remotename);
SS_API int SS_TcpFileClient_getTransferPercent(SS_TcpFileClient *pClient);
#endif //_SS_TCPFILE_H_
