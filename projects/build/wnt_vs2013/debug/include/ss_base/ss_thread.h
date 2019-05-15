/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_thread.h
* @brief LonbonVoip architecture thread definitions.
*
* @author	Qiusheng Li
* @date	2008-10-10
*
*/
#ifndef _SS_THREAD_H_
#define _SS_THREAD_H_
#include "ss_base/ss_def.h"

#ifdef _MSC_VER
typedef void *		ss_cond_t;
typedef void *		ss_mutex_t;
typedef void *		ss_thread_t;

SS_API int ss_thread_create(ss_thread_t *t, void *attr_unused, void *(*func)(void*), void *arg); 
SS_API int ss_thread_join(ss_thread_t thread, void **unused);
SS_API void ss_thread_exit (void *value_ptr);
SS_API ss_thread_t ss_thread_self(void);
SS_API int ss_mutex_init(ss_mutex_t *m, void *attr_unused);
SS_API int ss_mutex_lock(ss_mutex_t *mutex);
SS_API int ss_mutex_unlock(ss_mutex_t *mutex);
SS_API int ss_mutex_destroy(ss_mutex_t *mutex);
SS_API int ss_cond_init(ss_cond_t *cond, void *attr_unused);
SS_API int ss_cond_signal(ss_cond_t * cond);
SS_API int ss_cond_broadcast(ss_cond_t * cond);
SS_API int ss_cond_wait_timedwait(ss_cond_t* hCond, ss_mutex_t * hMutex, const struct timespec *ts);
SS_API int ss_cond_wait(ss_cond_t * cond, ss_mutex_t * mutex);
SS_API int ss_cond_destroy(ss_cond_t * cond);

#else    //use pthread

#include <pthread.h>
typedef pthread_mutex_t ss_mutex_t;
typedef pthread_cond_t	ss_cond_t;
typedef pthread_t		ss_thread_t;

#define ss_thread_create		pthread_create
#define ss_thread_join			pthread_join
#define ss_thread_exit			pthread_exit

#define ss_mutex_init			pthread_mutex_init
#define ss_mutex_lock			pthread_mutex_lock
#define ss_mutex_unlock			pthread_mutex_unlock
#define ss_mutex_destroy		pthread_mutex_destroy

#define ss_cond_init			pthread_cond_init
#define ss_cond_signal			pthread_cond_signal
#define ss_cond_broadcast		pthread_cond_broadcast
#define ss_cond_wait			pthread_cond_wait
#define ss_cond_destroy			pthread_cond_destroy
#endif

#define SS_LOCK_INIT(p) ss_mutex_init(&((p)->lock),NULL)
#define SS_LOCK_DESTROY(p) ss_mutex_destroy(&((p)->lock))
#define SS_COND_INIT(p) ss_cond_init(&((p)->cond),NULL)
#define SS_COND_SIGNAL(p) ss_cond_destroy(&((p)->cond))
#define SS_COND_WAIT(p) ss_cond_wait(&((p)->cond),&((p)->lock))
#define SS_COND_DESTROY(p) ss_cond_destroy(&((p)->cond))

#define SS_LOCK(p)  ss_mutex_lock(&((p)->lock)) 
#define SS_UNLOCK(p) ss_mutex_unlock(&((p)->lock))



#endif //_SS_THREAD_H_
