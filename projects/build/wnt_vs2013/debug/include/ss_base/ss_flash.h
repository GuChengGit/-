/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file lonbonvoip/lonbonvoip_config.h
* @brief Generic Defination.
*
* @author	Qiusheng Li
* @date	2008-09-20
*
*/

#ifndef _SS_FLASH_H_
#define _SS_FLASH_H_

#define SS_FLASH_CURRENT_VERSION			"0002"

#define SS_FLASH_KEY_CONFIG_OK				"CONFIGOK"
#define SS_FLASH_KEY_DEVICENAME				"LB_DEVICENAME"
#define SS_FLASH_KEY_DEVICEMODEL			"DEVICEMODEL"
#define SS_FLASH_KEY_CUSTOMIZEDMODEL		"CUSTOMIZEDMODEL"
#define SS_FLASH_KEY_HARD_VERSION			"LB_HARDWARE_VERSION"
#define SS_FLASH_KEY_LINE1AUTHUSER			"LINE1AUTHUSER"
#define SS_FLASH_KEY_LINE1AUTHPSWD			"LINE1AUTHPSWD"
#define SS_FLASH_KEY_LICENSENUMBER			"LICENSENUMBER"
#define SS_FLASH_KEY_LINE1PORT				"LINE1PORT"
#define SS_FLASH_KEY_BURNMAC				"BURNMAC"
#define SS_FLASH_KEY_SERIALNUMBER			"SERIALNUMBER"
#define SS_FLASH_KEY_HARD_ID				"HARD_ID"
#define SS_FLASH_KEY_SD_RECORDING			"SD_RECORDING"
#define SS_FLASH_KEY_SDK_ENABLE				"SDK_ENABLE"
#define SS_FLASH_KEY_MODEL_CODE				"MODEL_CODE"
#define SS_FLASH_KEY_MD5					"MD5"
#define SS_FLASH_KEY_ROTATION				"ROTATION"
#define SS_FLASH_KEY_DPI						"DPI"

#define SS_FLASH_DEFAULT_DATA_SIZE			2048
#define SS_FLASH_DEFAULT_KEY_SIZE			32

#define SS_FLASH_KEY_LENGTH_CONFIG_OK		4
#ifdef _NNOS
#define SS_FLASH_KEY_LENGTH_DEVICENAME		16
#else
#define SS_FLASH_KEY_LENGTH_DEVICENAME		32
#endif
#define SS_FLASH_KEY_LENGTH_CUSTOMIZEDMODEL	32
#define SS_FLASH_KEY_LENGTH_DEVICEMODEL		16
#define SS_FLASH_KEY_LENGTH_HARD_VERSION	16
#define SS_FLASH_KEY_LENGTH_LINE1AUTHUSER	14
#define SS_FLASH_KEY_LENGTH_LINE1AUTHPSWD	10
#define SS_FLASH_KEY_LENGTH_LICENSENUMBER	44
#define SS_FLASH_KEY_LENGTH_LINE1PORT		5
#define SS_FLASH_KEY_LENGTH_BURNMAC			12
#define SS_FLASH_KEY_LENGTH_SERIALNUMBER	11
#define SS_FLASH_KEY_LENGTH_HARD_ID			32
#define SS_FLASH_KEY_LENGTH_SD_RECORDING	1
#define SS_FLASH_KEY_LENGTH_SDK_ENABLE		1
#define SS_FLASH_KEY_LENGTH_MODEL_CODE		8
#define SS_FLASH_KEY_LENGTH_MD5				32
#define SS_FLASH_KEY_LENGTH_ROTATION		4
#define SS_FLASH_KEY_LENGTH_DPI		4


struct _SS_Flash_t;

typedef int (*fn_flash_t)(unsigned char* data,int length);
typedef int (*fn_get_key_string_value_t)(struct _SS_Flash_t* pFlash, const unsigned char* key, unsigned char** value);
typedef int (*fn_set_key_string_value_t)(struct _SS_Flash_t* pFlash,const unsigned char* key, const unsigned char* value);
typedef int (*fn_get_key_int_value_t)(struct _SS_Flash_t* pFlash,const unsigned char* key, unsigned int* value);
typedef int (*fn_set_key_int_value_t)(struct _SS_Flash_t* pFlash,const unsigned char* key, const unsigned int value);
typedef int (*fn_is_flash_key_t)(struct _SS_Flash_t* pFlash,const unsigned char* key);
typedef int (*fn_is_flash_scanned_t)(struct _SS_Flash_t* pFlash);

typedef struct _ss_flash_map{
	unsigned char name[32];
	int length;
}ss_flash_map_t;

typedef struct _SS_Flash_t{
	ss_flash_map_t *keyMap;
	int keyMapLength;
	unsigned char *data;
	int dataLength;
	unsigned long id;
	fn_flash_t init;
	fn_flash_t burn;
	fn_is_flash_key_t isFlashKey;
	fn_get_key_string_value_t getKeyStringValue;
	fn_set_key_string_value_t setKeyStringValue;
	fn_get_key_int_value_t getKeyIntValue;
	fn_set_key_int_value_t setKeyIntValue;
	fn_is_flash_scanned_t isFlashScanned;
}SS_Flash;


SS_API SS_Flash * SS_Flash_new(int flashSize,
						ss_flash_map_t *keyMap,
						int keyMapLength,
						fn_flash_t init,
						fn_flash_t burn
						);
SS_API void SS_Flash_destroy(SS_Flash *pFlash);

SS_API SS_Flash *SS_Flash_getDefaultInst();
SS_API void SS_Flash_destroyDefaultInst();
#if defined(_WIN32) && !defined(_WIN32_WCE)
SS_API SS_Flash *SS_Flash_getTestInst();
#endif
SS_API BOOL SS_Flash_isFlashKey(SS_Flash *pFlash,const unsigned char* key);
SS_API const ss_flash_map_t* SS_Flash_getDefaultKeyMap();
SS_API const int SS_Flash_getDefaultKeyMapLength();

#endif //_SS_FLASH_H_
