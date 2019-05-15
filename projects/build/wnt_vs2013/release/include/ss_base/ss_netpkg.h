#ifndef _SS_NETPKG_H_
#define _SS_NETPKG_H_

#define SS_NETPKG_SIZE_TYPE		sizeof(unsigned char)
#define SS_NETPKG_SIZE_INDEX	sizeof(unsigned int)
#define SS_NETPKG_SIZE_SIZE		sizeof(unsigned short int)

#define SS_NETPKG_SIZE_NODATA		(SS_NETPKG_SIZE_TYPE+SS_NETPKG_SIZE_INDEX+SS_NETPKG_SIZE_SIZE)
#define SS_NETPKG_SIZE_FULL		(SS_NETPKG_SIZE_NODATA+SS_NETPKG_SIZE_DATA)

#define SS_NETPKG_POINT_TYPE		0
#define SS_NETPKG_POINT_INDEX		SS_NETPKG_SIZE_TYPE
#define SS_NETPKG_POINT_SIZE		(SS_NETPKG_SIZE_TYPE+SS_NETPKG_SIZE_INDEX)
#define SS_NETPKG_POINT_DATA		(SS_NETPKG_SIZE_TYPE+SS_NETPKG_SIZE_INDEX+SS_NETPKG_SIZE_SIZE)

#define SS_NETPKG_SIZE_DATA		5120
//ERROR

typedef enum {
	SS_NETPKG_OK=0,
	SS_NETPKG_ERROR_SYS,
	SS_NETPKG_ERROR_TIMEOUT,
	SS_NETPKG_ERROR_NOT_SENT,
	SS_NETPKG_ERROR_NOT_RECV,
} SS_NetPkgError_t;

typedef enum {
	SS_NETPKG_TYPE_INVALID =0,
	SS_NETPKG_TYPE_ACK,
	SS_NETPKG_TYPE_MULTI_START,
	SS_NETPKG_TYPE_MULTI_DATA,
	SS_NETPKG_TYPE_MULTI_END,
	SS_NETPKG_TYPE_CMD_PUT,
	SS_NETPKG_TYPE_CMD_GET,
	SS_NETPKG_TYPE_ERROR,
	SS_NETPKG_TYPE_PIECE_DATA,
} SS_NetPkgType_t;


typedef struct _SS_NetPkg_t
{
	/* Header */
	unsigned char type;
	unsigned int index;
	unsigned short int size;
	/* Data */
	char data[SS_NETPKG_SIZE_DATA];
}SS_NetPkg_t;


typedef struct _SS_NetPkgServer_t {
	SS_Socket* listenerSocket;
	ss_mutex_t	lock;
	ss_thread_t	dispatcherThread;
	struct sockaddr_in* bind_address;
	BOOL isRunning;
	FILE *rfp;
	FILE *wfp;
}SS_NetPkgServer_t;

SS_API int  SS_NetPkgServer_start(int port);
SS_API int  SS_NetPkgServer_stop(void);
SS_API SS_NetPkgServer_t *  SS_NetPkgServer_getInstance();
SS_API int SS_NetPkg_sendCmdPut(SS_Socket *sockInst,const char *localName, const char *remoterName);
SS_API int SS_NetPkgServer_getTransferPercent();
SS_API BOOL SS_NetPkgServer_isBusy();
#endif //_SS_NETPKG_H_
