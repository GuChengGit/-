#ifndef _SS_HTTPC_H_
#define _SS_HTTPC_H_
#include "ss_base/ss_socket.h"

typedef enum{
	SS_HTTP_GET =0,
	SS_HTTP_POST
} SS_HTTPMethod;

typedef struct _SS_HTTPClient {
	SS_Socket *sock;
	SS_HTTPMethod method;
	int respose_state;
	int respose_content_length;
	char *respose_header;
	char *respose_content;
} SS_HTTPClient;

SS_API SS_HTTPClient * SS_HttpClient_new(const char* ip,const int port,const char *fileName,SS_HTTPMethod method, char *param);
SS_API void SS_HttpClient_destory(SS_HTTPClient *httpc);
SS_API char* SS_HttpClient_toString(SS_HTTPClient *httpc);
SS_API void SS_HttpClient_dump(SS_HTTPClient *httpc);

#endif
