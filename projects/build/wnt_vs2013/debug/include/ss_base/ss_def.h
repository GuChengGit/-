/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_def.h
* @brief Generic Defination.
*
* @author	Qiusheng Li
* @date	2008-09-20
*
*/
#ifndef _SS_DEF_H_
#define _SS_DEF_H_

#ifdef HAVE_VLD_H
#	include "vld.h"
#endif

#ifdef _NNOS
#include <stddef.h>
#endif

#define WHITESPACE_STR		" \f\n\r\t\v"
#define TRUE_STR			"YyTt1"
#define SS_MAX_LINE_LENGTH	256
#define SS_NULL_STR			"(null)"
#define SS_OK				0
#define SS_FAIL				-1
#define LQS					">>LQS<<"
#define SS_DEBUG_ENABLED	"SS_DEBUG_ENABLED"
#define SS_REBOOT_DISABLED	"SS_REBOOT_DISABLED"
#define SS_ENV_LONBON_ONLY	"SS_ENV_LONBON_ONLY"

#define SS_UPGRADE_TYPE		">LONBON_UPGRADE<"
#define SS_UPGRADE_TYPE_LENGTH		16
#define SS_BIG_BUFF_LENGTH		(64*1024)

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#define LONBONVOIP_REALM		"voip.lonbon.com"
#define LONBONVOIP_REALM_IP		"61.141.235.79"
//#define SS_TEST_DUMMY_LONBON_SERVER	 "192.168.1.81"

#define SS_DEFAULT_MAC			"00FA89010203"
#define SS_DEFAULT_DUMMY_IP			"127.0.0.1"

#if defined(__linux__)
#	define SS_DEFAULT_IP			"192.168.1.169"
#	define SS_DEFAULT_IP2			"192.168.1.170"
#else
#	define SS_DEFAULT_IP			"192.168.1.168"
#	define SS_DEFAULT_IP2			SS_DEFAULT_DUMMY_IP
#endif

#define SS_DEFAULT_NETMASK		"255.255.255.0"
#define SS_DEFAULT_GATEWAY		"192.168.1.1"
#define SS_DEFAULT_DNS			"202.96.134.133"
#define SS_DEFAULT_DNS2			"202.96.128.68"
#define NOT_SUPPORT_YET			"NOT_SUPPORT_YET"
#define NOT_SUPPORT_HARDDISK	"NOT_SUPPORT_HARDDISK"
#define SS_MAX_ENCRYPT_LENGTH	1024


#define SS_AUTO_NETWORK_IDENTIFIER		0x37F00000
#define SS_AUTO_NETWORK_MASK			"255.240.0.0"
#define SS_AUTO_NETWORK_ADDRESSBOX_IP1	"55.240.251.169"
#define SS_AUTO_NETWORK_ADDRESSBOX_IP2	"55.240.251.170"
#define SS_AUTO_NETWORK_GATEWAY			"55.240.251.1"

#define SS_OS_WINCE			"WinCE"
#define SS_OS_WINNT			"WinNT"
#define SS_OS_ANDROID		"Android"
#define SS_OS_LINUX			"Linux"

#ifdef _WIN32_WCE
#define SS_PLATFORM_OS			SS_OS_WINCE
#elif defined(ANDROID)
#define SS_PLATFORM_OS			SS_OS_ANDROID
#elif defined(__linux__) 
#define SS_PLATFORM_OS			SS_OS_LINUX
#else
#define SS_PLATFORM_OS			SS_OS_WINNT
#endif

#ifdef __cplusplus
#define SS_API extern "C"
#else
#define SS_API
#endif

#ifdef __cplusplus
#define SS_API_EXPORT extern "C" __declspec(dllexport)
#else
#define SS_API_EXPORT __declspec(dllexport)
#endif


#define SS_NEW(type,n)	(type*) malloc(sizeof(type)*(n))
#define SS_NEW0(type,n)	(type*) memset(malloc((n)*sizeof(type)),0,(n)*sizeof(type))

#define SS_FREE(p)  do { if((p)!= NULL) { free (p);     (p) = NULL; } }while(0)
#define SS_STRCPY(t,s)  do { if((s)!= NULL) strcpy((t),(s));else (t)[0]='\0';}while(0)
#define SS_STRNCPY(t,s) do { if((s)!= NULL && strlen(s)>0) strncpy((t),(s),sizeof(t)-1);else (t)[0]='\0';}while(0)

#define SS_CONVERT_CST2_TIME_FORMAT(c,s)  do { \
	time_t _theTime_; \
	format_string_to_time((c),DEFAULT_TIME_FORMAT_CST2,&_theTime_); \
	time_to_format_string(_theTime_,DEFAULT_TIME_FORMAT,(s)); \
}while(0)

#define	SS_ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))
#define	SS_SWAP(a,b)	a=a+b;b=a-b;a=a-b
#define	SS_WCHAR_SIZE	sizeof(wchar_t)

#define SS_FREE_ARRAY(s,n) \
	do{ \
	if ((s) != NULL && (n) > 0 ) {\
	int _i_=0; \
	while(_i_<(n)){\
	SS_FREE((s)[_i_]);\
	_i_++;\
	}\
	free((s));\
	(s)=NULL;\
	}\
	} while(0)

#define SS_FREE_ARRAY_CUST(s,n,fn) \
	do{ \
	if ((s) != NULL && (n) > 0 ) {\
	int _i_=0; \
	while(_i_<(n)){\
	fn((s)[_i_]);\
	(s)[_i_]=NULL; \
	_i_++;\
	}\
	free((s));\
	(s)=NULL;\
	}\
	} while(0)

#define SS_CALL(f) \
	do{ \
	int rc = SS_OK; \
	rc = (f); \
	if (rc != SS_OK) { \
	SS_LOG(SS_ERROR,"Error[%d] %s\n",rc,getErrorMessage (rc));	\
	} \
	} while(0)
#ifndef _NNOS
#ifndef MAX
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))
#endif
#endif
#ifndef _WIN32_WCE
#ifndef ASSERT
# define ASSERT(p) assert(p)
//# define ASSERT(p) do {SS_LOG(SS_DEBUG,"ASSERT HERE[%s]",p?"True":"False");assert(p);} while (0)
#endif
#endif

#if !(defined(uint32_t)||defined(__uint32_t_defined))
//typedef unsigned int uint32_t;
#define uint32_t unsigned int
#define __uint32_t_defined
#endif

#ifndef u_int8_t
#define u_int8_t unsigned char
#endif

#ifndef u_int16_t
#define u_int16_t unsigned short
#endif

#ifndef u_int32_t
#define u_int32_t unsigned long
#endif

#if (!(defined(__cplusplus) || defined(_WINDEF_)|| defined(BOOL_DECLARED)|| defined(_NNOS)))
#define BOOL_DECLARED
typedef int BOOL;
#endif

/**
* Define snprintf if they're not already defined.
* @def snprintf
*/

#ifdef _MSC_VER
#	define CRLF						"\n"
#	define PATH_SEPARATOR			'\\'
#	define SYSTEM_CMD_DELETE		"del /f /q"
#	define SYSTEM_CMD_MOVE			"move /y"
#	define SYSTEM_CMD_REBOOT		"shutdown -f -r"
#	ifdef _WIN32_WCE
#		define DEFAULT_TEMP_DIR		"\\TEMP"
#		define strerror(errno)		"WinCE Error"
#	else
#		define DEFAULT_TEMP_DIR		"C:\\TEMP"
#	endif
#	pragma warning(disable:4267 4996)
#   ifndef snprintf
#		define snprintf _snprintf
#   endif
#   ifndef vsnprintf
#		define vsnprintf  _vsnprintf
#   endif
#   ifndef strcasecmp
#       define strcasecmp _stricmp
#   endif
#   ifndef strncasecmp
#       define strncasecmp _strnicmp
#   endif
#	ifndef WIN32_LEAN_AND_MEAN
#		define WIN32_LEAN_AND_MEAN 
#	endif
#	ifndef usleep
#		define usleep(s) _sleep((s)/1000)
#	endif
#	ifndef bzero
#		define bzero(a, b) memset(a, 0, b)
#	endif
#else
#	define PATH_SEPARATOR		'/'
#	define SYSTEM_CMD_DELETE	"rm -f"
#	define SYSTEM_CMD_MOVE		"mv"
#	define SYSTEM_CMD_REBOOT	"reboot"
#	define DEFAULT_TEMP_DIR		"/tmp"
#	define CRLF					"\r\n"
#	ifndef MAX_PATH
#		define MAX_PATH 260
#	endif
//#  elif defined(_NNOS)
//#     ifndef strcasecmp
//#        define strcasecmp stricmp
//#     endif
//#     ifndef strncasecmp
//#        define strncasecmp strnicmp
//#     endif
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short i16;
typedef unsigned int u32;

#ifdef BIGENDIAN
typedef struct {
	u32 h;
	u32 l;
} u64;
#else
typedef struct {
	u32 l;
	u32 h;
} u64;
#endif

#endif //_SS_DEF_H_
