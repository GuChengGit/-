#pragma once

#include "lb_netio.h"
#include "lb_types.h"
#include "SQLite3Wrapper.h"
#include "Clb_global.h"

#define LB_FAIL -1
#define PORT_NUM_BROADCAST  5002
#define PORT_NUM_SETTEMPLATE 5510


#define LB_ACTION_LONBONLICENSE  "LonbonLicense"
#define LB_KEY_INTERCMD  "InterCmd"
#define LB_KEY_DEVICEINFO "DeviceInfo"
#define LB_KEY_HARDID    "HardId"
#define LB_KEY_MAC       "Mac"

#define LB_KEY_LICENSE "License"
#define LB_KEY_DEVICENUMBER  "DeviceNumber"

#define LB_KEY_MASTERNUM  "MasterNumber"
#define LB_KEY_SLAVENUM   "SlaveNumber"


extern BOOL lb_broadcast_screen();
char *lb_str_getTail(char *str);

class lb_action
{
public:
	lb_action();
	~lb_action();
	int lb_action_monitor_init();
	static int lb_action_lonbonlicense(element_array_pair *pair, pj_sockaddr_in *from, int fromlen);
	static int lb_get_screenInfo(element_array_pair *pair, pj_sockaddr_in *from, int fromlen);
	static BOOL lb_screen_database_init();
};

