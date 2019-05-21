
#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"

struct_arrow_to_db2_time::struct_arrow_to_db2_time()
{
    day = 0;
    month = 0;
    year = 0;
    hour = 0;
    min = 0;
    sec = 0;
    fraction = 0;
}

void struct_arrow_to_db2_time::clear()
{
    day = 0;
    month = 0;
    year = 0;
    hour = 0;
    min = 0;
    sec = 0;
    fraction = 0;
}

std::string struct_arrow_to_db2_time::to_string_as_date() const
{
    char buffer[100];
#ifdef WIN32
    _snprintf_s(buffer, 100, 100,
#else
    snprintf(buffer, 100,
#endif
        "%04d-%02d-%02d", year, month, day);

    return buffer;
}

std::string struct_arrow_to_db2_time::to_string_as_time() const
{
    char buffer[100];
#ifdef WIN32
    _snprintf_s(buffer, 100, 100,
#else
    snprintf(buffer, 100,
#endif
        "%02d:%02d:%02d:%-6ld", hour, min, sec, fraction);

    return buffer;
}

std::string struct_arrow_to_db2_time::to_string() const
{
    char buffer[100];
#ifdef WIN32
    _snprintf_s(buffer, 100, 100,
#else
    snprintf(buffer, 100,
#endif
        "%04d-%02d-%02d %02d:%02d:%02d:%-6ld", year, month, day, hour, min, sec, fraction);

    return buffer;
}

void tm_toTIME(
    std::tm tm,
    ARROW_TO_DB2_TIME &t1)
{
    t1.year = tm.tm_year + 1900;
    t1.month = tm.tm_mon + 1;
    t1.day = tm.tm_mday;

    t1.hour = tm.tm_hour;
    t1.min = tm.tm_min;
    t1.sec = tm.tm_sec;
}


bool struct_arrow_to_db2_time::operator != (const  struct_arrow_to_db2_time& rhs) const
{
    return !(*this == rhs);
}

ostream& operator<<(ostream& os, const struct_arrow_to_db2_time& struct_t)
{
    os << struct_t.to_string();
    return os;
}

void MY_DICT::TimeToSQL_TIMESTAMP_STRUCT(
    size_t j,
    const ARROW_TO_DB2_TIME &item1)
{
    SQL_TIMESTAMP_STRUCT & p = *((SQL_TIMESTAMP_STRUCT *)m_data_time + j);

    p.year = item1.year;
    p.month = item1.month;
    p.day = item1.day;
    p.hour = item1.hour;
    p.minute = item1.min;
    p.second = item1.sec;
    p.fraction = item1.fraction;
}

void MY_DICT::TimeToSQL_DATE_STRUCT(
    size_t j,
    const ARROW_TO_DB2_TIME &item1)
{
    SQL_DATE_STRUCT & p = *((SQL_DATE_STRUCT *)m_data_time + j);

    p.year = item1.year;
    p.month = item1.month;
    p.day = item1.day;
}

void MY_DICT::TimeToTIME_STRUCT(
    size_t j, 
    const ARROW_TO_DB2_TIME &item1)
{
    TIME_STRUCT & p = *((TIME_STRUCT *)m_data_time + j);
    p.hour = item1.hour;
    p.minute = item1.min;
    p.second = item1.sec;
}

void MY_DICT::fill_date32()
{
    VECT_ARROW_TO_DB2_TIME & v_Time = getVectorTime();
    size_t vector_size = v_Time.size();
    m_data_time = (SQL_DATE_STRUCT *)calloc(vector_size, sizeof(SQL_DATE_STRUCT));
    size_t j = 0;
    for (const ARROW_TO_DB2_TIME &item1 : v_Time)
    {
        TimeToSQL_DATE_STRUCT(j, item1);
        j++;
    }
}

void MY_DICT::fill_date64()
{
    VECT_ARROW_TO_DB2_TIME & v_Time = getVectorTime();
    size_t vector_size = v_Time.size();
    m_data_time = (SQL_DATE_STRUCT *)calloc(vector_size, sizeof(SQL_DATE_STRUCT));
    size_t j = 0;
    for (const ARROW_TO_DB2_TIME &item1 : v_Time)
    {
        TimeToSQL_DATE_STRUCT(j, item1);
        j++;
    }
}

void MY_DICT::fill_timestamp()
{
    VECT_ARROW_TO_DB2_TIME & v_Time = getVectorTime();
    size_t vector_size = v_Time.size();
    m_data_time = (SQL_TIMESTAMP_STRUCT *)calloc(vector_size, sizeof(SQL_TIMESTAMP_STRUCT));
    size_t j = 0;
    for (const ARROW_TO_DB2_TIME &item1 : v_Time)
    {
        TimeToSQL_TIMESTAMP_STRUCT(j, item1);
        j++;
    }
}

void MY_DICT::fill_time()
{
    size_t vector_size = getVectorTime().size();
    m_data_time = (TIME_STRUCT *)calloc(vector_size, sizeof(TIME_STRUCT));
    size_t j = 0;
    for (const ARROW_TO_DB2_TIME &item1 : getVectorTime())
    {
        TimeToTIME_STRUCT(j, item1);
        j++;
    }
}




