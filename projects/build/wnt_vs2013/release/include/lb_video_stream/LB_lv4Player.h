/**
*    LonBon������ý�岥������̬���ļ�ͷ
*    ˵�����ÿ�Ӧ���ڿ��������������˾����¼���ļ�(lv4�ļ�)
*          �ÿ�һ��ֻ֧�ֲ���һ����Ƶ����֧�ֶ��߳̿���
*/
#ifndef __H_LB_LV4_PUBLIC_API_
#define __H_LB_LV4_PUBLIC_API_
#include "LB_Util.h"

#define FLIP_FLAG_VERTICAL   0x01
#define FLIP_FLAG_HORIZONTAL 0x02
#define FLIP_FLAG_BOTH       (FLIP_FLAG_HORIZONTAL|FLIP_FLAG_VERTICAL)

/**
*    ˵�������ڳ�ʼ�����Ż���
*    ��������
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_init(void);

/**
*    ˵�����������ٲ���������
*    ��������
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_destroy(void);

/**
*    ˵����Ԥ��󶨴����Լ���Ϣ�ص�����
*    ������[@1] hwnd   ���ھ��
*          [@2] cb_msg �ص�������������ֹͣ��������Ϣʱ����øûص�����������ΪNULL
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_preset(void * hwnd, lb_util_msg_cb cb_msg);

/**
*    ˵��������ý���ļ�
*    ������[@1] filename NULL��β��lv4��ý���ļ�·���ַ�����֧�����·��������·��
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_open(const char * filename);

/**
*    ˵������ʼ���Ų���
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_play(void);

/**
*    ˵������ͣ���Ų���
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_pause(void);

/**
*    ˵����ֹͣ���Ų���
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_stop(void);

/**
*    ˵�����رղ��Ų�����
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_close(void);

LB_UTIL_API int lb_lv4player_flip(unsigned int flip_flag);

/**
*    ˵������ȡ��ǰ��Ƶ���ԣ���Ҫ��open����֮��
*    ���أ���Ƶ���ֵ
*/
LB_UTIL_API int lb_lv4player_get_width(void);

/**
*    ˵������ȡ��ǰ��Ƶ���ԣ���Ҫ��open����֮��
*    ���أ���Ƶ�߶�ֵ
*/
LB_UTIL_API int lb_lv4player_get_height(void);

/**
*    ˵������ȡ��ǰ��Ƶ���ԣ���Ҫ��open����֮��
*    ���أ���Ƶ����(��λ����)
*/
LB_UTIL_API int lb_lv4player_get_duration(void);

/**
*    ˵������ȡ��ǰ��Ƶ���ԣ���Ҫ��open����֮��
*    ���أ���ǰ���Ž���(��λ����)
*/
LB_UTIL_API int lb_lv4player_get_currenttime(void);

/**
*    ˵������ת�����Ž���
*    ������[@1] time_of_video ������ʱ��(��λ����)
*    ���أ�0 ��ʾ�ɹ�����0��ʧ��
*/
LB_UTIL_API int lb_lv4player_skip(int time_of_video);

/*
 * ˵����ˢ����Ƶ��,�������������
 * ���أ�0 ��ʾ�ɹ��� ��0ʧ�� 
*/
LB_UTIL_API int lb_lv4player_flush(void);


#endif