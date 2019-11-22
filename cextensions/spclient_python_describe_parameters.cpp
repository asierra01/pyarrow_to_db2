

//#include <utility>
#include "spclient_python_common_cpp.h"

using namespace py11::literals;
using namespace std;


static int func_registered_get_table_describe_parameters = 0;

py11::function py_get_table_describe_parameters;

void register_table_parameter()
{
    string str_get_table_describe_parameters = R"(
def get_table_describe_parameters():
    from texttable import Texttable
    table = Texttable()              
    table.set_deco(Texttable.HEADER) 
    table.set_cols_dtype(['t',       
                         't',        
                         't',        
                         't',        
                         't',        
                         't',
                         't'])
    table.set_cols_align(  ['l',  'r', 'l', 'r', 'r', 'l', 'l'])
    table.set_header_align(['l',  'r', 'l', 'r', 'r', 'l', 'l'])
    table.header(['no',
                  'pfSqlType',
                  'sql type',
                  'pibScale',
                  'pcbColDef',
                  'pfNullable',
                  'SQL_DESC_USER_DEFINED_TYPE_CODE'])
    table.set_cols_width([4,  10, 20, 10, 15, 24, 34])
    return table 
)";
    if (func_registered_get_table_describe_parameters == 0)
    {
        func_registered_get_table_describe_parameters = 1;
        try
        {
            //py11::exec(str_get_table_describe_parameters.c_str());
            PyObject * main_module = PyImport_AddModule("__main__"); //Borrowed reference. 
            PyObject * main_dict = PyModule_GetDict(main_module);  //Borrowed reference. same as main_module.__dict__ 
            py11::object obj = py11::eval<py11::eval_single_statement>(str_get_table_describe_parameters.c_str(),
                                                                       py11::globals(),
                                                                       py11::globals());
            py_get_table_describe_parameters = py11::reinterpret_borrow<py11::function> 
                (py11::globals()["get_table_describe_parameters"]);
            //LOG_INFO("py_get_table_describe_parameters type '%s'", Py_TYPE(py_get_table_describe_parameters.ptr())->tp_name); // function
            //print_mylog_info("trying PyModule_AddObject");
            int ret = PyDict_SetItemString(main_dict,
                                           "get_table_describe_parameters",
                                           py_get_table_describe_parameters.ptr());
            //print_mylog_info("trying PyModule_AddObject done");
            if (ret != 0)
            {
                LOG_INFO("PyDict_SetItemString ret %d", ret);
                return;
            }


        }
        catch (py11::error_already_set& e)
        {
            func_registered_get_table_describe_parameters = 0;
            LOG_INFO("py::exec error_already_set '%s'", e.what());
            return;
        }
    }
}

py11::object get_table_parameters()
{
    int err = 0;

    if (func_registered_get_table_describe_parameters == 0)
        register_table_parameter();

    try
    {
        PyObject* main_module = PyImport_AddModule("__main__"); // Borrowed reference.
        PyObject* main_dict = PyModule_GetDict(main_module);  //Borrowed reference. same as main_module.__dict__ 
        PyObject* get_table_describe_parameters = PyDict_GetItemString(main_dict, "get_table_describe_parameters");
        py_get_table_describe_parameters = py11::reinterpret_borrow<py11::function>(get_table_describe_parameters);
        return py_get_table_describe_parameters();
        //return py11::globals()["get_table_describe_parameters"]();
    }
    catch (py11::error_already_set & e)
    {
        err = 1;
        LOG_INFO("get_table_parameters error_already_set '%s'", e.what());

    }

    if (err == 1)
    {
        func_registered_get_table_describe_parameters = 0;
        register_table_parameter();
        try
        {
            return py11::globals()["get_table_describe_parameters"]();
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("get_table_describe_parameters error_already_set '%s'", e.what());
            return py11::cast<py11::none>(Py_None);

        }
    }
    return py11::cast<py11::none>(Py_None);
}
/*  wrapped python_describe_parameters function consuming ibm_db.IBM_DBStatement */
PYOBJ_PTR python_describe_parameters(
    PYOBJ_PTR self, 
    PYOBJ_PTR args)
{
    ERROR_VAR
    PYOBJ_PTR py_stmt_res;
    stmt_handle *stmt_res;
    int ret = 0;

    if (!PyArg_ParseTuple(args, "O", &py_stmt_res))
    {
        const char* current_func_doc = __doc__(python_describe_parameters);
        PyErr_Format(PyExc_ValueError,
                     "__doc__ '%s'\nparameters count must be 1 ibm_db.IBM_DBStatement",
                     current_func_doc);
        return NULL;
    }

    if (NIL_P(py_stmt_res))
    {
        PyErr_Format(PyExc_TypeError,
                     "Supplied conn object Parameter is NULL  it should be ibm_db.IBM_DBStatement");
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

    LOG_INFO("calling display_parameters 'generic'");;
    ret = display_parameters(stmt_res->hdbc,
                             stmt_res->hstmt,
                             "generic",
                             ERROR_VAR_PARAM_1);
    SPCLIENT_ERROR_MESSAGE

    Py_RETURN_NONE;

}

/*  wrapped python_describe_parameters function consuming vctypes.void_p */
PYOBJ_PTR python_describe_parameters_by_cli(
    PYOBJ_PTR self, 
    PYOBJ_PTR args)
{
    ERROR_VAR
    PYOBJ_PTR py_stmt;
    PYOBJ_PTR py_hdbc;
    SQLHANDLE *hstmt = nullptr; /* statement handle */
    SQLHANDLE *hdbc = nullptr;  /* connection handle */

    int ret = 0;

    if (!PyArg_ParseTuple(args, "OO", &py_hdbc, &py_stmt))
    {
        const char* current_func_doc = __doc__(python_describe_parameters_by_cli);
        PyErr_Format(PyExc_ValueError,
                     "__doc__ '%s'\n parameters count must be 2",
                     current_func_doc);
        return NULL;
    }

    hdbc  = (SQLHANDLE *)PyLong_AsVoidPtr(py_hdbc);
    hstmt = (SQLHANDLE *)PyLong_AsVoidPtr(py_stmt);
    LOG_INFO("calling display_parameters 'generic'");
    ret = display_parameters(*hdbc, *hstmt, "generic", ERROR_VAR_PARAM_1);
    SPCLIENT_ERROR_MESSAGE
    Py_RETURN_NONE;

}

static int my_dict_nulls_init = 0;
MAP_INT_STRING& map_nulls_str()
{

    static MAP_INT_STRING nulls;
    if (my_dict_nulls_init == 0)
    {
        my_dict_nulls_init = 1;
        nulls[SQL_NO_NULLS] = "SQL_NO_NULLS";
        nulls[SQL_NULLABLE] = "SQL_NULLABLE";
        nulls[SQL_NULLABLE_UNKNOWN] = "SQL_NULLABLE_UNKNOWN";
    }
    return nulls;
}

static int my_dict_userdefinedtypecode_init = 0;
MAP_INT_STRING& map_sql_value_userdefinedtypecode_str()
{
 
    static MAP_INT_STRING map_sql_value_userdefinedtypecode;
    if (my_dict_userdefinedtypecode_init == 0)
    {
        my_dict_userdefinedtypecode_init = 1;
        map_sql_value_userdefinedtypecode[-1] = "";
        map_sql_value_userdefinedtypecode[SQL_TYPE_BASE] = "SQL_TYPE_BASE";
        map_sql_value_userdefinedtypecode[SQL_TYPE_DISTINCT] = "SQL_TYPE_DISTINCT";
        map_sql_value_userdefinedtypecode[SQL_TYPE_STRUCTURED] = "SQL_TYPE_STRUCTURED";
        map_sql_value_userdefinedtypecode[SQL_TYPE_REFERENCE] = "SQL_TYPE_REFERENCE";
        map_sql_value_userdefinedtypecode[SQL_TYPE_DATE] = "SQL_TYPE_DATE";
        map_sql_value_userdefinedtypecode[SQL_TYPE_TIME] = "SQL_TYPE_TIME";
        map_sql_value_userdefinedtypecode[SQL_TYPE_TIMESTAMP] = "SQL_TYPE_TIMESTAMP";
    }

    return map_sql_value_userdefinedtypecode;

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

        str_sql_dict[SQL_UNICODE            ]= "SQL_UNICODE";
        str_sql_dict[SQL_UNICODE_VARCHAR    ]=  "SQL_UNICODE_VARCHAR";
        str_sql_dict[SQL_UNICODE_LONGVARCHAR]=  "SQL_UNICODE_LONGVARCHAR";
        str_sql_dict[SQL_UNICODE_CHAR       ]=  "SQL_UNICODE_CHAR";
        str_sql_dict[SQL_C_CHAR             ]=  "SQL_C_CHAR";
        str_sql_dict[SQL_C_LONG             ]=  "SQL_C_LONG";
        str_sql_dict[SQL_C_SHORT            ]=  "SQL_C_SHORT";
        str_sql_dict[SQL_C_FLOAT            ]=  "SQL_C_FLOAT";
        str_sql_dict[SQL_C_DOUBLE           ]=  "SQL_C_DOUBLE";
        str_sql_dict[SQL_C_NUMERIC          ]=  "SQL_C_NUMERIC";
        str_sql_dict[SQL_C_DEFAULT          ]=  "SQL_C_DEFAULT";

        str_sql_dict[SQL_C_DATE             ]=  "SQL_C_DATE";
        str_sql_dict[SQL_C_TIME             ]=  "SQL_C_TIME";
        str_sql_dict[SQL_C_TIMESTAMP        ]= "SQL_C_TIMESTAMP";
        str_sql_dict[SQL_C_TYPE_DATE        ]= "SQL_C_TYPE_DATE";
        str_sql_dict[SQL_C_TYPE_TIME        ]= "SQL_C_TYPE_TIME";
        str_sql_dict[SQL_C_TYPE_TIMESTAMP   ]= "SQL_C_TYPE_TIMESTAMP";
        str_sql_dict[SQL_C_INTERVAL_YEAR    ]= "SQL_C_INTERVAL_YEAR";
        str_sql_dict[SQL_C_INTERVAL_MONTH   ]= "SQL_C_INTERVAL_MONTH";
        str_sql_dict[SQL_C_INTERVAL_DAY     ]= "SQL_C_INTERVAL_DAY";
        str_sql_dict[SQL_C_INTERVAL_HOUR    ]= "SQL_C_INTERVAL_HOUR";
        str_sql_dict[SQL_C_INTERVAL_MINUTE  ]= "SQL_C_INTERVAL_MINUTE";
        str_sql_dict[SQL_C_INTERVAL_SECOND  ]= "SQL_C_INTERVAL_SECOND";
        str_sql_dict[SQL_C_INTERVAL_YEAR_TO_MONTH]=    "SQL_C_INTERVAL_YEAR_TO_MONTH";
        str_sql_dict[SQL_C_INTERVAL_DAY_TO_HOUR  ]=    "SQL_C_INTERVAL_DAY_TO_HOUR";
        str_sql_dict[SQL_C_INTERVAL_DAY_TO_MINUTE]=    "SQL_C_INTERVAL_DAY_TO_MINUTE";
        str_sql_dict[SQL_C_INTERVAL_DAY_TO_SECOND]=    "SQL_C_INTERVAL_DAY_TO_SECOND";
        str_sql_dict[SQL_C_INTERVAL_HOUR_TO_MINUTE]=   "SQL_C_INTERVAL_HOUR_TO_MINUTE";
        str_sql_dict[SQL_C_INTERVAL_HOUR_TO_SECOND]=   "SQL_C_INTERVAL_HOUR_TO_SECOND";
        str_sql_dict[SQL_C_INTERVAL_MINUTE_TO_SECOND]= "SQL_C_INTERVAL_MINUTE_TO_SECOND";
        str_sql_dict[SQL_C_BINARY]  = "SQL_C_BINARY";
        str_sql_dict[SQL_C_BIT]     = "SQL_C_BIT";
        str_sql_dict[SQL_C_SBIGINT] = "SQL_C_SBIGINT";
        str_sql_dict[SQL_C_UBIGINT] = "SQL_C_UBIGINT";
        str_sql_dict[SQL_C_TINYINT] = "SQL_C_TINYINT";
        str_sql_dict[SQL_C_SLONG]   = "SQL_C_SLONG";
        str_sql_dict[SQL_C_SSHORT]  = "SQL_C_SSHORT";
        str_sql_dict[SQL_C_STINYINT]= "SQL_C_STINYINT";
        str_sql_dict[SQL_C_ULONG]   = "SQL_C_ULONG";
        str_sql_dict[SQL_C_USHORT]  = "SQL_C_USHORT";
        str_sql_dict[SQL_C_UTINYINT]= "SQL_C_UTINYINT";
        str_sql_dict[SQL_C_GUID]    = "SQL_C_GUID";

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
            {SQL_UNICODE            , "SQL_UNICODE"},
            {SQL_UNICODE_VARCHAR    , "SQL_UNICODE_VARCHAR"},
            {SQL_UNICODE_LONGVARCHAR, "SQL_UNICODE_LONGVARCHAR"},
            {SQL_UNICODE_CHAR       , "SQL_UNICODE_CHAR"},
            {SQL_C_CHAR             , "SQL_C_CHAR"},
            {SQL_C_LONG             , "SQL_C_LONG"},
            {SQL_C_SHORT            , "SQL_C_SHORT"},
            {SQL_C_FLOAT            , "SQL_C_FLOAT"},
            {SQL_C_DOUBLE           , "SQL_C_DOUBLE"},
            {SQL_C_NUMERIC          , "SQL_C_NUMERIC"},
            {SQL_C_DEFAULT          , "SQL_C_DEFAULT"},

            {SQL_C_DATE             ,         "SQL_C_DATE"},
            {SQL_C_TIME             ,         "SQL_C_TIME"},
            {SQL_C_TIMESTAMP        ,         "SQL_C_TIMESTAMP"},
            {SQL_C_TYPE_DATE        ,         "SQL_C_TYPE_DATE"},
            {SQL_C_TYPE_TIME        ,         "SQL_C_TYPE_TIME"},
            {SQL_C_TYPE_TIMESTAMP   ,         "SQL_C_TYPE_TIMESTAMP"},
            {SQL_C_INTERVAL_YEAR    ,         "SQL_C_INTERVAL_YEAR"},
            {SQL_C_INTERVAL_MONTH   ,         "SQL_C_INTERVAL_MONTH"},
            {SQL_C_INTERVAL_DAY     ,         "SQL_C_INTERVAL_DAY"},
            {SQL_C_INTERVAL_HOUR    ,         "SQL_C_INTERVAL_HOUR"},
            {SQL_C_INTERVAL_MINUTE  ,         "SQL_C_INTERVAL_MINUTE"},
            {SQL_C_INTERVAL_SECOND  ,         "SQL_C_INTERVAL_SECOND"},
            {SQL_C_INTERVAL_YEAR_TO_MONTH,    "SQL_C_INTERVAL_YEAR_TO_MONTH"},
            {SQL_C_INTERVAL_DAY_TO_HOUR  ,    "SQL_C_INTERVAL_DAY_TO_HOUR"},
            {SQL_C_INTERVAL_DAY_TO_MINUTE,    "SQL_C_INTERVAL_DAY_TO_MINUTE"},
            {SQL_C_INTERVAL_DAY_TO_SECOND,    "SQL_C_INTERVAL_DAY_TO_SECOND"},
            {SQL_C_INTERVAL_HOUR_TO_MINUTE,   "SQL_C_INTERVAL_HOUR_TO_MINUTE"},
            {SQL_C_INTERVAL_HOUR_TO_SECOND,   "SQL_C_INTERVAL_HOUR_TO_SECOND"},
            {SQL_C_INTERVAL_MINUTE_TO_SECOND, "SQL_C_INTERVAL_MINUTE_TO_SECOND"},
            {SQL_C_BINARY,          "SQL_C_BINARY"},
            {SQL_C_BIT,             "SQL_C_BIT"},
            {SQL_C_SBIGINT,         "SQL_C_SBIGINT"},
            {SQL_C_UBIGINT,         "SQL_C_UBIGINT"},
            {SQL_C_TINYINT,         "SQL_C_TINYINT"},
            {SQL_C_SLONG,           "SQL_C_SLONG"},
            {SQL_C_SSHORT,          "SQL_C_SSHORT"},
            {SQL_C_STINYINT,        "SQL_C_STINYINT"},
            {SQL_C_ULONG,           "SQL_C_ULONG"},
            {SQL_C_USHORT,          "SQL_C_USHORT"},
            {SQL_C_UTINYINT,        "SQL_C_UTINYINT"},
            {SQL_C_GUID,            "SQL_C_GUID"},

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
        SQLHDBC       hdbc,
        SQLHSTMT      hstmt,
        const char* table_name,
        MAP_COLNO_COLUMN_INFO   &map_colno_sql_type,
        bool display,
        ERROR_VAR_PARAM_DEF)
{
    int rc = 0;
    int rc_SQLColAttribute = 0;
    py11::object  py11_table;
    SQLRETURN     cliRC = SQL_SUCCESS;
    SQLSMALLINT   NumParams;
    SQLSMALLINT   pfSqlType;
    SQLULEN       pcbColDef;
    SQLSMALLINT   pibScale;
    SQLSMALLINT   pfNullable;
    SQLSMALLINT   descUserDefinedTypeCode;
    SQLLEN        APDdescCardinality, IPDdescCardinality, IRDDescLength;
    string        str_sql_type;
    char descparamLocalTypeName[255] = {};
    char descrecordLocalTypeName[255] = {};
    char descrecordFieldTypeName[255] = {};
    char descparamFieldTypeName[255] = {};
    char descrecordFieldLabel[255] = {};
    char buffer[500];
    std::ostringstream ss;

    Py_BEGIN_ALLOW_THREADS;
    cliRC = SQLNumParams(hstmt, &NumParams);
    Py_END_ALLOW_THREADS;
    bool displgeneral_log = false;
    const char* env_general_log = std::getenv("SPCLIENT_PYTHON_LOG_GENERAL");
    if (env_general_log != nullptr)
    {
        if (string(env_general_log) == "1")
            displgeneral_log = true;
    }

    if (NumParams == 0)
    {
        LOG_INFO ("NumParams = 0");
        return 0;
    }

    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    if (display)
        py11_table = get_table_parameters();

    SQLHDESC hAPD = SQL_NULL_HDESC;
    cliRC = SQLGetStmtAttr(hstmt, SQL_ATTR_APP_PARAM_DESC, &hAPD, 0, NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC)

    SQLHDESC hIPD = SQL_NULL_HDESC;
    cliRC = SQLGetStmtAttr(hstmt, SQL_ATTR_IMP_PARAM_DESC, &hIPD, 0, NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    SQLHDESC hIRD = SQL_NULL_HDESC;
    cliRC = SQLGetStmtAttr(hstmt, SQL_ATTR_IMP_ROW_DESC, &hIRD, 0, NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    std::map<int, COLUMN_INFO>::iterator it = map_colno_sql_type.end();
    ss << table_name << "\n";
    int added;
    for (int col = 1; col <= NumParams; col++)
    {
        added = 0;
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
        rc = check_error(hdbc, hstmt, rc,
                __LINE__,
                __FUNCTION__,
                ERROR_VAR_PARAM);

        Py_BEGIN_ALLOW_THREADS
        descUserDefinedTypeCode = -1;
        rc_SQLColAttribute = SQLColAttribute(hstmt,
            (SQLSMALLINT)(col),
            SQL_DESC_USER_DEFINED_TYPE_CODE,
            NULL,
            0,
            NULL,
            &descUserDefinedTypeCode);
        //if (rc_SQLColAttribute != 0)
        //    printf("SQL_DESC_USER_DEFINED_TYPE_CODE done col %d rc %d\n", col, rc_SQLColAttribute);
        Py_END_ALLOW_THREADS
            // This sometimes error as, The statement did not return a result set. SQLSTATE=07005
            //rc = check_error(hdbc, hstmt, rc_SQLColAttribute,
            //        __LINE__,
            //        __FUNCTION__,
            //        ERROR_VAR_PARAM);

        int rc_descrecordFieldTypeName = -1;
        Py_BEGIN_ALLOW_THREADS
        descrecordFieldTypeName[0] = 0;
        rc_descrecordFieldTypeName = SQLGetDescField(hIRD,
            (SQLSMALLINT)col,
            SQL_DESC_TYPE_NAME, /* record field */
            descrecordFieldTypeName, /* result */
            sizeof(descrecordFieldTypeName),
            NULL);
        Py_END_ALLOW_THREADS

        descparamFieldTypeName[0] = 0;
        int rc_descparamFieldTypeName = -1;
        Py_BEGIN_ALLOW_THREADS
        rc_descparamFieldTypeName = SQLGetDescField(hIPD,
            (SQLSMALLINT)col,
            SQL_DESC_TYPE_NAME, /* param field */
            descparamFieldTypeName, /* result */
            sizeof(descparamFieldTypeName),
            NULL);
        Py_END_ALLOW_THREADS


        descrecordLocalTypeName[0] = 0;
        int rc_descrecordLocalTypeName = -1;
        Py_BEGIN_ALLOW_THREADS
        rc_descrecordLocalTypeName = SQLGetDescField(hIRD,
            (SQLSMALLINT)col,
            SQL_DESC_LOCAL_TYPE_NAME, /* record field */
            descrecordLocalTypeName, /* result */
            sizeof(descrecordLocalTypeName),
            NULL);
        Py_END_ALLOW_THREADS
        if ((rc_descrecordLocalTypeName == 0) && (descrecordLocalTypeName[0] != 0))
        {
            snprintf(buffer, 500, "descrecordLocalTypeName '%-15s' ",
                descrecordLocalTypeName
            );
            ss << buffer;
            added = 1;
        }


        descparamLocalTypeName[0] = 0;
        int rc_descparamLocalTypeName = -1;
        rc_descparamLocalTypeName = SQLGetDescField(hIPD,
            (SQLSMALLINT)col,
            SQL_DESC_LOCAL_TYPE_NAME, /* param field */
            descparamLocalTypeName, /* result */
            sizeof(descparamLocalTypeName),
            NULL);
        if ((rc_descparamLocalTypeName == 0) && (descparamLocalTypeName[0] != 0))
        {
            snprintf(buffer, 500, "descparamLocalTypeName '%-15s' ",
                descparamLocalTypeName
            );
            ss << buffer;
            added = 1;
        }


        descrecordFieldLabel[0] = 0;
        int rc_descrecordFieldLabel = -1;
        rc_descrecordFieldLabel = SQLGetDescField(hIRD,
            (SQLSMALLINT)col,
            SQL_DESC_LABEL, /* record field */
            descrecordFieldLabel, /* result */
            sizeof(descrecordFieldLabel),
            NULL);

        APDdescCardinality = -1;
        int rc_APDdescCardinality = -1;
        rc_APDdescCardinality = SQLGetDescField(hAPD,
            col,
            SQL_DESC_CARDINALITY,
            &APDdescCardinality,
            0,
            0);

        IRDDescLength = -1;
        int rc_IRDDescLength = -1;
        rc_IRDDescLength = SQLGetDescField(hIRD,
            col,
            SQL_DESC_LENGTH,
            &IRDDescLength,
            0,
            0);

        int rc_IPDdescCardinality = -1;
        IPDdescCardinality = -1;
        //Py_BEGIN_ALLOW_THREADS
        /*
        // doesnt work on DB2...crashed the app
        IPDdescCardinality = -1;
        int rc_IPDdescCardinality = -1;
        printf("IPDdescCardinality col %d\n", col);
        rc_IPDdescCardinality = SQLGetDescField(hIPD,
            col,
            SQL_DESC_CARDINALITY,
            &IPDdescCardinality,
            0,
            0);
        printf("IPDdescCardinality done col %d\n", col);
        */
        rc = check_error(hdbc, hstmt, rc,
            __LINE__,
            __FUNCTION__,
            ERROR_VAR_PARAM);

        SQLSMALLINT IPDType = -1;
        int rc_IPDType = 0;
        Py_BEGIN_ALLOW_THREADS
        rc_IPDType = SQLGetDescField(hIPD,
            col,
            SQL_DESC_TYPE,
            &IPDType,
            0,
            0);
        Py_END_ALLOW_THREADS

        SQLSMALLINT IRDType = -1;
        int rc_IRDType = 0;

        Py_BEGIN_ALLOW_THREADS
        rc_IRDType = SQLGetDescField(hIRD,
            col,
            SQL_DESC_TYPE,
            &IRDType,
            0,
            0);
        Py_END_ALLOW_THREADS
        rc = check_error(hdbc, hstmt, rc,
            __LINE__,
            __FUNCTION__,
            ERROR_VAR_PARAM);

        if (rc_IPDdescCardinality == 0)
        {
            string str_format = "IPD descCardinality  {:>13,} ";
            py11::str py_strformat(str_format.c_str());
            py11::str py_py_strformated = py_strformat.format(py11::int_(IPDdescCardinality));
            ss << (string)py_py_strformated;
            added = 1;

        }

        if (rc_APDdescCardinality == 0)
        {
            string str_format = "APD descCardinality  {:>13,} ";
            py11::str py_strformat(str_format.c_str());
            py11::str py_py_strformated = py_strformat.format(py11::int_(APDdescCardinality));
            ss << (string)py_py_strformated;
            added = 1;
        }

        if (rc_IPDType == 0)
        {
            snprintf(buffer, 500, "IPDType % 3d '%-15s' ",
                IPDType,
                map_sql_value_sql_str()[IPDType].c_str()
            );
            ss << buffer;
            added = 1;
        }

        if (rc_IRDType == 0)
        {
            snprintf(buffer, 500, "IRDType % 3d '%-15s' ",
                IRDType,
                map_sql_value_sql_str()[IRDType].c_str()
            );
            added = 1;
            ss << buffer;
        }

        if (rc_IRDDescLength == 0)
        {
            snprintf(buffer, 500, "IRDDescLength % 3d ",
                rc_IRDDescLength
            );
            ss << buffer;
            added = 1;
        }

        if (rc_SQLColAttribute == 0)
        {
            snprintf(buffer, 500, "descUserDefinedTypeCode '%s' ",
                map_sql_value_userdefinedtypecode_str()[descUserDefinedTypeCode].c_str()
                );
            ss << buffer;
            added = 1;

        }

        if (rc_descparamFieldTypeName == 0)
        {
            snprintf(buffer, 500, "descparamFieldTypeName '%-15s' ",
                descparamFieldTypeName
                );
            ss << buffer;
            added = 1;
        }

        if (rc_descrecordFieldTypeName == 0)
        {
            snprintf(buffer, 500, "descrecordFieldTypeName '%-15s' ",
                descrecordFieldTypeName);
            ss << buffer;
            added = 1;
        }

        if (rc_descrecordFieldLabel == 0)
        {
            snprintf(buffer, 500, "descrecordFieldLabel '%-15s'  rc %d ",
                descrecordFieldLabel,
                rc);
            ss << buffer;
            added = 1;
        }

        if (added == 1)
            ss << "\n";

        
        COLUMN_INFO col_info;
        col_info.cbColDef = pcbColDef;
        col_info.fNullable = pfNullable;
        col_info.fSqlType = pfSqlType;
        col_info.ibScale = pibScale;
        std::pair<int, COLUMN_INFO> mypair(col, col_info);
        it = map_colno_sql_type.insert(it, mypair);
        //map_colno_sql_type[col] = col_info; // same as above code
        str_sql_type = map_sql_value_sql_str()[pfSqlType];

        if (rc == SQL_ERROR)
        {
            if (displgeneral_log)
                LOG_INFO("\nError %d message '%s'\n, sqlstate '%s', sqlcode %d", rc, message, sqlstate, *sqlcode);
            return rc;
        }


        if (((rc == SQL_SUCCESS) || rc == (SQL_SUCCESS_WITH_INFO)) && display)
        {
            PyObject * obj_list = Py_BuildValue("[iisiOss]",
                col,
                pfSqlType,
                str_sql_type.c_str(),
                pibScale,
                "{:,}"_s.format(pcbColDef).ptr(),
                map_nulls_str()[pfNullable].c_str(),
                map_sql_value_userdefinedtypecode_str()[descUserDefinedTypeCode].c_str());

            py11::list py11_my_row = py11::reinterpret_borrow<py11::list>(obj_list);
 
            if (py11_table.is_none() == false)
                py11::object none = py11_table.attr("add_row")(py11_my_row);
            else
                LOG_INFO("py11_table.is_none");
        }
    }

    if ((display) && (py11_table.is_none() == false))
    {
        LOG_INFO("\n%s", ss.str().c_str());
        py11::str ret = py11_table.attr("draw")();
        LOG_INFO("py11 parameters\n'%s'\n%s\n", table_name, ((string)ret).c_str());
    }
    return 0;
}

int display_parameters(
    SQLHDBC       hdbc,
    SQLHSTMT      hstmt,
    const char* table_name,
    ERROR_VAR_PARAM_DEF)
{
    MAP_COLNO_COLUMN_INFO   map_colno_sql_type_dummy;

    return  display_parameters_map(
        hdbc,
        hstmt,
        table_name,
        map_colno_sql_type_dummy,
        true,
        ERROR_VAR_PARAM);
}
