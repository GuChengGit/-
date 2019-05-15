
#ifndef __LB_MP3_INFO_H__
#define __LB_MP3_INFO_H__

typedef struct LB_MP3_INFO
{
	int nSize ;                 /* �ýṹ��Ĵ�С */
	BOOL IsVBR ;                /* �Ƿ�Ϊ������ */

	int nEstimatedLengthSec ;   /* ����ʱ�� */
	int nFileSize ;             /* �ļ���С */

}LB_MP3_INFO ;



BOOL GetMP3Info(LPCTSTR szFile, LB_MP3_INFO * pInfo) ;


#endif // __LB_MP3_INFO_H__
