#if defined(__linux__)
#ifndef _SS_OPENSIPS_H_
#define _SS_OPENSIPS_H_
#include "ss_base/ss_def.h"
#define SS_PLATFORM_SMDK2416		"SMDK2416"
#define SS_PLATFORM_SMDK6410		"SMDK6410"
#define SS_PLATFORM_SMDKV210		"SMDKV210"
#define SS_PLATFORM_S5P4418			"s5p4418"
#define SS_PLATFORM_GNULINUX		"GNU/Linux"
#define SS_PLATFORM_UNKNOW			"UNKNOW Linux"

typedef enum{
	SS_LINUX_UNKNOW=0,
	SS_LINUX_SMDK2416,
	SS_LINUX_SMDK6410,
	SS_LINUX_SMDKV210,
	SS_LINUX_S5P4418,
	SS_LINUX_GNULINUX,
}ss_linux_platform;

SS_API ss_linux_platform getLinuxPlatform();
SS_API unsigned char* getLinuxPlatformDesc();
SS_API int getLinuxFlashFile(char ***flashDevices,int* length);

SS_API int setStaticIP(const char* ip1,const char* ip2,const char* netmask,const char* gateway,const char* dns1,const char* dns2);
SS_API char* getCPUName();
SS_API char* getPlatform();
SS_API char* getCPUId();
SS_API char* getSystemName();
SS_API char* getBoardName();
SS_API char* getBoardSN();
SS_API char* getKernelVersion();
SS_API int changeBroadcastProxy(const char* broadcast_ip,const int broadcast_port);
SS_API int getLonbonBroadcastParam(char** ip, int *port);
SS_API void SS_Opensips_start(void);
SS_API void SS_Opensips_stop(void);
SS_API int reConfigServices(const char* ip1,const char* ip2);
SS_API BOOL isProgramRunning(const char* program);
SS_API void createLibraryLink();
#ifndef __linux___ARM
SS_API char* getHDSerial(void);
SS_API int _isVMware();
#else
SS_API unsigned char* getArmLinuxHardId();
SS_API unsigned char* getArmCmdDevice(void);
SS_API unsigned char* getArmUserdataDevice(void);

#endif
#endif //_SS_OPENSIPS_H_
#endif //_MSC_VER

