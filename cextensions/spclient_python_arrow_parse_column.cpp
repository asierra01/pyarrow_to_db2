

#include "parse_arrow_dict.h"
#include "arrow/python/util/datetime.h"
#include "arrow/util/decimal.h"

#include <algorithm>
using namespace arrow;
using namespace py11::literals;

static int func_registered_set_table_describe_dict = 0;

void register_table_dict()
{
    string set_table_col = R"(
def set_table_describe_dict():
    from texttable import Texttable
    table = Texttable()
    table.set_deco(Texttable.HEADER)
    table.set_header_align(['l','l', 'l', 'l', 'l','l'])
    table.set_cols_dtype(['t',
                         't',
                         't',
                         't',
                         't',
                         't'])
    table.set_cols_align(['l', 'l', 'l', 'l', 'l', 'l'])  
    table.header(['line_no_funcname',
                  'ARROW Type',
                  'name',
                  'column name',
                  'size',
                  'chunks'])
    table.set_cols_width([30, 18, 22, 22, 20, 10])  
 
    return table
)";
    if (func_registered_set_table_describe_dict == 0)
    {

        try
        {
            py11::exec(set_table_col.c_str());
            func_registered_set_table_describe_dict = 1;
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("py::exec  %s", e.what());
            return;
        }
    }

}

py11::object get_table_dict()
{
    py11::object py_set_table_describe_col;
    int err = 0;

    if (func_registered_set_table_describe_dict == 0)
        register_table_dict();

    try
    {
        py_set_table_describe_col = py11::globals()["set_table_describe_dict"];
        py_set_table_describe_col.inc_ref();
        return py_set_table_describe_col();
    }
    catch (py11::error_already_set & e)
    {
        err = 1;
        LOG_INFO("set_table_describe_dict  %s", e.what());

    }

    if (err == 1)
    {
        func_registered_set_table_describe_dict = 0;
        register_table_dict();
        try
        {
            py_set_table_describe_col = py11::globals()["set_table_describe_dict"];
            return py_set_table_describe_col();
        }
        catch (py11::error_already_set & e)
        {
            LOG_INFO("set_table_describe_dict  %s", e.what());
            return py11::cast<py11::none>(Py_None);

        }

    }
    return py11::cast<py11::none>(Py_None);
}

void log_dic(
    MY_DICT &dict,
    COLUMN &c,
    py11::object &py_table,
    int line,
    const char * func_name)
{
    const char* env_log_dic = std::getenv("SPCLIENT_PYTHON_LOG_DIC");
    if (env_log_dic != nullptr)
    {
        if (string(env_log_dic) != "1")
            return;
    }
    else
        return;

    string arrow_type = my_dict_arrow()[dict.vector_type];
    string size_str   = "'{:,}'"_s.format(dict.size());
    string field_name = "'{}'"_s.format(c->name());

    string line_funcname = "{} {}"_s.format(line, func_name);
    py11::list my_row  = py11::reinterpret_borrow<py11::list>(
        Py_BuildValue("[sssssi]",
        line_funcname.c_str(),
        arrow_type.c_str(),
        c->data()->type()->ToString().c_str(),
        field_name.c_str(),
        size_str.c_str(),
        c->data()->num_chunks()));

    if (!py_table.is_none())
        py_table.attr("add_row")(my_row);
    else
        LOG_INFO("py_table is None");
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
                array->GetValue(i, &out_length);
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

}

void print_fixed_size_binary(
    COLUMN& c,
    MY_DICT* dict)
{
    std::shared_ptr<arrow::FixedSizeBinaryArray> array = 
        std::static_pointer_cast<FixedSizeBinaryArray> (c->data()->chunk(0));
    Py_BEGIN_ALLOW_THREADS;
    
    dict->max_size_string = array->byte_width();
    char* pad = (char*)malloc(dict->max_size_string);
    memset((void*)pad, 0, dict->max_size_string);

    dict->m_v_8_string.reserve(dict->max_size_string * c->length());
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        array = std::static_pointer_cast<FixedSizeBinaryArray> (c->data()->chunk(chunk));

        for (int64_t i = 0; i < array->length(); i++)
        {
            if (!array->IsNull(i))
            {
                const uint8_t* value = array->GetValue(i);
                dict->m_v_8_string.insert(dict->m_v_8_string.end(),
                    (char const*)value,
                    (char const*)value + dict->max_size_string);
                
            }
            else
            {
                dict->m_v_8_string.insert(dict->m_v_8_string.end(),
                    pad,
                    pad + (dict->max_size_string));
            }
            dict->m_str_lens.push_back(dict->max_size_string);
        }
    }
    free(pad);

    Py_END_ALLOW_THREADS;

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

}

void print_date64(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_ARROW_TO_DB2_TIME &v_db2_time = *dict;
    std::shared_ptr<arrow::Date64Array> date64_array;
    chrono::system_clock::time_point tp;
    ARROW_TO_DB2_TIME t1;
    v_db2_time.reserve(c->length());
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

}

void print_time32(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_ARROW_TO_DB2_TIME &v = *dict;
    std::shared_ptr<arrow::Time32Array> array;
    ARROW_TO_DB2_TIME t1;
    TimeUnit::type unit = TimeUnit::SECOND;
    string type = c->data()->type()->ToString();
    v.reserve(c->length());
    if (type == "time32[ms]")
        unit = TimeUnit::MILLI;
    else if (type == "time32[s]")
        unit = TimeUnit::SECOND;

    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        array = std::static_pointer_cast<Time32Array>(c->data()->chunk(chunk));
        for (int64_t i = 0; i < array->length(); i++)
        {
            arrow::Time32Array::value_type  v_1 = array->raw_values()[i];
            int64_t val;
            int64_t hour;

            int64_t microsecond;
            if (unit == TimeUnit::MILLI)
                microsecond = py::split_time(v_1, 1000, &val) * 1000;
            else // TimeUnit::SECOND
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

}

void print_time64(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_ARROW_TO_DB2_TIME& v = *dict;
    std::shared_ptr<arrow::Time64Array> time64_array;
    ARROW_TO_DB2_TIME t1;
    TimeUnit::type unit = TimeUnit::MICRO;
    string type = c->data()->type()->ToString();
    v.reserve(c->length());
    if (type == "time64[us]")
        unit = TimeUnit::MICRO;
    else if (type == "time64[ns]")
        unit = TimeUnit::NANO;

    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        time64_array = std::static_pointer_cast<Time64Array>(c->data()->chunk(chunk));
        chunk++;
        for (int64_t i = 0; i < time64_array->length(); i++)
        {
            Time64Array::value_type  v_1 = time64_array->raw_values()[i];

            if (unit == TimeUnit::NANO)
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
    v_db2_time.reserve(c->length());
    if (type == "date32[day]")
        unit = 1;
    else
        printf("error dont what unit for date32 %s\n", type.c_str());
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

}

void print_int32(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_32 &v_32 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<Int32Array> i32_array = 
            std::static_pointer_cast<Int32Array> (c->data()->chunk(chunk));
        const Int32Array::value_type * data0 = i32_array->raw_values();
        v_32.insert(v_32.end(), data0, data0 + i32_array->length());

    }
    Py_END_ALLOW_THREADS;

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

}

void print_uint16(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_U16& v_u16 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<UInt16Array> i16_array = 
            std::static_pointer_cast<UInt16Array> (c->data()->chunk(chunk));
        const UInt16Array::value_type* data0 = i16_array->raw_values();
        v_u16.insert(v_u16.end(), data0, data0 + i16_array->length());

    }
    Py_END_ALLOW_THREADS;

}

void print_uint32(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_U32& v_U32 = *dict;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<UInt32Array> ui32_array = 
            std::static_pointer_cast<UInt32Array> (c->data()->chunk(chunk));
        const UInt32Array::value_type * data0 = ui32_array->raw_values();
        v_U32.insert(v_U32.end(), data0, data0 + ui32_array->length());

    }
    Py_END_ALLOW_THREADS;

}

void print_float(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_FLOAT &f = dict->getFloat();
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<arrow::FloatArray> f_array = 
            std::static_pointer_cast<FloatArray> (c->data()->chunk(chunk));
        const FloatArray::value_type * data0 = f_array->raw_values();
        f.insert(f.end(), data0, data0 + f_array->length());

    }
    Py_END_ALLOW_THREADS;
}

void print_half_float(
    COLUMN &c,
    MY_DICT *dict)
{
    VECT_FLOAT &f = dict->getFloat();
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<arrow::HalfFloatArray> f_array =
            std::static_pointer_cast<HalfFloatArray> (c->data()->chunk(chunk));
        const HalfFloatArray::value_type * data0 = f_array->raw_values();
        f.insert(f.end(), data0, data0 + f_array->length());

    }
    Py_END_ALLOW_THREADS;
}

/*
void print_decimal_doesnt_work(
    COLUMN& c,
    MY_DICT* dict)
{
    VECT_DEC128& v = dict->getVectorDec128();
    bool log = false;
    const char* env_log_dic = std::getenv("SPCLIENT_PYTHON_LOG_DIC_DECIMAL");
    if (env_log_dic != nullptr)
    {
        if (string(env_log_dic) == "1")
            log = true;
    }
    dict->m_v_8_string.reserve(dict->ColDef * c->length());
    Py_BEGIN_ALLOW_THREADS;
    char hex[] = "0123456789ABCDEF";
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<arrow::Decimal128Array> f_array =
            std::static_pointer_cast<arrow::Decimal128Array> (c->data()->chunk(chunk));
        dict->max_size_string = f_array->byte_width(); //16
        SQL_NUMERIC_STRUCT val1 = {};
        for (int64_t i = 0; i < f_array->length(); i++)
        {
            memset(val1.val, 0, SQL_MAX_NUMERIC_LEN);
            val1.precision = dict->ColDef;
            val1.scale = dict->Scale;
            Decimal128 value(f_array->GetValue(i));
            //value = (uint64_t)1234567890123456789;

            // 
            Decimal128 value_original = value;
            Decimal128 result = -1;
            Decimal128 remainder;
            int pos = 0;
            char hexbuffer[30] = {};
            char finalhex[30] = {};
            const Decimal128 divisor = 16;
            while (result != 0)
            {
                arrow::Status OK = value.Divide(divisor, &result, &remainder);
                value = result;
                //printf("result %s remainder %s \n" , 
                //    result.ToIntegerString().c_str(),
                //    remainder.ToIntegerString().c_str());
                int64_t in64 = (int64_t)remainder;
                if (in64 < 0)
                    in64 = std::abs(in64);
                hexbuffer[pos] = hex[in64];
                pos++;
            }
            //printf("2 '%s'\n", hexbuffer);
            SQLLEN len = strlen(hexbuffer);
            if ((len % 2) == 1)
            {
                //printf("len is not par\n");
                strcat(hexbuffer, "0");
                len++;
            }
            int k = 0;
            for (int j = len - 1; j >= 0; j--)
            {
                finalhex[k] = hexbuffer[j];
                k++;
            }
            //printf("2 '%s' '%s'\n", finalhex, hexbuffer);
            int x = (len + 1) / 2;
            for (int j = 0; j < len; j++)
            {

                char high_nimble;
                char low_nimble;

                high_nimble = finalhex[j] - 0x30;
                if (high_nimble > 9)
                {
                    high_nimble -= 7;
                }
                low_nimble = finalhex[j + 1] - 0x30;
                if (low_nimble > 9)
                {
                    low_nimble -= 7;
                }

                char hex_v = (high_nimble << 4) | low_nimble;
                val1.val[x - 1] = hex_v;
                x--;
                j++;
            }
            x = (len + 1) / 2;
            if (value.Sign() == 1)
                val1.sign = (SQLCHAR)1;
            else
                val1.sign = (SQLCHAR)0;

            v.push_back(val1);
            string str = f_array->FormatValue(i);
            len = strlen(str.c_str());
            dict->m_str_lens.push_back(len);
            dict->m_v_8_string.insert(dict->m_v_8_string.end(),
                str.c_str(),
                str.c_str() + len);
            for (int i = 0; i < dict->ColDef - len; i++)
            {
                dict->m_v_8_string.push_back('\0');
            }
            if (log)
            {
                printf("value_original '%s' hexbuffer 0x%s len %zd  ",
                    value_original.ToIntegerString().c_str(),
                    finalhex,
                    strlen(finalhex));
                printf("val1.val len 0...%d %s\n", x - 1, f_array->FormatValue(i).c_str());
            }

        }

    }
    Py_END_ALLOW_THREADS;
    LOG_DICT;
    LOG_INFO("%d", dict->m_v_8_string.size());
    for (int i = 0; i < v.size(); i++)
    {
        LOG_INFO("%s", dict->m_v_8_string.data() + (i * dict->ColDef));
    }

}
*/

void print_decimal(
    COLUMN& c,
    MY_DICT* dict)
{
    bool log = false;
    const char* env_log_dic = std::getenv("SPCLIENT_PYTHON_LOG_DIC_DECIMAL");
    if (env_log_dic != nullptr)
    {
        if (string(env_log_dic) == "1")
            log = true;
    }

    dict->m_v_8_string.reserve(MAX_DIGITS  * c->length());
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {
        std::shared_ptr<arrow::Decimal128Array> f_array =
            std::static_pointer_cast<arrow::Decimal128Array> (c->data()->chunk(chunk));
        //dict->max_size_string = f_array->byte_width(); //16
        for (int64_t i = 0; i < f_array->length(); i++)
        {
            
            string str = f_array->FormatValue(i);
            SQLLEN len = (SQLLEN)str.length();
            dict->m_str_lens.push_back(len);
            dict->m_v_8_string.insert(dict->m_v_8_string.end(), 
                                      str.c_str(),
                                      str.c_str()+len );
            if (len< MAX_DIGITS)
            for (int j = 0; j < MAX_DIGITS - len; j++)
            {
                dict->m_v_8_string.push_back('\0');
            }
            //if (i < 8)
            //    printf("%-40s %-40s %d\n", dict->m_v_8_string.data() + (i * MAX_DIGITS), str.c_str(), len);
        }

    }
    Py_END_ALLOW_THREADS;
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
    Py_END_ALLOW_THREADS;

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

}


void from_pyarrow_array_std_chrono(
    COLUMN &c,
    VECT_ARROW_TO_DB2_TIME &test_from_pyarrow_array)
{
    ARROW_TO_DB2_TIME t1;
    TimeUnit::type unit = TimeUnit::MILLI;;
    std::string type = c->data()->type()->ToString();
    std::shared_ptr<arrow::TimestampArray> ts_array;

    if (type == "timestamp[ms]")
        unit = TimeUnit::MILLI;
    else if (type == "timestamp[us]")
        unit = TimeUnit::MICRO;
    else if (type == "timestamp[s]")
        unit = TimeUnit::SECOND;
    else if (type == "timestamp[ns]")
        unit = TimeUnit::NANO;
    else
        printf("error dont know what unit for timestamp %s\n", type.c_str());

    int64_t cont = 0;

    chrono::system_clock::time_point tp;
    Py_BEGIN_ALLOW_THREADS;
    for (int chunk = 0; chunk < c->data()->num_chunks(); chunk++)
    {

        ts_array = std::static_pointer_cast<TimestampArray> (c->data()->chunk(chunk));
        for (int64_t i = 0; i < ts_array->length(); i++)
        {
            int64_t    v = ts_array->raw_values()[i];
            switch (unit)
            {
                case TimeUnit::MILLI:
                {
                    t1.fraction = v % 1000LL;
                    tp = chrono::system_clock::time_point(chrono::milliseconds{ v }); 
                    break;
                }
                case TimeUnit::SECOND:
                {
                    tp = chrono::system_clock::time_point(chrono::seconds{ v }); 
                    break;
                }
                case TimeUnit::MICRO:
                {
                    t1.fraction = v % 1000000LL;
                    tp = chrono::system_clock::time_point(chrono::microseconds{ v });
                    break;
                }
                case TimeUnit::NANO:
                {    
                    t1.fraction = v % 1000000000LL;
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
                cont++;
                if (cont < 5)
                    printf("v %" PRId64 " p_now_tm=NULL\n", v);
            }
            tm_toTIME(now_tm, t1);
            test_from_pyarrow_array.push_back(t1);
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
    from_pyarrow_array_std_chrono(c, test_from_pyarrow_array);
}
