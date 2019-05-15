#ifndef  __LB_HOSPITAL_DAO_H__
#define  __LB_HOSPITAL_DAO_H__

#include "lb_headdef.h"
LB_BEGIN_DECL

#define LB_HOSPITAL_INPATIENT_EXT_CNT			20
#define LB_HOSPITAL_INPATIENT_FLAG_CNT			10
#define LB_HOSPITAL_INPATIENT_PREDISPLAY_CNT	(LB_HOSPITAL_INPATIENT_EXT_CNT + LB_HOSPITAL_INPATIENT_FLAG_CNT * 3)

/* @method 库初始化接口
* @param mstNum 主机号
* @param db_path 数据库路径
*/
LB_EXPORT int lb_hospital_dao_init(char *db_path);

/* @method 库销毁接口
* @param void
*/
LB_EXPORT int lb_hospital_dao_destory(void);

// 患者扩展信息
typedef struct _LB_HOSPITAL_INPATIENT_EXT_INFO
{
	char	*vContent;			// 扩展字段内容

}LB_HOSPITAL_INPATIENT_EXT_INFO;

// 患者护理标识信息
typedef struct _LB_HOSPITAL_INPATIENT_LEVEL_INFO
{
	char	*flagName;			// 护理标识名
	char	*flagColor;			// 护理标识颜色
	char	*flagFontColor;		// 护理标识字体颜色

}LB_HOSPITAL_INPATIENT_LEVEL_INFO;

// 患者信息
typedef struct _LB_HOSPITAL_INPATIENT_INFO
{
	char	*patientCode;		// 患者编号	
	char	*hosNumber;			// 住院号(注：大部分医院该编号与患者编号一致，此时，本字段可以不使用)
	char	*name;				// 姓名
	char	*sex;				// 性别
	char	*birthday;			// 年龄
	char	*doctorCode;		// 医生编号
	char	*nurseCode;			// 护士编号 
	char	*condition;			// 病情
	char	*advice;			// 医嘱
	char	*newInpatient;		// 新入院标识
	char	*checkInDate;		// 入院时间
	char	*lastModify;		// 最后更新时间

	LB_HOSPITAL_INPATIENT_EXT_INFO inpatientExtInfo[LB_HOSPITAL_INPATIENT_EXT_CNT];
	LB_HOSPITAL_INPATIENT_LEVEL_INFO inpatientFlagInfo[LB_HOSPITAL_INPATIENT_FLAG_CNT];

}LB_HOSPITAL_INPATIENT_INFO;

/* @method 获取指定分机的患者信息
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @param **inpatientInfo 患者信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_get_inpatient_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_HOSPITAL_INPATIENT_INFO **inpatientInfo);

/* @method 获取指定分机的患者年龄
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @return -1 失败， >=0 患者当前年龄
*/
LB_EXPORT int lb_hospital_get_inpatient_age(int accId, int areaId, int master_number, int slave_number, int devRegType);

/* @method 获取指定分机的患者入院日期
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @param *year 年
* @param *month 月
* @param *day 日
* @return -1 失败， 0成功
*/
LB_EXPORT int lb_hospital_get_inpatient_checkInDate(int accId, int areaId, int master_number, int slave_number, int devRegType, int *year, int *month, int *day);

/* @method 设置指定分机的患者信息
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @param *inpatientInfo 患者信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_set_inpatient_info(int accId, int areaId, int master_number, int slave_number, int devRegType, LB_HOSPITAL_INPATIENT_INFO *inpatientInfo);

/* @method 删除患者信息
* @param accId	账号序号（默认0）
* @param areaId	地址盒区号
* @param master_number 主机号
* @param slave_number 分机号
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_delete_inpatient_info(int accId, int areaId, int master_number, int slave_number, int devRegType);

/* @method 销毁患者信息
* @param *inpatientInfo 患者信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_destory_inpatient_info(LB_HOSPITAL_INPATIENT_INFO *inpatientInfo);

typedef struct _LB_HOSPITAL_KEY_NAME
{
	int		vSn;
	char	*keyName;

}LB_HOSPITAL_KEY_NAME;

/* @method 获取扩展字段别名信息
* @param vSn 字段序号（1~LB_HOSPITAL_INPATIENT_PREDISPLAY_CNT）
* @param *keyNameInfo 扩展字段别名信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_get_key_name(int vSn, char *keyName);

/* @method 设置扩展字段别名信息
* @param *reNameInfo 扩展字段别名信息
* @param cnt 扩展字段别名数量
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_set_key_name(LB_HOSPITAL_KEY_NAME *keyNameInfo, int cnt);

/* @method 销毁扩展字段别名信息
* @param *reNameInfo 扩展字段别名信息
* @param cnt 扩展字段别名数量
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_destory_key_name(LB_HOSPITAL_KEY_NAME *keyNameInfo, int cnt);

typedef struct _LB_HSOPITAL_PREDISPLAY
{
	int		vSn;
	char	*keyName;

}LB_HOSPITAL_PREDISPLAY;

/* @method 获取优先显示字段信息
* @param vSn 优先显示字段序号(1~LB_HOSPITAL_INPATIENT_PREDISPLAY_CNT)
* @param *preDisplayInfo 优先显示字段信息
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_get_predisplay_info(int vSn, char *keyName);

/* @method 设置优先显示字段信息
* @param *preDisplayInfo 优先显示字段信息
* @param cnt 优先显示字段数
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_set_predisplay_info(LB_HOSPITAL_PREDISPLAY *preDisplayInfo, int cnt);

/* @method 销毁优先显示字段信息
* @param *preDisplayInfo 优先显示字段信息
* @param cnt 优先显示字段数
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_destory_predisplay_info(LB_HOSPITAL_PREDISPLAY *preDisplayInfo, int cnt);


// 科室信息
typedef struct _LB_HOSPITAL_DEPARTMENT_INFO
{
	char *code;
	char *name;

}LB_HOSPITAL_DEPARTMENT_INFO;

/* @method 获取科室信息节点数
* @return -1 未初始化，0 无科室信息, >1 返回科室信息链表节点数
*/
LB_EXPORT int lb_hospital_get_department_info_cnt(void);

/* @method 获取科室信息
* @param **departmentInfo 科室信息
* @return 0 成功，-1 失败, >1 返回科室信息链表节点数
*/
LB_EXPORT int lb_hospital_get_department_info(LB_HOSPITAL_DEPARTMENT_INFO **departmentInfo);

/* @method 设置科室信息
* @param *departmentInfo 科室信息
* @param departmentCnt 科室数量
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_set_department_info(LB_HOSPITAL_DEPARTMENT_INFO *departmentInfo, int departmentCnt);

/* @method 销毁科室信息
* @param **departmentInfo 科室信息
* @param departmentCnt 科室数量
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_destory_department_info(LB_HOSPITAL_DEPARTMENT_INFO *departmentInfo, int departmentCnt);

// 雇员信息
typedef struct _LB_HOSPITAL_EMPLOYEER_INFO
{
	char *code;
	char *departmentCode;
	char *name;
	char *sex;
	char *occupation;
	char *title;

}LB_HOSPITAL_EMPLOYEER_INFO;

/* @method 获取雇员信息
* @param **employeerInfo 雇员信息
* @return 0 成功，-1 失败, >1 返回雇员信息链表节点数
*/
LB_EXPORT int lb_hospital_get_employeer_info(LB_HOSPITAL_EMPLOYEER_INFO **employeerInfo);

/* @method 根据编号获取雇员信息
* @param *employeerInfo 指定的雇员信息
* @param *code 雇员编号
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_get_employeer_info_from_code(LB_HOSPITAL_EMPLOYEER_INFO **employeerInfo, char *code);

/* @method 设置雇员信息
* @param *employeerInfo 雇员信息
* @param employeerCnt 雇员数量
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_set_employeer_info(LB_HOSPITAL_EMPLOYEER_INFO *employeerInfo, int employeerCnt);

/* @method 销毁雇员信息
* @param **employeerInfo 雇员信息
* @param employeerCnt 雇员数量
* @return 0 成功，-1 失败
*/
LB_EXPORT int lb_hospital_destory_employeer_info(LB_HOSPITAL_EMPLOYEER_INFO *employeerInfo, int employeerCnt);


LB_END_DECL

#endif
