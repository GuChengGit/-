#if defined(__linux__) && !defined(__linux___ARM)
#ifndef _SS_SYSTEM_LINUX_
#define _SS_SYSTEM_LINUX_
#include "ss_base/ss_def.h"

SS_API int linux_create_user(const char* username,const char* password, const int space);
SS_API int linux_modify_user(const char* username,const char* password, const int space);
SS_API int linux_delete_user(const char* username);
#endif //_SS_SYSTEM_LINUX_
#endif
