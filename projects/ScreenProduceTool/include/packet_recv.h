
#ifndef __NET_PACKET_RECV_H__
#define __NET_PACKET_RECV_H__

#include <pjlib-util.h>
#include <pjlib.h>

#ifdef __cplusplus
extern "C"
{
#endif



typedef struct packet_recv_param
{
	pj_pool_t * pool ;
	unsigned short port ;
	int buf_len ;
	
	void * usr_data ;
	// cb 

	pj_status_t (*process_cb)(void * data, 
		int data_len, 
		const pj_sockaddr_t *src_addr,
		int addr_len, 
		void * usr_data) ;

	void * internal_param ;

}packet_recv_param ;


//pj_status_t packet_recv_start(packet_recv_param * param) ;
//pj_status_t packet_recv_stop(packet_recv_param * param) ;

pj_status_t net_packet_recv_start(packet_recv_param * param) ;
pj_status_t net_packet_recv_stop(packet_recv_param * param) ;

pj_sock_t net_packet_recv_get_sock(packet_recv_param * param) ;


#ifdef __cplusplus
}
#endif


#endif  /* __NET_PACKET_RECV_H__ */
