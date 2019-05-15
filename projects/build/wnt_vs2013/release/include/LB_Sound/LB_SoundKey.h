#ifndef _LB_SOUNDKEY_H_
#define _LB_SOUNDKEY_H_
#include <ss_base/ss_base.h>

#define LONBON_SOUND_NAME					"LB-SOUND"

SS_API int LB_SoundKey_init(unsigned int pwd);
SS_API int LB_SoundKey_uninit();
SS_API BOOL LB_SoundKey_isInited();
SS_API int LB_SoundKey_getId(unsigned long *id);
SS_API BOOL LB_SoundKey_isGoodRandom();
SS_API BOOL LB_SoundKey_isKeyLinked();
SS_API int LB_SoundKey_checkNewKey(BOOL *isNewKey);
SS_API int LB_SoundKey_getVersion(unsigned int* version);
SS_API int LB_SoundKey_setVersion(unsigned int version);
SS_API int LB_SoundKey_readData(unsigned char *pbBuffer, int nLength);
SS_API int LB_SoundKey_writeData(unsigned char *pbBuffer, int nLength);
SS_API int LB_SoundKey_getDate(unsigned char** time_str);
SS_API int LB_SoundKey_setDate(unsigned char* time_str);
SS_API char LB_SoundKey_readKey();
SS_API int LB_SoundKey_setState(int state);

#endif //_LB_SOUNDKEY_H_