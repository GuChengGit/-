#ifndef _SS_NETFILE_H_
#define _SS_NETFILE_H_
#include "ss_base/ss_thread.h"
#include "ss_base/ss_socket.h"

//ERROR
#define SS_NETFILE_OK									 0
#define SS_NETFILE_ERROR_SYS							-1
#define SS_NETFILE_ERROR_TIMEOUT						-2
#define SS_NETFILE_ERROR_NOT_SENT						-3
#define SS_NETFILE_ERROR_NOT_RECV						-4
#define SS_NETFILE_ERROR_CANCEL							-5
#define SS_NETFILE_ERROR_FILE_WRITE_ERROR				-6
#define SS_NETFILE_ERROR_DATA_TOO_BIG					-7
#define SS_NETFILE_ERROR_FILE_NOT_FOUND_OR_ZERO_SIZE	-8
#define SS_NETFILE_ERROR_FILE_READ_ERROR				-9

#define SS_PACKAGE_SIZE_DATA							5120
typedef struct _SS_PackageStats_t {
	unsigned int sent;
	unsigned int resent;
	unsigned int recvd;
	unsigned int recvd_tmout;
	unsigned int recvd_badcrc;
	unsigned int recvd_nonsense; 
	unsigned long time_started;
}SS_PackageStats_t;


typedef struct _SS_NetServer_t {
	SS_Socket* listenerSocket;
	SS_Socket* connectSocket;
	ss_mutex_t	lock;
	ss_thread_t	dispatcherThread;
	//struct sockaddr_in* bind_address;
	BOOL isRunning;
}SS_NetServer_t;

SS_API int SS_Package_sendData (SS_Socket *sockInst,int msg_size, char *msg);
SS_API int SS_Package_recvData (SS_Socket *sockInst,int *msg_size, char **msg);
SS_API int SS_Package_sendMultipleData(SS_Socket *sockInst, int msg_size, char *msg);
SS_API int SS_Package_recvMultipleData(SS_Socket *sockInst, int *msg_size, char **msg);

SS_API SS_NetServer_t* SS_NetServer_getInstance(void);
SS_API SS_PackageStats_t* SS_Net_getPackageStats();
SS_API int SS_Net_getTransferPercent();

SS_API int SS_NetServer_start(int port);
SS_API int SS_NetServer_startTcp(int port);
SS_API int SS_NetServer_stop(void);
SS_API BOOL SS_NetServer_isBusy();

SS_API int SS_NetClient_doPutCmd(SS_Socket *sockInst,char* localName,char* remoteName);
SS_API int SS_NetClient_doGetCmd(SS_Socket *sockInst,char* localName,char* remoteName);
SS_API int SS_NetClient_doGetFileContent(SS_Socket *sockInst,char* remoteName,int *data_size, char **data);
//SS_API int SS_NetClient_doStopServer(SS_Socket *sockInst);

#endif //_SS_NETFILE_H_
