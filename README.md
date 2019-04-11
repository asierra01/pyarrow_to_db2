# pyarrow_to_db2
ibm_db extension to load a pyarrow table to db2
Initially named spclient_python but in the future the 'official' name could change.
sp for store procedure, client it was a client library not running on db2 backend, python as it was a python library.
```
To run it, go to cextensions
You need pyarrow installed
pip3 install pyarrow
pip3 install numpy
pip3 install pybind11

python3 setup.py build
also 
cmake CMakeLists.txt
make
cd ..
python3 hello_parquet.py
```
hello_parquet.ini contains the connect to db2 credentials.

The function to focus is spclient_python.arrow_table_to_db2 below is the docstring.

```
arrow_table_to_db2 (conn, log_result, DataBufferSize, Savecount, ChunkSize, log, table, tablespace_name, schema_name, table_name, column_oriented, drop_table)

    Parameters
    ----------
    conn             : :class:`ibm_db.IBM_DBConnection` connection object
    log_result       : :obj:`str` log result filename
    DataBufferSize   : :obj:`int  data buffer size`, this could be zero
    Savecount        : :obj:`int` save count, this could be zero
    ChunkSize        : :obj:`int` chunk size
    log              : :func:`log.info` logging info function
    table            : :class:`pyarrow.lib.Table` pyarrow table object
    tablespace_name  : :obj:`str` Table space name
    schema_name      : :obj:`str` Schema name
    table_name       : :obj:`str` Table name
    column_oriented  : :obj:`bool` True or False column oriented table ?
    drop_table       : :obj:`bool` True or False drop the table before inserting ?
```

