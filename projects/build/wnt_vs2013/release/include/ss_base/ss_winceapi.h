#ifndef _SS_WINCE_NET_H_
#define _SS_WINCE_NET_H_

#ifdef _WIN32_WCE
#include <windows.h>
#include "ss_base/ss_def.h"

#define SS_WINCE_PLATFORM_UNKNOW				"SS_WINCE_PLATFORM_UNKNOW"
#define SS_WINCE_PLATFORM_S3C6410				"S3C6410"
#define SS_WINCE_PLATFORM_S3C2416				"S3C2450"
#define SS_WINCE_PLATFORM_S5PV210				"S5PV210"

#define LB_SUBKEY_HSMMC0						"Drivers\\BuiltIn\\HSMMC0"
#define LB_HSMMC0_KEYNAME_DLL					"Dll"  
#define LB_HSMMC0_KEYNAME_ORDER					"Order"  
#define LB_HSMMC0_DF_DLL_KEYVAL					"s3c6410_hsmmc0.dll"

SS_API int SS_WinCE_getAdaptName(char *cNames);
SS_API int SS_WinCE_setMAC(const char* mac);
SS_API int SS_WinCE_enableDHCP();
SS_API int SS_WinCE_setStaticIp(const char*ip,const char*netmask,const char*gateway,const char*dns1,const char*dns2);
SS_API int SS_WinCE_installService(const unsigned char* program,const unsigned int level);
SS_API BOOL SS_WinCE_isServiceInstalled(const unsigned char* program,unsigned int *level);
SS_API void SS_WinCE_setIdentName(const unsigned char* name);
SS_API int LBK_getUUID(unsigned char *uuid);
SS_API int LBK_getUniqueID(unsigned int *uniqueId);
SS_API int LBK_getUniqueID2(unsigned int *uniqueId);
SS_API int LBK_getKernelVersion(unsigned char **nkVersion);
SS_API BOOL SS_WinCE_hasWatchdog();
SS_API BOOL SS_WinCE_existSD();
SS_API unsigned long long SS_WinCE_getSDSize();
SS_API int SS_WinCE_getRegMACIP(char** mac,char**ip);
SS_API BOOL SS_WinCE_EnableSD(BOOL bEnable);
SS_API char* SS_WinCE_getPlatform();
SS_API BOOL SS_WinCE_isS3C6410();
SS_API BOOL SS_WinCE_isS5PV210();
#endif

#endif
