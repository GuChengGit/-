/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_logger.h
* @brief LonbonVoip architecture logger system definitions.
*
* @author	Qiusheng Li
* @date	2008-09-10
*
*/
#ifndef _SS_LOGGER_H_
#define _SS_LOGGER_H_

#include <stdio.h>
#include "ss_base/ss_def.h"

typedef enum {
	SS_LOG_LEVEL_TRACE	 = 0,
	SS_LOG_LEVEL_DEBUG		,
	SS_LOG_LEVEL_INFO		,
	SS_LOG_LEVEL_WARN		,
	SS_LOG_LEVEL_ERROR		,
	SS_LOG_LEVEL_FATAL
} sslog_level_t;

typedef enum {
	SS_LOG_MODEL_NONE = 0,
	SS_LOG_MODEL_STDERR,
	SS_LOG_MODEL_FILE
} sslog_model_t;

typedef enum {
	SS_LOG_FORMAT_NONE=0,
	SS_LOG_FORMAT_TIME,
	SS_LOG_FORMAT_TIME_FILE_LINE,
	SS_LOG_FORMAT_TIME_FILE_LINE_FUNCTION
} sslog_format_t;

#define SS_TRACE		SS_LOG_LEVEL_TRACE, __FILE__, __LINE__,__FUNCTION__
#define SS_DEBUG		SS_LOG_LEVEL_DEBUG, __FILE__, __LINE__,__FUNCTION__
#define SS_INFO			SS_LOG_LEVEL_INFO,  __FILE__, __LINE__,__FUNCTION__
#define SS_WARN			SS_LOG_LEVEL_WARN,  __FILE__, __LINE__,__FUNCTION__
#define SS_ERROR		SS_LOG_LEVEL_ERROR, __FILE__, __LINE__,__FUNCTION__
#define SS_FATAL		SS_LOG_LEVEL_FATAL, __FILE__, __LINE__,__FUNCTION__

#define SS_LOG				sslogger_log

#define SS_LOG_INIT		    sslogger_init
#define SS_LOG_CLOSE		sslogger_close
#define SS_LOG_ENABLED		sslogger_isEnabled

#define DEFAULT_SS_LOG_LEVEL SS_LOG_LEVEL_DEBUG
#define DEFAULT_SS_LOG_MODEL SS_LOG_MODEL_STDERR
#define DEFAULT_SS_LOG_FORMAT SS_LOG_FORMAT_TIME_FILE_LINE_FUNCTION
#define DEFAULT_SS_LOG_FILE_NAME  "ss_log.log"


SS_API int sslogger_init(sslog_level_t current_sslog_level,sslog_model_t current_sslog_model,sslog_format_t current_sslog_format,const char* sslog_file_name);
SS_API int sslogger_log(sslog_level_t level,const char *subject,int lineno,const char *function,const char *output, ...);
SS_API int sslogger_close();
SS_API BOOL sslogger_isEnabled();
SS_API FILE * get_sslogger();

#ifndef NDEBUG
#define SS_LOG_INIT_DEFAULT() \
	do{ \
	sslogger_init(DEFAULT_SS_LOG_LEVEL,DEFAULT_SS_LOG_MODEL,DEFAULT_SS_LOG_FORMAT,DEFAULT_SS_LOG_FILE_NAME); \
	} while(0)

#else
#define SS_LOG_INIT_DEFAULT() \
	do{ \
	sslogger_init(DEFAULT_SS_LOG_LEVEL,SS_LOG_MODEL_NONE,DEFAULT_SS_LOG_FORMAT,DEFAULT_SS_LOG_FILE_NAME); \
	} while(0)

#endif


#endif
