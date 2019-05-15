#ifndef _SS_PKG_H_
#define _SS_PKG_H_
#include "ss_base/ss_def.h"
#ifdef ANDROID
#include "ss_base/ss_android.h"
#endif
#include "ss_base/ss_socket.h"
#include "ss_base/ss_thread.h"
#include "ss_base/ss_list.h"
#include "ss_base/ss_ini_config.h"
#include "ss_base/ss_flash.h"
#include "ss_base/ss_device.h"
#include "ss_base/ss_lonbon.h"

#define SS_PKG_LENGTH_ID			4
#define SS_PKG_LENGTH_CMD			4
#define SS_PKG_LENGTH_DATALENGTH	4
#define SS_PKG_LENGTH_MD5			32
#define SS_PKG_MAGIC_KEY			"---LONBON-LONBON-LONBON-LONBON--"

#define SS_PKG_AUTO_ID				0

#define SS_PKG_FILE_MAX_SIZE		(32*1024)

typedef enum {
	SS_PKG_ERROR=-1,
	SS_PKG_OK=0,
	SS_PKG_FILE_NOT_EXIST=100,
	SS_PKG_FILE_READ_ERROR,
	SS_PKG_FILE_WRITE_ERROR,
	SS_PKG_FILE_ZERO_SIZE,
	SS_PKG_FILE_TOO_BIG,
	SS_PKG_FILE_INVALID_PKG,
	SS_PKG_FILE_INVALID_PATH,
} SS_PKG_CODE;


typedef enum {
	LB_CMD_UNKNOW=-1,
	LB_CMD_GET_DEVICE_INFO=1000,
	LB_CMD_SET_INICONFIG,
	LB_CMD_GET_LCD_INFO,
	LB_CMD_CHANGE_LCD_INFO,
	LB_CMD_UPDATE_STATUS,
	LB_CMD_UPDATE_DASHBOARD,
	LB_CMD_GET_DOCTOR_PHOTO_NAME,
	LB_CMD_GET_NURSE_PHOTO_NAME,
} SS_PkgCommand;


typedef void (*_SS_PkgService_fn_)(struct _SS_PkgService* );
typedef void (*_SS_SocketPkg_callback) (struct _SS_SocketPkg_t*);

typedef struct _SS_Pkg_t {
	unsigned int id;
	unsigned int cmd;
	unsigned int length;
	unsigned char *data;
	unsigned char md5[SS_PKG_LENGTH_MD5];
}SS_Pkg_t;

typedef struct _SS_SocketPkg_t {
	SS_Pkg_t *pkg;
	struct sockaddr_in* addr;
}SS_SocketPkg_t;

typedef struct _SS_PkgService {
	SS_Socket* listenerSocket;
	ss_mutex_t	lock;
	ss_thread_t	dispatcherThread;
	ss_thread_t	netPkgHandlerThread;
	BOOL isRunning;
	int port;
	struct sockaddr_in* bind_address;
	BOOL isServiceProvider;
	MSList *pkgList;
	_SS_PkgService_fn_ netPkgHandler;
#ifdef ANDROID
	SS_AndroidDeviceInfo *androidDeviceInfo;
#endif
}SS_PkgService;

SS_API void SS_Pkg_free(SS_Pkg_t *pkg);
SS_API SS_Pkg_t *SS_Pkg_new(unsigned int id,unsigned int cmd,unsigned int length,unsigned char *data);

SS_API SS_SocketPkg_t *SS_SocketPkg_new(SS_Pkg_t *pkg,struct sockaddr_in* addr);
SS_API void SS_SocketPkg_free(SS_SocketPkg_t *netPkg);

SS_API int SS_Pkg_buff2Pkg(unsigned char *buff,unsigned int length,SS_Pkg_t ** pkg);
SS_API int SS_Pkg_pkg2Buff(SS_Pkg_t *pkg,unsigned char **buff,unsigned int *length);

SS_API SS_PkgService * SS_PkgService_start(BOOL isServer);
SS_API void SS_PkgService_stop(SS_PkgService *pkgService);
SS_API char* SS_PkgService_toString(SS_PkgService *pkgService);

SS_API void SS_PkgService_setNetPkgHandler(SS_PkgService *pkgService,_SS_PkgService_fn_ netPkgHandler);
SS_API int SS_PkgService_sendPkg(SS_PkgService *pkgService,const struct sockaddr_in *toAddr, SS_Pkg_t *pkg);
SS_API int SS_PkgService_sendCMD(SS_PkgService *pkgService,const struct sockaddr_in *toAddr, unsigned int id,unsigned int cmd,unsigned int length,unsigned char *data);
SS_API int SS_PkgService_sendStatus(const struct sockaddr_in *toAddr, LB_Status status);

SS_API SS_PKG_CODE SS_Pkg_file2Buff(unsigned char* filePath,unsigned char* fileName,unsigned int *pkgSize,unsigned char **pkgBuff);
SS_API SS_PKG_CODE SS_Pkg_buff2File(unsigned int pkgSize,unsigned char *pkgBuff,unsigned char* filePath);

#endif
