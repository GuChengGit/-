#ifndef __LB_VIDEO_CAPS_H__
#define __LB_VIDEO_CAPS_H__

#include "LB_Video.h"

/*
*	����ͷ��֧�ֵ�����
*/
typedef struct lb_cap_dev_property
{
	int resolution_w;	//�ֱ���
	int resolution_h;	
	int fps_min;		//֡��
	int fps_max;
	lb_video_frame_type type;		//����
	void * property_var;	//����ϵ��
}lb_cap_dev_property;

/*
*	����ͷ��Ϣ
*/
typedef struct lb_cap_dev_info
{
	char name[256];			//����ͷ����
	char sub_name[256];

	lb_cap_dev_property * property;		//����ͷ���ܣ�Ϊ����
	int num;				//��֧�����ܵ�����

	void * info_var;	//����ϵ��
}lb_cap_dev_info;

/*
*	����ͷ���ܳ�ʼ����һ�������������һ�ξ���
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_init();

/*
*	����ͷ��������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_destroy();

/*
*	����ˢ�¶�ȡ����ͷ�豸�������USB����ͷ�����øú���
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_refresh();

/*
*	��ȡ����ͷ����
*	[return]����ͷ����
*/
LB_VIDEO_API int lb_videocap_get_dev_count();

/*
*	������������ȡ����Ӧ������ͷ��Ϣ
*	[@1]Ϊ����ֵ������С��lb_videocap_get_dev_count()
*	[@2]Ϊһ������ͷ��Ϣ�����������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_get_dev_info(int index, lb_cap_dev_info ** info);

/*
*	ѡ������ͷ�Լ�����
*	[@1]����ͷ����
*	[@2]����ͷ����������������lb_cap_dev_info�г�Աproperty
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_sel_cap(const char * name, int property_index, int fps);

/*
*	��ȡѡ�������ͷһЩ����,δʵ�֣��ݲ�����
*	[@1]�ֱ��ʿ�
*	[@2]�ֱ��ʸ�
*	[@3]֡����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_get_sel_property(int * res_w, int * res_h, lb_video_frame_type * type);

/*
*	��������ͷ������
*	[@1]����֡�Ļص�����
*	[@2]lb_video_frame_cb�Ĳ���
*	[return]0�ɹ���-1ʧ��
*	ע�����øú���ǰ����ȷ���Ѿ�ѡ�������ͷ�Լ�����
*/
LB_VIDEO_API int lb_videocap_create_stream(lb_video_frame_cb cb, void * userdata);

/*
*	��������ͷ������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_destroy_stream();

/*
*	������
*	[return]0�ɹ���-1ʧ��
*	ע���ú�������ǰ�������lb_videocap_create_stream��
*	���øú���֮�󣬾ͻ���֡�����͵�lb_video_frame_cb����
*/
LB_VIDEO_API int lb_videocap_start_stream();

/*
*	�ر���
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videocap_stop_stream();

#endif /*__LB_VIDEO_CAPS_H__*/