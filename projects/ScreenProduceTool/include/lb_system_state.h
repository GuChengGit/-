#ifndef _LB_SYSTEM_STATE_H
#define _LB_SYSTEM_STATE_H
#ifdef _S3C_SERVER

typedef struct _LB_SYSTEM_STATE
{
	long memory;       //总内存，单位：M
	long free;         //剩余可用内存，单位：M
	long space;        //总磁盘大小，单位：M
	long remain;        //剩余可用磁盘，单位：M
	float used;         //CUP使用率
}LB_SYSTEM_STATE;

SS_API BOOL lb_get_system_state(LB_SYSTEM_STATE * state);

#endif

#endif