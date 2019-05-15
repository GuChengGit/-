/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_socket.h
* @brief LonbonVoip architecture socket definitions.
*
* @author	Qiusheng Li
* @date	2008-10-10
*
*/
#ifndef _SS_SOCKET_H_
#define _SS_SOCKET_H_


#include "ss_base/ss_def.h"
#include "ss_base/ss_list.h"
#include "ss_base/ss_time.h"
#include "ss_base/ss_pwd.h"

#define DEFAULT_SOCKET_READ_WRITE_TIMEOUT			200 

#define NET_TRANSFER_BUFFER_LENGTH					6144
#define SS_MAX_SOCKET_CONNECTION					256


typedef enum {
	SS_SOCKET_TYPE_TCP=0,
	SS_SOCKET_TYPE_UDP
} SS_SocketType;

// socket states
typedef enum {
	SS_SOCKET_STATE_ERROR=-1,
	SS_SOCKET_STATE_NOTINUSE=0,
	SS_SOCKET_STATE_LISTENING,
	SS_SOCKET_STATE_CONNECTING,
	SS_SOCKET_STATE_SENDING,
	SS_SOCKET_STATE_RECEIVING,
	SS_SOCKET_STATE_MULTICAST_LISTENING,
	SS_SOCKET_STATE_MULTICAST_SENDING,
	SS_SOCKET_STATE_CLOSING
} SS_SocketState;

typedef int (*_ss_socket_fn_)(struct _SS_Socket* );

typedef struct _SS_Socket {
	int id;
	char* ip;
	int port;
	SS_SocketType type;
	SS_SocketState state;
	ss_timer_t* timer;
	struct sockaddr_in* saddr;
	struct ip_mreq *command;
	char *readBuff;
	char *writeBuff;
	int rwTimeout;
	_ss_socket_fn_ logLastError;
}SS_Socket;

SS_API void initializeNetworkDriver();
SS_API void cleanupNetworkDriver();

SS_API SS_Socket* SS_Socket_newTcpServerListenerSocket(const int port,int maxConnections);
SS_API SS_Socket* SS_Socket_newTcpClientSocket(const char* serverIp,const int port);
SS_API SS_Socket * SS_Socket_newUdpServerSocket(const int port);
SS_API SS_Socket * SS_Socket_newUdpClientSocket(const char* serverHost,const int port);
SS_API SS_Socket* SS_Socket_newMulticastServerSocket(const char*ip,const int port);
SS_API SS_Socket* SS_Socket_newMulticastClientSocket(const char*ip,const int port);
SS_API SS_Socket* SS_Socket_newAcceptSocket(SS_Socket *listenningSockInst);
SS_API void SS_Socket_destroy(SS_Socket * sockInst);
#ifndef _NNOS
SS_API struct addrinfo * SS_Socket_getAddressInfo(const char* host);
SS_API char* SS_Socket_getIP(const char* host);
SS_API char* SS_Socket_getLocalIP();
#endif
SS_API int SS_Socket_stopMulticastService(SS_Socket *sockInst);
SS_API int SS_Socket_startMulticastService(SS_Socket *sockInst);

SS_API int SS_Socket_close(SS_Socket *sockInst);
SS_API int SS_Socket_send(SS_Socket *sockInst, const char *str);
SS_API int SS_Socket_send_plain(SS_Socket *sockInst, const char *msg);
SS_API int SS_Socket_sendFormatString(SS_Socket * sockInst,char* fmt,...);
SS_API int SS_Socket_receive(SS_Socket *sockInst,char **response);
SS_API int SS_Socket_receive_plain(SS_Socket *sockInst,char **response);
SS_API int SS_Socket_setBlockMode(SS_Socket *sockInst,BOOL isBlock);
SS_API void SS_Socket_dump(SS_Socket * sockInst);

SS_API int SS_Socket_setTimer(SS_Socket * sockInst,const long timer);
SS_API BOOL SS_Socket_isTimeOut(SS_Socket * sockInst);
SS_API int SS_Socket_timerReset(SS_Socket * sockInst);
SS_API BOOL SS_Socket_initSinAddress(const char* ip,const int port,struct sockaddr_in* sinAddr);
SS_API int SS_Socket_sendUDP(const struct sockaddr_in *fromAddr,const struct sockaddr_in *toAddr,const char* msg);
SS_API int SS_Socket_sendUDP_plain(const struct sockaddr_in *fromAddr,const struct sockaddr_in *toAddr,const char* msg);
SS_API int SS_Socket_sendEncryptUDP(const struct sockaddr_in *fromAddr,const struct sockaddr_in *toAddr,const char* msg,SS_EncryptType_t encType);
SS_API int SS_Socket_receiveEncryptUDP(SS_Socket *sockInst,char **response,SS_EncryptType_t *encType);
SS_API int SS_Socket_sendUDPData_plain(const struct sockaddr_in *fromAddr,const struct sockaddr_in *toAddr,const int data_size,const char* data);
SS_API int SS_Socket_recvUDPData_plain(SS_Socket *sockInst,int* msg_size,char **msg);

SS_API BOOL SS_Socket_isReadable(SS_Socket *sockInst);
SS_API BOOL SS_Socket_isWritable(SS_Socket *sockInst);

SS_API int SS_Socket_getFileTransferPercent();
SS_API int SS_Socket_sendFile(SS_Socket * sockInst,const char* localname,const char *remotename);
#endif /* _SS_SOCKET_H_ */
