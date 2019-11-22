
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

/*  wrapped python_get_db_size function */
PYOBJ_PTR python_get_db_size(PYOBJ_PTR self, PYOBJ_PTR args)
{
    ERROR_VAR
    int ret;
    PYOBJ_PTR py_conn_res = nullptr;
    conn_handle* conn_res = nullptr;
    PYOBJ_PTR py_mylist;
    PYOBJ_PTR py_datetime;
    SQLBIGINT            out_DATABASESIZE = 0;
    SQLBIGINT            out_DATABASECAPACITY = 0;
    SQL_TIMESTAMP_STRUCT out_snapshottimestamp = {};


    /*

        possible Python call : python_get_db_size(conn)
    */
    if (!PyArg_ParseTuple(args, "O",
        &py_conn_res))
    {
        PyErr_Format(PyExc_ValueError,
            "parameters count must be one ibm_db.IBM_DBConnection");
        return NULL;
    }

    if (py_conn_res == NULL)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied connection object Parameter is invalid NULL it should be of type ibm_db.IBM_DBConnection");
        return NULL;

    }
    if (py_conn_res == Py_None)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied connection object Parameter is invalid '%s' it should be of type ibm_db.IBM_DBConnection",
            Py_TYPE(py_conn_res)->tp_name);
        return NULL;

    }

    if (strcmp(Py_TYPE(py_conn_res)->tp_name, IBM_DBConnection) != 0)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied connection object Parameter is invalid '%s' it should be of type ibm_db.IBM_DBConnection",
            Py_TYPE(py_conn_res)->tp_name);
        return NULL;
    }
    else
        conn_res = (conn_handle*)py_conn_res;

    out_DATABASESIZE = 0;
    out_DATABASECAPACITY = 0;
    if (conn_res != nullptr)
    {
        ret = get_db_size(
            //conn_res->henv,
            conn_res->hdbc,
            &out_DATABASESIZE,
            &out_DATABASECAPACITY,
            &out_snapshottimestamp,
            ERROR_VAR_PARAM_1);
        SPCLIENT_ERROR_MESSAGE
    }

    
    //LOG_INFO("here %d-%d-%d  %d-%d %ld", 
    //    out_snapshottimestamp.year, 
    //    out_snapshottimestamp.month, 
    //    out_snapshottimestamp.day,
    //    out_snapshottimestamp.hour,
    //    out_snapshottimestamp.second, 
    //    out_snapshottimestamp.fraction/ 1000);
        

    PyDateTime_IMPORT;
    py_datetime = PyDateTime_FromDateAndTime(
        (int)out_snapshottimestamp.year,
        (int)out_snapshottimestamp.month,
        (int)out_snapshottimestamp.day,
        (int)out_snapshottimestamp.hour,
        (int)out_snapshottimestamp.minute,
        (int)out_snapshottimestamp.second,
        (int)(out_snapshottimestamp.fraction / 1000)); // Return value: New reference.
   


    py_mylist = Py_BuildValue("[LLO]", 
        out_DATABASESIZE, 
        out_DATABASECAPACITY, 
        py_datetime); // L as long long = int64 = SQLBIGINT //  result is a new reference
    return py_mylist;

}


/*  wrapped python_get_db_size function */
PYOBJ_PTR python_get_db_size_with_timestamp(PYOBJ_PTR self, PYOBJ_PTR args)
{
    ERROR_VAR
    int ret;
    PYOBJ_PTR py_conn_res = nullptr;
    PYOBJ_PTR pySNAPSHOTTIMESTAMP;
    conn_handle *conn_res = NULL;
    PYOBJ_PTR py_mylist;
    SQLBIGINT            out_DATABASESIZE;
    SQLBIGINT            out_DATABASECAPACITY;
    SQL_TIMESTAMP_STRUCT out_snapshottimestamp;


    /*
        self.conn = ibm_db.pconnect(self.mDb2_Cli.conn_str,
                                    self.mDb2_Cli.encode_utf8(self.mDb2_Cli.DB2_USER),
                                    self.mDb2_Cli.encode_utf8(self.mDb2_Cli.DB2_PASSWORD),
                                    self.mDb2_Cli.conn_options_autocommit_off)

        possible Python call : python_call_get_db_size(conn, self.SNAPSHOTTIMESTAMP)
    */
    if (!PyArg_ParseTuple(args, "OO", 
        &py_conn_res, 
        &pySNAPSHOTTIMESTAMP))
    {
        PyErr_Format(PyExc_ValueError, 
            "parameters count must be two ibm_db.IBM_DBConnection, and an instance of DB2_TIMESTAMP ");
        return NULL;
    }
    if (pySNAPSHOTTIMESTAMP == NULL)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied DB2_TIMESTAMP object Parameter is invalid NULL it should be of type 'DB2_TIMESTAMP'");
        return NULL;

    }

    if (strcmp(Py_TYPE(pySNAPSHOTTIMESTAMP)->tp_name, "DB2_TIMESTAMP") != 0)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied DB2_TIMESTAMP object Parameter is invalid '%s' it should be type 'DB2_TIMESTAMP'",
                     Py_TYPE(pySNAPSHOTTIMESTAMP)->tp_name );
        return NULL;
    }

    if (py_conn_res == NULL)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied connection object Parameter is invalid NULL it should be of type ibm_db.IBM_DBConnection");
        return NULL;

    }

    
    if (strcmp(Py_TYPE(py_conn_res)->tp_name, IBM_DBConnection) != 0)
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
    ret = get_db_size(//conn_res->henv, 
                     conn_res->hdbc,
                     &out_DATABASESIZE,
                     &out_DATABASECAPACITY,
                     &out_snapshottimestamp,
                     ERROR_VAR_PARAM_1);
    SPCLIENT_ERROR_MESSAGE
    py11_set_DB2_TIMESTAMP(pySNAPSHOTTIMESTAMP, out_snapshottimestamp);
    py_mylist = Py_BuildValue("[LL]", 
        out_DATABASESIZE, 
        out_DATABASECAPACITY); // L as long long = int64 = SQLBIGINT // result is a new reference
    return py_mylist;

}

int get_db_size(
//SQLHANDLE henv,
SQLHDBC hdbc,
SQLBIGINT    *out_DATABASESIZE,
SQLBIGINT    *out_DATABASECAPACITY,
SQL_TIMESTAMP_STRUCT *out_snapshottimestamp,
ERROR_VAR_PARAM_DEF)
{
  SQLRETURN    cliRC = SQL_SUCCESS;
  int          rc    = 0;
  SQLHANDLE    hstmt = SQL_NULL_HSTMT; /* statement handle */
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

