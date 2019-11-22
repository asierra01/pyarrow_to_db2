#pragma once


#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <inttypes.h>
#include <vector>
#include <map>
#include <ctime>
#include <chrono>
#include <sqlcli.h>

#include "spclient_python_common.h"

#include <pybind11/pybind11.h> //python37/include/pybind11/pybind11.h
#include <pybind11/eval.h>     //python37/include/pybind11/eval.h
#include <pybind11/stl.h>


namespace py11 = pybind11;
using namespace std;
void load_pyarrow();

extern string arrow_table_to_db2_docstring;
extern const char* IBM_DBConnection;

typedef std::map <int, std::string> MAP_INT_STRING;
MAP_INT_STRING &map_sql_value_sql_str(); // sql literal string type, sql type
MAP_INT_STRING &map_param_type_str();
MAP_INT_STRING& map_sql_type_str();
MAP_INT_STRING& map_nulls_str();
MAP_INT_STRING& map_sql_value_userdefinedtypecode_str();


struct struct_column_info
{
    SQLSMALLINT fSqlType;
    SQLULEN     cbColDef;
    SQLSMALLINT ibScale;
    SQLSMALLINT fNullable;
};


typedef struct struct_column_info COLUMN_INFO;
typedef std::map<int, COLUMN_INFO> MAP_COLNO_COLUMN_INFO;

int  display_parameters_map(
    SQLHDBC                hdbc,
    SQLHSTMT               hstmt,
    const char             * table_name,
    MAP_COLNO_COLUMN_INFO  &map_colno_sql_type,
    bool                   display,
    ERROR_VAR_PARAM_DEF);

int display_procedures(
    SQLHDBC  hdbc,
    SQLCHAR* owner,
    SQLCHAR* proc_name,
    bool           display,
    PYOBJ_PTR      py_list_describe_cols,
    ERROR_VAR_PARAM_DEF);

int check_error(
    SQLHDBC hdbc,
    SQLHSTMT hstmt,
    SQLRETURN cliRC,
    int line,
    const char * functionname,
    ERROR_VAR_PARAM_DEF);

void print_dir(py11::object &_object);
const char* __doc__(PyCFunction func);
