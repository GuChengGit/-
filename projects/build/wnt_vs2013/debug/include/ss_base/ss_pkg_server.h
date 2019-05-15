#ifndef _SS_PKG_SERVER_H_
#define _SS_PKG_SERVER_H_
#include "ss_base/ss_pkg.h"


SS_API void SS_PkgServer_start();
SS_API void SS_PkgServer_stop();
SS_API int SS_PkgServer_setPkgHandleCallback(_SS_SocketPkg_callback cb);
SS_API int  SS_PkgServer_sendCMDResponse(SS_SocketPkg_t *netPkg,unsigned int length,unsigned char *data);

#endif //_SS_PKG_SERVER_H_
