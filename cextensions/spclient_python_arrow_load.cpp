
#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"
#include <sqlcodes.h>
#include <chrono>
#include <thread>

#define TRUE 1
#define FALSE 0

using namespace py11::literals;

void log_mapfieldname_dict(
    MAP_FIELDNAME_DICT &map_field_memory_vectors)
{
    std::ostringstream stringStreamlog;
    //LOG_INFO("entering ");
    for (int i = 0; i < 2; i++)
    {
        stringStreamlog.str("");

        stringStreamlog << std::endl;
        size_t j = 0;
        size_t map_size = map_field_memory_vectors.size();
        for (auto const &item : map_field_memory_vectors)
        {
            //LOG_INFO("i %d > size %d j %d %s", i, item.second->size(), j, item.first.c_str());
            if (i > item.second->size())
            {
                break;
            }
            j++;
            stringStreamlog << "  \"" << item.first << "\": ";
            stringStreamlog << item.second->to_string(i).c_str() ;
            if (j != map_size)
                stringStreamlog << ", ";
        }
        stringStreamlog << std::endl;
        LOG_INFO("i %d %s",
            i, 
            stringStreamlog.str().c_str());

    }
    LOG_INFO("done");
    return;
}

void  create_generic_insert(
        MAP_FIELDNAME_DICT &map_field_memory_vectors,
        const char * schema_name,
        const char * table_name,
       std::string &insert_into)
{
    int i=0;
    size_t map_size = map_field_memory_vectors.size();
    insert_into = "INSERT INTO \"";
    string values = "\nVALUES (";
    if (schema_name != nullptr)
    {
        if (strcmp(schema_name, "") != 0)
        {
            insert_into += schema_name;
            insert_into += "\".\"";
        }
    }
    insert_into.append(string(table_name));
    insert_into += "\"\n(";
    for (auto const& item : map_field_memory_vectors)
    {
        i++;
        insert_into += "\"";
        insert_into +=  item.first;
        insert_into += "\"";
        values += "?";
        if (i != map_size)
        {
            insert_into += ",\n";
            values      += ",";
        }


    }
    insert_into += ")";
    values += ")";
    insert_into += values;

}

int run_dynamic_prepare(
        SQLHANDLE hdbc,
        SQLHANDLE hstmt,
        std::string &dynamic_insert)
{
    SQLRETURN cliRC = SQL_SUCCESS;
    int rc = 0;
    bool log = false;
    const char* env_log_create = std::getenv("SPCLIENT_PYTHON_LOG_CREATE_TABLE");
    if (env_log_create != nullptr)
    {
        if (string(env_log_create) == "1")
            log = true;
    }
    if (log)
        LOG_INFO("\n%s\n", dynamic_insert.c_str());

    cliRC = SQLPrepare(hstmt,
                      (SQLCHAR *)dynamic_insert.c_str(),
                      (SQLINTEGER)dynamic_insert.length());

    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    if (log)
        LOG_INFO("done");
    return cliRC;
}


int do_the_load_arrow(
    SQLHANDLE henv,
    SQLHANDLE hdbc,
    MAP_FIELDNAME_DICT &map_field_memory_vectors,
    const char  * tablespace_name,
    const char  * schema_name,
    const char  * table_name,
    const char  * MessageFile,
    const char  * TempFilesPath,
    db2Uint32   iDataBufferSize,
    db2Uint32   iSavecount,
    db2Uint32   iChunkSize,
    bool        column_oriented,
    bool        drop_table,
    db2LoadOut  * pLoadOut,
    int64_t     num_rows
)
{
    SQLRETURN cliRC = SQL_SUCCESS;
    int rc = 0;
    bool column_organyze_by = false;
    bool column_boolean = true;
    bool display_parameter = false;
    LOG_INFO("MessageFile '%s' TempFilesPath '%s'", MessageFile, TempFilesPath);
    SQLHANDLE hstmt;
    DB2LOAD_STRUCTURE load(pLoadOut,
        num_rows,
        iSavecount,
        iDataBufferSize,
        MessageFile,
        TempFilesPath);

    cliRC = SQLAllocHandle(SQL_HANDLE_STMT,
                           hdbc,
                           &hstmt);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    const char* env_log_rows = std::getenv("SPCLIENT_PYTHON_LOG_ROWS");
    if (env_log_rows != nullptr)
    {
        if (string(env_log_rows) == "1")
        {
            log_mapfieldname_dict(map_field_memory_vectors);
        }
    }


    rc = create_table_in_backend_from_map_fieldname(
                 hdbc,
                 hstmt,
                 map_field_memory_vectors,
                 tablespace_name,
                 schema_name,
                 table_name,
                 column_oriented,
                 drop_table,
                 column_organyze_by,
                 column_boolean);

    std::string  generic_insert;
    create_generic_insert(
            map_field_memory_vectors,
            schema_name,
            table_name,
            generic_insert);

    rc = run_dynamic_prepare(hdbc, hstmt, generic_insert);
    if (rc != SQL_SUCCESS)
        return rc;
 
    //bool display_columns = false;
    //const char* env_log_column = std::getenv("SPCLIENT_PYTHON_LOG_COLUMN");
    //if (env_log_column != NULL)
    //{
    //    if (string(env_log_column) == "1")
    //        display_columns = true;
    //}
    const char* env_log_parameter = std::getenv("SPCLIENT_PYTHON_LOG_PARAMETER");
    if (env_log_parameter != nullptr)
    {
        if (string(env_log_parameter) == "1")
            display_parameter = true;
    }

    bool displgeneral_log = false;
    const char* env_general_log = std::getenv("SPCLIENT_PYTHON_LOG_GENERAL");
    if (env_general_log != nullptr)
    {
        if (string(env_general_log) == "1")
            displgeneral_log = true;
    }

    MAP_COLNO_COLUMN_INFO   map_colno_sql_type; // this could be used for grained column definition
    int ret = display_parameters_map(hdbc,
                                     hstmt,
                                     map_colno_sql_type,
                                     display_parameter);

    if (displgeneral_log)
        LOG_INFO("display_parameters_map %d", ret);
    if (ret != 0)
    {
        cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
        STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
        return ret;

    }

    if (iChunkSize == 0)
        iChunkSize = num_rows / 10;

    int64_t chunks_size;
    SQLULEN chunks_size_proccesed = 0;

    if (num_rows> iChunkSize)
        chunks_size = iChunkSize;
    else
        chunks_size = num_rows;

    // Set the SQL_ATTR_PARAM_BIND_TYPE statement attribute to use
    // column-wise binding.  
    cliRC = SQLSetStmtAttr(hstmt, SQL_ATTR_PARAM_BIND_TYPE, SQL_PARAM_BIND_BY_COLUMN, 0);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    /* set the array size */
    cliRC = SQLSetStmtAttr(hstmt,
                          SQL_ATTR_PARAMSET_SIZE,
                          (SQLPOINTER)chunks_size,
                          0);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    /* set the processed records status variable*/
    cliRC = SQLSetStmtAttr(hstmt,
                           SQL_ATTR_PARAMS_PROCESSED_PTR,
                           &chunks_size_proccesed,
                           0);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    if (displgeneral_log)
        LOG_INFO("ready for bind_parameters_generic");
    /* bind the parameters */
    rc = bind_parameters_generic(
            hdbc,
            hstmt,
            num_rows,
            map_field_memory_vectors,
            map_colno_sql_type,
            column_boolean);

    if (rc != 0)
    {
        LOG_INFO("bind_parameters_generic failed %d", rc);
        return rc;
    }
    else
    {
        if (displgeneral_log)
            LOG_INFO(" bind_parameters_generic OK ");

    }
    /* turn CLI LOAD ON */
    rc = setCLILoadMode(hstmt, hdbc, TRUE, load.pLoadStruct);
    int64_t chunks_count = num_rows / chunks_size;
    std::string str_num_rows = "'{:,}'"_s.format(num_rows);


    if (displgeneral_log)
        LOG_INFO(" Inserting %s rows.. chunks_size %lld", str_num_rows.c_str(), chunks_size);

    int64_t total_inserted = 0;
    for (int64_t i = 0; i < chunks_count; i++)
    {
        total_inserted += chunks_size;
        /* insert the data */

        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLExecute(hstmt);
        Py_END_ALLOW_THREADS;


        if (cliRC != SQL_SUCCESS)
        {
            LOG_INFO("done SQLExecute %d", cliRC);
            rc = check_error(hdbc, hstmt, cliRC, __LINE__, __FUNCTION__);
        }
        else
        {
            rc = 0;
            //for (auto const& item : map_field_memory_vectors)
           // {
           //     if (item.second->vector_type == arrow::Type::DECIMAL)
           //     {
           //         for (int64_t j = 0; j < chunks_size; j++)
           //         {
           //             LOG_INFO(" sizes %d", item.second->m_str_lens[i]);
           //         }
           //     }
           // }
        }

        if (rc != 0)
        {
            if (displgeneral_log)
                LOG_INFO("the load failed, rc %d", rc);
            SQLCHAR message[SQL_MAX_MESSAGE_LENGTH + 1];
            SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1];
            SQLINTEGER sqlcode;
            SQLSMALLINT length;

            SQLGetDiagRec(SQL_HANDLE_STMT,
                hstmt,
                1,
                sqlstate,
                &sqlcode,
                message,
                SQL_MAX_MESSAGE_LENGTH + 1,
                &length);
            if (sqlcode != SQL_RC_E552)
            //User doesnt have rights for a LOAD...aka LOAD was never started
            {
                rc = setCLILoadMode(hstmt, hdbc, FALSE, load.pLoadStruct);
                if (rc != 0)
                    LOG_INFO("setCLILoadMode %d", rc);
            }
            Py_BEGIN_ALLOW_THREADS;
            cliRC = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_ROLLBACK);
            Py_END_ALLOW_THREADS;

            if (cliRC != 0)
                LOG_INFO("SQLEndTran %d", cliRC);

            cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
            if (cliRC != 0)
                LOG_INFO("SQLFreeHandle %d", cliRC);
            return rc;
        }
        else if (displgeneral_log)
            {
                std::string str_chunks_inserted = "'{:,}'"_s.format(chunks_size * (i + 1));

                LOG_INFO("Inserting %3d % 13s rows.. total % 13s %d",
                    i,
                    str_chunks_inserted.c_str(),
                    str_num_rows.c_str(),
                    chunks_size_proccesed);
            }

    }
    int64_t remaining = num_rows - total_inserted;

    // do remaining amount

    if (remaining > 0)
    {
        cliRC = SQLSetStmtAttr(hstmt,
            SQL_ATTR_PARAMSET_SIZE,
            (SQLPOINTER)remaining,
            0);
        STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLExecute(hstmt);
        Py_END_ALLOW_THREADS;
        STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
        if (displgeneral_log)
            LOG_INFO("remaining %ld %d", remaining, chunks_size_proccesed);

    }

    /* turn CLI LOAD OFF */
    rc = setCLILoadMode(hstmt, hdbc, FALSE, load.pLoadStruct);

    if (displgeneral_log)
        LOG_INFO("starting last SQL_COMMIT");

    Py_BEGIN_ALLOW_THREADS;
    cliRC = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_COMMIT);
    Py_END_ALLOW_THREADS;

    if (displgeneral_log)
        LOG_INFO("last SQL_COMMIT cliRC=%d", cliRC);
    rc = check_error(hdbc, hstmt, cliRC, __LINE__, __FUNCTION__);


    cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);

    if (displgeneral_log)
        LOG_INFO("Load messages can be found in file [%s].", MessageFile);
    return 0;

}
