
#include "spclient_python_common_cpp.h"
#include "win32_to_linux.h"
#include "arrow_table_to_db2.h"

using namespace arrow;

//long cont_date = 0;
//int64_t batch = 100000;
//too slow
void datetime64_toTIME(
    py11::handle & _object,
    ARROW_TO_DB2_TIME &t2)
{
    const char *str = ((std::string)(py11::str(_object))).c_str();
    sscanf(str, "%d-%d-%dT%d:%d:%d",
        &t2.year,
        &t2.month,
        &t2.day,
        &t2.hour,
        &t2.min,
        &t2.sec);
    //cont_date++;

    //if ((cont_date % batch) == 0)
    {
        //works
        //LOG_INFO("'%s' '%s'", str, t2.to_string().c_str(), cont_date);
    }

}


void Timestamp_toTIME(
    py11::handle &_object,
    ARROW_TO_DB2_TIME &t2)
{
    const char *str = ((std::string)(py11::str(_object))).c_str();
    sscanf(str, "%d-%d-%d %d:%d:%d",
        &t2.year,
        &t2.month,
        &t2.day,
        &t2.hour,
        &t2.min,
        &t2.sec);
    //cont_date++;

    //if ((cont_date % batch) == 0)
    {
        //works
       // print_mylog_info_format("%d '%s' '%s' %d", __LINE__, str, t2.to_string().c_str(), cont_date);

    }


}



void compare(
    VECT_ARROW_TO_DB2_TIME &test_list,
    VECT_ARROW_TO_DB2_TIME &test_from_pyarrow_array)
{
    unsigned long cont = 0;
    cont = 0;
    int cont_error = 0;
    //error checking
    //print_mylog_info_format("%d %s() start the test test_from_pyarrow_array %zd test_list %zd \n",
    //    __LINE__,
    //    __FUNCTION__,
    //    test_from_pyarrow_array.size(),
    //    test_list.size());
    for (auto const& t2 : test_from_pyarrow_array)
    {
        if (t2 != test_list[cont])
        {
            print_mylog_info_format("error day %ld \n%s\n%s\n",
                cont,
                t2.to_string().c_str(),
                test_list[cont].to_string().c_str());
            cont_error++;
        }
        cont++;
        if (cont_error > 3)
            break;
    }
    if (cont_error == 0)
    {
        print_mylog_info_format("no error test_list %zd", test_list.size());
    }

}



//using py.array.to_pandas
//return a list of numpy.datetime64
// to slowwwwwwwwww
void from_datetime64_to_vector(
    COLUMN &c,
    VECT_ARROW_TO_DB2_TIME &test_list)
{
    ARROW_TO_DB2_TIME t2;
    time_t begin_time, now;
    time(&begin_time);
    int64_t row_count = c->length();
    //batch = row_count / 3;
    PYOBJ_PTR  timestamp_array;
    py11::list list_datetime64_array_pandas; // list of numpy.datetime64

    unsigned long cont = 0;
    bool do_it = true;
    int chunk = 0;
    while (do_it)
    {
        timestamp_array = py::wrap_array(c->chunk(chunk));
        chunk++;
        py11::object py11_datetime64_array = py11::reinterpret_borrow<py11::object>(timestamp_array);
        list_datetime64_array_pandas = py11_datetime64_array.attr("to_pandas")();//// list of numpy.datetime64
        for (auto list_item : list_datetime64_array_pandas) //list_item  numpy.datetime64
        {

            if (cont < 0)
            {
                print_mylog_info_format("each item inside the list %8d '%s' type '%s' \n",
                    cont,
                    ((std::string)(py11::str(list_item))).c_str(),
                    Py_TYPE(list_item.ptr())->tp_name  //numpy.datetime64

                );
            }

            //print_dir(py11::reinterpret_borrow<py11::object>(list_item));

            datetime64_toTIME(list_item, t2);
            test_list.push_back(t2);
            cont++;
            if (cont == row_count)
            {
                //printf("done\n");
                do_it = false;
                break;
            }


        }
    }
    time(&now);
    double seconds = difftime(now, begin_time);

    if (list_datetime64_array_pandas.size() == test_list.size())
        print_mylog_info_format("%d %s()  to_pandas %lf",
            __LINE__,
            __FUNCTION__,
            seconds);
    else
        print_mylog_info_format("%d %s() list_datetime64_array_pandas len %zd test_list %zd time to_pandas %lf",
            __LINE__,
            __FUNCTION__,
            list_datetime64_array_pandas.size(),
            test_list.size(),
            seconds);
}

// using pyarrow.column.to_pandas
// that return a list of pd.Timestamp
// too slow
void from_timestamp_to_vector(
    std::shared_ptr <arrow::Field> &c,
    VECT_ARROW_TO_DB2_TIME &test_list)
{
    PYOBJ_PTR  py_column;
    ARROW_TO_DB2_TIME t2;
    time_t begin_time, now;
    time(&begin_time);

    //int64_t row_count = c->length();
    //batch = row_count / 3;

    py_column = py::wrap_field(c);
    py11::list list_Timestamp_pandas_column = py11::reinterpret_borrow<py11::object>(py_column).attr("to_pandas")();
    //printf("list_Timestamp_pandas_column %zd\n", list_Timestamp_pandas_column.size());//pd.Timestamp

    unsigned long cont = 0;
    //cont_date = 0;
    for (auto list_item : list_Timestamp_pandas_column) //list_item  pd.Timestamp
    {

        if (cont < 3)
        {
            //print_mylog_info_format("each item inside the list %8d '%s' type '%s' \n",
            //    cont,
            //    ((std::string)(py11::str(list_item))).c_str(),
            //    Py_TYPE(list_item.ptr())->tp_name  //pandas._libs.tslibs.timestamps.Timestamp aka pd.Timestamp
            //
            //);
        }

        //print_dir(py11::reinterpret_borrow<py11::object>(list_item));

        Timestamp_toTIME(list_item, t2);
        test_list.push_back(t2);
        cont++;
    }

    time(&now);
    double seconds = difftime(now, begin_time);
    print_mylog_info_format("%d %s() list_Timestamp_pandas_column len %zd test_list %zd time to_pandas %lf",
        __LINE__,
        __FUNCTION__,
        list_Timestamp_pandas_column.size(),
        test_list.size(),
        seconds);

}
