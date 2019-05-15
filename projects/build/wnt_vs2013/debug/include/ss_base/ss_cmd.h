#ifndef _SS_CMD_H_
#define _SS_CMD_H_
#include "ss_base/ss_def.h"

#define SS_CMD_MAGIC					"LBCMD"
#define SS_CMD_MAGIC_LENGTH				5
#define SS_CMD_MD5_LENGTH				32
#define SS_CMD_SIZE_LENGTH				2

#define SS_CMD_MIN_TABLE_SIZE			2048
#define SS_CMD_MAX_TABLE_SIZE			8192


typedef enum {
	SS_CMD_TYPE_NULL			 = 0,  	  
	SS_CMD_TYPE_FLASH_UBOOT,
	SS_CMD_TYPE_FLASH_KERNEL,
	SS_CMD_TYPE_FLASH_SYSTEM,
	SS_CMD_TYPE_FLASH_LONBON,
	SS_CMD_TYPE_FLASH_ALL,
	SS_CMD_TYPE_FORMAT_USERDATA,
}SS_CMD_TYPE_t;

typedef int (*fn_cmd_save_t)(struct _SS_CMDTable_t* pCmd,const char *fileName,BOOL isEncryptFile);
typedef int (*fn_cmd_update_t)(struct _SS_CMDTable_t* pCmd,unsigned char cmd,unsigned char* param,unsigned int length);
typedef int (*fn_cmd_delete_t)(struct _SS_CMDTable_t* pCmd,unsigned char cmd);

typedef struct _SS_CMD_t{
	unsigned char cmd;
	unsigned int param_length;
	unsigned char *param;
}SS_CMD_t;

typedef struct _SS_CMDTable_t{
	SS_CMD_t **cmdList;
	int cmdLength;
	fn_cmd_update_t update;
	fn_cmd_delete_t del;
	fn_cmd_save_t save;
}SS_CMDTable;

SS_API SS_CMD_t * SS_CMD_new(unsigned char cmd,unsigned char* param,unsigned int length);
SS_API void SS_CMD_destroy(SS_CMD_t *pCmd);

SS_API SS_CMDTable * SS_CMDTable_new(const unsigned char *data,const int length);
SS_API SS_CMDTable * SS_CMDTable_newFromFile(const char *fileName,BOOL isEncryptFile);
SS_API void SS_CMDTable_destroy(SS_CMDTable *pCmdTable);

SS_API void SS_CMDTable_createLbcmd(SS_CMD_TYPE_t ss_cmd);

#endif
