#ifndef _LBINSP_ROOM_H_
#define _LBINSP_ROOM_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "LB_TriageDB.h"
#include "LB_HISDB.h"

extern  int _load_insp_room(struct _LB_TriageQueue* queue,BOOL isForce);
extern int _load_insp_device(struct _LB_TriageQueue* queue,BOOL isForce);
extern int _import_lbinsp_room(struct _LB_TriageDB *triageDB, 
							   const char* code, 
							   const char* name,  
							   BOOL isForce);
extern int _import_lbinsp_device(struct _LB_TriageDB *triageDB, 
							   const char* code, 
							   const char* name,  
							   BOOL isForce);

#endif