#ifndef _LB_DOTMATRIXSCREEN_H
#define _LB_DOTMATRIXSCREEN_H
#include "lb_headdef.h"

LB_BEGIN_DECL

typedef struct _lb_dotMatrixScreenList
{
	char ip[32];
	int  port;

}lb_dotMatrixScreenList;

LB_EXPORT int lb_dotMatrixScreen_set(lb_dotMatrixScreenList *dotMatrixScreenList, int listCnt);


LB_END_DECL
#endif