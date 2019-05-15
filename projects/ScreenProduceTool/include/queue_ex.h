
//typedef int ElementType ;

#ifdef __cplusplus
extern "C"
{
#endif

typedef void *  ElementType ;

#ifndef _Queue_h_
#define _Queue_h_

struct QueueRecord;
typedef struct QueueRecord *Queue;




struct DataPoolRecord ;
typedef struct DataPoolRecord * DataPool ;

DataPool DataPool_Init_Ex(int MaxElements, int BlockSize) ;
void DataPool_Dispose_Ex(DataPool pool) ;
ElementType DataPool_GetFromFree_Ex(DataPool pool) ;
int DataPool_AddToFree_Ex(ElementType X, DataPool pool) ;
ElementType DataPool_GetFromFull_Ex(DataPool pool) ;
int DataPool_AddToFull_Ex(ElementType X, DataPool pool) ;

#endif  /* _Queue_h_ */


#ifdef __cplusplus
}
#endif



