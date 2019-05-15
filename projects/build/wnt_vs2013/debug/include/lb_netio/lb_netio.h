
#ifndef __LB_NETIO__H__
#define __LB_NETIO__H__

#define USE_NETIO_LIB_ALONE		1


#ifdef USE_NETIO_LIB_ALONE

typedef void pj_pool_factory ;
typedef long		pj_ssize_t ;
typedef unsigned short	pj_uint16_t;
typedef unsigned int	pj_uint32_t;

typedef struct pj_in_addr
{
	pj_uint32_t	ss_addr;		/**< The 32bit IP address.	    */
} pj_in_addr;

struct pj_str_t
{
	char       *ptr;
	pj_ssize_t  slen;
};

#define PJ_SOCKADDR_HAS_LEN	    0

struct pj_sockaddr_in
{
#if defined(PJ_SOCKADDR_HAS_LEN) && PJ_SOCKADDR_HAS_LEN!=0
	pj_uint8_t  sin_zero_len;	/**< Just ignore this.		    */
	pj_uint8_t  sin_family;	/**< Address family.		    */
#else
	pj_uint16_t	sin_family;	/**< Address family.		    */
#endif
	pj_uint16_t	sin_port;	/**< Transport layer port number.   */
	pj_in_addr	sin_addr;	/**< IP address.		    */
	char	sin_zero[8];	/**< Padding.			    */
};

#else
#include <pjlib-util.h>
#include <pjlib.h>
#endif


#include "lb_types.h"


#ifdef __cplusplus
extern "C"
{
#endif

//#define LB_EXPORT //__declspec(dllexport)

#define DF_NETIO_PORT		5020

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

/**
* Register one handler for custom data.
*.
* @param fptr	Callback to be called.
*
* @return    	Zero on success.
*/
int lb_netio_register_data_handler(lb_data_handler_ex *fptr) ;

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


#ifdef __cplusplus
}
#endif


#endif  /* __LB_NETIO__H__ */
