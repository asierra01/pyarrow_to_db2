

#include <utility>
#include "spclient_python_common_cpp.h"

using namespace py11::literals;
using namespace std;


static int func_registered_set_table_describe_parameters = 0;

void register_table_parameter()
{
    string some_command_find_path = R"(
def set_table_describe_parameters():
    from texttable import Texttable
    table = Texttable()              
    table.set_deco(Texttable.HEADER) 
    table.set_cols_dtype(['t',       
                         't',        
                         't',        
                         't',        
                         't',        
                         't'])
    table.set_cols_align(  ['l',  'r', 'l', 'r', 'r', 'l'])
    table.set_header_align(['l',  'r', 'l', 'r', 'r', 'l'])
    table.header(['no',
                  'pfSqlType',
                  'sql type',
                  'pibScale',
                  'pcbColDef',
                  'pfNullable'])
    table.set_cols_width([4,  10, 20, 10, 15, 10])
    return table 
)";
    if (func_registered_set_table_describe_parameters == 0)
    {
        func_registered_set_table_describe_parameters = 1;
        try
        {
            py11::exec(some_command_find_path.c_str());
        }
        catch (py11::error_already_set& e)
        {
            func_registered_set_table_describe_parameters = 0;
            LOG_INFO("py::exec  '%s'", e.what());
            return;
        }
    }
}

py11::object get_table_parameters()
{
    py11::object py_set_table_describe_parameters;
    int err = 0;

    if (func_registered_set_table_describe_parameters == 0)
        register_table_parameter();

    try
    {
        py_set_table_describe_parameters = py11::globals()["set_table_describe_parameters"];
    }
    catch (py11::error_already_set & e)
    {
        err = 1;
        LOG_INFO("set_table_describe_parameters  %s", e.what());

    }

    if (err == 1)
    {
        func_registered_set_table_describe_parameters = 0;
        register_table_parameter();
        try
        {
            py_set_table_describe_parameters = py11::globals()["set_table_describe_parameters"];
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("set_table_describe_parameters  %s", e.what());
            return py11::cast<py11::none>(Py_None);

        }

    }
    try
    {
        return py_set_table_describe_parameters();
    }
    catch (py11::error_already_set & e)
    {
        LOG_INFO("py_set_table_describe_parameters  %s", e.what());
        return py11::cast<py11::none>(Py_None);

    }
}
/*  wrapped python_describe_parameters function consuming ibm_db.IBM_DBStatement */
PYOBJ_PTR python_describe_parameters(PYOBJ_PTR self, PYOBJ_PTR args)
{
    PYOBJ_PTR py_stmt_res;
    stmt_handle *stmt_res;
    int ret = 0;

    if (!PyArg_ParseTuple(args, "OO", &py_stmt_res, &mylog_info))
    {
        PyErr_Format(PyExc_ValueError, 
            "parameters count must be 1  ibm_db.IBM_DBStatement, '%s'", 
            "yes 1 parameters");
        return NULL;
    }

    if (NIL_P(py_stmt_res))
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied conn object Parameter is NULL  '%s' it should be ibm_db.IBM_DBStatement",
                     Py_TYPE(py_stmt_res)->tp_name );
        return NULL;

    }

    //printf("%s\n", Py_TYPE(py_str_sql_dict)->tp_name); // yes dict
    if (strcmp(Py_TYPE(py_stmt_res)->tp_name, "ibm_db.IBM_DBStatement") != 0)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied connection object Parameter is invalid '%s' it should be ibm_db.IBM_DBStatement",
                     Py_TYPE(py_stmt_res)->tp_name );
        return NULL;
    }
    else
        stmt_res = (stmt_handle *)py_stmt_res;

    ret = display_parameters(stmt_res->hdbc, stmt_res->hstmt);

    Py_RETURN_NONE;

}

/*  wrapped python_describe_parameters function consuming vctypes.void_p */
PYOBJ_PTR python_describe_parameters_by_cli(
    PYOBJ_PTR self, 
    PYOBJ_PTR args)
{
    PYOBJ_PTR py_stmt;
    PYOBJ_PTR py_hdbc;
    SQLHANDLE *hstmt = 0; /* statement handle */
    SQLHANDLE *hdbc = 0;  /* connection handle */

    int ret = 0;

    if (!PyArg_ParseTuple(args, "OOO", &py_hdbc, &py_stmt, &mylog_info))
    {
        PyErr_Format(PyExc_ValueError,
            "parameters count must be 3, '%s'",
            "yes 3 parameters");
        return NULL;
    }

    hdbc  = (SQLHANDLE *)PyLong_AsVoidPtr(py_hdbc);
    hstmt = (SQLHANDLE *)PyLong_AsVoidPtr(py_stmt);
    ret = display_parameters(*hdbc, *hstmt);

    Py_RETURN_NONE;

}


static int my_dict_init = 0;
MAP_INT_STRING &map_sql_value_sql_str()
{

#if  (_MSC_VER == 1500) || (__APPLE__) || defined(__linux__)// VS 2008 PY 2.7 Win Default c++
    static MAP_INT_STRING str_sql_dict;
    if (my_dict_init == 0)
    {
        str_sql_dict[SQL_UNKNOWN_TYPE] =       "SQL_UNKNOWN_TYPE";
        str_sql_dict[SQL_CHAR] =               "SQL_CHAR";
        str_sql_dict[SQL_NUMERIC] =            "SQL_NUMERIC";
        str_sql_dict[SQL_DECIMAL] =            "SQL_DECIMAL";
        str_sql_dict[SQL_INTEGER] =            "SQL_INTEGER";
        str_sql_dict[SQL_SMALLINT] =           "SQL_SMALLINT";
        str_sql_dict[SQL_FLOAT] =              "SQL_FLOAT";
        str_sql_dict[SQL_REAL] =               "SQL_REAL";
        str_sql_dict[SQL_DOUBLE] =             "SQL_DOUBLE";
        str_sql_dict[SQL_DATETIME] =           "SQL_DATETIME";
        str_sql_dict[SQL_VARCHAR] =            "SQL_VARCHAR";
        str_sql_dict[SQL_BOOLEAN] =            "SQL_BOOLEAN";
        str_sql_dict[SQL_ROW] =                "SQL_ROW";
        str_sql_dict[SQL_WCHAR] =              "SQL_WCHAR";
        str_sql_dict[SQL_WVARCHAR] =           "SQL_WVARCHAR";
        str_sql_dict[SQL_WLONGVARCHAR] =       "SQL_WLONGVARCHAR";
        str_sql_dict[SQL_DECFLOAT] =           "SQL_DECFLOAT";
        //# One-parameter shortcuts for date/time data types
        str_sql_dict[SQL_TYPE_DATE] =          "SQL_TYPE_DATE";
        str_sql_dict[SQL_TYPE_TIME] =          "SQL_TYPE_TIME";
        str_sql_dict[SQL_TYPE_TIMESTAMP] =     "SQL_TYPE_TIMESTAMP";
        //# SQL Datatype for Time Zone
        str_sql_dict[SQL_TYPE_TIMESTAMP_WITH_TIMEZONE] = "SQL_TYPE_TIMESTAMP_WITH_TIMEZONE";
        str_sql_dict[SQL_C_DEFAULT] =          "SQL_C_DEFAULT";
        str_sql_dict[SQL_BIGINT] =             "SQL_BIGINT";
        str_sql_dict[SQL_GRAPHIC] =            "SQL_GRAPHIC";
        str_sql_dict[SQL_VARGRAPHIC] =         "SQL_VARGRAPHIC";
        str_sql_dict[SQL_LONGVARGRAPHIC] =     "SQL_LONGVARGRAPHIC";
        str_sql_dict[SQL_BLOB] =               "SQL_BLOB";
        str_sql_dict[SQL_CLOB] =               "SQL_CLOB";
        str_sql_dict[SQL_DBCLOB] =             "SQL_DBCLOB";
        str_sql_dict[SQL_XML] =                "SQL_XML";
        str_sql_dict[SQL_CURSORHANDLE] =       "SQL_CURSORHANDLE";
        str_sql_dict[SQL_DATALINK] =           "SQL_DATALINK";
        str_sql_dict[SQL_USER_DEFINED_TYPE] =  "SQL_USER_DEFINED_TYPE";
        //# SQL extended datatypes
        str_sql_dict[SQL_DATE] =               "SQL_DATE";
        str_sql_dict[SQL_INTERVAL] =           "SQL_INTERVAL";
        str_sql_dict[SQL_TIME] =               "SQL_TIME";
        str_sql_dict[SQL_TIMESTAMP] =          "SQL_TIMESTAMP";
        str_sql_dict[SQL_LONGVARCHAR] =        "SQL_LONGVARCHAR";
        str_sql_dict[SQL_BINARY] =             "SQL_BINARY";
        str_sql_dict[SQL_VARBINARY] =          "SQL_VARBINARY";
        str_sql_dict[SQL_LONGVARBINARY] =      "SQL_LONGVARBINARY";
        str_sql_dict[SQL_TINYINT] =            "SQL_TINYINT";
        str_sql_dict[SQL_BIT] =                "SQL_BIT";
        str_sql_dict[SQL_GUID] =               "SQL_GUID";
    }
#else
    static MAP_INT_STRING str_sql_dict;
    if (my_dict_init == 0)
    {
        str_sql_dict =
        {
            {SQL_UNKNOWN_TYPE       , "SQL_UNKNOWN_TYPE"},
            {SQL_CHAR               , "SQL_CHAR"},
            {SQL_NUMERIC            , "SQL_NUMERIC"},
            {SQL_DECIMAL            , "SQL_DECIMAL"},
            {SQL_INTEGER            , "SQL_INTEGER"},
            {SQL_SMALLINT           , "SQL_SMALLINT"},
            {SQL_FLOAT              , "SQL_FLOAT"},
            {SQL_REAL               , "SQL_REAL"},
            {SQL_DOUBLE             , "SQL_DOUBLE"},
            {SQL_DATETIME           , "SQL_DATETIME"},
            {SQL_VARCHAR            , "SQL_VARCHAR"},
            {SQL_BOOLEAN            , "SQL_BOOLEAN"},
            {SQL_ROW                , "SQL_ROW"},
            {SQL_WCHAR              , "SQL_WCHAR"},
            {SQL_WVARCHAR           , "SQL_WVARCHAR"},
            {SQL_WLONGVARCHAR       , "SQL_WLONGVARCHAR"},
            {SQL_DECFLOAT           , "SQL_DECFLOAT"},
            //# One-parameter shortcuts for date/time data types
            {SQL_TYPE_DATE          , "SQL_TYPE_DATE"},
            {SQL_TYPE_TIME          , "SQL_TYPE_TIME"},
            {SQL_TYPE_TIMESTAMP     , "SQL_TYPE_TIMESTAMP"},
            //# SQL Datatype for Time Zone
            {SQL_TYPE_TIMESTAMP_WITH_TIMEZONE , "SQL_TYPE_TIMESTAMP_WITH_TIMEZONE"},
            {SQL_C_DEFAULT          , "SQL_C_DEFAULT"},
            {SQL_BIGINT             , "SQL_BIGINT"},
            {SQL_GRAPHIC            , "SQL_GRAPHIC"},
            {SQL_VARGRAPHIC         , "SQL_VARGRAPHIC"},
            {SQL_LONGVARGRAPHIC     , "SQL_LONGVARGRAPHIC"},
            {SQL_BLOB               , "SQL_BLOB"},
            {SQL_CLOB               , "SQL_CLOB"},
            {SQL_DBCLOB             , "SQL_DBCLOB"},
            {SQL_XML                , "SQL_XML"},
            {SQL_CURSORHANDLE       , "SQL_CURSORHANDLE"},
            {SQL_DATALINK           , "SQL_DATALINK"},
            {SQL_USER_DEFINED_TYPE  , "SQL_USER_DEFINED_TYPE"},
            //# SQL extended datatypes
            {SQL_DATE               , "SQL_DATE"},
            {SQL_INTERVAL           , "SQL_INTERVAL"},
            {SQL_TIME               , "SQL_TIME"},
            {SQL_TIMESTAMP          , "SQL_TIMESTAMP"},
            {SQL_LONGVARCHAR        , "SQL_LONGVARCHAR"},
            {SQL_BINARY             , "SQL_BINARY"},
            {SQL_VARBINARY          , "SQL_VARBINARY"},
            {SQL_LONGVARBINARY      , "SQL_LONGVARBINARY"},
            {SQL_TINYINT            , "SQL_TINYINT"},
            {SQL_BIT                , "SQL_BIT"},
            {SQL_GUID               , "SQL_GUID"}
        };
    }
#endif
    my_dict_init = 1;
    return str_sql_dict;
}

int display_parameters_map(
        SQLHANDLE      hdbc,
        SQLHANDLE      hstmt,
        MAP_COLNO_COLUMN_INFO   &map_colno_sql_type,
        bool display)
{
    int rc = 0;
    py11::object  py_table;
    SQLRETURN     cliRC = SQL_SUCCESS;
    SQLSMALLINT   NumParams;
    SQLSMALLINT   pfSqlType;
    SQLULEN       pcbColDef;
    SQLSMALLINT   pibScale;
    SQLSMALLINT   pfNullable;
    string        str_sql_type;

    Py_BEGIN_ALLOW_THREADS;
    cliRC = SQLNumParams(hstmt, &NumParams);
    Py_END_ALLOW_THREADS;

    if (NumParams == 0)
    {
        LOG_INFO ("NumParams = 0");
        return 0;
    }
    else
    {
        //LOG_INFO("NumParams = %d", NumParams);
    }

    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    if (display)
        py_table = get_table_parameters();

    for (int col = 1; col <= NumParams; col++)
    {
        pfNullable = 0;
        pfSqlType = 0;
        Py_BEGIN_ALLOW_THREADS
        rc = SQLDescribeParam(hstmt,
                               col,
                               &pfSqlType,
                               &pcbColDef,
                               &pibScale,
                               &pfNullable);
        Py_END_ALLOW_THREADS
        rc = check_error(hdbc, hstmt, rc, __LINE__, __FUNCTION__);
        COLUMN_INFO col_info;
        col_info.pcbColDef = pcbColDef;
        col_info.pfNullabl = pfNullable;
        col_info.pfSqlType = pfSqlType;
        col_info.pibScale = pibScale;
        map_colno_sql_type[col] = col_info;
        str_sql_type = map_sql_value_sql_str()[pfSqlType];

        if (rc != 0)
            return rc;

        if (((rc == SQL_SUCCESS) || rc == (SQL_SUCCESS_WITH_INFO)) && display)
        {


            py11::list py11_my_row = py11::reinterpret_borrow<py11::list>(Py_BuildValue("[iisiOi]",
                col,
                pfSqlType,
                str_sql_type.c_str(),
                pibScale,
                "{:,}"_s.format(pcbColDef).ptr(),
                pfNullable));
            py_table.attr("add_row")(py11_my_row);
            
        }
    }

    if (display)
    {

        py11::str ret = py_table.attr("draw")();
        LOG_INFO("py11 parameters\n%s\n", ((string)ret).c_str());

    }
    return 0;
}

int display_parameters(
    SQLHANDLE      hdbc,
    SQLHANDLE      hstmt)
{
    MAP_COLNO_COLUMN_INFO   map_colno_sql_type_dummy;

    return  display_parameters_map(
        hdbc,
        hstmt,
        map_colno_sql_type_dummy,
        true);
}
