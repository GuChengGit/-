#ifndef _LB_FUNC_INTERFACE_H
#define _LB_FUNC_INTERFACE_H
#include <ss_base/ss_base.h>

/*
 *  Í¼Æ¬ËùÔÚÄ¿Â¼
 */
#ifdef ANDROID
#define IMAGE_FILE_DIR	    "/mnt/sdcard/Lonbon/img/doctors/"
#define TITLE_FILE_DIR		"/mnt/sdcard/Lonbon/img/title"
#elif defined _MSC_VER
#define IMAGE_FILE_DIR		"\\NandFlash\\lonbon\\images\\doctors\\"
#define TITLE_FILE_DIR		"\\NandFlash\\lonbon\\images\\title\\"
#endif

typedef enum service_ret_t
{
	SERVICE_TYPE_INFO_OK,
	SERVICE_TYPE_INFO_FAIL,
	SERVICE_TYPE_CLINIC_OK,
	SERVICE_TYPE_CLINIC_FAIL,
}service_ret;

typedef void (*pFunc)(int,char *);
SS_API BOOL StartInterService();
SS_API BOOL StopInterService();
SS_API BOOL GetClinic(char* hisIp, int count, char** codes,pFunc pf);
SS_API BOOL GetDashboard(LB_DASHBOARD_DATA_t *pData,char* hisIp,pFunc pf);

#endif