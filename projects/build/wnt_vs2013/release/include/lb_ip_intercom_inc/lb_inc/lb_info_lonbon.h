#ifndef _LB_INFO_LONBON_H
#define _LB_INFO_LONBON_H
#include "lb_headdef.h"
#include "lb_initial.h"
#include "lb_bc.h"
#include "lb_info.h"

LB_BEGIN_DECL

LB_EXPORT int lb_info_getRoomNum_fromExtn(int mstNum, int slaveNum);

// 300、600路获取本地使用页数
LB_EXPORT int lb_info_getLocalExtn_use_page(BOOL *usePage);

LB_END_DECL
#endif
