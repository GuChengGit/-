#ifndef _LBQY_DISPENSARY_H_
#define _LBQY_DISPENSARY_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "LB_TriageDB.h"
#include "LB_HISDB.h"

extern int _load_lbqy_dispensary(struct _LB_TriageQueue* queue);
extern int _load_lbqy_doctor(struct  _LB_TriageQueue* queue);
extern int load_lbqy_patient(struct _LB_TriageQueue *queue);

#endif