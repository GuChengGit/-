#ifndef _SS_DIR_H_
#define _SS_DIR_H_
#ifndef _NNOS
#ifdef _MSC_VER
#include <windows.h>
#include "ss_base/ss_winapi.h"

struct dirent {
	unsigned char d_name[MAX_PATH];
};

typedef struct _DIR {
	HANDLE			handle;
	WIN32_FIND_DATAW	info;
	struct dirent result;
} DIR;

#define	set_close_on_exec(fd)	/* No FD_CLOEXEC on Windows */


SS_API DIR* opendir(const char *name);
SS_API int closedir(DIR *dir);
SS_API struct dirent* readdir(DIR *dir);
SS_API unsigned long getFileAttributes(const char* filename);
SS_API void setFileAttributes(const char* filename,unsigned long newAttrs);
#else
#	include <dirent.h>
BOOL chmodfile(const char* filename,const char* s_mode);
#endif  //_MSC_VER
SS_API BOOL deleteDirContent(const char * path,const char **extFiles,const int length);
SS_API BOOL deletedir(const char * name);
SS_API BOOL createdir(const char * name);

SS_API BOOL existfile(const char* filename);
SS_API BOOL existdevice(const char* devicename);
SS_API BOOL existdir(const char* dirname);
SS_API BOOL deletefile(const char* filename);
SS_API BOOL copyfile(const char* from, const char* to);
SS_API BOOL movefile(const char* from, const char* to);
SS_API BOOL deletefileForce(const char* filename);
SS_API BOOL isSameFile(const char* filename1,const char* filename2);
#endif
#endif  //_SS_DIR_H_
