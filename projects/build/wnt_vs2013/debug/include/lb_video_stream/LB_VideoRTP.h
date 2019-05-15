#ifndef __LB_VIDEO_RTP_H__
#define __LB_VIDEO_RTP_H__

#include "LB_Video.h"

/*
*	������rtp���Ļص�����
*/
typedef int(*lb_rtpdata_cb)(void * data, int len, void * userdata);

/*
*	������Ϣ�ص�������
*	lost��һ��int [5]������ָ�룬lenΪsizeof(int [5])
*	lost[0]���յ����ܵİ�����
*	lost[1]���ܵĶ��İ�����
*	lost[2]�ǵ�ǰ�����(unsigned short)
*	lost[3]����һ�������(unsigned short)
*	lost[4]ָ��ʧ��ssrc
*	ע���ڳ��ֶ���ʱ����ص��ú���
*/
typedef void(*lb_rtp_lost_cb)(void * lost, int len);

/*
*	��׼rtp�����ʼ����һ�������������һ�ξ���
*	[return]0�ɹ���-1ʧ��
*	ע����lb_videortp_inner_init����ͬ��
*/
LB_VIDEO_API int lb_videortp_init();

/*
*	�����ڲ�rtp�����ʽ�����Ǳ�׼��ʽ
*	[return]0�ɹ���-1ʧ��
*	ע�������������һ�ξ��У���lb_videortp_init����ͬ�ã�
*	�����������ʱ��ֻ������lb_videortp_create_only_combine����
*/
LB_VIDEO_API int lb_videortp_inner_init();

/*
*	rtp��ת������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videortp_destroy();

/*
*	��ȡһ��ssrc��ʵ���ϵõ�һ��32λ���ֵ��
*	[return]ssrcֵ
*	ע��ssrcΪrtp��Դʶ�������һ����Ƶ�������У����ҽ���һ��ssrc
*/
LB_VIDEO_API unsigned lb_videortp_get_ssrc();

/*
*	����һ����Ƶѹ����ת����rtp����ת����
*	[@1]һ��rtp������󳤶�(ͨ�����������ƴ���İ��Ĵ�С)
*	[@2]����rtp���Ļص�����
*	[@3]��rtp����Ӧ��ssrc�����ڲ�rtp�����ʽʱ����ֵ����ֱ����0��
*	[@4]ת�����Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*	ע��Զ�̷��ͣ�rtp_max_size��ò�����MTU(1448)���������ڲ����ͣ�Ҳ��Ҫ����UDP��󳤶�
*/
LB_VIDEO_API int lb_videortp_create_offer(int rtp_max_size, lb_rtpdata_cb cb, void * userdata, unsigned ssrc, void ** handle);

/*
*	�ر�ת����
*	[@1]ת�����Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videortp_close_offer(void * handle);

/*
*	��ת������������Ƶѹ����
*	[@1]��Ƶѹ�����ݰ�(��ʱֻ����h264��ʽ)
*	[@2]ת�����Ĳ�����
*	[return]0�ɹ���< 0ʧ��
*/
LB_VIDEO_API int lb_videortp_packet_cb(lb_video_packet * packet, void * handle);

/*
*	����rtp����ϳ���Ƶ���ݰ������
*	[@1]������Ƶ�������ݰ��ص�����
*	[@2]lb_video_packet_cb����
*	[@3]������Ĳ����������������
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videortp_create_combine(lb_video_packet_cb cb, void * userdata, void ** handle);

/*
*	�ر������
*	[@1]������Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videortp_close_combine(void * handle);

/*
*	���������Ϊֻ֧������ض�ssrc��rtp��
*	[@1]֧�ֵ�ssrc
*	[@2]�յ��ر�ssrc���ص��ĺ�����ΪNULL����ɾ����ssrc
*	[@3]���ص��ĺ�������
*	[@4]���ĵ���������
*	[return] 0 Ϊ�ɹ���< 0 ʧ��
*	ע:���øú����Ժ󣬸��������ֻ������ض���ssrc��ϰ��ˣ�
*	��˸ú���ֻ���Ǳ�׼rtp�����ʽ���������ڹ�˾�ڲ������ʽ��
*/
LB_VIDEO_API int lb_videortp_set_map(unsigned ssrc, lb_video_packet_cb cb, void * userdata, void * handle);

/*
*	����rtp��ʧ����ͳ�ƻص�����
*	[@1]������Ϣ�ص�����
*	[@2]������Ĳ�����
*	[return]0�ɹ���-1ʧ��
*/
LB_VIDEO_API int lb_videortp_set_lost(lb_rtp_lost_cb cb, void * handle);

/*
*	�������������rtp��
*	[@1]rtp������
*	[@2]rtp���ݳ���
*	[@3]������Ĳ�����
*	[return]>= 0 �ɹ���< 0ʧ��, (& PACKET_SIGN_KEY)��ʾ�ؼ�֡
*/
LB_VIDEO_API int lb_videortp_data_cb(void * data, int len, void * handle);


#endif /*__LB_VIDEO_RTP_H__*/