#ifndef _LB_HISOPTION_H_
#define _LB_HISOPTION_H_

typedef enum _LB_DISPENSARY_TYPE
{
	IS_QY = 1, //ȡҩ
	IS_CX,//��Ѫ
	IS_SY //��Һ
}LB_DISPENSARY_TYPE;

typedef enum _LB_HISDBConnType
{
	LB_HISDB_CONN_UNKNOW = -1,
	LB_HISDB_CONN_DB= 0,
	LB_HISDB_CONN_WEBSERVICE,
} LB_HISDBConnType;

typedef struct _LB_HisWSConfig{
	char *ip;
	int port;
}LB_HisWSConfig;

typedef struct _LB_HisDBConfig{
	HISType hisType;
	char* url;
}LB_HisDBConfig;

typedef union _LB_HisConfigUnion{
	LB_HisWSConfig *ws;
	LB_HisDBConfig *db;
}LB_HisConfigUnion;

typedef int (*_lb_fn_hisopt)(struct _LB_HisOption*,int);

typedef int (*_lb_fn_hisopt_set_time)(struct _LB_HisOption*, const char *theTime);

typedef enum _LB_HisDateFormatId
{
	LB_HIS_DATE_FORMAT_DEFAULT=0,	/*��׼ʱ���ʽ��YYYY-MM-DD HH:MM:SS 2013-04-27 12:30:40 */
	LB_HIS_DATE_FORMAT_USER_1,		/*ʱ���ʽ��YYYYMMDDHH:MM:SS 2013042712:30:40 */
	LB_HIS_DATE_FORMAT_USER_2,		/*ʱ���ʽ��YYYYMMDDHHMMSS 20130427123040 */
} LB_HisDateFormatId;

typedef enum 
{
	NEW_VIEW=0,
	OLD_VIEW_TYPE_CODE,
	OLD_VIEW_TYPE_NAME
};

typedef struct _LB_HisDateFormat {
	LB_HisDateFormatId format_id;
	char format_str[32];
	int date_time_length;	/*���ں�ʱ��ĳ���		*/
	int date_length;		/*���ڳ��ȣ�����ʱ��	*/
} LB_HisDateFormat;

typedef struct _LB_HisOption
{
	BOOL isTriageDBEnabled;
	BOOL isInpatientDBEnabled;
	BOOL is_insp_patientDBEnable;
	BOOL is_DispensaryDBEnable;
	BOOL isDashboardDBEnable;

	int ViewVertion;
	ss_db_charset_t charset;
	LB_HISDBConnType hisDBConnType;
	LB_HisConfigUnion config;
	LB_HisDateFormat dateFormat;
	int updateInterval;   //HIS����ʱ��������λΪ�룬��С10�룬���60�룬Ĭ��10��
	int queryMaxRecords;  //һ�����ݲ�ѯ���ص�����¼����Ĭ��500
	char *first_query_time;	// ��ʼ����ʱ��
	_lb_fn_hisopt setTriageDBEnabled;
	_lb_fn_hisopt setInpatientDBEnabled;
	_lb_fn_hisopt set_insp_patient_DBEnable;
	_lb_fn_hisopt setDispensaryDBEnable;
	_lb_fn_hisopt setDashboardDBEnable;

	_lb_fn_hisopt setHisUpdateInterval;
	_lb_fn_hisopt setQueryMaxRecords;
	_lb_fn_hisopt setCharset;
	_lb_fn_hisopt_set_time setFirstQueryTime;
	_lb_fn_hisopt setViewVersion;
}LB_HisOption;

SS_API LB_HisOption* LB_HisOption_newWSOption(char*ip,int port,LB_HisDateFormatId dateFormatId);
SS_API LB_HisOption* LB_HisOption_newDBOption(HISType hisType,char *driver,char *ip,char *user,char *password,char *database,LB_HisDateFormatId dateFormatId);

SS_API void LB_HisOption_destroy(LB_HisOption *opt);

#endif //_LB_HISOPTION_H_
