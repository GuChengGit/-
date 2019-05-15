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
	UTIL_MSG_OK,				//�ɹ�
	UTIL_MSG_ERR,				//ʧ�ܣ� param1������ʧ�ܵ���Ϣ,ת��char *
	UTIL_MSG_STOP,				//ֹͣ
	UTIL_MSG_NOSTREAM,			//û��������
	UTIL_MSG_RESOLUTION_SIZE,	//�ֱ��ʴ�С
	UTIL_MSG_VIDEO_CODEC_TYPE,	//��Ƶ�������ͣ�param1Ϊlb_video_codec_type
	UTIL_MSG_AUDIO_CODEC_TYPE,	//��Ƶ�������ͣ�param1Ϊlb_audio_codec_type
}lb_util_msg;

/*
*	������Ϣ�Ļص�������msgΪ��Ϣֵ��param1, param2Ϊ��������ֵ
*/
typedef int(*lb_util_msg_cb)(void * handle, unsigned msg, unsigned param1, unsigned param2);

#endif