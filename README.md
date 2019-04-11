# pyarrow_to_db2
ibm_db extension to load a pyarrow table to db2
```
To run it, go to cextensions
You need pyarrow installed
pip3 install pyarrow
pip3 install numpy
pip3 install pybind11

python3 setup.py build
cd ..
python3 hello_parquet.py
```
hello_parquet.ini contains the connect to db2 credentilas.

