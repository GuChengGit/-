#ifndef _SS_SN_H_
#define _SS_SN_H_

#include "ss_base/ss_def.h"

#define ICU_MASTER_SLAVE_COUNT			30

typedef enum {
	SS_SN_TYPE_UNKNOW=0,
	SS_SN_TYPE_SLAVE,
	SS_SN_TYPE_DIGATAL_MASTER,
	SS_SN_TYPE_AD_MASTER,
	SS_SN_TYPE_SERVER,
	SS_SN_TYPE_SOFT_MASTER,
	SS_SN_TYPE_AD,
	SS_SN_TYPE_SOFT_BROADCAST,
	SS_SN_TYPE_FIRE_CONTROL_MATRIX,
	SS_SN_TYPE_LCONTROL,
	SS_SN_TYPE_ATA,
	SS_SN_TYPE_QUEUE_MASTER,
	SS_SN_TYPE_QUEUE_CLINIC_DISPLAY,
	SS_SN_TYPE_QUEUE_CALLER,
	SS_SN_TYPE_QUEUE_TICKET,
	SS_SN_TYPE_QUEUE_VOICE_CONTROLER,
	SS_SN_TYPE_BUILDING_OUTSIDE_DOOR,
	SS_SN_TYPE_BUILDING_HOME,
	SS_SN_TYPE_BUILDING_MANAGER,
	SS_SN_TYPE_BUILDING_DOOR,
	SS_SN_TYPE_ICU_MASTER,
	SS_SN_TYPE_ICU_SLAVE_VISIT,
	SS_SN_TYPE_ICU_SLAVE_BED,
	SS_SN_TYPE_SOFT_BROADCAST_MASTER,
	SS_SN_TYPE_SOFT_BROADCAST_SLAVE,
	SS_SN_TYPE_QUEUE_OPINION_COLLECTOR,
	SS_SN_TYPE_ADMINISTRATION_SERVER,
	SS_SN_TYPE_SMARTPHONE,
	SS_SN_TYPE_MULTIMEDIA_SLAVE,
	SS_SN_TYPE_DOOR_STATION,
	SS_SN_TYPE_DISPLAY
}ss_sn_type_t;

typedef enum{
	REGISTER_TYPE_UNKNOW = -1,
	REGISTER_TYPE_GENERAL = 0,
	REGISTER_TYPE_LCD_CONTROL,
	REGISTER_TYPE_VOICE_CONTROLER,
	REGISTER_TYPE_CLINIC_DISPLAY,
	REGISTER_TYPE_OPINION_COLLECTOR,
	REGISTER_TYPE_BED_EXTENSION,
	REGISTER_TYPE_SMARTPHONE,
	REGISTER_TYPE_MULTIMEDIA,
	REGISTER_TYPE_DOOR_STATION,
	REGISTER_TYPE_DISPLAY
} ss_sn_register_type;

typedef enum{
	MANUFACTORY_TYPE_UNKNOW = -1,
	MANUFACTORY_TYPE_LONBON = 0,  
	MANUFACTORY_TYPE_OEM,
	MANUFACTORY_TYPE_POST,
	MANUFACTORY_TYPE_CCB,
} ss_sn_manufactory_type;

#define SS_SN_VIRTUAL_CODE					"000"

SS_API ss_sn_type_t SS_SN_getType(const char * sn);
SS_API ss_sn_register_type SS_SN_getRegisterType(const char * sn);
SS_API ss_sn_manufactory_type SS_SN_getManufactoryType(const char * sn);

SS_API int SS_SN_getCountOfSlave(const char * sn);
SS_API const char* SS_SN_getTypeDesc(ss_sn_type_t type);
SS_API const char* SS_SN_getTypeDescCN(ss_sn_type_t type);
SS_API const char* SS_SN_getTypeDescTW(ss_sn_type_t type);
SS_API const char* SS_SN_getTypeDescEN(ss_sn_type_t type);
SS_API BOOL SS_SN_isLevelOneMaster(const char * sn);
SS_API BOOL SS_SN_isVirtualSN(unsigned char** sn);

#endif
