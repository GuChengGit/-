#ifndef _SS_STRING_H_
#define _SS_STRING_H_
#include <stdarg.h>
#include <time.h>

#include "ss_base/ss_def.h"
#if defined(__linux__) && !defined(__linux___ARM) && !defined(ANDROID)
SS_API void *__wrap_memcpy(void *dest, const void *src, size_t n);
#endif
#define IS_STRING_EQUAL(a,b) (((a)==NULL && (b)==NULL)||((a)!=NULL && (b)!=NULL && strcmp((a),(b))==0))

#define LONBON_UUID_LENGTH	16

#define string_to_int(s) atoi(s)
#define string_to_double(s) atof(s)
#define string_to_float(s) (float)atof(s)
#define string_to_long(s) atol(s)
#define string_to_uint(s) (unsigned int) strtoul(s,NULL,10)
#define string_to_ulong(s) (unsigned long) strtoul(s,NULL,10)
#define string_to_longlong(s) stringToLongLong((s),NULL,10)
#define string_to_ulonglong(s) stringToUnsignedLongLong((s),NULL,10)

typedef struct _ss_str_t{
	unsigned char *s;
	int len;
}ss_str_t;

SS_API ss_str_t* ss_str_new(const char *str,int len);
SS_API ss_str_t* ss_str_dup(ss_str_t *ss_str);
SS_API void ss_str_destory(ss_str_t* str);

SS_API int stringToBoolean(const char *str);
SS_API BOOL string_to_boolean(const char *str);
SS_API char* boolean_to_string(BOOL boolStr);

SS_API int intToString(int i,char **s);
SS_API int uintToString(unsigned int i,char **s);

SS_API int is_space_char(char c);
SS_API BOOL isNotNull(const char* s);
SS_API BOOL isEmptyString(const char* s);
SS_API int toUpCase(char* s);
SS_API int toLowCase(char* s);

SS_API int trimString(char * str);
SS_API int subString(const char *str, int beginIndex, int endIndex, char **subStr );
SS_API char* getFirstStr(char* str);

SS_API char * str_dup(const char *s);
SS_API char * str_ncpy(const char *src, int dst_size);
SS_API int copyString(const char *str1,char **str2);
SS_API const char * str_nstr (const char *buf, const char *sub,const size_t n);

SS_API int ss_sprintf(char *buf, const char *fmt, ...);
SS_API int ss_snprintf(char *buf, size_t n, const char *fmt, ...);
SS_API char *str_printf(const char *fmt,...);
SS_API char *str_vsprintf(const char *fmt,va_list args);

SS_API int addToString(char **str,const char *fmt,...);
SS_API int addToArray(char ***strArray,int*length,const char *str);

SS_API int convertTableStringToArray(const char* inputString,int *nRow,int *nCol, char**** table);
SS_API char* convertTableArrayToString(int nRow,int nCol,char*** table);
SS_API void freeTableString(int nRow,int nCol,char*** table);

SS_API int split_string(const char *str,const char *delims, char***values,int *numberOfValues);
SS_API int splitString(const char *str, const char c, char **key, char **value);
SS_API int splitMultiLinesString(const char *str, char c, char***keys, char***values, int *numberOfKeys) ;
SS_API int splitMultiString(const char *str, char nl,char c, char***keys, char***values, int *numberOfKeys);

SS_API int indexOfString(const char* str, char c,int *indexOf) ;

SS_API unsigned int hexToInt(const char *hexStr);
SS_API char* intToHex(unsigned int _s);
SS_API unsigned short hexCharToInt(char c);
SS_API int hexToBytes(const char *hexStr,unsigned char **bytes,int* numberOfBytes);
SS_API int bytesTohex(const unsigned char *bytes,int n,unsigned char** hexStr);

SS_API int convertStringToArray(const char* inputString,const char* token,int * arrayLength, char*** strArray );
SS_API int convertArrayToString(const char** strArray,const int arrayLength,const char* token,char** str);
SS_API int indexOfStringArray(const char** strArray,const int arrayLength, const char *str,int *indexOf) ;

SS_API const char* strstr_nocomment(const char* s1,const char* s2);
SS_API BOOL isInteger(const char* s);
SS_API BOOL isHex(const char* s);
SS_API BOOL isHexInterger(const char* s);
#ifndef _NNOS
SS_API long long stringToLongLong(const char* nptr, char **endptr, int base);
SS_API unsigned long long stringToUnsignedLongLong(const char* nptr, char **endptr, int base);
#endif

#endif //_SS_STRING_H_
