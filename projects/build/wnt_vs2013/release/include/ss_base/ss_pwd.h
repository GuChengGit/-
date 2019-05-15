#ifndef _SS_PWD_H_
#define _SS_PWD_H_

#include "ss_base/ss_def.h"

#define MAXPWLEN 8
#define CHALLENGESIZE 16
#ifndef LONBONVOIP_LONBON_STRING
#define LONBONVOIP_LONBON_STRING "b842e1b4356e"
#define LONBONVOIP_LONBON_STRING_NEW "b842e1b4356f"
#define LONBONVOIP_LONBON_STRING_LENGTH 12
#endif
typedef enum _SS_EncryptType
{
	SS_ENCRYPT_TYPE_UNKNOW,
	SS_ENCRYPT_TYPE_LONBON,
	SS_ENCRYPT_TYPE_LONBON1
}SS_EncryptType_t;

SS_API char* ss_cal_pwd(const char* mac);
SS_API char* ss_enc_pwd(const char* OriginalPwd);
SS_API char* ss_dec_pwd(const char* encryptewdPwd);
SS_API char* ss_cal_ha1(const char* user,const char* realm,const char* password);
SS_API char* ss_cal_ha1b(const char* user,const char* realm,const char* password);
SS_API char* ss_cal_auth(const char* user,const char* password);
SS_API char* ss_cal_license(const char* user,const char* password,const char* serialNumber,const char* model,const char* mac);

SS_API BOOL  ss_is_invalid_product(const char* license);
SS_API BOOL  ss_is_invalid_license(const char* license,const char* user,const char* password,const char* serialNumber,const char* model,const char* mac);
SS_API char* ss_cal_burn_device_auth(const char* user,const char* password);
SS_API char* ss_cal_burn_device_auth_ha1();
SS_API char* ss_encrypt(const char *originalString);
SS_API char* ss_decrypt(const char *encryptString);

SS_API void ss_encrypt_bytes(unsigned char *originalString,unsigned int length);
SS_API void ss_decrypt_bytes(unsigned char *encryptString,unsigned int length);
SS_API void  ss_encrypt_bytes_simple(unsigned char *encryptString,unsigned int length);
SS_API void  ss_decrypt_bytes_simple(unsigned char *encryptString,unsigned int length);
SS_API char *ss_lonbon_encrypt(const char* msg);
SS_API char *ss_lonbon_decrypt(const char* msg);

SS_API char *ss_lonbon_encrypt_by_type(const char* msg,SS_EncryptType_t encType);
SS_API char *ss_lonbon_decrypt_type(const char* msg,SS_EncryptType_t *encType);

SS_API char* ss_license_get_model_number(const char* license);
SS_API char ss_license_get_model_subnumber(const char* license);
#endif //_SS_PWD_H_
