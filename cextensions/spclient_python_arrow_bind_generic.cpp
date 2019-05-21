
#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"

/*
 * SQL_C_BIGINT          SQLBIGINT        long long int
   SQL_C_CHAR            SQLCHAR          Unsigned char
   SQL_C_BIT             SQLCHAR          Unsigned char or char (Value 1 or 0)
   SQL_C_TINYINT         SQLSCHAR         Signed char (Range -128 to 127)
   SQL_C_SHORT           SQLSMALLINT      Short int
   SQL_C_LONG            SQLINTEGER       Long int (31-bit) or int (64-bit)1
   SQL_C_DOUBLE          SQLDOUBLE        Double
   SQL_C_FLOAT           SQLREAL          Float
   SQL_C_DECIMAL64       SQLDECIMAL64     See Table 3
   SQL_C_DECIMAL128      SQLDECIMAL128    See Table 3
   SQL_C_TYPE_DATE       DATE_STRUCT      See Table 3
   SQL_C_TYPE_TIME       TIME_STRUCT      See Table 3
   SQL_C_TYPE_TIMESTAMP  TIMESTAMP_STRUCT See Table 3
   SQL_C_CLOB_LOCATOR    SQLINTEGER       Long int (31-bit) or int (64-bit)1
   SQL_C_BINARY          SQLCHAR          Unsigned char
   SQL_C_BINARYXML       SQLCHAR          Unsigned char
   SQL_C_BLOB_LOCATOR    SQLINTEGER       Long int (31-bit) or int (64-bit)1
   SQL_C_DBCHAR          SQLDBCHAR        Unsigned short
   SQL_C_DBCLOB_LOCATOR  SQLINTEGER       Long int (31-bit) or int (64-bit)1
   SQL_C_WCHAR           SQLWCHAR         wchar_t (31-bit) or unsigned short (64-bit)
 *
 */
//SQL_DAY_SECOND_STRUCT

int  bind_parameters_generic(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    int64_t num_rows,
    MAP_FIELDNAME_DICT &map_field_memory_vectors,
    MAP_COLNO_COLUMN_INFO &map_column_info,
    bool &column_boolean)
{
    SQLRETURN cliRC = SQL_SUCCESS;
    int rc;
    bool log_bind = false;
    const char* env_log_bind = std::getenv("SPCLIENT_PYTHON_LOG_BIND_PARAMETERS");
    if (env_log_bind != nullptr)
    {
        if (string(env_log_bind) == "1")
            log_bind = true;
    }
    if (log_bind)
        LOG_INFO("start");

    //SQLULEN ulen_vector_size = num_rows;
    int col = 1;
    for (auto const & item : map_field_memory_vectors)
    {
        SQLSMALLINT pfSqlType = map_column_info[col].pfSqlType;
        if (log_bind)
            LOG_INFO("%2d %-20s %-20s %-13s",
                     col,
                     map_sql_value_sql_str()[pfSqlType].c_str(),
                     item.first.c_str(),
                     my_dict_arrow()[item.second->vector_type].c_str());
        MY_DICT &d = *item.second;
        switch (d.vector_type)
        {
            case arrow::Type::BOOL:
                if (column_boolean)// do the bind as boolean...only supported on db2 11.1.3?
                {
                    Py_BEGIN_ALLOW_THREADS;
                    cliRC = SQLBindParameter(
                        hstmt,
                        col,
                        SQL_PARAM_INPUT,
                        SQL_C_BIT,
                        pfSqlType,//SQL_BOOLEAN,
                        0,
                        0,
                        d.get_data(),
                        sizeof(int8_t),
                        NULL);
                    Py_END_ALLOW_THREADS;
                }
                else
                {
                    Py_BEGIN_ALLOW_THREADS;
                    cliRC = SQLBindParameter(hstmt,
                        col,
                        SQL_PARAM_INPUT,
                        SQL_C_SHORT,
                        pfSqlType,//SQL_SMALLINT,
                        map_column_info[col].pcbColDef,
                        map_column_info[col].pibScale, 
                        //0,
                        //0,
                        d.get_data(),
                        sizeof(int8_t),
                        NULL);
                    Py_END_ALLOW_THREADS;
                }
            break;
            case arrow::Type::DECIMAL:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_CHAR,
                    pfSqlType,//SQL_DECIMAL
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale,
                    d.m_v_8_string.data(),
                    MAX_DIGITS ,
                    d.m_str_lens.data());

                /* Modify the fields in the implicit application parameter descriptor */
                //SQLHDESC   hdesc = NULL;

                //cliRC = SQLGetStmtAttr(hstmt, SQL_ATTR_APP_PARAM_DESC, &hdesc, 0, NULL);
                //cliRC = SQLSetDescField(hdesc, col, SQL_DESC_TYPE, (SQLPOINTER)SQL_C_NUMERIC, 0);
                //cliRC = SQLSetDescField(hdesc, col, SQL_DESC_PRECISION, (SQLPOINTER)map_column_info[col].pcbColDef, 0);
                //cliRC = SQLSetDescField(hdesc, col, SQL_DESC_SCALE, (SQLPOINTER)map_column_info[col].pibScale, 0);
                //cliRC = SQLSetDescField(hdesc, col, SQL_DESC_DATA_PTR, (SQLPOINTER)d.get_data(), 0);
                //cliRC = SQLSetDescField(hdesc, col, SQL_DESC_COUNT, (SQLPOINTER)d.m_str_lens.size(), 0);


                Py_END_ALLOW_THREADS;
                break;

            case arrow::Type::INT16:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_SSHORT,
                    //SQL_SMALLINT, 
                    pfSqlType,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(int16_t),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::UINT16:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_USHORT,
                    pfSqlType,//SQL_SMALLINT,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(uint16_t),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::UINT8:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_UTINYINT,
                    pfSqlType,//SQL_SMALLINT,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(uint8_t),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;

            case arrow::Type::INT8:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_STINYINT,
                    pfSqlType,////SQL_SMALLINT,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(int8_t),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;

            case arrow::Type::TIME32:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_TYPE_TIME,
                    pfSqlType, //SQL_TYPE_TIME,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(TIME_STRUCT),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::TIME64:
            case arrow::Type::TIMESTAMP:
            case arrow::Type::DATE64:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(
                    hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_TYPE_TIMESTAMP,
                    pfSqlType, //SQL_TYPE_TIMESTAMP,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale,

                    //0,
                    //0, // 6 digits for the fraction  SQLUINTEGER    fraction;     /* fraction of a second */
                       // in my case I am setting the fraction to 0....but I may assign a value in the future
                    d.get_data(),
                    sizeof(SQL_TIMESTAMP_STRUCT),
                    0);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::DATE32:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_TYPE_DATE,
                    pfSqlType, //SQL_TYPE_DATE,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQL_DATE_STRUCT),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::INT64:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_SBIGINT,
                    pfSqlType, //SQL_BIGINT,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQLBIGINT),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;

            case arrow::Type::UINT64:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_UBIGINT,
                    pfSqlType, //SQL_BIGINT,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQLUBIGINT),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::INT32:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_SLONG,
                    pfSqlType, //SQL_INTEGER,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQLINTEGER),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::UINT32:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_ULONG,
                    pfSqlType, //SQL_INTEGER,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQLUINTEGER),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::DOUBLE:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_DOUBLE,
                    pfSqlType, //SQL_DOUBLE,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQLDOUBLE),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::HALF_FLOAT:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_FLOAT,
                    pfSqlType, //SQL_REAL,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQLREAL),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;

            case arrow::Type::FLOAT:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_FLOAT,
                    pfSqlType, //SQL_REAL,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.get_data(),
                    sizeof(SQLREAL),
                    NULL);
                Py_END_ALLOW_THREADS;
                break;
            case arrow::Type::STRING:
            case arrow::Type::FIXED_SIZE_BINARY:
            case arrow::Type::BINARY:
                Py_BEGIN_ALLOW_THREADS;
                cliRC = SQLBindParameter(
                    hstmt,
                    col,
                    SQL_PARAM_INPUT,
                    SQL_C_CHAR,
                    pfSqlType, //SQL_VARCHAR,
                    map_column_info[col].pcbColDef,
                    map_column_info[col].pibScale, 
                    //0,
                    //0,
                    d.m_v_8_string.data(),
                    d.max_size_string,
                    d.m_str_lens.data()
                );
                Py_END_ALLOW_THREADS;
                break;
            default:
            {
                printf("%d %s() error unknow type %d '%s'\n", 
                    __LINE__, 
                    __FUNCTION__,
                    d.vector_type,
                    my_dict_arrow()[d.vector_type].c_str());
            }
        }
        col++;
        rc = check_error(
            hdbc,
            hstmt,
            cliRC,
            __LINE__,
            __FUNCTION__);
        if (cliRC != SQL_SUCCESS)
            return cliRC;
    }
    return 0;
}

/*
int  bind_paraneters(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    size_t vector_size,
    MAP_FIELDNAME_DICT &map_field_memory_vectors)
{
    SQLRETURN cliRC = SQL_SUCCESS;
    int rc;
    SQLULEN ulen_vector_size = vector_size;
    //bind parameters for the load operations on table
//INSERT INTO "OPTIONS".LOAD_TEST_ONE_BIG_CSV
//("Type",
//"Bid",
//"Ask",
//"Root",
//"Open_Int",
//"Vol",
//"Date_Downloaded",
//"Underlying_Price")
//VALUES (?,?,?,?,?,?,?)
//    )

    cliRC = SQLBindParameter(hstmt,
        1,
        SQL_PARAM_INPUT,
        SQL_C_CHAR,
        SQL_VARCHAR,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Type"]->get_data(),
        sizeof(struct_data100),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    cliRC = SQLBindParameter(hstmt,
        2,
        SQL_PARAM_INPUT,
        SQL_C_DOUBLE,
        SQL_DOUBLE,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Bid"]->get_data(),
        sizeof(SQLDOUBLE),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    cliRC = SQLBindParameter(hstmt,
        3,
        SQL_PARAM_INPUT,
        SQL_C_DOUBLE,
        SQL_DOUBLE,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Ask"]->get_data(),
        sizeof(SQLDOUBLE),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    cliRC = SQLBindParameter(hstmt,
        4,
        SQL_PARAM_INPUT,
        SQL_C_CHAR,
        SQL_VARCHAR,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Root"]->get_data(),
        sizeof(struct_data100),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    cliRC = SQLBindParameter(hstmt,
        5,
        SQL_PARAM_INPUT,
        SQL_C_SBIGINT,
        SQL_BIGINT,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Open_Int"]->get_data(),
        sizeof(SQLBIGINT),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    cliRC = SQLBindParameter(hstmt,
        6,
        SQL_PARAM_INPUT,
        SQL_C_SBIGINT,
        SQL_BIGINT,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Open_Vol"]->get_data(),
        sizeof(SQLBIGINT),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    cliRC = SQLBindParameter(hstmt,
        7,
        SQL_PARAM_INPUT,
        SQL_C_TYPE_DATE,
        SQL_TYPE_DATE,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Date_Downloaded"]->get_data(),
        sizeof(SQL_DATE_STRUCT),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    cliRC = SQLBindParameter(hstmt,
        8,
        SQL_PARAM_INPUT,
        SQL_C_DOUBLE,
        SQL_DOUBLE,
        ulen_vector_size,
        0,
        map_field_memory_vectors["Underliying_Price"]->get_data(),
        sizeof(SQLDOUBLE),
        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);


    return 0;

}
*/
