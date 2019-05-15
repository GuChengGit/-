#ifndef LB_PUBLIC_H
#define LB_PUBLIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ss_base/ss_base.h>
#include "lb_headdef.h"
#include "stdio.h"

/* @method �Ƚ������ַ����Ƿ����
* @param *str1 �ַ���1
* @param *str2 �ַ���2
* @return 0 ��ȣ�-1 �����
*/
LB_EXPORT BOOL lb_public_strcmp(char *str1, char *str2);

/* @method �ж��Ƿ���Ч�ַ���
* @param *str �ַ���
* @return 1 ��Ч�ַ�����0 ��Ч�ַ���
*/
LB_EXPORT BOOL lb_public_isValidString(char *str);

/* @method �ַ�������
* @param **dest Ŀ���ַ���
* @param *src   Դ�ַ���
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT BOOL lb_public_strcpy(char **dest, char *src);

#endif