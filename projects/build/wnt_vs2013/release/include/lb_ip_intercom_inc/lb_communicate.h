#ifndef _LB_COMMUNICATE_H
#define _LB_COMMUNICATE_H
#include "lb_headdef.h"

LB_BEGIN_DECL
typedef enum _lb_ua2ui_event
{
	LB_UA2UI_NONE=0,

	LB_UA2UI_CALL_PROCESSING,                //呼出处理中
	LB_UA2UI_CALL_RINGBACK,                  //呼出振铃
	LB_UA2UI_CALL_LSTN_CONNECT,              //监听接通
	LB_UA2UI_CALL_TALK_CONNECT,              //对讲接通
	LB_UA2UI_CALL_DISCONNECT,                //通话或呼叫挂断
	LB_UA2UI_CALL_REFUSE,                    //呼出被拒绝
	LB_UA2UI_CALL_BUSY,                      //对方忙
	LB_UA2UI_CALL_FAIL,                      //呼出失败
	LB_UA2UI_CALL_TIMEOUT,                   //呼出超时无响应
	LB_UA2UI_CALL_CALLIN,                    //普通呼入
	LB_UA2UI_CALL_EMERGENCYCALL,             //紧急报警
	LB_UA2UI_CALL_NSALARM,                   //喧哗报警
	LB_UA2UI_CALL_CANCEL,                    //对方取消呼入

	LB_UA2UI_BC_START,                       //广播成功启动
	LB_UA2UI_BC_STOP,                        //广播停止
	LB_UA2UI_BC_NOTALLOW,                    //广播有冲突，不允许启动
	LB_UA2UI_BC_FAIL,                        //广播启动失败
	LB_UA2UI_BC_SPK_PROCESSING,              //喊话广播启动中……
	LB_UA2UI_BC_SPK_START,                   //喊话广播成功启动，可以喊话
	LB_UA2UI_BC_SPK_STOP,                    //喊话广播停止
	LB_UA2UI_BC_SPK_FAIL,                    //喊话广播启动失败
	LB_UA2UI_BC_FILE_PAUSE,                  //文件广播暂停，本地控制暂停，执行成功返回的事件
	LB_UA2UI_BC_FILE_BREAK2PAUSE,            //文件广播临时暂停，因为插话或高级别广播而被迫暂停，可自动恢复
	LB_UA2UI_BC_FILE_PLAY_END,               //文件广播时，一个文件播放结束，即将播放下一个文件
	LB_UA2UI_BC_TRANS2EXTN_START,            //收到其他主机对本机的直属分机广播，本机转发给直属分机
	LB_UA2UI_BC_TRANS2EXTN_STOP,             //转发广播给直属分机结束
	LB_UA2UI_BEBC_START,                     //开始被广播
	LB_UA2UI_BEBC_STOP,                      //停止被广播

	LB_UA2UI_CRCLST_FAIL,                    //循环监听启动失败
	LB_UA2UI_CRCLST_EXTN_START,              //开始监听某一分机
	LB_UA2UI_CRCLST_EXTN_STOP,               //结束监听某一分机
	LB_UA2UI_CRCLST_EXTN_FAIL,               //循环监听某一分机失败，会继续监听下一个分机
	LB_UA2UI_CRCLST_FINISH,                  //循环监听停止

	LB_UA2UI_EXTN_IO_DR1_OPEN,               //分机端门磁1断开提示
	LB_UA2UI_EXTN_IO_DR1_CLOSE,              //分机端门磁1闭合提示
	LB_UA2UI_EXTN_IO_DR2_OPEN,               //分机端门磁2断开提示
	LB_UA2UI_EXTN_IO_DR2_CLOSE,              //分机端门磁2闭合提示

	LB_UA2UI_AGENT_REQUEST,                  //收到代管请求
	LB_UA2UI_AGENT_REQ_CANCLE,               //代管请求取消（已收到请求，尚未应答）
	LB_UA2UI_AGENT_QUIT,                     //收到退出代管请求
	LB_UA2UI_BEAGENTED_REQ_ACCEPTED,         //本机发出代管请求，对方同意代管
	LB_UA2UI_BEAGENTED_REQ_REJECTED,         //本机发出代管请求，对方拒绝代管
	LB_UA2UI_BEAGENTED_REQ_TIMEOUT,          //本机发出代管请求没响应（没有送达或没有应答）
	LB_UA2UI_BEAGENTED_REQ_FAIL,             //本机请求代管失败，可能是没有预设代管机或没有代管机的地址
	LB_UA2UI_BEAGENTED_QUIT,                 //本机退出被代管状态

	LB_UA2UI_SYSTEM_BUSY,                   //当前忙，操作无效
	LB_UA2UI_NETWORK_INIT_FAIL,             //网络初始化失败
	LB_UA2UI_NETWORK_DISCONNECTED,          //网络断开

	LB_UA2UI_EXTN_IO_OPLK1_UNALLOW,         //当前不允许开锁1
	LB_UA2UI_EXTN_IO_OPLK1_SUCC,            //开锁1成功
	LB_UA2UI_EXTN_IO_OPLK1_DISABLE,         //锁1没有启用
	LB_UA2UI_EXTN_IO_OPLK2_UNALLOW,         //当前不允许开锁2
	LB_UA2UI_EXTN_IO_OPLK2_SUCC,            //开锁2成功
	LB_UA2UI_EXTN_IO_OPLK2_DISABLE,         //锁2没有启用

	LB_UA2UI_ADDRQUERY_FINISHED,            //已获取到所需地址信息，界面可以刷新显示的号码列表
	LB_UA2UI_BEMANGED_RFSH_EXTNDSCRBINFO,   //一级主机通知上级主机或托管主机更新它的分机的描述信息
	LB_UA2UI_BEMANGED_EXTNCNT_CHANGED,      //被管的主机的分机个数刷新
	LB_UA2UI_BEMANGED_RFSH_EXTNVOCRGINFO,   //一级主机通知上级主机或托管主机更新它的分机的呼入时的语音播报信息

	LB_UA2UI_NO_AUDIOINPUTDEV,               //没有音频输入设备
	LB_UA2UI_NO_AUDIOOUTPUTDEV,              //没有音频输出设备
	LB_UA2UI_NO_NETCONNECTION,               //没有网络连接
	LB_UA2UI_ADDRLOG_SUCCESS,                //向地址盒登记地址成功

	LB_UA2UI_CALL_ATM_LSTN_SELTER,        //ATM接线盒已经接通，需要选择要监听的终端的终端号，参数为可供选择的终端号列表
	LB_UA2UI_CALL_ATM_TALK_SELTER,        //ATM接线盒已经接通，需要选择要对讲的终端的终端号或者要接听的终端的终端号，参数为可供选择的终端号列表
	LB_UA2UI_CALL_ATM_LSTN_CONNECT,              //监听ATM终端接通
	LB_UA2UI_CALL_ATM_TALK_CONNECT,              //对讲ATM终端接通
	LB_UA2UI_CALL_ATM_DISCONNECT,                //与ATM终端通话或相互呼叫挂断
	LB_UA2UI_CALL_ATM_FAIL,                      //呼叫ATM终端或者接听ATM终端呼叫失败

	LB_UA2UI_ONBUSYCALLINMST_NOTIFY,          //本机在通话过程中，其他主机试图呼叫本机，但是是呼不进来的，这个消息提示这些主机呼叫过
	LB_UA2UI_ONBUSYCALLINATMTER_NOTIFY,       //本机在与某一个ATM接线盒的一个终端通话过程中，该接线盒的其他终端发起呼叫，但是在通话中是呼不到主机的，这个消息提示这些终端正在呼叫

	LB_UA2UI_CALL_PRISONER_ESCAPE,	  //犯人逃跑
	LB_UA2UI_CALL_PRISONER_OUTBREAK,  //犯人暴狱
	LB_UA2UI_CALL_PRISONER_FIGHTS,	  //犯人打架
	LB_UA2UI_CALL_INTRUSION_ATTACK,	  //入侵袭击
	LB_UA2UI_CALL_NATURAL_DISASTER,	  //自然灾害

	LB_UA2UI_EXTN_ONLINE,                //分机在线
	LB_UA2UI_EXTN_OFFLINE,               //分机掉线
	LB_UA2UI_OFFLINENTY_STOP,            //分机掉线的语音提示已经停止
	LB_UA2UI_GROUPDEVINFO_UPDATE,     //排队系统的候诊区号设备号信息有更新
	LB_UA2UI_BC_FILE_PLAY_ADJUST,     //用于调整播放文件，例如上一首，下一首等，成功，就反馈本事件

	LB_UA2UI_BEMANGED_RFSH_PATIENTINFO,		// 医院模数主机通知上级主机或托管主机更新病人信息
	LB_UA2UI_BEMANGED_RFSH_BEDEXTNINFO,		// 一级主机通知上级主机或托管主机更新病人信息

	LB_UA2UI_CALL_INFUSION_ALARM,			 //输液报警
	LB_UA2UI_CALL_INFUSION_ALARM_CAN,		 //输液报警取消
	LB_UA2UI_CALL_REQRINFORCE,				 //请求增援
	LB_UA2UI_CALL_REQRINFORCE_CAN,			 //请求增援取消 

	LB_UA2UI_CALL_TRANS_LISTEN,				 //中转监听
	LB_UA2UI_CALL_TRANS_TALK,				 //中转对讲
	LB_UA2UI_CALL_TRANS_CRCLISTEN,			 //中转循环监听
	LB_UA2UI_CALL_TRANS_CANCEL,				 //上述三种中转停止

	LB_UA2UI_TALK_HOLD_ON,					 //通话保持

	LB_UA2UI_EXTN_ONLINE2OFFLINE,			 //分机由在线变成掉线状态
	LB_UA2UI_ALLEXTN_OFFLINENTY_STOP,		 //所有分机掉线语音提示停止

	LB_UA2UI_UPDATE_PATIENT_INFO_EXTERNAL,	 // 外部更新病人信息
	LB_UA2UI_PATIENT_CHANGE_BED,			 // 病人转床

	LB_UA2UI_GET_ALLEXTNINFO,				 // 开机从地址盒获取所有分机信息或注册本地信息到地址盒上

	LB_UA2UI_ADDRESS_UPDATE_EXTN_INFO,			// 从地址盒更新分机信息
	LB_UA2UI_ADDRESS_UPDATE_PATIENT_INFO,		// 从地址盒更新病人信息
	LB_UA2UI_ADDRESS_UPDATE_DUTY_DOCTOR,		// 从地址盒更新责任医生列表
	LB_UA2UI_ADDRESS_UPDATE_UDTY_NURSE,			// 从地址盒更新责任护士列表

	LB_UA2UI_BEMANGED_CLEAREPORTDATABASE,		//高级主机清空指定主机所有分机的报号信息
	LB_UA2UI_BEMANGED_CLEARDESDATABASE,			//高级主机清空指定主机所有分机的描述信息		

	LB_UA2UI_CALL_RMALARM,					 //防拆报警
	LB_UA2UI_AREAINFO_UPDATE,           //区号信息有更新
	LB_UA2UI_DTMFINPUT_ENA,             //显示DTMF输入键盘
	LB_UA2UI_PLAY_FILE_STOP,            //通话中插播文件播放结束

	LB_UA2UI_EXTN_TALK_OTHER_START,      //分机与其他主机或分机开始通话，该分机的直属主机或高级主机在该分机与其他设备通话开始时会收到该事件
	LB_UA2UI_EXTN_TALK_OTHER_STOP,       //分机与其他主机或分机结束通话，该分机的直属主机或高级主机在该分机与其他设备通话结束时会收到该事件
	LB_UA2UI_EXTN_EXTALARM,              //外接扩展报警
	LB_UA2UI_EXTN_EXTALARM_CANCEL,       //外接扩展报警取消

	LB_UA2UI_MLTK_SPK_PROCESSING,         //多方通话启动，收到就提示喊话广播准备中…，1.5秒钟后提示可以喊话
	LB_UA2UI_MLTK_SPK_OK,           //多方通话,提示可以喊话
	LB_UA2UI_MLTK_SPK_STOP,         //多方通话停止
	LB_UA2UI_MLTK_FAIL,             //多方通话失败
	LB_UA2UI_MLTK_NOTALLOW,         //多方通话有冲突，不允许启动
	LB_UA2UI_MLTK_APPLY_SPK,        //与会者申请发言
	LB_UA2UI_MLTK_APPLY_SPK_CONNECT,      //发言开始
	LB_UA2UI_MLTK_APPLY_SPK_DISCONNECT,   //发言结束
	LB_UA2UI_MLTK_APPLY_SPK_FAIL,         //发言失败，SIP接通失败
	LB_UA2UI_MLTK_WAIT_SPK,               //与会者申请发言,但是已经有其它与会者正在发言，申请失败

	LB_UA2UI_MLTK_BE_CONFERENCE_START,      //参与会议模式开始（与会成员端）
	LB_UA2UI_MLTK_BE_CONDUCT_START,         //参与指挥模式开始（与会成员端）
	LB_UA2UI_MLTK_BE_STOP,                  //多方通话结束（与会成员端）
	LB_UA2UI_MLTK_CLT_APYSPK,               //与会者申请发言（与会成员端）
	LB_UA2UI_MLTK_CLT_APYSPK_CONNECT,       //发言开始（与会成员端）
	LB_UA2UI_MLTK_CLT_APYSPK_DISCONNECT,    //发言结束（与会成员端）
	LB_UA2UI_MLTK_CLT_APYSPK_FAIL,          //发言失败（与会成员端）

	LB_UA2UI_MLTK_VIDEOVIEW_START,          //开始查看某一个与会成员的视频（多方通话发起端）
	LB_UA2UI_MLTK_VIDEOVIEW_STOP,           //停止查看某一个与会成员的视频（多方通话发起端）
	LB_UA2UI_MLTK_VIDEOVIEW_FAIL,           //查看某一个与会成员的视频失败（多方通话发起端）
	LB_UA2UI_MLTK_CLT_VIDEORCV_START,       //开始接收会议发起端的视频（与会成员端）
	LB_UA2UI_MLTK_CLT_VIDEORCV_STOP,        //停止接收会议发起端的视频（与会成员端）

	LB_UA2UI_MLTK_VIDEO_SESSION_START,		//视频会议开始
	LB_UA2UI_MLTK_VIDEO_SESSION_FAIL,		//视频会议失败
	LB_UA2UI_MLTK_VIDEO_SESSION_STOP,		//视频会议结束
	LB_UA2UI_MLTK_VIDEO_WINDOW_PREPARE,        //视频显示窗口创建，反映成员与窗口的对应关系

	LB_UA2UI_EXTN_IO_DR1_OPEN_TIME_OUT,       //分机端门磁1超时提示

	LB_UA2UI_EXTN_IO_INFUSION_JIONUP,		  // 输液报警器插入
	LB_UA2UI_EXTN_IO_INFUSION_PULLOUT,		  // 输液报警器拔出
	LB_UA2UI_EXTN_IO_HEADPHONE_JIONUP,		  // 耳机接入
	LB_UA2UI_EXTN_IO_HEADPHONE_PULLOUT,		  // 耳机拔出

	LB_UA2UI_SIPCALL_PROCESSING,                //呼出处理中
	LB_UA2UI_SIPCALL_RINGBACK,                  //呼出振铃
	LB_UA2UI_SIPCALL_CONNECT,              //对讲接通
	LB_UA2UI_SIPCALL_DISCONNECT,                //通话或呼叫挂断
	LB_UA2UI_SIPCALL_BUSY,                      //对方忙
	LB_UA2UI_SIPCALL_FAIL,                      //呼出失败
	LB_UA2UI_SIPCALL_CALLIN,                    //普通呼入

	LB_UA2UI_SIPREGISTER_FAIL,                //SIP注册失败
	LB_UA2UI_SIPREGISTER_SUCC,                //SIP注册成功
	LB_UA2UI_SIPUNREGISTER_SUCC,              //SIP注销成功

	LB_UA2UI_CALL_ORDERLIES,				  // 呼叫护工
	LB_UA2UI_DRESS,							  // 换药提醒
	LB_UA2UI_BED_LAMP_STATE,				  // 床头灯开关状态
	LB_UA2UI_LOCAL_LAMP_STATE,				  // 手持灯状态
	LB_UA2UI_HAND_VOL_UPANDOWN,				  // 音量加减
	LB_UA2UI_HAND_CHANL_UPANDOWN,			  // 频道加减

	LB_UA2UI_IDENTIFICATION_START,            //开始身份识别
	LB_UA2UI_IDENTIFICATION_STOP,             //退出身份识别

	LB_UA2UI_HAND_OK_UPANDDOWN,					 // 确认键弹起
	LB_UA2UI_HAND_1D2DCODE_DATA,				// 手持扫描到一二维码数据

	LB_UA2UI_EXTN_BACK_LIGHT,				//分机背光
	LB_UA2UI_CASTING_STRING,				//播报字符串

	LB_UA2UI_BEMANGED_CALLIN,                                  // 分机普通呼入时向绑定门口机报告该事件
	LB_UA2UI_BEMANGED_EMG_CALLIN,                              // 分机紧急报警时向绑定门口机报告该事件
	LB_UA2UI_BEMANGED_NOISE_CALLIN,                            // 分机喧哗报警时向绑定门口机报告该事件

	LB_UA2UI_UNMANNED_REACTION,					//无人感应器状态
	LB_UA2UI_EXTERNAL_IO_NOTIFY,				//外部IO口通知

	LB_UA2UI_OCCUPATION_CALL,						//呼叫中(门口机)
	LB_UA2UI_OCCUPATION_CALL_CAN,					//取消呼叫(门口机)
	LB_UA2UI_OCCUPATION_CONNECTING,					//通话中(门口机)
	LB_UA2UI_OCCUPATION_DISCONNECT,					//挂断(门口机)

	LB_UA2UI_BUSY_WAITING,							//对方忙,请等待

	LB_UA2UI_EXTN_TOILET_ALARM,					// 洗手间外接按钮报警
	LB_UA2UI_EXTN_WARDALARM,					// 门口机报警

	LB_UA2UI_PHONE_LOGIN_OK,
	LB_UA2UI_PHONE_LOGIN_FAIL,
	LB_UA2UI_PHONE_LOGOUT_OK,
	LB_UA2UI_PHONE_GETDEVICEINFO_OK,
	LB_UA2UI_PHONE_GETDEVICEINFO_FAIL,

	LB_UA2UI_TEMPERATURE_UPDATE,
	LB_UA2UI_HUMIDITY_UPDATE,
} lb_ua2ui_event_e;

typedef int (*fun_ua2ui_event_callback)(lb_ua2ui_event_e UA2UIEvent,int param1,void *param2);
typedef int (LB_STDCALL *fun_ua2ui_event_ext_callback)(lb_ua2ui_event_e UA2UIEvent, int param1, int areaId, int devRegType, void *param2);
typedef int (LB_STDCALL *fun_ua2ui_event_stdcall_callback)(lb_ua2ui_event_e UA2UIEvent, int param1, void *param2);   //相比于fun_ua2ui_event_callback类型，这个类型申明了调用约定(WINAPI)，可以供C#等使用

LB_END_DECL
#endif