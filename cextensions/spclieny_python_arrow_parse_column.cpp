

#include "parse_arrow_dict.h"
#include "arrow/python/util/datetime.h"
using namespace arrow;
using namespace py11::literals;

void log_dic(
    MY_DICT &dict,
    COLUMN &c,
    int line,
    const char * func_name)
{
    const char* env_log_dic = std::getenv("SPCLIENT_PYTHON_LOG_DIC");
    if (env_log_dic != NULL)
    {
        if (string(env_log_dic) != "1")
            return;
    }
    else
        return;
    std::string size_str;
    std::string arrow_type;
    char buffer[1000] = {};
    arrow_type = my_dict_arrow()[dict.vector_type];
    size_str = "'{:,}'"_s.format(dict.size());
    string field_name = "'{}'"_s.format(c->name());

    snprintf(buffer, sizeof(buffer), "%3d %-15s() %-10s %-15s %-18s dict_size %s chunk counted %d",
        line,
        func_name,
        arrow_type.c_str(),
        c->data()->type()->ToString().c_str(),
        field_name.c_str(),
        size_str.c_str(),
        c->data()->num_chunks());
    print_mylog_info(buffer);
}

void print_string(
    COLUMN &c,
    MY_DICT *dict)
{
    std::shared_ptr<arrow::StringArray> array;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        array = std::static_pointer_cast<StringArray> (c->data()->chunk(chunk));
        for (int64_t i = 0; i < array->length(); i++)
        {
            int32_t  out_length = 0;
            //if (!array->IsNull(i))
            //{
                //const uint8_t*  value = array->GetValue(i, &out_length);
                array->GetValue(i, &out_length);
            //}
            //else
            //{
            //}
            if (out_length > dict->max_size_string)
                dict->max_size_string = out_length;
        }
    }

    char * blank_pads = (char *)malloc(dict->max_size_string);
    if (blank_pads == NULL)
        return;
    memset(blank_pads, 0, dict->max_size_string);

    dict->m_v_8_string.reserve(dict->max_size_string * c->length());
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        array = std::static_pointer_cast<StringArray> (c->data()->chunk(chunk));

        for (int64_t i = 0; i < array->length(); i++)
        {
            int32_t  out_length = 0;
            if (!array->IsNull(i))
            {
                const uint8_t*  value = array->GetValue(i, &out_length);
                dict->m_v_8_string.insert(dict->m_v_8_string.end(),
                                        (char const *)value,
                                        (char const *)value+ out_length);
                //padding with blanks
                dict->m_v_8_string.insert(dict->m_v_8_string.end(),
                    blank_pads,
                    blank_pads + ((int64_t)dict->max_size_string - out_length));
            }
            else
            {
                //insert a max_size_string blank string
                dict->m_v_8_string.insert(dict->m_v_8_string.end(), blank_pads, blank_pads + (dict->max_size_string));
            }
            dict->m_str_lens.push_back(out_length);
        }
    }
    free(blank_pads);

    /*
    size_t start = 0;
    SQLLEN len = 0;
    for (size_t i = 0; i < dict->str_lens.size(); i++)
    {
        len = dict->str_lens[i];
        if ((i < 3) || i > (dict->str_lens.size() - 3))
        {
            char buffer[100] = {};
            memcpy(buffer, dict->m_v_8_string.data() + start, len);
            printf("%zd '%s' %d\n", i, buffer, len);
        }
        start += dict->max_size_string;
    }
    */

    Py_END_ALLOW_THREADS;
    LOG_DICT;

}


void print_binary(
    COLUMN &c,
    MY_DICT *dict)
{
    std::shared_ptr<arrow::BinaryArray> array;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        array = std::static_pointer_cast<BinaryArray> (c->data()->chunk(chunk));
        for (int64_t i = 0; i < array->length(); i++)
        {
            int32_t  out_length = 0;
            if (!array->IsNull(i))
            {
                const uint8_t*  value = array->GetValue(i, &out_length);
            }
            else
            {
            }
            if (out_length > dict->max_size_string)
                dict->max_size_string = out_length;
        }
    }
    char * pad = (char *)malloc(dict->max_size_string);
    memset((void * )pad, 0, dict->max_size_string);

    dict->m_v_8_string.reserve(dict->max_size_string * c->length());
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        array = std::static_pointer_cast<BinaryArray> (c->data()->chunk(chunk));

        for (int64_t i = 0; i < array->length(); i++)
        {
            int32_t  out_length = 0;
            if (!array->IsNull(i))
            {
                const uint8_t*  value = array->GetValue(i, &out_length);
                dict->m_v_8_string.insert(dict->m_v_8_string.end(), 
                                         (char const *)value,
                                         (char const *)value+ out_length);
                if (dict->max_size_string != out_length)
                {
                    dict->m_v_8_string.insert(dict->m_v_8_string.end(),
                                              pad,
                                              pad + ((int64_t)dict->max_size_string - out_length));
                }
            }
            else
            {
                dict->m_v_8_string.insert(dict->m_v_8_string.end(),
                                          pad,
                                          pad + (dict->max_size_string));
            }
            dict->m_str_lens.push_back(out_length);
        }
    }
    free(pad);


    /*
    size_t start=0;
    SQLLEN len = 0;
    for (size_t i = 0; i < dict->str_lens.size(); i++)
    {
        len = dict->str_lens[i];
        if ((i < 3) || i > (dict->str_lens.size()-3))
        {
            char buffer[100] = {};
            memcpy(buffer, dict->m_v_8_string.data() + start, len);
            printf("%zd '%s' %d\n", i, buffer, len);
        }
        start += dict->max_size_string;
    }
    */

    Py_END_ALLOW_THREADS;
    LOG_DICT;

}

void print_int64(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_64 &v_64 = *dict;
    std::shared_ptr<Int64Array> int64_array;


    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        int64_array = std::static_pointer_cast<Int64Array>(c->data()->chunk(chunk));
        const Int64Array::value_type* data0 = int64_array->raw_values();
        v_64.insert(v_64.end(), data0, data0 + int64_array->length());


    }
    Py_END_ALLOW_THREADS;

    LOG_DICT;
}

void print_uint64(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_U64& v_u64 = *dict;
    std::shared_ptr<UInt64Array> uint64_array;


    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        uint64_array = std::static_pointer_cast<UInt64Array>(c->data()->chunk(chunk));
        const UInt64Array::value_type * data0 = uint64_array->raw_values();
        v_u64.insert(v_u64.end(), data0, data0 + uint64_array->length());


    }
    Py_END_ALLOW_THREADS;

    LOG_DICT;
}

void print_date64(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_ARROW_TO_DB2_TIME &v_db2_time = *dict;
    std::shared_ptr<arrow::Date64Array> date64_array;
    chrono::system_clock::time_point tp;
    ARROW_TO_DB2_TIME t1;
    //date64[ms]
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        date64_array = std::static_pointer_cast<Date64Array>(c->data()->chunk(chunk));
        for (int64_t i = 0; i < date64_array->length(); i++)
        {
            arrow::Date64Array::value_type  v = date64_array->raw_values()[i];
            t1.fraction = v % 1000LL;
            tp = chrono::system_clock::time_point(chrono::milliseconds{ v });
            std::time_t now_c = chrono::system_clock::to_time_t(tp);
            std::tm *p_now_tm = std::gmtime(&now_c);
            //printf("p_now_tm %p\n", p_now_tm);
            std::tm now_tm = {};
            if (p_now_tm != NULL)
                now_tm = *p_now_tm;
            else
            {
                t1.clear();
            }
            tm_toTIME(now_tm, t1);

            v_db2_time.push_back(t1);
        }
    }
    Py_END_ALLOW_THREADS;

    LOG_DICT;
}

void print_time32(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_ARROW_TO_DB2_TIME &v = *dict;
    std::shared_ptr<arrow::Time32Array> array;
    ARROW_TO_DB2_TIME t1;
    int unit = 1;
    string type = c->data()->type()->ToString();

    if (type == "time32[us]")
        unit = 1;
    else if (type == "time32[s]")
        unit = 2;

    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        array = std::static_pointer_cast<Time32Array>(c->data()->chunk(chunk));
        chunk++;
        for (int64_t i = 0; i < array->length(); i++)
        {
            arrow::Time32Array::value_type  v_1 = array->raw_values()[i];
            int64_t val;
            int64_t hour;

            int64_t microsecond;
            if (unit == 1)
                microsecond = py::split_time(v_1, 1000, &val) * 1000;
            else
            {
                microsecond = 0;
                val = v_1;
            }

            int64_t second = py::split_time(val, 60, &val);
            int64_t minute = py::split_time(val, 60, &hour);
            t1.year = 1;
            t1.month = 1;
            t1.day = 1;
            t1.hour = (int)hour;
            t1.min = (int)minute;
            t1.sec = (int)second;
            t1.fraction = (unsigned long)microsecond;;
            //if (i < 5)
            //    printf("%s\n", t1.to_string().c_str());
            v.push_back(t1);

        }
    }
    Py_END_ALLOW_THREADS;

    LOG_DICT;
}

void print_time64(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_ARROW_TO_DB2_TIME& v = *dict;
    std::shared_ptr<arrow::Time64Array> time64_array;
    ARROW_TO_DB2_TIME t1;
    int unit = 1;
    string type = c->data()->type()->ToString();

    if (type == "time64[us]")
        unit = 1;
    else if (type == "time64[ns]")
        unit = 2;

    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        time64_array = std::static_pointer_cast<Time64Array>(c->data()->chunk(chunk));
        chunk++;
        for (int64_t i = 0; i < time64_array->length(); i++)
        {
            Time64Array::value_type  v_1 = time64_array->raw_values()[i];
            if (unit == 2)
                v_1 /= 1000;
            int64_t val;
            int64_t hour;
            int64_t microsecond = py::split_time(v_1, 1000000LL, &val);
            int64_t second = py::split_time(val, 60, &val);
            int64_t minute = py::split_time(val, 60, &hour);
            t1.year = 1;
            t1.month = 1;
            t1.day = 1;
            t1.hour = (int)hour;
            t1.min = (int)minute;
            t1.sec = (int)second;
            t1.fraction = (unsigned long)microsecond * 1000;
            //if (i < 5)
            //    printf("ms %s\n", t1.to_string().c_str());
            v.push_back(t1);
            
        }
    }
    Py_END_ALLOW_THREADS;

    LOG_DICT;
}

void print_date32(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_ARROW_TO_DB2_TIME &v_db2_time = *dict;
    std::shared_ptr<arrow::Date32Array> date32_array;
    ARROW_TO_DB2_TIME t1;
    int unit;
    std::string type = c->data()->type()->ToString();

    if (type == "date32[day]")
        unit = 1;
    //else if (type == "timestamp[us]")
    //    unit = 2;
    //else if (type == "timestamp[s]")
    //    unit = 3;
    //else if (type == "timestamp[ns]")
    //    unit = 4;
    else
        printf("error dont what unit for timestamp %s\n", type.c_str());
    //printf("type %s\n", type.c_str());
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        date32_array = std::static_pointer_cast<Date32Array>(c->data()->chunk(chunk));
        for (int64_t i = 0; i < date32_array->length(); i++)
        {

            Date32Array::value_type  v = date32_array->raw_values()[i];
            //printf("%d\n", v);
            int64_t year = 0, month = 0, day = 0;
            py::get_date_from_days(v, &year, &month, &day);
            t1.day = (int)day;
            t1.year = (int)year;
            t1.month = (int)month;
            v_db2_time.push_back(t1);
        }

    }
    Py_END_ALLOW_THREADS;

    LOG_DICT;
}

void print_int32(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_32 &v_32 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<Int32Array> i32_array = std::static_pointer_cast<Int32Array> (c->data()->chunk(chunk));
        const Int32Array::value_type * data0 = i32_array->raw_values();
        v_32.insert(v_32.end(), data0, data0 + i32_array->length());

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;

}

void print_int16(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_16& v_16 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<Int16Array> i16_array = std::static_pointer_cast<Int16Array> (c->data()->chunk(chunk));
        const Int16Array::value_type* data0 = i16_array->raw_values();
        v_16.insert(v_16.end(), data0, data0 + i16_array->length());

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;

}

void print_uint16(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_U16& v_u16 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<UInt16Array> i16_array = std::static_pointer_cast<UInt16Array> (c->data()->chunk(chunk));
        const UInt16Array::value_type* data0 = i16_array->raw_values();
        v_u16.insert(v_u16.end(), data0, data0 + i16_array->length());

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;

}

void print_uint32(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_U32& v_U32 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<UInt32Array> ui32_array = std::static_pointer_cast<UInt32Array> (c->data()->chunk(chunk));
        const UInt32Array::value_type * data0 = ui32_array->raw_values();
        v_U32.insert(v_U32.end(), data0, data0 + ui32_array->length());

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;

}

void print_float(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_FLOAT &f = dict->getFloat();
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<arrow::FloatArray> f_array = std::static_pointer_cast<FloatArray> (c->data()->chunk(chunk));
        const FloatArray::value_type * data0 = f_array->raw_values();
        f.insert(f.end(), data0, data0 + f_array->length());

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;
}

void print_int8(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_8 &v_8 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<arrow::Int8Array> i8_array = std::static_pointer_cast<Int8Array> (c->data()->chunk(chunk));
        const Int8Array::value_type * data0 = i8_array->raw_values();
        v_8.insert(v_8.end(), data0, data0 + i8_array->length());

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;
}

void print_uint8(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_U8& v_8 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<UInt8Array> i8_array = std::static_pointer_cast<UInt8Array> (c->data()->chunk(chunk));
        const UInt8Array::value_type* data0 = i8_array->raw_values();
        v_8.insert(v_8.end(), data0, data0 + i8_array->length());

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;
}

void print_bool(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_8 &v_8 = *dict;

    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<BooleanArray>  bool_array = std::static_pointer_cast<BooleanArray>(c->data()->chunk(chunk));
        for (int64_t i = 0; i < bool_array->length(); i++)
            v_8.push_back(bool_array->Value(i));

    }
    /*
    for (int i = 0; i < v_8.size(); i++)
    {
        bool val = bool_array->Value(i);
        printf("print_bool %d %zd %d\n", v_8[i], v_8.size(), val);
        if (i >= 5)
            break;
    }
    */

    Py_END_ALLOW_THREADS;

    LOG_DICT;
}


void print_double(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_DOUBLE &vd = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<arrow::DoubleArray> double_array = std::static_pointer_cast<DoubleArray> (c->data()->chunk(chunk));
        const DoubleArray::value_type * data0 = double_array->raw_values();
        vd.insert(vd.end(), data0, data0 + double_array->length());
    }
    Py_END_ALLOW_THREADS;

    LOG_DICT;

}


//another idea
//fastest one so far
// convert each TimestampArray value ts_array->raw_values()[i]
// to chrono::system_clock::time_point
// from there to td::time_t now_c = chrono::system_clock::to_time_t(tp);
// from there to std::tm
// from there to ARROW_TO_DB2_TIME
void from_pyarrow_array_std_chrono(
    COLUMN &c,
    VECT_ARROW_TO_DB2_TIME &test_from_pyarrow_array)
{
    ARROW_TO_DB2_TIME t1;
    int unit = 0;
    std::string type = c->data()->type()->ToString();
    std::shared_ptr<arrow::TimestampArray> ts_array;

    if (type == "timestamp[ms]")
        unit = 1;
    else if (type == "timestamp[us]")
        unit = 2;
    else if (type == "timestamp[s]")
        unit = 3;
    else if (type == "timestamp[ns]")
        unit = 4;
    else
        printf("error dont know what unit for timestamp %s\n", type.c_str());

    int64_t num_rows = c->length();
    //printf("unit %s\n", type.c_str());
    bool  do_it = true;
    int chunk = 0;
    int64_t cont = 0;

    chrono::system_clock::time_point tp;
    Py_BEGIN_ALLOW_THREADS;
    while (do_it)
    {

        ts_array = std::static_pointer_cast<TimestampArray> (c->data()->chunk(chunk));
        chunk++;
        for (int64_t i = 0; i < ts_array->length(); i++)
        {
            int64_t    v = ts_array->raw_values()[i];
            switch (unit)
            {
                case 1: 
                {
                    t1.fraction = v % 1000LL;
                    tp = chrono::system_clock::time_point(chrono::milliseconds{ v }); 
                    break;
                }
                case 3:
                {
                    tp = chrono::system_clock::time_point(chrono::seconds{ v }); 
                    break;
                }
                case 2:
                {
                    t1.fraction = v % 1000000LL;
                    tp = chrono::system_clock::time_point(chrono::microseconds{ v });
                    break;
                }
                case 4:
                {    
                    t1.fraction = v % 1000000000LL;
                    //printf("unit %lld\n", v);
                    v = v / 1000LL;
                    tp = chrono::system_clock::time_point(chrono::microseconds{ v });
                    break;
                }
            }
            std::time_t now_c = chrono::system_clock::to_time_t(tp);
            std::tm *p_now_tm = std::gmtime(&now_c);
            std::tm now_tm = {};
            if (p_now_tm != NULL)
                now_tm = *p_now_tm;
            else
            {
                t1.clear();
                if (cont < 5)
                    printf("v %" PRId64 " p_now_tm=NULL\n", v);
            }
            tm_toTIME(now_tm, t1);
            test_from_pyarrow_array.push_back(t1);
            cont++;
            //printf("%s\n", t1.to_string().c_str());
            if (cont == num_rows)
            {
                do_it = false;
                break;
            }
        }
    }
    Py_END_ALLOW_THREADS;

    return;

}


void print_timestamp(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_ARROW_TO_DB2_TIME &test_from_pyarrow_array = *dict;
    //VECT_ARROW_TO_DB2_TIME test_timestamp_list, test_datetime64_list;
    //printf("%s\n", ts_array->ToString().c_str());
    //from_timestamp_to_vector(c, test_timestamp_list);
    //from_datetime64_to_vector(c, test_datetime64_list);
    //compare(test_timestamp_list, test_datetime64_list);
    //print_mylog_info_format("%d %s() type::TIMESTAMP chunks %d",
    //    __LINE__,
    //    __FUNCTION__,
    //    c->data()->num_chunks());
    //print_mylog_info_format("%d %s() type::TIMESTAMP test_timestamp_list %" PRId64 " test_datetime64_list %" PRId64 " chunks %d",
    //    __LINE__, 
    //    __FUNCTION__, 
    //    test_timestamp_list.size(),
    //    test_datetime64_list.size(),
    //    c->data()->num_chunks());
    //return;
    from_pyarrow_array_std_chrono(c, test_from_pyarrow_array);
    LOG_DICT;
    //compare(test_datetime64_list, test_from_pyarrow_array);
}
