#ifndef _LB_TIMER_H
#define _LB_TIMER_H
#include <ss_base/ss_base.h>

#define LB_TIMER_INTERVAL_MILLISECOND                  100         // ¶¨Ê±Æ÷select¼ä¸ô£¨ºÁÃë£©

typedef void (*_fn_lb_timer_t)(struct _lb_timer*);
typedef void (*_fn_lb_timer_func_t)(void* pParam, int nParam);

typedef struct _lb_timer{
	int flag;
	ss_thread_t pthread;
	long m_second;
	long m_microsecond;
	void* pParam;
	int  nParam;

	_fn_lb_timer_t start;
	_fn_lb_timer_t stop;
	_fn_lb_timer_func_t func;
}lb_timer;

#endif

lb_timer* lb_timer_init(long m_millisecond,_fn_lb_timer_func_t bfunc, void* pParam, int nParam);

void lb_timer_deinit(lb_timer* timer);