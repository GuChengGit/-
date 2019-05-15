#ifndef _LB_WEBSERVICECLIENT_H
#define _LB_WEBSERVICECLIENT_H
#include "lonbon_webserviceH.h"
#include <ss_base/ss_base.h>

typedef int (*_lb_fn_webservice)(struct _LB_WebServiceClient*);

typedef int (*_lb_fn_LB_wsPing)(struct _LB_WebServiceClient* ,int*);
typedef int (*_lb_fn_LB_action)(struct _LB_WebServiceClient* ,struct LB_PairArray *cmd,struct lb__Response ** resp);
typedef int (*_lb_fn_LB_getSystemInfo)(struct _LB_WebServiceClient* ,struct lb__SystemInfo **);
typedef int (*_lb_fn_LB_getCallLogInfo)(struct _LB_WebServiceClient*,struct lb__CallLogQuery* ,struct lb__CallLogInfoResponse ** );
typedef int (*_lb_fn_PD_getDepartmentInfo)(struct _LB_WebServiceClient* ,struct lb__DepartmentInfoResponse **);
typedef int (*_lb_fn_PD_getTypeInfo)(struct _LB_WebServiceClient* ,struct lb__TypeInfoResponse **);
typedef int (*_lb_fn_PD_getDoctorInfo)(struct _LB_WebServiceClient* ,struct lb__DoctorInfoResponse **);
typedef int (*_lb_fn_PD_getNurseInfo)(struct _LB_WebServiceClient* ,struct lb__NurseInfoResponse **);
typedef int (*_lb_fn_PD_getDutyInfo)(struct _LB_WebServiceClient* ,struct lb__DutyInfoResponse **);
typedef int (*_lb_fn_PD_getPatientInfo)(struct _LB_WebServiceClient* ,char *last_query_time,char *department_list,int department_size,struct lb__PatientInfoResponse **);
typedef int (*_lb_fn_NN_getInpatientInfo)(struct _LB_WebServiceClient* ,char *last_query_time,struct lb__InpatientInfoResponse **);
typedef int (*_lb_fn_NN_getZoneInpatientInfo)(struct _LB_WebServiceClient* ,char *last_query_time,int zone_number,struct lb__InpatientInfoResponse **);
typedef int (*_lb_fn_NN_getRoomInpatientInfo)(struct _LB_WebServiceClient* ,char *last_query_time,int zone_number,char *room_number_list,int room_number_size,struct lb__InpatientInfoResponse **);
typedef int (*_lb_fn_NN_getBedInpatientInfo)(struct _LB_WebServiceClient* ,char *last_query_time,int zone_number,char *bed_number_list,int bed_number_size,struct lb__InpatientInfoResponse **);
typedef int (*_lb_fn_NN_getZoneAllInpatientInfo)(struct _LB_WebServiceClient*,int zone_number,struct lb__InpatientInfoResponse **);
typedef int (*_lb_fn_NN_getAllRoomInpatientInfo)(struct _LB_WebServiceClient* ,int zone_number,char *room_number_list,int room_number_size,struct lb__InpatientInfoResponse **);
typedef int (*_lb_fn_NN_getAllBedInpatientInfo)(struct _LB_WebServiceClient* ,int zone_number,char *bed_number_list,int bed_number_size,struct lb__InpatientInfoResponse **);
typedef int (*_lb_fn_NN_getZoneAllInpatientId)(struct _LB_WebServiceClient*,int zone_number,struct lb__InpatientIdResponse **);
typedef int (*_lb_fn_NN_getAllRoomInpatientId)(struct _LB_WebServiceClient* ,int zone_number,char *room_number_list,int room_number_size,struct lb__InpatientIdResponse **);
typedef int (*_lb_fn_NN_getAllBedInpatientId)(struct _LB_WebServiceClient* ,int zone_number,char *bed_number_list,int bed_number_size,struct lb__InpatientIdResponse **);

typedef int (*_lb_fn_LBINSP_getItemInfo)(struct _LB_WebServiceClient*,struct lb__ItemInfoResponse **);
typedef int (*_lb_fn_LBINSP_getInspPatientInfo)(struct _LB_WebServiceClient *client,char *last_query_time,char *item_list,int item_size,struct lb__InspPatientInfoResponse **info);
typedef int (*_lb_fn_PD_getInspRoomInfo)(struct _LB_WebServiceClient* ,struct lb__InspRoomInfoResponse **);
typedef int (*_lb_fn_LB_getInspDeviceInfo)(struct _LB_WebServiceClient* ,struct lb__InspDeviceInfoResponse **);
typedef int (*_lb_fn_LB_Dashboard_getDataInfo)(struct _LB_WebServiceClient* ,struct lb__DashboardDataResponse **);
typedef int (*_lb_fn_LB_Dashboard_getMessageInfo)(struct _LB_WebServiceClient* ,struct lb__DashboardMessageResponse **);

typedef int (*_lb_fn_NN_getInpatientKeyInfo)(struct _LB_WebServiceClient* ,struct lb__InpatientKeyInfoResponse **);

typedef void* (*_lb_fn_thread_proc)(void*);

typedef struct _LB_WebServiceClient
{
	struct soap lb_soap;
	char soap_endpoint[128];
	char soap_action[32];
	ss_mutex_t	lock;
	BOOL	isConnected;
	_lb_fn_webservice LB_connect;
	_lb_fn_webservice LB_disconnect;
	_lb_fn_LB_wsPing LB_wsPing;
	_lb_fn_LB_action LB_action;
	_lb_fn_LB_getSystemInfo LB_getSystemInfo;
	_lb_fn_LB_getCallLogInfo LB_getCallLogInfo;
	_lb_fn_PD_getDepartmentInfo PD_getDepartmentInfo;
	_lb_fn_PD_getTypeInfo PD_getTypeInfo;
	_lb_fn_PD_getDoctorInfo PD_getDoctorInfo;
	_lb_fn_PD_getNurseInfo PD_getNurseInfo;
	_lb_fn_PD_getDutyInfo PD_getDutyInfo;
	_lb_fn_PD_getPatientInfo PD_getPatientInfo;
	_lb_fn_NN_getInpatientInfo NN_getInpatientInfo;
	_lb_fn_NN_getZoneInpatientInfo NN_getZoneInpatientInfo;
	_lb_fn_NN_getRoomInpatientInfo NN_getRoomInpatientInfo;
	_lb_fn_NN_getBedInpatientInfo NN_getBedInpatientInfo;
	_lb_fn_NN_getZoneAllInpatientInfo NN_getZoneAllInpatientInfo;
	_lb_fn_NN_getAllRoomInpatientInfo NN_getAllRoomInpatientInfo;
	_lb_fn_NN_getAllBedInpatientInfo NN_getAllBedInpatientInfo;
	_lb_fn_NN_getZoneAllInpatientId NN_getZoneAllInpatientId;
	_lb_fn_NN_getAllRoomInpatientId NN_getAllRoomInpatientId;
	_lb_fn_NN_getAllBedInpatientId NN_getAllBedInpatientId;

	_lb_fn_LBINSP_getItemInfo LB_getItemInfo;
	_lb_fn_LBINSP_getInspPatientInfo LB_getInspPatientInfo;
	_lb_fn_PD_getInspRoomInfo PD_getInspRoomInfo;
	_lb_fn_LB_getInspDeviceInfo LB_getInspDeviceInfo;
	_lb_fn_LB_Dashboard_getDataInfo LB_Dashboard_getDataInfo;
	_lb_fn_LB_Dashboard_getMessageInfo LB_Dashboard_getMessageInfo;

	_lb_fn_NN_getInpatientKeyInfo NN_getInpatientKeyInfo;
}LB_WebServiceClient;

SS_API LB_WebServiceClient * LB_WebServiceClient_start(const char *ip,const int port);
SS_API void LB_WebServiceClient_stop(LB_WebServiceClient *client);

#endif //_LB_WEBSERVICECLIENT_H
