/**
* LonbonVoip -- Lonbon VOIP Interface
* Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
*
* This file is part of lonbon ip intercom system.
*
*/

/**
* @file ss_base/ss_endian.h
* @brief LonbonVOIP architecture endianess compatibility definitions.
*
* @author	Qiusheng Li
* @date	2008-10-20
*
*/
#ifndef _SS_ENDIAN_H_
#define _SS_ENDIAN_H_

/*
 * Autodetect system endianess
 */

#ifndef __BYTE_ORDER
#	ifdef __linux__
#		include <endian.h>
#	elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
#		include <machine/endian.h>
#		define __BYTE_ORDER BYTE_ORDER
#		define __LITTLE_ENDIAN LITTLE_ENDIAN
#		define __BIG_ENDIAN BIG_ENDIAN
#	elif defined(_NNOS)
#		include <os.h>
#	else
#		ifndef	__LITTLE_ENDIAN
#			define	__LITTLE_ENDIAN		1234
#		endif
#		ifndef	__BIG_ENDIAN
#			define	__BIG_ENDIAN		4321
#		endif
#		ifdef __LITTLE_ENDIAN__
#			define __BYTE_ORDER __LITTLE_ENDIAN
#		endif /* __LITTLE_ENDIAN */
#		if defined(i386) || defined(__i386__) || defined (WIN32) || defined (WINCE)
#			define __BYTE_ORDER __LITTLE_ENDIAN
#		endif /* defined i386 */
#		if defined(sun) && defined(unix) && defined(sparc)
#			define __BYTE_ORDER __BIG_ENDIAN
#		endif /* sun unix sparc */
#	endif /* linux */
#endif /* __BYTE_ORDER */

#ifndef __BYTE_ORDER
#	error Need to know endianess
#endif /* __BYTE_ORDER */

#endif /* _SS_ENDIAN_H_ */

