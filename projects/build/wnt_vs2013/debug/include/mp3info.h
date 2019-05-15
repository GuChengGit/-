
#ifndef __LB_MP3_INFO_H__
#define __LB_MP3_INFO_H__

typedef struct LB_MP3_INFO
{
	int nSize ;                 /* 该结构体的大小 */
	BOOL IsVBR ;                /* 是否为变码率 */

	int nEstimatedLengthSec ;   /* 评估时间 */
	int nFileSize ;             /* 文件大小 */

}LB_MP3_INFO ;



BOOL GetMP3Info(LPCTSTR szFile, LB_MP3_INFO * pInfo) ;


#endif // __LB_MP3_INFO_H__
