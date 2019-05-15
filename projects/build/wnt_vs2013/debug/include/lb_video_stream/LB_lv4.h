#ifndef __H_LB_LV4__
#define __H_LB_LV4__
#pragma once

#include <stdio.h>
#include "LB_Util.h"
#include "LB_Audio.h"
#include "LB_Video.h"

#ifdef  __H_LB_LV4_PUBLIC_API_
#define LB_INTERNAL_API static
#else
#define LB_INTERNAL_API EXTERN_C __declspec(dllexport)
#endif

typedef unsigned char  uint8;
typedef unsigned short uint16;

#ifdef _ARM_
typedef unsigned long  uint32;
#else
typedef unsigned int   uint32;
#endif

enum lb_lv4_context_status{
	LV4_STATUS_UNUSED,
	LV4_STATUS_UNOPENED,
	LV4_STATUS_READY,
	LV4_STATUS_PLAYING,
	LV4_STATUS_PAUSE
};

enum lb_lv4_propertys{
	LV4_PROPERTY_NULL,
	LV4_PROPERTY_V_WIDTH      = 1,    /* OUT */
	LV4_PROPERTY_V_HEIGHT     = 2,    /* OUT */
	LV4_PROPERTY_TIME_TOTAL   = 4,    /* OUT */
	LV4_PROPERTY_TIME_NOW     = 8,    /* IN_OUT */
	LV4_PROPERTY_PACKET_TOTAL = 16,   /* OUT */
	LV4_PROPERTY_STATUS       = 32    /* OUT */
};
/* should use this sequence strictly */
#define PROPERTYS_NUM 6


typedef struct lb_lv4_context{

	FILE * fp;                //playing file
//should not change the sequence of element
	uint32 ts_start;          //first packet timestamp
	uint32 width;
	uint32 height;
	uint32 time_cnt;          //total time
	uint32 time_now;          //now playing time
	uint32 packet_cnt;        //total packet
	uint32 status;            //playing status

	lb_util_msg_cb cb_msg;    //message callback function

	lb_video_packet_cb video_handle;      //video packet handler
	lb_audio_frame_cb audio_handle;       //audio packet handler
	void * vcodec_handle;
	void * ashow_handle;
	void * vshow_handle;
	void * playthread;

}lb_lv4_context;

#define LV4_HEADER_SIZE           0x50
#define DEVNOLENGTH               8
#define DVR_VIDEO_TYPE_FLIP       0x01

typedef struct lb_lv4_fileheader{
	uint8  ver;
	uint8  reserved0[3];   //align to 4 bytes
	char   dev_no[DEVNOLENGTH];
	char   target_dev_no[DEVNOLENGTH];
	
	int    record_time_year;
	int    record_time_mon;
	int    record_time_date;
	int    record_time_hour;
	int    record_time_min;
	int    record_time_sec;
//Audio info
	uint8  type_audio;
	uint8  reserved1[3];   //align to 4 bytes
	int    sampling_rate;
	uint8  bits_cnt;
	uint8  channel;
	uint8  reserved2[2];   //align to 4 bytes
	int    sampling_size;
//Video info
	uint8  type_video;
	uint8  reserved3[3];   //align to 4 bytes
	int    width;
	int    height;
	float  frame_rate;
	uint32 time_total;
//char reserved[0x50];     //file header are reserved
}lb_lv4_fileheader;

typedef struct lb_lv4_packet{
	uint16 packet_type;    //packet_type : packet type, 0x0000 for audio, 0x6000 for video
	uint16 packet_num;     //packet_num  : packet number,start from 1
	uint32 packet_ts;      //packet_ts   : packet timestamp
	uint32 packet_dsize;   //packet_dsize: packet data size
}lb_lv4_packet;

#define LV4_PAKCET_SIZE (sizeof(lb_lv4_packet))

#define DEFAULT_VIDEO_PACKET_TYPE VIDEO_CODEC_TYPE_H264    /*VIDEO_CODEC_TYPE_H264*/
#define DEFAULT_AUDIO_FRAME_TYPE  AUDIO_FRAME_TYPE_S16    /*AUDIO_FRAME_TYPE_S16*/
#define DEFAULT_AUDIO_CHANNEL     1
#define DEFAULT_AUDIO_SAMPLERATE  16000
#define DEFAULT_AUDIO_SAMPLENUM   2048
#define FILMSHOW_INIT_BOTH (FILMSHOW_INIT_AUDIO|FILMSHOW_INIT_VIDEO)
#define VIDEOSHOW_FLIP_BOTH (VIDEOSHOW_FLIP_HORIZONTAL|VIDEOSHOW_FLIP_VERTICAL)

#ifndef MAX_PLAYER_INSTANCE
#define MAX_PLAYER_INSTANCE       32UL
#endif

/************************************************************************/
/*                         function definition                          */
/************************************************************************/

LB_INTERNAL_API int lb_lv4_init(void);
LB_INTERNAL_API int lb_lv4_destroy(void);
LB_INTERNAL_API int lb_lv4_destroy_without_release(void);

LB_INTERNAL_API int lb_lv4_create(lb_video_packet_cb video_handle, lb_audio_frame_cb audio_handle, void * vcodec_handle, void * ashow_handle);
LB_INTERNAL_API int lb_lv4_release(uint32 ctx_id);

LB_INTERNAL_API int lb_lv4_open(uint32 ctx_id, char * filename);
LB_INTERNAL_API int lb_lv4_play(uint32 ctx_id);
LB_INTERNAL_API int lb_lv4_pause(uint32 ctx_id);
LB_INTERNAL_API int lb_lv4_stop(uint32 ctx_id);
LB_INTERNAL_API int lb_lv4_close(uint32 ctx_id);

LB_INTERNAL_API int lb_lv4_flip_support(uint32 ctx_id, void * vshow);
LB_INTERNAL_API int lb_lv4_flip(uint32 ctx_id, uint32 flip_flag);

LB_INTERNAL_API int lb_lv4_set_msg_cb(uint32 ctx_id, lb_util_msg_cb cb_msg);

LB_INTERNAL_API int lb_lv4_get_property(uint32 ctx_id, uint32 property_flag, void * properties);
/* Only for property:LV4_PROPERTY_TIME_NOW */
LB_INTERNAL_API int lb_lv4_set_property(uint32 ctx_id, uint32 property_flag, void * properties);

#endif