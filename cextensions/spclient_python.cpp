
#include "spclient_python_common_cpp.h"
#pragma pack( show )

//#include "ctypes.h" ? should I include this ? for PyCArgObject


PYOBJ_PTR mylog_info = NULL;
PYOBJ_PTR SpClientError = NULL; // Creating a new exception

const char * IBM_DBConnection = "ibm_db.IBM_DBConnection";

void print_mylog_info_format(const char * format, ...)
{
    va_list args;
    char * buffer_log = (char *) malloc(120000);
    va_start(args, format);
    vsnprintf(buffer_log, 120000, format, args);
    if (mylog_info != NULL)
    {
        py11::function mylog = py11::reinterpret_borrow<py11::function>(mylog_info);
        try
        {
            py11::str py_str(buffer_log);
            auto py_ret = mylog(py_str);
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("error_already_set '%s' '%s'", e.what(), buffer_log);
        }
    }
    free(buffer_log);
    va_end(args);

}

void print_mylog_info(const char * buffer_log)
{
    if (mylog_info != NULL)
    {
        py11::function mylog = py11::reinterpret_borrow<py11::function>(mylog_info);
        try
        {
            py11::str py_str(buffer_log);
            auto ret = mylog(py_str);
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("error_already_set '%s' '%s'\n", e.what(), buffer_log);
            return;
        }
    }

}

string run_the_test_udfcli_docstring = R"(

run_the_test_udfcli(conn)
    
)";


string run_the_test_cli_docstring = R"(
ref_henv    = byref(self.mDb2_Cli.henv)
argobj_henv = PyCArgObject.from_address(id(ref_henv))

ref_hdbc    = byref(self.mDb2_Cli.hdbc)
argobj_hdbc = PyCArgObject.from_address(id(ref_hdbc))

run_the_test_cli(argobj_henv.p,
                argobj_hdbc.p)
    
)";

string error_docstring = R"(

Error(msg, sqlcode, errormsg)

    Parameters
    ----------
    msg      :  :obj:`str`
    sqlcode  :  :obj:`int`
    errormsg :  :obj:`str`
)";

string arrow_table_to_db2_docstring = R"(

arrow_table_to_db2 (conn,
                    MessageFile,
                    TempFilesPath,
                    DataBufferSize,
                    SaveCount,
                    ChunkSize,
                    MaxRows,
                    table,
                    tablespace_name,
                    schema_name,
                    table_name,
                    column_oriented,
                    drop_table,
                    create_table)

    Parameters
    ----------
    conn             : :class:`ibm_db.IBM_DBConnection` connection object
    MessageFile      : :obj:`str` load result MessageFile filename
    TempFilesPath    : :obj:`str` TempFilesPath
    DataBufferSize   : :obj:`int  data buffer size`, this could be zero
    SaveCount        : :obj:`int` save count, this could be zero
    ChunkSize        : :obj:`int` chunk size
    MaxRows          : :obj:`int` max rows intended to be inserted
    table            : :class:`pyarrow.lib.Table` pyarrow table object
    tablespace_name  : :obj:`str` Table space name
    schema_name      : :obj:`str` Schema name
    table_name       : :obj:`str` Table name
    column_oriented  : :obj:`bool` True or False column oriented table ?
    drop_table       : :obj:`bool` True or False drop the table before inserting ?
    create_table     : :obj:`bool` True or False create the table before inserting ? 
                       if you are inserting data, one should create the table once

)";

string tbload_docstring = R"(

run the sample code tbload.c (ibm_db.IBM_DBConnection)  

**
** SOURCE FILE NAME: tbload.c
**
** SAMPLE: How to insert data using the CLI LOAD utility 
**        
**         This program demonstrates usage of the CLI LOAD feature.  An array
**         of rows of size "ARRAY_SIZE" will be inserted "NUM_ITERATIONS"
**         times.  Execution of this program will write a text file called
**         cliloadmsg.txt to the current directory.  It contains messages
**         generated during program execution.
**         (Messages will be appended to the end of the file.)  
**
** CLI FUNCTIONS USED:
**         SQLAllocHandle -- Allocate Handle
**         SQLBindParameter -- Bind a Parameter Marker to a Buffer or
**                             LOB Locator
**         SQLEndTran -- End Transactions of a Connection
**         SQLExecDirect -- Execute a Statement Directly
**         SQLExecute -- Execute a Statement
**         SQLFreeHandle -- Free Handle Resources
**         SQLPrepare -- Prepare a Statement
**         SQLSetStmtAttr -- Set Options Related to a Statement
**
** OUTPUT FILE: tbload.out (available in the online documentation)
** Table used loadtable(Col1 VARCHAR(30))

)";

string update_dbcfg32_docstring = R"(
update_dbcfg32(dbalias, flags, token, ptrvalue)
    Parameters
    ----------
    dbalias  : :obj:`str`
    flags    : :obj:`int`
    token    : :obj:`int`
    ptrvalue : :obj:`int`

    ex: update_dbcfg32('SAMPLE', db2CfgImmediate, SQLF_DBTN_PL_STACK_TRACE, SQLF_PL_STACK_TRACE_NONE)

** flags
** Input. Specifies the type of action to be taken. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** - db2CfgDatabase
** Specifies to return the values in the database configuration file.

** - db2CfgDatabaseManager
** Specifies to return the values in the database manager configuration file.

** - db2CfgImmediate
** Returns the current values of the configuration parameters stored in
** memory.

** - db2CfgDelayed
** Gets the values of the configuration parameters on disk. These do not
** become the current values in memory until the next database connection
** or instance attachment.

** - db2CfgGetDefaults
** Returns the default values for the configuration parameter.

** - db2CfgReset
** Reset to default values.

** - db2CfgSingleDbpartition
** To update or reset the database configuration on a specific database
** partition, set this flag and provide a value for dbpartitionnum. This is only
** applicable in a partitioned database environment and ignored in other environments.

** - db2CfgSingleMember
** To update or reset the database configuration on a specific member, set this flag
** and provide a value for member. This is only applicable in a DB2 pureScale environment
** and ignored in other environments.

)";
/*  define functions in module */
PyMethodDef spclient_python_Methods[] =
{
     //{"run_the_test_udfcli", (PyCFunction)python_run_the_test_udfcli, METH_VARARGS,
     //run_the_test_udfcli_docstring.c_str()},

     //{"run_the_test_cli", (PyCFunction)python_run_the_test_cli, METH_VARARGS,
     //run_the_test_cli_docstring.c_str()},

     //{"run_the_test", (PyCFunction)python_run_the_test, METH_VARARGS,
     // "run_the_test(ibm_db.IBM_DBConnection)"},

     //{"run_the_test_only_windows", (PyCFunction)python_run_the_test_only_windows, METH_VARARGS,
     // "run_the_test_only_windows(byref(henv), byref(hdbc))"},

     //{"send_file_to_local_fs", (PyCFunction)python_send_file_to_local_fs, METH_VARARGS,
     // "send_file_to_local_fs(ibm_db.IBM_DBConnection, full_path_name)"},

     {"describe_parameters", (PyCFunction)python_describe_parameters, METH_VARARGS,
      "describe_parameters(ibm_db.IBM_DBStatement)"},

     //{"describe_parameters_by_cli", (PyCFunction)python_describe_parameters_by_cli, METH_VARARGS,
     // "describe_parameters_by_cli(argobj_hdbc.p, argobj_stmt.p)"},

     {"describe_columns", (PyCFunction)python_describe_columns, METH_VARARGS,
      "describe_columns(ibm_db.IBM_DBStatement, True, list_cols=[])"},

     //{"describe_procedure", (PyCFunction)python_describe_procedure, METH_VARARGS,
     // "describe_procedure(ibm_db.IBM_DBConnection, True, schema, procedure_name)"},

     //{"describe_admin_cmd_procedure", (PyCFunction)python_describe_admin_cmd_procedure, METH_VARARGS,
     // "python_describe_admin_cmd_procedure(ibm_db.IBM_DBConnection, True, schema, procedure_name, list_cols=[])"},

     //{"describe_columns_by_cli", (PyCFunction)python_describe_columns_by_cli, METH_VARARGS,
     // "describe_columns_by_cli(ctypes.c_void_p, ctypes.c_void_p)"},

     //{"sqlextendedstoreproc", (PyCFunction)python_sqlextendedstoreproc, METH_VARARGS,
     // "sqlextendedstoreproc(ibm_db.IBM_DBConnection)) doc"},

     //{"get_db_size", (PyCFunction)python_get_db_size, METH_VARARGS,
     // "get_db_size(ibm_db.IBM_DBConnection)"},

     //{"get_db_size_with_timestamp", (PyCFunction)python_get_db_size_with_timestamp, METH_VARARGS,
     // "get_db_size(ibm_db.IBM_DBConnection, DB2_TIMESTAMP)"},

     //{"create_dummy_exception", (PyCFunction)python_create_dummy_exception, METH_VARARGS,
     // "create_dummy_exception('whatever')"},

     //{"get_stmt_handle",  (PyCFunction)python_get_stmt_handle, METH_VARARGS,
     // "get_stmt_handle (ibm_db.IBM_DBStatement) doc, gets SQLHANDLE stmt from ibm_db.IBM_DBStatement"},

     //{"get_hdbc_handle",  (PyCFunction)python_get_hdbc_handle, METH_VARARGS,
     // "get_hdbc_handle(ibm_db.IBM_DBStatement) doc, gets SQLHDBC hdbc from ibm_db.IBM_DBStatement"},

     {"arrow_table_to_db2",  (PyCFunction)python_arrow_table_to_db2, METH_VARARGS,
      arrow_table_to_db2_docstring.c_str()},

     //{"sample_tbload_c",  (PyCFunction)python_sample_tbload_c, METH_VARARGS,
     //tbload_docstring.c_str()},

     //{"sample_tbload_c_cli",  (PyCFunction)python_sample_tbload_c_cli, METH_VARARGS,
     //tbload_docstring.c_str()},

     //{"extract_doublearray",  (PyCFunction)python_extract_doublearray, METH_VARARGS,
     // "extract_dublearray (ibm_db.IBM_DBConnection) "},

     //{"extract_array_one_big_csv",  (PyCFunction)python_extract_array_one_big_csv, METH_VARARGS,
     // "extract_array_one_big_csv (ibm_db.IBM_DBConnection, which_table))"},

     //{"extract_array_into_python",  (PyCFunction)python_extract_array_into_python, METH_VARARGS,
     // "extract_array_into_python (ibm_db.IBM_DBConnection)"},

    // {"update_dbcfg32",  (PyCFunction)python_update_dbcfg32, METH_VARARGS,
    //  update_dbcfg32_docstring.c_str()},

    // {"update_dbcfg64",  (PyCFunction)python_update_dbcfg64, METH_VARARGS,
    //  "update_dbcfg64 ('SAMPLE', 0, SQLF_DBTN_PL_STACK_TRACE, SQLF_PL_STACK_TRACE_NONE)"},

    // {"update_dbcfg_string",  (PyCFunction)python_update_dbcfg_string, METH_VARARGS,
    //  "update_dbcfg_string ('SAMPLE', 0, SQLF_DBTN_LOGARCHMETH1, 'LOGRETAIN')"},

    // {"sqlectnd",  (PyCFunction)python_sqlectnd, METH_VARARGS,
    //  "sqlectnd(nodename, hostname, service_name, comment) ex: sqlectnd('db2tcp1', 'localhost', '50010', 'db2 warehouse')"},

    // {"get_dbcfg_string",  (PyCFunction)python_get_dbcfg_string, METH_VARARGS,
    //  "get_dbcfg_string ('SAMPLE', spclient_python.SQLF_DBTN_LOGPATH)"},

    // {"get_dbcfg_int64",  (PyCFunction)python_get_dbcfg_int64, METH_VARARGS,
    //  "get_dbcfg_int64 ('SAMPLE', spclient_python.SQLF_DBTN_APPL_MEMORY)"},

/*
     {"get_dbcfg_int32",  (PyCFunction)python_get_dbcfg_int32, METH_VARARGS,
      "get_dbcfg_int32 ('SAMPLE', spclient_python.SQLF_DBTN_LOGFIL_SIZ)"},

     {"get_dbcfg_int16",  (PyCFunction)python_get_dbcfg_int16, METH_VARARGS,
      "get_dbcfg_int16 ('SAMPLE', spclient_python.SQLF_DBTN_APPLHEAPSZ)"},

     {"call_sp_blob",  (PyCFunction)python_call_sp_blob, METH_VARARGS,
      "call_sp_blob (conn)"},

     {"call_sp_get_message_pipe1",  (PyCFunction)python_call_sp_get_message_pipe1, METH_VARARGS,
      "call_sp_get_message_pipe1 (conn)"},

     {"list_database_directory",  (PyCFunction)python_list_database_directory, METH_NOARGS,
      "list_database_directory ()"},

     {"dbauthforcurrentuserdisplay",  (PyCFunction)python_dbauthforcurrentuserdisplay, METH_NOARGS,
      "dbauthforcurrentuserdisplay ()"},

     {"catalog_database",  (PyCFunction)python_catalog_database, METH_VARARGS,
      "catalog_database (dbname, dbalias, nodename, dbpath, comment)"},

     {"backup",  (PyCFunction)python_backup, METH_VARARGS,
      "backup (dbalias, user, pwd, options, workingpath)"},

     {"databaseupgrade",  (PyCFunction)python_databaseupgrade, METH_VARARGS,
      "databaseupgrade (dbalias, user, pwd)"},

     {"get_node_directory",  (PyCFunction)python_get_node_directory, METH_VARARGS,
      "get_node_directory ()"},

     {"monitor_load",  (PyCFunction)python_monitor_load, METH_VARARGS,
      "monitor_load ('TABLE_001')"},

     {"snapshot_monitor",  (PyCFunction)python_snapshot_monitor, METH_VARARGS,
      "snapshot_monitor()" },
 
     { "autoconfigure",  (PyCFunction)python_autoconfigure, METH_VARARGS,
       "autoconfigure (conn)" },

     { "SQLGetInfo",  (PyCFunction)python_SQLGetInfo, METH_VARARGS,
       "SQLGetInfo (conn, Info Type)" },

     { "SQLGetInfoInt",  (PyCFunction)python_SQLGetInfoInt, METH_VARARGS,
       "SQLGetInfoInt (conn, Info Type)" },

     {"SQLGetConnectAttrInt",  (PyCFunction)python_SQLGetConnectAttrInt, METH_VARARGS,
      "SQLGetConnectAttrInt (conn, SQL_ATTR_AUTOCOMMIT)" },

     { "SQLSetConnectAttrInt",  (PyCFunction)python_SQLSetConnectAttrInt, METH_VARARGS,
       "SQLSetConnectAttrInt (conn, SQL_ATTR_RETURN_USER_DEFINED_TYPES, SQL_TRUE)" },

     {"SQLGetStmtAttrInt",  (PyCFunction)python_SQLGetStmtAttrInt, METH_VARARGS,
      "SQLGetStmtAttrInt (stmt, SQL_ATTR_CLOSE_BEHAVIOR)" },
  
     { "SQLSetStmtAttrInt",  (PyCFunction)python_SQLSetStmtAttrInt, METH_VARARGS,
      "SQLSetStmtAttrInt (stmt, SQL_ATTR_CONCURRENCY, SQL_CONCUR_READ_ONLY)" },
*/
     {"set_mylog",  (PyCFunction)python_set_mylog, METH_VARARGS,
      "set_mylog (log.info)" },


     {NULL, NULL, 0, NULL}

};

#if PY_MAJOR_VERSION > 2
static struct PyModuleDef ccos_module_np =
{
    PyModuleDef_HEAD_INIT,
    "spclient_python", /* name of module */
    "hello this is my spclient_python to interface with ibm odbc cli python_callOutLanguage(henv, hdbc) doc",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    spclient_python_Methods
};

PyMODINIT_FUNC PyInit_spclient_python(void) //python 3
{
    PyObject *m;
    int ret = 0;
    m = PyModule_Create(&ccos_module_np); // Return value: New reference.
    SpClientError = PyErr_NewExceptionWithDoc("spclient_python.Error", error_docstring.c_str(), NULL, NULL); //Return value: New reference.
    // I am creating a new exception
    Py_INCREF(SpClientError); 
    ret = PyObject_SetAttrString(SpClientError, "errorMsg", Py_BuildValue("s", ""));
    ret = PyObject_SetAttrString(SpClientError, "SQLCODE", PyLong_FromLong(0));
    ret = PyObject_SetAttrString(SpClientError, "SQLSTATE", Py_BuildValue("s", ""));
    ret = PyModule_AddObject(m, "Error", SpClientError);
    // ret = -1 on error ret = 0 on success
    ret = add_module_globals(m);
    ret = add_module_globals_DBTN(m);
    ret = add_sqlcli(m);
    ret = add_sqlcli1(m);
    ret = add_sqlext(m);
    ret = add_sqlutil(m);
    ret = add_monitor(m);
    ret = add_sqlstate(m);
    ret = add_module_globlas_backup(m);
    ret = add_module_globals_sqlcodes(m);
    ret = add_module_globals_sqlenv(m);
    return m;
}
#else // Python 2.7...Py_InitModule way to initialize my module
// stopped supporting py2.7 as pybind11 cant compile under windows with py2.7 VC++ 2008

PyMODINIT_FUNC initspclient_python(void) //python 2.7
{
    PyObject *m;
    int ret = 0;

    m = Py_InitModule("spclient_python", spclient_python_Methods); // Return value: Borrowed reference.
    if (m == NULL)
        return;

    SpClientError = PyErr_NewExceptionWithDoc("spclient_python.Error", error_docstring.c_str(), NULL, NULL); //Return value: New reference.
    // I am creating a new exception
    Py_INCREF(SpClientError); 
    ret = PyObject_SetAttrString(SpClientError, "errorMsg", Py_BuildValue("s", ""));
    ret = PyObject_SetAttrString(SpClientError, "SQLCODE", PyLong_FromLong(0));
    ret = PyObject_SetAttrString(SpClientError, "SQLSTATE", Py_BuildValue("s", ""));
    ret = PyModule_AddObject(m, "Error", SpClientError);
    // ret = -1 on error ret = 0 on success
    ret = add_module_globals(m);
    ret = add_module_globals_DBTN(m);
    ret = add_sqlcli(m);
    ret = add_sqlcli1(m);
    ret = add_sqlext(m);
    ret = add_sqlutil(m);
    ret = add_monitor(m);
    ret = add_module_globlas_backup(m);
    ret = add_module_globals_sqlcodes(m);
    ret = add_module_globals_sqlenv(m);

}
#endif

