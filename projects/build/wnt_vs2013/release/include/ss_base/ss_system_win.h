#ifndef _SS_SYSTEM_WIN_
#define _SS_SYSTEM_WIN_
#if defined(_MSC_VER) && !defined(_WIN32_WCE)
#include "ss_base/ss_def.h"

SS_API char* SS_Win_getIP();
SS_API unsigned char* SS_Win_getPlatform();
SS_API int SS_Win_enableDHCP();
SS_API int SS_Win_setStaticIp(const char*ip,const char*netmask,const char*gateway,const char*dns1,const char*dns2);
#endif
#endif //_SS_SYSTEM_WIN_
