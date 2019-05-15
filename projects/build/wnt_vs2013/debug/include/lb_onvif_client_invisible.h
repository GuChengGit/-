#ifndef LB_ONVIF_CLIENT_INVISIBLE_H
#define LB_ONVIF_CLIENT_INVISIBLE_H


#if defined(__WIN32__) || defined(_WIN32)
#define LB_ONVIF_API  __declspec(dllexport)
#else
#define LB_ONVIF_API
#endif

#define LB_ONVIF_AUTHOR_FAILED	1000
#define LB_ONVIF_CONNECT_FAILED	1001

typedef int (*onvif_player_msg_cb)(void * userdata,unsigned msg);
typedef int (*onvif_player_data_cb)(void * userdata,void * data, unsigned size);


#ifdef __cplusplus
extern "C"
{
#endif
	/*
	* ˵������ʼ��ipc����
	* ����  [@1]ipcInfo  �ַ�����ʽ��ip��ַ,onvif�˿�,�û���,��¼����,tcpѡ��
	*		[@2]timeout ipc���ӳ�ʱʱ��
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��,1000��ʾ��¼ʧ��,1001��ʾ����ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_Init_Inv(const char* ipcInfo, int timeout, onvif_player_msg_cb cb ,void * userdata);
	/*
	* ˵������ȡipc��Ƶͨ��
	* ���أ�ͨ������
	*/
	LB_ONVIF_API int Onvif_Client_GetChannels_Inv();
	/*
	* ˵������ȡͨ���ķֱ���
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_GetChannelResolution_Inv(int channel, int* width, int* height);
	/*
	* ˵����������Ƶ
	* ����	[@1] channel ͨ���ţ�һ��Ϊ1
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_Play_Inv(int channel,onvif_player_data_cb cb,void * userdata);
	/*
	* ˵����ֹͣ����ipc
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_Stop_Inv();

	
#ifdef __cplusplus
}
#endif

#endif