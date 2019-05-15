#ifndef _LB_INFO_H_
#define _LB_INFO_H_
#include "lb_info_data.h"
#include "lb_dashboard.h"
#include "lb_pause_info.h"
#include "lb_func_interface.h"
#include <ss_base/ss_base.h>

#define MAX_COLUMNS_NUMBER				10						/* 表的最大列数*/
#define MAX_COLUMNS_DESC				32						/* 表头最大字符数*/
#define MAX_IPADDRESS_LENGTH			32						/* IP地址（或域名）最大字符数*/


typedef enum _LB_INFO_TYPE{
	LBTYPE_UNKNOW=0,										
	LBTYPE_MASTER_SCREEN,										/*主屏*/
	LBTYPE_WINDOW_SCREEN										/*窗口屏*/
}LB_INFO_TYPE_t;

typedef enum _LB_INFO_MODEL{
	LBMODEL_TRIAGE=0,											/*分诊排队*/
	LBMODEL_PRISON_VISITING,									/*监狱探访*/
	LBMODEL_BANK_QUEUE,											/*银行排队*/
	LBMODEL_INTERCOM,											/*网络对讲*/
}LB_INFO_MODEL_t;

typedef enum _LB_INFO_DATATYPE
{
	LB_DATATYPE_WAITTING,										// 等待信息
	LB_DATATYPE_PASSING,										// 过号信息
	LB_DATATYPE_CALLING,										// 呼叫信息
	LB_DATATYPE_IDLE,											// 待机信息
}_LB_INFO_DATATYPE_t;

#define BASE_LBSTYLE_UNKNOW				-1						
#define BASE_LBSTYLE_TRIAGE				0						/*分诊排队*/	
#define BASE_LBSTYLE_PRISONVISITING		100						/*监狱探访*/
#define BASE_LBSTYLE_BANKQUEUE			200						/*银行排队*/
#define BASE_LBSTYLE_INTERCOM			300						/*网络对讲*/

typedef enum _LB_INFO_STYLE{
	LBSTYLE_TRIAGE_MAIN_DISPLAY = BASE_LBSTYLE_TRIAGE,			/*	分诊排队 主显示屏  */
	LBSTYLE_TRIAGE_STATISTICS,									/*  候诊区统计人数显示 */
	LBSTYLE_TRIAGE_WAITING,										/*  候诊区等待病人显示 */
	LBSTYLE_TRIAGE_PASSING,										/*  候诊区过号病人显示 */
	LBSTYLE_TRIAGE_CLINIC,										/*	分诊排队 诊室窗口显示屏*/
	LBSTYLE_TRIAGE_DISPENSARY,									/*	取药叫号主显示屏   */
	LBSTYLE_TRIAGE_DISPENSARY_WINDOW,							/*	取药叫号窗口屏	   */
	LBSTYLE_TRIAGE_INFOMATION,									/*  电子信息看板	   */
	LBSTYLE_TRIAGE_SECONDARY_DISPLAY,							/*	分诊排队 候诊区辅显示屏*/
	LBSTYLE_TRIAGE_WAITING_AND_PASSING, 						/*  候诊与过号显示	   */
	LBSTYLE_TRIAGE_SECONDARY_DISPLAY2,							/*  分诊－候诊区辅显示屏2*/
	LBSTYLE_TRIAGE_CLINIC2,										/*  分诊－液晶诊室显示屏2*/
	LBSTYLE_TRIAGE_SECONDARY_DISPLAY3,							/*  分诊－候诊区辅显示屏3*/
	LBSTYLE_TRIAGE_INPATIENT_INFOMATION,						/*  医院－住院病人信息一览表*/
	LBSTYLE_TRIAGE_CLINIC3,										/*  分诊－液晶诊室显示屏3*/
	LBSTYLE_TRIAGE_CLINIC4,										/*  分诊－液晶诊室显示屏4*/
	LBSTYLE_TRIAGE_SECONDARY_CALL_DISPLAY,						/*  候诊区呼叫显示屏     */
	LBSTYLE_TRIAGE_SECONDARY_DISPLAY4,							/*  分诊－候诊区辅显示屏4*/
	LBSTYLE_TRIAGE_DISPENSARY2,									/*  取药叫号主显示屏2    */
	LBSTYLE_TRIAGE_MAIN_DISPLAY2,                               /*                       */
	LBSTYLE_TRIAGE_DISPENSARY3,
	LBSTYLE_TRIAGE_CLINIC5,										/*  分诊-候诊区辅显示屏6*/
	LBSTYLE_TRIAGE_SECONDARY_DISPLAY5,							/*  门诊/体检-候诊辅显示屏2*/
	LBSTYLE_TRIAGE_MAIN_DISPLAY3,								/*  门诊/体检- 候诊主显示屏2*/
	LBSTYLE_TRIAGE_DOORWAY_DIAPLAY,                             /*  住院病房门口显示屏*/
	LBSTYLE_TRIAGE_SECONDARY_DISPLAY6,							/*  门诊/体检- 候诊辅显示屏3 */
	LBSTYLE_TRIAGE_CLINIC6,										/*  门诊/体检- 诊室显示屏2 */  
	LBSTYLE_TRIAGE_CLINIC7,                                     /*  门诊/体检- 诊室显示屏3*/
	LBSTYLE_TRIAGE_CLINIC8,										/*  分诊-液晶诊室显示屏5*/
	LBSTYLE_TRIAGE_INFODISPLAY,                                 /*  信息发布系统客户端*/
	LBSTYLE_TRIAGE_DISPENSARY5,                                 /*  取药/输液-等候显示屏*/
	LBSTYLE_TRIAGE_DISPENSARY6,                                 /*  取药/输液-过号显示屏*/
	LBSTYLE_TRIAGE_SECONDARY_DISPLAY5_ORDER_BY_CLINIC,          /*  门诊/体检-候诊辅显示屏2 按诊室排序 */
	LBSTYLE_TRIAGE_CLINIC9,                                     /*  分诊－液晶诊室显示屏4*/
	LBSTYLE_TRIAGE_CLINIC3_NEW,                                 /*  新的真是门口屏*/

	LBSTYLE_PRISONVISITING_CALLING=BASE_LBSTYLE_PRISONVISITING,	/*  监狱探访呼叫信息   */
	LBSTYLE_INTERCOM_INQUEST1,                                  /*  监狱门口屏*/

	LBSTYLE_BANKQUEUE_CALLING=BASE_LBSTYLE_BANKQUEUE,			/*  银行主屏呼叫信息   */
	LBSTYLE_BANKQUEUE_CALLING_WINDOW,							/*  银行窗口呼叫信息   */
	LBSTYLE_BANKQUEUE_CALLING_WINDOW2,							/*  银行窗口呼叫信息2   */
	LBSTYLE_BANKQUEUE_CALLING2,									/*  银行主屏呼叫信息2    */
	LBSTYLE_BANKQUEUE_CALLING_WINDOW_BAR,						/*  银行窗口呼叫信息条形屏版*/
	LBSTYLE_BANKQUEUE_CALLING_AUXILIARY,                        /*  银行辅屏呼叫屏*/
	LBSTYLE_BANKQUEUE_CALLING_WINDOW3,							/*  银行窗口呼叫信息3   */

	LBSTYLE_INTERCOM_CALLING=BASE_LBSTYLE_INTERCOM, 			/*  网络对讲－走廊显示屏 */
	LBSTYLE_INTERCOM_SENTRY_CALLING,							/*	网络对讲－岗亭显示屏 */
	LBSTYLE_INTERCOM_DOOR_INFOMATION,							/*  网络对讲－开门提示一览表*/
	LBSTYLE_INTERCOM_REAL_TIME_MONITORING,						/*  网络对讲－实时监控*/
	LBSTYLE_INTERCOM_BAR,										/*  网络对讲－走廊显示屏(条形屏)*/
	LBSTYLE_INTERCOM_DEVICESTATE_DISPLAY,						/*  网络对讲－设备信息状态一览表*/

}LB_INFO_STYLE_t;

/* 定义模板 */
#define LBFIELD_NUMBER                   (1 << LBINDEX_NUMBER         )   /*号码*/
#define LBFIELD_NAME                     (1 << LBINDEX_NAME           )   /*姓名*/
#define LBFIELD_DEPARTMENT               (1 << LBINDEX_DEPARTMENT     )   /*科室*/
#define LBFIELD_PRISON_SECTITON          (1 << LBINDEX_PRISON_SECTITON)   /*监区*/
#define LBFIELD_TYPE                     (1 << LBINDEX_TYPE           )   /*门诊类别*/
#define LBFIELD_DOCTOR                   (1 << LBINDEX_DOCTOR         )   /*医生*/
#define LBFIELD_FAMILY                   (1 << LBINDEX_FAMILY         )   /*家属*/
#define LBFIELD_ROOM_CODE                (1 << LBINDEX_ROOM_CODE      )   /*诊室编号*/
#define LBFIELD_WINDOW                   (1 << LBINDEX_WINDOW         )   /*窗口*/
#define LBFIELD_STATE                    (1 << LBINDEX_STATE          )   /*状态*/
#define LBFIELD_DESCRIPTION              (1 << LBINDEX_DESCRIPTION    )   /*备注*/
#define LBFIELD_WAITING_PATIENT          (1 << LBINDEX_WAITING_PATIENT)   /*等待人员*/
#define LBFIELD_WAITING_COUNT            (1 << LBINDEX_WAITING_COUNT  )   /*等待人数*/
#define LBFIELD_MESSAGE                  (1 << LBINDEX_MESSAGE        )   /*信息*/
#define LBFIELD_SENTRY_STATE			 (1 << LBINDEX_SENTRY_STATE	  )	  /*状态－－－－－岗亭显示屏*/
#define LBFIELD_PRISONER				 (1 << LBINDEX_PRISONER		  )	  /*犯人*/
#define LBFIELD_TITLES					 (1 << LBINDEX_TITLES		  )   /*职称*/
#define LBFIELD_TOBEPATIENT_NUMBER		 (1 << LBINDEX_TOBEPATIENT_NUMBER)/*待诊票号*/
#define LBFIELD_DEPARTMENT_DOCTOR		 (1 << LBINDEX_DEPARTMENT_DOCTOR) /*科室医生*/
#define LBFIELD_ROOM_NAME				 (1 << LBINDEX_ROOM_NAME	  )   /*诊室名称*/
#define LBFIELD_WAIT_DESCRIPTION         (1 << LBINDEX_WAIT_DESCRIPTION)  /*等待备注*/
#define LBFIELD_BED_NUMBER				 (1 << LBINDEX_BED_NUMBER)        /*床号*/
#define LBFIELD_TOTAL_BED_NUMBER		 (1 << LBINDEX_TOTAL_BED_NUMBER)  /*总床号*/
#define LBFIELD_IS_INIT_DISPLAY          (1 << LBINDEX_IS_INIT_DISPLAY)   /*是否初始化显示屏*/

//#define LBFILED_INPATIENT_SEX_AGE        (1 << LBINDEX_INPATIENT_SEX_AGE) /*性别/年龄*/
//#define LBFILED_INPATIENT_DATETIME		 (1 << LBINDEX_INPATIENT_DATETIME)/*入院时间*/  
//#define LBFILED_INPATIENT_CARE			 (1 << LBINDEX_INPATIENT_CARE)    /*护理级别*/
//#define LBFILED_INPATIENT_MEASURE		 (1 << LBINDEX_INPATIENT_MEASURE) /*计量级别*/
//#define LBFILED_INPATIENT_ISOLATION		 (1 << LBINDEX_INPATIENT_ISOLATION)/*隔离级别*/
//#define LBFILED_INPATIENT_DIET			 (1 << LBINDEX_INPATIENT_DIET)    /*饮食级别*/
//#define LBFILED_INPATIENT_ALLERGY		 (1 << LBINDEX_INPATIENT_ALLERGY) /*饮食级别*/

/** 分诊排队 -> 液晶主显示屏 */
#define DEFAULT_COLUMNS_TRIAGE_MAIN_DISPLAY {\
		{LBFIELD_NUMBER				,13},\
		{LBFIELD_NAME				,13},\
		{LBFIELD_DEPARTMENT			,13},\
		{LBFIELD_TYPE				,12},\
		{LBFIELD_ROOM_CODE			,7 },\
		{LBFIELD_ROOM_NAME			,15},\
		{LBFIELD_DOCTOR				,16},\
		{LBFIELD_DESCRIPTION		,11},\
		{0							,0 } \
	}

/** 门诊/体检- 候诊主显示屏2 */
#define DEFAULT_COLUMNS_TRIAGE_MAIN_DISPLAY3 {\
		{LBFIELD_NUMBER				,13},\
		{LBFIELD_NAME				,13},\
		{LBFIELD_DEPARTMENT			,13},\
		{LBFIELD_TYPE				,12},\
		{LBFIELD_ROOM_CODE			,7 },\
		{LBFIELD_ROOM_NAME			,15},\
		{LBFIELD_DOCTOR				,16},\
		{LBFIELD_DESCRIPTION		,11},\
		{0							,0 } \
	}
#define DEFAULT_COLUMNS_TRIAGE_MAIN_DISPLAY_ANDROID {\
		{LBFIELD_NUMBER				,13},\
		{LBFIELD_NAME				,12},\
		{LBFIELD_DEPARTMENT			,12},\
		{LBFIELD_TYPE				,10},\
		{LBFIELD_ROOM_CODE			,7 },\
		{LBFIELD_ROOM_NAME			,12},\
		{LBFIELD_DOCTOR				,12},\
		{LBFIELD_DESCRIPTION		,10},\
		{LBFIELD_STATE				,12},\
		{0							,0 } \
}

/** 分诊排队 -> 候诊区统计人数显示 */
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_DISPLAY_ANDROID {\
		{LBFIELD_NUMBER				,11},\
		{LBFIELD_NAME				,11},\
		{LBFIELD_DEPARTMENT			,11},\
		{LBFIELD_TYPE				,11},\
		{LBFIELD_ROOM_CODE			,7},\
		{LBFIELD_ROOM_NAME			,10},\
		{LBFIELD_DOCTOR				,10},\
		{LBFIELD_WAITING_COUNT		,7},\
		{LBFIELD_WAITING_PATIENT	,12},\
		{LBFIELD_TOBEPATIENT_NUMBER	,10},\
		{0							,0 } \
	}
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_DISPLAY {\
		{LBFIELD_DEPARTMENT			,15},\
		{LBFIELD_TYPE				,12},\
		{LBFIELD_ROOM_CODE			,7},\
		{LBFIELD_ROOM_NAME			,14},\
		{LBFIELD_DOCTOR				,19},\
		{LBFIELD_WAITING_COUNT		,7},\
		{LBFIELD_WAITING_PATIENT	,26},\
		{0							,0 } \
	}

/** 分诊排队 -> 诊室呼叫显示 */
#define DEFAULT_COLUMNS_TRIAGE_CLINIC {  \
		{LBFIELD_ROOM_CODE			,100},\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_NAME				,100},\
		{0							,0 } \
	}

/** 分诊排队 -> 药房主屏病人显示 */
#define DEFAULT_COLUMNS_TRIAGE_DISPENSARY {\
		{LBFIELD_NUMBER				,20},\
		{LBFIELD_NAME				,35},\
		{LBFIELD_WINDOW				,20},\
		{LBFIELD_STATE				,25},\
		{0							,0 } \
	}

/** 分诊排队 -> 药房主屏病人显示2 */
#define DEFAULT_COLUMNS_TRIAGE_DISPENSARY2 {\
		{LBFIELD_NUMBER				,20},\
		{LBFIELD_NAME				,20},\
		{LBFIELD_WINDOW				,15},\
		{LBFIELD_STATE				,15},\
		{LBFIELD_ROOM_CODE          ,15},\
		{LBFIELD_ROOM_NAME			,15},\
		{0							,0 } \
	}
/**  取药-液晶主显示屏3 **/
#define DEFAULT_COLUMNS_TRIAGE_DISPENSARY3 {\
		{LBFIELD_NUMBER				,20},\
		{LBFIELD_NAME				,25},\
		{LBFIELD_WINDOW				,20},\
		{LBFIELD_WAITING_PATIENT	,15},\
		{LBFIELD_TOBEPATIENT_NUMBER	,10},\
		{LBFIELD_WAITING_COUNT		,10},\
		{0							,0 } \
	}

/** 分诊排队 -> 药房主屏病人显示5 */
#define DEFAULT_COLUMNS_TRIAGE_DISPENSARY5 {\
		{LBFIELD_NUMBER				,20},\
		{LBFIELD_NAME				,35},\
		{LBFIELD_WAITING_PATIENT	,20},\
		{LBFIELD_TOBEPATIENT_NUMBER	,25},\
		{0							,0 } \
	}

/** 分诊排队 -> 药房主屏病人显示6 */
#define DEFAULT_COLUMNS_TRIAGE_DISPENSARY6 {\
		{LBFIELD_NUMBER				,20},\
		{LBFIELD_NAME				,35},\
		{0							,0 } \
	}

/** 分诊排队 -> 药房窗口病人显示 */
#define DEFAULT_COLUMNS_TRIAGE_DISPENSARY_WINDOW {\
		{LBFIELD_NUMBER				,30},\
		{LBFIELD_NAME				,40},\
		{LBFIELD_STATE				,30},\
		{0							,0 } \
	}


/** 分诊排队 -> 候诊区辅显示屏2 */
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_DISPLAY2 {\
		{LBFIELD_ROOM_CODE			,7},\
		{LBFIELD_ROOM_NAME			,14},\
		{LBFIELD_DOCTOR				,15},\
		{LBFIELD_DEPARTMENT			,9},\
		{LBFIELD_TYPE				,7},\
		{LBFIELD_NUMBER				,12},\
		{LBFIELD_NAME				,12},\
		{LBFIELD_TOBEPATIENT_NUMBER	,12},\
		{LBFIELD_WAITING_PATIENT	,12},\
		{0							,0 } \
	}

/** 分诊排队 -> 候诊区辅显示屏3 */
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_DISPLAY3 {\
		{LBFIELD_NUMBER				,10},\
		{LBFIELD_NAME				,10},\
		{LBFIELD_DEPARTMENT			,15},\
		{LBFIELD_TYPE				,15},\
		{LBFIELD_DOCTOR				,15},\
		{LBFIELD_ROOM_CODE			,15},\
		{LBFIELD_ROOM_NAME			,20},\
		{0							,0 } \
	}

/** 分诊排队 -> 候诊区辅显示屏4 */
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_DISPLAY4 {\
		{LBFIELD_NUMBER				,30},\
		{LBFIELD_NAME				,30},\
		{LBFIELD_DESCRIPTION		,40},\
		{0							,0 } \
	}
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_DISPLAY5 {\
		{LBFIELD_NUMBER				,10},\
		{LBFIELD_NAME				,15},\
		{LBFIELD_DEPARTMENT_DOCTOR	,10},\
		{LBFIELD_ROOM_CODE			,10},\
		{LBFIELD_ROOM_NAME			,10},\
		{LBFIELD_WAITING_PATIENT	,15},\
		{LBFIELD_TOBEPATIENT_NUMBER	,10},\
		{LBFIELD_DESCRIPTION		,10},\
		{LBFIELD_WAIT_DESCRIPTION	,10},\
		{0							,0 } \
}
/*门诊/体检- 候诊辅显示屏3*/
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_DISPLAY6 {\
		{LBFIELD_NAME				,15},\
		{LBFIELD_NUMBER				,15},\
		{LBFIELD_ROOM_NAME			,15},\
		{LBFIELD_DOCTOR				,15},\
		{LBFIELD_TITLES				,15},\
		{LBFIELD_WAITING_PATIENT	,15},\
		{LBFIELD_TOBEPATIENT_NUMBER	,10},\
		{0							,0 } \
}
/*分诊  ->  候诊区呼叫显示屏*/
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_CALL_DISPLAY {\
		{LBFIELD_NUMBER				,10},\
		{LBFIELD_NAME				,10},\
		{LBFIELD_DEPARTMENT			,15},\
		{LBFIELD_DOCTOR				,15},\
		{LBFIELD_ROOM_CODE			,10},\
		{LBFIELD_ROOM_NAME			,10},\
		{LBFIELD_WAITING_PATIENT	,10},\
		{LBFIELD_TOBEPATIENT_NUMBER	,10},\
		{LBFIELD_DESCRIPTION       ,10},\
		{0							,0 } \
	}

/** 分诊排队 -> 液晶诊室显示屏2 */
#define DEFAULT_COLUMNS_TRIAGE_CLINIC2 {\
		{LBFIELD_DOCTOR				,100},\
		{LBFIELD_TITLES				,100},\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_NAME				,100},\
		{LBFIELD_TOBEPATIENT_NUMBER	,100},\
		{LBFIELD_WAITING_PATIENT	,100},\
		{0							,0 } \
	}

/** 分诊排队 -> 液晶诊室显示屏3 */
#define DEFAULT_COLUMNS_TRIAGE_CLINIC3 {\
	    {LBFIELD_ROOM_CODE         ,100},\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_NAME				,100},\
		{LBFIELD_TOBEPATIENT_NUMBER	,100},\
		{LBFIELD_WAITING_PATIENT	,100},\
		{0							,0 } \
	}

/** 分诊排队 -> 液晶诊室显示屏3_NEW */
#define DEFAULT_COLUMNS_TRIAGE_CLINIC3_NEW {\
		{LBFIELD_ROOM_CODE         ,20},\
		{LBFIELD_NUMBER				,20},\
		{LBFIELD_NAME				,20},\
		{LBFIELD_TOBEPATIENT_NUMBER	,20},\
		{LBFIELD_WAITING_PATIENT	,20},\
		{0							,0 } \
	}

/** 分诊排队 -> 液晶诊室显示屏4 */
#define DEFAULT_COLUMNS_TRIAGE_CLINIC4 {\
		{LBFIELD_ROOM_CODE         ,100},\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_NAME				,100},\
		{LBFIELD_TOBEPATIENT_NUMBER	,100},\
		{LBFIELD_WAITING_PATIENT	,100},\
		{0							,0 } \
	}

/** 分诊-候诊区辅显示屏6 */
#define DEFAULT_COLUMNS_TRIAGE_SECONDARY_CALL_DISPLAY2 {\
		{LBFIELD_NUMBER				,10},\
		{LBFIELD_NAME				,10},\
		{LBFIELD_DEPARTMENT			,10},\
		{LBFIELD_DOCTOR				,10},\
		{LBFIELD_ROOM_CODE			,10},\
		{LBFIELD_ROOM_NAME			,10},\
		{LBFIELD_WAITING_PATIENT	,10},\
		{LBFIELD_TOBEPATIENT_NUMBER	,10},\
		{LBFIELD_DESCRIPTION		,10},\
		{LBFIELD_IS_INIT_DISPLAY	,10},\
		{0							,0 } \
}

/* 门诊/体检 诊室显示屏2 */
#define DEFAULT_COLUMNS_TRIAGE_CLINIC6 {\
		{LBFIELD_NAME				,100},\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_DEPARTMENT			,100},\
		{LBFIELD_ROOM_CODE			,100},\
		{LBFIELD_DOCTOR				,100},\
		{LBFIELD_TITLES				,100},\
		{LBFIELD_TOBEPATIENT_NUMBER	,100},\
		{LBFIELD_WAITING_PATIENT	,100},\
		{0							,0 } \
}

/* 门诊/体检 诊室显示屏2 */
#define DEFAULT_COLUMNS_TRIAGE_CLINIC7 {\
		{LBFIELD_NAME				,100},\
		{LBFIELD_DEPARTMENT			,100},\
		{LBFIELD_WAITING_PATIENT	,100},\
		{LBFIELD_ROOM_NAME          ,100},\
		{0							,0 } \
}

/* 分诊-液晶诊室显示屏5*/
#define DEFAULT_COLUMNS_TRIAGE_CLINIC8 {\
		{LBFIELD_NAME				,100},\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_DOCTOR				,100},\
		{LBFIELD_TITLES				,100},\
		{LBFIELD_ROOM_CODE			,100},\
		{0							,0 } \
}

/* 分诊-液晶诊室显示屏4*/
#define DEFAULT_COLUMNS_TRIAGE_CLINIC9 {\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_NAME				,100},\
		{LBFIELD_DOCTOR				,100},\
		{LBFIELD_MESSAGE            ,100},\
		{LBFIELD_TITLES 			,100},\
		{0							,0 } \
}

/** 监狱门口屏,不支持定制 */
#define DEFAULT_COLUMNS_TRIAGE_INQUEST1 {\
		{0							,0 } \
}

/*  银行排队辅屏叫号屏*/
#define DEFAULT_COLUMNS_BANKQUEUE_CALLING_AUXILIARY {\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_NAME				,100},\
		{LBFIELD_DOCTOR				,100},\
		{LBFIELD_WINDOW				,100},\
		{LBFIELD_MESSAGE			,100},\
		{0							,0 } \
}

/** 信息发布系统客户端,不支持定制 */
#define DEFAULT_COLUMNS_TRIAGE_INFODISPLAY {\
		{0							,0 } \
}

/** 分诊排队 -> 电子信息看板,不支持定制 */
#define DEFAULT_COLUMNS_TRIAGE_INFOMATION {\
		{0							,0 } \
}

//{LBFIELD_NAME					,100},\
//{LBFILED_INPATIENT_SEX_AGE      ,100},\
//{LBFILED_INPATIENT_DATETIME     ,100},\
//{LBFIELD_DOCTOR					,100},\
//{LBFIELD_MESSAGE				,100},\
//{LBFIELD_DESCRIPTION			,100},\
//{LBFILED_INPATIENT_CARE         ,100},\
//{LBFILED_INPATIENT_MEASURE      ,100},\
//{LBFILED_INPATIENT_ISOLATION    ,100},\
//{LBFILED_INPATIENT_DIET         ,100},\
//{LBFILED_INPATIENT_ALLERGY      ,100},\
//{LBFIELD_NUMBER				    ,100},\
/** 医院 -> 住院病人信息一览表,支持定制 [医嘱 -->用备注代替,病情 --->用信息代替]*/
#define DEFAULT_COLUMNS_TRIAGE_INPATIENT_INFOMATION {\
		{0							    ,0 } \
}    

/** 住院病房门口显示屏   */
#define DEFAULT_COLUMNS_TRIAGE_DOORWAY_DIAPLAY {\
		{LBFIELD_DEPARTMENT        ,100},\
		{LBFIELD_BED_NUMBER			,100},\
		{LBFIELD_TOTAL_BED_NUMBER	,100},\
		{LBFIELD_DOCTOR				,100},\
		{LBFIELD_TITLES				,100},\
		{0							,0 } \
}



/** 监狱探访 -> 监狱探访呼叫信息 */
#define DEFAULT_COLUMNS_PRISONVISITING_CALLING {\
		{LBFIELD_NUMBER				,18},\
		{LBFIELD_FAMILY				,25},\
		{LBFIELD_NAME   			,25},\
		{LBFIELD_WINDOW				,12},\
		{LBFIELD_PRISON_SECTITON	,20},\
		{0							,0 } \
}

/** 银行排队 -> 银行主屏呼叫信息 */
#define DEFAULT_COLUMNS_BANKQUEUE_CALLING {\
		{LBFIELD_NUMBER				,30},\
		{LBFIELD_WINDOW				,30},\
		{LBFIELD_STATE				,40},\
		{0							,0 } \
}

/** 银行排队 -> 银行主屏呼叫信息2 */
#define DEFAULT_COLUMNS_BANKQUEUE_CALLING2 {\
		{LBFIELD_STATE				,30},\
		{LBFIELD_NUMBER				,30},\
		{LBFIELD_WINDOW				,40},\
		{0							,0 } \
}

/** 银行排队 -> 银行窗口呼叫信息 */
#define DEFAULT_COLUMNS_BANKQUEUE_CALLING_WINDOW {\
		{LBFIELD_WINDOW				,100},\
		{LBFIELD_NUMBER				,100},\
		{0							,0 }  \
}
/** 银行排队 -> 银行窗口呼叫信息条形屏版 */
#define DEFAULT_COLUMNS_BANKQUEUE_CALLING_WINDOW_BAR {\
		{LBFIELD_WINDOW				,100},\
		{LBFIELD_NUMBER				,100},\
		{LBFIELD_STATE              ,100},\
		{0							,0 }  \
}

/** 银行排队 -> 银行窗口呼叫信息 */
#define DEFAULT_COLUMNS_BANKQUEUE_CALLING_WINDOW2 {\
		{LBFIELD_WINDOW				,100},\
		{LBFIELD_NUMBER				,100},\
		{0							,0 }  \
}

/** 银行排队 -> 银行窗口呼叫信息3 */
#define DEFAULT_COLUMNS_BANKQUEUE_CALLING_WINDOW3 {\
		{LBFIELD_NAME				,25},\
		{LBFIELD_NUMBER				,25},\
		{LBFIELD_ROOM_CODE			,25},\
		{LBFIELD_MESSAGE			,25},\
		{0							,0 }  \
}

/** 网络对讲 -> 网络对讲走廊显示屏 */
#define DEFAULT_COLUMNS_INTERCOM_CALLING  {\
		{LBFIELD_MESSAGE			,60},\
		{LBFIELD_STATE				,40},\
		{0							,0 } \
}

/** 网络对讲 -> 网络对讲走廊显示屏(条形屏) */
#define DEFAULT_COLUMNS_INTERCOM_BAR  {\
		{LBFIELD_MESSAGE			,60},\
		{LBFIELD_STATE				,40},\
		{0							,0 } \
}

/** 网路对讲 －> 岗亭显示屏 */
#define  DEFAULT_COLUMNS_INTERCOM_SENTRY_CALLING {\
		{LBFIELD_MESSAGE			,60},\
		{LBFIELD_SENTRY_STATE		,40},\
		{0							,0}  \
}

/** 网路对讲 －> 开门提示一览表*/
#define DEFAULT_COLUMNS_INTERCOM_DOOR_INFOMATION {\
		{0							,0 } \
}

/** 网路对讲 －> 实时监控*/
#define DEFAULT_COLUMNS_INTERCOM_REAL_TIME_MONITORING {\
		{0							,0 } \
}

/** 网路对讲 －> 设备信息状态一览表*/
#define DEFAULT_COLUMNS_INTERCOM_DEVICESTATE_DISPLAY {\
		{0							,0 } \
}


#ifdef ANDROID
#define STR_LB_INFO_SETTING_TYPE               "SETTINGTYPE"     //护理类别设置类型 COMMONSETTING(普通设置) ADVANCEDSETTING(高级设置)
#define STR_LB_INFO_GENERAL_NURSING            "GENERAL_NURSING" //普通护理
#define STR_LB_INFO_ADVANCED_NURSING            "ADVANCED_NURSING" //高级护理
#define STR_LB_INFO_SPECIAL_NURSING             "SPECIAL_NURSING"  //特殊护理
#define DEFAULT_SETTING_TYPE                    "COMMONSETTING"    //缺省的设置类别
#define DEFAULT_GENERAL_NURSING                 16711680
#define DEFAULT_ADVANCED_NURSING                255
#define DEFAULT_SPECIAL_NURSING                 32768
#endif

#define STR_LB_INFO_MODEL						"LB_INFO_MODEL"
#define STR_LB_INFO_STYLE						"LB_INFO_STYLE"
#define STR_LB_INFO_POSITION_X0					"LB_INFO_POSITION_X0"
#define STR_LB_INFO_POSITION_Y0					"LB_INFO_POSITION_Y0"
#define STR_LB_INFO_POSITION_WIDTH				"LB_INFO_POSITION_WIDTH"
#define STR_LB_INFO_POSITION_HEIGHT				"LB_INFO_POSITION_HEIGHT"
#define STR_LB_INFO_TITLE_HIDEN					"LB_INFO_TITLE_HIDEN"
#define STR_LB_INFO_TITLE						"LB_INFO_TITLE"
#define STR_LB_INFO_SUB_TITLE					"LB_INFO_SUB_TITLE"
//#define STR_LB_INFO_TIPS_TITLE					"LB_INFO_TIPS_TITLE"
//#define STR_LB_INFO_TIPS						"LB_INFO_TIPS"

#define STR_LB_INFO_TRANSFER_485				"LB_INFO_TRANSFER_485"
#define STR_LB_INFO_485_DATA					"LB_INFO_485_DATA"
#define STR_LB_INFO_NET_MODEL					"LB_INFO_NET_MODEL"
#define STR_LB_INFO_MASTERIP_MODEL				"LB_INFO_MASTERIP_MODEL"
#define STR_LB_INFO_MASTERIP					"LB_INFO_MASTERIP"

#define STR_LB_INFO_TABLEHEADS					"LB_INFO_TABLEHEADS"
#define STR_LB_INFO_FORMAT_TABLEHEADS           "LB_INFO_FORMAT_TABLEHEADS"
#define STR_LB_INFO_ROWS						"LB_INFO_ROWS"
#define STR_LB_INFO_NOW_ROWS					"LB_INFO_NOW_ROWS"
#define STR_LB_INFO_NUM_SCREEN					"LB_INFO_NUM_SCREEN"
#define STR_LB_INFO_SAVE						"LB_INFO_SAVE"
#define STR_LB_INFO_MODELDESC					"LB_INFO_MODELDESC"
#define STR_LB_INFO_STYLEDESC					"LB_INFO_STYLEDESC_"
#define STR_LB_INFO_SCREEN_ROTATION				STR_SCREEN_ROTATION
#define STR_LB_INFO_NLVDCEVENTMESSAGE           "LB_INFO_NLVDCEVENTMESSAGE"
#define STR_LB_INFO_QUEUETIME                   "LB_INFO_QUEUETIME"
#define STR_LB_INFO_CHANGETIME                  "LB_INFO_CHANGETIME"
#define STR_LB_INFO_INFODISPLAY_SERVERIP        "LB_INFO_INFODISPLAY_SERVERIP"
#define STR_LB_INFO_SYSTEMVOICE					"LB_INFO_SYSTEMVOICE"
#define STR_LB_INFO_IS_HIDE_BOTTOM				"LB_INFO_IS_HIDE_BOTTOM"
#define STR_LB_INFO_IS_HIDE_CALL_INFO		    "LB_INFO_IS_HIDE_CALL_INFO"
#define STR_LB_INFO_IS_DISPLAY_DATASOURCE		"LB_INFO_IS_DISPLAY_DATASOURCE"
#define STR_LB_INFO_SHOWLOWESTLEVEL             "LB_INFO_SHOWLOWESTLEVEL"
#define STR_LB_INFO_SHOW_OLDSTYLE               "LB_INFO_SHOW_OLDSTYLE"
#define STR_LB_INFO_SHOW_NEWSTYLE               "LB_INFO_SHOW_NEWSTYLE"
#define STR_LB_INFO_TODAY_INPATIENT             "LB_INFO_TODAY_INPATIENT"
#define STR_LB_INFO_SHOW_CALLINFO_RIGHT         "LB_INFO_SHOW_CALLINFO_RIGHT"
#define STR_LB_INFO_SORTBYOFFICE                "LB_INFO_SORTBYOFFICE"
#define STR_LB_INFO_STAYTIME                    "LB_INFO_STAYTIME"
#define STR_LB_INFO_CHANGETIME                  "LB_INFO_CHANGETIME"
#define STR_LB_INFO_SHOWMODEL                   "LB_INFO_SHOWMODEL"
#define STR_LB_AD_ENABLED						"LB_AD_ENABLED"
#define STR_LB_AD_VIDEO_ENABLED					"LB_AD_VIDEO_ENABLED"
#define STR_LB_AD_AREA							"LB_AD_AREA"
#define STR_LB_AD_VIDEO_SIZE					"LB_AD_VIDEO_SIZE"
#define STR_LB_AD_VIDEO_SOURCE					"LB_AD_VIDEO_SOURCE"
#define STR_LB_AD_VIDEO_URL						"LB_AD_VIDEO_URL"
#define STR_LB_AD_TEXT_ENABLED					"LB_AD_TEXT_ENABLED"

#define STR_LB_DASHBOARD_DATASOURCE				"LB_DASHBOARD_DATASOURCE"

#define DEFAULT_LB_INFO_MODEL					LBMODEL_TRIAGE
#define DEFAULT_LB_INFO_STYLE					LBSTYLE_TRIAGE_MAIN_DISPLAY
#define DEFAULT_LB_INFO_POSITION_X0				0
#define DEFAULT_LB_INFO_POSITION_Y0				0

#define DEFAULT_LB_AD_ENABLED					FALSE
#define DEFAULT_LB_AD_VIDEO_ENABLED				TRUE
#define DEFAULT_LB_AD_AREA						30
#define DEFAULT_LB_AD_VIDEO_SIZE				1
#define DEFAULT_LB_AD_VIDEO_SOURCE				1
#define DEFAULT_LB_AD_VIDEO_URL					"http://x.x.x.x/"
#define DEFAULT_LB_AD_TEXT_ENABLED				TRUE



#ifdef MSC_VER
#define DEFAULT_LB_INFO_POSITION_WIDTH			1024
#define DEFAULT_LB_INFO_POSITION_HEIGHT			768
#else
#define DEFAULT_LB_INFO_POSITION_WIDTH			1280
#define DEFAULT_LB_INFO_POSITION_HEIGHT			720
#endif

#define DEFAULT_LB_INFO_TITLE					"主标题"
#define DEFAULT_LB_INFO_SUB_TITLE				"副标题"
#define DEFAULT_LB_INFO_US_TITLE                 "Main Title"
#define DEFAULT_LB_INFO_US_SUB_TITLE             "Subtitle"
//#define DEFAULT_LB_INFO_TIPS_TITLE				"温馨提示"
//#define DEFAULT_LB_INFO_TIPS					"温馨提示内容"
#define DEFAULT_LB_INFO_TRANSFER_485			FALSE
#define DEFAULT_LB_INFO_485_DATA				""
#define DEFAULT_LB_INFO_NET_MODEL				TRUE
#define DEFAULT_LB_INFO_MASTERIP				""
#define DEFAULT_LB_INFO_MASTERIP_MODEL			FALSE


#define DEFAULT_ROWS_TRIAGE_MAIN_DISPLAY              7
#define DEFAULT_ROWS_TRIAGE_MAIN_DISPLAY3             7
#define DEFAULT_ROWS_TRIAGE_SECONDAYR_DISPLAY         7
#define DEFAULT_ROWS_TRIAGE_CLINIC                    3
#define DEFAULT_ROWS_TRIAGE_DISPENSARY                7
#define DEFAULT_ROWS_TRIAGE_DISPENSARY2               5
#define DEFAULT_ROWS_TRIAGE_DISPENSARY3               6
#define DEFAULT_ROWS_TRIAGE_DISPENSARY5               5
#define DEFAULT_ROWS_TRIAGE_DISPENSARY6               5
#define DEFAULT_ROWS_TRIAGE_DISPENSARY_WINDOW         5
#define DEFAULT_ROWS_TRIAGE_INFOMATION				  0
#define DEFAULT_ROWS_TRIAGE_SECONDARY_DISPLAY2		  10
#define DEFAULT_ROWS_TRIAGE_SECONDARY_DISPLAY3		  10
#define DEFAULT_ROWS_TRIAGE_SECONDARY_DISPLAY4		  6
#define DEFAULT_ROWS_TRIAGE_SECONDAYR_DISPLAY5		  6
#define DEFAULT_ROWS_TRIAGE_SECONDAYR_DISPLAY6		  6
#define DEFAULT_ROWS_TRIAGE_SECONDARY_CALL_DISPLAY    0
#define DEFAULT_ROWS_TRIAGE_CLINIC2					  0
#define DEFAULT_ROWS_TRIAGE_INPATIENT_INFOMATION	  0
#define DEFAULT_ROWS_TRIAGE_DOORWAY_DIAPLAY           0
#define DEFAULT_ROWS_TRIAGE_CLINIC3					  3
#define DEFAULT_ROWS_TRIAGE_CLINIC3_NEW				  3
#define DEFAULT_ROWS_TRIAGE_CLINIC4					  3
#define DEFAULT_ROWS_TRIAGE_SECONDARY_CALL_DISPLAY2	  3
#define DEFAULT_ROWS_TRIAGE_CLINIC6					  8
#define DEFAULT_ROWS_TRIAGE_CLINIC7					  5
#define DEFAULT_ROWS_TRIAGE_CLINIC8					  2
#define DEFAULT_ROWS_TRIAGE_CLINIC9					  2
#define DEFAULT_ROWS_TRIAGE_INQUEST1				  2
#define DEFAULT_ROWS_BANKQUEUE_CALLING_AUXILIARY      1
#define DEFAULT_ROWS_TRIAGE_INFODISPLAY               0

#define DEFAULT_ROWS_PRISONVISITING_CALLING           7

#define DEFAULT_ROWS_BANKQUEUE_CALLING                6
#define DEFAULT_ROWS_BANKQUEUE_CALLING2               6
#define DEFAULT_ROWS_BANKQUEUE_CALLING_WINDOW         2
#define DEFAULT_ROWS_BANKQUEUE_CALLING_WINDOW2        3
#define DEFAULT_ROWS_BANKQUEUE_CALLING_WINDOW3        3
#define DEFAULT_ROWS_BANKQUEUE_CALLING_WINDOW_BAR     2

#define DEFAULT_ROWS_INTERCOM_CALLING                 3
#define DEFAULT_ROWS_INTERCOM_DOOR_INFOMATION         0
#define DEFAULT_ROWS_INTERCOM_REAL_TIME_MONITORING    0
#define DEFAULT_ROWS_INTERCOM_BAR                     0
#define DEFAULT_ROWS_INTERCOM_DEVICESTATE_DISPLAY     0

#define DEFAULT_NOW_ROWS						      1
#define DEFAULT_NUM_SCREEN							  1

typedef struct _LB_TABLEHEAD {
	int id;
	char desc[MAX_COLUMNS_DESC+1];
	int width;
	BOOL enabled;
	int order;
} LB_TABLEHEAD_t;

typedef struct _LB_INFO_POSITION {
	short x0;
	short y0;
	short width;
	short height;
} LB_INFO_POSITION_t;

#ifdef ANDROID
typedef enum  _LB_AD_VIDEO_SIZE_t{
	LB_AD_VIDEO_SIZE_FIT_AUTO,
	LB_AD_VIDEO_SIZE_4X3,
	LB_AD_VIDEO_SIZE_16X9,
	LB_AD_VIDEO_SIZE_FILL_H,
	LB_AD_VIDEO_SIZE_FILL_V
} LB_AD_VIDEO_SIZE_t;

typedef enum  _LB_AD_VIDEO_SOURCE_t{
	LB_AD_VIDEO_SOURCE_LOCAL,
	LB_AD_VIDEO_SOURCE_NETWORK
} LB_AD_VIDEO_SOURCE_t;
#endif 

typedef BOOL  (*_fn_lb_info_set_tableheads_t)(struct _LB_INFO_TEMPLATE*,const char*);

typedef struct _LB_INFO_TEMPLATE {
	ss_mutex_t	lock;
	int defined_value;
	LB_INFO_TYPE_t type;
	LB_INFO_MODEL_t model;
	LB_INFO_STYLE_t style;
	LB_INFO_POSITION_t position;
	int rotation;
	int number_of_columns;
	int number_of_rows;
	int number_of_now_rows;
	int number_of_screen;
	int factory_default_rows;
	int factory_default_now_rows;
	int factory_default_num_screen;
	BOOL isHidenTitle;
	char *title;
	char *sub_title;
	char *tableheads_str;
	char *default_tableheads_str;
	LB_TABLEHEAD_t **tableheads;
	_fn_lb_info_set_tableheads_t set_tableheads;
	LB_DASHBOARD_t *pDashboard;
 	LB_PAUSE_INFO_t *pPauseInfo;
#ifdef ANDROID
	char* tv_message;
	char* buffer;
	BOOL isHideBottom;
	BOOL isHideCallInfo;
	BOOL isDisplayDataSource;
	BOOL isShowLowestLevel;
	BOOL isShowOldStyle;
	BOOL isShowNewStyle;
	BOOL isTodayInPatient;
	BOOL ShowCallInfoByRight;
	BOOL SortByOffice;
	char* lb_queue_time;
	int lb_systemvoice;
	int lb_staytime;
	int lb_changetime;
	int lb_showmodel;
#endif 
} LB_INFO_TEMPLATE_t;


typedef void  (*_fn_lb_info_t) (struct _LB_INFO*);
typedef void  (*_fn_lb_info_message_t) (struct _LB_INFO*,int);
typedef void  (*_fn_lb_info_change_style) (struct _LB_INFO*,LB_INFO_MODEL_t,LB_INFO_STYLE_t);
typedef char* (*_fn_lb_info_get_model_desc_t)();
typedef char* (*_fn_lb_info_get_style_desc_t)(LB_INFO_MODEL_t);

static int LB_INFO_INI_saveData();

typedef struct _LB_INFO {
	ss_mutex_t	lock;
	LB_INFO_TEMPLATE_t *lb_template;
	IniConfig *iniconfig;
	SS_DeviceInfo *deviceInfo;
	unsigned char ip[MAX_IPADDRESS_LENGTH];
	int port;
	BOOL isMasterIPModel;
	unsigned char serverIP[MAX_IPADDRESS_LENGTH];
	unsigned char masterIP[MAX_IPADDRESS_LENGTH];
	int serverPort;
	int area_number;
	int master_number;
	int slaver_number;
	int group_number;
	int device_number;
	char *mstNumList;
	BOOL isNetModel;
	BOOL isTransfer485;
	BOOL isFixResolution;
	char *transfer_485_data;
#ifdef ANDROID
	BOOL isAdEnabled;
	BOOL isAdVideoEnabled;
	BOOL isAdTextEnabled;
	int adAreaPercent;
	LB_AD_VIDEO_SIZE_t iVideoSize;
	LB_AD_VIDEO_SOURCE_t iVideoSource;
	char *videoUrl;
#endif 
	_fn_lb_info_t load_template;
	_fn_lb_info_change_style change_template;
	_fn_lb_info_t save;
	_fn_lb_info_message_t post_message;
	_fn_lb_info_get_model_desc_t get_model_descs;
	_fn_lb_info_get_style_desc_t get_style_descs;
} LB_INFO_t;

SS_API LB_INFO_t *LB_INFO_new(SS_DeviceInfo *deviceInfo,IniConfig *iniconfig);
SS_API void LB_INFO_destroy(LB_INFO_t *lbInfo);


#ifdef ANDROID
typedef struct _NlvDcTemplate {
	int defined_value;
	int type;
	int model;
	int style;
	int rotation;
	int number_of_columns;
	int number_of_rows;
	int number_of_now_rows;
	int number_of_screen;
	int x0;
	int y0;
	int width;
	int height;
	BOOL isHidenTitle;
	char title[48];
	char sub_title[48];
	char tableheads_str[512];
	LB_DASHBOARD_DATA_t dashboard;
	char tv_message[128];
	char buffer[2048];
	BOOL isHideBottom;
	BOOL isHideCallInfo;
	BOOL isDisplayDataSource;
	BOOL isShowLowestLevel;
	BOOL isShowOldStyle;
	BOOL isShowNewStyle;
	BOOL isTodayInPatient;
	BOOL ShowCallInfoByRight;
	BOOL SortByOffice;
	char lb_queue_time[128];
	int lb_systemvoice;
	int lb_staytime;
	int lb_changetime;
	int lb_showmodel;
} NlvDcTemplate;

typedef struct _NlvDcInfo {
	int message;
	NlvDcTemplate template;
	int port;
	BOOL isMasterIPModel;
	char serverIP[MAX_IPADDRESS_LENGTH];
	char masterIP[MAX_IPADDRESS_LENGTH];
	int serverPort;
	int area_number;
	int master_number;
	int slaver_number;
	int group_number;
	int device_number;
	char mstNumList[64];
	BOOL isAdEnabled;
	BOOL isAdVideoEnabled;
	BOOL isAdTextEnabled;
	int adAreaPercent;
	int iVideoSize;
	int iVideoSource;
	char videoUrl[128];
} NlvDcInfo;

SS_API int updateVlvDcInfo(LB_INFO_t *lbInfo,NlvDcInfo *nlvDcInfo);
SS_API void postNlvDcInfoMessage(LB_INFO_t *lbInfo,int message);
#endif


/* 定义消息 */
#define LB_INFO_WINDOWS_TITLE			"LB_LCD_INFO"
#ifdef MSC_VER
#define WM_LB_INFO						(WM_USER + 2000)
#else
#define WM_LB_INFO						(2000)
#endif

#define WM_LB_INFO_POSITION				(WM_LB_INFO + 0)
#define WM_LB_INFO_TEMPLATE				(WM_LB_INFO + 1)
#define WM_LB_INFO_TABLEHEAD			(WM_LB_INFO + 2)
#define WM_LB_INFO_ROWS					(WM_LB_INFO + 3)
#define WM_LB_INFO_NOW_ROWS				(WM_LB_INFO + 4)
#define WM_LB_INFO_NUM_SCREEN			(WM_LB_INFO + 5)
#define WM_LB_INFO_SCREEN_ROTATION		(WM_LB_INFO + 6)
#define WM_LB_INFO_UPDATE				(WM_LB_INFO + 7)
#define WM_LB_INFO_TITLE_CHANGED		(WM_LB_INFO + 8)
#define WM_LB_INFO_AD_CHANGED			(WM_LB_INFO + 9)

#define WM_LB_INFO_DASHBOARD_CHANGED	(WM_LB_INFO + 10)
#define WM_LB_INFO_PAUSE_INFO_CHANGED   (WM_LB_INFO + 11)
#ifdef ANDROID
#define WM_LB_INFO_NLVDCEVENTMESSAGE    (WM_LB_INFO + 12)
#define WM_LB_INFO_QUEUETIME            (WM_LB_INFO + 13)
#define WM_LB_INFO_CHANGETIME            (WM_LB_INFO + 14)
#endif
#endif  //_LB_INFO_H_
