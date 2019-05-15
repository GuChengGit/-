#ifndef _LB_HEADDEF_H
#define _LB_HEADDEF_H
#include <stdlib.h>

#define NET_INIT_STEP	"2 step init net"

#if defined(WIN32) || defined(WIN64) || defined(WINCE)

#ifdef _USE_DLL
#define LB_EXPORT __declspec(dllexport)
#else
#define LB_EXPORT 
#endif

#define LB_STDCALL  WINAPI

#elif defined(linux) || defined(__linux) || defined(PJ_ANDROID)
#define LB_EXPORT

#define LB_STDCALL  __attribute__((stdcall))

#ifndef BOOL_DECLARED
#define BOOL_DECLARED
#endif
#endif

typedef int BOOL;

#ifdef __cplusplus
#  define LB_BEGIN_DECL		    extern "C" {
#  define LB_END_DECL		    }
#else
#  define LB_BEGIN_DECL
#  define LB_END_DECL
#endif

#if 0
#define _PRINTF  sprintf
#else
#define _PRINTF printf
#endif


#ifdef LB_ANDROID
#include <android/log.h>
#define LB_DEBUGINFO_PRINT LB_DEBUGINFO_PRINT
#define LB_LOG_INFO LB_LOG_INFO

#else
#define LB_DEBUGINFO_PRINT            
#define LB_LOG_INFO             NULL,  __FILE__, __LINE__,__FUNCTION__
#endif


#define LB_HOS_MAX_MASTER_NUM	600
#define LB_HOS_MAX_SLAVE_NUM	999
#define LB_HOS_SLAVE_CNT		120
#define LB_HOS_VSN_NUM			50
#define LB_HOSPITAL_DATABASE	"lb_hospital.db"
#define LB_PUBLIC_DATABASE		"lb_public.db"


// 数据库版本宏
#ifndef DB_VERSION
#define DB_VERSION(a, b, c) 	(((a) << 16) + ((b) << 8) + (c)) //版本生成宏
#endif

#endif