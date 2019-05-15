package com.lonbon.dc.queueup;

public final class LCDQueueConfig {
//	public final static int MAX_COLUMNS_NUMBER = 10; /* 表的最大列数 */
//	public final static int MAX_COLUMNS_DESC = 32; /* 表头最大字符数 */
//	public final static int MAX_IPADDRESS_LENGTH = 32; /* IP地址（或域名）最大字符数 */

	public static class _LB_INFO_TYPE {
		public final static int LBTYPE_UNKNOW = 0;
		public final static int LBTYPE_MASTER_SCREEN = 1; /* 主屏 */
		public final static int LBTYPE_WINDOW_SCREEN = 2; /* 窗口屏 */
	}

	public static class _LB_INFO_MODEL {
		public final static int LBMODEL_TRIAGE = 0; /* 分诊排队 */
		public final static int LBMODEL_PRISON_VISITING = 1; /* 监狱探访 */
		public final static int LBMODEL_BANK_QUEUE = 2; /* 银行排队 */
		public final static int LBMODEL_INTERCOM = 3; /* 网络对讲 */
	}

	public static class _LB_INFO_DATATYPE {
		public final static int LB_DATATYPE_NONE = -1;
		public final static int LB_DATATYPE_WAITTING = 0;
		public final static int LB_DATATYPE_PASSING = 1;
		public final static int LB_DATATYPE_CALLING = 2;
		public final static int LB_DATATYPE_MESSAGE = 3;
	}

	public static class _LB_INFO_STYLETYPE {
		public final static int LB_STYLETYPE_WITHOUT_VEDIO = 0; // 不带视频
		public final static int LB_STYLETYPE_WITH_VEDIO = 1; // 带视频
	}

//	public final static int BASE_LBSTYLE_UNKNOW = -1;
//	public final static int BASE_LBSTYLE_TRIAGE = 0; /* 分诊排队 */
//	public final static int BASE_LBSTYLE_PRISONVISITING = 100; /* 监狱探访 */
//	public final static int BASE_LBSTYLE_BANKQUEUE = 200; /* 银行排队 */
//	public final static int BASE_LBSTYLE_INTERCOM = 300; /* 网络对讲 */

	public static class _LB_INFO_STYLE {
		
		public final static int LBSTYLE_TRIAGE_MAIN_DISPLAY = 0; /* 分诊排队 主显示屏 */
		public final static int LBSTYLE_TRIAGE_STATISTICS = 1; /* 候诊区统计人数显示 */
		public final static int LBSTYLE_TRIAGE_WAITING = 2; /* 候诊区等待病人显示 */
		public final static int LBSTYLE_TRIAGE_PASSING = 3; /* 候诊区过号病人显示 */
		public final static int LBSTYLE_TRIAGE_CLINIC = 4; /* 分诊排队 诊室窗口显示屏 */
		public final static int LBSTYLE_TRIAGE_DISPENSARY = 5; /* 取药叫号主显示屏 */
		public final static int LBSTYLE_TRIAGE_DISPENSARY_WINDOW = 6; /* 取药叫号窗口屏 */ 
		public final static int LBSTYLE_TRIAGE_INFOMATION = 7; /* 电子信息看板 */
		public final static int LBSTYLE_TRIAGE_SECONDARY_DISPLAY = 8; /*分诊排队候诊区辅显示屏*/
		public final static int LBSTYLE_TRIAGE_WAITING_AND_PASSING = 9; /* 候诊与过号显示 */
		public final static int LBSTYLE_TRIAGE_SECONDARY_DISPLAY2 = 10; /* 分诊－ 候诊区辅显示屏2*/
		public final static int LBSTYLE_TRIAGE_CLINIC2 = 11; /* 分诊－液晶诊室显示屏2 */
		public final static int LBSTYLE_TRIAGE_SECONDARY_DISPLAY3 = 12; /*分诊－候诊区辅显示屏3*/
		public final static int LBSTYLE_TRIAGE_ELEC_PATIENT_GRIDLIST = 13; /*医护一览表*/
		public final static int LBSTYLE_TRIAGE_CLINIC3 = 14; /* 门诊/体检 门诊显示屏*/
		public final static int LBSTYLE_TRIAGE_WAITING_CALLING = 16; /*分诊 - 侯诊区呼叫显示*/
		public final static int LBSTYLE_TRIAGE_WAITING_DISPLAY = 17; /*分诊 - 侯诊区呼叫显示*/
		public final static int LBSTYLE_TRIAGE_DISPENSARY2 = 18; /* 取药叫号主显示屏 */
		public final static int LBSTYLE_TRIAGE_MAIN_DISPLAY2 = 19; /* 门诊-候诊主显示屏2 */
		public final static int LBSTYLE_TRIAGE_DISPENSARY_WINDOW_3 = 20; /* 取药叫号主显示屏3 */ 
		public final static int LBSTYLE_TRIAGE_WAITING_CALLING2 = 21;/*分诊 - 侯诊区呼叫显示屏6*/
//		public final static int LBSTYLE_TRIAGE_CLINIC5 = 21;/*分诊-液晶诊室显示屏5*/
		public final static int LBSTYLE_TRIAGE_SECONDARY_DISPLAY4 = 22; /*门诊/体检 候诊辅显示屏2*/
		public final static int LBSTYLE_TRIAGE_MAIN_DISPLAY3 = 23; /* 门诊/体检 候诊主显示屏2 */
		public final static int LBSTYLE_TRIAGE_CLINIC4 = 25; /* 门诊/体检 门诊显示屏2*/
		public final static int LBSTYLE_TRIAGE_CLINIC6 = 26; /* 门诊/体检 诊室显示屏2*/
		public final static int LBSTYLE_TRIAGE_CLINIC7 = 27; /* 门诊/体检 诊室显示屏3*/
		public final static int LBSTYLE_TRAIGE_INFODISPLAY=29;/*信息发布系统客户端*/
		public final static int LBSTYLE_TRIAGE_DISPENSARY5 = 30; /*取药叫号等候显示屏2*/
		public final static int LBSTYLE_TRIAGE_PASSDISPENSARY = 31; /*取药过号显示屏*/
        public final static int LBSTYLE_TRIAGE_CLINIC3_NEW = 34; /* 门诊/体检 门诊显示屏*/
        public final static int LBSTYLE_TRIAGE_SURGICAL_ULLETIN = 35; /* 门诊/体检 手术公告显示屏*/
        public final static int LBSTYLE_TRIAGE_CONSULTING_ROOM = 36; /* 门诊/体检 诊室叫号屏*/
        public final static int LBSTYLE_TRIAGE_SCREEN_DISPLAY = 37; /* 门诊/体检 诊室叫号屏*/
        public final static int LBSTYLE_TRIAGE_SIGN_DISPLAY = 38; /* 门诊/体检 扫码签到显示屏*/
		public final static int LBSTYLE_TRIAGE_CLINIC10 = 39;     /*  门诊/体检- 诊室显示屏5*/


		public final static int LBSTYLE_PRISONVISITING_CALLING = 100; /* 监狱探访呼叫信息 */
		public final static int LBSTYLE_VISIT_DISPLAY = 102; /* 监狱探访呼叫信息2 */
		public final static int LBSTYLE_BANKQUEUE_CALLING = 200; /* 银行主屏呼叫信息 */
		public final static int LBSTYLE_BANKQUEUE_CALLING_WINDOW1 = 201; /* 银行窗口呼叫信息1 */
		public final static int LBSTYLE_BANKQUEUE_CALLING_WINDOW2 = 202; /* 银行窗口呼叫信息2 */
		public final static int LBSTYLE_BANKQUEUE_SERVICE_WINDOW = 203; /* 银行主屏呼叫2 */
		public final static int LBSTYLE_BANKQUEUE_CALLING_WINDOW3 = 204; /* 银行窗口呼叫信息1(条形屏) */
		public final static int LBSTYLE_BANKQUEUE_CALLING_WINDOW4 = 206; /* 银行窗口显示屏3 */
		public final static int LBSTYLE_INTERCOM_CALLING = 300; /* 网络对讲走廊显示屏 */
		public final static int LBSTYLE_INTERCOM_SENTRY_CALLING = 301; /* 网络对讲岗亭显示屏 */
		public final static int LBSTYLE_INTERCOM_BAR = 304; /* 走廊显示屏(条形屏) */
		public final static int LBSTYLE_INTERCOM_DEVICESTATE_DISPLAY = 305; /* 设备信息状态一览表 */
		/* 带视频*/
		public final static int LBSTYLE_VEDIO_TRIAGE_MAIN_DISPLAY = 1000; /* 分诊排队 主显示屏 */ 
		public final static int LBSTYLE_VEDIO_TRIAGE_CLINIC = 1004; /* 分诊排队 诊室窗口显示屏 */
		public final static int LBSTYLE_VEDIO_TRIAGE_DISPENSARY = 1005; /* 取药叫号主显示屏 */
		public final static int LBSTYLE_VEDIO_TRIAGE_DISPENSARY_WINDOW = 1006; /* 取药叫号窗口屏 */
		public final static int LBSTYLE_VEDIO_TRIAGE_INFOMATION = 1007; /* 电子信息看板 */  
		public final static int LBSTYLE_VEDIO_TRIAGE_SECONDARY_DISPLAY = 1008; /*分诊排队候诊区辅显示屏*/
		public final static int LBSTYLE_VEDIO_TRIAGE_SECONDARY_DISPLAY2 = 1010; /* 分诊－ 候诊区辅显示屏2*/
		public final static int LBSTYLE_VEDIO_TRIAGE_CLINIC2 = 1011; /* 分诊－液晶诊室显示屏2 */
		public final static int LBSTYLE_VEDIO_TRIAGE_SECONDARY_DISPLAY3 = 1012; /*分诊－候诊区辅显示屏3*/
		public final static int LBSTYLE_VEDIO_TRIAGE_PATIENT_GRIDLIST = 1013; /*医护一览表*/
		public final static int LBSTYLE_VEDIO_PRISONVISITING_CALLING = 1100; /* 监狱探访呼叫信息 */
		public final static int LBSTYLE_VEDIO_BANKQUEUE_CALLING = 1200; /* 银行主屏呼叫信息 */
		public final static int LBSTYLE_VEDIO_BANKQUEUE_CALLING_WINDOW = 1201; /* 银行窗口呼叫信息 */
		public final static int LBSTYLE_VEDIO_BANKQUEUE_CALLING_WINDOW2 = 1204; /* 银行窗口呼叫信息(条形屏) */
		public final static int LBSTYLE_VEDIO_INTERCOM_CALLING = 1300; /* 网络对讲走廊显示屏 */
		public final static int LBSTYLE_VEDIO_INTERCOM_SENTRY_CALLING = 1301; /* 网络对讲岗亭显示屏 */
	}

	/* 定义模板 */
LBFIELD_NUMBER +LBFIELD_NAME +LBFIELD_DEPARTMENT +LBFIELD_TYPE +LBFIELD_ROOM_CODE +LBINDEX_ROOM_NAME+LBINDEX_DEPARTMENT_DOCTOR + LBFIELD_WAIT_DESCRIPTION 
	public final static int LBFIELD_NUMBER = 1 << 0; /* 号码 1*/   --票号  
	public final static int LBFIELD_NAME = 1 << 1; /* 姓名 2*/
	public final static int LBFIELD_DEPARTMENT = 1 << 2; /* 科室 4*/
	public final static int LBFILED_PRISON_SECTION= 1 << 3; /* 监区 8*/
	public final static int LBFIELD_TYPE = 1 << 4; /* 门诊类别 16*/
	public final static int LBFILED_DOCTOR= 1 << 5; /* 医生 32*/
	public final static int LBFIELD_FAMILY = 1 << 6; /* 家属 64*/
	public final static int LBFIELD_ROOM_CODE = 1 << 7; /* 诊室编号 128*/
	public final static int LBFIELD_WINDOW = 1 << 8; /* 窗口 256*/
	public final static int LBFIELD_STATE = 1 << 9; /* 状态 512*/
	public final static int LBFILED_DESCRIPTION= 1 << 10; /* 备注 1024*/
	public final static int LBFIELD_WAITING_PATIENT = 1 << 11; /* 等待人员 2048*/
	public final static int LBFIELD_WAITING_COUNT = 1 << 12; /* 等待人数 4096*/
	public final static int LBFIELD_MESSAGE = 1 << 13; /* 信息 8192*/
	public final static int LBFIELD_SENTRY_STATE = 1 << 14; /* 状态--- 岗亭显示屏 16384*/
	public final static int LBFIELD_PRISONER = 1 << 15; /* 犯人 32768*/
	public final static int LBFIELD_TITLES = 1 << 16; /* 职称 65536*/
	public final static int LBFIELD_TOBEPATIENT_NUMBER = 1 << 17; /* 待诊票号 131072*/   ----等待票号
	public final static int LBFIELD_DEPARTMENT_DOCTOR= 1 << 18;	/*科室医生 262144 */
	public final static int LBFILED_ROOM_NMAE= 1 << 19;	/*诊室名称 524288*/
	public final static int LBFIELD_WAIT_DESCRIPTION = 1 << 20; /*等待备注 1048576*/
	public final static int LBFIELD_INITSCREEN = 1 << 23; /*初始化显示屏，0表示不初始化，1表示初始化 8388608*/
    public final static int LBFIELD_OPERATIONROOM= 1 << 24; /*手术间 16777216*/
    public final static int LBFIELD_TIME = 1 << 25; /*时间 33554432*/
    public final static int LBFIELD_OPERATIVENAME = 1 << 26; /*手术名称 67108864*/
    public final static int LBFIELD_LEVEL = 1 << 27; /*等级 134217728*/
    public final static int LBFIELD_ANESTHESIOLOGIST = 1 << 28; /*麻醉医生 268435456*/
    public final static int LBFIELD_LAWYER = 1 << 29; /*律师 536870912*/
    public final static int LBFIELD_MEETING_AREA = 1 << 30; /*会见区 1073741824*/

	
	public final static String Message = "lbmessage"; // 待机消息
	
    public static int OldStyle = 0;     //最初的显示样式
    public static int NewStyle = 1;     //新的显示样式
    public static int NewStyle2 = 2;    //大屏显示样式

    public static String LICENSE = "license";
    public static String ADDRESSIP = "addressIP";
    public static String ZONENUMBER = "zonenumber";
    public static String DEVICENUMBER = "devicenumber";
    public static String MASTERNUMBER = "masternumber";



------------------------------------------------
//代码中的定义：
#define LBFIELD_NUMBER     (1<<0)       //票号
#define LBFIELD_NAME       (1<<1)          //姓名
#define LBFILED_DEPARTMENTS  (1<<2)    //科室
#define LBFILED_PRISON_SECTION  (1<<3)   //监区
#define LBFILED_OUTPATIENT_SERVICE  (1<<4)     //门诊类别
#define LBFILED_DOCTOR    (1<<5)           //医生
#define LBFILED_FAMILY     (1<<6)        //家属
#define LBFIELD_ROOM_CODE  (1<<7)       //诊室编号
#define LBFILED_WINDOW  (1<<8)  //窗口
#define LBFILED_STATE   (1<<9)  //状态
#define LBFILED_DESCRIPTION   (1<<10)     //备注
#define LBFIELD_WAITING_PATIENT   (1<<11)    //等待人员
#define LBFIELD_WAITING_COUNT    (1<<12)    //等待人数
#define LBFIELD_TOBEPATIENT_NUMBER   (1<<17)     //等待票号
#define LBFIELD_DEPARTMENT_DOCTOR    (1<<18)     //科室医生
#define LBFILED_ROOM_NMAE   (1<<19)     //诊室名称
#define LBFILED_WAIT_DESCRIPTION  (1<<20)   //等待备注
#define LBFILED_OPERATION_ROOM (1<<24)   //手术间
#define LBFILED_TIME  (1<<25)   //时间
#define LBFILED_OPERATION_NAME  (1<<26)   //手术名称
#define LBFILED_LEVEL   (1<<27)    //等级
#define LBFILED_ANESTHETIST  (1<<28)   //麻醉医生
}



consultname
 
head_name 
head_width
head_seq

server_directory    //留言后面的
lb_list_title    //诊室后面的
Infoserver_port    //端口后面的