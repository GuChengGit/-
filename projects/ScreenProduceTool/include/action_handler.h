
#ifndef __ACTION_HANDLER_H__
#define __ACTION_HANDLER_H__

#include <pjlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

	enum net_type{
		NETPK_DEFAULT_TYPE = 1,
	} ;

typedef struct 
{
	enum net_type type ;
	int len ;

	pj_sockaddr_in from ;
	int from_len ;

	// timestamp
}NETPK_HEAD, * PNETPK_HEAD ;

int action_handler_init() ;
int action_handler_release() ;
int action_handler_start(pj_pool_factory *pf) ;
int action_handler_stop() ;

int action_handler_add(const void * data, int len, pj_sockaddr_in *from, int fromlen) ;

#define LONBON_MSG_ECRYPT           1
#ifdef __cplusplus
}
#endif


#endif  /* __ACTION_HANDLER_H__ */




