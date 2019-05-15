#ifndef  __LB_PUBLIC_DAO_H__
#define  __LB_PUBLIC_DAO_H__

#include "lb_headdef.h"

LB_BEGIN_DECL

typedef struct _LB_PUBLIC_SLAVE_DETAIL
{
	char *reportMain;
	char *reportAttach;
	char *desc;
	char *areaNum;
	int devType;
	
}LB_PUBLIC_DEVICE_DETAIL;

/* @method 获取指定设备属性信息
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @param *detailInfo 分机属性信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_public_get_device_detail_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_PUBLIC_DEVICE_DETAIL **detailInfo);

/* @method 根据房间床位号获取分机信息
* @param *zoneNumber 病区号
* @param *reportMain 主播报号码
* @param *reportAttach 副播报号码
* @param devType 设备类型
* @output *accId	账号序号（默认0）
* @output *areaId	地址盒区号
* @output *master_number 主机号
* @output *slave_number 分机号
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_public_get_slave_info_from_detail_info(char *zoneNumber, char *reportMain, char *reportAttach, int devType, int *accId, int *areaId, int *master_number, int *slave_number, int *devRegType);


/* @method 设置指定设备属性信息
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @param *detailInfo 分机属性信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_public_set_device_detail_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_PUBLIC_DEVICE_DETAIL *detailInfo);

/* @method 删除设备属性信息
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_public_delete_device_detail_info(int accId, int areaId, int master_number, int slave_number, int devRegType);

/* @method 销毁设备属性信息
* @param *detailInfo 分机属性信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_public_destory_device_detail_info(LB_PUBLIC_DEVICE_DETAIL *detailInfo);

typedef struct _LB_PUBLIC_DOT_MATRIX_DETAIL
{
	char *ip;
	char *port;

}LB_PUBLIC_DOT_MATRIX_DETAIL;

/* @method 获取所有显示屏信息
* @param **dotMatrixDetail 显示屏信息
* @return -1 失败，>= 0 返回显示屏信息条数
*/
LB_EXPORT int lb_public_get_dot_matrix_detail_info(LB_PUBLIC_DOT_MATRIX_DETAIL **dotMatrixDetail);

/* @method 设置显示屏信息
* @param *dotMatrixDetail 显示屏信息
* @param dotMatrixDetailCnt	显示屏信息条数
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_public_set_dot_matrix_detail_info(LB_PUBLIC_DOT_MATRIX_DETAIL *dotMatrixDetail, int dotMatrixDetailCnt);

/* @method 销毁显示屏信息
* @param *dotMatrixDetail 显示屏信息
* @param dotMatrixDetailCnt	显示屏信息条数
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_public_destory_dot_matrix_detail_info(LB_PUBLIC_DOT_MATRIX_DETAIL *dotMatrixDetail, int dotMatrixDetailCnt);

/* @method 库初始化接口
*/
LB_EXPORT int lb_public_dao_init();

/* @method 库销毁接口
* @param void
*/
LB_EXPORT int lb_public_dao_destory(void);

LB_END_DECL

#endif
