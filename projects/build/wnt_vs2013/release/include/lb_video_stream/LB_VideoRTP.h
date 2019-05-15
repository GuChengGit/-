#ifndef __LB_VIDEO_RTP_H__
#define __LB_VIDEO_RTP_H__

#include "LB_Video.h"

/*
*	定义获得rtp包的回调函数
*/
typedef int(*lb_rtpdata_cb)(void * data, int len, void * userdata);

/*
*	丢包信息回调函数，
*	lost是一个int [5]的数组指针，len为sizeof(int [5])
*	lost[0]是收到的总的包个数
*	lost[1]是总的丢的包个数
*	lost[2]是当前包序号(unsigned short)
*	lost[3]是上一个包序号(unsigned short)
*	lost[4]指丢失的ssrc
*	注：在出现丢包时，会回调该函数
*/
typedef void(*lb_rtp_lost_cb)(void * lost, int len);

/*
*	标准rtp打包初始化，一般整个程序调用一次就行
*	[return]0成功，-1失败
*	注：与lb_videortp_inner_init不可同用
*/
LB_VIDEO_API int lb_videortp_init();

/*
*	来邦内部rtp打包方式，不是标准格式
*	[return]0成功，-1失败
*	注：整个程序调用一次就行，与lb_videortp_init不可同用，
*	调用组合器的时候，只能启用lb_videortp_create_only_combine函数
*/
LB_VIDEO_API int lb_videortp_inner_init();

/*
*	rtp包转换销毁
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videortp_destroy();

/*
*	获取一个ssrc（实际上得到一个32位随机值）
*	[return]ssrc值
*	注：ssrc为rtp资源识别符，在一个视频流过程中，有且仅有一个ssrc
*/
LB_VIDEO_API unsigned lb_videortp_get_ssrc();

/*
*	创建一个视频压缩包转换成rtp包的转换器
*	[@1]一个rtp包的最大长度(通过设置来控制传输的包的大小)
*	[@2]接收rtp包的回调函数
*	[@3]该rtp包对应的ssrc，（内部rtp打包方式时，该值可以直接填0）
*	[@4]转换器的操作柄，是输出参数
*	[return]0成功，-1失败
*	注：远程发送，rtp_max_size最好不超过MTU(1448)，局域网内部发送，也不要超过UDP最大长度
*/
LB_VIDEO_API int lb_videortp_create_offer(int rtp_max_size, lb_rtpdata_cb cb, void * userdata, unsigned ssrc, void ** handle);

/*
*	关闭转换器
*	[@1]转换器的操作柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videortp_close_offer(void * handle);

/*
*	往转换器中输送视频压缩包
*	[@1]视频压缩数据包(暂时只能是h264格式)
*	[@2]转换器的操作柄
*	[return]0成功，< 0失败
*/
LB_VIDEO_API int lb_videortp_packet_cb(lb_video_packet * packet, void * handle);

/*
*	创建rtp包组合成视频数据包组合器
*	[@1]接收视频数据数据包回调函数
*	[@2]lb_video_packet_cb参数
*	[@3]组合器的操作柄，是输出参数
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videortp_create_combine(lb_video_packet_cb cb, void * userdata, void ** handle);

/*
*	关闭组合器
*	[@1]组合器的操作柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videortp_close_combine(void * handle);

/*
*	将组合器改为只支持组合特定ssrc的rtp包
*	[@1]支持的ssrc
*	[@2]收到特别ssrc所回调的函数，为NULL代表删除该ssrc
*	[@3]所回调的函数参数
*	[@4]更改的组合器句柄
*	[return] 0 为成功，< 0 失败
*	注:调用该函数以后，该组合器就只能针对特定的ssrc组合包了，
*	因此该函数只能是标准rtp打包方式，不可用于公司内部打包方式。
*/
LB_VIDEO_API int lb_videortp_set_map(unsigned ssrc, lb_video_packet_cb cb, void * userdata, void * handle);

/*
*	设置rtp丢失包的统计回调函数
*	[@1]丢包信息回调函数
*	[@2]组合器的操作柄
*	[return]0成功，-1失败
*/
LB_VIDEO_API int lb_videortp_set_lost(lb_rtp_lost_cb cb, void * handle);

/*
*	往组合器中输送rtp包
*	[@1]rtp数据流
*	[@2]rtp数据长度
*	[@3]组合器的操作柄
*	[return]>= 0 成功，< 0失败, (& PACKET_SIGN_KEY)表示关键帧
*/
LB_VIDEO_API int lb_videortp_data_cb(void * data, int len, void * handle);


#endif /*__LB_VIDEO_RTP_H__*/