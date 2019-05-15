#ifndef _LB_DUTY_H_
#define _LB_DUTY_H_


typedef struct _LB_Duty{
	unsigned int id;
	unsigned int  caller_address;   /*½ÐºÅÆ÷±àºÅ */
	unsigned int  doctor_id;
	int dayofweek;
	int timeofday;
	unsigned int  type_id;
	unsigned int  room_id;
}LB_Duty;

#endif //_LB_DUTY_H_
