# Add executable called "spclient_python" that is built from the source files
# The extensions are automatically found.
cmake_minimum_required (VERSION 3.10.11)

PROJECT(spclient_python LANGUAGES C CXX)
set(SPCLIENT_PYTHON_MAJOR 1)
set(SPCLIENT_PYTHON_MINOR 0)
set(SPCLIENT_PYTHON_PATCH 0)
set(SPCLIENT_PYTHON_VERSION ${SPCLIENT_PYTHON_MAJOR}.${SPCLIENT_PYTHON_MINOR}.${SPCLIENT_PYTHON_PATCH} )

message("Generating spclient_python") 

include(project_helper.cmake)

if (DEFINED  ENV{DB2INCLUDE})
    include_directories("$ENV{DB2INCLUDE}")
    message(STATUS "ENV DB2INCLUDE                 : $ENV{DB2INCLUDE}" )
    message(STATUS "ENV DB2PATH                    : $ENV{DB2PATH}" )

    set (my_DB2INCLUDE $ENV{DB2INCLUDE})

    if (WIN32)
        STRING(REPLACE "\\" "/" my_DB2INCLUDE ${my_DB2INCLUDE} )

        set (sqlutil_h "win64/sqlutil.h" 
                       "${my_DB2INCLUDE}/sqlenv.h"
                       "${my_DB2INCLUDE}/sqlcodes.h"
                       "${my_DB2INCLUDE}/sql.h"
                       "${my_DB2INCLUDE}/sqlcli.h"
                       "${my_DB2INCLUDE}/sqlcli1.h"
                       "${my_DB2INCLUDE}/db2ApiDf.h"
                       "${my_DB2INCLUDE}/sqlsystm.h"
                       "${my_DB2INCLUDE}/sqlda.h"
                       "${my_DB2INCLUDE}/sqlca.h"
                       #"${my_DB2INCLUDE}/sqle819a.h"
                       #"include/utilapi.h"
                       )
    endif(WIN32)

else ()
    message(WARNING "env variable DB2INCLUDE, not set")
endif()

if (WIN32)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -DSPCLIENT_PYTHON)
    find_library(DB2API_LIBRARY  NAMES db2api HINTS $ENV{DB2PATH}\\lib NO_DEFAULT_PATH DOC "db2api.lib library under windows")
    #message(STATUS "DB2API_LIBRARY                 : " ${DB2API_LIBRARY})
    if(EXISTS "${DB2API_LIBRARY}")
        message(STATUS "DB2API_LIBRARY exist           : " ${DB2API_LIBRARY})
    else()
        message(WARNING "DB2API_LIBRARY do not exist                : " ${DB2API_LIBRARY})
        set (DB2API_LIBRARY $ENV{DB2PATH}\\lib\\db2api.lib) 
        #message(WARNING "using DB2API_LIBRARY                       : " ${DB2API_LIBRARY})
    endif()
else()
    add_definitions(-DSPCLIENT_PYTHON)
    find_library(DB2API_LIBRARY NAMES db2 HINTS $ENV{DB2PATH}/lib DOC "db2.lib library under linux/darwin")
endif()

function(set_cpp_files)
    FILE (GLOB CPP_FILES *.cpp )

    FILE (GLOB H_FILES *.h )

    set (CPP_FILES ${CPP_FILES}
         PARENT_SCOPE)

    foreach (CPP_FILE ${CPP_FILES})
        message(STATUS "CPP_FILES                      : " ${CPP_FILE}) 
    endforeach()

    foreach (H_FILE ${H_FILES})
        #message(STATUS "H_FILE                      : " ${H_FILE}) 
    endforeach()

    set (H_FILES ${H_FILES}
         PARENT_SCOPE)
endfunction(set_cpp_files)

function(set_c_files)
    FILE (GLOB C_FILES *.c)
    if(WIN32)
        LIST(APPEND C_FILES win64/utilcli.cpp win64/utilcli.h)
    elseif(APPLE)
        LIST(APPEND C_FILES osx/utilcli.cpp osx/utilcli.h)
    elseif(UNIX AND NOT APPLE)
        LIST(APPEND C_FILES lin64/utilcli.cpp lin64/utilcli.h)
    endif()

    foreach (C_FILE ${C_FILES})
        message(STATUS "C_FILES                        : " ${C_FILE}) 
    endforeach()

    set (C_FILES ${C_FILES}
         PARENT_SCOPE)

endfunction(set_c_files)



# This ensures that things like gnu++11 get passed correctly
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
    #set(CMAKE_SHARED_MODULE_SUFFIX ".pyd" )
    #message(STATUS "CMAKE_SHARED_MODULE_SUFFIX  :" ${CMAKE_SHARED_MODULE_SUFFIX})

    if (IS_DIRECTORY "C:/Python37")
        message(STATUS "Directory exist 'C:/Python37' setting Python3_ROOT_DIR to 'C:/Python37'")
        #set(Python3_ROOT_DIR  C:/Python37)
    elseif (IS_DIRECTORY "E:/Python37")
        message(STATUS "Directory exist 'E:/Python37' setting Python3_ROOT_DIR to 'E:/Python37'")
        #set(Python3_ROOT_DIR  E:/Python37)
    endif()

    find_package(Python3 COMPONENTS Interpreter Compiler Development Numpy)

    if (${Python3_EXECUTABLE} MATCHES "Python3_EXECUTABLE-NOTFOUND")
        message(STATUS "Python3_EXECUTABLE             : " ${Python3_EXECUTABLE})
        set(Python3_EXECUTABLE ${Python3_ROOT_DIR}/python.exe )
    endif()
    get_dll_name()

    #C:\Python37\Lib\site-packages\numpy\core\include

    display_python_var()

    foreach(DIR ${Python3_LIBRARIES})
        message(STATUS "Python3_LIBRARIES              : " ${DIR})
    endforeach()

    message(STATUS "CMAKE_GENERATOR                : " ${CMAKE_GENERATOR})
    message(STATUS "MSVC_TOOLSET_VERSION           : " ${MSVC_TOOLSET_VERSION})

    if (MSVC_TOOLSET_VERSION EQUAL 140)
        set (PROJECT_NAME spclient_python_2015)
    else()
        #message(STATUS "CMAKE_GENERATOR is not Visual Studio 14 2015 Win64")
    endif()

    if (MSVC_TOOLSET_VERSION EQUAL 141)
        if (${CMAKE_GENERATOR} STREQUAL "Visual Studio 16 2019")
            set (PROJECT_NAME spclient_python_2019)
            message(STATUS "spclient_python_2019")
        else()
            message(STATUS "spclient_python_2017")
            set (PROJECT_NAME spclient_python_2017)
        endif()
    else()
        #message(STATUS "CMAKE_GENERATOR is not Visual Studio 15 2017 Win64")
    endif()

    add_definitions( -D_CRT_SECURE_NO_WARNINGS -DNOMINMAX)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:100000")
    message(STATUS "CMAKE_EXE_LINKER_FLAGS         : " ${CMAKE_EXE_LINKER_FLAGS})
    find_arrow_loc()
    find_pybind11_loc()
    clean_pybind11()

    set_python_headers()
    set_pyarrow_headers()
    set_parquet_headers()
    set_cpp_files()
    set_c_files()

    list(APPEND PYTHON_HEADERS ${Python3_INCLUDE_DIRS}/pybind11/pybind11.h)
    list(APPEND PYTHON_HEADERS ${Python3_INCLUDE_DIRS}/pybind11/eval.h)


    add_library (${PROJECT_NAME} SHARED 
                    resource.h
                    Resource.rc
                    ${H_FILES}
                    ${CPP_FILES}
                    ${C_FILES}
                    ${sqlutil_h}
                    ${PYTHON_HEADERS}
                    ${PYARROW_HEADERS}
                    ${PARQUET_HEADERS})

    if(MSVC)
        source_group("Header Files/python"       FILES ${PYTHON_HEADERS})
        source_group("Header Files/parquet"      FILES ${PARQUET_HEADERS})
        source_group("Header Files/pyarrow"      FILES ${PYARROW_HEADERS})
        source_group("Header Files/db2_headers"  FILES ${sqlutil_h})

    endif()

    display_python_headers()
    display_numpy_var()
    display_pyarrow_var()
    display_pyarrow_h()
    include_directories(${Python3_INCLUDE_DIRS})
    include_directories(${Python3_INCLUDE_DIRS}/pybind11)
    include_directories(win64)
    include_directories(${PROJECT_SOURCE_DIR})

    include_directories(${NUMPY_OUT_HEADER})
    include_directories(${PYARROW_OUT_HEADER})
    target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})

    if (DB2API_LIBRARY STREQUAL "DB2API_LIBRARY-NOTFOUND")
        message(WARNING "DB2API_LIBRARY, not found under $ENV{DB2PATH}/lib" )
    else()
        message(STATUS "DB2API_LIBRARY                 : " ${DB2API_LIBRARY})
        target_link_libraries(${PROJECT_NAME} ${DB2API_LIBRARY})
    endif()

   if (PYARROW_RES_LIBRARY_LOC EQUAL 0)
        target_link_libraries(${PROJECT_NAME}
        ${PYARROW_OUT_LIBRARY_LOC}\\parquet.lib
        )
        foreach (PYARROW_OUT_LIBRARY_L ${PYARROW_OUT_LIBRARIES})
            target_link_libraries(${PROJECT_NAME} ${PYARROW_OUT_LIBRARY_LOC}\\${PYARROW_OUT_LIBRARY_L}.lib)
            message(STATUS "adding link library            : " ${PYARROW_OUT_LIBRARY_LOC}\\${PYARROW_OUT_LIBRARY_L}.lib)
        endforeach()

        message(STATUS "adding link library            : " ${PYARROW_OUT_LIBRARY_LOC}\\parquet.lib)
    endif()

    set (COMPILE_PDB_NAME ${PROJECT_NAME})

    foreach (conf ${CMAKE_CONFIGURATION_TYPES})
        message(STATUS "CMAKE_CONFIGURATION_TYPES      : " ${conf})
    endforeach()

    message(STATUS "CMAKE_BUILD_TYPE               : " ${CMAKE_BUILD_TYPE})

    include_directories ("include")

    set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${SPCLIENT_PYTHON_VERSION})
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/SUBSYSTEM:CONSOLE")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG          "/DYNAMICBASE  /LIBPATH:\"Debug\"")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE        "/DYNAMICBASE  /LIBPATH:\"Release\"")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL     "/LIBPATH:\"Release\"")
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/DYNAMICBASE /LIBPATH:\"Release\"")

    set_target_properties(${PROJECT_NAME} PROPERTIES  OUTPUT_NAME "spclient_python" )

    install(TARGETS ${PROJECT_NAME}
            #EXPORT ${PROJECT_NAME}
            RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
            LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/bin)


    #$(OutDir)$(TargetName)$(TargetExt) Visual Studio internal Variables
    set(COPY_COMMAND copy)
    set(PDB_EXT pdb)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                        COMMAND  ${COPY_COMMAND} $(OutDir)$(TargetName)$(TargetExt) $(OutDir)${BUILDNAME_OUT}
                        COMMENT "Copying $(OutDir)${BUILDNAME_OUT}"
                        VERBATIM
                    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                        COMMAND  ${COPY_COMMAND} $(OutDir)$(TargetName)$(TargetExt) ..\\${BUILDNAME_OUT}
                        COMMENT "Copying ..\\${BUILDNAME_OUT}" 
                        VERBATIM
                    )

    STRING(REPLACE ".pyd" ".pdb " BUILDNAME_OUT_PDB ${BUILDNAME_OUT})
    MESSAGE(STATUS "BUILDNAME_OUT                  : "  ${BUILDNAME_OUT})
    MESSAGE(STATUS "BUILDNAME_OUT_PDB              : "  ${BUILDNAME_OUT_PDB})

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                        COMMAND  ${COPY_COMMAND} $(OutDir)$(TargetName).pdb $(OutDir)${BUILDNAME_OUT_PDB}
                        COMMENT "Copying  $(OutDir)${BUILDNAME_OUT_PDB}"
                        DEPENDS ${COPY_COMMAND} $(OutDir)$(TargetName).pdb

                        VERBATIM
                    )

endif(WIN32)

if (UNIX)
    if (APPLE)
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -g3 -Wall -O0 ")
        #set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
        #set(Python3_ROOT_DIR  /usr/local/Cellar/python/3.7.1)
    else()
        #SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -D_GLIBCXX_USE_CXX11_ABI=0 ")
        #I already did set(CMAKE_CXX_STANDARD 11) why do I need to do -std=c++11

        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -D_GLIBCXX_USE_CXX11_ABI=0 ")
    endif()

    message(STATUS "DB2API_LIBRARY                 : " ${DB2API_LIBRARY})
    #set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_VERBOSE_MAKEFILE ON)
    find_package(Python3 COMPONENTS Interpreter Development )

    get_dll_name()
    set_pyarrow_headers()
    set_python_headers()
    set_cpp_files()
    set_c_files()

    add_library (${PROJECT_NAME} SHARED

                    ${CPP_FILES}
                    ${C_FILES}
                    ${H_FILES}
                    ${PYTHON_HEADERS}
                    ${PARQUET_HEADERS}
                    )

    #display_python_var()
    #display_python_headers()

    include_directories(${Python3_INCLUDE_DIRS})

    find_arrow_loc()
    find_pybind11_loc()
    clean_pybind11()

    if (NUMPY_RES_HEADER EQUAL 0)
        STRING(REPLACE "\n" "" NUMPY_OUT_HEADER ${NUMPY_OUT_HEADER} )
        list(APPEND PYTHON_HEADERS ${NUMPY_OUT_HEADER}/numpy/arrayobject.h)
    endif()

    if (PYARROW_RES_HEADER EQUAL 0)
        list(APPEND PYTHON_HEADERS ${PYARROW_OUT_HEADER}/arrow/python/pyarrow.h)
    endif()


    display_numpy_var()
    display_pyarrow_var()
    include_directories(${NUMPY_OUT_HEADER})
    include_directories(${PYARROW_OUT_HEADER})
    include_directories(${PROJECT_SOURCE_DIR})


    target_link_libraries(${PROJECT_NAME} ${Python3_LIBRARIES})

    find_library(LIBDL NAMES dl REQUIRED)
    find_library(LIBARROW_PYTHON HINTS  ${PYARROW_OUT_LIBRARY_LOC} NAMES arrow_python REQUIRED) #HINTS  ${PYARROW_OUT_LIBRARY_LOC}  
    find_library(LIBARROW        HINTS  ${PYARROW_OUT_LIBRARY_LOC} NAMES arrow REQUIRED)
    find_library(LIBPARQUET      HINTS  ${PYARROW_OUT_LIBRARY_LOC} NAMES parquet REQUIRED)

    #if (PYARROW_RES_LIBRARY_LOC EQUAL 0)
    #    target_link_libraries(${PROJECT_NAME}
    #    ${PYARROW_OUT_LIBRARY_LOC}\\parquet.juana
    #    )
    #    foreach (PYARROW_OUT_LIBRARY_L ${PYARROW_OUT_LIBRARIES})
    #        target_link_libraries(${PROJECT_NAME} ${PYARROW_OUT_LIBRARY_LOC}\\${PYARROW_OUT_LIBRARY_L}.juana)
    #        message(STATUS "adding link library            : " ${PYARROW_OUT_LIBRARY_LOC}\\${PYARROW_OUT_LIBRARY_L}.juana)
    #    endforeach()
    #
    #    message(STATUS "adding link library            : " ${PYARROW_OUT_LIBRARY_LOC}\\parquet.juana)
    #endif()

    #if (${LIBARROW_PYTHON} STREQUAL "LIBARROW_PYTHON-NOTFOUND")
    #    message(WARNING "LIBARROW_PYTHON = LIBARROW_PYTHON-NOTFOUND")
    #    if (NOT APPLE)
    #        if (EXISTS "/home/jorge/.local/lib/python3.7/site-packages/pyarrow/libarrow_python.so")
    #            set(LIBARROW_PYTHON "/home/jorge/.local/lib/python3.7/site-packages/pyarrow/libarrow_python.so")
    #        endif()
    #    endif()
    #endif()

    message(STATUS "LIBDL                          : " ${LIBDL})
    message(STATUS "LIBARROW                       : " ${LIBARROW})
    message(STATUS "LIBARROW_PYTHON                : " ${LIBARROW_PYTHON})
    message(STATUS "PYARROW_OUT_LIBRARY_LOC        : " ${PYARROW_OUT_LIBRARY_LOC})
    message(STATUS "LIBPARQUET                     : " ${LIBPARQUET})
    message(STATUS "CMAKE_SYSTEM_NAME              : " ${CMAKE_SYSTEM_NAME})
    if (APPLE)
        message(STATUS "CURRENT_OSX_VERSION            : " ${CURRENT_OSX_VERSION})
        message(STATUS "CMAKE_HOST_SYSTEM              : " ${CMAKE_HOST_SYSTEM})
    endif(APPLE)

    display_pyarrow_h()

    if (APPLE)
        include_directories(osx)
        include_directories(include)
        target_link_libraries(${PROJECT_NAME}
                              ${LIBDL}
                              ${DB2API_LIBRARY}
                              stdc++
                              c++
                              ${LIBARROW}
                              ${LIBARROW_PYTHON}
                              ${LIBPARQUET})
    else() #UNIX excluding APPLE
        include_directories(lin64)
        include_directories(include)
        target_link_libraries(${PROJECT_NAME}
                              ${LIBDL}
                              ${DB2API_LIBRARY}
                              ${LIBARROW}
                              ${LIBARROW_PYTHON}
                              ${LIBPARQUET})
    endif ()
    MESSAGE(STATUS "BUILDNAME_OUT                  : "  ${BUILDNAME_OUT})

    set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${SPCLIENT_PYTHON_VERSION})

    set(COPY_COMMAND cp)
    set (copySource ${CMAKE_SHARED_LIBRARY_PREFIX}${CMAKE_PROJECT_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})
    set (COPY_COMMAND "cp")
    set (copyDest ../${BUILDNAME_OUT})
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                        COMMAND  ${COPY_COMMAND} ${copySource} ${copyDest} 
                    )

endif(UNIX)

get_property(include_dirs DIRECTORY PROPERTY INCLUDE_DIRECTORIES)
foreach (include_dir ${include_dirs})
    message(STATUS "include_dir                    : " ${include_dir})
endforeach()

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})

    #message(STATUS "CMAKE Variables ${_variableName}=${${_variableName}}")

endforeach()
