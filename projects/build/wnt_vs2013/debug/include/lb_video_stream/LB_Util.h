#ifndef __LB_UTIL_H__
#define __LB_UTIL_H__

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C" 
#else
#define EXTERN_C 
#endif
#endif

#ifdef LB_UTIL_EXPORTS
#define LB_UTIL_API EXTERN_C __declspec(dllexport)
#else
#define LB_UTIL_API EXTERN_C __declspec(dllimport)
#endif

typedef enum lb_util_msg
{
	UTIL_MSG_OK,				//成功
	UTIL_MSG_ERR,				//失败， param1参数有失败的信息,转成char *
	UTIL_MSG_STOP,				//停止
	UTIL_MSG_NOSTREAM,			//没有数据流
	UTIL_MSG_RESOLUTION_SIZE,	//分辨率大小
	UTIL_MSG_VIDEO_CODEC_TYPE,	//视频编码类型，param1为lb_video_codec_type
	UTIL_MSG_AUDIO_CODEC_TYPE,	//音频编码类型，param1为lb_audio_codec_type
}lb_util_msg;

/*
*	定义消息的回调函数，msg为消息值，param1, param2为两个参数值
*/
typedef int(*lb_util_msg_cb)(void * handle, unsigned msg, unsigned param1, unsigned param2);

#endif