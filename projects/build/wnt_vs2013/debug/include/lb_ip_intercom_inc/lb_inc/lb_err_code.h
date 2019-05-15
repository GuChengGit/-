#ifndef __LB_ERR_CODE_LIB_H__
#define __LB_ERR_CODE_LIB_H__


#ifdef __cplusplus
extern "C"
{
#endif


#define LB_ERR_NET_CODE_BIND_PORT_FAILED        0x00000001


void lb_err_code_set(unsigned int err_code) ;

unsigned int lb_err_code_get() ;

void lb_err_code_reset() ;



#ifdef __cplusplus
}
#endif

#endif // __LB_ERR_CODE_LIB_H__
