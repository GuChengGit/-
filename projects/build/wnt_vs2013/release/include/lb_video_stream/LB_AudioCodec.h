#ifndef __LB_AUDIO_CODEC_H__
#define __LB_AUDIO_CODEC_H__

#include "LB_Audio.h"

/*
*	���������ʼ����һ�������������һ�ξ���
*	[return]0�ɹ���-1ʧ��
*/
LB_AUDIO_API int lb_audiocodec_init();

/*
*	�����������
*	[return]0�ɹ���-1ʧ��
*/
LB_AUDIO_API int lb_audiocodec_destroy();

/*
*	����һ��������
*	[@1]����֡�Ļص�����
*	[@2]lb_audio_frame_cb�Ĳ���
*	[@3]�������Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*/
LB_AUDIO_API int lb_audiocodec_create_decode(lb_audio_frame_cb cb, void * userdata, void ** handle);

/*
*	�رս�����
*	[@1]�������Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_AUDIO_API int lb_audiocodec_close_decode(void * handle);

/*
*	����Ӧ�Ľ�������������ѹ����
*	[@1]����ѹ����
*	[@2]�������Ĳ�����
*	[return]>=0Ϊ�������������֡����������4�����޷�������Ƶ����< 0 ʧ��
*/
LB_AUDIO_API int lb_audiocodec_packet_cb(lb_audio_packet * packet, void * handle);



#endif