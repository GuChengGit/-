#ifndef _LBINSP_PATIENT_H_
#define _LBINSP_PATIENT_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "LB_TriageDB.h"
#include "LB_HISDB.h"

#define LB_TRIAGE_LAST_QUERY_INSP_PATIENT			"_LB_TRIAGE_LAST_QUERY_INSP_PATIENT_"

extern  int _import_lbinsp_patient(struct _LB_TriageDB *triageDB,
								 const char * charge_code,
								 const char* code,
								 const char* name,
								 const char* abbr,
								 const char* item_code,
								 const char* device_code ,
								 const char* last_modify,
								 const char* ticket_number,
								 const char* ticket_time,
								 const int queue_state
							  );
 extern  void _update_last_query_time_insp_patient(struct _LB_TriageQueue* queue,char *time_now);
 extern int _load_insp_patient(struct _LB_TriageQueue* queue);

#endif