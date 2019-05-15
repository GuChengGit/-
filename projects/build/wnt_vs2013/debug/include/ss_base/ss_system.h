#if (defined(_MSC_VER) && !defined(_WIN32_WCE))|| (defined(__linux__) && !defined(__linux___ARM))|| defined(ANDROID)

#ifndef _SS_SYSTEM_H_
#define _SS_SYSTEM_H_
#include "ss_base/ss_def.h"

typedef struct _SS_MemoryInfo{
	char manufactuer[32];
	char serial_number[32];
	char part_number[32];
}SS_MemoryInfo;

typedef struct _SS_InterfaceInfo{
	char name[64];
	char mac[13];
	char ip[16];
}SS_InterfaceInfo;

typedef struct _SS_HardInfo{
	char system_uuid[48];
	char cpu_name[64];
	char cpu_id[17];
	char baseboard_name[48];
	char baseboard_sn[48];
	char harddisk_model[32];
	char harddisk_sn[32];
	int memoey_count;
	SS_MemoryInfo **memory_info;
	int eth_count;
	SS_InterfaceInfo **eth_info;
}SS_HardInfo;

SS_API char* SS_HardInfo_toString(SS_HardInfo *info);
SS_API void SS_HardInfo_dump(SS_HardInfo *info);
SS_API unsigned int SS_System_getAuthID();
SS_API const SS_HardInfo* SS_System_getHardInfo();

SS_API void SS_System_initHardInfo();
SS_API void SS_System_uninitHardInfo();

#endif //_SS_SYSTEM_H_
#endif
