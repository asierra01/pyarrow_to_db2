
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

void do_switch(
    MY_DICT& d, 
    SQLHANDLE hstmt,
    bool &column_boolean,
    int col,
    MAP_COLNO_COLUMN_INFO& map_column_info)
{
    SQLRETURN cliRC;
    SQLSMALLINT fSqlType = map_column_info[col].fSqlType;
    SQLULEN cbColDef = map_column_info[col].cbColDef;
    SQLSMALLINT ibScale = map_column_info[col].ibScale;

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
                fSqlType,//SQL_BOOLEAN,
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
                fSqlType,//SQL_SMALLINT,
                cbColDef,
                ibScale,
                d.get_data(),
                sizeof(int8_t),
                NULL);
            Py_END_ALLOW_THREADS;
        }
        break;

    case arrow::Type::DECIMAL: //  I am passing the decimal as the string 
                               // representation of the decimal 44555.6789999999
                               // this is slow but it works
                               // thats the reason for SQL_C_CHAR
        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLBindParameter(hstmt,
            col,
            SQL_PARAM_INPUT,
            SQL_C_CHAR,
            fSqlType,//SQL_DECIMAL
            cbColDef,
            ibScale,
            d.m_v_8_string.data(),
            MAX_DIGITS,
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
            fSqlType, //SQL_SMALLINT, 
            cbColDef,
            ibScale,
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
            fSqlType,//SQL_SMALLINT,
            cbColDef,
            ibScale,
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
            fSqlType,//SQL_SMALLINT,
            cbColDef,
            ibScale,
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
            fSqlType,////SQL_SMALLINT,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_TYPE_TIME,
            cbColDef,
            ibScale,
            d.get_data(),
            sizeof(TIME_STRUCT),
            NULL);
        Py_END_ALLOW_THREADS;
        break;
    case arrow::Type::TIMESTAMP:
    {
        Py_BEGIN_ALLOW_THREADS;
        if (fSqlType == SQL_TYPE_TIMESTAMP_WITH_TIMEZONE)
            cliRC = SQLBindParameter(
                hstmt,
                col,
                SQL_PARAM_INPUT,
                SQL_C_TIMESTAMP_EXT_TZ,
                fSqlType, //SQL_TYPE_TIMESTAMP_WITH_TIMEZONE,
                cbColDef,
                ibScale,

                //0,
                //0, // 6 digits for the fraction  SQLUINTEGER    fraction;     /* fraction of a second */
                   // in my case I am setting the fraction to 0....but I may assign a value in the future
                d.get_data(),
                sizeof(TIMESTAMP_STRUCT_EXT_TZ),
                NULL);
        if (fSqlType == SQL_TYPE_TIMESTAMP)
        {
            cliRC = SQLBindParameter(
                hstmt,
                col,
                SQL_PARAM_INPUT,
                SQL_C_TIMESTAMP,
                fSqlType, //SQL_TYPE_TIMESTAMP,
                cbColDef,
                ibScale,

                //0,
                //0, // 6 digits for the fraction  SQLUINTEGER    fraction;     /* fraction of a second */
                // in my case I am setting the fraction to 0....but I may assign a value in the future
                d.get_data(),
                sizeof(SQL_TIMESTAMP_STRUCT),
                NULL);
        }
        Py_END_ALLOW_THREADS;
        break;


    }
    case arrow::Type::TIME64:
    case arrow::Type::DATE64:
        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLBindParameter(
            hstmt,
            col,
            SQL_PARAM_INPUT,
            SQL_C_TYPE_TIMESTAMP,
            fSqlType, //SQL_TYPE_TIMESTAMP,
            cbColDef,
            ibScale,

            //0,
            //0, // 6 digits for the fraction  SQLUINTEGER    fraction;     /* fraction of a second */
               // in my case I am setting the fraction to 0....but I may assign a value in the future
            d.get_data(),
            sizeof(SQL_TIMESTAMP_STRUCT),
            NULL);
        Py_END_ALLOW_THREADS;
        break;

    case arrow::Type::DATE32:
        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLBindParameter(hstmt,
            col,
            SQL_PARAM_INPUT,
            SQL_C_TYPE_DATE,
            fSqlType, //SQL_TYPE_DATE,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_BIGINT,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_BIGINT,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_INTEGER,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_INTEGER,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_DOUBLE,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_REAL,
            cbColDef,
            ibScale,
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
            fSqlType, //SQL_REAL,
            cbColDef,
            ibScale,
            d.get_data(),
            sizeof(SQLREAL),
            NULL);
        Py_END_ALLOW_THREADS;
        break;

    case arrow::Type::FIXED_SIZE_BINARY:
    case arrow::Type::BINARY:
        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLBindParameter(
            hstmt,
            col,
            SQL_PARAM_INPUT,
            SQL_C_BINARY,
            fSqlType, //SQL_VARBINARY,
            cbColDef,
            ibScale,
            d.m_v_8_string.data(),
            d.max_size_string,
            d.m_str_lens.data()
        );
        Py_END_ALLOW_THREADS;
        break;

    case arrow::Type::STRING:
        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLBindParameter(
            hstmt,
            col,
            SQL_PARAM_INPUT,
            SQL_C_CHAR,
            fSqlType, //SQL_VARCHAR,
            cbColDef,
            ibScale,
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

}

int  bind_parameters(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    int64_t num_rows,
    MAP_FIELDNAME_DICT &map_field_memory_vectors,
    MAP_COLNO_COLUMN_INFO &map_column_info,
    bool &column_boolean,
    ERROR_VAR_PARAM_DEF)
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

    int col = 1;
    std::vector<string> column_names;
    size_t max_size = 0;
    if (log_bind)
    {
        for (auto const& item : map_field_memory_vectors)
        {
            if (item.first.length() > max_size)
                max_size = item.first.length();
        }
        for (auto const& item : map_field_memory_vectors)
        {
            string column_name = "\""+item.first+ "\"";
            column_name.append(max_size - item.first.length(), ' ');
            column_names.push_back(column_name);

        }
    }
    int cont = 0;
    std::ostringstream ss;
    char buffer[300] = {};
    SQLSMALLINT fSqlType;
    SQLUINTEGER cbColDef;
    for (auto const & item : map_field_memory_vectors)
    {
        fSqlType = map_column_info[col].fSqlType;
        cbColDef = map_column_info[col].cbColDef;
        if (log_bind)
        {
            snprintf(buffer, 300, "%2d %-20s cbColDef %6d %s %-13s\n",
                col,
                map_sql_value_sql_str()[fSqlType].c_str(),
                cbColDef,
                column_names[cont].c_str(), //same as item.first.c_str() but padded with blanks
                my_dict_arrow()[item.second->vector_type].c_str());
            ss << buffer;
        }
        cont++;
        MY_DICT &d = *item.second;
        do_switch(
            d,
            hstmt,
            column_boolean,
            col,
            map_column_info );



        col++;
        rc = check_error(
            hdbc,
            hstmt,
            cliRC,
            __LINE__,
            __FUNCTION__,
            ERROR_VAR_PARAM);

        if (cliRC != SQL_SUCCESS)
        {
            if (log_bind)
                LOG_INFO("\n%s\n", ss.str().c_str());

            return cliRC;
        }
    }
    if (log_bind)
        LOG_INFO("\n%s\n", ss.str().c_str());

    return 0;
}

