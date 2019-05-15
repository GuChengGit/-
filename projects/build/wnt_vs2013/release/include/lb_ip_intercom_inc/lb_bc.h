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
	BCMODE_MICROPHONE_2EXTN_ALL,      //ȫ�������㲥
	BCMODE_EXTERNALAUDIO_2EXTN_ALL,   //ȫ�������Դ�㲥
	BCMODE_FILE_2EXTN_ALL,            //ȫ���ļ��㲥
	
	BCMODE_MICROPHONE_2EXTN_PART,     //���������㲥
	BCMODE_FILE_2EXTN_PART,           //�����ļ��㲥

	BCMODE_MICROPHONE_2MST_ALL,      //�����������㲥
	BCMODE_MICROPHONE_2MST_PART,      //�Բ������������㲥
}lbBc_mode_e;

typedef enum _lbBc_propert
{
	LBBC_PROP_GENERAL=0,      //��ͨ�㲥
	LBBC_PROP_TIME,           //��ʱ�㲥
} lbBc_propert_e;

/* �����㲥����bc_service_ui_win32.exe
** ��ȷ��bc_service_ui_win32.exe����λ��"bin"Ŀ¼�£�������÷��������������ص�
** Ӧ�ó���Ҳ���Լ������ù㲥�������
** 0����ʾ�ɹ�������ʧ��
*/
LB_EXPORT int lb_bcService_start(void);

/* �رչ㲥����bc_service_ui_win32.exe
** 0����ʾ�ɹ�������ʧ��
*/
LB_EXPORT int lb_bcService_stop(void);

LB_EXPORT int lb_fun_startBc(lbBc_mode_e mode,lbBc_propert_e bcPropert,int bcVol,int *dstDisplayNum,int dstCount,char **file,int fileCount,int playIndex);
LB_EXPORT int lb_fun_stopBc(int bcIndex);

LB_EXPORT int lb_fun_fileBc_pause(int bcIndex);
LB_EXPORT int lb_fun_fileBc_resume(int bcIndex);

/*�����ļ��㲥���ĸ��ļ���ʼ���ţ�����ʵ����һ�ף���һ�׻�ָ���ļ�����
* playFileIndexΪ�����ļ��㲥ʱ�ļ����ļ��б��е�λ�򣬴ӡ�0����ʼ��
* �����Ƿ������ء�-1����
* ʵ��ִ�����Ҫ���ݷ������¼��ж�
*/
LB_EXPORT int lb_fun_fileBc_playCtr(int bcIndex,int playFileIndex);

LB_EXPORT int lb_fun_setBcAddnalMst(int *displayNumList,int count); //���ø��ӹ㲥��������ȫ���㲥ʱ�����Զ�������Щ�㲥���󣬶�����ȫ���㲥���Ͱ�����Щ�������Էֻ�ȫ���㲥���Ͱ�����Щ������ֱ���ֻ�
LB_EXPORT int lb_fun_adjustBcVolume(int bcIndex,int vol);       //ʵʱ�����㲥������vol:1-10

#if defined(WINCE) || defined(_WIN32_WCE) || defined(WIN32) || defined(WIN64)
LB_EXPORT DWORD lb_ipc_on_copy_data(HWND hWnd, PCOPYDATASTRUCT pcds);
#endif
LB_EXPORT void * lb_thread_regiter();
LB_EXPORT int lb_thread_unregiter(void * id);

LB_END_DECL
#endif