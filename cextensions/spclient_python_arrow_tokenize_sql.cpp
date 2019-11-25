
#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"
#include <sqlcodes.h>

int check_error(
    SQLHDBC  hdbc,
    SQLHSTMT hstmt,
    SQLRETURN cliRC,
    int line,
    const char * functionname,
    ERROR_VAR_PARAM_DEF)
{
    int rc = 0;
    if (cliRC != SQL_SUCCESS)
    {
        rc = HandleInfoPrint(SQL_HANDLE_STMT,
                             hstmt,
                             cliRC,
                             line,
                             functionname,
                             ERROR_VAR_PARAM);
        //if (rc == 2) StmtResourcesFree(hstmt);
        //if (rc != 0) TransRollback(hdbc);
        if (rc != 0) return rc;
    }


    return rc;
}


int boost_tokenize_and_run_sql(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    std::string& s,
    ERROR_VAR_PARAM_DEF)
{
    SQLRETURN cliRC = SQL_SUCCESS;
    int rc = 0;
    bool log_create_table = false;
    const char* env_log_create = std::getenv("SPCLIENT_PYTHON_LOG_CREATE_TABLE");
    if (env_log_create != nullptr)
    {
        if (string(env_log_create) == "1")
            log_create_table = true;
    }

    py11::list py_list_str = py11::str(s.c_str()).attr("split")(";");
    for (auto str_item : py_list_str)
    {
        py11::str py_str = py11::reinterpret_borrow<py11::str>(str_item.attr("strip")());
        string str_str = string(py_str);
        if (str_str == "")
            continue;
        if (log_create_table)
            LOG_INFO("\n'%s'\n", str_str.c_str());

        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLExecDirect(hstmt,
            (SQLCHAR*)str_str.c_str(),
            (SQLINTEGER)str_str.length());
        Py_END_ALLOW_THREADS;

        if (cliRC != SQL_SUCCESS)
        {
            SQLSMALLINT length, i;
            i = 1;
            /* get multiple field settings of diagnostic record */
            sqlstate[0] = 0;
            message[0] = 0;
            SQLGetDiagRec(SQL_HANDLE_STMT,
                hstmt,
                i,
                sqlstate,
                sqlcode,
                message,
                SQL_MAX_MESSAGE_LENGTH + 1,
                &length);
            if (*sqlcode == SQL_RC_E204) /* undefined name                      */
            {
                // thats ok..if we drop a table that doesnt exist
                if (env_log_create)
                    LOG_INFO("\nsql='%s'\n'message=%s' sqlstate=%s sqlcode %d",
                        str_str.c_str(),
                        message,
                        sqlstate,
                        *sqlcode);

            }
            else
            {
                LOG_INFO("an error ocurred running\n'%s'\n", str_str.c_str());
                rc = check_error(hdbc, hstmt, cliRC, __LINE__, __FUNCTION__, ERROR_VAR_PARAM);
            }
        }

        Py_BEGIN_ALLOW_THREADS;
        cliRC = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_COMMIT);
        Py_END_ALLOW_THREADS;
        rc = HandleInfoPrint(SQL_HANDLE_DBC, hdbc,
                             cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);
    }
    if (log_create_table)
        LOG_INFO("done");
    return 0;
}
