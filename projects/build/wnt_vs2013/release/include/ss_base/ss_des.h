#ifndef _SS_DES_H_
#define _SS_DES_H_
#include "ss_base/ss_def.h"

#define SS_DES_ENCRYPT	0	/* MODE == encrypt */
#define SS_DES_DECRYPT	1	/* MODE == decrypt */

SS_API char* ss_des_encypt(const char* str,const char *key,int keylen);
SS_API char* ss_des_decypt(const char* str,const char *key,int keylen);
SS_API void ss_des_decypt_bytes(unsigned char* encStr,const unsigned int numberOfBytes,const char *key,int keylen);
SS_API void ss_des_encypt_bytes(unsigned char* str,const unsigned int length,const char *key,int keylen);
#endif
