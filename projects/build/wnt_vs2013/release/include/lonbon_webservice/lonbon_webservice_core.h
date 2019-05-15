#ifndef _LONBON_WEBSERVICE_CORE_H_
#define _LONBON_WEBSERVICE_CORE_H_
#include "lonbon_webserviceH.h"
#include <ss_base/ss_base.h>

extern SOAP_NMAC struct Namespace namespaces[];

#define SS_NEW0_SOAP(soap,type,n)	(type*) memset(soap_malloc(soap,sizeof(type)*(n)),0,sizeof(type)*(n))
#define SS_DB_DATA_SOAPCOPY(soap,d,s)  if((s)!=NULL && (s)->string_val!=NULL) (d)=soap_strdup(soap,(s)->string_val)

SS_API void LB_PairArray_destory(struct LB_PairArray*  pairArray);
SS_API int  LB_PairArray_addKeyValue(struct LB_PairArray** pairArray,char* key,char* value);

SS_API void LB_Response_destroy(struct lb__Response*  resp);
SS_API int  LB_Response_setResponce(struct lb__Response**  resp,struct LB_PairArray*  respArray);
SS_API int  LB_Response_addEvent(struct lb__Response**  resp,struct LB_PairArray*  aPairArray);
SS_API struct lb__Response* LB_Response_soapCopy(struct soap *lb_soap, struct lb__Response*  resp);
SS_API int LB_Response_toString(struct lb__Response*  resp,char** str);

SS_API void lb__SystemInfo_destroy(struct lb__SystemInfo *info);
SS_API void lb__CallLogQuery_destroy(struct lb__CallLogQuery *info);
SS_API void lb__CallLogInfoResponse_destroy(struct lb__CallLogInfoResponse *info);

SS_API void lb__DepartmentInfoResponse_destroy(struct lb__DepartmentInfoResponse *info);
SS_API void lb__TypeInfoResponse_destroy(struct lb__TypeInfoResponse *info);
SS_API void lb__DoctorInfoResponse_destroy(struct lb__DoctorInfoResponse *info);
SS_API void lb__DutyInfoResponse_destroy(struct lb__DutyInfoResponse *info);
SS_API void lb__PatientInfoResponse_destroy(struct lb__PatientInfoResponse *info);
SS_API void lb__InpatientInfoResponse_destroy(struct lb__InpatientInfoResponse *info);
SS_API void lb__InpatientlistInfoResponse_destroy(struct lb__InpatientlistInfoResponse *info);

SS_API void lb__ItemInfoResponse_destroy(struct lb__ItemInfoResponse *info);
SS_API void lb__InspPatientInfoResponse_destroy(struct lb__InspPatientInfoResponse *info);
SS_API void lb__InspRoomInfoResponse_destroy(struct lb__InspRoomInfoResponse *info);
SS_API void lb__InspDeviceInfoResponse_destroy(struct lb__InspDeviceInfoResponse *info);
SS_API void lb__DashboardDataResponse_destroy(struct lb__DashboardDataResponse *info);
SS_API void lb__DashboardMessageResponse_destroy(struct lb__DashboardMessageResponse *info);

SS_API void lb__InpatientKeyInfoResponse_destroy(struct lb__InpatientKeyInfoResponse *info);

#endif //_LONBON_WEBSERVICE_CORE_H_
