
#include "spclient_python_common_cpp.h"
#include "win32_to_linux.h"
#include "arrow_table_to_db2.h"
#include "arrow/util/decimal.h"

using namespace arrow;

static int my_dict_arrow_init = 0;

MAP_ARROWTYPE_STRING  &my_dict_arrow()
{
#if  (_MSC_VER == 1500) || (__APPLE__) || defined(__linux__)// VS 2008 PY 2.7 Win Default c++
    static MAP_ARROWTYPE_STRING str_arrow_dict;
    if (my_dict_arrow_init == 0)
    {
        str_arrow_dict[arrow::Type::BOOL]       = "BOOL";
        str_arrow_dict[arrow::Type::UINT64]     = "UINT64";
        str_arrow_dict[arrow::Type::UINT32]     = "UINT32";
        str_arrow_dict[arrow::Type::UINT16]     = "UINT16";
        str_arrow_dict[arrow::Type::UINT8]      = "UINT8";
        str_arrow_dict[arrow::Type::INT64]      = "INT64";
        str_arrow_dict[arrow::Type::INT32]      = "INT32";
        str_arrow_dict[arrow::Type::INT16]      = "INT16";
        str_arrow_dict[arrow::Type::INT8]       = "INT8";
        str_arrow_dict[arrow::Type::STRING]     = "STRING";
        str_arrow_dict[arrow::Type::BINARY]     = "BINARY";
        str_arrow_dict[arrow::Type::FIXED_SIZE_BINARY] = "FIXED_SIZE_BINARY";
        str_arrow_dict[arrow::Type::TIMESTAMP]  = "TIMESTAMP";
        str_arrow_dict[arrow::Type::DOUBLE]     = "DOUBLE";
        str_arrow_dict[arrow::Type::TIME64]     = "TIME64";
        str_arrow_dict[arrow::Type::TIME32]     = "TIME32";
        str_arrow_dict[arrow::Type::DATE64]     = "DATE64";
        str_arrow_dict[arrow::Type::DATE32]     = "DATE32";
        str_arrow_dict[arrow::Type::FLOAT]      = "FLOAT";
        str_arrow_dict[arrow::Type::HALF_FLOAT] = "HALF_FLOAT";
        str_arrow_dict[arrow::Type::INTERVAL]   = "INTERVAL"; 
        str_arrow_dict[arrow::Type::DECIMAL]    = "DECIMAL";
        str_arrow_dict[arrow::Type::LIST]       = "LIST";
        str_arrow_dict[arrow::Type::STRUCT]     = "STRUCT";
        str_arrow_dict[arrow::Type::UNION]      = "UNION";
        str_arrow_dict[arrow::Type::DICTIONARY] = "DICTIONARY";
        str_arrow_dict[arrow::Type::MAP]        = "MAP"; 
        str_arrow_dict[arrow::Type::EXTENSION] = "EXTENSION";
        str_arrow_dict[arrow::Type::FIXED_SIZE_LIST] = "FIXED_SIZE_LIST";
        str_arrow_dict[arrow::Type::DURATION] = "DURATION";

    }
#else
    static MAP_ARROWTYPE_STRING str_arrow_dict;
    if (my_dict_arrow_init == 0)
    {
        str_arrow_dict =
        {
            {arrow::Type::BOOL,   "BOOL"},
            {arrow::Type::INT64,  "INT64"},
            {arrow::Type::INT32,  "INT32"},
            {arrow::Type::INT16,  "INT16"},
            {arrow::Type::INT8,   "INT8"},
            {arrow::Type::UINT64, "UINT64"},
            {arrow::Type::UINT32, "UINT32"},
            {arrow::Type::UINT16, "UINT16"},
            {arrow::Type::UINT8,  "UINT8"},
            {arrow::Type::STRING, "STRING"},
            {arrow::Type::BINARY, "BINARY"},
            {arrow::Type::FIXED_SIZE_BINARY, "FIXED_SIZE_BINARY"},
            {arrow::Type::TIME64,           "TIME64"},
            {arrow::Type::TIME32,           "TIME32"},
            {arrow::Type::DATE64,           "DATE64"},
            {arrow::Type::DATE32,           "DATE32"},
            {arrow::Type::TIMESTAMP,        "TIMESTAMP"},
            {arrow::Type::DOUBLE,           "DOUBLE"},
            {arrow::Type::FLOAT,            "FLOAT"},
            {arrow::Type::HALF_FLOAT,       "HALF_FLOAT"},
            {arrow::Type::INTERVAL,         "INTERVAL"},
            {arrow::Type::DECIMAL,          "DECIMAL"},
            {arrow::Type::LIST,             "LIST"},
            {arrow::Type::STRUCT,           "STRUCT"},
            {arrow::Type::UNION,            "UNION"},
            {arrow::Type::DICTIONARY,       "DICTIONARY"},
            {arrow::Type::MAP,              "MAP"},
            {arrow::Type::EXTENSION,        "EXTENSION"},
            {arrow::Type::FIXED_SIZE_LIST,  "FIXED_SIZE_LIST"},
            {arrow::Type::DURATION,         "DURATION"},

        };
    }
#endif
    my_dict_arrow_init = 1;
    return str_arrow_dict;
}


//VECT_64 &vs = (VECT_64&)*dict;
MY_DICT::operator VECT_64 & () // casting operator overloading
{
    return *((VECT_64 *)m_vector);
}

MY_DICT::operator VECT_U64& () // casting operator overloading
{
    return *((VECT_U64*)m_vector);
}

MY_DICT::operator VECT_8 & () // casting operator overloading
{
    return *((VECT_8 *)m_vector);
}

MY_DICT::operator VECT_U8& () // casting operator overloading
{
    return *((VECT_U8*)m_vector);
}

MY_DICT::operator VECT_DOUBLE & () // casting operator overloading
{
    return *((VECT_DOUBLE *)m_vector);
}

MY_DICT::operator VECT_32 & () // casting operator overloading
{
    return *((VECT_32 *)m_vector);
}

MY_DICT::operator VECT_U32& () // casting operator overloading
{
    return *((VECT_U32*)m_vector);
}

MY_DICT::operator VECT_U16& () // casting operator overloading
{
    return *((VECT_U16*)m_vector);
}

MY_DICT::operator VECT_16& () // casting operator overloading
{
    return *((VECT_16*)m_vector);
}

MY_DICT::operator VECT_ARROW_TO_DB2_TIME & () // casting operator overloading
{
    return *((VECT_ARROW_TO_DB2_TIME*)m_vector);
}

// experimental
size_t MY_DICT::size1()
{
    return 0;
    //return static_cast<size_t>(*((VECT_DOUBLE *)m_vector)->_Mylast() - *((VECT_DOUBLE *)m_vector)->_Myfirst());
}

VECT_DOUBLE & MY_DICT::getVectorDouble()
{
    return *((VECT_DOUBLE *)m_vector);
}

//VECT_DEC128& MY_DICT::getVectorDec128()
//{
//    return *((VECT_DEC128*)m_vector);
//}

VECT_64 & MY_DICT::getVector64()
{
    return *((VECT_64 *)m_vector);
}

VECT_U64& MY_DICT::getVectorU64()
{
    return *((VECT_U64*)m_vector);
}

VECT_FLOAT & MY_DICT::getFloat()
{
    return *((VECT_FLOAT *)m_vector);
}

VECT_8 & MY_DICT::getVector8()
{
    return *((VECT_8 *)m_vector);
}

VECT_U8& MY_DICT::getVectorU8()
{
    return *((VECT_U8*)m_vector);
}

VECT_32 & MY_DICT::getVector32()
{
    return *((VECT_32 *)m_vector);
}

VECT_U32& MY_DICT::getVectorU32()
{
    return *((VECT_U32*)m_vector);
}

VECT_U16& MY_DICT::getVectorU16()
{
    return *((VECT_U16*)m_vector);
}

VECT_16& MY_DICT::getVector16()
{
    return *((VECT_16*)m_vector);
}

VECT_ARROW_TO_DB2_TIME & MY_DICT::getVectorTime()
{
    return *((VECT_ARROW_TO_DB2_TIME *)m_vector);
}

// return address of first element
void * MY_DICT::get_data()
{
    switch (this->vector_type)
    {

        case arrow::Type::TIMESTAMP:
        case arrow::Type::TIME64:
        case arrow::Type::TIME32:
        case arrow::Type::DATE64:
        case arrow::Type::DATE32:
            return m_data_time;

        case arrow::Type::INT64:
            return getVector64().data();

        case arrow::Type::UINT64:
            return getVectorU64().data();

        case arrow::Type::BOOL:
        case arrow::Type::INT8:
            return getVector8().data();

        case arrow::Type::UINT8:
            return getVectorU8().data();

        case arrow::Type::INT32:
            return getVector32().data();

        case arrow::Type::UINT32:
            return getVectorU32().data();

        case arrow::Type::UINT16:
            return getVectorU16().data();

        case arrow::Type::INT16:
            return getVector16().data();

        case arrow::Type::DOUBLE:
            return getVectorDouble().data();

        case arrow::Type::DECIMAL:
        case arrow::Type::FIXED_SIZE_BINARY:
        case arrow::Type::BINARY:
        case arrow::Type::STRING:
            return m_v_8_string.data();


        case arrow::Type::FLOAT:
            return getFloat().data();

        case arrow::Type::HALF_FLOAT:
            return getFloat().data();

        default:
        {
            //const MAP_ARROWTYPE_STRING  & _my_dict_arrow = my_dict_arrow();
            printf("%d %s() error dont know how to get_data() %d '%s'\n",
                __LINE__,
                __FUNCTION__,
                this->vector_type,
                my_dict_arrow()[vector_type].c_str()
            );
            return nullptr;
            break;
        }
    }
}
/*
*Erase all Occurrences of given substring from main string.
*/
void eraseAllSubStr(std::string& mainStr, const std::string& toErase)
{
    size_t pos = std::string::npos;

    // Search for the substring in string in a loop untill nothing is found
    while ((pos = mainStr.find(toErase)) != std::string::npos)
    {
        // If found then erase it from string
        mainStr.erase(pos, toErase.length());
    }
}

/*
MY_DICT * MY_DICT::get_MY_DICT(
    arrow::Type::type vector_type,
    const string &field_name,
    const string &type_string)
{
    return new MY_DICT(vector_type, field_name, type_string);
}
*/
MY_DICT::MY_DICT(
    arrow::Type::type vector_type,
    const string &in_field_name,
    const string &in_type_string) :
    field_name(in_field_name),
    type_string(in_type_string)
{
    m_data_time = nullptr;
    ColDef = 0;
    Scale = 0;
    //LOG_INFO("%s %s", field_name.c_str(), type_string.c_str());


    this->vector_type = vector_type;
    switch (this->vector_type)
    {

        case arrow::Type::UINT64:
        {
            this->m_vector = new VECT_U64();
            break;
        }

        case arrow::Type::INT64:
        {
            this->m_vector = new VECT_64(); //new VECT_64;
            //vector1 = std::make_shared<VECT_64 *> (new VECT_64);
            break;
        }

        case arrow::Type::BOOL:
        case arrow::Type::INT8:
        {
            this->m_vector = new VECT_8();
            break;
        }
        case arrow::Type::UINT8:
        {
            this->m_vector = new VECT_U8();
            break;
        }

        case arrow::Type::INT32:
        {
            this->m_vector = new VECT_32();
            break;
        }

        case arrow::Type::UINT32:
        {
            this->m_vector = new VECT_U32();
            break;
        }

        case arrow::Type::INT16:
        {
            this->m_vector = new VECT_16();
            break;
        }

        case arrow::Type::UINT16:
        {
            this->m_vector = new VECT_U16();
            break;
        }

        case arrow::Type::FIXED_SIZE_BINARY:
        case arrow::Type::BINARY:
        {
            // we use member variable v_8_string
            // not dynamically allocated
            break;
        }
        case arrow::Type::DOUBLE:
        {
            this->m_vector = new VECT_DOUBLE();
            break;
        }
        case arrow::Type::DECIMAL:
        {
            // we use member variable v_8_string
            // not dynamically allocated
            string local = type_string;
            eraseAllSubStr(local, "decimal(");;
            
            int ret = sscanf(local.c_str(), "%d, %d", &ColDef, &Scale);
            assert(ret == 2);
            break;
        }
        case arrow::Type::DATE32:
        case arrow::Type::DATE64:
        case arrow::Type::TIME64:
        case arrow::Type::TIME32:
        case arrow::Type::TIMESTAMP:
        {
            this->m_vector = new VECT_ARROW_TO_DB2_TIME();
            break;

        }
        case arrow::Type::STRING:
        {
            // we use member variable v_8_string
            // not dynamically allocated
            break;
        }
        case arrow::Type::FLOAT:
        {
            this->m_vector = new VECT_FLOAT();
            break;
        }
        case arrow::Type::HALF_FLOAT:
        {
            this->m_vector = new VECT_FLOAT();
            break;
        }
        default:
        {
            printf("%d %s() error vector not initialized %d %s\n", 
                __LINE__, 
                __FUNCTION__, 
                this->vector_type,
                my_dict_arrow()[vector_type].c_str()
                );
            break;
        }
    }

}

size_t MY_DICT::size()
{
    switch (this->vector_type)
    {
        case arrow::Type::BOOL:
        case arrow::Type::INT8:
            return ((VECT_8 *)m_vector)->size();
        case arrow::Type::UINT8:
            return ((VECT_U8*)m_vector)->size();
        case arrow::Type::UINT16:
            return ((VECT_U16*)m_vector)->size();
        case arrow::Type::INT16:
            return ((VECT_16*)m_vector)->size();
        case arrow::Type::UINT64:
            return ((VECT_U64*)m_vector)->size();
        case arrow::Type::INT64:
            return ((VECT_64 *)m_vector)->size();

        case arrow::Type::HALF_FLOAT:
        case arrow::Type::FLOAT:
            return ((VECT_FLOAT *)m_vector)->size();
        case arrow::Type::DOUBLE:
            return ((VECT_DOUBLE *)m_vector)->size();
        case arrow::Type::DATE64:
        case arrow::Type::DATE32:
        case arrow::Type::TIME64:
        case arrow::Type::TIME32:
        case arrow::Type::TIMESTAMP:
            return ((VECT_ARROW_TO_DB2_TIME *)m_vector)->size();
        case arrow::Type::STRING:
        case arrow::Type::FIXED_SIZE_BINARY:
        case arrow::Type::BINARY:
        case arrow::Type::DECIMAL:
            return m_str_lens.size();
        case arrow::Type::INT32:
            return ((VECT_32 *)m_vector)->size();
        case arrow::Type::UINT32:
            return ((VECT_U32*)m_vector)->size();
        default:
        {
            printf("%d %s() dont know what type %d\n",
                __LINE__,
                __FUNCTION__,
                this->vector_type);
            break;
        }
    }
    return 0;

}

MY_DICT::~MY_DICT()
{
    // ONLY on these types we did a malloc on m_data_time
    if ((vector_type == arrow::Type::TIMESTAMP) ||
        (vector_type == arrow::Type::DATE32) ||
        (vector_type == arrow::Type::TIME32) ||
        (vector_type == arrow::Type::TIME64) ||
        (vector_type == arrow::Type::DATE64))
    {
        if (m_data_time != nullptr)
        {
            free(m_data_time);
            m_data_time = nullptr;
        }
    }
    // string or binary type
    // uses member variable that is not dynamically allocated 
    // m_v_8_string
    if ((this->vector_type == arrow::Type::STRING) ||
        (this->vector_type == arrow::Type::FIXED_SIZE_BINARY) ||
        (this->vector_type == arrow::Type::BINARY) ||
        (this->vector_type == arrow::Type::DECIMAL))
        return;

    if (m_vector != NULL)
    {
        switch (this->vector_type)
        {
            case arrow::Type::UINT64:
            {
                delete ((VECT_U64*)m_vector);
                break;
            }

            case arrow::Type::INT64:
            {
                delete ((VECT_64 *)m_vector);
                break;
            }
 
            case arrow::Type::INT32:
            {
                delete ((VECT_32 *)m_vector);
                break;
            }
            case arrow::Type::UINT32:
            {
                delete ((VECT_U32*)m_vector);
                break;
            }
            case arrow::Type::INT16:
            {
                delete ((VECT_16*)m_vector);
                break;
            }
            case arrow::Type::UINT16:
            {
                delete ((VECT_U16*)m_vector);
                break;
            }
            case arrow::Type::BOOL:
            case arrow::Type::INT8:
            {
                delete ((VECT_8 *)m_vector);
                break;
            }
            case arrow::Type::UINT8:
            {
                delete ((VECT_U8*)m_vector);
                break;
            }
            case arrow::Type::DOUBLE:
            {
                delete ((VECT_DOUBLE *)m_vector);
                break;
            }
            case arrow::Type::DECIMAL:
            {
                break;
            }
            case arrow::Type::HALF_FLOAT:
            case arrow::Type::FLOAT:
            {
                delete ((VECT_FLOAT *)m_vector);
                break;
            }
            case arrow::Type::DATE64:
            case arrow::Type::DATE32:
            case arrow::Type::TIME64:
            case arrow::Type::TIME32:
            case arrow::Type::TIMESTAMP:
            {
                delete ((VECT_ARROW_TO_DB2_TIME *)m_vector);
                break;

            }
            default:
            {
                printf("%d %s() error dont know what arrow type %d arrow type '%s'\n", 
                    __LINE__, 
                    __FUNCTION__,
                    this->vector_type,
                    my_dict_arrow()[vector_type].c_str());
                break;
            }
        }

        m_vector = NULL;
    }
    else
    {
        printf("error vector is NULL\n");

    }
    //printf("%d %s() done %-20s %-12s\n", 
    //    __LINE__, 
    //    __FUNCTION__, field_name.c_str(), type_string.c_str());

}



ostream& operator<<(ostream& os, MY_DICT& _d)
{
    unsigned long i = 0;
    os << _d.to_string(i).c_str();
    return os;
}

string MY_DICT::to_string(size_t i)
{
    char buffer[4];
    char buffer50[50];

    std::ostringstream stringStreamlog;
    switch (vector_type)
    {
        case arrow::Type::FIXED_SIZE_BINARY:
        case arrow::Type::BINARY:
        case arrow::Type::STRING:
            for (int j = 0; j < m_str_lens[i]; j++)
                stringStreamlog << m_v_8_string[(i * max_size_string) + j];
            break;
        case arrow::Type::DOUBLE:
            sprintf(buffer50, "%lf", getVectorDouble()[i]);
            stringStreamlog << buffer50;
            break;
        case arrow::Type::FLOAT:
            stringStreamlog << getFloat()[i];
            break;
        case arrow::Type::DECIMAL:
        {
            for (int j = 0; j < m_str_lens[i]; j++)
                stringStreamlog << m_v_8_string[(i * MAX_DIGITS) + j];
            break;
        }
        case arrow::Type::HALF_FLOAT:
            stringStreamlog << getFloat()[i];
            break;
        case arrow::Type::INT64:
            stringStreamlog << getVector64()[i];
            break;
        case arrow::Type::UINT64:
            stringStreamlog << getVectorU64()[i];
            break;
        case arrow::Type::INT32:
            stringStreamlog << getVector32()[i];
            break;
        case arrow::Type::UINT32:
            stringStreamlog << getVectorU32()[i];
            break;
        case arrow::Type::DATE32:
            stringStreamlog << getVectorTime()[i].to_string_as_date();
            break;
        case arrow::Type::TIME32:
            stringStreamlog << getVectorTime()[i].to_string_as_time();
            break;
        case arrow::Type::TIMESTAMP:
        case arrow::Type::DATE64:
        case arrow::Type::TIME64:
            stringStreamlog << getVectorTime()[i];
            break;
        case arrow::Type::INT16:
            stringStreamlog << getVector16()[i];
            break;
        case arrow::Type::UINT16:
            stringStreamlog << getVectorU16()[i];
            break;
        case arrow::Type::INT8:
            sprintf(buffer, "%d", getVector8()[i]);
            stringStreamlog << buffer;
            break;
        case arrow::Type::UINT8:
            sprintf(buffer, "%d", getVectorU8()[i]);
            stringStreamlog << buffer;
            break;
        case arrow::Type::BOOL:
            if (getVector8()[i])
                stringStreamlog << "True";
            else
                stringStreamlog << "False";
            break;
        default:
            stringStreamlog << "UNKNOW";
    }

    stringStreamlog << " ";

    return stringStreamlog.str();
}


void free_MAP_FIELDNAME_DICT(
    MAP_FIELDNAME_DICT &map_field_memory_vectors)
{
    // free STRUCT_DICT
    for (const std::pair<string, MY_DICT *>& item : map_field_memory_vectors)
        delete item.second;
    //printf("done %d %s()\n", __LINE__, __FUNCTION__);
}
