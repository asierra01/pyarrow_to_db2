#pragma once


#include <stdint.h>
#include <arrow/python/pyarrow.h>
#include <arrow/status.h>
#include <arrow/table.h>
#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2_dict.h"


typedef std::shared_ptr<arrow::Column> COLUMN;
typedef std::shared_ptr<arrow::Table> TABLE;



typedef std::map <arrow::Type::type, std::string> MAP_ARROWTYPE_STRING;
typedef std::map<string, MY_DICT *> MAP_FIELDNAME_DICT;

int using_arrow_cpp_api(
    TABLE &parquet_table,
    MAP_FIELDNAME_DICT &map_field_memory_vectors);

int create_table_in_backend_from_map_fieldname(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    MAP_FIELDNAME_DICT &map_field_memory_vectors,
    const char * tablespace_name,
    const char * schema_name,
    const char * table_name,
    bool         column_oriented,
    bool         drop_table,
    bool         &column_organyze_by,
    bool         &column_boolean);

int do_the_load_arrow_to_one_big_csv(
    SQLHANDLE henv,
    SQLHANDLE hdbc,
    MAP_FIELDNAME_DICT &map_field_memory_vectors,
    const char * tablespace_name,
    const char * schema_name,
    const char * table_name,
    const char * MESSAGE_FILE_ONE_BIG_CSV,
    db2Uint32  iDataBufferSize,
    db2Uint32  iSavecount,
    db2Uint32  iChunkSize,
    bool         column_oriented,
    bool         drop_table,
    db2LoadOut * pLoadOut,
    int64_t     num_rows);


MAP_ARROWTYPE_STRING &my_dict_arrow();

struct my_db2load_struct
{
    struct sqldcol *pDataDescriptor = NULL;
    db2LoadIn *pLoadIn = NULL;
    db2LoadOut *pLoadOut = NULL;
    db2LoadStruct *pLoadStruct = NULL;
    char *pMessageFile = NULL;
    my_db2load_struct() = delete; // will never be generated

    my_db2load_struct(
        db2LoadOut *LoadOut, 
        db2Uint64 iRowcount,
        db2Uint32 iSavecount,
        db2Uint32 iDataBufferSize,
        const char * MESSAGE_FILE);

    int initialize_db2loadstructure(
        db2Uint64 iRowcount,
        db2Uint32 iSavecount, 
        db2Uint32 iDataBufferSize,
        const char * MESSAGE_FILE);

    ~my_db2load_struct();
 

};

typedef struct my_db2load_struct MY_DB2LOAD_STRUCTURE;

void log_mapfieldname_dict(
    MAP_FIELDNAME_DICT &map_field_memory_vectors);

int boost_tokenize_and_run_sql(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    std::string &s);

int  bind_parameters_generic(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    int64_t num_rows,
    MAP_FIELDNAME_DICT &map_field_memory_vectors,
    bool &column_boolean);

void free_MAP_FIELDNAME_DICT(
    MAP_FIELDNAME_DICT &map_field_memory_vectors);


void tm_toTIME(
    std::tm tm, 
    ARROW_TO_DB2_TIME &t1);

void print_dir(py11::object _object);
