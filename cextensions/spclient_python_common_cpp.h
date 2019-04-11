#pragma once


#include <string>
#include <memory>
#include <iostream>
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

typedef std::map <int, std::string> MAP_INT_STRING;
MAP_INT_STRING &map_sql_value_sql_str(); // sql literal string type, sql type

struct struct_column_info
{
    SQLSMALLINT pfSqlType;
    SQLULEN     pcbColDef;
    SQLSMALLINT pibScale;
    SQLSMALLINT pfNullabl;
};


typedef struct struct_column_info COLUMN_INFO;
typedef std::map<int, COLUMN_INFO> MAP_COLNO_COLUMN_INFO;

int  display_parameters_map(
    SQLHANDLE              hdbc,
    SQLHANDLE              hstmt,
    MAP_COLNO_COLUMN_INFO  &map_colno_sql_type,
    bool                   display);

int check_error(
    SQLHANDLE hdbc,
    SQLHANDLE hstmt,
    SQLRETURN cliRC,
    int line,
    const char * functionname);

void print_dir(py11::object _object);