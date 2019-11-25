if (NOT DEFINED ENV{DB2INCLUDE})
    message(WARNING "env variable DB2INCLUDE, not set")
    if (UNIX)
        if(IS_DIRECTORY "$ENV{HOME}/sqllib/include")
            message (STATUS "Directory exist $ENV{HOME}/sqllib/include")
            set (ENV{DB2INCLUDE} "$ENV{HOME}/sqllib/include")
        else()
            message (WARNING  "Directory doesnt exist $ENV{HOME}/sqllib/include")
        endif()
    else()
        if(IS_DIRECTORY "$ENV{ProgramFiles}/IBM/SQLLIB/include")
            message (STATUS "Directory exist $ENV{ProgramFiles}/IBM/SQLLIB/include")
            set (ENV{DB2INCLUDE} "$ENV{ProgramFiles}/IBM/SQLLIB/include")
        else()
            message (WARNING  "Directory doesnt exist $ENV{ProgramFiles}/IBM/SQLLIB/include")
        endif()
        if(IS_DIRECTORY "$ENV{ProgramFiles}/IBM/SQLLIB_01/include")
            message (STATUS "Directory exist $ENV{ProgramFiles}/IBM/SQLLIB_01/include")
            set (ENV{DB2INCLUDE} "$ENV{ProgramFiles}/IBM/SQLLIB_01/include")
        else()
            message (WARNING  "Directory doesnt exist $ENV{ProgramFiles}/IBM/SQLLIB_01/include")
        endif()

    endif()
endif()

if (NOT DEFINED ENV{DB2PATH})
    message(WARNING "env variable DB2PATH, not set")
    if (UNIX)
        if(IS_DIRECTORY "$ENV{HOME}/sqllib")
            message (STATUS "Directory exist $ENV{HOME}/sqllib")
            set (ENV{DB2PATH} "$ENV{HOME}/sqllib")
        else()
            message (WARNING  "Directory doesnt exist $ENV{HOME}/sqllib")
        endif()
    else()
        if(IS_DIRECTORY "$ENV{ProgramFiles}/IBM/SQLLIB")
            message (STATUS "Directory exist $ENV{ProgramFiles}/IBM/SQLLIB")
            set (ENV{DB2PATH} "$ENV{ProgramFiles}/IBM/SQLLIB")
        else()
            message (WARNING  "Directory doesnt exist $ENV{ProgramFiles}/IBM/SQLLIB")
        endif()
        if(IS_DIRECTORY "$ENV{ProgramFiles}/IBM/SQLLIB_01")
            message (STATUS "Directory exist $ENV{ProgramFiles}/IBM/SQLLIB_01")
            set (ENV{DB2PATH} "$ENV{ProgramFiles}/IBM/SQLLIB_01")
        else()
            message (WARNING  "Directory doesnt exist $ENV{ProgramFiles}/IBM/SQLLIB_01")
        endif()

    endif()
endif()

function (set_parquet_headers)
    set (PARQUET_HEADERS 
         ${PYARROW_OUT_HEADER}/parquet/exception.h
        PARENT_SCOPE)
endfunction(set_parquet_headers)

function (set_pyarrow_headers)
    message(STATUS "PROJECT_SOURCE_DIR             : " ${PROJECT_SOURCE_DIR})
    set (PYARROW_HEADERS 
         ${PYARROW_OUT_HEADER}/arrow/python/pyarrow.h
         ${PYARROW_OUT_HEADER}/arrow/api.h
         ${PYARROW_OUT_HEADER}/arrow/io/api.h
         ${PROJECT_SOURCE_DIR}/include/arrow/python/util/datetime.h
        PARENT_SCOPE)
endfunction(set_pyarrow_headers)

function(set_python_headers)

    set (PYTHON_HEADERS ${Python3_INCLUDE_DIRS}/Python.h
                        ${Python3_INCLUDE_DIRS}/pythread.h)

    if (NUMPY_RES_HEADER EQUAL 0)
        STRING(REPLACE "\\" "/" NUMPY_OUT_HEADER ${NUMPY_OUT_HEADER} )
        list(APPEND PYTHON_HEADERS ${NUMPY_OUT_HEADER}/numpy/arrayobject.h)
    endif()

    if (PYARROW_RES_HEADER EQUAL 0)
        STRING(REPLACE "\\" "/" PYARROW_OUT_HEADER ${PYARROW_OUT_HEADER} )
        set (PYARROW_OUT_HEADER ${PYARROW_OUT_HEADER} PARENT_SCOPE)
        # I need to make the changes global as PYARROW_OUT_HEADER outside this function
        list(APPEND PYTHON_HEADERS ${PYARROW_OUT_HEADER}/arrow/python/pyarrow.h)
    endif()


    set (PYTHON_HEADERS ${PYTHON_HEADERS} PARENT_SCOPE)

endfunction(set_python_headers)

function(display_python_var)
    message(STATUS "Python3_INCLUDE_DIRS           : " ${Python3_INCLUDE_DIRS})
    message(STATUS "Python3_LIBRARY_DIRS           : " ${Python3_LIBRARY_DIRS})
    message(STATUS "Python3_VERSION                : " ${Python3_VERSION})
    message(STATUS "Python3_EXECUTABLE             : " ${Python3_EXECUTABLE})
    message(STATUS "Python3_ROOT_DIR               : " ${Python3_ROOT_DIR}) #this variable if set is used as a Hint to find Python3 on Darwin is set
    message(STATUS "Python3_SITELIB                : " ${Python3_SITELIB})
    message(STATUS "Python3_LIBRARY_RELEASE        : " ${Python3_LIBRARY_RELEASE})
    message(STATUS "Python3_LIBRARY_DEBUG          : " ${Python3_LIBRARY_DEBUG})
    message(STATUS "Python3_RUNTIME_LIBRARY_RELEASE: " ${Python3_RUNTIME_LIBRARY_RELEASE})
    message(STATUS "Python3_RUNTIME_LIBRARY_DEBUG  : " ${Python3_RUNTIME_LIBRARY_DEBUG})
endfunction(display_python_var)

function(display_pyarrow_h)
    foreach(arrow_h ${PYARROW_HEADERS})
        message(STATUS "arrow_h                        : " ${arrow_h})
    endforeach()

    foreach(parquet_h ${PARQUET_HEADERS})
        message(STATUS "parquet_h                      : " ${parquet_h})
    endforeach()
endfunction(display_pyarrow_h)


function(display_numpy_var)
    message(STATUS "NUMPY_OUT_HEADER               : " ${NUMPY_OUT_HEADER})
endfunction(display_numpy_var)

function(display_pyarrow_var)
    message(STATUS "PYARROW_OUT_HEADER             : " ${PYARROW_OUT_HEADER})
    message(STATUS "PYARROW_OUT_LIBRARY_LOC        : " ${PYARROW_OUT_LIBRARY_LOC})
    message(STATUS "SPCLIENT_PYTHON_VERSION        : " ${SPCLIENT_PYTHON_VERSION})
    message(STATUS "NUMPY_VERSION                  : " ${NUMPY_OUT_VERSION})
    message(STATUS "PYBIND11_VERSION               : " ${PYBIND11_OUT_VERSION})
    message(STATUS "PYARROW_VERSION                : " ${PYARROW_OUT_VERSION})
    message(STATUS "DB2 SDK Ver                    : " ${DB2VER_OUT})
endfunction(display_pyarrow_var)

function (find_pybind11_loc)
    if (NOT ${Python3_EXECUTABLE} MATCHES "Python3_EXECUTABLE-NOTFOUND")
        execute_process(COMMAND ${Python3_EXECUTABLE} -m pybind11 --includes
                        RESULT_VARIABLE PYBIND11_RES_HEADER
                        OUTPUT_VARIABLE PYBIND11_OUT_HEADER)

        if (PYBIND11_RES_HEADER EQUAL 0)
            STRING(REPLACE "\n" "" PYBIND11_OUT_HEADER ${PYBIND11_OUT_HEADER} )
        else()
            message(WARNING "PYBIND11_RES_HEADER not equal 0 PYBIND11_RES_HEADER=" ${PYBIND11_RES_HEADER})
        endif()

        set (PYBIND11_OUT_HEADER ${PYBIND11_OUT_HEADER}
             PARENT_SCOPE)

        set (PYBIND11_RES_HEADER ${PYBIND11_RES_HEADER}
             PARENT_SCOPE)
    else()
        message(STATUS "Cant run python.exe as Python3_EXECUTABLE  : " ${Python3_EXECUTABLE})
    endif()
endfunction(find_pybind11_loc)

function (find_arrow_loc)
    message(STATUS "Executing " ${Python3_EXECUTABLE} " " -c " \"import numpy; print (numpy.get_include())\"")

    execute_process(COMMAND ${Python3_EXECUTABLE} -c "import numpy; print (numpy.get_include())"
                    RESULT_VARIABLE NUMPY_RES_HEADER
                    OUTPUT_VARIABLE NUMPY_OUT_HEADER)

    execute_process(COMMAND ${Python3_EXECUTABLE} -c "import pyarrow; print (pyarrow.get_include())"
                    RESULT_VARIABLE PYARROW_RES_HEADER
                    OUTPUT_VARIABLE PYARROW_OUT_HEADER)

    execute_process(COMMAND ${Python3_EXECUTABLE} -c "import pyarrow; print (pyarrow.get_library_dirs()[0])"
                    RESULT_VARIABLE PYARROW_RES_LIBRARY_LOC
                    OUTPUT_VARIABLE PYARROW_OUT_LIBRARY_LOC)

    execute_process(COMMAND ${Python3_EXECUTABLE} -c "import pyarrow; print (pyarrow.get_libraries())"
                    RESULT_VARIABLE PYARROW_RES_LIBRARIES
                    OUTPUT_VARIABLE PYARROW_OUT_LIBRARIES)

    execute_process(COMMAND ${Python3_EXECUTABLE} -c "import pyarrow; print (pyarrow.__version__)"
                    RESULT_VARIABLE PYARROW_RES_VERSION
                    OUTPUT_VARIABLE PYARROW_OUT_VERSION)

    execute_process(COMMAND ${Python3_EXECUTABLE} -c "import numpy; print (numpy.__version__)"
                    RESULT_VARIABLE NUMPY_RES_VERSION
                    OUTPUT_VARIABLE NUMPY_OUT_VERSION)

    execute_process(COMMAND ${Python3_EXECUTABLE} -c "import pybind11; print (pybind11.__version__)"
                    RESULT_VARIABLE PYBIND11_RES_VERSION
                    OUTPUT_VARIABLE PYBIND11_OUT_VERSION)

    execute_process(COMMAND ${Python3_EXECUTABLE} find_db2_ver.py
                    RESULT_VARIABLE DB2VER_RES_OUT
                    OUTPUT_VARIABLE DB2VER_OUT)

    if (NUMPY_RES_HEADER EQUAL 0)
        STRING(REPLACE "\n" "" NUMPY_OUT_HEADER ${NUMPY_OUT_HEADER} )
    else()
         message(FATAL_ERROR "NUMPY_RES_HEADER not zero                 : " ${NUMPY_RES_HEADER})
    endif()

    if (PYARROW_RES_LIBRARY_LOC EQUAL 0)
        STRING(REPLACE "\n" "" PYARROW_OUT_LIBRARY_LOC ${PYARROW_OUT_LIBRARY_LOC} )
        STRING(REPLACE "\\" "/" PYARROW_OUT_LIBRARY_LOC ${PYARROW_OUT_LIBRARY_LOC} )
    else()
         message(FATAL_ERROR "PYARROW_RES_LIBRARY_LOC not zero                 : " ${PYARROW_RES_LIBRARY_LOC})
    endif()

    if (PYARROW_RES_HEADER EQUAL 0)
        STRING(REPLACE "\n" "" PYARROW_OUT_HEADER ${PYARROW_OUT_HEADER} )
    else()
         message(FATAL_ERROR "PYARROW_RES_HEADER not zero                 : " ${PYARROW_RES_HEADER})
    endif()

    if (PYARROW_RES_VERSION EQUAL 0)
        STRING(REPLACE "\n" "" PYARROW_OUT_VERSION ${PYARROW_OUT_VERSION} )
    else()
         message(FATAL_ERROR "PYARROW_RES_VERSION not zero                 : " ${PYARROW_RES_VERSION})
    endif()

    STRING(REPLACE "\n" "" NUMPY_OUT_VERSION ${NUMPY_OUT_VERSION} )
    STRING(REPLACE "\n" "" PYBIND11_OUT_VERSION ${PYBIND11_OUT_VERSION} )
    STRING(REPLACE "\n" "" DB2VER_OUT ${DB2VER_OUT} )

    if (PYARROW_RES_LIBRARIES EQUAL 0)
        STRING(REPLACE "\n" "" PYARROW_OUT_LIBRARIES ${PYARROW_OUT_LIBRARIES} )
        STRING(REPLACE "[" "" PYARROW_OUT_LIBRARIES ${PYARROW_OUT_LIBRARIES} )
        STRING(REPLACE "]" "" PYARROW_OUT_LIBRARIES ${PYARROW_OUT_LIBRARIES} )
        STRING(REPLACE "'" "" PYARROW_OUT_LIBRARIES ${PYARROW_OUT_LIBRARIES} )
        STRING(REPLACE ", " ";" PYARROW_OUT_LIBRARIES ${PYARROW_OUT_LIBRARIES} )
    else()
         message(FATAL_ERROR "PYARROW_RES_LIBRARIES not zero                 : " ${PYARROW_RES_LIBRARIES})
    endif()
 
    set (NUMPY_RES_HEADER ${NUMPY_RES_HEADER}
         PARENT_SCOPE)

    set (NUMPY_OUT_HEADER ${NUMPY_OUT_HEADER}
         PARENT_SCOPE)

    set (PYARROW_RES_HEADER ${PYARROW_RES_HEADER}
         PARENT_SCOPE)

    set (PYARROW_OUT_HEADER ${PYARROW_OUT_HEADER}
         PARENT_SCOPE)

    set (PYARROW_RES_LIBRARY_LOC ${PYARROW_RES_LIBRARY_LOC}
         PARENT_SCOPE)

    set (PYARROW_OUT_LIBRARY_LOC ${PYARROW_OUT_LIBRARY_LOC}
         PARENT_SCOPE)

    set (PYARROW_OUT_LIBRARIES ${PYARROW_OUT_LIBRARIES}
         PARENT_SCOPE)

    set (PYARROW_OUT_VERSION ${PYARROW_OUT_VERSION}
         PARENT_SCOPE)

    set (NUMPY_OUT_VERSION ${NUMPY_OUT_VERSION}
         PARENT_SCOPE)

    set (PYBIND11_OUT_VERSION ${PYBIND11_OUT_VERSION}
         PARENT_SCOPE)

    set (DB2VER_OUT ${DB2VER_OUT}
         PARENT_SCOPE)

endfunction(find_arrow_loc)

function (get_dll_name)
    execute_process(COMMAND ${Python3_EXECUTABLE} build_name.py
                        RESULT_VARIABLE BUILDNAME_RES
                        OUTPUT_VARIABLE BUILDNAME_OUT)
    #message(STATUS "BUILDNAME_OUT  " ${BUILDNAME_OUT})
    if (BUILDNAME_RES EQUAL 0)
        STRING(REPLACE "\n" "" BUILDNAME_OUT ${BUILDNAME_OUT} )
    else()
        message(WARNING "BUILDNAME_RES not equal 0 BUILDNAME_RES=" ${BUILDNAME_RES})
    endif()
    set (BUILDNAME_OUT ${BUILDNAME_OUT}
             PARENT_SCOPE)
endfunction (get_dll_name)

function(display_python_headers)

    foreach (PYTHON_HEADER ${PYTHON_HEADERS})
        message(STATUS "PYTHON_HEADER                  : " ${PYTHON_HEADER})
    endforeach()

endfunction(display_python_headers)

function(clean_pybind11)
    if (PYBIND11_RES_HEADER EQUAL 0)
        STRING(REPLACE "-I" "" PYBIND11_OUT_HEADER ${PYBIND11_OUT_HEADER} )
        STRING(REPLACE " " ";" PYBIND11_OUT_HEADER_LIST ${PYBIND11_OUT_HEADER} )
        foreach (PYBIND11_PATH ${PYBIND11_OUT_HEADER_LIST})
            include_directories(${PYBIND11_PATH})
            message(STATUS "PYBIND11_PATH                  : " ${PYBIND11_PATH})
        endforeach()
    endif()
endfunction(clean_pybind11)


