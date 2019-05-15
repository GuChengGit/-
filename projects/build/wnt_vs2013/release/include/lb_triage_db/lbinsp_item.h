#ifndef _LBINSP_ITEM_H_
#define _LBINSP_ITEM_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
//#include "LB_TriageDB.h"

#define LBINSP_ITEM_TABLE_NAME lbinsp_item

#define LBINSP_MAX_LENGTH_CODE	20
#define LBINSP_MAX_LENGTH_NAME	64

#define LB_NUMBER_OF_COLUMNS_ITEM			3


typedef struct _LBINSP_item 
{
	unsigned int id;
	char code[LBINSP_MAX_LENGTH_CODE];
	char name[LBINSP_MAX_LENGTH_NAME];
}LBINSP_item;

//struct lbinsp_item
//{
//	char *code;
//	char *name;
//};
//
//struct lbinsp_itemArray
//{
//	int __size;
//	struct lbinsp_item *__ptr;
//};
//
//struct lb__ItemInfoResponse
//{
//	int code;
//	char *msg;
//	struct lbinsp_itemArray *data;
//};



extern int get_insp_item_id(struct _LB_TriageDB *triageDB,const char* item_code);
extern int _import_lbinsp_item(struct _LB_TriageDB *triageDB, 
							   const char* code, 
							   const char* name,  
							   BOOL isForce);
extern int _load_insp_item(struct _LB_TriageQueue* queue,BOOL isForce);
extern int _update_actived_items(struct _LB_TriageQueue* queue);
#endif