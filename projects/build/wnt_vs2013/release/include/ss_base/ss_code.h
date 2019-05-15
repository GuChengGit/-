#ifndef _SS_CODE_H_
#define _SS_CODE_H_
#include "ss_base/ss_def.h"

typedef unsigned int LB_MODEL_CODE;



#define MODEL_CODE_NONE				0
/* Product Model Code Configuration bits */
#define MODEL_CODE_SDK_GATEWAY		(1 << 0)

SS_API BOOL SS_Code_isSupprtFunction(LB_MODEL_CODE code,int funFlag);
SS_API const char* SS_Code_getDesc(int funFlag);
SS_API int SS_Code_getAllFunctions(int** funs,char***descs,int* size);

#endif

