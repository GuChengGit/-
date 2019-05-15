#ifndef _SS_TIME_H_
#define _SS_TIME_H_
#include <time.h>
#include "ss_base/ss_def.h"
#if defined(_WIN32_WCE)||defined(_NNOS)
#	undef HAVE_STRFTIME
#	undef HAVE_STRPTIME
#	undef HAVE_MKTIME
#else
#	ifndef HAVE_STRFTIME
#		define HAVE_STRFTIME
#	endif
#	ifndef HAVE_MKTIME
#		define HAVE_MKTIME
#	endif
#   ifndef WIN32
#		ifndef HAVE_STRPTIME
#			define HAVE_STRPTIME
#		endif
#	endif
#endif 

#define DEFAULT_TIME_FORMAT "%Y-%m-%d %H:%M:%S"
#define DEFAULT_TIME_FORMAT_CST "%b %d, %Y %H:%M:%S"
#define DEFAULT_TIME_FORMAT_CST2 "%b %d %Y %H:%M:%S"
#define DEFAULT_TIME_STRING_LENGTH 19

typedef struct _ss_timer_t{
	unsigned long timer;
	unsigned long timerBegin;
	BOOL (*isTimeout)(struct _ss_timer_t*);
	void (*begin)(struct _ss_timer_t*);
	void (*setTimer)(struct _ss_timer_t*,unsigned long);
}ss_timer_t;

SS_API void ss_timer_destroy(ss_timer_t* ss_timer);
SS_API ss_timer_t* ss_timer_new(unsigned long timer);
SS_API unsigned long get_time_of_day (struct timeval *tv, void* tz) ;
SS_API unsigned long get_cur_time(void *unused);  //TimeOfDay
SS_API int convertMsToDHMS(const unsigned long ms,int* d,int*h,int*m,int*s);
SS_API int convertMsToString(const unsigned long ms,char str[]);
SS_API void sleep_ms(int ms);

/**
 * current_time must be a char[DEFAULT_TIME_STRING_LENGTH]
 */
SS_API void update_current_time_string(char *current_time);
SS_API int setLocalTime(const char *fmt,const char *current_time);

SS_API void time_to_string(const time_t theTime, char **time_str);
SS_API void string_to_time(const char *time_str,time_t* theTime);
SS_API void time_to_format_string(const time_t theTime,const char* time_format,char **time_str);
SS_API void format_string_to_time(const char *time_str,const char* time_format,time_t* theTime);

SS_API char* getCurrentTimeString(const char* format);
#ifdef _MSC_VER
SS_API char * strptime(const char *buf, const char *fmt, struct tm *tm);
#endif
#ifdef _WIN32_WCE
#ifndef HAVE_LOCALTIME_DEFINED
#define HAVE_LOCALTIME_DEFINED 1
#endif
SS_API struct tm *localtime( const time_t *timer );
SS_API time_t time( time_t *timer );
#endif

#ifndef HAVE_MKTIME
SS_API time_t mktime (struct tm *tim_p);
#endif
#ifndef HAVE_STRFTIME
SS_API size_t strftime (char *buf, size_t maxsize, const char *format, const struct tm *tm);
#endif
#endif  // _SS_TIME_H_
