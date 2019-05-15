#ifndef _LB_PATIENT_H_
#define _LB_PATIENT_H_

typedef struct _LB_Patient{
	unsigned int id;
	char code[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	unsigned int  department_id;
	unsigned int  type_id;
	unsigned int  doctor_id;
	char register_time[DEFAULT_TIME_STRING_LENGTH];
	int state;
	char ticket_number[LB_MAX_LENGTH_TICKET+1];
	int ticket_order;
	char ticket_time[DEFAULT_TIME_STRING_LENGTH+1];
	char call_time[DEFAULT_TIME_STRING_LENGTH+1];
	char treat_time[DEFAULT_TIME_STRING_LENGTH+1];
}LB_Patient;

#endif //_LB_PATIENT_H_
