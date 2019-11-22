
#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"
#include <sqlcodes.h>
#include <chrono>
#include <thread>
#include <sstream>

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
    insert_into = "INSERT INTO\n \"";
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
    std::string &dynamic_insert,
    ERROR_VAR_PARAM_DEF)
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

    Py_BEGIN_ALLOW_THREADS
    cliRC = SQLPrepare(hstmt,
                      (SQLCHAR *)dynamic_insert.c_str(),
                      (SQLINTEGER)dynamic_insert.length());
    Py_END_ALLOW_THREADS

    if (log)
        LOG_INFO("SQLPrepare cliRC=%d", cliRC);

    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    if (log)
        LOG_INFO("done");
    return cliRC;
}


int do_the_load_arrow(
    SQLHANDLE henv,
    SQLHANDLE hdbc,
    SQLHANDLE &hstmt,
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
    bool        create_table,
    db2LoadOut  * pLoadOut,
    int64_t     parquet_num_rows,
    ERROR_VAR_PARAM_DEF
)
{
    SQLRETURN cliRC = SQL_SUCCESS;
    int rc = 0;
    long rows_loaded = 0;
    long rows_deleted = 0;
    long rows_committed = 0;
    long rows_read = 0;

    bool column_organize_by = false;
    bool column_boolean = true;
    bool display_parameter = false;
    //LOG_INFO("MessageFile '%s' TempFilesPath '%s'", MessageFile, TempFilesPath);
 
    DB2LOAD_STRUCTURE load( pLoadOut,
                            parquet_num_rows,
                            iSavecount,
                            iDataBufferSize,
                            MessageFile,
                            TempFilesPath);

    cliRC = SQLAllocHandle(SQL_HANDLE_STMT,
                           hdbc,
                           &hstmt);
    DBC_HANDLE_CHECK(hdbc, cliRC);
    const char* env_log_rows = std::getenv("SPCLIENT_PYTHON_LOG_ROWS");
    if (env_log_rows != nullptr)
    {
        if (string(env_log_rows) == "1")
            log_mapfieldname_dict(map_field_memory_vectors);
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
                 create_table,
                 column_organize_by,
                 column_boolean,
                 ERROR_VAR_PARAM);

    std::string  generic_insert;
    create_generic_insert(
            map_field_memory_vectors,
            schema_name,
            table_name,
            generic_insert);

    rc = run_dynamic_prepare(hdbc, hstmt, generic_insert, ERROR_VAR_PARAM);
    if (rc != SQL_SUCCESS)
    {
        LOG_INFO("run_dynamic_prepare failed %d", rc);
        return rc;
    }
 
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
                                     table_name,
                                     map_colno_sql_type,
                                     display_parameter,
                                     ERROR_VAR_PARAM);
 

    if (ret != 0)
    {
        if (displgeneral_log)
            LOG_INFO("display_parameters_map falied %d", ret);
        return ret;
    }

    if (iChunkSize == 0)
        //iChunkSize = parquet_num_rows / 10;
        iChunkSize = 10000;

    int64_t chunks_size;
    SQLULEN chunks_size_proccesed = 0;

    if (parquet_num_rows> iChunkSize)
        chunks_size = iChunkSize;
    else
        chunks_size = parquet_num_rows;

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

    cliRC = SQLSetStmtAttr(hstmt,
                           SQL_ATTR_LOAD_ROWS_COMMITTED_PTR,
                           &rows_committed,
                           SQL_IS_POINTER);
 
    cliRC = SQLSetStmtAttr(hstmt,
                           SQL_ATTR_LOAD_ROWS_READ_PTR,
                           &rows_read,
                           SQL_IS_POINTER);

    cliRC = SQLSetStmtAttr(hstmt,
                           SQL_ATTR_LOAD_ROWS_LOADED_PTR,
                           &rows_loaded,
                           SQL_IS_POINTER);
    cliRC = SQLSetStmtAttr(hstmt,
                           SQL_ATTR_LOAD_ROWS_DELETED_PTR,
                           &rows_deleted,
                           SQL_IS_POINTER);


    if (displgeneral_log)
        LOG_INFO("ready for bind_parameters");
    /* bind the parameters */
    rc = bind_parameters(
            hdbc,
            hstmt,
            parquet_num_rows,
            map_field_memory_vectors,
            map_colno_sql_type,
            column_boolean,
            ERROR_VAR_PARAM);

    if (rc != 0)
    {
        LOG_INFO("bind_parameters failed %d", rc);
        return rc;
    }
    else
    {
        if (displgeneral_log)
            LOG_INFO(" bind_parameters OK ");

    }
    /* turn CLI LOAD ON */
    rc = setCLILoadMode(hstmt, hdbc, TRUE, load.pLoadStruct, ERROR_VAR_PARAM);
    int64_t chunks_count = parquet_num_rows / chunks_size;
    string str_num_rows = "'{:,}'"_s.format(parquet_num_rows);
    string str_chunks_size = "'{:,}'"_s.format(chunks_size);

    if (displgeneral_log)
        LOG_INFO(" Inserting %s rows.. chunks_size %s",
                 str_num_rows.c_str(),
                 str_chunks_size.c_str());

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
            rc = check_error(hdbc, hstmt, cliRC, __LINE__, __FUNCTION__, ERROR_VAR_PARAM);
            LOG_INFO("done SQLExecute rc %d", rc);
        }
        else
        {
            rc = 0;
        }

        if (cliRC != 0)
        {
            SQLRETURN originalcliRC = cliRC;
            if (displgeneral_log)
                LOG_INFO("the load failed, cliRC %d", cliRC);

            SQLSMALLINT length;

            SQLGetDiagRec(SQL_HANDLE_STMT,
                hstmt,
                1,
                sqlstate,
                sqlcode,
                message,
                SQL_MAX_MESSAGE_LENGTH + 1,
                &length);

            if (*sqlcode != SQL_RC_E552)
            //User doesnt have rights for a LOAD...aka LOAD was never started
            {
                LOG_INFO("sqlcode %d != SQL_RC_E552", *sqlcode);
                rc = setCLILoadMode(hstmt, hdbc, FALSE, load.pLoadStruct, ERROR_VAR_PARAM);
                if (rc != 0)
                    LOG_INFO("setCLILoadMode %d", rc);
            }
            Py_BEGIN_ALLOW_THREADS;
            cliRC = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_ROLLBACK);
            Py_END_ALLOW_THREADS;

            if (cliRC != 0)
            {
                LOG_INFO("SQLEndTran %d", cliRC);
                rc = HandleInfoPrint(SQL_HANDLE_DBC, hdbc,
                    cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);

            }

            cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
            if (cliRC != 0)
                LOG_INFO("SQLFreeHandle %d", cliRC);
            hstmt = SQL_NULL_HSTMT;

            LOG_INFO("returning originalcliRC %d", originalcliRC);
            return originalcliRC;
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
    int64_t remaining = parquet_num_rows - total_inserted;

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
    if (displgeneral_log)
        LOG_INFO("calling  setCLILoadMode");
    rc = setCLILoadMode(hstmt, hdbc, FALSE, load.pLoadStruct, ERROR_VAR_PARAM);

    if (displgeneral_log)
        LOG_INFO("starting last SQL_COMMIT");

    Py_BEGIN_ALLOW_THREADS;
    cliRC = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_COMMIT);
    Py_END_ALLOW_THREADS;
    rc = HandleInfoPrint(SQL_HANDLE_DBC, hdbc,
                         cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);

    //if (displgeneral_log // yes it works
    //    LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_READ_PTR       is %ld", rows_read);
    //    LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_LOADED_PTR     is %ld", rows_loaded);
    //    LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_COMMITTED_PTR  is %ld", rows_committed);
    //    LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_DELETED_PTR    is %ld", rows_deleted);

#define READ_LOAD__ // yes it works ? we can use it later
#ifdef READ_LOAD
    long* prows_loaded;
    long* prows_read;
    long* prows_deleted;
    long* prows_committed;
    rc = SQLGetStmtAttr(hstmt,
                        SQL_ATTR_LOAD_ROWS_LOADED_PTR,
                        &prows_loaded,
                        sizeof(rows_loaded),
                        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, rc);

    rc = SQLGetStmtAttr(hstmt,
                        SQL_ATTR_LOAD_ROWS_READ_PTR,
                        &prows_read,
                        sizeof(rows_read),
                        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, rc);

    rc = SQLGetStmtAttr(hstmt,
                        SQL_ATTR_LOAD_ROWS_COMMITTED_PTR,
                        &prows_committed,
                        sizeof(rows_committed),
                        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, rc);

    rc = SQLGetStmtAttr(hstmt,
                        SQL_ATTR_LOAD_ROWS_DELETED_PTR,
                        &prows_deleted,
                        sizeof(rows_deleted),
                        NULL);
    STMT_HANDLE_CHECK(hstmt, hdbc, rc);
    
    if (displgeneral_log)
        LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_READ_PTR      is %ld",  *prows_read);
        LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_LOADED_PTR    is %ld",  *prows_loaded);
        LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_COMMITTED_PTR is %ld",  *prows_committed);
        LOG_INFO("Value of SQL_ATTR_LOAD_ROWS_DELETED_PTR   is %ld",  *prows_deleted);

#endif
    if ((displgeneral_log) && (cliRC !=0))
        LOG_INFO("last SQL_COMMIT cliRC=%d", cliRC);

    cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    hstmt = SQL_NULL_HSTMT;

    if (displgeneral_log)
        LOG_INFO("\nLoad messages can be found in file [%s].", MessageFile);
    return 0;

}
