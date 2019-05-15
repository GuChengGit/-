#ifndef _FT_KEY_API_H_
#define _FT_KEY_API_H_

#include "ss_base/ss_base.h"

#define LBFT_RESERVER_KEY_DATE_STR				"KEYSN"
#define LBFT_RESERVER_KEY_VERSION_STR			"KEYVERSION"

/**
* @brief  �򿪼����豸�������һ������
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_open();

/**
* @brief  �ر�K�����豸���������һ������
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_close();

/**
* @brief  �������豸�Ƿ���ȷ���ӣ���ÿ5��10����������һ��
*
* @return TRUE -- �ɹ�����  FALSE -- �Ҳ���KEY��Ƿ�KEY
*/
SS_API BOOL LBFT_isLBKey();

/**
* @brief  ��ü����豸�д洢�����ݣ������û����ɸ��ĵ��豸��Ϣ���û��ɸ��ĵ�������Ϣ
*
* @param  key        [in]     ��ѯ�ļ���
* @param  value      [out]    ���صļ�ֵ���ڲ����䣬��ҪFREE
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_getStringValue(const unsigned char* key,unsigned char**value);

/**
* @brief  ���ü����豸��ָ�������ļ�ֵ��ע��ֻ���ڴ��и��ģ�����LBFT_save()��ſ�д������豸��
*
* @param  key        [in]     ��ѯ�ļ���
* @param  value      [out]    ���صļ�ֵ
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_setStringValue(const unsigned char* key,unsigned char*value);

/**
* @brief  ��������豸�д洢���û�����
*
* @param  key        [in]     ��ѯ�ļ���
* @param  value      [out]    ���صļ�ֵ
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_clean();

/**
* @brief  �������ݵ������豸��
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_save();

/**
* @brief  ��ȡ�����豸��Ӳ��ID
*
* @return Ӳ��ID
*/
SS_API const unsigned long LBFT_getId();

/**
* @brief  ��ȡ�����豸��Ӳ��SS_Flashʵ�����û�����Ҫfree�������ڵ���LBFT_close()ʱ�Զ�����
*
* @return SS_Flashʵ��
*/
SS_API const SS_Flash * LBFT_getFlash();

/**
* @brief  ��ȡ�����豸�����ֵ��16���ֽ��ַ����飬�û�����free
*
* @return 16�ֽڵ��ַ�����
*/
SS_API const unsigned char* LBFT_getRandom();


/**
* @brief  ��ȡ�����豸�İ汾��Ϣ��
*
* @param  version  [out]    ���صİ汾��Ϣ���ڲ����䣬��ҪFREE
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_getVersion(unsigned char**version);

/**
* @brief  ��ȡ�����豸���û�������Ϣ��
*
* @param  data  [out]    ���ص��û�������Ϣ���ڲ����䣬��ҪFREE
*
* @return 0 -- �ɹ�  -1 -- ʧ��
*/
SS_API int LBFT_getUserData(unsigned char**data);
#endif
