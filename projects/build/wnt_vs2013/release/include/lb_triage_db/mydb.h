#ifndef _LB_MYDB_H
#define _LB_MYDB_H

#include <ss_base/ss_base.h>
#include <ss_db/ss_db.h>


#define MYDB_DSN_NAME						"MYDBdsn"
#define SQL_TRANSACTION_START		"begin transaction;"
#define SQL_TRANSACTION_COMMIT		"commit transaction;"
#define SQL_TRANSACTION_ROLLBACK	"rollback transaction;"


typedef struct _mydb
{
	ss_mutex_t	lock;
	ss_db_t *ss_db;
	BOOL isConnected;
	HISType dbType;
	ss_db_charset_t charset;
	char* url;
}MYDB;

SS_API MYDB * mydb_init(HISType dbType,const char *driver,const char *host,const char *user,const char *pwd,
						const char *database,int port,const ss_db_charset_t charset);
SS_API int mydb_connect(MYDB *mydb);
SS_API int mydb_disconnect(MYDB *mydb);
SS_API int mydb_free(MYDB *mydb);
SS_API ss_db_result_t *mydb_query(MYDB *mydb,char *sql);
SS_API void mydb_result_free(ss_db_result_t *result);
SS_API int mydb_excute(MYDB *mydb ,char *sql);
SS_API int creat_db(MYDB *mydb,char *dbName);

SS_API int transaction_start(MYDB *mydb);
SS_API int transaction_commit(MYDB *mydb);
SS_API int transaction_rollback(MYDB *mydb);


#endif 