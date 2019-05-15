#ifndef _LB_VIDEO_H
#define _LB_VIDEO_H
#include "lb_headdef.h"

LB_BEGIN_DECL

/* 对方视频显示窗口初始化
*/
LB_EXPORT int lb_video_initial(void *wndHandle);

LB_EXPORT int lb_video_destroy(void);

/* 本地视频预览窗口初始化
*/
LB_EXPORT int lb_localVideo_preview_initial(void *previewWin_hwnd);

/* 多摄像头本地窗口初始化
*/
LB_EXPORT int lb_localMultiVideo_initial(void *previewHwnd, int preIndex);

/* 多摄像头显示对方窗口初始化
*/
LB_EXPORT int lb_remote_multiVideo_initial(void *rmtHwnd, int rmtIndex);

/* 设置onvif功能摄像头参数
*  Setting onvif camera parameters
*/
LB_EXPORT int lb_video_set_onvif_param(int width, int height);

/*获取当前通话是否发送本地视频
*/
LB_EXPORT BOOL lb_video_isSupportVideoTx(void);

/*获取要显示对方视频的窗口大小
*/
LB_EXPORT int lb_video_get_remote_videoSize(int *w, int *h);

/*刷新显示
*/
LB_EXPORT int lb_video_remoteVideoDisplay_refresh(void *wndHandle);

/*刷新捕捉
*/
LB_EXPORT int lb_video_localVideoCap_refresh(void);

/*查询当前对方视频是否激活的
*/
LB_EXPORT BOOL lb_video_remoteVideo_isActive(void);

/* 多方通话视频初始化
*/
LB_EXPORT int lb_video_multiTalkVideo_initial(void *wndHandle, void *previewWin_hwnd);

/* 视频会议初始化
*/
LB_EXPORT int lb_video_session_initial(int *hwndList, int hwndCount, void *previewWin_hwnd);

/*  视频窗口背景设置，在没有视频流的时候会显示该背景图片
*/
LB_EXPORT int lb_video_wndBkg_set(char *localWnd_file, char *rmtWnd_file);

LB_END_DECL
#endif