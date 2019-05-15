#ifndef _LB_INI_CONFIG_H
#define _LB_INI_CONFIG_H
#include "comm.h"

int  lb_ini_config_init();
int  lb_ini_config_reinit();
void lb_ini_config_deinit();

const char* lb_ini_config_get_string_value(const char* section,const char *key,const char *default_string);
void lb_ini_config_set_string_value(const char* section,const char *key,const char* value);

int lb_ini_config_get_int_value(const char* section,const char *key, const int default_value);
void lb_ini_config_set_int_value(const char* section,const char *key,const int value);

BOOL lb_ini_config_get_Bool_value(const char* section,const char *key, const BOOL default_value);
void lb_ini_config_set_Bool_value(const char* section,const char *key,const BOOL value);

int lb_ini_config_save_data();

extern IniConfig * iniConfig;

#define STR_SERVERPORT          "SERVERPORT"
#define DEFAULT_SERVERPORT      5160
#define DEFAULT_MASTER_NUM_FOR_MANAGER_SERVER    1

int lb_ini_get_master_num();
const char* lb_ini_get_server_ip();
int lb_ini_get_server_port();

#endif