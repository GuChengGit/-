#pragma once

#if defined(_WIN32_WCE) || defined(WIN32) || defined(__WIN32__) || defined(WIN64)
#include "windows.h"
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif

#include "lb_headdef.h"

#include "sqlite3.h"

int lb_sqlite3_init(void);
int lb_sqlite_init(void);

int lb_sqlite3_destory(void);

int lb_sqlite3_open(char *fileName);

void lb_sqlite3_close(void);

int lb_sqlite3_execSql(const char *sql);

int lb_sqlite3_execQuery(const char *sql);

sqlite3_int64 lb_sqlite3_getLastInsertRowId(void);

BOOL lb_sqlite3_isTableExist(const char *tableName);

int lb_sqlite3_getNumFields();

int lb_sqlite3_getNumRows();

int lb_sqlite3_nextRow();

int lb_sqlite3_execSqlExt(const char *sql, const unsigned char *data, int len);

const char *lb_sqlite3_getFieldName(int nField);

sqlite3_int64 lb_sqlite3_getInt64FieldValue(int nField);

int lb_sqlite3_getIntFieldValue(int nField);

double lb_sqlite3_getFloatFieldValue(int nField);

const char *lb_sqlite3_getStringFieldValue(int nField);

const unsigned char *lb_sqlite3_getBolbFieldValue(int nField);

int lb_sqlite3_beginTran(void);

int lb_sqlite3_commitran(void);

int lb_sqlite3_rollbacktran();

void lb_sqlite3_finalize(void);

typedef struct _lb_sqlite3_manage
{
	int totalRow;
	int totalCol;

	sqlite3 * mpDB;
	sqlite3_stmt * mpVM;

	BOOL mbEof;

	//pthread_mutex_t mutex;

}lb_sqlite3_manage;

lb_sqlite3_manage *lb_sqlite3_manage_get(void);

// int lb_sqlite3_manage_lock(void);

//int lb_sqlite3_manage_unLock(void);