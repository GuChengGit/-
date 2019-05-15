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

/*�ļ��ϴ�������ʱ�Ļص���������Ҫ���ڷ�������
* file���ļ����ƣ�����·�������ϴ�ʱ�������ļ����ƣ�����ʱ���������ϵ��ļ�����
* fileSize���ļ���С
* xferSize���Ѿ�����Ĵ�С
* ����ֵ��0���ɹ�������ʧ��
*/
typedef int (WINAPI *lbFtpXferCallback)(char *file, fsz_t fileSize, fsz_t xferSize);

typedef enum _lbFtp_mode_e
{
	LBFTPMD_PASS=0,              //������ʽ
	LBFTPMD_PORT                 //������ʽ
}lbFtp_mode_e;

typedef enum _lbFtp_dataTyp_e
{
	LBFTPDTP_ASCII=0,            //ASCII����ģʽ
	LBFTPDTP_IMAGE               //�����ƴ���ģʽ
}lbFtp_dataTyp_e;

typedef enum _lbFtp_fileTyp_e
{
	LBFTPFLTP_NONE=0,
	LBFTPFLTP_FILE,    //�ļ�
	LBFTPFLTP_DIR      //Ŀ¼
}lbFtp_fileTyp_e;

typedef struct _lbFtp_file_s
{
	struct _lbFtp_file_s *next;         //ָ����һ��ͬ���ļ���Ŀ¼
	struct _lbFtp_file_s *childList;    //ָ����Ŀ¼���ļ��б��ļ��ڵ�ı��ֶ�ΪNULL
	char *fileName;                     //�ļ�����Ŀ¼��
	lbFtp_fileTyp_e fileType;           //����
	fsz_t fsz;                          //�ļ���С���ļ�����Ч��Ŀ¼��Ч
}lbFtp_file_s;

#define LBFTPRET_SUCC               0         //�ɹ�
#define LBFTPRET_FTPCMD_FAIL        -1        //����ִ��ʧ��
#define LBFTPRET_FTPCONN_FAIL       -2        //FTP����ʧ��
#define LBFTPRET_FTPLOGIN_FAIL      -3        //FTP��¼ʧ��
#define LBFTPRET_OTHER_FAIL         -4        //��������

/*��ȡ������Ϣ
* ����ֵ��������Ϣ
*/
LB_EXPORT char *lb_ftp_getLastErrorInfo(void);

/*��ʼ��
* ftpSvrAddr��FTP��������ַ��֧�֣�192.168.1.4
                                   192.168.1.4/recfile
                                   ftp://192.168.1.4
                                   FTP://192.168.1.4
								   ftp://192.168.1.4/recfile
								   ftp://192.168.1.4:21
								   ftp://192.168.1.4:21/recfile
* user���û�����ΪNULL��������¼
* pwd������
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_initial(char *ftpSvrAddr,char *user,char *pwd);

/*�ͷ�
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_destroy(void);

/*̽���Ƿ���Գɹ�����FTP������
* ���ò���ȷ�����粻�ɴ������û�����ȶ������ǵ���ʧ�ܵ�ԭ��
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_serverState_check(void);

/*�ϴ������ļ�
* localFile��Ҫ�ϴ��ı����ļ����ļ���
* remotePath���ļ�Ҫ��ŵ�Ŀ¼
* mode��FTP������ʽ
* dataTyp�����ݴ���ģʽ
* sendProgressNotify���ص�����
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_put(char *localFile,char *remotePath,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback sendProgressNotify);

/*���ص����ļ�
* localPath���ļ�Ҫ��ŵ�Ŀ¼
* remoteFile��Ҫ���ص�Զ���ļ����ļ���
* mode��FTP������ʽ
* dataTyp�����ݴ���ģʽ
* rcvProgressNotify���ص�����
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_get(char *localPath,char *remoteFile,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback rcvProgressNotify);

/*ɾ��FTP�������ϵ��ļ�
* remoteFile��Ҫɾ����Զ���ļ����ļ���
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_delete(char *remoteFile);

/*�ڷ������ϴ���Ŀ¼
* dir��Ŀ¼��
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_make_dir(char *dir);

/*�л�FTP���ӵĵ�ǰ����Ŀ¼������ӿ�û��ʵ�����壬��Ϊ�л������Ӿ͹ر��ˣ�������Ϊ����Ŀ¼�Ƿ���ڵĽӿ�ʹ��
* dir��Ŀ¼��
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_change_dir(char *dir);

/*�г�Ŀ¼�µ������ļ���Ŀ¼����Ŀ¼
* fileList����ȡ���ļ��б�
* dir��Ŀ¼��
* mode��FTP������ʽ
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_list_dir(lbFtp_file_s **fileList,char *dir,lbFtp_mode_e mode);

/*�ϴ�����ļ���ָ��Ŀ¼
* localFiles��Ҫ�ϴ��ı����ļ����ļ����б�
* fileCnt���ļ�����
* remotePath���ļ�Ҫ��ŵ�Ŀ¼
* mode��FTP������ʽ
* dataTyp�����ݴ���ģʽ
* sendProgressNotify���ص�����
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_put_files(char **localFiles,int fileCnt,char *remotePath,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback sendProgressNotify);

/*���ض���ļ���ָ��Ŀ¼
* localPath���ļ�Ҫ��ŵ�Ŀ¼
* remoteFiles��Ҫ���ص�Զ���ļ����ļ����б�
* fileCnt���ļ�����
* mode��FTP������ʽ
* dataTyp�����ݴ���ģʽ
* rcvProgressNotify���ص�����
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_get_files(char *localPath,char **remoteFiles,int fileCnt,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback rcvProgressNotify);

/*ɾ������ļ�
* remoteFiles��Ҫɾ����Զ���ļ����ļ����б�
* fileCnt���ļ�����
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_delete_files(char **remoteFiles,int fileCnt);

/*�ϴ�Ŀ¼��ͬ��������
* localDir��Ҫ�ϴ��ı���Ŀ¼
* remotePath��Ҫ��ŵ�Ŀ¼
* mode��FTP������ʽ
* dataTyp�����ݴ���ģʽ
* sendProgressNotify���ص�����
* createMainDir��TRUE���ڡ�remotePath��Ŀ¼���½�һ��Ŀ¼�����ھͲ���������š�localDir��Ŀ¼�µ��ļ������籾��Ŀ¼Ϊ��recordfile/today��������ڡ�remotePath�����½�Ŀ¼��today����
*                FALSE��ֱ�ӽ���localDir��Ŀ¼�µ��ļ��ϴ�����remotePath��Ŀ¼��
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_put_dir(char *localDir,char *remotePath,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback sendProgressNotify,BOOL createMainDir);

/*����Ŀ¼��ͬ��������
* localPath��Ҫ��ŵ�Ŀ¼
* remoteDir��Ҫ���ص�Զ��Ŀ¼
* mode��FTP������ʽ
* dataTyp�����ݴ���ģʽ
* rcvProgressNotify���ص�����
* createMainDir��TRUE���ڡ�localPath��Ŀ¼���½�һ��Ŀ¼�����ھͲ���������š�remoteDir��Ŀ¼�µ��ļ�������Զ��Ŀ¼Ϊ��recordfile/today��������ڡ�localPath�����½�Ŀ¼��today����
*                FALSE��ֱ�ӽ���remoteDir��Ŀ¼�µ��ļ����ص���localPath��Ŀ¼��
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_get_dir(char *localPath,char *remoteDir,lbFtp_mode_e mode,lbFtp_dataTyp_e dataTyp,lbFtpXferCallback rcvProgressNotify,BOOL createMainDir);

/*ɾ��Զ��Ŀ¼
* remoteDir��Ҫɾ����Զ��Ŀ¼
* mode��FTP������ʽ
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_remove_dir(char *remoteDir,lbFtp_mode_e mode);

/*�½�lbFtp_file_s�ڵ�
* fileName���ļ�����Ŀ¼��
* type������
* fsz����С�������Ŀ¼��Ϊ0
* ����ֵ���ɹ��򷵻�lbFtp_file_s�ڵ㣬ʧ�ܷ���NULL
*/
LB_EXPORT lbFtp_file_s *lb_ftp_fileInfo_new(char *fileName,lbFtp_fileTyp_e type,fsz_t fsz);

/*�ͷ��ļ���Ŀ¼���ڵ�
* fileInfo��Ҫ�ͷŵĽڵ�
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_fileInfo_destroy(lbFtp_file_s *fileInfo);

/*ΪĿ¼�ڵ����ø�Ŀ¼�µ��ļ��б�
* fileInfo��Ŀ¼�ڵ�
* childFileList����Ŀ¼�ļ��б�
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_fileInfo_addChild(lbFtp_file_s *fileInfo,lbFtp_file_s *childFileList);

/*����ͬ�����ֵ��ļ���Ŀ¼���ڵ�
* fileList���ļ��б�
* brotherFileInfo���ļ���Ŀ¼�ڵ�
* ����ֵ���ļ��б�ͷ
*/
LB_EXPORT lbFtp_file_s *lb_ftp_fileList_addBrother(lbFtp_file_s *fileList,lbFtp_file_s *brotherFileInfo);

/*�ͷ��ļ��б�
* fileList���ļ��б�
* ����ֵ��0���ɹ�������ʧ��
*/
LB_EXPORT int lb_ftp_fileList_destroy(lbFtp_file_s *fileList);

/*��ȡ����Ŀ¼���ļ��б�
* dir������Ŀ¼
* ����ֵ���ļ��б�ͷ
*/
LB_EXPORT lbFtp_file_s *getLocalFileList(char *dir);
#ifdef __cplusplus
}
#endif
#endif