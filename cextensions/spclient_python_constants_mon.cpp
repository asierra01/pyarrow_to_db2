#include "spclient_python_common_cpp.h"
#include "sqlmon.h"

int add_monitor(PyObject* m)
{
    int ret = 0;

/******************************************************************************/
/* Database System Monitor Version (version, server_version)                  */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION1);//      1
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION2);//      2
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION5);//      3
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION5_2);//    4
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION6);//      5
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION7);//      6
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION8);//      7
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION9);//      8
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION9_5);//    9
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION9_7);//    10
    ret = PyModule_AddIntMacro(m, SQLM_DBMON_VERSION9_7_1);//  11
#ifndef SQLM_DBMON_VERSION10_5_6
#define SQLM_DBMON_VERSION10_5_6 12
#endif
    ret = PyModule_AddIntMacro(m,  SQLM_DBMON_VERSION10_5_6);// 12
    ret = PyModule_AddIntMacro(m,  SQLM_CURRENT_VERSION);// SQLM_DBMON_VERSION10_5_6

/******************************************************************************/
/* Snapshot class qualifiers (This indicates how the sqlma is to be           */
/* interpreted)                                                               */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m,  SQLM_CLASS_DEFAULT);//             0 /* SQLMA is for a standard snapshot  */
    ret = PyModule_AddIntMacro(m,  SQLM_CLASS_HEALTH);//              1 /* SQLMA is for a health snapshot    */
    ret = PyModule_AddIntMacro(m,  SQLM_CLASS_HEALTH_WITH_DETAIL);//  2 /* SQLMA is for a health snapshot
                                                                        /* including additional details */
    ret = PyModule_AddIntMacro(m,  SQLM_CLASS_MAX);// 2                 /* The highest class value           */

    /******************************************************************************/
    /* Snapshot requests (sqlm_obj_struct.obj_type in sqlma)                      */
    /******************************************************************************/

                                                 /* Database Manager snapshot */
    ret = PyModule_AddIntMacro(m, SQLMA_DB2);//                 0x00010001 /* 01.DBM information            */

/* List of connections */
    ret = PyModule_AddIntMacro(m,  SQLMA_DBASE_APPLINFO);//      0x00010007 /*07.List of connections to a DB */
    ret = PyModule_AddIntMacro(m,  SQLMA_APPLINFO_ALL);//        0x0001000B /*11.List of connections to DB2  */
    ret = PyModule_AddIntMacro(m,  SQLMA_DCS_APPLINFO_ALL);//    0X0001000C /*12.List of DCS connects to DB2 */

/* Database snapshot */
    ret = PyModule_AddIntMacro(m,  SQLMA_DBASE);//               0x00010002 /*02.Database level information  */
    ret = PyModule_AddIntMacro(m,  SQLMA_DBASE_ALL);//           0x00010009 /*09.DB info for all active DBs  */
    ret = PyModule_AddIntMacro(m,  SQLMA_DCS_DBASE);//           0x00010022 /*34.DCS Database level info     */
    ret = PyModule_AddIntMacro(m,  SQLMA_DCS_DBASE_ALL);//       0x00010023 /*35.DCS DB info for allActiveDBs*/
    ret = PyModule_AddIntMacro(m,  SQLMA_DBASE_REMOTE);//        0x00010025 /*37.Remote access inf for a DB  */
    ret = PyModule_AddIntMacro(m,  SQLMA_DBASE_REMOTE_ALL);//    0x00010026 /*38.Remote access inf for allDBs*/

/* Application snapshot */
    ret = PyModule_AddIntMacro(m,  SQLMA_APPL_ALL);//            0x0001000A /*10.Appl lvl inf-all connects   */
    ret = PyModule_AddIntMacro(m,  SQLMA_APPL);//                0x00010003 /*03.Appl lvl inf-for appl_id    */
    ret = PyModule_AddIntMacro(m,  SQLMA_AGENT_ID);//            0x00010004 /*04.Appl lvl inf-for appl-hdl   */
    ret = PyModule_AddIntMacro(m,  SQLMA_DBASE_APPLS);//         0x00010006 /*06.Appl lvl inf-all conns to db*/
    ret = PyModule_AddIntMacro(m,  SQLMA_DCS_APPL_ALL);//        0x0001001E /*30.DCS appl inf-all connections*/
    ret = PyModule_AddIntMacro(m,  SQLMA_DCS_APPL);//            0x0001001F /*31.DCS appl inf-for appl_id    */
    ret = PyModule_AddIntMacro(m,  SQLMA_DCS_APPL_HANDLE);//     0x00010020 /*32.DCS appl inf-for appl-hdl   */
    ret = PyModule_AddIntMacro(m,  SQLMA_DCS_DBASE_APPLS);//     0x00010021 /*33.DCS appl inf-all cons to db */
    ret = PyModule_AddIntMacro(m,  SQLMA_DBASE_APPLS_REMOTE);//  0x00010027 /*39.RemoteAccessInf for an Appl */
    ret = PyModule_AddIntMacro(m,  SQLMA_APPL_REMOTE_ALL);//     0x00010028 /*40.RemoteAccessInf for allAppls*/

/* Table snapshot */
    ret = PyModule_AddIntMacro(m, SQLMA_DBASE_TABLES);//        0x00010005 /*05.Table related inf for a DB  */

/* Tablespace snapshot */
    ret = PyModule_AddIntMacro(m, SQLMA_DBASE_TABLESPACES);//   0x0001000D /*13.Tablespace related inf forDB*/

/* Snapshot for locks */
    ret = PyModule_AddIntMacro(m, SQLMA_APPL_LOCKS);//          0x00010014 /*20.ListOfLocks held-for applId */
    ret = PyModule_AddIntMacro(m, SQLMA_APPL_LOCKS_AGENT_ID);// 0x00010015 /*21.ListOfLocks held-for applHdl*/
    ret = PyModule_AddIntMacro(m, SQLMA_DBASE_LOCKS);//         0x00010008 /*08.ListOfLocks all appls for db*/

/* Bufferpool snapshot */
    ret = PyModule_AddIntMacro(m, SQLMA_DBASE_BUFFERPOOLS);//   0x00010016 /*22.BufferpoolInf-for a db      */
    ret = PyModule_AddIntMacro(m, SQLMA_BUFFERPOOLS_ALL);//     0x00010017 /*23.BufferpoolInf-AllBufferpools*/

/* Dynamic sql snapshot */
    ret = PyModule_AddIntMacro(m, SQLMA_DYNAMIC_SQL);//         0x00010024 /*36.Dynamic SQL statement info  */

/******************************************************************************/
/* Snapshot output structure type identifiers                                 */
/*                                                                            */
/* (info_type element in the sqlm_xxx structures that are returned in the     */
/* sqlmonss() output buffer.)                                                 */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_DB2_SS);//               '1' /* DB2 info (sqlm_db2)                  */
    ret = PyModule_AddIntMacro(m, SQLM_FCM_SS);//               'E' /* DB2 FCM info (sqlm_fcm)              */
    ret = PyModule_AddIntMacro(m, SQLM_NODE_SS);//              'G' /* DB2 FCM Node info (sqlm_fcm_node)    */
    ret = PyModule_AddIntMacro(m, SQLM_APPLINFO_SS);//          '4' /* Summary appl info (sqlm_applinfo)    */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_APPLINFO_SS);//      'A' /* DCS appl info (sqlm_dcs_applinfo)    */
    ret = PyModule_AddIntMacro(m, SQLM_DBASE_SS);//             '2' /* DB info (sqlm_dbase)                 */
    ret = PyModule_AddIntMacro(m, SQLM_TABLE_HEADER_SS);//      '5' /* DB table info (sqlm_table_header)    */
    ret = PyModule_AddIntMacro(m, SQLM_TABLE_SS);//             '6' /* Table info (sqlm_table)              */
    ret = PyModule_AddIntMacro(m, SQLM_DBASE_LOCK_SS);//        '7' /* DB lock info (sqlm_dbase_lock)       */
    ret = PyModule_AddIntMacro(m, SQLM_APPL_LOCK_SS);//         '8' /* Appl lock info (sqlm_appl_lock)      */
    ret = PyModule_AddIntMacro(m, SQLM_LOCK_SS);//              '9' /* Lock info (sqlm_lock)                */
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_HEADER_SS);// 'B' /* DB tspaces (sqlm_tablespace_header)  */
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_SS);//        'C' /* Tablespace info (sqlm_tablespace)    */
    ret = PyModule_AddIntMacro(m, SQLM_APPL_SS);//              '3' /* Appl info (sqlm_appl)                */
    ret = PyModule_AddIntMacro(m, SQLM_DBASE_ROLLFWD_SS);//     'H' /* Rollfwd info  (sqlm_rollfwd_info)    */
    ret = PyModule_AddIntMacro(m, SQLM_DBASE_ROLLFWD_TS_SS);//  'I' /* Rollfwd tablespace information
                                                                    /* (sqlm_rollfwd_ts_info)               */
    ret = PyModule_AddIntMacro(m, SQLM_BUFFERPOOL_SS);//        'J' /* Bufferpool info (sqlm_bufferpool)    */
    ret = PyModule_AddIntMacro(m, SQLM_LOCK_WAIT_SS);//         'K' /* Lock wait info (sqlm_lock_wait)      */
    ret = PyModule_AddIntMacro(m, SQLM_STMT_SS);//              'L' /* Statement info (sqlm_stmt)           */
    ret = PyModule_AddIntMacro(m, SQLM_SUBSECTION_SS);//        'M' /* Subsection info (sqlm_subsection)    */
    ret = PyModule_AddIntMacro(m, SQLM_AGENT_SS);//             'N' /* Agent info (sqlm_agent)              */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_APPL_SS);//          'O' /* DCS appl info (sqlm_dcs_appl)        */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_APPLID_SS);//        'P' /* DCS appl ident.(sqlm_dcs_applid_info)*/
    ret = PyModule_AddIntMacro(m, SQLM_DCS_APPL_STATS_SS);//    'Q' /* DCS appl stats.(sqlm_dcs_appl_snap_stats)*/
    ret = PyModule_AddIntMacro(m, SQLM_APPL_XID_SS);//          'R' /* 2PC transaction ID (sqlm_appl_xid)   */
    ret = PyModule_AddIntMacro(m, SQLM_TPMON_INFO_SS);//        'S' /* 3-tier client info (sqlm_tpmon_info) */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_STMT_SS);//          'T' /* DCS statement info (sqlm_dcs_stmt)   */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_DBASE_SS);//         'U' /* DCS database info (sqlm_dcs_dbase)   */
    ret = PyModule_AddIntMacro(m, SQLM_COLLECTED_SS);//         'V' /* Collected info    (sqlm_collected)
                                                                    /* Used as input to the                 */
                                                                    /* db2ConvToOldMonFormat api            */
    ret = PyModule_AddIntMacro(m, SQLM_DBASE_REMOTE_SS);//      'W' /* Remote datasource access info        */
    ret = PyModule_AddIntMacro(m, SQLM_APPL_REMOTE_SS);//       'X' /* Remote access info by application    */

/******************************************************************************/
/* stream type ids                                                            */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_STREAM_SNAPSHOT);// 1
    ret = PyModule_AddIntMacro(m, SQLM_STREAM_EVMON);//    2

/******************************************************************************/
/* size constants                                                             */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_APPLID_SZ);//        64          /* size of the application id V9+   */
    ret = PyModule_AddIntMacro(m, SQLM_APPLID_SZ_V8);//     32          /* size of the V8 and below app id  */
    ret = PyModule_AddIntMacro(m, SQLM_SEQ_SZ);//            5          /* sequence number size             */
    ret = PyModule_AddIntMacro(m, SQLM_SEQ_SZ_V8);//         4          /* seq num size for V8 and below    */
    ret = PyModule_AddIntMacro(m, SQLM_SH_IDENT_SZ);//       8          /* Small identifier size            */
    ret = PyModule_AddIntMacro(m, SQLM_IDENT_SZ);//         20          /* General identifier size          */
    ret = PyModule_AddIntMacro(m, SQLM_LG_IDENT_SZ);//      32          /* Long identifier size             */
    ret = PyModule_AddIntMacro(m, SQLM_OBJECT_SZ );//      128          /* object size in sqlma structure   */
    ret = PyModule_AddIntMacro(m, SQLM_DBPATH_SZ );//      256          /* Database Path size               */
    ret = PyModule_AddIntMacro(m, SQLM_COMM_ADDR_SZ);//     64          /* Communication address size (V9+) */
    ret = PyModule_AddIntMacro(m, SQLM_COMM_ADDR_SZ_V8);//  32          /* Communication address size (V8)  */
    ret = PyModule_AddIntMacro(m, SQLM_SERVERNAME_SZ);//   128          /* DJ server_name                   */
    ret = PyModule_AddIntMacro(m, SQLM_MESSAGE_SZ);//      128          /* The message in the WTT control   */
    ret = PyModule_AddIntMacro(m, SQLM_STORAGE_PATH_SZ);// 190          /* Storage group path size          */
    ret = PyModule_AddIntMacro(m, SQLM_OLD_PACKAGE_NAME_SZ);//    20    /* Package name size in V8 and prev */

/******************************************************************************/
/* Information group state switches (sqlmon and sqlmonss functions)           */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_OFF);//    0              /* Turn monitoring group OFF               */
    ret = PyModule_AddIntMacro(m, SQLM_ON);//     1              /* Turn monitoring group ON                */
    ret = PyModule_AddIntMacro(m, SQLM_HOLD);//   2              /* leave monitoring group in current state */

/******************************************************************************/
/* flag constant for sqlmrset()                                               */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_UDB_DBASE);// 0
    ret = PyModule_AddIntMacro(m, SQLM_UDB_ALL);// 1
    ret = PyModule_AddIntMacro(m, SQLM_DCS_DBASE);// 2
    ret = PyModule_AddIntMacro(m, SQLM_DCS_ALL);// 3
    ret = PyModule_AddIntMacro(m, SQLM_APM);// 4

/******************************************************************************/
/* Monitor switches                                                           */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_UOW_SW );//         0           /* Unit of Work information          */
    ret = PyModule_AddIntMacro(m, SQLM_STATEMENT_SW);//    1           /* Statement information             */
    ret = PyModule_AddIntMacro(m, SQLM_TABLE_SW);//        2           /* Table information                 */
    ret = PyModule_AddIntMacro(m, SQLM_BUFFER_POOL_SW);//  3           /* Buffer Pool information           */
    ret = PyModule_AddIntMacro(m, SQLM_LOCK_SW);//         4           /* Lock information                  */
    ret = PyModule_AddIntMacro(m, SQLM_SORT_SW);//         5           /* Sort information                  */
    ret = PyModule_AddIntMacro(m, SQLM_TIMESTAMP_SW);//    6           /* Timestamp information             */

    ret = PyModule_AddIntMacro(m, SQLM_NUM_GROUPS);//      7           /* number of monitor switches        */
    ret = PyModule_AddIntMacro(m, SQLM_NUM_GROUPS_PREV8);// 6          /* number of monitor switches        */

/******************************************************************************/
/* Statement Types (stmt_type)                                                */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_STATIC);//            1         /* Static statement                  */
    ret = PyModule_AddIntMacro(m, SQLM_DYNAMIC);//           2         /* Dynamic statement                 */
    ret = PyModule_AddIntMacro(m, SQLM_NON_STMT);//          3         /* Operation other than an SQL stmt  */
    ret = PyModule_AddIntMacro(m, SQLM_STMT_TYPE_UNKNOWN);// 4         /* Unknown statement type            */

/******************************************************************************/
/* Statement Operation Types (stmt_operation)                                 */
/******************************************************************************/
/* SQL operations */
    ret = PyModule_AddIntMacro(m, SQLM_PREPARE);//            1        /* SQL Prepare                       */
    ret = PyModule_AddIntMacro(m, SQLM_EXECUTE);//            2        /* SQL Execute                       */
    ret = PyModule_AddIntMacro(m, SQLM_EXECUTE_IMMEDIATE);//  3        /* SQL Execute Immediate             */
    ret = PyModule_AddIntMacro(m, SQLM_OPEN);//               4        /* SQL Open                          */
    ret = PyModule_AddIntMacro(m, SQLM_FETCH);//              5        /* SQL Fetch                         */
    ret = PyModule_AddIntMacro(m, SQLM_CLOSE);//              6        /* SQL Close                         */
    ret = PyModule_AddIntMacro(m, SQLM_DESCRIBE);//           7        /* SQL Describe                      */
    ret = PyModule_AddIntMacro(m, SQLM_STATIC_COMMIT);//      8        /* SQL Static Commit                 */
    ret = PyModule_AddIntMacro(m, SQLM_STATIC_ROLLBACK);//    9        /* SQL Static Rollback               */
    ret = PyModule_AddIntMacro(m, SQLM_FREE_LOCATOR);//      10        /* SQL Free Locator                  */
    ret = PyModule_AddIntMacro(m, SQLM_PREP_COMMIT);//       11        /* Prepare to commit (2-phase commit)*/
    ret = PyModule_AddIntMacro(m, SQLM_CALL);//              12        /* Call a stored procedure           */
    ret = PyModule_AddIntMacro(m, SQLM_SELECT);//            15        /* SELECT statement                  */
    ret = PyModule_AddIntMacro(m, SQLM_PREP_OPEN);//         16        /* Prep. and open (DB2 Connect only) */
    ret = PyModule_AddIntMacro(m, SQLM_PREP_EXEC);//         17        /* Prep. and execute (DB2 Connect)   */
    ret = PyModule_AddIntMacro(m, SQLM_COMPILE);//           18        /* Compile (DB2 Connect only)        */
    ret = PyModule_AddIntMacro(m, SQLM_SET);//               19        /* SET statement                     */

/* non-SQL operations */
    ret = PyModule_AddIntMacro(m, SQLM_RUNSTATS);//          20        /* Runstats                          */
    ret = PyModule_AddIntMacro(m, SQLM_REORG);//             21        /* Reorg                             */
    ret = PyModule_AddIntMacro(m, SQLM_REBIND);//            22        /* Rebind package                    */
    ret = PyModule_AddIntMacro(m, SQLM_REDIST);//            23        /* Redistribute                      */
    ret = PyModule_AddIntMacro(m, SQLM_GETTA);//             24        /* Get Table Authorization           */
    ret = PyModule_AddIntMacro(m, SQLM_GETAA);//             25        /* Get Administrative Authorization  */
    ret = PyModule_AddIntMacro(m, SQLM_GETNEXTCHUNK);//      26        /* DRDA Get Next Chunk command       */
    ret = PyModule_AddIntMacro(m, SQLM_DRPPKG);//            27        /* Drop Package                      */

/******************************************************************************/
/* Table Types (table_type)                                                   */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_USER_TABLE);//      1           /* User table                        */
    ret = PyModule_AddIntMacro(m, SQLM_DROPPED_TABLE);//   2           /* Dropped user table                */
    ret = PyModule_AddIntMacro(m, SQLM_TEMP_TABLE);//      3           /* Temporary table                   */
    ret = PyModule_AddIntMacro(m, SQLM_CATALOG_TABLE);//   4           /* System Catalog table              */
    ret = PyModule_AddIntMacro(m, SQLM_REORG_TABLE);//     5           /* Reorg table                       */
#ifndef SQLM_SYNOPSIS_TABLE
#define SQLM_SYNOPSIS_TABLE  6
#define SQLM_EXTERNAL_TABLE  7
#endif
    ret = PyModule_AddIntMacro(m, SQLM_SYNOPSIS_TABLE);//  6           /* Synopsis table                    */
    ret = PyModule_AddIntMacro(m, SQLM_EXTERNAL_TABLE);//  7           /* External table                    */

/******************************************************************************/
/* lock modes (lock_mode)                                                     */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_LNON);//  0                  /*  No Lock                             */
    ret = PyModule_AddIntMacro(m, SQLM_LOIS);//  1                  /*  Intention Share Lock                */
    ret = PyModule_AddIntMacro(m, SQLM_LOIX);//  2                  /*  Intention Exclusive Lock            */
    ret = PyModule_AddIntMacro(m, SQLM_LOOS);//  3                  /*  Share Lock                          */
    ret = PyModule_AddIntMacro(m, SQLM_LSIX);//  4                  /*  Share with Intention Exclusive Lock */
    ret = PyModule_AddIntMacro(m, SQLM_LOOX);//  5                  /*  Exclusive Lock                      */
    ret = PyModule_AddIntMacro(m, SQLM_LOIN);//  6                  /*  Intent None (For Dirty Read)        */
    ret = PyModule_AddIntMacro(m, SQLM_LOOZ);//  7                  /*  Super Exclusive Lock                */
    ret = PyModule_AddIntMacro(m, SQLM_LOOU);//  8                  /*  Update Lock                         */
    ret = PyModule_AddIntMacro(m, SQLM_LONS);//  9                  /*  Share Lock (CS/RS)                  */
    ret = PyModule_AddIntMacro(m, SQLM_LONX);// 10                  /*  Next-key Exclusive Lock             */
    ret = PyModule_AddIntMacro(m, SQLM_LOOW);// 11                  /*  Weak Exclusive Lock                 */
    ret = PyModule_AddIntMacro(m, SQLM_LONW);// 12                  /*  Next-key Weak Exclusive Lock        */

/******************************************************************************/
/* subsection status (ss_status)                                              */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_SSEXEC);//             1  /* Subsection executing                    */
    ret = PyModule_AddIntMacro(m, SQLM_SSTQ_WAIT_TO_RCV);//   2  /* Waiting to receive data on a tablequeue */
    ret = PyModule_AddIntMacro(m, SQLM_SSTQ_WAIT_TO_SEND);//  3  /* Waiting to send data on a tablequeue    */
    ret = PyModule_AddIntMacro(m, SQLM_SSCOMPLETED);//        4  /* Subsection execution is completed       */

/******************************************************************************/
/* application status (appl_status)                                           */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_INIT);//                 0            /* Performing initialization  */
    ret = PyModule_AddIntMacro(m, SQLM_CONNECTPEND);//          1            /* connect pending             */
    ret = PyModule_AddIntMacro(m, SQLM_CONNECTED);//            2            /* connect completed           */
    ret = PyModule_AddIntMacro(m, SQLM_UOWEXEC);//              3            /* UOW executing               */
    ret = PyModule_AddIntMacro(m, SQLM_UOWWAIT);//              4            /* UOW waiting                 */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKWAIT);//             5            /* lock wait                   */
    ret = PyModule_AddIntMacro(m, SQLM_COMMIT_ACT);//           6            /* commit active               */
    ret = PyModule_AddIntMacro(m, SQLM_ROLLBACK_ACT);//         7            /* rollback active             */
    ret = PyModule_AddIntMacro(m, SQLM_RECOMP);//               8            /* recompiling a plan          */
    ret = PyModule_AddIntMacro(m, SQLM_COMP);//                 9            /* compiling a SQL statement   */
    ret = PyModule_AddIntMacro(m, SQLM_INTR);//                10            /* request interrupted         */
    ret = PyModule_AddIntMacro(m, SQLM_DISCONNECTPEND);//      11            /* disconnect pending          */
    ret = PyModule_AddIntMacro(m, SQLM_TPREP);//               12            /* Prepared transaction        */
    ret = PyModule_AddIntMacro(m, SQLM_THCOMT);//              13            /* heuristically committed     */
    ret = PyModule_AddIntMacro(m, SQLM_THABRT);//              14            /* heuristically rolled back   */
    ret = PyModule_AddIntMacro(m, SQLM_TEND);//                15            /* Transaction ended           */
    ret = PyModule_AddIntMacro(m, SQLM_CREATE_DB);//           16            /* Creating Database           */
    ret = PyModule_AddIntMacro(m, SQLM_RESTART);//             17            /* Restarting a Database       */
    ret = PyModule_AddIntMacro(m, SQLM_RESTORE);//             18            /* Restoring a Database        */
    ret = PyModule_AddIntMacro(m, SQLM_BACKUP);//              19            /* Performing a Backup         */
    ret = PyModule_AddIntMacro(m, SQLM_LOAD);//                20            /* Performing a fast load      */
    ret = PyModule_AddIntMacro(m, SQLM_UNLOAD);//              21            /* Performing a fast unload    */
    ret = PyModule_AddIntMacro(m, SQLM_IOERROR_WAIT);//        22            /* Wait to disable tablespace  */
    ret = PyModule_AddIntMacro(m, SQLM_QUIESCE_TABLESPACE);//  23            /* Quiescing a tablespace      */
    ret = PyModule_AddIntMacro(m, SQLM_WAITFOR_REMOTE);//      24            /* Waiting for remote node     */
    ret = PyModule_AddIntMacro(m, SQLM_REMOTE_RQST);//         25            /* Pending results from remote request */
    ret = PyModule_AddIntMacro(m, SQLM_DECOUPLED);//           26            /* App has been decoupled from coord */
    ret = PyModule_AddIntMacro(m, SQLM_ROLLBACK_TO_SAVEPOINT);// 27          /* Rollback to savepoint       */
    ret = PyModule_AddIntMacro(m, SQLM_AUTONOMOUS_WAIT);//     28            /* Autonomous Routine Wait     */
    ret = PyModule_AddIntMacro(m, SQLM_UOWQUEUED);//           29            /* WLM activity is queued      */
#ifndef SQLM_ANONBLOCK_WAIT
#define SQLM_ANONBLOCK_WAIT 30
#endif
    ret = PyModule_AddIntMacro(m, SQLM_ANONBLOCK_WAIT);//      30            /* Anonymous Block Wait        */

/******************************************************************************/
/* DCS application status (dcs_appl_status)                                   */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_DCS_CONNECTPEND_OUTBOUND);//  101   /* connect to host db pending    */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_UOWWAIT_OUTBOUND);//      102   /* gateway waiting for reply
                                                                           /* from host database           */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_UOWWAIT_INBOUND);//       103   /* conn. to host db established  */
                                                                           /* or gateway waiting for request*/

    /******************************************************************************/
    /* DCS transmission chain groupings (num_transmissions_group)                 */
    /******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_DCS_TRANS_GROUP_2);//         1     /* 2 transmissions               */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_TRANS_GROUP_3TO7);//      2     /* 3-7 transmissions             */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_TRANS_GROUP_8TO15);//     3     /* 8-15 transmissions            */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_TRANS_GROUP_16TO64);//    4     /* 16-64 transmissions           */
    ret = PyModule_AddIntMacro(m, SQLM_DCS_TRANS_GROUP_GT64);//      5     /* Greater than 64 transmissions */

/******************************************************************************/
/* Concentrator agent statuses                                                */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_AGENT_ASSOCIATED);//            1   /* agent associated with appl    */
ret = PyModule_AddIntMacro(m, SQLM_AGENT_NOT_ASSOCIATED);//        2   /* agent not assoc with appl     */

/******************************************************************************/
/* database status (db_status)                                                */
/******************************************************************************/

ret = PyModule_AddIntMacro(m, SQLM_DB_ACTIVE);//          0              /* Database is active          */
ret = PyModule_AddIntMacro(m, SQLM_DB_QUIESCE_PEND);//    1              /* Quiesce is pending for DB   */
ret = PyModule_AddIntMacro(m, SQLM_DB_QUIESCED);//        2              /* Database has been quiesced  */
ret = PyModule_AddIntMacro(m, SQLM_DB_ROLLFWD);//         3              /* DB in Database rollforward  */
ret = PyModule_AddIntMacro(m, SQLM_DB_ACTIVE_STANDBY);//  4              /* Standby with read           */
ret = PyModule_AddIntMacro(m, SQLM_DB_STANDBY);//         5              /* Standby without read        */

/******************************************************************************/
/* rollforward types (rf_type)                                                */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_ROLLFWD_TYP_DB);//        0  /* Database rollforward                */
ret = PyModule_AddIntMacro(m, SQLM_ROLLFWD_TYP_TSPACE);//    1  /* DB tablespace (on-line) rollforward */
ret = PyModule_AddIntMacro(m, SQLM_NO_ROLLFWD);//            2  /* No rollforward in progress          */

/******************************************************************************/
/* Rollforward status (rf_status)                                             */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_ROLLFWD_STATUS_REDO);//     0  /* REDO phase in progress */
ret = PyModule_AddIntMacro(m, SQLM_ROLLFWD_STATUS_UNDO);//     1  /* UNDO phase in progress */
ret = PyModule_AddIntMacro(m, SQLM_ROLLFWD_STATUS_SUCCESS);//  2  /* Successfuly completed on this node */
ret = PyModule_AddIntMacro(m, SQLM_ROLLFWD_STATUS_ERROR);//    3  /* Error occurred on this node */
ret = PyModule_AddIntMacro(m, SQLM_ROLLFWD_STATUS_USR_INTR);// 4  /* User intervention required */

/******************************************************************************/
/* tablespace types                                                           */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_TYP_DMS);//    0
ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_TYP_SMS);//    1

/******************************************************************************/
/* storage path states                                                        */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_DB_STORAGE_PATH_STATE_NOTINUSE);//    0
ret = PyModule_AddIntMacro(m, SQLM_DB_STORAGE_PATH_STATE_INUSE);//       1
ret = PyModule_AddIntMacro(m, SQLM_DB_STORAGE_PATH_STATE_DROPPENDING);// 2

/******************************************************************************/
/* tablespace content type                                                    */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_CONTENT_ANY);//     0
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_CONTENT_LONG);//    1
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_CONTENT_LARGE);//   1      /* Long renamed to Large in v9 */
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_CONTENT_SYSTEMP);// 2
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_CONTENT_USRTEMP);// 3

/******************************************************************************/
/* tablespace file system caching settings                                    */
/******************************************************************************/
#ifndef SQLM_TABLESPACE_FSCACHING_ON
#define SQLM_TABLESPACE_FSCACHING_ON      0
#define SQLM_TABLESPACE_FSCACHING_OFF     1
#define SQLM_TABLESPACE_FSCACHING_DEFAULT 2
#endif
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_FSCACHING_ON);//      0
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_FSCACHING_OFF);//     1
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_FSCACHING_DEFAULT);// 2

/******************************************************************************/
/*  reorg table defines                                                       */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_REORG_STARTED);//     1
    ret = PyModule_AddIntMacro(m, SQLM_REORG_PAUSED);//      2
    ret = PyModule_AddIntMacro(m, SQLM_REORG_STOPPED);//     3
    ret = PyModule_AddIntMacro(m, SQLM_REORG_COMPLETED);//   4
    ret = PyModule_AddIntMacro(m, SQLM_REORG_TRUNCATE);//    5

    ret = PyModule_AddIntMacro(m, SQLM_REORG_SORT);//           1
    ret = PyModule_AddIntMacro(m, SQLM_REORG_BUILD);//          2
    ret = PyModule_AddIntMacro(m, SQLM_REORG_REPLACE);//        3
    ret = PyModule_AddIntMacro(m, SQLM_REORG_INDEX_RECREATE);// 4
    ret = PyModule_AddIntMacro(m, SQLM_REORG_DICT_SAMPLE);//    5

#ifndef SQLM_REORG_CONSOLIDATE_SPARSE_BLOCKS
#define SQLM_REORG_CONSOLIDATE_SPARSE_BLOCKS   9
#endif
    ret = PyModule_AddIntMacro(m, SQLM_REORG_CONSOLIDATE_SPARSE_BLOCKS);// 9
    ret = PyModule_AddIntMacro(m, SQLM_REORG_SCAN);// 10
    ret = PyModule_AddIntMacro(m, SQLM_REORG_DRAIN);// 11
    ret = PyModule_AddIntMacro(m, SQLM_REORG_RELEASE);// 12

    ret = PyModule_AddIntMacro(m, SQLM_REORG_SUCCESS);//   0
    ret = PyModule_AddIntMacro(m, SQLM_REORG_FAIL);//     -1

/******************************************************************************/
/* rebalancer modes                                                           */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_NO_REBAL);//             0
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_FWD_REBAL);//            1
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_REV_REBAL);//            2
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_FWD_REBAL_OF_2PASS);//   3
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_REV_REBAL_OF_2PASS);//   4

/******************************************************************************/
/* Memory Heaps                                                               */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_APPLICATION);//    1      /* Application Heap                   */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_DATABASE);//       2      /* Database Heap                      */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_APPL_CONTROL);//   3      /* Application Control Heap (pre-v95) */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_LOCK_MGR);//       4      /* Lock Manager Heap                  */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_UTILITY);//        5      /* Backup/Restore/Util Heap           */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_STATISTICS);//     6      /* Statistics Heap                    */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_PACKAGE_CACHE);//  7      /* Package Cache Heap                 */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_CAT_CACHE);//      8      /* Catalog Cache Heap                 */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_DFM);//            9      /* DFM Heap                           */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_QUERY);//         10      /* Query Heap                         */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_MONITOR);//       11      /* Database Monitor Heap              */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_STATEMENT);//     12      /* Statement Heap                     */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_FCMBP);//         13      /* FCMBP Heap                         */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_IMPORT_POOL);//   14      /* Import Pool                        */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_OTHER);//         15      /* Other Memory                       */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_BP);//            16      /* Buffer Pool heap                   */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_APP_GROUP);//     17      /* Application Group Shared (pre-v95) */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_SHARED_SORT);//   18      /* Sort Shared Heap                   */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_SORT);//          19      /* Sort Heap                          */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_APPL_SHARED);//   20      /* Applications Shared Heap           */
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_MIN);//           SQLM_HEAP_APPLICATION
    ret = PyModule_AddIntMacro(m, SQLM_HEAP_MAX);//           SQLM_HEAP_APPL_SHARED


/* Memory Pool List ID's (for element SQLM_ELM_POOL_LIST_ID)                  */
    ret = PyModule_AddIntMacro(m, SQLM_POOL_LIST_ID_APPLSHR);//         0   /* Shared Appl Memory List      */
    ret = PyModule_AddIntMacro(m, SQLM_POOL_LIST_ID_PRIVAGENT);//       1   /* Private Agent Memory List    */


/******************************************************************************/
/* database manager status  (db2_status)                                      */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_DB2_ACTIVE);//          0             /* DB2 is active               */
    ret = PyModule_AddIntMacro(m, SQLM_DB2_QUIESCE_PEND);//    1             /* Quiesce is pending for DB2  */
    ret = PyModule_AddIntMacro(m, SQLM_DB2_QUIESCED);//        2             /* DB2 has been quiesced       */

/******************************************************************************/
/* UOW completion status (uow_comp_status)                                    */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_UOWCOMMIT);//       1       /* UOW issued a commit                   */
    ret = PyModule_AddIntMacro(m, SQLM_UOWROLLBACK);//     2       /* UOW issued a rollback                 */
    ret = PyModule_AddIntMacro(m, SQLM_UOWDEADLOCK);//     3       /* UOW was rolled back due to a deadlock */
    ret = PyModule_AddIntMacro(m, SQLM_UOWABEND);//        4       /* UOW was rolled back due to an abend   */
    ret = PyModule_AddIntMacro(m, SQLM_APPL_END);//        5       /* application normal termination        */
    ret = PyModule_AddIntMacro(m, SQLM_UOWLOCKTIMEOUT);//  6       /* UOW was rolled back from lock timeout */
    ret = PyModule_AddIntMacro(m, SQLM_UOWUNKNOWN);//      7       /* Returned for flushed events           */

/******************************************************************************/
/* lock attributes (lock_attributes)                                         */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_WAIT_FOR_AVAIL);//  0x00000001  /* wait for availability    */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_ESCALATED);//       0x00000002  /* acquired by escalation   */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_RR_IN_BLOCK);//     0x00000004  /* RR lock "in" block       */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_INSERT);//          0x00000008  /* insert lock              */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_RR);//              0x00000010  /* lock by RR scan          */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_UPDATE_DELETE);//   0x00000020  /* update/delete row lock   */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_ALLOW_NEW);//       0x10000000  /* allow new lock requests  */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_NEW_REQUEST);//     0x20000000  /* a new lock requestor     */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_DELETE_IN_BLOCK);// 0x00000000  /* deleted row "in" block   */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_INDOUBT);//         0x00010000  /* held by indoubt trans    */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKATTR_LOW_PRIORITY);//    0x00000000  /* held by low priority app */

/******************************************************************************/
/* lock release flags (lock_release_flags)                                    */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_LOCKRELFLAGS_SQLCOMPILER);// 0x80000000  /* locks by SQL compiler    */
    ret = PyModule_AddIntMacro(m, SQLM_LOCKRELFLAGS_UNTRACKED);//   0x40000000  /* non-unique, untracked    */

/******************************************************************************/
/* lock object type (lock_object_type)                                        */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_TABLE_LOCK);//            1    /* table lock type                   */
    ret = PyModule_AddIntMacro(m, SQLM_ROW_LOCK);//              2    /* table row lock type               */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNAL_LOCK);//         3    /* Internal lock type                */
    ret = PyModule_AddIntMacro(m, SQLM_TABLESPACE_LOCK);//       4    /* Tablespace lock type              */
    ret = PyModule_AddIntMacro(m, SQLM_EOT_LOCK);//              5    /* end of table lock                 */
    ret = PyModule_AddIntMacro(m, SQLM_KEYVALUE_LOCK);//         6    /* key value lock                    */
    ret = PyModule_AddIntMacro(m, SQLM_SYSBOOT_LOCK);//          7    /* Internal lock on the sysboot table*/
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALP_LOCK);//        8    /* Internal Plan lock                */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALV_LOCK);//        9    /* Internal Variation lock           */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALS_LOCK);//        10   /* Internal Sequence lock            */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALJ_LOCK);//        11   /* Bufferpool lock                   */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALL_LOCK);//        12   /* Internal Long/Lob lock            */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALC_LOCK);//        13   /* Internal Catalog Cache lock       */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALB_LOCK);//        14   /* Internal Online Backup lock       */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALO_LOCK);//        15   /* Internal Object Table lock        */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALT_LOCK);//        16   /* Internal Table Alter lock         */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALQ_LOCK);//        17   /* Internal DMS Sequence lock        */
    ret = PyModule_AddIntMacro(m, SQLM_INPLACE_REORG_LOCK);//    18   /* Inplace reorg lock                */
    ret = PyModule_AddIntMacro(m, SQLM_BLOCK_LOCK);//            19   /* Block lock type                   */
    ret = PyModule_AddIntMacro(m, SQLM_TABLE_PART_LOCK);//       20   /* Table partition lock type         */
    ret = PyModule_AddIntMacro(m, SQLM_AUTORESIZE_LOCK);//       21   /* Autoresize lock type              */
    ret = PyModule_AddIntMacro(m, SQLM_AUTOSTORAGE_LOCK);//      22   /* Automatic storage lock type       */
    ret = PyModule_AddIntMacro(m, SQLM_XML_PATH_LOCK);//         23   /* XML Path lock type                */
    ret = PyModule_AddIntMacro(m, SQLM_INTERNALM_LOCK);//        24   /* Internal Extent Movement lock     */
    ret = PyModule_AddIntMacro(m, SQLM_GLOBAL_DDL_LOCK);//       25   /* Global DDL lock                   */
#ifndef SQLM_INSERT_RANGE_LOCK
#define SQLM_INSERT_RANGE_LOCK        26
#define SQLM_COL_TABLE_SERIALIZE_LOCK 27
#endif
    ret = PyModule_AddIntMacro(m, SQLM_INSERT_RANGE_LOCK);//          26   /* Insert Range lock                 */
    ret = PyModule_AddIntMacro(m, SQLM_COL_TABLE_SERIALIZE_LOCK);//   27   /* Column Organized Table UpdateDelete Serialization */

/******************************************************************************/
/* lock status (lock_status)                                                  */
/******************************************************************************/

    ret = PyModule_AddIntMacro(m, SQLM_LRBGRNT);//      1                     /*  Granted State             */
    ret = PyModule_AddIntMacro(m, SQLM_LRBCONV);//      2                     /*  Converting state          */

/******************************************************************************/
/* client communications protocols (client_protocol)                          */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_PROT_APPC);//         SQL_PROTOCOL_APPC    /* appc                   */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_NETBIOS);//      SQL_PROTOCOL_NETB    /* netbios                */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_APPN);//         SQL_PROTOCOL_APPN    /* appn                   */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_TCPIP);//        SQL_PROTOCOL_TCPIP   /* TCP/IPv4 or 6          */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_TCPIP4);//       SQL_PROTOCOL_TCPIP4  /* TCP/IPv4               */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_TCPIP6);//       SQL_PROTOCOL_TCPIP6  /* TCP/IPv6               */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_CPIC);//         SQL_PROTOCOL_CPIC    /* APPC using CPIC        */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_IPXSPX);//       SQL_PROTOCOL_IPXSPX  /* ipx/spx                */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_LOCAL);//        SQL_PROTOCOL_LOCAL   /* local client           */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_NPIPE);//        SQL_PROTOCOL_NPIPE   /* Named pipe             */

#ifndef SQLM_PROT_SOCKS4
#define SQLM_PROT_SOCKS4 SQL_PROTOCOL_SOCKS4
#define SQLM_PROT_SSL    SQL_PROTOCOL_SSL
#define SQLM_PROT_SSL4   SQL_PROTOCOL_SSL4
#define SQLM_PROT_SSL6   SQL_PROTOCOL_SSL6
#endif
    ret = PyModule_AddIntMacro(m, SQLM_PROT_SOCKS4);//       SQL_PROTOCOL_SOCKS4  /* TCP/IPv4 using SOCKS   */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_SSL);//          SQL_PROTOCOL_SSL     /* TCP/IP using SSL       */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_SSL4);//         SQL_PROTOCOL_SSL4    /* TCP/IPv4 using SSL     */
    ret = PyModule_AddIntMacro(m, SQLM_PROT_SSL6);//         SQL_PROTOCOL_SSL6    /* TCP/IPv6 using SSL     */


/******************************************************************************/
/* Operating Systems (client_platform and server_platform)                    */
/******************************************************************************/
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_UNKNOWN);//         0         /* Unknown platform           */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_OS2);//             1         /* OS/2                       */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_DOS);//             2         /* DOS                        */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_WINDOWS);//         3         /* Windows                    */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_AIX);//             4         /* AIX                        */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_NT);//              5         /* NT                         */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_HP);//              6         /* HP                         */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_SUN);//             7         /* Sun                        */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_MVS_DRDA);//        8         /* MVS (client via DRDA)      */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_AS400_DRDA);//      9         /* AS400 (client via DRDA)    */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_VM_DRDA);//        10         /* VM (client via DRDA)       */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_VSE_DRDA);//       11         /* VSE (client via DRDA)      */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_UNKNOWN_DRDA);//   12         /* Unknown DRDA Client        */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_SNI);//            13         /* Siemens Nixdorf            */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_MAC);//            14         /* Macintosh Client           */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_WINDOWS95);//      15         /* Windows 95                 */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_SCO);//            16         /* SCO                        */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_SGI);//            17         /* Silicon Graphic            */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUX);//          18         /* Linux                      */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_DYNIX);//          19         /* DYNIX/ptx                  */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_AIX64);//          20         /* AIX 64 bit                 */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_SUN64);//          21         /* Sun 64 bit                 */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_HP64);//           22         /* HP 64 bit                  */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_NT64);//           23         /* NT 64 bit                  */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUX390);//       24         /* Linux for S/390            */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUXZ64);//       25         /* Linux for z900             */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUXIA64);//      26         /* Linux for IA64             */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUXPPC);//       27         /* Linux for PPC              */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUXPPC64);//     28         /* Linux for PPC64            */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_OS390);//          29         /* OS/390 Tools (CC, DW)      */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUXX8664);//     30         /* Linux for x86-64           */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_HPIA);//           31         /* HP-UX Itanium 32bit        */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_HPIA64);//         32         /* HP-UX Itanium 64bit        */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_SUNX86);//         33         /* Sun for x86-64             */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_SUNX8664);//       34         /* Sun for x86-64 64bit       */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_DARWIN);//         35         /* Mac OS X 32bit             */
	ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_DARWIN64);//       36         /* Mac OS X 64bit             */
#ifndef SQLM_PLATFORM_LINUXPPC64LE
#define SQLM_PLATFORM_LINUXPPC64LE 37
#define SQLM_PLATFORM_INSPURKUXI64 SQLM_PLATFORM_LINUXIA64
#endif
    ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_LINUXPPC64LE);//   37         /* Linux for PPC64 LE         */

/* IMPORTANT NOTE: When adding a new platform above, please notify the        */
/*                 DRDA team to update the table srvclsnms in file            */
/*                 sqljspconvars.h with a new entry for that platform!!!      */

    ret = PyModule_AddIntMacro(m, SQLM_PLATFORM_INSPURKUXI64);//   SQLM_PLATFORM_LINUXIA64  /* Inspur K-UX  */

/******************************************************************************/
/* Operating System Application Priority Type (appl_priority_type)            */
/******************************************************************************/
	ret = PyModule_AddIntMacro(m, SQLM_FIXED_PRIORITY);//    1         /* Remains unchanged over time       */
	ret = PyModule_AddIntMacro(m, SQLM_DYNAMIC_PRIORITY);//  2         /* Recalculated by OS based on usage */

/******************************************************************************/
/* Isolation levels                                                           */
/******************************************************************************/
	ret = PyModule_AddIntMacro(m, SQLM_ISOLATION_LEVEL_NONE);// 0    /* no isolation level specified        */
	ret = PyModule_AddIntMacro(m, SQLM_ISOLATION_LEVEL_UR);//   1    /* uncommited read                     */
	ret = PyModule_AddIntMacro(m, SQLM_ISOLATION_LEVEL_CS);//   2    /* cursor stability                    */
	ret = PyModule_AddIntMacro(m, SQLM_ISOLATION_LEVEL_RS);//   3    /* read stability                      */
	ret = PyModule_AddIntMacro(m, SQLM_ISOLATION_LEVEL_RR);//   4    /* repeatable read                     */

/******************************************************************************/
/* Event Monitor Record Type Identifiers  (sqlm_event_rec_header.type)        */
/*                                                                            */
/* Used to read the records in a trace produced by an Event Monitor           */
/******************************************************************************/
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_DB);//               1  /* Database Event                      */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_CONN);//             2  /* Connection Event                    */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_TABLE);//            3  /* Table Event                         */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_STMT);//             4  /* Statement Event                     */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_STMTTEXT);//         5  /* Dynamic Statement Text (OBSOLETE)   */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_XACT);//             6  /* Transaction Event                   */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_DEADLOCK);//         7  /* Deadlock Event                      */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_DLCONN);//           8  /* Deadlock Connection Event           */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_TABLESPACE);//       9  /* Tablespace Event                    */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_DBHEADER);//        10  /* Database Header Event               */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_START);//           11  /* Event monitor start Event           */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_CONNHEADER);//      12  /* Connection Header Event             */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_OVERFLOW);//        13  /* Overflow Event                      */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_BUFFERPOOL);//      14  /* Bufferpool Event                    */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_SUBSECTION);//      15  /* Subsection Event (MPP systems)      */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_LOG_HEADER);//      16  /* Log header event                    */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_DBMEMUSE);//        17  /* Mem Pool Infor for DB Event         */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_CONNMEMUSE);//      18  /* Mem Pool Infor for CONN Event       */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_STMT_HISTORY);//    19  /* Statement history event             */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_DATA_VALUE);//      20  /* Statement history data value        */
	ret = PyModule_AddIntMacro(m, SQLM_EVENT_MAX);//             20  /* Must be set to the largest value in */
																	 /* the list                            */

/******************************************************************************/
/* Event Monitor Byte Order Identifiers (byte_order)                          */
/******************************************************************************/
	ret = PyModule_AddIntMacro(m, SQLM_LITTLE_ENDIAN);//      0         /* Little endian server             */
	ret = PyModule_AddIntMacro(m, SQLM_BIG_ENDIAN);//        -1         /* Big endian server                */

/******************************************************************************/
/* Database Monitor Error Constants (sqlcode)                                 */
/******************************************************************************/
    ret = PyModule_AddIntMacro(m, SQLM_RC_INV_PTR);//         -1601 /* Parameter is a NULL pointer          */
    ret = PyModule_AddIntMacro(m, SQLM_RC_INV_OBJ_TYPE);//    -1602 /* invalid obj_type in sqlma struct     */
    ret = PyModule_AddIntMacro(m, SQLM_RC_NOT_SPECIFIED);//   -1603 /* dbname/appl_id not specified in sqlma*/
    ret = PyModule_AddIntMacro(m, SQLM_RC_NOT_NULL_TERM);//   -1604 /* dbname/appl_id not NULL terminated   */
    ret = PyModule_AddIntMacro(m, SQLM_RC_DBNOACT);//          1605 /* database is not active               */
    ret = PyModule_AddIntMacro(m, SQLM_RC_BUFFER_FULL);//      1606 /* DBMON buffer area is full            */
    ret = PyModule_AddIntMacro(m, SQLM_RC_NOMEM);//           -1607 /* not enough working memory for DBMON  */
    ret = PyModule_AddIntMacro(m, SQLM_RC_DUPLICATE_DB);//     1608 /* duplicate database aliases           */
    ret = PyModule_AddIntMacro(m, SQLM_RC_REMOTE_DB);//       -1609 /* cannot monitor remote databases      */
    ret = PyModule_AddIntMacro(m, SQLM_RC_INV_VALUE);//       -1610 /* invalid value for input parameter    */
    ret = PyModule_AddIntMacro(m, SQLM_RC_NO_DATA);//          1611 /* No data returned by Database Monitor */
    ret = PyModule_AddIntMacro(m, SQLM_RC_TOO_MANY_OBJECTS);// -1623/* Too many objects for this request.   */
    ret = PyModule_AddIntMacro(m, SQLM_RC_MULTIPLE_NODES);//  -1624 /* Databases in a sqlmonsz or sqlmonss
                                                                    /* call reside at different nodes.      */
    ret = PyModule_AddIntMacro(m, SQLM_RC_MEMORY_ERROR);//      -83 /* Memory allocation error.             */

/******************************************************************************/
/* FCM Connection Status (connection_status)                                  */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_FCM_CONNECT_INACTIVE);//    0         /* No current connection       */
ret = PyModule_AddIntMacro(m, SQLM_FCM_CONNECT_ACTIVE);//      1         /* Connection is active        */
ret = PyModule_AddIntMacro(m, SQLM_FCM_CONNECT_CONGESTED);//   2         /* Connection is congested     */

/******************************************************************************/
/* Database location relative to snapshot application (db_location)           */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_LOCAL);//                   1         /* Same node as snapshot       */
ret = PyModule_AddIntMacro(m, SQLM_REMOTE);//                  2         /* DB is on a different node   */

/******************************************************************************/
/* Node location definitions                                                  */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_CURRENT_NODE);// -1
ret = PyModule_AddIntMacro(m, SQLM_ALL_NODES);//    -2

/******************************************************************************/
/* Log space usage definitions                                                */
/******************************************************************************/
ret = PyModule_AddObject(m, "SQLM_LOGSPACE_INFINITE", PyLong_FromLongLong(SQLM_LOGSPACE_INFINITE));// (sqluint64)-1   /* Database is configured with
                                                  /*infinite active log space   */

/******************************************************************************/
/* Log file number definitions                                                */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_LOGFILE_NUM_UNKNOWN);// (sqluint32)-1 /* Log file number is unknown  */

/******************************************************************************/
/* Utility types associated with SQLM_ELM_UTILITY_TYPE                        */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_REBALANCE);//              0
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_BACKUP);//                 1
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_RUNSTATS);//               2
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_REORG);//                  3
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_RESTORE);//                4
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_CRASH_RECOVERY);//         5
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_ROLLFORWARD_RECOVERY);//   6
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_LOAD);//                   7
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_RESTART_RECREATE_INDEX);// 8
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_REDISTRIBUTE);//           9
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_ASYNC_INDEX_CLEANUP);//   10
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_MDC_ROLLOUT_CLEANUP);//   11
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_GROUP_CRASH_RECOVERY);//  12
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_MEMBER_CRASH_RECOVERY);// 13
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_ASYNC_PART_DETACH);//     14
#ifndef SQLM_UTILITY_ADC
#define SQLM_UTILITY_ADC 15
#endif
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_ADC);//                   15

/******************************************************************************/
/* Utility priority of value 0                                                */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_UNTHROTTLED);//       0

/******************************************************************************/
/* Progress information work metric values                                    */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_NOT_SUPPORT);//   0
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_BYTES);//         1
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_EXTENTS);//       2
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_ROWS);//          3
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_PAGES);//         4
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_INDEXES);//       5
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_TABLES);//        6
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_INDEX_PARTS);//   7
ret = PyModule_AddIntMacro(m, SQLM_WORK_METRIC_NONPART_INDEXES);//   8

/******************************************************************************/
/* Utility states associated with SQLM_ELM_UTILITY_STATE                      */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_STATE_EXECUTE);//     0
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_STATE_WAIT);//        1
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_STATE_ERROR);//       2
#ifndef SQLM_UTILITY_STATE_SUSPENDED
#define SQLM_UTILITY_STATE_SUSPENDED 3
#endif
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_STATE_SUSPENDED);//   3

/******************************************************************************/
/* Utility states associated with SQLM_ELM_UTILITY_INVOKER_TYPE               */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_INVOKER_USER);//      0
ret = PyModule_AddIntMacro(m, SQLM_UTILITY_INVOKER_AUTO);//      1

/******************************************************************************/
/* Utility attributes associated with SQLM_ELM_PROGRESS_LIST_ATTR             */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_LIST_ATTR_SERIAL);//      0x1
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_LIST_ATTR_CONCURRENT);//  0x2

/******************************************************************************/
/* Current HADR roles of the database                                         */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_HADR_ROLE_STANDARD);//         0
ret = PyModule_AddIntMacro(m, SQLM_HADR_ROLE_PRIMARY);//          1
ret = PyModule_AddIntMacro(m, SQLM_HADR_ROLE_STANDBY);//          2

/******************************************************************************/
/* State of HADR subsystem                                                    */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_HADR_STATE_DISCONNECTED);//    0
ret = PyModule_AddIntMacro(m, SQLM_HADR_STATE_LOCAL_CATCHUP);//   1
ret = PyModule_AddIntMacro(m, SQLM_HADR_STATE_REM_CATCH_PEND);//  2
ret = PyModule_AddIntMacro(m, SQLM_HADR_STATE_REM_CATCHUP);//     3
ret = PyModule_AddIntMacro(m, SQLM_HADR_STATE_PEER);//            4
ret = PyModule_AddIntMacro(m, SQLM_HADR_STATE_DISCONN_PEER);//    5

/******************************************************************************/
/* HADR synchronization mode                                                  */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_HADR_SYNCMODE_SYNC);//         0
ret = PyModule_AddIntMacro(m, SQLM_HADR_SYNCMODE_NEARSYNC);//     1
ret = PyModule_AddIntMacro(m, SQLM_HADR_SYNCMODE_ASYNC);//        2
ret = PyModule_AddIntMacro(m, SQLM_HADR_SYNCMODE_SUPERASYNC);//   3 

/******************************************************************************/
/* Status of HADR primary-standby connection                                  */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_HADR_CONN_CONNECTED);//        0
ret = PyModule_AddIntMacro(m, SQLM_HADR_CONN_CONGESTED);//        1
ret = PyModule_AddIntMacro(m, SQLM_HADR_CONN_DISCONNECTED);//     2

/******************************************************************************/
/* Snapshot Monitoring defines (db2GetSnapshot, etc) for self-describing      */
/* datastream                                                                 */
/* Used by all versions of snapshot v6 and later.                             */
/******************************************************************************/
/******************************************************************************/
/* Defines for snapshot output stream format                                  */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_STREAM_STATIC_FORMAT);//  0
ret = PyModule_AddIntMacro(m, SQLM_STREAM_DYNAMIC_FORMAT);// 1

/******************************************************************************/
/* This structure can be used for parsing through the self describing snapshot*/
/* data stream. All data in the snapshot and event monitor hiearchy have this */
/* header.                                                                    */
/*                                                                            */
/*         size:         The size (in bytes) of the data stored in the data   */
/*                       element.                                             */
/*                                                                            */
/*         type:         The type of element stored in the data. See the      */
/*                       defines of the form SQLM_TYP_... for values note     */
/*                       that the type HEADER refers to "logical" types,      */
/*                       meaning they do not represent specific data          */
/*                       elements, but rather logical groupings of elements.  */
/*                                                                            */
/*      element:         The element that data holds. See the defines of the  */
/*                       form SQLM_ELM_... for values                         */
/*                                                                            */
/*         data:         The data itself.                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* Snapshot data is returned in a heirarchtical fashion. At the bottom of the */
/* hiearchy, are the individual data elements. Higher up in the hiearchy, are */
/* the logical groupings of data elements. What follows is a description of   */
/* the logical data hiearchy. Shown by element values.                        */
/*                                                                            */
/* SQLM_ELM_COLLECTED - Top level logical data member, contains information   */
/*                      relevant to the entire snapshot, and indicates how    */
/*                      many second tier snapshot logical data elements will  */
/*                      follow.                                               */
/* SQLM_ELM_DB2             - DB2 instance information                        */
/* SQLM_ELM_FCM             - FCM information                                 */
/* SQLM_ELM_FCM_NODE        - FCM node information                            */
/* SQLM_ELM_APPL_INFO       - application identifiern                         */
/* SQLM_ELM_APPL            - application information                         */
/* SQLM_ELM_DCS_APPL_INFO   - dcs application identifier                      */
/* SQLM_ELM_DCS_APPL        - dcs application information                     */
/* SQLM_ELM_DCS_STMT        - dcs statement information                       */
/* SQLM_ELM_AGENT           - agent information                               */
/* SQLM_ELM_LOCK_WAIT       - lock waiting information                        */
/* SQLM_ELM_DCS_DBASE       - dcs database information                        */
/* SQLM_ELM_DBASE           - database information                            */
/* SQLM_ELM_ROLLFORWARD     - database rollforward information                */
/* SQLM_ELM_TABLE_LIST      - database wide table information                 */
/* SQLM_ELM_TABLE           - table information                               */
/* SQLM_ELM_LOCK            - lock information                                */
/* SQLM_ELM_TABLESPACE_LIST - database wide tablespace info                   */
/* SQLM_ELM_TABLESPACE      - tablespace information                          */
/* SQLM_ELM_BUFFERPOOL      - bufferpool information                          */
/* SQLM_ELM_DYNSQL          - dynamic sql statement information               */
/* SQLM_ELM_DYNSQL_LIST     - dynamic sql statement list                      */
/* SQLM_ELM_SWITCHES        - a list of the switch state on the server        */
/* SQLM_ELM_APPL_LOCK_LIST  - a list of application locks                     */
/* SQLM_ELM_DB_LOCK_LIST    - a list of database locks                        */
/* SQLM_ELM_STMT            - statement information                           */
/* SQLM_ELM_SUBSECTION      - subsection information                          */
/* SQLM_ELM_DBASE_REMOTE    - remote datasource information for database      */
/* SQLM_ELM_APPL_REMOTE     - remote datasource information for application   */
/* SQLM_ELM_TABLE_REORG     - table reorg data                                */
/* SQLM_ELM_MEMORY_POOL     - memory pool statistics                          */
/* SQLM_ELM_TABLESPACE_QUIESCER        - List of quiescers for a tablespace   */
/* SQLM_ELM_TABLESPACE_CONTAINER       - List of containers for a TS          */
/* SQLM_ELM_TABLESPACE_RANGE           - List of ranges for TS map            */
/* SQLM_ELM_TABLESPACE_RANGE_CONTAINER - List of containers for range         */
/* SQLM_ELM_TABLESPACE_NODEINFO        - Node unique info for a tablespace    */
/* SQLM_ELM_BUFFERPOOL_NODEINFO        - Node unique info for a bufferpool    */
/*                                                                            */
/* SQLM_ELM_COLLECTED --- DB2 - FCM - FCM_NODE                                */
/*                            +- MEMORY_POOL                                  */
/*                            +- SWITCH_LIST +- UOW_SW                        */
/*                                           +- STATEMENT_SW                  */
/*                                           +- LOCK_SW                       */
/*                                           +- BUFFPOOL_SW                   */
/*                                           +- TABLE_SW                      */
/*                                           +- SORT_SW                       */
/*                                           +- TIMESTAMP_SW                  */
/*                     +- APPL_INFO                                           */
/*                     +- DCS_APPL_INFO                                       */
/*                     +- DCS_APPL -- STMT                                    */
/*                                 +- DCS_APPL_INFO                           */
/*                     +- APPL -- AGENT -- MEMORY_POOL                        */
/*                             +- APPLINFO                                    */
/*                             +- LOCK_WAIT                                   */
/*                             +- STMT -  SUBSECTION - AGENT MEMORY_POOL (MPP)*/
/*                                     +- AGENT --MEMORY_POOL            (SMP)*/
/*                     +- DCS_DBASE                                           */
/*                     +- DBASE -  ROLLFORWARD - TABLESPACE                   */
/*                              +- MEMORY_POOL                                */
/*                     +- TABLE_LIST - TABLE - TABLE_REORG                    */
/*                     +- APPL_LOCK_LIST +-- LOCK                             */
/*                                       +- LOCK_WAIT - LOCK                  */
/*                     +- DB_LOCK_LIST +- LOCK                                */
/*                                     +- LOCK_WAIT - LOCK                    */
/*                                     +- APPL_LOCK_LIST                      */
/*                     +- TABLESPACE_LIST - TABLESPACE                        */
/*                                        +-QUIESCER                          */
/*                                        +-CONTAINER                         */
/*                                        +-RANGE                             */
/*                                        +-RANGE_CONTAINER                   */
/*                                        +-NODEINFO                          */
/*                     +- BUFFERPOOL      --NODEINFO                          */
/*                     +- DYNSQL_LIST - DYNSQL                                */
/*                     +- SWITCH_LIST +- UOW_SW                               */
/*                                    +- STATEMENT_SW                         */
/*                                    +- LOCK_SW                              */
/*                                    +- BUFFPOOL_SW                          */
/*                                    +- TABLE_SW                             */
/*                                    +- SORT_SW                              */
/*                                    +- TIMESTAMP_SW                         */
/*                     +- DBASE_REMOTE                                        */
/*                     +- APPL_REMOTE                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* Event monitor data is returned as a series of records of the following     */
/* types:                                                                     */
/* SQLM_ELM_EVENT_DB         - database event                                 */
/* SQLM_ELM_EVENT_CONN       - connection event                               */
/* SQLM_ELM_EVENT_TABLE      - table event                                    */
/* SQLM_ELM_EVENT_STMT       - statement event                                */
/* SQLM_ELM_EVENT_XACT       - transaction event                              */
/* SQLM_ELM_EVENT_DEADLOCK   - deadlock event                                 */
/* SQLM_ELM_EVENT_DLCONN     - deadlocked connection event                    */
/* SQLM_ELM_EVENT_TABLESPACE - tablespace event                               */
/* SQLM_ELM_EVENT_DBHEADER   - database header event                          */
/* SQLM_ELM_EVENT_START      - event monitor start                            */
/* SQLM_ELM_EVENT_CONNHEADER - connection header event                        */
/* SQLM_ELM_EVENT_OVERFLOW   - overflow event                                 */
/* SQLM_ELM_EVENT_BUFFERPOOL - bufferpool event                               */
/* SQLM_ELM_EVENT_SUBSECTION - subsection event                               */
/* SQLM_ELM_EVENT_LOCK_LIST  - lock list for en_dlock                         */
/* SQLM_ELM_EVENT_CONTROL    - control table                                  */
/* SQLM_ELM_EVENT_LOG_HEADER - log start event                                */
/* SQLM_ELM_EVENT_DETAILED_DLCONN - detailed deadlocked connection event      */
/* SQLM_ELM_EVENT_STMT_HISTORY - part of details dlock with history evmon     */
/* SQLM_ELM_EVENT_DATA_VALUE - paramter values corresponding to stmt history  */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/* Monitor data types (reside in the "type" field of the sqlm_header_data     */
/******************************************************************************/
/*****************Logical data elements****************************************/
    ret = PyModule_AddIntMacro(m, SQLM_TYPE_HEADER);//       1  /* The header monitor types, which
															    /* indicate what type of record is being
																 looked at when encountering an element
																 of this type, in indicates an element
																 composed of multible base data elements  */

    /*****************Base data elements*******************************************/
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_STRING);//      50  /* variable length string                   */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_U8BIT);//       51  /* unsigned 8 bit value                     */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_8BIT);//        52  /* signed 8 bit value                       */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_16BIT);//       53  /* signed 16 bit numeric value              */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_U16BIT);//      54  /* unsigned 16 bit numeric value            */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_32BIT);//       55  /* signed 32 bit numeric value              */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_U32BIT);//      56  /* unsigned 32 bit numeric value            */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_U64BIT);//      57  /* unsigned 64 bit value numeric value      */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_64BIT);//       58  /* signed 64 bit value                      */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_HANDLE);//      59  /* compilation environment blob             */
	ret = PyModule_AddIntMacro(m, SQLM_TYPE_BINARY);//      60  /* binary object                            */
#ifndef SQLM_TYPE_DOUBLE
#define SQLM_TYPE_DOUBLE 61
#endif
    ret = PyModule_AddIntMacro(m, SQLM_TYPE_DOUBLE);//      61  /* 8-byte floating point (only used for     */
                                                                /* event monitor streams)                   */

/******************************************************************************/
/* Monitor data elements (reside in the "element" field of the                */
/* sqlm_header_data                                                           */
/******************************************************************************/
/* The following group of defines relate to logical groupings of snapshot     */
/* information. They do not represent data elements, but rather groups of     */
/* data elements                                                              */
/******************************************************************************/

                                  /* DB2 instance information                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB2);//                                                           1
                                  /* FCM information                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FCM);//                                                           2
                                  /* FCM member number information            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FCM_NODE);//                                                      3
                                  /* application identifiern                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_INFO);//                                                     4
                                  /* application information                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL);//                                                          5
                                  /* dcs application identifier               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DCS_APPL_INFO);//                                                 6
                                  /* dcs application information              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DCS_APPL);//                                                      7
                                  /* dcs statement information                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DCS_STMT);//                                                      8
                                  /* subsection related information           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SUBSECTION);//                                                    9
                                  /* agent information                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT);//                                                        10
                                  /* lock waiting information                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_WAIT);//                                                    11
                                  /* dcs database information                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DCS_DBASE);//                                                    12
                                  /* database information                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DBASE);//                                                        13
                                  /* database rollforward information         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROLLFORWARD);//                                                  14
                                  /* table information                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE);//                                                        15
                                  /* lock information                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK);//                                                         16
                                  /* tablespace information                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE);//                                                   17
                                  /* bufferpool information                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BUFFERPOOL);//                                                   18
                                  /* dynamic sql statement information        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DYNSQL);//                                                       19
                                  /* First element in any data stream         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COLLECTED);//                                                    20
                                  /* List of switches                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SWITCH_LIST);//                                                  21
                                  /* unit of work switch                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_SW);//                                                       22
                                  /* statement switch                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STATEMENT_SW);//                                                 23
                                  /* table switch                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE_SW);//                                                     24
                                  /* bufferpool switch                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BUFFPOOL_SW);//                                                  25
                                  /* lock switch                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_SW);//                                                      26
                                  /* sort switch                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SW);//                                                      27
                                  /* database wide table information          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE_LIST);//                                                   28
                                  /* database wide tablespace information     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_LIST);//                                              29
                                  /* List of dynamic sql statements           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DYNSQL_LIST);//                                                  30
                                  /* List of locks for an application         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_LOCK_LIST);//                                               31
                                  /* List of locks for a db                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_LOCK_LIST);//                                                 32
                                  /* Statement related information            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT);//                                                         33
                                  /* remote data source information by DB     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DBASE_REMOTE);//                                                 34
                                  /* remote data source information by Appl   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_REMOTE);//                                                  35
                                  /* application ID information               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_ID_INFO);//                                                 36
                                  /* transmission level info for a stmt       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_TRANSMISSIONS);//                                           37
                                  /* timestamp switch                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TIMESTAMP_SW);//                                                 38
                                  /* A table reorg                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE_REORG);//                                                  39
                                  /* Memory statistics for a pool             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMORY_POOL);//                                                  40
                                  /* List of quiescers for a tablespace       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_QUIESCER);//                                          41
                                  /* List of containers for a TS              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_CONTAINER);//                                         42
                                  /* List of ranges for TS map                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_RANGE);//                                             43
                                  /* List of containers for range             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_RANGE_CONTAINER);//                                   44
                                  /* Node unique info for a tablespace        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_NODEINFO);//                                          45
                                  /* Health indicator data                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HEALTH_INDICATOR);//                                             46
                                  /* Health indicator data history            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HEALTH_INDICATOR_HIST);//                                        47
                                  /* Node unique info for a bufferpool        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BUFFERPOOL_NODEINFO);//                                          48
                                  /* Utility info                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY);//                                                      49
                                  /* Health indicator collection data         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_OBJ_LIST);//                                                  50
                                  /* Health indicator collection data history */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_OBJ_LIST_HIST);//                                             51
                                  /* Utility progress info                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS);//                                                     52
                                  /* Utility progress info list               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_LIST);//                                                53
                                  /* HADR info                                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR);//                                                         54
                                  /* Detail logging information               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DETAIL_LOG);//                                                   55
                                  /* Runtime Rollback Progress Monitor        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROLLBACK_PROGRESS);//                                            56
                                  /* DB storage group paths                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_STORAGE_GROUP);//                                             57
                                  /* Storage path Info group                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_STO_PATH_INFO);//                                             58
                                  /* List of Memory Pools                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMORY_POOL_LIST);//                                             59
                                  /* This value should equal the largest of   */
                                  /* the logical grouping elements            */
#define SQLM_MAX_LOGICAL_ELEMENT                       SQLM_ELM_MEMORY_POOL_LIST
ret = PyModule_AddIntMacro(m, SQLM_ELM_FCM_MEMBER);//                     60 /*       FCM member number */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FCM_DBPARTITIONNUM);//             61 /* FCM DB Partition number */

/******************************************************************************/
/* The following group of defines relate to logical groupings of event monitor*/
/* information. They do not represent data elements, but rather groups of     */
/* data elements                                                              */
/******************************************************************************/

                                          /* database event                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_DB);//                                                    100
                                          /* connection event                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_CONN);//                                                  101
                                          /* table event                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_TABLE);//                                                 102
                                          /* statement event                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_STMT);//                                                  103
                                          /* transaction event                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_XACT);//                                                  104
                                          /* deadlock event                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_DEADLOCK);//                                              105
                                          /* deadlocked connection event      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_DLCONN);//                                                106
                                          /* tablespace event                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_TABLESPACE);//                                            107
                                          /* database header event            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_DBHEADER);//                                              108
                                          /* event monitor start              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_START);//                                                 109
                                          /* connection header event          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_CONNHEADER);//                                            110
                                          /* overflow event                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_OVERFLOW);//                                              111
                                          /* bufferpool event                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_BUFFERPOOL);//                                            112
                                          /* subsection event                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_SUBSECTION);//                                            113
                                          /* log header event                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_LOG_HEADER);//                                            114
                                          /* lock list for en_dlock           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_CONTROL);//                                               115
                                          /* lock list for en_dlock           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_LOCK_LIST);//                                             116
                                          /* detailed dlconn event            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_DETAILED_DLCONN);//                                       117
                                          /* Mem Pool Infor for CONN Event    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_CONNMEMUSE);//                                            118
                                          /* Mem Pool Infor for DB Event      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_DBMEMUSE);//                                              119
                                          /* Statement history event          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_STMT_HISTORY);//                                          120
                                          /* Parameter values in stmt history */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_DATA_VALUE);//                                            121
                                          /* Activity event                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_ACTIVITY);//                                              122
                                          /* Activity statement event         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_ACTIVITYSTMT);//                                          123
                                          /* Activity statement values event  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_ACTIVITYVALS);//                                          124
                                          /* Service Class Stats event        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_SCSTATS);//                                               125
                                          /* Work Class Stats event           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_WCSTATS);//                                               126
                                          /* Workload Stats event             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_WLSTATS);//                                               127
                                          /* Queue Stats event                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_QSTATS);//                                                128
                                          /* Histogrambin event               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_HISTOGRAMBIN);//                                          129
                                          /* Threshold Violations event       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_THRESHOLDVIOLATIONS);//                                   130
                                          /* Locking event                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_LOCKING);//                                               131
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_ACTIVITYMETRICS);//           132 /* ACTIVITYMETRICS event */

                                  /* For events bigger than 4k (or 1k on      */
                                  /* Windows) this identifies the beginning   */
                                  /* block for the entire event.              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_STARTPIPEBLOCK);//                                        133
                                  /* For events bigger than 4k (or 1k on      */
                                  /* Windows) this identifies a middle block  */
                                  /* for the entire event.                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_MIDPIPEBLOCK);//                                          134
                                  /* For events bigger than 4k (or 1k on      */
                                  /* Windows) this identifies the ending      */
                                  /* block for the entire event.              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_ENDPIPEBLOCK);//                                          135

#ifndef SQLM_ELM_EVENT_SCMETRICS
#define SQLM_ELM_EVENT_SCMETRICS 136
#define SQLM_ELM_EVENT_WLMETRICS 137
#define SQLM_ELM_EVENT_OSMETRICS 138
#define SQLM_ELM_EVENT_SUPERCLASSMETRICS 139
#define SQLM_ELM_EVENT_SUPERCLASSSTATS   140
#endif

#ifndef SQLM_ELM_EVENT_SUPERCLASSMETRICS
#define SQLM_ELM_EVENT_SUPERCLASSMETRICS 139
#define SQLM_ELM_EVENT_SUPERCLASSSTATS   140
#endif

ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_SCMETRICS);//           136 /* Service Class Metrics event */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_WLMETRICS);//           137 /*      Workload Metrics event */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_OSMETRICS);//              138 /* OS Metrics logical group */
                                          /* Service Superclass Metrics event */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_SUPERCLASSMETRICS);//                                     139
                                          /* Service Superclass Stats event   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_SUPERCLASSSTATS);//                                       140


/******************************************************************************/
/* Timestamps are returned as logic data elements with seconds and            */
/* microseconds returned in seperate base elements                            */
/******************************************************************************/

                                  /* Smallest timestamp element               */
ret = PyModule_AddIntMacro(m, SQLM_MIN_TIME_STAMP);//                                  SQLM_ELM_TIME_STAMP

                                  /* Timestamp                                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TIME_STAMP);//                                                  200
                                  /* last appl status change time             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STATUS_CHANGE_TIME);//                                          201
                                  /* Connect start date/time                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_CON_TIME);//                                                 202
                                  /* prev commit or rollback time             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PREV_UOW_STOP_TIME);//                                          203
                                  /* time transaction execution started       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_START_TIME);//                                              204
                                  /* unit-of-work stop time                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_STOP_TIME);//                                               205
                                  /* when received from client at the gateway */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_START);//                                                  206
                                  /* when sent to client from the gateway     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_STOP);//                                                   207
                                  /* Last snapshot reset date and time        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LAST_RESET);//                                                  208
                                  /* DB2START timestamp                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB2START_TIME);//                                               209
                                  /* Time of 1st database connection          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_CONN_TIME);//                                                210
                                  /* Date/Time of Last Backup                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LAST_BACKUP);//                                                 211
                                  /* Time when lock wait entered              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_WAIT_START_TIME);//                                        212
                                  /* Connect start date/time                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_CON_TIME);//                                               213
                                  /* Connect complete date/time               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONN_COMPLETE_TIME);//                                          214
                                  /* Time of last database disconnect         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DISCONN_TIME);//                                                215
                                  /* Table Event Date and Time                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_TIME);//                                                  216
                                  /* Time event started                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_START_TIME);//                                                  217
                                  /* SQL statement operation stop time        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STOP_TIME);//                                                   218
                                  /* Time of Log record currently processed   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RF_TIMESTAMP);//                                                219
                                  /* Time of 1st database connection          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONN_TIME);//                                                   220
                                  /* The time of the first overflow           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FIRST_OVERFLOW_TIME);//                                         221
                                  /* The time of the last overflow            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LAST_OVERFLOW_TIME);//                                          222
                                  /* Time spent on gateway processing         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_EXEC_TIME);//                                                223
                                  /* total user CPU time of application       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_USR_CPU_TIME);//                                          224
                                  /* total application system cpu time        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_SYS_CPU_TIME);//                                          225
                                  /* total user CPU time (sec.microsec)       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SS_USR_CPU_TIME);//                                             226
                                  /* total system CPU time (sec.microsec)     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SS_SYS_CPU_TIME);//                                             227
                                  /* Total user CPU time of appl agents       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_USER_CPU_TIME);//                                               228
                                  /* Total execution time                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_EXEC_TIME);//                                             229
                                  /* Time the switch was set                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SWITCH_SET_TIME);//                                             230
                                  /* Elapsed execution time                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ELAPSED_EXEC_TIME);//                                           231
                                  /* Aggregate response time to queries       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SELECT_TIME);//                                                 232
                                  /* Aggregate response time to inserts       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INSERT_TIME);//                                                 233
                                  /* Aggregate response time to updates       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UPDATE_TIME);//                                                 234
                                  /* Aggregate response time to deletes       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DELETE_TIME);//                                                 235
                                  /* Aggregate response time to create        */
                                  /* nicknames                                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CREATE_NICKNAME_TIME);//                                        236
                                  /* Aggregate response time to passthru      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PASSTHRU_TIME);//                                               237
                                  /* Aggregate response time to stored        */
                                  /* procedures                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STORED_PROC_TIME);//                                            238
                                  /* Aggregate responce time to lock remote   */
                                  /* table                                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_REMOTE_LOCK_TIME);//                                            239
                                  /* High water mark for network time         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NETWORK_TIME_TOP);//                                            240
                                  /* Low water mark for network time          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NETWORK_TIME_BOTTOM);//                                         241
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_REBALANCER_START_TIME);//                            242
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_REBALANCER_RESTART_TIME);//                          243
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_MIN_RECOVERY_TIME);//                                244
                                  /* health indicator timestamp               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_TIMESTAMP);//                                                245
                                  /* Maximum timestamp value                  */
#define SQLM_MAX_TIME_STAMP                                SQLM_ELM_HI_TIMESTAMP


/******************************************************************************/
/* Actual database monitor elements                                           */
/******************************************************************************/
                                  /* GMT time in seconds since Jan.1,1970     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SECONDS);//                                                     300
                                  /* microseconds, range 0 to 999999          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MICROSEC);//                                                    301
                                  /* used for requests based on app-handle    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_ID);//                                                    302
                                  /* Server DB2 Type(defined in sqlutil.h)    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVER_DB2_TYPE);//                                             303
                                  /* product/version on server                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVER_PRDID);//                                                304
                                  /* Config NNAME of server                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVER_NNAME);//                                                305
                                  /* instance name of DB2                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVER_INSTANCE_NAME);//                                        306
                                  /* Number of member sending data            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NODE_NUMBER);//                                                 307
                                  /* Diff. in secs between GMT and local time */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TIME_ZONE_DISP);//                                              308
                                  /* Version of server returning data         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVER_VERSION);//                                              309
                                  /* Application Status                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_STATUS);//                                                 310
                                  /* codepage/CCSID identifier                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CODEPAGE_ID);//                                                 311
                                  /* Statement text                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_TEXT);//                                                   312
                                  /* Application Program Name                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_NAME);//                                                   313
                                  /* Application Id                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_ID);//                                                     314
                                  /* application id sequence number           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SEQUENCE_NO);//                                                 315
                                  /* Authorization Id                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AUTH_ID);//                                                     316
                                  /* (Primary) Authorization Id               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PRIMARY_AUTH_ID);//                                SQLM_ELM_AUTH_ID
                                  /* Config NNAME of client                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_NNAME);//                                                317
                                  /* product/version on client                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_PRDID);//                                                318
                                  /* Input Database Alias                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INPUT_DB_ALIAS);//                                              319
                                  /* Client Database Alias                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_DB_ALIAS);//                                             320
                                  /* Database name                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_NAME);//                                                     321
                                  /* Database Path                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_PATH);//                                                     322
                                  /* Number of agents associated with this    */
                                  /* application                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_ASSOC_AGENTS);//                                            323
                                  /* Coordinating member number               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_NODE_NUM);//                                              324
                                  /* User authorizations                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AUTHORITY_LVL);//                                               325
                                  /* login ID                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EXECUTION_ID);//                                                326
                                  /* DRDA AS Correlation Token                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CORR_TOKEN);//                                                  327
                                  /* Process/thread ID of client appl.        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_PID);//                                                  328
                                  /* Platform of client application           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_PLATFORM);//                                             329
                                  /* Communications protocol of client        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_PROTOCOL);//                                             330
                                  /* Country code of client application       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COUNTRY_CODE);//                                                331
                                  /* Territory code of client application     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TERRITORY_CODE);//                            SQLM_ELM_COUNTRY_CODE
                                  /* Coordinator agent process/thread id      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_AGENT_PID);//                                             332
                                  /* gateway  Database Alias                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_DB_ALIAS);//                                                 333
                                  /* Outb. comm. address                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_COMM_ADDRESS);//                                       334
                                  /* Inbound comm. address                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INBOUND_COMM_ADDRESS);//                                        335
                                  /* Outbound comm. protocol                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_COMM_PROTOCOL);//                                      336
                                  /* DCS Database name                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DCS_DB_NAME);//                                                 337
                                  /* Host Database name                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HOST_DB_NAME);//                                                338
                                  /* Host Product id                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HOST_PRDID);//                                                  339
                                  /* Outbound LUWID                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_APPL_ID);//                                            340
                                  /* Outbound sequence #                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_SEQUENCE_NO);//                                        341
                                  /* Status of DCS application                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DCS_APPL_STATUS);//                                             342
                                  /* Host database Coded Char Set ID          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HOST_CCSID);//                                                  343
                                  /* Switch output state                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTPUT_STATE);//                                                344
                                  /* The number of overflows                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COUNT);//                                                       345
                                  /* # of rows selected                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_SELECTED);//                                               346
                                  /* # of sql stmts attempted                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQL_STMTS);//                                                   347
                                  /* # of Failed SQL stmts                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FAILED_SQL_STMTS);//                                            348
                                  /* # of Commit SQL stmts                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COMMIT_SQL_STMTS);//                                            349
                                  /* # of Rollback SQL stmts                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROLLBACK_SQL_STMTS);//                                          350
                                  /* inbound # of bytes received              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INBOUND_BYTES_RECEIVED);//                                      351
                                  /* outbound # of bytes sent                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_BYTES_SENT);//                                         352
                                  /* outbound # of bytes received             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_BYTES_RECEIVED);//                                     353
                                  /* inbound # of bytes sent                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INBOUND_BYTES_SENT);//                                          354
                                  /* most recent SQL stmt operation           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_OPERATION);//                                              355
                                  /* most recent SQL stmt section number      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SECTION_NUMBER);//                                              356
                                  /* Node on which app waited for lock        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_NODE);//                                                   357
                                  /* package creator                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CREATOR);//                                                     358
                                  /* package name                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PACKAGE_NAME);//                                                359
                                  /* time (seconds) since the application     */
                                  /* last completed a statement               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_IDLE_TIME);//                                              360
                                  /* currently open cursors                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OPEN_CURSORS);//                                                361
                                  /* previous uow completion status           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_COMP_STATUS);//                                             362
                                  /* seq no. holding lock                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SEQUENCE_NO_HOLDING_LK);//                                      363
                                  /* Application handle                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROLLED_BACK_AGENT_ID);//                                        364
                                  /* victim's appl id                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROLLED_BACK_APPL_ID);//                                         365
                                  /* victim's seq no.                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROLLED_BACK_SEQUENCE_NO);//                                     366
                                  /* XID                                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_XID);//                                                         367
                                  /* TP Monitor client user ID                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TPMON_CLIENT_USERID);//                                         368
                                  /* TP Monitor client workstation            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TPMON_CLIENT_WKSTN);//                                          369
                                  /* TP Monitor client app. name              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TPMON_CLIENT_APP);//                                            370
                                  /* Client accounting string                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TPMON_ACC_STR);//                                               371
                                  /* SQL compiler estim. in TIMERONS          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUERY_COST_ESTIMATE);//                                         372
                                  /* SQL compiler estim. number of rows       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUERY_CARD_ESTIMATE);//                                         373
                                  /* total number of rows fetched             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FETCH_COUNT);//                                                 374
                                  /* # of rows selected (returned)            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_RETURNED);//                              SQLM_ELM_FETCH_COUNT
                                  /* connects since db activations            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_TOTAL_CONS);//                                               375
                                  /* appls currently connected                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_CUR_CONS);//                                                 376
                                  /* appls waiting for host's reply           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_CONS_WAIT_HOST);//                                           377
                                  /* appls waiting for client to send         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_CONS_WAIT_CLIENT);//                                         378
                                  /* high water mark for concurrent           */
                                  /* connections                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_CONNECTIONS_TOP);//                                          379
                                  /* Sort Priv heap currently allocated       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_HEAP_ALLOCATED);//                                         380
                                  /* # sorts started after heap threshold     */
                                  /* exceeded                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POST_THRESHOLD_SORTS);//                                        381
                                  /* # of piped sorts requested by RDS to SLS */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PIPED_SORTS_REQUESTED);//                                       382
                                  /* # of piped sorts accepted by SLS         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PIPED_SORTS_ACCEPTED);//                                        383
                                  /* number of conns deadlocked               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DL_CONNS);//                                                    384
                                  /* Remote connects to target DB2            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_REM_CONS_IN);//                                                 385
                                  /* Remote connects to target exec DB2       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_REM_CONS_IN_EXEC);//                                            386
                                  /* Current Local Connections                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCAL_CONS);//                                                  387
                                  /* Local connects curr exec in DB2          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCAL_CONS_IN_EXEC);//                                          388
                                  /* Local databases w/current connects       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CON_LOCAL_DBASES);//                                            389
                                  /* Number of agents registered in DB2       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_REGISTERED);//                                           390
                                  /* # of agents waiting on a token           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_WAITING_ON_TOKEN);//                                     391
                                  /* status of the DB2 instance               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB2_STATUS);//                                                  392
                                  /* agents_registered high water mark        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_REGISTERED_TOP);//                                       393
                                  /* agents_waiting high water mark           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_WAITING_TOP);//                                          394
                                  /* Committed Private Memory                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COMM_PRIVATE_MEM);//                                            395
                                  /* number of unassigned agents in pool      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_IDLE_AGENTS);//                                                 396
                                  /* # agents assigned from pool              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_FROM_POOL);//                                            397
                                  /* # agents created because the pool was    */
                                  /* empty                                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_CREATED_EMPTY_POOL);//                                   398
                                  /* agents high water mark                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_TOP);//                                                  399
                                  /* coordinating agents high water mark      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_AGENTS_TOP);//                                            400
                                  /* # of attempts to exceed the MAXAGENTS    */
                                  /* configuration parameter.                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_AGENT_OVERFLOWS);//                                         401
                                  /* # agents stolen                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENTS_STOLEN);//                                               402
                                  /* Product Name                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PRODUCT_NAME);//                                                403
                                  /* Product Identificiation                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COMPONENT_ID);//                                                404
                                  /* Service Level                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVICE_LEVEL);//                                               405
                                  /* # hash joins started after heap          */
                                  /* threshold exceeded                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POST_THRESHOLD_HASH_JOINS);//                                   406
                                  /* # of FCM buffers free                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BUFF_FREE);//                                                   407
                                  /* low water mark of buffers free           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BUFF_FREE_BOTTOM);//                                            408
                                  /* # of FCM message anchors free            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MA_FREE);//                                                     409
                                  /* low water mark of anchors free           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MA_FREE_BOTTOM);//                                              410
                                  /* # of FCM connection entries free         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CE_FREE);//                                                     411
                                  /* low water mark of free CEs               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CE_FREE_BOTTOM);//                                              412
                                  /* # of FCM request blocks free             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RB_FREE);//                                                     413
                                  /* low water mark of free RBs               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RB_FREE_BOTTOM);//                                              414
                                  /* FCM Connnection status to node           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONNECTION_STATUS);//                                           416
                                  /* Total # of buffers sent                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_BUFFERS_SENT);//                                          417
                                  /* Total # of buffers received              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_BUFFERS_RCVD);//                                          418
                                  /* Locks currently held                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCKS_HELD);//                                                  419
                                  /* Lock waits since 1st connect             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_WAITS);//                                                  420
                                  /* time spent waiting on locks              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_WAIT_TIME);//                                              421
                                  /* lock list memory in use                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_LIST_IN_USE);//                                            422
                                  /* number of deadlocks                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DEADLOCKS);//                                                   423
                                  /* number of lock escalations               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_ESCALS);//                                                 424
                                  /* number of x-lock excalations             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_X_LOCK_ESCALS);//                                               425
                                  /* agents currently waiting on locks        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCKS_WAITING);//                                               426
                                  /* total number of sorts                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_SORTS);//                                                 427
                                  /* elapsed time spent in sorts              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_SORT_TIME);//                                             428
                                  /* number of sort overflows                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_OVERFLOWS);//                                              429
                                  /* sorts currently active                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_SORTS);//                                                430
                                  /* pool data logical reads                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_DATA_L_READS);//                                           431
                                  /* pool data reads                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_DATA_P_READS);//                                           432
                                  /* pool data writes                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_DATA_WRITES);//                                            433
                                  /* pool index logical reads                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_INDEX_L_READS);//                                          434
                                  /* pool index reads                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_INDEX_P_READS);//                                          435
                                  /* pool index writes                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_INDEX_WRITES);//                                           436
                                  /* Buff pool read time                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_READ_TIME);//                                              437
                                  /* Buff pool write time                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_WRITE_TIME);//                                             438
                                  /* files closed                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FILES_CLOSED);//                                                439
                                  /* # of Dynamic SQL stmts                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DYNAMIC_SQL_STMTS);//                                           440
                                  /* # of Static SQL stmts                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STATIC_SQL_STMTS);//                                            441
                                  /* # of SQL select stmts                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SELECT_SQL_STMTS);//                                            442
                                  /* # of data definition lang. stmts         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DDL_SQL_STMTS);//                                               443
                                  /* # of update/insert/delete stmts          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UID_SQL_STMTS);//                                               444
                                  /* # of Auto Rebinds                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INT_AUTO_REBINDS);//                                            445
                                  /* # of Casc. Deletes                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INT_ROWS_DELETED);//                                            446
                                  /* # of Set Null Deletes                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INT_ROWS_UPDATED);//                                            447
                                  /* # of int. Commits                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INT_COMMITS);//                                                 448
                                  /* # of int. Rollbacks                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INT_ROLLBACKS);//                                               449
                                  /* # of Rollbacks due to deadlock           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INT_DEADLOCK_ROLLBACKS);//                                      450
                                  /* # of Rows Deleted                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_DELETED);//                                                451
                                  /* # of Rows Inserted                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_INSERTED);//                                               452
                                  /* # of Rows Updated                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_UPDATED);//                                                453
                                  /* # of Binds/Precomps                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BINDS_PRECOMPILES);//                                           454
                                  /* max locks held in transaction            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCKS_HELD_TOP);//                                              455
                                  /* 1 if SERIAL                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_NODES_IN_DB2_INSTANCE);//                                   456
                                  /* total number of connects                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_CONS);//                                                  457
                                  /* Appls currently connected                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPLS_CUR_CONS);//                                              458
                                  /* Appls executing in the DB2               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPLS_IN_DB2);//                                                459
                                  /* Maximum secondary log space used         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SEC_LOG_USED_TOP);//                                            460
                                  /* Maximum total log space used             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOT_LOG_USED_TOP);//                                            461
                                  /* Number of secondary logs allocated       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SEC_LOGS_ALLOCATED);//                                          462
                                  /* asynchronous pool index reads            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_INDEX_READS);//                                      463
                                  /* #pages copied from BP to estore          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_DATA_TO_ESTORE);//                                         464
                                  /* #pages copied from BP to estore          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_INDEX_TO_ESTORE);//                                        465
                                  /* #pages copied from estore to BP          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_INDEX_FROM_ESTORE);//                                      466
                                  /* #pages copied from estore to BP          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_DATA_FROM_ESTORE);//                                       467
                                  /* status of the Database                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_STATUS);//                                                   468
                                  /* # of lock timeouts                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_TIMEOUTS);//                                               469
                                  /* high water mark for current connections  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONNECTIONS_TOP);//                                             470
                                  /* high water mark for database heap        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_HEAP_TOP);//                                                 471
                                  /* asynchronous pool data reads             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_DATA_READS);//                                       472
                                  /* asynchronous pool data writes            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_DATA_WRITES);//                                      473
                                  /* asynchronous pool indx writes            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_INDEX_WRITES);//                                     474
                                  /* total async read time                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_READ_TIME);//                                        475
                                  /* total async write time                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_WRITE_TIME);//                                       476
                                  /* # async read requests                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_DATA_READ_REQS);//                                   477
                                  /* LSN Gap cleaner triggers                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_LSN_GAP_CLNS);//                                           478
                                  /* dirty page steal cleaner triggers        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_DRTY_PG_STEAL_CLNS);//                                     479
                                  /* dirty list threshold cln trig            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_DRTY_PG_THRSH_CLNS);//                                     480
                                  /* direct reads                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DIRECT_READS);//                                                481
                                  /* direct writes                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DIRECT_WRITES);//                                               482
                                  /* direct read requests                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DIRECT_READ_REQS);//                                            483
                                  /* direct write requests                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DIRECT_WRITE_REQS);//                                           484
                                  /* direct read time                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DIRECT_READ_TIME);//                                            485
                                  /* direct write time                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DIRECT_WRITE_TIME);//                                           486
                                  /* # rows insrted for Trigger               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INT_ROWS_INSERTED);//                                           487
                                  /* # of log pages read                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_READS);//                                                   488
                                  /* # of log pages read                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_WRITES);//                                                  489
                                  /* # of section lookups                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKG_CACHE_LOOKUPS);//                                           490
                                  /* # of sections inserted into cache        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKG_CACHE_INSERTS);//                                           491
                                  /* # of table descriptor lookups            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CAT_CACHE_LOOKUPS);//                                           492
                                  /* # of table descriptors inserted          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CAT_CACHE_INSERTS);//                                           493
                                  /* # of catalog cache overflows             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CAT_CACHE_OVERFLOWS);//                                         494
                                  /* Obsolete in V8 - always reported as 0 -  */
                                  /* use CAT_CACHE_SIZE_TOP                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CAT_CACHE_HEAP_FULL);//                                         495
                                  /* Catalog node number                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CATALOG_NODE);//                                                496
                                  /* Secondary connects database connection   */
                                  /* with appls connected to this db.         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_SEC_CONS);//                                              497
                                  /* local or remote to snapshot appl.        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_LOCATION);//                                                 498
                                  /* OS on which dbm runs                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVER_PLATFORM);//                                             499
                                  /* Catalog network node name                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CATALOG_NODE_NAME);//                                           500
                                  /* Time waited for prefetch (ms)            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PREFETCH_WAIT_TIME);//                                          501
                                  /* # of section lookups                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_SECTION_LOOKUPS);//                                        502
                                  /* # of sections inserted                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_SECTION_INSERTS);//                                        503
                                  /* number of hash joins                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_HASH_JOINS);//                                            504
                                  /* number of hash loops                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_HASH_LOOPS);//                                            505
                                  /* number of hash join overflows            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HASH_JOIN_OVERFLOWS);//                                         506
                                  /* small hash join overflows                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HASH_JOIN_SMALL_OVERFLOWS);//                                   507
                                  /* time UOW waited on locks (ms)            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_LOCK_WAIT_TIME);//                                          508
                                  /* Statement type indicator                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_TYPE);//                                                   509
                                  /* Name of cursor                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CURSOR_NAME);//                                                 510
                                  /* Log space used in most recent UOW        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_LOG_SPACE_USED);//                                          511
                                  /* Currently open remote cursors            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OPEN_REM_CURS);//                                               512
                                  /* Currently open rem cursors w/blk         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OPEN_REM_CURS_BLK);//                                           513
                                  /* Rej block remote cursor requests         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_REJ_CURS_BLK);//                                                514
                                  /* Acc block remote cursor requests         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACC_CURS_BLK);//                                                515
                                  /* Event Monitor Version                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_VERSION);//                                                     516
                                  /* Name of the Event Mon                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVENT_MONITOR_NAME);//                                          517
                                  /* # SQL requests since last commit         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQL_REQS_SINCE_COMMIT);//                                       518
                                  /* Big Endian or Little Endian              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BYTE_ORDER);//                                                  520
                                  /* Worst prep time of statement             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PREP_TIME_WORST);//                                             521
                                  /* # rows read                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_READ);//                                                   522
                                  /* # rows read                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_FETCHED);//                                 SQLM_ELM_ROWS_READ
                                  /* # rows written                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_WRITTEN);//                                                523
                                  /* # of rows modified (synonym)             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_MODIFIED);//                             SQLM_ELM_ROWS_WRITTEN
                                  /* Currently open local cursors             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OPEN_LOC_CURS);//                                               524
                                  /* Currently open local cursors w/blk       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OPEN_LOC_CURS_BLK);//                                           525
                                  /* Coordinating node number.                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_NODE);//                                                  526
                                  /* Coordinating partition number            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_PARTITION_NUM);//                         SQLM_ELM_COORD_NODE
                                  /* # of agents currently active             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_AGENTS);//                                                  527
                                  /* # of agents associated with this         */
                                  /* application  high water mark.            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ASSOCIATED_AGENTS_TOP);//                                       528
                                  /* priority at which appl agents work       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_PRIORITY);//                                               529
                                  /* Dynamic or Static                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_PRIORITY_TYPE);//                                          530
                                  /* SMP Intraquery Parallelism req           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DEGREE_PARALLELISM);//                                          531
                                  /* number of sorts for this statement       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_SORTS);//                                                  532
                                  /* total user CPU time of SQL stmt          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_USR_CPU_TIME);//                                           533
                                  /* total system CPU time for SQL stmt       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_SYS_CPU_TIME);//                                           534
                                  /* Subsection number                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SS_NUMBER);//                                                   535
                                  /* Subsection status                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SS_STATUS);//                                                   536
                                  /* Node where the subsec is executing       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SS_NODE_NUMBER);//                                              537
                                  /* Execution elapsed time in seconds        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SS_EXEC_TIME);//                                                538
                                  /* Best prep time of statement              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PREP_TIME_BEST);//                                              539
                                  /* Number of compilation environments       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_COMPILATIONS);//                                            540
                                  /* If blocked when sending or receiving on  */
                                  /* a tablequeue, node for which we wait     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_NODE_WAITED_FOR);//                                          541
                                  /* TRUE if waiting for any node             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_WAIT_FOR_ANY);//                                             542
                                  /* tablequeue waiting to send/receive       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_ID_WAITING_ON);//                                            543
                                  /* Total # of buffers overflowed to a temp  */
                                  /* table when sending on a tq               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_TOT_SEND_SPILLS);//                                          544
                                  /* Current # of tq send buffers overflowed  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_CUR_SEND_SPILLS);//                                          545
                                  /* Maximum # of tq send buffers overflowed  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_MAX_SEND_SPILLS);//                                          546
                                  /* Total # rows received on tablequeues     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_ROWS_READ);//                                                547
                                  /* Total # rows sent on tablequeues         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TQ_ROWS_WRITTEN);//                                             548
                                  /* db2agent process/thread id               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_PID);//                                                   549
                                  /* Was this lock part of an escalation      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_ESCALATION);//                                             550
                                  /* Subsection waiting for lock              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SUBSECTION_NUMBER);//                                           551
                                  /* Mode of Lock waited on                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_MODE);//                                                   552
                                  /* lock object type: row, table,            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_OBJECT_TYPE);//                                            553
                                  /* Number of executions                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_EXECUTIONS);//                                              554
                                  /* Table name                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE_NAME);//                                                  555
                                  /* Schema name                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE_SCHEMA);//                                                556
                                  /* Tablespace name                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_NAME);//                                             557
                                  /* Application holding the lock             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_ID_HOLDING_LK);//                                         558
                                  /* Appl. holding the lock                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_ID_HOLDING_LK);//                                          559
                                  /* the file ID for the table                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE_FILE_ID);//                                               561
                                  /* table type                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLE_TYPE);//                                                  562
                                  /* no. of accesses to overflow rec          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OVERFLOW_ACCESSES);//                                           563
                                  /* no. of page reorgs for table             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PAGE_REORGS);//                                                 564
                                  /* size of the sqlca                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLCABC);//                                                     565
                                  /* Lock status                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_STATUS);//                                                 566
                                  /* Lock Object Name - RID or FID of lock    */
                                  /* obj                                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_OBJECT_NAME);//                                            567
                                  /* database or tablespace rollforward       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RF_TYPE);//                                                     568
                                  /* Current log being processed              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RF_LOG_NUM);//                                                  569
                                  /* Log phase in progress                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RF_STATUS);//                                                   570
                                  /* Tablespace being rolled forward          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TS_NAME);//                                                     571
                                  /* Bufferpool name                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BP_NAME);//                                                     572
                                  /* Statement node number                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_NODE_NUMBER);//                                            573
                                  /* partial record for flush evmon           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PARTIAL_RECORD);//                                              574
                                  /* Amount of system cpu time used           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SYSTEM_CPU_TIME);//                                             575
                                  /* An sqlca                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLCA);//                                                       576
                                  /* sqlcode of the sqlca                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLCODE);//                                                     577
                                  /* length of ca message tokens              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRML);//                                                    578
                                  /* message tokensessage tokens              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRMC);//                                                    579
                                  /* diagnostic information                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRP);//                                                     580
                                  /* diagnostic information                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRD);//                                                     581
                                  /* warning flags                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLWARN);//                                                     582
                                  /* state corresponding to SQLCODE           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLSTATE);//                                                    583
                                  /* uow status                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_STATUS);//                                                  584
                                  /* elapsed system cpu time                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_SYS_CPU_TIME);//                                          585
                                  /* elapsed user   cpu time                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_USR_CPU_TIME);//                                          586
                                  /* the lock mode requested                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_MODE_REQUESTED);//                                         587
                                  /* number of primed gw agents               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INACTIVE_GW_AGENTS);//                                          588
                                  /* number of times an primed agent was      */
                                  /* stolen.                                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_GW_CONN_SWITCHES);//                                        589
                                  /* number of comm erros on the gw           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_COMM_ERRORS);//                                              590
                                  /* time of the most recent comm err         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_COMM_ERROR_TIME);//                                          591
                                  /* time the most recent conn started        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GW_CON_START_TIME);//                                           592
                                  /* most recent connection response tm       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CON_RESPONSE_TIME);//                                           593
                                  /* elapsed connected time of most recent    */
                                  /* disconnect                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CON_ELAPSED_TIME);//                                            594
                                  /* elapsed response time from host          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HOST_RESPONSE_TIME);//                                          595
                                  /* number of pkg cache overflows            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKG_CACHE_NUM_OVERFLOWS);//                                     596
                                  /* high water mark for pkg cache size       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKG_CACHE_SIZE_TOP);//                                          597
                                  /* transaction holding oldest xact          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APPL_ID_OLDEST_XACT);//                                         598
                                  /* log space used by database               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_LOG_USED);//                                              599
                                  /* log space available in database          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_LOG_AVAILABLE);//                                         600
                                  /* previous statement elapsed time          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_ELAPSED_TIME);//                                           601
                                  /* previous uow elpased time                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_ELAPSED_TIME);//                                            602
                                  /* sqlca eyecatcher                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLCAID);//                                                     603
                                  /* node with worst log  ratio               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SMALLEST_LOG_AVAIL_NODE);//                                     604
                                  /* number of disconnects                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DISCONNECTS);//                                                 605
                                  /* number of create nickname stmts          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CREATE_NICKNAME);//                                             606
                                  /* number of stmts passed through           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PASSTHRUS);//                                                   607
                                  /* number of stored procedures              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STORED_PROCS);//                                                608
                                  /* number of rows returned from stored      */
                                  /* procedures                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SP_ROWS_SELECTED);//                                            609
                                  /* Remote datasource name                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DATASOURCE_NAME);//                                             610
                                  /* number of remote table lock stmts        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_REMOTE_LOCKS);//                                                611
                                  /* Blocking cursor                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BLOCKING_CURSOR);//                                             612
                                  /* outbound blocking cursor                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_BLOCKING_CURSOR);//                                    613
                                  /* Insert sql statements                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INSERT_SQL_STMTS);//                                            614
                                  /* Update sql statements                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UPDATE_SQL_STMTS);//                                            615
                                  /* Delete sql statements                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DELETE_SQL_STMTS);//                                            616
                                  /* unread prefetch pages                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UNREAD_PREFETCH_PAGES);//                                       617
                                  /* work agent association status            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_STATUS);//                                                618
                                  /* Number of Transmissions                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_TRANSMISSIONS);//                                           619
                                  /* High water mark for number of bytes sent */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_BYTES_SENT_TOP);//                                     620
                                  /* High water mark for number of bytes      */
                                  /* received                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_BYTES_RECEIVED_TOP);//                                 621
                                  /* Low water mark for number of bytes sent  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_BYTES_SENT_BOTTOM);//                                  622
                                  /* High water mark for num of bytes         */
                                  /* received                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OUTBOUND_BYTES_RECEIVED_BOTTOM);//                              623

/*  The following elements represent counts of the number of transmissions    */
/*  whose size in bytes is less than or equal to the number in the name.      */
                                  /* Cnt:Sent size <= 128 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_128);//                                           624
                                  /* Cnt:Sent size <= 256 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_256);//                                           625
                                  /* Cnt:Sent size <= 512 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_512);//                                           626
                                  /* Cnt:Sent size <= 1024 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_1024);//                                          627
                                  /* Cnt:Sent size <= 2048 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_2048);//                                          628
                                  /* Cnt:Sent size <= 4096 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_4096);//                                          629
                                  /* Cnt:Sent size <= 8192 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_8192);//                                          630
                                  /* Cnt:Sent size <= 16384 bytes             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_16384);//                                         631
                                  /* Cnt:Sent size <= 31999 bytes             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_31999);//                                         632
                                  /* Cnt:Sent size <= 64000 bytes             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_64000);//                                         633
                                  /* Cnt:Sent size > 64000 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_SENT_GT64000);//                                       634
                                  /* Cnt:Rcv size <= 128 bytes                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_128);//                                       635
                                  /* Cnt:Rcv size <= 256 bytes                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_256);//                                       636
                                  /* Cnt:Rcv size <= 512 bytes                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_512);//                                       637
                                  /* Cnt:Rcv size <= 1024 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_1024);//                                      638
                                  /* Cnt:Rcv size <= 2048 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_2048);//                                      639
                                  /* Cnt:Rcv size <= 4096 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_4096);//                                      640
                                  /* Cnt:Rcv size <= 8192 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_8192);//                                      641
                                  /* Cnt:Rcv size <= 16384 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_16384);//                                     642
                                  /* Cnt:Rcv size <= 31999 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_31999);//                                     643
                                  /* Cnt:Rcv size <= 64000 bytes              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_64000);//                                     644
                                  /* Cnt:Rcv size > 64000 bytes               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_DATA_RECEIVED_GT64000);//                                   645

/*  The following elements represent counts of the number of transmissions    */
/*  whose network transmission time is less than the time (in milliseconds)   */
/*  in the name.                                                              */
                                  /* Cnt:network time <= 2 millisec.          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_2_MS);//                                               646
                                  /* Cnt:network time <= 4 millisec.          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_4_MS);//                                               647
                                  /* Cnt:network time <= 8 millisec.          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_8_MS);//                                               648
                                  /* Cnt:network time <= 16 millisec.         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_16_MS);//                                              649
                                  /* Cnt:network time <= 32 millisec.         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_32_MS);//                                              650
                                  /* Cnt:network time > 32 millisec.          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_GT32_MS);//                                            651

/* Deadlock Identification elements.                                          */
                                  /* Deadlock ID on the node                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DEADLOCK_ID);//                                                 652
                                  /* Node where found                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DEADLOCK_NODE);//                                               653

/* Deadlock Participant numbers                                               */
                                  /* # of part. within this deadlock          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PARTICIPANT_NO);//                                              654
                                  /* part. # of deadlocked connection holding */
                                  /* lock we are waiting for                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PARTICIPANT_NO_HOLDING_LK);//                                   655
                                  /* participant number of the rolled back    */
                                  /* application                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROLLED_BACK_PARTICIPANT_NO);//                                  656

/* Please make these 6 element always consecutive, sqlmetart.C relys on this  */
                                  /* 1st of the array                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRD1);//                                                    657
                                  /* 2nd of the array                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRD2);//                                                    658
                                  /* 3rd of the array                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRD3);//                                                    659
                                  /* 4th of the array                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRD4);//                                                    660
                                  /* 5th of the array                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRD5);//                                                    661
                                  /* 6th of the array                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQLERRD6);//                                                    662

/*Event monitor new elements added  */
                                  /* Number of evmon is activated             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVMON_ACTIVATES);//                                             663
                                  /* Number of evmon is flushed               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EVMON_FLUSHES);//                                               664
                                  /* A unique identifier for SQL request      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQL_REQ_ID);//                                                  665

/*New elements added for WTT control table                                    */
                                  /* The message in the control table         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MESSAGE);//                                                     666
                                  /* The timestamp for the above message      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MESSAGE_TIME);//                                                667

/* Elements for dynamic bufferpool                                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_VECTORED_IOS);//                                                668
ret = PyModule_AddIntMacro(m, SQLM_ELM_PAGES_FROM_VECTORED_IOS);//                                     669
ret = PyModule_AddIntMacro(m, SQLM_ELM_BLOCK_IOS);//                                                   670
ret = PyModule_AddIntMacro(m, SQLM_ELM_PAGES_FROM_BLOCK_IOS);//                                        671
ret = PyModule_AddIntMacro(m, SQLM_ELM_PHYSICAL_PAGE_MAPS);//                                          672

/* Specifies the number of locks in the detailed dlconn lock list             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCKS_IN_LIST);//                                               673

/* Elements for table reorg                                                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_PHASE);//                                                 674
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_MAX_PHASE);//                                             675
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_CURRENT_COUNTER);//                                       676
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_MAX_COUNTER);//                                           677
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_TYPE);//                                                  678
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_STATUS);//                                                679
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_COMPLETION);//                                            680
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_START);//                                                 681
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_END);//                                                   682
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_PHASE_START);//                                           683
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_INDEX_ID);//                                              684
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_TBSPC_ID);//                                              685


/*Pool memory elements                                                        */
                                  /* Pool identifier                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ID);//                                                     686
                                  /* Current size of storage pool             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_CUR_SIZE);//                                               687
                                  /* Configured size for a pool (v8.2)        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_CONFIG_SIZE);//                                            688
                                  /* Largest size pool can have (v8.1)        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_MAX_SIZE);//                           SQLM_ELM_POOL_CONFIG_SIZE
                                  /* Largest amount used so far               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_WATERMARK);//                                              689

/* Elements for tablespace containers                                         */
                                  /* Tablespace identifier                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_ID);//                                               690
                                  /* Type of TS - DMS or SMS                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_TYPE);//                                             691
                                  /* Type of data in this TS                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_CONTENT_TYPE);//                                     692
                                  /* Describes current TS state               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_STATE);//                                            693
                                  /* Size for each TS page                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_PAGE_SIZE);//                                        694
                                  /* # of pages in each TS extent             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_EXTENT_SIZE);//                                      695
                                  /* # of pages for prefetching               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_PREFETCH_SIZE);//                                    696
                                  /* Current buffer pool id                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_CUR_POOL_ID);//                                      697
                                  /* Buffer pool id next startup              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_NEXT_POOL_ID);//                                     698
                                  /* Total num pages in TS                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_TOTAL_PAGES);//                                      699
                                  /* # usable pages in TS                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_USABLE_PAGES);//                                     700
                                  /* # pages used in TS                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_USED_PAGES);//                                       701
                                  /* # free pages in TS                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_FREE_PAGES);//                                       702
                                  /* Page # of 1st free extent                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_PAGE_TOP);//                                         703
                                  /* # pending free pages                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_PENDING_FREE_PAGES);//                               704
                                  /* Rebal Mode - Forward/Rev                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_REBALANCER_MODE);//                                  705
                                  /* # ext to be done                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_REBALANCER_EXTENTS_REMAINING);//                     706
                                  /* # extents done                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_REBALANCER_EXTENTS_PROCESSED);//                     707
                                  /* last extent moved                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_REBALANCER_LAST_EXTENT_MOVED);//                     708
                                  /* Priority of rebalancer                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_REBALANCER_PRIORITY);//                              709
                                  /* # of quiescers                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_NUM_QUIESCERS);//                                    710
                                  /* Obj ID of object that caused TS state to */
                                  /* be changed                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_STATE_CHANGE_OBJECT_ID);//                           711
                                  /* TS id of object that caused TS state to  */
                                  /* be changed                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_STATE_CHANGE_TS_ID);//                               712
                                  /* # of containers in TS                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_NUM_CONTAINERS);//                                   713
                                  /* # of ranges in TS map                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_NUM_RANGES);//                                       714
                                  /* State of the quiesce                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUIESCER_STATE);//                                              715
                                  /* Agent id of agent holding the quiesce    */
                                  /* state                                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUIESCER_AGENT_ID);//                                           716
                                  /* TS id of object causing tablespace to be */
                                  /* quiesced                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUIESCER_TS_ID);//                                              717
                                  /* Object ID of object causing tablespace   */
                                  /* to be quiesced                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUIESCER_OBJ_ID);//                                             718
                                  /* Auth id of user holding the quiesce      */
                                  /* state                                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUIESCER_AUTH_ID);//                                            719
                                  /* Container identifier                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_ID);//                                                720
                                  /* Type of container                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_TYPE);//                                              721
                                  /* Total # pages in container               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_TOTAL_PAGES);//                                       722
                                  /* # usable pages in container              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_USABLE_PAGES);//                                      723
                                  /* Stripe set cont. belongs to              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_STRIPE_SET);//                                        724
                                  /* Is container accessible?                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_ACCESSIBLE);//                                        725
                                  /* Name of the container                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_NAME);//                                              726
                                  /* Stripe set range resides in              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_STRIPE_SET_NUMBER);//                                     727
                                  /* The number of the range                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_NUMBER);//                                                728
                                  /* Offset from stripe 0                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_OFFSET);//                                                729
                                  /* Max page # in the range                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_MAX_PAGE_NUMBER);//                                       730
                                  /* Max extent # in the range                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_MAX_EXTENT);//                                            731
                                  /* # of first stripe in range               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_START_STRIPE);//                                          732
                                  /* # of last stripe in range                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_END_STRIPE);//                                            733
                                  /* Offset into which the range actually     */
                                  /* starts                                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_ADJUSTMENT);//                                            734
                                  /* # of containers in the range             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_NUM_CONTAINERS);//                                        735
                                  /* ID of container belonging to the current */
                                  /* range                                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RANGE_CONTAINER_ID);//                                          736

                                  /* Package Consistency Token                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONSISTENCY_TOKEN);//                                           737
                                  /* Package version identifier               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PACKAGE_VERSION_ID);//                                          738

                                  /* binary lock name                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_NAME);//                                                   739
                                  /* lock count                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_COUNT);//                                                  740
                                  /* hold count                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_HOLD_COUNT);//                                             741
                                  /* lock attributes                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_ATTRIBUTES);//                                             742
                                  /* internal release bits                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_RELEASE_FLAGS);//                                          743
                                  /* orig mode before conversion              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_CURRENT_MODE);//                                           744
                                  /* fs caching                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_FS_CACHING);//                                       745


/******************************************************************************/
/* Dynamic Bufferpool                                                         */
/******************************************************************************/
                                  /* # of tblspaces mapped to BP              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BP_TBSP_USE_COUNT);//                                           751
                                  /* # pages left to remove                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BP_PAGES_LEFT_TO_REMOVE);//                                     752
                                  /* Current size of bufferpool               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BP_CUR_BUFFSZ);//                                               753
                                  /* BP size after imdt/def. alt              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BP_NEW_BUFFSZ);//                                               754

                                  /* Sort Priv heap high water mark           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_HEAP_TOP);//                                               755
                                  /* Sort SHARE heap currently alloc          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SHRHEAP_ALLOCATED);//                                      756
                                  /* Sort SHARE heap high water mark          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SHRHEAP_TOP);//                                            757


/******************************************************************************/
/* APM Interaction                                                            */
/******************************************************************************/

                                  /* s wrkspc high watermrk                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SHR_WORKSPACE_SIZE_TOP);//                                      758
                                  /* s wrkspc # overflows                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SHR_WORKSPACE_NUM_OVERFLOWS);//                                 759
                                  /* s wrkspc sec. lookups                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SHR_WORKSPACE_SECTION_LOOKUPS);//                               760
                                  /* s wrkspc sec. inserts                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SHR_WORKSPACE_SECTION_INSERTS);//                               761
                                  /* p wrkspc high watermrk                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PRIV_WORKSPACE_SIZE_TOP);//                                     762
                                  /* p wrkspc # overflows                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PRIV_WORKSPACE_NUM_OVERFLOWS);//                                763
                                  /* p wrkspc sec. lookups                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PRIV_WORKSPACE_SECTION_LOOKUPS);//                              764
                                  /* p wrkspc sec. inserts                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PRIV_WORKSPACE_SECTION_INSERTS);//                              765

/******************************************************************************/
/* Catalog Cache                                                              */
/******************************************************************************/
                                  /* Cat cache sz high water mark             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CAT_CACHE_SIZE_TOP);//                                          766

/******************************************************************************/
/* Partition Number for EEE WTT evmon                                         */
/******************************************************************************/
                                  /* Partition Number for EEE WTT             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PARTITION_NUMBER);//                                            767
                                  /* Number of Transmissions group            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_TRANSMISSIONS_GROUP);//                                     768
                                  /* Number of indoubt transactions           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_INDOUBT_TRANS);//                                           769

/******************************************************************************/
/* Information for active utilities                                           */
/******************************************************************************/
                                  /* Utility's database                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_DBNAME);//                                              770
                                  /* Utility ID                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_ID);//                                                  771
                                  /* Type of utility                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_TYPE);//                                                772
                                  /* Utility priority                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_PRIORITY);//                                            773
                                  /* Start time of utility                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_START_TIME);//                                          774
                                  /* Utility description                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_DESCRIPTION);//                                         775

                                  /* # async index read requests              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_INDEX_READ_REQS);//                                  776
                                  /* Authorization Id                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SESSION_AUTH_ID);//                                             777

                                  /* number of SQL stmt chains sent           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SQL_CHAINS);//                                                  778

                                  /* pool temp data logical reads             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_TEMP_DATA_L_READS);//                                      779
                                  /* pool temp data physical reads            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_TEMP_DATA_P_READS);//                                      780
                                  /* pool temp index logical reads            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_TEMP_INDEX_L_READS);//                                     781
                                  /* pool temp index physical reads           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_TEMP_INDEX_P_READS);//                                     782

                                  /* Cnt:network time <= 1 millisec.          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_1_MS);//                                               783
                                  /* Cnt:network time <= 100 millisec.        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_100_MS);//                                             784
                                  /* Cnt:network time <= 500 millisec.        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_500_MS);//                                             785
                                  /* Cnt:network time > 500 millisec.         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MAX_TIME_GT500_MS);//                                           786

                                  /* bytes of log that need to be redone      */
                                  /* during recovery                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_TO_REDO_FOR_RECOVERY);//                                    787
                                  /* number of times no victim buffer         */
                                  /* available from hate list                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_NO_VICTIM_BUFFER);//                                       788
                                  /* bytes of log that are held up by minbuf  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_HELD_BY_DIRTY_PAGES);//                                     789

/******************************************************************************/
/*   Information for the progress of utilities                                */
/******************************************************************************/
                                  /* job progress description                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_DESCRIPTION);//                                        790
                                  /* job progress start time                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_START_TIME);//                                         791
                                  /* job progress work metric                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_WORK_METRIC);//                                        792
                                  /* job progress total units                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_TOTAL_UNITS);//                                        793
                                  /* job progress completed units             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_COMPLETED_UNITS);//                                    794
                                  /* job progress id                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_SEQ_NUM);//                                            795
                                  /* current job of progress list             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_LIST_CUR_SEQ_NUM);//                                   796

/******************************************************************************/
/* Information for HADR                                                       */
/******************************************************************************/
                                  /* HADR Role                                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_ROLE);//                                                   797
                                  /* HADR State                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_STATE);//                                                  798
                                  /* HADR Synchronization mode                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_SYNCMODE);//                                               799
                                  /* HADR Connection                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_CONNECT_STATUS);//                                         800
                                  /* HADR Timestamp for connection status     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_CONNECT_TIME);//                                           801
                                  /* HADR Heartbeat                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_HEARTBEAT);//                                              802
                                  /* HADR Local host                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_LOCAL_HOST);//                                             803
                                  /* HADR Local service                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_LOCAL_SERVICE);//                                          804
                                  /* HADR Remote host                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_REMOTE_HOST);//                                            805
                                  /* HADR Remote service                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_REMOTE_SERVICE);//                                         806
                                  /* HADR timeout                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_TIMEOUT);//                                                807
                                  /* HADR Primary log file name               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_PRIMARY_LOG_FILE);//                                       808
                                  /* HADR Primary log page number             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_PRIMARY_LOG_PAGE);//                                       809
                                  /* HADR Primary log position                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_PRIMARY_LOG_LSN);//                                        810
                                  /* HADR Secondary log file name             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_STANDBY_LOG_FILE);//                                       811
                                  /* HADR Secondary log page number           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_STANDBY_LOG_PAGE);//                                       812
                                  /* HADR Secondary log position              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_STANDBY_LOG_LSN);//                                        813
                                  /* HADR Log gap running average             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_LOG_GAP);//                                                814
                                  /* HADR Remote instance name                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_REMOTE_INSTANCE);//                                        815
/******************************************************************************/
/* Additional elements added in 8.2                                           */
/******************************************************************************/
                                  /* number of pages for table base data      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DATA_OBJECT_PAGES);//                                           816
                                  /* number of pages for index base data      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INDEX_OBJECT_PAGES);//                                          817
                                  /* number of pages for LOB data             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOB_OBJECT_PAGES);//                                            818
                                  /* number of pages for long data            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LONG_OBJECT_PAGES);//                                           819

                                  /* Appl lock timeout value                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_TIMEOUT_VAL);//                                            820

/******************************************************************************/
/*  Log elements v8.2                                                         */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_WRITE_TIME);//                                              821
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_READ_TIME);//                                               822
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_LOG_WRITE_IO);//                                            823
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_LOG_READ_IO);//                                             824
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_LOG_PART_PAGE_IO);//                                        825
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_LOG_BUFF_FULL);//                                           826
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_LOG_DATA_IN_BUFF);//                                        827
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_FILE_NUM_FIRST);//                                          828
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_FILE_NUM_LAST);//                                           829
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_FILE_NUM_CURR);//                                           830
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOG_FILE_ARCHIVE);//                                            831


ret = PyModule_AddIntMacro(m, SQLM_ELM_NANOSEC);//                                                     832

/******************************************************************************/
/*  New elements for enhanced deadlock event monitor with statement history   */
/******************************************************************************/
                                  /* statement history id                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_HISTORY_ID);//                                             833
                                  /* lock timeout reg var of stmt             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_LOCK_TIMEOUT);//                                           834
                                  /* cursor isolation level                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_ISOLATION);//                                              835
                                  /* descriptor blob of compilation           */
                                  /* environment                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COMP_ENV_DESC);//                                               836
                                  /* data value type                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_VALUE_TYPE);//                                             837
                                  /* value set by reopt?                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_VALUE_ISREOPT);//                                          838
                                  /* data has null values                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_VALUE_ISNULL);//                                           839
                                  /* variable data                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_VALUE_DATA);//                                             840
                                  /* position of value in stmt                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_VALUE_INDEX);//                                            841
                                  /* time of stmt first use                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_FIRST_USE_TIME);//                                         842
                                  /* time stmt last use                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_LAST_USE_TIME);//                                          843
                                  /* nesting level of statement               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_NEST_LEVEL);//                                             844
                                  /* invocation id of statement               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_INVOCATION_ID);//                                          845
                                  /* query id of statement                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_QUERY_ID);//                                               846
                                  /* source id of statement                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_SOURCE_ID);//                                              847
                                  /* unique package cache id                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMT_PKGCACHE_ID);//                                            848
                                  /* size of stmts history list               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INACT_STMTHIST_SZ);//                                           849

/******************************************************************************/
/* New elements for Single point of storage management                        */
/******************************************************************************/
                                  /* num automatic storage paths              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_DB_STORAGE_PATHS);//                                        850
                                  /* automatic storage path                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_STORAGE_PATH);//                                             851
                                  /* initial size of tbsp                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_INITIAL_SIZE);//                                     852
                                  /* current tablespace size                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_CURRENT_SIZE);//                                     853
                                  /* maximum tablespace size                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_MAX_SIZE);//                                         854
                                  /* growth size by percent                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_INCREASE_SIZE_PERCENT);//                            855
                                  /* growth size in bytes                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_INCREASE_SIZE);//                                    856
                                  /* last growth time                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_LAST_RESIZE_TIME);//                                 857
                                  /* using automatic storage                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_USING_AUTO_STORAGE);//                               858
                                  /* auto resize enabled                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_AUTO_RESIZE_ENABLED);//                              859
                                  /* last resize failed                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_LAST_RESIZE_FAILED);//                               860

                                  /* Bufferpool identifier                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BP_ID);//                                                       861

/*  New elements for v9.1                                                     */
                                  /* Tablespace ID in Reorg                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_LONG_TBSPC_ID);//                                         862

                                  /* Partition id of Table                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DATA_PARTITION_ID);//                                           863
                                  /* Progress list attributes                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PROGRESS_LIST_ATTR);//                                          864


/******************************************************************************/
/* New REORG monitoring elements for v9 (Row Compression)                     */
/******************************************************************************/
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_ROWSCOMPRESSED);//                                        865
ret = PyModule_AddIntMacro(m, SQLM_ELM_REORG_ROWSREJECTED);//                                          866

/******************************************************************************/
/* FCM monitoring element additions for v9                                    */
/******************************************************************************/
                                  /* # of FCM channel blocks free             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CH_FREE);//                                                     867
                                  /* low water mark of free channels          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CH_FREE_BOTTOM);//                                              868
/******************************************************************************/
/* Utility monitoring element additions for v9                                */
/******************************************************************************/
                                  /* Utility state                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_STATE);//                                               869
                                  /* Invoker type                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UTILITY_INVOKER_TYPE);//                                        870
/******************************************************************************/
/* New sort monitor elements                                                  */
/******************************************************************************/

                                  /* Sorts that started passed the throttling */
                                  /* threshold for shared memory              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POST_SHRTHRESHOLD_SORTS);//                                     871
                                  /* Hash Joins that started passed the       */
                                  /* throttling threshold for shared memory   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POST_SHRTHRESHOLD_HASH_JOINS);//                                872
                                  /* hash joins currently active              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_HASH_JOINS);//                                           873

                                  /* Pool secondary identifier                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_SECONDARY_ID);//                                           874

                                  /* File system ID number for a stg path     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FS_ID);//                                                       875
                                  /* Total size of a stg path                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FS_TOTAL_SZ);//                                                 876
                                  /* Space currently used on a stg path       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_FS_USED_SZ);//                                                  877
                                  /* Free space available on a stg path       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STO_PATH_FREE_SZ);//                                            878

                                  /* BP XDA logical reads                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_XDA_L_READS);//                                            879
                                  /* BP XDA physical reads                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_XDA_P_READS);//                                            880
                                  /* BP XDA page writes                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_XDA_WRITES);//                                             881
                                  /* logical reads of temp XDA pgs            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_TEMP_XDA_L_READS);//                                       882
                                  /* physical reads of temp XDA pgs           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_TEMP_XDA_P_READS);//                                       883
                                  /* Prefetcher XDA reads                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_XDA_READS);//                                        884
                                  /* Prefetcher XDA writes                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_XDA_WRITES);//                                       885
                                  /* Num prefetcher XDA read reqs             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_ASYNC_XDA_READ_REQS);//                                    886
                                  /* number of pages for XDA data             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_XDA_OBJECT_PAGES);//                                            887
                                  /* # of XQUERY stmts                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_XQUERY_STMTS);//                                                888

/******************************************************************************/
/* New Trusted Context monitor element for v9                                 */
/******************************************************************************/
                                  /* Trusted Authorization ID                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TRUSTED_AUTH_ID);//                                             889

/*****************************************************************************/
/* HADR Peer Window elements                                                 */
/*****************************************************************************/
                                  /* HADR Peer window end                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_PEER_WINDOW_END);//                                        890
                                  /* HADR Peer window                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HADR_PEER_WINDOW);//                                            891

/******************************************************************************/
/* New elements added for v9.5                                                */
/******************************************************************************/

ret = PyModule_AddIntMacro(m, SQLM_ELM_BLOCKS_PENDING_CLEANUP);//                                      892
ret = PyModule_AddIntMacro(m, SQLM_ELM_AUTHORITY_BITMAP);//                                            893

                                  /* # OLAP functions executed                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_OLAP_FUNCS);//                                            894
                                  /* # OLAP functions started after sortheap  */
                                  /* threshold exceeded                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POST_THRESHOLD_OLAP_FUNCS);//                                   895
                                  /* # OLAP functions currently running       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_OLAP_FUNCS);//                                           896
                                  /* # OLAP functions which have overflowed   */
                                  /* to temp tables                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_OLAP_FUNC_OVERFLOWS);//                                         897

/******************************************************************************/
/* Work Load Management elements for new event monitors                       */
/******************************************************************************/

                                  /* Service class identifier                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVICE_CLASS_ID);//                                            898
                                  /* Service superclass name                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVICE_SUPERCLASS_NAME);//                                     899
                                  /* Service subclass name                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SERVICE_SUBCLASS_NAME);//                                       900
                                  /* Work action set identifier               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WORK_ACTION_SET_ID);//                                          901
                                  /* Work action set name                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WORK_ACTION_SET_NAME);//                                        902
                                  /* Database Work action set ID              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_WORK_ACTION_SET_ID);//                                       903
                                  /* Service_class Work act set ID            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SC_WORK_ACTION_SET_ID);//                                       904
                                  /* Work class identifier                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WORK_CLASS_ID);//                                               905
                                  /* Work class name                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WORK_CLASS_NAME);//                                             906
                                  /* Database Work class ID                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_WORK_CLASS_ID);//                                            907
                                  /* Service_class Work class ID              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SC_WORK_CLASS_ID);//                                            908
                                  /* Workload identifier                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WORKLOAD_ID);//                                                 909
                                  /* Workload occurrance Id                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WORKLOAD_OCCURRENCE_ID);//                                      910
                                  /* Workload name                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WORKLOAD_NAME);//                                               911
                                  /* Temp tablespace usage HWM                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TEMP_TABLESPACE_TOP);//                                         912
                                  /* Actual rows returned HWM                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROWS_RETURNED_TOP);//                                           913
                                  /* HWM for # conc. activities               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONCURRENT_ACT_TOP);//                                          914
                                  /* HWM for # conc. connections              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONCURRENT_CONNECTION_TOP);//                                   915
                                  /* HWM for cost estimate                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COST_ESTIMATE_TOP);//                                           916
                                  /* Statistics timestamp                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STATISTICS_TIMESTAMP);//                                        917
                                  /* Total number of activities               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_TOTAL);//                                                   918
                                  /* No. completed activities                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WLO_COMPLETED_TOTAL);//                                         919
                                  /* HWM for concurrent occurrences of a      */
                                  /* workload                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONCURRENT_WLO_TOP);//                                          920
                                  /* HWM for concurrent activities of any     */
                                  /* occurrance of this workload              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONCURRENT_WLO_ACT_TOP);//                                      921
                                  /* Top end of histogram range               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOP);//                                                         922
                                  /* Bottom end of histog. range              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BOTTOM);//                                                      923
                                  /* Type of histogram                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HISTOGRAM_TYPE);//                                              924
                                  /* Histogram bin identifier                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BIN_ID);//                                                      925

                                  /* Activity Identifier                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVITY_ID);//                                                 926
                                  /* Activity Secondary ID                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVITY_SECONDARY_ID);//                                       927
                                  /* Unit of Work identifier                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_ID);//                                                      928
                                  /* Parent's Activity Id                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PARENT_ACTIVITY_ID);//                                          929
                                  /* Parent's Unit of Work Id                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PARENT_UOW_ID);//                                               930
                                  /* Time the violation occurred              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TIME_OF_VIOLATION);//                                           931
                                  /* Was the activity collected?              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVITY_COLLECTED);//                                          932
                                  /* Type of activity                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVITY_TYPE);//                                               933
                                  /* Type of threshold violated               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_THRESHOLD_PREDICATE);//                                         934
                                  /* Action performed on appl                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_THRESHOLD_ACTION);//                                            935
                                  /* Value that was exceeded                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_THRESHOLD_MAXVALUE);//                                          936
                                  /* Size of the queue exceeded               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_THRESHOLD_QUEUESIZE);//                                         937
                                  /* No. completed activities                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_COMPLETED_TOTAL);//                                   938
                                  /* No. aborted activities                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_ABORTED_TOTAL);//                                     939
                                  /* No. rejected activities                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_REJECTED_TOTAL);//                                    940
                                  /* HWM Coord activity lifetime              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_LIFETIME_TOP);//                                      941
                                  /* Activity execution time                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_EXEC_TIME);//                                               942
                                  /* Time activity was created                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TIME_CREATED);//                                                943
                                  /* Time activity started                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TIME_STARTED);//                                                944
                                  /* Time activity completed                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TIME_COMPLETED);//                                              945
                                  /* Time activity completed                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SECTION_ENV);//                                                 946
                                  /* Time when evmon activated                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVATE_TIMESTAMP);//                                          947
                                  /* # of Threshold Violations                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_THRESHOLD_VIOLATIONS);//                                    948
                                  /* WLM ARM Correlator                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ARM_CORRELATOR);//                                              949
                                  /* Prep time for activity                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PREP_TIME);//                                                   950
                                  /* HWM Queue size                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUEUE_SIZE_TOP);//                                              951
                                  /* No. conn/activ assigned to Q             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUEUE_ASSIGNMENTS_TOTAL);//                                     953
                                  /* Total time spent in queue                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUEUE_TIME_TOTAL);//                                            954
                                  /* Time stats were last reset               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LAST_WLM_RESET);//                                              955
                                  /* Threshold Domain                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_THRESHOLD_DOMAIN);//                                            956
                                  /* Name of threshold resp for Q             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_THRESHOLD_NAME);//                                              957
                                  /* ID of threshold violated                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_THRESHOLDID);//                                                 958
                                  /* # items in Histogram Bin                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUMBER_IN_BIN);//                                               959
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_LIFETIME_AVG);//                                      960
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_QUEUE_TIME_AVG);//                                    961
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_EXEC_TIME_AVG);//                                     962
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_EST_COST_AVG);//                                      963
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_INTERARRIVAL_TIME_AVG);//                             964
ret = PyModule_AddIntMacro(m, SQLM_ELM_REQUEST_EXEC_TIME_AVG);//                                       965

/******************************************************************************/
/* New elements for JITS                                                      */
/******************************************************************************/
                                  /* Statistic cache size                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STATS_CACHE_SIZE);//                                            966
                                  /* number of stats fabrication              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STATS_FABRICATIONS);//                                          967
                                  /* time for stats fabrication               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STATS_FABRICATE_TIME);//                                        968
                                  /* number of synchronous runstats           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SYNC_RUNSTATS);//                                               969
                                  /* time for synchronous runstats            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SYNC_RUNSTATS_TIME);//                                          970
                                  /* number of asynchronous runstats          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ASYNC_RUNSTATS);//                                              971


/* Memory Pool List element                                                   */
                                  /* Pool List identifier                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_POOL_LIST_ID);//                                                972

                                  /* Is app a system application?             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_IS_SYSTEM_APPL);//                                              973
                                  /* Time to insert(from all apps)            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INSERT_TIMESTAMP);//                                            974
                                  /* Maximum value of high water mark         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_MAX_PAGE_TOP);//                                     975
                                  /* path with db partition expression        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_STORAGE_PATH_WITH_DPE);//                                    976
                                  /* state of storage path                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB_STORAGE_PATH_STATE);//                                       977
                                  /* underlying storage paths dropped         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_PATHS_DROPPED);//                                    978
ret = PyModule_AddIntMacro(m, SQLM_ELM_DESTINATION_SERVICE_CLASS_ID);//                                979
ret = PyModule_AddIntMacro(m, SQLM_ELM_SOURCE_SERVICE_CLASS_ID);//                                     980
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_REMAPPED_IN);//                                             981
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_REMAPPED_OUT);//                                            982
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGG_TEMP_TABLESPACE_TOP);//                                     983
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_REMAPS);//                                                  984
                                  /* Unit of work total time high watermark   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_TOTAL_TIME_TOP);//                                          985
                                  /* IP address of the host returning this    */
                                  /* information                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADDRESS);//                                                   45001
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_CPU_TIME_TOP);//                                            986
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_ROWS_READ_TOP);//                                           987
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_WAIT_TIME_TOP);//                                          988
                                  /*  Metrics exposed as an XML document. For */
                                  /* details please see the XML Schema in     */
                                  /* sqllib/misc/DB2MonMetrics.xsd            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DETAILS_XML);//                                                 989
                                  /* Opaque token that uniquely identifies a  */
                                  /* section that has been executed.          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EXECUTABLE_ID);//                                               990
                                  /* Effective statement text after any       */
                                  /* literal replacement by statement         */
                                  /* concentrator.                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EFF_STMT_TEXT);//                                               991
                                  /* Unique routine identifier.               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ROUTINE_ID);//                                                  992
                                  /* Internal binary string containing        */
                                  /* runtime section statistics.              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SECTION_ACTUALS);//                                             993
                                  /* Unit of work event monitor record        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_EVENT);//                                                   994
                                  /* Unit of work completion status           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CMPSTATUS);//                                                   995
                                  /* Application connect time                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONNTIME);//                                                    996
                                  /* Application handle                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_APP_HANDLE);//                                                  997
                                  /* The coordinating member for this         */
                                  /* application                              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_MEMBER);//                                                998
                                  /* The activation time of this member       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMBER_ACT_TIME);//                                             999
                                  /* The system authorization id              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SYSTEM_AUTH_ID);//                                            45952
                                  /* The local transaction id                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCAL_TID);//                                                  1000
                                  /* The global transaction id                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_GXID);//                                                       1001
                                  /* System metrics data                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SYSTEM_METRICS);//                                             1002
                                  /* XML document event id attribute          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ATTR_EVENT_ID);//                                              1003
                                  /* XML document type attribute              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ATTR_TYPE);//                                                  1004
                                  /* XML document timestamp attribute         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ATTR_TIMESTAMP);//                                             1005
                                  /* XML document member attribute            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ATTR_MEMBER);//                                                1006
                                  /* XML document release attribute           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ATTR_RELEASE);//                                               1007
                                  /* Host name of the client application      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_HOSTNAME);//                                            1008
                                  /* Port number of the client application    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_PORT);//                                                1009
                                  /* Package list for this unit of work       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKGLIST);//                                                    1010
                                  /* Package list size for this unit of work  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKGLIST_SIZE);//                                               1011
                                  /* Package list entries for this unit of    */
                                  /* work                                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKGLIST_ENTRIES);//                                            1012
                                  /* Single package list entry for this unit  */
                                  /* of work                                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKGLIST_ENTRY);//                                              1013
                                  /* Package list size was exceeded within    */
                                  /* the unit of work                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_PKGLIST_EXCEEDED);//                                           1014
                                  /* Workload Work act set ID                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WL_WORK_ACTION_SET_ID);//                                      1015
                                  /* Workload Work class ID                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_WL_WORK_CLASS_ID);//                                           1016
/* Total elapsed delta time taken between two snapshots                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_SYS_CPU_DELTA_TIME);//       1017 /* System CPU delta time */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_USR_CPU_DELTA_TIME);//       1018 /*   User CPU delta time */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BUFF_MAX);//                     1019 /*    max # of FCM buffers */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CH_TOTAL);//                    45634 /* total # of FCM channels */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CH_MAX);//                       1020 /*   max # of FCM channels */
ret = PyModule_AddIntMacro(m, SQLM_ELM_LOCK_WAIT_TIME_GLOBAL_TOP);//                                  1021
                                              /* Trackmod state of tablespace */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_TRACKMOD_STATE);//                                  1022
                                  /* DB member                                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DBPARTITIONNUM);//                                             1023
                                  /* Coordinating DB Partition number         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_DBPARTITIONNUM);//                                       1024
                                  /* Unit of work throughout                  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_THROUGHPUT);//                                             1025
                                  /* Unit of Work Lifetime Average            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_LIFETIME_AVG);//                                           1026
                                  /* Unit of Work Completed Total             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_UOW_COMPLETED_TOTAL);//                                        1027
                                  /* Total CPU Time                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_CPU_TIME);//                                             1028
                                  /* Total Dispacther Run Queue Time          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_DISP_RUN_QUEUE_TIME);//                                  1029
                                  /* Activities Throuhput                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_THROUGHPUT);//                                             1030
                                  /* CPU Utilization                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_UTILIZATION);//                                            1031
                                  /* List of data tags of data table spaces   */
                                  /* accessed by statement.                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUERY_DATA_TAG_LIST);//                                        1032
                                  /* Query's actual degree of parallelism     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_QUERY_ACTUAL_DEGREE);//                                        1033
                                  /* total # of FCM buffers                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_BUFF_TOTAL);//                                                45633

                                  /* Executable list for this unit of work    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EXECLIST);//                                                   1034
                                  /* Executable list size for this unit of    */
                                  /* work                                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EXECLIST_SIZE);//                                              1035
                                  /* Executable list was truncated within the */
                                  /* unit of work                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EXECLIST_TRUNCATED);//                                         1036
                                  /* Executable list entries for this unit of */
                                  /* work                                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EXECLIST_ENTRIES);//                                           1037
                                  /* Single executable list entry for this    */
                                  /* unit of work                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EXECLIST_ENTRY);//                                             1038
                                  /* Total stats fabrication time             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_STATS_FABRICATION_TIME);//                               1039
                                  /* Total stats fabrications                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_STATS_FABRICATIONS);//                                   1040
                                  /* Total synchronous runstats time          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_SYNC_RUNSTATS_TIME);//                                   1041
                                  /* Total synchronous runstats               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_SYNC_RUNSTATS);//                                        1042
                                  /* Total connect request time               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_CONNECT_REQUEST_TIME);//                                 1043
                                  /* Total connect requests                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_CONNECT_REQUESTS);//                                     1044
                                  /* Total connect authentication time        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_CONNECT_AUTHENTICATION_TIME);//                          1045
                                  /* Total connect authentications            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TOTAL_CONNECT_AUTHENTICATIONS);//                              1046

/* new to Galileo */

                                  /* Monitoring interval ID                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MON_INTERVAL_ID);//                                            1047
                                  /* total # of non-nested coordinator        */
                                  /* completed activities                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_APP_ACT_COMPLETED_TOTAL);//                              1048
                                  /* total # of non-nested coordinator        */
                                  /* aborted activities                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_APP_ACT_ABORTED_TOTAL);//                                1049
                                  /* total # of non-nested coordinator        */
                                  /* rejected activities                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_APP_ACT_REJECTED_TOTAL);//                               1050
                                  /*  Delta metrics exposed as an XML         */
                                  /* document. For details please see the XML */
                                  /* Schema in sqllib/misc/DB2MonMetrics.xsd  */

#ifndef SQLM_ELM_METRICS
#define SQLM_ELM_METRICS               1051
#define SQLM_ELM_CLIENT_PORT_NUMBER    1052
#define SQLM_ELM_CONNECTION_START_TIME 1053
#define SQLM_ELM_STMTNO                1054
#define SQLM_ELM_NUM_ROUTINES          1055
#define SQLM_ELM_CPU_TOTAL             1056
#define SQLM_ELM_CPU_ONLINE            1057
#define SQLM_ELM_CPU_CONFIGURED        1058
#define SQLM_ELM_CPU_SPEED             1059
#define SQLM_ELM_CPU_TIMEBASE          1060
#define SQLM_ELM_CPU_HMT_DEGREE        1061
#define SQLM_ELM_CPU_CORES_PER_SOCKET  1062
#define SQLM_ELM_MEMORY_TOTAL          1063
#define SQLM_ELM_MEMORY_FREE                                                1064
#define SQLM_ELM_MEMORY_SWAP_TOTAL                                          1065
#define SQLM_ELM_MEMORY_SWAP_FREE                                           1066
#define SQLM_ELM_VIRTUAL_MEM_TOTAL                                          1067
#define SQLM_ELM_VIRTUAL_MEM_RESERVED                                       1068
#define SQLM_ELM_VIRTUAL_MEM_FREE                                           1069
#define SQLM_ELM_CPU_LOAD_SHORT                                             1070
#define SQLM_ELM_CPU_LOAD_MEDIUM                                            1071
#define SQLM_ELM_CPU_LOAD_LONG                                              1072
#define SQLM_ELM_CPU_USAGE_TOTAL                                            1073
#define SQLM_ELM_CPU_USER                                                   1074
#define SQLM_ELM_CPU_IDLE                                                   1075
#define SQLM_ELM_CPU_IOWAIT                                                 1076
#define SQLM_ELM_CPU_SYSTEM                                                 1077
#define SQLM_ELM_SWAP_PAGE_SIZE                                             1078
#define SQLM_ELM_SWAP_PAGES_IN                                              1079
#define SQLM_ELM_SWAP_PAGES_OUT                                             1080
#define SQLM_ELM_INTRA_PARALLEL_STATE                                       1081
#define SQLM_ELM_MEMBER_SUBSET_ID                                          47045
#define SQLM_ELM_ACTIVE_HASH_GRPBYS_TOP                                     1082
#define SQLM_ELM_ACTIVE_HASH_JOINS_TOP                                      1083
#define SQLM_ELM_ACTIVE_OLAP_FUNCS_TOP                                      1084
#define SQLM_ELM_ACTIVE_PEAS_TOP                                            1085
#define SQLM_ELM_ACTIVE_PEDS_TOP                                            1086
#define SQLM_ELM_ACTIVE_SORT_CONSUMERS_TOP                                  1087
#define SQLM_ELM_ACTIVE_SORTS_TOP                                           1088
#define SQLM_ELM_ACTIVE_COL_VECTOR_CONSUMERS_TOP                            1089
#define SQLM_ELM_SORT_CONSUMER_HEAP_TOP                                     1090
#define SQLM_ELM_SORT_CONSUMER_SHRHEAP_TOP                                  1091
#define SQLM_ELM_EFFECTIVE_QUERY_DEGREE                                    55358
#define SQLM_ELM_ADM_BYPASSED                                               1092
#define SQLM_ELM_ESTIMATED_SORT_SHRHEAP_TOP                                 1093
#define SQLM_ELM_ESTIMATED_SORT_CONSUMERS_TOP                               1094
#define SQLM_ELM_ESTIMATED_RUNTIME                                          1095
#define SQLM_ELM_ADM_RESOURCE_ACTUALS                                       1096
#define SQLM_ELM_ACTUAL_PARALLELISM_AVG                                     1097
#define SQLM_ELM_ACTUAL_PARALLELISM_TOP                                     1098
#define SQLM_ELM_AGENT_LOAD_TRGT_UTILIZATION_AVG                            1099
#define SQLM_ELM_AGENT_LOAD_TRGT_UTILIZATION_TOP                            1100
#define SQLM_ELM_COORD_ACT_EXEC_TIME_STDDEV                                 1101
#define SQLM_ELM_COORD_ACT_LIFETIME_STDDEV                                  1102
#define SQLM_ELM_COORD_ACT_QUEUE_TIME_STDDEV                                1103
#define SQLM_ELM_COORD_ACT_EST_COST_STDDEV                                  1104
#define SQLM_ELM_COORD_ACT_INTERARRIVAL_TIME_STDDEV                         1105
#define SQLM_ELM_CPU_ENTITLEMENT                                            1106
#define SQLM_ELM_CPU_SHARE_TYPE                                             1107
#define SQLM_ELM_EFF_PARALLELISM_AVG                                        1108
#define SQLM_ELM_EFF_PARALLELISM_TOP                                        1109
#define SQLM_ELM_RESOURCE_ENTITLEMENT                                       1110
#define SQLM_ELM_RESOURCE_SHARES                                            1111
#define SQLM_ELM_RESOURCE_SHARE_TYPE                                        1112
#define SQLM_ELM_SORT_SHRHEAP_AVG                                           1113
#define SQLM_ELM_SORT_SHRHEAP_UTILIZATION_AVG                               1114
#define SQLM_ELM_SORT_SHRHEAP_UTILIZATION_TOP                               1115
#define SQLM_ELM_SORT_SHRHEAP_DEMAND_AVG                                    1116
#define SQLM_ELM_SORT_SHRHEAP_DEMAND_TOP                                    1117
#define SQLM_ELM_AGENT_LOAD_TRGT_DEMAND_AVG                                 1118
#define SQLM_ELM_AGENT_LOAD_TRGT_DEMAND_TOP                                 1119
#define SQLM_ELM_ADM_RUNNING_ACT_LOAD                                       1120
#define SQLM_ELM_ADM_QUEUED_ACT_LOAD                                        1121
#define SQLM_ELM_ADM_BYPASSED_ACT_LOAD                                      1122
#define SQLM_ELM_ADM_RUNNING_ACT_TIME                                       1123
#define SQLM_ELM_ADM_QUEUED_ACT_TIME                                        1124
#define SQLM_ELM_ADM_BYPASSED_ACT_TIME                                      1125
#define SQLM_ELM_ACT_TOP                                                    1126

#endif

#ifndef SQLM_ELM_ADM_RESOURCE_ACTUALS
#define SQLM_ELM_ADM_RESOURCE_ACTUALS                                       1096
#define SQLM_ELM_ACTUAL_PARALLELISM_AVG                                     1097
#define SQLM_ELM_ACTUAL_PARALLELISM_TOP                                     1098
#define SQLM_ELM_AGENT_LOAD_TRGT_UTILIZATION_AVG                            1099
#define SQLM_ELM_AGENT_LOAD_TRGT_UTILIZATION_TOP                            1100
#define SQLM_ELM_COORD_ACT_EXEC_TIME_STDDEV                                 1101
#define SQLM_ELM_COORD_ACT_LIFETIME_STDDEV                                  1102
#define SQLM_ELM_COORD_ACT_QUEUE_TIME_STDDEV                                1103
#define SQLM_ELM_COORD_ACT_EST_COST_STDDEV                                  1104
#define SQLM_ELM_COORD_ACT_INTERARRIVAL_TIME_STDDEV                         1105
#define SQLM_ELM_CPU_ENTITLEMENT                                            1106
#define SQLM_ELM_CPU_SHARE_TYPE                                             1107
#define SQLM_ELM_EFF_PARALLELISM_AVG                                        1108
#define SQLM_ELM_EFF_PARALLELISM_TOP                                        1109
#define SQLM_ELM_RESOURCE_ENTITLEMENT                                       1110
#define SQLM_ELM_RESOURCE_SHARES                                            1111
#define SQLM_ELM_RESOURCE_SHARE_TYPE                                        1112
#define SQLM_ELM_SORT_SHRHEAP_AVG                                           1113
#define SQLM_ELM_SORT_SHRHEAP_UTILIZATION_AVG                               1114
#define SQLM_ELM_SORT_SHRHEAP_UTILIZATION_TOP                               1115
#define SQLM_ELM_SORT_SHRHEAP_DEMAND_AVG                                    1116
#define SQLM_ELM_SORT_SHRHEAP_DEMAND_TOP                                    1117
#define SQLM_ELM_AGENT_LOAD_TRGT_DEMAND_AVG                                 1118
#define SQLM_ELM_AGENT_LOAD_TRGT_DEMAND_TOP                                 1119
#define SQLM_ELM_ADM_RUNNING_ACT_LOAD                                       1120
#define SQLM_ELM_ADM_QUEUED_ACT_LOAD                                        1121
#define SQLM_ELM_ADM_BYPASSED_ACT_LOAD                                      1122
#define SQLM_ELM_ADM_RUNNING_ACT_TIME                                       1123
#define SQLM_ELM_ADM_QUEUED_ACT_TIME                                        1124
#define SQLM_ELM_ADM_BYPASSED_ACT_TIME                                      1125
#define SQLM_ELM_ACT_TOP                                                    1126

#endif

ret = PyModule_AddIntMacro(m, SQLM_ELM_METRICS);//                                                    1051
                                  /* client port number                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CLIENT_PORT_NUMBER);//                                         1052
                                  /* connection start time                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONNECTION_START_TIME);//                                      1053
                                  /* statement number for static statements   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_STMTNO);//                                                     1054
                                  /* number of routines that may be invoked   */
                                  /* by statement                             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_NUM_ROUTINES);//                                               1055
/* New to Kepler - Part of os_metrics logical group */
                                       /* CPU total                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_TOTAL);//                                                  1056
                                       /* CPU online                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_ONLINE);//                                                 1057
                                       /* CPU configured                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_CONFIGURED);//                                             1058
                                       /* CPU speed                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_SPEED);//                                                  1059
                                       /* CPU timebase                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_TIMEBASE);//                                               1060
                                       /* CPU hmt degree                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_HMT_DEGREE);//                                             1061
                                       /* Number of CPU cores for each socket */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_CORES_PER_SOCKET);//                                       1062
                                       /* Memory total                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMORY_TOTAL);//                                               1063
                                       /* Memory free                         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMORY_FREE);//                                                1064
                                       /* Memory swap total                   */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMORY_SWAP_TOTAL);//                                          1065
                                       /* Memory swap free                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMORY_SWAP_FREE);//                                           1066
                                       /* Virtual memory total                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_VIRTUAL_MEM_TOTAL);//                                          1067
                                       /* Virtual memory reserved             */
ret = PyModule_AddIntMacro(m, SQLM_ELM_VIRTUAL_MEM_RESERVED);//                                       1068
                                       /* Virtual memory free                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_VIRTUAL_MEM_FREE);//                                           1069
                                       /* CPU load short                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_LOAD_SHORT);//                                             1070
                                       /* CPU load medium                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_LOAD_MEDIUM);//                                            1071
                                       /* CPU load long                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_LOAD_LONG);//                                              1072
                                       /* CPU usage total                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_USAGE_TOTAL);//                                            1073
                                       /* CPU user                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_USER);//                                                   1074
                                       /* CPU idle                            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_IDLE);//                                                   1075
                                       /* CPU IO wait time                    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_IOWAIT);//                                                 1076
                                       /* CPU system                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_SYSTEM);//                                                 1077
                                       /* Swap page size                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SWAP_PAGE_SIZE);//                                             1078
                                       /* Swap page in                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SWAP_PAGES_IN);//                                              1079
                                       /* Swap page out                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SWAP_PAGES_OUT);//                                             1080
                                      /*  Intra Parallel state                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_INTRA_PARALLEL_STATE);//                                       1081
                                      /* Unique identifier of a member subset */
ret = PyModule_AddIntMacro(m, SQLM_ELM_MEMBER_SUBSET_ID);//                                          47045
                                            /* active hash grpbys HWM         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_HASH_GRPBYS_TOP);//                                     1082
                                            /* active hash joins HWM          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_HASH_JOINS_TOP);//                                      1083
                                            /* active olap funs HWM           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_OLAP_FUNCS_TOP);//                                      1084
                                            /* active peas HWM                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_PEAS_TOP);//                                            1085
                                            /* active peds HWM                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_PEDS_TOP);//                                            1086
                                            /* active sort consumers HWM      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_SORT_CONSUMERS_TOP);//                                  1087
                                            /* active sort consumers HWM      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_SORTS_TOP);//                                           1088
                                            /* active work unit consumers HWM */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTIVE_COL_VECTOR_CONSUMERS_TOP);//                            1089
                                            /* sort consumer heap HWM         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_CONSUMER_HEAP_TOP);//                                     1090
                                            /* sort consumer shrheap HWM      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_CONSUMER_SHRHEAP_TOP);//                                  1091
                                   /* Query's effective degree of parallelism */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EFFECTIVE_QUERY_DEGREE);//                                    55358
                                  /* Query bypassed admission control         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_BYPASSED);//                                               1092
                                  /* Estimated peak shared sort memory usage  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ESTIMATED_SORT_SHRHEAP_TOP);//                                 1093
                                  /* Estimated peak sort memory consumers     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ESTIMATED_SORT_CONSUMERS_TOP);//                               1094
                                  /* Estimated runtime                        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ESTIMATED_RUNTIME);//                                          1095
                                  /* Query is using estimates from a previous */
                                  /* execution.                               */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_RESOURCE_ACTUALS);//                                       1096
                                  /* Average parallelism                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTUAL_PARALLELISM_AVG);//                                     1097
                                  /* Max parallelism                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACTUAL_PARALLELISM_TOP);//                                     1098
                                  /* Average load utilization                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_LOAD_TRGT_UTILIZATION_AVG);//                            1099
                                  /* Max load utilization                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_LOAD_TRGT_UTILIZATION_TOP);//                            1100
                                  /* Coord activity execution time std dev    */

ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_EXEC_TIME_STDDEV);//                                 1101
                                  /* Coord activity life time std dev         */
//#ifndef DB2DARWIN

ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_LIFETIME_STDDEV);//                                  1102
                                  /* Coord activity queue time std dev        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_QUEUE_TIME_STDDEV);//                                1103
                                  /* Coord activity estimated cost std dev    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_EST_COST_STDDEV);//                                  1104
                                  /* Coord activity interarrival time std dev */
ret = PyModule_AddIntMacro(m, SQLM_ELM_COORD_ACT_INTERARRIVAL_TIME_STDDEV);//                         1105
                                  /* CPU entitlement                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_ENTITLEMENT);//                                            1106
                                  /* CPU share type                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CPU_SHARE_TYPE);//                                             1107
                                  /* Average current parallelism              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EFF_PARALLELISM_AVG);//                                        1108
                                  /* Max parallelism                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_EFF_PARALLELISM_TOP);//                                        1109
                                  /* Resource entitlement                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RESOURCE_ENTITLEMENT);//                                       1110
                                  /* Resource shares                          */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RESOURCE_SHARES);//                                            1111
                                  /* Resource share type                      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_RESOURCE_SHARE_TYPE);//                                        1112
                                  /* Shared sort heap avg                     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SHRHEAP_AVG);//                                           1113
                                  /* Shared sort heap utilization avg         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SHRHEAP_UTILIZATION_AVG);//                               1114
                                  /* Shared sort heap utilization top         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SHRHEAP_UTILIZATION_TOP);//                               1115
                                  /* Admission shared sort heap demand avg    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SHRHEAP_DEMAND_AVG);//                                    1116
                                  /* Admission shared sort heap demand top    */
ret = PyModule_AddIntMacro(m, SQLM_ELM_SORT_SHRHEAP_DEMAND_TOP);//                                    1117
                                  /* Admission average load demand            */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_LOAD_TRGT_DEMAND_AVG);//                                 1118
                                  /* Admission load demand top                */
ret = PyModule_AddIntMacro(m, SQLM_ELM_AGENT_LOAD_TRGT_DEMAND_TOP);//                                 1119
                                  /* Load of activities running inside        */
                                  /* admission control.                       */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_RUNNING_ACT_LOAD);//                                       1120
                                  /* Load of activity queued inside admission */
                                  /* control.                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_QUEUED_ACT_LOAD);//                                        1121
                                  /* Load of activities bypassing admission   */
                                  /* control.                                 */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_BYPASSED_ACT_LOAD);//                                      1122
                                  /* Time spent executing activities that     */
                                  /* passed through admission control.        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_RUNNING_ACT_TIME);//                                       1123
                                  /* Time spent queued while waiting for      */
                                  /* admission control to admit an activity.  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_QUEUED_ACT_TIME);//                                        1124
                                  /* Time spent executing activities that     */
                                  /* bypassed admission control.              */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ADM_BYPASSED_ACT_TIME);//                                      1125
                                  /* Activities top                           */
ret = PyModule_AddIntMacro(m, SQLM_ELM_ACT_TOP);//                                                    1126

//#endif

/******************************************************************************/
/*                                                                            */
/* The following describes the elements found in the SQLM_CLASS_HEALTH        */
/* and SQLM_CLASS_HEALTH_WITH_DETAIL snapshot types. There can be more than   */
/* one SQLM_ELM_HEALTH_INDICATOR and SQLM_ELM_HEALTH_INDICATOR_HIST.          */
/* SQLM_ELM_HEALTH_INDICATOR_HIST is only present in health snapshot with     */
/* details.                                                                   */
/*                                                                            */
/* There will be only one NODEINFO stream for a single partition snapshot. A  */
/* global snapshot will contain a NODEINFO stream for each partition with an  */
/* activate Health Monitor.                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* Typical health snapshot hierarchy:                                         */
/*                                                                            */
/* SQLM_ELM_COLLECTED                                                         */
/*    +- DB2                                                                  */
/*          +- HEALTH_INDICATOR                                               */
/*                +- HEALTH_INDICATOR_HIST (only with details)                */
/*    +- DBASE                                                                */
/*          +- HEALTH_INDICATOR                                               */
/*                +- HEALTH_INDICATOR_HIST (only with details)                */
/*    +- TABLESPACE_LIST                                                      */
/*          +- TABLESPACE                                                     */
/*                +- HEALTH_INDICATOR                                         */
/*                      +- HEALTH_INDICATOR_HIST (only with details)          */
/*                +- NODEINFO (ESE only, otherwise TSCs are here)             */
/*                      +- TABLESPACE_CONTAINER                               */
/*                            +- HEALTH_INDICATOR                             */
/*                               +- HEALTH_INDICATOR_HIST (only with details) */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/* Hierarchy of elements under SQLM_ELM_HI and SQLM_ELM_HI_HIST:              */
/*                                                                            */
/*  +- HEALTH_INDICATOR                                                       */
/*        SQLM_ELM_HI_ID                                                      */
/*        SQLM_ELM_HI_VALUE                                                   */
/*        +- SQLM_ELM_HI_TIMESTAMP                                            */
/*              SQLM_ELM_SECONDS                                              */
/*              SQLM_ELM_MICROSEC                                             */
/*        SQLM_ELM_HI_ALERT_STATE                                             */
/*        +- SQLM_ELM_HI_OBJ_LIST                                             */
/*              SQLM_ELM_HI_OBJ_NAME                                          */
/*              SQLM_ELM_HI_OBJ_DETAIL                                        */
/*              SQLM_ELM_HI_OBJ_STATE                                         */
/*              +- SQLM_ELM_HI_TIMESTAMP                                      */
/*                    SQLM_ELM_SECONDS                                        */
/*                    SQLM_ELM_MICROSEC                                       */
/*              +- SQLM_ELM_HI_OBJ_LIST_HIST      (only with details)         */
/*                    SQLM_ELM_HI_OBJ_STATE                                   */
/*                    +- SQLM_ELM_HI_TIMESTAMP                                */
/*                          SQLM_ELM_SECONDS                                  */
/*                          SQLM_ELM_MICROSEC                                 */
/*                                                                            */
/* (The following is additional info present in SQLM_CLASS_HEALTH_WITH_DETAIL */
/*  snapshot only.)                                                           */
/*                                                                            */
/*        SQLM_ELM_HI_FORMULA                                                 */
/*        SQLM_ELM_HI_ADDITIONAL_INFO                                         */
/*        +- SQLM_ELM_HEALTH_INDICATOR_HIST                                   */
/*              SQLM_ELM_HI_ID                                                */
/*              SQLM_ELM_HI_VALUE                                             */
/*              +- SQLM_ELM_HI_TIMESTAMP                                      */
/*                    SQLM_ELM_SECONDS                                        */
/*                    SQLM_ELM_MICROSEC                                       */
/*              SQLM_ELM_HI_ALERT_STATE                                       */
/*              SQLM_ELM_HI_FORMULA                                           */
/*              SQLM_ELM_HI_ADDITIONAL_INFO                                   */
/*                                                                            */
/******************************************************************************/

/* Health snapshot only elements. These are not found in the standard         */
/* snapshots but can be present in snapshot with and without details.         */
/* Used under SQLM_ELM_HEALTH INDICATOR and SQLM_ELM_HEALTH_INDICATOR_HIST    */
/* logical group.                                                             */

                                               /* health indicator number     */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_ID);//                                                     55001
                                               /* health indicator value      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_VALUE);//                                                  55002
                                               /* health indicator state      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_ALERT_STATE);//                                            55003
                                               /* state of sub dbm obj        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DB2_ROLLED_UP_ALERT_STATE);//                                 55004
                                               /* state of sub db obj         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_DATABASE_ROLLED_UP_ALERT_STATE);//                            55005
                                               /* state of sub ts obj         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_TABLESPACE_ROLLED_UP_ALERT_STATE);//                          55006
                                               /* state of TSContainer        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_CONTAINER_ROLLED_UP_ALERT_STATE);//                           55007
                                               /* hi collection object        */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_OBJ_NAME);//                                               55008
                                               /* hi collection object detail */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_OBJ_DETAIL);//                                             55009
                                               /* hi collection object state  */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_OBJ_STATE);//                                              55010

/* the following are for health snapshot with detail only                     */
                                               /* formula used for value      */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_FORMULA);//                                                55101
                                               /* more info available         */
ret = PyModule_AddIntMacro(m, SQLM_ELM_HI_ADDITIONAL_INFO);//                                        55102



/******************************************************************************/
/* The folowing macros define the health indicators and are present in the    */
/* sqlm_header_data.data field when sqlm_header_data.header.element is        */
/* SQLM_ELM_HI_ID.                                                            */
/******************************************************************************/


/******************************************************************************/
/* Health snapshot elements under SQLM_ELM_DB2 logical grouping:              */
/*                                                                            */
/* +- SQLM_ELM_DB2                                                            */
/*       (also present in standard system snapshots)                          */
/*       SQLM_ELM_DB2START_TIME                                               */
/*       SQLM_ELM_NUM_NODES_IN_DB2_INSTANCE                                   */
/*       (new for health snapshot)                                            */
/*       SQLM_ELM_DB2_ROLLED_UP_ALERT_STATE                                   */
/*       SQLM_ELM_HEALTH_INDICATOR                                            */
/******************************************************************************/

/* these are possible values for SQLM_ELM_HEALTH_INDICATOR -- SQLM_ELM_HI_ID  */
/* under the SQLM_ELM_DB2 logical group                                       */
#define SQLM_HI_DB2_STATE                            1 /* state of db2        */
#define SQLM_HI_DB2_PRIVATE_SORT_MEM_UTILIZATION     2 /* sorting memory util */
#define SQLM_HI_DB2_MAX_PRIVATE_SORT_MEM_UTILIZATION 3 /* max sorting memory  */
#define SQLM_HI_DB2_MON_HEAP_UTILIZATION             4 /* monitor heap util   */



/******************************************************************************/
/* Health snapshot elements under SQLM_ELM_DB logical grouping:               */
/*                                                                            */
/* +- SQLM_ELM_DB                                                             */
/*       (also present in standard system snapshots)                          */
/*       SQLM_ELM_DB_LOCATION                                                 */
/*       SQLM_ELM_SERVER_PLATFORM                                             */
/*       SQLM_ELM_INPUT_DB_ALIAS                                              */
/*       SQLM_ELM_DB_NAME                                                     */
/*       SQLM_ELM_DB_PATH                                                     */
/*       (new for health snapshot)                                            */
/*       SQLM_ELM_DATABASE_ROLLED_UP_ALERT_STATE                              */
/*       SQLM_ELM_HEALTH_INDICATOR                                            */
/******************************************************************************/

/* these are possible values for SQLM_ELM_HEALTH_INDICATOR -- SQLM_ELM_HI_ID  */
/* under the SQLM_ELM_DATABASE logical group                                  */
#define SQLM_HI_DATABASE_STATE                  1001 /* state of the database */
#define SQLM_HI_DATABASE_SHARED_SORT_MEM_UTILIZATION 1002 /* shared sorting mem util */
#define SQLM_HI_DATABASE_SPILLED_SORTS          1003 /* percent sort overflow */
#define SQLM_HI_DATABASE_MAX_SHARED_SORT_MEM_UTILIZATION 1004 /* max sort mem used */
#define SQLM_HI_DATABASE_LOG_UTILIZATION        1005 /* fullness of transaction log */
#define SQLM_HI_DATABASE_LOG_FILESYSTEM_UTILIZATION 1006 /* fullness of log FS */
#define SQLM_HI_DATABASE_DEADLOCK_RATE          1007 /* rate of deadlock      */
#define SQLM_HI_DATABASE_LOCKLIST_UTILIZATION   1008 /* locklist util         */
#define SQLM_HI_DATABASE_LOCK_ESCALATION_RATE   1009 /* DB lock esc. rate     */
#define SQLM_HI_DATABASE_APPS_WAITING_ON_LOCKS  1010 /* percent apps waiting on locks */
#define SQLM_HI_DATABASE_PKGCACHE_HITRATIO      1011 /* package cache hitratio*/
#define SQLM_HI_DATABASE_CATCACHE_HITRATIO      1012 /* catalog cache hitratio*/
#define SQLM_HI_DATABASE_SHRWORKSPACE_HITRATIO  1013 /* shared SQL workspace hitratio */
#define SQLM_HI_DATABASE_HEAP_UTILIZATION       1014 /* heap utilization      */
#define SQLM_HI_DATABASE_TB_REORG_REQ           1015 /* manual reorg required */
#define SQLM_HI_DATABASE_HADR_OP_STATUS         1016 /* hadr op status */
#define SQLM_HI_DATABASE_HADR_DELAY             1017 /* hadr delay */
#define SQLM_HI_DATABASE_BACKUP_REQ             1018 /* manual backup required */
#define SQLM_HI_DATABASE_FED_NICKNAME_STATUS    1019 /* invalid fed nicknames */
#define SQLM_HI_DATABASE_FED_SERVER_STATUS      1020 /* fed server status */
#define SQLM_HI_DATABASE_TB_STATS_REQ           1022 /* runstats */
#define SQLM_HI_DATABASE_AUTO_STORAGE_UTILIZATION 1023 /* auto storage uti */

/******************************************************************************/
/* Health snapshot elements under SQLM_ELM_TABLESPACE_LIST logical grouping:  */
/*                                                                            */
/* +- SQLM_ELM_TABLESPACE_LIST                                                */
/*       (also present in standard system snapshots)                          */
/*       SQLM_ELM_DB_NAME                                                     */
/*       SQLM_ELM_DB_PATH                                                     */
/*       SQLM_ELM_INPUT_DB_ALIAS                                              */
/*       (new for health snapshot)                                            */
/*       //none for now                                                       */
/******************************************************************************/


/******************************************************************************/
/* Health snapshot elements under SQLM_ELM_TABLESPACE logical grouping:       */
/*                                                                            */
/* +- SQLM_ELM_TABLESPACE                                                     */
/*       (also present in standard system snapshots)                          */
/*       SQLM_ELM_TABLESPACE_NAME                                             */
/*       (new for health snapshot)                                            */
/*       SQLM_ELM_TABLESPACE_ROLLED_UP_ALERT_STATE                            */
/*       SQLM_ELM_HEALTH_INDICATOR                                            */
/******************************************************************************/

/* these are possible values for SQLM_ELM_HEALTH_INDICATOR -- SQLM_ELM_HI_ID  */
/* under the SQLM_ELM_TABLESPACE logical group                                */
#define SQLM_HI_TABLESPACE_STATE                  2001 /* tablespace state    */
#define SQLM_HI_TABLESPACE_UTILIZATION            2002 /* tablespace util     */
#define SQLM_HI_TABLESPACE_AUTO_RESIZE_STATUS     2003 /* tablespace resize status */
#define SQLM_HI_AUTO_RESIZE_TABLESPACE_UTILIZATION 2004 /* auto-resize tablespace util */



/******************************************************************************/
/* Health snapshot elements under SQLM_ELM_TABLESPACE_CONTAINER logical group */
/*                                                                            */
/* +- SQLM_ELM_TABLESPACE_CONTAINER                                           */
/*       (also present in standard system snapshots)                          */
/*       SQLM_ELM_CONTAINER_NAME                                              */
/*       (new for health snapshot)                                            */
/*       SQLM_ELM_HEALTH_INDICATOR                                            */
/******************************************************************************/

/* these are possible values for SQLM_ELM_HEALTH_INDICATOR -- SQLM_ELM_HI_ID  */
/* under the SQLM_ELM_TABLESPACE_CONTAINER logical group                      */
#define SQLM_HI_TABLESPACE_CONTAINER_STATE        3001 /* TSC state           */
#define SQLM_HI_TABLESPACE_CONTAINER_UTILIZATION  3002 /* TSC utilization     */





/******************************************************************************/
/* Health snapshot alert state values.                                        */
/*                                                                            */
/* Those states can be used as values of the following health snapshot        */
/* elements:                                                                  */
/*                                                                            */
/*    SQLM_ELM_HI_ALERT_STATE                                                 */
/*    SQLM_ELM_DB2_ROLLED_UP_ALERT_STATE                                      */
/*    SQLM_ELM_DATABASE_ROLLED_UP_ALERT_STATE                                 */
/*    SQLM_ELM_TABLESPACE_ROLLED_UP_ALERT_STATE                               */
/*    SQLM_ELM_HI_OBJ_STATE                                                   */
/*                                                                            */
/* Keep the values as different bits as we might run actions on combinations  */
/* of those alert states.                                                     */
/* NOTE: Currently, all the AUTOMATED states are only applicable for          */
/*       collection object state. These values are not valid for health       */
/*       indicator states.                                                    */
/*                                                                            */
/******************************************************************************/

#define SQLM_HI_ALERT_STATE_UNKNOWN         0
#define SQLM_HI_ALERT_STATE_NORMAL          1
#define SQLM_HI_ALERT_STATE_ATTENTION       2
#define SQLM_HI_ALERT_STATE_WARNING         3
#define SQLM_HI_ALERT_STATE_ALARM           4
#define SQLM_HI_ALERT_STATE_AUTOMATED       5
#define SQLM_HI_ALERT_STATE_AUTOMATE_FAILED 6

/******************************************************************************/
/* Health Indicator specific values                                           */
/******************************************************************************/

/* these are possible values for SQLM_HI_DATABASE_BACKUP_REQ                  */
#define SQLM_HI_VAL_NO_DB_BACKUP_REQ       0   /* No manual db backup required*/
#define SQLM_HI_VAL_DB_BACKUP_REQ          1   /* Manual db backup required   */
#define SQLM_HI_VAL_AUTO_DB_BACKUP_FAILED  2   /* Automatic db backup failed  */

/* these are the possible values for SQLM_HI_DATABASE_TB_REORG_REQ            */
#define SQLM_HI_VAL_NO_REORG_REQ           0   /* No reorganization required  */
#define SQLM_HI_VAL_REORG_REQ              1   /* Reorganization required     */

/* these are the possible values for SQLM_HI_DATABASE_TB_STATS_REQ            */
#define SQLM_HI_VAL_NO_STATS_REQ           0   /* No new statistics required  */
#define SQLM_HI_VAL_STATS_REQ              1   /* New statistics required     */

/* nickname status (fed_nickname_status)                                      */
#define SQLM_FED_NN_VALID                  0   /* all nicknames are valid     */
#define SQLM_FED_NN_INVALID                1   /* one or more nickname invalid*/

/* federated server status (fed_server_status)                                */
#define SQLM_FED_SERVER_AVAILABLE          0   /* all servers are available   */
#define SQLM_FED_SERVER_UNAVAILABLE        1   /* one or more srvr unavailable*/

/* table space container status (tscont_op_status)                            */
#define SQLM_HI_VAL_TSCONT_INACCESSIBLE    0   /* Inaccessible                */
#define SQLM_HI_VAL_TSCONT_ACCESSIBLE      1   /* Accessible                  */

/******************************************************************************/
/* Health snapshot option flags. These flags can be used in the agent_id      */
/* field of the sqlm_obj_struct passed in the sqlma. The flag is used in      */
/* conjunction with the snapshot classes SQLM_CLASS_HEALTH and                */
/* SQLM_CLASS_HEALTH_WITH_DETAIL  to determine what additional health snapshot*/
/* information to return in the snapshot stream                               */
/******************************************************************************/

#define SQLM_HMON_OPT_COLL_FULL    0x00000001 /* with full collection details */


/******************************************************************************/
/* Snapshot Request Stream Element Identifiers                                */
/******************************************************************************/

#define SQLM_INSTREAM_ELM_DBNAME        128
#define SQLM_INSTREAM_ELM_APPLID        129
#define SQLM_INSTREAM_ELM_AGENTID       130

/******************************************************************************/
/* Snapshot Request Stream Request Flag Actions                               */
/******************************************************************************/
#define SQLM_INSTREAM_ADD_REQUEST      0x00000001
#define SQLM_INSTREAM_ADD_QUALIFIER    0x00000002
#define SQLM_INSTREAM_ADD_REQQUAL      (SQLM_INSTREAM_ADD_REQUEST| \
                                        SQLM_INSTREAM_ADD_QUALIFIER)

return ret;
}
