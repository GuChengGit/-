#ifndef _LB_DEVCTR_H
#define _LB_DEVCTR_H
#include "lb_headdef.h"
#if defined(_WIN32_WCE) || defined(WIN32) || defined(__WIN32__) || defined(WIN64)
#include <windows.h>
#endif

LB_BEGIN_DECL

LB_EXPORT int lb_devCtr_getAudioInputDevNameList(char name[][64],int bufCnt,int *devCnt);
LB_EXPORT int lb_devCtr_getActiveAudioInputDevName(char name[],int bufSize);
LB_EXPORT int lb_devCtr_setActiveAudioInputDevName(char name[]);

LB_EXPORT int lb_devCtr_getAudioOutputDevNameList(char name[][64],int bufCnt,int *devCnt);
LB_EXPORT int lb_devCtr_getActiveAudioOutputDevName(char name[],int bufSize);
LB_EXPORT int lb_devCtr_setActiveAudioOutputDevName(char name[]);

LB_EXPORT int lb_devCtr_getNetDevIpList(char ip[][32],int bufCnt,int *ipCnt);
LB_EXPORT int lb_devCtr_getActiveNetDevIp(char ip[],int bufSize);
LB_EXPORT int lb_devCtr_setActiveNetDevIp(char ip[]);

LB_EXPORT int lb_devCtr_set_fullDuplexSupport(BOOL isSpt);    //是否支持全双工
LB_END_DECL
#endif