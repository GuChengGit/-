#ifndef __LB_RTSPPLAYER_H__
#define __LB_RTSPPLAYER_H__

#include "LB_Util.h"

LB_UTIL_API int lb_rtspplayer_init();

LB_UTIL_API int lb_rtspplayer_destroy();

LB_UTIL_API int lb_rtspplayer_preset(void * hwnd, lb_util_msg_cb cb);

LB_UTIL_API int lb_rtspplayer_enableAudio(bool enable);

LB_UTIL_API int lb_rtspplayer_open(const char * path);

LB_UTIL_API int lb_rtspplayer_stop();

#endif
