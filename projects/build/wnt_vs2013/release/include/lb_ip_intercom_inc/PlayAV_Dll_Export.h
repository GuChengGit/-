

#ifndef __PLAY_AV_DLL_EXPORT_H__
#define __PLAY_AV_DLL_EXPORT_H__

#define LB_EXPORT __declspec(dllexport)

#include "windows.h"


#ifdef __cplusplus
extern "C"
{
#endif

/************************************************************************/
/*              ���Žӿڣ�������Щ�ӿ�һ�����ڱ��ز��š�                */
/************************************************************************/

/**
* ����λ��֪ͨ�ص�
* 
* usr_data ��lb_avplay_open����ȥ�Ĳ���
* x        λ�ã���Χ[0, 1000]
*/
typedef void (*CallBack_OnSetPos)(void * usr_data,int x);

/**
* ���Ž���֪ͨ�ص�
* 
* usr_data ��lb_avplay_open����ȥ�Ĳ���
*/
typedef void (*CallBack_OnPlayEnd)(void * usr_data);

/**
* ����ʱ�����Ƶ���ݰ��Ļص��ӿ�
* 
* audio_data ��Ƶ���ݵ�ַ
* size       ���ݳ���
*/
typedef void (*CallBack_OnAudioData)(void * audio_data, int size);

/**
* ����ʱ�����Ƶ���ݰ��Ļص��ӿ�
* 
* video_data ��Ƶ���ݵ�ַ
* size       ���ݳ���
*/
typedef void (*CallBack_OnVideoData)(void * video_data, int size);




/**
* ���ļ������в���
* 
* pszFileName Ҫ���ŵ��ļ���
* hVideoWnd   ������Ƶ��ʾ�Ĵ��ھ������Ƶ���ڸô�������ʾ����С�͸ô���һ�¡�
*             �ò�������Ϊ��
* UsrData     ���ص�ʱ�������û��Զ�������
* OnSetPos    ����λ��֪ͨ�ص�����
* OnPlayEnd   ���Ž���֪ͨ�ص�����
*/
LB_EXPORT BOOL lb_avplay_open(LPCTSTR pszFileName, HWND hVideoWnd, void * UsrData, 
							  CallBack_OnSetPos OnSetPos, 
							  CallBack_OnPlayEnd OnPlayEnd) ;


/**
* �رյ�ǰ����
* 
*/
LB_EXPORT void lb_avplay_close(void) ;

/**
* �ָ���ǰ����
* 
*/
LB_EXPORT void lb_avplay_resume() ;

/**
* ��ͣ��ǰ����
* 
*/
LB_EXPORT void lb_avplay_pause() ;

/**
* �����ڲ���ʱ�������Ƶ���ݰ��Ļص��ӿ�
* 
* cb �ص�����
*/
LB_EXPORT void lb_avplay_set_audio_cb(CallBack_OnAudioData cb) ;

/**
* �����ڲ���ʱ�������Ƶ���ݰ��Ļص��ӿ�
* 
* cb �ص�����
*/
LB_EXPORT void lb_avplay_set_video_cb(CallBack_OnVideoData cb) ;





/************************************************************************/
/*           ����ӿڣ�������Щ�ӿ�һ������������ղ����š�             */
/************************************************************************/

/**
* ��Ƶ�����ʼ��
* 
* hVideoWnd ������Ƶ��ʾ�Ĵ��ھ������Ƶ���ڸô�������ʾ����С�͸ô���һ�¡�
*           �ò�������Ϊ��
*/
LB_EXPORT int  lb_video_dec_init(HWND hVideoWnd) ;

/**
* ������ǰ��Ƶ���룬���ͷ������Դ
* 
*/
LB_EXPORT void lb_video_dec_deinit() ;

/**
* ����Ƶ���ݸ���Ƶ���������н��벢����
* 
* data   ��Ƶ����
* length ��Ƶ���ݳ���
*/
LB_EXPORT void lb_video_dec_put_data(void * data, int length) ;


/**
* ��Ƶ�����ʼ��
* 
*/
LB_EXPORT int lb_audio_dec_init() ;

/**
* ������ǰ��Ƶ���룬���ͷ������Դ
* 
*/
LB_EXPORT void lb_audio_dec_deinit() ;

/**
* ����Ƶ���ݸ���Ƶ���������н��벢����
* 
* data   ��Ƶ����
* length ��Ƶ���ݳ���
*/
LB_EXPORT void lb_audio_dec_put_data(void * data, int length) ;



#ifdef __cplusplus
}
#endif



#endif // __PLAY_AV_DLL_EXPORT_H__





	