#ifndef __LB_VIDEO_H__
#define __LB_VIDEO_H__

#if defined(_WIN32) || defined(__WIN32__) || \
	defined(WIN32) || defined(PJ_WIN64) || defined(_WIN64) || \
	defined(WIN64)
		#undef LB_WIN32
		#define LB_WIN32 1
#elif defined(linux) || defined(__linux)
		#undef LB_LINUX
		#define LB_LINUX 1
#elif defined(ANDROID)
		#undef LB_ANDROID
		#define LB_ANDROID 1
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif
#endif

#ifdef LB_WIN32
	#ifdef LB_VIDEO_EXPORTS
		#define LB_VIDEO_API EXTERN_C __declspec(dllexport)
	#else
		#define LB_VIDEO_API EXTERN_C __declspec(dllimport)
	#endif
#else
	#ifdef LB_VIDEO_EXPORTS
		#define LB_VIDEO_API EXTERN_C __attribute__((visibility("default")))
	#else
		#define LB_VIDEO_API EXTERN_C
	#endif
#endif

#ifndef LB_WIN32
typedef unsigned long long uint64_t;
#else
typedef unsigned __int64 uint64_t;
#endif

#ifndef uint32_t
typedef unsigned int uint32_t;
#endif

//#define LB_VIDEO_BLUELOVER	1

/*
*	帧所对应的类型
*/
typedef enum lb_video_frame_type
{
	FRAME_TYPE_YUV420P,
	FRAME_TYPE_BGR24,
#ifdef LB_VIDEO_BLUELOVER
	FRAME_TYPE_YUY2,
#endif
}lb_video_frame_type;

/*
*	压缩包对应的类型，
*/
typedef enum lb_video_codec_type
{
	VIDEO_CODEC_TYPE_NONE,
	VIDEO_CODEC_TYPE_H264,
}lb_video_codec_type;

#define FRAME_SIGN_KEY		0x00000001	//可以用该标志设置关键帧
/*
*	原始采集数据帧
*/
typedef struct lb_video_frame
{
	lb_video_frame_type type;	//类型
	int width, height;	//宽高
	void * buf;			//缓冲区
	int len;			//长度
	uint64_t timestamp;	//时间戳
	uint32_t frame_sign;	//标记，保留值
}lb_video_frame;

/*
*	定义获得帧的回调函数，lb_video_frame_cb不可以为阻塞函数，发送的帧不用释放
*/
typedef int(*lb_video_frame_cb)(lb_video_frame * frame, void * userdata);

#define PACKET_SIGN_KEY		0x00000001		//关键帧标记
/*
*	编码后数据包
*/
typedef struct lb_video_packet
{
	lb_video_codec_type type; //编码类型
	void * buf;		//缓冲区
	int len;		//长度
	uint64_t timestamp;	//时间戳
	uint32_t packet_sign;	//标记，保留值
}lb_video_packet;

/*
*	定义获得包的回调函数，lb_video_packet_cb不可以为阻塞函数，发送的包不用释放
*/
typedef int(*lb_video_packet_cb)(lb_video_packet * packet, void * userdata);

/*
*	RTP打印日志函数
*/
typedef void(*lb_log_print_cb)(char * info);

/*
*	RTP日志打印
*	[@1]日志回调函数
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_set_log_print_callback(lb_log_print_cb print_fun);
#endif