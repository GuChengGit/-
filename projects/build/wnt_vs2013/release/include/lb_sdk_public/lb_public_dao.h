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

/* @method ��ȡָ���豸������Ϣ
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @param *detailInfo �ֻ�������Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_public_get_device_detail_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_PUBLIC_DEVICE_DETAIL **detailInfo);

/* @method ���ݷ��䴲λ�Ż�ȡ�ֻ���Ϣ
* @param *zoneNumber ������
* @param *reportMain ����������
* @param *reportAttach ����������
* @param devType �豸����
* @output *accId	�˺���ţ�Ĭ��0��
* @output *areaId	��ַ������
* @output *master_number ������
* @output *slave_number �ֻ���
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_public_get_slave_info_from_detail_info(char *zoneNumber, char *reportMain, char *reportAttach, int devType, int *accId, int *areaId, int *master_number, int *slave_number, int *devRegType);


/* @method ����ָ���豸������Ϣ
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @param *detailInfo �ֻ�������Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_public_set_device_detail_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_PUBLIC_DEVICE_DETAIL *detailInfo);

/* @method ɾ���豸������Ϣ
* @param accId	�˺���ţ�Ĭ��0��
* @param areaId	��ַ������
* @param master_number ������
* @param slave_number �ֻ���
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_public_delete_device_detail_info(int accId, int areaId, int master_number, int slave_number, int devRegType);

/* @method �����豸������Ϣ
* @param *detailInfo �ֻ�������Ϣ
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_public_destory_device_detail_info(LB_PUBLIC_DEVICE_DETAIL *detailInfo);

typedef struct _LB_PUBLIC_DOT_MATRIX_DETAIL
{
	char *ip;
	char *port;

}LB_PUBLIC_DOT_MATRIX_DETAIL;

/* @method ��ȡ������ʾ����Ϣ
* @param **dotMatrixDetail ��ʾ����Ϣ
* @return -1 ʧ�ܣ�>= 0 ������ʾ����Ϣ����
*/
LB_EXPORT int lb_public_get_dot_matrix_detail_info(LB_PUBLIC_DOT_MATRIX_DETAIL **dotMatrixDetail);

/* @method ������ʾ����Ϣ
* @param *dotMatrixDetail ��ʾ����Ϣ
* @param dotMatrixDetailCnt	��ʾ����Ϣ����
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_public_set_dot_matrix_detail_info(LB_PUBLIC_DOT_MATRIX_DETAIL *dotMatrixDetail, int dotMatrixDetailCnt);

/* @method ������ʾ����Ϣ
* @param *dotMatrixDetail ��ʾ����Ϣ
* @param dotMatrixDetailCnt	��ʾ����Ϣ����
* @return 0 �ɹ���-1 ʧ��
*/
LB_EXPORT int lb_public_destory_dot_matrix_detail_info(LB_PUBLIC_DOT_MATRIX_DETAIL *dotMatrixDetail, int dotMatrixDetailCnt);

/* @method ���ʼ���ӿ�
*/
LB_EXPORT int lb_public_dao_init();

/* @method �����ٽӿ�
* @param void
*/
LB_EXPORT int lb_public_dao_destory(void);

LB_END_DECL

#endif
