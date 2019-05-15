#include "stdafx.h"
#include "lb_action.h"



lb_action::lb_action()
{
}


lb_action::~lb_action()
{
}

char* lb_str_getTail(char *str)
{
	char* pos = str;

	while (*pos != '\0')
		pos++;

	return pos;
}

int lb_action::lb_get_screenInfo(element_array_pair *pair, pj_sockaddr_in *from, int fromlen)
{
	CppSQLite3DB db;
	CppSQLite3Table table,table1;
	USES_CONVERSION;

	int nRet = LB_FAIL;
	char *pos = NULL;
	char msg[512] = { 0 };
	char HardId[32] = { 0 };
	char Mac[32] = { 0 };
	char sql[512] = { 0 };
	char License[128] = { 0 };
	int master_num = 0, slave_num = 0,id;
	char ip[32];
	memset(ip, 0, 32);

	strncpy(ip, inet_ntoa(*(struct in_addr*)&(from->sin_addr)), 32);
	
	nRet = lb_netio_action_pair_get_str_value(pair, LB_KEY_HARDID, HardId, sizeof(HardId));

	nRet = lb_netio_action_pair_get_str_value(pair, LB_KEY_MAC, Mac,sizeof(Mac));

	nRet = lb_netio_action_pair_get_int_value(pair, LB_KEY_MASTERNUM, &master_num);

	nRet = lb_netio_action_pair_get_int_value(pair, LB_KEY_SLAVENUM, &slave_num);

	nRet = lb_netio_action_pair_get_str_value(pair, LB_KEY_LICENSE, License, sizeof(License));

	printf("Receive the Mac is %s\n",Mac);
	printf("Receive the HardId is %s\n",HardId);
	if (strlen(Mac)>0)
	{
		//存数据库
		db.open(LB_SCREEN_DB);

		sprintf(sql, "select id from %s where ip = '%s' and hardId = '%s' and mac = '%s'", LB_SCREENINFO, ip, HardId, Mac);
		table = db.getTable(sql);
		if (table.numRows() <= 0)
		{
			printf("lonbon1!\n");
			memset(sql, 0, sizeof(sql));
			sprintf(sql, "insert into LBScreenInfo(Devicemodel, hardId, mac, master_number, slave_number,ip,License) values ('%s','%s','%s', %d, %d,'%s','%s')", T2A(DeviceModelstr), HardId, Mac, master_num, slave_num, ip, License);
			db.execDML(sql);

			memset(sql, 0, sizeof(sql));
			sprintf(sql, "select id from %s where ip = '%s' and hardId = '%s' and mac = '%s'", LB_SCREENINFO, ip, HardId, Mac);
			table1 = db.getTable(sql);
			for (int i = 0; i < table1.numRows(); ++i)
			{
				table1.setRow(i);
				id = table1.getIntField(i);
				//printf("the id is %d\n", id);
			}

			memset(sql, 0, sizeof(sql));
			sprintf(sql, "update LBScreenInfo set Screentemplate_id = %d where id = %d", id, id);
			db.execDML(sql);

			memset(sql, 0, sizeof(sql));
			sprintf(sql, "insert into LBScreentemplate(id) values(%d)", id);
			db.execDML(sql);
		}
		else
		{
			printf("lonbon2!\n");
			memset(sql, 0, sizeof(sql));
			sprintf(sql, "update LBScreenInfo set Devicemodel = '%s', hardId = '%s', mac = '%s', master_number = %d, slave_number = %d, ip = '%s',License = '%s'", T2A(DeviceModelstr), HardId, Mac, master_num, slave_num, ip, License);
			db.execDML(sql);
		}

		//回复显示屏
		sprintf(msg, "%s", "Action:LonbonLicense\r\n");

		pos = lb_str_getTail(msg);
		sprintf(pos, "%s", "InterCmd:DeviceInfoOK\r\n");

		lb_netio_msg_sendto2(msg, sizeof(msg), from);

		if (strlen(License) != 0)
		{
			memset(sql, 0, sizeof(sql));
			sprintf(sql, "update LBScreenInfo set Activate = '已激活' where hardId = '%s' and mac = '%s'", HardId, Mac);
			db.execDML(sql);
		}

		db.close();

		::SendMessage(FactoryScreenHwnd, WM_COUNTINCREASE_MSG, 0, 0);

		::SendMessage(UserHwnd, WM_DEVICENUM_MSG, 0, 0);
	}

	return nRet;
}


int lb_action::lb_action_lonbonlicense(element_array_pair *pair, pj_sockaddr_in *from, int fromlen)
{
	int nRet = LB_FAIL;
	char intercmd[128] = { 0 };
	
	nRet = lb_netio_action_pair_get_str_value(pair,LB_KEY_INTERCMD,intercmd, sizeof(intercmd));
	

	//printf("the message is %s\n",pair);
	printf("receive the message is %s\n","hello world!\n");

	if (strcmp(intercmd, LB_KEY_DEVICEINFO) == 0)
	{
		lb_get_screenInfo(pair, from, fromlen);
	}

	return nRet;
}

int lb_action::lb_action_monitor_init()
{
	int nRet = LB_FAIL;

	lb_screen_database_init();
	
	nRet = lb_netio_register_action_handler(LB_ACTION_LONBONLICENSE, &lb_action_lonbonlicense);


	return nRet;
}

BOOL lb_broadcast_screen()
{
	
	char msg[512] = { 0 };
	char *pos = NULL;
	bool opt = true;
	sockaddr_in addr_to;

	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char FAR *)&opt, sizeof(opt));

	addr_to.sin_family=AF_INET; 
    addr_to.sin_addr.S_un.S_addr=INADDR_BROADCAST;  
	addr_to.sin_port = htons(PORT_NUM_BROADCAST);

	sprintf(msg,"%s","Action:LonbonLicense\r\n");
	pos = lb_str_getTail(msg);
	sprintf(pos,"%s","InterCmd:Discovery\r\n\r\n");

	sendto(sock, msg, strlen(msg) + 1, 0, (SOCKADDR*)&addr_to, sizeof(SOCKADDR));
	
	return TRUE;
}

BOOL lb_action::lb_screen_database_init()
{
	CppSQLite3DB db;
	CppSQLite3Table table;
	char sql[2048] = { 0 };

	db.open(LB_SCREEN_DB);

	if (db.isTableExist(LB_SCREENINFO))
	{
		sprintf(sql, "drop table %s", LB_SCREENINFO);
		db.execDML(sql);
	}

	if (db.isTableExist(LB_SCREENTEMPLATE))
	{
		memset(sql, 0, sizeof(sql));
		sprintf(sql, "drop table %s", LB_SCREENTEMPLATE);
		db.execDML(sql);
	}
	
	memset(sql, 0, sizeof(sql));
	if (!db.isTableExist(LB_SCREENINFO))
	{
		sprintf(sql, "CREATE TABLE %s (%s INTEGER PRIMARY KEY AUTOINCREMENT, %s interger, %s varchar(32), %s varchar(32), %s varchar(32), %s interger, %s interger, %s varchar(32), %s varchar(64),%s varchar(32))",
			LB_SCREENINFO, ID, LBScreentemplate_ID, LB_DEVICEMODEL, LB_HARDID, LB_MAC, MASTER_NUMBER, SLAVE_NUMBER, IP, LB_SCREENINFOLICENSE, LB_SCREENINFOACTIVATE);
		db.execDML(sql);
		printf("%s\n",sql);

	}

	memset(sql, 0, sizeof(sql));
	if (!db.isTableExist(LB_SCREENTEMPLATE))
	{
		sprintf(sql, "create table %s (%s interger , %s interger, %s interger, %s interger, %s interger, %s interger,%s interger,%s varchar(256),%s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s varchar(64), %s varchar(128), %s varchar(64), %s varchar(64),%s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger, %s interger)",
			LB_SCREENTEMPLATE, ID,  ISADENABLED, ISADVIDEOENABLED, ISADTEXTENABLED, ADAREAPERCENT, IVIDEOSIZE, IVIDEOSOURCE, VIDEOURL,DEFINED_VALUE, TYPE, MODEL, STYLE, ROTATION, NUMBER_OF_COLUMNS, NUMBER_OF_ROWS, NUMBER_OF_NOW_ROWS, NUMBER_OF_SCREEN, X0, Y0, WIDTH, HEIGHT, ISHIDENTITLE, TITLE, SUB_TITLE, TABLEHEADS_STR, TV_MESSAGE,ISHIDEBOTTOM, ISHIDECALLINFO, ISDISPLAYDATASOURCE, ISSHOWLOWESTLEVEL, ISSHOWOLDSTYLE, LB_QUEUE_TIME, ISTODAYINPATIENT, SHOWCALLINFOBYRIGHT, SORTBYOFFICE, SYSTEMVOICE, STAYTIME, SHOWMODEL);
		db.execDML(sql);
	}

	db.close();

	return TRUE;
}





