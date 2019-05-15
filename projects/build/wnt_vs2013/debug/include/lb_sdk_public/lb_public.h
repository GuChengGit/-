#ifndef LB_PUBLIC_H
#define LB_PUBLIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ss_base/ss_base.h>
#include "lb_headdef.h"
#include "stdio.h"

/* @method 比较两个字符串是否相等
* @param *str1 字符串1
* @param *str2 字符串2
* @return 0 相等，-1 不相等
*/
LB_EXPORT BOOL lb_public_strcmp(char *str1, char *str2);

/* @method 判断是否有效字符串
* @param *str 字符串
* @return 1 有效字符串，0 无效字符串
*/
LB_EXPORT BOOL lb_public_isValidString(char *str);

/* @method 字符串复制
* @param **dest 目标字符串
* @param *src   源字符串
* @return 0 成功，-1 失败
*/
LB_EXPORT BOOL lb_public_strcpy(char **dest, char *src);

#endif