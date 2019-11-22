
#include "spclient_python_common_cpp.h"
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include "numpy/arrayobject.h"
#include "win32_to_linux.h"
#include "arrow_table_to_db2.h"
#include "parse_arrow_dict.h"

using namespace arrow;
using namespace py11::literals;


PyObject * pyarrow_parquet = NULL;
PyObject * pyarrow = NULL;
PyObject * numpy = NULL;
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
            pyarrow = PyImport_ImportModule("pyarrow"); //New reference.

        if (pyarrow_parquet == NULL)
            pyarrow_parquet = PyImport_ImportModule("pyarrow.parquet"); //New reference.

        numpy = PyImport_ImportModule("numpy");
        py_np = py11::reinterpret_borrow<py11::module>(numpy);
    }

}

void print_column_name(char * name)
{
    LOG_INFO("column name '%-16s' ", name);

}

void print_column(COLUMN &c, char * name)
{
    LOG_INFO("column name '%-16s'  column data null_count %lld length %lld num_chunks %d type '%-15s' name '%-13s' id '%d'",
        name,
        c->null_count(),
        c->length(),
        c->num_chunks(),
        c->type()->ToString().c_str(),
        c->type()->name().c_str(),
        c->type()->id());

}


int using_arrow_cpp_api(
    TABLE &parquet_table,
    MAP_FIELDNAME_DICT &map_field_memory_vectors)
{
    COLUMN c;
    py11::object py_table;
    bool log = false;
    const char* env_log_dic = std::getenv("SPCLIENT_PYTHON_LOG_DIC");
    if (env_log_dic != nullptr)
    {
        if (string(env_log_dic) == "1")
            log=true;
    }

    if (log)
        py_table = get_table_dict();

    for (int i = 0; i < parquet_table->num_columns(); i++)
    {
        c = parquet_table->column(i);
        string column_name = parquet_table->ColumnNames()[i];
        //if (log)
        //    print_column(c);
        //if (log)
        //print_column_name(c);
        try
        {
            MY_DICT * dict = new MY_DICT(
                c->type()->id(), 
                column_name,
                c->type()->ToString());
            map_field_memory_vectors[column_name.c_str()] = dict;

            //if (log)
            //    LOG_INFO("column type '%s'", c->data()->type()->ToString().c_str());

            switch (c->type()->id())
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
                case arrow::Type::FIXED_SIZE_BINARY:
                {
                    print_fixed_size_binary(c, dict);
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
                case arrow::Type::HALF_FLOAT:
                {
                    print_half_float(c, dict);
                    break;
                }
                case arrow::Type::DECIMAL:
                {
                    print_decimal(c, dict);
                    break;
                }
                default:
                {
                    print_mylog_info_format("%d %s() unknow type %d '%s'", 
                        __LINE__,
                        __FUNCTION__,
                        c->type()->id(),
                        my_dict_arrow()[c->type()->id()].c_str());
                    return -1;

                }

            }
            log_dic(*dict, c, py_table, __LINE__, __FUNCTION__);

            //printf("dict size %zd\n", dict->size());
        }
        catch (py11::error_already_set &e)
        {
            char buffer[500];
            snprintf(buffer, 500, "%d %s() error_already_set  '%s'\n",
                     __LINE__,
                     __FUNCTION__,
                     e.what());
            LOG_INFO("%s", buffer);
            return -1;
        }

    }
    if (log)
    {
        py11::str ret = py_table.attr("draw")();
        LOG_INFO("dict \n%s\n", ((string)ret).c_str());

        LOG_INFO("done");
    }
    return 0;

}
