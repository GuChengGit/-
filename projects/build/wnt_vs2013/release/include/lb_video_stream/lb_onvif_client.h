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
	//Windows平台用,一般程序开始和结束调用
	LB_ONVIF_API int Onvif_Player_Init();
	LB_ONVIF_API int Onvif_Player_Destroy();
#endif
	/*
	* 说明：初始化ipc配置
	* 参数  [@1]ipcInfo  字符串格式：ip地址,onvif端口,用户名,登录密码,tcp选项
	*		[@2]timeout ipc连接超时时间
	* 返回：0 表示成功， 非0失败,1000表示登录失败,1001表示连接失败
	*/
	LB_ONVIF_API int Onvif_Client_Init(const char* ipcInfo, int timeout, onvif_player_msg_cb cb);
	/*
	* 说明：获取ipc视频通道
	* 返回：通道数量
	*/
	LB_ONVIF_API int Onvif_Client_GetChannels();
	/*
	* 说明：获取通道的分辨率
	* 返回：0 表示成功， 非0失败
	*/
	LB_ONVIF_API int Onvif_Client_GetChannelResolution(int channel, int* width, int* height);
	/*
	* 说明：播放视频
	* 参数	[@1] channel 通道号
	*		[@2] Window  播放图像的窗口句柄
	* 返回：0 表示成功， 非0失败
	*/
	LB_ONVIF_API int Onvif_Client_Play(int channel, void* Window);
	/*
	* 说明：停止播放ipc
	* 返回：0 表示成功， 非0失败
	*/
	LB_ONVIF_API int Onvif_Client_Stop();

	
#ifdef __cplusplus
}
#endif

#endif