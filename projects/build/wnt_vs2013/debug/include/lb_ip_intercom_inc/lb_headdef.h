#ifndef _LB_HEADDEF_H
#define _LB_HEADDEF_H
#include <stdlib.h>

#define _USE_DLL
#define NET_INIT_STEP	"2 step init net"

#if defined(WIN32) || defined(WIN64)
#include <windows.h>

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
typedef int BOOL;
#endif
#endif

#ifdef __cplusplus
#  define LB_BEGIN_DECL		    extern "C" {
#  define LB_END_DECL		    }
#else
#  define LB_BEGIN_DECL
#  define LB_END_DECL
#endif

#endif