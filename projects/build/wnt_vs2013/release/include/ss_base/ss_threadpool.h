/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_threadpool.h
* @brief LonbonVoip architecture thread pool definitions.
*
* @author	Qiusheng Li
* @date	2008-11-1
*
*/
#ifndef _SS_THREADPOOL_H
#define _SS_THREADPOOL_H

#include "ss_base/ss_def.h"
#include "ss_base/ss_thread.h"
#include "ss_base/ss_list.h"


typedef struct _ss_threadpool_t
{
	/** Number of task consumers */
	int _nbconsumers;

	/** Working threads */
	ss_thread_t **_consumer;

	/** Queue of tasks contexts */
	MSList *_taskList;

	/** Size of the largest accepted queue */
	int _queueSize;

	/** Is the pool accepting tasks */
	BOOL _isClosed;

	/** Is the object being destroyed */
	BOOL _isDestroyed;

	/** Mutex protecting the task queue */
	ss_mutex_t lock;

	/** Condition that signals the task is empty*/
	ss_cond_t _task_empty;

	/** Condition that signals the task queue is not empty */
	ss_cond_t _task_not_empty;

	/** Condition that signals the task queue is not full */
	ss_cond_t _task_not_full;
}ss_threadpool_t;

SS_API ss_threadpool_t * ss_threadpool_new(int queueSize);
SS_API void ss_threadpool_destroy(ss_threadpool_t **tpi);
SS_API int ss_threadpool_push(ss_threadpool_t *tp, void (*consume)(void *),void (*destroy)(void *), void *arg);
#endif //_SS_THREADPOOL_H
