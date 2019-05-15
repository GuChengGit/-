
#ifndef _SS_INI_CONFIG_H_
#define _SS_INI_CONFIG_H_
#include "ss_base/ss_def.h"
#include "ss_base/ss_list.h"


typedef struct _IniConfig IniConfig;

typedef struct _IniItem{
	char *key;
	char *value;
	BOOL isChanged;
	BOOL isLocalChanged;
} IniItem;

typedef struct _IniSection{
	char *name;
	MSList *items;
} IniSection;

struct _IniConfig{
	char *filename;
	MSList *sections;
};

SS_API IniConfig * ini_config_new(const char *filename);
SS_API IniConfig * ini_config_new_withreboot(const char *filename,BOOL isNeedReboot,BOOL *isChanged);

SS_API IniSection *ini_config_find_section(IniConfig *iniconfig, const char *name);

SS_API const char *ini_config_get_string(IniConfig *iniconfig, const char *section, const char *key, const char *default_string);
SS_API void ini_config_set_string(IniConfig *iniconfig,const char *section, const char *key, const char *value);

SS_API int ini_config_get_int(IniConfig *iniconfig,const char *section, const char *key, int default_value);
SS_API void ini_config_set_int(IniConfig *iniconfig,const char *section, const char *key, int value);

SS_API BOOL ini_config_get_bool(IniConfig *iniconfig,const char *section, const char *key, BOOL default_value);
SS_API void ini_config_set_bool(IniConfig *iniconfig,const char *section, const char *key, BOOL value);

SS_API MSList * ini_config_get_string_list(IniConfig *iniconfig, const char *section, const char *key, const char *defaultStringListStr,const char *divider);
SS_API void ini_config_set_string_list(IniConfig *iniconfig, const char *section, const char *key, const MSList *msList,const char *divider);

SS_API int ini_config_sync(IniConfig *iniconfig);
SS_API int ini_config_sync_withregcheck(IniConfig *iniconfig,BOOL isCheckReg);

SS_API int ini_config_has_section(IniConfig *iniconfig, const char *section);
SS_API void ini_config_clean_section(IniConfig *iniconfig, const char *section);
SS_API void ini_config_destroy(IniConfig *cfg);
SS_API char* ini_config_to_string(IniConfig *iniconfig);

SS_API IniConfig * ini_config_from_string(const char *str);
SS_API BOOL ini_config_checkbackup(const char *filename);
SS_API BOOL ini_config_md5ok(const char *configFile);
#endif //_SS_INI_CONFIG_H_
