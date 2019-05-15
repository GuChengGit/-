#ifndef _SS_DEVICE_H_
#define _SS_DEVICE_H_
#include "ss_base/ss_flash.h"
#include "ss_base/ss_sn.h"
#include "ss_base/ss_thread.h"
#ifdef ANDROID
#include "ss_base/ss_android.h"
#endif


struct _SS_DeviceInfo_t;
typedef int (*fn_device_t)(struct _SS_DeviceInfo_t *pDeviceInst);
typedef int (*fn_refresh_t)(struct _SS_DeviceInfo_t *pDeviceInst,unsigned long timer);

typedef struct _SS_DeviceInfo_t{
	unsigned char* configOK;
	unsigned char* deviceName;
	unsigned char* deviceModel;
	unsigned char* customizedModel;
	unsigned char* hardVersion;
	unsigned char* hd_id;
	unsigned char* nk_version;
	unsigned char* platform;
	unsigned int   modelCode;
#ifdef __linux__
	unsigned char* os;
	unsigned char* board_name;
	unsigned char* board_sn;
	unsigned char* cpu_name;
	unsigned char* cpu_id;
#endif
	unsigned char* account;
	unsigned char* password;
	unsigned char* encPassword;
	unsigned int   sipPort;

	unsigned char* license;
	unsigned char* sn;
	unsigned char* mac;
#if defined(ANDROID)
	unsigned char* wifiMac;
	ss_net_ifc_t network_type;
#endif
	unsigned char *ip;
	unsigned char *ip2;
	unsigned char *gateway;
	unsigned char *netmask;
	unsigned char *dns1;
	unsigned char *dns2;
	BOOL isEnableDHCP;
	BOOL isGoodLicense;
	BOOL isAllowSDRecording;
	BOOL isLevelOneMaster;
	BOOL isSDKEnabled;
	ss_sn_type_t type;
	fn_device_t refresh;
	fn_device_t stopRefresh;
	fn_refresh_t startRefresh;
	ss_mutex_t lock;
	ss_thread_t	refreshThread;
	BOOL isRefreshThreadRunning;
	unsigned long timer;
	ss_sn_manufactory_type manufactoryType;
	int rotation;
}SS_DeviceInfo;

SS_API SS_DeviceInfo* SS_DeviceInfo_new(SS_Flash *pFlash);
SS_API void SS_DeviceInfo_destroy(SS_DeviceInfo *pDeviceInst);
SS_API char* SS_DeviceInfo_toString(SS_DeviceInfo *pDeviceInst);
SS_API char* SS_DeviceInfo_toFullString(SS_DeviceInfo *pDeviceInst,BOOL isFullInfo);
SS_API void SS_DeviceInfo_dump(SS_DeviceInfo *pDeviceInst);

#ifdef ANDROID
typedef struct _SS_AndroidDeviceInfo_t{
	char configOK[5];
	char deviceModel[17];
	char hardVersion[17];
	char hd_id[33];
	char nk_version[64];
	char account[15];
	char password[11];
	char encPassword[17];
	int  sipPort;
	char license[45];
	char sn[12];
	BOOL isGoodLicense;
	ss_net_ifc_t networkType;
	char lanMac[13];
	char wifiMac[13];
	char ip[16];
	char netmask[16];
	char gateway[16];
	char dns1[16];
	char dns2[16];
	char customizedModel[17];
	ss_sn_manufactory_type manufactoryType;
	unsigned int   modelCode;
	int rotation;
}SS_AndroidDeviceInfo;

SS_API SS_AndroidDeviceInfo* getAndroidDeviceInfo(const SS_DeviceInfo* pDeviceInst);
#endif
#endif  //_SS_DEVICE_H_
