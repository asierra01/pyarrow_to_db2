#pragma once

#ifndef IBM_DB_COMMON_H
#define IBM_DB_COMMON_H

#define SPCLIENT_PYTHON_MAJOR 1
#define SPCLIENT_PYTHON_MINOR 0
#define SPCLIENT_PYTHON_PATCH 0
#define SPCLIENT_PYTHON_VERSION "1.0.0"


#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <sqlutil.h>
#include <sql.h>
#include <sqlenv.h>
#include <db2ApiDf.h>
#include <sqlcli.h>
#include <sqlcli1.h>
#include "win32_to_linux.h"

#pragma push_macro("max")
//#define max
#include "utilcli.h"
////#undef max
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

//void _python_ibm_db_check_sql_errors( SQLHANDLE handle, SQLSMALLINT hType, int rc, int cpy_to_global, char* ret_str, int API, SQLSMALLINT recno );

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
    SQLHANDLE hdbc;
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

int run_PROC_SEND_CSV_TO_LOCAL_FS(
    SQLHANDLE hdbc,
    char * filename_in,
    SQLINTEGER len_filename,
    char * csv_data,
    size_t file_size);

int extract_array_one_big_csv(
        SQLHANDLE henv,
        SQLHANDLE hdbc,
        long      table);


int  display_parameters(
    SQLHANDLE      hdbc,
    SQLHANDLE      hstmt);

int display_columns(
        SQLHANDLE      hdbc,
        SQLHANDLE      hstmt,
        bool           display,
        PYOBJ_PTR      py_list_describe_cols);

int setCLILoadMode(
    SQLHANDLE, 
    SQLHANDLE, 
    int, 
    db2LoadStruct*);

int load_c_example(
    SQLHANDLE henv,
    SQLHANDLE hdbc);

int run_the_test(
    SQLHANDLE henv, 
    SQLHANDLE hdbc);
// variables
extern PYOBJ_PTR  mylog_info;
extern PYOBJ_PTR  SpClientError;

// functions

PYOBJ_PTR  python_arrow_table_to_db2(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_parameters(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_describe_columns(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_call_get_db_size(PYOBJ_PTR  self, PYOBJ_PTR  args);
PYOBJ_PTR  python_create_dummy_exception(PYOBJ_PTR  self, PYOBJ_PTR  args);

//void report_load(db2LoadOut *pLoadOut);

int extract_array(
    SQLHANDLE henv,
    SQLHANDLE hdbc);

int extract_array_phones(
    SQLHANDLE henv,
    SQLHANDLE hdbc);

int get_sqlextendedstoreproc(
    SQLHANDLE henv,
    SQLHANDLE hdbc);

int get_db_size(
SQLHANDLE henv,
SQLHANDLE hdbc,
SQLBIGINT    *out_DATABASESIZE,
SQLBIGINT    *out_DATABASECAPACITY,
SQL_TIMESTAMP_STRUCT *out_snapshottimestamp);



#ifdef __cplusplus
}
#endif

#endif
