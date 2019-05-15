#ifndef __LB_AUDIO_H__
#define __LB_AUDIO_H__

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C extern "C" 
#else
#define EXTERN_C 
#endif
#endif

#ifdef LB_AUDIO_EXPORTS
#define LB_AUDIO_API EXTERN_C __declspec(dllexport)
#else
#define LB_AUDIO_API EXTERN_C __declspec(dllimport)
#endif

/*
*	帧所对应的类型
*/
typedef enum lb_audio_frame_type
{
	AUDIO_FRAME_TYPE_U8,          ///< unsigned 8 bits
	AUDIO_FRAME_TYPE_S16,         ///< signed 16 bits
	AUDIO_FRAME_TYPE_S32,         ///< signed 32 bits
	AUDIO_FRAME_TYPE_FLT,         ///< float
	AUDIO_FRAME_TYPE_DBL,         ///< double

	AUDIO_FRAME_TYPE_U8P,         ///< unsigned 8 bits, planar
	AUDIO_FRAME_TYPE_S16P,        ///< signed 16 bits, planar
	AUDIO_FRAME_TYPE_S32P,        ///< signed 32 bits, planar
	AUDIO_FRAME_TYPE_FLTP,        ///< float, planar
	AUDIO_FRAME_TYPE_DBLP,        ///< double, planar
}lb_audio_frame_type;

/*
*	压缩包对应的类型，
*/
typedef enum lb_audio_codec_type
{
	AUDIO_CODEC_TYPE_NONE,
	AUDIO_CODEC_TYPE_ACC,
}lb_audio_codec_type;

/*
*	原始采集数据帧
*/
typedef struct lb_audio_frame
{
	lb_audio_frame_type type;	//类型
	int channels;			//声道数
	int sample_rate;		//采样率
	int nb_samples;			//样本个数
	void * buf;			//缓冲区
	int len;			//长度
	unsigned __int64 timestamp;	//时间戳
	unsigned frame_sign;	//标记，保留值
}lb_audio_frame;

/*
*	定义获得帧的回调函数，lb_audio_frame_cb不可以为阻塞函数，发送的帧不用释放
*/
typedef int(*lb_audio_frame_cb)(lb_audio_frame * frame, void * userdata);

/*
*	编码后数据包
*/
typedef struct lb_audio_packet
{
	lb_audio_codec_type type;	//包类型
	void * buf;		//缓冲区
	int len;		//长度
	unsigned __int64 timestamp;		//时间戳
	unsigned packet_sign;	//标记，保留值
}lb_audio_packet;

/*
*	定义获得包的回调函数，lb_audio_packet_cb不可以为阻塞函数，发送的数据包不用释放
*/
typedef int(*lb_audio_packet_cb)(lb_audio_packet * packet, void * userdata);

#endif