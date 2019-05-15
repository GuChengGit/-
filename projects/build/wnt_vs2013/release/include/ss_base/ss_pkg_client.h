#ifndef _SS_PKG_CLIENT_H_
#define _SS_PKG_CLIENT_H_
#include "ss_base/ss_pkg.h"


SS_API void SS_PkgClient_start(char * serverIP);
SS_API void SS_PkgClient_stop();
SS_API int SS_PkgClient_sendCMD(unsigned int id,unsigned int cmd,unsigned int length,unsigned char *data);
SS_API int SS_PkgClient_setPkgHandleCallback(_SS_SocketPkg_callback cb);

SS_API int SS_PkgClient_getDoctorPhotoName(unsigned int id,char *doctorCode);
SS_API int SS_PkgClient_getNursePhotoName(unsigned int id,char *nurseCode);

#endif //_SS_PKG_CLIENT_H_
