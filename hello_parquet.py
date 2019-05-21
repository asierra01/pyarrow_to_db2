""":mod:`hello_parquet` module to test all fields of a `pyarrow` table  to db2  
"""
#import pyarrow.parquet as pq
import pyarrow as pa
import pandas as pd
import os
import json
from datetime import datetime, time, timedelta, date
import pprint
import sys
import errno
from texttable import Texttable
import logging
import logging.handlers
from dateutil.relativedelta import relativedelta
import ibm_db
import ibm_db_dbi
import collections
import numpy as np
import decimal
import humanfriendly
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
import datetime as dt


class MyFormatter(logging.Formatter):
    converter = dt.datetime.fromtimestamp

    def formatTime(self, record, datefmt=None):
        ct = self.converter(record.created)
        if datefmt:
            s = ct.strftime(datefmt)
        else:
            t = ct.strftime("%Y-%m-%d %H:%M:%S")
            s = "%s,%03d" % (t, record.msecs)
        return s

#format_hdlr = "%(asctime)s %(levelname)6s:%(lineno)4s - %(funcName)10s() %(message)s  "


console_hdlr = logging.StreamHandler()
console_hdlr.setLevel(logging.INFO)

formatter = MyFormatter(fmt='%(asctime)s %(levelname)6s:%(lineno)4s - %(funcName)10s() %(message)s', datefmt='%Y-%m-%d,%H:%M:%S.%f')
#log_formatter = logging.Formatter(format_hdlr, "%H:%M:%S:%F") # "%Y-%m-%d %H:%M:%S"

hdlr = logging.handlers.RotatingFileHandler(
    os.path.join("log", "hello_parquet.log"), 
    maxBytes=10000000, 
    backupCount=3)
hdlr.setLevel(logging.INFO)

console_hdlr.setFormatter(formatter)
hdlr.setFormatter(formatter)
mylog = logging.getLogger(__name__)
mylog.setLevel(logging.INFO)
#log.addHandler(file_hdlr)
mylog.addHandler(console_hdlr)
mylog.addHandler(hdlr)


if sys.version_info > (3,):
    import configparser  # @UnusedImport
else:
    import ConfigParser as configparser  # @ImportRedefinition

config = None
DSN = None


def my_func():
    return ""


def get_my_dict():
    items = config.items(DSN)
    my_dict = {}
    for item in items:
        key, value = item
        my_dict[key.upper()] = value
    return my_dict


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


def merge_dicts(*dict_args):
    """
    Given any number of dicts, shallow copy and merge into a new dict,
    precedence goes to key value pairs in latter dicts.
    """
    result = collections.defaultdict(my_func, {})
    for dictionary in dict_args:
        result.update(dictionary)
    return result


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

        DB2_USER            = get_config('DB2_USER', 'some_db2_user')
        DB2_PASSWORD        = get_config('DB2_PASSWORD', 'some_db2_password')
        DB2_DATABASE        = get_config('DB2_DATABASE', 'SAMPLE')
        DB2_ALIAS           = get_config('DB2_ALIAS', 'SAMPLE')
        DB2_HOSTADDR        = get_config('DB2_HOSTADDR', '*LOCAL')
        DB2_INSTANCE        = get_config('DB2_INSTANCE', 'DB2')
        DB2_PORT            = get_config('DB2_PORT', '50000')
        DB2_PROTOCOL        = get_config('DB2_PROTOCOL', 'IPC')
        TEST_SIZE           = get_config('TEST_SIZE', '1000000')
        DB2_ICHUNKSIZE      = get_config('DB2_ICHUNKSIZE', '20000')
        DB2_IDATABUFFERSIZE = get_config('DB2_IDATABUFFERSIZE', '0')
        DB2_TABLESPACE      = get_config('DB2_TABLESPACE', '')
        DB2_COLUMN_ORIENTED = get_config('DB2_COLUMN_ORIENTED', '1')
        DB2_DROPTABLE       = get_config('DB2_DROPTABLE', '1')
        all_keys         = get_my_dict()

    else:
        mylog.error("hello_parquet.ini not present")
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
        'DB2_IDATABUFFERSIZE'     : DB2_IDATABUFFERSIZE,
        'DB2_ICHUNKSIZE'          : DB2_ICHUNKSIZE,
        'DB2_TABLESPACE'          : DB2_TABLESPACE,
        'TEST_SIZE'               : TEST_SIZE })
    my_dict = merge_dicts(my_dict, all_keys)
    return my_dict


def create_df():
    """Create pandas.DataFrame with dummy data and different field types
    """
    v1 = datetime.today()
    v2 = v1 - timedelta(days=5)
    v3 = v1 - timedelta(days=6)
    v4 = v1 - timedelta(days=7)

    d1 = date.today()
    d2 = d1 - timedelta(days=900)
    d3 = date(1981, 10, 10)
    d4 = date(1985, 10, 10)

    t1 = datetime.today().time()
    v2_for_time = v1 - timedelta(hours=3)
    t2 = v2_for_time.time()
    t3 = time(10,10,10, 4300)

    rng = pd.date_range(date.today(), periods=4, freq='H')
    dates = pd.Series([v1, v2, v3, v4])
    mylog.info("dates \n%s" % dates)
    mylog.info("dates.dt.date \n%s" % dates.dt.date)
    mylog.info("dates.dt.date.dtype \n%s" % dates.dt.date.dtype)

    df = pd.DataFrame({ 'c_float64'           : [-1, 1.0, 2.5, 3.0],
                        'c_float32'           : [-1, 1.0, 2.5, 3.0],
                        'c_string'            : ['foo', 'bar', 'baz', 'lola'],
                        'c_boolean'           : [True, False, True, False],
                        'c_datetime'          : [v1, v2 , v3, v4],
                        'c_time'              : [t1, t2, t3, t3],
                        'c_timestamp_1h_frec' : rng,
                        'c_date'              : [d1, d2 , d3, d4]
                        },
                        index=list('abcd'))

    df['c_timestamp_1h_frec'] = pd.to_datetime(df['c_timestamp_1h_frec'], unit='D')
    df['c_date'] = df['c_date'].values.astype('datetime64[D]')
    df['c_float32'] = df['c_float32'].values.astype('float32')
    return df


def create_dummy_data_all_fields(size):
    """Create dummy data pyarrow table with all the different arrow::type fields
    """

    column_names = ["c_uint8", "c_int8", "c_uint16", "c_int16", 
                    "c_uint32", "c_int32", "c_uint64", "c_int64", 
                    "c_float16",
                    "c_float32", "c_float64", "c_bool", "c_date32", 
                    "c_date64", "c_time64_us", "c_time64_ns", "c_time32_ms", 
                    "c_time32_s", "c_timestamp_s", "c_timestamp_ms", 
                    "c_timestamp_us", "c_timestamp_ns", "c_string", 
                    "c_binary",
                    "c_fixed_size_binary", "c_decimal128"]
    arrays = []
    time64_list = []
    time64_ns_list = []
    string_list = []
    fixed_size_binary = []
    decimal_list = []
    t4_ms = time(10, 10, 10, 999999)
    t4_s = time(10, 10, 10, 0)
    ctx = decimal.Context(prec=31, Emax=99999)
    mylog.info("here size %d" % size)
    now = datetime.now()
    dec1 = ctx.create_decimal("1.00000010000")
    dec2 = ctx.create_decimal("1234.5678901234567890123456789")
    for i in range(size):
        t3 = time(10, 10, 10, i % 999999)

        t_nas = time(10, 10, 10, i % 999999)
        #date64_list.append(now)
        time64_list.append(t3)
        time64_ns_list.append(t_nas)
        if i % 2 == 0:
            string_list.append("juana")
        else:
            string_list.append("petra")

        fixed_size_binary.append("same_string_size_again_and_again")
        if i % 2 == 1:
            decimal_list.append(dec1)
        else:
            decimal_list.append(dec2)

        if (i % 100000 == 0):
            mylog.info("creating fake data %d %d" % (i, size))

    t1 = pa.int32()
    t2 = pa.string()
    t3 = pa.binary()
    t4 = pa.binary(10)
    t5 = pa.timestamp('ms')
    t6 = pa.list_(t1)
    mylog.debug("t6 '%s'" % t6)
    fields = [
             pa.field('s0', t1),
             pa.field('s1', t2),
             pa.field('s2', t3),
             pa.field('s4', t4)]
    t7 = pa.struct(fields)
    mylog.debug("t7 '%s'" % t7)

    pd_Series = pd.Series(fixed_size_binary)
    mylog.debug("%s"  % pprint.pformat(dir(pa)))
    mylog.debug("first 4 decimals %s" % decimal_list[0:4])
    mylog.debug("decimal.Context '%s'" % ctx)

    uint8_list   = np.arange( 1, size+1,  1, dtype=np.uint8)
    int8_list    = np.arange(-1,-size-1, -1, dtype=np.int8)
    uint16_list  = np.arange( 1, size+1,  1, dtype=np.uint16)
    int16_list   = np.arange(-1,-size-1, -1, dtype=np.int16)
    uint32_list  = np.arange( 1, size+1,  1, dtype=np.uint32)
    int32_list   = np.arange(-1,-size-1, -1, dtype=np.int32)
    uint64_list  = np.arange( 1, size+1,  1, dtype=np.uint64)
    int64_list   = np.arange(-1,-size-1, -1, dtype=np.int64)
    bool_list    = ( uint64_list % 2 == 0)
    date32_list  = np.arange( 1, size+1,  1, dtype=np.int32)
    float16_list = np.linspace(0.0, 10.0, num=size, dtype=np.float16)
    float32_list = np.linspace(0.0, 10.0, num=size, dtype=np.float32)
    float64_list = np.linspace(0.0, 10.0, num=size, dtype=np.float64)

    date64_list    = np.full(size, now)
    time32_ms_list = np.full(size, t4_ms)
    time32_s_list  = np.full(size, t4_s)


    arr_uint8     = pa.array(uint8_list,        pa.uint8())
    arr_int8      = pa.array(int8_list,         pa.int8())
    arr_uint16    = pa.array(uint16_list,       pa.uint16())
    arr_int16     = pa.array(int16_list,        pa.int16())
    arr_uint32    = pa.array(uint32_list,       pa.uint32())
    arr_int32     = pa.array(int32_list,        pa.int32())
    arr_uint64    = pa.array(uint64_list,       pa.uint64())
    arr_int64     = pa.array(int64_list,        pa.int64())
    arr_float16   = pa.array(float16_list,      pa.float16())
    arr_float32   = pa.array(float32_list,      pa.float32())
    arr_float64   = pa.array(float64_list,      pa.float64())
    arr_bool      = pa.array(bool_list,         pa.bool_())
    arr_date32    = pa.array(date32_list,       pa.date32())
    arr_date64    = pa.array(date64_list,       pa.date64())
    arr_time64_us = pa.array(time64_list,       pa.time64("us"))
    arr_time64_ns         = pa.array(time64_ns_list,    pa.time64("ns"))
    arr_time32_ms         = pa.array(time32_ms_list,    pa.time32("ms"))
    arr_time32_s          = pa.array(time32_s_list,     pa.time32("s"))
    arr_timestamp_s       = pa.array(date64_list,       pa.timestamp("s"))
    arr_timestamp_ms      = pa.array(date64_list,       pa.timestamp("ms"))
    arr_timestamp_us      = pa.array(date64_list,       pa.timestamp("us"))
    arr_timestamp_ns      = pa.array(date64_list,       pa.timestamp("ns"))
    arr_string            = pa.array(string_list,       pa.string())
    arr_binary            = pa.array(string_list,       pa.binary())
    arr_fixed_size_binary = pa.array(pd_Series,         pa.binary(len(fixed_size_binary[0])))
    precision = 31
    scale     = 27
    arr_decimals          = pa.array(decimal_list,      pa.decimal128(precision, scale))

    mylog.debug("arr_time64_ns         %s %s" % (arr_time64_ns, type(arr_time64_ns)))
    mylog.debug("float16_list          %s %s" % (float16_list, type(float16_list)))
    mylog.debug("float32_list          %s %s" % (float32_list, type(float32_list)))
    mylog.debug("float64_list          %s %s" % (float64_list, type(float64_list)))
    mylog.debug("int8_list             %s %s" % (int8_list, type(int8_list)))
    mylog.debug("uint8_list            %s %s" % (uint8_list, type(uint8_list)))
    mylog.debug("int64_list            %s %s" % (int64_list, type(int64_list)))
    mylog.debug("uint64_list           %s %s" % (uint64_list, type(uint64_list)))
    mylog.debug("bool_list             %s %s" % (bool_list, type(bool_list)))
    mylog.debug("arr_fixed_size_binary %s %s" % (arr_fixed_size_binary, type(arr_fixed_size_binary)))
    mylog.debug("arr_decimals          %s %s" % (arr_decimals, type(arr_decimals)))

    arrays.append(arr_uint8)
    arrays.append(arr_int8)
    arrays.append(arr_uint16)
    arrays.append(arr_int16)
    arrays.append(arr_uint32)
    arrays.append(arr_int32)
    arrays.append(arr_uint64)
    arrays.append(arr_int64)
    arrays.append(arr_float16)
    arrays.append(arr_float32)
    arrays.append(arr_float64)
    arrays.append(arr_bool)
    arrays.append(arr_date32)
    arrays.append(arr_date64)
    arrays.append(arr_time64_us)
    arrays.append(arr_time64_ns)
    arrays.append(arr_time32_ms)
    arrays.append(arr_time32_s)
    arrays.append(arr_timestamp_s)
    arrays.append(arr_timestamp_ms)
    arrays.append(arr_timestamp_us)
    arrays.append(arr_timestamp_ns)
    arrays.append(arr_string)
    arrays.append(arr_binary)
    arrays.append(arr_fixed_size_binary)
    arrays.append(arr_decimals)

    table = pa.Table.from_arrays(arrays, column_names, metadata={'a':'pila de datos', 'b' : 'esto es una b'})
    del arrays
    #table = table.drop(["c_timestamp_ns", "c_timestamp_us" , "c_timestamp_s", "c_timestamp_ms"])
    #table = table.drop(["c_decimal128"])
    return table


def do_all_fields_test(conn, iDataBufferSize, iChunkSize, tablespace, column_oriented, drop_table):
    """
    Parameters
    ----------
    conn            : :class:`ibm_db.IBM_DBConnection`
    iDataBufferSize : :obj:`int`
    iChunkSize      : :obj:`int`
    tablespace      : :obj:`str`
    column_oriented : :obj:`int`
    drop_table      : :obj:`int`
    """
    filename = "test_parquet_table"

    start = datetime.now()
    MessageFile = os.path.join("log", "test_parquet.txt")
    try:
        mylog.info("deleting MessageFile '%s'" % MessageFile)
        os.remove(MessageFile)
    except OSError as e:
        mylog.error("%s" % e)

    if column_oriented == '1':
        column_oriented = True
    else:
        column_oriented = False

    if drop_table == '1':
        drop_table = True
    else:
        drop_table = False

    TempFilesPath = os.environ.get("TEMP", None)
    mylog.debug("\nspclient_python.arrow_table_to_db2.__doc__ %s " % spclient_python.arrow_table_to_db2.__doc__)
    """
    Insert the data
    """
    mylog.info("iDataBufferSize '%s' iChunkSize '%s' tablespace '%s' TempFilesPath '%s'" % (
        "{:,}".format(iDataBufferSize),
        "{:,}".format(iChunkSize),
        tablespace,
        TempFilesPath
        ))
    try:
        load_result = spclient_python.arrow_table_to_db2(
                    conn,
                    MessageFile,
                    TempFilesPath,
                    iDataBufferSize,
                    200000,
                    iChunkSize,
                    mylog.info,
                    table_with_dummy_data,
                    tablespace, # "TABLESPACE_NAME"
                    None, # "SCHEMA_NAME"
                    filename,
                    column_oriented, # column oriented row oriented, True or False
                    drop_table)

        mylog.info("load_result \n%s" % pprint.pformat(load_result))
        bytes_allocated = load_result['bytes_allocated']
        mylog.info("load_result bytes_allocated '%s'" % "{:,}".format(bytes_allocated))
        mylog.info("load_result bytes_allocated '%s'" %  humanfriendly.format_size(bytes_allocated, binary=True))

        t_diff = relativedelta(datetime.now(), start)
        seg = (t_diff.hours*60*60)+(t_diff.minutes*60)+t_diff.seconds
        if seg == 0:
            seg = 0.1
        megs_per_seconds = bytes_allocated/(seg * 1024 * 1024)
        mylog.info("Speed %5.5f M/seg" % megs_per_seconds)
    except Exception as e:
        mylog.error("%s %s" % (type(e), e))

    retrieve_data_from_db2(conn, filename)


def retrieve_data_from_db2(conn, filename):
    """Retrieve the data and display it
    """

    sql_str = """
SELECT 
    *
FROM 
    "%s" 

""" % filename

    try:
        stmt = ibm_db.exec_immediate(conn, sql_str)
    except Exception as e:
        mylog.error("Exception %s" % e)
        return

    mytable = Texttable()
    dictionary = ibm_db.fetch_both(stmt)
    if not dictionary:
        mylog.warn("table '%s' is empty" % filename)
        return
    mytable.set_deco(Texttable.HEADER)
    headers = []
    allign = []
    cols_width = []
    cols_dtype = []
    if dictionary:
        for key in dictionary.keys():
            if isinstance(key, str):
                headers.append(key)
                allign.append("l")
                cols_dtype.append("t")
                cols_width.append(len(key))

    mytable.header(headers)
    mytable.set_cols_align(allign)
    mytable.set_header_align(allign)
    mytable.set_cols_width(cols_width)
    mytable.set_cols_dtype(cols_dtype)

    cont  = 0
    while dictionary:
        if (cont % 30000) == 0 or (cont < 5):
            my_row = []
            #print("%s" % type(dictionary["c_decimal128"]))
            for key in dictionary.keys():
                if isinstance(key, str):
                    my_row.append(dictionary[key])

            for pos, len_ in enumerate(cols_width):
                if len_ < len(str(my_row[pos])) :
                    cols_width[pos] = len(str(my_row[pos]))
            mytable.add_row(my_row)

        dictionary = ibm_db.fetch_both(stmt)
        if cont > 100000:
            break
        cont += 1
 
    mytable.set_cols_width(cols_width)
    mylog.info("db2 table \"%s\" data \n%s" % (filename, mytable.draw()))


def read_df_from_db2(conn, metadata, filename):
    key = list(metadata.keys())[0]
    metadata_dict = json.loads(metadata[key])
    columns       = metadata_dict['columns']
    index_columns = metadata_dict['index_columns']
    columns_name_for_select=[]
    for column in columns:
        columns_name_for_select.append('"%s"' % column["field_name"])

    column_str = ""
    for column_name in columns_name_for_select:
        column_str += column_name + ","

    column_str = column_str[:-1]
    #mylog.info("column_str %s" % column_str)
    sql_str = '''
select 
    %s 
from 
    "%s" 
fetch first 
10000 ROWS ONLY
''' % (column_str, filename)

    dbapi_conn = ibm_db_dbi.Connection(conn)
    df_db2 = pd.read_sql(sql_str, dbapi_conn, index_col=index_columns)
    df_db2['c_boolean'] = df_db2['c_boolean'].astype('bool')
    df_db2['c_float32'] = df_db2['c_float32'].astype('float32')
    #df_db2['time'] = df_db2['time'].astype('time64[us]')
    mylog.info("df_db2 from db2\n\n%s\n" % df_db2.head())
    mylog.info("df_db2 from db2\n%s\n\n" % df_db2.dtypes)

def do_pandas_test(conn):
    filename = "test_pandas_df"

    df = create_df()

    mylog.info("df \n%s\n\n" % df.head())
    mylog.info("df \n%s\n\n" % df.dtypes)
    table = pa.Table.from_pandas(df)

    try:
        TempFilesPath = os.environ.get("TEMP", None)
        MessageFile = os.path.join("log", "test_pandas_df.txt")
        column_oriented = False
        drop_table = True
        load_result = spclient_python.arrow_table_to_db2(
                    conn,
                    MessageFile,
                    TempFilesPath,
                    1000,
                    1000,
                    1000,
                    mylog.info,
                    table,
                    None, #"Tablespace name
                    None, # Schema name
                    filename,
                    column_oriented, # column oriented=True row oriented =False
                    drop_table)
        mylog.info("load_result \n%s" % load_result)
        read_df_from_db2(conn, table.schema.metadata, filename)
    except Exception as e:
        mylog.error("%s %s" % (type(e), e))

def connect_to_db2(data_read_ini):

    userid = data_read_ini["DB2_USER"]
    passw  = data_read_ini["DB2_PASSWORD"]
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
    mylog.debug("connecting %s " % connecting_str)
    conn = ibm_db.connect(connecting_str, userid, passw)
    ibm_db.autocommit(conn, ibm_db.SQL_AUTOCOMMIT_ON)
    return conn


if __name__ == "__main__":

    data_read_ini = read_ini()
    conn = connect_to_db2(data_read_ini)

    table_with_dummy_data = create_dummy_data_all_fields(int(data_read_ini["TEST_SIZE"]))
    mylog.debug("table_with_dummy_data %s" % table_with_dummy_data)
    #mylog.info("table_with_dummy_data.schema \n%s" % table_with_dummy_data.schema)
    mylog.info("table_with_dummy_data num_rows    %s num_columns %s" % (
        "{:,}".format(table_with_dummy_data.num_rows),
        table_with_dummy_data.num_columns))

    for key in data_read_ini.keys():
        if key.upper().startswith("SPCLIENT_PYTHON"):
            os.environ[key] = data_read_ini[key]


    mylog.debug ("'%s'" % data_read_ini["SPCLIENT_PYTHON_LOG_COLUMN"])
    mylog.debug ("'%s'" % pprint.pformat(data_read_ini))

    """
    All fields type test
    """
    mylog.debug("%s" % pprint.pformat(data_read_ini))
    do_all_fields_test(conn,
                       int(data_read_ini["DB2_IDATABUFFERSIZE"]),
                       int(data_read_ini["DB2_ICHUNKSIZE"]),
                       data_read_ini["DB2_TABLESPACE"],
                       data_read_ini["DB2_COLUMN_ORIENTED"],
                       data_read_ini["DB2_DROPTABLE"])

    """
    Another test with pandas dataframe
    """
    #do_pandas_test(conn)
