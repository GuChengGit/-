#ifndef _LB_CALLLOGSAVE_H
#define _LB_CALLLOGSAVE_H
#include "lb_headdef.h"

LB_BEGIN_DECL

typedef enum _lb_callLogInfoType
{
    LBCALLLOG_IN_MISS = 1,     //����δ��
    LBCALLLOG_IN_ANSWER,       //�����ѽ�
    LBCALLLOG_OUT_MISS,        //����δ��
    LBCALLLOG_OUT_ANSWER,      //�����ѽ�
	LBCALLLOG_SLAVEXTALARM,	   //��ӱ���������
}lb_callLogInfoType_e;

typedef struct _lb_callLogInfo
{
	int displayNum;       //��ʾ��
	lb_callLogInfoType_e logType;         //��¼����
	int callYear;         //������
	int callMonth;        //������
	int callDay;          //������
	int callHour;         //����Сʱ
	int callMinute;       //���з���
	int callSecond;       //��������
	int callDuration;     //����ʱ�����룩
	int talkBeginYear;    //ͨ����ʼ��
	int talkBeginMonth;   //ͨ����ʼ��
	int talkBeginDay;     //ͨ����ʼ��
	int talkBeginHour;    //ͨ����ʼСʱ
	int talkBeginMinute;  //ͨ����ʼ����
	int talkBeginSecond;  //ͨ����ʼ����
	int talkDuration;     //ͨ��ʱ�����룩
	char fileName[256];    //¼���ļ���
}lb_callLogInfo_s;

typedef void (LB_STDCALL *callLogSave_fun)(lb_callLogInfo_s info);
LB_EXPORT int lb_callLogSave_setSaveFun(callLogSave_fun fun);
LB_END_DECL
#endif