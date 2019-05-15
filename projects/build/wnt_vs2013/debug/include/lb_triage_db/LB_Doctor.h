#ifndef _LB_DOCTOR_H_
#define _LB_DOCTOR_H_

typedef struct _LB_Doctor{
	unsigned int id;
	char code[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	char login_code[LB_MAX_LENGTH_CODE+1];
	unsigned int  department_id;
}LB_Doctor;

#endif //_LB_DOCTOR_H_
