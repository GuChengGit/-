#ifndef __LB_VIDEO_CODEC_H__
#define __LB_VIDEO_CODEC_H__

#include "LB_Video.h"

/*
*	���������ʼ����һ�������������һ�ξ���
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocodec_init();

/*
*	�����������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocodec_destroy();

/*
*	����һ��������
*	[@1]֡������
*	[@2]֡�ķֱ��ʿ�
*	[@3]֡�ķֱ��ʸ�
*	[@4]׼����������ͣ���ʱֻ����VIDEO_CODEC_TYPE_H264
*	[@5]�������ݰ��Ļص�����
*	[@6]lb_video_packet_cb�Ĳ���
*	[@7]�������Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocodec_create_encode(lb_video_frame_type frame_type, int width, int height,
	lb_video_codec_type codec_type, lb_video_packet_cb cb, void * userdata, void ** handle);

/*
*	�رձ�����
*	[@1]�������Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocodec_close_encode(void * handle);

/*
*	����Ӧ�ı���������֡
*	[@1]֡����
*	[@2]�������Ĳ�����
*	[return]>=0Ϊ�������������֡����������4�����޷�����֡��< 0ʧ��
*/
LB_VIDEO_API int lb_videocodec_frame_cb(lb_video_frame * frame, void * handle);

/*
*	�ú�����ʱûʵ�֣�������
*/
LB_VIDEO_API int lb_videocodec_flush_encode(void * handle);

/*
*	����һ��������(��ʱֻ�ܽ�h264����)
*	[@1]����֡�Ļص�����
*	[@2]lb_video_frame_cb�Ĳ���
*	[@3]�������Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocodec_create_decode(lb_video_frame_cb cb, void * userdata, void ** handle);

/*
*	�رս�����
*	[@1]�������Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocodec_close_decode(void * handle);

/*
*	����Ӧ�Ľ������������ݰ�
*	[@1]���ݰ�
*	[@2]�������Ĳ�����
*	[return]>=0Ϊ�������������֡����������4�����޷��������ݰ���< 0ʧ��
*/
LB_VIDEO_API int lb_videocodec_packet_cb(lb_video_packet * packet, void * handle);

/*
*	�ú�����ʱûʵ�֣�������
*/
LB_VIDEO_API int lb_videocodec_flush_decode(void * handle);

#endif /*__LB_VIDEO_CODEC_H__*/


