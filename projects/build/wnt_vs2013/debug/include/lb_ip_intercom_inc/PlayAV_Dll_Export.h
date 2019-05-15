

#ifndef __PLAY_AV_DLL_EXPORT_H__
#define __PLAY_AV_DLL_EXPORT_H__

#define LB_EXPORT __declspec(dllexport)

#include "windows.h"


#ifdef __cplusplus
extern "C"
{
#endif

/************************************************************************/
/*              播放接口，以下这些接口一般用于本地播放。                */
/************************************************************************/

/**
* 播放位置通知回调
* 
* usr_data 由lb_avplay_open传进去的参数
* x        位置，范围[0, 1000]
*/
typedef void (*CallBack_OnSetPos)(void * usr_data,int x);

/**
* 播放结束通知回调
* 
* usr_data 由lb_avplay_open传进去的参数
*/
typedef void (*CallBack_OnPlayEnd)(void * usr_data);

/**
* 播放时获得音频数据包的回调接口
* 
* audio_data 音频数据地址
* size       数据长度
*/
typedef void (*CallBack_OnAudioData)(void * audio_data, int size);

/**
* 播放时获得视频数据包的回调接口
* 
* video_data 视频数据地址
* size       数据长度
*/
typedef void (*CallBack_OnVideoData)(void * video_data, int size);




/**
* 打开文件并进行播放
* 
* pszFileName 要播放的文件名
* hVideoWnd   播放视频显示的窗口句柄，视频将在该窗口上显示，大小和该窗口一致。
*             该参数不能为空
* UsrData     给回调时传进的用户自定义数据
* OnSetPos    播放位置通知回调函数
* OnPlayEnd   播放结束通知回调函数
*/
LB_EXPORT BOOL lb_avplay_open(LPCTSTR pszFileName, HWND hVideoWnd, void * UsrData, 
							  CallBack_OnSetPos OnSetPos, 
							  CallBack_OnPlayEnd OnPlayEnd) ;


/**
* 关闭当前播放
* 
*/
LB_EXPORT void lb_avplay_close(void) ;

/**
* 恢复当前播放
* 
*/
LB_EXPORT void lb_avplay_resume() ;

/**
* 暂停当前播放
* 
*/
LB_EXPORT void lb_avplay_pause() ;

/**
* 设置在播放时，获得音频数据包的回调接口
* 
* cb 回调函数
*/
LB_EXPORT void lb_avplay_set_audio_cb(CallBack_OnAudioData cb) ;

/**
* 设置在播放时，获得视频数据包的回调接口
* 
* cb 回调函数
*/
LB_EXPORT void lb_avplay_set_video_cb(CallBack_OnVideoData cb) ;





/************************************************************************/
/*           解码接口，以下这些接口一般用于网络接收并播放。             */
/************************************************************************/

/**
* 视频解码初始化
* 
* hVideoWnd 播放视频显示的窗口句柄，视频将在该窗口上显示，大小和该窗口一致。
*           该参数不能为空
*/
LB_EXPORT int  lb_video_dec_init(HWND hVideoWnd) ;

/**
* 结束当前视频解码，并释放相关资源
* 
*/
LB_EXPORT void lb_video_dec_deinit() ;

/**
* 送视频数据给视频解码器进行解码并播放
* 
* data   视频数据
* length 视频数据长度
*/
LB_EXPORT void lb_video_dec_put_data(void * data, int length) ;


/**
* 音频解码初始化
* 
*/
LB_EXPORT int lb_audio_dec_init() ;

/**
* 结束当前音频解码，并释放相关资源
* 
*/
LB_EXPORT void lb_audio_dec_deinit() ;

/**
* 送音频数据给音频解码器进行解码并播放
* 
* data   音频数据
* length 音频数据长度
*/
LB_EXPORT void lb_audio_dec_put_data(void * data, int length) ;



#ifdef __cplusplus
}
#endif



#endif // __PLAY_AV_DLL_EXPORT_H__





	