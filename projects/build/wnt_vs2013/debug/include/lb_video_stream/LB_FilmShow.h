#ifndef __LB_FILM_SHOW_H__
#define __LB_FILM_SHOW_H__

#ifdef __LB_VIDEO_H__
#include "LB_Video.h"
#endif 

#ifdef __LB_AUDIO_H__
#include "LB_Audio.h"
#endif

#define FILMSHOW_INIT_AUDIO		0x00000010
#define FILMSHOW_INIT_VIDEO		0x00000020

/*
*	音视频显示初始化，一般整个程序调用一次就行
*	[@1]视频显示依赖的窗口句柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_filmshow_init(unsigned flag);

/*
*	视频显示关闭
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_filmshow_destroy();

#ifdef __LB_VIDEO_H__

/*
*	创建一个视频窗
*	[@1]视频显示的参数，(目前arg可以直接填为hwnd)
*	[@2]参数1的大小，用sizeof就行（例sizeof(void *)）
*	[@3]视频窗的操作柄，是输出参数
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videoshow_create(void * arg, int arg_size, void ** handle);

/*
*	关闭视频窗
*	[@1]视频窗的操作柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videoshow_close(void * handle);

#define VIDEOSHOW_FLIP_VERTICAL		0x01
#define VIDEOSHOW_FLIP_HORIZONTAL	0x02
/*
*	设置视频翻转值
*	[@1]视频窗的操作柄
*	[@2]视频翻转,参数可以是VIDEOSHOW_FLIP_，可以用或‘|’
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videoshow_flip(void * handle, unsigned flip);

/*
*	设置视频窗的背景图片
*	[@1]视频窗的操作柄
*	[@2]背景图片路径名
*	[return]0成功，-1失败
*	注：暂时file只能是bmp图片
*/
LB_VIDEO_API int lb_videoshow_set_bk(void * handle, const char * file);

/*
*	刷新视频窗
*	[@1]视频窗的操作柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videoshow_flush(void * handle);

/*
*	往视频窗输送帧数据
*	[@1]帧数据
*	[@2]视频窗句柄
*	[return]>=0为视频窗缓存的帧个数，超过4个则无法输送帧，< 0失败
*/
LB_VIDEO_API int lb_videoshow_frame_cb(lb_video_frame * frame, void * handle);

#endif

#ifdef __LB_AUDIO_H__

/*
*	创建一路声音
*	[@1]声音播放器的操作柄，是输出参数
*	[return]0成功，-1失败
*/
LB_AUDIO_API int lb_audioshow_create(void ** handle);

/*
*	关闭一路声音
*	[return]0成功，-1失败
*/
LB_AUDIO_API int lb_audioshow_close(void * handle);

/*
*	往声音播放器输送帧数据
*	[@1]帧数据
*	[@2]声音播放器操作柄
*	[return]>=0为声音播放器缓存的帧个数，超过4个则无法输送帧，< 0失败
*	注：lb_audio_frame暂时只支持AUDIO_FRAME_TYPE_S16这个类型
*/
LB_AUDIO_API int lb_audioshow_frame_cb(lb_audio_frame * frame, void * handle);

/*
*	播放指定路声音
*	[@1]指定路句柄，为NULL，表示对所有路静音
*	[@2]上一次指定路声音的操作柄，是输出参数，可设为NULL
*	[return]0成功，-1失败
*	注：若*old_handle 为NULL，表示上一次所有路都静音
*/
LB_AUDIO_API int lb_audioshow_sound(void * handle, void ** old_handle);

/*
*	设置lv4文件切换播放时重新初始化
*	[1]声音播放句柄
*	[return] 0成功，-1失败。
*/
LB_AUDIO_API int lb_audioshow_reinitialize(void *handle);

#endif

#endif /*__LB_FILM_SHOW_H__*/