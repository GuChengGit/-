/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file lonbonvoip.h
* @brief LonbonVoip Generic Defination.
*
* @author	Qiusheng Li
* @date	2008-09-20
*
*/
#ifndef _SS_BASE_H_
#define _SS_BASE_H_

#include "ss_base/ss_auth.h"
#include "ss_base/ss_callback.h"
#include "ss_base/ss_cmd.h"
#include "ss_base/ss_cmi.h"
#include "ss_base/ss_code.h"
#include "ss_base/ss_def.h"
#include "ss_base/ss_des.h"
#include "ss_base/ss_device.h"
#include "ss_base/ss_endian.h"
#include "ss_base/ss_error.h"
#include "ss_base/ss_extdata.h"
#include "ss_base/ss_gbk2utf.h"
#include "ss_base/ss_httpc.h"
#include "ss_base/ss_iconv.h"
#include "ss_base/ss_ini_config.h"
#include "ss_base/ss_kernel_command.h"
#include "ss_base/ss_lang.h"
#include "ss_base/ss_list.h"
#include "ss_base/ss_logger.h"
#include "ss_base/ss_md5.h"
#include "ss_base/ss_netfile.h"
#include "ss_base/ss_netpkg.h"
#include "ss_base/ss_netutils.h"
#include "ss_base/ss_pair.h"
#include "ss_base/ss_port.h"
#include "ss_base/ss_pwd.h"
#include "ss_base/ss_sn.h"
#include "ss_base/ss_socket.h"
#include "ss_base/ss_string.h"
#include "ss_base/ss_tcpfile.h"
#include "ss_base/ss_thread.h"
#include "ss_base/ss_threadpool.h"
#include "ss_base/ss_time.h"
#include "ss_base/ss_utils.h"
#include "ss_base/ss_pkg.h"
#include "ss_base/ss_pkg_client.h"
#include "ss_base/ss_pkg_server.h"
#include "ss_base/ss_ping.h"
#include "ss_base/ss_property.h"
#include "ss_base/ss_virtual_device.h"
#ifndef _NNOS
#include "ss_base/ss_his.h"
#include "ss_base/ss_dir.h"
#include "ss_base/ss_lonbon.h"
#include "ss_base/ss_flash.h"
#include "ss_base/ss_opensips.h"
#include "ss_base/ss_system.h"
#include "ss_base/ss_winapi.h"
#include "ss_base/ss_winceapi.h"
#endif
#ifdef ANDROID
#include "ss_base/ss_android.h"
#elif defined(__linux__) 
#include "ss_base/ss_user_service.h"
#endif
#endif //_SS_BASE_H_
