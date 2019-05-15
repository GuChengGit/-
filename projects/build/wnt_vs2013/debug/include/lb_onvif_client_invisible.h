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
	* 说明：初始化ipc配置
	* 参数  [@1]ipcInfo  字符串格式：ip地址,onvif端口,用户名,登录密码,tcp选项
	*		[@2]timeout ipc连接超时时间
	* 返回：0 表示成功， 非0失败,1000表示登录失败,1001表示连接失败
	*/
	LB_ONVIF_API int Onvif_Client_Init_Inv(const char* ipcInfo, int timeout, onvif_player_msg_cb cb ,void * userdata);
	/*
	* 说明：获取ipc视频通道
	* 返回：通道数量
	*/
	LB_ONVIF_API int Onvif_Client_GetChannels_Inv();
	/*
	* 说明：获取通道的分辨率
	* 返回：0 表示成功， 非0失败
	*/
	LB_ONVIF_API int Onvif_Client_GetChannelResolution_Inv(int channel, int* width, int* height);
	/*
	* 说明：播放视频
	* 参数	[@1] channel 通道号，一般为1
	* 返回：0 表示成功， 非0失败
	*/
	LB_ONVIF_API int Onvif_Client_Play_Inv(int channel,onvif_player_data_cb cb,void * userdata);
	/*
	* 说明：停止播放ipc
	* 返回：0 表示成功， 非0失败
	*/
	LB_ONVIF_API int Onvif_Client_Stop_Inv();

	
#ifdef __cplusplus
}
#endif

#endif