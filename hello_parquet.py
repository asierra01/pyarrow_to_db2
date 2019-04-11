""":mod:`hello_parquet` module to test all fields of a `pyarrow` table  to db2  
"""
import pyarrow.parquet as pq
import pyarrow as pa
import os
import datetime
import pprint
import sys
import errno
import logging
import logging.handlers
from dateutil.relativedelta import relativedelta
import ibm_db
import collections
import numpy as np
from pyarrow import types
import pyarrow.lib as lib
import spclient_python




try:
    os.mkdir('log')
except OSError as e:
    if e.errno != errno.EEXIST:
        print ("creating directory 'log'  OSError %s" % e)

try:
    os.remove(os.path.join("log", "hello_parquet.log"))
except OSError:
    pass

format_hdlr = "%(asctime)s %(levelname)6s:%(lineno)4s - %(funcName)10s() %(message)s  "

#file_hdlr = logging.handlers.RotatingFileHandler('build.log',maxBytes=5000000, backupCount = 5)
# create console handler and set level to debug
console_hdlr = logging.StreamHandler()
console_hdlr.setLevel(logging.INFO)


log_formatter = logging.Formatter(format_hdlr, "%H:%M:%S") # "%Y-%m-%d %H:%M:%S"

hdlr = logging.handlers.RotatingFileHandler(
    os.path.join("log", "hello_parquet.log"), 
    maxBytes=10000000, 
    backupCount=3)
hdlr.setLevel(logging.INFO)

console_hdlr.setFormatter(log_formatter)
hdlr.setFormatter(log_formatter)
mylog = logging.getLogger(__name__)
mylog.setLevel(logging.INFO)
#log.addHandler(file_hdlr)
mylog.addHandler(console_hdlr)
mylog.addHandler(hdlr)


if sys.version_info > (3,):
    import configparser #@UnusedImport
else:
    import ConfigParser as configparser #@ImportRedefinition

config=None

def my_func():
    return ""

def get_config(key, default):
    global config, DSN
    if config is None:
        if sys.version_info > (3,):
            config = configparser.ConfigParser()
        else:
            config = configparser.RawConfigParser()
        try:
            config.read("hello_parquet.ini")
            DSN = config.get('DSN', 'DSN')
            mylog.info("DSN='%s' cwd=%s" % (DSN, os.getcwd()))

        except configparser.ParsingError as e:
            mylog.error("ParsingError %s" % e)
            sys.exit(0)

    try:
        local = config.get(DSN, key)
    except configparser.Error as e:
        local = default
        cwd = os.getcwd()
        mylog.error("""
type %s 
error '%s' 
using default %s='%s' 
cwd %s
""" % (type(e), e, key, default, cwd))
    return local

def read_ini():
    """
    This function set the DSN parameters, DB2_USER, DB2_PASSWORD, DB2_DATABASE
    DB2_DATABASE is really the DSN on the db2cli.ini file, so is not the DB NAME

    Returns
    -------
    :class:`collections.defaultdict`
    """

    if os.path.exists("hello_parquet.ini"):
        mylog.info("hello_parquet.ini present")

        DB2_USER         = get_config('DB2_USER', 'some_db2_user')
        DB2_PASSWORD     = get_config('DB2_PASSWORD', 'some_db2_password')
        DB2_DATABASE     = get_config('DB2_DATABASE', 'SAMPLE')
        DB2_ALIAS        = get_config('DB2_ALIAS', 'SAMPLE')
        DB2_HOSTADDR     = get_config('DB2_HOSTADDR', '*LOCAL')
        DB2_INSTANCE     = get_config('DB2_INSTANCE', 'DB2')
        DB2_PORT         = get_config('DB2_PORT', '50000')
        DB2_PROTOCOL     = get_config('DB2_PROTOCOL', 'IPC')
        TEST_SIZE        = get_config('TEST_SIZE', '1000000')


    else:# as conn.ini is not present try to fill the values with os env variables 
        mylog.error("hello_parquet.ini present not present")
        sys.exit(0)

    my_dict = collections.defaultdict ( my_func,{
        'DB2_USER'                : DB2_USER,
        'DB2_PASSWORD'            : DB2_PASSWORD,
        'DB2_INSTANCE'            : DB2_INSTANCE,
        'DB2_HOSTADDR'            : DB2_HOSTADDR,
        'DB2_DATABASE'            : DB2_DATABASE,
        'DB2_PROTOCOL'            : DB2_PROTOCOL,
        'DB2_ALIAS'               : DB2_ALIAS,
        'DB2_PORT'                : DB2_PORT,
        'TEST_SIZE'               : TEST_SIZE })

    return my_dict



def create_dummy_data_all_fields(size):
    """Create dummy data pyarrow table
    """

    column_names = ["c_uint8", "c_int8", "c_uint16", "c_int16", 
                  "c_uint32", "c_int32", "c_uint64", "c_int64", 
                  "c_float32", "c_float64", "c_bool", "c_date32", 
                  "c_date64", "c_time64_us", "c_time64_ns", "c_time32_ms", 
                  "c_time32_s", "c_timestamp_s", "c_timestamp_ms", 
                  "c_timestamp_us", "c_timestamp_ns", "c_string"]
    arrays = []
    int_list = []
    int64_list = []
    uint64_list = []
    date32_list = []
    date64_list = []
    time64_list = []
    time32_ms_list = []
    time32_s_list = []
    time64_ns_list = []
    string_list = []

    #import time
    t4_ms = datetime.time(10, 10, 10, 999999)
    t4_s = datetime.time(10, 10, 10, 0)
    for i in range(size):
        t3 = datetime.time(10, 10, 10, i)

        t_nas = datetime.time(10, 10, 10, i)
        #t_nas_test = time.time_ns() #should work but doesnt
        int_list.append((i % 2+1))
        date32_list.append(i % 50000)
        date64_list.append(datetime.datetime.now())
        time64_list.append(t3)
        time64_ns_list.append(t_nas)
        time32_ms_list.append(t4_ms)
        time32_s_list.append(t4_s)
        if i % 2 == 0:
            string_list.append("juana")
        else:
            string_list.append("petra")

    for i in range(size):
        int64_list.append(-i)

    for i in range(size):
        uint64_list.append(i)

    float32_list = []
    float64_list = []
    bool_list    = []

    for j in range(len(int_list)):
       if (j % 2 == 1):
           bool_list.append(True)
       else:
           bool_list.append(False)

    #mylog.info("%s"  % dir(pa))

    uint8_list   = np.arange(size, dtype=np.uint8)
    int8_list    = np.arange(size, dtype=np.int8)
    uint16_list  = np.arange(size, dtype=np.uint16)
    int16_list   = np.arange(size, dtype=np.int16)
    float32_list = np.arange(size, dtype=np.float32)
    float64_list = np.arange(size, dtype=np.float64)

    arr_uint8     = pa.array(uint8_list,   pa.uint8())
    arr_int8      = pa.array(int8_list,    pa.int8())
    arr_uint16    = pa.array(uint16_list,  pa.uint16())
    arr_int16     = pa.array(int16_list,   pa.int16())
    arr_uint32    = pa.array(int_list,     pa.uint32())
    arr_int32     = pa.array(int_list,     pa.int32())
    arr_uint64    = pa.array(uint64_list,  pa.uint64())
    arr_int64     = pa.array(int64_list,   pa.int64())
    arr_float32   = pa.array(float32_list, pa.float32())
    arr_float64   = pa.array(float64_list, pa.float64())
    arr_bool      = pa.array(bool_list,    pa.bool_())
    arr_date32    = pa.array(date32_list,  pa.date32())
    arr_date64    = pa.array(date64_list,       pa.date64())
    arr_time64_us = pa.array(time64_list,       pa.time64("us"))
    arr_time64_ns = pa.array(time64_ns_list,    pa.time64("ns"))
    arr_time32_ms = pa.array(time32_ms_list,    pa.time32("ms"))
    arr_time32_s  = pa.array(time32_s_list,     pa.time32("s"))
    timestamp_s   = pa.array(date64_list,       pa.timestamp("s"))
    timestamp_ms   = pa.array(date64_list,      pa.timestamp("ms"))
    timestamp_us   = pa.array(date64_list,      pa.timestamp("us"))
    timestamp_ns   = pa.array(date64_list,      pa.timestamp("ns"))
    arr_string    = pa.array(string_list,       pa.string())
    mylog.debug("%s %s" % (arr_time64_ns, type(arr_time64_ns)))

    arrays.append(arr_uint8)
    arrays.append(arr_int8)
    arrays.append(arr_uint16)
    arrays.append(arr_int16)
    arrays.append(arr_uint32)
    arrays.append(arr_int32)
    arrays.append(arr_uint64)
    arrays.append(arr_int64)
    arrays.append(arr_float32)
    arrays.append(arr_float64)
    arrays.append(arr_bool)
    arrays.append(arr_date32)
    arrays.append(arr_date64)
    arrays.append(arr_time64_us)
    arrays.append(arr_time64_ns)
    arrays.append(arr_time32_ms)
    arrays.append(arr_time32_s)
    arrays.append(timestamp_s)
    arrays.append(timestamp_ms)
    arrays.append(timestamp_us)
    arrays.append(timestamp_ns)
    arrays.append(arr_string)
    table = pa.Table.from_arrays(arrays, column_names, metadata={'a':'pila de datos', 'b' : 'esto es una b'})
    return table



cont_t = 0
data_read_ini = read_ini()
userid = data_read_ini["DB2_USER"]
passw = data_read_ini["DB2_PASSWORD"]
connecting_str = """
UID={DB2_USER};
PWD={DB2_PASSWORD};
DATABASE={DB2_DATABASE};
DBALIAS={DB2_ALIAS};
HOSTNAME={DB2_HOSTADDR};
PORT={DB2_PORT};
PROTOCOL={DB2_PROTOCOL};
PROGRAMNAME=Python_ibm_db_test;
PROGRAMID=ProgramId_ibm_db_test;
CLIENTAPPLNAME=Client_ibm_db_test;
CLIENTUSERID=ClientUserID_ibm_db_test;
CONNECTTIMEOUT=10
""".format(**data_read_ini)
connecting_str = connecting_str.replace("\n", "")
mylog.info("connecting %s " % connecting_str)
conn = ibm_db.connect(connecting_str, userid, passw)
ibm_db.autocommit(conn, ibm_db.SQL_AUTOCOMMIT_ON)
table1 = create_dummy_data_all_fields(int(data_read_ini["TEST_SIZE"]))
mylog.debug("table1 %s" % table1)
#mylog.info("table1.schema \n%s" % table1.schema)
mylog.info("table1 num_rows    %s" % "{:,}".format(table1.num_rows))
mylog.info("table1 num_columns %s" % table1.num_columns)


os.environ["SPCLIENT_PYTHON_LOG_COLUMN"] = data_read_ini["SPCLIENT_PYTHON_LOG_COLUMN"]
os.environ["SPCLIENT_PYTHON_LOG_PARAMETER"] = data_read_ini["SPCLIENT_PYTHON_LOG_PARAMETER"]
os.environ["SPCLIENT_PYTHON_LOG_CREATE_TABLE"] = data_read_ini["SPCLIENT_PYTHON_LOG_CREATE_TABLE"]
os.environ["SPCLIENT_PYTHON_LOG_GENERAL"] = data_read_ini["SPCLIENT_PYTHON_LOG_GENERAL"]
os.environ["SPCLIENT_PYTHON_LOG_ROWS"] = data_read_ini["SPCLIENT_PYTHON_LOG_ROWS"]
os.environ["SPCLIENT_PYTHON_LOG_DIC"] = data_read_ini["SPCLIENT_PYTHON_LOG_DIC"]

start = datetime.datetime.now()
column_oriented = False
drop_table = True
filename = "test_parquet_table"
MESSAGE_FILE = os.path.join("log", "test_parquet.txt")
mylog.debug("\nspclient_python.arrow_table_to_db2.__doc__ %s " % spclient_python.arrow_table_to_db2.__doc__)
"""
Insert the data
"""
try:
    load_result = spclient_python.arrow_table_to_db2(
                conn,
                MESSAGE_FILE ,
                100000,
                100000,
                10000,
                mylog.info,
                table1,
                None, # "TABLESPACE_NAME"
                "", # "SCHEMA_NAME"
                filename,
                column_oriented, # column oriented=1 row oriented =0
                drop_table)
    mylog.info("load_result \n%s" % pprint.pformat(load_result))
    bytes_allocated = load_result['bytes_allocated']

    t_diff = relativedelta(datetime.datetime.now(), start)
    seg = (t_diff.hours*60*60)+(t_diff.minutes*60)+t_diff.seconds
    if seg == 0:
        seg = 0.1
    megs_per_seconds = bytes_allocated/(seg * 1024 * 1024)
    mylog.info("Speed %5.5f M/seg" % megs_per_seconds)
except Exception as e:
    mylog.error("%s %s" % (type(e), e))

"""
Retrieve the data
"""

sql_str = """
SELECT 
 *
FROM 
"%s" 

""" % filename
stmt = ibm_db.exec_immediate(conn, sql_str)
dictionary = ibm_db.fetch_both(stmt)
cont  = 0
while dictionary:
    cont += 1
    if (cont % 30000) == 0:
        new_dictionary = {}
        for key in dictionary.keys():
            if isinstance(key, str):
                new_dictionary[key] = dictionary[key]

        #mylog.info("dictionary \n%s" % pprint.pformat(new_dictionary))
        mylog.info("dictionary \n%s" % new_dictionary)
    dictionary = ibm_db.fetch_both(stmt)
    if cont > 100000:
        break

