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
*	֡����Ӧ������
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
*	ѹ������Ӧ�����ͣ�
*/
typedef enum lb_video_codec_type
{
	VIDEO_CODEC_TYPE_NONE,
	VIDEO_CODEC_TYPE_H264,
}lb_video_codec_type;

#define FRAME_SIGN_KEY		0x00000001	//�����øñ�־���ùؼ�֡
/*
*	ԭʼ�ɼ�����֡
*/
typedef struct lb_video_frame
{
	lb_video_frame_type type;	//����
	int width, height;	//���
	void * buf;			//������
	int len;			//����
	uint64_t timestamp;	//ʱ���
	uint32_t frame_sign;	//��ǣ�����ֵ
}lb_video_frame;

/*
*	������֡�Ļص�������lb_video_frame_cb������Ϊ�������������͵�֡�����ͷ�
*/
typedef int(*lb_video_frame_cb)(lb_video_frame * frame, void * userdata);

#define PACKET_SIGN_KEY		0x00000001		//�ؼ�֡���
/*
*	��������ݰ�
*/
typedef struct lb_video_packet
{
	lb_video_codec_type type; //��������
	void * buf;		//������
	int len;		//����
	uint64_t timestamp;	//ʱ���
	uint32_t packet_sign;	//��ǣ�����ֵ
}lb_video_packet;

/*
*	�����ð��Ļص�������lb_video_packet_cb������Ϊ�������������͵İ������ͷ�
*/
typedef int(*lb_video_packet_cb)(lb_video_packet * packet, void * userdata);

/*
*	RTP��ӡ��־����
*/
typedef void(*lb_log_print_cb)(char * info);

/*
*	RTP��־��ӡ
*	[@1]��־�ص�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_set_log_print_callback(lb_log_print_cb print_fun);
#endif