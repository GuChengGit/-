#ifndef _LB_SETTING_H
#define _LB_SETTING_H
#include "lb_headdef.h"

LB_BEGIN_DECL

typedef enum
{
	LBSET_NSALM_LEVEL_DISABLE=0,     //关闭
	LBSET_NSALM_LEVEL_LOW,           //低感度，响应时间长    
	LBSET_NSALM_LEVEL_HIGHTER,       //较高感度
	LBSET_NSALM_LEVEL_HIGHTEST,      //高感度，响应时间短
	LBSET_NSALM_LEVEL_VERYHIGHT,     //特高灵敏度，响应时间最短
} lb_nsAlmLevel_e;

typedef enum{
	LBSET_VOICERING_GENERAL,          //xx主机xx分机
	LBSET_VOICERING_PRISON,           //xx监仓
	LBSET_VOICERING_HSPT_ROOM_BED,    //xx病房xx病床
	LBSET_VOICERING_HSPT_BED,         //xx病床
	LBSET_VOICERING_UNIVERSAL_DESC,   //xx号呼叫
	LBSET_VOICERING_USER_DEFINE,      //xx号呼叫,号码用户自定义    //高级模式的主机才支持，一级主机不支持
	LBSET_VOICERING_SAME_PRIMASTER,   //按一级主机的报号方式播报  //高级模式的主机才支持，一级主机不支持
	LBSET_VOICERING_CLINIC_ROOM,      //xx诊室 
	LBSET_VOICERING_BUILDING_LIFT,    //xx栋xx号电梯
	LBSET_VOICERING_HOSPITAL_TRIAGE,  //xx候诊区xx叫号器
	LBSET_VOICERING_DESCRIPTION,	   //播报描述信息
	LBSET_VOICERING_HSPT_ZONE,		   //xx区xx床
} lb_voiceRing_mode_e;

typedef enum _lb_setting_key
{
	LBSETTING_KEY_DISPLAYNUM,
	LBSETTING_KEY_ADDRMANAGESVR,
	LBSETTING_KEY_EXTNVOL,						//分机音量设置
	LBSETTING_KEY_LAN_CODEC,
	LBSETTING_KEY_WAN_CODEC,
	LBSETTING_KEY_HEADMST,
	LBSETTING_KEY_NOASWUPTRANS_TIME,
	LBSETTING_KEY_REPMST,
	LBSETTING_KEY_EXTN_NSALARM_LVL,
	LBSETTING_KEY_RECORD_PATH,
	LBSETTING_KEY_RECORD_ENA,
	LBSETTING_KEY_EXTNCALLIN_ADPY_MODE,
	LBSETTING_KEY_CRCLISTENTIME,				//循环监听单个分机的时长
	LBSETTING_KEY_MYEXTNCALLOUT_MAXTIME,		//本机直属分机呼叫，无人接听，呼叫的最大时长，超时自动挂断，设为‘0’则一直呼叫，不会自动挂断
	LBSETTING_KEY_TRANS_EXTNINFO_ADTLMST,		//设置上传描述信息和报号信息的附加主机，是指除了上级主机之外的需要本机直属分机信息的主机，可设多个
	LBSETTING_KEY_CALL_ADTLMST,					//设置呼叫的附加主机，是指除了上级主机之外的其他本机直属分机还要呼叫的主机，可设多个
	LBSETTING_KEY_CALL_ADTLMST_DLYTM,			//相比呼叫直属主机，分机延迟多久呼叫附加主机，设为‘0’则同时呼叫
	LBSETTING_KEY_TRIAGE_MSTNUM,
	LBSETTING_KEY_TRIAGE_GROUPNUM,
	LBSETTING_KEY_TRIAGE_DEVNUM,
	LBSETTING_KEY_RECORD_UPLOAD_ENA,			// 录音录像自动上传
	LBSETTING_KEY_RECORD_UPLOAD_SERVERIP,		// 录音录像自动上传服务器IP
	LBSETTING_KEY_RINGMUSIC_NANME,				// 呼入音乐铃声
	LBSETTING_KEY_FORBID_EXTNCALLIN,			// 寻呼状态设置
	LBSETTING_KEY_HIS_ENABLED,					// 是否启用HIS系统连接
	LBSETTING_KEY_HIS_SERVERIP,					// HIS服务器IP
	LBSETTING_KEY_HIS_ZONENUMBER,				// 病区号
	LBSETTING_KEY_DOORLAMPCOLOR,				// 门灯颜色标准
	LBSETTING_KEY_DUTYDOCTOR_PATH,				// 责任医生照片存储路径
	LBSETTING_KEY_DUTYNURSE_PATH,				// 责任护士照片存储路径
	LBSETTING_KEY_CALLONBUSY_TRANS_ENA,         // 遇忙转移功能使能
	LBSETTING_KEY_CALLONBUSY_TRANS_MST,         // 遇忙转移的被叫主机号
	LBSETTING_KEY_CONSULTCALL_MST,              // 设置咨询呼叫主机的号码
	LBSETTING_KEY_LANGUAGE,						// 0-简体中文，1-英文， 2-繁体中文
	LBSETTING_KEY_RING_ONCONN_ENA,              // 在通话中，其他呼叫是否振铃提示
	LBSETTING_KEY_EXTNOFFLN_VNTY_ENA,           // 直属分机掉线，是否语音提示
	LBSETTING_KEY_MYEXTN_TKBELSN_ENA,           // 直属分机与本机或托管主机通话，是否允许高级主机监听,第三方监听
	LBSETTING_KEY_EXTERNALALARM_DESC1,          // 外接报警信号1的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC2,          // 外接报警信号2的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC3,          // 外接报警信号3的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC4,          // 外接报警信号4的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC5,          // 外接报警信号5的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC6,          // 外接报警信号6的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC7,          // 外接报警信号7的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC8,          // 外接报警信号8的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC9,          // 外接报警信号9的描述信息
	LBSETTING_KEY_EXTERNALALARM_DESC10,         // 外接报警信号10的描述信息
	LBSETTING_KEY_VIDEOCLARITY,                 // 视频图像的清晰度，0－普清，1－标清，2－高清
	LBSETTING_KEY_MULTITALKVID_ENA,             //多方通话支持视频
	LBSETTING_KEY_ALARMRINGMUSIC_NAME,			// 报警音乐铃声
	LBSETTING_KEY_RINGINTERNAL_DIS,		    	// 禁止内部振铃及语音播报
	LBSETTING_KEY_DR1OP_TIMEOUTALARM_ENA,		// 门磁1触发，超时报警使能
	LBSETTING_KEY_DR1OP_TIMEOUTALARM_TM,		// 门磁1触发，超时报警超时时长

	LBSETTING_KEY_PLAYFILE_ENA,					//通话中插播文件

	LBSETTING_KEY_FONT_SCREEN_TIME_TYPE,		// 点阵屏显示时间格式 0~4
	LBSETTING_KEY_FONT_SCREEN_PROMPTING,		// 点阵屏提示语
	LBSETTING_KEY_FONT_SCREEN_MODE,				// 点阵屏模式设置 0 - 十字屏（默认）， 1 - 五字屏

    LBSETTING_KEY_SIP_ENABLE,                   // 是否启用标准SIP
    LBSETTING_KEY_SIP_SERVER_ADDRESS,           // 标准SIP服务器IP
    LBSETTING_KEY_SIP_SERVER_PORT,              // 标准SIP服务器端口
    LBSETTING_KEY_SIP_USERNAME,                 // 标准SIP账号用户名
    LBSETTING_KEY_SIP_PASSWORD,                 // 标准SIP账号密码

	LBSETTING_KEY_IPC_ENA,						//设置IPC使能
	LBSETTING_KEY_IPC_ADDRESS,					//设置IPC地址

	LBSETTING_KEY_DOORMACHINE_TITLE,			//门口机标题

    LBSETTING_KEY_SIP_DISPLAY_NAME,              // 标准SIP账号名称
    LBSETTING_KEY_SIP_VID_RX_CLARITY,             // 标准SIP的视频接收清晰度
    LBSETTING_KEY_SIP_VID_TX_CLARITY,             // 标准SIP的视频发送清晰度

	LBSETTING_KEY_EXTDOORLAMP,					  //分机门灯设置

	LBSETTING_KEY_SPK_VOICE_ENA,				 // 在通话中，是否启动喊话广播功能

	LBSETTING_KEY_IPC_CAPTURE_PARAM,             // 第一个IPC采集器的参数
	LBSETTING_KEY_SIP_IPC_CAPTRUE_ENABLE,        // SIP对讲是否采用IPC采集器
} lb_setting_key_e;


LB_EXPORT int lb_setting_set(int key, void *data, int dataSize);

LB_EXPORT int lb_setting_get(int key, void *data, int dataBufSize, int *valSize);

LB_EXPORT int lb_custom_setting_set(const char *key, const char* value);

LB_EXPORT int lb_custom_setting_get(const char *key, char *value, int *len);

LB_END_DECL
#endif