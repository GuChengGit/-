#ifndef _SS_EXTDATA_H_
#define _SS_EXTDATA_H_

#include "ss_base/ss_list.h"

#define SS_EXTDATA_IDENTIFY				"SS_EXTDATA"

typedef struct _SS_Field_t{
	int index;
	char* field;
}SS_Field_t;

typedef struct _SS_ExtData_t{
	char* id;
	int buffSize;
	int fieldCount;
	MSList *fieldList;
}SS_ExtData_t;
SS_API SS_ExtData_t* SS_ExtData_new(const char* id);
SS_API int SS_ExtData_addField(SS_ExtData_t** ext_data,int index,const char* field);
SS_API void SS_ExtData_destroy(SS_ExtData_t* data);
SS_API const char* SS_ExtData_getFieldData(SS_ExtData_t* ext_data,int index);
SS_API int SS_ExtData_fromBuff(SS_ExtData_t** data,char*buff,int buff_length);
SS_API int SS_ExtData_toBuff(SS_ExtData_t*ext_data,char**buff,int*buff_length);
SS_API char* SS_ExtData_toString(SS_ExtData_t*ext_data);
SS_API void SS_ExtData_dump(SS_ExtData_t*ext_data);

#endif //_SS_EXTDATA_H_
