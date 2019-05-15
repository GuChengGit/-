#ifndef __LB_RTSP_H__
#define __LB_RTSP_H__

#include "LB_Util.h"
#include "LB_Video.h"
#include "LB_Audio.h"

typedef struct lb_rtsp_context
{
	char input_name[256];
	void * userdata_video;			//视频回调参数
	void * userdata_audio;			//音频回调参数

	lb_util_msg_cb cb_msg;			//消息回调函数

	lb_video_packet_cb cb_video;	//视频回调函数，可为NULL
	lb_audio_packet_cb cb_audio;	//音频回调函数，可为NULL
}lb_rtsp_context;

/*
*	rtsp初始化，一般整个程序调用一次就行
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_init();

/*
*	rtsp销毁
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_destroy();

/*
*	创建一个rtsp接收端
*	[@0]rtsp接收端的操作柄，是输出参数
*	[return]0成功，-1失败
*	注:一个rtsp代表一个线程，如果只需要一个rtsp接收端，则该函数只要初始化一次
*/
LB_UTIL_API int lb_rtsp_create(void ** handle);

/*
*是否开启rtsp音频接收
*/
LB_UTIL_API int lb_rtsp_enableAudio(void * handle, bool enableAudio);

/*
*	关闭rtsp接收端
*	[@1]rtsp接收端的操作柄
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_close(void * handle);

/*
*	设置rtsp接收端环境上下文
*	[@0]rtsp上下文参数
*	[@1]rtsp接收端的操作柄
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_set_context(lb_rtsp_context * cx, void * handle);

/*
*	设置rtsp接收端环境上下文0
*	[@0]rtsp接收端的操作柄
*	[@1]rtsp路径
*	[@2]消息回调函数
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_set_path(void * handle, const char * path, lb_util_msg_cb cb);

/*
*	设置rtsp接收端环境上下文1
*	[@0]rtsp接收端的操作柄
*	[@1]视频接收回调函数
*	[@2]lb_video_packet_cb的参数
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_set_video_packet_cb(void * handle, lb_video_packet_cb cb, void * userdata);

/*
*	设置rtsp接收端环境上下文2
*	[@0]rtsp接收端的操作柄
*	[@1]音频接收回调函数
*	[@2]lb_audio_packet_cb的参数
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_set_audio_packet_cb(void * handle, lb_audio_packet_cb cb, void * userdata);

/*
*	开始接收流
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_open(void * handle);

/*
*	停止接收流
*	[return]0成功，-1失败
*/
LB_UTIL_API int lb_rtsp_stop(void * handle);

#endif