#ifndef __LB_FILM_SHOW_H__
#define __LB_FILM_SHOW_H__

#ifdef __LB_VIDEO_H__
#include "LB_Video.h"
#endif 

#ifdef __LB_AUDIO_H__
#include "LB_Audio.h"
#endif

#define FILMSHOW_INIT_AUDIO		0x00000010
#define FILMSHOW_INIT_VIDEO		0x00000020

/*
*	����Ƶ��ʾ��ʼ����һ�������������һ�ξ���
*	[@1]��Ƶ��ʾ�����Ĵ��ھ��
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_filmshow_init(unsigned flag);

/*
*	��Ƶ��ʾ�ر�
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_filmshow_destroy();

#ifdef __LB_VIDEO_H__

/*
*	����һ����Ƶ��
*	[@1]��Ƶ��ʾ�Ĳ�����(Ŀǰarg����ֱ����Ϊhwnd)
*	[@2]����1�Ĵ�С����sizeof���У���sizeof(void *)��
*	[@3]��Ƶ���Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videoshow_create(void * arg, int arg_size, void ** handle);

/*
*	�ر���Ƶ��
*	[@1]��Ƶ���Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videoshow_close(void * handle);

#define VIDEOSHOW_FLIP_VERTICAL		0x01
#define VIDEOSHOW_FLIP_HORIZONTAL	0x02
/*
*	������Ƶ��תֵ
*	[@1]��Ƶ���Ĳ�����
*	[@2]��Ƶ��ת,����������VIDEOSHOW_FLIP_�������û�|��
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videoshow_flip(void * handle, unsigned flip);

/*
*	������Ƶ���ı���ͼƬ
*	[@1]��Ƶ���Ĳ�����
*	[@2]����ͼƬ·����
*	[return]0�ɹ���-1ʧ��
*	ע����ʱfileֻ����bmpͼƬ
*/
LB_VIDEO_API int lb_videoshow_set_bk(void * handle, const char * file);

/*
*	ˢ����Ƶ��
*	[@1]��Ƶ���Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videoshow_flush(void * handle);

/*
*	����Ƶ������֡����
*	[@1]֡����
*	[@2]��Ƶ�����
*	[return]>=0Ϊ��Ƶ�������֡����������4�����޷�����֡��< 0ʧ��
*/
LB_VIDEO_API int lb_videoshow_frame_cb(lb_video_frame * frame, void * handle);

#endif

#ifdef __LB_AUDIO_H__

/*
*	����һ·����
*	[@1]�����������Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*/
LB_AUDIO_API int lb_audioshow_create(void ** handle);

/*
*	�ر�һ·����
*	[return]0�ɹ���-1ʧ��
*/
LB_AUDIO_API int lb_audioshow_close(void * handle);

/*
*	����������������֡����
*	[@1]֡����
*	[@2]����������������
*	[return]>=0Ϊ���������������֡����������4�����޷�����֡��< 0ʧ��
*	ע��lb_audio_frame��ʱֻ֧��AUDIO_FRAME_TYPE_S16�������
*/
LB_AUDIO_API int lb_audioshow_frame_cb(lb_audio_frame * frame, void * handle);

/*
*	����ָ��·����
*	[@1]ָ��·�����ΪNULL����ʾ������·����
*	[@2]��һ��ָ��·�����Ĳ����������������������ΪNULL
*	[return]0�ɹ���-1ʧ��
*	ע����*old_handle ΪNULL����ʾ��һ������·������
*/
LB_AUDIO_API int lb_audioshow_sound(void * handle, void ** old_handle);

/*
*	����lv4�ļ��л�����ʱ���³�ʼ��
*	[1]�������ž��
*	[return] 0�ɹ���-1ʧ�ܡ�
*/
LB_AUDIO_API int lb_audioshow_reinitialize(void *handle);

#endif

#endif /*__LB_FILM_SHOW_H__*/