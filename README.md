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

