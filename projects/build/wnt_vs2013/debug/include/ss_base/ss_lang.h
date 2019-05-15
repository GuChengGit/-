#ifndef _SS_LANG_H_
#define _SS_LANG_H_
#include "ss_base/ss_def.h"
#include "ss_base/ss_ini_config.h"

typedef enum{
	LB_LANG_CHINESE_SIMPLIFIED=0,
	LB_LANG_CHINESE_TRADITIONAL,
	LB_LANG_ENGLISH,
	LB_LANG_CZECH
} lb_language_t;

SS_API lb_language_t getLanguageFromIni(IniConfig *iniconfig);

#endif
