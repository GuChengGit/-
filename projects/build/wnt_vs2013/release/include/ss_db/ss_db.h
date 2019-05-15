/**
 * ss_db -- Generic Database Interface
 * Copywrite (C) 2008 Lonbon Electronics Co. Ltd. All Rights Reserved.
 *
 * This file is part of lonbon ip intercom system.
 *
 */

/**
 * @file ss_db/ss_db.h
 * @brief Generic Database Interface Defination.
 *
 * @author	Qiusheng Li
 * @date	2008-09-20
 *
 * This is a generic database interface for modules that need to utilize a
 * database. The interface should be used by all modules that access database.
 * The interface will be independent of the underlying database server.
 */
#ifndef _SS_DB_H_
#define _SS_DB_H_

#include <ss_base/ss_base.h>
#include <time.h>

#define SS_DB_DATA_NCOPY(d,s,n) do{ if((s)!=NULL && (s)->string_val!=NULL && strcmp((s)->string_val,"NULL")!=0) strncpy((d),(s)->string_val,(n)) ;} while(0)
#define SS_DB_DATA_INT_VALUE(s)		(s)?(s)->get_int_value(s):0
#define SS_DB_DATA_UINT_VALUE(s)    (s)?(s)->get_uint_value(s):0
#define SS_DB_DATA_STRING_VALUE(s)  (s)?(s)->get_string_value(s):NULL

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
typedef enum _ss_db_charset
{
	SS_DB_CHARSET_DEFAULT =0,  //Not set, using database default
	SS_DB_CHARSET_GBK,
	SS_DB_CHARSET_GB2312,
	SS_DB_CHARSET_UTF8
}ss_db_charset_t;

/** 
 * @enum database type supported.
 *	SS_DB_SCHEMA_MYSQL
 *	SS_DB_SCHEMA_ORACLE
 *	SS_DB_SCHEMA_DB2
 *	SS_DB_SCHEMA_MSSQL
 */
typedef enum _ss_db_schema
{
	SS_DB_SCHEMA_UNKNOW = -1,
	SS_DB_SCHEMA_MYSQL = 0,
	SS_DB_SCHEMA_BERKELEY,
	SS_DB_SCHEMA_ORACLE,
	SS_DB_SCHEMA_DB2,
	SS_DB_SCHEMA_MSSQL,
	SS_DB_SCHEMA_ODBC,
	SS_DB_SCHEMA_SQLITE
} ss_db_schema_t;

/** 
* @struct typedef struct _ss_db_conf ss_db_conf_t
* A type definition for a database configeration.
*/
typedef struct _ss_db_url{
	char username[32];      /**< Username, case sensitive */
	char password[32];      /**< Password, case sensitive */
	char host[32];          /**< Host or IP or DataSources, case insensitive */
	unsigned short port; /**< Port number */
	char database[32];      /**< Database, case sensitive */
}ss_db_url_t;
/** 
* @struct typedef struct _ss_db_conf ss_db_conf_t
* A type definition for a database configeration.
*/
typedef struct _ss_db_dsn{
	char name[256];      /**< DataSources name */
}ss_db_dsn_t;
/** 
* @struct typedef struct _ss_db_conf ss_db_conf_t
* A type definition for a database configeration.
*/
typedef struct _ss_db_embedded{
	char name[256];      /**< DataSources name */
}ss_db_embedded_t;

typedef union _conn_union{
	ss_db_url_t			url;
	ss_db_dsn_t			dsn;
	ss_db_embedded_t  embedded;
}conn_union_t;
/** 
 * @struct typedef struct _ss_db_conf ss_db_conf_t
 * A type definition for a database configeration.
 */
typedef struct _ss_db_conf{
	ss_db_charset_t charset;
	ss_db_schema_t schema;
	conn_union_t  conn;
	int max_records;
}ss_db_conf_t;


/**
* Each cell in a database table can be of a different type. To distinguish
* among these types, the ss_db_type_t enumeration is used. Every value of the
* enumeration represents one datatype that is recognized by the database
* API.
*/
typedef enum _ss_db_data_type{
	SS_DB_INT,        /**< represents an 32 bit integer number      */
	SS_DB_UINT,        /**< represents an 32 bit integer number      */
	SS_DB_LONG,        /**< represents an 32 bit integer number      */
	SS_DB_ULONG,        /**< represents an 32 bit integer number      */
	SS_DB_LONGLONG,     /**< represents an 64 bit long long integer number      */
	SS_DB_ULONGLONG,    /**< represents an 64 bit unsigned long long integer number      */
	SS_DB_FLOAT,     /**< represents a floating point number       */
	SS_DB_DOUBLE,     /**< represents a floating point number       */
	SS_DB_STRING,     /**< represents a zero terminated const char* */
	SS_DB_DATETIME    /**< represents date and time                 */
} ss_db_data_type_t;

/**
* This structure represents a value in the database. Several datatypes are
* recognized and converted by the database API. These datatypes are automaticaly
* recognized, converted from internal database representation and stored in the
* variable of corresponding type.
*
* Module that want to use this values needs to copy them to another memory
* location, because after the call to free_result there are not more available.
*
* If the structure holds a pointer to a string value that needs to be freed
* because the module allocated new memory for it then the free flag must
* be set to a non-zero value. A free flag of zero means that the string
* data must be freed internally by the database driver.
*/
typedef unsigned int (*fn_get_uint_value_t)(struct _ss_db_data_value_t *data);
typedef int (*fn_get_int_value_t)(struct _ss_db_data_value_t *data);
typedef long (*fn_get_long_value_t)(struct _ss_db_data_value_t *data);
typedef unsigned long (*fn_get_ulong_value_t)(struct _ss_db_data_value_t *data);
typedef long long (*fn_get_longlong_value_t)(struct _ss_db_data_value_t *data);
typedef unsigned long long (*fn_get_ulonglong_value_t)(struct _ss_db_data_value_t *data);
typedef float (*fn_get_float_value_t)(struct _ss_db_data_value_t *data);
typedef double (*fn_get_double_value_t)(struct _ss_db_data_value_t *data);
typedef time_t (*fn_get_date_value_t)(struct _ss_db_data_value_t *data);
typedef const char* (*fn_get_string_value_t)(struct _ss_db_data_value_t *data);
typedef struct _ss_db_data_value_t{
	char* string_val;
	fn_get_uint_value_t      get_uint_value;     
	fn_get_int_value_t       get_int_value;      
	fn_get_long_value_t      get_long_value;     
	fn_get_ulong_value_t     get_ulong_value;    
	fn_get_longlong_value_t  get_longlong_value; 
	fn_get_ulonglong_value_t get_ulonglong_value;
	fn_get_float_value_t     get_float_value;    
	fn_get_double_value_t    get_double_value;   
	fn_get_date_value_t      get_date_value;     
	fn_get_string_value_t    get_string_value;  
} ss_db_data_value_t;

SS_API ss_db_data_value_t* ss_db_data_value_new(const char* str);
SS_API void ss_db_data_value_destroy(ss_db_data_value_t* value);

SS_API ss_db_data_value_t* ss_db_data_value_dup(ss_db_data_value_t *value);

typedef enum _ss_db_parameter_type{
	SS_DB_PARAM_IN,
	SS_DB_PARAM_OUT
//	SS_DB_PARAM_INOUT
}ss_db_parameter_type_t;

typedef struct _ss_db_parameter_t{
	ss_db_parameter_type_t param_type;
	ss_db_data_type_t data_type;
	ss_db_data_value_t* data_value;
}ss_db_parameter_t;

/**
* Create a new ss_db_parameter and initialize it.
* \return a pointer to the new ss_db_parameter_t on success, NULL on errors
*/
SS_API ss_db_parameter_t* ss_db_parameter_new(void);

/**
* Release memory used by a ss_db_parameter_t structure.
* \return zero on success, negative on errors
*/
SS_API int ss_db_parameter_free(ss_db_parameter_t* _r);

SS_API ss_db_parameter_t** ss_db_parameters_new(int n);
SS_API int ss_db_parameters_free(ss_db_parameter_t**  rarams,int n);
SS_API int ss_db_parameters_to_string(ss_db_parameter_t **p,int n,char** str);
SS_API void ss_db_parameters_dump(ss_db_parameter_t **p,int n);

typedef struct _ss_db_col {
	ss_db_data_type_t type;
	char*  name;
	unsigned int size;
	unsigned int decim_size;
	BOOL is_not_null_able;
} ss_db_col_t;

/**
* Structure holding the result of a query table function.
* It represents one row in a database table. In other words, the row is an
* array of ss_db_val_t variables, where each ss_db_val_t variable represents exactly
* one cell in the table.
*/
typedef struct _ss_db_row {
	ss_db_data_value_t** datas;  /**< Columns in the row */
} ss_db_row_t;




/**
* This type represents a result returned by ss_db_query function (see below). The 
* result can consist of zero or more rows (see ss_db_row_t description).
*
* Note: A variable of type ss_db_res_t returned by ss_db_query function uses dynamicaly
* allocated memory, don't forget to call ss_db_result_free if you don't need the
* variable anymore. You will encounter memory leaks if you fail to do this!
*
* In addition to zero or more rows, each ss_db_res_t object contains also an array
* of ss_db_key_t objects. The objects represent keys (names of columns). *
*/
typedef struct _ss_db_result {
	int number_of_records;
	int number_of_column;
	ss_db_col_t* columns;
	ss_db_row_t* rows;
} ss_db_result_t;


/**
* Create a new result structure and initialize it.
* \return a pointer to the new result on success, NULL on errors
*/
SS_API ss_db_result_t* ss_db_result_new(void);

/**
* Release memory used by a result structure.
* \return zero on success, negative on errors
*/
SS_API int ss_db_result_free(ss_db_result_t* _r);

SS_API int ss_db_result_to_string(ss_db_result_t* c_result,char**str);
SS_API int ss_db_result_to_xml(ss_db_result_t* c_result,char**xmlstr);
SS_API int ss_db_result_from_xml(char*xmlstr,ss_db_result_t** c_result);

SS_API void ss_db_result_dump(ss_db_result_t* c_result);
SS_API void ss_db_result_print(ss_db_result_t* c_result);
typedef struct _ss_db_ops{
	/*
	* Open db connection with given config params.
	* Config params are specificaly for each database type.
	* return NULL if error occurs ; established connection's pointer otherwise
	*/
	void* (*open) (const ss_db_conf_t *ss_db_conf);
	/*
	* close given connection.
	*/
	void (*close) (void *conn);
	/*
	* check if given connection still alive,
	* return -1 if not or error occurs ; 0 if all was fine
	* NOTE: this function is optional
	*/
	int (*check) (void *conn);

	/*
	* Execute any INSERT,DELETE,UPDATE statements
	* @params conn - database specific connection; sql - sql statement ; 
	*         sql - any INSERT,DELETE,UPDATE statements
	* @return the number of rows affected by an UPDATE, INSERT, or DELETE statement;
	*          -1 if a error occurs
	*/
	int (*execute) (void *conn, const char *sql);

	/*
	* Execute any SELECT statements.
	* @params conn - database specific connection; sql - sql statement ; 
	*         sql - any SELECT statements
	*         result - result will be saved here
	* @return the number of records by an SELECT statement;-1 if a error occurs
	*/
	int (*query) (void *conn, const char *sql, ss_db_result_t **result);

	/*
	* @return #rows processed ; -1 if a error occurs
	*/
	//  int (*update) (void *conn, const char *sql, List *binds);
	int (*call) (void *conn,const char *procedure_name,ss_db_parameter_t** ss_db_params,int number_of_param);

	/*
	* @return last insert id
	*/
	unsigned long long  (*last_insert_id) (void *conn);

} ss_db_ops_t;

typedef int (*_fn_db)(struct _ss_db*);

/** Structure representing a database ID */
typedef struct _ss_db{
	ss_db_conf_t* conf;      /**< Username, case sensitive */
	const ss_db_ops_t* ss_db_ops;      /**< Database, case sensitive */
	void *conn; /* database connection  */
	BOOL is_keepalive;
	ss_mutex_t	lock;
	ss_thread_t keepalive_thread;
	_fn_db start_keepalive;
	_fn_db stop_keepalive;
	_fn_db reconnect;
}ss_db_t;

/**
* Create a new connection identifier using default character set
* \param url database, format like
*			schema://[username[:password]@]hostname[:port]/database
* \return new allocated ss_db_id structure, NULL on failure
*/
SS_API ss_db_t* ss_db_new(const char* url);

/**
* Create a new connection identifier
* \param url database, format like
*			schema://[username[:password]@]hostname[:port]/database
*        charset - Character Encoding Set
* \return new allocated ss_db_id structure, NULL on failure
*/
SS_API ss_db_t* ss_db_new_with_charset(const char* url,ss_db_charset_t charset);


/**
* Create a new connection identifier using default character set
* \param url database, format like
*			schema://[username[:password]@]hostname[:port]/database
* \return new allocated ss_db_id structure, NULL on failure
*/
SS_API void ss_db_set_max_records(ss_db_t* ss_db,int max_records);

/**
* Free a connection identifier
* \param id the identifier that should released
*/
SS_API void ss_db_free(ss_db_t* ss_db);

#endif  //_SS_DB_H_
