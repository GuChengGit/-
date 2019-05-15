#if defined(__linux___ARM) || defined(ANDROID)
#ifndef _SS_KERNEL_COMMAND_H_
#define _SS_KERNEL_COMMAND_H_
#include "ss_base/ss_def.h"
#define LBK_COMMAND_FORMAT_USERDATA		(1<<0)

SS_API int LBK_getUUID(unsigned char *uuid);
SS_API int LBK_getUniqueID(unsigned int *uniqueId);
SS_API int LBK_getUniqueID2(unsigned int *uniqueId);
SS_API int LBK_getKernelVersion(unsigned char **nkVersion);
SS_API unsigned int LBK_getKernelCommand();
SS_API BOOL LBK_isNeedFormatUserData();
SS_API int LBK_formatUserData(BOOL isForce);
SS_API int LBK_setWatchDogStop();
SS_API int LBK_setWatchDogShutdown();
SS_API int LBK_setWatchDogReboot();
#endif
#endif
