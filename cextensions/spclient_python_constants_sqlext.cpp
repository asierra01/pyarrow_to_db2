#include "spclient_python_common_cpp.h"


int add_sqlext(PyObject* m)
{
    int ret;

    ret = PyModule_AddIntMacro(m, SQL_SPEC_MAJOR);
    ret = PyModule_AddIntMacro(m, SQL_SPEC_MINOR);
    ret = PyModule_AddStringMacro(m, SQL_SPEC_STRING);

    ret = PyModule_AddIntMacro(m, SQL_SQLSTATE_SIZE);/* size of SQLSTATE */
    ret = PyModule_AddIntMacro(m, SQL_MAX_DSN_LENGTH);
    ret = PyModule_AddIntMacro(m, SQL_MAX_OPTION_STRING_LENGTH);
    ret = PyModule_AddIntMacro(m, SQL_NO_DATA_FOUND);
    ret = PyModule_AddIntMacro(m, SQL_HANDLE_SENV);

    /* env attribute */
#if (ODBCVER >= 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ODBC_VERSION);//               200
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONNECTION_POOLING);//         201
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CP_MATCH);//                   202
#endif  /* ODBCVER >= 0x0300 */

#if (ODBCVER >= 0x0300)
    /* values for SQL_ATTR_CONNECTION_POOLING */
    ret = PyModule_AddIntMacro(m, SQL_CP_OFF);//                          0UL
    ret = PyModule_AddIntMacro(m, SQL_CP_ONE_PER_DRIVER);//               1UL
    ret = PyModule_AddIntMacro(m, SQL_CP_ONE_PER_HENV);//                 2UL
    ret = PyModule_AddIntMacro(m, SQL_CP_DEFAULT);//                      SQL_CP_OFF

/* values for SQL_ATTR_CP_MATCH */
    ret = PyModule_AddIntMacro(m, SQL_CP_STRICT_MATCH);//                 0UL
    ret = PyModule_AddIntMacro(m, SQL_CP_RELAXED_MATCH);//                1UL
    ret = PyModule_AddIntMacro(m, SQL_CP_MATCH_DEFAULT);//                SQL_CP_STRICT_MATCH

/* values for SQL_ATTR_ODBC_VERSION */
    ret = PyModule_AddIntMacro(m, SQL_OV_ODBC2);//                        2UL
    ret = PyModule_AddIntMacro(m, SQL_OV_ODBC3);//                        3UL
#endif  /* ODBCVER >= 0x0300 */

    ret = PyModule_AddIntMacro(m, SQL_OV_ODBC3_80);

    /* connection attributes */
    ret = PyModule_AddIntMacro(m, SQL_ACCESS_MODE);//                 101
    ret = PyModule_AddIntMacro(m, SQL_AUTOCOMMIT);//                  102
    ret = PyModule_AddIntMacro(m, SQL_LOGIN_TIMEOUT);//               103
    ret = PyModule_AddIntMacro(m, SQL_OPT_TRACE);//                   104
    ret = PyModule_AddIntMacro(m, SQL_OPT_TRACEFILE);//               105
    ret = PyModule_AddIntMacro(m, SQL_TRANSLATE_DLL);//               106
    ret = PyModule_AddIntMacro(m, SQL_TRANSLATE_OPTION);//            107
    ret = PyModule_AddIntMacro(m, SQL_TXN_ISOLATION);//               108
    ret = PyModule_AddIntMacro(m, SQL_CURRENT_QUALIFIER);//           109
    ret = PyModule_AddIntMacro(m, SQL_ODBC_CURSORS);//                110
    ret = PyModule_AddIntMacro(m, SQL_QUIET_MODE);//                  111
    ret = PyModule_AddIntMacro(m, SQL_PACKET_SIZE);//                 112

    /* connection attributes with new names */
#if (ODBCVER >= 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ACCESS_MODE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_AUTOCOMMIT);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONNECTION_TIMEOUT);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURRENT_CATALOG);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DISCONNECT_BEHAVIOR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ENLIST_IN_DTC);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ENLIST_IN_XA);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOGIN_TIMEOUT);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ODBC_CURSORS);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PACKET_SIZE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_QUIET_MODE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TRACE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TRACEFILE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TRANSLATE_LIB);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TRANSLATE_OPTION);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TXN_ISOLATION);
#endif  /* ODBCVER >= 0x0300 */


    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONNECTION_DEAD);//    1209    /* GetConnectAttr only */

#if (ODBCVER >= 0x0351)
/*  ODBC Driver Manager sets this connection attribute to a unicode driver
    (which supports SQLConnectW) when the application is an ANSI application
    (which calls SQLConnect, SQLDriverConnect, or SQLBrowseConnect).
    This is SetConnectAttr only and application does not set this attribute
    This attribute was introduced because some unicode driver's some APIs may
    need to behave differently on ANSI or Unicode applications. A unicode
    driver, which  has same behavior for both ANSI or Unicode applications,
    should return SQL_ERROR when the driver manager sets this connection
    attribute. When a unicode driver returns SQL_SUCCESS on this attribute,
    the driver manager treates ANSI and Unicode connections differently in
    connection pooling.
*/
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ANSI_APP);//           115
#endif

#if (ODBCVER >= 0x0380)
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RESET_CONNECTION);//   116
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ASYNC_DBC_FUNCTIONS_ENABLE);//    117
#endif

    /* SQL_ACCESS_MODE options */
    ret = PyModule_AddIntMacro(m, SQL_MODE_READ_WRITE);//             0UL
    ret = PyModule_AddIntMacro(m, SQL_MODE_READ_ONLY);//              1UL
    ret = PyModule_AddIntMacro(m, SQL_MODE_READ_WRITE);//

    /*SQL_AUTOCOMMIT options*/
    ret = PyModule_AddIntMacro(m, SQL_AUTOCOMMIT_OFF);
    ret = PyModule_AddIntMacro(m, SQL_AUTOCOMMIT_ON);
#ifndef SQL_AUTOCOMMIT_DEFERRED
#define SQL_AUTOCOMMIT_DEFERRED  2UL
#endif
    ret = PyModule_AddIntMacro(m, SQL_AUTOCOMMIT_DEFERRED);
    ret = PyModule_AddIntMacro(m, SQL_AUTOCOMMIT_DEFAULT);

    /* SQL_LOGIN_TIMEOUT options */
    ret = PyModule_AddIntMacro(m, SQL_LOGIN_TIMEOUT_DEFAULT);//       15UL

/* SQL_OPT_TRACE options */
    ret = PyModule_AddIntMacro(m, SQL_OPT_TRACE_OFF);//               0UL
    ret = PyModule_AddIntMacro(m, SQL_OPT_TRACE_ON);//                1UL
    ret = PyModule_AddIntMacro(m, SQL_OPT_TRACE_DEFAULT);//           SQL_OPT_TRACE_OFF
    ret = PyModule_AddStringMacro(m, SQL_OPT_TRACE_FILE_DEFAULT);//      "\\SQL.LOG"

/* SQL_ODBC_CURSORS options */
    ret = PyModule_AddIntMacro(m, SQL_CUR_USE_IF_NEEDED);//           0UL
    ret = PyModule_AddIntMacro(m, SQL_CUR_USE_ODBC);//                1UL
    ret = PyModule_AddIntMacro(m, SQL_CUR_USE_DRIVER);//              2UL
    ret = PyModule_AddIntMacro(m, SQL_CUR_DEFAULT);//                 SQL_CUR_USE_DRIVER

#if (ODBCVER >= 0x0300)
/* values for SQL_ATTR_DISCONNECT_BEHAVIOR */
ret = PyModule_AddIntMacro(m, SQL_DB_RETURN_TO_POOL);//           0UL
ret = PyModule_AddIntMacro(m, SQL_DB_DISCONNECT);//               1UL
ret = PyModule_AddIntMacro(m, SQL_DB_DEFAULT);//                  SQL_DB_RETURN_TO_POOL

/* values for SQL_ATTR_ENLIST_IN_DTC */
ret = PyModule_AddIntMacro(m, SQL_DTC_DONE);//                    0L
#endif  /* ODBCVER >= 0x0300 */

/* values for SQL_ATTR_CONNECTION_DEAD */
ret = PyModule_AddIntMacro(m, SQL_CD_TRUE);//                     1L      /* Connection is closed/dead */
ret = PyModule_AddIntMacro(m, SQL_CD_FALSE);//                    0L      /* Connection is open/available */

/* values for SQL_ATTR_ANSI_APP */
#if (ODBCVER >= 0x0351)
ret = PyModule_AddIntMacro(m, SQL_AA_TRUE);//                     1L  /* the application is an ANSI app */
ret = PyModule_AddIntMacro(m, SQL_AA_FALSE);//                    0L  /* the application is a Unicode app */
#endif

/* values for SQL_ATTR_RESET_CONNECTION */
#if (ODBCVER >= 0x0380)
ret = PyModule_AddIntMacro(m, SQL_RESET_CONNECTION_YES);//        1UL
#endif

/* values for SQL_ATTR_ASYNC_DBC_FUNCTIONS_ENABLE */
#if (ODBCVER >= 0x0380)
ret = PyModule_AddIntMacro(m, SQL_ASYNC_DBC_ENABLE_ON);//         1UL
ret = PyModule_AddIntMacro(m, SQL_ASYNC_DBC_ENABLE_OFF);//        0UL
ret = PyModule_AddIntMacro(m, SQL_ASYNC_DBC_ENABLE_DEFAULT);//	SQL_ASYNC_DBC_ENABLE_OFF
#endif /* ODBCVER >= 0x0380 */

/* statement attributes */
ret = PyModule_AddIntMacro(m, SQL_QUERY_TIMEOUT);//       0
ret = PyModule_AddIntMacro(m, SQL_MAX_ROWS);//            1
ret = PyModule_AddIntMacro(m, SQL_NOSCAN);//              2
ret = PyModule_AddIntMacro(m, SQL_MAX_LENGTH);//          3
ret = PyModule_AddIntMacro(m, SQL_ASYNC_ENABLE);//        4   /* same as SQL_ATTR_ASYNC_ENABLE */
ret = PyModule_AddIntMacro(m, SQL_BIND_TYPE);//           5
ret = PyModule_AddIntMacro(m, SQL_CURSOR_TYPE);//         6
ret = PyModule_AddIntMacro(m, SQL_CONCURRENCY);//         7
ret = PyModule_AddIntMacro(m, SQL_KEYSET_SIZE);//         8
ret = PyModule_AddIntMacro(m, SQL_ROWSET_SIZE);//         9
ret = PyModule_AddIntMacro(m, SQL_SIMULATE_CURSOR);//     10
ret = PyModule_AddIntMacro(m, SQL_RETRIEVE_DATA);//       11
ret = PyModule_AddIntMacro(m, SQL_USE_BOOKMARKS);//       12
ret = PyModule_AddIntMacro(m, SQL_GET_BOOKMARK);//        13      /*      GetStmtOption Only */
ret = PyModule_AddIntMacro(m, SQL_ROW_NUMBER);//          14      /*      GetStmtOption Only */

/* statement attributes for ODBC 3.0 */
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_ATTR_ASYNC_ENABLE);//               4
ret = PyModule_AddIntMacro(m, SQL_ATTR_CONCURRENCY);//                SQL_CONCURRENCY
ret = PyModule_AddIntMacro(m, SQL_ATTR_CURSOR_TYPE);//                SQL_CURSOR_TYPE
ret = PyModule_AddIntMacro(m, SQL_ATTR_ENABLE_AUTO_IPD);//            15
ret = PyModule_AddIntMacro(m, SQL_ATTR_FETCH_BOOKMARK_PTR);//         16
ret = PyModule_AddIntMacro(m, SQL_ATTR_KEYSET_SIZE);//                SQL_KEYSET_SIZE
ret = PyModule_AddIntMacro(m, SQL_ATTR_MAX_LENGTH);//                 SQL_MAX_LENGTH
ret = PyModule_AddIntMacro(m, SQL_ATTR_MAX_ROWS);//                   SQL_MAX_ROWS
ret = PyModule_AddIntMacro(m, SQL_ATTR_NOSCAN);//                     SQL_NOSCAN
ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_BIND_OFFSET_PTR);//      17
ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_BIND_TYPE);//            18
ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_OPERATION_PTR);//        19
ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_STATUS_PTR);//           20
ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAMS_PROCESSED_PTR);//       21
ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAMSET_SIZE);//              22
ret = PyModule_AddIntMacro(m, SQL_ATTR_QUERY_TIMEOUT);//              SQL_QUERY_TIMEOUT
ret = PyModule_AddIntMacro(m, SQL_ATTR_RETRIEVE_DATA);//              SQL_RETRIEVE_DATA
ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_BIND_OFFSET_PTR);//        23
ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_BIND_TYPE);//              SQL_BIND_TYPE
ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_NUMBER);//                 SQL_ROW_NUMBER      /*GetStmtAttr*/
ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_OPERATION_PTR);//          24
ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_STATUS_PTR);//             25
ret = PyModule_AddIntMacro(m, SQL_ATTR_ROWS_FETCHED_PTR);//           26
ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_ARRAY_SIZE);//             27
ret = PyModule_AddIntMacro(m, SQL_ATTR_SIMULATE_CURSOR);//            SQL_SIMULATE_CURSOR
ret = PyModule_AddIntMacro(m, SQL_ATTR_USE_BOOKMARKS);//              SQL_USE_BOOKMARKS

#endif  /* ODBCVER >= 0x0300 */

/* New defines for SEARCHABLE column in SQLGetTypeInfo */

#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_COL_PRED_CHAR);//       SQL_LIKE_ONLY
ret = PyModule_AddIntMacro(m, SQL_COL_PRED_BASIC);//      SQL_ALL_EXCEPT_LIKE
#endif /* ODBCVER >= 0x0300 */


/* whether an attribute is a pointer or not */
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_IS_POINTER);//                          (-4)
ret = PyModule_AddIntMacro(m, SQL_IS_UINTEGER);//                         (-5)
ret = PyModule_AddIntMacro(m, SQL_IS_INTEGER);//                          (-6)
ret = PyModule_AddIntMacro(m, SQL_IS_USMALLINT);//                        (-7)
ret = PyModule_AddIntMacro(m, SQL_IS_SMALLINT);//                         (-8)
#endif  /* ODBCVER >= 0x0300 */

/* the value of SQL_ATTR_PARAM_BIND_TYPE */
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_PARAM_BIND_BY_COLUMN);//            0UL
ret = PyModule_AddIntMacro(m, SQL_PARAM_BIND_TYPE_DEFAULT);//         SQL_PARAM_BIND_BY_COLUMN
#endif  /* ODBCVER >= 0x0300 */

/* SQL_QUERY_TIMEOUT options */
ret = PyModule_AddIntMacro(m, SQL_QUERY_TIMEOUT_DEFAULT);//       0UL

/* SQL_MAX_ROWS options */
ret = PyModule_AddIntMacro(m, SQL_MAX_ROWS_DEFAULT);//            0UL

/* SQL_NOSCAN options */
ret = PyModule_AddIntMacro(m, SQL_NOSCAN_OFF);//                  0UL     /*      1.0 FALSE */
ret = PyModule_AddIntMacro(m, SQL_NOSCAN_ON);//                   1UL     /*      1.0 TRUE */
ret = PyModule_AddIntMacro(m, SQL_NOSCAN_DEFAULT);//              SQL_NOSCAN_OFF

/* SQL_MAX_LENGTH options */
ret = PyModule_AddIntMacro(m, SQL_MAX_LENGTH_DEFAULT);//          0UL

/* values for SQL_ATTR_ASYNC_ENABLE */
ret = PyModule_AddIntMacro(m, SQL_ASYNC_ENABLE_OFF);//            0UL
ret = PyModule_AddIntMacro(m, SQL_ASYNC_ENABLE_ON);//             1UL
ret = PyModule_AddIntMacro(m, SQL_ASYNC_ENABLE_DEFAULT);//        SQL_ASYNC_ENABLE_OFF

/* SQL_BIND_TYPE options */
ret = PyModule_AddIntMacro(m, SQL_BIND_BY_COLUMN);//              0UL
ret = PyModule_AddIntMacro(m, SQL_BIND_TYPE_DEFAULT);//           SQL_BIND_BY_COLUMN  /* Default value */

/* SQL_CONCURRENCY options */
ret = PyModule_AddIntMacro(m, SQL_CONCUR_READ_ONLY);//            1
ret = PyModule_AddIntMacro(m, SQL_CONCUR_LOCK);//                 2
ret = PyModule_AddIntMacro(m, SQL_CONCUR_ROWVER);//               3
ret = PyModule_AddIntMacro(m, SQL_CONCUR_VALUES);//               4
ret = PyModule_AddIntMacro(m, SQL_CONCUR_DEFAULT);//              SQL_CONCUR_READ_ONLY /* Default value */

/* SQL_CURSOR_TYPE options */
ret = PyModule_AddIntMacro(m, SQL_CURSOR_FORWARD_ONLY);//         0UL
ret = PyModule_AddIntMacro(m, SQL_CURSOR_KEYSET_DRIVEN);//        1UL
ret = PyModule_AddIntMacro(m, SQL_CURSOR_DYNAMIC);//              2UL
ret = PyModule_AddIntMacro(m, SQL_CURSOR_STATIC);//               3UL
ret = PyModule_AddIntMacro(m, SQL_CURSOR_TYPE_DEFAULT);//         SQL_CURSOR_FORWARD_ONLY /* Default value */

/* SQL_ROWSET_SIZE options */
ret = PyModule_AddIntMacro(m, SQL_ROWSET_SIZE_DEFAULT);//         1UL

/* SQL_KEYSET_SIZE options */
ret = PyModule_AddIntMacro(m, SQL_KEYSET_SIZE_DEFAULT);//         0UL

/* SQL_SIMULATE_CURSOR options */
ret = PyModule_AddIntMacro(m, SQL_SC_NON_UNIQUE);//               0UL
ret = PyModule_AddIntMacro(m, SQL_SC_TRY_UNIQUE);//               1UL
ret = PyModule_AddIntMacro(m, SQL_SC_UNIQUE);//                   2UL

/* SQL_RETRIEVE_DATA options */
ret = PyModule_AddIntMacro(m, SQL_RD_OFF);//                      0UL
ret = PyModule_AddIntMacro(m, SQL_RD_ON);//                       1UL
ret = PyModule_AddIntMacro(m, SQL_RD_DEFAULT);//                  SQL_RD_ON

/* SQL_USE_BOOKMARKS options */
ret = PyModule_AddIntMacro(m, SQL_UB_OFF);//                      0UL
ret = PyModule_AddIntMacro(m, SQL_UB_ON);//                       01UL
ret = PyModule_AddIntMacro(m, SQL_UB_DEFAULT);//                  SQL_UB_OFF

/* New values for SQL_USE_BOOKMARKS attribute */
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_UB_FIXED);//                    SQL_UB_ON
ret = PyModule_AddIntMacro(m, SQL_UB_VARIABLE);//                 2UL
#endif  /* ODBCVER >= 0x0300 */

/* extended descriptor field */
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_DESC_ARRAY_SIZE);//                     20
ret = PyModule_AddIntMacro(m, SQL_DESC_ARRAY_STATUS_PTR);//               21
ret = PyModule_AddIntMacro(m, SQL_DESC_AUTO_UNIQUE_VALUE);//              SQL_COLUMN_AUTO_INCREMENT
ret = PyModule_AddIntMacro(m, SQL_DESC_BASE_COLUMN_NAME);//               22
ret = PyModule_AddIntMacro(m, SQL_DESC_BASE_TABLE_NAME);//                23
ret = PyModule_AddIntMacro(m, SQL_DESC_BIND_OFFSET_PTR);//                24
ret = PyModule_AddIntMacro(m, SQL_DESC_BIND_TYPE);//                      25
ret = PyModule_AddIntMacro(m, SQL_DESC_CASE_SENSITIVE);//                 SQL_COLUMN_CASE_SENSITIVE
ret = PyModule_AddIntMacro(m, SQL_DESC_CATALOG_NAME);//                   SQL_COLUMN_QUALIFIER_NAME
ret = PyModule_AddIntMacro(m, SQL_DESC_CONCISE_TYPE);//                   SQL_COLUMN_TYPE
ret = PyModule_AddIntMacro(m, SQL_DESC_DATETIME_INTERVAL_PRECISION);//    26
ret = PyModule_AddIntMacro(m, SQL_DESC_DISPLAY_SIZE);//                   SQL_COLUMN_DISPLAY_SIZE
ret = PyModule_AddIntMacro(m, SQL_DESC_FIXED_PREC_SCALE);//               SQL_COLUMN_MONEY
ret = PyModule_AddIntMacro(m, SQL_DESC_LABEL);//                          SQL_COLUMN_LABEL
ret = PyModule_AddIntMacro(m, SQL_DESC_LITERAL_PREFIX);//                 27
ret = PyModule_AddIntMacro(m, SQL_DESC_LITERAL_SUFFIX);//                 28
ret = PyModule_AddIntMacro(m, SQL_DESC_LOCAL_TYPE_NAME);//                29
ret = PyModule_AddIntMacro(m, SQL_DESC_MAXIMUM_SCALE);//                  30
ret = PyModule_AddIntMacro(m, SQL_DESC_MINIMUM_SCALE);//                  31
ret = PyModule_AddIntMacro(m, SQL_DESC_NUM_PREC_RADIX);//                 32
ret = PyModule_AddIntMacro(m, SQL_DESC_PARAMETER_TYPE);//                 33
ret = PyModule_AddIntMacro(m, SQL_DESC_ROWS_PROCESSED_PTR);//             34
#if (ODBCVER >= 0x0350)
ret = PyModule_AddIntMacro(m, SQL_DESC_ROWVER);//                         35
#endif /* ODBCVER >= 0x0350 */
ret = PyModule_AddIntMacro(m, SQL_DESC_SCHEMA_NAME);//                    SQL_COLUMN_OWNER_NAME
ret = PyModule_AddIntMacro(m, SQL_DESC_SEARCHABLE);//                     SQL_COLUMN_SEARCHABLE
ret = PyModule_AddIntMacro(m, SQL_DESC_TYPE_NAME);//                      SQL_COLUMN_TYPE_NAME
ret = PyModule_AddIntMacro(m, SQL_DESC_TABLE_NAME);//                     SQL_COLUMN_TABLE_NAME
ret = PyModule_AddIntMacro(m, SQL_DESC_UNSIGNED);//                       SQL_COLUMN_UNSIGNED
ret = PyModule_AddIntMacro(m, SQL_DESC_UPDATABLE);//                      SQL_COLUMN_UPDATABLE
#endif /* ODBCVER >= 0x0300 */


/* defines for diagnostics fields */
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_DIAG_CURSOR_ROW_COUNT);//           (-1249)
ret = PyModule_AddIntMacro(m, SQL_DIAG_ROW_NUMBER);//                 (-1248)
ret = PyModule_AddIntMacro(m, SQL_DIAG_COLUMN_NUMBER);//              (-1247)
#endif /* ODBCVER >= 0x0300 */

    /* SQL extended datatypes */
ret = PyModule_AddIntMacro(m, SQL_DATE);
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL);
#endif  /* ODBCVER >= 0x0300 */
ret = PyModule_AddIntMacro(m, SQL_TIME);
ret = PyModule_AddIntMacro(m, SQL_TIMESTAMP);
ret = PyModule_AddIntMacro(m, SQL_LONGVARCHAR);
ret = PyModule_AddIntMacro(m, SQL_BINARY);
ret = PyModule_AddIntMacro(m, SQL_VARBINARY);
ret = PyModule_AddIntMacro(m, SQL_LONGVARBINARY);
ret = PyModule_AddIntMacro(m, SQL_BIGINT);
ret = PyModule_AddIntMacro(m, SQL_TINYINT);
ret = PyModule_AddIntMacro(m, SQL_BIT);
#if (ODBCVER >= 0x0350)
ret = PyModule_AddIntMacro(m, SQL_GUID);
#endif  /* ODBCVER >= 0x0350 */

#if (ODBCVER >= 0x0300)
/* interval code */
ret = PyModule_AddIntMacro(m, SQL_CODE_YEAR);//               1
ret = PyModule_AddIntMacro(m, SQL_CODE_MONTH);//              2
ret = PyModule_AddIntMacro(m, SQL_CODE_DAY);//                3
ret = PyModule_AddIntMacro(m, SQL_CODE_HOUR);//               4
ret = PyModule_AddIntMacro(m, SQL_CODE_MINUTE);//             5
ret = PyModule_AddIntMacro(m, SQL_CODE_SECOND);//             6
ret = PyModule_AddIntMacro(m, SQL_CODE_YEAR_TO_MONTH);//          7
ret = PyModule_AddIntMacro(m, SQL_CODE_DAY_TO_HOUR);//            8
ret = PyModule_AddIntMacro(m, SQL_CODE_DAY_TO_MINUTE);//          9
ret = PyModule_AddIntMacro(m, SQL_CODE_DAY_TO_SECOND);//          10
ret = PyModule_AddIntMacro(m, SQL_CODE_HOUR_TO_MINUTE);//         11
ret = PyModule_AddIntMacro(m, SQL_CODE_HOUR_TO_SECOND);//         12
ret = PyModule_AddIntMacro(m, SQL_CODE_MINUTE_TO_SECOND);//       13

ret = PyModule_AddIntMacro(m, SQL_INTERVAL_YEAR);//                   (100 + SQL_CODE_YEAR)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_MONTH);//                  (100 + SQL_CODE_MONTH)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY);//                    (100 + SQL_CODE_DAY)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_HOUR);//                   (100 + SQL_CODE_HOUR)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_MINUTE);//                 (100 + SQL_CODE_MINUTE)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_SECOND);//                 (100 + SQL_CODE_SECOND)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_YEAR_TO_MONTH);//          (100 + SQL_CODE_YEAR_TO_MONTH)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY_TO_HOUR);//            (100 + SQL_CODE_DAY_TO_HOUR)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY_TO_MINUTE);//          (100 + SQL_CODE_DAY_TO_MINUTE)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY_TO_SECOND);//          (100 + SQL_CODE_DAY_TO_SECOND)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_HOUR_TO_MINUTE);//         (100 + SQL_CODE_HOUR_TO_MINUTE)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_HOUR_TO_SECOND);//         (100 + SQL_CODE_HOUR_TO_SECOND)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_MINUTE_TO_SECOND);//       (100 + SQL_CODE_MINUTE_TO_SECOND)

#else
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_YEAR);//                       (-80)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_MONTH);//                      (-81)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_YEAR_TO_MONTH);//              (-82)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY);//                        (-83)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_HOUR);//                       (-84)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_MINUTE);//                     (-85)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_SECOND);//                     (-86)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY_TO_HOUR);//                (-87)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY_TO_MINUTE);//              (-88)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_DAY_TO_SECOND);//              (-89)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_HOUR_TO_MINUTE);//             (-90)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_HOUR_TO_SECOND);//             (-91)
ret = PyModule_AddIntMacro(m, SQL_INTERVAL_MINUTE_TO_SECOND);//           (-92)
#endif  /* ODBCVER >= 0x0300 */


#if (ODBCVER <= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_UNICODE);//                             (-95)
ret = PyModule_AddIntMacro(m, SQL_UNICODE_VARCHAR);//                     (-96)
ret = PyModule_AddIntMacro(m, SQL_UNICODE_LONGVARCHAR);//                 (-97)
ret = PyModule_AddIntMacro(m, SQL_UNICODE_CHAR);//                        SQL_UNICODE
#else
/* The previous definitions for SQL_UNICODE_ are historical and obsolete */

ret = PyModule_AddIntMacro(m, SQL_UNICODE);//             SQL_WCHAR

ret = PyModule_AddIntMacro(m, SQL_UNICODE_VARCHAR);//     SQL_WVARCHAR
ret = PyModule_AddIntMacro(m, SQL_UNICODE_LONGVARCHAR);// SQL_WLONGVARCHAR
ret = PyModule_AddIntMacro(m, SQL_UNICODE_CHAR);//        SQL_WCHAR
#endif

    /* C datatype to SQL datatype mapping                  SQL types
                                                           ------------------- */
ret = PyModule_AddIntMacro(m, SQL_C_CHAR);             /* CHAR, VARCHAR, DECIMAL, NUMERIC */
ret = PyModule_AddIntMacro(m, SQL_C_LONG);             /* INTEGER                      */
ret = PyModule_AddIntMacro(m, SQL_C_SHORT);            /* SMALLINT                     */
ret = PyModule_AddIntMacro(m, SQL_C_FLOAT);            /* REAL                         */
ret = PyModule_AddIntMacro(m, SQL_C_DOUBLE);           /* FLOAT, DOUBLE                */
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_C_NUMERIC);
#endif /* ODBCVER >= 0x0300 */
ret = PyModule_AddIntMacro(m, SQL_C_DEFAULT);

ret = PyModule_AddIntMacro(m, SQL_SIGNED_OFFSET);
ret = PyModule_AddIntMacro(m, SQL_UNSIGNED_OFFSET);

/* C datatype to SQL datatype mapping */
ret = PyModule_AddIntMacro(m, SQL_C_DATE);
ret = PyModule_AddIntMacro(m, SQL_C_TIME);
ret = PyModule_AddIntMacro(m, SQL_C_TIMESTAMP);
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_C_TYPE_DATE);
ret = PyModule_AddIntMacro(m, SQL_C_TYPE_TIME);
ret = PyModule_AddIntMacro(m, SQL_C_TYPE_TIMESTAMP);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_YEAR);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_MONTH);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_DAY);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_HOUR);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_MINUTE);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_SECOND);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_YEAR_TO_MONTH);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_DAY_TO_HOUR);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_DAY_TO_MINUTE);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_DAY_TO_SECOND);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_HOUR_TO_MINUTE);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_HOUR_TO_SECOND);
ret = PyModule_AddIntMacro(m, SQL_C_INTERVAL_MINUTE_TO_SECOND);
#endif                                         /* ODBCVER >= 0x0300 */
ret = PyModule_AddIntMacro(m, SQL_C_BINARY);
ret = PyModule_AddIntMacro(m, SQL_C_BIT);
#if (ODBCVER >= 0x0300)
ret = PyModule_AddIntMacro(m, SQL_C_SBIGINT);/* SIGNED BIGINT */
ret = PyModule_AddIntMacro(m, SQL_C_UBIGINT);/* UNSIGNED BIGINT */
#endif                                           /* ODBCVER >= 0x0300 */
ret = PyModule_AddIntMacro(m, SQL_C_TINYINT);
ret = PyModule_AddIntMacro(m, SQL_C_SLONG);/* SIGNED INTEGER  */
ret = PyModule_AddIntMacro(m, SQL_C_SSHORT);/* SIGNED SMALLINT */
ret = PyModule_AddIntMacro(m, SQL_C_STINYINT);  /* SIGNED TINYINT  */
ret = PyModule_AddIntMacro(m, SQL_C_ULONG);     /* UNSIGNED INTEGER*/
ret = PyModule_AddIntMacro(m, SQL_C_USHORT);/* UNSIGNED SMALLINT*/
ret = PyModule_AddIntMacro(m, SQL_C_UTINYINT); /* UNSIGNED TINYINT*/

ret = PyModule_AddIntMacro(m, SQL_C_BOOKMARK);                     /* BOOKMARK        */

#if (ODBCVER >= 0x0350)
ret = PyModule_AddIntMacro(m, SQL_C_GUID);
#endif                                                                 /* ODBCVER >= 0x0350 */










    /* Defines for SQLBindParameter and
SQLProcedureColumns (returned in the result set) */
    ret = PyModule_AddIntMacro(m, SQL_PARAM_TYPE_UNKNOWN);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_INPUT);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_INPUT_OUTPUT);
    ret = PyModule_AddIntMacro(m, SQL_RESULT_COL);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_OUTPUT);
    ret = PyModule_AddIntMacro(m, SQL_RETURN_VALUE);

#if (ODBCVER >= 0x0380)
    ret = PyModule_AddIntMacro(m, SQL_PARAM_INPUT_OUTPUT_STREAM);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_OUTPUT_STREAM);
#endif

    /* Defines for SQLProcedures (returned in the result set) */
    ret = PyModule_AddIntMacro(m, SQL_PT_UNKNOWN);
    ret = PyModule_AddIntMacro(m, SQL_PT_PROCEDURE);
    ret = PyModule_AddIntMacro(m, SQL_PT_FUNCTION);

    ret = PyModule_AddStringConstant(m, "SQL_ODBC_KEYWORDS", SQL_ODBC_KEYWORDS);



    ret = PyModule_AddIntMacro(m, SQL_TYPE_NULL);
#if (ODBCVER < 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_TYPE_MIN);
    ret = PyModule_AddIntMacro(m, SQL_TYPE_MAX);
#endif

#if (ODBCVER >= 0x380)
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_C_TYPE_BASE);
#endif

#if (ODBCVER >= 0x380)
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_SQL_TYPE_BASE);
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_DESC_FIELD_BASE);
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_DIAG_FIELD_BASE);
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_INFO_TYPE_BASE);
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_CONN_ATTR_BASE);  /* 32-bit */
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_STMT_ATTR_BASE);  /* 32-bit */
#endif


    /* statement attributes for ODBC 3.0 */
#if (ODBCVER >= 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ASYNC_ENABLE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONCURRENCY);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURSOR_TYPE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ENABLE_AUTO_IPD);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_FETCH_BOOKMARK_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_KEYSET_SIZE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_MAX_LENGTH);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_MAX_ROWS);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_NOSCAN);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_BIND_OFFSET_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_BIND_TYPE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_OPERATION_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAM_STATUS_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAMS_PROCESSED_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAMSET_SIZE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_QUERY_TIMEOUT);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RETRIEVE_DATA);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_BIND_OFFSET_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_BIND_TYPE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_NUMBER);      /*GetStmtAttr*/
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_OPERATION_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_STATUS_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROWS_FETCHED_PTR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROW_ARRAY_SIZE);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SIMULATE_CURSOR);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_USE_BOOKMARKS);

#endif /* ODBCVER >= 0x0300 */

#if (ODBCVER < 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_STMT_OPT_MAX);
    ret = PyModule_AddIntMacro(m, SQL_QUERY_TIMEOUT);
#endif      /* ODBCVER < 0x0300 */

    /* SQLExtendedFetch "fFetchType" values */
    ret = PyModule_AddIntMacro(m, SQL_FETCH_BOOKMARK);

    /* SQLExtendedFetch "rgfRowStatus" element values */
    ret = PyModule_AddIntMacro(m, SQL_ROW_SUCCESS);
    ret = PyModule_AddIntMacro(m, SQL_ROW_DELETED);
    ret = PyModule_AddIntMacro(m, SQL_ROW_UPDATED);
    ret = PyModule_AddIntMacro(m, SQL_ROW_NOROW);
    ret = PyModule_AddIntMacro(m, SQL_ROW_ADDED);
    ret = PyModule_AddIntMacro(m, SQL_ROW_ERROR);
#if (ODBCVER >= 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_ROW_SUCCESS_WITH_INFO);
    ret = PyModule_AddIntMacro(m, SQL_ROW_PROCEED);
    ret = PyModule_AddIntMacro(m, SQL_ROW_IGNORE);
#endif

    /* value for SQL_DESC_ARRAY_STATUS_PTR */
#if (ODBCVER >= 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_PARAM_SUCCESS);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_SUCCESS_WITH_INFO);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_ERROR);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_UNUSED);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_DIAG_UNAVAILABLE);

    ret = PyModule_AddIntMacro(m, SQL_PARAM_PROCEED);
    ret = PyModule_AddIntMacro(m, SQL_PARAM_IGNORE);
#endif  /* ODBCVER >= 0x0300 */

    /* Defines for SQLForeignKeys (UPDATE_RULE and DELETE_RULE) */
    ret = PyModule_AddIntMacro(m, SQL_CASCADE);
    ret = PyModule_AddIntMacro(m, SQL_RESTRICT);
    ret = PyModule_AddIntMacro(m, SQL_SET_NULL);
#if (ODBCVER >= 0x0250)
    ret = PyModule_AddIntMacro(m, SQL_NO_ACTION);
    ret = PyModule_AddIntMacro(m, SQL_SET_DEFAULT);
#endif  /* ODBCVER >= 0x0250 */

#if (ODBCVER >= 0x0300)
    /* Note that the following are in a different column of SQLForeignKeys than */
    /* the previous #defines. );//);//);//  These are for DEFERRABILITY.                    */

    ret = PyModule_AddIntMacro(m, SQL_INITIALLY_DEFERRED);
    ret = PyModule_AddIntMacro(m, SQL_INITIALLY_IMMEDIATE);
    ret = PyModule_AddIntMacro(m, SQL_NOT_DEFERRABLE);

#endif  /* ODBCVER >= 0x0300 */

    /* Defines for SQLSetPos */
    ret = PyModule_AddIntMacro(m, SQL_ENTIRE_ROWSET);

    /* Operations in SQLSetPos */
    ret = PyModule_AddIntMacro(m, SQL_POSITION);               /*      1.0 FALSE */
    ret = PyModule_AddIntMacro(m, SQL_REFRESH);                /*      1.0 TRUE */
    ret = PyModule_AddIntMacro(m, SQL_UPDATE);
    ret = PyModule_AddIntMacro(m, SQL_DELETE);

    /* Operations in SQLBulkOperations */
    ret = PyModule_AddIntMacro(m, SQL_ADD);
    ret = PyModule_AddIntMacro(m, SQL_SETPOS_MAX_OPTION_VALUE);
#if (ODBCVER >= 0x0300)
    ret = PyModule_AddIntMacro(m, SQL_UPDATE_BY_BOOKMARK);
    ret = PyModule_AddIntMacro(m, SQL_DELETE_BY_BOOKMARK);
    ret = PyModule_AddIntMacro(m, SQL_FETCH_BY_BOOKMARK);

#endif /*  ODBCVER >= 0x0300 */




    /* Options for SQLDriverConnect */
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_NOPROMPT);
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_COMPLETE);
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_PROMPT);
    ret = PyModule_AddIntMacro(m, SQL_DRIVER_COMPLETE_REQUIRED);


    ret = PyModule_AddIntMacro(m, SQL_SCROLL_FORWARD_ONLY);  /* -SQL_CURSOR_FORWARD_ONLY */
    ret = PyModule_AddIntMacro(m, SQL_SCROLL_KEYSET_DRIVEN); /* -SQL_CURSOR_KEYSET_DRIVEN */
    ret = PyModule_AddIntMacro(m, SQL_SCROLL_DYNAMIC);            /* -SQL_CURSOR_DYNAMIC */
    ret = PyModule_AddIntMacro(m, SQL_SCROLL_STATIC);              /* -SQL_CURSOR_STATIC */



    /* SQL_CONCURRENCY options */
    ret = PyModule_AddIntMacro(m, SQL_CONCUR_READ_ONLY);
    ret = PyModule_AddIntMacro(m, SQL_CONCUR_LOCK);
    ret = PyModule_AddIntMacro(m, SQL_CONCUR_ROWVER);
    ret = PyModule_AddIntMacro(m, SQL_CONCUR_VALUES);
    ret = PyModule_AddIntMacro(m, SQL_CONCUR_DEFAULT);/* Default value */

    /* SQL_CURSOR_TYPE options */
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_FORWARD_ONLY);
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_KEYSET_DRIVEN);
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_DYNAMIC);
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_STATIC);
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_TYPE_DEFAULT); /* Default value */

 

    return ret;

}



