#ifndef _LB_FUN_EXT_H
#define _LB_FUN_EXT_H
#include "lb_headdef.h"

LB_BEGIN_DECL
LB_EXPORT int lb_fun_call_ext(int displayNum,int areaId,int devRegType);
LB_EXPORT int lb_fun_answer_ext(int displayNum,int areaId,int devRegType);
LB_EXPORT int lb_fun_hungup_ext(int displayNum,int areaId,int devRegType);

LB_EXPORT int lb_fun_crcListen_start_ext(int mstDisplayNum,int areaId,int devRegType);
LB_EXPORT int lb_fun_crcListen_stop_ext(int mstDisplayNum,int areaId,int devRegType);

LB_EXPORT int lb_fun_openExtnLock_ext(int displayNum,int areaId,int devRegType,int lock);

LB_EXPORT int lb_fun_notifyCallTransfer_ext(int displayNum,int areaId,int devRegType,int transDestNum);//呼叫转移相关接口 add by Bob 2017-08-03

LB_EXPORT int lb_fun_notifyCallHoldOn_ext(int displayNum, int areaId,int devRegType);

LB_EXPORT int lb_fun_myExtnOffLineVoiceNty_stop_ext(int displayNum, int areaId,int devRegType);

// 从地址盒获取分机信息
LB_EXPORT int lb_fun_hospiatl_getExtnInfo_belongToMaster(int mstNum, int areaId, int devRegType);

LB_END_DECL
#endif