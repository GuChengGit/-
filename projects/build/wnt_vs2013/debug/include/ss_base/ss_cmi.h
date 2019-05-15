/**
 * @file ss_ami_core.h
 * This file is core define file of module AMI.
 * The Asterisk Manager Interface allows a client program to connect to an Asterisk instance and
 * issue commands or read PBX events over a TCP/IP stream. This file include general define 
 * needed by AMI
 */
#ifndef _SS_CMI_H_
#define _SS_CMI_H_
#include "ss_base/ss_socket.h"
#include "ss_base/ss_pair.h"

#define CMI_KEY_RESPONSE	"Response"
#define CMI_KEY_EVENT		"Event"


//#define CMI_KEY_VALUE_TOKEN  ": "
/**
 *	@typedef ami_item
 *	A type definition for cmi packet item.
 *  The packet item has a number of packet name: value pairs.
 *  Every packet coming from asterisk is an event packet with the one exception of a
 *  response packet. Events can either be generated by things happening on the server, or
 *  generated by a request by you. In the latter case, the event packets will be prepended by
 *  a response packet.
 *  An event packet is a series of Name: Value tags separated by a carriage return and a new line ('\r\n').
 *  The end of a packet is specified by having a '\r\n' on a line all by itself.
 */

/**
 * @typedef CmiRespone
 * A type definition for event packet.
 */
typedef ss_pair_list CmiAction;

typedef struct _CmiRespone{
	ss_pair_list *response;
	ss_pair_list **event_list;
	int enevt_length;
} CmiRespone;

SS_API int CmiRespone_new(CmiRespone **cmi);
SS_API int CmiRespone_destroy(CmiRespone **cmi);
SS_API int CmiRespone_toString(CmiRespone *cmi,char **str);
SS_API int CmiRespone_addEvent(CmiRespone **cmi,ss_pair_list *aEvent);
SS_API int CmiRespone_isSuccess(CmiRespone *cmi);
SS_API int CmiRespone_getFromSocket(SS_Socket *sockInst, const char* cmd, const char *finishedEventStr,CmiRespone ** cmi);


#endif /*  _SS_CMI_H_ */