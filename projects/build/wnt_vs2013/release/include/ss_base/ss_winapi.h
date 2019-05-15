#ifndef _SS_WINAPI_H_
#define _SS_WINAPI_H_
#ifdef _MSC_VER
#include <windows.h>
#include  "ss_base/ss_def.h"

#define MAX_REG_KEY_LENGTH			256
#define MAX_REG_VALUE_LENGTH		256


#define SS_HEAP_MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define SS_HEAP_FREE(x) HeapFree(GetProcessHeap(), 0, (x))

#define SS_WIN_SERVICE_WMI   "winmgmt"		
#define SS_WIN_SERVICE_WMI   "winmgmt"		


#define MBYTE_TO_WCHAR(a,b) do{ \
		memset(b,0,sizeof(b)); \
		SS_Win_mByteToWChar(a,b); \
}while(0)

#define WCHAR_TO_MBYTE(a,b) do{ \
	memset(b,0,sizeof(b)); \
	SS_Win_wCharToMByte(a,b); \
}while(0)

#define MBYTE_TO_WCHAR2(a,b) do{ \
	memset(b,0,sizeof(b)); \
	SS_mByteToWChar(a,b); \
}while(0)

#define WCHAR_TO_MBYTE2(a,b) do{ \
	memset(b,0,sizeof(b)); \
	SS_wCharToMByte(a,b); \
}while(0)

typedef struct _LB_IP_ADAPTER_INFO {
	unsigned int index;
	unsigned int type;
	char *name;
	char *description;
	char *mac;
	BOOL isDhcp;
	char *ip;
	char *gateway;
	char *netmask;
	char *dns1;
	char *dns2;
} LB_IP_ADAPTER_INFO_t;

SS_API BOOL SS_Win_wCharToMByte(LPCWSTR lpcwszStr, LPSTR lpszStr);
SS_API BOOL SS_Win_mByteToWChar(LPCSTR lpcszStr, LPWSTR lpwszStr);

SS_API HKEY SS_Win_openReg(const char* regKey,unsigned long ulOptions);
SS_API void SS_Win_closeReg(HKEY hkey,BOOL isFlush);
SS_API int SS_Win_getAllKeys(HKEY hKey,char***keys,int *numberOfKeys);

SS_API unsigned char* SS_Win_getRegistryStringValue(HKEY hkey,const char* regStr);
SS_API void SS_Win_setRegistryStringValue(HKEY hkey,const char* regStr,const unsigned char* cBuff);

SS_API unsigned int SS_Win_getRegistryIntValue(HKEY hkey,const char* regStr);
SS_API void SS_Win_setRegistryIntValue(HKEY hkey,const char* regStr,const unsigned int iData);

SS_API int SS_Win_getRegistryBinaryValue(HKEY hkey,const char* regStr,unsigned char** binData,int *sizeOfData);
SS_API void SS_Win_setRegistryBinaryValue(HKEY hkey,const char* regStr,const unsigned char* binData,const int sizeOfData);

SS_API unsigned char* SS_Win_getRegistryMultiStringValue(HKEY hkey,const char*  regStr);
SS_API void SS_Win_setRegistryMultiStringValue(HKEY hkey,const char*  regStr,const unsigned char* cBuff);

SS_API void SS_Win_getRegistryMultiStringValues(HKEY hkey,const char* regStr,unsigned char***values, int*n);
SS_API void SS_Win_setRegistryMultiStringValues(HKEY hkey,const char* regStr,unsigned char**values, int n);
SS_API void SS_Win_deleteRegistry(HKEY hkey,const char* regStr);
SS_API BOOL SS_Win_isWin7OrAbove();
SS_API void SS_Win_reboot();
SS_API BOOL SS_Win_shellExecute(const char* program,BOOL isWaitFinish);
SS_API BOOL SS_Win_execute(const char* program,BOOL waitFinish);
SS_API BOOL SS_Win_isEventExist(const char* eventName);
SS_API char* SS_Win_Gb2Big(const char* strGb);
SS_API char* SS_Win_Big2Gb(const char* strBig);

SS_API int SS_Win_getNetworkAdapterInfo(LB_IP_ADAPTER_INFO_t ***info,int *count);
SS_API LB_IP_ADAPTER_INFO_t * SS_Win_AdapterInfo_new();
SS_API void SS_Win_AdapterInfo_destroy(LB_IP_ADAPTER_INFO_t *pInfo);
SS_API char* SS_Win_AdapterInfo_toString(LB_IP_ADAPTER_INFO_t *pInfo);
SS_API void SS_Win_AdapterInfo_dump(LB_IP_ADAPTER_INFO_t *pInfo);

#ifndef _WIN32_WCE
SS_API int SS_Win_createOdbcDSN(const char* driver,const char* dsnname,const char* server_ip,const char* username,const char* password,const char* database);
SS_API int SS_Win_startService(const char *serviceName);
#endif  // _WIN32_WCE
#endif  // _MSC_VER
#endif  //_SS_WINAPI_H_
