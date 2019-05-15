#ifndef _LB_TYPE_H_
#define _LB_TYPE_H_


typedef struct _LB_Room{
	unsigned int id;
	int number;
	char name[LB_MAX_LENGTH_NAME+1];
	char message[LB_MAX_LENGTH_MESSAGE+1];
	unsigned int  department_id;
}LB_Room;


#endif //_LB_TYPE_H_
