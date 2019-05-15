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

//本扩展接口只支持开发管理多个分区的高级主机，也就是 runLvl==LB_RUNLVL_SENIOR。相比与lb_ipIntercom_start_ext()接口，功能相同，只是可以指定UDP端口，lb_ipIntercom_start_ext()接口使用的是5060端口
LB_EXPORT int lb_ipIntercom_start_ext_withUdpPort(lb_runLevel runLvl,char *sn,char *sipAcc,char *sipPwd,unsigned int udpPort,fun_ua2ui_event_ext_callback fun_ext);

//相比与lb_ipIntercom_start2()接口，功能相同，只是可以指定UDP端口，lb_ipIntercom_start2()接口使用的是5060端口
LB_EXPORT int lb_ipIntercom_start2_withUdpPort(lb_runLevel runLvl,char *sn,char *sipAcc,char *sipPwd,unsigned int udpPort,fun_ua2ui_event_stdcall_callback stdcall_fun);

//初始化支持输入网络信息
LB_EXPORT int lb_ipIntercom_start2_NetInfo(lb_runLevel runLvl, char *sn, char *sipAcc, char *sipPwd, char *ip,
	char *mac, char *netmask, char *gateway, unsigned int udpPort, fun_ua2ui_event_stdcall_callback stdcall_fun);

LB_EXPORT int lb_ipIntercom_stop(void);

LB_EXPORT int lb_ipIntercom_restoreFactorySettings(void);

//设置工作目录路径，即“ipIntercom”文件夹所在的目录，默认的录音文件也会生成在该目录下，需要先于"lb_ipIntercom_start()"等初始化接口调用。
LB_EXPORT int lb_ipIntercom_workDirectory_set(char *path);

//获取工作目录
LB_EXPORT int lb_ipIntercom_workDirectory_get(char *path, int len);

/* 初始化前设置端口
* @param netPort 通用UDP端口(默认5000)
* @param linkPort 联动端口(默认5050)
*/
LB_EXPORT int lb_previous_start_set_port(int udpPort, int linkPort);


LB_END_DECL
#endif