
#ifndef __LB_NETIO__H__
#define __LB_NETIO__H__

#include <pjlib-util.h>
#include <pjlib.h>
#include "lb_types.h"


#include "action_parser_ex.h"
#ifdef __cplusplus
extern "C"
{
#endif

//#define LB_EXPORT //__declspec(dllexport)

#define DF_NETIO_PORT		5020
#define AUDIOBOX_NETIO_PORT		9125

typedef void *  LB_HANDLE ;

/**
* Initialize netio lib
*
* @param pf	    Pool factory.
*
* @return    	    Zero on success.
*/
int lb_netio_init(pj_pool_factory *pf) ;

/**
* Initialize netio lib
*
* @param pf	    Pool factory.
* @param port   Local bind port.
*
* @return    	    Zero on success.
*/
int lb_netio_init_ex(pj_pool_factory *pf, unsigned short port) ;

/**
* Initialize netio lib
*
* @param pf	        Pool factory.
* @param port       port group array
* @param port_count port count
*
* @return    	    Zero on success.
*/
int lb_netio_init_port_group(pj_pool_factory *pf, unsigned short port[], int port_count) ;

/**
* Release res
*
* @return    	    Zero on success.
*/
int lb_netio_deinit() ;

/**
* Register one handler for one action name.
*
* @param name   The action name.
* @param fptr	Callback to be called.
*
* @return    	Zero on success.
*/
int lb_netio_register_action_handler(const char *name, lb_action_handler_ex *fptr) ;

int lb_netio_register_data_handler(lb_data_handler_ex *fptr);

LB_HANDLE lb_create_thread(int stack_size, int (thread_proc)(void*), void *arg, unsigned flags) ;

void lb_close_thread(LB_HANDLE thread_handle) ;

/**
* Find the val.
*
* @param key    The key name.
* @param pair   Pointer to [key:val] pair.
*
* @return    	The val string correspond to the key name, or NULL.
*/
pj_str_t * lb_netio_action_val_find(const pj_str_t * key, element_array_pair *pair) ;

int lb_netio_action_pair_get_str_value(element_array_pair * pair, 
									   const char *key, 
									   char *out_buf,  
									   int out_buf_len) ;

int lb_netio_action_pair_get_int_value(element_array_pair * pair, const char *key, int *value) ;
/**
* Send message.
*
* @param msg        Buffer containing msg to be sent.
* @param msg_size   On input, the length of the msg in the buffer.
* @param ip         The address to send.
*
* @return    	    Zero on success.
*/
int lb_netio_msg_sendto(const void * msg, int msg_size, const char * ip) ;

/**
* Send message.
*
* @param msg        Buffer containing msg to be sent.
* @param msg_size   On input, the length of the msg in the buffer.
* @param addr       The address to send.
*
* @return    	    Zero on success.
*/
int lb_netio_msg_sendto2(const void * msg, int msg_size, const pj_sockaddr_in *addr) ;

int lb_netio_msg_sendto3(const void * msg, int msg_size, const char * ip, unsigned short port) ;

pj_pool_factory * lb_netio_get_pool_factory() ;

#ifdef __cplusplus
}
#endif


#endif  /* __LB_NETIO__H__ */
