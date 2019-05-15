#ifndef _LB_INITIAL_H
#define _LB_INITIAL_H
#include "lb_headdef.h"
#include "lb_communicate.h"

LB_BEGIN_DECL
typedef enum _lb_runLevel
{
	LB_RUNLVL_PRIMARY=0,
	LB_RUNLVL_SENIOR,
}lb_runLevel;

typedef enum _lb_runMode
{
	LB_RUNMODE_HOSPITAL = 0,
	LB_RUNMODE_PRISON,
}lb_runMode;

LB_EXPORT int lb_ipIntercom_set_runMode(lb_runMode mode);

LB_EXPORT int lb_ipIntercom_init_his(void);

//����չ�ӿ�ֻ֧�ֿ��������������ĸ߼�������Ҳ���� runLvl==LB_RUNLVL_SENIOR�������lb_ipIntercom_start_ext()�ӿڣ�������ͬ��ֻ�ǿ���ָ��UDP�˿ڣ�lb_ipIntercom_start_ext()�ӿ�ʹ�õ���5060�˿�
LB_EXPORT int lb_ipIntercom_start_ext_withUdpPort(lb_runLevel runLvl,char *sn,char *sipAcc,char *sipPwd,unsigned int udpPort,fun_ua2ui_event_ext_callback fun_ext);

//�����lb_ipIntercom_start2()�ӿڣ�������ͬ��ֻ�ǿ���ָ��UDP�˿ڣ�lb_ipIntercom_start2()�ӿ�ʹ�õ���5060�˿�
LB_EXPORT int lb_ipIntercom_start2_withUdpPort(lb_runLevel runLvl,char *sn,char *sipAcc,char *sipPwd,unsigned int udpPort,fun_ua2ui_event_stdcall_callback stdcall_fun);

//��ʼ��֧������������Ϣ
LB_EXPORT int lb_ipIntercom_start2_NetInfo(lb_runLevel runLvl, char *sn, char *sipAcc, char *sipPwd, char *ip,
	char *mac, char *netmask, char *gateway, unsigned int udpPort, fun_ua2ui_event_stdcall_callback stdcall_fun);

LB_EXPORT int lb_ipIntercom_stop(void);

LB_EXPORT int lb_ipIntercom_restoreFactorySettings(void);

//���ù���Ŀ¼·��������ipIntercom���ļ������ڵ�Ŀ¼��Ĭ�ϵ�¼���ļ�Ҳ�������ڸ�Ŀ¼�£���Ҫ����"lb_ipIntercom_start()"�ȳ�ʼ���ӿڵ��á�
LB_EXPORT int lb_ipIntercom_workDirectory_set(char *path);

//��ȡ����Ŀ¼
LB_EXPORT int lb_ipIntercom_workDirectory_get(char *path, int len);

/* ��ʼ��ǰ���ö˿�
* @param netPort ͨ��UDP�˿�(Ĭ��5000)
* @param linkPort �����˿�(Ĭ��5050)
*/
LB_EXPORT int lb_previous_start_set_port(int udpPort, int linkPort);


LB_END_DECL
#endif