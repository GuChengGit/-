#ifndef _SS_LONBON_H_
#define _SS_LONBON_H_
#include "ss_base/ss_ini_config.h"

#if defined(_MSC_VER)
#	define LONBON_VERSION_FILE			"lonbon/bin/VERSION"
#	define LONBON_APP_HTTPD				"lonbon_httpd.exe"
#	define LONBON_APP_MAIN				"lonbon_app.exe"
#	define LONBON_APP_SERVICE			"lonbon_service.exe"
#	define LONBON_APP_ADDRESS			"lonbon_address.exe"
#	define LONBON_APP_KEEPALIVE			"lonbon_keepalive.exe"
#	define LONBON_DIRECTORY				"lonbon"
#	define LONBON_SYSTEM_PACKAGE		"lonbon.7z"
#	ifdef _WIN32_WCE
#		define LONBON_BASE_NANDFLASH	"/NandFlash"
#		define LONBON_BASE_SYSTEM		"/"
#		define LONBON_BASE_RECORD		"/Storage Card/file"
#		define LONBON_BASE_MULTIMEDIA_EXT		"/Storage Card/ext_multimedia"
#		define LONBON_APP_WAITING				"CeBootWaiting.exe"
#	else
#		define LONBON_BASE_NANDFLASH	"C:\\Work"
#		define LONBON_BASE_SYSTEM		"C:\\Work\\system"
#		define LONBON_BASE_RECORD		"C:\\Work\\record"
#		define LONBON_BASE_MULTIMEDIA_EXT "C:\\Work\\ext_multimedia"
#		define LONBON_APP_WAITING			"lonbon_wait.exe"
#	endif
#else
#	define LONBON_SS_LIB_LINKED_FILE	"/usr/local/lib/_SS_LIB_LINKED_"
#	define LONBON_VERSION_FILE			"local/sbin/VERSION"
#	define LONBON_APP_HTTPD				"lonbon_httpd"
#	define LONBON_APP_SERVICE			"lonbon_service"
#	define LONBON_APP_KEEPALIVE			"lonbon_keepalive"
#	define LONBON_DIRECTORY				"local"
#	define LONBON_SYSTEM_PACKAGE		"local.7z"
#	if defined(__linux___ARM)
#		define LONBON_APP_MAIN				"opensips"
#		define LONBON_BASE_NANDFLASH	"/mnt/rwfs"
#		define LONBON_BASE_RECORD		"/mnt/rwfs/record"
#	    define LONBON_BASE_SYSTEM		"/lonbon"
#	    define LONBON_APP_SERVICE_2416	"lonbon_service_2416"
#	    define LONBON_APP_SERVICE_6410	"lonbon_service_6410"
#	    define LONBON_APP_SERVICE_210	"lonbon_service_210"
#	    define LONBON_APP_SERVICE_4418	"lonbon_service_4418"
#   elif defined(ANDROID)
#		define LONBON_APP_MAIN			"LonbonApp"
#		define LONBON_BASE_NANDFLASH	"/lonbon/data"
#		define LONBON_BASE_RECORD		"/lonbon/record"
#	    define LONBON_BASE_SYSTEM		"/lonbon/system"
#	else
#		define LONBON_APP_MAIN				"opensips"
#		define LONBON_BASE_NANDFLASH	"/usr"
#		define LONBON_BASE_RECORD		"/usr/record"
#	    define LONBON_BASE_SYSTEM		"/lonbon"
#	endif
#endif


#if defined(__linux__)||defined(ANDROID)
#define LONBON_BIN				"sbin"
#else
#define LONBON_BIN				"bin"
#endif
#define LONBON_APK				"apk"
#define LONBON_CONFIG			"config"
#define LONBON_WEBS				"webs"
#define LONBON_UPLOAD			"upload"
#define LONBON_MULTIMEDIA		"multimedia"
#define LONBON_TEMP				"temp"
#define LONBON_DATABASE			"database"
#define LONBON_TEMPLATE			"template"
#define LONBON_RES				"res"
#define LONBON_LOG				"log"
#define LONBON_FONT				"font"
#define LONBON_BACKUP			"backup"
#define LONBON_SCRIPT			"script"
#define LONBON_EXT_NEW_UPGRADE	"_NEW_UPGRADE"
#define LONBON_EXT_BACKUP		"_BACKUP"
#define LONBON_DB_CREATE_SCRIPT			"LONBON_DBS.SQL"
#define LONBON_UPGRADE_SCRIPT			"LONBON_UPGRADE.SQL"
#define LONBON_INIT_SCRIPT				"lonbonopensips.sql"
#define LONBON_UPGRADE_VISIT_SCRIPT	    "LONBON_UPGRADE_VISIT.SQL"
#define LONBON_INIT_VISIT_SCRIPT		"lonbonvisit.sql"

#define LONBON_PID_HTTPD				"lonbon_httpd.pid"
#define LONBON_PID_KEEPALIVE			"lonbon_keepalive.pid"
#define LONBON_PID_MAIN					"lonbon_app.pid"
#define LONBON_PID_NK					"lonbon_nk.pid"
#define LONBON_PID_FACTORY				"lonbon_factory.pid"
#define LONBON_PID_ADDRESS				"lonbon_address.pid"
#define LONBON_PID_REBOOT				"lonbon_reboot.pid"
#define LONBON_PID_UPGRADE_FAIL			"lonbon_upgrade_fail.pid"

#define LONBON_ENEVT_MAIN				"lb_app_exist_event"
#define LONBON_ENEVT_HTTPD				"lb_httpd_exist_event"
#define LONBON_ENEVT_ADDRESS			"lb_address_exist_event"
#define LONBON_ENEVT_KEEPALIVE			"lb_keepalive_exist_event"

#define LONBON_ENEVT_REBOOT				"lb_reboot_event"
#define LONBON_ALL_MODELS				"ALL"

#define SS_HTTPD_FAIL_UPGRADE_FILE		"LB_FAIL_UPGRADE"
#define SS_HTTPD_UPGRADE_FILE			"LB_UPGRADE"
#define SS_HTTPD_DATABASE_FILE			"LB_DATABASE"
#define SS_HTTPD_MULTIMEDIA_FILE		"LB_MULTIMEDIA"
#define SS_HTTPD_DUTY_DOCTOR_FILE		"LB_DUTY_DOCTOR"
#define SS_HTTPD_DUTY_NURSE_FILE		"LB_DUTY_NURSE"
#define SS_HTTPD_CONFIG_FILE			"LB_CONFIG"
#define SS_HTTPD_NOLOGO_FILE			"LB_NOLOGO"
#define SS_HTTPD_SDFILE_FILE			"LB_SDFILE"
#define SS_HTTPD_LOG_FILE				"LB_DIAG.log"
#define SS_HTTPD_CONFIG_FILE_SECTION	"LB_CONFIG"
#define SS_HTTPD_DBINFO_FILE			"LB_DBINFO"
#define SS_HTTPD_VERSION_FILE			"VERSION"
#define SS_HTTPD_LONBONSERVICE_WSDL		"lonbonservice.wsdl"
#define SS_HTTPD_MAC_LOG_FILE			"LB_MAC.log"
#define SS_HTTPD_IP_BACK_FILE			"_IP_BACK_"
#define SS_HTTPD_LOG_REPORT_FILE		"LB_RECORD.log"

#define STR_SOFTWAREVERSION        		"LB_SOFTWARE_VERSION"
#define STR_ENABLE_DIAG        			"ENABLE_DIAG"
#define SS_SERVICE_VERSION_FILE			"SERVICE_VERSION"
//For Android
#define STR_SCREEN_ROTATION				"LB_SCREEN_ROTATION"
#define DEFAULT_SCREEN_ROTATION			0

#define LONBON_BIN_PATH		    LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_BIN
#define LONBON_CONFIG_PATH      LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_CONFIG
#define LONBON_WEBS_PATH        LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_WEBS
#define LONBON_UPLOAD_PATH      LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_UPLOAD
#define LONBON_MULTIMEDIA_PATH  LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_MULTIMEDIA
#define LONBON_LOG_PATH         LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_LOG
#define LONBON_TEMP_PATH        LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_TEMP
#define LONBON_DATABASE_PATH    LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_DATABASE
#define LONBON_TEMPLATE_PATH    LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_TEMPLATE
#define LONBON_RES_PATH         LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_RES
#define LONBON_SCRIPT_PATH      LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_SCRIPT
#define LONBON_BACKUP_PATH      LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_BACKUP

#define LB_UPGRADE_FULL_PATH	LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_UPLOAD"/"SS_HTTPD_UPGRADE_FILE
#define LB_NO_WAITTING_FILE     LONBON_BASE_SYSTEM"/"LONBON_DIRECTORY"/"LONBON_TEMP"/LONBON_NO_WAITTING_FILE"

#ifdef ANDROID
#define LONBON_APK_PATH				LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_APK
#define LONBON_APK_NAME				"LonbonApp.apk"
#define LONBON_APP_PACKAGE			"com.lonbon.lonbon_app"
#define LONBON_APK_FULL_PATH		LONBON_APK_PATH"/"LONBON_APK_NAME
#define LB_DIAG_FULL_PATH			"/sdcard/Lonbon/log/"SS_HTTPD_LOG_FILE
#define LONBON_APP_FULL_PATH		LONBON_APK_PATH"/LonbonApp"
#define SYSTEM_APP_PATH				"/system/app"
#define SYSTEM_APP_PATH_LONBONAPP	"/system/app/LonbonApp"
#else
#define LB_DIAG_FULL_PATH			LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_TEMP"/"SS_HTTPD_LOG_FILE
#endif
#define LB_CONFIG_FULL_PATH			LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_CONFIG"/"SS_HTTPD_CONFIG_FILE
#define LB_NOLOGO_FULL_PATH			LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_BIN"/"SS_HTTPD_NOLOGO_FILE
#define LB_MAC_LOG_FULL_PATH		LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_TEMP"/"SS_HTTPD_MAC_LOG_FILE
#define LB_IP_BACK_FULL_PATH		LONBON_BACKUP_PATH"/"SS_HTTPD_IP_BACK_FILE
#define LB_LOG_REPORT_FULL_PATH		LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_TEMP"/"SS_HTTPD_LOG_REPORT_FILE

#define LB_SD_CARD_ROOT				"/Storage Card/"
#define LB_SD_CARD_ROOT_CFG			"/Storage Card/ENC_CONFIG"
#define LB_SD_CARD_LB_PWD			"LONBON_SDCARD_ENC_PWD_20110120"

#define LB_DUTY_NURSE_PATH		LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/images/nurses"
#define LB_DUTY_DOCTOR_PATH		LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/images/doctors"

#define LONBON_NET_PROPERTY_FILE			LONBON_BASE_NANDFLASH"/"LONBON_DIRECTORY"/"LONBON_CONFIG"/eth0.prop"
#define LONBON_NET_PROPERTY_ETH_ON  		  "lonbon.net.eth_on"
#define LONBON_NET_PROPERTY_ETH_ROUTE  		"lonbon.net.eth_route"
#define LONBON_NET_PROPERTY_ETH_IP     		"lonbon.net.eth_ip"
#define LONBON_NET_PROPERTY_ETH_CONF   		"lonbon.net.eth_conf"
#define LONBON_NET_PROPERTY_ETH_IFNAME 		"lonbon.net.eth_ifname"
#define LONBON_NET_PROPERTY_ETH_DNS    		"lonbon.net.eth_dns"
#define LONBON_NET_PROPERTY_ETH_MODE   		"lonbon.net.eth_mode"
#define LONBON_NET_PROPERTY_ETH_NETMASK		"lonbon.net.eth_netmask"

#define LONBON_NET_PROPERTY_WIFI_ON			"lonbon.net.wifi_on"

#define ANDROID_BUILD_PROPERTY_FILE			"/system/build.prop"
#define LONBON_KERNEL_PROPERTY_ROTATION		"lonbon.kernel.rotation"
#define LONBON_KERNEL_PROPERTY_DPI			"ro.sf.lcd_density"	

#define ANDROID_PROPERTY_HW_ROTATION		"ro.sf.hwrotation"

#define LB_MYSQL_INIT_FILE			LONBON_TEMPLATE_PATH"/etc/init.d/mysql"
#ifdef __linux___ARM
#define LB_MYSQL_INIT_FILE_SYSTEM		"/usr/local/etc/init.d/mysql"
#define SQL_ROOT_CMD			"/usr/local/mysql/bin/mysql -f -plonbon mysql"
#define SQL_CMD			"/usr/local/mysql/bin/mysql -f -plonbon lonbonopensips"
#define SQL_VISIT_CMD	"/usr/local/mysql/bin/mysql -f -plonbon lonbonvisit"
#define DB_BACKUP_CMD	"/usr/local/mysql/bin/mysqldump -plonbon -q --add-drop-table lonbonopensips lb_address_desc lb_address_maxslave lb_address_ext lb_address_group lb_address_nndc lb_address lb_area lb_duty_doctor lb_duty_nurses lb_extension lb_lcdinfo lb_level lb_patient lb_patient_ext lb_patient_ext_desc subscriber lb_model lb_soft lb_table_version > %s"
#define DB_RESTORE_CMD	"/usr/local/mysql/bin/mysql -plonbon lonbonopensips < %s"
#define SQL_VISIT_CMD			"/usr/local/mysql/bin/mysql -f -plonbon lonbonvisit"
#define DB_BACKUP_VISIT_CMD	"/usr/local/mysql/bin/mysqldump -plonbon -q --add-drop-table lonbonvisit base branch card daytickets lbpdwindowInfo numtbl prisoner relation lbqy_dispensary lbqy_doctor lbqy_lcd_info lbqy_login lbqy_patient lbqy_patient_restore > %s"
#define DB_RESTORE_VISIT_CMD	"/usr/local/mysql/bin/mysql -plonbon lonbonvisit < %s"
#define LB_MYSQL_CHECK              "/usr/local/mysql/bin/mysqlcheck -A -r -plonbon"
#else
#define LB_MYSQL_INIT_FILE_SYSTEM		"/etc/init.d/mysql"
#define SQL_ROOT_CMD	"mysql -f -plonbon mysql"
#define SQL_CMD			"mysql -f -plonbon lonbonopensips"
#define SQL_VISIT_CMD	"mysql -f -plonbon lonbonvisit"
#define DB_BACKUP_CMD	"mysqldump -plonbon -q --add-drop-table lonbonopensips lb_address_desc lb_address_maxslave lb_address_ext lb_address_group lb_address_nndc lb_address lb_area lb_duty_doctor lb_duty_nurses lb_extension lb_lcdinfo lb_level lb_patient lb_patient_ext lb_patient_ext_desc subscriber lb_model lb_soft lb_table_version > %s"
#define DB_RESTORE_CMD	"mysql -plonbon lonbonopensips < %s"
#define SQL_VISIT_CMD			"mysql -f -plonbon lonbonvisit"
#define DB_BACKUP_VISIT_CMD	"mysqldump -plonbon -q --add-drop-table lonbonvisit base branch card daytickets lbpdwindowInfo numtbl prisoner relation lbqy_dispensary lbqy_doctor lbqy_lcd_info lbqy_login lbqy_patient lbqy_patient_restore > %s"
#define DB_RESTORE_VISIT_CMD	"mysql -plonbon lonbonvisit < %s"
#define LB_MYSQL_CHECK              "mysqlcheck -A -r -plonbon"

#endif

#define LONBON_PATH_BASE(a,b,dir) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s/%s/%s",LONBON_BASE_NANDFLASH,LONBON_DIRECTORY,dir,b); \
}while(0)

#define LONBON_PATH_BIN(a,b)		LONBON_PATH_BASE(a,b,LONBON_BIN)
#define LONBON_PATH_WEBS(a,b)		LONBON_PATH_BASE(a,b,LONBON_WEBS)
#define LONBON_PATH_CONFIG(a,b)		LONBON_PATH_BASE(a,b,LONBON_CONFIG)
#define LONBON_PATH_TEMPLATE(a,b)	LONBON_PATH_BASE(a,b,LONBON_TEMPLATE)
#define LONBON_PATH_BACKUP(a,b)		LONBON_PATH_BASE(a,b,LONBON_BACKUP)
#define LONBON_PATH_MULTIMEDIA(a,b) LONBON_PATH_BASE(a,b,LONBON_MULTIMEDIA)
#define LONBON_PATH_TEMP(a,b)		LONBON_PATH_BASE(a,b,LONBON_TEMP)
#define LONBON_PATH_DATABASE(a,b)	LONBON_PATH_BASE(a,b,LONBON_DATABASE)
#define LONBON_PATH_SCRIPT(a,b)		LONBON_PATH_BASE(a,b,LONBON_SCRIPT)
#define LONBON_PATH_RES(a,b)		LONBON_PATH_BASE(a,b,LONBON_RES)

#define LONBON_PATH(a,b)			LONBON_PATH_BIN(a,b)
#define LONBON_PATH_PID(a,b)		LONBON_PATH_TEMP(a,b)

#define LONBON_PATH_BASE_SUB(a,b,dir,sub) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s/%s/%s/%s",LONBON_BASE_NANDFLASH,LONBON_DIRECTORY,dir,sub,b); \
}while(0)

#define LONBON_PATH_WEBS_JS(a,b)			LONBON_PATH_BASE_SUB(a,b,LONBON_WEBS,"js")
#define LONBON_PATH_WEBS_LANG(a,b,lang)		LONBON_PATH_BASE_SUB(a,b,LONBON_WEBS,lang)


#define LONBON_PATH_NEW_UPGRADE(a,b) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s/%s/%s%s",LONBON_BASE_NANDFLASH,LONBON_DIRECTORY,LONBON_BIN,b,LONBON_EXT_NEW_UPGRADE); \
}while(0)


#define LONBON_PATH_DOCTOR_JPEG(a,b) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s.jpg",LB_DUTY_DOCTOR_PATH,b); \
}while(0)

#define LONBON_PATH_NURSE_JPEG(a,b) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s.jpg",LB_DUTY_NURSE_PATH,b); \
}while(0)

#define LONBON_PATH_RECORD(a,b) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s",LONBON_BASE_RECORD,b); \
}while(0)

#define LONBON_PATH_SYSTEM_DIR(a,b,dir) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s/%s/%s",LONBON_BASE_SYSTEM,LONBON_DIRECTORY,dir,b); \
}while(0)

#ifdef _WIN32_WCE
#define LONBON_PATH_SYSTEM(a,b) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"/Windows/%s",b); \
}while(0)
#define LONBON_PATH_SYSTEM_TEMP(a,b)	do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"/Temp/%s",b); \
}while(0)

#define LONBON_PATH_SYSTEM_TEMP_DIR(a) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"Temp"); \
}while(0) 

#define LONBON_PATH_SYSTEM_BIN(a,b)		LONBON_PATH_SYSTEM(a,b)
#define LONBON_PATH_SYSTEM_WEBS(a,b)	LONBON_PATH_SYSTEM(a,b)
#else
#define LONBON_PATH_SYSTEM(a,b)			LONBON_PATH_SYSTEM_DIR(a,b,LONBON_BIN)
#define LONBON_PATH_SYSTEM_TEMP(a,b)	LONBON_PATH_SYSTEM_DIR(a,b,LONBON_TEMP)
#define LONBON_PATH_SYSTEM_BIN(a,b)		LONBON_PATH_SYSTEM_DIR(a,b,LONBON_BIN)
#define LONBON_PATH_SYSTEM_WEBS(a,b)	LONBON_PATH_SYSTEM_DIR(a,b,LONBON_WEBS)
#define LONBON_PATH_SYSTEM_TEMP_DIR(a) do { \
	memset(a,0,sizeof(a)); \
	sprintf(a,"%s/%s/%s",LONBON_BASE_SYSTEM,LONBON_DIRECTORY,LONBON_TEMP); \
}while(0)

#endif
#define LONBON_PATH_SYSTEM_PID(a,b)		LONBON_PATH_SYSTEM_TEMP(a,b)


#ifdef _WIN32_WCE
#define LB_REG_PATH				"HKEY_LOCAL_MACHINE\\Comm\\LBKEY"
#define LB_CONFIG_REG_PATH		"HKEY_LOCAL_MACHINE\\Comm\\LB_CONFIG"
#else
#define LB_REG_PATH				"HKEY_CURRENT_USER\\Comm\\LBKEY"
#define LB_CONFIG_REG_PATH		"HKEY_CURRENT_USER\\Comm\\LB_CONFIG"
#endif

#define LB_REG_NAME_COUNT		"LBUPGRADE_COUNT"
#define LB_REG_NAME_TIME		"LBUPGRADE_TIME"
#define LB_REG_NAME_CONFIG		"LBCONFIG"
#define LB_REG_NAME_FLASH		"LBFLASH"

typedef enum {
	LB_STATUS_UNKNOW=0,
	LB_STATUS_STARTING,
	LB_STATUS_CHECKING_UPGHRADE_FILE,
	LB_STATUS_UPGHRADING,
	LB_STATUS_APK_INSTALLING,
	LB_STATUS_HTTPD_STARTING,
	LB_STATUS_SERVICE_DONE,
} LB_Status;

#define LB_CONFIG_FILE_SECTION				"LB_CONFIG"


#define STR_MASTER_NUMBER          			"MASTER_NUMBER"
#define STR_SLAVE_NUMBER          			"SLAVE_NUMBER"
#define STR_GROUP_NUMBER					"LB_GROUP_NUMBER"
#define STR_DEVICE_NUMBER					"LB_DEVICE_NUMBER"
#define STR_AREA_NUMBER						"LB_AREA_NUMBER"
#define STR_HOST_NUMBER						"LB_HOST_NO"
#define STR_HANDSETMICGAIN         			"HANDSETMICGAIN"
#define STR_HANDSETVOLUME          			"HANDSETVOLUME"
#define STR_LANGUAGE						"LB_LANGUAGE"
#define STR_SERVERIP         				"SERVERIP"
#define STR_HOST_NUMBER						"LB_HOST_NO"
#define STR_PRIVATE							"LB_PRIVATE"

#define DEFAULT_MASTER_NUMBER				0     
#define DEFAULT_SLAVE_NUMBER				0      
#define DEFAULT_GROUP_NUMBER				1
#define DEFAULT_DEVICE_NUMBER				1
#define DEFAULT_AREA_NUMBER					0
#define DEFAULT_HANDSETMICGAIN          	8
#define DEFAULT_HANDSETVOLUME         		3

#define DEFAULT_SERVERIP					"192.168.1.169"         	
#define DEFAULT_HOST_NUMBER					""
#define DEFAULT_PRIVATE						"NO"

#define SS_LOCK_NAME_BACKUPIP				"SS_LOCK_NAME_BACKUPIP"
#define SS_LOCK_NAME_PROPERTY				"SS_LOCK_NAME_PROPERTY"
#define SS_LOCK_NAME_INICONFIG				"SS_LOCK_NAME_INICONFIG"

typedef struct _lb_key_config_t{
	int master_number;
	int slave_number;
	int area_number;
	int group_number;
	int device_number;
	int micGain;
	int speakVolume;
	unsigned char privateSlave[8];
	unsigned char lang[16];
	unsigned char serverIPList[64];
	unsigned char serverIP[32];
}lb_key_config_t;

typedef enum{
	LB_BACKUP=0,
	LB_RESTORE
}lb_backup_restore_t;

SS_API lb_key_config_t* LBKeyConfig_getFromIni(IniConfig *iniConfig);
#ifdef _MSC_VER
SS_API lb_key_config_t* LBKeyConfig_getFromReg(const char *iniFileName);
SS_API void LBKeyConfig_deleteReg(const char *iniFileName);
SS_API void LBKeyConfig_deleteAllReg();
#endif
SS_API void LBKeyConfig_saveToIni(IniConfig *iniConfig,lb_key_config_t* keyConfig);
SS_API BOOL LBKeyConfig_isSame(lb_key_config_t *a,lb_key_config_t*b);
SS_API BOOL LBKeyConfig_checkIni(IniConfig *iniConfig,lb_backup_restore_t backupOrRestore);
SS_API void LB_initDirectorys();
#if defined(__linux__)||defined(ANDROID)
SS_API BOOL LB_isServiceSuccessUpgraded();
SS_API BOOL LB_isServiceNeedUpgrade();
#endif
SS_API const char* LB_getServiceName();
#endif   //_SS_LONBON_H_
