#ifndef _LB_CALLLOGSAVE_H
#define _LB_CALLLOGSAVE_H
#include "lb_headdef.h"

LB_BEGIN_DECL

typedef enum _lb_callLogInfoType
{
    LBCALLLOG_IN_MISS = 1,     //呼入未接
    LBCALLLOG_IN_ANSWER,       //呼入已接
    LBCALLLOG_OUT_MISS,        //呼出未接
    LBCALLLOG_OUT_ANSWER,      //呼出已接
	LBCALLLOG_SLAVEXTALARM,	   //外接报警器报警
}lb_callLogInfoType_e;

typedef struct _lb_callLogInfo
{
	int displayNum;       //显示号
	lb_callLogInfoType_e logType;         //记录类型
	int callYear;         //呼叫年
	int callMonth;        //呼叫月
	int callDay;          //呼叫日
	int callHour;         //呼叫小时
	int callMinute;       //呼叫分钟
	int callSecond;       //呼叫秒钟
	int callDuration;     //呼叫时长（秒）
	int talkBeginYear;    //通话开始年
	int talkBeginMonth;   //通话开始月
	int talkBeginDay;     //通话开始日
	int talkBeginHour;    //通话开始小时
	int talkBeginMinute;  //通话开始分钟
	int talkBeginSecond;  //通话开始秒钟
	int talkDuration;     //通话时长（秒）
	char fileName[256];    //录音文件名
}lb_callLogInfo_s;

typedef void (LB_STDCALL *callLogSave_fun)(lb_callLogInfo_s info);
LB_EXPORT int lb_callLogSave_setSaveFun(callLogSave_fun fun);
LB_END_DECL
#endif