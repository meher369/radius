/***************************************************************************
*  sql_module.h                       rlm_sql - FreeRADIUS SQL Module      *
*                                                                          *
*      MySQL headers for rlm_sql                                           *
*                                                                          *
*                                     Mike Machado <mike@innercite.com>    *
***************************************************************************/
#include	<mysql/mysql.h>
#include	"rlm_sql.h"

typedef struct rlm_sql_mysql_sock {
	MYSQL conn;
	MYSQL *sock;
	MYSQL_RES *result;
	SQL_ROW row;
} rlm_sql_mysql_sock;

int	sql_init_socket(SQLSOCK *sqlsocket, SQL_CONFIG *config);
int	sql_destroy_socket(SQLSOCK *sqlsocket, SQL_CONFIG *config);
int     sql_query(SQLSOCK *sqlsocket, SQL_CONFIG *config, char *querystr);
int     sql_select_query(SQLSOCK *sqlsocket, SQL_CONFIG *config, char *querystr);
int     sql_store_result(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_num_fields(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_num_rows(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_fetch_row(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_free_result(SQLSOCK * sqlsocket, SQL_CONFIG *config);
char    *sql_error(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_close(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_finish_query(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_finish_select_query(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int     sql_affected_rows(SQLSOCK * sqlsocket, SQL_CONFIG *config);
int	sql_check_error(int error);
/*
 * Unused.  Now provided in rlm_sql main module.
 * But left in here just in case...
 *
int     sql_escape_string(SQLSOCK *sqlsocket, SQL_CONFIG *config, char *to, char *from, int length);
*/
