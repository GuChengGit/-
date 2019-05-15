/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_pair.h
* @brief LonbonVoip architecture pair definitions.
*
* @author	Qiusheng Li
* @date	2008-09-10
*
*/
#ifndef _SS_PAIR_H_
#define _SS_PAIR_H_

#include "ss_base/ss_def.h"
#include "ss_base/ss_list.h"


typedef struct _ss_pair {
	char *key;
	char *value;
} ss_pair;

typedef struct _ss_pair_list {
	MSList * list;
} ss_pair_list;

SS_API int createEmptyPair(ss_pair **my_pair);
SS_API int createPair(const char *key,const char* value,ss_pair **my_pair);
SS_API int destroyPair(ss_pair *my_pair);
SS_API int createEmptyPairList(ss_pair_list **my_pair_list);
SS_API int destroyPairList(ss_pair_list *pair_list) ;
SS_API int getPairListStringValue(const ss_pair_list *pair_list,const char *key,char **value);
SS_API int setPairListStringValue(ss_pair_list **pair_list,const char *key,const char *value);
SS_API int getPairListIntValue(const ss_pair_list *pair_list,const char *key,int *value);
SS_API int setPairListIntValue(ss_pair_list **pair_list,const char *key,const int value);
SS_API int getPairListUIntValue(const ss_pair_list *pair_list,const char *key,unsigned int *value);
SS_API int setPairListUIntValue(ss_pair_list **pair_list,const char *key,const unsigned int value);
SS_API int getPairListULongValue(const ss_pair_list *pair_list,const char *key,unsigned long *value);
SS_API int setPairListULongValue(ss_pair_list **pair_list,const char *key,const unsigned long  value);
SS_API int getPairListBoolValue(const ss_pair_list *pair_list,const char *key,BOOL *value);
SS_API int setPairListBoolValue(ss_pair_list **pair_list,const char *key,const BOOL value);

SS_API int removeFromPairList(ss_pair_list **pair_list,const char *key);
SS_API int addToPairList(ss_pair_list **pair_list,ss_pair  *a_pair);
SS_API int addKeyValueToPairList(ss_pair_list **pair_list,const char *key,const char *value);
SS_API int addKeyValuesToPairList(ss_pair_list **pair_list,const char **keys,const char **values,int new_key_length);
SS_API int stringToPairList(const char *str,const char declare_char, ss_pair_list **pair_list);
SS_API int stringToPairList2(const char *str,const char nl,const char declare_char, ss_pair_list **pair_list);
SS_API int pairListToString(const ss_pair_list *pair_list,char **str);
SS_API int copyPair(const ss_pair *old_pair,ss_pair **new_pair);
SS_API int copyPairList(const ss_pair_list *pair_list,ss_pair_list **new_pair_list);
#endif /*_SS_PAIR_H_*/
