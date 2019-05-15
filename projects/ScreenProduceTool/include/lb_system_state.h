#ifndef _LB_SYSTEM_STATE_H
#define _LB_SYSTEM_STATE_H
#ifdef _S3C_SERVER

typedef struct _LB_SYSTEM_STATE
{
	long memory;       //���ڴ棬��λ��M
	long free;         //ʣ������ڴ棬��λ��M
	long space;        //�ܴ��̴�С����λ��M
	long remain;        //ʣ����ô��̣���λ��M
	float used;         //CUPʹ����
}LB_SYSTEM_STATE;

SS_API BOOL lb_get_system_state(LB_SYSTEM_STATE * state);

#endif

#endif