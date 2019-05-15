#ifndef _LB_FTP_H
#define _LB_FTP_H
#include <Windows.h>
#ifdef __cplusplus
extern "C"{
#endif

#if defined(WIN32) && !defined(__MINGW32__) && !defined(__CYGWIN__)
	typedef unsigned __int64 uint64_t;
#     else /* other OS */
	typedef unsigned long long uint64_t;
#     endif /* other OS */

typedef uint64_t fsz_t;


#ifdef _USE_DLL
#if defined(__unix__)
#define LB_EXPORT extern
#elif defined(WIN32) || defined(WINCE)
#define LB_EXPORT __declspec(dllexport)
#else
#define LB_EXPORT 
#endif
#else
#define LB_EXPORT 
#endif

/*文件上传或下载时的回调函数，主要用于反馈进度
* file：文件名称（包含路径），上传时，本地文件名称，下载时，服务器上的文件名称
* fileSize：文件大小
* xferSize：已经传输的大小
* 返回值：0－成功，否则失败
*/
typedef int (WINAPI *lbFtpXferCallback)(char *file, fsz_t fileSize, fsz_t xferSize);

typedef enum _lbFtp_mode_e
{
	LBFTPMD_PASS=0,              //被动方式
	LBFTPMD_PORT                 //主动方式
}lbFtp_mode_e;

typedef enum _lbFtp_dataTyp_e
{
	LBFTPDTP_ASCII=0,            //ASCII传输模式
	LBFTPDTP_IMAGE               //二进制传输模式
}lbFtp_dataTyp_e;

typedef enum _lbFtp_fileTyp_e
{
	LBFTPFLTP_NONE=0,
	LBFTPFLTP_FILE,    //文件
	LBFTPFLTP_DIR      //目录
}lbFtp_fileTyp_e;

typedef struct _lbFtp_file_s
{
	struct _lbFtp_file_s *next;         //指向下一个同级文件或目录
	struct _lbFtp_file_s *childList;    //指向子目录的文件列表，文件节点的本字段为NULL
	char *fileName;                     //文件名或目录名
	lbFtp_fileTyp_e fileType;           //类型
	fsz_t fsz;                          //文件大小，文件才有效，目录无效
}lbFtp_file_s;

#define LBFTPRET_SUCC               0         //成功
#define LBFTPRET_FTPCMD_FAIL        -1        //命令执行失败
#define LBFTPRET_FTPCONN_FAIL       -2        //FTP连接失败
#define LBFTPRET_FTPLOGIN_FAIL      -3        //FTP登录失败
#define LBFTPRET_OTHER_FAIL         -4        //其他错误

/*获取错误信息
* 返回值：错误信息
*/
LB_EXPORT char *lb_ftp_getLastErrorInfo(void);

/*初始化
* ftpSvrAddr：FTP服务器地址，支持：192.168.1.4
                                   192.168.1.4/recfile
                                   ftp://192.168.1.4
                                   FTP://192.168.1.4
								   ftp://192.168.1.4/recfile
								   ftp://192.168.1.4:21
								   ftp://192.168.1.4:21/recfile
* user：用户名，为NULL则匿名登录
* pwd：密码
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_initial(char *ftpSvrAddr,char *user,char *pwd);

/*释放
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_destroy(void);

/*探测是否可以成功连接FTP服务器
* 配置不正确，网络不可达，服务器没启动等都可能是导致失败的原因
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_serverState_check(void);

/*上传单个文件
* localFile：要上传的本地文件的文件名
* remotePath：文件要存放的目录
* mode：FTP工作方式
* dataTyp：数据传输模式
* sendProgressNotify：回调函数
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_put(char *localFile,char *remotePath,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback sendProgressNotify);

/*下载单个文件
* localPath：文件要存放的目录
* remoteFile：要下载的远程文件的文件名
* mode：FTP工作方式
* dataTyp：数据传输模式
* rcvProgressNotify：回调函数
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_get(char *localPath,char *remoteFile,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback rcvProgressNotify);

/*删除FTP服务器上的文件
* remoteFile：要删除的远程文件的文件名
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_delete(char *remoteFile);

/*在服务器上创建目录
* dir：目录名
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_make_dir(char *dir);

/*切换FTP连接的当前工作目录，这个接口没有实际意义，因为切换后，连接就关闭了，可以作为检测该目录是否存在的接口使用
* dir：目录名
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_change_dir(char *dir);

/*列出目录下的所有文件和目录，子目录
* fileList：获取的文件列表
* dir：目录名
* mode：FTP工作方式
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_list_dir(lbFtp_file_s **fileList,char *dir,lbFtp_mode_e mode);

/*上传多个文件到指定目录
* localFiles：要上传的本地文件的文件名列表
* fileCnt：文件个数
* remotePath：文件要存放的目录
* mode：FTP工作方式
* dataTyp：数据传输模式
* sendProgressNotify：回调函数
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_put_files(char **localFiles,int fileCnt,char *remotePath,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback sendProgressNotify);

/*下载多个文件到指定目录
* localPath：文件要存放的目录
* remoteFiles：要下载的远程文件的文件名列表
* fileCnt：文件个数
* mode：FTP工作方式
* dataTyp：数据传输模式
* rcvProgressNotify：回调函数
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_get_files(char *localPath,char **remoteFiles,int fileCnt,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback rcvProgressNotify);

/*删除多个文件
* remoteFiles：要删除的远程文件的文件名列表
* fileCnt：文件个数
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_delete_files(char **remoteFiles,int fileCnt);

/*上传目录，同名不覆盖
* localDir：要上传的本地目录
* remotePath：要存放的目录
* mode：FTP工作方式
* dataTyp：数据传输模式
* sendProgressNotify：回调函数
* createMainDir：TRUE—在“remotePath”目录下新建一个目录（存在就不建）来存放“localDir”目录下的文件，例如本地目录为“recordfile/today”，则会在“remotePath”下新建目录“today”；
*                FALSE－直接将“localDir”目录下的文件上传到“remotePath”目录下
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_put_dir(char *localDir,char *remotePath,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback sendProgressNotify,BOOL createMainDir);

/*下载目录，同名不覆盖
* localPath：要存放的目录
* remoteDir：要下载的远程目录
* mode：FTP工作方式
* dataTyp：数据传输模式
* rcvProgressNotify：回调函数
* createMainDir：TRUE—在“localPath”目录下新建一个目录（存在就不建）来存放“remoteDir”目录下的文件，例如远程目录为“recordfile/today”，则会在“localPath”下新建目录“today”；
*                FALSE－直接将“remoteDir”目录下的文件下载到“localPath”目录下
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_get_dir(char *localPath,char *remoteDir,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback rcvProgressNotify,BOOL createMainDir);

/*删除远程目录
* remoteDir：要删除的远程目录
* mode：FTP工作方式
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_remove_dir(char *remoteDir,lbFtp_mode_e mode);

/*新建lbFtp_file_s节点
* fileName：文件名或目录名
* type：类型
* fsz：大小，如果是目录则为0
* 返回值：成功则返回lbFtp_file_s节点，失败返回NULL
*/
LB_EXPORT lbFtp_file_s *lb_ftp_fileInfo_new(char *fileName,lbFtp_fileTyp_e type,fsz_t fsz);

/*释放文件（目录）节点
* fileInfo：要释放的节点
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_fileInfo_destroy(lbFtp_file_s *fileInfo);

/*为目录节点设置该目录下的文件列表
* fileInfo：目录节点
* childFileList：子目录文件列表
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_fileInfo_addChild(lbFtp_file_s *fileInfo,lbFtp_file_s *childFileList);

/*增加同级的兄弟文件（目录）节点
* fileList：文件列表
* brotherFileInfo：文件或目录节点
* 返回值：文件列表头
*/
LB_EXPORT lbFtp_file_s *lb_ftp_fileList_addBrother(lbFtp_file_s *fileList,lbFtp_file_s *brotherFileInfo);

/*释放文件列表
* fileList：文件列表
* 返回值：0－成功，否则失败
*/
LB_EXPORT int lb_ftp_fileList_destroy(lbFtp_file_s *fileList);

/*获取本地目录的文件列表
* dir：本地目录
* 返回值：文件列表头
*/
LB_EXPORT lbFtp_file_s *getLocalFileList(char *dir);
#ifdef __cplusplus
}
#endif
#endif