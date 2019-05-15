/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_callback.h
* @brief Generic Callback Defination.
*
* @author	Qiusheng Li
* @date	2008-10-20
*
*/
#ifndef _SS_CALLBACK_H_
#define _SS_CALLBACK_H_

#include "ss_base/ss_list.h"

typedef struct _SS_Callback SS_Callback;

typedef void (*SS_CallbackFunc)(void * call_arg);
typedef void (*SS_CallbackCall)(SS_Callback* cb);


typedef struct _SS_CallbackListener {
	SS_CallbackFunc callback;
	void * user_data;
}SS_CallbackListener;

struct _SS_Callback{
	MSList *listeners;
	SS_CallbackCall call;
}; 

SS_API SS_Callback* SS_Callback_new ();
SS_API void SS_Callback_destroy (SS_Callback* cb);
SS_API void SS_Callback_register(SS_Callback* cb, SS_CallbackFunc cbf, void * user_data);
SS_API SS_CallbackListener* SS_CallbackListener_new(SS_CallbackFunc cbf, void * user_data);
SS_API void SS_CallbackListener_destroy (SS_CallbackListener* cbl);
#endif /* _SS_CALLBACK_H_ */
