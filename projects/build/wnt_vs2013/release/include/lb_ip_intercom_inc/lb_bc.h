#ifndef _LB_BC_H
#define _LB_BC_H
#include "lb_headdef.h"
#if defined(_WIN32_WCE) || defined(WIN32) || defined(__WIN32__) || defined(WIN64)
#include "windows.h"
#endif

LB_BEGIN_DECL

typedef enum _lbBc_mode
{
	BCMODE_UNKNOWN=0,
	BCMODE_MICROPHONE_2EXTN_ALL,      //全区喊话广播
	BCMODE_EXTERNALAUDIO_2EXTN_ALL,   //全区外接音源广播
	BCMODE_FILE_2EXTN_ALL,            //全区文件广播
	
	BCMODE_MICROPHONE_2EXTN_PART,     //分区喊话广播
	BCMODE_FILE_2EXTN_PART,           //分区文件广播

	BCMODE_MICROPHONE_2MST_ALL,      //对主机喊话广播
	BCMODE_MICROPHONE_2MST_PART,      //对部分主机喊话广播
}lbBc_mode_e;

typedef enum _lbBc_propert
{
	LBBC_PROP_GENERAL=0,      //普通广播
	LBBC_PROP_TIME,           //定时广播
} lbBc_propert_e;

/* 启动广播服务bc_service_ui_win32.exe
** 请确保bc_service_ui_win32.exe程序位于"bin"目录下，启动后该服务程序界面是隐藏的
** 应用程序也可自己启动该广播服务程序
** 0：表示成功，否则失败
*/
LB_EXPORT int lb_bcService_start(void);

/* 关闭广播服务bc_service_ui_win32.exe
** 0：表示成功，否则失败
*/
LB_EXPORT int lb_bcService_stop(void);

LB_EXPORT int lb_fun_startBc(lbBc_mode_e mode,lbBc_propert_e bcPropert,int bcVol,int *dstDisplayNum,int dstCount,char **file,int fileCount,int playIndex);
LB_EXPORT int lb_fun_stopBc(int bcIndex);

LB_EXPORT int lb_fun_fileBc_pause(int bcIndex);
LB_EXPORT int lb_fun_fileBc_resume(int bcIndex);

/*控制文件广播从哪个文件开始播放，可以实现上一首，下一首或指定文件播放
* playFileIndex为创建文件广播时文件在文件列表中的位序，从“0”开始；
* 参数非法，返回“-1”；
* 实际执行情况要根据反馈的事件判断
*/
LB_EXPORT int lb_fun_fileBc_playCtr(int bcIndex,int playFileIndex);

LB_EXPORT int lb_fun_setBcAddnalMst(int *displayNumList,int count); //设置附加广播主机，在全区广播时，会自动包含这些广播对象，对主机全区广播，就包含这些主机，对分机全区广播，就包含这些主机的直属分机
LB_EXPORT int lb_fun_adjustBcVolume(int bcIndex,int vol);       //实时调整广播音量，vol:1-10

#if defined(WINCE) || defined(_WIN32_WCE) || defined(WIN32) || defined(WIN64)
LB_EXPORT DWORD lb_ipc_on_copy_data(HWND hWnd, PCOPYDATASTRUCT pcds);
#endif
LB_EXPORT void * lb_thread_regiter();
LB_EXPORT int lb_thread_unregiter(void * id);

LB_END_DECL
#endif