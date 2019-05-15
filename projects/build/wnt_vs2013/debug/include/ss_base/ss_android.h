#ifndef _SS_ANDROID_H_
#define _SS_ANDROID_H_
#ifdef ANDROID
#include "ss_base/ss_sn.h"
#define LB_PROPERTY_SERVICE_STATUS		"lonbon.service.status"
#define ANDROID_ETHERNET_IFNAME			"eth0"
#define ANDROID_WIFI_IFNAME				"wlan0"
#define ANDROID_AID_ROOT				0
#define ANDROID_AID_SYSTEM				1000
#define ANDROID_AID_SHELL				2000  /* adb and debug shell user */
#define ANDROID_AID_CACHE				2001  /* cache access */
#define ANDROID_AID_DIAG				2002  /* access to diagnostic resources */

typedef enum{
	SS_HW_PLATFORM_UNKNOW=0,
	SS_HW_PLATFORM_A10,
	SS_HW_PLATFORM_A10S,
	SS_HW_PLATFORM_A20,
	SS_HW_PLATFORM_SMDK4412,
	SS_HW_PLATFORM_S5P4418,
	SS_HW_PLATFORM_RK3188
}ss_hardware_platform;

typedef enum {
	SS_NET_IFC_UNKNOW=-1,
	SS_NET_IFC_STATIC=0,
	SS_NET_IFC_DHCP,
	SS_NET_IFC_WIFI,
} ss_net_ifc_t;

typedef enum {
	SS_NET_IFC_DOWN=0,
	SS_NET_IFC_UP
} ss_net_ifc_stat_t;

typedef enum {
	SS_RECOVERY_TYPE_UNKNOW=-1,
	SS_RECOVERY_TYPE_FORMAT_SD=0,
	SS_RECOVERY_TYPE_WIPE_DATA,
	SS_RECOVERY_TYPE_UPDATE_PACKAGE,
	SS_RECOVERY_TYPE_FORMAT_EXT_SD
} ss_recovery_type_t;


#define MBYTE_TO_WCHAR(a,b) do{ \
	memset(b,0,sizeof(b)); \
	SS_Android_mByteToWChar(a,b); \
	}while(0)

#define WCHAR_TO_MBYTE(a,b) do{ \
	memset(b,0,sizeof(b)); \
	SS_Android_wCharToMByte(a,b); \
	}while(0)

#define MBYTE_TO_WCHAR2(a,b) MBYTE_TO_WCHAR(a,b)

#define WCHAR_TO_MBYTE2(a,b) WCHAR_TO_MBYTE(a,b)

SS_API unsigned char* getAndroidHardId();
SS_API unsigned char* getAndroidBuildVersion();
//SS_API char* getAllAndroidProperties();
//SS_API void dumpAllAndroidProperties();
SS_API ss_net_ifc_t getAndroidNetworkType();
SS_API int getAndroidNetworkInfo(char **lanMac,char **wifiMac,ss_net_ifc_t *network_type,ss_net_ifc_stat_t *stat,char**ip,char**netmask,char**gateway,char**dns1,char**dns2);
SS_API char* getAndroidEthernetMac();
SS_API char* getAndroidWifiMac();
SS_API char* getAndroidMac(); /* Try to get Ethernet MAC first, if NULL return Wifi MAC */

SS_API char* getAndroidIP();
SS_API int getAndroidPropertie(const char *key, char *value, const char *default_valu);
SS_API int setAndroidPropertie(const char *key, const char *value);

SS_API char* getAndroidBuildProperty(const char *key, const char *defaultValue);
SS_API int setAndroidBuildProperty(const char *key, const char *value);
SS_API int getAndroidBuildIntProperty(const char *key, const int defaultValue);
SS_API int setAndroidBuildIntProperty(const char *key, const int value);
SS_API BOOL isAndroidSystemWriteable();
SS_API int setAndroidSystemWriteable(BOOL enableWrite);

SS_API int setAndroidIntPropertie(const char *key, const int value);
SS_API void setAndroidRotation(int rotation);
SS_API int setAndroidStaticIP(const char* ip,const char* netmask,const char* gateway,const char* dns1,const char* dns2);
SS_API ss_hardware_platform getAndroidPlatform();
SS_API unsigned char* getAndroidPlatformDesc();
SS_API unsigned char* getAndroidRecoveryDevice();
SS_API unsigned char* getAndroidCmdDevice();
SS_API unsigned char* getAndroidUserdataDevice(void);
SS_API int getAndroidFlashFile(char ***flashDevices,int* length);

SS_API BOOL SS_Android_wCharToMByte(wchar_t *, char*);
SS_API BOOL SS_Android_mByteToWChar(char*, wchar_t *);
SS_API int SS_Android_setRecovery(ss_recovery_type_t type);
SS_API int SS_Android_setRecoveryBCB(ss_recovery_type_t type);
SS_API BOOL SS_Android_isSystemRecoveryAvaliabled();

SS_API int LBK_getKernelVersion(unsigned char **nkVersion);
SS_API unsigned int LBK_getKernelCommand();
SS_API int SS_Android_unpackOtaFile(char *lbFile);
#endif //ANDROID
#endif //_SS_ANDROID_H_
