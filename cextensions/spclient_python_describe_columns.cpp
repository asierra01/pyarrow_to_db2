
#include <utility>
#include "spclient_python_common_cpp.h"

using namespace py11::literals;
using namespace std;

//#define _DEBUG 1

static int func_registered_set_table_describe_col = 0;

void register_table_columns()
{
    string some_command_find_path = R"(
def set_table_describe_col():
    from texttable import Texttable
    table = Texttable()
    table.set_deco(Texttable.HEADER)
    table.set_header_align(['l','l', 'r', 'r', 'l','r', 'r', 'r'])
    table.set_cols_dtype(['t',
                         't',
                         't',   
                         't',   
                         't',   
                         't',   
                         't',   
                         't'])  
    table.set_cols_align(['l', 'l', 'r', 'r', 'l', 'r', 'r', 'r'])  
    table.header(['no',            
                  'c. name',       
                  'c. name size',  
                  'pfSqlType',     
                  'sql type',      
                  'pibScale',      
                  'pcbColDef',     
                  'pfNullable'])   
    table.set_cols_width([4, 50, 13, 10, 20, 10, 10, 10])  
 
    return table
)";
    if (func_registered_set_table_describe_col == 0)
    {

        try
        {
            py11::exec(some_command_find_path.c_str());
            func_registered_set_table_describe_col = 1;
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("py::exec  %s", e.what());
            return;
        }
    }

}

py11::object get_table_columns()
{
    py11::object py_set_table_describe_col;
    int err = 0;

    if (func_registered_set_table_describe_col == 0)
        register_table_columns();

    try
    {
        py_set_table_describe_col = py11::globals()["set_table_describe_col"];
    }
    catch (py11::error_already_set & e)
    {
        err = 1;
        LOG_INFO("set_table_describe_col  %s", e.what());

    }

    if (err == 1)
    {
        func_registered_set_table_describe_col = 0;
        register_table_columns();
        try
        { 
            py_set_table_describe_col = py11::globals()["set_table_describe_col"];
        }
        catch (py11::error_already_set& e)
        {
            LOG_INFO("set_table_describe_col  %s", e.what());
            return py11::cast<py11::none>(Py_None);

        }

    }
    try
    {
       return py_set_table_describe_col(); 
    }
    catch (py11::error_already_set& e)
    {
        LOG_INFO("py_set_table_describe_col  %s", e.what());
        return py11::cast<py11::none>(Py_None);

    }
}

/*  wrapped python_describe_columns function consuming ibm_db.IBM_DBStatement */
PYOBJ_PTR python_describe_columns(
    PYOBJ_PTR self, 
    PYOBJ_PTR args)
{
    PYOBJ_PTR py_stmt_res = NULL;
    PYOBJ_PTR py_display = NULL;
    PYOBJ_PTR py_list_describe_cols = NULL;
    stmt_handle *stmt_res;
    bool display;
    int ret = 0;

    if (!PyArg_ParseTuple(args, "OOOO", 
        &py_stmt_res, 
        &mylog_info, 
        &py_display, 
        &py_list_describe_cols))
    {
        PyErr_Format(PyExc_ValueError,
                     "parameters count must be 3  ibm_db.IBM_DBStatement, '%s'", "yes 3 parameters");
        return NULL;
    }

    if (py_stmt_res == NULL)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied statement object Parameter is NULL");
        return NULL;

    }
    display = PyObject_IsTrue(py_display);

    //LOG_INFO("%s", Py_TYPE(py_Db2_Cli)->tp_name); // yes list
    if (strcmp(Py_TYPE(py_stmt_res)->tp_name, "ibm_db.IBM_DBStatement") != 0)
    {
        PyErr_Format( PyExc_TypeError,
                     "Supplied connection object Parameter is invalid '%s' it should be ibm_db.IBM_DBStatement",
                     Py_TYPE(py_stmt_res)->tp_name );
        return NULL;
    }
    else
        stmt_res = (stmt_handle *)py_stmt_res;

    //StmtResultPrint(stmt_res->hstmt, stmt_res->hdbc);
    ret = display_columns(stmt_res->hdbc, stmt_res->hstmt, display, py_list_describe_cols);

    Py_RETURN_NONE;

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
    PYOBJ_PTR py_stmt;
    PYOBJ_PTR py_hdbc;
    PYOBJ_PTR py_display;
    PYOBJ_PTR py_list_describe_cols = NULL;
    SQLHANDLE *hsmt = 0; /* statement handle */
    SQLHANDLE *hdbc = 0; /* connection handle */
    bool display;
    int ret = 0;

    if (!PyArg_ParseTuple(args, "OOOOO",
        &py_hdbc,
        &py_stmt,
        &mylog_info,
        &py_display,
        &py_list_describe_cols))
    {
        PyErr_Format(PyExc_ValueError,
            "parameters count must be 3  ibm_db.IBM_DBStatement, '%s'", "yes 3 parameters");
        return NULL;
    }

    hdbc = (SQLHANDLE *)PyLong_AsVoidPtr(py_hdbc);
    hsmt = (SQLHANDLE *)PyLong_AsVoidPtr(py_stmt);

    display = PyObject_IsTrue(py_display);
    ret = display_columns(*hdbc, *hsmt, display, py_list_describe_cols);

    Py_RETURN_NONE;

}


int display_columns(
        SQLHANDLE      hdbc,
        SQLHANDLE      hstmt,
        bool           display,
        PYOBJ_PTR      py_list_describe_cols)
{
    int           rc = 0;
    py11::object  py_table;
    SQLRETURN     cliRC = SQL_SUCCESS;
    SQLSMALLINT   NumColumns;
    SQLSMALLINT   pfSqlType;
    SQLULEN       pcbColDef;
    SQLSMALLINT   pibScale;
    SQLSMALLINT   pfNullable;
    SQLSMALLINT   column_name_size;
    int           max_column_name_len = 0;
    string        str_sql_type;
    char          column_name[255];

    Py_BEGIN_ALLOW_THREADS
    cliRC = SQLNumResultCols(hstmt, &NumColumns);
    Py_END_ALLOW_THREADS
    STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
    if (NumColumns == 0)
    {
        LOG_INFO("NumColumns = 0\n");
        return 0;
    }
    py_table = get_table_columns();

    //LOG_INFO("py_table= %x  '%s'",  py_table.ptr(), Py_TYPE(py_table.ptr())->tp_name);

    for (int col=1; col <= NumColumns; col++)
    {
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

        if (column_name_size > max_column_name_len)
            max_column_name_len = column_name_size;

        str_sql_type = map_sql_value_sql_str()[pfSqlType];
        if ((rc == SQL_SUCCESS) || rc == (SQL_SUCCESS_WITH_INFO))
        {
            if (py_list_describe_cols != NULL)
            {
                PyObject* some_dic = Py_BuildValue("{sssssisi}",
                        "name",
                        column_name,
                        "sql_type",
                        str_sql_type.c_str(),
                        "name_size",
                        column_name_size,
                        "pcbColDef",
                        pcbColDef
                        );//New reference.
                PyList_Append(py_list_describe_cols, some_dic);
            }
            /*
            some_dic = {'name'      : column_name.value,
                        'sql_type'  : str_sql_type,
                        'name_size' : column_name_size.value,
                        'pcbColDef' : pcbColDef.value
                        }
            self.describe_cols.append(some_dic)
            */
            if (display)
            {

                py11::list py11_my_row = py11::reinterpret_borrow<py11::list>(Py_BuildValue("[isiisiOi]",
                    col,
                    column_name,
                    column_name_size,
                    pfSqlType,
                    str_sql_type.c_str(),
                    pibScale,
                    "{:,}"_s.format(pcbColDef).ptr(),
                    pfNullable));
                py_table.attr("add_row")(py11_my_row);
            }
        }
    }


    if (display)
    {
        py11::list  py_table_width = py_table.attr("_width");
        py_table_width[1] = max_column_name_len + 2;

        py11::str ret = py_table.attr("draw")();
        LOG_INFO("py11 columns\n%s\n", ((string)ret).c_str());
    }

    return 0;


}


