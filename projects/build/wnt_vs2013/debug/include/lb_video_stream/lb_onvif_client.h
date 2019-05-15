#ifndef LB_ONVIF_CLIENT_H
#define LB_ONVIF_CLIENT_H

#if defined(__WIN32__) || defined(_WIN32)
#define LB_ONVIF_API  __declspec(dllexport)
#else
#define LB_ONVIF_API
#endif
#define LB_ONVIF_AUTHOR_FAILED	1000
#define LB_ONVIF_CONNECT_FAILED	1001


typedef int(*onvif_player_msg_cb)(unsigned msg);


#ifdef __cplusplus
extern "C"
{
#endif
#if defined(__WIN32__) || defined(_WIN32)
	//Windowsƽ̨��,һ�����ʼ�ͽ�������
	LB_ONVIF_API int Onvif_Player_Init();
	LB_ONVIF_API int Onvif_Player_Destroy();
#endif
	/*
	* ˵������ʼ��ipc����
	* ����  [@1]ipcInfo  �ַ�����ʽ��ip��ַ,onvif�˿�,�û���,��¼����,tcpѡ��
	*		[@2]timeout ipc���ӳ�ʱʱ��
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��,1000��ʾ��¼ʧ��,1001��ʾ����ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_Init(const char* ipcInfo, int timeout, onvif_player_msg_cb cb);
	/*
	* ˵������ȡipc��Ƶͨ��
	* ���أ�ͨ������
	*/
	LB_ONVIF_API int Onvif_Client_GetChannels();
	/*
	* ˵������ȡͨ���ķֱ���
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_GetChannelResolution(int channel, int* width, int* height);
	/*
	* ˵����������Ƶ
	* ����	[@1] channel ͨ����
	*		[@2] Window  ����ͼ��Ĵ��ھ��
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_Play(int channel, void* Window);
	/*
	* ˵����ֹͣ����ipc
	* ���أ�0 ��ʾ�ɹ��� ��0ʧ��
	*/
	LB_ONVIF_API int Onvif_Client_Stop();

	
#ifdef __cplusplus
}
#endif

#endif