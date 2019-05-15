#ifndef _SS_NETUTILS_H_
#define _SS_NETUTILS_H_

#include "ss_base/ss_def.h"
typedef enum _lb_eth_status
{
	LB_ETH_STATUS_FAILED=-1,
	LB_ETH_STATUS_OK =0,  //Not set, using database default
	LB_ETH_STATUS_CONFLICT,
}lb_eth_status_t;
SS_API int checkNetworkStatus(unsigned char ip[],unsigned char mac[],lb_eth_status_t *status);
#endif //_SS_NETUTILS_H_
