#ifndef _LB_CALLLOGSAVE_EXT_H
#define _LB_CALLLOGSAVE_EXT_H
#include "lb_headdef.h"
#include "lb_callLogSave.h"

LB_BEGIN_DECL

typedef void (LB_STDCALL *callLogSave_ext_fun)(lb_callLogInfo_s extInfo,int areaNum,int devRegType);
LB_EXPORT int lb_callLogSave_setSaveFun_ext(callLogSave_ext_fun extFun);
LB_END_DECL
#endif