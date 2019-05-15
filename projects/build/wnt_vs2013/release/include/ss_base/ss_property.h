
#ifndef _SS_PROPERTY_H_
#define _SS_PROPERTY_H_
#include "ss_base/ss_def.h"
#include "ss_base/ss_list.h"

typedef struct _SS_Property {
	char *filename;
	MSList *items;
}SS_Property;

SS_API SS_Property * SS_Property_new(const char *filename);
SS_API SS_Property * SS_Property_new_withreboot(const char *filename,BOOL isNeedReboot,BOOL *isChanged);

SS_API const char *SS_Property_get_string(SS_Property *ss_property, const char *key, const char *default_string);
SS_API void SS_Property_set_string(SS_Property *ss_property,const char *key, const char *value);

SS_API int SS_Property_get_int(SS_Property *ss_property,const char *key, int default_value);
SS_API void SS_Property_set_int(SS_Property *ss_property,const char *key, int value);

SS_API BOOL SS_Property_get_bool(SS_Property *ss_property,const char *key, BOOL default_value);
SS_API void SS_Property_set_bool(SS_Property *ss_property,const char *key, BOOL value);

SS_API MSList * SS_Property_get_string_list(SS_Property *ss_property, const char *key, const char *defaultStringListStr,const char *divider);
SS_API void SS_Property_set_string_list(SS_Property *ss_property, const char *key, const MSList *msList,const char *divider);

SS_API int SS_Property_sync(SS_Property *ss_property);
SS_API void SS_Property_destroy(SS_Property *ss_property);

SS_API char* SS_Property_toString(SS_Property *ss_property);
SS_API int SS_Property_dump(SS_Property *ss_property);
SS_API BOOL SS_Property_md5ok(SS_Property *ss_property);
SS_API BOOL SS_Property_checkbackup(SS_Property *ss_property);
#endif //_SS_PROPERTY_H_
