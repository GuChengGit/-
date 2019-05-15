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

/*获取设备类型为devRegType的组信息个数*/
LB_EXPORT int lb_gpDev_getGpDevInfoCnt(int devRegType);

/*获取设备类型为devRegType的组号设备号与显示号的对应信息，
* bufCnt 为缓冲区的个数
* infoCnt 实际信息的个数
*/
LB_EXPORT int lb_gpDev_getGpDevInfoList(int devRegType,lb_gpDevInfo_s *infoListBuf,int bufCnt,int *infoCnt);

/*根据设备类型和显示号获取组号设备号*/
LB_EXPORT int lb_gpDev_getGroupNumDevNum_fromDisplayNum(int devRegType,int displayNum,int *groupNum,int *localNum);

/*根据设备类型和组号设备号获取显示号*/
LB_EXPORT int lb_gpDev_getDisplayNum_fromGroupNumDevNum(int devRegType,int groupNum,int localNum,int *displayNum);

LB_END_DECL
#endif
