
#include "spclient_python_common_cpp.h"

using namespace py11::literals;

void print_dir(py11::object &_object)
{
    std::string code = R"(
def print_py(py):
    print(dir(py))
)";
    try
    {
        py11::exec(code.c_str());
        py11::object ret = py11::globals()["print_py"](_object);
    }
    catch (py11::error_already_set & e)
    {
        LOG_INFO("error_already_set '%s'", e.what());
        return;
    }

}


/*
int  read_sql_file(char * sql_str)
{
    FILE *p_file;
    std::string drop_table_str;
    p_file = fopen("create_load_table.sql", "r");
    if (p_file == NULL)
    {
        LOG_INFO("create_load_table.sql file missing");
        return -1;
    }
    fseek(p_file, 0L, SEEK_END);
    size_t file_size = ftell(p_file);
    rewind(p_file);
    Py_BEGIN_ALLOW_THREADS;
    size_t file_read = fread(sql_str, 1, file_size, p_file);
    Py_END_ALLOW_THREADS;
    assert(file_read == file_size);
    sql_str[file_read] = 0;
    fclose(p_file);

    return 0;

}
*/

const char* __doc__(PyCFunction func)
{
    PyMethodDef* pymethod;
    bool OK = true;
    int i = 0;
    while (OK == true)
    {
        pymethod = &spclient_python_Methods[i];
        if (pymethod->ml_name == NULL)
            OK = false;
        else
        {
            if (spclient_python_Methods[i].ml_meth == func)
                return spclient_python_Methods[i].ml_doc;
        }
        i++;
    }
    return NULL;
}
/* turn the CLI LOAD feature ON or OFF */
int setCLILoadMode(
    SQLHSTMT hstmt,
    SQLHDBC hdbc,
    int fStartLoad,
    db2LoadStruct *pLoadStruct,
    ERROR_VAR_PARAM_DEF)
{
    int rc = 0;
    SQLRETURN cliRC = SQL_SUCCESS;
    bool displgeneral_log = false;
    const char* env_general_log = std::getenv("SPCLIENT_PYTHON_LOG_GENERAL");
    if (env_general_log != nullptr)
    {
        if (string(env_general_log) == "1")
            displgeneral_log = true;
    }

    if (displgeneral_log)
    {
        if (fStartLoad)
            LOG_INFO("\n  Turn CLI LOAD on");
        else
            LOG_INFO("\n  Turn CLI LOAD off");
    }

    if (fStartLoad)
    {

    /*
        
       Use load values.

    SQL_USE_LOAD_OFF                  0
    SQL_USE_LOAD_INSERT               1
    SQL_USE_LOAD_REPLACE              2
    SQL_USE_LOAD_RESTART              3
    SQL_USE_LOAD_TERMINATE            4
    */
        cliRC = SQLSetStmtAttr(hstmt,
                               SQL_ATTR_USE_LOAD_API,
                               (SQLPOINTER)SQL_USE_LOAD_INSERT,
                               0);
        /*When SQL_USE_LOAD_INSERT or SQL_USE_LOAD_REPLACE is set,
         * no other CLI functions except for the following can be called until SQL_USE_LOAD_OFF is set (see Step 3 below):
        SQLBindParameter()
        SQLExecute()
        SQLExtendedBind()
        SQLParamOptions()
        SQLSetStmtAttr()
        */
        STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
        Py_BEGIN_ALLOW_THREADS
        cliRC = SQLSetStmtAttr(hstmt,
                               SQL_ATTR_LOAD_INFO,
                               (SQLPOINTER)pLoadStruct,
                               0);
        Py_END_ALLOW_THREADS
        STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    }

    else
    {
        Py_BEGIN_ALLOW_THREADS
        cliRC = SQLSetStmtAttr(hstmt,
                               SQL_ATTR_USE_LOAD_API,
                               (SQLPOINTER)SQL_USE_LOAD_OFF,
                               0);
        Py_END_ALLOW_THREADS
        STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    }

    return rc;
}

