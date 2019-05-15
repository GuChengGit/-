#ifndef _SS_ICONV_H_
#define _SS_ICONV_H_
#include <wchar.h>

#include "ss_base/ss_def.h"

/* WARNING: All ICONV API have not been tested yet */

SS_API int SS_ICONV_wCharToUTF8( const wchar_t* a_szSrc, char* a_szDest, int a_nDestSize );
SS_API int SS_ICONV_UTF8ToWChar( const char* a_szSrc, wchar_t* a_szDest, int a_nDestSize );
SS_API int SS_ICONV_wCharToUTF16( const wchar_t* a_szSrc, char* a_szDest, int a_nDestSize ); 
SS_API int SS_ICONV_UTF16ToWChar( const  char* a_szSrc, wchar_t* a_szDest, int a_nDestSize );
SS_API int SS_ICONV_mByteToWChar( const char* a_szSrc, wchar_t* a_szDest, int a_nDestSize );
SS_API int SS_ICONV_wCharToMByte( const wchar_t* a_szSrc,char* a_szDest, int a_nDestSize );

#endif
