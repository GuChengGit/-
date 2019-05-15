#ifndef __LB_RTSP_H__
#define __LB_RTSP_H__

#include "LB_Util.h"
#include "LB_Video.h"
#include "LB_Audio.h"

typedef struct lb_rtsp_context
{
	char input_name[256];
	void * userdata_video;			//��Ƶ�ص�����
	void * userdata_audio;			//��Ƶ�ص�����

	lb_util_msg_cb cb_msg;			//��Ϣ�ص�����

	lb_video_packet_cb cb_video;	//��Ƶ�ص���������ΪNULL
	lb_audio_packet_cb cb_audio;	//��Ƶ�ص���������ΪNULL
}lb_rtsp_context;

/*
*	rtsp��ʼ����һ�������������һ�ξ���
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_init();

/*
*	rtsp����
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_destroy();

/*
*	����һ��rtsp���ն�
*	[@0]rtsp���ն˵Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*	ע:һ��rtsp����һ���̣߳����ֻ��Ҫһ��rtsp���նˣ���ú���ֻҪ��ʼ��һ��
*/
LB_UTIL_API int lb_rtsp_create(void ** handle);

/*
*�Ƿ���rtsp��Ƶ����
*/
LB_UTIL_API int lb_rtsp_enableAudio(void * handle, bool enableAudio);

/*
*	�ر�rtsp���ն�
*	[@1]rtsp���ն˵Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_close(void * handle);

/*
*	����rtsp���ն˻���������
*	[@0]rtsp�����Ĳ���
*	[@1]rtsp���ն˵Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_set_context(lb_rtsp_context * cx, void * handle);

/*
*	����rtsp���ն˻���������0
*	[@0]rtsp���ն˵Ĳ�����
*	[@1]rtsp·��
*	[@2]��Ϣ�ص�����
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_set_path(void * handle, const char * path, lb_util_msg_cb cb);

/*
*	����rtsp���ն˻���������1
*	[@0]rtsp���ն˵Ĳ�����
*	[@1]��Ƶ���ջص�����
*	[@2]lb_video_packet_cb�Ĳ���
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_set_video_packet_cb(void * handle, lb_video_packet_cb cb, void * userdata);

/*
*	����rtsp���ն˻���������2
*	[@0]rtsp���ն˵Ĳ�����
*	[@1]��Ƶ���ջص�����
*	[@2]lb_audio_packet_cb�Ĳ���
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_set_audio_packet_cb(void * handle, lb_audio_packet_cb cb, void * userdata);

/*
*	��ʼ������
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_open(void * handle);

/*
*	ֹͣ������
*	[return]0�ɹ���-1ʧ��
*/
LB_UTIL_API int lb_rtsp_stop(void * handle);

#endif