#pragma once

#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"


void print_double(
    COLUMN &c,
    MY_DICT *dict);

void from_pyarrow_array_std_chrono(
    COLUMN &c,
    VECT_ARROW_TO_DB2_TIME &test_from_pyarrow_array);

void print_int16(
    COLUMN& c,
    MY_DICT* dict);

void print_uint16(
    COLUMN& c,
    MY_DICT* dict);

void print_int32(
    COLUMN &c,
    MY_DICT *dict);

void print_uint32(
    COLUMN& c,
    MY_DICT* dict);

void print_int64(
        COLUMN &c,
        MY_DICT *dict);

void print_uint64(
    COLUMN& c,
    MY_DICT* dict);

void print_time64(
    COLUMN &c,
    MY_DICT *dict);

void print_time32(
    COLUMN& c,
    MY_DICT* dict);

void print_bool(
    COLUMN &c,
    MY_DICT *dict);

void print_int8(
    COLUMN &c,
    MY_DICT *dict);

void print_uint8(
    COLUMN& c,
    MY_DICT* dict);

void print_string(
    COLUMN &c,
    MY_DICT *dict);

void print_binary(
    COLUMN &c,
    MY_DICT *dict);

void print_fixed_size_binary(
    COLUMN& c,
    MY_DICT* dict);

void print_date64(
    COLUMN &c,
    MY_DICT *dict);

void print_date32(
    COLUMN &c,
    MY_DICT *dict);

void print_float(
    COLUMN &c,
    MY_DICT *dict);

void print_half_float(
    COLUMN &c,
    MY_DICT *dict);

void print_decimal(
    COLUMN& c,
    MY_DICT* dict);

void print_timestamp(
    COLUMN &c,
    MY_DICT *dict);

void log_dic(
    MY_DICT &dict,
    COLUMN &c,
    py11::object &py_table,
    int line,
    const char * func_name);

#define LOG_DICT log_dic(*dict, c, py_table, __LINE__, __FUNCTION__)

py11::object get_table_dict();