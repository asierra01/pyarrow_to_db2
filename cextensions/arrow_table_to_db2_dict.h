
#include <stdint.h>
#include <arrow/python/pyarrow.h>
#include <arrow/status.h>
#include <arrow/table.h>
#include "spclient_python_common_cpp.h"

struct struct_arrow_to_db2_time
{
    int day;
    int month;
    int year;
    int hour;
    int min;
    int sec;
    unsigned long fraction;

    struct_arrow_to_db2_time();

    ~struct_arrow_to_db2_time()
    {

    }

    void clear();

    bool operator == (const  struct_arrow_to_db2_time& rhs) const
    {

        if ((day == rhs.day) &&
            (hour == rhs.hour) &&
            (min == rhs.min) &&
            (year == rhs.year) &&
            (month == rhs.month) &&
            (day == rhs.day) &&
            (fraction == rhs.fraction))
            return true;

        return false;
    }

    bool operator != (const  struct_arrow_to_db2_time & rhs) const;
    std::string to_string() const;
    std::string to_string_as_date() const;
    std::string to_string_as_time() const;
    friend ostream & operator<<(ostream & os, const struct_arrow_to_db2_time & struct_t);

};

typedef struct struct_arrow_to_db2_time ARROW_TO_DB2_TIME;

//typedef std::vector<SQL_NUMERIC_STRUCT> VECT_DEC128;
typedef std::vector<int64_t> VECT_64;
typedef std::vector<uint64_t> VECT_U64;
typedef std::vector<double> VECT_DOUBLE;
typedef std::vector<float> VECT_FLOAT;
typedef std::vector<int8_t> VECT_8;
typedef std::vector<uint8_t> VECT_U8;
typedef std::vector<int32_t> VECT_32;
typedef std::vector<int16_t> VECT_16;
typedef std::vector<uint16_t> VECT_U16;
typedef std::vector<uint32_t> VECT_U32;
typedef std::vector<ARROW_TO_DB2_TIME> VECT_ARROW_TO_DB2_TIME;


class MY_DICT
{
public:
    // this is only used when field is time ralated
    // I need to convert arrow time to these structures
    // SQL_TIMESTAMP_STRUCT * or  SQL_DATE_STRUCT * or TIME_STRUCT *  
    SQLPOINTER m_data_time = nullptr;

    //std::vector<int64_t or int8_t or double or TEST_TIME>
    //depends on vector_type
    void* m_vector = NULL;

    int ColDef;
    int Scale;

    //experimental
    //std::shared_ptr< void > vector1

    string type_string;
    string field_name;
    int32_t max_size_string = 0;

    //this is used for string array or binary array
    std::vector<uint8_t> m_v_8_string;

    // sizes of each string.or object being passed..db2/odbc SQLBindParameter needs these sizes 
    std::vector<SQLLEN>  m_str_lens;

    arrow::Type::type  vector_type = arrow::Type::type::NA;
    friend ostream& operator<<(ostream& os, MY_DICT& str_d);
    string to_string(size_t i);
    size_t size1();//experimental

    //VECT_DEC128& getVectorDec128();
    VECT_DOUBLE& getVectorDouble();
    VECT_64& getVector64();
    VECT_U64& getVectorU64();
    VECT_FLOAT& getFloat();
    VECT_8& getVector8();
    VECT_U8& getVectorU8();
    VECT_32& getVector32();
    VECT_U32& getVectorU32();
    VECT_16& getVector16();
    VECT_U16& getVectorU16();
    VECT_ARROW_TO_DB2_TIME& getVectorTime();

    void TimeToSQL_TIMESTAMP_STRUCT(size_t j, const ARROW_TO_DB2_TIME& item1);
    void TimeToSQL_DATE_STRUCT(size_t j, const ARROW_TO_DB2_TIME& item1);
    void TimeToTIME_STRUCT(size_t j, const ARROW_TO_DB2_TIME& item1);

    void fill_date32();
    void fill_date64();
    void fill_timestamp();
    void fill_time();

    MY_DICT() = delete;

    // construct a MY_DICT instance based on arrow vector type
    // field_name, type as a string
    MY_DICT(arrow::Type::type vector_type,
        const string& field_name,
        const string& type_string);

    // construct and return a MY_DICT instance based on arrow vector type
    // field_name, type as a string
    MY_DICT* get_MY_DICT(
        arrow::Type::type vector_type,
        const string& field_name,
        const string& type_string);

    // return the vector size
    size_t size();

    //cast operator overloading
    operator VECT_64& ();
    operator VECT_U64& ();
    operator VECT_8& ();
    operator VECT_U8& ();
    operator VECT_DOUBLE& ();
    operator VECT_32& ();
    operator VECT_U32& ();
    operator VECT_16& ();
    operator VECT_U16& ();
    operator VECT_ARROW_TO_DB2_TIME& ();

    // return address of first element
    // of generic std::vector<int64 or int32 or int8 or float or double> m_vector 
    void* get_data();

    // destructor...free memory
    ~MY_DICT();
};
