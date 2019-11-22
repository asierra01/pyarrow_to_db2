

#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"



int create_table_in_backend_from_map_fieldname(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    MAP_FIELDNAME_DICT &map_field_memory_vectors,
    const char * tablespace_name,
    const char * schema_name,
    const char * table_name,
    bool        column_oriented,
    bool        drop_table,
    bool        create_table,
    bool        &column_organize_by,
    bool        &column_boolean,
    ERROR_VAR_PARAM_DEF)
{
    int rc;
    SQLRETURN cliRC = SQL_SUCCESS;
    std::string sql_create_table_str;

    sql_create_table_str = "CREATE TABLE\n \"";

    if (schema_name != nullptr)
    {
        if (strcmp(schema_name, "") != 0)
        {
            sql_create_table_str += schema_name;
            sql_create_table_str += "\".\"";
        }

    }
    sql_create_table_str.append(string(table_name));
    sql_create_table_str += "\" (\n";
    /* find if what DB2 we are using */
    char bufferDBMS_VER[50] = {};
    char bufferDBMS_NAME[50] = {};
    string DBMS_VER;
    string DBMS_NAME;
    bool log = false;
    bufferDBMS_VER[0] = '\0';
    //memset(bufferDBMS_VER, 0, sizeof(bufferDBMS_VER));

    const char* env_log_bind = std::getenv("SPCLIENT_PYTHON_LOG_CREATE_TABLE");
    if (env_log_bind != nullptr)
    {
        if (string(env_log_bind) == "1")
            log = true;
    }


    Py_BEGIN_ALLOW_THREADS;
    cliRC = SQLGetInfo(hdbc,
                       SQL_DBMS_VER,
                       (SQLPOINTER)bufferDBMS_VER,
                       sizeof(bufferDBMS_VER)-1,
                       NULL);
    Py_END_ALLOW_THREADS;
    DBC_HANDLE_CHECK(hdbc, cliRC);
    Py_BEGIN_ALLOW_THREADS;
    cliRC = SQLGetInfo(hdbc,
        SQL_DBMS_NAME,
        (SQLPOINTER)bufferDBMS_NAME,
        sizeof(bufferDBMS_NAME) - 1,
        NULL);
    Py_END_ALLOW_THREADS;
    DBC_HANDLE_CHECK(hdbc, cliRC);

    DBMS_VER = bufferDBMS_VER;
    DBMS_NAME = bufferDBMS_NAME;
    LOG_INFO("DBMS_VER  '%s'", DBMS_VER.c_str());
    LOG_INFO("DBMS_NAME '%s'", DBMS_NAME.c_str());

    if (DBMS_VER < "10.5")
        column_organize_by = false;
    else
        column_organize_by = true;

    if (DBMS_VER < "11.01.01")
        column_boolean = false;
    else
        column_boolean = true;

    int i = 0;
    size_t max_column_len = 0;
    for (auto const& item : map_field_memory_vectors)
    {
        if (item.first.length() > max_column_len)
            max_column_len = item.first.length();
    }
    ostringstream ss;
    char buffer[300] = {};
    for (auto const& item : map_field_memory_vectors)
    {
        i++;
        sql_create_table_str += "\"";
        sql_create_table_str += item.first.c_str();
        sql_create_table_str += "\"  ";
        sql_create_table_str += std::string(max_column_len - item.first.length(), ' ');
        if (log)
        {
            snprintf(buffer, 300, "%03d arrow type_string '%-35s' field_name '%s'\n",
                i,
                item.second->type_string.c_str(),
                item.second->field_name.c_str());
            ss << buffer;
        }
        switch (item.second->vector_type)
        {
            case  arrow::Type::DOUBLE: {
                sql_create_table_str += "DOUBLE"; //DOUBLE
                break;
            }
            case  arrow::Type::HALF_FLOAT:
            case  arrow::Type::FLOAT: {
                sql_create_table_str += "REAL";
                break;
            }
            case  arrow::Type::BOOL: {
                if (column_boolean)
                    sql_create_table_str += "BOOLEAN";
                else // bellow 11.1.1 no Boolean on column type
                    sql_create_table_str += "SMALLINT";
                break;
            }
            case  arrow::Type::UINT32:
            case  arrow::Type::INT32: {
                sql_create_table_str += "INTEGER";
                break;
            }
            case  arrow::Type::DECIMAL: {
                char buffer[30];
                sprintf(buffer, "NUMERIC (%d, %d)", 
                    item.second->ColDef, 
                    item.second->Scale);
                sql_create_table_str += string(buffer);
                //sql_create_table_str += "DECFLOAT(34)";
                break;
            }

            case arrow::Type::UINT16:
            case arrow::Type::INT16:
            case  arrow::Type::INT8:
            case  arrow::Type::UINT8: {
                sql_create_table_str += "SMALLINT";
                break;
            }

            case  arrow::Type::STRING: {
                char buffer[40] = {};
                if (item.second->max_size_string <= 255)
                    sprintf(buffer, "CHAR (%d)", item.second->max_size_string);
                else if ((item.second->max_size_string > 255) && (item.second->max_size_string < 32704))
                    sprintf(buffer, "VARCHAR (%d)", item.second->max_size_string);
                else
                    sprintf(buffer, "CLOB (%d)", item.second->max_size_string);
                sql_create_table_str += string(buffer);
                break;
            }
            case  arrow::Type::FIXED_SIZE_BINARY:
            case  arrow::Type::BINARY: {
                char buffer[40] = {};
                if (item.second->max_size_string <= 255)
                    sprintf(buffer, "BINARY (%d)", item.second->max_size_string);
                else if ((item.second->max_size_string > 255) && (item.second->max_size_string < 32704))
                    sprintf(buffer, "VARBINARY (%d)", item.second->max_size_string);
                else 
                    sprintf(buffer, "BLOB (%d)", item.second->max_size_string);
                sql_create_table_str += string(buffer);
                break;
            }
            case  arrow::Type::TIME64:
            case  arrow::Type::DATE64:
            case  arrow::Type::TIMESTAMP: {
                //if (item.second->type_string.find("tz") != string::npos) // this is only active on ZOS
                //{
                //    sql_create_table_str += "TIMESTAMP WITH TIMEZONE";
                //    item.second->fill_timestamp_with_tz();
                //}
                //else
                {
                    sql_create_table_str += "TIMESTAMP";
                    item.second->fill_timestamp();

                }
                break;
            }
            case  arrow::Type::DATE32: {
                sql_create_table_str += "DATE";
                item.second->fill_date32();
                break;

            }
            case  arrow::Type::TIME32: {
                sql_create_table_str += "TIME";
                item.second->fill_time();
                break;
            }
            case  arrow::Type::UINT64:
            case  arrow::Type::INT64: {
                sql_create_table_str += "BIGINT";
                break;
            default:
                LOG_INFO("dont know how to process arrow type %d %s",
                          item.second->vector_type,
                          my_dict_arrow()[item.second->vector_type].c_str());
                break;
            }
        }


        if (i != map_field_memory_vectors.size())
            sql_create_table_str += ",";

        sql_create_table_str += "\n";

    }
    sql_create_table_str += ")";
    if (log)
    {
        LOG_INFO("\n%s\n", ss.str().c_str());
        LOG_INFO("done the table definition");
    }
    if (tablespace_name != nullptr)
    {
        if (strcmp(tablespace_name, "") != 0)
            sql_create_table_str += "\nIN " + string(tablespace_name);
    }

    if (column_organize_by)
    {
        if (column_oriented)
            sql_create_table_str += "\nORGANIZE BY COLUMN\n";
        else
            sql_create_table_str += "\nORGANIZE BY ROW\n";
    }

    sql_create_table_str += ";\n";
    if (!create_table)
    {
        sql_create_table_str = ";\n";
    }

    string sql_drop_table = "";

    if (drop_table)
    {
        sql_drop_table = "\nDROP TABLE \"";

        if (schema_name != nullptr)
        {
            if (strcmp(schema_name, "") != 0)
            {
                sql_drop_table += schema_name;
                sql_drop_table += "\".\"";
            }
        }
        sql_drop_table += table_name;
        sql_drop_table += "\";\n\n";

    }
    string sql_select_schema = "";
    if (schema_name != nullptr)
    {
        if (strcmp(schema_name, "") != 0)
            sql_select_schema = "SET SCHEMA \"" + string(schema_name) + "\";\n";
    }

    sql_create_table_str = sql_select_schema + sql_drop_table + sql_create_table_str;
    if (log)
        LOG_INFO("Intended to run \n %s ", sql_create_table_str.c_str());
    rc = boost_tokenize_and_run_sql(hdbc, hstmt, sql_create_table_str, ERROR_VAR_PARAM);
    if (rc != 0)
        LOG_INFO("done boost_tokenize_and_run_sql rc=%d", rc);

    return rc;

}
