/**
*    LonBon本地流媒体播放器动态库文件头
*    说明：该库应用于开发播放深圳来邦公司自有录像文件(lv4文件)
*          该库一次只支持播放一个视频，不支持多线程控制
*/
#ifndef __H_LB_LV4_PUBLIC_API_
#define __H_LB_LV4_PUBLIC_API_
#include "LB_Util.h"

#define FLIP_FLAG_VERTICAL   0x01
#define FLIP_FLAG_HORIZONTAL 0x02
#define FLIP_FLAG_BOTH       (FLIP_FLAG_HORIZONTAL|FLIP_FLAG_VERTICAL)

/**
*    说明：用于初始化播放环境
*    参数：无
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_init(void);

/**
*    说明：用于销毁播放器内容
*    参数：无
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_destroy(void);

/**
*    说明：预设绑定窗口以及消息回调函数
*    参数：[@1] hwnd   窗口句柄
*          [@2] cb_msg 回调函数，当发生停止，错误信息时会调用该回调函数，可以为NULL
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_preset(void * hwnd, lb_util_msg_cb cb_msg);

/**
*    说明：打开流媒体文件
*    参数：[@1] filename NULL结尾的lv4流媒体文件路径字符串，支持相对路径及绝对路径
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_open(const char * filename);

/**
*    说明：开始播放操作
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_play(void);

/**
*    说明：暂停播放操作
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_pause(void);

/**
*    说明：停止播放操作
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_stop(void);

/**
*    说明：关闭播放操作，
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_close(void);

LB_UTIL_API int lb_lv4player_flip(unsigned int flip_flag);

/**
*    说明：获取当前视频属性，需要在open操作之后
*    返回：视频宽度值
*/
LB_UTIL_API int lb_lv4player_get_width(void);

/**
*    说明：获取当前视频属性，需要在open操作之后
*    返回：视频高度值
*/
LB_UTIL_API int lb_lv4player_get_height(void);

/**
*    说明：获取当前视频属性，需要在open操作之后
*    返回：视频长度(单位毫秒)
*/
LB_UTIL_API int lb_lv4player_get_duration(void);

/**
*    说明：获取当前视频属性，需要在open操作之后
*    返回：当前播放进度(单位毫秒)
*/
LB_UTIL_API int lb_lv4player_get_currenttime(void);

/**
*    说明：跳转到播放进度
*    参数：[@1] time_of_video 跳过的时间(单位毫秒)
*    返回：0 表示成功，非0则失败
*/
LB_UTIL_API int lb_lv4player_skip(int time_of_video);

/*
 * 说明：刷新视频窗,清除解码器缓存
 * 返回：0 表示成功， 非0失败 
*/
LB_UTIL_API int lb_lv4player_flush(void);


#endif