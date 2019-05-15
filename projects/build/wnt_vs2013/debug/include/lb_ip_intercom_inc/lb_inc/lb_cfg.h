#ifndef _LB_CFG_H
#define _LB_CFG_H
#include "lb_headdef.h"

LB_BEGIN_DECL

/*保存，只有执行该功能，配置值才最终写到文件*/
LB_EXPORT int lb_cfg_save(void);

/*获取字符串类型的配置值
* key：配置关键字
* value：获取的字符串值，需是预先分配好的缓冲区
* bufSize：value缓冲区的大小
* dftValue：默认值，如果在配置文件中没有读取到该项关键字的值，就使用默认值
* 返回：0表示成功，否则失败
*/
LB_EXPORT int lb_cfg_getStrValue(char *key,char *value,int bufSize,char *dftValue);

/*设置字符串类型的配置值
* key：配置关键字
* value：设置值
* 返回：0表示成功，否则失败
*/
LB_EXPORT int lb_cfg_setStrValue(char *key,char *value);

/*获取整型类型的配置值
* key：配置关键字
* dftValue：默认值，如果在配置文件中没有读取到该项关键字的值，就使用默认值
* 返回：返回该项配置值
*/
LB_EXPORT int lb_cfg_getIntValue(char *key,int dftValue);

/*设置整型类型的配置值
* key：配置关键字
* value：设置值
* 返回：0表示成功，否则失败
*/
LB_EXPORT int lb_cfg_setIntValue(char *key,int value);

/*获取布尔类型的配置值
* key：配置关键字
* dftValue：默认值，如果在配置文件中没有读取到该项关键字的值，就使用默认值
* 返回：返回该项配置值
*/
LB_EXPORT BOOL lb_cfg_getBoolValue(char *key,BOOL dftValue);

/*设置布尔类型的配置值
* key：配置关键字
* value：设置值
* 返回：0表示成功，否则失败
*/
LB_EXPORT int lb_cfg_setBoolValue(char *key,BOOL value);

LB_END_DECL
#endif