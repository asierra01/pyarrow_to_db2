
#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"

void py11_set_DB2_TIMESTAMP(
    PYOBJ_PTR pySNAPSHOTTIMESTAMP,
    SQL_TIMESTAMP_STRUCT &out_snapshottimestamp)
{
    py11::object py11_pySNAPSHOTTIMESTAMP = py11::reinterpret_borrow<py11::object>(pySNAPSHOTTIMESTAMP);
    //print_dir(py11_pySNAPSHOTTIMESTAMP);
    py11_pySNAPSHOTTIMESTAMP.attr("year")     = py11::int_(out_snapshottimestamp.year);
    py11_pySNAPSHOTTIMESTAMP.attr("month")    = py11::int_(out_snapshottimestamp.month);
    py11_pySNAPSHOTTIMESTAMP.attr("day")      = py11::int_(out_snapshottimestamp.day);
    py11_pySNAPSHOTTIMESTAMP.attr("hour")     = py11::int_(out_snapshottimestamp.hour);
    py11_pySNAPSHOTTIMESTAMP.attr("minute")   = py11::int_(out_snapshottimestamp.minute);
    py11_pySNAPSHOTTIMESTAMP.attr("second")   = py11::int_(out_snapshottimestamp.second);
    py11_pySNAPSHOTTIMESTAMP.attr("fraction") = py11::int_(out_snapshottimestamp.fraction);

}

/*
void set_DB2_TIMESTAMP(
    PyObject * pySNAPSHOTTIMESTAMP,
    SQL_TIMESTAMP_STRUCT &out_snapshottimestamp)
{
    PyObject *arglist = NULL;
    PyObject *pyFunction = NULL;
    PyObject *py_result = NULL;
    pyFunction = PyObject_GetAttrString(pySNAPSHOTTIMESTAMP, (char *)"__setattr__"); // New reference.
    arglist = Py_BuildValue("(si)",  "year", out_snapshottimestamp.year);
    py_result = PyObject_CallObject(pyFunction, arglist);
    Py_XDECREF(arglist);
    Py_XDECREF(py_result);

    arglist = Py_BuildValue("(si)",  "month", out_snapshottimestamp.month);
    py_result = PyObject_CallObject(pyFunction, arglist);
    Py_XDECREF(arglist);
    Py_XDECREF(py_result);

    arglist = Py_BuildValue("(si)", "day", out_snapshottimestamp.day);
    py_result = PyObject_CallObject(pyFunction, arglist);
    Py_XDECREF(arglist);
    Py_XDECREF(py_result);

    arglist = Py_BuildValue("(si)", "hour", out_snapshottimestamp.hour);
    py_result = PyObject_CallObject(pyFunction, arglist);
    Py_XDECREF(arglist);
    Py_XDECREF(py_result);

    arglist = Py_BuildValue("(si)", "minute", out_snapshottimestamp.minute);
    py_result = PyObject_CallObject(pyFunction, arglist);
    Py_XDECREF(arglist);
    Py_XDECREF(py_result);

    arglist = Py_BuildValue("(si)", "second", out_snapshottimestamp.second);
    py_result = PyObject_CallObject(pyFunction, arglist);
    Py_XDECREF(arglist);
    Py_XDECREF(py_result);

    arglist = Py_BuildValue("(si)", "fraction", out_snapshottimestamp.fraction);
    py_result = PyObject_CallObject(pyFunction, arglist);
    Py_XDECREF(arglist);
    Py_XDECREF(py_result);

    Py_XDECREF(pyFunction);

}
*/

/*  wrapped python_call_get_db_size function */
PYOBJ_PTR python_call_get_db_size(PYOBJ_PTR self, PYOBJ_PTR args)
{
    int rc;
    PYOBJ_PTR py_conn_res = NULL;
    PYOBJ_PTR pySNAPSHOTTIMESTAMP;
    conn_handle *conn_res;
    PYOBJ_PTR py_mylist;
    SQLBIGINT            out_DATABASESIZE;
    SQLBIGINT            out_DATABASECAPACITY;
    SQL_TIMESTAMP_STRUCT out_snapshottimestamp;


    /*
        self.conn = ibm_db.pconnect(self.mDb2_Cli.conn_str,
                                    self.mDb2_Cli.encode_utf8(self.mDb2_Cli.DB2_USER),
                                    self.mDb2_Cli.encode_utf8(self.mDb2_Cli.DB2_PASSWORD),
                                    self.mDb2_Cli.conn_options_autocommit_off)

        possible Python call : python_call_get_db_size(conn, mylog.info, self.SNAPSHOTTIMESTAMP)
    */
    if (!PyArg_ParseTuple(args, "OOO", 
        &py_conn_res, 
        &mylog_info, 
        &pySNAPSHOTTIMESTAMP))
    {
        PyErr_Format(PyExc_ValueError, 
            "parameters count must be three ibm_dbIBM_DBConnection, mylog.info and an instance of SNAPSHOTTIMESTAMP '%s'", 
            "yes three parameters");
        return NULL;
    }

    if (strcmp(Py_TYPE(pySNAPSHOTTIMESTAMP)->tp_name, "DB2_TIMESTAMP") != 0)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied DB2_TIMESTAMP object Parameter is invalid '%s' it should be type 'DB2_TIMESTAMP'",
                     Py_TYPE(py_conn_res)->tp_name );
        return NULL;
    }

    if (strcmp(Py_TYPE(py_conn_res)->tp_name, "ibm_db.IBM_DBConnection") != 0)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied connection object Parameter is invalid '%s' it should be of type ibm_db.IBM_DBConnection",
                     Py_TYPE(py_conn_res)->tp_name );
        return NULL;
    }
    else
        conn_res = (conn_handle *)py_conn_res;

    out_DATABASESIZE = 0;
    out_DATABASECAPACITY = 0;
    rc = get_db_size(conn_res->henv, 
                     conn_res->hdbc,
                     &out_DATABASESIZE,
                     &out_DATABASECAPACITY,
                     &out_snapshottimestamp );

    //set_DB2_TIMESTAMP(pySNAPSHOTTIMESTAMP, out_snapshottimestamp);
    py11_set_DB2_TIMESTAMP(pySNAPSHOTTIMESTAMP, out_snapshottimestamp);

    py_mylist = Py_BuildValue("[LL]", out_DATABASESIZE, out_DATABASECAPACITY); // L as long long = int64 = SQLBIGINT
    return py_mylist;

}

int get_db_size(
SQLHANDLE henv,
SQLHANDLE hdbc,
SQLBIGINT    *out_DATABASESIZE,
SQLBIGINT    *out_DATABASECAPACITY,
SQL_TIMESTAMP_STRUCT *out_snapshottimestamp)
{
  SQLRETURN    cliRC = SQL_SUCCESS;
  int          rc    = 0;
  SQLHANDLE    hstmt; /* statement handle */
  SQLINTEGER   in_out_REFRESHWINDOW = 0;
  SQLINTEGER   len_out_snapshottimestamp = 0;

  //char procName[] = "GET_DBSIZE_INFO";
  SQLCHAR *stmt = (SQLCHAR *)"CALL GET_DBSIZE_INFO (?, ?, ?, ?)";


  //LOG_INFO("CALL stored procedure: '%s'", procName);

  /* allocate a statement handle */
  cliRC = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
  DBC_HANDLE_CHECK(hdbc, cliRC);

  /* prepare the statement */
  cliRC = SQLPrepare(hstmt, stmt, SQL_NTS);
  STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);


  /* bind the parameter to the statement */
   cliRC = SQLBindParameter(hstmt,
                           1,
                           SQL_PARAM_OUTPUT,
                           SQL_C_TYPE_TIMESTAMP,
                           SQL_TYPE_TIMESTAMP,
                           0,
                           0,
                           out_snapshottimestamp,
                           sizeof(SQL_TIMESTAMP_STRUCT),
                           &len_out_snapshottimestamp);
   STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

   cliRC = SQLBindParameter(hstmt,
                            2,
                            SQL_PARAM_OUTPUT,
                            SQL_C_SBIGINT,
                            SQL_BIGINT,
                            0,
                            0,
                            out_DATABASESIZE,
                            0,
                            NULL);
   STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

   cliRC = SQLBindParameter(hstmt,
                            3,
                            SQL_PARAM_OUTPUT,
                            SQL_C_SBIGINT,
                            SQL_BIGINT,
                            0,
                            0,
                            out_DATABASECAPACITY,
                            0,
                            NULL);
   STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

   cliRC = SQLBindParameter(hstmt,
                           4,
                           SQL_PARAM_INPUT_OUTPUT,
                           SQL_C_LONG,
                           SQL_INTEGER,
                           0,
                           0,
                           &in_out_REFRESHWINDOW,
                           0,
                           NULL);
   STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);


  /* execute the statement */
  Py_BEGIN_ALLOW_THREADS;
  cliRC = SQLExecute(hstmt);
  Py_END_ALLOW_THREADS;

  STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);


  /* free the statement handle */
  cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
  STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

  return cliRC;
} /* end get_db_size */

