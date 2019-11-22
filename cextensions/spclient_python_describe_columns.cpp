
#include <utility>
#include "spclient_python_common_cpp.h"

using namespace py11::literals;
using namespace std;


static int func_registered_set_table_describe_col = 0;

void register_table_columns()
{
    string set_table_col = R"(
def get_table_describe_col():
    from texttable import Texttable
    table = Texttable()
    table.set_deco(Texttable.HEADER)
    table.set_header_align(['l','l', 'l', 'r', 'r', 'l','r', 'r', 'r', 'r'])
    table.set_cols_dtype(['t',
                         't',
                         't',
                         't',   
                         't',   
                         't',   
                         't',   
                         't',   
                         't',
                         't'])  
    table.set_cols_align(['l', 'l', 'l', 'r', 'r', 'l', 'r', 'r', 'r', 'r'])  
    table.header(['no',            
                  'c. name',       
                  'c. name size',  
                  'colDataDisplaySize',
                  'pfSqlType',     
                  'sql type',      
                  'pibScale',      
                  'pcbColDef',     
                  'pfNullable', 'SQL_DESC_USER_DEFINED_TYPE_CODE'])   
    table.set_cols_width([4, 50, 13, 10, 10, 20, 10, 10, 24, 32])  
 
    return table
)";
    if (func_registered_set_table_describe_col == 0)
    {

        try
        {
            py11::function py_get_table_describe_col;
            PyObject* main_module = PyImport_AddModule("__main__"); //Borrowed reference. 
            PyObject* main_dict = PyModule_GetDict(main_module);    //Borrowed reference. same as main_module.__dict__ 
            py11::exec(set_table_col.c_str());
            py_get_table_describe_col = py11::reinterpret_borrow<py11::function>
                (py11::globals()["get_table_describe_col"]);
            int ret = PyDict_SetItemString(main_dict,
                                           "get_table_describe_col",
                                           py_get_table_describe_col.ptr());
            if (ret != 0)
            {
                LOG_INFO("PyDict_SetItemString ret = %d", ret);
                return;
            }
            func_registered_set_table_describe_col = 1;
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("py::exec  error_already_set '%s'", e.what());
            return;
        }
    }

}

py11::object get_table_columns()
{
    py11::function py_get_table_describe_col;
    int err = 0;

    if (func_registered_set_table_describe_col == 0)
        register_table_columns();

    try
    {
        PyObject* main_module = PyImport_AddModule("__main__"); // //Borrowed reference.
        PyObject* main_dict = PyModule_GetDict(main_module);  //Borrowed reference. same as main_module.__dict__ 
        PyObject* get_table_describe_col = PyDict_GetItemString(main_dict, "get_table_describe_col");
        py_get_table_describe_col = py11::reinterpret_borrow<py11::function>(get_table_describe_col);
        //py_set_table_describe_col = py11::reinterpret_borrow<py11::function>(py11::globals()["get_table_describe_col"]);
        return py_get_table_describe_col();
    }
    catch (py11::error_already_set & e)
    {
        err = 1;
        LOG_INFO("set_table_describe_col error_already_set '%s'", e.what());

    }

    if (err == 1)
    {
        func_registered_set_table_describe_col = 0;
        register_table_columns();
        try
        { 
            py_get_table_describe_col = py11::reinterpret_borrow<py11::function>(py11::globals()["set_table_describe_col"]);
            return py_get_table_describe_col();
        }
        catch (py11::error_already_set& e)
        {
            LOG_INFO("set_table_describe_col  error_already_set '%s'", e.what());
            return py11::cast<py11::none>(Py_None);

        }

    }
    return py11::cast<py11::none>(Py_None);
}

/*  wrapped python_describe_columns function consuming ibm_db.IBM_DBStatement */
PYOBJ_PTR python_describe_columns(
    PYOBJ_PTR self, 
    PYOBJ_PTR args)
{
    ERROR_VAR
    PYOBJ_PTR py_stmt_res = NULL;
    PYOBJ_PTR py_display = NULL;
    PYOBJ_PTR py_list_describe_cols = NULL;
    stmt_handle *stmt_res;
    bool display;
    int ret = 0;

    if (!PyArg_ParseTuple(args, "OO", 
        &py_stmt_res, 
        &py_display))
    {
        PyErr_Format(PyExc_ValueError,
                     "parameters count must be 2 %s %d %s()", 
            __doc__(python_describe_columns), 
            __LINE__, 
            __FUNCTION__);
        return NULL;
    }

    if (py_stmt_res == NULL)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied statement object Parameter is NULL %d %s()", __LINE__, __FUNCTION__);
        return NULL;

    }
    display = PyObject_IsTrue(py_display);

    if (strcmp(Py_TYPE(py_stmt_res)->tp_name, "ibm_db.IBM_DBStatement") != 0)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied connection object Parameter is invalid '%s' it should be ibm_db.IBM_DBStatement %d %s()",
                     Py_TYPE(py_stmt_res)->tp_name, __LINE__, __FUNCTION__ );
        return NULL;
    }
    else
        stmt_res = (stmt_handle *)py_stmt_res;

    py_list_describe_cols = PyList_New(0); //Return value: New reference.
    ret = display_columns(stmt_res->hdbc,
                          stmt_res->hstmt,
                          "generic",
                          display,
                          py_list_describe_cols,
                          ERROR_VAR_PARAM_1);
    return py_list_describe_cols;


}

/*  wrapped python_describe_columns function consuming ctypes.c_void_p
       henv         = ctypes.c_void_p(None) # environment handle
       hdbc         = ctypes.c_void_p(None) # communication handle
       hstmt        = ctypes.c_void_p(None) # statement handle

*/
PYOBJ_PTR python_describe_columns_by_cli(
    PYOBJ_PTR self,
    PYOBJ_PTR args)
{
    ERROR_VAR
    PYOBJ_PTR py_stmt;
    PYOBJ_PTR py_hdbc;
    PYOBJ_PTR py_display;
    PYOBJ_PTR py_list_describe_cols = NULL;
    SQLHANDLE *hsmt = 0; /* statement handle */
    SQLHANDLE *hdbc = 0; /* connection handle */
    bool display;
    int ret = 0;

    if (!PyArg_ParseTuple(args, "OOO",
        &py_hdbc,
        &py_stmt,
        &py_display))
    {
        PyErr_Format(PyExc_ValueError,
            "parameters count must be 4, hdbc, stmt, display, list_describe_cols");
        return NULL;
    }

    hdbc = (SQLHANDLE *)PyLong_AsVoidPtr(py_hdbc);
    hsmt = (SQLHANDLE *)PyLong_AsVoidPtr(py_stmt);

    display = PyObject_IsTrue(py_display);
    py_list_describe_cols = PyList_New(0); //Return value: New reference.
    ret = display_columns(*hdbc,
                          *hsmt,
                          "generic",
                          display,
                          py_list_describe_cols,
                          ERROR_VAR_PARAM_1);
    return py_list_describe_cols;
}

int display_columns(
SQLHDBC       hdbc,
SQLHSTMT      hstmt,
const char *   comment,
bool           display,
PYOBJ_PTR      py_list_describe_cols,
ERROR_VAR_PARAM_DEF)
{
    int           rc = 0;
    py11::object  py11_table;
    SQLRETURN     cliRC = SQL_SUCCESS;
    SQLSMALLINT   NumColumns;
    SQLSMALLINT   pfSqlType;
    SQLULEN       pcbColDef;
    SQLSMALLINT   pibScale;
    SQLSMALLINT   pfNullable;
    SQLSMALLINT   column_name_size;
    SQLINTEGER    colDataDisplaySize;
    SQLSMALLINT   descUserDefinedTypeCode;
    int           max_column_name_len = 0;
    string        str_sql_type;
    char          column_name[255] = {};

    Py_BEGIN_ALLOW_THREADS
    cliRC = SQLNumResultCols(hstmt, &NumColumns);
    Py_END_ALLOW_THREADS
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    if (NumColumns == 0)
    {
        LOG_INFO("NumColumns = 0");
        return 0;
    }
    if (display)
        py11_table = get_table_columns();

    //LOG_INFO("py_table= %x  '%s'",  py_table.ptr(), Py_TYPE(py_table.ptr())->tp_name);
 
    for (int col=1; col <= NumColumns; col++)
    {
        memset(column_name, 0, sizeof(column_name));
        Py_BEGIN_ALLOW_THREADS
        rc = SQLDescribeCol(hstmt,
                            col,
                            (SQLCHAR *)column_name,
                            sizeof(column_name),
                            &column_name_size,
                            &pfSqlType,
                            &pcbColDef,
                            &pibScale,
                            &pfNullable);
        Py_END_ALLOW_THREADS
        STMT_HANDLE_CHECK(hstmt, hdbc, rc);

        Py_BEGIN_ALLOW_THREADS
        /* get display size for column */
        cliRC = SQLColAttribute(hstmt,
            (SQLSMALLINT)(col),
            SQL_DESC_DISPLAY_SIZE,
            NULL,
            0,
            NULL,
            &colDataDisplaySize);
        Py_END_ALLOW_THREADS
        STMT_HANDLE_CHECK(hstmt, hdbc, rc);

        Py_BEGIN_ALLOW_THREADS
        /* get SQL_DESC_USER_DEFINED_TYPE_CODE */
        descUserDefinedTypeCode = -1;
        cliRC = SQLColAttribute(hstmt,
            (SQLSMALLINT)(col),
                SQL_DESC_USER_DEFINED_TYPE_CODE,
                NULL,
                0,
                NULL,
                &descUserDefinedTypeCode);
        Py_END_ALLOW_THREADS
        STMT_HANDLE_CHECK(hstmt, hdbc, rc);

        if (column_name_size > max_column_name_len)
            max_column_name_len = column_name_size;

        str_sql_type = map_sql_value_sql_str()[pfSqlType];
        if ((rc == SQL_SUCCESS) || rc == (SQL_SUCCESS_WITH_INFO))
        {
            if (py_list_describe_cols != NULL)
            {
                PyObject* some_dic = Py_BuildValue("{sssssisisi}",
                        "name",
                        column_name,
                        "sql_type",
                        str_sql_type.c_str(),
                        "name_size",
                        column_name_size,
                        "pcbColDef",
                        pcbColDef,
                        "colDataDisplaySize",
                        colDataDisplaySize
                        );//New reference.
                PyList_Append(py_list_describe_cols, some_dic);
            }

            if (display)
            {

                py11::list py11_my_row = py11::reinterpret_borrow<py11::list>(Py_BuildValue("[isiiisiOss]",
                    col,
                    column_name,
                    column_name_size,
                    colDataDisplaySize,
                    pfSqlType,
                    str_sql_type.c_str(),
                    pibScale,
                    "{:,}"_s.format(pcbColDef).ptr(),
                    map_nulls_str()[pfNullable].c_str(),
                    map_sql_value_userdefinedtypecode_str()[descUserDefinedTypeCode].c_str()));

                if (py11_table.is_none() == false)
                    auto ret = py11_table.attr("add_row")(py11_my_row);
            }
        }
    }


    if ((display) && (py11_table.is_none() == false))
    {
        py11::list  py_table_width = py11_table.attr("_width");
        py_table_width[1] = max_column_name_len + 2;

        py11::str ret = py11_table.attr("draw")();
        LOG_INFO("py11 columns\n'%s' \n%s\n", comment, ((string)ret).c_str());
    }

    return 0;


}


