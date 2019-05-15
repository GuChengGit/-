/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_auth.h
* @brief LonbonVoip Generic Authorize Defination.
*
* @author	Qiusheng Li
* @date	2008-09-20
*
*/
#ifndef _SS_AUTH_H_
#define _SS_AUTH_H_
#include <time.h>
#include "ss_base/ss_md5.h"

//#define AUTHENTICATE_MD5         (1<<0)
//#define AUTHENTICATE_MD5SESS     (1<<1)


SS_API void ss_cvtHex(SS_HASH Bin, SS_HASHHEX Hex);

/*
* calculate H(A1) as per HTTP Digest spec
*/
SS_API void DigestCalcHA1(const char * pszAlg, const char * pszUserName, const char * pszRealm,
				   const char * pszPassword, const char * pszNonce, const char * pszCNonce,
				   SS_HASHHEX SessionKey);

/* calculate request-digest/response-digest as per HTTP Digest spec */
SS_API void DigestCalcResponse(SS_HASHHEX HA1,           /* H(A1) */
						const char * pszNonce,       /* nonce from server */
						const char * pszNonceCount,  /* 8 hex digits */
						const char * pszCNonce,      /* client nonce */
						const char * pszQop,         /* qop-value: "", "auth", "auth-int" */
						const char * pszMethod,      /* method from the request */
						const char * pszDigestUri,   /* requested URL */
						SS_HASHHEX HEntity,       /* H(entity body) if qop="auth-int" */
						SS_HASHHEX Response      /* request-digest or response-digest */);

SS_API char *ss_base64encode(char const *inbuf, unsigned int inbuf_size);
SS_API char* ss_base64decode(const char *inbuf);
SS_API char * ss_getBasicAuthInfo (const char * username, const char * password);
SS_API char * ss_constructBasicAuth (char * username, char * password);

#endif //_SS_AUTH_H_
