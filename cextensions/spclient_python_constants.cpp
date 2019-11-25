
#include "spclient_python_common_cpp.h"


int add_module_globals(PyObject* m)
{
    int ret;
    ret = PyModule_AddStringMacro(m, SPCLIENT_PYTHON_VERSION);
    ret = PyModule_AddStringConstant(m, "__version__", SPCLIENT_PYTHON_VERSION);
#ifndef SQLF_PL_STACK_TRACE_NONE
    /* Defines for SQLF_DBTN_PL_STACK_TRACE                                       */
#define SQLF_PL_STACK_TRACE_NONE  0    /* Do not log stack traces for any     */
                                       /* SQL PL error.                       */
#define SQLF_PL_STACK_TRACE_UNHANDLED 1 /* Log stack traces for unhandled     */
                                        /* SQL PL errors only.                 */
#define SQLF_PL_STACK_TRACE_ALL   2    /* Log stack traces for all SQL PL     */
                                       /* errors.                             */
#endif
                                       /*  Defines for SQLF_DBTN_PL_STACK_TRACE  */
    ret = PyModule_AddIntMacro(m, SQLF_PL_STACK_TRACE_NONE);
    ret = PyModule_AddIntMacro(m, SQLF_PL_STACK_TRACE_UNHANDLED);
    ret = PyModule_AddIntMacro(m, SQLF_PL_STACK_TRACE_ALL);
    /* Constants describing a single configuration parameter */
    ret = PyModule_AddIntMacro(m, db2CfgParamAutomatic);
    ret = PyModule_AddIntMacro(m, db2CfgParamComputed);
    ret = PyModule_AddIntMacro(m, db2CfgParamManual);

    /******************************************************************************
    ** Constants for updating and getting self_tuning_mem.
    ** The self_tuning_mem parameter can be updated to ON or OFF
    ** and it can return ON, OFF, ON_ACTIVE or ON_INACTIVE.
    ** Please refer to the documentation on Self-Tuning Memory.
    *******************************************************************************/
    ret = PyModule_AddIntMacro(m, db2SelfTuningOff);
    ret = PyModule_AddIntMacro(m, db2SelfTuningOn);
    ret = PyModule_AddIntMacro(m, db2SelfTuningOnActive);
    ret = PyModule_AddIntMacro(m, db2SelfTuningOnInactive);

    /* Database and Database Manager Configuration Structures, Constants, and     */
    /* Function Prototypes                                                        */
    ret = PyModule_AddIntMacro(m, db2CfgDatabase);
    ret = PyModule_AddIntMacro(m, db2CfgDatabaseManager);
    ret = PyModule_AddIntMacro(m, db2CfgImmediate);
    ret = PyModule_AddIntMacro(m, db2CfgDelayed);
    ret = PyModule_AddIntMacro(m, db2CfgGetDefaults);
    ret = PyModule_AddIntMacro(m, db2CfgSingleDbpartition);
    ret = PyModule_AddIntMacro(m, db2CfgSingleMember);
    ret = PyModule_AddIntMacro(m, db2CfgReset);
    ret = PyModule_AddIntMacro(m, db2CfgMaxParam);

    /******************************************************************************/
    /* client communications protocols (client_protocol)                          */
    /******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_APPC);   /* appc                   */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_NETB);   /* netbios                */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_APPN);   /* appn                   */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_TCPIP);  /* TCP/IPv4 or 6          */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_TCPIP4); /* TCP/IPv4               */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_TCPIP6); /* TCP/IPv6               */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_SOCKS);  /* TCP/IP   using SOCKS   */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_SOCKS4); /* TCP/IPv4 using SOCKS   */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_CPIC);   /* APPC using CPIC        */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_IPXSPX); /* ipx/spx                */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_LOCAL);  /* local client           */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_NPIPE);  /* Named pipe             */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_SSL);    /* TCP/IP using SSL       */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_SSL4);   /* IPv4  using SSL        */
    ret = PyModule_AddIntMacro(m, SQL_PROTOCOL_SSL6);   /* IPv6  using SSL        */

    /* db locations */
    ret = PyModule_AddIntMacro(m, SQL_LDAP);
    ret = PyModule_AddIntMacro(m, SQL_INDIRECT);
    ret = PyModule_AddIntMacro(m, SQL_REMOTE);
    ret = PyModule_AddIntMacro(m, SQL_HOME);
    ret = PyModule_AddIntMacro(m, SQL_DCE);

    /*  Authentication type */
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_SERVER);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_CLIENT);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_DCS);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_DCE);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_KERBEROS);

#ifndef SQL_AUTHENTICATION_NOT_SPEC
ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_NOT_SPEC    255  /* Authentication Not Specified   */
#endif
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_NOT_SPEC);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_SVR_ENCRYPT);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_DCS_ENCRYPT);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_DCE_SVR_ENC);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_KRB_SVR_ENC);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_DATAENC);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_DATAENC_CMP);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_SVRENC_AESO);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_GSSPLUGIN);
    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_GSS_SVR_ENC);
    ret = PyModule_AddIntMacro(m, SQL_ALTERNATE_AUTH_ENC_NOTSPEC);

    /* Variable Types                                                             */
    ret = PyModule_AddIntMacro(m, SQL_TYP_DATE);//           384     /* DATE                                */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDATE);//          (SQL_TYP_DATE+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_TIME);//           388     /* TIME                                */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NTIME);//          (SQL_TYP_TIME+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_STAMP);//          392     /* TIMESTAMP                           */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NSTAMP);//         (SQL_TYP_STAMP+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_DATALINK);//       396     /* DATALINK                            */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDATALINK);//      (SQL_TYP_DATALINK+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CGSTR);//          400     /* C NUL-terminated graphic str        */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCGSTR);//         (SQL_TYP_CGSTR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_BLOB);//           404     /* BLOB - varying length string        */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBLOB);//          (SQL_TYP_BLOB+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CLOB);//           408     /* CLOB - varying length string        */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCLOB);//          (SQL_TYP_CLOB+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_DBCLOB);//         412     /* DBCLOB - varying length string      */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDBCLOB);//        (SQL_TYP_DBCLOB+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_VARCHAR);//        448     /* VARCHAR(i) - varying length string  */
                                                                     /* (2 byte length)                     */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NVARCHAR);//       (SQL_TYP_VARCHAR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CHAR);//           452     /* CHAR(i) - fixed length string       */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCHAR);//          (SQL_TYP_CHAR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_LONG);//           456     /* LONG VARCHAR - varying length       */
                                                                     /* string                              */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NLONG);//          (SQL_TYP_LONG+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CSTR);//           460     /* varying length string for C (null   */
                                                                     /* terminated)                         */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCSTR);//          (SQL_TYP_CSTR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_VARGRAPH);//       464     /* VARGRAPHIC(i) - varying length      */
                                                                     /* graphic string (2 byte length)      */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NVARGRAPH);//      (SQL_TYP_VARGRAPH+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_GRAPHIC);//        468     /* GRAPHIC(i) - fixed length graphic   */
                                                                     /* string                              */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NGRAPHIC);//       (SQL_TYP_GRAPHIC+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_LONGRAPH);//       472     /* LONG VARGRAPHIC(i) - varying        */
                                                                     /* length graphic string               */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NLONGRAPH);//      (SQL_TYP_LONGRAPH+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_LSTR);//           476     /* varying length string for Pascal    */
                                                                     /* (1-byte length)                     */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NLSTR);//          (SQL_TYP_LSTR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_FLOAT);//          480     /* FLOAT - 4 or 8 byte floating point  */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NFLOAT);//         (SQL_TYP_FLOAT+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_DECIMAL);//        484     /* DECIMAL (m,n)                       */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDECIMAL);//       (SQL_TYP_DECIMAL+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_ZONED);//          488     /* Zoned Decimal -> DECIMAL (m,n)      */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NZONED);//         (SQL_TYP_ZONED+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_BIGINT);//         492     /* BIGINT - 8-byte signed integer      */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBIGINT);//        (SQL_TYP_BIGINT+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_INTEGER);//        496     /* INTEGER - 4-byte signed integer     */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NINTEGER);//       (SQL_TYP_INTEGER+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_SMALL);//          500     /* SMALLINT - 2-byte signed integer    */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NSMALL);//         (SQL_TYP_SMALL+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_NUMERIC);//        504     /* NUMERIC -> DECIMAL (m,n)            */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NNUMERIC);//       (SQL_TYP_NUMERIC+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_BLOB_FILE_OBSOLETE);// 804 /* Obsolete Value                      */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBLOB_FILE_OBSOLETE);// (SQL_TYP_BLOB_FILE_OBSOLETE+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CLOB_FILE_OBSOLETE);// 808 /* Obsolete Value                      */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCLOB_FILE_OBSOLETE);// (SQL_TYP_CLOB_FILE_OBSOLETE+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_DBCLOB_FILE_OBSOLETE);// 812 /* Obsolete Value                    */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDBCLOB_FILE_OBSOLETE);// (SQL_TYP_DBCLOB_FILE_OBSOLETE+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_ARRAY);//          900       /* User defined array type             */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NARRAY);//         (SQL_TYP_ARRAY+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_VARBINARY);//      908     /* Variable Binary                     */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NVARBINARY);//     (SQL_TYP_VARBINARY+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_BINARY);//         912     /* Fixed Binary                        */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBINARY);//        (SQL_TYP_BINARY+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_BLOB_FILE);//      916     /* BLOB File - Binary Large Object     */
                                                                     /* File                                */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBLOB_FILE);//     (SQL_TYP_BLOB_FILE+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CLOB_FILE);//      920     /* CLOB File - Char Large Object File  */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCLOB_FILE);//     (SQL_TYP_CLOB_FILE+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_DBCLOB_FILE);//    924     /* DBCLOB File - Double Byte Char      */
                                                                     /* Large Object File                   */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDBCLOB_FILE);//   (SQL_TYP_DBCLOB_FILE+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_BLOB_LOCATOR);//   960     /* BLOB locator                        */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBLOB_LOCATOR);//  (SQL_TYP_BLOB_LOCATOR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CLOB_LOCATOR);//   964     /* CLOB locator                        */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCLOB_LOCATOR);//  (SQL_TYP_CLOB_LOCATOR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_DBCLOB_LOCATOR);// 968     /* DBCLOB locator                      */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDBCLOB_LOCATOR);// (SQL_TYP_DBCLOB_LOCATOR+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_XML);//            988     /* XML                                 */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NXML);//           (SQL_TYP_XML+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_DECFLOAT);//       996     /* Decimal Float (16/34)               */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDECFLOAT);//      (SQL_TYP_DECFLOAT+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_BOOLEAN);//        2436    /* BOOLEAN                             */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBOOLEAN);//       (SQL_TYP_BOOLEAN+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_ROW);//            2440    /* User defined row type               */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NROW);//           (SQL_TYP_ROW+SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_TYP_CURSOR);//         2444    /* CURSOR                              */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCURSOR);//        (SQL_TYP_CURSOR+SQL_TYP_NULINC)
    ret = PyModule_AddIntMacro(m, SQL_TYP_STAMP_TZ);//       2448    /* TIMESTAMP WITH TIME ZONE            */
    ret = PyModule_AddIntMacro(m, SQL_TYP_NSTAMP_TZ);//      (SQL_TYP_STAMP_TZ +SQL_TYP_NULINC)

    ret = PyModule_AddIntMacro(m, SQL_LOBTOKEN_LEN);//       SQL_LOBLOCATOR_LEN
    ret = PyModule_AddIntMacro(m, SQL_TYP_BLOB_TOKEN);//     SQL_TYP_BLOB_LOCATOR
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBLOB_TOKEN);//    SQL_TYP_NBLOB_LOCATOR
    ret = PyModule_AddIntMacro(m, SQL_TYP_CLOB_TOKEN);//     SQL_TYP_CLOB_LOCATOR
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCLOB_TOKEN);//    SQL_TYP_NCLOB_LOCATOR
    ret = PyModule_AddIntMacro(m, SQL_TYP_DBCLOB_TOKEN);//   SQL_TYP_DBCLOB_LOCATOR
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDBCLOB_TOKEN);//  SQL_TYP_NDBCLOB_LOCATOR
    ret = PyModule_AddIntMacro(m, SQL_NCLOB_MAXLEN);//       SQL_DBCLOB_MAXLEN
    ret = PyModule_AddIntMacro(m, SQL_LOBHANDLE_LEN);//      SQL_LOBTOKEN_LEN
    ret = PyModule_AddIntMacro(m, SQL_TYP_BLOB_HANDLE);//    SQL_TYP_BLOB_TOKEN
    ret = PyModule_AddIntMacro(m, SQL_TYP_NBLOB_HANDLE);//   SQL_TYP_NBLOB_TOKEN
    ret = PyModule_AddIntMacro(m, SQL_TYP_CLOB_HANDLE);//    SQL_TYP_CLOB_TOKEN
    ret = PyModule_AddIntMacro(m, SQL_TYP_NCLOB_HANDLE);//   SQL_TYP_NCLOB_TOKEN
    ret = PyModule_AddIntMacro(m, SQL_TYP_DBCLOB_HANDLE);//  SQL_TYP_DBCLOB_TOKEN
    ret = PyModule_AddIntMacro(m, SQL_TYP_NDBCLOB_HANDLE);// SQL_TYP_NDBCLOB_TOKEN

    return ret;
}

int add_sqlcli1(PyObject* m)
{
    int ret;

    /*
    *  Descriptor value for setting the descriptor type.
    */

    ret = PyModule_AddIntMacro(m, SQL_DESC_DESCRIPTOR_TYPE);//     1287

    ret = PyModule_AddIntMacro(m, SQL_ATTR_OPTIMIZE_SQLCOLUMNS);// 1288
    ret = PyModule_AddIntMacro(m, SQL_ATTR_MEM_DEBUG_DUMP);//      1289
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONNECT_NODE);//        1290
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONNECT_WITH_XA);//     1291
    ret = PyModule_AddIntMacro(m, SQL_ATTR_GET_XA_RESOURCE);//     1292
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2_SQLERRP);//         2451
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SERVER_MSGTXT_SP);//    2452
    ret = PyModule_AddIntMacro(m, SQL_ATTR_OPTIMIZE_FOR_NROWS);//         2450
    ret = PyModule_AddIntMacro(m, SQL_ATTR_QUERY_OPTIMIZATION_LEVEL);//   1293
    ret = PyModule_AddIntMacro(m, SQL_ATTR_USE_LIGHT_OUTPUT_SQLDA);//     1298
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURSOR_BLOCK_NUM_ROWS);//      2453
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURSOR_BLOCK_EARLY_CLOSE);//   2454
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SERVER_MSGTXT_MASK);//         2455
    ret = PyModule_AddIntMacro(m, SQL_ATTR_USE_LIGHT_INPUT_SQLDA);//      2458
    ret = PyModule_AddIntMacro(m, SQL_ATTR_BLOCK_FOR_NROWS);//            2459
    ret = PyModule_AddIntMacro(m, SQL_ATTR_OPTIMIZE_ROWS_FOR_BLOCKING);// 2460
    ret = PyModule_AddIntMacro(m, SQL_ATTR_STATICMODE);//                 2467
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2_MESSAGE_PREFIX);//         2468
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CALL_RETVAL_AS_PARM);//        2469
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CALL_RETURN);//                2470
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RETURN_USER_DEFINED_TYPES);//  2471
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ENABLE_EXTENDED_PARAMDATA);//  2472
    ret = PyModule_AddIntMacro(m, SQL_ATTR_APP_TYPE);//                   2473
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TRANSFORM_GROUP);//            2474
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DESCRIBE_CALL);//              2476
    ret = PyModule_AddIntMacro(m, SQL_ATTR_AUTOCOMMCLEANUP);//            2477
    ret = PyModule_AddIntMacro(m, SQL_ATTR_USEMALLOC);//                  2478
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PRESERVE_LOCALE);//            2479
    ret = PyModule_AddIntMacro(m, SQL_ATTR_MAPGRAPHIC);//                 2480
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INSERT_BUFFERING);//           2481



    /* Options for SQLGetConnectOption/SQLSetConnectOption extensions */
    ret = PyModule_AddIntMacro(m, SQL_WCHARTYPE);//                              1252
    ret = PyModule_AddIntMacro(m, SQL_LONGDATA_COMPAT);//                        1253
    ret = PyModule_AddIntMacro(m, SQL_CURRENT_SCHEMA);//                         1254
    ret = PyModule_AddIntMacro(m, SQL_DB2EXPLAIN);//                             1258
    ret = PyModule_AddIntMacro(m, SQL_DB2ESTIMATE);//                            1259
    ret = PyModule_AddIntMacro(m, SQL_PARAMOPT_ATOMIC);//                        1260
    ret = PyModule_AddIntMacro(m, SQL_STMTTXN_ISOLATION);//                      1261
    ret = PyModule_AddIntMacro(m, SQL_MAXCONN);//                                1262
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLISCHEMA);//                         1280
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INFO_USERID);//                       1281
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INFO_WRKSTNNAME);//                   1282
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INFO_APPLNAME);//                     1283
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INFO_ACCTSTR);//                      1284
    ret = PyModule_AddIntMacro(m, SQL_ATTR_AUTOCOMMIT_NOCOMMIT);//               2462
    ret = PyModule_AddIntMacro(m, SQL_ATTR_QUERY_PATROLLER);//                   2466
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CHAINING_BEGIN);//                    2464
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CHAINING_END);//                      2465
    ret = PyModule_AddIntMacro(m, SQL_ATTR_EXTENDEDBIND);//                      2475
    ret = PyModule_AddIntMacro(m, SQL_ATTR_GRAPHIC_UNICODESERVER);//             2503
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RETURN_CHAR_AS_WCHAR_OLEDB);//        2517
    ret = PyModule_AddIntMacro(m, SQL_ATTR_GATEWAY_CONNECTED);//                 2537
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SQLCOLUMNS_SORT_BY_ORDINAL_OLEDB);//  2542
    ret = PyModule_AddIntMacro(m, SQL_ATTR_REPORT_ISLONG_FOR_LONGTYPES_OLEDB);// 2543
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PING_DB);//                           2545
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RECEIVE_TIMEOUT);//                   2547
    ret = PyModule_AddIntMacro(m, SQL_ATTR_REOPT);//                             2548
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOB_CACHE_SIZE);//                    2555
    ret = PyModule_AddIntMacro(m, SQL_ATTR_STREAM_GETDATA);//                    2558
    ret = PyModule_AddIntMacro(m, SQL_ATTR_APP_USES_LOB_LOCATOR);//              2559
    ret = PyModule_AddIntMacro(m, SQL_ATTR_MAX_LOB_BLOCK_SIZE);//                2560
    ret = PyModule_AddIntMacro(m, SQL_ATTR_USE_TRUSTED_CONTEXT);//               2561
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TRUSTED_CONTEXT_USERID);//            2562
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TRUSTED_CONTEXT_PASSWORD);//          2563
    ret = PyModule_AddIntMacro(m, SQL_ATTR_USER_REGISTRY_NAME);//                2564
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DECFLOAT_ROUNDING_MODE);//            2565
    ret = PyModule_AddIntMacro(m, SQL_ATTR_APPEND_FOR_FETCH_ONLY);//             2573
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ONLY_USE_BIG_PACKAGES);//             2577
    ret = PyModule_AddIntMacro(m, SQL_ATTR_NONATMOIC_BUFFER_INSERT);//           2588
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ROWCOUNT_PREFETCH);//                 2592
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PING_REQUEST_PACKET_SIZE);//          2593
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PING_NTIMES);//                       2594
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ALLOW_INTERLEAVED_GETDATA);//         2599
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INTERLEAVED_STREAM_PUTDATA);//        3000
    ret = PyModule_AddIntMacro(m, SQL_ATTR_FET_BUF_SIZE);//                      3001
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLIENT_CODEPAGE);//                   3002
    ret = PyModule_AddIntMacro(m, SQL_ATTR_EXTENDED_INDICATORS);//               3003
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SESSION_TIME_ZONE);//                 3004
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLIENT_TIME_ZONE);//                  3005
    /* A Connection attribute which controls the collection of network statistics */
    /* for a connection.  The statistics can be retrieved by calling */
    /* SQLGetDiagField() */
    /* with the SQL_DIAG_NETWORK_STATISTICS DiagIdentifier. */
    ret = PyModule_AddIntMacro(m, SQL_ATTR_NETWORK_STATISTICS);//                3006
    ret = PyModule_AddIntMacro(m, SQL_ATTR_OVERRIDE_CHARACTER_CODEPAGE);//       3007
    ret = PyModule_AddIntMacro(m, SQL_ATTR_GET_LATEST_MEMBER);//                 3008
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CO_CAPTUREONPREPARE);//               3009
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RETRYBINDONERROR);//                  3010
    ret = PyModule_AddIntMacro(m, SQL_ATTR_COMMITONEOF);//                       3011
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARC_BATCH);//                        3012
    ret = PyModule_AddIntMacro(m, SQL_ATTR_COLUMNWISE_MRI);//                    3013
    ret = PyModule_AddIntMacro(m, SQL_ATTR_OVERRIDE_CODEPAGE);//                 3014

#ifndef SQL_ATTR_SQLCODEMAP
#define SQL_ATTR_SQLCODEMAP                        3015
#define SQL_ATTR_ISREADONLYSQL                     3016
#define SQL_ATTR_DBC_SYS_NAMING                    3017
#define SQL_ATTR_FREE_MEMORY_ON_STMTCLOSE          3018
#define SQL_ATTR_OVERRIDE_PRIMARY_AFFINITY         3020
#define SQL_ATTR_STREAM_OUTPUTLOB_ON_CALL          3021
#define SQL_ATTR_CACHE_USRLIBL                     3022
#define SQL_ATTR_GET_LATEST_MEMBER_NAME            3023
#define SQL_ATTR_INFO_CRRTKN                       3024
#define SQL_ATTR_DATE_FMT                          3025
#define SQL_ATTR_DATE_SEP                          3026
#define SQL_ATTR_TIME_FMT                          3027
#define SQL_ATTR_TIME_SEP                          3028
#define SQL_ATTR_DECIMAL_SEP                       3029
#define SQL_ATTR_READ_ONLY_CONNECTION              3030
#define SQL_ATTR_CONFIG_KEYWORDS_ARRAY_SIZE        3031
#define SQL_ATTR_CONFIG_KEYWORDS_MAXLEN            3032
#define SQL_ATTR_RETRY_ON_MERGE                    3033
#endif

#ifndef SQL_ATTR_IGNORE_SERVER_LIST
#define SQL_ATTR_DETECT_READ_ONLY_TXN              3034
#define SQL_ATTR_IGNORE_SERVER_LIST                3035
#define SQL_ATTR_DB2ZLOAD_LOADSTMT                 3037
#define SQL_ATTR_DB2ZLOAD_RECDELIM                 3038
#define SQL_ATTR_DB2ZLOAD_BEGIN                    3039
#define SQL_ATTR_DB2ZLOAD_END                      3040
#define SQL_ATTR_DB2ZLOAD_FILETYPE                 3041
#define SQL_ATTR_DB2ZLOAD_MSGFILE                  3042
#define SQL_ATTR_DB2ZLOAD_UTILITYID                3043
#define SQL_ATTR_CONNECT_PASSIVE                   3045
#define SQL_ATTR_CLIENT_APPLCOMPAT                 3046
#define SQL_ATTR_DB2ZLOAD_LOADFILE                 3047
#define SQL_ATTR_PREFETCH_NROWS                    3048
#endif

    ret = PyModule_AddIntMacro(m, SQL_ATTR_SQLCODEMAP);//                        3015
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ISREADONLYSQL);//                     3016
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DBC_SYS_NAMING);//                    3017
    ret = PyModule_AddIntMacro(m, SQL_ATTR_FREE_MEMORY_ON_STMTCLOSE);//          3018
    ret = PyModule_AddIntMacro(m, SQL_ATTR_OVERRIDE_PRIMARY_AFFINITY);//         3020
    ret = PyModule_AddIntMacro(m, SQL_ATTR_STREAM_OUTPUTLOB_ON_CALL);//          3021
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CACHE_USRLIBL);//                     3022
    ret = PyModule_AddIntMacro(m, SQL_ATTR_GET_LATEST_MEMBER_NAME);//            3023
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INFO_CRRTKN);//                       3024
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DATE_FMT);//                          3025
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DATE_SEP);//                          3026
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TIME_FMT);//                          3027
    ret = PyModule_AddIntMacro(m, SQL_ATTR_TIME_SEP);//                          3028
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DECIMAL_SEP);//                       3029
    ret = PyModule_AddIntMacro(m, SQL_ATTR_READ_ONLY_CONNECTION);//              3030
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONFIG_KEYWORDS_ARRAY_SIZE);//        3031
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONFIG_KEYWORDS_MAXLEN);//            3032
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RETRY_ON_MERGE);//                    3033
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DETECT_READ_ONLY_TXN);//              3034
    ret = PyModule_AddIntMacro(m, SQL_ATTR_IGNORE_SERVER_LIST);//                3035
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_LOADSTMT);//                 3037
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_RECDELIM);//                 3038
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_BEGIN);//                    3039
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_END);//                      3040
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_FILETYPE);//                 3041
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_MSGFILE);//                  3042
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_UTILITYID);//                3043
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONNECT_PASSIVE);//                   3045
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLIENT_APPLCOMPAT);//                 3046
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ZLOAD_LOADFILE);//                 3047
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PREFETCH_NROWS);//                    3048

    ret = PyModule_AddIntMacro(m, SQL_ATTR_WCHARTYPE);//          SQL_WCHARTYPE
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LONGDATA_COMPAT);//    SQL_LONGDATA_COMPAT
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURRENT_SCHEMA);//     SQL_CURRENT_SCHEMA
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2EXPLAIN);//         SQL_DB2EXPLAIN
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2ESTIMATE);//        SQL_DB2ESTIMATE
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PARAMOPT_ATOMIC);//    SQL_PARAMOPT_ATOMIC
    ret = PyModule_AddIntMacro(m, SQL_ATTR_STMTTXN_ISOLATION);//  SQL_STMTTXN_ISOLATION
    ret = PyModule_AddIntMacro(m, SQL_ATTR_MAXCONN);//            SQL_MAXCONN


    /* SQLGetInfo defines  - Info Type */
    ret = PyModule_AddIntMacro(m, SQL_DATA_SOURCE_NAME);
    ret = PyModule_AddIntMacro(m, SQL_FETCH_DIRECTION);
    ret = PyModule_AddIntMacro(m, SQL_SERVER_NAME);
    ret = PyModule_AddIntMacro(m, SQL_SEARCH_PATTERN_ESCAPE);
    ret = PyModule_AddIntMacro(m, SQL_DBMS_NAME);
    ret = PyModule_AddIntMacro(m, SQL_DBMS_VER);
    ret = PyModule_AddIntMacro(m, SQL_ACCESSIBLE_TABLES);
    ret = PyModule_AddIntMacro(m, SQL_ACCESSIBLE_PROCEDURES);
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_COMMIT_BEHAVIOR);
    ret = PyModule_AddIntMacro(m, SQL_DATA_SOURCE_READ_ONLY);
    ret = PyModule_AddIntMacro(m, SQL_DEFAULT_TXN_ISOLATION);
    ret = PyModule_AddIntMacro(m, SQL_IDENTIFIER_CASE);
    ret = PyModule_AddIntMacro(m, SQL_IDENTIFIER_QUOTE_CHAR);
    ret = PyModule_AddIntMacro(m, SQL_MAX_COLUMN_NAME_LEN);
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_COLUMN_NAME_LENGTH);
    ret = PyModule_AddIntMacro(m, SQL_MAX_CURSOR_NAME_LEN);
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_CURSOR_NAME_LENGTH);
    ret = PyModule_AddIntMacro(m, SQL_MAX_TABLE_NAME_LEN);
    ret = PyModule_AddIntMacro(m, SQL_SCROLL_CONCURRENCY);
    ret = PyModule_AddIntMacro(m, SQL_TXN_CAPABLE);
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_CAPABLE);
    ret = PyModule_AddIntMacro(m, SQL_USER_NAME);
    ret = PyModule_AddIntMacro(m, SQL_TXN_ISOLATION_OPTION);
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_ISOLATION_OPTION);
    ret = PyModule_AddIntMacro(m, SQL_GETDATA_EXTENSIONS);
    ret = PyModule_AddIntMacro(m, SQL_NULL_COLLATION);
    ret = PyModule_AddIntMacro(m, SQL_ALTER_TABLE);
    ret = PyModule_AddIntMacro(m, SQL_ORDER_BY_COLUMNS_IN_SELECT);
    ret = PyModule_AddIntMacro(m, SQL_SPECIAL_CHARACTERS);
    ret = PyModule_AddIntMacro(m, SQL_MAX_COLUMNS_IN_GROUP_BY);
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_COLUMNS_IN_GROUP_BY);
    ret = PyModule_AddIntMacro(m, SQL_MAX_COLUMNS_IN_INDEX);
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_COLUMNS_IN_INDEX);
    ret = PyModule_AddIntMacro(m, SQL_MAX_COLUMNS_IN_ORDER_BY);
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_COLUMNS_IN_ORDER_BY);
    ret = PyModule_AddIntMacro(m, SQL_MAX_COLUMNS_IN_SELECT);
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_COLUMNS_IN_SELECT);
    ret = PyModule_AddIntMacro(m, SQL_MAX_COLUMNS_IN_TABLE);
    ret = PyModule_AddIntMacro(m, SQL_MAX_INDEX_SIZE);//                  102
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_INDEX_SIZE);//              SQL_MAX_INDEX_SIZE
    ret = PyModule_AddIntMacro(m, SQL_MAX_ROW_SIZE);//                    104
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_ROW_SIZE);//                SQL_MAX_ROW_SIZE
    ret = PyModule_AddIntMacro(m, SQL_MAX_STATEMENT_LEN);//               105
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_STATEMENT_LENGTH);//        SQL_MAX_STATEMENT_LEN
    ret = PyModule_AddIntMacro(m, SQL_MAX_TABLES_IN_SELECT);//            106
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_TABLES_IN_SELECT);//        SQL_MAX_TABLES_IN_SELECT
    ret = PyModule_AddIntMacro(m, SQL_MAX_USER_NAME_LEN);//               107
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_USER_NAME_LENGTH);//        SQL_MAX_USER_NAME_LEN
    ret = PyModule_AddIntMacro(m, SQL_MAX_SCHEMA_NAME_LEN);//             SQL_MAX_OWNER_NAME_LEN
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_SCHEMA_NAME_LENGTH);//      SQL_MAX_SCHEMA_NAME_LEN
    ret = PyModule_AddIntMacro(m, SQL_MAX_CATALOG_NAME_LEN);//            SQL_MAX_QUALIFIER_NAME_LEN
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_CATALOG_NAME_LENGTH);//     SQL_MAX_CATALOG_NAME_LEN
    ret = PyModule_AddIntMacro(m, SQL_OJ_CAPABILITIES);//                115
#ifndef SQL_CONFIG_KEYWORDS
#define SQL_CONFIG_KEYWORDS 174
#endif
    ret = PyModule_AddIntMacro(m, SQL_CONFIG_KEYWORDS);//                174
    ret = PyModule_AddIntMacro(m, SQL_OUTER_JOIN_CAPABILITIES);//                SQL_OJ_CAPABILITIES
    ret = PyModule_AddIntMacro(m, SQL_XOPEN_CLI_YEAR);//               10000
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_SENSITIVITY);//           10001
    ret = PyModule_AddIntMacro(m, SQL_DESCRIBE_PARAMETER);//           10002
    ret = PyModule_AddIntMacro(m, SQL_CATALOG_NAME);//                 10003
    ret = PyModule_AddIntMacro(m, SQL_COLLATION_SEQ);//                10004
    ret = PyModule_AddIntMacro(m, SQL_MAX_IDENTIFIER_LEN);//           10005
    ret = PyModule_AddIntMacro(m, SQL_MAXIMUM_IDENTIFIER_LENGTH);//    SQL_MAX_IDENTIFIER_LEN
    ret = PyModule_AddIntMacro(m, SQL_INTEGRITY);//                       73
    ret = PyModule_AddIntMacro(m, SQL_DATABASE_CODEPAGE);//               2519
    ret = PyModule_AddIntMacro(m, SQL_APPLICATION_CODEPAGE);//            2520
    ret = PyModule_AddIntMacro(m, SQL_CONNECT_CODEPAGE);//                2521
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2_APPLICATION_ID);//         2532
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2_APPLICATION_HANDLE);//     2533
    ret = PyModule_AddIntMacro(m, SQL_ATTR_HANDLE_XA_ASSOCIATED);//       2535
    ret = PyModule_AddIntMacro(m, SQL_DB2_DRIVER_VER);//                  2550
    ret = PyModule_AddIntMacro(m, SQL_ATTR_XML_DECLARATION);//            2552
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURRENT_IMPLICIT_XMLPARSE_OPTION);//    2553
    ret = PyModule_AddIntMacro(m, SQL_ATTR_XQUERY_STATEMENT);//           2557
    ret = PyModule_AddIntMacro(m, SQL_DB2_DRIVER_TYPE);//                 2567
    ret = PyModule_AddIntMacro(m, SQL_INPUT_CHAR_CONVFACTOR);//           2581
    ret = PyModule_AddIntMacro(m, SQL_OUTPUT_CHAR_CONVFACTOR);//          2582
    ret = PyModule_AddIntMacro(m, SQL_ATTR_REPLACE_QUOTED_LITERALS);//    2586
    ret = PyModule_AddIntMacro(m, SQL_ATTR_REPORT_TIMESTAMP_TRUNC_AS_WARN);//    2587
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLIENT_ENCALG);//              2589
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CONCURRENT_ACCESS_RESOLUTION);//  2595      /*  @d348892lmy */
    ret = PyModule_AddIntMacro(m, SQL_ATTR_REPORT_SEAMLESSFAILOVER_WARNING);// 2605
    ret = PyModule_AddIntMacro(m, SQL_CONCURRENT_ACCESS_RESOLUTION_UNSET);//    0
    ret = PyModule_AddIntMacro(m, SQL_USE_CURRENTLY_COMMITTED);// 1
    ret = PyModule_AddIntMacro(m, SQL_WAIT_FOR_OUTCOME);// 2
    ret = PyModule_AddIntMacro(m, SQL_SKIP_LOCKED_DATA);//  3

#ifdef SQL_DBMS_FUNCTIONLVL
    ret = PyModule_AddIntMacro(m, SQL_DBMS_FUNCTIONLVL);//                203
#endif

    /* Options for SQLGetStmtOption/SQLSetStmtOption */

    ret = PyModule_AddIntMacro(m, SQL_ATTR_AUTO_IPD);
    ret = PyModule_AddIntMacro(m, SQL_ATTR_APP_ROW_DESC);      
    ret = PyModule_AddIntMacro(m, SQL_ATTR_APP_PARAM_DESC);    
    ret = PyModule_AddIntMacro(m, SQL_ATTR_IMP_ROW_DESC);      
    ret = PyModule_AddIntMacro(m, SQL_ATTR_IMP_PARAM_DESC);    
    ret = PyModule_AddIntMacro(m, SQL_ATTR_METADATA_ID);       
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURSOR_SCROLLABLE); 
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURSOR_SENSITIVITY); 

    /* CLI attribute/option values */
    ret = PyModule_AddIntMacro(m, SQL_FALSE);
    ret = PyModule_AddIntMacro(m, SQL_TRUE);

    /* Options for SQLGetStmtOption/SQLSetStmtOption extensions */
    ret = PyModule_AddIntMacro(m, SQL_CURSOR_HOLD);//             1250
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURSOR_HOLD);//         1250
    ret = PyModule_AddIntMacro(m, SQL_NODESCRIBE_OUTPUT);//        1251
    ret = PyModule_AddIntMacro(m, SQL_ATTR_NODESCRIBE_OUTPUT);//   1251

    ret = PyModule_AddIntMacro(m, SQL_NODESCRIBE_INPUT);//         1264
    ret = PyModule_AddIntMacro(m, SQL_ATTR_NODESCRIBE_INPUT);//    1264
    ret = PyModule_AddIntMacro(m, SQL_NODESCRIBE);//               SQL_NODESCRIBE_OUTPUT
    ret = PyModule_AddIntMacro(m, SQL_ATTR_NODESCRIBE);//          SQL_NODESCRIBE_OUTPUT
    ret = PyModule_AddIntMacro(m, SQL_CLOSE_BEHAVIOR);//           1257
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLOSE_BEHAVIOR);//      1257
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLOSE_BEHAVIOR);//      1257
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLOSEOPEN);//           1265
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURRENT_PACKAGE_SET);// 1276
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DEFERRED_PREPARE);//    1277
    ret = PyModule_AddIntMacro(m, SQL_ATTR_EARLYCLOSE);//          1268
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PROCESSCTL);//          1278
    ret = PyModule_AddIntMacro(m, SQL_ATTR_PREFETCH);//            1285
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ENABLE_IPD_SETTING);//  1286
    ret = PyModule_AddIntMacro(m, SQL_ATTR_RETRYONERROR);//        121

    /* SQL_CLOSE_BEHAVIOR values.                  */

    ret = PyModule_AddIntMacro(m, SQL_CC_NO_RELEASE);
    ret = PyModule_AddIntMacro(m, SQL_CC_RELEASE);
    ret = PyModule_AddIntMacro(m, SQL_CC_DEFAULT);

    /*
    * Options for SQL_ATTR_INSERT_BUFFERING
    */
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INSERT_BUFFERING_OFF);//     0
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INSERT_BUFFERING_ON);//      1
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INSERT_BUFFERING_IGD);//     2

    /*
    * Options for SQL_ATTR_ROWCOUNT_PREFETCH
    */
    ret = PyModule_AddIntMacro(m, SQL_ROWCOUNT_PREFETCH_OFF);//   0
    ret = PyModule_AddIntMacro(m, SQL_ROWCOUNT_PREFETCH_ON);//    1

    /* Column types and scopes in SQLSpecialColumns */

    ret = PyModule_AddIntMacro(m, SQL_SCOPE_CURROW);//             0
    ret = PyModule_AddIntMacro(m, SQL_SCOPE_TRANSACTION);//        1
    ret = PyModule_AddIntMacro(m, SQL_SCOPE_SESSION);//            2

    /* Defines for SQLStatistics */
    ret = PyModule_AddIntMacro(m, SQL_INDEX_UNIQUE);//             0
    ret = PyModule_AddIntMacro(m, SQL_INDEX_ALL);//                1

    /* Defines for SQLStatistics (returned in the result set) */
    ret = PyModule_AddIntMacro(m, SQL_INDEX_CLUSTERED);//          1
    ret = PyModule_AddIntMacro(m, SQL_INDEX_HASHED);//             2
    ret = PyModule_AddIntMacro(m, SQL_INDEX_OTHER);//              3

    /* Defines for SQLSpecialColumns (returned in the result set) */
    ret = PyModule_AddIntMacro(m, SQL_PC_UNKNOWN);//               0
    ret = PyModule_AddIntMacro(m, SQL_PC_NON_PSEUDO);//            1
    ret = PyModule_AddIntMacro(m, SQL_PC_PSEUDO);//                2

    /* Reserved value for the IdentifierType argument of SQLSpecialColumns() */
    ret = PyModule_AddIntMacro(m, SQL_ROW_IDENTIFIER);//  1

    /* Options for SQL_ATTR_MAPGRAPHIC */
    ret = PyModule_AddIntMacro(m, SQL_MAPGRAPHIC_DEFAULT);//      -1
    ret = PyModule_AddIntMacro(m, SQL_MAPGRAPHIC_GRAPHIC);//       0
    ret = PyModule_AddIntMacro(m, SQL_MAPGRAPHIC_WCHAR);//         1

    /* Options for SQL_ATTR_MAPCHAR */
    ret = PyModule_AddIntMacro(m, SQL_MAPCHAR_DEFAULT);//          0
    ret = PyModule_AddIntMacro(m, SQL_MAPCHAR_WCHAR);//            1

    /* SQLDataSources "fDirection" values, also used on SQLExtendedFetch() */
    /* See sqlext.h for additional SQLExtendedFetch fetch direction defines */
    ret = PyModule_AddIntMacro(m,  SQL_FETCH_NEXT);//              1
    ret = PyModule_AddIntMacro(m,  SQL_FETCH_FIRST);//             2

    /* OTHER CODES USED FOR FETCHORIENTATION IN SQLFETCHSCROLL() */
    ret = PyModule_AddIntMacro(m, SQL_FETCH_LAST);//      3
    ret = PyModule_AddIntMacro(m, SQL_FETCH_PRIOR);//     4
    ret = PyModule_AddIntMacro(m, SQL_FETCH_ABSOLUTE);//  5
    ret = PyModule_AddIntMacro(m, SQL_FETCH_RELATIVE);//  6

    /*
        *IBM specific SQLGetInfo values.
    */

    ret = PyModule_AddIntMacro(m, SQL_IBM_ALTERTABLEVARCHAR);

        /* SQL_ALTER_TABLE bitmasks */
    ret = PyModule_AddIntMacro(m, SQL_AT_ADD_COLUMN);//                       0x00000001L
    ret = PyModule_AddIntMacro(m, SQL_AT_DROP_COLUMN);//                      0x00000002L
    ret = PyModule_AddIntMacro(m, SQL_AT_ADD_CONSTRAINT);//                   0x00000008L

    /* SQL_CURSOR_COMMIT_BEHAVIOR and SQL_CURSOR_ROLLBACK_BEHAVIOR values */

    ret = PyModule_AddIntMacro(m, SQL_CB_DELETE);//                 0x0000
    ret = PyModule_AddIntMacro(m, SQL_CB_CLOSE);//                  0x0001
    ret = PyModule_AddIntMacro(m, SQL_CB_PRESERVE);//               0x0002

    /* SQL_IDENTIFIER_CASE values */

    ret = PyModule_AddIntMacro(m, SQL_IC_UPPER);//                  0x0001
    ret = PyModule_AddIntMacro(m, SQL_IC_LOWER);//                  0x0002
    ret = PyModule_AddIntMacro(m, SQL_IC_SENSITIVE);//              0x0003
    ret = PyModule_AddIntMacro(m, SQL_IC_MIXED);//                  0x0004

    /* SQL_TXN_CAPABLE values */

    ret = PyModule_AddIntMacro(m, SQL_TC_NONE);//                   0x0000
    ret = PyModule_AddIntMacro(m, SQL_TC_DML);//                    0x0001
    ret = PyModule_AddIntMacro(m, SQL_TC_ALL);//                    0x0002
    ret = PyModule_AddIntMacro(m, SQL_TC_DDL_COMMIT);//             0x0003
    ret = PyModule_AddIntMacro(m, SQL_TC_DDL_IGNORE);//             0x0004

    /* SQL_SCROLL_CONCURRENCY masks */

    ret = PyModule_AddIntMacro(m, SQL_SCCO_READ_ONLY);//            0x00000001L
    ret = PyModule_AddIntMacro(m, SQL_SCCO_LOCK);//                 0x00000002L
    ret = PyModule_AddIntMacro(m, SQL_SCCO_OPT_ROWVER);//           0x00000004L
    ret = PyModule_AddIntMacro(m, SQL_SCCO_OPT_VALUES);//           0x00000008L

    /* SQL_FETCH_DIRECTION masks */

    ret = PyModule_AddIntMacro(m,  SQL_FD_FETCH_NEXT);//            0x00000001L
    ret = PyModule_AddIntMacro(m,  SQL_FD_FETCH_FIRST);//           0x00000002L
    ret = PyModule_AddIntMacro(m,  SQL_FD_FETCH_LAST);//            0x00000004L
    ret = PyModule_AddIntMacro(m,  SQL_FD_FETCH_PRIOR);//           0x00000008L
    ret = PyModule_AddIntMacro(m,  SQL_FD_FETCH_ABSOLUTE);//        0x00000010L
    ret = PyModule_AddIntMacro(m,  SQL_FD_FETCH_RELATIVE);//        0x00000020L
    ret = PyModule_AddIntMacro(m,  SQL_FD_FETCH_RESUME);//          0x00000040L

    /* SQL_TXN_ISOLATION_OPTION masks */
    ret = PyModule_AddIntMacro(m, SQL_TXN_READ_UNCOMMITTED);//            0x00000001L
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_READ_UNCOMMITTED);//        SQL_TXN_READ_UNCOMMITTED
    ret = PyModule_AddIntMacro(m, SQL_TXN_READ_COMMITTED);//              0x00000002L
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_READ_COMMITTED);//          SQL_TXN_READ_COMMITTED
    ret = PyModule_AddIntMacro(m, SQL_TXN_REPEATABLE_READ);//             0x00000004L
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_REPEATABLE_READ);//         SQL_TXN_REPEATABLE_READ
    ret = PyModule_AddIntMacro(m, SQL_TXN_SERIALIZABLE);//                0x00000008L
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_SERIALIZABLE);//            SQL_TXN_SERIALIZABLE
    ret = PyModule_AddIntMacro(m, SQL_TXN_NOCOMMIT);//                   0x00000020L
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_NOCOMMIT);//                SQL_TXN_NOCOMMIT
    ret = PyModule_AddIntMacro(m, SQL_TXN_IDS_CURSOR_STABILITY);//        0x00000040L
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_IDS_CURSOR_STABILITY);//    SQL_TXN_IDS_CURSOR_STABILITY
    ret = PyModule_AddIntMacro(m, SQL_TXN_IDS_LAST_COMMITTED);//          0x00000080L
    ret = PyModule_AddIntMacro(m, SQL_TRANSACTION_IDS_LAST_COMMITTED);//      SQL_TXN_IDS_LAST_COMMITTED

    /* SQL_GETDATA_EXTENSIONS values */

    ret = PyModule_AddIntMacro(m, SQL_GD_ANY_COLUMN);//             0x00000001L
    ret = PyModule_AddIntMacro(m, SQL_GD_ANY_ORDER);//              0x00000002L

    /* SQL_OJ_CAPABILITIES values */

    ret = PyModule_AddIntMacro(m, SQL_OJ_LEFT);//                   0x00000001L
    ret = PyModule_AddIntMacro(m, SQL_OJ_RIGHT);//                  0x00000002L
    ret = PyModule_AddIntMacro(m, SQL_OJ_FULL);//                   0x00000004L
    ret = PyModule_AddIntMacro(m, SQL_OJ_NESTED);//                 0x00000008L
    ret = PyModule_AddIntMacro(m, SQL_OJ_NOT_ORDERED);//            0x00000010L
    ret = PyModule_AddIntMacro(m, SQL_OJ_INNER);//                  0x00000020L
    ret = PyModule_AddIntMacro(m, SQL_OJ_ALL_COMPARISON_OPS);//     0x00000040L

    /* SQL_DB2_DRIVER_TYPE values */
    ret = PyModule_AddIntMacro(m, SQL_CLI_DRIVER_TYPE_UNDEFINED);// 0
    ret = PyModule_AddIntMacro(m, SQL_CLI_DRIVER_RUNTIME_CLIENT);// 1
    ret = PyModule_AddIntMacro(m, SQL_CLI_DRIVER_CLI_DRIVER);// 2

    /* identifiers of fields in the diagnostics area */
    ret = PyModule_AddIntMacro(m, SQL_DIAG_RETURNCODE);//        1
    ret = PyModule_AddIntMacro(m, SQL_DIAG_NUMBER);//            2
    ret = PyModule_AddIntMacro(m, SQL_DIAG_ROW_COUNT);//         3
    ret = PyModule_AddIntMacro(m, SQL_DIAG_SQLSTATE);//          4
    ret = PyModule_AddIntMacro(m, SQL_DIAG_NATIVE);//            5
    ret = PyModule_AddIntMacro(m, SQL_DIAG_MESSAGE_TEXT);//      6
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DYNAMIC_FUNCTION);//  7
    ret = PyModule_AddIntMacro(m, SQL_DIAG_CLASS_ORIGIN);//      8
    ret = PyModule_AddIntMacro(m, SQL_DIAG_SUBCLASS_ORIGIN);//   9
    ret = PyModule_AddIntMacro(m, SQL_DIAG_CONNECTION_NAME);//  10
    ret = PyModule_AddIntMacro(m, SQL_DIAG_SERVER_NAME);//      11
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DYNAMIC_FUNCTION_CODE);// 12
    ret = PyModule_AddIntMacro(m, SQL_DIAG_ISAM_ERROR);//       13

#if !defined(SQL_DIAG_SYSPLEX_STATISTICS) || !defined(SQL_DIAG_DB2ZLOAD_RETCODE)
#define SQL_DIAG_SYSPLEX_STATISTICS  2528
#define SQL_DIAG_DB2ZLOAD_RETCODE    2529
#define SQL_DIAG_DB2ZLOAD_LOAD_MSGS  2530
#define SQL_DIAG_LOG_FILENAME        2531
#define SQL_DIAG_BAD_FILENAME        2532
#endif


    ret = PyModule_AddIntMacro(m, SQL_DIAG_SYSPLEX_STATISTICS);// 2528
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DB2ZLOAD_RETCODE);//   2529 
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DB2ZLOAD_LOAD_MSGS);// 2530 
    ret = PyModule_AddIntMacro(m, SQL_DIAG_LOG_FILENAME);//       2531
    ret = PyModule_AddIntMacro(m, SQL_DIAG_BAD_FILENAME);//       2532

    /* dynamic function codes */
    ret = PyModule_AddIntMacro(m, SQL_DIAG_ALTER_TABLE);//            4
    ret = PyModule_AddIntMacro(m, SQL_DIAG_CALL);//                  7
    ret = PyModule_AddIntMacro(m, SQL_DIAG_CREATE_INDEX);//          (-1)
    ret = PyModule_AddIntMacro(m, SQL_DIAG_CREATE_TABLE);//          77
    ret = PyModule_AddIntMacro(m, SQL_DIAG_CREATE_VIEW);//           84
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DELETE_WHERE);//          19
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DROP_INDEX);//            (-2)
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DROP_TABLE);//            32
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DROP_VIEW);//             36
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DYNAMIC_DELETE_CURSOR);// 38
    ret = PyModule_AddIntMacro(m, SQL_DIAG_DYNAMIC_UPDATE_CURSOR);// 81
    ret = PyModule_AddIntMacro(m, SQL_DIAG_GRANT);//                 48
    ret = PyModule_AddIntMacro(m, SQL_DIAG_INSERT);//                50
    ret = PyModule_AddIntMacro(m, SQL_DIAG_MERGE);//                128
    ret = PyModule_AddIntMacro(m, SQL_DIAG_REVOKE);//                59
    ret = PyModule_AddIntMacro(m, SQL_DIAG_SELECT_CURSOR);//         85
    ret = PyModule_AddIntMacro(m, SQL_DIAG_UNKNOWN_STATEMENT);//      0
    ret = PyModule_AddIntMacro(m, SQL_DIAG_UPDATE_WHERE);//          82


    return ret;

}

int add_sqlcli(PyObject* m)
{
    int ret;

    /* generally useful constants */
    ret = PyModule_AddIntMacro(m, SQL_MAX_MESSAGE_LENGTH);/* message buffer size             */
    ret = PyModule_AddIntMacro(m, SQL_MAX_ID_LENGTH);     /* maximum identifier name size,
                                                             e.g. cursor names               */

                                                          /* date/time length constants */
    ret = PyModule_AddIntMacro(m, SQL_DATE_LEN);
    ret = PyModule_AddIntMacro(m, SQL_TIME_LEN);          /* add P+1 if precision is nonzero */
    ret = PyModule_AddIntMacro(m, SQL_TIMESTAMP_LEN);     /* add P+1 if precision is nonzero */
    ret = PyModule_AddIntMacro(m, SQL_TIMESTAMPTZ_LEN);   /* add P+1 if precision is nonzero */

    /* handle type identifiers */
    ret = PyModule_AddIntMacro(m, SQL_HANDLE_ENV);
    ret = PyModule_AddIntMacro(m, SQL_HANDLE_DBC);
    ret = PyModule_AddIntMacro(m, SQL_HANDLE_STMT);
    ret = PyModule_AddIntMacro(m, SQL_HANDLE_DESC);


    /* NULL handle defines    */
    ret = PyModule_AddIntMacro(m, SQL_NULL_HENV);
    ret = PyModule_AddIntMacro(m, SQL_NULL_HDBC);
    ret = PyModule_AddIntMacro(m, SQL_NULL_HSTMT);
    ret = PyModule_AddIntMacro(m, SQL_NULL_HDESC);
    ret = PyModule_AddIntMacro(m, SQL_NULL_HANDLE);

    /* RETCODE values             */
    ret = PyModule_AddIntMacro(m, SQL_SUCCESS);
    ret = PyModule_AddIntMacro(m, SQL_SUCCESS_WITH_INFO);
    ret = PyModule_AddIntMacro(m, SQL_NEED_DATA);
    ret = PyModule_AddIntMacro(m, SQL_NO_DATA);
    ret = PyModule_AddIntMacro(m, SQL_STILL_EXECUTING);
    ret = PyModule_AddIntMacro(m, SQL_ERROR);
    ret = PyModule_AddIntMacro(m, SQL_INVALID_HANDLE);

    /* SQLFreeStmt option values  */
    ret = PyModule_AddIntMacro(m, SQL_CLOSE);
    ret = PyModule_AddIntMacro(m, SQL_DROP);
    ret = PyModule_AddIntMacro(m, SQL_UNBIND);
    ret = PyModule_AddIntMacro(m, SQL_RESET_PARAMS);

    /* SQLTransact option values  */
    ret = PyModule_AddIntMacro(m, SQL_COMMIT);
    ret = PyModule_AddIntMacro(m, SQL_ROLLBACK);


    /* Standard SQL data types */
    ret = PyModule_AddIntMacro(m, SQL_UNKNOWN_TYPE);
    ret = PyModule_AddIntMacro(m, SQL_CHAR);
    ret = PyModule_AddIntMacro(m, SQL_NUMERIC);
    ret = PyModule_AddIntMacro(m, SQL_DECIMAL);
    ret = PyModule_AddIntMacro(m, SQL_INTEGER);
    ret = PyModule_AddIntMacro(m, SQL_SMALLINT);
    ret = PyModule_AddIntMacro(m, SQL_FLOAT);
    ret = PyModule_AddIntMacro(m, SQL_REAL);
    ret = PyModule_AddIntMacro(m, SQL_DOUBLE);
    ret = PyModule_AddIntMacro(m, SQL_DATETIME);
    ret = PyModule_AddIntMacro(m, SQL_VARCHAR);
    ret = PyModule_AddIntMacro(m, SQL_BOOLEAN);
    ret = PyModule_AddIntMacro(m, SQL_ROW);
    ret = PyModule_AddIntMacro(m, SQL_WCHAR);
    ret = PyModule_AddIntMacro(m, SQL_WVARCHAR);
    ret = PyModule_AddIntMacro(m, SQL_WLONGVARCHAR);
    ret = PyModule_AddIntMacro(m, SQL_DECFLOAT);
    /* One-parameter shortcuts for date/time data types */
    ret = PyModule_AddIntMacro(m, SQL_TYPE_DATE);
    ret = PyModule_AddIntMacro(m, SQL_TYPE_TIME);
    ret = PyModule_AddIntMacro(m, SQL_TYPE_TIMESTAMP);
    /* SQL Datatype for Time Zone */
    ret = PyModule_AddIntMacro(m, SQL_TYPE_TIMESTAMP_WITH_TIMEZONE);

    /* Statement attribute values for cursor sensitivity */
    ret = PyModule_AddIntMacro(m, SQL_UNSPECIFIED);
    ret = PyModule_AddIntMacro(m, SQL_INSENSITIVE);
    ret = PyModule_AddIntMacro(m, SQL_SENSITIVE);

    /* Default conversion code for SQLBindCol(), SQLBindParam() and SQLGetData() */
    ret = PyModule_AddIntMacro(m, SQL_DEFAULT);

    /* SQLGetData() code indicating that the application row descriptor
     * specifies the data type
     */
    ret = PyModule_AddIntMacro(m, SQL_ARD_TYPE);

    /* SQL date/time type subcodes */
    ret = PyModule_AddIntMacro(m, SQL_CODE_DATE);
    ret = PyModule_AddIntMacro(m, SQL_CODE_TIME);
    ret = PyModule_AddIntMacro(m, SQL_CODE_TIMESTAMP);
    ret = PyModule_AddIntMacro(m, SQL_CODE_TIMESTAMP_WITH_TIMEZONE);

    /* SQL extended data types */
    ret = PyModule_AddIntMacro(m, SQL_GRAPHIC);
    ret = PyModule_AddIntMacro(m, SQL_VARGRAPHIC);
    ret = PyModule_AddIntMacro(m, SQL_LONGVARGRAPHIC);
    ret = PyModule_AddIntMacro(m, SQL_BLOB);
    ret = PyModule_AddIntMacro(m, SQL_CLOB);
    ret = PyModule_AddIntMacro(m, SQL_DBCLOB);
    ret = PyModule_AddIntMacro(m, SQL_XML);
    ret = PyModule_AddIntMacro(m, SQL_CURSORHANDLE);
    ret = PyModule_AddIntMacro(m, SQL_DATALINK);
    ret = PyModule_AddIntMacro(m, SQL_USER_DEFINED_TYPE);

    /* C data type to SQL data type mapping */
    ret = PyModule_AddIntMacro(m, SQL_C_DBCHAR);
    ret = PyModule_AddIntMacro(m, SQL_C_DECIMAL_IBM);
    ret = PyModule_AddIntMacro(m, SQL_C_CHAR);
    ret = PyModule_AddIntMacro(m, SQL_C_PTR);
    ret = PyModule_AddIntMacro(m, SQL_C_DECIMAL_OLEDB);
    ret = PyModule_AddIntMacro(m, SQL_C_DECIMAL64);
    ret = PyModule_AddIntMacro(m, SQL_C_DECIMAL128);
    ret = PyModule_AddIntMacro(m, SQL_C_TIMESTAMP_EXT);
    ret = PyModule_AddIntMacro(m, SQL_C_TYPE_TIMESTAMP_EXT);
    ret = PyModule_AddIntMacro(m, SQL_C_BINARYXML);
    ret = PyModule_AddIntMacro(m, SQL_C_TIMESTAMP_EXT_TZ);
    ret = PyModule_AddIntMacro(m, SQL_C_TYPE_TIMESTAMP_EXT_TZ);
#ifndef SQL_C_CURSORHANDLE
#define SQL_C_CURSORHANDLE   -365
#endif
    ret = PyModule_AddIntMacro(m, SQL_C_CURSORHANDLE);

    /*
    *  locator type identifier
    */

    ret = PyModule_AddIntMacro(m, SQL_BLOB_LOCATOR);
    ret = PyModule_AddIntMacro(m, SQL_CLOB_LOCATOR);
    ret = PyModule_AddIntMacro(m, SQL_DBCLOB_LOCATOR);

    /*
    * C Data Type for the LOB locator types
    */
    ret = PyModule_AddIntMacro(m, SQL_C_BLOB_LOCATOR);
    ret = PyModule_AddIntMacro(m, SQL_C_CLOB_LOCATOR);
    ret = PyModule_AddIntMacro(m, SQL_C_DBCLOB_LOCATOR);

    /*
    * NULL status defines; these are used in SQLColAttributes, SQLDescribeCol,
    * to describe the nullability of a column in a table.
    */

    ret = PyModule_AddIntMacro(m,  SQL_NO_NULLS);//         0
    ret = PyModule_AddIntMacro(m,  SQL_NULLABLE);//         1
    ret = PyModule_AddIntMacro(m,  SQL_NULLABLE_UNKNOWN);// 2

    /* values of UNNAMED field in descriptor used in SQLColAttribute */
    ret = PyModule_AddIntMacro(m, SQL_NAMED);//             0
    ret = PyModule_AddIntMacro(m, SQL_UNNAMED);//           1

    /* values of ALLOC_TYPE field in descriptor */
    ret = PyModule_AddIntMacro(m, SQL_DESC_ALLOC_AUTO);// 1
    ret = PyModule_AddIntMacro(m, SQL_DESC_ALLOC_USER);// 2

    /* values of USER_DEFINED_TYPE_CODE */
    ret = PyModule_AddIntMacro(m, SQL_TYPE_BASE);//            0
    ret = PyModule_AddIntMacro(m, SQL_TYPE_DISTINCT);//        1
    ret = PyModule_AddIntMacro(m, SQL_TYPE_STRUCTURED);//      2
    ret = PyModule_AddIntMacro(m, SQL_TYPE_REFERENCE);//       3


    /* Special length values  */
    ret = PyModule_AddIntMacro(m, SQL_NULL_DATA);
    ret = PyModule_AddIntMacro(m, SQL_DATA_AT_EXEC);
    ret = PyModule_AddIntMacro(m, SQL_NTS);         /* NTS = Null Terminated String    */
    ret = PyModule_AddIntMacro(m, SQL_NTSL);        /* NTS = Null Terminated String    */


/* Defines for SQLF_DBTN_AUTONOMIC_SWITCHES                                   */
/* Each bit below represents an individual parameter inside                   */
/* the autonomic switches bitmap                                              */
#ifndef SQLF_ENABLE_AUTO_MAINT
    /* Defines for SQLF_DBTN_AUTONOMIC_SWITCHES                                   */
    /* Each bit below represents an individual parameter inside                   */
    /* the autonomic switches bitmap                                              */
    #define SQLF_ENABLE_AUTO_MAINT        1    /* xxxx xxxx xxxx xxx1             */
    #define SQLF_ENABLE_AUTO_DB_BACKUP    2    /* xxxx xxxx xxxx xx1x             */
    #define SQLF_ENABLE_AUTO_TBL_MAINT    4    /* xxxx xxxx xxxx x1xx             */
    #define SQLF_ENABLE_AUTO_RUNSTATS     8    /* xxxx xxxx xxxx 1xxx             */
    #define SQLF_ENABLE_AUTO_STATS_PROF   16   /* Deprecated since v10.1          */
                                               /* xxxx xxxx xxx1 xxxx             */
    #define SQLF_ENABLE_AUTO_PROF_UPD     32   /* xxxx xxxx xx1x xxxx             */
    #define SQLF_ENABLE_AUTO_REORG        64   /* xxxx xxxx x1xx xxxx             */
    #define SQLF_ENABLE_AUTOMATIC_STORAGE 128  /* Informational only.             */
                                               /* xxxx xxxx 1xxx xxxx             */
    #define SQLF_ENABLE_AUTO_STMT_STATS   256  /* xxxx xxx1 xxxx xxxx             */
    #define SQLF_ENABLE_AUTO_STATS_VIEWS  512  /* xxxx xx1x xxxx xxxx             */
    #define SQLF_ENABLE_AUTO_SAMPLING     1024 /* xxxx x1xx xxxx xxxx             */

#endif
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_MAINT);           /* xxxx xxxx xxxx xxx1             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_DB_BACKUP);       /* xxxx xxxx xxxx xx1x             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_TBL_MAINT);       /* xxxx xxxx xxxx x1xx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_RUNSTATS);        /* xxxx xxxx xxxx 1xxx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_STATS_PROF);      /* Deprecated since v10.1          */
                                                                     /* xxxx xxxx xxx1 xxxx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_PROF_UPD);        /* xxxx xxxx xx1x xxxx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_REORG);           /* xxxx xxxx x1xx xxxx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTOMATIC_STORAGE);    /* Informational only.             */
                                                                     /* xxxx xxxx 1xxx xxxx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_STMT_STATS);      /* xxxx xxx1 xxxx xxxx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_STATS_VIEWS);     /* xxxx xx1x xxxx xxxx             */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_SAMPLING);        /* xxxx x1xx xxxx xxxx             */



    ret = PyModule_AddIntMacro(m, SQL_ATTR_USE_LOAD_API);//               2482
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_RECOVERABLE);//           2483
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_COPY_LOCATION);//         2484
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_MESSAGE_FILE);//          2485
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_SAVECOUNT);//             2486
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_CPU_PARALLELISM);//       2487
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_DISK_PARALLELISM);//      2488
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_INDEXING_MODE);//         2489
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_STATS_MODE);//            2490
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_TEMP_FILES_PATH);//       2491
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_DATA_BUFFER_SIZE);//      2492
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_MODIFIED_BY);//           2493
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2_RESERVED_2494);//          2494
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DESCRIBE_BEHAVIOR);//          2495
    ret = PyModule_AddIntMacro(m, SQL_ATTR_FETCH_SENSITIVITY);//          2496
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DB2_RESERVED_2497);//          2497
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLIENT_LOB_BUFFERING);//       2498
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SKIP_TRACE);//                 2499
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_INFO);//                  2501
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DESCRIBE_INPUT_ON_PREPARE);//  2505
    ret = PyModule_AddIntMacro(m, SQL_ATTR_DESCRIBE_OUTPUT_LEVEL);//      2506
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CURRENT_PACKAGE_PATH);//       2509
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INFO_PROGRAMID);//             2511
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INFO_PROGRAMNAME);//           2516
    ret = PyModule_AddIntMacro(m, SQL_ATTR_FREE_LOCATORS_ON_FETCH);//     2518
    ret = PyModule_AddIntMacro(m, SQL_ATTR_KEEP_DYNAMIC);//               2522
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_ROWS_READ_PTR);//         2524
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_ROWS_SKIPPED_PTR);//      2525
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_ROWS_COMMITTED_PTR);//    2526
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_ROWS_LOADED_PTR);//       2527
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_ROWS_REJECTED_PTR);//     2528
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_ROWS_DELETED_PTR);//      2529
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_INFO_VER);//              2530
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SET_SSA);//                    2531
    ret = PyModule_AddIntMacro(m, SQL_ATTR_BLOCK_LOBS);//                 2534
    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_ACCESS_LEVEL);//          2536
    ret = PyModule_AddIntMacro(m, SQL_ATTR_MAPCHAR);//                    2546
    ret = PyModule_AddIntMacro(m, SQL_ATTR_ARM_CORRELATOR);//             2554
    ret = PyModule_AddIntMacro(m, SQL_ATTR_CLIENT_DEBUGINFO);//           2556
    ret = PyModule_AddIntMacro(m, SQL_ATTR_GET_GENERATED_VALUE);//        2583
    ret = PyModule_AddIntMacro(m, SQL_ATTR_GET_SERIAL_VALUE);//           2584
    ret = PyModule_AddIntMacro(m, SQL_ATTR_INTERLEAVED_PUTDATA);//        2591
    ret = PyModule_AddIntMacro(m, SQL_ATTR_FORCE_ROLLBACK);//             2596
    ret = PyModule_AddIntMacro(m, SQL_ATTR_STMT_CONCENTRATOR);//          2597

#ifndef SQL_ATTR_LOAD_REPLACE_OPTION
#define SQL_ATTR_LOAD_REPLACE_OPTION 3036
#define SQL_ATTR_SESSION_GLOBAL_VAR  3044
#define SQL_ATTR_SPECIAL_REGISTER    3049
#endif

#ifndef SQL_LOAD_KEEPDICTIONARY
#define SQL_LOAD_KEEPDICTIONARY 1
#define SQL_LOAD_RESETDICTIONARY 2
#define SQL_LOAD_RESETDICTIONARYONLY 3
#define SQL_LOAD_REPLACE_DEFAULT 0

#endif
    ret = PyModule_AddIntMacro(m, SQL_LOAD_KEEPDICTIONARY);
    ret = PyModule_AddIntMacro(m, SQL_LOAD_RESETDICTIONARY);
    ret = PyModule_AddIntMacro(m, SQL_LOAD_RESETDICTIONARYONLY);
    ret = PyModule_AddIntMacro(m, SQL_LOAD_REPLACE_DEFAULT);

    ret = PyModule_AddIntMacro(m, SQL_ATTR_LOAD_REPLACE_OPTION);//        3036
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SESSION_GLOBAL_VAR);//         3044
    ret = PyModule_AddIntMacro(m, SQL_ATTR_SPECIAL_REGISTER);//           3049    

    /* define constants for statement concentrator attribute */
    ret = PyModule_AddIntMacro(m, SQL_STMT_CONCENTRATOR_OFF);//   1
    ret = PyModule_AddIntMacro(m, SQL_STMT_CONCENTRATOR_WITH_LITERALS);// 2

    ret = PyModule_AddIntMacro(m, SQL_INFO_LAST);//                         174
    ret = PyModule_AddIntMacro(m, SQL_INFO_DRIVER_START);//                 1000
    /* SQL_ATTR_FORCE_ROLLBACK option */
    ret = PyModule_AddIntMacro(m, SQL_FORCE_ROLLBACK_ON);//             1
    ret = PyModule_AddIntMacro(m, SQL_FORCE_ROLLBACK_OFF);//            0
    ret = PyModule_AddIntMacro(m, SQL_FORCE_ROLLBACK_DEFAULT);//        SQL_FORCE_ROLLBACK_OFF



    return ret;
}

int add_sqlutil(PyObject* m)
{
    int ret;

    /* Parameters for Rollforward caller action                                   */
    ret = PyModule_AddIntMacro(m, SQLUM_ROLLFWD);//        1            /* Roll forward to requested point     */
    ret = PyModule_AddIntMacro(m, SQLUM_STOP);//           2            /* End roll-forward recovery           */
    ret = PyModule_AddIntMacro(m, SQLUM_COMPLETE);//       2            /* End roll-forward recovery           */
    ret = PyModule_AddIntMacro(m, SQLUM_ROLLFWD_STOP);//   3            /* Roll forward to requested point     */
                                                                        /* and end roll-forward recovery       */
    ret = PyModule_AddIntMacro(m, SQLUM_ROLLFWD_COMPLETE);//3           /* Roll forward to requested point     */
                                                                        /* and end roll-forward recovery       */
    ret = PyModule_AddIntMacro(m, SQLUM_QUERY);//          4            /* Query nextArcFile, firstDeleteArc,  */
                                                                        /* lastDeleteArc, lastCommitTime       */
    ret = PyModule_AddIntMacro(m, SQLUM_CANCEL);//         8            /* Cancel current rollforward          */
    ret = PyModule_AddIntMacro(m, SQLUM_PARM_CHECK);//     10           /* Parameter check                     */
    ret = PyModule_AddIntMacro(m, SQLUM_LOADREC_CONTINUE);//  11        /* Continue load recovery.             */
    ret = PyModule_AddIntMacro(m, SQLUM_LOADREC_TERMINATE);// 12        /* Terminate load recovery.            */
    ret = PyModule_AddIntMacro(m, SQLUM_LOADREC_DEVICE_TERMINATE);// 13 /* Terminate device.Caller action   */
                                                                        /* codes 31 - 50 reserved for          */
                                                                        /* internal use.                       */

    /* Constants used for Rollforward                                             */
    ret = PyModule_AddStringMacro(m, SQLUM_INFINITY_TIMESTAMP);// "9999-12-31-23.59.59.999999" /* Roll         */
                                                                                               /* forward until STOP specified        */
    ret = PyModule_AddIntMacro(m, SQLUM_ARCHIVE_FILE_LEN);// 12      /* Length of Archive File name         */
    ret = PyModule_AddIntMacro(m, SQLUM_TIMESTAMP_LEN);//    26      /* Length of ISO format Timestamp      */

    /* Roll forward input version values                                          */
    ret = PyModule_AddIntMacro(m, SQLUM_RFWD_VERSION);// 5       /* current rollforward input version   */

    /* Roll forward allNodeFlag values                                            */
    ret = PyModule_AddIntMacro(m, SQLURF_NODE_LIST);//       0       /* submit to all nodes in the node     */
                                                                     /* list                                */
    ret = PyModule_AddIntMacro(m, SQLURF_ALL_NODES);//       1       /* submit to all nodes in the          */
                                                                     /* nodeconfiguration file              */
    ret = PyModule_AddIntMacro(m, SQLURF_ALL_EXCEPT);//      2       /* submit to all nodes except the      */
                                                                     /* onesspecified by the nodelist       */
                                           /* parameter                           */
    ret = PyModule_AddIntMacro(m, SQLURF_CAT_NODE_ONLY);//   3       /* submit to catalog node only         */

    /* Roll forward query status codes                                            */
    ret = PyModule_AddIntMacro(m, SQLURFQ_NOT_AVAILABLE);//       0      /* cannot query node                   */
    ret = PyModule_AddIntMacro(m, SQLURFQ_NOT_RFW_PENDING);//     1      /* rollforward is not pending          */
    ret = PyModule_AddIntMacro(m, SQLURFQ_DB_RFW_PENDING);//      2      /* database rollforward pending        */
    ret = PyModule_AddIntMacro(m, SQLURFQ_TBL_RFW_PENDING);//     3      /* tablespace rollforward pending      */
    ret = PyModule_AddIntMacro(m, SQLURFQ_DB_RFW_IN_PROGRESS);//  4      /* database rollforward in progress    */
    ret = PyModule_AddIntMacro(m, SQLURFQ_TBL_RFW_IN_PROGRESS);// 5      /* tablespace rollforward in progress  */
    ret = PyModule_AddIntMacro(m, SQLURFQ_DB_RFW_STOPPING);//     6      /* database rollforward processing     */
                                                                         /* STOP                                */
    ret = PyModule_AddIntMacro(m, SQLURFQ_TBL_RFW_STOPPING);//    7      /* tablespace rollforward processing   */
                                                                         /* STOP                                */

    /* Rollforward connect mode                                                   */
    ret = PyModule_AddIntMacro(m, SQLUM_OFFLINE);          // 0x0     /* Offline rollforward mode            */
    ret = PyModule_AddIntMacro(m, SQLUM_ONLINE           );// 0x1     /* Online rollforward mode             */

    /* Backup mode                                                                */
    ret = PyModule_AddIntMacro(m, SQLUB_OFFLINE          );// 0x0     /* Offline backup mode                 */
    ret = PyModule_AddIntMacro(m, SQLUB_ONLINE           );// 0x1     /* Online backup mode                  */
    ret = PyModule_AddIntMacro(m, SQLUB_SPLITMIRROR      );// 0x10    /* Split mirror backup                 */
    ret = PyModule_AddIntMacro(m, SQLUB_MODE_MASK        );// 0xf     /* Backup modes                        */
    ret = PyModule_AddIntMacro(m, SQLUB_OPT_MASK         );// 0x0     /* Backup options                      */

    /* Backup type                                                                */
    ret = PyModule_AddIntMacro(m, SQLUB_DB               );// 0x0
    ret = PyModule_AddIntMacro(m, SQLUB_FULL             );// 0x0
    ret = PyModule_AddIntMacro(m, SQLUB_TABLESPACE       );// 0x3
    ret = PyModule_AddIntMacro(m, SQLUB_INCREMENTAL      );// 0x10
    ret = PyModule_AddIntMacro(m, SQLUB_DELTA            );// 0x30
    ret = PyModule_AddIntMacro(m, SQLUB_INC_LEVEL_MASK   );// 0xff00

    /* Backup type masks                                                          */
    ret = PyModule_AddIntMacro(m, SQLUB_TYPE_MASK        );// 0xf     /* Determines if full/tbsp bckp.       */
    ret = PyModule_AddIntMacro(m, SQLUB_INCR_MASK        );// 0xf0    /* Determines if incr/delta bckp.      */

    /* Backup calling action values                                               */
    ret = PyModule_AddIntMacro(m, SQLUB_BACKUP);//           0       /* initial call                        */
    ret = PyModule_AddIntMacro(m, SQLUB_CONTINUE);//         1       /* Subsequent call                     */
    ret = PyModule_AddIntMacro(m, SQLUB_TERMINATE);//        2       /* Terminating call                    */
    ret = PyModule_AddIntMacro(m, SQLUB_NOINTERRUPT);//      3       /* Initial call to run without         */
                                                                     /* prompting                           */
    ret = PyModule_AddIntMacro(m, SQLUB_DEVICE_TERMINATE);// 9       /* End media device.                   */
    ret = PyModule_AddIntMacro(m, SQLUB_PARM_CHECK);//       10      /* for parameter check and             */
                                                                     /* initialization.                     */
    ret = PyModule_AddIntMacro(m, SQLUB_PARM_CHECK_INIT_AND_WAIT);// 10 /* for parameter check and          */
                                                                        /* initialization.                     */
    ret = PyModule_AddIntMacro(m, SQLUB_PARM_CHECK_ONLY);//  11      /* for parameter checking only.        */

    /* Restore rollforward mode                                                   */
    ret = PyModule_AddIntMacro(m, SQLUD_ROLLFWD          );// 0x0
    ret = PyModule_AddIntMacro(m, SQLUD_NOROLLFWD        );// 0x1

    /* Restore mode                                                               */
    ret = PyModule_AddIntMacro(m, SQLUD_OFFLINE          );// 0x0     /* Offline restore mode                */
    ret = PyModule_AddIntMacro(m, SQLUD_ONLINE           );// 0x1     /* Online restore mode                 */

    /* Datalink mode                                                              */
    ret = PyModule_AddIntMacro(m, SQLUD_DATALINK         );// 0x0
    ret = PyModule_AddIntMacro(m, SQLUD_NODATALINK       );// 0x1

    /* Restore calling action values                                              */
    ret = PyModule_AddIntMacro(m, SQLUD_RESTORE);//          0          /* initial call                        */
    ret = PyModule_AddIntMacro(m, SQLUD_CONTINUE);//         1          /* Subsequent call                     */
    ret = PyModule_AddIntMacro(m, SQLUD_TERMINATE);//        2          /* Terminating call                    */
    ret = PyModule_AddIntMacro(m, SQLUD_NOINTERRUPT);//      3          /* Initial call to run without         */
                                                                        /* prompting                           */
    ret = PyModule_AddIntMacro(m, SQLUD_DEVICE_TERMINATE);// 9          /* End media device.                   */
    ret = PyModule_AddIntMacro(m, SQLUD_PARM_CHECK);//       10         /* for parameter check and             */
                                                                        /* initialization.                     */
    ret = PyModule_AddIntMacro(m, SQLUD_PARM_CHECK_INIT_AND_WAIT);// 10 /* for parameter check and          */
                                                                        /* initialization.                     */
    ret = PyModule_AddIntMacro(m, SQLUD_PARM_CHECK_ONLY);//  11         /* for parameter checking only.        */
    ret = PyModule_AddIntMacro(m, SQLUD_RESTORE_TABLESPACE_LIST);// 12  /* list of tablespaces/containers.   */
    ret = PyModule_AddIntMacro(m, SQLUD_TERMINATE_INCREMENTAL);// 13    /* abort incremental restore           */
    ret = PyModule_AddIntMacro(m, SQLUD_RESTORE_STORDEF);//  100        /* initial call, tablespace container  */
                                                                        /* redefinition requested              */
    ret = PyModule_AddIntMacro(m, SQLUD_STORDEF_NOINTERRUPT);// 101     /* initial call, tablespace container  */
                                                                        /* redefinition requested without      */
                                                                        /* prompting                           */

    /* Restore type                                                               */
    ret = PyModule_AddIntMacro(m, SQLUD_DB               );// 0x0
    ret = PyModule_AddIntMacro(m, SQLUD_FULL             );// 0x0
    ret = PyModule_AddIntMacro(m, SQLUD_ONLINE_TABLESPACE);// 0x3
    ret = PyModule_AddIntMacro(m, SQLUD_TABLESPACE       );// 0x4
    ret = PyModule_AddIntMacro(m, SQLUD_HISTORY          );// 0x5
    ret = PyModule_AddIntMacro(m, SQLUD_INCREMENTAL      );// 0x10
    ret = PyModule_AddIntMacro(m, SQLUD_AUTOMATIC        );// 0x100

    /* The following are not supported in V2.1.0                                  */
    ret = PyModule_AddIntMacro(m, SQLUD_TABLESPACE_TBL);//   6
    ret = PyModule_AddIntMacro(m, SQLUD_HIST_TBLSPACE_TBL);// 7

    /* Restore type masks                                                         */
    ret = PyModule_AddIntMacro(m, SQLUD_TYPE_MASK        );// 0xf     /* Determines if full/tbsp restore     */
    ret = PyModule_AddIntMacro(m, SQLUD_INCR_MASK        );// 0xf0    /* Determines if incr. restore         */

    /* Backup/Restore Definitions                                                 */
    ret = PyModule_AddIntMacro(m, SQLU_ALIAS_SZ);//          8       /* length of database alias name       */
    ret = PyModule_AddIntMacro(m, SQLU_USERID_LEN);//        1024    /* Maximum length of userid            */
    ret = PyModule_AddIntMacro(m, SQLU_PWD_LEN);//           18      /* length of password.Deprecated       */
                                                                     /* constant. Use ONLY for V9 and       */
                                                                     /* lower versions. For newer versions  */
                                                                     /* use SQLU_PASSWORD_LEN               */
    ret = PyModule_AddIntMacro(m, SQLU_PASSWORD_LEN);//      255     /* length of password. Use for V9.5    */
                                                                     /* and later versions of DB2           */
    ret = PyModule_AddIntMacro(m, SQLU_TIME_STAMP_LEN);//    14      /* length of the backup timestamp in   */
                                                                     /* yyyymmddhhmmss format               */

    ret = PyModule_AddIntMacro(m, SQLU_INSTNAME_SZ);//       8       /* max length of an instance name      */
                                                                     /* length of filename of backup image:                                        */
    /* dbalias.type.db2instance.node.timestamp.seq                                */
    ret = PyModule_AddIntMacro(m, SQLU_BACKUP_NAME_SZ);//    (SQLU_ALIAS_SZ+5+SQLU_INSTNAME_SZ+5+SQLU_TIME_STAMP_LEN+4)

    /* length of directory where backup file will reside:dir - '/' - filename     */
    ret = PyModule_AddIntMacro(m, SQLU_BACKUP_DIR_SZ);//     (1023-1-SQLU_BACKUP_NAME_SZ)

    /* Data map separator for LOAD utility;  Partition Key Identifier             */
    ret = PyModule_AddStringMacro(m, SQL_HEADER_DATA_SEPARATOR);// "===PDB==="
    ret = PyModule_AddStringMacro(m, SQLU_PARTITIONKEY);//      "Key:"

    /* Parameters for Backup/Restore old api's                                    */
    ret = PyModule_AddIntMacro(m, SQLU_NSD_ID);//            '0'     /* User exit used, not SD interface    */

                                                                     /* Parameters for SQLUHPRN force option                                       */
    ret = PyModule_AddIntMacro(m, SQLUH_NO_FORCE);//                 0
    ret = PyModule_AddIntMacro(m, SQLUH_FORCE);//                    1

    /* Parameters for SQLUHOPS caller action                                      */
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_BACKUP);//              0
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_HISTORY);//             1
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_BACKUP);//          2
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_ROLLFORWARD);//     3
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_RUNSTATS);//        4
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_REORG);//           5
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_ALT_TABLESPACE);//  6
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_DROPPED_TABLE);//   7
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_LOAD);//            8
    ret = PyModule_AddIntMacro(m, SQLUH_LIST_ADM_HISTORY);//         9

    /* Parameters for SQLUHGNE caller action                                      */
    ret = PyModule_AddIntMacro(m, SQLUH_GET_NEXT_ENTRY);//           0
    ret = PyModule_AddIntMacro(m, SQLUH_GET_DDL);//                  1
    ret = PyModule_AddIntMacro(m, SQLUH_GET_NEXT_ENTRY_DDL);//       2

    /* History File structure sizes                                               */
    ret = PyModule_AddIntMacro(m, SQLUH_OP_SZ);//                    1
    ret = PyModule_AddIntMacro(m, SQLUH_OBJ_SZ);//                   1
    ret = PyModule_AddIntMacro(m, SQLUH_OBJPART_SZ);//               17
    ret = PyModule_AddIntMacro(m, SQLUH_OPTYPE_SZ);//                1
    ret = PyModule_AddIntMacro(m, SQLUH_DEVTYPE_SZ);//               1
    ret = PyModule_AddIntMacro(m, SQLUH_FIRSTLOG_SZ);//              12
    ret = PyModule_AddIntMacro(m, SQLUH_LASTLOG_SZ);//               12
    ret = PyModule_AddIntMacro(m, SQLUH_BACKID_SZ);//                14
    ret = PyModule_AddIntMacro(m, SQLUH_TCREATE_SZ);//               8
    ret = PyModule_AddIntMacro(m, SQLUH_TNAME_SZ);//                 18
    ret = PyModule_AddIntMacro(m, SQLUH_NUMTABLESPACE_SZ);//         5
    ret = PyModule_AddIntMacro(m, SQLUH_LOC_SZ);//                   255
    ret = PyModule_AddIntMacro(m, SQLUH_COMMENT_SZ);//               30
    ret = PyModule_AddIntMacro(m, SQLUH_TABLESPACENAME_SZ);//        18
    ret = PyModule_AddIntMacro(m, SQLUH_TIMESTAMP_SZ);//             14
    ret = PyModule_AddIntMacro(m, SQLUH_ID_SZ);//                    24

    /* Parameters for RUNSTATS                                                    */
    ret = PyModule_AddIntMacro(m, SQL_STATS_TABLE);//           'T'  /* TABLEOPT = Table w/o Indexes        */
    ret = PyModule_AddIntMacro(m, SQL_STATS_BOTH);//            'B'  /* TABLEOPT = Table and Indexes        */
    ret = PyModule_AddIntMacro(m, SQL_STATS_INDEX);//           'I'  /* TABLEOPT = Indexes w/o Table        */
    ret = PyModule_AddIntMacro(m, SQL_STATS_EXTTABLE_ONLY);//   'D'  /* TABLEOPT = Table and dist stats     */
    ret = PyModule_AddIntMacro(m, SQL_STATS_EXTTABLE_INDEX);//  'E'  /* TABLEOPT = Table and dist stats     */
                                                                     /* and basic indexes                   */
    ret = PyModule_AddIntMacro(m, SQL_STATS_EXTINDEX_ONLY);//   'X'  /* TABLEOPT = Ext stats for indexes    */
                                                                     /* only                                */
    ret = PyModule_AddIntMacro(m, SQL_STATS_EXTINDEX_TABLE);//  'Y'  /* TABLEOPT = Ext stats for indexes    */
                                                                     /* and basic table stats               */
    ret = PyModule_AddIntMacro(m, SQL_STATS_ALL);//             'A'  /* TABLEOPT = Ext stats for indexes    */
                                                                     /* and table with dist stats           */
    ret = PyModule_AddIntMacro(m, SQL_STATS_REF);//             'R'  /* SHAREOPT = Reference                */
    ret = PyModule_AddIntMacro(m, SQLU_STATS_USE_PROFILE);//    'P'  /* TABLEOPT - statistics are to be     */
                                                                     /* gathered using the profile - Load   */
                                                                     /* only                                */
    ret = PyModule_AddIntMacro(m, SQL_STATS_CHG);//             'C'  /* SHAREOPT = Change                   */

#ifndef SQLU_STATS_DEFAULT
#define SQLU_STATS_DEFAULT 'F'
#endif

    ret = PyModule_AddIntMacro(m, SQLU_STATS_DEFAULT);//        'F'  /* TABLEOPT - default statistics       */
                                                                     /* collection for the table - Load     */
                                                                     /* only                                */
    ret = PyModule_AddIntMacro(m, SQLU_STATS_NONE);//           ' '  /* TABLEOPT - no statistics are to be  */
                                                                     /* gathered - Load only                */

    /* Parameters for selection method in sqldcol                                 */
    ret = PyModule_AddIntMacro(m, SQL_METH_N);//             78      /* Names                               */
    ret = PyModule_AddIntMacro(m, SQL_METH_P);//             80      /* Positional                          */
    ret = PyModule_AddIntMacro(m, SQL_METH_D);//             68      /* Default                             */
    ret = PyModule_AddIntMacro(m, SQL_METH_L);//             76      /* Locations                           */

    /* File Types for Import/Export                                               */
    ret = PyModule_AddStringMacro(m, SQL_IXF);//                "IXF"
    ret = PyModule_AddStringMacro(m, SQL_WSF);//                "WSF"
    ret = PyModule_AddStringMacro(m, SQL_DEL);//                "DEL"
    ret = PyModule_AddStringMacro(m, SQL_ASC);//                "ASC"
    ret = PyModule_AddStringMacro(m, SQL_CURSOR);//             "CURSOR"
    ret = PyModule_AddStringMacro(m, SQL_DB2CS);//              "DB2CS" /* load/unload                         */

    /* Import/Export/Load/Unload calling action values                            */
    ret = PyModule_AddIntMacro(m, SQLU_INITIAL           );// 0x0     /* Initial call                        */
    ret = PyModule_AddIntMacro(m, SQLU_CONTINUE          );// 0x1     /* Subsequent call                     */
    ret = PyModule_AddIntMacro(m, SQLU_TERMINATE         );// 0x2     /* Terminating call                    */
    ret = PyModule_AddIntMacro(m, SQLU_NOINTERRUPT       );// 0x3     /* Initial call - Load/Unload only     */
    ret = PyModule_AddIntMacro(m, SQLU_ABORT             );// 0x4     /* Abort call - Load only              */
    ret = PyModule_AddIntMacro(m, SQLU_RESTART           );// 0x5     /* Restart call - Load only            */
    ret = PyModule_AddIntMacro(m, SQLU_DEVICE_TERMINATE  );// 0x9     /* Subsequent call - Load/Unload only  */

    /* Actions for quiesce tablespaces for table                                  */
    ret = PyModule_AddIntMacro(m, SQLU_QUIESCEMODE_SHARE);//              0
    ret = PyModule_AddIntMacro(m, SQLU_QUIESCEMODE_INTENT_UPDATE);//      1
    ret = PyModule_AddIntMacro(m, SQLU_QUIESCEMODE_EXCLUSIVE);//          2
    ret = PyModule_AddIntMacro(m, SQLU_QUIESCEMODE_RESET);//              9
    ret = PyModule_AddIntMacro(m, SQLU_QUIESCEMODE_RESET_OWNED);//        10


    /* IMPORT/EXPORT Return codes                                                 */
    ret = PyModule_AddIntMacro(m, SQLUE_DFO                      ); //-3001   /* error opening output file   */
    ret = PyModule_AddIntMacro(m, SQLUE_IOE                      ); //-3002   /* i/o error writing output    */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUE_CLS                      ); //-3003   /* i/o error closing output    */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUE_IFT                      ); //-3004   /* invalid filetype parameter  */
    ret = PyModule_AddIntMacro(m, SQLUE_CBI                      ); //-3005   /* function interrupted        */
    ret = PyModule_AddIntMacro(m, SQLUE_MFO                      ); //-3006   /* i/o error opening message   */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUE_MFW                      ); //-3007   /* i/o error writing message   */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUE_STA                      ); //-3008   /* start using database        */
                                                                              /* failed                      */
    ret = PyModule_AddIntMacro(m, SQLUE_STR                      ); //-3009   /* invalid tcolstrg            */
    ret = PyModule_AddIntMacro(m, SQLUE_COL                      ); //-3010   /* invalid dcoldata            */

    ret = PyModule_AddIntMacro(m, SQLUE_MEM                      ); //-3011   /* memory allocation error     */
    ret = PyModule_AddIntMacro(m, SQLUE_SYSERR                   ); //-3012   /* system error                */
    ret = PyModule_AddIntMacro(m, SQLUE_FTMOD                    ); //-3013   /* invalid filetmod            */
    ret = PyModule_AddIntMacro(m, SQLUE_MFC                      ); //-3014   /* failure on closing message  */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUE_SQLERR                   ); //-3015   /* SQL error occurred          */
    ret = PyModule_AddIntMacro(m, SQLUE_FMODNK                   ); //-3016   /* no keywords found           */
    ret = PyModule_AddIntMacro(m, SQLUE_FMODID                   ); //-3017   /* invalid delimiter or        */
                                                                              /* duplicate                   */
    ret = PyModule_AddIntMacro(m, SQLUE_FMODDEC                  ); //-3018   /* decimal used for char       */
                                                                              /* delimiter                   */
    ret = PyModule_AddIntMacro(m, SQLUE_NTS                      ); //-3019   /* no tcolstrg                 */
    ret = PyModule_AddIntMacro(m, SQLUE_RC_INSAUTH               ); //-3020   /* insufficient authority for  */
                                                                              /* exp.                        */

    ret = PyModule_AddIntMacro(m, SQLUI_RC_INSAUTH               ); //-3021   /* insufficient authority for  */
                                                                              /* imp.                        */
    ret = PyModule_AddIntMacro(m, SQLUE_SQL_PREP_ERR             ); //-3022   /* SQL error on input string   */
    ret = PyModule_AddIntMacro(m, SQLUE_DATABASE                 ); //-3023   /* invalid database name       */
    ret = PyModule_AddIntMacro(m, SQLUE_DATAFILE                 ); //-3025   /* invalid datafile            */
    ret = PyModule_AddIntMacro(m, SQLUE_MSGFILE                  ); //-3026   /* invalid msgfile             */
    ret = PyModule_AddIntMacro(m, SQLUE_DCOLMETH                 ); //-3028   /* Export method indicator     */
                                                                              /* not n/d                     */
    ret = PyModule_AddIntMacro(m, SQLUE_NUL_FTYPE                ); //-3029   /* filetype is null            */

    ret = PyModule_AddIntMacro(m, SQLUI_DFO                      ); //-3030   /* error opening input data    */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUI_IOE                      ); //-3031   /* i/o error reading input     */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUI_DCOLMETH                 ); //-3032   /* Import method not n/d/p     */
    ret = PyModule_AddIntMacro(m, SQLUI_TINSERT                  ); //-3033   /* invalid insert in tcolstrg  */
    ret = PyModule_AddIntMacro(m, SQLUI_TINTO                    ); //-3034   /* invalid into in tcolstrg    */
    ret = PyModule_AddIntMacro(m, SQLUI_TABLENAME                ); //-3035   /* invalid tablename in        */
                                                                              /* tcolstrg                    */
    ret = PyModule_AddIntMacro(m, SQLUI_CPAREN                   ); //-3036   /* close paren not in          */
                                                                              /* tcolstrg                    */
    ret = PyModule_AddIntMacro(m, SQLUE_SQL_PREP_INSERT          ); //-3037   /* SQL error on insert string  */
    ret = PyModule_AddIntMacro(m, SQLUI_TCOLJUNK                 ); //-3038   /* tcolstrg invalid            */
    ret = PyModule_AddIntMacro(m, SQLU_REDUCE_CPUPAR             ); //3039    /* load parallelism reduced    */
    ret = PyModule_AddIntMacro(m, SQLUE_LOBFILE_ERROR            ); //-3040   /* lob file error              */

    ret = PyModule_AddIntMacro(m, SQLUI_DL_ILLEGAL_LINKTYPE      ); //-3042   /* LINKTYPE is not URL         */
    ret = PyModule_AddIntMacro(m, SQLUI_DL_COL_JUNK              ); //-3043   /* dl_specification invalid    */
    ret = PyModule_AddIntMacro(m, SQLUI_DL_COL_DUP_PREFIX        ); //-3044   /* multiple prefix decl per    */
                                                                              /* col                         */

    ret = PyModule_AddIntMacro(m, SQLUIC_BAD_DCOL_POS            ); //-3045   /* invalid dcol position for   */
                                                                              /* CSV                         */
    ret = PyModule_AddIntMacro(m, SQLUI_NONDEF_DCOL_NOCOLS       ); //-3046   /* non-default dcol and no     */
                                                                              /* cols                        */
    ret = PyModule_AddIntMacro(m, SQLUI_BAD_DCOL_METH            ); //-3047   /* dcolinfo has invalid        */
                                                                              /* method                      */
    ret = PyModule_AddIntMacro(m, SQLUI_NODCOL_FOR_NONNULL_DBCOL ); //-3048   /* non nullable column         */
    ret = PyModule_AddIntMacro(m, SQLUIC_UNSUPTYP_NONULLS        ); //-3049   /* unsupported column type     */

    ret = PyModule_AddIntMacro(m, SQLUII_CONVERSION              );// 3050    /* conversion for cdpg         */
    ret = PyModule_AddIntMacro(m, SQLU_PATH_MISSING              ); //-3052   /* Required path is missing    */
    ret = PyModule_AddIntMacro(m, SQLUII_HEOF                    ); //-3054   /* eof reading first rec in    */
                                                                              /* IXF                         */
    ret = PyModule_AddIntMacro(m, SQLUII_HLEN_CONV               ); //-3055   /* length of 'H' rec not       */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_HLEN_SHORT              ); //-3056   /* first record too short      */
    ret = PyModule_AddIntMacro(m, SQLUII_HTYP                    ); //-3057   /* first IXF rec is not 'H'    */
    ret = PyModule_AddIntMacro(m, SQLUII_HID                     ); //-3058   /* no IXF identifier in 'H'    */
    ret = PyModule_AddIntMacro(m, SQLUII_HVERS                   ); //-3059   /* invalid version field in    */
                                                                              /* 'H'                         */

    ret = PyModule_AddIntMacro(m, SQLUII_HCNT                    ); //-3060   /* HCNT in 'H' not numeric     */
    ret = PyModule_AddIntMacro(m, SQLUII_HSBCP_BAD               ); //-3061   /* SBCP in 'H' not numeric     */
    ret = PyModule_AddIntMacro(m, SQLUII_HDBCP_BAD               ); //-3062   /* DBCP in 'H' not numeric     */
    ret = PyModule_AddIntMacro(m, SQLUII_HSBCP_CMP               ); //-3063   /* 'H' SBCP not compat w/data  */
                                                                              /* SBCP                        */
    ret = PyModule_AddIntMacro(m, SQLUII_HDBCP_CMP               ); //-3064   /* 'H' DBCP not compat w/data  */
                                                                              /* DBCP                        */
    ret = PyModule_AddIntMacro(m, SQLUII_DB_CODEPG               ); //-3065   /* can't get codepages         */
    ret = PyModule_AddIntMacro(m, SQLUII_TEOF                    ); //-3066   /* eof reading/looking for     */
                                                                              /* 'T' rec                     */
    ret = PyModule_AddIntMacro(m, SQLUII_TLEN_CONV               ); //-3067   /* length of 'T' rec not       */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_TLEN_SHORT              ); //-3068   /* 'T' record is too short     */
    ret = PyModule_AddIntMacro(m, SQLUII_TTYP                    ); //-3069   /* first non-'A' rec not 'T'   */
                                                                              /* rec                         */

    ret = PyModule_AddIntMacro(m, SQLUII_ALEN_BAD                ); //-3070   /* invalid rec length of 'A'   */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_TCONV                   ); //-3071   /* invalid data convention in  */
                                                                              /* 'T'                         */
    ret = PyModule_AddIntMacro(m, SQLUII_TFORM                   ); //-3072   /* invalid data format in 'T'  */
    ret = PyModule_AddIntMacro(m, SQLUII_TMFRM                   ); //-3073   /* invalid machine form in     */
                                                                              /* 'T'                         */
    ret = PyModule_AddIntMacro(m, SQLUII_TLOC                    ); //-3074   /* invalid data location in    */
                                                                              /* 'T'                         */
    ret = PyModule_AddIntMacro(m, SQLUII_TCCNT                   ); //-3075   /* 'C' rec cnt in 'T' not      */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_TNAML                   ); //-3076   /* name len fld in 'T' not     */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_CCNT_HIGH               ); //-3077   /* too many 'C' records        */
    ret = PyModule_AddIntMacro(m, SQLUII_ALEN_CONV               ); //-3078   /* length of 'A' rec not       */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_CLEN_CONV               ); //-3079   /* length of 'C' rec not       */
                                                                              /* numeric                     */

    ret = PyModule_AddIntMacro(m, SQLUII_CLEN_SHORT              ); //-3080   /* 'C' record is too short     */
    ret = PyModule_AddIntMacro(m, SQLUII_CTYP                    ); //-3081   /* wrong rec type / 'C'        */
                                                                              /* expected                    */
    ret = PyModule_AddIntMacro(m, SQLUII_CEOF                    ); //-3082   /* EOF while processing 'C'    */
                                                                              /* recs                        */
    ret = PyModule_AddIntMacro(m, SQLUII_CDRID                   ); //-3083   /* 'D' rec id field not        */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_CPOSN                   ); //-3084   /* 'D' rec posn field not      */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_CIDPOS                  ); //-3085   /* 'D' id/position not         */
                                                                              /* consistent                  */
    ret = PyModule_AddIntMacro(m, SQLUII_NOCREC_FOR_NONNULL_DBCOL); //-3086  /* IXF column does not exist   */
    ret = PyModule_AddIntMacro(m, SQLUII_INVCREC_NONNULL_DBCOL   ); //-3087   /* IXF column not valid        */
    ret = PyModule_AddIntMacro(m, SQLUII_CRECCOMP_NONNULL_DBCOL  ); //-3088   /* IXF column not compatible   */
    ret = PyModule_AddIntMacro(m, SQLUII_DTYP                    ); //-3089   /* wrong rec type / 'D'        */
                                                                              /* expected                    */

    ret = PyModule_AddIntMacro(m, SQLUII_DLEN_CONV               ); //-3090   /* length of 'D' rec not       */
                                                                              /* numeric                     */
    ret = PyModule_AddIntMacro(m, SQLUII_DLEN_RANGE              ); //-3091   /* length of 'D' rec not       */
                                                                              /* valid                       */
    ret = PyModule_AddIntMacro(m, SQLUII_DID                     ); //-3092   /* invalid id field in 'D'     */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUIW_NNCOL_LOST              ); //-3094   /* DOS non-nullable name not   */
                                                                              /* found                       */
    ret = PyModule_AddIntMacro(m, SQLUIW_PCOL_INV                ); //-3095   /* col position out of range   */

    ret = PyModule_AddIntMacro(m, SQLUE_COL_TOOBIG               ); //3100    /* column longer than 254      */
                                                                              /* chars                       */
    ret = PyModule_AddIntMacro(m, SQLUE_DATA_CHARDEL             ); //3101    /* column has char delimiter   */
    ret = PyModule_AddIntMacro(m, SQLUE_DCNUM_HIGH               ); //3102    /* dcol column nbr > tcol      */
                                                                              /* number                      */
    ret = PyModule_AddIntMacro(m, SQLUE_DCNUM_LOW                ); //3103    /* dcol column nbr < tcol      */
                                                                              /* number                      */
    ret = PyModule_AddIntMacro(m, SQLUE_MFE                      ); //-3106   /* error formatting a message  */
    ret = PyModule_AddIntMacro(m, SQLUE_WARNING                  ); //3107    /* warning message issued      */

    ret = PyModule_AddIntMacro(m, SQLUI_DLFM_LINK                ); //3108    /* file not linked             */

    ret = PyModule_AddIntMacro(m, SQLUI_FEWER_DCOLS_DBCOLS_NULLED ); //3112   /* extra database cols         */
    ret = PyModule_AddIntMacro(m, SQLUIC_UNSUPTYP_NULLABLE       ); //3113    /* column will be nulled       */
    ret = PyModule_AddIntMacro(m, SQLUIC_IGNORED_CHAR            ); //3114    /* character ignored           */
    ret = PyModule_AddIntMacro(m, SQLUIC_FIELD_TOO_LONG          ); //3115    /* input CSV field too long    */
    ret = PyModule_AddIntMacro(m, SQLUIC_CF_REQFIELD_MISSING     ); //3116    /* field value missing         */
    ret = PyModule_AddIntMacro(m, SQLUIC_CF_GENALWAYS_NOTNULL    );// 3550    /* non NULL found for          */
                                                                              /* GENERATED ALWAYWS col       */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFINT2_NULLED           ); //3117    /* smallint field nulled       */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFINT2_ROWREJ           ); //3118    /* smallint field error        */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFINT4_NULLED           ); //3119    /* int field nulled            */

#ifndef SQLUIC_CFBOOL_NULLED
#define SQLUIC_CFBOOL_NULLED 27923
#endif

    ret = PyModule_AddIntMacro(m, SQLUIC_CFBOOL_NULLED           ); //27923   /* boolean field nulled        */
#ifndef SQLUIC_CFBOOL_ROWREJ
#define SQLUIC_CFBOOL_ROWREJ 27924
#endif
    ret = PyModule_AddIntMacro(m, SQLUIC_CFBOOL_ROWREJ           ); //27924   /* boolean field error         */

    ret = PyModule_AddIntMacro(m, SQLUIC_CFINT4_ROWREJ           ); //3120    /* int field error             */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFFLOAT_NULLED          ); //3121    /* float field nulled          */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFFLOAT_ROWREJ          ); //3122    /* float field error           */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFDEC_NULLED            ); //3123    /* decimal field nulled        */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFDEC_ROWREJ            ); //3124    /* decimal field error         */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFTRUNC                 ); //3125    /* char field truncated        */

    ret = PyModule_AddIntMacro(m, SQLU_RMTCLNT_NEEDS_ABSPATH     ); //-3126   /* Absolute path must be       */
                                                                              /* specified for load from     */
                                                                              /* remote client               */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFDATETRUNC             ); //3128    /* date field truncated        */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFDTPAD                 ); //3129    /* date/time/stamp field       */
                                                                              /* padded                      */

    ret = PyModule_AddIntMacro(m, SQLUIC_CFTIMETRUNC             ); //3130    /* time field truncated        */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFSTAMPTRUNC            ); //3131    /* stamp field truncated       */
    ret = PyModule_AddIntMacro(m, SQLUE_TRUNCATE                 ); //3132    /* char field truncated        */
    ret = PyModule_AddIntMacro(m, SQLUI_DATALINK_NULLED          ); //3133    /* Datalink field nulled       */
    ret = PyModule_AddIntMacro(m, SQLUI_DATALINK_ROWREJ          ); //3134    /* Datalink field error        */
    ret = PyModule_AddIntMacro(m, SQLU_DCOL_TOO_MANY             ); //-3135   /* Too many METHOD cols        */
    ret = PyModule_AddIntMacro(m, SQLUIC_ROWTOOSHORT             ); //3137    /* not enough columns          */
    ret = PyModule_AddIntMacro(m, SQLUIC_EOF_IN_CHARDELS         ); //3138    /* end of input data file      */
    ret = PyModule_AddIntMacro(m, SQLUE_SQLSTPDB_ERR             ); //3139    /* stop using database failed  */

    ret = PyModule_AddIntMacro(m, SQLUIC_CFDECFLOAT_NULLED       ); //3140    /* decfloat field nulled       */
    ret = PyModule_AddIntMacro(m, SQLUIC_CFDECFLOAT_ROWREJ       ); //3141    /* decfloat field error        */
    ret = PyModule_AddIntMacro(m, SQLUE_3148                     ); //3148    /* row not inserted            */

    ret = PyModule_AddIntMacro(m, SQLUII_TCNTCMP                 ); //3154    /* 'H' hcnt not equal 'T' rec  */
                                                                              /* ccnt                        */
    ret = PyModule_AddIntMacro(m, SQLUII_CNAML                   ); //3155    /* invalid name length in 'C'  */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_CNULL                   ); //3156    /* invalid null field in 'C'   */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_CTYPE                   ); //3157    /* invalid type field in 'C'   */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_CSBCP                   ); //3158    /* invalid SBCP field in 'C'   */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_CDBCP                   ); //3159    /* invalid DBCP field in 'C'   */
                                                                              /* rec                         */

    ret = PyModule_AddIntMacro(m, SQLUII_CLENG                   ); //3160    /* invalid col len fld in 'C'  */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_CPREC                   ); //3161    /* invalid precision in 'C'    */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_CSCAL                   ); //3162    /* invalid scale field in 'C'  */
                                                                              /* rec                         */
    ret = PyModule_AddIntMacro(m, SQLUII_CFLOAT_BLANKLENG        ); //3163    /* use 00008 for float col     */
                                                                              /* length                      */
    ret = PyModule_AddIntMacro(m, SQLUII_CFLOAT_BADLENG          ); //3164    /* invalid float col len in    */
                                                                              /* 'C'.                        */
    ret = PyModule_AddIntMacro(m, SQLUII_CUTYPE                  ); //3165    /* 'C' record has invalid      */
                                                                              /* type                        */
    ret = PyModule_AddIntMacro(m, SQLUII_NOCREC_FOR_NULL_DBCOL   ); //3166    /* IXF col does not exist      */
    ret = PyModule_AddIntMacro(m, SQLUII_INVCREC_FOR_NULL_DBCOL  ); //3167    /* IXF col is invalid          */
    ret = PyModule_AddIntMacro(m, SQLUII_CRECCOMP_NULL_DBCOL     ); //3168    /* IXF col not compatible      */

    ret = PyModule_AddIntMacro(m, SQLUII_DEOF_INROW              ); //3170    /* EOF found in row of data    */

    ret = PyModule_AddIntMacro(m, SQLUE_INSERT_DISK              ); //3180    /* insert diskette request     */
    ret = PyModule_AddIntMacro(m, SQLUII_AE_NOTFOUND             ); //3181    /* file ended before AE rec    */
    ret = PyModule_AddIntMacro(m, SQLUII_INSERT_DISK_RETRY       ); //3182    /* retry to insert diskette    */
    ret = PyModule_AddIntMacro(m, SQLUEC_NOBLANK_B4KW            ); //3183    /* mult del o'rides/no blanks  */
    ret = PyModule_AddIntMacro(m, SQLUI_PREVMESG_ROWNO           ); //3185    /* row of previous warning     */
    ret = PyModule_AddIntMacro(m, SQLUI_LOGFULL_INSWARN          ); //3186    /* log full inserting row      */
    ret = PyModule_AddIntMacro(m, SQLUI_INDEX_WARN               ); //3187    /* error creating index        */
    ret = PyModule_AddIntMacro(m, SQLUI_TRUNCATE_TABLE           ); //-3188   /* error truncating table      */

    ret = PyModule_AddIntMacro(m, SQLUI_INDEXIXF                 ); //-3190   /* invalid INDEXIXF option     */
    ret = PyModule_AddIntMacro(m, SQLUE_INVALID_DATE_DATA        ); //3191    /* data not fit modifier       */
    ret = PyModule_AddIntMacro(m, SQLUE_INVALID_DATE_SPEC        ); //-3192   /* invalid user date modifier  */
    ret = PyModule_AddIntMacro(m, SQLUI_VIEW_ERROR               ); //-3193   /* cannot import to this view  */
    ret = PyModule_AddIntMacro(m, SQLUI_SYSTBL_ERROR             ); //-3194   /* cannot import system table  */
    ret = PyModule_AddIntMacro(m, SQLUE_RETRY_DISK               ); //3195    /* not enough space            */
    ret = PyModule_AddIntMacro(m, SQLUI_IN_NOTFD                 ); //-3196   /* input file not found        */
    ret = PyModule_AddIntMacro(m, SQLUI_IMPBUSY                  ); //-3197   /* import/export in use        */
    ret = PyModule_AddIntMacro(m, SQLUII_CDECFLOAT_BLANKLENG     ); //3198    /* use 00008 for decfloat col  */
                                                                              /* length                      */
    ret = PyModule_AddIntMacro(m, SQLUII_CDECFLOAT_BADLENG       ); //3199    /* invalid decfloat col len    */
                                                                              /* in 'C'.                     */

    ret = PyModule_AddIntMacro(m, SQLUI_REPL_PAR                 ); //-3201   /* cant replace parent table   */
    ret = PyModule_AddIntMacro(m, SQLUI_IUOPT_NOPK               ); //-3203   /* cant update without PK's    */
    ret = PyModule_AddIntMacro(m, SQLUI_IUOPT_NOVIEW             ); //-3204   /* cant update views           */
    ret = PyModule_AddIntMacro(m, SQLUI_VIEW_REF                 ); //-3205   /* cant replace ref cons view  */
    ret = PyModule_AddIntMacro(m, SQLUI_VIEW_SQUERY              ); //-3206   /* cant replace subquery view  */

    ret = PyModule_AddIntMacro(m, SQLU_INVALID_TABLES_LIST       ); //-3207   /* Invalid table list          */
    ret = PyModule_AddIntMacro(m, SQLU_TYPED_IMPORT_INTO_REGULAR ); //3208    /* Import Typed-table to Reg   */
    ret = PyModule_AddIntMacro(m, SQLU_CANT_RENAM_SUBTAB_OR_ATTR ); //-3209   /* Cannot rename sub-table     */
                                                                              /* attr                        */
    ret = PyModule_AddIntMacro(m, SQLU_INCOMPATIBLE_HIERARCHY    ); //-3210   /* Options incompatible w/     */
                                                                              /* hier                        */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_DOESNT_SUPP_RT       ); //-3211   /* Load doesn't supp RT        */
    ret = PyModule_AddIntMacro(m, SQLU_NOSUPP_LD_TERM_OP         ); //-3212   /* not supported Load          */
                                                                              /* Terminate operation         */

    ret = PyModule_AddIntMacro(m, SQLU_INXMODE_INFO              ); //3213    /* Load indexing mode          */
    ret = PyModule_AddIntMacro(m, SQLU_INXMODE_DEFBUTUNIQUE      ); //-3214   /* Deferred indexing, but      */
                                                                              /* unique inx                  */
    ret = PyModule_AddIntMacro(m, SQLU_INXMODE_DMS_RESTRICTION   ); //3215    /* Load incrmental indexing +  */
                                                                              /* DMS + copy + same TS        */
    ret = PyModule_AddIntMacro(m, SQLU_INXMODE_INC_BUTBADINX     ); //3216    /* Load incrmental indexing    */
                                                                              /* but inx invalid             */
    ret = PyModule_AddIntMacro(m, SQLU_INXMODE_INC_BUTNOTINSERT  ); //3217    /* Load incrmental indexing    */
                                                                              /* but not insert              */
    ret = PyModule_AddIntMacro(m, SQLU_INDEX_FILE_MISSING        ); //-3218   /* Index file is damaged       */
                                                                              /* missing                     */
    ret = PyModule_AddIntMacro(m, SQLU_CONSTRAINTS_OFF_FAILED    ); //-3219   /* Load unable to turn off     */
                                                                              /* constraints                 */

    ret = PyModule_AddIntMacro(m, SQLUE_PROVIDE_FILE_PART        ); //3220    /* AIX req next file           */
    ret = PyModule_AddIntMacro(m, SQLUI_START_COMMIT             ); //3221    /* start commit                */
    ret = PyModule_AddIntMacro(m, SQLUI_FINISH_COMMIT            ); //3222    /* finish commit               */
    ret = PyModule_AddIntMacro(m, SQLUI_BAD_STRUCT_PARM          ); //-3223   /* bad input parms             */
    ret = PyModule_AddIntMacro(m, SQLUI_SKIPPED_ALL_ROWS         ); //-3225   /* restartcnt too big          */
    ret = PyModule_AddIntMacro(m, SQLU_WHICH_USER_RECORD         ); //3227    /* map special token to user   */
                                                                              /* record                      */
    ret = PyModule_AddIntMacro(m, SQLU_DL_AND_DEFERRED_INX       ); //-3228   /* Datalink table, deferred    */
                                                                              /* indexing not allowed on     */
                                                                              /* load                        */

    ret = PyModule_AddIntMacro(m, SQLUI_INVALID_DATA             ); //3229    /* Row contains invalid data,  */
                                                                              /* will be rejected            */
    ret = PyModule_AddIntMacro(m, SQLU_INCOMPAT_TYPE_CODEPAGE    ); //-3230   /* Data type incompatible      */
                                                                              /* with given codepage         */
    ret = PyModule_AddIntMacro(m, SQLUE_LOB_XML_WRITE_ERROR      ); //3232    /* Write to file failed,       */
                                                                              /* different file name used    */
    ret = PyModule_AddIntMacro(m, SQLUI_IGNORE_XDS_ATTR          ); //3233    /* Invalid XDS attribute       */
                                                                              /* ignored                     */
    ret = PyModule_AddIntMacro(m, SQLUI_INVALID_XDS              ); //-3234   /* Invalid XDS                 */
    ret = PyModule_AddIntMacro(m, SQLUE_PATH_ERROR               ); //-3235   /* Path error                  */
    ret = PyModule_AddIntMacro(m, SQLUI_XMLSCHEMA_CONFLICT       ); //-3236   /* XML schema conflict         */
                                                                              /* between IGNORE and          */
    /* XMLVALIDATE options         */
    ret = PyModule_AddIntMacro(m, SQLUE_ACTION_STRING_XML_ERROR  ); //-3237   /* Export Action String error  */
                                                                              /* due to XML processing       */
    ret = PyModule_AddIntMacro(m, SQLUE_NO_SCHEMA_IN_XDS         ); //3239    /* XML schema not written out  */
                                                                              /* to XDS                      */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_SECLABEL          ); //3241    /* Invalid security label      */
    ret = PyModule_AddIntMacro(m, SQLU_MALFORMED_SECLABEL        ); //3242    /* Security label is           */
                                                                              /* syntactically incorrect.    */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_SECLABEL_ELEMENT  ); //3243    /* Invalid element for the     */
                                                                              /* security policy             */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_SECLABELNAME      ); //3244    /* Invalid security label      */
                                                                              /* name                        */
    ret = PyModule_AddIntMacro(m, SQLU_LBAC_ENFORCE_FAILED       ); //3245    /* Enforcement of security     */
                                                                              /* label failed                */

    ret = PyModule_AddIntMacro(m, SQLUI_COMPOUND_ERR             ); //-3250   /* compound=x error            */

    ret = PyModule_AddIntMacro(m, SQLUIW_EARLY_EOF               ); //-3302   /* unexpected EOF              */
    ret = PyModule_AddIntMacro(m, SQLUI_IXFONLY                  ); //-3303   /* filetype not ixf            */
    ret = PyModule_AddIntMacro(m, SQLUI_DELTABLE                 ); //-3304   /* table does not exist        */
    ret = PyModule_AddIntMacro(m, SQLUI_CREATE_ERR               ); //-3305   /* table already exists        */
    ret = PyModule_AddIntMacro(m, SQLUI_EXECUTE_ERR              ); //-3306   /* SQL error during insert     */
    ret = PyModule_AddIntMacro(m, SQLUI_INC_COL                  ); //-3307   /* incomplete col info         */
    ret = PyModule_AddIntMacro(m, SQLUI_CP_MISMATCH              ); //-3308   /* codepage mismatch           */
    ret = PyModule_AddIntMacro(m, SQLUI_DBLDATA                  ); //-3309   /* double byte data found      */

    ret = PyModule_AddIntMacro(m, SQLUI_UNREC_CTYPE              ); //-3310   /* unrec col type              */
    ret = PyModule_AddIntMacro(m, SQLUI_INVCREC_FOR_CREATE       ); //-3310   /* invalid IXF column          */

    ret = PyModule_AddIntMacro(m, SQLUE_DISK_FULL_DB2OS2         ); //-3313   /* disk full - OS/2            */
    ret = PyModule_AddIntMacro(m, SQLUE_DISK_FULL_DB2NT          ); //-3313   /* disk full - Windows NT      */
    ret = PyModule_AddIntMacro(m, SQLUE_DISK_FULL_DB2DOS         ); //-3313   /* disk full - DOS             */
    ret = PyModule_AddIntMacro(m, SQLUE_DISK_FULL_DB2WIN         ); //-3313   /* disk full - Windows         */
    ret = PyModule_AddIntMacro(m, SQLUE_DISK_FULL_DB2AIX         ); //-10018  /* disk full - AIX             */
    ret = PyModule_AddIntMacro(m, SQLUE_DISK_FULL_DB2MAC         ); //-3313   /* disk full - MacOS           */

    ret = PyModule_AddIntMacro(m, SQLUE_DISK_FULL                );// SQLUE_DISK_FULL_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLUII_ASTAMP_NOMATCH          ); //-3314   /* 'A' data/ time not as 'H'.  */
    ret = PyModule_AddIntMacro(m, SQLUII_ACREC_BADVOL            ); //-3315   /* invalid volume info         */
    ret = PyModule_AddIntMacro(m, SQLUII_CLOSE_NOTLAST           ); //-3316   /* error closing IXF file      */
    ret = PyModule_AddIntMacro(m, SQLUW_FTMOD_INV                ); //-3317   /* conflict in filetmod        */
    ret = PyModule_AddIntMacro(m, SQLUEC_DUP_KEYWORD             ); //-3318   /* keyword repeated/filetmod   */
    ret = PyModule_AddIntMacro(m, SQLUI_ERR_CREATETAB            ); //-3319   /* error creating table        */

    ret = PyModule_AddIntMacro(m, SQLUEC_NOROOM_AFTERKW          ); //-3320   /* keyword at end of filetmod  */
    ret = PyModule_AddIntMacro(m, SQLUI_LOGFULL_INSERR           ); //-3321   /* circular log full           */
    ret = PyModule_AddIntMacro(m, SQLUE_SEM_ERROR                ); //-3322   /* semaphore error             */
    ret = PyModule_AddIntMacro(m, SQLUE_INVCOLTYPE               ); //-3324   /* column type invalid         */
    ret = PyModule_AddIntMacro(m, SQLUI_COL_LIST                 ); //-3326   /* column list invalid         */
    ret = PyModule_AddIntMacro(m, SQLUEI_SYSERROR                ); //-3327   /* system error                */
    ret = PyModule_AddIntMacro(m, SQLUI_NICKNAME_ERR             ); //-27999  /* Error importing to          */
                                                                              /* nickname                    */
    ret = PyModule_AddIntMacro(m, SQLUE_NO_IXF_INFO              ); //27984   /* Some metadata will not be   */
                                                                              /* saved to IXF on Export      */
    ret = PyModule_AddIntMacro(m, SQLUEW_COL_TRUNC               ); //27986   /* Column name truncated       */
                                                                              /* during Export               */
    ret = PyModule_AddIntMacro(m, SQLUE_IXF_NO_SUPP_N            ); //-27987  /* IXF file not supported in   */
                                                                              /* Import using Method N       */
    ret = PyModule_AddIntMacro(m, SQLUE_NO_IXF_INFO_ERR          ); //-3311   /* IXF file not supported in   */
                                                                              /* IMPORT CREATE               */

    ret = PyModule_AddIntMacro(m, SQLUII_ODD2GRAPH               ); //3330    /* odd leng char -> graphic    */
    ret = PyModule_AddIntMacro(m, SQLUE_OEACCESS                 ); //-3331   /* permission denied           */
    ret = PyModule_AddIntMacro(m, SQLUE_OEMFILE                  ); //-3332   /* too many files open         */
    ret = PyModule_AddIntMacro(m, SQLUE_OENOENT                  ); //-3333   /* no such file or directory   */
    ret = PyModule_AddIntMacro(m, SQLUE_OENOMEM                  ); //-3334   /* not enough memory           */
    ret = PyModule_AddIntMacro(m, SQLUE_OENOSPC                  ); //-3335   /* no space left               */
    ret = PyModule_AddIntMacro(m, SQLU_READ_ACCESS_NOT_ALLOWED   ); //-3340   /* read access load            */
                                                                              /* conditions not met          */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_USE_TABLESPACE    ); //-3341   /* use tablespace incorrect    */
    ret = PyModule_AddIntMacro(m, SQLU_LOCK_WITH_FORCE_DENIED    ); //-3342   /* insufficient authority to   */
                                                                              /* issue lock with force       */
    ret = PyModule_AddIntMacro(m, SQLU_NO_RSTART_POST_RLFWARD    ); //-3343   /* cant load restart after     */
                                                                              /* rollforward                 */
    ret = PyModule_AddIntMacro(m, SQLU_USE_TABLESPACE_WARNING    );// 3346    /* use tablespace warning      */
                                                                              /* message                     */

    ret = PyModule_AddIntMacro(m, SQLUIA_BAD_DCOL_METH           ); //-3400   /* invalid method for ASC      */
    ret = PyModule_AddIntMacro(m, SQLUI_DCOLM_ALL                ); //-3401   /* invalid import method       */
    ret = PyModule_AddIntMacro(m, SQLUIA_NULLLOC                 ); //-3402   /* zeroes as begin/end         */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCPAIR                 ); //-3403   /* invalid pair                */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCNUM                  ); //-3404   /* invalid pair for number     */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCDATE                 ); //-3405   /* invalid pair for date       */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCTIME                 ); //-3406   /* invalid pair for time       */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCSTAMP                ); //-3407   /* invalid pair for timestamp  */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCLONG                 ); //3408    /* pair defines long field     */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCSHORT                ); //3409    /* pair defines short field    */
    ret = PyModule_AddIntMacro(m, SQLUIA_LOCODD                  ); //-3410   /* invalid pair for graphic    */
    ret = PyModule_AddIntMacro(m, SQLUIA_CFGRAPH_NULLED          ); //3411    /* value not graphic--null     */
    ret = PyModule_AddIntMacro(m, SQLUIA_CFGRAPH_ROWREJ          ); //3412    /* value not graphic--not      */
                                                                              /* null                        */
    ret = PyModule_AddIntMacro(m, SQLUIA_SHORTFLDNULLED          ); //3413    /* field too short--nulled     */
    ret = PyModule_AddIntMacro(m, SQLU_NO_LIFEBOAT               ); //-3414
    ret = PyModule_AddIntMacro(m, SQLUIA_CFCPCV_NULLED           ); //3415    /* CPCV failed--null           */
    ret = PyModule_AddIntMacro(m, SQLUIA_CFCPCV_ROWREJ           ); //3416    /* CPCV failed--not null       */
    ret = PyModule_AddIntMacro(m, SQLU_NOCHARDEL_WARNING         ); //3418    /* Modified by NOCHARDEL       */
                                                                              /* usage warning               */
    ret = PyModule_AddIntMacro(m, SQLU_VENDOR_SORT_IGNORED       ); //3419    /* Vendor sort for collating   */
                                                                              /* type is unsupported, using  */
                                                                              /* default db2 sort            */

    ret = PyModule_AddIntMacro(m, SQLU_TOO_MANY_WARNINGS         ); //-3502   /* number of warnings hit      */
                                                                              /* threshold                   */
    ret = PyModule_AddIntMacro(m, SQLU_ROWCNT                    ); //3503    /* number of rows hit          */
                                                                              /* threshold                   */
    ret = PyModule_AddIntMacro(m, SQLULA_INVALID_RECLEN          ); //-3505   /* reclen > 32767              */
    ret = PyModule_AddIntMacro(m, SQLULA_NULLIND_IGNORED         ); //3506    /* null ind value not Y or N   */
    ret = PyModule_AddIntMacro(m, SQLUI_NULLIND                  ); //-3507   /* nullind column is invalid   */
    ret = PyModule_AddIntMacro(m, SQLUL_FILE_ERROR               ); //-3508   /* file access error during    */
                                                                              /* load                        */
    ret = PyModule_AddIntMacro(m, SQLUL_NUM_ROW_DELETED          ); //3509    /* num of row deleted after    */
                                                                              /* load                        */
    ret = PyModule_AddIntMacro(m, SQLU_SORT_WORK_DIR_ERROR       ); //-3510   /* work directory is invalid   */
    ret = PyModule_AddIntMacro(m, SQLU_NB_LOBFILE_MISSING        ); //3511    /* lobfile missing but         */
                                                                              /* nullable col                */
    ret = PyModule_AddIntMacro(m, SQLU_NNB_LOBFILE_MISSING       ); //3512    /* lobfile missing,            */
                                                                              /* nonnullable col             */
    ret = PyModule_AddIntMacro(m, SQLUL_UNMATCHED_CODEPAGE       ); //-3513   /* codepage doesn't match db   */
    ret = PyModule_AddIntMacro(m, SQLUL_SYSERR_WITH_REASON       ); //-3514   /* system error with reason    */
                                                                              /* code                        */
    ret = PyModule_AddIntMacro(m, SQLUL_UNEXPECTED_RECORD        ); //-3517   /* unexpected rec in db2cs     */
    ret = PyModule_AddIntMacro(m, SQLUL_INCOMPATIBLE_TABLE       ); //-3518   /* coltype incompatible for    */
                                                                              /* db2cs                       */
    ret = PyModule_AddIntMacro(m, SQLUL_FILE_NOT_FOUND           ); //-3521   /* missing file                */
    ret = PyModule_AddIntMacro(m, SQLUL_COPY_LOGRETAIN_OFF       ); //-3522   /* copy spec, no logretain     */
                                                                              /* userexit                    */
    ret = PyModule_AddIntMacro(m, SQLUL_NO_MESSAGES              ); //3523    /* no messages to be           */
                                                                              /* retrieved                   */
    ret = PyModule_AddIntMacro(m, SQLUL_FREESPACE_OPT            ); //-3524   /* freespace option invalid    */
    ret = PyModule_AddIntMacro(m, SQLU_INCOMPAT_OPT              ); //-3525   /* incompatible options        */
    ret = PyModule_AddIntMacro(m, SQLU_MOD_INCOMPAT_WITH_OPT     ); //-3526   /* modifier incompatible with  */
                                                                              /* load options                */
    ret = PyModule_AddIntMacro(m, SQLULA_INVALID_CODEPAGE        ); //-3527   /* invalid codepage            */
    ret = PyModule_AddIntMacro(m, SQLUL_DELIMITER_CONV_W         ); //3528    /* delimiter may be converted  */
                                                                              /* from app to DB              */
    ret = PyModule_AddIntMacro(m, SQLUL_UNSUPPORTED_DATA_TYPE    ); //-3529   /* Unsupported data type       */
    ret = PyModule_AddIntMacro(m, SQLUL_OBSOLETETE_SORT_PARM     ); //3535    /* Load index creation         */
                                                                              /* parameter no longer         */
                                                   /* supported                   */
    ret = PyModule_AddIntMacro(m, SQLUL_GENERATED_OVERRIDE       ); //3551    /* Generated override warning  */
    ret = PyModule_AddIntMacro(m, SQLU_NEXT_TAPE_WARNING         ); //3700    /* mount new tape              */
    ret = PyModule_AddIntMacro(m, SQLU_LOBPATHS_IGNORED          ); //3701    /* no lobs/longs but lobpath   */
                                                                              /* nonull                      */
    ret = PyModule_AddIntMacro(m, SQLU_DEVICE_IGNORED            ); //3702    /* device error but ignored    */
    ret = PyModule_AddIntMacro(m, SQLU_NUM_BUFFERS               ); //-3704   /* invalid number of buffers   */
    ret = PyModule_AddIntMacro(m, SQLU_BUFFER_SIZE_ERROR         ); //-3705   /* invalid load/unload buffer  */
                                                                              /* size                        */
    ret = PyModule_AddIntMacro(m, SQLUL_DISK_FULL                ); //-3706   /* copy target full            */
    ret = PyModule_AddIntMacro(m, SQLU_SORT_BUFFSIZE_ERROR       ); //-3707   /* invalid sort buffer size    */
    ret = PyModule_AddIntMacro(m, SQLUE_NOSPACE_IN_HASH          ); //-3708   /* Hash table is full          */

                                                                              /* Load / unload / load recovery SQLCODES                                     */
    ret = PyModule_AddIntMacro(m, SQLU_OPEN_COPY_LOC_FILE_ERROR  ); //-3783
    ret = PyModule_AddIntMacro(m, SQLU_INV_COPY_LOC_FILE_INPUT   ); //-3784
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_RECOVERY_FAILED      ); //-3785
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_PARM_WARNING      ); //3798
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_RECOVERY_PENDING     ); //3799

    /* load recovery - copy location input error type                             */
    ret = PyModule_AddIntMacro(m, SQLU_KEYWORD_CODE);//              1
    ret = PyModule_AddIntMacro(m, SQLU_OVERRIDE_CODE);//             2
    ret = PyModule_AddIntMacro(m, SQLU_UNEXPECTED_EOF_CODE);//       3
    ret = PyModule_AddIntMacro(m, SQLU_IOERROR_CODE);//              4

    /* load recovery - Different Load recovery options                            */
    ret = PyModule_AddIntMacro(m, SQLU_RECOVERABLE_LOAD);//          0
    ret = PyModule_AddIntMacro(m, SQLU_NON_RECOVERABLE_LOAD);//      1


    /* Loadapi SQLCODES                                                           */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_QUIESCEMODE       );// -3802
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_INDEX             );// -3804
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_LOADAPI_ACTION    );// -3805
    ret = PyModule_AddIntMacro(m, SQLU_CONSTRAINTS_NOT_OFF       );// -3806

    /* Export SQLCODES                                                            */
    ret = PyModule_AddIntMacro(m, SQLUE_MSG                      );// -3999   /* Export message              */

    /* Roll-Forward Recovery SQLCODES                                             */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_PARAM             );// -4904   /* invalid parameter           */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_RANGE             );// -4905   /* invalid parameter range     */
    ret = PyModule_AddIntMacro(m, SQLUM_INVALID_TPS_SET          );// -4906   /* invalid tablespace set      */
    ret = PyModule_AddIntMacro(m, SQLUM_CHECK_PENDING_SET        );// 4907    /* tables set to check         */
                                                                              /* pending state               */
    ret = PyModule_AddIntMacro(m, SQLUM_TSP_NOT_READY            );// -4908   /* tablespace not ready to     */
                                                                              /* roll forward                */
    ret = PyModule_AddIntMacro(m, SQLU_INVALID_OFLOGPATH         );// -4910   /* Invalid overflow log path   */
    ret = PyModule_AddIntMacro(m, SQLU_RC_MISSING_LOGFILES       );// -4970   /* missing log files           */
    ret = PyModule_AddIntMacro(m, SQLU_RC_LOG_TRUNCATED          );// -4971   /* log truncation failed       */
    ret = PyModule_AddIntMacro(m, SQLU_RC_LOGPATH_FULL           );// -4972   /* log path full               */
    ret = PyModule_AddIntMacro(m, SQLU_RC_LOG_MISMATCH           );// -4973   /* log mismatch with catalog   */
                                                                              /* node                        */
    ret = PyModule_AddIntMacro(m, SQLU_RC_QRY_ERR_WARN          );// 4974    /* query status warning        */
    ret = PyModule_AddIntMacro(m, SQLU_RC_CANCELED_WARN         );// 4975    /* rollforward canceled        */
    ret = PyModule_AddIntMacro(m, SQLU_RC_NOT_ON_CATALOG_NODE    );// -4976   /* not on catalog node         */
    ret = PyModule_AddIntMacro(m, SQLU_RC_EXPORT_DIR             );// -4977   /* bad export directory        */
    ret = PyModule_AddIntMacro(m, SQLU_RC_DROPPED_TBL            );// -4978   /* bad dropped table recovery  */
                                                                              /* option                      */
    ret = PyModule_AddIntMacro(m, SQLU_RC_EXPORT_DATA           );// 4979    /* error while exporting       */
                                                                             /* table data                  */
    ret = PyModule_AddIntMacro(m, SQLU_RC_LOGFILE_CORRUPT        );// -4980   /* Corrupt Log file            */
    ret = PyModule_AddIntMacro(m, SQLU_RC_EXPORT_PART           );// 4981     /* error while exporting       */
                                                                             /* partition data              */

    /* Configuration SQLCODES                                                     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_STANDBY_MIGR           );// -1776   /* command not valid for       */
                                                                              /* standby.                    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_SYSAUTH                );// -5001   /* only SYSADM_GROUP can       */
                                                                              /* change db2 configuration    */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_SYSERR                 );// -5005   /* system error                */
    ret = PyModule_AddIntMacro(m, SQLF_RC_PATHNAME               );// -5010   /* path name error             */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNODENAME            );// -5020   /* invalid node name           */
    ret = PyModule_AddIntMacro(m, SQLF_RC_REL                    );// -5030   /* invalid release number      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_NEEDMIG                );// -5035   /* database needs migration;   */
                                                                              /* release number is back      */
                                                                              /* level                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INSMEM                 );// -5047   /* insufficient memory to      */
                                                                              /* support stack switching     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_SYSCSUM                );// -5050   /* invalid db2 configuration   */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_DBCSUM                 );// -5055   /* invalid db configuration    */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVTKN                 );// -5060   /* invalid token parameter     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVTKN_STRUCT          );// -5061   /* invalid ptr to sqlfupd      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVTKN_PTR             );// -5062   /* invalid token ptr value     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_OLD_DB_CFG_TKN_TRUNC   );// 5066    /* warning - truncated result  */
                                                                              /* due to obsolete db cfg      */
                                                                              /* token                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_CNTINV                 );// -5070   /* invalid count parameter     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVLOGCFG              );// -5099   /* invalid logging db cfg      */
                                                                              /* parameter                   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNEWLOGP             );// -5099   /* invalid new log path - use  */
                                                                              /* SQLF_RC_INVLOGCFG instead   */

    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_BIT_VALUE          );// -5112   /* invalid bit value - must    */
                                                                              /* be 0 or 1                   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_ALT_COLLATE            );// -5113   /* set alt_collate on unicode  */
                                                                              /* db not allowed              */

    ret = PyModule_AddIntMacro(m, SQLF_RC_INVDETS                );// -5121   /* invalid DB configuration    */
                                                                              /* details                     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_PROTECT                );// -5122   /* database is copy protected  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_LOGIO                  );// -5123   /* I/O Error with log header   */
#ifndef SQLF_RC_UPDATE_FAILED
#define SQLF_RC_UPDATE_FAILED -5124
#endif
    ret = PyModule_AddIntMacro(m, SQLF_RC_UPDATE_FAILED          );// -5124   /* Failed to update the DB     */
                                                                              /* configuration on one or     */
                                                                              /* more nodes                  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_DBMENT             );// -5126   /* DBM Param not supported by  */
                                                                              /* nodetype                    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE              );// -5130   /* integer out of range        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_2            );// -5131   /* integer out of range (-1)   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_STRING             );// -5132   /* string null or too long     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_SET                );// -5133   /* char/int not in set         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVTPNAME              );// -5134   /* tpname not valid            */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_DBPATH             );// -5136   /* dftdbpath not valid         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_DIAGPATH           );// -5137   /* diagpath not valid          */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_CF_DIAGPATH        );// -1565   /* cf_diagpath not valid       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_AGENTPRI           );// -5131   /* invalid agent priority      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_WRN_SELF_TUN_ON        );// 5144    /* tuning won't occur until    */
                                                                              /* self_tun is ON              */
    ret = PyModule_AddIntMacro(m, SQLF_RC_WRN_AUTO_DEACTIV       );// 5145    /* tuning deactivated because  */
                                                                              /* not enough auto parms       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_WRN_PARM_SET_AUTO      );// 5146    /* db2 set param 2 to auto     */
                                                                              /* because parm 1 set auto by  */
                                                                              /* user                        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_NO_MAN_IF_AUTO     );// -5147   /* param 1 can't be set to     */
                                                                              /* manual if param 2 auto      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_WRN_SHEAPTHRES_NOT_0   );// 5148    /* no tuning until sheapthres  */
                                                                              /* set to 0                    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_CFG_LATCH_NOT_AVAIL    );// -5149   /* cfg latch not available     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_TOO_SMALL    );// -5150   /* out of range - value too    */
                                                                              /* small                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_TOO_SMALL_2  );// -5151   /* out of range - value too    */
                                                                              /* small (-1 is allowed)       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_TOO_BIG      );// -5152   /* out of range - value too    */
                                                                              /* large                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_CONDITION    );// -5153   /* out of range - condition    */
                                                                              /* violated                    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_CFG_SETTING        );// -6112   /* cfg param settings not      */
                                                                              /* valid                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_AUTH_TRUST         );// -5154   /* authentication must be      */
                                                                              /* CLIENT for trust_allcnts =  */
                                                                              /* NO or trust_clntauth =      */
                                                                              /* SERVER                      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_SORTHEAP_PERF          );// 5155    /* sortheap performance        */
                                                                              /* warning                     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_NO_MORE_DB_CFG_UPD     );// -5160   /* No more db cfg updates      */
                                                                              /* allowed in HA               */
    ret = PyModule_AddIntMacro(m, SQLF_RC_NO_MORE_DBM_CFG_UPD    );// -5161   /* No more dbm cfg updates     */
                                                                              /* allowed in HA               */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVHADRTARGETLIST      );// -5165   /* invalid hadr target list    */
#ifndef SQLF_RC_INV_DBCFG_VAL_NT
#define SQLF_RC_INV_DBCFG_VAL_NT  -5195
#define SQLF_RC_INV_DBCFG_PARM_NT -5196
#endif
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_DBCFG_VAL_NT       );// -5195   /* DB cfg parameter value not  */
                                                                              /* valid on this instance      */
                                                                              /* type.                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_DBCFG_PARM_NT      );// -5196   /* DB cfg parameter not valid  */
                                                                              /* on this instance type.      */

    /* Data Redistribution Return Codes                                           */
    ret = PyModule_AddIntMacro(m, SQLUT_NGNAME_UNDEF             );// -204    /* nodegroup name is           */
                                                                              /* undefined                   */
    ret = PyModule_AddIntMacro(m, SQLUT_NODE_DUP                 );// -265    /* node is a duplicate node    */
    ret = PyModule_AddIntMacro(m, SQLUT_NODE_UNDEF               );// -266    /* node is undefined           */
    ret = PyModule_AddIntMacro(m, SQLUT_OVER_MAX_PARTNO          );// -269    /* max no. of part. map        */
                                                                              /* reached                     */
    ret = PyModule_AddIntMacro(m, SQLUT_REDIST_UNDEF             );// -607    /* redist undefined for sys    */
                                                                              /* obj.                        */
    ret = PyModule_AddIntMacro(m, SQLUT_INSAUTH                  );// -1092   /* insufficient authority      */
    ret = PyModule_AddIntMacro(m, SQLUT_ACCESS_DENIED            );// -1326   /* file or dir access denied   */
    ret = PyModule_AddIntMacro(m, SQLUT_NO_CONTAINERS            );// -1755   /* for tablespaces on a node   */
    ret = PyModule_AddIntMacro(m, SQLUT_INVALID_AUTHS            );// SQLU_INVALID_AUTHS /* invalid          */
                                                                                         /* authorizations -2018        */
    ret = PyModule_AddIntMacro(m, SQLUT_INVALID_PARM);// SQLU_INVALID_PARM /* parm to utility   */
                                                                           /* incorrect -2032             */
    ret = PyModule_AddIntMacro(m, SQLUT_INVALID_PARM_ADDRESS);// SQLU_INVALID_PARM_ADDRESS /* addr of   */
                                                                                           /* parm incorrect -2034        */
    ret = PyModule_AddIntMacro(m, SQLUT_RC_REDIST_CHECK_ERR      );// -2436   /* Redistribution cannot be    */
                                                                              /* performed                   */
    ret = PyModule_AddIntMacro(m, SQLUT_CBI);                     // SQLUE_CBI/* function interruption       */
                                                                              /* 3005                        */
    ret = PyModule_AddIntMacro(m, SQLUT_REDIST_NO_PARTKEY        );// -6047   /* redist failed - no part     */
                                                                              /* key                         */
    ret = PyModule_AddIntMacro(m, SQLUT_ERR_IN_FILE              );// -6053   /* error found in the input    */
                                                                              /* file                        */
    ret = PyModule_AddIntMacro(m, SQLUT_RC_REDIST_ERR            );// -6056   /* redistribution not          */
                                                                              /* performed                   */
    ret = PyModule_AddIntMacro(m, SQLUT_ERROR_REDIST             );// -6064   /* error during data           */
                                                                              /* redistbution                */
    ret = PyModule_AddIntMacro(m, SQLUT_WRT_OUT_FILE             );// -6065   /* error writing output file   */
    ret = PyModule_AddIntMacro(m, SQLUT_BAD_PARM                 );// -1385   /* error input paramenters     */
    ret = PyModule_AddIntMacro(m, SQLUT_PARTIAL                  );// 1379    /* database partition group    */
                                                                              /* has been partially          */
                                                                              /* redistributed               */
    /* Load Header Return Codes                                                   */
    ret = PyModule_AddIntMacro(m, SQLU_PARTITIONMAP              );// -6100   /* Invalid partition map       */
    ret = PyModule_AddIntMacro(m, SQLU_NODE_NUMBER               );// -6101   /* Invalid node number         */
    ret = PyModule_AddIntMacro(m, SQLU_FUTURE_PARM               );// -6102   /* Parameter reserved for      */
                                                                              /* future                      */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_SYSERR               );// -6103   /* Unexpected load system      */
                                                                              /* error                       */
    ret = PyModule_AddIntMacro(m, SQLU_NO_INDICES                );// -6104   /* Load does not support       */
                                                                              /* indices                     */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_COMPLETE             );// -6105   /* Load complete - backup NOW  */
                                                                              /* !                           */
    ret = PyModule_AddIntMacro(m, SQLU_NOHEADER                  );// -6106   /* Invalid use of NOHEADER     */
    ret = PyModule_AddIntMacro(m, SQLU_PARTITION_KEY             );// -6107   /* Invalid partitioning key    */
    ret = PyModule_AddIntMacro(m, SQLU_PARTITION_KEY_NUM         );// -6108   /* Wrong number of partition   */
                                                                              /* keys                        */
    ret = PyModule_AddIntMacro(m, SQLU_PARTITION_KEY_NAME        );// -6109   /* Unexpected partitioning     */
                                                                              /* key                         */
    ret = PyModule_AddIntMacro(m, SQLU_PARTITION_KEY_TYPE        );// -6110   /* Unexpected partition key    */
                                                                              /* type                        */
    /* Repository for obsolete Return Codes                                       */

    ret = PyModule_AddIntMacro(m, SQLU_WRITE_ERROR               );// -2006   /* wrote wrong # of bytes      */
    ret = PyModule_AddIntMacro(m, SQLU_CONNECT_ERROR             );// -2010   /* error in Start Using        */
    ret = PyModule_AddIntMacro(m, SQLU_INT_ERROR                 );// -2012   /* error in ints               */
    ret = PyModule_AddIntMacro(m, SQLU_ADSM_ERROR);// SQLU_TSM_ERROR          /* ADSM reported error  */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_ADSM_ERROR);// SQLU_LOAD_TSM_ERROR /* unable to load  */
                                                                               /* ADSM                        */
    ret = PyModule_AddIntMacro(m, SQLUD_NO_MHEADER_ERROR         );// -2531   /* media header not present    */
    ret = PyModule_AddIntMacro(m, SQLUD_NO_MHEADER_WARNING);// 2534           /* media header missing        */
    ret = PyModule_AddIntMacro(m, SQLUD_NEXT_TAPE_WARNING);// 2535     /* another tape mount          */
                                                                      /* required                    */
    ret = PyModule_AddIntMacro(m, SQLUD_TSM_MOUNT_WAIT);// 2545    /* waiting for TSM server to   */
                                                                   /* access data on removable    */
                                                                   /* media                       */
    ret = PyModule_AddIntMacro(m, SQLUD_ADSM_MOUNT_WAIT);// SQLUD_TSM_MOUNT_WAIT /* waiting for    */
                                                                                 /* ADSM server to access data  */
                                                                                 /* on removable media          */

    /* Configuration parameter obsolete return codes defines - Some               */
    /* configuration parameters had specific out of range return codes; these     */
    /* have been replaced by generic out of range messages In these cases the     */
    /* old token names for the specific return codes are given, but the values    */
    /* are replaced by the new values returned when out of range.                 */

    ret = PyModule_AddIntMacro(m, SQLF_RC_DBAUTH                 );// -5002   /* only SYSADM can             */
                                                                              /* changedatabase              */
                                                                              /* configuration file          */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNDB                 );// -5130   /* invalid # of concurrent db  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVRIO                 );// -5130   /* invalid req I/O blk size    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSIO                 );// -5015   /* invalid serv I/O blk size   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVCHEAP               );// -5016   /* invalid communications      */
                                                                              /* heap                        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVRSHEAP              );// -5017   /* invalid remote services     */
                                                                              /* heap                        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSHPTHR              );// -5130   /* invalid sort heap           */
                                                                              /* threshold                   */
    ret = PyModule_AddIntMacro(m, SQLCC_RC_BAD_DB2COMM           );// -5036   /* invalid DB2COMM value       */
    ret = PyModule_AddIntMacro(m, SQLCC_RC_NO_SERV_IN_DBMCFG     );// -5037   /* service name not definein   */
                                                                              /* db2 config file             */
    ret = PyModule_AddIntMacro(m, SQLCC_RC_SERV_NOT_FOUND        );// -5038   /* service name not found in   */
                                                                              /* etc/services file           */
    ret = PyModule_AddIntMacro(m, SQLCC_RC_INT_PORT_NOT_FOUND    );// -5039   /* interrupt port not found    */
                                                                              /* in/etc/services file        */
    ret = PyModule_AddIntMacro(m, SQLCC_RC_NO_TPN_IN_DBMCFG      );// -5041   /* trans program name not      */
                                                                              /* definedin db2               */
                                                                              /* configuration file          */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNLL                 );// -5130   /* invalid # of locklist       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNBP                 );// -5130   /* invalid # bufr pool pages   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNDBF                );// -5130   /* invalid # of DB files open  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSCP_DB2OS2          );// -5130   /* invalid soft check point    */
                                                                              /* value                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSCP_DB2AIX          );// -5130   /* invalid soft check point    */
                                                                              /* value                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSCP                 );// -5130   /* invalid soft check point    */
                                                                              /* value                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNAP                 );// -5130   /* invalid # of active appls   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVAHP                 );// -5130   /* invalid application heapsz  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVDHP                 );// -5130   /* invalid database heap size  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVDLT                 );// -5130   /* invalid deadlock detection  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVTAF                 );// -5130   /* invalid # of total files    */
                                                                              /* openper application         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSHP                 );// -5130   /* invalid sortlist heap       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVMAL                 );// -5130   /* invalid maxlocks per        */
                                                                              /* application                 */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSTMHP               );// -5130   /* invalid statement heap      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVLOGPRIM             );// -5130   /* invalid number primary log  */
                                                                              /* files                       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVLOG2ND              );// -5130   /* invalid number of           */
                                                                              /* secondary log files         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVLOGFSZ              );// -5130   /* invalid log file size       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVDB2                 );// -5102   /* incompatible file open      */
                                                                              /* parmeter                    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVK2                  );// -5104   /* no DB's / requestor only    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVK3                  );// -5126   /* standalone nodetype does    */
                                                                              /* notsupport nodename         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_RWS_EXIST              );// -5106   /* remote workstation has      */
                                                                              /* alreadybeen configured      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_RWS_SYSADM             );// -5107   /* <authid> does not           */
                                                                              /* haveauthority to add or     */
                                                                              /* drop a remote workstation   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_RWS_NOT_EXIST          );// -5108   /* remote workstation has      */
                                                                              /* notbeen previously setup    */
                                                                              /* using sqlarws               */
    ret = PyModule_AddIntMacro(m, SQLF_RC_RWS_MACHINENAME        );// -5109   /* machine name is missing     */
                                                                              /* ors too long.               */
    ret = PyModule_AddIntMacro(m, SQLF_RC_RWS_INV_OPT            );// -5110   /* configuration option is     */
                                                                              /* invalid                     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_ENV_VAR_NOTDEF         );// -5111   /* environment                 */
                                                                              /* variableDB2WKSTPROF is not  */
                                                                              /* defined                     */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVDB3                 );// -5146   /* incompatible buffer pool    */
                                                                              /* and maximum # of            */
                                                                              /* applications                */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_QUERY_HEAP_SZ      );// -5143   /* invalid QUERY_HEAP_SZ       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_3            );// -5144   /* out of range - limited by   */
                                                                              /* a parm                      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_MAX_EXPR     );// -5144   /* out of range - maximum      */
                                                                              /* limited by an expression    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_MAX_EXPR_2   );// -5145   /* out of range - maximum      */
                                                                              /* limited by an expression    */
                                                                              /* (range includes -1)         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_MIN_EXPR     );// -5146   /* out of range - minimum      */
                                                                              /* limited by an expression    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_RANGE_MIN_EXPR_2   );// -5147   /* out of range - minimum      */
                                                                              /* limited by an expression    */
                                                                              /* (range includes -1)         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_KCON                   );// -5025   /* not current db2             */
                                                                              /* configuration               */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVILF                 );// -5083   /* invalid initial log size    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVLFE                 );// -5091   /* invalid logfile extention   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNLE                 );// -5092   /* invalid # of log extention  */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVDB1                 );// -5101   /* incompatible logfile        */
                                                                              /* parameter                   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_LF_1_3                 );// -5120   /* both R1 & R3 Log            */
                                                                              /* parameters may not be       */
                                                                              /* modified                    */
    ret = PyModule_AddIntMacro(m, SQLF_RC_LOW_APPLS_AND_LOCKS    );// -5135   /* maxappls*maxlocks too low   */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_AVG_APPLS          );// -5141   /* invalid AVG_APPLS           */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSYSIDX              );// -5021   /* invalid system flag         */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVDBIDX               );// -5022   /* invalid database flag       */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVSYSADM              );// -5028   /* invalid sysadm_group        */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVNT                  );// -5065   /* invalid node type           */
    ret = PyModule_AddIntMacro(m, SQLF_RC_CNTBRK                 );// -5075   /* interrupt received          */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_AUTHENTICATION     );// -5140   /* invalid authentication      */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INV_TRUST_ALLCLNTS     );// -5156   /* invalid trust_allclnts      */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_RESTARTCOUNT_WARN    );// 6500    /* db2atld restartcount        */
                                                                              /* warning                     */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_SAVECOUNT_ERROR      );// -6532   /* db2atld savecount error     */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_RESTARTCOUNT_ERROR   );// -6533   /* db2atld restartcount error  */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_SPLIT_NOT_NEEDED     );// -6535   /* db2atld does not need       */
                                                                              /* splitting                   */
    ret = PyModule_AddIntMacro(m, SQLU_PMAP_OPEN_ERR             );// -6550   /* db2atld unable to open      */
                                                                              /* pmap                        */
    ret = PyModule_AddIntMacro(m, SQLU_PMAP_WRITE_ERR            );// -6551   /* db2atld failed to write     */
                                                                              /* pmap                        */
    ret = PyModule_AddIntMacro(m, SQLU_TEMPCFG_OPEN_ERR          );// -6552   /* db2atld failed to open      */
                                                                              /* temp file                   */
    ret = PyModule_AddIntMacro(m, SQLU_TEMPCFG_WRITE_ERR         );// -6553   /* db2atld failed to write to  */
                                                                              /* tmp file                    */
    ret = PyModule_AddIntMacro(m, SQLU_REXEC_ERR                 );// -6554   /* db2atld failed to spawn     */
                                                                              /* remote child                */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_COMM_ERR             );// -6555   /* db2atld comm error          */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_PARTIAL_REC);// 6556              /* db2atld partial record      */
                                                                              /* found                       */
    ret = PyModule_AddIntMacro(m, SQLU_GET_DEFAULT_NODE_ERR      );// -6557   /* db2atld failed to get       */
                                                                              /* default node                */
    ret = PyModule_AddIntMacro(m, SQLU_GET_CURDIR_ERR            );// -6558   /* db2atld unable to get cur   */
                                                                              /* working dir                 */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_BAD_CLP_ERR          );// -6559   /* db2atld incorrect usage     */
    ret = PyModule_AddIntMacro(m, SQLU_BAD_SPLIT_NODE            );// -6560   /* db2atld split node          */
                                                                              /* incorrect                   */
    ret = PyModule_AddIntMacro(m, SQLU_BAD_LOAD_NODE             );// -6561   /* db2atld invalid load node   */
    ret = PyModule_AddIntMacro(m, SQLU_GET_INSTANCE_ERR          );// -6562   /* db2atld failed to get       */
                                                                              /* instance                    */
    ret = PyModule_AddIntMacro(m, SQLU_GET_UID_ERR               );// -6563   /* db2atld failed to get cur   */
                                                                              /* UID                         */
    ret = PyModule_AddIntMacro(m, SQLU_BAD_PASSWORD              );// -6564   /* db2atld invalid password    */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_HELP                );// 6565     /* db2atld help msg            */
    ret = PyModule_AddIntMacro(m, SQLU_MISSING_LOAD_COMMAND      );// -6566   /* db2atld load command not    */
                                                                              /* specified                   */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_DUP_OPTION           );// -6567   /* db2atld option specified    */
                                                                              /* twice                       */
    ret = PyModule_AddIntMacro(m, SQLU_STARTING_ALL_LOADS       );// 6568    /* db2atld starting all the    */
                                                                             /* load jobs                   */
    ret = PyModule_AddIntMacro(m, SQLU_STARTING_ALL_SPLITTERS   );// 6569    /* db2atld starting all the    */
                                                                             /* splitters                   */
    ret = PyModule_AddIntMacro(m, SQLU_WAITING_FOR_SPLITTERS    );// 6570    /* db2atld waiting for         */
                                                                             /* splitters to finish         */
    ret = PyModule_AddIntMacro(m, SQLU_WAITING_FOR_LOADS        );// 6571    /* db2atld waiting for load    */
                                                                             /* to complete                 */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_STARTED             );// 6572    /* db2atld load has started    */
    ret = PyModule_AddIntMacro(m, SQLU_SPLIT_RESULT             );// 6573    /* db2atld splitters has       */
                                                                             /* finished                    */
    ret = PyModule_AddIntMacro(m, SQLU_DATA_READ_STATUS         );// 6574    /* db2atld Bytes read thus     */
                                                                             /* far                         */
    ret = PyModule_AddIntMacro(m, SQLU_TOTAL_DATA_READ          );// 6575    /* db2atld total size of data  */
                                                                             /* read                        */
    ret = PyModule_AddIntMacro(m, SQLU_THREAD_ERR                );// -6576   /* db2atld threading error     */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_ROWCOUNT_ERROR       );// -27961  /* rowcount not supported in   */
                                                                              /* this mode                   */
    ret = PyModule_AddIntMacro(m, SQLU_ATLD_TOO_MANY_SPLITTERS   );// -27991  /* too many splitters          */
    ret = PyModule_AddIntMacro(m, SQLU_COPYNO_OVERRIDE_INVALID   );// -27965  /* invalid DB2_LOAD_COPY_NO    */
                                                                              /* OVERRIDE reg variable       */
    ret = PyModule_AddIntMacro(m, SQLU_COPYNO_OVERRIDE_WARNING);// 27966   /* COPY NO was overridden      */
                                                                           /* warning                     */
    ret = PyModule_AddIntMacro(m, SQLU_COPYNO_OVERRIDE_DFLTWARN);//  27967   /* COPY NO was overriden with  */
                                                                             /* default (nonrecov)          */
#ifndef SQLU_NOREBUILD_DETACHEDMQT
#define SQLU_NOREBUILD_DETACHEDMQT -27983
#endif
    ret = PyModule_AddIntMacro(m, SQLU_NOREBUILD_DETACHEDMQT     );// -27983  /* Can't REBUILD when          */
                                                                              /* partition is detached and   */
                                                                              /* MQT exists                  */
    ret = PyModule_AddIntMacro(m, SQLU_SPEC_REGSTR_TRUNC_WARN);//27994   /* Special Register Default    */
                                                                         /* value truncated.            */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_INCOMPATIBLE_OPTS    );// -1159   /* Incompatible LOAD options.  */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_INV_REMOTEFETCH_OPTS );// -1151   /* Invalid REMOTEFETCH media   */
                                                                              /* options.                    */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_REMOTEFETCH_ERROR    );// -1168   /* Load REMOTEFETCH media      */
                                                                              /* error.                      */
    ret = PyModule_AddIntMacro(m, SQLU_LOAD_REMOTEFETCH_WARNING);//1175    /* Load REMOTEFETCH media      */
                                                                           /* warning.                    */

    /* Flush Table API Return Codes                                               */
    ret = PyModule_AddIntMacro(m, SQLUF_TABLE_NOT_AT_NODE        );// -6024   /* Table not at this node      */

                                                                              /* sqlugrpi, sqlugrpn, and sqlugtpi return codes                              */
    ret = PyModule_AddIntMacro(m, SQLUG_INVALID_AUTHID);// SQLUS_INVALID_AUTHID /* Invalid        */
                                                                                /* authid                      */
    ret = PyModule_AddIntMacro(m, SQLUG_INVALID_TABLE_NAME);//       SQLUS_INVALID_TABLE_NAME /* invalid    */
                                                                                              /* table                       */
    ret = PyModule_AddIntMacro(m, SQLUG_CBI);//SQLUE_CBI /* Interrupt                 */
    ret = PyModule_AddIntMacro(m, SQLUG_TABLE_NOT_FOUND);//SQLUR_TABLE_NOT_FOUND /* Table not     */
                                                                                 /* exist                       */
    ret = PyModule_AddIntMacro(m, SQLUG_RC_INSAUTH               );// -6023   /* Insufficient authorization  */
    ret = PyModule_AddIntMacro(m, SQLUG_NULL_PARTKEY             );// -6038   /* No partitioning key         */
    ret = PyModule_AddIntMacro(m, SQLUG_NULL_NOTALLOWED          );// -6039   /* Nulls not allowed           */
    ret = PyModule_AddIntMacro(m, SQLUG_DECIMAL_FORMAT_CONFLICT  );// -2755   /* decimal format conflict     */
    ret = PyModule_AddIntMacro(m, SQLUG_INVALID_SYNTAX           );// -6044   /* Invalid syntax              */
    ret = PyModule_AddIntMacro(m, SQLUG_INVALID_DATATYPE         );// -6045   /* Invalid datatype            */
    ret = PyModule_AddIntMacro(m, SQLF_RC_INVALID_DYNQUERYMGMT   );// -29000  /* Invalid dynamic query mgmt  */
                                                                              /* flag                        */

    /* Load error codes continued                                                 */
    ret = PyModule_AddIntMacro(m, SQLU_INV_RESTART_TERMINATE     );// -27902  /* Load restart/terminate is   */
                                                                              /* not necessary               */
#ifndef SQLU_BAD_PARM_FOR_COL_TABLE
#define SQLU_BAD_PARM_FOR_COL_TABLE   -27906
#define SQLU_BAD_PARM_AFT_FAILED_LOAD -27917
#endif
    ret = PyModule_AddIntMacro(m, SQLU_BAD_PARM_FOR_COL_TABLE    );// -27906  /* Unsupported LOAD            */
                                                                              /* parameters for column       */
                                                                              /* organized table             */
    ret = PyModule_AddIntMacro(m, SQLU_BAD_PARM_AFT_FAILED_LOAD  );// -27917  /* Unsupported LOAD            */
                                                                              /* parameters for table in     */
                                                                              /* load pending                */
    ret = PyModule_AddIntMacro(m, SQLU_PARTLOAD_BAD_PARAMETER    );// -27959  /* Invalid input parameter     */
                                                                              /* for partitioned database    */
                                                                              /* load                        */
    ret = PyModule_AddIntMacro(m, SQLU_PARTLOAD_PART_FILE_CURSOR );// -27960  /* Invalid PART_FILE_LOCATION  */
                                                                              /* specified for source type   */
                                                                              /* CURSOR                      */
    ret = PyModule_AddIntMacro(m, SQLU_PARTLOAD_BAD_ROWCOUNT     );// -27961  /* Invalid rowcount specified  */
                                                                              /* for partitioned database    */
                                                                              /* load                        */
    ret = PyModule_AddIntMacro(m, SQLU_PARTITION_VIOLATIONS);//27990   /* Load partition violations   */
                                                                       /* detected                    */
    ret = PyModule_AddIntMacro(m, SQLU_PARTITIONING_MAP_FOUND    );// -27992  /* Partitioning map was        */
                                                                              /* found, but load mode is     */
                                                                              /* not load_only               */
    ret = PyModule_AddIntMacro(m, SQLU_INCOMPAT_FEATURE          );// -1407   /* The table contains a        */
                                                                              /* feature that is             */
                                                                              /* incompatible with the       */
                                                                              /* specified option            */
    ret = PyModule_AddIntMacro(m, SQLU_SHARED_SORT_MEM_REQUIRED  );// -1406   /* Shared sort memory is       */
                                                                              /* required for this           */
                                                                              /* operation                   */

    /* Utility control error codes                                                */
    ret = PyModule_AddIntMacro(m, SQLUTH_INVALID_PRIORITY        );// -1152   /* Invalid priority            */
    ret = PyModule_AddIntMacro(m, SQLUTH_UTILITY_NOT_FOUND       );// -1153   /* Utility not found           */
    ret = PyModule_AddIntMacro(m, SQLUTH_NO_THROTTLE_SUPPORT     );// -1154   /* Utility does not support    */
                                                                              /* throttling                  */

    /* obsolete database manager configuration parameter tokens                   */
    ret = PyModule_AddIntMacro(m, SQLF_KTN_SVRIOBLK);//              3
    ret = PyModule_AddIntMacro(m, SQLF_KTN_SQLENSEG);//              5
    ret = PyModule_AddIntMacro(m, SQLF_KTN_COMHEAPSZ);//             8
    ret = PyModule_AddIntMacro(m, SQLF_KTN_RSHEAPSZ);//              9
    ret = PyModule_AddIntMacro(m, SQLF_KTN_NUMRC);//                 10
    ret = PyModule_AddIntMacro(m, SQLF_KTN_CUINTERVAL);//            14
    ret = PyModule_AddIntMacro(m, SQLF_KTN_SQLSTMTSZ);//             17
    ret = PyModule_AddIntMacro(m, SQLF_KTN_COMHEAPSZ_P);//           50
    ret = PyModule_AddIntMacro(m, SQLF_KTN_RSHEAPSZ_P);//            51
    ret = PyModule_AddIntMacro(m, SQLF_KTN_IPX_FILESERVER);//        SQLF_KTN_FILESERVER
    ret = PyModule_AddIntMacro(m, SQLF_KTN_IPX_OBJECTNAME);//        SQLF_KTN_OBJECTNAME
    ret = PyModule_AddIntMacro(m, SQLF_KTN_ADSM_PASSWORD);//         93
    ret = PyModule_AddIntMacro(m, SQLF_KTN_ADSM_NODENAME);//         94
    ret = PyModule_AddIntMacro(m, SQLF_KTN_ADSM_OWNER);//            95
    ret = PyModule_AddIntMacro(m, SQLF_KTN_MAX_IDLEAGENTS);//        60
    ret = PyModule_AddIntMacro(m, SQLF_KTN_DOS_RQRIOBLK);//          72
    ret = PyModule_AddIntMacro(m, SQLF_KTN_DIR_TYPE);//              73
    ret = PyModule_AddIntMacro(m, SQLF_KTN_DIR_PATH_NAME);//         74
    ret = PyModule_AddIntMacro(m, SQLF_KTN_DIR_OBJ_NAME);//          75
    ret = PyModule_AddIntMacro(m, SQLF_KTN_ROUTE_OBJ_NAME);//        76
    ret = PyModule_AddIntMacro(m, SQLF_KTN_DFT_CLIENT_COMM);//       77
    ret = PyModule_AddIntMacro(m, SQLF_KTN_DFT_CLIENT_ADPT);//       82
    ret = PyModule_AddIntMacro(m, SQLF_KTN_SS_LOGON);//              309
    ret = PyModule_AddIntMacro(m, SQLF_KTN_UDF_MEM_SZ);//            69
    ret = PyModule_AddIntMacro(m, SQLF_KTN_FCM_NUM_RQB);//           504
    ret = PyModule_AddIntMacro(m, SQLF_KTN_FCM_NUM_CONNECT);//       505
    ret = PyModule_AddIntMacro(m, SQLF_KTN_FCM_NUM_ANCHORS);//       506
    ret = PyModule_AddIntMacro(m, SQLF_KTN_MIN_PRIV_MEM);//          43
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ESTORE_SEG_SZ);//        303
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUM_ESTORE_SEGS);//      304
    ret = PyModule_AddIntMacro(m, SQLF_KTN_PRIV_MEM_THRESH);//       44
    ret = PyModule_AddIntMacro(m, SQLF_KTN_MAXAGENTS);//             12
    ret = PyModule_AddIntMacro(m, SQLF_KTN_MAXCAGENTS);//            13

    /* obsolete database configuration parameter tokens                           */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGFILE);//              4
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MAXTOTFILOP);//          10
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGEXT);//               12
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGMAXEXT);//            13
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AGENTHEAP);//            14
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOG_RETAIN);//           23
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_USER_EXIT);//            24
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SEGPAGES);//             123
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_BUFFPAGE);//             2
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SORTHEAP);//             91
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SORTHEAPSZ_P);//         SQLF_DBTN_SORT_HEAP
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DBHEAP);//               50
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DBHEAP_P);//             SQLF_DBTN_DBHEAP
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_APPLHEAPSZ_P);//         SQLF_DBTN_APPLHEAPSZ
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_STMTHEAPSZ_P);//         SQLF_DBTN_STMTHEAP
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGFILSIZ);//            18
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MULTIPGAL);//            504
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ADSM_PASSWD);//          501
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NEXTACTIVE);//           107
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DL_NUM_BACKUP);//        352
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ADSM_PASSWORD);//        SQLF_DBTN_TSM_PASSWORD
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ADSM_OWNER);//           SQLF_DBTN_TSM_OWNER
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ADSM_NODENAME);//        SQLF_DBTN_TSM_NODENAME
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ADSM_MGMTCLASS);//       SQLF_DBTN_TSM_MGMTCLASS
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOCKLIST);//             1


    /* obsolete config parm assorted defines                                      */
    ret = PyModule_AddIntMacro(m, SQLFDMCA                       );// -1      /* Default maxcagents          */
    ret = PyModule_AddIntMacro(m, SQLFDMXD                       );// -1      /* Default maxdari             */
    ret = PyModule_AddIntMacro(m, SQLFDAPR                       );// -1      /* Default agentpri            */
    ret = PyModule_AddIntMacro(m, SQLFMKPD);//                       0        /* keepdari - no               */
    ret = PyModule_AddIntMacro(m, SQLFXKPD);//                       1       /* keepdari - yes              */

    /* obsolete defines for SQLF_DBTN_DETS                                        */
    ret = PyModule_AddIntMacro(m, SQLF_COPY_NOPROT);//               0x0     /* xxxx xxxx xxxx xxx0         */
    ret = PyModule_AddIntMacro(m, SQLF_COPY_PROTECT);//              0x1     /* xxxx xxxx xxxx xxx1         */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_LOG_RETAIN);//         0x2     /* xxxx xxxx xxxx xx1x         */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_USER_EXIT);//          0x4     /* xxxx xxxx xxxx x1xx         */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_AUTO_RESTART);//       0x8     /* xxxx xxxx xxxx 1xxx         */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_LOGRETAIN_CAPTURE);//  0x10    /* xxxx xxxx xxx1 xxxx         */
    ret = PyModule_AddIntMacro(m, SQLF_ENABLE_TRACKMOD);//           0x20    /* xxxx xxxx xx1x xxxx         */

                                                                             /* Obsolete media types                                                       */
    ret = PyModule_AddIntMacro(m, SQLU_ADSM_MEDIA);//                'A'     /* ADSM                        */

    return ret;

}

int add_module_globlas_backup(PyObject* m)
{
    int ret;

    /* Backup Options                                                             */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_DB);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_TABLESPACE);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_MERGE);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_INCREMENTAL);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_DELTA);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_OFFLINE);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_ONLINE);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_DEDUP_DEVICE);           /* Dedup device                   */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_COMPRESS);               /* Compress backup image          */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_INCLUDE_COMPR_LIB);      /* Include compression lib in     */
                                                                /* backup image                   */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_EXCLUDE_COMPR_LIB); /* Do not include compression     */
                                                                /* lib in backup image            */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_INCLUDE_LOGS);      /* Include log files in online    */
                                                                /* backup image                   */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_EXCLUDE_LOGS);      /* Exclude log files from backup  */
                                                                /* image                          */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_MPP);               /* Perform multi-partition        */
                                                                /* backup                         */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_COPY_ONLY);         /* Copy only backup               */
#ifdef DB2BACKUP_ENCRYPT
    ret = PyModule_AddIntMacro(m, DB2BACKUP_ENCRYPT);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_INCLUDE_ENCR_LIB);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_EXCLUDE_ENCR_LIB);
#endif
                                                                /* Backup Caller Actions                                                      */
    ret = PyModule_AddIntMacro(m, DB2BACKUP_BACKUP);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_CONTINUE);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_TERMINATE);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_NOINTERRUPT); 
    ret = PyModule_AddIntMacro(m, DB2BACKUP_DEVICE_TERMINATE); 
    ret = PyModule_AddIntMacro(m, DB2BACKUP_PARM_CHK);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_PARM_CHK_INIT_WAIT);
    ret = PyModule_AddIntMacro(m, DB2BACKUP_PARM_CHK_ONLY); 
    return ret;

}

int add_module_globals_DBTN(PyObject* m)
{
    int ret;

    ret = PyModule_AddIntMacro(m, SQLF_DBTN_BUFF_PAGE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MAXFILOP);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SOFTMAX); 
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MAXAPPLS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_APPLHEAPSZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DB_HEAP);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DLCHKTIME);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SORT_HEAP);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MAXLOCKS);       
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGPRIMARY);    
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGSECOND);      
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGFIL_SIZ);     
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_STMTHEAP);       
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NEWLOGPATH);     
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_COPY_PROTECT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_RESTART);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_INDEXREC);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_PCKCACHESZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MINCOMMIT);   /* Deprecated.                         */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGBUFSZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGBUFSZ32);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOCKTIMEOUT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_INDEXSORT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUM_FREQVALUES);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUM_IOCLEANERS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CHNGPGS_THRESH);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUM_IOSERVERS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_PREFETCH_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SEQDETECT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_LOADREC_SES);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_REC_HIS_RETENTN);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_STAT_HEAP_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DIR_OBJ_NAME);   /* token for directory services        */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AVG_APPLS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUM_QUANTILES);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_EXTENT_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_UTIL_HEAP_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CATALOGCACHE_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_QUERYOPT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_APP_CTL_HEAP_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_TSM_PASSWORD);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_PCKCACHE_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MULTIPAGE_ALLOC);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_DEGREE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_TSM_OWNER);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_TSM_NODENAME);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_TSM_MGMTCLASS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DISCOVER);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_SQLMATHWARN);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DL_EXPINT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DL_NUM_COPIES);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DL_TIME_DROP);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUM_DB_BACKUPS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DL_TOKEN);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DL_UPPER);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DL_WT_IEXPINT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DYN_QUERY_MGMT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MIN_DEC_DIV_3);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_REFRESH_AGE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOCK_LIST);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_TRACKMOD);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_APPGROUP_MEM_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_GROUPHEAP_RATIO);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SHEAPTHRES_SHR);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DATABASE_MEMORY);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_BLK_LOG_DSK_FUL);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_OVERFLOWLOGPATH);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MIRRORLOGPATH);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MAX_LOG);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUM_LOG_SPAN);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ALT_COLLATE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_DB_ROLE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_LOCAL_HOST);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_LOCAL_SVC);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_REMOTE_HOST);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_REMOTE_SVC);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_REMOTE_INST);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_TIMEOUT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_SYNCMODE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGINDEXBUILD);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SHEAPTHRES);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_STMT_HEAP);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGARCHMETH1);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGARCHMETH2);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGARCHOPT1);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGARCHOPT2);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_FAILARCHPATH);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUMARCHRETRY);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ARCHRETRYDELAY);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_VENDOROPT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTONOMIC_SWITCHES);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_MAINT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_MAINT_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_DB_BACKUP);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_DB_BACKUP_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_TBL_MAINT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_TBL_MAINT_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_RUNSTATS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_RUNSTATS_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_STATS_PROF);  /* Deprecated.                         */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_STATS_PROF_EFF); /* Deprecated.                      */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_PAGESIZE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_REORG);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_REORG_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_MTTB_TYPES);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_PROF_UPD);       /* Deprecated.                         */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_PROF_UPD_EFF); /* Deprecated.                        */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SELF_TUNING_MEM);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DB_MEM_THRESH);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ENABLE_XMLCHAR);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_APPL_MEMORY);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_STMT_STATS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_STMT_STATS_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_WLM_COLLECT_INT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_BLOCKNONLOGGED);
                                                                /* Monitoring Database Control Parameters                                     */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_REQ_METRICS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_ACT_METRICS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_UOW_DATA);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_LOCKTIMEOUT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_DEADLOCK);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_LOCKWAIT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_LW_THRESH);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_OBJ_METRICS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_PKGLIST_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_LCK_MSG_LVL);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SYSTIME_PERIOD_ADJ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_UOW_PKGLIST);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_UOW_EXECLIST);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_STATS_VIEWS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_STATS_VIEWS_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_SAMPLING);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_SAMPLING_EFF);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGGING_DETAIL);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOG_DDL_STMTS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOG_APPL_INFO);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_SCHEMAS_DCC);

    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_TARGET_LIST);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_SPOOL_LIMIT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_REPLAY_DELAY);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGARCHCOMPR1);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGARCHCOMPR2);
#ifndef SQLF_DBTN_OPT_DIRECT_WRKLD
#define SQLF_DBTN_OPT_DIRECT_WRKLD 10127
#endif
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_OPT_DIRECT_WRKLD);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_DEL_REC_OBJ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DECFLT_ROUNDING);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_PEER_WINDOW);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CF_GBP_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CF_LOCK_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CF_SCA_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CF_DB_MEM_SZ);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CF_CATCHUP_TRGT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DBRESERVEDBITMAP);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_STMT_CONC);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CONNECT_PROC);

#ifdef SQLF_DBTN_DFT_TABLE_ORG
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_TABLE_ORG);
#endif

#ifdef SQLF_DBTN_MON_RTN_EXECLIST
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_RTN_EXECLIST);
#endif

#ifdef SQLF_DBTN_MON_RTN_DATA
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_MON_RTN_DATA);
#endif

#ifdef SQLF_DBTN_STRING_UNITS
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_STRING_UNITS);
#endif

#ifdef SQLF_DBTN_NCHAR_MAPPING
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NCHAR_MAPPING);
#endif
    /* tokens for informational (non-modifiable) parameters                       */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_COLLATE_INFO);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DB_COLLNAME);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_COUNTRY);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_OVERHEAD);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DFT_TRANSFERRATE);

#ifndef SQLF_DBTN_EXTBL_STRICT_IO
#define SQLF_DBTN_EXTBL_STRICT_IO 10135
#define SQLF_DBTN_EXTBL_LOCATION  10134
#define SQLF_DBTN_PAGE_AGE_TRGT_MCR 10137
#define SQLF_DBTN_PAGE_AGE_TRGT_GCR 10136
#define SQLF_DBTN_CF_SELF_TUNING_MEM 10143
#endif
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_EXTBL_STRICT_IO);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_EXTBL_LOCATION);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_PAGE_AGE_TRGT_MCR);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_PAGE_AGE_TRGT_GCR);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CF_SELF_TUNING_MEM);

#ifdef SQLF_DBTN_ENCRLIB
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ENCRLIB);
#endif

#ifdef SQLF_DBTN_ENCROPTS
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ENCROPTS);
#endif

#ifdef SQLF_DBTN_APPLHEAP_SZ
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_APPLHEAP_SZ);
#endif

#ifdef SQLF_DBTN_PL_STACK_TRACE
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_PL_STACK_TRACE);
#endif

#ifdef SQLF_DBTN_HADR_SSL_LABEL
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_HADR_SSL_LABEL);
#endif

#ifdef SQLF_DBTN_DEC_ARITHMETIC
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DEC_ARITHMETIC);
#endif

#ifdef SQLF_DEC_ARITHMETIC_LEN
    ret = PyModule_AddIntMacro(m, SQLF_DEC_ARITHMETIC_LEN);    /* Maximum size of dec_arithmetic.     */
#endif

    ret = PyModule_AddIntMacro(m, SQLF_DBTN_TERRITORY_CODE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CODEPAGE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_RELEASE);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGPATH);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOGHEAD);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CONSISTENT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_BACKUP_PENDING);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ROLLFWD_PENDING);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_LOG_RETAIN_STATUS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_USER_EXIT_STATUS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CODESET);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_TERRITORY);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUMSEGS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DATABASE_LEVEL);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NOTOKEN);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_RESTORE_PENDING);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_RESTRICT_ACCESS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_NUMBER_COMPAT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_VARCHAR2_COMPAT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_CUR_COMMIT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DATE_COMPAT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_AUTO_REVAL);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_DEC_TO_CHAR_FMT);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SMTP_SERVER);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SQL_CCFLAGS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SECTION_ACTUALS);
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_SUSPEND_IO);

#ifdef SQLF_DBTN_EXTENDED_ROW_SZ
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_EXTENDED_ROW_SZ);
#endif

#ifdef SQLF_DBTN_ENCRYPTED_DATABASE
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_ENCRYPTED_DATABASE);
#endif

    /* These are internal optimizer parameters that the DB Config Advisorgives   */
    /* recommendations for.  They can only be set via theConfiguration Advisor    */
    /* or through the dbfopt command                                             */
#ifdef SQLF_DBTN_OPT_BUFFPAGE
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_OPT_BUFFPAGE); /* (Internal) Optimizer bufferppol     */
                                                           /* page                                */
#endif

#ifdef SQLF_DBTN_OPT_SORTHEAP
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_OPT_SORTHEAP); /* (Internal) Optimizer sort heap      */
#endif

#ifdef SQLF_DBTN_OPT_LOCKLIST
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_OPT_LOCKLIST); /* (Internal) Optimizer lock list      */
#endif

#ifdef SQLF_DBTN_OPT_MAXLOCKS
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_OPT_MAXLOCKS); /* (Internal) Optimizer max locks      */
#endif

#ifdef SQLF_DBTN_WLM_ADMISSION_CTRL
                                                                 /* WLM admission control parameters                                           */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_WLM_ADMISSION_CTRL); /* WLM admission control enabled   */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_WLM_CPU_SHARES);     /* Allocated share of CPU resources   */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_WLM_CPU_SHARE_MODE); /* CPU share behavior (hard/soft)  */
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_WLM_CPU_LIMIT);      /* Maximum allowable CPU utilization  */
                                                                 /* (%)                                 */
#endif

#ifdef SQLF_DBTN_WLM_AGENT_LOAD_TRGT
    ret = PyModule_AddIntMacro(m, SQLF_DBTN_WLM_AGENT_LOAD_TRGT); /* Target agent load per CPU      */
                                                                  /* core                                */
#endif

    return ret;
}


