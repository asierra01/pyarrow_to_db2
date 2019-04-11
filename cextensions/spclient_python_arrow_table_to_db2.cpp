

#include <parquet/exception.h>
#include "arrow_table_to_db2.h"


int check_parameters(
    PYOBJ_PTR py_conn_res,
    conn_handle * * conn_res,
    PYOBJ_PTR py_parquet_table,
    TABLE       * parquet_table,
    PYOBJ_PTR py_table_name,
    PYOBJ_PTR py_schema_name,
    PYOBJ_PTR py_tablespace_name,
    PYOBJ_PTR py_table_column_oriented,
    PYOBJ_PTR py_drop_table,
    char * table_name,
    char * schema_name,
    char * tablespace_name,
    bool& table_column_oriented,
    bool& drop_table
)
{
    PYOBJ_PTR py_str_table_name = NULL;
    PYOBJ_PTR py_str_schema_name = NULL;
    PYOBJ_PTR py_str_tablespace_name = NULL;
    if (py_conn_res == NULL)
    {
        PyErr_Format(PyExc_TypeError,
            "Supplied conn object Parameter is NULL  '%s' it should be ibm_db.IBM_DBConnection %s",
            Py_TYPE(py_conn_res)->tp_name,
            arrow_table_to_db2_docstring.c_str());
        return -1;
    }

    if (strcmp(Py_TYPE(py_conn_res)->tp_name, "ibm_db.IBM_DBConnection") != 0)
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
#if PY_MAJOR_VERSION == 2
        py_str_table_name = PyObject_Str(py_table_name); //Return value: New reference.
#else
        py_str_table_name = PyUnicode_AsEncodedString(py_table_name, "utf-8", "~E~"); //Return value: New reference.
#endif
        strcpy_s(table_name, 255, PyBytes_AS_STRING(py_str_table_name));
    }

    if (py_schema_name != Py_None)
    {
#if PY_MAJOR_VERSION == 2
        py_str_schema_name = PyObject_Str(py_table_name); //Return value: New reference.
#else
        py_str_schema_name = PyUnicode_AsEncodedString(py_schema_name, "utf-8", "~E~"); //Return value: New reference.
#endif
        strcpy_s(schema_name, 255, PyBytes_AS_STRING(py_str_schema_name));
    }

    if (py_tablespace_name != Py_None)
    {
#if PY_MAJOR_VERSION == 2
        py_str_schema_name = PyObject_Str(py_table_name); //Return value: New reference.
#else
        py_str_tablespace_name = PyUnicode_AsEncodedString(py_tablespace_name, "utf-8", "~E~"); //Return value: New reference.
#endif
        strcpy_s(tablespace_name, 255, PyBytes_AS_STRING(py_str_tablespace_name));
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
        LOG_INFO("ParquetException %s \n", e.what());
        PyErr_Format(PyExc_Exception, e.what());
        return -1;
    }
    Py_XDECREF(py_str_table_name);
    Py_XDECREF(py_str_schema_name);
    Py_XDECREF(py_str_tablespace_name);
    return 0;
}

/*  wrapped python_arrow_table_to_db2 function but now consuming ibm_db.IBM_DBConnection and pyarrow.lib.table */
PYOBJ_PTR  python_arrow_table_to_db2(
    PYOBJ_PTR  self, 
    PYOBJ_PTR  args)
{
    char table_name[255] = {};
    char schema_name[255] = {};
    char tablespace_name[255] = {};
    char * MESSAGE_FILE_ONE_BIG_CSV = nullptr;
    db2Uint32 iDataBufferSize = 0;
    db2Uint32 iSavecount = 0;
    db2Uint32 iChunkSize = 0;
    PYOBJ_PTR py_table_name = NULL;
    PYOBJ_PTR py_schema_name = NULL;
    PYOBJ_PTR py_tablespace_name = NULL;
    PYOBJ_PTR py_table_column_oriented = NULL;
    PYOBJ_PTR py_conn_res = NULL;
    PYOBJ_PTR py_parquet_table = NULL;
    PYOBJ_PTR py_drop_table = NULL;
    conn_handle * conn_res = NULL;
    TABLE       parquet_table;
    bool        table_column_oriented = false;
    bool        drop_table = false;
    int ret = 0;
    MAP_FIELDNAME_DICT map_field_memory_vectors;
    int64_t num_rows = 0;

    if (!PyArg_ParseTuple(args, "OsiiiOOOOOOO",
        &py_conn_res,
        &MESSAGE_FILE_ONE_BIG_CSV,
        &iDataBufferSize,
        &iSavecount,
        &iChunkSize,
        &mylog_info,
        &py_parquet_table,
        &py_tablespace_name,
        &py_schema_name,
        &py_table_name,
        &py_table_column_oriented,
        &py_drop_table))
    {
        PyErr_Format(PyExc_ValueError,
                     "%d %s() %s the function needs 12 parameters '%s'",
                     __LINE__, __FUNCTION__,
                     arrow_table_to_db2_docstring.c_str(),
                     "yes 12 parameters");
        return NULL;
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
        table_name,
        schema_name,
        tablespace_name,
        table_column_oriented,
        drop_table
    );
    if (ret == -1) // this will provoke python to notice en exc happened
        return NULL;

    num_rows = parquet_table->num_rows();
    
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
    //LOG_INFO("iDataBufferSize %ld iSavecount %ld", iDataBufferSize, iSavecount);
    ret = do_the_load_arrow_to_one_big_csv(
        conn_res->henv,
        conn_res->hdbc,
        map_field_memory_vectors,
        tablespace_name,
        schema_name,
        table_name,
        MESSAGE_FILE_ONE_BIG_CSV,
        iDataBufferSize,
        iSavecount,
        iChunkSize,
        table_column_oriented,
        drop_table,
        &LoadOut,
        num_rows);

    if (ret != 0)
    {
        PyErr_Format(PyExc_Exception,
                     "do_the_load_arrow_to_one_big_csv failed %d %s() ret=%d",
                     __LINE__,
                     __FUNCTION__,
                     ret);
        return NULL;

    }
    free_MAP_FIELDNAME_DICT(map_field_memory_vectors);


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