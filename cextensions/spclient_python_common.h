#pragma once

#ifndef SPCLIENT_COMMON_H
#define SPCLIENT_COMMON_H

#define SPCLIENT_PYTHON_MAJOR 1
#define SPCLIENT_PYTHON_MINOR 0
#define SPCLIENT_PYTHON_PATCH 0
#define SPCLIENT_PYTHON_VERSION "1.0.0"



#include <stdlib.h>
#include <sqlutil.h>
#include <sql.h>
#include <sqlenv.h>
#include <db2ApiDf.h>
#include <sqlcli.h>
#include <sqlcli1.h>
#include "win32_to_linux.h"

#pragma push_macro("max")
#ifndef SqlInfoPrint
/* function used in DB2_API_CHECK */
void SqlInfoPrint(const char *, struct sqlca * pSqlca, int, const char*);
#endif

#include "utilcli.h"
#pragma pop_macro("max")

#include <Python.h>

typedef PyObject    * PYOBJ_PTR;
///////////////////////from ctypes.c
typedef struct _ffi_type
{
    size_t size;
    unsigned short alignment;
    //unsigned short alignment1;
    unsigned short type;
    /*@null@*/ struct _ffi_type **elements;
} ffi_type;

struct tagPyCArgObject {
    //PyObject_HEAD
    _PyObject_HEAD_EXTRA
        Py_ssize_t ob_refcnt;
    struct _typeobject *ob_type;
    ffi_type *pffi_type;
    char tag;
    union {
        char c;
        char b;
        short h;
        int i;
        long l;
        long long q;
        long double D;
        double d;
        float f;
        void *p;
    } value;
    PyObject *obj;
    Py_ssize_t size; /* for the 'V' tag */
};
typedef struct tagPyCArgObject PyCArgObject;


#define NIL_P(ptr) (ptr == NULL)

/* Defines a linked list structure for caching param data */
typedef struct _param_cache_node {
    SQLSMALLINT data_type;             /* Datatype */
    SQLUINTEGER param_size;            /* param size */
    SQLSMALLINT nullable;              /* is Nullable */
    SQLSMALLINT scale;                 /* Decimal scale */
    SQLUINTEGER file_options;          /* File options if PARAM_FILE */
    SQLINTEGER    bind_indicator;      /* indicator variable for SQLBindParameter */
    int        param_num;              /* param number in stmt */
    int        param_type;             /* Type of param - INP/OUT/INP-OUT/FILE */
    int        size;                   /* Size of param */
    char    *varname;                  /* bound variable name */
    PyObject  *var_pyvalue;            /* bound variable value */
    SQLINTEGER      ivalue;            /* Temp storage value */
    double    fvalue;                  /* Temp storage value */
    char      *svalue;                 /* Temp storage value */
    SQLWCHAR *uvalue;                  /* Temp storage value */
    DATE_STRUCT *date_value;           /* Temp storage value */
    TIME_STRUCT *time_value;           /* Temp storage value */
    TIMESTAMP_STRUCT *ts_value;        /* Temp storage value */
    struct _param_cache_node *next;    /* Pointer to next node */
} param_node;

typedef struct _ibm_db_result_set_info_struct {
    SQLCHAR    *name;
    SQLSMALLINT type;
    SQLUINTEGER size;
    SQLSMALLINT scale;
    SQLSMALLINT nullable;
    unsigned char *mem_alloc;  /* Mem free */
} ibm_db_result_set_info;


typedef union {
    SQLINTEGER i_val;
    SQLDOUBLE d_val;
    SQLFLOAT f_val;
    SQLSMALLINT s_val;
    SQLCHAR *str_val;
    SQLREAL r_val;
    SQLWCHAR *w_val;
    TIMESTAMP_STRUCT *ts_val;
    DATE_STRUCT *date_val;
    TIME_STRUCT *time_val;
} ibm_db_row_data_type;


typedef struct {
    SQLINTEGER out_length;
    ibm_db_row_data_type data;
} ibm_db_row_type;


typedef struct _stmt_handle_struct {
    PyObject_HEAD
    SQLHDBC hdbc;
    SQLHANDLE hstmt;
    long s_bin_mode;
    long cursor_type;
    long s_case_mode;
    long s_use_wchar;
    SQLSMALLINT error_recno_tracker;
    SQLSMALLINT errormsg_recno_tracker;

    /* Parameter Caching variables */
    param_node *head_cache_list;
    param_node *current_node;

    int num_params;          /* Number of Params */
    int file_param;          /* if option passed in is FILE_PARAM */
    int num_columns;
    ibm_db_result_set_info *column_info;
    ibm_db_row_type *row_data;
} stmt_handle;

typedef struct _conn_handle_struct {
    PyObject_HEAD
    SQLHANDLE henv;
    SQLHANDLE hdbc;
    long auto_commit;
    long c_bin_mode;
    long c_case_mode;
    long c_cursor_type;
    long c_use_wchar;
    int handle_active;
    SQLSMALLINT error_recno_tracker;
    SQLSMALLINT errormsg_recno_tracker;
    int flag_pconnect; /* Indicates that this connection is persistent */
} conn_handle;


#define LOG_INFO(a, ...)  print_mylog_info_format("%d %s() " a, __LINE__, __FUNCTION__, ##__VA_ARGS__)
void print_mylog_info(const char * buffer_log);
void print_mylog_info_format(const char * format, ...);

int run_proc_send_csv_to_local_fs(
    SQLHDBC hdbc,
    const char* filename_in,
    SQLINTEGER len_filename,
    SQLSMALLINT  chunk,
    char* csv_data,
    int64_t file_size,
    ERROR_VAR_PARAM_DEF
);

int extract_array_one_big_csv(
    //SQLHENV henv,
    SQLHDBC hdbc,
    long      table,
    PYOBJ_PTR * py_out_open_int,
    PYOBJ_PTR * py_out_root,
	ERROR_VAR_PARAM_DEF
);


int  display_parameters(
    SQLHDBC      hdbc,
    SQLHSTMT      hstmt,
    const char * table_name,
    ERROR_VAR_PARAM_DEF
);

int display_columns(
    SQLHDBC      hdbc,
    SQLHSTMT      hstmt,
    const char *   comment,
    bool           display,
    PYOBJ_PTR      py_list_describe_cols,
    ERROR_VAR_PARAM_DEF
);

int setCLILoadMode(
    SQLHSTMT, 
    SQLHDBC, 
    int, 
    db2LoadStruct*,
    ERROR_VAR_PARAM_DEF
);

int load_c_example(
    SQLHDBC hdbc,
    ERROR_VAR_PARAM_DEF
);

int run_the_test(
    SQLHDBC hdbc,
    ERROR_VAR_PARAM_DEF
);

int run_the_test_udfcli(
    SQLHDBC hdbc,
    ERROR_VAR_PARAM_DEF
);
// variables
extern PYOBJ_PTR  mylog_info;
extern PYOBJ_PTR  SpClientError;

// functions
PYOBJ_PTR  python_get_hdbc_handle(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_get_stmt_handle(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_sqlextendedstoreproc(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_sample_tbload_c(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_sample_tbload_c_cli(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_arrow_table_to_db2(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_extract_doublearray(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_parameters(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_parameters_by_cli(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_columns(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_procedure(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_admin_cmd_procedure(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_columns_by_cli(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_extract_array_into_python(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_extract_array_one_big_csv(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_call_sp_blob(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_call_sp_get_message_pipe1(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_send_file_to_local_fs(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_run_the_test(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_run_the_test_cli(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_run_the_test_only_windows(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_run_the_test_udfcli(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_get_db_size(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_get_db_size_with_timestamp(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_create_dummy_exception(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_set_mylog(PYOBJ_PTR self, PYOBJ_PTR args);

PYOBJ_PTR  python_update_dbcfg32(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_update_dbcfg64(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_update_dbcfg_string(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_monitor_load(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_snapshot_monitor(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_get_dbcfg_string(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_get_dbcfg_int64(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_get_dbcfg_int32(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_get_dbcfg_int16(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_sqlectnd(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_get_node_directory(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_catalog_database(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_list_database_directory(PYOBJ_PTR self);
PYOBJ_PTR  python_dbauthforcurrentuserdisplay(PYOBJ_PTR self);
PYOBJ_PTR  python_backup(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_databaseupgrade(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_autoconfigure(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_SQLGetConnectAttrInt(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_SQLSetConnectAttrInt(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_SQLGetInfo(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_SQLGetInfoInt(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_SQLGetStmtAttrInt(PYOBJ_PTR self, PYOBJ_PTR args);
PYOBJ_PTR  python_SQLSetStmtAttrInt(PYOBJ_PTR self, PYOBJ_PTR args);

extern PyMethodDef spclient_python_Methods[];


int get_dbcfg_string(
    char* dbName,
    char* buffer,
    db2Uint32 token,
    struct sqlca& sqlca);

int get_dbcfg_int64(
    char* dbName,
    db2Uint64& buffer,
    db2Uint32 token,
    struct sqlca& sqlca);

int get_dbcfg_int16(
    char* dbName,
    db2Uint16& buffer,
    db2Uint32 token,
    struct sqlca& sqlca);

int get_dbcfg_int32(
    char* dbName,
    db2Uint32& buffer,
    db2Uint32 token,
    struct sqlca& sqlca);


int update_dbcfg32(
    char* dbAlias, 
    db2Uint32 flags, 
    db2Uint32 token, 
    db2Uint32 ptrvalue,
    struct sqlca &sqlca);

int update_dbcfg64(
    char* dbAlias, 
    db2Uint32 flags, 
    db2Uint32 token, 
    db2Uint64 ptrvalue,
    struct sqlca &sqlca );

int update_dbcfg_string(
    char* dbAlias,
    db2Uint32 flags,
    char* buffer,
    db2Uint32 token,
    struct sqlca &sqlca );

int add_module_globals(PyObject* m);
int add_module_globals_DBTN(PyObject* m);
int add_sqlcli(PyObject* m);
int add_sqlcli1(PyObject* m);
int add_sqlext(PyObject* m);
int add_sqlutil(PyObject* m);
int add_monitor(PyObject* m);
int add_sqlstate(PyObject* m);
int add_module_globlas_backup(PyObject*);
int add_module_globals_sqlcodes(PyObject* m);
int add_module_globals_sqlenv(PyObject* m);

int extract_doublearray(
    //SQLHANDLE henv,
    SQLHDBC hdbc,
    ERROR_VAR_PARAM_DEF);

int extract_array_phones(
    //SQLHANDLE henv,
    SQLHDBC hdbc,
    ERROR_VAR_PARAM_DEF);

int get_sqlextendedstoreproc(
    SQLHDBC hdbc,
    ERROR_VAR_PARAM_DEF);

int get_db_size(
    //SQLHANDLE henv,
    SQLHDBC hdbc,
    SQLBIGINT    *out_DATABASESIZE,
    SQLBIGINT    *out_DATABASECAPACITY,
    SQL_TIMESTAMP_STRUCT *out_snapshottimestamp,
    ERROR_VAR_PARAM_DEF
);

int dumpDescriptors ( SQLCHAR *comment,         // display heading/comment
                      SQLHDBC hdbc,
                      SQLHSTMT hstmt,           // statement handle
                      USHORT header,            // display header record
                      USHORT records,           // display col/parm records
                      int incBookmarkRec,
                      ERROR_VAR_PARAM_DEF);      // include bookmark record


#define SPCLIENT_ERROR_MESSAGE if (ret != 0)\
{\
    int ret_set;\
    ret_set = PyObject_SetAttrString(SpClientError, "errorMsg", Py_BuildValue("s", message));\
    ret_set = PyObject_SetAttrString(SpClientError, "SQLCODE", PyLong_FromLong(sqlcode));\
    ret_set = PyObject_SetAttrString(SpClientError, "SQLSTATE", Py_BuildValue("s", sqlstate));\
    PyErr_Format(SpClientError, "something went wrong ret=%d %d %s()\nSQLCODE=%d\nSQLSTATE='%s'\nerrorMsg='%s'",\
        ret,\
        __LINE__,\
        __FUNCTION__,\
        sqlcode,\
        sqlstate,\
        message);\
    return NULL;\
}


#define SPCLIENT_ERROR { rc = sqlaintp(errorMsg, 1024, 80, &sqlca);\
PyObject_SetAttrString(SpClientError, "errorMsg", Py_BuildValue("s", errorMsg));\
PyObject_SetAttrString(SpClientError, "SQLCODE", PyLong_FromLong(sqlca.sqlcode));\
char sqlstate [6] = {};\
strncpy(sqlstate, sqlca.sqlstate, 5);\
sqlstate[5] = 0;\
PyObject_SetAttrString(SpClientError, "SQLSTATE", Py_BuildValue("s", sqlstate));\
PyErr_Format(SpClientError, "something went wrong %d %d %s()\nSQLCODE=%d\nSQLSTATE='%s'\nerrorMsg='%s'",\
    ret,\
    __LINE__,\
    __FUNCTION__,\
    sqlca.sqlcode,\
    sqlstate,\
    errorMsg);\
return NULL;}


#endif
