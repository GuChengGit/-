/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_list.h
* @brief LonbonVoip architecture linked list definitions.
*
* @author	Qiusheng Li
* @date	2008-10-20
*
*/

#ifndef _SS_LIST_H_
#define _SS_LIST_H_
#include "ss_base/ss_def.h"

typedef struct _MSList {
	struct _MSList *next;
	struct _MSList *prev;
	void *data;
}MSList;

#define ms_list_next(elem) ((elem)->next)

SS_API MSList * ms_list_new(void *data);
SS_API MSList * ms_list_append(MSList *elem, void * data);
SS_API MSList * ms_list_prepend(MSList *elem, void * data);
SS_API MSList * ms_list_free(MSList *elem);
SS_API MSList * ms_list_concat(MSList *first, MSList *second);
SS_API MSList * ms_list_remove(MSList *first, void *data);
SS_API int ms_list_size(const MSList *first);
SS_API void ms_list_for_each(const MSList *list, void (*func)(void *));
SS_API void ms_list_for_each2(const MSList *list, void (*func)(void *, void *), void *user_data);
SS_API MSList *ms_list_remove_link(MSList *list, MSList *elem);
SS_API MSList *ms_list_find(MSList *list, void *data);
SS_API MSList *ms_list_find_custom(MSList *list, int (*compare_func)(const void *, const void*), void *user_data);
SS_API void * ms_list_nth_data(const MSList *list, int n);
SS_API int ms_list_position(const MSList *list, MSList *elem);
SS_API int ms_list_index(const MSList *list, void *data);
SS_API MSList *ms_list_insert_sorted(MSList *list, void *data, int (*compare_func)(const void *, const void*));

SS_API void ms_list_push(MSList **elem, void * data);
SS_API void * ms_list_pop(MSList **elem);

#endif //_SS_LIST_H_
