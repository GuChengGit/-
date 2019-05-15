/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_md5.h
* @brief LonbonVoip architecture MD5 digest definitions.
*
* @author	Qiusheng Li
* @date	2008-09-10
*
*/
#ifndef _SS_MD5_H_
#define _SS_MD5_H_


#include "ss_base/ss_def.h"

#define SS_HASHLEN 16
typedef char SS_HASH[SS_HASHLEN];

#define SS_HASHHEXLEN 32
typedef char SS_HASHHEX[SS_HASHHEXLEN+1];

struct SS_MD5Context {
	uint32_t buf[4];
	uint32_t bits[2];
	unsigned char in[64];
};

SS_API void SS_MD5Init(struct SS_MD5Context *context);
SS_API void SS_MD5Update(struct SS_MD5Context *context, unsigned char const *buf, unsigned len);
SS_API void SS_MD5Final(unsigned char digest[16], struct SS_MD5Context *context);
SS_API void SS_MD5Transform(uint32_t buf[4], uint32_t const in[16]);
SS_API char* ss_md5(unsigned char const *buf, unsigned len);
SS_API char* ss_md5_lonbon(unsigned char const *buf, unsigned len);
SS_API char* ss_md5_file(unsigned char *fileName);
SS_API char* ss_md5_file_length(unsigned char *fileName,unsigned int length);
#endif /* _SS_MD5_H_ */
