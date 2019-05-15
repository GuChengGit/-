
#ifndef __LB_ACTION_PARSER_EX_H__
#define __LB_ACTION_PARSER_EX_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include <pjlib-util.h>
#include <pjlib.h>
#include "lb_types.h"
#define PD_NEW0(type,n)	(type*) memset(malloc(sizeof(type)*(n)),0,sizeof(type)*(n))
//typedef struct element_array_pair element_array_pair;

//typedef int (lb_action_handler)(element_array_pair *pair) ;

int lb_action_parse_msg(const char * buf, int size, pj_sockaddr_in *from, int fromlen) ;

int lb_action_parse_init() ;

pj_str_t * lb_action_val_find(const pj_str_t * key, element_array_pair *pair) ;

PJ_DEF(pj_status_t) lb_register_action_parser( const char *name,
												 lb_action_handler_ex *fptr) ;

PJ_DEF(pj_status_t) lb_register_data_handler(lb_data_handler_ex *fptr) ;

int lb_action_pair_get_str_value(element_array_pair * pair,char *key,char *value) ;
int lb_action_pair_get_int_value(element_array_pair * pair,char *key,int *value) ;
char *lb_action_pair_get_strValue_withMallocBuf(element_array_pair * pair,char *key);


#ifdef __cplusplus
}
#endif

#endif	/* __LB_ACTION_PARSER_EX_H__ */

