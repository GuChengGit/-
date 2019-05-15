/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_util.h
* @brief LonbonVoip architecture util functions definitions.
*
* @author	Qiusheng Li
* @date	2008-09-08
*
*/
#ifndef _SS_UTILS_H_
#define _SS_UTILS_H_
#include <stdarg.h>
#include "ss_base/ss_def.h"
#include "ss_base/ss_list.h"
#include "ss_base/ss_callback.h"

typedef void (*_fn_run_in_thread)(void*);

SS_Callback *getRebootCB();
void setRebootCB(SS_Callback * cb);


SS_API void* safe_malloc (size_t sz);
SS_API void* safe_malloc0 (size_t sz);

SS_API unsigned char* getMulticastAddressFromMac(const char* mac);
SS_API unsigned char* convertIPIntToString(const unsigned int dwIfIpAddr);
SS_API unsigned char* getAutoIPFromNumber(int master,int slave);

SS_API unsigned int convertIPStringToInt(const unsigned char* ip);
SS_API int isValidIP(const char *ipStr);
SS_API int isValidNetmask(const char *ipStr);
SS_API BOOL isInSameSubnet(const unsigned char*ip1,const unsigned char*ip2,const unsigned char* subnetMask);
SS_API char* getMulticastAddress(const unsigned char* mac);

SS_API int splitHTMLPostString(const char *str,  char***keys, char***values, int *numberOfKeys) ;
SS_API void HttpDecodeString(unsigned char* pchString);
SS_API unsigned char *HttpEncodeString(const unsigned char *src);

#if defined(_MSC_VER) || defined(ANDROID) 
SS_API unsigned char *HttpUnicodeEncodeString(const unsigned char *src);
SS_API void HttpUnicodeDecodeString(unsigned char *src);
SS_API void HttpUTF8DecodeString(unsigned char *src);
#endif

SS_API char* getHtmlPostParameter(const char* contentStr,const char*para);
SS_API BOOL isLastMultipartPostData(const char* data);

SS_API int generateId(unsigned int *id);
SS_API int generateStringId(char **id);
SS_API int generateRand(unsigned int seed,unsigned int maxInt);
SS_API int generateRand2(unsigned int minInt,unsigned int maxInt);
SS_API void generateTempFile(char *tmpFilename);
SS_API int addToIntArray(int **intArray,int*length,const  int intValue);
SS_API void createPidFile(const char *pidfile);
SS_API void createRestoreFactoryPid();

SS_API char* ms_list_to_string(const MSList* msList,const char* token);
SS_API MSList* string_to_ms_list(const char* str,const char* token);
SS_API void replaceStrInFile(const char* configFile,const char* oldStr,const char* newStr);
SS_API void resetWSDLLocation();
SS_API char* getKeyStringValueInFile(const char* configFile,const char* key,const char* defaultVal);
SS_API int setKeyStringValueInFile(const char* configFile,const char* key,const char* val);
SS_API int getKeyIntValueInFile(const char* configFile,const char* key,const int defaultVal);
SS_API int setKeyIntValueInFile(const char* configFile,const char* key,const int val);

SS_API int getMaxInput(char* s,int maxLength);
SS_API int generateSdkSN(char**sn,char**user,char**pwd);
SS_API int getFirstHZLetters(const unsigned char *str, char* abbr);
#if defined(_MSC_VER) && !defined(_WIN32_WCE)
	SS_API int getPassword(char* s,int maxLength);
#endif
SS_API int changeSlashesToBackslashes(char *path);
SS_API int initRunningPath(char path[]);
SS_API char* getFileShortName(const char* fullName);
SS_API const char *getFileExtention(const char* fullName);
SS_API char* getFileDirectory(const char* fullName);
SS_API int getFileDirAndShortName(const char* fullName,char **dirName,char**shortName);
SS_API char* getFileBackupName(const char* fullName);
SS_API void checkFileDirectory(const char* fullName);
SS_API char* getFileContent(const char* fullName);
SS_API int getFileSize( const char *fileName );
SS_API int readLineFromFile(char * str, int num, FILE * fp );
SS_API char* readLineFromFile2(FILE * fp );
SS_API BOOL isLonbonVoipServer(const char* server);
SS_API BOOL isLonbonOnlyFunction();
SS_API int getNetworkInfo(char **mac,BOOL *isEnableDHCP,char**ip,char**ip2,char**netmask,char**gateway,char**dns1,char**dns2);
SS_API int SS_setStaticIP(const char* ip1,const char* ip2,const char* netmask,const char* gateway,const char* dns1,const char* dns2);

SS_API char* getMAC();
SS_API char* getLocalIP();
SS_API int getDiskSpace(const char* dirName,unsigned long long *totalSpace,double *usedRate,unsigned long long *availableSpace);
SS_API int convertUUID2Int(unsigned char* uuid,unsigned int *uniqueId);
SS_API int convertUUID2Int2(unsigned char* uuid,unsigned int *uniqueId);
SS_API int convertByteSize2String(int nFileSize,char *sFileSize);
SS_API int mp3Check(const char *mp3file, int *isLBValid,long *size);
SS_API BOOL isNewNKVersion(const char *nk,int y,int m,int d);
SS_API BOOL isNewSoftVersion(const char *softVersion,int y,int m,int d);
SS_API BOOL isSoftNewThanNK(const char *nkVersion,const char *softVersion);
SS_API unsigned int getStringCrc32(char* InStr);
SS_API unsigned short GetCrc16(char* InStr);
SS_API void ss_reboot();
SS_API BOOL isDebugEnvEnabled();
SS_API void SS_RunCallbackInThread(SS_CallbackFunc cbf, void * user_data);
SS_API BOOL isHttpdRunning(const char* ip);
SS_API BOOL isLocalHttpdRunning();
SS_API void print_hex_string(unsigned char *str,int length);
SS_API void print_hex_wchar(unsigned short *wStr,int length);
SS_API int ss_short_len(const unsigned short *ucs);
SS_API int ss_utf16_len(const unsigned char *ucs);
SS_API BOOL isBinaryEqual(const unsigned char *a,const unsigned char *b,int length);
SS_API BOOL isWCharEqual(const unsigned short *a,const unsigned short  *b,int length);
#if !(defined(_WIN32_WCE)||defined(_NNOS))
SS_API char * getOutputString(const char* systemCmd);
SS_API char * getFileChecksum(const char* filePath);
SS_API BOOL command_line_sync(const char *command, char **result,int *command_ret);
#endif

SS_API int getFileAdditionalInfo(const char* archfile,char **addInfo,int *length);

#ifndef _NNOS
SS_API int fileEncrypt(const char* filename);
SS_API int fileDecrypt(const char* filename);
#endif
/**
参数 mode 有下列数种组合：
1、S_ISUID 04000 文件的 (set user-id on execution)位
2、S_ISGID 02000 文件的 (set group-id on execution)位
3、S_ISVTX 01000 文件的sticky 位
4、S_IRUSR (S_IREAD) 00400 文件所有者具可读取权限
5、S_IWUSR (S_IWRITE)00200 文件所有者具可写入权限
6、S_IXUSR (S_IEXEC) 00100 文件所有者具可执行权限
7、S_IRGRP 00040 用户组具可读取权限
8、S_IWGRP 00020 用户组具可写入权限
9、S_IXGRP 00010 用户组具可执行权限
10、S_IROTH 00004 其他用户具可读取权限
11、S_IWOTH 00002 其他用户具可写入权限
12、S_IXOTH 00001 其他用户具可执行权限
*/


#ifndef _MSC_VER
#define SS_PERMISSION_777	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)
#define SS_PERMISSION_770	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP)
#define SS_PERMISSION_775	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IXOTH)
#define SS_PERMISSION_755	(S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IXOTH)
#define SS_PERMISSION_700	(S_IRUSR|S_IWUSR|S_IXUSR)
#define SS_PERMISSION_644	(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH)
#define SS_PERMISSION_600	(S_IRUSR|S_IWUSR)

SS_API int  find_pid_by_name(const char* pidName);
SS_API int get_httpd_connect_number();
SS_API int ss_get_owner(const char* filename,int *uid,int*gid);
SS_API int ss_set_owner(const char* filename,int uid,int gid);
SS_API int ss_set_premission( const char *filename, int pmode );
#endif
SS_API void SS_LOCK_FILE(const char* fileLockName);
SS_API void SS_UNLOCK_FILE(const char* fileLockName);
SS_API void cleanTempDirectory();
SS_API char *getProcessName();
SS_API char *getLbcmdDevice();
SS_API void format_path_slash(char *path);
SS_API int format_mac(char *mac);
#endif //_SS_UTILS_H_
