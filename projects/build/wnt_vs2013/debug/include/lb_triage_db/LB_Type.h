#ifndef _LB_TYPE_H_
#define _LB_TYPE_H_

typedef struct _LB_Type{
	unsigned int id;
	char code[LB_MAX_LENGTH_CODE+1];
	char name[LB_MAX_LENGTH_NAME+1];
	char abbr[LB_MAX_LENGTH_ABBR+1];
	unsigned int  department_id;
}LB_Type;


#endif //_LB_TYPE_H_
