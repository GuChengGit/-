#ifndef _SS_GBK2UTF_H_
#define _SS_GBK2UTF_H_


#include "ss_base/ss_def.h"

SS_API BOOL SS_mByteToWChar(unsigned char *cBuff, unsigned short *wBuff);
SS_API BOOL SS_wCharToMByte(unsigned short *wBuff,unsigned char *cBuff);

#endif