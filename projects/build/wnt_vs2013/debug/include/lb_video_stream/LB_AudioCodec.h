#ifndef __LB_AUDIO_CODEC_H__
#define __LB_AUDIO_CODEC_H__

#include "LB_Audio.h"

/*
*	编解码器初始化，一般整个程序调用一次就行
*	[return]0成功，-1失败
*/
LB_AUDIO_API int lb_audiocodec_init();

/*
*	编解码器销毁
*	[return]0成功，-1失败
*/
LB_AUDIO_API int lb_audiocodec_destroy();

/*
*	创建一个解码器
*	[@1]接收帧的回调函数
*	[@2]lb_audio_frame_cb的参数
*	[@3]解码器的操作柄，是输出参数
*	[return]0成功，-1失败
*/
LB_AUDIO_API int lb_audiocodec_create_decode(lb_audio_frame_cb cb, void * userdata, void ** handle);

/*
*	关闭解码器
*	[@1]解码器的操作柄
*	[return]0成功，-1失败
*/
LB_AUDIO_API int lb_audiocodec_close_decode(void * handle);

/*
*	往对应的解码器输送语音压缩包
*	[@1]语音压缩包
*	[@2]解码器的操作柄
*	[return]>=0为解码器所缓存的帧个数，超过4个则无法输送音频包，< 0 失败
*/
LB_AUDIO_API int lb_audiocodec_packet_cb(lb_audio_packet * packet, void * handle);



#endif