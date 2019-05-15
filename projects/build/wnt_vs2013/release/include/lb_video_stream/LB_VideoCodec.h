#ifndef __LB_VIDEO_CODEC_H__
#define __LB_VIDEO_CODEC_H__

#include "LB_Video.h"

/*
*	编解码器初始化，一般整个程序调用一次就行
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocodec_init();

/*
*	编解码器销毁
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocodec_destroy();

/*
*	创建一个编码器
*	[@1]帧的类型
*	[@2]帧的分辨率宽
*	[@3]帧的分辨率高
*	[@4]准备编码的类型，暂时只能填VIDEO_CODEC_TYPE_H264
*	[@5]接收数据包的回调函数
*	[@6]lb_video_packet_cb的参数
*	[@7]编码器的操作柄，是输出参数
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocodec_create_encode(lb_video_frame_type frame_type, int width, int height,
	lb_video_codec_type codec_type, lb_video_packet_cb cb, void * userdata, void ** handle);

/*
*	关闭编码器
*	[@1]编码器的操作柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocodec_close_encode(void * handle);

/*
*	往对应的编码器输送帧
*	[@1]帧数据
*	[@2]编码器的操作柄
*	[return]>=0为编码器所缓存的帧个数，超过4个则无法输送帧，< 0失败
*/
LB_VIDEO_API int lb_videocodec_frame_cb(lb_video_frame * frame, void * handle);

/*
*	该函数暂时没实现，不可用
*/
LB_VIDEO_API int lb_videocodec_flush_encode(void * handle);

/*
*	创建一个解码器(暂时只能解h264编码)
*	[@1]接收帧的回调函数
*	[@2]lb_video_frame_cb的参数
*	[@3]解码器的操作柄，是输出参数
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocodec_create_decode(lb_video_frame_cb cb, void * userdata, void ** handle);

/*
*	关闭解码器
*	[@1]解码器的操作柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocodec_close_decode(void * handle);

/*
*	往对应的解码器输送数据包
*	[@1]数据包
*	[@2]解码器的操作柄
*	[return]>=0为解码器所缓存的帧个数，超过4个则无法输送数据包，< 0失败
*/
LB_VIDEO_API int lb_videocodec_packet_cb(lb_video_packet * packet, void * handle);

/*
*	该函数暂时没实现，不可用
*/
LB_VIDEO_API int lb_videocodec_flush_decode(void * handle);

#endif /*__LB_VIDEO_CODEC_H__*/


