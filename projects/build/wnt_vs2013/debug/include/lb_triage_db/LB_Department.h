#ifndef _LB_DEPARTMENT_H_
#define _LB_DEPARTMENT_H_

typedef struct _LB_Department{
	unsigned int id;
	char code[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	char ticket_prefix[LB_MAX_LENGTH_TICKET_PREFIX+1];
	int is_actived;
}LB_Department;

#endif //_LB_DEPARTMENT_H_
