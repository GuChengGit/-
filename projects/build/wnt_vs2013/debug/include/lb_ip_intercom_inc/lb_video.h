#ifndef _LB_VIDEO_H
#define _LB_VIDEO_H
#include "lb_headdef.h"

LB_BEGIN_DECL

/* �Է���Ƶ��ʾ���ڳ�ʼ��
*/
LB_EXPORT int lb_video_initial(void *wndHandle);

LB_EXPORT int lb_video_destroy(void);

/* ������ƵԤ�����ڳ�ʼ��
*/
LB_EXPORT int lb_localVideo_preview_initial(void *previewWin_hwnd);

/* ������ͷ���ش��ڳ�ʼ��
*/
LB_EXPORT int lb_localMultiVideo_initial(void *previewHwnd, int preIndex);

/* ������ͷ��ʾ�Է����ڳ�ʼ��
*/
LB_EXPORT int lb_remote_multiVideo_initial(void *rmtHwnd, int rmtIndex);

/* ����onvif��������ͷ����
*  Setting onvif camera parameters
*/
LB_EXPORT int lb_video_set_onvif_param(int width, int height);

/*��ȡ��ǰͨ���Ƿ��ͱ�����Ƶ
*/
LB_EXPORT BOOL lb_video_isSupportVideoTx(void);

/*��ȡҪ��ʾ�Է���Ƶ�Ĵ��ڴ�С
*/
LB_EXPORT int lb_video_get_remote_videoSize(int *w, int *h);

/*ˢ����ʾ
*/
LB_EXPORT int lb_video_remoteVideoDisplay_refresh(void *wndHandle);

/*ˢ�²�׽
*/
LB_EXPORT int lb_video_localVideoCap_refresh(void);

/*��ѯ��ǰ�Է���Ƶ�Ƿ񼤻��
*/
LB_EXPORT BOOL lb_video_remoteVideo_isActive(void);

/* �෽ͨ����Ƶ��ʼ��
*/
LB_EXPORT int lb_video_multiTalkVideo_initial(void *wndHandle, void *previewWin_hwnd);

/* ��Ƶ�����ʼ��
*/
LB_EXPORT int lb_video_session_initial(int *hwndList, int hwndCount, void *previewWin_hwnd);

/*  ��Ƶ���ڱ������ã���û����Ƶ����ʱ�����ʾ�ñ���ͼƬ
*/
LB_EXPORT int lb_video_wndBkg_set(char *localWnd_file, char *rmtWnd_file);

LB_END_DECL
#endif