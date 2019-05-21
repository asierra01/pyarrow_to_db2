
#include "spclient_python_common_cpp.h"

//#include "ctypes.h" ? should I include this ? for PyCArgObject


PYOBJ_PTR mylog_info = Py_None;
PYOBJ_PTR SpClientError = NULL; // Creating a new exception


void print_mylog_info_format(const char* format, ...)
{
    va_list args;
    char buffer_log[100000] = { 0 };
    va_start(args, format);
    vsnprintf(buffer_log, 100000, format, args);
    if (mylog_info != Py_None)
    {
        py11::function mylog = py11::reinterpret_borrow<py11::function>(mylog_info);
        try
        {
            py11::str py_str(buffer_log);
            mylog(py_str);
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("error_already_set '%s' '%s'", e.what(), buffer_log);
        }
    }
    va_end(args);

}

void print_mylog_info(const char* buffer_log)
{
    if (mylog_info != Py_None)
    {
        py11::function mylog = py11::reinterpret_borrow<py11::function>(mylog_info);
        try
        {
            py11::str py_str(buffer_log);
            mylog(py_str);
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("error_already_set '%s' '%s'\n", e.what(), buffer_log);
            return;
        }
    }

}

string run_the_test_cli_docstring = R"(
ref_henv    = byref(self.mDb2_Cli.henv)
argobj_henv = PyCArgObject.from_address(id(ref_henv))

ref_hdbc    = byref(self.mDb2_Cli.hdbc)
argobj_hdbc = PyCArgObject.from_address(id(ref_hdbc))

run_the_test_cli(argobj_henv.p,
                argobj_hdbc.p,
                mylog.info)
    
)";

string arrow_table_to_db2_docstring = R"(

arrow_table_to_db2 (conn, MessageFile, TempFilesPath, DataBufferSize, Savecount, ChunkSize, log, table, tablespace_name, schema_name, table_name, column_oriented, drop_table

    Parameters
    ----------
    conn             : :class:`ibm_db.IBM_DBConnection` connection object
    MessageFile      : :obj:`str` load result MessageFile filename
    TempFilesPath    : :obj:`str` TempFilesPath
    DataBufferSize   : :obj:`int  data buffer size`, this could be zero
    Savecount        : :obj:`int` save count, this could be zero
    ChunkSize        : :obj:`int` chunk size
    log              : :func:`log.info` logging info function
    table            : :class:`pyarrow.lib.Table` pyarrow table object
    tablespace_name  : :obj:`str` Table space name
    schema_name      : :obj:`str` Schema name
    table_name       : :obj:`str` Table name
    column_oriented  : :obj:`bool` True or False column oriented table ?
    drop_table       : :obj:`bool` True or False drop the table before inserting ?

)";

string tbload_docstring = R"(

run the sample code tbload.c (ibm_db.IBM_DBConnection, mylog.info)  

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


/*  define functions in module */
PyMethodDef spclient_python_Methods[] =
{
     //{"run_the_test_cli", (PyCFunction)python_run_the_test_cli, METH_VARARGS,
     //run_the_test_cli_docstring.c_str()},

     //{"run_the_test", (PyCFunction)python_run_the_test, METH_VARARGS,
      //"run_the_test(ibm_db.IBM_DBConnection, mylog.info)"},

     //{"run_the_test_only_windows", (PyCFunction)python_run_the_test_only_windows, METH_VARARGS,
     // "run_the_test_only_windows(byref(henv), byref(hdbc), mylog.info)"},

     //{"send_file", (PyCFunction)python_send_file, METH_VARARGS,
     // "send_file(ibm_db.IBM_DBConnection, mylog.info)"},

     {"describe_parameters", (PyCFunction)python_describe_parameters, METH_VARARGS,
      "describe_parameters(ibm_db.IBM_DBStatement)"},

     //{"describe_parameters_by_cli", (PyCFunction)python_describe_parameters_by_cli, METH_VARARGS,
     // "describe_parameters_by_cli(argobj_hdbc.p, argobj_stmt.p, mylog.info)"},

     {"describe_columns", (PyCFunction)python_describe_columns, METH_VARARGS,
      "python_describe_columns(ibm_db.IBM_DBStatement)"},

     //{"describe_columns_by_cli", (PyCFunction)python_describe_columns_by_cli, METH_VARARGS,
     // "python_describe_columns_by_cli(ctypes.c_void_p, ctypes.c_void_p)"},

     //{"sqlextendedstoreproc", (PyCFunction)python_sqlextendedstoreproc, METH_VARARGS,
     // "sqlextendedstoreproc(ibm_db.IBM_DBConnection, mylog.info)) doc"},

     {"call_get_db_size", (PyCFunction)python_call_get_db_size, METH_VARARGS,
      "call_get_db_size(ibm_db.IBM_DBConnection, mylog.info)"},

     //{"call_get_db_size_with_timestamp", (PyCFunction)python_call_get_db_size_with_timestamp, METH_VARARGS,
     // "call_get_db_size(ibm_db.IBM_DBConnection, mylog.info, DB2_TIMESTAMP)"},

     {"create_dummy_exception", (PyCFunction)python_create_dummy_exception, METH_VARARGS,
      "create_dummy_exception('whatever')"},

     //{"get_stmt_handle",  (PyCFunction)python_get_stmt_handle, METH_VARARGS,
     // "get_stmt_handle (ibm_db.IBM_DBStatement, mylog.info) doc, gets SQLHANDLE stmt from ibm_db.IBM_DBStatement"},

     //{"get_hdbc_handle",  (PyCFunction)python_get_hdbc_handle, METH_VARARGS,
     // "get_hdbc_handle(ibm_db.IBM_DBStatement, mylog.info) doc, gets SQLHANDLE hdbc from ibm_db.IBM_DBStatement"},

     {"arrow_table_to_db2",  (PyCFunction)python_arrow_table_to_db2, METH_VARARGS,
      arrow_table_to_db2_docstring.c_str()},

     //{"sample_tbload_c",  (PyCFunction)python_sample_tbload_c, METH_VARARGS,
     //tbload_docstring.c_str()},

     //{"sample_tbload_c_cli",  (PyCFunction)python_sample_tbload_c_cli, METH_VARARGS,
     //tbload_docstring.c_str()},

     //{"extract_array",  (PyCFunction)python_extract_array, METH_VARARGS,
     // "extract_array (ibm_db.IBM_DBConnection, mylog.info) "},

     //{"extract_array_one_big_csv",  (PyCFunction)python_extract_array_one_big_csv, METH_VARARGS,
     // "extract_array_one_big_csv (ibm_db.IBM_DBConnection, mylog.info) doc, "},

     //{"extract_array_into_python",  (PyCFunction)python_extract_array_into_python, METH_VARARGS,
     // "extract_array_into_python (ibm_db.IBM_DBConnection, mylog.info)"},

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
    PyObject* m;
    int ret = 0;
    m = PyModule_Create(&ccos_module_np); // Return value: New reference.
    SpClientError = PyErr_NewException("spclient_python.Error", NULL, NULL); //Return value: New reference.
    // I am creating a new exception
    //Py_INCREF(SpClientError); 
    //I dont think I need to increment the ref as PyErr_NewException already return a new ref
    ret = PyModule_AddObject(m, "Error", SpClientError);
    // ret = -1 on error ret = 0 on success

    return m;
}
#else // Python 2.7...Py_InitModule way to initialize my module

PyMODINIT_FUNC initspclient_python(void) //python 2.7
{
    PyObject* m;
    int ret = 0;

    m = Py_InitModule("spclient_python", spclient_python_Methods); // Return value: Borrowed reference.
    if (m == NULL)
        return;

    SpClientError = PyErr_NewException("spclient_python.Error", NULL, NULL); //Return value: New reference.
    // I am creating a new exception
    //Py_INCREF(SpClientError); I dont think I need to increment the ref as PyErr_NewException already return a new ref
    ret = PyModule_AddObject(m, "Error", SpClientError);
    // ret = -1 on error ret = 0 on success
}
#endif

