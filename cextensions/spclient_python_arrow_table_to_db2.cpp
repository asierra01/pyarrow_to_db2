

#include <parquet/exception.h>
#include "arrow_table_to_db2.h"


int check_parameters(
    PYOBJ_PTR py_conn_res,
    conn_handle * * conn_res,
    PYOBJ_PTR py_parquet_table,
    TABLE     * parquet_table,
    PYOBJ_PTR py_table_name,
    PYOBJ_PTR py_schema_name,
    PYOBJ_PTR py_tablespace_name,
    PYOBJ_PTR py_table_column_oriented,
    PYOBJ_PTR py_drop_table,
    PYOBJ_PTR py_create_table,
    char *    table_name,
    char *    schema_name,
    char *    tablespace_name,
    bool&     table_column_oriented,
    bool&     drop_table,
    bool&     create_table
)
{
    if (py_conn_res == NULL)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied conn object Parameter is NULL it should be ibm_db.IBM_DBConnection %s",
            arrow_table_to_db2_docstring.c_str());
        return -1;
    }

    if (strcmp(Py_TYPE(py_conn_res)->tp_name, IBM_DBConnection) != 0)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied connection object Parameter is invalid '%s' it should be ibm_db.IBM_DBConnection %s",
            Py_TYPE(py_conn_res)->tp_name,
            arrow_table_to_db2_docstring.c_str());
        return -1;
    }
    else
        * conn_res = (conn_handle * )py_conn_res;

    if (py_table_name != Py_None)
    {
        py11::str py_str_table_name = py11::reinterpret_borrow<py11::str>(py_table_name);
        strcpy_s(table_name, 255, ((string) py_str_table_name).c_str());
    }

    if (py_schema_name != Py_None)
    {
        py11::str py_str_schema_name = py11::reinterpret_borrow<py11::str>(py_schema_name);
        strcpy_s(schema_name, 255, ((string) py_str_schema_name).c_str());
    }

    if (py_tablespace_name != Py_None)
    {
        py11::str py_str_tablespace_name = py11::reinterpret_borrow<py11::str>(py_tablespace_name);
        strcpy_s(tablespace_name, 255, ((string) py_str_tablespace_name).c_str());
    }

    if (py_table_column_oriented != Py_None)
    {
        if (PyBool_Check(py_table_column_oriented))
        {
            if (py_table_column_oriented == Py_True)
                table_column_oriented = true;
            else
                table_column_oriented = false;
        }
        else
        {
            PyErr_Format(PyExc_TypeError,
                "Supplied table_column_oriented is invalid '%s' it should be True or False %s",
                Py_TYPE(py_table_column_oriented)->tp_name,
                arrow_table_to_db2_docstring.c_str());
            return -1;

        }
    }

    if (py_drop_table != Py_None)
    {
        if (PyBool_Check(py_drop_table))
        {
            if (py_drop_table == Py_True)
                drop_table = true;
            else
                drop_table = false;
        }
        else
        {
            PyErr_Format(PyExc_TypeError,
                "Supplied drop_table is invalid '%s' it should be True or False %s",
                Py_TYPE(py_drop_table)->tp_name,
                arrow_table_to_db2_docstring.c_str());
            return -1;
        }
    }

    if (py_create_table != Py_None)
    {
        if (PyBool_Check(py_create_table))
        {
            if (py_create_table == Py_True)
                create_table = true;
            else
                create_table = false;
        }
        else
        {
            PyErr_Format(PyExc_TypeError,
                "Supplied py_create_table is invalid '%s' it should be True or False %s",
                Py_TYPE(py_create_table)->tp_name,
                arrow_table_to_db2_docstring.c_str());
            return -1;
        }
    }

    load_pyarrow();

    try
    {
        if (arrow::py::is_table(py_parquet_table))
        {
            PARQUET_THROW_NOT_OK(arrow::py::unwrap_table(py_parquet_table, parquet_table));
        }
        else
        {
            PyErr_Format(PyExc_TypeError,
                " table parameter invalid type '%s' it should be 'pyarrow.Table' 'pyarrow.lib.Table'",
                Py_TYPE(py_parquet_table)->tp_name);
            return -1;
        }
    }
    catch (::parquet::ParquetException &e)
    {
        LOG_INFO("ParquetException '%s' \n", e.what());
        PyErr_Format(PyExc_Exception, e.what());
        return -1;
    }
    return 0;
}

/*  wrapped python_arrow_table_to_db2 function but now consuming ibm_db.IBM_DBConnection and pyarrow.lib.table */
PYOBJ_PTR  python_arrow_table_to_db2(
    PYOBJ_PTR  self, 
    PYOBJ_PTR  args)
{
    ERROR_VAR
    char table_name[255] = {};
    char schema_name[255] = {};
    char tablespace_name[255] = {};
    char MessageFile[255] = {};
    char TempFilesPath[255] = {};
    db2Uint32 iDataBufferSize = 0;
    db2Uint32 iSavecount = 0;
    db2Uint32 iChunkSize = 0;
    db2Uint32 imax_rows = 0;
    PYOBJ_PTR py_MessageFile = nullptr;
    PYOBJ_PTR py_TempFilesPath = nullptr;
    PYOBJ_PTR py_table_name = nullptr;
    PYOBJ_PTR py_schema_name = nullptr;
    PYOBJ_PTR py_tablespace_name = nullptr;
    PYOBJ_PTR py_table_column_oriented = nullptr;
    PYOBJ_PTR py_conn_res = nullptr;
    PYOBJ_PTR py_parquet_table = nullptr;
    PYOBJ_PTR py_drop_table = nullptr;
    PYOBJ_PTR py_create_table = nullptr;
    conn_handle * conn_res = nullptr;
    TABLE       parquet_table;
    bool        table_column_oriented = false;
    bool        drop_table = false;
    bool        create_table = false;
    py11::str py_str_MessageFile;
    py11::str py_str_TempFilesPath;
    int ret = 0;
    MAP_FIELDNAME_DICT map_field_memory_vectors;
    int64_t parquet_num_rows = 0;
    SQLHANDLE hstmt = SQL_NULL_HSTMT;


    if (!PyArg_ParseTuple(args, "OOOiiiiOOOOOOO",
        &py_conn_res,
        &py_MessageFile,
        &py_TempFilesPath,
        &iDataBufferSize,
        &iSavecount,
        &iChunkSize,
        &imax_rows,
        &py_parquet_table,
        &py_tablespace_name,
        &py_schema_name,
        &py_table_name,
        &py_table_column_oriented,
        &py_drop_table,
        &py_create_table))
    {
        PyErr_Format(PyExc_ValueError,
                     "%d %s() %s the function needs 14 parameters",
                     __LINE__, __FUNCTION__,
                     arrow_table_to_db2_docstring.c_str());
        return NULL;
    }

    if (py_MessageFile != Py_None)
    {
        py_str_MessageFile = py11::reinterpret_borrow<py11::str>(py_MessageFile);
        strcpy_s(MessageFile, 255, ((string) py_str_MessageFile).c_str());
    }

    if (py_TempFilesPath != Py_None)
    {
        py_str_TempFilesPath = py11::reinterpret_borrow<py11::str>(py_TempFilesPath);
        strcpy_s(TempFilesPath, 255, ((string) py_str_TempFilesPath).c_str());
    }
    ret = check_parameters(
        py_conn_res,
        &conn_res,
        py_parquet_table,
        &parquet_table,
        py_table_name,
        py_schema_name,
        py_tablespace_name,
        py_table_column_oriented,
        py_drop_table,
        py_create_table,
        table_name,
        schema_name,
        tablespace_name,
        table_column_oriented,
        drop_table,
        create_table
    );
 
    if (ret == -1) // this will provoke Python to notice an exc happened
        return NULL;

    parquet_num_rows = parquet_table->num_rows();
    if (imax_rows > 0)
        if (parquet_num_rows > imax_rows)
            parquet_num_rows = imax_rows;
    
    /*
    LOG_INFO("'%s' '%s' '%s' table_column_oriented %d num_rows  %ld drop_table %d\n", 
        tablespace_name, 
        table_name, 
        schema_name, 
        table_column_oriented, 
        num_rows,
        drop_table);
    */

    // from parquet to STRUCT_DICT
    ret = using_arrow_cpp_api(parquet_table, map_field_memory_vectors);
    if (ret != 0)
    {
        PyErr_Format(PyExc_Exception,
                     "using_arrow_cpp_api failed %d %s() ret = %d",
                     __LINE__,
                     __FUNCTION__,
                     ret);
        return NULL;

    }
    // do the load
    db2LoadOut LoadOut;
    ret = do_the_load_arrow(
        conn_res->henv,
        conn_res->hdbc,
        hstmt,
        map_field_memory_vectors,
        tablespace_name,
        schema_name,
        table_name,
        MessageFile,
        TempFilesPath,
        iDataBufferSize,
        iSavecount,
        iChunkSize,
        table_column_oriented,
        drop_table,
        create_table,
        &LoadOut,
        parquet_num_rows,
        ERROR_VAR_PARAM_1);
    free_MAP_FIELDNAME_DICT(map_field_memory_vectors);

    if (ret != 0)
    {

        SQLRETURN cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
        if (cliRC != 0)
            LOG_INFO("SQLFreeHandle cliRC=%d", cliRC);
        //STMT_HANDLE_CHECK(hstmt, hdbc, cliRC);
        SPCLIENT_ERROR_MESSAGE

    }


    PyDictObject * return_dict = (PyDictObject *)Py_BuildValue("{sLsLsLsLsLsLsL}", // New Reference
        "RowsCommitted", 
        LoadOut.oRowsCommitted,
        "RowsDeleted",
        LoadOut.oRowsDeleted,
        "RowsLoaded",
        LoadOut.oRowsLoaded,
        "RowsRead",
        LoadOut.oRowsRead,
        "RowsSkipped",
        LoadOut.oRowsSkipped,
        "RowsRejected",
        LoadOut.oRowsRejected,
        "bytes_allocated",
        arrow::default_memory_pool()->bytes_allocated());
    //printf("done %d %s()\n", __LINE__, __FUNCTION__);
    return (PYOBJ_PTR )return_dict;

}
