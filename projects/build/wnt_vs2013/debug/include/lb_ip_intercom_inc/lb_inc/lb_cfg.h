#ifndef _LB_CFG_H
#define _LB_CFG_H
#include "lb_headdef.h"

LB_BEGIN_DECL

/*���棬ֻ��ִ�иù��ܣ�����ֵ������д���ļ�*/
LB_EXPORT int lb_cfg_save(void);

/*��ȡ�ַ������͵�����ֵ
* key�����ùؼ���
* value����ȡ���ַ���ֵ������Ԥ�ȷ���õĻ�����
* bufSize��value�������Ĵ�С
* dftValue��Ĭ��ֵ������������ļ���û�ж�ȡ������ؼ��ֵ�ֵ����ʹ��Ĭ��ֵ
* ���أ�0��ʾ�ɹ�������ʧ��
*/
LB_EXPORT int lb_cfg_getStrValue(char *key,char *value,int bufSize,char *dftValue);

/*�����ַ������͵�����ֵ
* key�����ùؼ���
* value������ֵ
* ���أ�0��ʾ�ɹ�������ʧ��
*/
LB_EXPORT int lb_cfg_setStrValue(char *key,char *value);

/*��ȡ�������͵�����ֵ
* key�����ùؼ���
* dftValue��Ĭ��ֵ������������ļ���û�ж�ȡ������ؼ��ֵ�ֵ����ʹ��Ĭ��ֵ
* ���أ����ظ�������ֵ
*/
LB_EXPORT int lb_cfg_getIntValue(char *key,int dftValue);

/*�����������͵�����ֵ
* key�����ùؼ���
* value������ֵ
* ���أ�0��ʾ�ɹ�������ʧ��
*/
LB_EXPORT int lb_cfg_setIntValue(char *key,int value);

/*��ȡ�������͵�����ֵ
* key�����ùؼ���
* dftValue��Ĭ��ֵ������������ļ���û�ж�ȡ������ؼ��ֵ�ֵ����ʹ��Ĭ��ֵ
* ���أ����ظ�������ֵ
*/
LB_EXPORT BOOL lb_cfg_getBoolValue(char *key,BOOL dftValue);

/*���ò������͵�����ֵ
* key�����ùؼ���
* value������ֵ
* ���أ�0��ʾ�ɹ�������ʧ��
*/
LB_EXPORT int lb_cfg_setBoolValue(char *key,BOOL value);

LB_END_DECL
#endif