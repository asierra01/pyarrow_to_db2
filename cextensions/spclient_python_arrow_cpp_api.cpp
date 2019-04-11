
#include "spclient_python_common_cpp.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"
#include "win32_to_linux.h"
#include "arrow_table_to_db2.h"
#include "parse_arrow_dict.h"

using namespace arrow;
using namespace py11::literals;


PyObject* pyarrow_parquet = NULL;
PyObject* pyarrow = NULL;
PyObject* numpy = NULL;
py11::module py_np;
static int initialized = 0;


void load_pyarrow()
{
    if (initialized == 0)
    {
        initialized = 1;
        int ret = arrow::py::import_pyarrow();
        if (ret != 0)
            printf("error arrow::py::import_pyarrow %d\n", ret);
        if (pyarrow == NULL)
        {
            pyarrow = PyImport_ImportModule("pyarrow"); //New reference.
            //printf("pyarrow         %p\n", pyarrow);
        }

        if (pyarrow_parquet == NULL)
        {
            pyarrow_parquet = PyImport_ImportModule("pyarrow.parquet"); //New reference.
            //printf("pyarrow_parquet %p\n", pyarrow_parquet);
        }
        numpy = PyImport_ImportModule("numpy");
        py_np = py11::reinterpret_borrow<py11::module>(numpy);
        //print_mylog_info_format("all loaded");
    }

}

void print_column_name(COLUMN& c)
{
    LOG_INFO("column name '%-16s' ", c->name().c_str());

}

void print_column(COLUMN& c)
{
    LOG_INFO("column name '%-16s'  column data null_count %lld length %lld num_chunks %d type '%-15s' name '%-13s' id '%d'",
        c->name().c_str(),
        c->null_count(),
        c->length(),
        c->data()->num_chunks(),
        c->data()->type()->ToString().c_str(),
        c->data()->type()->name().c_str(),
        c->data()->type()->id());

}


int using_arrow_cpp_api(
    TABLE& parquet_table,
    MAP_FIELDNAME_DICT& map_field_memory_vectors)
{
    COLUMN c;

    for (int i = 0; i < parquet_table->num_columns(); i++)
    {
        c = parquet_table->column(i);
        //print_column(c);
        //print_column_name(c);
        try
        {
            MY_DICT* dict = new MY_DICT(
                c->data()->type()->id(),
                c->name(),
                c->data()->type()->ToString());
            map_field_memory_vectors[c->name().c_str()] = dict;

            switch (c->data()->type()->id())
            {
            case arrow::Type::INT64:
            {
                print_int64(c, dict);
                break;
            }
            case arrow::Type::UINT64:
            {
                print_uint64(c, dict);
                break;
            }
            case arrow::Type::BOOL:
            {
                print_bool(c, dict);
                break;
            }
            case arrow::Type::DOUBLE:
            {
                print_double(c, dict);
                break;
            }
            case arrow::Type::INT32:
            {
                print_int32(c, dict);
                break;
            }
            case arrow::Type::UINT32:
            {
                print_uint32(c, dict);
                break;
            }
            case arrow::Type::INT8:
            {
                print_int8(c, dict);
                break;
            }
            case arrow::Type::UINT8:
            {
                print_uint8(c, dict);
                break;
            }

            case arrow::Type::INT16:
            {
                print_int16(c, dict);
                break;
            }
            case arrow::Type::UINT16:
            {
                print_uint16(c, dict);
                break;
            }
            case arrow::Type::STRING:
            {
                print_string(c, dict);
                break;
            }
            case arrow::Type::BINARY:
            {
                print_binary(c, dict);
                break;
            }
            case arrow::Type::DATE64:
            {
                print_date64(c, dict);
                break;
            }
            case arrow::Type::TIME64:
            {
                print_time64(c, dict);
                break;
            }
            case arrow::Type::DATE32:
            {
                print_date32(c, dict);
                break;
            }
            case arrow::Type::TIME32:
            {
                print_time32(c, dict);
                break;
            }
            case arrow::Type::TIMESTAMP:
            {
                print_timestamp(c, dict);
                break;
            }
            case arrow::Type::FLOAT:
            {
                print_float(c, dict);
                break;
            }
            default:
            {
                print_mylog_info_format("%d %s() unknow type %d '%s'",
                    __LINE__,
                    __FUNCTION__,
                    c->data()->type()->id(),
                    my_dict_arrow()[c->data()->type()->id()].c_str());
                return -1;

            }

            }
            //printf("dict size %zd\n", dict->size());
        }
        catch (py11::error_already_set & e)
        {
            char buffer[500];
            snprintf(buffer, 500, "error_already_set  '%s'\n", e.what());
            LOG_INFO("%s", buffer);
            return -1;
        }

    }
    const char* env_log_dic = std::getenv("SPCLIENT_PYTHON_LOG_DIC");
    if (env_log_dic != NULL)
    {
        if (string(env_log_dic) == "1")
            LOG_INFO("done");
    }
    return 0;
    //print_mylog_info_format("%d %s() done", __LINE__, __FUNCTION__);
}
