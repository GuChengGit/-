/**
 * LonbonVoip -- Lonbon VOIP Interface
 * Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
 *
 * This file is part of lonbon ip intercom system.
 *
 */

/**
 * @file ss_base/ss_error.h
 * @brief LonbonVOIP architecture error handler definitions.
 *
 * @author	Qiusheng Li
 * @date	2008-10-20
 *
 */
#ifndef _SS_ERROR_H_
#define _SS_ERROR_H_

#include "ss_base/ss_def.h"


#define BASE_ERROR_NO						5000

typedef enum _SS_Error
{
	NULL_POINTER_EXCEPTION=BASE_ERROR_NO,
	INVALIDE_PARAMETER_EXCEPTION,
	EMPTY_STRING_EXCEPTION,
	CAN_NOT_OPEN_CONFIG_FILE_EXCEPTION,
	CAN_NOT_OPEN_LOG_FILE_EXCEPTION,
	NOT_SUPPORT_FOR_THIS_PLATFORM
}SS_Error;

#ifdef _WIN32_WCE
#ifndef errno
extern int errno;
#endif
#endif

SS_API const char * getErrorMessage(int errorNo);


#endif /*_SS_ERROR_H_*/
