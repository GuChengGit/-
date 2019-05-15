#ifndef _FT_KEY_API_H_
#define _FT_KEY_API_H_

#include "ss_base/ss_base.h"

#define LBFT_RESERVER_KEY_DATE_STR				"KEYSN"
#define LBFT_RESERVER_KEY_VERSION_STR			"KEYVERSION"

/**
* @brief  打开加密设备，比须第一个调用
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_open();

/**
* @brief  关闭K加密设备，比须最后一个调用
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_close();

/**
* @brief  检查加密设备是否正确连接，需每5到10分钟随机检查一次
*
* @return TRUE -- 成功连接  FALSE -- 找不到KEY或非法KEY
*/
SS_API BOOL LBFT_isLBKey();

/**
* @brief  获得加密设备中存储的数据，包括用户不可更改的设备信息和用户可更改的配置信息
*
* @param  key        [in]     查询的键名
* @param  value      [out]    返回的键值，内部分配，需要FREE
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_getStringValue(const unsigned char* key,unsigned char**value);

/**
* @brief  设置加密设备中指定键名的键值，注意只是内存中更改，调用LBFT_save()后才可写入加密设备中
*
* @param  key        [in]     查询的键名
* @param  value      [out]    返回的键值
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_setStringValue(const unsigned char* key,unsigned char*value);

/**
* @brief  清除加密设备中存储的用户数据
*
* @param  key        [in]     查询的键名
* @param  value      [out]    返回的键值
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_clean();

/**
* @brief  保存数据到加密设备中
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_save();

/**
* @brief  获取加密设备的硬件ID
*
* @return 硬件ID
*/
SS_API const unsigned long LBFT_getId();

/**
* @brief  获取加密设备的硬件SS_Flash实例，用户不需要free，它将在调用LBFT_close()时自动销毁
*
* @return SS_Flash实例
*/
SS_API const SS_Flash * LBFT_getFlash();

/**
* @brief  获取加密设备的随机值，16个字节字符数组，用户不可free
*
* @return 16字节的字符数组
*/
SS_API const unsigned char* LBFT_getRandom();


/**
* @brief  获取加密设备的版本信息，
*
* @param  version  [out]    返回的版本信息，内部分配，需要FREE
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_getVersion(unsigned char**version);

/**
* @brief  获取加密设备的用户数据信息，
*
* @param  data  [out]    返回的用户数据信息，内部分配，需要FREE
*
* @return 0 -- 成功  -1 -- 失败
*/
SS_API int LBFT_getUserData(unsigned char**data);
#endif
