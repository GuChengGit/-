#ifndef _LB_GPDEV_H
#define _LB_GPDEV_H
#include "lb_headdef.h"

LB_BEGIN_DECL
typedef struct _lb_gpDevInfo_s
{
	int displayNum;
	int groupNum;
	int localDevNum;
} lb_gpDevInfo_s;

/*��ȡ�豸����ΪdevRegType������Ϣ����*/
LB_EXPORT int lb_gpDev_getGpDevInfoCnt(int devRegType);

/*��ȡ�豸����ΪdevRegType������豸������ʾ�ŵĶ�Ӧ��Ϣ��
* bufCnt Ϊ�������ĸ���
* infoCnt ʵ����Ϣ�ĸ���
*/
LB_EXPORT int lb_gpDev_getGpDevInfoList(int devRegType,lb_gpDevInfo_s *infoListBuf,int bufCnt,int *infoCnt);

/*�����豸���ͺ���ʾ�Ż�ȡ����豸��*/
LB_EXPORT int lb_gpDev_getGroupNumDevNum_fromDisplayNum(int devRegType,int displayNum,int *groupNum,int *localNum);

/*�����豸���ͺ�����豸�Ż�ȡ��ʾ��*/
LB_EXPORT int lb_gpDev_getDisplayNum_fromGroupNumDevNum(int devRegType,int groupNum,int localNum,int *displayNum);

LB_END_DECL
#endif
