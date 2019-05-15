#ifndef __LB_TYPES_H__
#define __LB_TYPES_H__

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct element_array_pair element_array_pair;
typedef struct _element_array_pair_ex_ex element_array_pair_ex;

typedef int (lb_action_handler_ex)(element_array_pair_ex *pair, pj_sockaddr_in *from, int fromlen);

typedef int (lb_data_handler_ex)(void * data, int data_size, pj_sockaddr_in *from, int fromlen) ;


#ifdef __cplusplus
}
#endif

#endif /* __LB_TYPES_H__ */


