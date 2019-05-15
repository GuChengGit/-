#ifndef __LB_VIDEO_CAPS_H__
#define __LB_VIDEO_CAPS_H__

#include "LB_Video.h"

/*
*	摄像头所支持的性能
*/
typedef struct lb_cap_dev_property
{
	int resolution_w;	//分辨率
	int resolution_h;	
	int fps_min;		//帧率
	int fps_max;
	lb_video_frame_type type;		//类型
	void * property_var;	//其他系数
}lb_cap_dev_property;

/*
*	摄像头信息
*/
typedef struct lb_cap_dev_info
{
	char name[256];			//摄像头名称
	char sub_name[256];

	lb_cap_dev_property * property;		//摄像头性能，为数组
	int num;				//所支持性能的组数

	void * info_var;	//其他系数
}lb_cap_dev_info;

/*
*	摄像头功能初始化，一般整个程序调用一次就行
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_init();

/*
*	摄像头功能销毁
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_destroy();

/*
*	重新刷新读取摄像头设备，当插拔USB摄像头当调用该函数
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_refresh();

/*
*	获取摄像头个数
*	[return]摄像头个数
*/
LB_VIDEO_API int lb_videocap_get_dev_count();

/*
*	依据索引，获取所对应的摄像头信息
*	[@1]为索引值，必须小于lb_videocap_get_dev_count()
*	[@2]为一个摄像头信息，是输出参数
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_get_dev_info(int index, lb_cap_dev_info ** info);

/*
*	选择摄像头以及性能
*	[@1]摄像头名称
*	[@2]摄像头性能索引，可依据lb_cap_dev_info中成员property
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_sel_cap(const char * name, int property_index, int fps);

/*
*	获取选择的摄像头一些参数,未实现，暂不可用
*	[@1]分辨率宽
*	[@2]分辨率高
*	[@3]帧类型
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_get_sel_property(int * res_w, int * res_h, lb_video_frame_type * type);

/*
*	创建摄像头数据流
*	[@1]接收帧的回调函数
*	[@2]lb_video_frame_cb的参数
*	[return]0成功，-1失败
*	注：调用该函数前必须确保已经选择好摄像头以及性能
*/
LB_VIDEO_API int lb_videocap_create_stream(lb_video_frame_cb cb, void * userdata);

/*
*	销毁摄像头数据流
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_destroy_stream();

/*
*	启动流
*	[return]0成功，-1失败
*	注：该函数调用前必须调用lb_videocap_create_stream，
*	调用该函数之后，就会有帧流传送到lb_video_frame_cb里面
*/
LB_VIDEO_API int lb_videocap_start_stream();

/*
*	关闭流
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videocap_stop_stream();

#endif /*__LB_VIDEO_CAPS_H__*/