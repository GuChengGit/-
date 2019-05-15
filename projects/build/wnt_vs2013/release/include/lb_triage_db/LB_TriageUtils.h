#ifndef _LB_TRIAGEUTILS_H_
#define _LB_TRIAGEUTILS_H_

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>
#include "LB_TriageDB.h"

//utils
SS_API int lb_triage_result_to_departments(ss_db_result_t *result,LB_Department *lb_departments,int count);
SS_API int lb_triage_result_to_types(ss_db_result_t *result,LB_Type *lb_types,int count);
SS_API int lb_triage_result_to_doctors(ss_db_result_t *result,LB_Doctor *lb_doctors,int count);
SS_API int lb_triage_result_to_rooms(ss_db_result_t *result,LB_Room *lb_rooms,int count);
SS_API int lb_triage_result_to_dutys(ss_db_result_t *result,LB_Duty *lb_dutys,int count);
SS_API int lb_triage_result_to_patients(ss_db_result_t *result,LB_Patient *lb_patients,int count);
SS_API int lb_triage_result_to_audios(ss_db_result_t* result, LB_Audio* datas, int count);
SS_API int lb_triage_result_to_dashboard_data(ss_db_result_t* result, LB_DashboardData *lb_dashboard_data, int count);
SS_API int lb_triage_result_to_dashboard_message(ss_db_result_t* result, LB_DashboardMessage *data, int count);

#endif //_LB_TRIAGEUTILS_H_
