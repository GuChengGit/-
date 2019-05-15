#ifndef _SS_KEY_H_
#define _SS_KEY_H_
#include <stdio.h>
#include "ss_base/ss_base.h"

#define FT_KEY_DPIN						"FFFFFFFFFFFFFFFF"
#define FT_KEY_TEST_SPIN				"9BD601884AB0C4D9"

#define FT_KEY_RSA_SIZE					128
#define FT_KEY_RSA_NAME_PUBLIC			"LBFT_PUB"
#define FT_KEY_RSA_NAME_PRIVATE			"LBFT_PRI"

#define FT_KEY_RESERVE_DATA_LENGTH		64
#define FT_KEY_MAX_DATA_LENGTH			(4096-FT_KEY_RESERVE_DATA_LENGTH)

SS_API int ft_key_open(unsigned char* pid,unsigned char* pin,BOOL isSoPin);
SS_API int ft_key_close();
SS_API int ft_key_get_version(int *major,int *minor);
SS_API int ft_key_get_hid(unsigned char* hid);
SS_API BOOL ft_key_is_new();

SS_API int ft_key_format(unsigned char* upin,unsigned char* seed,char *rsa_key_path);
SS_API int ft_key_private_read(unsigned char* buff,const int length);
SS_API int ft_key_private_write(unsigned char* buff,const int length);
SS_API int ft_key_public_read(unsigned char* buff,const int length);
SS_API int ft_key_public_write(unsigned char* buff,const int length);
SS_API int ft_key_private_read_reserve(unsigned char* buff,const int length);
SS_API int ft_key_private_write_reserve(unsigned char* buff,const int length);
SS_API int ft_key_public_read_reserve(unsigned char* buff,const int length);
SS_API int ft_key_public_write_reserve(unsigned char* buff,const int length);

SS_API int ft_key_random(unsigned char *random);
SS_API int ft_key_des_encrypt(int id,unsigned char* buff,int length);
SS_API int ft_key_des_decrypt(int id,unsigned char* buff,int length);
SS_API int ft_key_genrsa(int index,char*pubkey, char *prikey);
SS_API int ft_key_genrsa_by_openssl(char* pubkey,char*prikey);
SS_API int ft_key_setrsa(int index,char*pubkey, char *prikey);
SS_API int ft_key_rsaenc(int bFlag,int index,unsigned char *bBuf,int dwLen,unsigned char *bEncBuf);
SS_API int ft_key_rsadec(int bFlag,int index,unsigned char *data);
SS_API int ft_key_local_encrypt(char *keyfile,unsigned char *bBuf,int dwLen,unsigned char *bEncBuf);
SS_API int ft_key_local_decrypt(char *keyfile,unsigned char *bBuf);
#endif //_SS_KEY_H_

