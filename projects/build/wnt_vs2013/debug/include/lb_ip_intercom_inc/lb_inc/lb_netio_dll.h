#ifndef __LB_NETIO_DLL_EXPORT_H__
#define __LB_NETIO_DLL_EXPORT_H__


#ifdef __cplusplus
extern "C"
{
#endif

#include "lb_headdef.h"
#include "lb_netio.h"

typedef void *  LB_HANDLE ;

LB_EXPORT int dll_lb_netio_init(pj_pool_factory *pf) ;
LB_EXPORT int dll_lb_netio_init_ex(pj_pool_factory *pf, unsigned short port) ;
LB_EXPORT int dll_lb_netio_deinit() ;
LB_EXPORT int dll_lb_netio_register_action_handler(const char *name, lb_action_handler_ex *fptr) ;
LB_EXPORT int dll_lb_netio_register_data_handler(lb_data_handler_ex *fptr) ;

LB_EXPORT pj_str_t * dll_lb_netio_action_val_find(const pj_str_t * key, element_array_pair_ex *pair) ;
LB_EXPORT int dll_lb_netio_action_pair_get_str_value(element_array_pair_ex * pair, 
													 const char *key, 
													 char *out_buf,  
													 int out_buf_len) ;
LB_EXPORT int dll_lb_netio_action_pair_get_int_value(element_array_pair_ex * pair, const char *key, int *value) ;
LB_EXPORT int dll_lb_netio_msg_sendto(const void * msg, pj_ssize_t msg_size, const char * ip);
LB_EXPORT int dll_lb_netio_msg_sendto2(const void * msg, pj_ssize_t msg_size, const pj_sockaddr_in *addr);
LB_EXPORT int dll_lb_netio_msg_sendto3(const void * msg, pj_ssize_t msg_size, const char * ip, unsigned short port);

LB_EXPORT LB_HANDLE dll_lb_create_thread(int stack_size, 
										 int (thread_proc)(void*), 
										 void *arg, 
										 unsigned flags) ;
LB_EXPORT void dll_lb_close_thread(LB_HANDLE thread_handle) ;

LB_EXPORT unsigned int dll_lb_err_code_get()  ;
LB_EXPORT unsigned int dll_lb_intercom_get_pool_factory() ;

#ifdef __cplusplus
}
#endif

#endif // __LB_NETIO_DLL_EXPORT_H__
