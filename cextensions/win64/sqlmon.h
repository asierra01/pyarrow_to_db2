/********************************************************************************
 *
 * Source File Name = SQLMON.H
 *
 * (C) COPYRIGHT International Business Machines Corp. 1993, 1997
 * All Rights Reserved
 * Licensed Materials - Property of IBM
 *
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 *
 * Function = Include File defining:
 *              Database System Monitor - Constants
 *              Database System Monitor - Structures
 *              Database System Monitor - Function Prototypes
 *
 * Operating System: Common C Include File
 *
 * Notes:
 *   THIS FILE IS GENERATED FROM sqlmon.in
 *
 *   structures returned as output to the 'Get Snapshot' function, 'sqlmonss()'
 *   are of the form: 'sqlm_xxxx', for example: sqlm_dbase.
 *
 *   sqlm_xxxx_event structures are logged to a trace by DB2 Event Monitors,
 *   which can be defined and activated using SQL commands (CREATE EVENT
 *   MONITOR, SET EVENT MONITOR).
 *
 ******************************************************************************/

#ifndef  SQL_H_SQLMON
   #define SQL_H_SQLMON            /* Permit duplicate Includes */

#ifdef __cplusplus
extern "C" {
#endif

#include "sqlsystm.h"              /* System dependent defines     */
#include "sqlca.h"                 /* SQL API - Communication Area */
#include "sqlenv.h"                /* DB2 Environment commands     */

#if defined(DB2NT)
#pragma pack(4)
#elif (defined(DB2AIX) && defined(__64BIT__))
#pragma options align=natural
#elif (defined(DB2AIX))
#pragma options align=power
#endif

/******************************************************************************/
/* Database System Monitor Version (version, server_version)                  */
/******************************************************************************/
#define SQLM_DBMON_VERSION1      1
#define SQLM_DBMON_VERSION2      2
#define SQLM_DBMON_VERSION5      3
#define SQLM_DBMON_VERSION5_2    4
#define SQLM_DBMON_VERSION6      5
#define SQLM_DBMON_VERSION7      6
#define SQLM_DBMON_VERSION8      7
#define SQLM_DBMON_VERSION9      8
#define SQLM_DBMON_VERSION9_5    9
#define SQLM_DBMON_VERSION9_7    10
#define SQLM_DBMON_VERSION9_7_1  11
#define SQLM_DBMON_VERSION10_5_6 12
#define SQLM_CURRENT_VERSION SQLM_DBMON_VERSION10_5_6

/******************************************************************************/
/* Snapshot class qualifiers (This indicates how the sqlma is to be           */
/* interpreted)                                                               */
/******************************************************************************/

#define SQLM_CLASS_DEFAULT             0 /* SQLMA is for a standard snapshot  */
#define SQLM_CLASS_HEALTH              1 /* SQLMA is for a health snapshot    */
#define SQLM_CLASS_HEALTH_WITH_DETAIL  2 /* SQLMA is for a health snapshot
                                                 including additional details */
#define SQLM_CLASS_MAX 2                 /* The highest class value           */

/******************************************************************************/
/* Snapshot requests (sqlm_obj_struct.obj_type in sqlma)                      */
/******************************************************************************/

/* Database Manager snapshot */
#define SQLMA_DB2                 0x00010001 /* 01.DBM information            */

/* List of connections */
#define SQLMA_DBASE_APPLINFO      0x00010007 /*07.List of connections to a DB */
#define SQLMA_APPLINFO_ALL        0x0001000B /*11.List of connections to DB2  */
#define SQLMA_DCS_APPLINFO_ALL    0X0001000C /*12.List of DCS connects to DB2 */

/* Database snapshot */
#define SQLMA_DBASE               0x00010002 /*02.Database level information  */
#define SQLMA_DBASE_ALL           0x00010009 /*09.DB info for all active DBs  */
#define SQLMA_DCS_DBASE           0x00010022 /*34.DCS Database level info     */
#define SQLMA_DCS_DBASE_ALL       0x00010023 /*35.DCS DB info for allActiveDBs*/
#define SQLMA_DBASE_REMOTE        0x00010025 /*37.Remote access inf for a DB  */
#define SQLMA_DBASE_REMOTE_ALL    0x00010026 /*38.Remote access inf for allDBs*/

/* Application snapshot */
#define SQLMA_APPL_ALL            0x0001000A /*10.Appl lvl inf-all connects   */
#define SQLMA_APPL                0x00010003 /*03.Appl lvl inf-for appl_id    */
#define SQLMA_AGENT_ID            0x00010004 /*04.Appl lvl inf-for appl-hdl   */
#define SQLMA_DBASE_APPLS         0x00010006 /*06.Appl lvl inf-all conns to db*/
#define SQLMA_DCS_APPL_ALL        0x0001001E /*30.DCS appl inf-all connections*/
#define SQLMA_DCS_APPL            0x0001001F /*31.DCS appl inf-for appl_id    */
#define SQLMA_DCS_APPL_HANDLE     0x00010020 /*32.DCS appl inf-for appl-hdl   */
#define SQLMA_DCS_DBASE_APPLS     0x00010021 /*33.DCS appl inf-all cons to db */
#define SQLMA_DBASE_APPLS_REMOTE  0x00010027 /*39.RemoteAccessInf for an Appl */
#define SQLMA_APPL_REMOTE_ALL     0x00010028 /*40.RemoteAccessInf for allAppls*/

/* Table snapshot */
#define SQLMA_DBASE_TABLES        0x00010005 /*05.Table related inf for a DB  */

/* Tablespace snapshot */
#define SQLMA_DBASE_TABLESPACES   0x0001000D /*13.Tablespace related inf forDB*/

/* Snapshot for locks */
#define SQLMA_APPL_LOCKS          0x00010014 /*20.ListOfLocks held-for applId */
#define SQLMA_APPL_LOCKS_AGENT_ID 0x00010015 /*21.ListOfLocks held-for applHdl*/
#define SQLMA_DBASE_LOCKS         0x00010008 /*08.ListOfLocks all appls for db*/

/* Bufferpool snapshot */
#define SQLMA_DBASE_BUFFERPOOLS   0x00010016 /*22.BufferpoolInf-for a db      */
#define SQLMA_BUFFERPOOLS_ALL     0x00010017 /*23.BufferpoolInf-AllBufferpools*/

/* Dynamic sql snapshot */
#define SQLMA_DYNAMIC_SQL         0x00010024 /*36.Dynamic SQL statement info  */

/******************************************************************************/
/* Snapshot output structure type identifiers                                 */
/*                                                                            */
/* (info_type element in the sqlm_xxx structures that are returned in the     */
/* sqlmonss() output buffer.)                                                 */
/******************************************************************************/

#define SQLM_DB2_SS               '1' /* DB2 info (sqlm_db2)                  */
#define SQLM_FCM_SS               'E' /* DB2 FCM info (sqlm_fcm)              */
#define SQLM_NODE_SS              'G' /* DB2 FCM Node info (sqlm_fcm_node)    */
#define SQLM_APPLINFO_SS          '4' /* Summary appl info (sqlm_applinfo)    */
#define SQLM_DCS_APPLINFO_SS      'A' /* DCS appl info (sqlm_dcs_applinfo)    */
#define SQLM_DBASE_SS             '2' /* DB info (sqlm_dbase)                 */
#define SQLM_TABLE_HEADER_SS      '5' /* DB table info (sqlm_table_header)    */
#define SQLM_TABLE_SS             '6' /* Table info (sqlm_table)              */
#define SQLM_DBASE_LOCK_SS        '7' /* DB lock info (sqlm_dbase_lock)       */
#define SQLM_APPL_LOCK_SS         '8' /* Appl lock info (sqlm_appl_lock)      */
#define SQLM_LOCK_SS              '9' /* Lock info (sqlm_lock)                */
#define SQLM_TABLESPACE_HEADER_SS 'B' /* DB tspaces (sqlm_tablespace_header)  */
#define SQLM_TABLESPACE_SS        'C' /* Tablespace info (sqlm_tablespace)    */
#define SQLM_APPL_SS              '3' /* Appl info (sqlm_appl)                */
#define SQLM_DBASE_ROLLFWD_SS     'H' /* Rollfwd info  (sqlm_rollfwd_info)    */
#define SQLM_DBASE_ROLLFWD_TS_SS  'I' /* Rollfwd tablespace information
                                             (sqlm_rollfwd_ts_info)           */
#define SQLM_BUFFERPOOL_SS        'J' /* Bufferpool info (sqlm_bufferpool)    */
#define SQLM_LOCK_WAIT_SS         'K' /* Lock wait info (sqlm_lock_wait)      */
#define SQLM_STMT_SS              'L' /* Statement info (sqlm_stmt)           */
#define SQLM_SUBSECTION_SS        'M' /* Subsection info (sqlm_subsection)    */
#define SQLM_AGENT_SS             'N' /* Agent info (sqlm_agent)              */
#define SQLM_DCS_APPL_SS          'O' /* DCS appl info (sqlm_dcs_appl)        */
#define SQLM_DCS_APPLID_SS        'P' /* DCS appl ident.(sqlm_dcs_applid_info)*/
#define SQLM_DCS_APPL_STATS_SS    'Q' /* DCS appl stats.(sqlm_dcs_appl_snap_stats)*/
#define SQLM_APPL_XID_SS          'R' /* 2PC transaction ID (sqlm_appl_xid)   */
#define SQLM_TPMON_INFO_SS        'S' /* 3-tier client info (sqlm_tpmon_info) */
#define SQLM_DCS_STMT_SS          'T' /* DCS statement info (sqlm_dcs_stmt)   */
#define SQLM_DCS_DBASE_SS         'U' /* DCS database info (sqlm_dcs_dbase)   */
#define SQLM_COLLECTED_SS         'V' /* Collected info    (sqlm_collected)
                                         Used as input to the
                                         db2ConvToOldMonFormat api            */
#define SQLM_DBASE_REMOTE_SS      'W' /* Remote datasource access info        */
#define SQLM_APPL_REMOTE_SS       'X' /* Remote access info by application    */

/******************************************************************************/
/* stream type ids                                                            */
/******************************************************************************/
#define SQLM_STREAM_SNAPSHOT 1
#define SQLM_STREAM_EVMON    2

/******************************************************************************/
/* size constants                                                             */
/******************************************************************************/

#define SQLM_APPLID_SZ        64          /* size of the application id V9+   */
#define SQLM_APPLID_SZ_V8     32          /* size of the V8 and below app id  */
#define SQLM_SEQ_SZ            5          /* sequence number size             */
#define SQLM_SEQ_SZ_V8         4          /* seq num size for V8 and below    */
#define SQLM_SH_IDENT_SZ       8          /* Small identifier size            */
#define SQLM_IDENT_SZ         20          /* General identifier size          */
#define SQLM_LG_IDENT_SZ      32          /* Long identifier size             */
#define SQLM_OBJECT_SZ       128          /* object size in sqlma structure   */
#define SQLM_DBPATH_SZ       256          /* Database Path size               */
#define SQLM_COMM_ADDR_SZ     64          /* Communication address size (V9+) */
#define SQLM_COMM_ADDR_SZ_V8  32          /* Communication address size (V8)  */
#define SQLM_SERVERNAME_SZ   128          /* DJ server_name                   */
#define SQLM_MESSAGE_SZ      128          /* The message in the WTT control   */
#define SQLM_STORAGE_PATH_SZ 190          /* Storage group path size          */
#define SQLM_OLD_PACKAGE_NAME_SZ    20    /* Package name size in V8 and prev */

/******************************************************************************/
/* Information group state switches (sqlmon and sqlmonss functions)           */
/******************************************************************************/

#define SQLM_OFF    0              /* Turn monitoring group OFF               */
#define SQLM_ON     1              /* Turn monitoring group ON                */
#define SQLM_HOLD   2              /* leave monitoring group in current state */

/******************************************************************************/
/* flag constant for sqlmrset()                                               */
/******************************************************************************/
#define SQLM_UDB_DBASE 0
#define SQLM_UDB_ALL 1
#define SQLM_DCS_DBASE 2
#define SQLM_DCS_ALL 3
#define SQLM_APM 4

/******************************************************************************/
/* Monitor switches                                                           */
/******************************************************************************/

#define SQLM_UOW_SW          0           /* Unit of Work information          */
#define SQLM_STATEMENT_SW    1           /* Statement information             */
#define SQLM_TABLE_SW        2           /* Table information                 */
#define SQLM_BUFFER_POOL_SW  3           /* Buffer Pool information           */
#define SQLM_LOCK_SW         4           /* Lock information                  */
#define SQLM_SORT_SW         5           /* Sort information                  */
#define SQLM_TIMESTAMP_SW    6           /* Timestamp information             */

#define SQLM_NUM_GROUPS      7           /* number of monitor switches        */
#define SQLM_NUM_GROUPS_PREV8 6          /* number of monitor switches        */

/******************************************************************************/
/* Statement Types (stmt_type)                                                */
/******************************************************************************/
#define SQLM_STATIC            1         /* Static statement                  */
#define SQLM_DYNAMIC           2         /* Dynamic statement                 */
#define SQLM_NON_STMT          3         /* Operation other than an SQL stmt  */
#define SQLM_STMT_TYPE_UNKNOWN 4         /* Unknown statement type            */

/******************************************************************************/
/* Statement Operation Types (stmt_operation)                                 */
/******************************************************************************/
/* SQL operations */
#define SQLM_PREPARE            1        /* SQL Prepare                       */
#define SQLM_EXECUTE            2        /* SQL Execute                       */
#define SQLM_EXECUTE_IMMEDIATE  3        /* SQL Execute Immediate             */
#define SQLM_OPEN               4        /* SQL Open                          */
#define SQLM_FETCH              5        /* SQL Fetch                         */
#define SQLM_CLOSE              6        /* SQL Close                         */
#define SQLM_DESCRIBE           7        /* SQL Describe                      */
#define SQLM_STATIC_COMMIT      8        /* SQL Static Commit                 */
#define SQLM_STATIC_ROLLBACK    9        /* SQL Static Rollback               */
#define SQLM_FREE_LOCATOR      10        /* SQL Free Locator                  */
#define SQLM_PREP_COMMIT       11        /* Prepare to commit (2-phase commit)*/
#define SQLM_CALL              12        /* Call a stored procedure           */
#define SQLM_SELECT            15        /* SELECT statement                  */
#define SQLM_PREP_OPEN         16        /* Prep. and open (DB2 Connect only) */
#define SQLM_PREP_EXEC         17        /* Prep. and execute (DB2 Connect)   */
#define SQLM_COMPILE           18        /* Compile (DB2 Connect only)        */
#define SQLM_SET               19        /* SET statement                     */

/* non-SQL operations */
#define SQLM_RUNSTATS          20        /* Runstats                          */
#define SQLM_REORG             21        /* Reorg                             */
#define SQLM_REBIND            22        /* Rebind package                    */
#define SQLM_REDIST            23        /* Redistribute                      */
#define SQLM_GETTA             24        /* Get Table Authorization           */
#define SQLM_GETAA             25        /* Get Administrative Authorization  */
#define SQLM_GETNEXTCHUNK      26        /* DRDA Get Next Chunk command       */
#define SQLM_DRPPKG            27        /* Drop Package                      */

/******************************************************************************/
/* Table Types (table_type)                                                   */
/******************************************************************************/
#define SQLM_USER_TABLE      1           /* User table                        */
#define SQLM_DROPPED_TABLE   2           /* Dropped user table                */
#define SQLM_TEMP_TABLE      3           /* Temporary table                   */
#define SQLM_CATALOG_TABLE   4           /* System Catalog table              */
#define SQLM_REORG_TABLE     5           /* Reorg table                       */
#define SQLM_SYNOPSIS_TABLE  6           /* Synopsis table                    */
#define SQLM_EXTERNAL_TABLE  7           /* External table                    */

/******************************************************************************/
/* lock modes (lock_mode)                                                     */
/******************************************************************************/

#define SQLM_LNON  0                  /*  No Lock                             */
#define SQLM_LOIS  1                  /*  Intention Share Lock                */
#define SQLM_LOIX  2                  /*  Intention Exclusive Lock            */
#define SQLM_LOOS  3                  /*  Share Lock                          */
#define SQLM_LSIX  4                  /*  Share with Intention Exclusive Lock */
#define SQLM_LOOX  5                  /*  Exclusive Lock                      */
#define SQLM_LOIN  6                  /*  Intent None (For Dirty Read)        */
#define SQLM_LOOZ  7                  /*  Super Exclusive Lock                */
#define SQLM_LOOU  8                  /*  Update Lock                         */
#define SQLM_LONS  9                  /*  Share Lock (CS/RS)                  */
#define SQLM_LONX 10                  /*  Next-key Exclusive Lock             */
#define SQLM_LOOW 11                  /*  Weak Exclusive Lock                 */
#define SQLM_LONW 12                  /*  Next-key Weak Exclusive Lock        */

/******************************************************************************/
/* subsection status (ss_status)                                              */
/******************************************************************************/

#define SQLM_SSEXEC             1  /* Subsection executing                    */
#define SQLM_SSTQ_WAIT_TO_RCV   2  /* Waiting to receive data on a tablequeue */
#define SQLM_SSTQ_WAIT_TO_SEND  3  /* Waiting to send data on a tablequeue    */
#define SQLM_SSCOMPLETED        4  /* Subsection execution is completed       */

/******************************************************************************/
/* application status (appl_status)                                           */
/******************************************************************************/
#define SQLM_INIT                 0            /* Performing initialization  */
#define SQLM_CONNECTPEND          1            /* connect pending             */
#define SQLM_CONNECTED            2            /* connect completed           */
#define SQLM_UOWEXEC              3            /* UOW executing               */
#define SQLM_UOWWAIT              4            /* UOW waiting                 */
#define SQLM_LOCKWAIT             5            /* lock wait                   */
#define SQLM_COMMIT_ACT           6            /* commit active               */
#define SQLM_ROLLBACK_ACT         7            /* rollback active             */
#define SQLM_RECOMP               8            /* recompiling a plan          */
#define SQLM_COMP                 9            /* compiling a SQL statement   */
#define SQLM_INTR                10            /* request interrupted         */
#define SQLM_DISCONNECTPEND      11            /* disconnect pending          */
#define SQLM_TPREP               12            /* Prepared transaction        */
#define SQLM_THCOMT              13            /* heuristically committed     */
#define SQLM_THABRT              14            /* heuristically rolled back   */
#define SQLM_TEND                15            /* Transaction ended           */
#define SQLM_CREATE_DB           16            /* Creating Database           */
#define SQLM_RESTART             17            /* Restarting a Database       */
#define SQLM_RESTORE             18            /* Restoring a Database        */
#define SQLM_BACKUP              19            /* Performing a Backup         */
#define SQLM_LOAD                20            /* Performing a fast load      */
#define SQLM_UNLOAD              21            /* Performing a fast unload    */
#define SQLM_IOERROR_WAIT        22            /* Wait to disable tablespace  */
#define SQLM_QUIESCE_TABLESPACE  23            /* Quiescing a tablespace      */
#define SQLM_WAITFOR_REMOTE      24            /* Waiting for remote node     */
#define SQLM_REMOTE_RQST         25    /* Pending results from remote request */
#define SQLM_DECOUPLED           26      /* App has been decoupled from coord */
#define SQLM_ROLLBACK_TO_SAVEPOINT 27          /* Rollback to savepoint       */
#define SQLM_AUTONOMOUS_WAIT     28            /* Autonomous Routine Wait     */
#define SQLM_UOWQUEUED           29            /* WLM activity is queued      */
#define SQLM_ANONBLOCK_WAIT      30            /* Anonymous Block Wait        */

/******************************************************************************/
/* DCS application status (dcs_appl_status)                                   */
/******************************************************************************/

#define SQLM_DCS_CONNECTPEND_OUTBOUND  101   /* connect to host db pending    */
#define SQLM_DCS_UOWWAIT_OUTBOUND      102   /* gateway waiting for reply
                                                 from host database           */
#define SQLM_DCS_UOWWAIT_INBOUND       103   /* conn. to host db established  */
                                             /* or gateway waiting for request*/

/******************************************************************************/
/* DCS transmission chain groupings (num_transmissions_group)                 */
/******************************************************************************/

#define SQLM_DCS_TRANS_GROUP_2         1     /* 2 transmissions               */
#define SQLM_DCS_TRANS_GROUP_3TO7      2     /* 3-7 transmissions             */
#define SQLM_DCS_TRANS_GROUP_8TO15     3     /* 8-15 transmissions            */
#define SQLM_DCS_TRANS_GROUP_16TO64    4     /* 16-64 transmissions           */
#define SQLM_DCS_TRANS_GROUP_GT64      5     /* Greater than 64 transmissions */

/******************************************************************************/
/* Concentrator agent statuses                                                */
/******************************************************************************/
#define SQLM_AGENT_ASSOCIATED            1   /* agent associated with appl    */
#define SQLM_AGENT_NOT_ASSOCIATED        2   /* agent not assoc with appl     */

/******************************************************************************/
/* database status (db_status)                                                */
/******************************************************************************/

#define SQLM_DB_ACTIVE          0              /* Database is active          */
#define SQLM_DB_QUIESCE_PEND    1              /* Quiesce is pending for DB   */
#define SQLM_DB_QUIESCED        2              /* Database has been quiesced  */
#define SQLM_DB_ROLLFWD         3              /* DB in Database rollforward  */
#define SQLM_DB_ACTIVE_STANDBY  4              /* Standby with read           */
#define SQLM_DB_STANDBY         5              /* Standby without read        */

/******************************************************************************/
/* rollforward types (rf_type)                                                */
/******************************************************************************/
#define SQLM_ROLLFWD_TYP_DB        0  /* Database rollforward                */
#define SQLM_ROLLFWD_TYP_TSPACE    1  /* DB tablespace (on-line) rollforward */
#define SQLM_NO_ROLLFWD            2  /* No rollforward in progress          */

/******************************************************************************/
/* Rollforward status (rf_status)                                             */
/******************************************************************************/
#define SQLM_ROLLFWD_STATUS_REDO     0  /* REDO phase in progress */
#define SQLM_ROLLFWD_STATUS_UNDO     1  /* UNDO phase in progress */
#define SQLM_ROLLFWD_STATUS_SUCCESS  2  /* Successfuly completed on this node */
#define SQLM_ROLLFWD_STATUS_ERROR    3  /* Error occurred on this node */
#define SQLM_ROLLFWD_STATUS_USR_INTR 4  /* User intervention required */

/******************************************************************************/
/* tablespace types                                                           */
/******************************************************************************/
#define SQLM_TABLESPACE_TYP_DMS    0
#define SQLM_TABLESPACE_TYP_SMS    1

/******************************************************************************/
/* storage path states                                                        */
/******************************************************************************/
#define SQLM_DB_STORAGE_PATH_STATE_NOTINUSE    0
#define SQLM_DB_STORAGE_PATH_STATE_INUSE       1
#define SQLM_DB_STORAGE_PATH_STATE_DROPPENDING 2

/******************************************************************************/
/* tablespace content type                                                    */
/******************************************************************************/
#define SQLM_TABLESPACE_CONTENT_ANY     0
#define SQLM_TABLESPACE_CONTENT_LONG    1
#define SQLM_TABLESPACE_CONTENT_LARGE   1      /* Long renamed to Large in v9 */
#define SQLM_TABLESPACE_CONTENT_SYSTEMP 2
#define SQLM_TABLESPACE_CONTENT_USRTEMP 3

/******************************************************************************/
/* tablespace file system caching settings                                    */
/******************************************************************************/
#define SQLM_TABLESPACE_FSCACHING_ON      0
#define SQLM_TABLESPACE_FSCACHING_OFF     1
#define SQLM_TABLESPACE_FSCACHING_DEFAULT 2

/******************************************************************************/
/*  reorg table defines                                                       */
/******************************************************************************/

#define SQLM_REORG_STARTED     1
#define SQLM_REORG_PAUSED      2
#define SQLM_REORG_STOPPED     3
#define SQLM_REORG_COMPLETED   4
#define SQLM_REORG_TRUNCATE    5

#define SQLM_REORG_SORT           1
#define SQLM_REORG_BUILD          2
#define SQLM_REORG_REPLACE        3
#define SQLM_REORG_INDEX_RECREATE 4
#define SQLM_REORG_DICT_SAMPLE    5

#define SQLM_REORG_CONSOLIDATE_SPARSE_BLOCKS 9
#define SQLM_REORG_SCAN 10
#define SQLM_REORG_DRAIN 11
#define SQLM_REORG_RELEASE 12

#define SQLM_REORG_SUCCESS   0
#define SQLM_REORG_FAIL     -1

/******************************************************************************/
/* rebalancer modes                                                           */
/******************************************************************************/
#define SQLM_TABLESPACE_NO_REBAL             0
#define SQLM_TABLESPACE_FWD_REBAL            1
#define SQLM_TABLESPACE_REV_REBAL            2
#define SQLM_TABLESPACE_FWD_REBAL_OF_2PASS   3
#define SQLM_TABLESPACE_REV_REBAL_OF_2PASS   4

/******************************************************************************/
/* Memory Heaps                                                               */
/******************************************************************************/
#define SQLM_HEAP_APPLICATION    1      /* Application Heap                   */
#define SQLM_HEAP_DATABASE       2      /* Database Heap                      */
#define SQLM_HEAP_APPL_CONTROL   3      /* Application Control Heap (pre-v95) */
#define SQLM_HEAP_LOCK_MGR       4      /* Lock Manager Heap                  */
#define SQLM_HEAP_UTILITY        5      /* Backup/Restore/Util Heap           */
#define SQLM_HEAP_STATISTICS     6      /* Statistics Heap                    */
#define SQLM_HEAP_PACKAGE_CACHE  7      /* Package Cache Heap                 */
#define SQLM_HEAP_CAT_CACHE      8      /* Catalog Cache Heap                 */
#define SQLM_HEAP_DFM            9      /* DFM Heap                           */
#define SQLM_HEAP_QUERY         10      /* Query Heap                         */
#define SQLM_HEAP_MONITOR       11      /* Database Monitor Heap              */
#define SQLM_HEAP_STATEMENT     12      /* Statement Heap                     */
#define SQLM_HEAP_FCMBP         13      /* FCMBP Heap                         */
#define SQLM_HEAP_IMPORT_POOL   14      /* Import Pool                        */
#define SQLM_HEAP_OTHER         15      /* Other Memory                       */
#define SQLM_HEAP_BP            16      /* Buffer Pool heap                   */
#define SQLM_HEAP_APP_GROUP     17      /* Application Group Shared (pre-v95) */
#define SQLM_HEAP_SHARED_SORT   18      /* Sort Shared Heap                   */
#define SQLM_HEAP_SORT          19      /* Sort Heap                          */
#define SQLM_HEAP_APPL_SHARED   20      /* Applications Shared Heap           */
#define SQLM_HEAP_MIN           SQLM_HEAP_APPLICATION
#define SQLM_HEAP_MAX           SQLM_HEAP_APPL_SHARED


/* Memory Pool List ID's (for element SQLM_ELM_POOL_LIST_ID)                  */
#define SQLM_POOL_LIST_ID_APPLSHR         0   /* Shared Appl Memory List      */
#define SQLM_POOL_LIST_ID_PRIVAGENT       1   /* Private Agent Memory List    */


/******************************************************************************/
/* database manager status  (db2_status)                                      */
/******************************************************************************/

#define SQLM_DB2_ACTIVE          0             /* DB2 is active               */
#define SQLM_DB2_QUIESCE_PEND    1             /* Quiesce is pending for DB2  */
#define SQLM_DB2_QUIESCED        2             /* DB2 has been quiesced       */

/******************************************************************************/
/* UOW completion status (uow_comp_status)                                    */
/******************************************************************************/

#define SQLM_UOWCOMMIT       1       /* UOW issued a commit                   */
#define SQLM_UOWROLLBACK     2       /* UOW issued a rollback                 */
#define SQLM_UOWDEADLOCK     3       /* UOW was rolled back due to a deadlock */
#define SQLM_UOWABEND        4       /* UOW was rolled back due to an abend   */
#define SQLM_APPL_END        5       /* application normal termination        */
#define SQLM_UOWLOCKTIMEOUT  6       /* UOW was rolled back from lock timeout */
#define SQLM_UOWUNKNOWN      7       /* Returned for flushed events           */

/******************************************************************************/
/* lock attributes (lock_attributes)                                         */
/******************************************************************************/

#define SQLM_LOCKATTR_WAIT_FOR_AVAIL  0x00000001  /* wait for availability    */
#define SQLM_LOCKATTR_ESCALATED       0x00000002  /* acquired by escalation   */
#define SQLM_LOCKATTR_RR_IN_BLOCK     0x00000004  /* RR lock "in" block       */
#define SQLM_LOCKATTR_INSERT          0x00000008  /* insert lock              */
#define SQLM_LOCKATTR_RR              0x00000010  /* lock by RR scan          */
#define SQLM_LOCKATTR_UPDATE_DELETE   0x00000020  /* update/delete row lock   */
#define SQLM_LOCKATTR_ALLOW_NEW       0x10000000  /* allow new lock requests  */
#define SQLM_LOCKATTR_NEW_REQUEST     0x20000000  /* a new lock requestor     */
#define SQLM_LOCKATTR_DELETE_IN_BLOCK 0x00000000  /* deleted row "in" block   */
#define SQLM_LOCKATTR_INDOUBT         0x00010000  /* held by indoubt trans    */
#define SQLM_LOCKATTR_LOW_PRIORITY    0x00000000  /* held by low priority app */

/******************************************************************************/
/* lock release flags (lock_release_flags)                                    */
/******************************************************************************/

#define SQLM_LOCKRELFLAGS_SQLCOMPILER 0x80000000  /* locks by SQL compiler    */
#define SQLM_LOCKRELFLAGS_UNTRACKED   0x40000000  /* non-unique, untracked    */

/******************************************************************************/
/* lock object type (lock_object_type)                                        */
/******************************************************************************/

#define SQLM_TABLE_LOCK            1    /* table lock type                   */
#define SQLM_ROW_LOCK              2    /* table row lock type               */
#define SQLM_INTERNAL_LOCK         3    /* Internal lock type                */
#define SQLM_TABLESPACE_LOCK       4    /* Tablespace lock type              */
#define SQLM_EOT_LOCK              5    /* end of table lock                 */
#define SQLM_KEYVALUE_LOCK         6    /* key value lock                    */
#define SQLM_SYSBOOT_LOCK          7    /* Internal lock on the sysboot table*/
#define SQLM_INTERNALP_LOCK        8    /* Internal Plan lock                */
#define SQLM_INTERNALV_LOCK        9    /* Internal Variation lock           */
#define SQLM_INTERNALS_LOCK        10   /* Internal Sequence lock            */
#define SQLM_INTERNALJ_LOCK        11   /* Bufferpool lock                   */
#define SQLM_INTERNALL_LOCK        12   /* Internal Long/Lob lock            */
#define SQLM_INTERNALC_LOCK        13   /* Internal Catalog Cache lock       */
#define SQLM_INTERNALB_LOCK        14   /* Internal Online Backup lock       */
#define SQLM_INTERNALO_LOCK        15   /* Internal Object Table lock        */
#define SQLM_INTERNALT_LOCK        16   /* Internal Table Alter lock         */
#define SQLM_INTERNALQ_LOCK        17   /* Internal DMS Sequence lock        */
#define SQLM_INPLACE_REORG_LOCK    18   /* Inplace reorg lock                */
#define SQLM_BLOCK_LOCK            19   /* Block lock type                   */
#define SQLM_TABLE_PART_LOCK       20   /* Table partition lock type         */
#define SQLM_AUTORESIZE_LOCK       21   /* Autoresize lock type              */
#define SQLM_AUTOSTORAGE_LOCK      22   /* Automatic storage lock type       */
#define SQLM_XML_PATH_LOCK         23   /* XML Path lock type                */
#define SQLM_INTERNALM_LOCK        24   /* Internal Extent Movement lock     */
#define SQLM_GLOBAL_DDL_LOCK       25   /* Global DDL lock                   */
#define SQLM_INSERT_RANGE_LOCK     26   /* Insert Range lock                 */
#define SQLM_COL_TABLE_SERIALIZE_LOCK   27   /* Column Organized Table UpdateDelete Serialization */

/******************************************************************************/
/* lock status (lock_status)                                                  */
/******************************************************************************/

#define SQLM_LRBGRNT      1                     /*  Granted State             */
#define SQLM_LRBCONV      2                     /*  Converting state          */

/******************************************************************************/
/* client communications protocols (client_protocol)                          */
/******************************************************************************/
#define SQLM_PROT_APPC         SQL_PROTOCOL_APPC    /* appc                   */
#define SQLM_PROT_NETBIOS      SQL_PROTOCOL_NETB    /* netbios                */
#define SQLM_PROT_APPN         SQL_PROTOCOL_APPN    /* appn                   */
#define SQLM_PROT_TCPIP        SQL_PROTOCOL_TCPIP   /* TCP/IPv4 or 6          */
#define SQLM_PROT_TCPIP4       SQL_PROTOCOL_TCPIP4  /* TCP/IPv4               */
#define SQLM_PROT_TCPIP6       SQL_PROTOCOL_TCPIP6  /* TCP/IPv6               */
#define SQLM_PROT_CPIC         SQL_PROTOCOL_CPIC    /* APPC using CPIC        */
#define SQLM_PROT_IPXSPX       SQL_PROTOCOL_IPXSPX  /* ipx/spx                */
#define SQLM_PROT_LOCAL        SQL_PROTOCOL_LOCAL   /* local client           */
#define SQLM_PROT_NPIPE        SQL_PROTOCOL_NPIPE   /* Named pipe             */
#define SQLM_PROT_SOCKS4       SQL_PROTOCOL_SOCKS4  /* TCP/IPv4 using SOCKS   */
#define SQLM_PROT_SSL          SQL_PROTOCOL_SSL     /* TCP/IP using SSL       */
#define SQLM_PROT_SSL4         SQL_PROTOCOL_SSL4    /* TCP/IPv4 using SSL     */
#define SQLM_PROT_SSL6         SQL_PROTOCOL_SSL6    /* TCP/IPv6 using SSL     */


/******************************************************************************/
/* Operating Systems (client_platform and server_platform)                    */
/******************************************************************************/
#define SQLM_PLATFORM_UNKNOWN         0         /* Unknown platform           */
#define SQLM_PLATFORM_OS2             1         /* OS/2                       */
#define SQLM_PLATFORM_DOS             2         /* DOS                        */
#define SQLM_PLATFORM_WINDOWS         3         /* Windows                    */
#define SQLM_PLATFORM_AIX             4         /* AIX                        */
#define SQLM_PLATFORM_NT              5         /* NT                         */
#define SQLM_PLATFORM_HP              6         /* HP                         */
#define SQLM_PLATFORM_SUN             7         /* Sun                        */
#define SQLM_PLATFORM_MVS_DRDA        8         /* MVS (client via DRDA)      */
#define SQLM_PLATFORM_AS400_DRDA      9         /* AS400 (client via DRDA)    */
#define SQLM_PLATFORM_VM_DRDA        10         /* VM (client via DRDA)       */
#define SQLM_PLATFORM_VSE_DRDA       11         /* VSE (client via DRDA)      */
#define SQLM_PLATFORM_UNKNOWN_DRDA   12         /* Unknown DRDA Client        */
#define SQLM_PLATFORM_SNI            13         /* Siemens Nixdorf            */
#define SQLM_PLATFORM_MAC            14         /* Macintosh Client           */
#define SQLM_PLATFORM_WINDOWS95      15         /* Windows 95                 */
#define SQLM_PLATFORM_SCO            16         /* SCO                        */
#define SQLM_PLATFORM_SGI            17         /* Silicon Graphic            */
#define SQLM_PLATFORM_LINUX          18         /* Linux                      */
#define SQLM_PLATFORM_DYNIX          19         /* DYNIX/ptx                  */
#define SQLM_PLATFORM_AIX64          20         /* AIX 64 bit                 */
#define SQLM_PLATFORM_SUN64          21         /* Sun 64 bit                 */
#define SQLM_PLATFORM_HP64           22         /* HP 64 bit                  */
#define SQLM_PLATFORM_NT64           23         /* NT 64 bit                  */
#define SQLM_PLATFORM_LINUX390       24         /* Linux for S/390            */
#define SQLM_PLATFORM_LINUXZ64       25         /* Linux for z900             */
#define SQLM_PLATFORM_LINUXIA64      26         /* Linux for IA64             */
#define SQLM_PLATFORM_LINUXPPC       27         /* Linux for PPC              */
#define SQLM_PLATFORM_LINUXPPC64     28         /* Linux for PPC64            */
#define SQLM_PLATFORM_OS390          29         /* OS/390 Tools (CC, DW)      */
#define SQLM_PLATFORM_LINUXX8664     30         /* Linux for x86-64           */
#define SQLM_PLATFORM_HPIA           31         /* HP-UX Itanium 32bit        */
#define SQLM_PLATFORM_HPIA64         32         /* HP-UX Itanium 64bit        */
#define SQLM_PLATFORM_SUNX86         33         /* Sun for x86-64             */
#define SQLM_PLATFORM_SUNX8664       34         /* Sun for x86-64 64bit       */
#define SQLM_PLATFORM_DARWIN         35         /* Mac OS X 32bit             */
#define SQLM_PLATFORM_DARWIN64       36         /* Mac OS X 64bit             */
#define SQLM_PLATFORM_LINUXPPC64LE   37         /* Linux for PPC64 LE         */

/* IMPORTANT NOTE: When adding a new platform above, please notify the        */
/*                 DRDA team to update the table srvclsnms in file            */
/*                 sqljspconvars.h with a new entry for that platform!!!      */

#define SQLM_PLATFORM_INSPURKUXI64   SQLM_PLATFORM_LINUXIA64  /* Inspur K-UX  */

/******************************************************************************/
/* Operating System Application Priority Type (appl_priority_type)            */
/******************************************************************************/
#define SQLM_FIXED_PRIORITY    1         /* Remains unchanged over time       */
#define SQLM_DYNAMIC_PRIORITY  2         /* Recalculated by OS based on usage */

/******************************************************************************/
/* Isolation levels                                                           */
/******************************************************************************/
#define SQLM_ISOLATION_LEVEL_NONE 0    /* no isolation level specified        */
#define SQLM_ISOLATION_LEVEL_UR   1    /* uncommited read                     */
#define SQLM_ISOLATION_LEVEL_CS   2    /* cursor stability                    */
#define SQLM_ISOLATION_LEVEL_RS   3    /* read stability                      */
#define SQLM_ISOLATION_LEVEL_RR   4    /* repeatable read                     */

/******************************************************************************/
/* Event Monitor Record Type Identifiers  (sqlm_event_rec_header.type)        */
/*                                                                            */
/* Used to read the records in a trace produced by an Event Monitor           */
/******************************************************************************/
#define SQLM_EVENT_DB               1  /* Database Event                      */
#define SQLM_EVENT_CONN             2  /* Connection Event                    */
#define SQLM_EVENT_TABLE            3  /* Table Event                         */
#define SQLM_EVENT_STMT             4  /* Statement Event                     */
#define SQLM_EVENT_STMTTEXT         5  /* Dynamic Statement Text (OBSOLETE)   */
#define SQLM_EVENT_XACT             6  /* Transaction Event                   */
#define SQLM_EVENT_DEADLOCK         7  /* Deadlock Event                      */
#define SQLM_EVENT_DLCONN           8  /* Deadlock Connection Event           */
#define SQLM_EVENT_TABLESPACE       9  /* Tablespace Event                    */
#define SQLM_EVENT_DBHEADER        10  /* Database Header Event               */
#define SQLM_EVENT_START           11  /* Event monitor start Event           */
#define SQLM_EVENT_CONNHEADER      12  /* Connection Header Event             */
#define SQLM_EVENT_OVERFLOW        13  /* Overflow Event                      */
#define SQLM_EVENT_BUFFERPOOL      14  /* Bufferpool Event                    */
#define SQLM_EVENT_SUBSECTION      15  /* Subsection Event (MPP systems)      */
#define SQLM_EVENT_LOG_HEADER      16  /* Log header event                    */
#define SQLM_EVENT_DBMEMUSE        17  /* Mem Pool Infor for DB Event         */
#define SQLM_EVENT_CONNMEMUSE      18  /* Mem Pool Infor for CONN Event       */
#define SQLM_EVENT_STMT_HISTORY    19  /* Statement history event             */
#define SQLM_EVENT_DATA_VALUE      20  /* Statement history data value        */
#define SQLM_EVENT_MAX             20  /* Must be set to the largest value in */
                                       /* the list                            */

/******************************************************************************/
/* Event Monitor Byte Order Identifiers (byte_order)                          */
/******************************************************************************/
#define SQLM_LITTLE_ENDIAN      0         /* Little endian server             */
#define SQLM_BIG_ENDIAN        -1         /* Big endian server                */

/******************************************************************************/
/* Database Monitor Error Constants (sqlcode)                                 */
/******************************************************************************/
#define SQLM_RC_INV_PTR         -1601 /* Parameter is a NULL pointer          */
#define SQLM_RC_INV_OBJ_TYPE    -1602 /* invalid obj_type in sqlma struct     */
#define SQLM_RC_NOT_SPECIFIED   -1603 /* dbname/appl_id not specified in sqlma*/
#define SQLM_RC_NOT_NULL_TERM   -1604 /* dbname/appl_id not NULL terminated   */
#define SQLM_RC_DBNOACT          1605 /* database is not active               */
#define SQLM_RC_BUFFER_FULL      1606 /* DBMON buffer area is full            */
#define SQLM_RC_NOMEM           -1607 /* not enough working memory for DBMON  */
#define SQLM_RC_DUPLICATE_DB     1608 /* duplicate database aliases           */
#define SQLM_RC_REMOTE_DB       -1609 /* cannot monitor remote databases      */
#define SQLM_RC_INV_VALUE       -1610 /* invalid value for input parameter    */
#define SQLM_RC_NO_DATA          1611 /* No data returned by Database Monitor */
#define SQLM_RC_TOO_MANY_OBJECTS -1623/* Too many objects for this request.   */
#define SQLM_RC_MULTIPLE_NODES  -1624 /* Databases in a sqlmonsz or sqlmonss
                                         call reside at different nodes.      */
#define SQLM_RC_MEMORY_ERROR      -83 /* Memory allocation error.             */

/******************************************************************************/
/* FCM Connection Status (connection_status)                                  */
/******************************************************************************/
#define SQLM_FCM_CONNECT_INACTIVE    0         /* No current connection       */
#define SQLM_FCM_CONNECT_ACTIVE      1         /* Connection is active        */
#define SQLM_FCM_CONNECT_CONGESTED   2         /* Connection is congested     */

/******************************************************************************/
/* Database location relative to snapshot application (db_location)           */
/******************************************************************************/
#define SQLM_LOCAL                   1         /* Same node as snapshot       */
#define SQLM_REMOTE                  2         /* DB is on a different node   */

/******************************************************************************/
/* Node location definitions                                                  */
/******************************************************************************/
#define SQLM_CURRENT_NODE -1
#define SQLM_ALL_NODES    -2

/******************************************************************************/
/* Log space usage definitions                                                */
/******************************************************************************/
#define SQLM_LOGSPACE_INFINITE (sqluint64)-1   /* Database is configured with
                                                  infinite active log space   */

/******************************************************************************/
/* Log file number definitions                                                */
/******************************************************************************/
#define SQLM_LOGFILE_NUM_UNKNOWN (sqluint32)-1 /* Log file number is unknown  */

/******************************************************************************/
/* Utility types associated with SQLM_ELM_UTILITY_TYPE                        */
/******************************************************************************/
#define SQLM_UTILITY_REBALANCE              0
#define SQLM_UTILITY_BACKUP                 1
#define SQLM_UTILITY_RUNSTATS               2
#define SQLM_UTILITY_REORG                  3
#define SQLM_UTILITY_RESTORE                4
#define SQLM_UTILITY_CRASH_RECOVERY         5
#define SQLM_UTILITY_ROLLFORWARD_RECOVERY   6
#define SQLM_UTILITY_LOAD                   7
#define SQLM_UTILITY_RESTART_RECREATE_INDEX 8
#define SQLM_UTILITY_REDISTRIBUTE           9
#define SQLM_UTILITY_ASYNC_INDEX_CLEANUP   10
#define SQLM_UTILITY_MDC_ROLLOUT_CLEANUP   11
#define SQLM_UTILITY_GROUP_CRASH_RECOVERY  12
#define SQLM_UTILITY_MEMBER_CRASH_RECOVERY 13
#define SQLM_UTILITY_ASYNC_PART_DETACH     14
#define SQLM_UTILITY_ADC                   15

/******************************************************************************/
/* Utility priority of value 0                                                */
/******************************************************************************/
#define SQLM_UTILITY_UNTHROTTLED       0

/******************************************************************************/
/* Progress information work metric values                                    */
/******************************************************************************/
#define SQLM_WORK_METRIC_NOT_SUPPORT   0
#define SQLM_WORK_METRIC_BYTES         1
#define SQLM_WORK_METRIC_EXTENTS       2
#define SQLM_WORK_METRIC_ROWS          3
#define SQLM_WORK_METRIC_PAGES         4
#define SQLM_WORK_METRIC_INDEXES       5
#define SQLM_WORK_METRIC_TABLES        6
#define SQLM_WORK_METRIC_INDEX_PARTS   7
#define SQLM_WORK_METRIC_NONPART_INDEXES   8

/******************************************************************************/
/* Utility states associated with SQLM_ELM_UTILITY_STATE                      */
/******************************************************************************/
#define SQLM_UTILITY_STATE_EXECUTE     0
#define SQLM_UTILITY_STATE_WAIT        1
#define SQLM_UTILITY_STATE_ERROR       2
#define SQLM_UTILITY_STATE_SUSPENDED   3

/******************************************************************************/
/* Utility states associated with SQLM_ELM_UTILITY_INVOKER_TYPE               */
/******************************************************************************/
#define SQLM_UTILITY_INVOKER_USER      0
#define SQLM_UTILITY_INVOKER_AUTO      1

/******************************************************************************/
/* Utility attributes associated with SQLM_ELM_PROGRESS_LIST_ATTR             */
/******************************************************************************/
#define SQLM_ELM_PROGRESS_LIST_ATTR_SERIAL      0x1
#define SQLM_ELM_PROGRESS_LIST_ATTR_CONCURRENT  0x2

/******************************************************************************/
/* Current HADR roles of the database                                         */
/******************************************************************************/
#define SQLM_HADR_ROLE_STANDARD         0
#define SQLM_HADR_ROLE_PRIMARY          1
#define SQLM_HADR_ROLE_STANDBY          2

/******************************************************************************/
/* State of HADR subsystem                                                    */
/******************************************************************************/
#define SQLM_HADR_STATE_DISCONNECTED    0
#define SQLM_HADR_STATE_LOCAL_CATCHUP   1
#define SQLM_HADR_STATE_REM_CATCH_PEND  2
#define SQLM_HADR_STATE_REM_CATCHUP     3
#define SQLM_HADR_STATE_PEER            4
#define SQLM_HADR_STATE_DISCONN_PEER    5

/******************************************************************************/
/* HADR synchronization mode                                                  */
/******************************************************************************/
#define SQLM_HADR_SYNCMODE_SYNC         0
#define SQLM_HADR_SYNCMODE_NEARSYNC     1
#define SQLM_HADR_SYNCMODE_ASYNC        2
#define SQLM_HADR_SYNCMODE_SUPERASYNC   3 

/******************************************************************************/
/* Status of HADR primary-standby connection                                  */
/******************************************************************************/
#define SQLM_HADR_CONN_CONNECTED        0
#define SQLM_HADR_CONN_CONGESTED        1
#define SQLM_HADR_CONN_DISCONNECTED     2

/******************************************************************************/
/* Snapshot Monitoring defines (db2GetSnapshot, etc) for self-describing      */
/* datastream                                                                 */
/* Used by all versions of snapshot v6 and later.                             */
/******************************************************************************/
/******************************************************************************/
/* Defines for snapshot output stream format                                  */
/******************************************************************************/
#define SQLM_STREAM_STATIC_FORMAT  0
#define SQLM_STREAM_DYNAMIC_FORMAT 1

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
#define SQLM_TYPE_HEADER       1  /* The header monitor types, which
                                     indicate what type of record is being
                                     looked at when encountering an element
                                     of this type, in indicates an element
                                     composed of multible base data elements  */

/*****************Base data elements*******************************************/
#define SQLM_TYPE_STRING      50  /* variable length string                   */
#define SQLM_TYPE_U8BIT       51  /* unsigned 8 bit value                     */
#define SQLM_TYPE_8BIT        52  /* signed 8 bit value                       */
#define SQLM_TYPE_16BIT       53  /* signed 16 bit numeric value              */
#define SQLM_TYPE_U16BIT      54  /* unsigned 16 bit numeric value            */
#define SQLM_TYPE_32BIT       55  /* signed 32 bit numeric value              */
#define SQLM_TYPE_U32BIT      56  /* unsigned 32 bit numeric value            */
#define SQLM_TYPE_U64BIT      57  /* unsigned 64 bit value numeric value      */
#define SQLM_TYPE_64BIT       58  /* signed 64 bit value                      */
#define SQLM_TYPE_HANDLE      59  /* compilation environment blob             */
#define SQLM_TYPE_BINARY      60  /* binary object                            */
#define SQLM_TYPE_DOUBLE      61  /* 8-byte floating point (only used for     */
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
#define SQLM_ELM_DB2                                                           1
                                  /* FCM information                          */
#define SQLM_ELM_FCM                                                           2
                                  /* FCM member number information            */
#define SQLM_ELM_FCM_NODE                                                      3
                                  /* application identifiern                  */
#define SQLM_ELM_APPL_INFO                                                     4
                                  /* application information                  */
#define SQLM_ELM_APPL                                                          5
                                  /* dcs application identifier               */
#define SQLM_ELM_DCS_APPL_INFO                                                 6
                                  /* dcs application information              */
#define SQLM_ELM_DCS_APPL                                                      7
                                  /* dcs statement information                */
#define SQLM_ELM_DCS_STMT                                                      8
                                  /* subsection related information           */
#define SQLM_ELM_SUBSECTION                                                    9
                                  /* agent information                        */
#define SQLM_ELM_AGENT                                                        10
                                  /* lock waiting information                 */
#define SQLM_ELM_LOCK_WAIT                                                    11
                                  /* dcs database information                 */
#define SQLM_ELM_DCS_DBASE                                                    12
                                  /* database information                     */
#define SQLM_ELM_DBASE                                                        13
                                  /* database rollforward information         */
#define SQLM_ELM_ROLLFORWARD                                                  14
                                  /* table information                        */
#define SQLM_ELM_TABLE                                                        15
                                  /* lock information                         */
#define SQLM_ELM_LOCK                                                         16
                                  /* tablespace information                   */
#define SQLM_ELM_TABLESPACE                                                   17
                                  /* bufferpool information                   */
#define SQLM_ELM_BUFFERPOOL                                                   18
                                  /* dynamic sql statement information        */
#define SQLM_ELM_DYNSQL                                                       19
                                  /* First element in any data stream         */
#define SQLM_ELM_COLLECTED                                                    20
                                  /* List of switches                         */
#define SQLM_ELM_SWITCH_LIST                                                  21
                                  /* unit of work switch                      */
#define SQLM_ELM_UOW_SW                                                       22
                                  /* statement switch                         */
#define SQLM_ELM_STATEMENT_SW                                                 23
                                  /* table switch                             */
#define SQLM_ELM_TABLE_SW                                                     24
                                  /* bufferpool switch                        */
#define SQLM_ELM_BUFFPOOL_SW                                                  25
                                  /* lock switch                              */
#define SQLM_ELM_LOCK_SW                                                      26
                                  /* sort switch                              */
#define SQLM_ELM_SORT_SW                                                      27
                                  /* database wide table information          */
#define SQLM_ELM_TABLE_LIST                                                   28
                                  /* database wide tablespace information     */
#define SQLM_ELM_TABLESPACE_LIST                                              29
                                  /* List of dynamic sql statements           */
#define SQLM_ELM_DYNSQL_LIST                                                  30
                                  /* List of locks for an application         */
#define SQLM_ELM_APPL_LOCK_LIST                                               31
                                  /* List of locks for a db                   */
#define SQLM_ELM_DB_LOCK_LIST                                                 32
                                  /* Statement related information            */
#define SQLM_ELM_STMT                                                         33
                                  /* remote data source information by DB     */
#define SQLM_ELM_DBASE_REMOTE                                                 34
                                  /* remote data source information by Appl   */
#define SQLM_ELM_APPL_REMOTE                                                  35
                                  /* application ID information               */
#define SQLM_ELM_APPL_ID_INFO                                                 36
                                  /* transmission level info for a stmt       */
#define SQLM_ELM_STMT_TRANSMISSIONS                                           37
                                  /* timestamp switch                         */
#define SQLM_ELM_TIMESTAMP_SW                                                 38
                                  /* A table reorg                            */
#define SQLM_ELM_TABLE_REORG                                                  39
                                  /* Memory statistics for a pool             */
#define SQLM_ELM_MEMORY_POOL                                                  40
                                  /* List of quiescers for a tablespace       */
#define SQLM_ELM_TABLESPACE_QUIESCER                                          41
                                  /* List of containers for a TS              */
#define SQLM_ELM_TABLESPACE_CONTAINER                                         42
                                  /* List of ranges for TS map                */
#define SQLM_ELM_TABLESPACE_RANGE                                             43
                                  /* List of containers for range             */
#define SQLM_ELM_TABLESPACE_RANGE_CONTAINER                                   44
                                  /* Node unique info for a tablespace        */
#define SQLM_ELM_TABLESPACE_NODEINFO                                          45
                                  /* Health indicator data                    */
#define SQLM_ELM_HEALTH_INDICATOR                                             46
                                  /* Health indicator data history            */
#define SQLM_ELM_HEALTH_INDICATOR_HIST                                        47
                                  /* Node unique info for a bufferpool        */
#define SQLM_ELM_BUFFERPOOL_NODEINFO                                          48
                                  /* Utility info                             */
#define SQLM_ELM_UTILITY                                                      49
                                  /* Health indicator collection data         */
#define SQLM_ELM_HI_OBJ_LIST                                                  50
                                  /* Health indicator collection data history */
#define SQLM_ELM_HI_OBJ_LIST_HIST                                             51
                                  /* Utility progress info                    */
#define SQLM_ELM_PROGRESS                                                     52
                                  /* Utility progress info list               */
#define SQLM_ELM_PROGRESS_LIST                                                53
                                  /* HADR info                                */
#define SQLM_ELM_HADR                                                         54
                                  /* Detail logging information               */
#define SQLM_ELM_DETAIL_LOG                                                   55
                                  /* Runtime Rollback Progress Monitor        */
#define SQLM_ELM_ROLLBACK_PROGRESS                                            56
                                  /* DB storage group paths                   */
#define SQLM_ELM_DB_STORAGE_GROUP                                             57
                                  /* Storage path Info group                  */
#define SQLM_ELM_DB_STO_PATH_INFO                                             58
                                  /* List of Memory Pools                     */
#define SQLM_ELM_MEMORY_POOL_LIST                                             59
                                  /* This value should equal the largest of   */
                                  /* the logical grouping elements            */
#define SQLM_MAX_LOGICAL_ELEMENT                       SQLM_ELM_MEMORY_POOL_LIST
#define SQLM_ELM_FCM_MEMBER                     60 /*       FCM member number */
#define SQLM_ELM_FCM_DBPARTITIONNUM             61 /* FCM DB Partition number */

/******************************************************************************/
/* The following group of defines relate to logical groupings of event monitor*/
/* information. They do not represent data elements, but rather groups of     */
/* data elements                                                              */
/******************************************************************************/

                                          /* database event                   */
#define SQLM_ELM_EVENT_DB                                                    100
                                          /* connection event                 */
#define SQLM_ELM_EVENT_CONN                                                  101
                                          /* table event                      */
#define SQLM_ELM_EVENT_TABLE                                                 102
                                          /* statement event                  */
#define SQLM_ELM_EVENT_STMT                                                  103
                                          /* transaction event                */
#define SQLM_ELM_EVENT_XACT                                                  104
                                          /* deadlock event                   */
#define SQLM_ELM_EVENT_DEADLOCK                                              105
                                          /* deadlocked connection event      */
#define SQLM_ELM_EVENT_DLCONN                                                106
                                          /* tablespace event                 */
#define SQLM_ELM_EVENT_TABLESPACE                                            107
                                          /* database header event            */
#define SQLM_ELM_EVENT_DBHEADER                                              108
                                          /* event monitor start              */
#define SQLM_ELM_EVENT_START                                                 109
                                          /* connection header event          */
#define SQLM_ELM_EVENT_CONNHEADER                                            110
                                          /* overflow event                   */
#define SQLM_ELM_EVENT_OVERFLOW                                              111
                                          /* bufferpool event                 */
#define SQLM_ELM_EVENT_BUFFERPOOL                                            112
                                          /* subsection event                 */
#define SQLM_ELM_EVENT_SUBSECTION                                            113
                                          /* log header event                 */
#define SQLM_ELM_EVENT_LOG_HEADER                                            114
                                          /* lock list for en_dlock           */
#define SQLM_ELM_EVENT_CONTROL                                               115
                                          /* lock list for en_dlock           */
#define SQLM_ELM_EVENT_LOCK_LIST                                             116
                                          /* detailed dlconn event            */
#define SQLM_ELM_EVENT_DETAILED_DLCONN                                       117
                                          /* Mem Pool Infor for CONN Event    */
#define SQLM_ELM_EVENT_CONNMEMUSE                                            118
                                          /* Mem Pool Infor for DB Event      */
#define SQLM_ELM_EVENT_DBMEMUSE                                              119
                                          /* Statement history event          */
#define SQLM_ELM_EVENT_STMT_HISTORY                                          120
                                          /* Parameter values in stmt history */
#define SQLM_ELM_EVENT_DATA_VALUE                                            121
                                          /* Activity event                   */
#define SQLM_ELM_EVENT_ACTIVITY                                              122
                                          /* Activity statement event         */
#define SQLM_ELM_EVENT_ACTIVITYSTMT                                          123
                                          /* Activity statement values event  */
#define SQLM_ELM_EVENT_ACTIVITYVALS                                          124
                                          /* Service Class Stats event        */
#define SQLM_ELM_EVENT_SCSTATS                                               125
                                          /* Work Class Stats event           */
#define SQLM_ELM_EVENT_WCSTATS                                               126
                                          /* Workload Stats event             */
#define SQLM_ELM_EVENT_WLSTATS                                               127
                                          /* Queue Stats event                */
#define SQLM_ELM_EVENT_QSTATS                                                128
                                          /* Histogrambin event               */
#define SQLM_ELM_EVENT_HISTOGRAMBIN                                          129
                                          /* Threshold Violations event       */
#define SQLM_ELM_EVENT_THRESHOLDVIOLATIONS                                   130
                                          /* Locking event                    */
#define SQLM_ELM_EVENT_LOCKING                                               131
#define SQLM_ELM_EVENT_ACTIVITYMETRICS           132 /* ACTIVITYMETRICS event */

                                  /* For events bigger than 4k (or 1k on      */
                                  /* Windows) this identifies the beginning   */
                                  /* block for the entire event.              */
#define SQLM_ELM_EVENT_STARTPIPEBLOCK                                        133
                                  /* For events bigger than 4k (or 1k on      */
                                  /* Windows) this identifies a middle block  */
                                  /* for the entire event.                    */
#define SQLM_ELM_EVENT_MIDPIPEBLOCK                                          134
                                  /* For events bigger than 4k (or 1k on      */
                                  /* Windows) this identifies the ending      */
                                  /* block for the entire event.              */
#define SQLM_ELM_EVENT_ENDPIPEBLOCK                                          135
#define SQLM_ELM_EVENT_SCMETRICS           136 /* Service Class Metrics event */
#define SQLM_ELM_EVENT_WLMETRICS           137 /*      Workload Metrics event */
#define SQLM_ELM_EVENT_OSMETRICS              138 /* OS Metrics logical group */


/******************************************************************************/
/* Timestamps are returned as logic data elements with seconds and            */
/* microseconds returned in seperate base elements                            */
/******************************************************************************/

                                  /* Smallest timestamp element               */
#define SQLM_MIN_TIME_STAMP                                  SQLM_ELM_TIME_STAMP

                                  /* Timestamp                                */
#define SQLM_ELM_TIME_STAMP                                                  200
                                  /* last appl status change time             */
#define SQLM_ELM_STATUS_CHANGE_TIME                                          201
                                  /* Connect start date/time                  */
#define SQLM_ELM_GW_CON_TIME                                                 202
                                  /* prev commit or rollback time             */
#define SQLM_ELM_PREV_UOW_STOP_TIME                                          203
                                  /* time transaction execution started       */
#define SQLM_ELM_UOW_START_TIME                                              204
                                  /* unit-of-work stop time                   */
#define SQLM_ELM_UOW_STOP_TIME                                               205
                                  /* when received from client at the gateway */
#define SQLM_ELM_STMT_START                                                  206
                                  /* when sent to client from the gateway     */
#define SQLM_ELM_STMT_STOP                                                   207
                                  /* Last snapshot reset date and time        */
#define SQLM_ELM_LAST_RESET                                                  208
                                  /* DB2START timestamp                       */
#define SQLM_ELM_DB2START_TIME                                               209
                                  /* Time of 1st database connection          */
#define SQLM_ELM_DB_CONN_TIME                                                210
                                  /* Date/Time of Last Backup                 */
#define SQLM_ELM_LAST_BACKUP                                                 211
                                  /* Time when lock wait entered              */
#define SQLM_ELM_LOCK_WAIT_START_TIME                                        212
                                  /* Connect start date/time                  */
#define SQLM_ELM_APPL_CON_TIME                                               213
                                  /* Connect complete date/time               */
#define SQLM_ELM_CONN_COMPLETE_TIME                                          214
                                  /* Time of last database disconnect         */
#define SQLM_ELM_DISCONN_TIME                                                215
                                  /* Table Event Date and Time                */
#define SQLM_ELM_EVENT_TIME                                                  216
                                  /* Time event started                       */
#define SQLM_ELM_START_TIME                                                  217
                                  /* SQL statement operation stop time        */
#define SQLM_ELM_STOP_TIME                                                   218
                                  /* Time of Log record currently processed   */
#define SQLM_ELM_RF_TIMESTAMP                                                219
                                  /* Time of 1st database connection          */
#define SQLM_ELM_CONN_TIME                                                   220
                                  /* The time of the first overflow           */
#define SQLM_ELM_FIRST_OVERFLOW_TIME                                         221
                                  /* The time of the last overflow            */
#define SQLM_ELM_LAST_OVERFLOW_TIME                                          222
                                  /* Time spent on gateway processing         */
#define SQLM_ELM_GW_EXEC_TIME                                                223
                                  /* total user CPU time of application       */
#define SQLM_ELM_AGENT_USR_CPU_TIME                                          224
                                  /* total application system cpu time        */
#define SQLM_ELM_AGENT_SYS_CPU_TIME                                          225
                                  /* total user CPU time (sec.microsec)       */
#define SQLM_ELM_SS_USR_CPU_TIME                                             226
                                  /* total system CPU time (sec.microsec)     */
#define SQLM_ELM_SS_SYS_CPU_TIME                                             227
                                  /* Total user CPU time of appl agents       */
#define SQLM_ELM_USER_CPU_TIME                                               228
                                  /* Total execution time                     */
#define SQLM_ELM_TOTAL_EXEC_TIME                                             229
                                  /* Time the switch was set                  */
#define SQLM_ELM_SWITCH_SET_TIME                                             230
                                  /* Elapsed execution time                   */
#define SQLM_ELM_ELAPSED_EXEC_TIME                                           231
                                  /* Aggregate response time to queries       */
#define SQLM_ELM_SELECT_TIME                                                 232
                                  /* Aggregate response time to inserts       */
#define SQLM_ELM_INSERT_TIME                                                 233
                                  /* Aggregate response time to updates       */
#define SQLM_ELM_UPDATE_TIME                                                 234
                                  /* Aggregate response time to deletes       */
#define SQLM_ELM_DELETE_TIME                                                 235
                                  /* Aggregate response time to create        */
                                  /* nicknames                                */
#define SQLM_ELM_CREATE_NICKNAME_TIME                                        236
                                  /* Aggregate response time to passthru      */
#define SQLM_ELM_PASSTHRU_TIME                                               237
                                  /* Aggregate response time to stored        */
                                  /* procedures                               */
#define SQLM_ELM_STORED_PROC_TIME                                            238
                                  /* Aggregate responce time to lock remote   */
                                  /* table                                    */
#define SQLM_ELM_REMOTE_LOCK_TIME                                            239
                                  /* High water mark for network time         */
#define SQLM_ELM_NETWORK_TIME_TOP                                            240
                                  /* Low water mark for network time          */
#define SQLM_ELM_NETWORK_TIME_BOTTOM                                         241
#define SQLM_ELM_TABLESPACE_REBALANCER_START_TIME                            242
#define SQLM_ELM_TABLESPACE_REBALANCER_RESTART_TIME                          243
#define SQLM_ELM_TABLESPACE_MIN_RECOVERY_TIME                                244
                                  /* health indicator timestamp               */
#define SQLM_ELM_HI_TIMESTAMP                                                245
                                  /* Maximum timestamp value                  */
#define SQLM_MAX_TIME_STAMP                                SQLM_ELM_HI_TIMESTAMP


/******************************************************************************/
/* Actual database monitor elements                                           */
/******************************************************************************/
                                  /* GMT time in seconds since Jan.1,1970     */
#define SQLM_ELM_SECONDS                                                     300
                                  /* microseconds, range 0 to 999999          */
#define SQLM_ELM_MICROSEC                                                    301
                                  /* used for requests based on app-handle    */
#define SQLM_ELM_AGENT_ID                                                    302
                                  /* Server DB2 Type(defined in sqlutil.h)    */
#define SQLM_ELM_SERVER_DB2_TYPE                                             303
                                  /* product/version on server                */
#define SQLM_ELM_SERVER_PRDID                                                304
                                  /* Config NNAME of server                   */
#define SQLM_ELM_SERVER_NNAME                                                305
                                  /* instance name of DB2                     */
#define SQLM_ELM_SERVER_INSTANCE_NAME                                        306
                                  /* Number of member sending data            */
#define SQLM_ELM_NODE_NUMBER                                                 307
                                  /* Diff. in secs between GMT and local time */
#define SQLM_ELM_TIME_ZONE_DISP                                              308
                                  /* Version of server returning data         */
#define SQLM_ELM_SERVER_VERSION                                              309
                                  /* Application Status                       */
#define SQLM_ELM_APPL_STATUS                                                 310
                                  /* codepage/CCSID identifier                */
#define SQLM_ELM_CODEPAGE_ID                                                 311
                                  /* Statement text                           */
#define SQLM_ELM_STMT_TEXT                                                   312
                                  /* Application Program Name                 */
#define SQLM_ELM_APPL_NAME                                                   313
                                  /* Application Id                           */
#define SQLM_ELM_APPL_ID                                                     314
                                  /* application id sequence number           */
#define SQLM_ELM_SEQUENCE_NO                                                 315
                                  /* Authorization Id                         */
#define SQLM_ELM_AUTH_ID                                                     316
                                  /* (Primary) Authorization Id               */
#define SQLM_ELM_PRIMARY_AUTH_ID                                SQLM_ELM_AUTH_ID
                                  /* Config NNAME of client                   */
#define SQLM_ELM_CLIENT_NNAME                                                317
                                  /* product/version on client                */
#define SQLM_ELM_CLIENT_PRDID                                                318
                                  /* Input Database Alias                     */
#define SQLM_ELM_INPUT_DB_ALIAS                                              319
                                  /* Client Database Alias                    */
#define SQLM_ELM_CLIENT_DB_ALIAS                                             320
                                  /* Database name                            */
#define SQLM_ELM_DB_NAME                                                     321
                                  /* Database Path                            */
#define SQLM_ELM_DB_PATH                                                     322
                                  /* Number of agents associated with this    */
                                  /* application                              */
#define SQLM_ELM_NUM_ASSOC_AGENTS                                            323
                                  /* Coordinating member number               */
#define SQLM_ELM_COORD_NODE_NUM                                              324
                                  /* User authorizations                      */
#define SQLM_ELM_AUTHORITY_LVL                                               325
                                  /* login ID                                 */
#define SQLM_ELM_EXECUTION_ID                                                326
                                  /* DRDA AS Correlation Token                */
#define SQLM_ELM_CORR_TOKEN                                                  327
                                  /* Process/thread ID of client appl.        */
#define SQLM_ELM_CLIENT_PID                                                  328
                                  /* Platform of client application           */
#define SQLM_ELM_CLIENT_PLATFORM                                             329
                                  /* Communications protocol of client        */
#define SQLM_ELM_CLIENT_PROTOCOL                                             330
                                  /* Country code of client application       */
#define SQLM_ELM_COUNTRY_CODE                                                331
                                  /* Territory code of client application     */
#define SQLM_ELM_TERRITORY_CODE                            SQLM_ELM_COUNTRY_CODE
                                  /* Coordinator agent process/thread id      */
#define SQLM_ELM_COORD_AGENT_PID                                             332
                                  /* gateway  Database Alias                  */
#define SQLM_ELM_GW_DB_ALIAS                                                 333
                                  /* Outb. comm. address                      */
#define SQLM_ELM_OUTBOUND_COMM_ADDRESS                                       334
                                  /* Inbound comm. address                    */
#define SQLM_ELM_INBOUND_COMM_ADDRESS                                        335
                                  /* Outbound comm. protocol                  */
#define SQLM_ELM_OUTBOUND_COMM_PROTOCOL                                      336
                                  /* DCS Database name                        */
#define SQLM_ELM_DCS_DB_NAME                                                 337
                                  /* Host Database name                       */
#define SQLM_ELM_HOST_DB_NAME                                                338
                                  /* Host Product id                          */
#define SQLM_ELM_HOST_PRDID                                                  339
                                  /* Outbound LUWID                           */
#define SQLM_ELM_OUTBOUND_APPL_ID                                            340
                                  /* Outbound sequence #                      */
#define SQLM_ELM_OUTBOUND_SEQUENCE_NO                                        341
                                  /* Status of DCS application                */
#define SQLM_ELM_DCS_APPL_STATUS                                             342
                                  /* Host database Coded Char Set ID          */
#define SQLM_ELM_HOST_CCSID                                                  343
                                  /* Switch output state                      */
#define SQLM_ELM_OUTPUT_STATE                                                344
                                  /* The number of overflows                  */
#define SQLM_ELM_COUNT                                                       345
                                  /* # of rows selected                       */
#define SQLM_ELM_ROWS_SELECTED                                               346
                                  /* # of sql stmts attempted                 */
#define SQLM_ELM_SQL_STMTS                                                   347
                                  /* # of Failed SQL stmts                    */
#define SQLM_ELM_FAILED_SQL_STMTS                                            348
                                  /* # of Commit SQL stmts                    */
#define SQLM_ELM_COMMIT_SQL_STMTS                                            349
                                  /* # of Rollback SQL stmts                  */
#define SQLM_ELM_ROLLBACK_SQL_STMTS                                          350
                                  /* inbound # of bytes received              */
#define SQLM_ELM_INBOUND_BYTES_RECEIVED                                      351
                                  /* outbound # of bytes sent                 */
#define SQLM_ELM_OUTBOUND_BYTES_SENT                                         352
                                  /* outbound # of bytes received             */
#define SQLM_ELM_OUTBOUND_BYTES_RECEIVED                                     353
                                  /* inbound # of bytes sent                  */
#define SQLM_ELM_INBOUND_BYTES_SENT                                          354
                                  /* most recent SQL stmt operation           */
#define SQLM_ELM_STMT_OPERATION                                              355
                                  /* most recent SQL stmt section number      */
#define SQLM_ELM_SECTION_NUMBER                                              356
                                  /* Node on which app waited for lock        */
#define SQLM_ELM_LOCK_NODE                                                   357
                                  /* package creator                          */
#define SQLM_ELM_CREATOR                                                     358
                                  /* package name                             */
#define SQLM_ELM_PACKAGE_NAME                                                359
                                  /* time (seconds) since the application     */
                                  /* last completed a statement               */
#define SQLM_ELM_APPL_IDLE_TIME                                              360
                                  /* currently open cursors                   */
#define SQLM_ELM_OPEN_CURSORS                                                361
                                  /* previous uow completion status           */
#define SQLM_ELM_UOW_COMP_STATUS                                             362
                                  /* seq no. holding lock                     */
#define SQLM_ELM_SEQUENCE_NO_HOLDING_LK                                      363
                                  /* Application handle                       */
#define SQLM_ELM_ROLLED_BACK_AGENT_ID                                        364
                                  /* victim's appl id                         */
#define SQLM_ELM_ROLLED_BACK_APPL_ID                                         365
                                  /* victim's seq no.                         */
#define SQLM_ELM_ROLLED_BACK_SEQUENCE_NO                                     366
                                  /* XID                                      */
#define SQLM_ELM_XID                                                         367
                                  /* TP Monitor client user ID                */
#define SQLM_ELM_TPMON_CLIENT_USERID                                         368
                                  /* TP Monitor client workstation            */
#define SQLM_ELM_TPMON_CLIENT_WKSTN                                          369
                                  /* TP Monitor client app. name              */
#define SQLM_ELM_TPMON_CLIENT_APP                                            370
                                  /* Client accounting string                 */
#define SQLM_ELM_TPMON_ACC_STR                                               371
                                  /* SQL compiler estim. in TIMERONS          */
#define SQLM_ELM_QUERY_COST_ESTIMATE                                         372
                                  /* SQL compiler estim. number of rows       */
#define SQLM_ELM_QUERY_CARD_ESTIMATE                                         373
                                  /* total number of rows fetched             */
#define SQLM_ELM_FETCH_COUNT                                                 374
                                  /* # of rows selected (returned)            */
#define SQLM_ELM_ROWS_RETURNED                              SQLM_ELM_FETCH_COUNT
                                  /* connects since db activations            */
#define SQLM_ELM_GW_TOTAL_CONS                                               375
                                  /* appls currently connected                */
#define SQLM_ELM_GW_CUR_CONS                                                 376
                                  /* appls waiting for host's reply           */
#define SQLM_ELM_GW_CONS_WAIT_HOST                                           377
                                  /* appls waiting for client to send         */
#define SQLM_ELM_GW_CONS_WAIT_CLIENT                                         378
                                  /* high water mark for concurrent           */
                                  /* connections                              */
#define SQLM_ELM_GW_CONNECTIONS_TOP                                          379
                                  /* Sort Priv heap currently allocated       */
#define SQLM_ELM_SORT_HEAP_ALLOCATED                                         380
                                  /* # sorts started after heap threshold     */
                                  /* exceeded                                 */
#define SQLM_ELM_POST_THRESHOLD_SORTS                                        381
                                  /* # of piped sorts requested by RDS to SLS */
#define SQLM_ELM_PIPED_SORTS_REQUESTED                                       382
                                  /* # of piped sorts accepted by SLS         */
#define SQLM_ELM_PIPED_SORTS_ACCEPTED                                        383
                                  /* number of conns deadlocked               */
#define SQLM_ELM_DL_CONNS                                                    384
                                  /* Remote connects to target DB2            */
#define SQLM_ELM_REM_CONS_IN                                                 385
                                  /* Remote connects to target exec DB2       */
#define SQLM_ELM_REM_CONS_IN_EXEC                                            386
                                  /* Current Local Connections                */
#define SQLM_ELM_LOCAL_CONS                                                  387
                                  /* Local connects curr exec in DB2          */
#define SQLM_ELM_LOCAL_CONS_IN_EXEC                                          388
                                  /* Local databases w/current connects       */
#define SQLM_ELM_CON_LOCAL_DBASES                                            389
                                  /* Number of agents registered in DB2       */
#define SQLM_ELM_AGENTS_REGISTERED                                           390
                                  /* # of agents waiting on a token           */
#define SQLM_ELM_AGENTS_WAITING_ON_TOKEN                                     391
                                  /* status of the DB2 instance               */
#define SQLM_ELM_DB2_STATUS                                                  392
                                  /* agents_registered high water mark        */
#define SQLM_ELM_AGENTS_REGISTERED_TOP                                       393
                                  /* agents_waiting high water mark           */
#define SQLM_ELM_AGENTS_WAITING_TOP                                          394
                                  /* Committed Private Memory                 */
#define SQLM_ELM_COMM_PRIVATE_MEM                                            395
                                  /* number of unassigned agents in pool      */
#define SQLM_ELM_IDLE_AGENTS                                                 396
                                  /* # agents assigned from pool              */
#define SQLM_ELM_AGENTS_FROM_POOL                                            397
                                  /* # agents created because the pool was    */
                                  /* empty                                    */
#define SQLM_ELM_AGENTS_CREATED_EMPTY_POOL                                   398
                                  /* agents high water mark                   */
#define SQLM_ELM_AGENTS_TOP                                                  399
                                  /* coordinating agents high water mark      */
#define SQLM_ELM_COORD_AGENTS_TOP                                            400
                                  /* # of attempts to exceed the MAXAGENTS    */
                                  /* configuration parameter.                 */
#define SQLM_ELM_MAX_AGENT_OVERFLOWS                                         401
                                  /* # agents stolen                          */
#define SQLM_ELM_AGENTS_STOLEN                                               402
                                  /* Product Name                             */
#define SQLM_ELM_PRODUCT_NAME                                                403
                                  /* Product Identificiation                  */
#define SQLM_ELM_COMPONENT_ID                                                404
                                  /* Service Level                            */
#define SQLM_ELM_SERVICE_LEVEL                                               405
                                  /* # hash joins started after heap          */
                                  /* threshold exceeded                       */
#define SQLM_ELM_POST_THRESHOLD_HASH_JOINS                                   406
                                  /* # of FCM buffers free                    */
#define SQLM_ELM_BUFF_FREE                                                   407
                                  /* low water mark of buffers free           */
#define SQLM_ELM_BUFF_FREE_BOTTOM                                            408
                                  /* # of FCM message anchors free            */
#define SQLM_ELM_MA_FREE                                                     409
                                  /* low water mark of anchors free           */
#define SQLM_ELM_MA_FREE_BOTTOM                                              410
                                  /* # of FCM connection entries free         */
#define SQLM_ELM_CE_FREE                                                     411
                                  /* low water mark of free CEs               */
#define SQLM_ELM_CE_FREE_BOTTOM                                              412
                                  /* # of FCM request blocks free             */
#define SQLM_ELM_RB_FREE                                                     413
                                  /* low water mark of free RBs               */
#define SQLM_ELM_RB_FREE_BOTTOM                                              414
                                  /* FCM Connnection status to node           */
#define SQLM_ELM_CONNECTION_STATUS                                           416
                                  /* Total # of buffers sent                  */
#define SQLM_ELM_TOTAL_BUFFERS_SENT                                          417
                                  /* Total # of buffers received              */
#define SQLM_ELM_TOTAL_BUFFERS_RCVD                                          418
                                  /* Locks currently held                     */
#define SQLM_ELM_LOCKS_HELD                                                  419
                                  /* Lock waits since 1st connect             */
#define SQLM_ELM_LOCK_WAITS                                                  420
                                  /* time spent waiting on locks              */
#define SQLM_ELM_LOCK_WAIT_TIME                                              421
                                  /* lock list memory in use                  */
#define SQLM_ELM_LOCK_LIST_IN_USE                                            422
                                  /* number of deadlocks                      */
#define SQLM_ELM_DEADLOCKS                                                   423
                                  /* number of lock escalations               */
#define SQLM_ELM_LOCK_ESCALS                                                 424
                                  /* number of x-lock excalations             */
#define SQLM_ELM_X_LOCK_ESCALS                                               425
                                  /* agents currently waiting on locks        */
#define SQLM_ELM_LOCKS_WAITING                                               426
                                  /* total number of sorts                    */
#define SQLM_ELM_TOTAL_SORTS                                                 427
                                  /* elapsed time spent in sorts              */
#define SQLM_ELM_TOTAL_SORT_TIME                                             428
                                  /* number of sort overflows                 */
#define SQLM_ELM_SORT_OVERFLOWS                                              429
                                  /* sorts currently active                   */
#define SQLM_ELM_ACTIVE_SORTS                                                430
                                  /* pool data logical reads                  */
#define SQLM_ELM_POOL_DATA_L_READS                                           431
                                  /* pool data reads                          */
#define SQLM_ELM_POOL_DATA_P_READS                                           432
                                  /* pool data writes                         */
#define SQLM_ELM_POOL_DATA_WRITES                                            433
                                  /* pool index logical reads                 */
#define SQLM_ELM_POOL_INDEX_L_READS                                          434
                                  /* pool index reads                         */
#define SQLM_ELM_POOL_INDEX_P_READS                                          435
                                  /* pool index writes                        */
#define SQLM_ELM_POOL_INDEX_WRITES                                           436
                                  /* Buff pool read time                      */
#define SQLM_ELM_POOL_READ_TIME                                              437
                                  /* Buff pool write time                     */
#define SQLM_ELM_POOL_WRITE_TIME                                             438
                                  /* files closed                             */
#define SQLM_ELM_FILES_CLOSED                                                439
                                  /* # of Dynamic SQL stmts                   */
#define SQLM_ELM_DYNAMIC_SQL_STMTS                                           440
                                  /* # of Static SQL stmts                    */
#define SQLM_ELM_STATIC_SQL_STMTS                                            441
                                  /* # of SQL select stmts                    */
#define SQLM_ELM_SELECT_SQL_STMTS                                            442
                                  /* # of data definition lang. stmts         */
#define SQLM_ELM_DDL_SQL_STMTS                                               443
                                  /* # of update/insert/delete stmts          */
#define SQLM_ELM_UID_SQL_STMTS                                               444
                                  /* # of Auto Rebinds                        */
#define SQLM_ELM_INT_AUTO_REBINDS                                            445
                                  /* # of Casc. Deletes                       */
#define SQLM_ELM_INT_ROWS_DELETED                                            446
                                  /* # of Set Null Deletes                    */
#define SQLM_ELM_INT_ROWS_UPDATED                                            447
                                  /* # of int. Commits                        */
#define SQLM_ELM_INT_COMMITS                                                 448
                                  /* # of int. Rollbacks                      */
#define SQLM_ELM_INT_ROLLBACKS                                               449
                                  /* # of Rollbacks due to deadlock           */
#define SQLM_ELM_INT_DEADLOCK_ROLLBACKS                                      450
                                  /* # of Rows Deleted                        */
#define SQLM_ELM_ROWS_DELETED                                                451
                                  /* # of Rows Inserted                       */
#define SQLM_ELM_ROWS_INSERTED                                               452
                                  /* # of Rows Updated                        */
#define SQLM_ELM_ROWS_UPDATED                                                453
                                  /* # of Binds/Precomps                      */
#define SQLM_ELM_BINDS_PRECOMPILES                                           454
                                  /* max locks held in transaction            */
#define SQLM_ELM_LOCKS_HELD_TOP                                              455
                                  /* 1 if SERIAL                              */
#define SQLM_ELM_NUM_NODES_IN_DB2_INSTANCE                                   456
                                  /* total number of connects                 */
#define SQLM_ELM_TOTAL_CONS                                                  457
                                  /* Appls currently connected                */
#define SQLM_ELM_APPLS_CUR_CONS                                              458
                                  /* Appls executing in the DB2               */
#define SQLM_ELM_APPLS_IN_DB2                                                459
                                  /* Maximum secondary log space used         */
#define SQLM_ELM_SEC_LOG_USED_TOP                                            460
                                  /* Maximum total log space used             */
#define SQLM_ELM_TOT_LOG_USED_TOP                                            461
                                  /* Number of secondary logs allocated       */
#define SQLM_ELM_SEC_LOGS_ALLOCATED                                          462
                                  /* asynchronous pool index reads            */
#define SQLM_ELM_POOL_ASYNC_INDEX_READS                                      463
                                  /* #pages copied from BP to estore          */
#define SQLM_ELM_POOL_DATA_TO_ESTORE                                         464
                                  /* #pages copied from BP to estore          */
#define SQLM_ELM_POOL_INDEX_TO_ESTORE                                        465
                                  /* #pages copied from estore to BP          */
#define SQLM_ELM_POOL_INDEX_FROM_ESTORE                                      466
                                  /* #pages copied from estore to BP          */
#define SQLM_ELM_POOL_DATA_FROM_ESTORE                                       467
                                  /* status of the Database                   */
#define SQLM_ELM_DB_STATUS                                                   468
                                  /* # of lock timeouts                       */
#define SQLM_ELM_LOCK_TIMEOUTS                                               469
                                  /* high water mark for current connections  */
#define SQLM_ELM_CONNECTIONS_TOP                                             470
                                  /* high water mark for database heap        */
#define SQLM_ELM_DB_HEAP_TOP                                                 471
                                  /* asynchronous pool data reads             */
#define SQLM_ELM_POOL_ASYNC_DATA_READS                                       472
                                  /* asynchronous pool data writes            */
#define SQLM_ELM_POOL_ASYNC_DATA_WRITES                                      473
                                  /* asynchronous pool indx writes            */
#define SQLM_ELM_POOL_ASYNC_INDEX_WRITES                                     474
                                  /* total async read time                    */
#define SQLM_ELM_POOL_ASYNC_READ_TIME                                        475
                                  /* total async write time                   */
#define SQLM_ELM_POOL_ASYNC_WRITE_TIME                                       476
                                  /* # async read requests                    */
#define SQLM_ELM_POOL_ASYNC_DATA_READ_REQS                                   477
                                  /* LSN Gap cleaner triggers                 */
#define SQLM_ELM_POOL_LSN_GAP_CLNS                                           478
                                  /* dirty page steal cleaner triggers        */
#define SQLM_ELM_POOL_DRTY_PG_STEAL_CLNS                                     479
                                  /* dirty list threshold cln trig            */
#define SQLM_ELM_POOL_DRTY_PG_THRSH_CLNS                                     480
                                  /* direct reads                             */
#define SQLM_ELM_DIRECT_READS                                                481
                                  /* direct writes                            */
#define SQLM_ELM_DIRECT_WRITES                                               482
                                  /* direct read requests                     */
#define SQLM_ELM_DIRECT_READ_REQS                                            483
                                  /* direct write requests                    */
#define SQLM_ELM_DIRECT_WRITE_REQS                                           484
                                  /* direct read time                         */
#define SQLM_ELM_DIRECT_READ_TIME                                            485
                                  /* direct write time                        */
#define SQLM_ELM_DIRECT_WRITE_TIME                                           486
                                  /* # rows insrted for Trigger               */
#define SQLM_ELM_INT_ROWS_INSERTED                                           487
                                  /* # of log pages read                      */
#define SQLM_ELM_LOG_READS                                                   488
                                  /* # of log pages read                      */
#define SQLM_ELM_LOG_WRITES                                                  489
                                  /* # of section lookups                     */
#define SQLM_ELM_PKG_CACHE_LOOKUPS                                           490
                                  /* # of sections inserted into cache        */
#define SQLM_ELM_PKG_CACHE_INSERTS                                           491
                                  /* # of table descriptor lookups            */
#define SQLM_ELM_CAT_CACHE_LOOKUPS                                           492
                                  /* # of table descriptors inserted          */
#define SQLM_ELM_CAT_CACHE_INSERTS                                           493
                                  /* # of catalog cache overflows             */
#define SQLM_ELM_CAT_CACHE_OVERFLOWS                                         494
                                  /* Obsolete in V8 - always reported as 0 -  */
                                  /* use CAT_CACHE_SIZE_TOP                   */
#define SQLM_ELM_CAT_CACHE_HEAP_FULL                                         495
                                  /* Catalog node number                      */
#define SQLM_ELM_CATALOG_NODE                                                496
                                  /* Secondary connects database connection   */
                                  /* with appls connected to this db.         */
#define SQLM_ELM_TOTAL_SEC_CONS                                              497
                                  /* local or remote to snapshot appl.        */
#define SQLM_ELM_DB_LOCATION                                                 498
                                  /* OS on which dbm runs                     */
#define SQLM_ELM_SERVER_PLATFORM                                             499
                                  /* Catalog network node name                */
#define SQLM_ELM_CATALOG_NODE_NAME                                           500
                                  /* Time waited for prefetch (ms)            */
#define SQLM_ELM_PREFETCH_WAIT_TIME                                          501
                                  /* # of section lookups                     */
#define SQLM_ELM_APPL_SECTION_LOOKUPS                                        502
                                  /* # of sections inserted                   */
#define SQLM_ELM_APPL_SECTION_INSERTS                                        503
                                  /* number of hash joins                     */
#define SQLM_ELM_TOTAL_HASH_JOINS                                            504
                                  /* number of hash loops                     */
#define SQLM_ELM_TOTAL_HASH_LOOPS                                            505
                                  /* number of hash join overflows            */
#define SQLM_ELM_HASH_JOIN_OVERFLOWS                                         506
                                  /* small hash join overflows                */
#define SQLM_ELM_HASH_JOIN_SMALL_OVERFLOWS                                   507
                                  /* time UOW waited on locks (ms)            */
#define SQLM_ELM_UOW_LOCK_WAIT_TIME                                          508
                                  /* Statement type indicator                 */
#define SQLM_ELM_STMT_TYPE                                                   509
                                  /* Name of cursor                           */
#define SQLM_ELM_CURSOR_NAME                                                 510
                                  /* Log space used in most recent UOW        */
#define SQLM_ELM_UOW_LOG_SPACE_USED                                          511
                                  /* Currently open remote cursors            */
#define SQLM_ELM_OPEN_REM_CURS                                               512
                                  /* Currently open rem cursors w/blk         */
#define SQLM_ELM_OPEN_REM_CURS_BLK                                           513
                                  /* Rej block remote cursor requests         */
#define SQLM_ELM_REJ_CURS_BLK                                                514
                                  /* Acc block remote cursor requests         */
#define SQLM_ELM_ACC_CURS_BLK                                                515
                                  /* Event Monitor Version                    */
#define SQLM_ELM_VERSION                                                     516
                                  /* Name of the Event Mon                    */
#define SQLM_ELM_EVENT_MONITOR_NAME                                          517
                                  /* # SQL requests since last commit         */
#define SQLM_ELM_SQL_REQS_SINCE_COMMIT                                       518
                                  /* Big Endian or Little Endian              */
#define SQLM_ELM_BYTE_ORDER                                                  520
                                  /* Worst prep time of statement             */
#define SQLM_ELM_PREP_TIME_WORST                                             521
                                  /* # rows read                              */
#define SQLM_ELM_ROWS_READ                                                   522
                                  /* # rows read                              */
#define SQLM_ELM_ROWS_FETCHED                                 SQLM_ELM_ROWS_READ
                                  /* # rows written                           */
#define SQLM_ELM_ROWS_WRITTEN                                                523
                                  /* # of rows modified (synonym)             */
#define SQLM_ELM_ROWS_MODIFIED                             SQLM_ELM_ROWS_WRITTEN
                                  /* Currently open local cursors             */
#define SQLM_ELM_OPEN_LOC_CURS                                               524
                                  /* Currently open local cursors w/blk       */
#define SQLM_ELM_OPEN_LOC_CURS_BLK                                           525
                                  /* Coordinating node number.                */
#define SQLM_ELM_COORD_NODE                                                  526
                                  /* Coordinating partition number            */
#define SQLM_ELM_COORD_PARTITION_NUM                         SQLM_ELM_COORD_NODE
                                  /* # of agents currently active             */
#define SQLM_ELM_NUM_AGENTS                                                  527
                                  /* # of agents associated with this         */
                                  /* application  high water mark.            */
#define SQLM_ELM_ASSOCIATED_AGENTS_TOP                                       528
                                  /* priority at which appl agents work       */
#define SQLM_ELM_APPL_PRIORITY                                               529
                                  /* Dynamic or Static                        */
#define SQLM_ELM_APPL_PRIORITY_TYPE                                          530
                                  /* SMP Intraquery Parallelism req           */
#define SQLM_ELM_DEGREE_PARALLELISM                                          531
                                  /* number of sorts for this statement       */
#define SQLM_ELM_STMT_SORTS                                                  532
                                  /* total user CPU time of SQL stmt          */
#define SQLM_ELM_STMT_USR_CPU_TIME                                           533
                                  /* total system CPU time for SQL stmt       */
#define SQLM_ELM_STMT_SYS_CPU_TIME                                           534
                                  /* Subsection number                        */
#define SQLM_ELM_SS_NUMBER                                                   535
                                  /* Subsection status                        */
#define SQLM_ELM_SS_STATUS                                                   536
                                  /* Node where the subsec is executing       */
#define SQLM_ELM_SS_NODE_NUMBER                                              537
                                  /* Execution elapsed time in seconds        */
#define SQLM_ELM_SS_EXEC_TIME                                                538
                                  /* Best prep time of statement              */
#define SQLM_ELM_PREP_TIME_BEST                                              539
                                  /* Number of compilation environments       */
#define SQLM_ELM_NUM_COMPILATIONS                                            540
                                  /* If blocked when sending or receiving on  */
                                  /* a tablequeue, node for which we wait     */
#define SQLM_ELM_TQ_NODE_WAITED_FOR                                          541
                                  /* TRUE if waiting for any node             */
#define SQLM_ELM_TQ_WAIT_FOR_ANY                                             542
                                  /* tablequeue waiting to send/receive       */
#define SQLM_ELM_TQ_ID_WAITING_ON                                            543
                                  /* Total # of buffers overflowed to a temp  */
                                  /* table when sending on a tq               */
#define SQLM_ELM_TQ_TOT_SEND_SPILLS                                          544
                                  /* Current # of tq send buffers overflowed  */
#define SQLM_ELM_TQ_CUR_SEND_SPILLS                                          545
                                  /* Maximum # of tq send buffers overflowed  */
#define SQLM_ELM_TQ_MAX_SEND_SPILLS                                          546
                                  /* Total # rows received on tablequeues     */
#define SQLM_ELM_TQ_ROWS_READ                                                547
                                  /* Total # rows sent on tablequeues         */
#define SQLM_ELM_TQ_ROWS_WRITTEN                                             548
                                  /* db2agent process/thread id               */
#define SQLM_ELM_AGENT_PID                                                   549
                                  /* Was this lock part of an escalation      */
#define SQLM_ELM_LOCK_ESCALATION                                             550
                                  /* Subsection waiting for lock              */
#define SQLM_ELM_SUBSECTION_NUMBER                                           551
                                  /* Mode of Lock waited on                   */
#define SQLM_ELM_LOCK_MODE                                                   552
                                  /* lock object type: row, table,            */
#define SQLM_ELM_LOCK_OBJECT_TYPE                                            553
                                  /* Number of executions                     */
#define SQLM_ELM_NUM_EXECUTIONS                                              554
                                  /* Table name                               */
#define SQLM_ELM_TABLE_NAME                                                  555
                                  /* Schema name                              */
#define SQLM_ELM_TABLE_SCHEMA                                                556
                                  /* Tablespace name                          */
#define SQLM_ELM_TABLESPACE_NAME                                             557
                                  /* Application holding the lock             */
#define SQLM_ELM_AGENT_ID_HOLDING_LK                                         558
                                  /* Appl. holding the lock                   */
#define SQLM_ELM_APPL_ID_HOLDING_LK                                          559
                                  /* the file ID for the table                */
#define SQLM_ELM_TABLE_FILE_ID                                               561
                                  /* table type                               */
#define SQLM_ELM_TABLE_TYPE                                                  562
                                  /* no. of accesses to overflow rec          */
#define SQLM_ELM_OVERFLOW_ACCESSES                                           563
                                  /* no. of page reorgs for table             */
#define SQLM_ELM_PAGE_REORGS                                                 564
                                  /* size of the sqlca                        */
#define SQLM_ELM_SQLCABC                                                     565
                                  /* Lock status                              */
#define SQLM_ELM_LOCK_STATUS                                                 566
                                  /* Lock Object Name - RID or FID of lock    */
                                  /* obj                                      */
#define SQLM_ELM_LOCK_OBJECT_NAME                                            567
                                  /* database or tablespace rollforward       */
#define SQLM_ELM_RF_TYPE                                                     568
                                  /* Current log being processed              */
#define SQLM_ELM_RF_LOG_NUM                                                  569
                                  /* Log phase in progress                    */
#define SQLM_ELM_RF_STATUS                                                   570
                                  /* Tablespace being rolled forward          */
#define SQLM_ELM_TS_NAME                                                     571
                                  /* Bufferpool name                          */
#define SQLM_ELM_BP_NAME                                                     572
                                  /* Statement node number                    */
#define SQLM_ELM_STMT_NODE_NUMBER                                            573
                                  /* partial record for flush evmon           */
#define SQLM_ELM_PARTIAL_RECORD                                              574
                                  /* Amount of system cpu time used           */
#define SQLM_ELM_SYSTEM_CPU_TIME                                             575
                                  /* An sqlca                                 */
#define SQLM_ELM_SQLCA                                                       576
                                  /* sqlcode of the sqlca                     */
#define SQLM_ELM_SQLCODE                                                     577
                                  /* length of ca message tokens              */
#define SQLM_ELM_SQLERRML                                                    578
                                  /* message tokensessage tokens              */
#define SQLM_ELM_SQLERRMC                                                    579
                                  /* diagnostic information                   */
#define SQLM_ELM_SQLERRP                                                     580
                                  /* diagnostic information                   */
#define SQLM_ELM_SQLERRD                                                     581
                                  /* warning flags                            */
#define SQLM_ELM_SQLWARN                                                     582
                                  /* state corresponding to SQLCODE           */
#define SQLM_ELM_SQLSTATE                                                    583
                                  /* uow status                               */
#define SQLM_ELM_UOW_STATUS                                                  584
                                  /* elapsed system cpu time                  */
#define SQLM_ELM_TOTAL_SYS_CPU_TIME                                          585
                                  /* elapsed user   cpu time                  */
#define SQLM_ELM_TOTAL_USR_CPU_TIME                                          586
                                  /* the lock mode requested                  */
#define SQLM_ELM_LOCK_MODE_REQUESTED                                         587
                                  /* number of primed gw agents               */
#define SQLM_ELM_INACTIVE_GW_AGENTS                                          588
                                  /* number of times an primed agent was      */
                                  /* stolen.                                  */
#define SQLM_ELM_NUM_GW_CONN_SWITCHES                                        589
                                  /* number of comm erros on the gw           */
#define SQLM_ELM_GW_COMM_ERRORS                                              590
                                  /* time of the most recent comm err         */
#define SQLM_ELM_GW_COMM_ERROR_TIME                                          591
                                  /* time the most recent conn started        */
#define SQLM_ELM_GW_CON_START_TIME                                           592
                                  /* most recent connection response tm       */
#define SQLM_ELM_CON_RESPONSE_TIME                                           593
                                  /* elapsed connected time of most recent    */
                                  /* disconnect                               */
#define SQLM_ELM_CON_ELAPSED_TIME                                            594
                                  /* elapsed response time from host          */
#define SQLM_ELM_HOST_RESPONSE_TIME                                          595
                                  /* number of pkg cache overflows            */
#define SQLM_ELM_PKG_CACHE_NUM_OVERFLOWS                                     596
                                  /* high water mark for pkg cache size       */
#define SQLM_ELM_PKG_CACHE_SIZE_TOP                                          597
                                  /* transaction holding oldest xact          */
#define SQLM_ELM_APPL_ID_OLDEST_XACT                                         598
                                  /* log space used by database               */
#define SQLM_ELM_TOTAL_LOG_USED                                              599
                                  /* log space available in database          */
#define SQLM_ELM_TOTAL_LOG_AVAILABLE                                         600
                                  /* previous statement elapsed time          */
#define SQLM_ELM_STMT_ELAPSED_TIME                                           601
                                  /* previous uow elpased time                */
#define SQLM_ELM_UOW_ELAPSED_TIME                                            602
                                  /* sqlca eyecatcher                         */
#define SQLM_ELM_SQLCAID                                                     603
                                  /* node with worst log  ratio               */
#define SQLM_ELM_SMALLEST_LOG_AVAIL_NODE                                     604
                                  /* number of disconnects                    */
#define SQLM_ELM_DISCONNECTS                                                 605
                                  /* number of create nickname stmts          */
#define SQLM_ELM_CREATE_NICKNAME                                             606
                                  /* number of stmts passed through           */
#define SQLM_ELM_PASSTHRUS                                                   607
                                  /* number of stored procedures              */
#define SQLM_ELM_STORED_PROCS                                                608
                                  /* number of rows returned from stored      */
                                  /* procedures                               */
#define SQLM_ELM_SP_ROWS_SELECTED                                            609
                                  /* Remote datasource name                   */
#define SQLM_ELM_DATASOURCE_NAME                                             610
                                  /* number of remote table lock stmts        */
#define SQLM_ELM_REMOTE_LOCKS                                                611
                                  /* Blocking cursor                          */
#define SQLM_ELM_BLOCKING_CURSOR                                             612
                                  /* outbound blocking cursor                 */
#define SQLM_ELM_OUTBOUND_BLOCKING_CURSOR                                    613
                                  /* Insert sql statements                    */
#define SQLM_ELM_INSERT_SQL_STMTS                                            614
                                  /* Update sql statements                    */
#define SQLM_ELM_UPDATE_SQL_STMTS                                            615
                                  /* Delete sql statements                    */
#define SQLM_ELM_DELETE_SQL_STMTS                                            616
                                  /* unread prefetch pages                    */
#define SQLM_ELM_UNREAD_PREFETCH_PAGES                                       617
                                  /* work agent association status            */
#define SQLM_ELM_AGENT_STATUS                                                618
                                  /* Number of Transmissions                  */
#define SQLM_ELM_NUM_TRANSMISSIONS                                           619
                                  /* High water mark for number of bytes sent */
#define SQLM_ELM_OUTBOUND_BYTES_SENT_TOP                                     620
                                  /* High water mark for number of bytes      */
                                  /* received                                 */
#define SQLM_ELM_OUTBOUND_BYTES_RECEIVED_TOP                                 621
                                  /* Low water mark for number of bytes sent  */
#define SQLM_ELM_OUTBOUND_BYTES_SENT_BOTTOM                                  622
                                  /* High water mark for num of bytes         */
                                  /* received                                 */
#define SQLM_ELM_OUTBOUND_BYTES_RECEIVED_BOTTOM                              623

/*  The following elements represent counts of the number of transmissions    */
/*  whose size in bytes is less than or equal to the number in the name.      */
                                  /* Cnt:Sent size <= 128 bytes               */
#define SQLM_ELM_MAX_DATA_SENT_128                                           624
                                  /* Cnt:Sent size <= 256 bytes               */
#define SQLM_ELM_MAX_DATA_SENT_256                                           625
                                  /* Cnt:Sent size <= 512 bytes               */
#define SQLM_ELM_MAX_DATA_SENT_512                                           626
                                  /* Cnt:Sent size <= 1024 bytes              */
#define SQLM_ELM_MAX_DATA_SENT_1024                                          627
                                  /* Cnt:Sent size <= 2048 bytes              */
#define SQLM_ELM_MAX_DATA_SENT_2048                                          628
                                  /* Cnt:Sent size <= 4096 bytes              */
#define SQLM_ELM_MAX_DATA_SENT_4096                                          629
                                  /* Cnt:Sent size <= 8192 bytes              */
#define SQLM_ELM_MAX_DATA_SENT_8192                                          630
                                  /* Cnt:Sent size <= 16384 bytes             */
#define SQLM_ELM_MAX_DATA_SENT_16384                                         631
                                  /* Cnt:Sent size <= 31999 bytes             */
#define SQLM_ELM_MAX_DATA_SENT_31999                                         632
                                  /* Cnt:Sent size <= 64000 bytes             */
#define SQLM_ELM_MAX_DATA_SENT_64000                                         633
                                  /* Cnt:Sent size > 64000 bytes              */
#define SQLM_ELM_MAX_DATA_SENT_GT64000                                       634
                                  /* Cnt:Rcv size <= 128 bytes                */
#define SQLM_ELM_MAX_DATA_RECEIVED_128                                       635
                                  /* Cnt:Rcv size <= 256 bytes                */
#define SQLM_ELM_MAX_DATA_RECEIVED_256                                       636
                                  /* Cnt:Rcv size <= 512 bytes                */
#define SQLM_ELM_MAX_DATA_RECEIVED_512                                       637
                                  /* Cnt:Rcv size <= 1024 bytes               */
#define SQLM_ELM_MAX_DATA_RECEIVED_1024                                      638
                                  /* Cnt:Rcv size <= 2048 bytes               */
#define SQLM_ELM_MAX_DATA_RECEIVED_2048                                      639
                                  /* Cnt:Rcv size <= 4096 bytes               */
#define SQLM_ELM_MAX_DATA_RECEIVED_4096                                      640
                                  /* Cnt:Rcv size <= 8192 bytes               */
#define SQLM_ELM_MAX_DATA_RECEIVED_8192                                      641
                                  /* Cnt:Rcv size <= 16384 bytes              */
#define SQLM_ELM_MAX_DATA_RECEIVED_16384                                     642
                                  /* Cnt:Rcv size <= 31999 bytes              */
#define SQLM_ELM_MAX_DATA_RECEIVED_31999                                     643
                                  /* Cnt:Rcv size <= 64000 bytes              */
#define SQLM_ELM_MAX_DATA_RECEIVED_64000                                     644
                                  /* Cnt:Rcv size > 64000 bytes               */
#define SQLM_ELM_MAX_DATA_RECEIVED_GT64000                                   645

/*  The following elements represent counts of the number of transmissions    */
/*  whose network transmission time is less than the time (in milliseconds)   */
/*  in the name.                                                              */
                                  /* Cnt:network time <= 2 millisec.          */
#define SQLM_ELM_MAX_TIME_2_MS                                               646
                                  /* Cnt:network time <= 4 millisec.          */
#define SQLM_ELM_MAX_TIME_4_MS                                               647
                                  /* Cnt:network time <= 8 millisec.          */
#define SQLM_ELM_MAX_TIME_8_MS                                               648
                                  /* Cnt:network time <= 16 millisec.         */
#define SQLM_ELM_MAX_TIME_16_MS                                              649
                                  /* Cnt:network time <= 32 millisec.         */
#define SQLM_ELM_MAX_TIME_32_MS                                              650
                                  /* Cnt:network time > 32 millisec.          */
#define SQLM_ELM_MAX_TIME_GT32_MS                                            651

/* Deadlock Identification elements.                                          */
                                  /* Deadlock ID on the node                  */
#define SQLM_ELM_DEADLOCK_ID                                                 652
                                  /* Node where found                         */
#define SQLM_ELM_DEADLOCK_NODE                                               653

/* Deadlock Participant numbers                                               */
                                  /* # of part. within this deadlock          */
#define SQLM_ELM_PARTICIPANT_NO                                              654
                                  /* part. # of deadlocked connection holding */
                                  /* lock we are waiting for                  */
#define SQLM_ELM_PARTICIPANT_NO_HOLDING_LK                                   655
                                  /* participant number of the rolled back    */
                                  /* application                              */
#define SQLM_ELM_ROLLED_BACK_PARTICIPANT_NO                                  656

/* Please make these 6 element always consecutive, sqlmetart.C relys on this  */
                                  /* 1st of the array                         */
#define SQLM_ELM_SQLERRD1                                                    657
                                  /* 2nd of the array                         */
#define SQLM_ELM_SQLERRD2                                                    658
                                  /* 3rd of the array                         */
#define SQLM_ELM_SQLERRD3                                                    659
                                  /* 4th of the array                         */
#define SQLM_ELM_SQLERRD4                                                    660
                                  /* 5th of the array                         */
#define SQLM_ELM_SQLERRD5                                                    661
                                  /* 6th of the array                         */
#define SQLM_ELM_SQLERRD6                                                    662

/*Event monitor new elements added  */
                                  /* Number of evmon is activated             */
#define SQLM_ELM_EVMON_ACTIVATES                                             663
                                  /* Number of evmon is flushed               */
#define SQLM_ELM_EVMON_FLUSHES                                               664
                                  /* A unique identifier for SQL request      */
#define SQLM_ELM_SQL_REQ_ID                                                  665

/*New elements added for WTT control table                                    */
                                  /* The message in the control table         */
#define SQLM_ELM_MESSAGE                                                     666
                                  /* The timestamp for the above message      */
#define SQLM_ELM_MESSAGE_TIME                                                667

/* Elements for dynamic bufferpool                                            */
#define SQLM_ELM_VECTORED_IOS                                                668
#define SQLM_ELM_PAGES_FROM_VECTORED_IOS                                     669
#define SQLM_ELM_BLOCK_IOS                                                   670
#define SQLM_ELM_PAGES_FROM_BLOCK_IOS                                        671
#define SQLM_ELM_PHYSICAL_PAGE_MAPS                                          672

/* Specifies the number of locks in the detailed dlconn lock list             */
#define SQLM_ELM_LOCKS_IN_LIST                                               673

/* Elements for table reorg                                                   */
#define SQLM_ELM_REORG_PHASE                                                 674
#define SQLM_ELM_REORG_MAX_PHASE                                             675
#define SQLM_ELM_REORG_CURRENT_COUNTER                                       676
#define SQLM_ELM_REORG_MAX_COUNTER                                           677
#define SQLM_ELM_REORG_TYPE                                                  678
#define SQLM_ELM_REORG_STATUS                                                679
#define SQLM_ELM_REORG_COMPLETION                                            680
#define SQLM_ELM_REORG_START                                                 681
#define SQLM_ELM_REORG_END                                                   682
#define SQLM_ELM_REORG_PHASE_START                                           683
#define SQLM_ELM_REORG_INDEX_ID                                              684
#define SQLM_ELM_REORG_TBSPC_ID                                              685


/*Pool memory elements                                                        */
                                  /* Pool identifier                          */
#define SQLM_ELM_POOL_ID                                                     686
                                  /* Current size of storage pool             */
#define SQLM_ELM_POOL_CUR_SIZE                                               687
                                  /* Configured size for a pool (v8.2)        */
#define SQLM_ELM_POOL_CONFIG_SIZE                                            688
                                  /* Largest size pool can have (v8.1)        */
#define SQLM_ELM_POOL_MAX_SIZE                           SQLM_ELM_POOL_CONFIG_SIZE
                                  /* Largest amount used so far               */
#define SQLM_ELM_POOL_WATERMARK                                              689

/* Elements for tablespace containers                                         */
                                  /* Tablespace identifier                    */
#define SQLM_ELM_TABLESPACE_ID                                               690
                                  /* Type of TS - DMS or SMS                  */
#define SQLM_ELM_TABLESPACE_TYPE                                             691
                                  /* Type of data in this TS                  */
#define SQLM_ELM_TABLESPACE_CONTENT_TYPE                                     692
                                  /* Describes current TS state               */
#define SQLM_ELM_TABLESPACE_STATE                                            693
                                  /* Size for each TS page                    */
#define SQLM_ELM_TABLESPACE_PAGE_SIZE                                        694
                                  /* # of pages in each TS extent             */
#define SQLM_ELM_TABLESPACE_EXTENT_SIZE                                      695
                                  /* # of pages for prefetching               */
#define SQLM_ELM_TABLESPACE_PREFETCH_SIZE                                    696
                                  /* Current buffer pool id                   */
#define SQLM_ELM_TABLESPACE_CUR_POOL_ID                                      697
                                  /* Buffer pool id next startup              */
#define SQLM_ELM_TABLESPACE_NEXT_POOL_ID                                     698
                                  /* Total num pages in TS                    */
#define SQLM_ELM_TABLESPACE_TOTAL_PAGES                                      699
                                  /* # usable pages in TS                     */
#define SQLM_ELM_TABLESPACE_USABLE_PAGES                                     700
                                  /* # pages used in TS                       */
#define SQLM_ELM_TABLESPACE_USED_PAGES                                       701
                                  /* # free pages in TS                       */
#define SQLM_ELM_TABLESPACE_FREE_PAGES                                       702
                                  /* Page # of 1st free extent                */
#define SQLM_ELM_TABLESPACE_PAGE_TOP                                         703
                                  /* # pending free pages                     */
#define SQLM_ELM_TABLESPACE_PENDING_FREE_PAGES                               704
                                  /* Rebal Mode - Forward/Rev                 */
#define SQLM_ELM_TABLESPACE_REBALANCER_MODE                                  705
                                  /* # ext to be done                         */
#define SQLM_ELM_TABLESPACE_REBALANCER_EXTENTS_REMAINING                     706
                                  /* # extents done                           */
#define SQLM_ELM_TABLESPACE_REBALANCER_EXTENTS_PROCESSED                     707
                                  /* last extent moved                        */
#define SQLM_ELM_TABLESPACE_REBALANCER_LAST_EXTENT_MOVED                     708
                                  /* Priority of rebalancer                   */
#define SQLM_ELM_TABLESPACE_REBALANCER_PRIORITY                              709
                                  /* # of quiescers                           */
#define SQLM_ELM_TABLESPACE_NUM_QUIESCERS                                    710
                                  /* Obj ID of object that caused TS state to */
                                  /* be changed                               */
#define SQLM_ELM_TABLESPACE_STATE_CHANGE_OBJECT_ID                           711
                                  /* TS id of object that caused TS state to  */
                                  /* be changed                               */
#define SQLM_ELM_TABLESPACE_STATE_CHANGE_TS_ID                               712
                                  /* # of containers in TS                    */
#define SQLM_ELM_TABLESPACE_NUM_CONTAINERS                                   713
                                  /* # of ranges in TS map                    */
#define SQLM_ELM_TABLESPACE_NUM_RANGES                                       714
                                  /* State of the quiesce                     */
#define SQLM_ELM_QUIESCER_STATE                                              715
                                  /* Agent id of agent holding the quiesce    */
                                  /* state                                    */
#define SQLM_ELM_QUIESCER_AGENT_ID                                           716
                                  /* TS id of object causing tablespace to be */
                                  /* quiesced                                 */
#define SQLM_ELM_QUIESCER_TS_ID                                              717
                                  /* Object ID of object causing tablespace   */
                                  /* to be quiesced                           */
#define SQLM_ELM_QUIESCER_OBJ_ID                                             718
                                  /* Auth id of user holding the quiesce      */
                                  /* state                                    */
#define SQLM_ELM_QUIESCER_AUTH_ID                                            719
                                  /* Container identifier                     */
#define SQLM_ELM_CONTAINER_ID                                                720
                                  /* Type of container                        */
#define SQLM_ELM_CONTAINER_TYPE                                              721
                                  /* Total # pages in container               */
#define SQLM_ELM_CONTAINER_TOTAL_PAGES                                       722
                                  /* # usable pages in container              */
#define SQLM_ELM_CONTAINER_USABLE_PAGES                                      723
                                  /* Stripe set cont. belongs to              */
#define SQLM_ELM_CONTAINER_STRIPE_SET                                        724
                                  /* Is container accessible?                 */
#define SQLM_ELM_CONTAINER_ACCESSIBLE                                        725
                                  /* Name of the container                    */
#define SQLM_ELM_CONTAINER_NAME                                              726
                                  /* Stripe set range resides in              */
#define SQLM_ELM_RANGE_STRIPE_SET_NUMBER                                     727
                                  /* The number of the range                  */
#define SQLM_ELM_RANGE_NUMBER                                                728
                                  /* Offset from stripe 0                     */
#define SQLM_ELM_RANGE_OFFSET                                                729
                                  /* Max page # in the range                  */
#define SQLM_ELM_RANGE_MAX_PAGE_NUMBER                                       730
                                  /* Max extent # in the range                */
#define SQLM_ELM_RANGE_MAX_EXTENT                                            731
                                  /* # of first stripe in range               */
#define SQLM_ELM_RANGE_START_STRIPE                                          732
                                  /* # of last stripe in range                */
#define SQLM_ELM_RANGE_END_STRIPE                                            733
                                  /* Offset into which the range actually     */
                                  /* starts                                   */
#define SQLM_ELM_RANGE_ADJUSTMENT                                            734
                                  /* # of containers in the range             */
#define SQLM_ELM_RANGE_NUM_CONTAINERS                                        735
                                  /* ID of container belonging to the current */
                                  /* range                                    */
#define SQLM_ELM_RANGE_CONTAINER_ID                                          736

                                  /* Package Consistency Token                */
#define SQLM_ELM_CONSISTENCY_TOKEN                                           737
                                  /* Package version identifier               */
#define SQLM_ELM_PACKAGE_VERSION_ID                                          738

                                  /* binary lock name                         */
#define SQLM_ELM_LOCK_NAME                                                   739
                                  /* lock count                               */
#define SQLM_ELM_LOCK_COUNT                                                  740
                                  /* hold count                               */
#define SQLM_ELM_LOCK_HOLD_COUNT                                             741
                                  /* lock attributes                          */
#define SQLM_ELM_LOCK_ATTRIBUTES                                             742
                                  /* internal release bits                    */
#define SQLM_ELM_LOCK_RELEASE_FLAGS                                          743
                                  /* orig mode before conversion              */
#define SQLM_ELM_LOCK_CURRENT_MODE                                           744
                                  /* fs caching                               */
#define SQLM_ELM_TABLESPACE_FS_CACHING                                       745


/******************************************************************************/
/* Dynamic Bufferpool                                                         */
/******************************************************************************/
                                  /* # of tblspaces mapped to BP              */
#define SQLM_ELM_BP_TBSP_USE_COUNT                                           751
                                  /* # pages left to remove                   */
#define SQLM_ELM_BP_PAGES_LEFT_TO_REMOVE                                     752
                                  /* Current size of bufferpool               */
#define SQLM_ELM_BP_CUR_BUFFSZ                                               753
                                  /* BP size after imdt/def. alt              */
#define SQLM_ELM_BP_NEW_BUFFSZ                                               754

                                  /* Sort Priv heap high water mark           */
#define SQLM_ELM_SORT_HEAP_TOP                                               755
                                  /* Sort SHARE heap currently alloc          */
#define SQLM_ELM_SORT_SHRHEAP_ALLOCATED                                      756
                                  /* Sort SHARE heap high water mark          */
#define SQLM_ELM_SORT_SHRHEAP_TOP                                            757


/******************************************************************************/
/* APM Interaction                                                            */
/******************************************************************************/

                                  /* s wrkspc high watermrk                   */
#define SQLM_ELM_SHR_WORKSPACE_SIZE_TOP                                      758
                                  /* s wrkspc # overflows                     */
#define SQLM_ELM_SHR_WORKSPACE_NUM_OVERFLOWS                                 759
                                  /* s wrkspc sec. lookups                    */
#define SQLM_ELM_SHR_WORKSPACE_SECTION_LOOKUPS                               760
                                  /* s wrkspc sec. inserts                    */
#define SQLM_ELM_SHR_WORKSPACE_SECTION_INSERTS                               761
                                  /* p wrkspc high watermrk                   */
#define SQLM_ELM_PRIV_WORKSPACE_SIZE_TOP                                     762
                                  /* p wrkspc # overflows                     */
#define SQLM_ELM_PRIV_WORKSPACE_NUM_OVERFLOWS                                763
                                  /* p wrkspc sec. lookups                    */
#define SQLM_ELM_PRIV_WORKSPACE_SECTION_LOOKUPS                              764
                                  /* p wrkspc sec. inserts                    */
#define SQLM_ELM_PRIV_WORKSPACE_SECTION_INSERTS                              765

/******************************************************************************/
/* Catalog Cache                                                              */
/******************************************************************************/
                                  /* Cat cache sz high water mark             */
#define SQLM_ELM_CAT_CACHE_SIZE_TOP                                          766

/******************************************************************************/
/* Partition Number for EEE WTT evmon                                         */
/******************************************************************************/
                                  /* Partition Number for EEE WTT             */
#define SQLM_ELM_PARTITION_NUMBER                                            767
                                  /* Number of Transmissions group            */
#define SQLM_ELM_NUM_TRANSMISSIONS_GROUP                                     768
                                  /* Number of indoubt transactions           */
#define SQLM_ELM_NUM_INDOUBT_TRANS                                           769

/******************************************************************************/
/* Information for active utilities                                           */
/******************************************************************************/
                                  /* Utility's database                       */
#define SQLM_ELM_UTILITY_DBNAME                                              770
                                  /* Utility ID                               */
#define SQLM_ELM_UTILITY_ID                                                  771
                                  /* Type of utility                          */
#define SQLM_ELM_UTILITY_TYPE                                                772
                                  /* Utility priority                         */
#define SQLM_ELM_UTILITY_PRIORITY                                            773
                                  /* Start time of utility                    */
#define SQLM_ELM_UTILITY_START_TIME                                          774
                                  /* Utility description                      */
#define SQLM_ELM_UTILITY_DESCRIPTION                                         775

                                  /* # async index read requests              */
#define SQLM_ELM_POOL_ASYNC_INDEX_READ_REQS                                  776
                                  /* Authorization Id                         */
#define SQLM_ELM_SESSION_AUTH_ID                                             777

                                  /* number of SQL stmt chains sent           */
#define SQLM_ELM_SQL_CHAINS                                                  778

                                  /* pool temp data logical reads             */
#define SQLM_ELM_POOL_TEMP_DATA_L_READS                                      779
                                  /* pool temp data physical reads            */
#define SQLM_ELM_POOL_TEMP_DATA_P_READS                                      780
                                  /* pool temp index logical reads            */
#define SQLM_ELM_POOL_TEMP_INDEX_L_READS                                     781
                                  /* pool temp index physical reads           */
#define SQLM_ELM_POOL_TEMP_INDEX_P_READS                                     782

                                  /* Cnt:network time <= 1 millisec.          */
#define SQLM_ELM_MAX_TIME_1_MS                                               783
                                  /* Cnt:network time <= 100 millisec.        */
#define SQLM_ELM_MAX_TIME_100_MS                                             784
                                  /* Cnt:network time <= 500 millisec.        */
#define SQLM_ELM_MAX_TIME_500_MS                                             785
                                  /* Cnt:network time > 500 millisec.         */
#define SQLM_ELM_MAX_TIME_GT500_MS                                           786

                                  /* bytes of log that need to be redone      */
                                  /* during recovery                          */
#define SQLM_ELM_LOG_TO_REDO_FOR_RECOVERY                                    787
                                  /* number of times no victim buffer         */
                                  /* available from hate list                 */
#define SQLM_ELM_POOL_NO_VICTIM_BUFFER                                       788
                                  /* bytes of log that are held up by minbuf  */
#define SQLM_ELM_LOG_HELD_BY_DIRTY_PAGES                                     789

/******************************************************************************/
/*   Information for the progress of utilities                                */
/******************************************************************************/
                                  /* job progress description                 */
#define SQLM_ELM_PROGRESS_DESCRIPTION                                        790
                                  /* job progress start time                  */
#define SQLM_ELM_PROGRESS_START_TIME                                         791
                                  /* job progress work metric                 */
#define SQLM_ELM_PROGRESS_WORK_METRIC                                        792
                                  /* job progress total units                 */
#define SQLM_ELM_PROGRESS_TOTAL_UNITS                                        793
                                  /* job progress completed units             */
#define SQLM_ELM_PROGRESS_COMPLETED_UNITS                                    794
                                  /* job progress id                          */
#define SQLM_ELM_PROGRESS_SEQ_NUM                                            795
                                  /* current job of progress list             */
#define SQLM_ELM_PROGRESS_LIST_CUR_SEQ_NUM                                   796

/******************************************************************************/
/* Information for HADR                                                       */
/******************************************************************************/
                                  /* HADR Role                                */
#define SQLM_ELM_HADR_ROLE                                                   797
                                  /* HADR State                               */
#define SQLM_ELM_HADR_STATE                                                  798
                                  /* HADR Synchronization mode                */
#define SQLM_ELM_HADR_SYNCMODE                                               799
                                  /* HADR Connection                          */
#define SQLM_ELM_HADR_CONNECT_STATUS                                         800
                                  /* HADR Timestamp for connection status     */
#define SQLM_ELM_HADR_CONNECT_TIME                                           801
                                  /* HADR Heartbeat                           */
#define SQLM_ELM_HADR_HEARTBEAT                                              802
                                  /* HADR Local host                          */
#define SQLM_ELM_HADR_LOCAL_HOST                                             803
                                  /* HADR Local service                       */
#define SQLM_ELM_HADR_LOCAL_SERVICE                                          804
                                  /* HADR Remote host                         */
#define SQLM_ELM_HADR_REMOTE_HOST                                            805
                                  /* HADR Remote service                      */
#define SQLM_ELM_HADR_REMOTE_SERVICE                                         806
                                  /* HADR timeout                             */
#define SQLM_ELM_HADR_TIMEOUT                                                807
                                  /* HADR Primary log file name               */
#define SQLM_ELM_HADR_PRIMARY_LOG_FILE                                       808
                                  /* HADR Primary log page number             */
#define SQLM_ELM_HADR_PRIMARY_LOG_PAGE                                       809
                                  /* HADR Primary log position                */
#define SQLM_ELM_HADR_PRIMARY_LOG_LSN                                        810
                                  /* HADR Secondary log file name             */
#define SQLM_ELM_HADR_STANDBY_LOG_FILE                                       811
                                  /* HADR Secondary log page number           */
#define SQLM_ELM_HADR_STANDBY_LOG_PAGE                                       812
                                  /* HADR Secondary log position              */
#define SQLM_ELM_HADR_STANDBY_LOG_LSN                                        813
                                  /* HADR Log gap running average             */
#define SQLM_ELM_HADR_LOG_GAP                                                814
                                  /* HADR Remote instance name                */
#define SQLM_ELM_HADR_REMOTE_INSTANCE                                        815
/******************************************************************************/
/* Additional elements added in 8.2                                           */
/******************************************************************************/
                                  /* number of pages for table base data      */
#define SQLM_ELM_DATA_OBJECT_PAGES                                           816
                                  /* number of pages for index base data      */
#define SQLM_ELM_INDEX_OBJECT_PAGES                                          817
                                  /* number of pages for LOB data             */
#define SQLM_ELM_LOB_OBJECT_PAGES                                            818
                                  /* number of pages for long data            */
#define SQLM_ELM_LONG_OBJECT_PAGES                                           819

                                  /* Appl lock timeout value                  */
#define SQLM_ELM_LOCK_TIMEOUT_VAL                                            820

/******************************************************************************/
/*  Log elements v8.2                                                         */
/******************************************************************************/
#define SQLM_ELM_LOG_WRITE_TIME                                              821
#define SQLM_ELM_LOG_READ_TIME                                               822
#define SQLM_ELM_NUM_LOG_WRITE_IO                                            823
#define SQLM_ELM_NUM_LOG_READ_IO                                             824
#define SQLM_ELM_NUM_LOG_PART_PAGE_IO                                        825
#define SQLM_ELM_NUM_LOG_BUFF_FULL                                           826
#define SQLM_ELM_NUM_LOG_DATA_IN_BUFF                                        827
#define SQLM_ELM_LOG_FILE_NUM_FIRST                                          828
#define SQLM_ELM_LOG_FILE_NUM_LAST                                           829
#define SQLM_ELM_LOG_FILE_NUM_CURR                                           830
#define SQLM_ELM_LOG_FILE_ARCHIVE                                            831


#define SQLM_ELM_NANOSEC                                                     832

/******************************************************************************/
/*  New elements for enhanced deadlock event monitor with statement history   */
/******************************************************************************/
                                  /* statement history id                     */
#define SQLM_ELM_STMT_HISTORY_ID                                             833
                                  /* lock timeout reg var of stmt             */
#define SQLM_ELM_STMT_LOCK_TIMEOUT                                           834
                                  /* cursor isolation level                   */
#define SQLM_ELM_STMT_ISOLATION                                              835
                                  /* descriptor blob of compilation           */
                                  /* environment                              */
#define SQLM_ELM_COMP_ENV_DESC                                               836
                                  /* data value type                          */
#define SQLM_ELM_STMT_VALUE_TYPE                                             837
                                  /* value set by reopt?                      */
#define SQLM_ELM_STMT_VALUE_ISREOPT                                          838
                                  /* data has null values                     */
#define SQLM_ELM_STMT_VALUE_ISNULL                                           839
                                  /* variable data                            */
#define SQLM_ELM_STMT_VALUE_DATA                                             840
                                  /* position of value in stmt                */
#define SQLM_ELM_STMT_VALUE_INDEX                                            841
                                  /* time of stmt first use                   */
#define SQLM_ELM_STMT_FIRST_USE_TIME                                         842
                                  /* time stmt last use                       */
#define SQLM_ELM_STMT_LAST_USE_TIME                                          843
                                  /* nesting level of statement               */
#define SQLM_ELM_STMT_NEST_LEVEL                                             844
                                  /* invocation id of statement               */
#define SQLM_ELM_STMT_INVOCATION_ID                                          845
                                  /* query id of statement                    */
#define SQLM_ELM_STMT_QUERY_ID                                               846
                                  /* source id of statement                   */
#define SQLM_ELM_STMT_SOURCE_ID                                              847
                                  /* unique package cache id                  */
#define SQLM_ELM_STMT_PKGCACHE_ID                                            848
                                  /* size of stmts history list               */
#define SQLM_ELM_INACT_STMTHIST_SZ                                           849

/******************************************************************************/
/* New elements for Single point of storage management                        */
/******************************************************************************/
                                  /* num automatic storage paths              */
#define SQLM_ELM_NUM_DB_STORAGE_PATHS                                        850
                                  /* automatic storage path                   */
#define SQLM_ELM_DB_STORAGE_PATH                                             851
                                  /* initial size of tbsp                     */
#define SQLM_ELM_TABLESPACE_INITIAL_SIZE                                     852
                                  /* current tablespace size                  */
#define SQLM_ELM_TABLESPACE_CURRENT_SIZE                                     853
                                  /* maximum tablespace size                  */
#define SQLM_ELM_TABLESPACE_MAX_SIZE                                         854
                                  /* growth size by percent                   */
#define SQLM_ELM_TABLESPACE_INCREASE_SIZE_PERCENT                            855
                                  /* growth size in bytes                     */
#define SQLM_ELM_TABLESPACE_INCREASE_SIZE                                    856
                                  /* last growth time                         */
#define SQLM_ELM_TABLESPACE_LAST_RESIZE_TIME                                 857
                                  /* using automatic storage                  */
#define SQLM_ELM_TABLESPACE_USING_AUTO_STORAGE                               858
                                  /* auto resize enabled                      */
#define SQLM_ELM_TABLESPACE_AUTO_RESIZE_ENABLED                              859
                                  /* last resize failed                       */
#define SQLM_ELM_TABLESPACE_LAST_RESIZE_FAILED                               860

                                  /* Bufferpool identifier                    */
#define SQLM_ELM_BP_ID                                                       861

/*  New elements for v9.1                                                     */
                                  /* Tablespace ID in Reorg                   */
#define SQLM_ELM_REORG_LONG_TBSPC_ID                                         862

                                  /* Partition id of Table                    */
#define SQLM_ELM_DATA_PARTITION_ID                                           863
                                  /* Progress list attributes                 */
#define SQLM_ELM_PROGRESS_LIST_ATTR                                          864


/******************************************************************************/
/* New REORG monitoring elements for v9 (Row Compression)                     */
/******************************************************************************/
#define SQLM_ELM_REORG_ROWSCOMPRESSED                                        865
#define SQLM_ELM_REORG_ROWSREJECTED                                          866

/******************************************************************************/
/* FCM monitoring element additions for v9                                    */
/******************************************************************************/
                                  /* # of FCM channel blocks free             */
#define SQLM_ELM_CH_FREE                                                     867
                                  /* low water mark of free channels          */
#define SQLM_ELM_CH_FREE_BOTTOM                                              868
/******************************************************************************/
/* Utility monitoring element additions for v9                                */
/******************************************************************************/
                                  /* Utility state                            */
#define SQLM_ELM_UTILITY_STATE                                               869
                                  /* Invoker type                             */
#define SQLM_ELM_UTILITY_INVOKER_TYPE                                        870
/******************************************************************************/
/* New sort monitor elements                                                  */
/******************************************************************************/

                                  /* Sorts that started passed the throttling */
                                  /* threshold for shared memory              */
#define SQLM_ELM_POST_SHRTHRESHOLD_SORTS                                     871
                                  /* Hash Joins that started passed the       */
                                  /* throttling threshold for shared memory   */
#define SQLM_ELM_POST_SHRTHRESHOLD_HASH_JOINS                                872
                                  /* hash joins currently active              */
#define SQLM_ELM_ACTIVE_HASH_JOINS                                           873

                                  /* Pool secondary identifier                */
#define SQLM_ELM_POOL_SECONDARY_ID                                           874

                                  /* File system ID number for a stg path     */
#define SQLM_ELM_FS_ID                                                       875
                                  /* Total size of a stg path                 */
#define SQLM_ELM_FS_TOTAL_SZ                                                 876
                                  /* Space currently used on a stg path       */
#define SQLM_ELM_FS_USED_SZ                                                  877
                                  /* Free space available on a stg path       */
#define SQLM_ELM_STO_PATH_FREE_SZ                                            878

                                  /* BP XDA logical reads                     */
#define SQLM_ELM_POOL_XDA_L_READS                                            879
                                  /* BP XDA physical reads                    */
#define SQLM_ELM_POOL_XDA_P_READS                                            880
                                  /* BP XDA page writes                       */
#define SQLM_ELM_POOL_XDA_WRITES                                             881
                                  /* logical reads of temp XDA pgs            */
#define SQLM_ELM_POOL_TEMP_XDA_L_READS                                       882
                                  /* physical reads of temp XDA pgs           */
#define SQLM_ELM_POOL_TEMP_XDA_P_READS                                       883
                                  /* Prefetcher XDA reads                     */
#define SQLM_ELM_POOL_ASYNC_XDA_READS                                        884
                                  /* Prefetcher XDA writes                    */
#define SQLM_ELM_POOL_ASYNC_XDA_WRITES                                       885
                                  /* Num prefetcher XDA read reqs             */
#define SQLM_ELM_POOL_ASYNC_XDA_READ_REQS                                    886
                                  /* number of pages for XDA data             */
#define SQLM_ELM_XDA_OBJECT_PAGES                                            887
                                  /* # of XQUERY stmts                        */
#define SQLM_ELM_XQUERY_STMTS                                                888

/******************************************************************************/
/* New Trusted Context monitor element for v9                                 */
/******************************************************************************/
                                  /* Trusted Authorization ID                 */
#define SQLM_ELM_TRUSTED_AUTH_ID                                             889

/*****************************************************************************/
/* HADR Peer Window elements                                                 */
/*****************************************************************************/
                                  /* HADR Peer window end                     */
#define SQLM_ELM_HADR_PEER_WINDOW_END                                        890
                                  /* HADR Peer window                         */
#define SQLM_ELM_HADR_PEER_WINDOW                                            891

/******************************************************************************/
/* New elements added for v9.5                                                */
/******************************************************************************/

#define SQLM_ELM_BLOCKS_PENDING_CLEANUP                                      892
#define SQLM_ELM_AUTHORITY_BITMAP                                            893

                                  /* # OLAP functions executed                */
#define SQLM_ELM_TOTAL_OLAP_FUNCS                                            894
                                  /* # OLAP functions started after sortheap  */
                                  /* threshold exceeded                       */
#define SQLM_ELM_POST_THRESHOLD_OLAP_FUNCS                                   895
                                  /* # OLAP functions currently running       */
#define SQLM_ELM_ACTIVE_OLAP_FUNCS                                           896
                                  /* # OLAP functions which have overflowed   */
                                  /* to temp tables                           */
#define SQLM_ELM_OLAP_FUNC_OVERFLOWS                                         897

/******************************************************************************/
/* Work Load Management elements for new event monitors                       */
/******************************************************************************/

                                  /* Service class identifier                 */
#define SQLM_ELM_SERVICE_CLASS_ID                                            898
                                  /* Service superclass name                  */
#define SQLM_ELM_SERVICE_SUPERCLASS_NAME                                     899
                                  /* Service subclass name                    */
#define SQLM_ELM_SERVICE_SUBCLASS_NAME                                       900
                                  /* Work action set identifier               */
#define SQLM_ELM_WORK_ACTION_SET_ID                                          901
                                  /* Work action set name                     */
#define SQLM_ELM_WORK_ACTION_SET_NAME                                        902
                                  /* Database Work action set ID              */
#define SQLM_ELM_DB_WORK_ACTION_SET_ID                                       903
                                  /* Service_class Work act set ID            */
#define SQLM_ELM_SC_WORK_ACTION_SET_ID                                       904
                                  /* Work class identifier                    */
#define SQLM_ELM_WORK_CLASS_ID                                               905
                                  /* Work class name                          */
#define SQLM_ELM_WORK_CLASS_NAME                                             906
                                  /* Database Work class ID                   */
#define SQLM_ELM_DB_WORK_CLASS_ID                                            907
                                  /* Service_class Work class ID              */
#define SQLM_ELM_SC_WORK_CLASS_ID                                            908
                                  /* Workload identifier                      */
#define SQLM_ELM_WORKLOAD_ID                                                 909
                                  /* Workload occurrance Id                   */
#define SQLM_ELM_WORKLOAD_OCCURRENCE_ID                                      910
                                  /* Workload name                            */
#define SQLM_ELM_WORKLOAD_NAME                                               911
                                  /* Temp tablespace usage HWM                */
#define SQLM_ELM_TEMP_TABLESPACE_TOP                                         912
                                  /* Actual rows returned HWM                 */
#define SQLM_ELM_ROWS_RETURNED_TOP                                           913
                                  /* HWM for # conc. activities               */
#define SQLM_ELM_CONCURRENT_ACT_TOP                                          914
                                  /* HWM for # conc. connections              */
#define SQLM_ELM_CONCURRENT_CONNECTION_TOP                                   915
                                  /* HWM for cost estimate                    */
#define SQLM_ELM_COST_ESTIMATE_TOP                                           916
                                  /* Statistics timestamp                     */
#define SQLM_ELM_STATISTICS_TIMESTAMP                                        917
                                  /* Total number of activities               */
#define SQLM_ELM_ACT_TOTAL                                                   918
                                  /* No. completed activities                 */
#define SQLM_ELM_WLO_COMPLETED_TOTAL                                         919
                                  /* HWM for concurrent occurrences of a      */
                                  /* workload                                 */
#define SQLM_ELM_CONCURRENT_WLO_TOP                                          920
                                  /* HWM for concurrent activities of any     */
                                  /* occurrance of this workload              */
#define SQLM_ELM_CONCURRENT_WLO_ACT_TOP                                      921
                                  /* Top end of histogram range               */
#define SQLM_ELM_TOP                                                         922
                                  /* Bottom end of histog. range              */
#define SQLM_ELM_BOTTOM                                                      923
                                  /* Type of histogram                        */
#define SQLM_ELM_HISTOGRAM_TYPE                                              924
                                  /* Histogram bin identifier                 */
#define SQLM_ELM_BIN_ID                                                      925

                                  /* Activity Identifier                      */
#define SQLM_ELM_ACTIVITY_ID                                                 926
                                  /* Activity Secondary ID                    */
#define SQLM_ELM_ACTIVITY_SECONDARY_ID                                       927
                                  /* Unit of Work identifier                  */
#define SQLM_ELM_UOW_ID                                                      928
                                  /* Parent's Activity Id                     */
#define SQLM_ELM_PARENT_ACTIVITY_ID                                          929
                                  /* Parent's Unit of Work Id                 */
#define SQLM_ELM_PARENT_UOW_ID                                               930
                                  /* Time the violation occurred              */
#define SQLM_ELM_TIME_OF_VIOLATION                                           931
                                  /* Was the activity collected?              */
#define SQLM_ELM_ACTIVITY_COLLECTED                                          932
                                  /* Type of activity                         */
#define SQLM_ELM_ACTIVITY_TYPE                                               933
                                  /* Type of threshold violated               */
#define SQLM_ELM_THRESHOLD_PREDICATE                                         934
                                  /* Action performed on appl                 */
#define SQLM_ELM_THRESHOLD_ACTION                                            935
                                  /* Value that was exceeded                  */
#define SQLM_ELM_THRESHOLD_MAXVALUE                                          936
                                  /* Size of the queue exceeded               */
#define SQLM_ELM_THRESHOLD_QUEUESIZE                                         937
                                  /* No. completed activities                 */
#define SQLM_ELM_COORD_ACT_COMPLETED_TOTAL                                   938
                                  /* No. aborted activities                   */
#define SQLM_ELM_COORD_ACT_ABORTED_TOTAL                                     939
                                  /* No. rejected activities                  */
#define SQLM_ELM_COORD_ACT_REJECTED_TOTAL                                    940
                                  /* HWM Coord activity lifetime              */
#define SQLM_ELM_COORD_ACT_LIFETIME_TOP                                      941
                                  /* Activity execution time                  */
#define SQLM_ELM_ACT_EXEC_TIME                                               942
                                  /* Time activity was created                */
#define SQLM_ELM_TIME_CREATED                                                943
                                  /* Time activity started                    */
#define SQLM_ELM_TIME_STARTED                                                944
                                  /* Time activity completed                  */
#define SQLM_ELM_TIME_COMPLETED                                              945
                                  /* Time activity completed                  */
#define SQLM_ELM_SECTION_ENV                                                 946
                                  /* Time when evmon activated                */
#define SQLM_ELM_ACTIVATE_TIMESTAMP                                          947
                                  /* # of Threshold Violations                */
#define SQLM_ELM_NUM_THRESHOLD_VIOLATIONS                                    948
                                  /* WLM ARM Correlator                       */
#define SQLM_ELM_ARM_CORRELATOR                                              949
                                  /* Prep time for activity                   */
#define SQLM_ELM_PREP_TIME                                                   950
                                  /* HWM Queue size                           */
#define SQLM_ELM_QUEUE_SIZE_TOP                                              951
                                  /* No. conn/activ assigned to Q             */
#define SQLM_ELM_QUEUE_ASSIGNMENTS_TOTAL                                     953
                                  /* Total time spent in queue                */
#define SQLM_ELM_QUEUE_TIME_TOTAL                                            954
                                  /* Time stats were last reset               */
#define SQLM_ELM_LAST_WLM_RESET                                              955
                                  /* Threshold Domain                         */
#define SQLM_ELM_THRESHOLD_DOMAIN                                            956
                                  /* Name of threshold resp for Q             */
#define SQLM_ELM_THRESHOLD_NAME                                              957
                                  /* ID of threshold violated                 */
#define SQLM_ELM_THRESHOLDID                                                 958
                                  /* # items in Histogram Bin                 */
#define SQLM_ELM_NUMBER_IN_BIN                                               959
#define SQLM_ELM_COORD_ACT_LIFETIME_AVG                                      960
#define SQLM_ELM_COORD_ACT_QUEUE_TIME_AVG                                    961
#define SQLM_ELM_COORD_ACT_EXEC_TIME_AVG                                     962
#define SQLM_ELM_COORD_ACT_EST_COST_AVG                                      963
#define SQLM_ELM_COORD_ACT_INTERARRIVAL_TIME_AVG                             964
#define SQLM_ELM_REQUEST_EXEC_TIME_AVG                                       965
/******************************************************************************/
/* New elements for JITS                                                      */
/******************************************************************************/
                                  /* Statistic cache size                     */
#define SQLM_ELM_STATS_CACHE_SIZE                                            966
                                  /* number of stats fabrication              */
#define SQLM_ELM_STATS_FABRICATIONS                                          967
                                  /* time for stats fabrication               */
#define SQLM_ELM_STATS_FABRICATE_TIME                                        968
                                  /* number of synchronous runstats           */
#define SQLM_ELM_SYNC_RUNSTATS                                               969
                                  /* time for synchronous runstats            */
#define SQLM_ELM_SYNC_RUNSTATS_TIME                                          970
                                  /* number of asynchronous runstats          */
#define SQLM_ELM_ASYNC_RUNSTATS                                              971


/* Memory Pool List element                                                   */
                                  /* Pool List identifier                     */
#define SQLM_ELM_POOL_LIST_ID                                                972

                                  /* Is app a system application?             */
#define SQLM_ELM_IS_SYSTEM_APPL                                              973
                                  /* Time to insert(from all apps)            */
#define SQLM_ELM_INSERT_TIMESTAMP                                            974
                                  /* Maximum value of high water mark         */
#define SQLM_ELM_TABLESPACE_MAX_PAGE_TOP                                     975
                                  /* path with db partition expression        */
#define SQLM_ELM_DB_STORAGE_PATH_WITH_DPE                                    976
                                  /* state of storage path                    */
#define SQLM_ELM_DB_STORAGE_PATH_STATE                                       977
                                  /* underlying storage paths dropped         */
#define SQLM_ELM_TABLESPACE_PATHS_DROPPED                                    978
#define SQLM_ELM_DESTINATION_SERVICE_CLASS_ID                                979
#define SQLM_ELM_SOURCE_SERVICE_CLASS_ID                                     980
#define SQLM_ELM_ACT_REMAPPED_IN                                             981
#define SQLM_ELM_ACT_REMAPPED_OUT                                            982
#define SQLM_ELM_AGG_TEMP_TABLESPACE_TOP                                     983
#define SQLM_ELM_NUM_REMAPS                                                  984
                                  /* Unit of work total time high watermark   */
#define SQLM_ELM_UOW_TOTAL_TIME_TOP                                          985
                                  /* IP address of the host returning this    */
                                  /* information                              */
#define SQLM_ELM_ADDRESS                                                   45001
#define SQLM_ELM_ACT_CPU_TIME_TOP                                            986
#define SQLM_ELM_ACT_ROWS_READ_TOP                                           987
#define SQLM_ELM_LOCK_WAIT_TIME_TOP                                          988
                                  /*  Metrics exposed as an XML document. For */
                                  /* details please see the XML Schema in     */
                                  /* sqllib/misc/DB2MonMetrics.xsd            */
#define SQLM_ELM_DETAILS_XML                                                 989
                                  /* Opaque token that uniquely identifies a  */
                                  /* section that has been executed.          */
#define SQLM_ELM_EXECUTABLE_ID                                               990
                                  /* Effective statement text after any       */
                                  /* literal replacement by statement         */
                                  /* concentrator.                            */
#define SQLM_ELM_EFF_STMT_TEXT                                               991
                                  /* Unique routine identifier.               */
#define SQLM_ELM_ROUTINE_ID                                                  992
                                  /* Internal binary string containing        */
                                  /* runtime section statistics.              */
#define SQLM_ELM_SECTION_ACTUALS                                             993
                                  /* Unit of work event monitor record        */
#define SQLM_ELM_UOW_EVENT                                                   994
                                  /* Unit of work completion status           */
#define SQLM_ELM_CMPSTATUS                                                   995
                                  /* Application connect time                 */
#define SQLM_ELM_CONNTIME                                                    996
                                  /* Application handle                       */
#define SQLM_ELM_APP_HANDLE                                                  997
                                  /* The coordinating member for this         */
                                  /* application                              */
#define SQLM_ELM_COORD_MEMBER                                                998
                                  /* The activation time of this member       */
#define SQLM_ELM_MEMBER_ACT_TIME                                             999
                                  /* The system authorization id              */
#define SQLM_ELM_SYSTEM_AUTH_ID                                            45952
                                  /* The local transaction id                 */
#define SQLM_ELM_LOCAL_TID                                                  1000
                                  /* The global transaction id                */
#define SQLM_ELM_GXID                                                       1001
                                  /* System metrics data                      */
#define SQLM_ELM_SYSTEM_METRICS                                             1002
                                  /* XML document event id attribute          */
#define SQLM_ELM_ATTR_EVENT_ID                                              1003
                                  /* XML document type attribute              */
#define SQLM_ELM_ATTR_TYPE                                                  1004
                                  /* XML document timestamp attribute         */
#define SQLM_ELM_ATTR_TIMESTAMP                                             1005
                                  /* XML document member attribute            */
#define SQLM_ELM_ATTR_MEMBER                                                1006
                                  /* XML document release attribute           */
#define SQLM_ELM_ATTR_RELEASE                                               1007
                                  /* Host name of the client application      */
#define SQLM_ELM_CLIENT_HOSTNAME                                            1008
                                  /* Port number of the client application    */
#define SQLM_ELM_CLIENT_PORT                                                1009
                                  /* Package list for this unit of work       */
#define SQLM_ELM_PKGLIST                                                    1010
                                  /* Package list size for this unit of work  */
#define SQLM_ELM_PKGLIST_SIZE                                               1011
                                  /* Package list entries for this unit of    */
                                  /* work                                     */
#define SQLM_ELM_PKGLIST_ENTRIES                                            1012
                                  /* Single package list entry for this unit  */
                                  /* of work                                  */
#define SQLM_ELM_PKGLIST_ENTRY                                              1013
                                  /* Package list size was exceeded within    */
                                  /* the unit of work                         */
#define SQLM_ELM_PKGLIST_EXCEEDED                                           1014
                                  /* Workload Work act set ID                 */
#define SQLM_ELM_WL_WORK_ACTION_SET_ID                                      1015
                                  /* Workload Work class ID                   */
#define SQLM_ELM_WL_WORK_CLASS_ID                                           1016
/* Total elapsed delta time taken between two snapshots                       */
#define SQLM_ELM_TOTAL_SYS_CPU_DELTA_TIME       1017 /* System CPU delta time */
#define SQLM_ELM_TOTAL_USR_CPU_DELTA_TIME       1018 /*   User CPU delta time */
#define SQLM_ELM_BUFF_MAX                     1019 /*    max # of FCM buffers */
#define SQLM_ELM_CH_TOTAL                    45634 /* total # of FCM channels */
#define SQLM_ELM_CH_MAX                       1020 /*   max # of FCM channels */
#define SQLM_ELM_LOCK_WAIT_TIME_GLOBAL_TOP                                  1021
                                              /* Trackmod state of tablespace */
#define SQLM_ELM_TABLESPACE_TRACKMOD_STATE                                  1022
                                  /* DB member                                */
#define SQLM_ELM_DBPARTITIONNUM                                             1023
                                  /* Coordinating DB Partition number         */
#define SQLM_ELM_COORD_DBPARTITIONNUM                                       1024
                                  /* Unit of work throughout                  */
#define SQLM_ELM_UOW_THROUGHPUT                                             1025
                                  /* Unit of Work Lifetime Average            */
#define SQLM_ELM_UOW_LIFETIME_AVG                                           1026
                                  /* Unit of Work Completed Total             */
#define SQLM_ELM_UOW_COMPLETED_TOTAL                                        1027
                                  /* Total CPU Time                           */
#define SQLM_ELM_TOTAL_CPU_TIME                                             1028
                                  /* Total Dispacther Run Queue Time          */
#define SQLM_ELM_TOTAL_DISP_RUN_QUEUE_TIME                                  1029
                                  /* Activities Throuhput                     */
#define SQLM_ELM_ACT_THROUGHPUT                                             1030
                                  /* CPU Utilization                          */
#define SQLM_ELM_CPU_UTILIZATION                                            1031
                                  /* List of data tags of data table spaces   */
                                  /* accessed by statement.                   */
#define SQLM_ELM_QUERY_DATA_TAG_LIST                                        1032
                                  /* Query's actual degree of parallelism     */
#define SQLM_ELM_QUERY_ACTUAL_DEGREE                                        1033
                                  /* total # of FCM buffers                   */
#define SQLM_ELM_BUFF_TOTAL                                                45633

                                  /* Executable list for this unit of work    */
#define SQLM_ELM_EXECLIST                                                   1034
                                  /* Executable list size for this unit of    */
                                  /* work                                     */
#define SQLM_ELM_EXECLIST_SIZE                                              1035
                                  /* Executable list was truncated within the */
                                  /* unit of work                             */
#define SQLM_ELM_EXECLIST_TRUNCATED                                         1036
                                  /* Executable list entries for this unit of */
                                  /* work                                     */
#define SQLM_ELM_EXECLIST_ENTRIES                                           1037
                                  /* Single executable list entry for this    */
                                  /* unit of work                             */
#define SQLM_ELM_EXECLIST_ENTRY                                             1038
                                  /* Total stats fabrication time             */
#define SQLM_ELM_TOTAL_STATS_FABRICATION_TIME                               1039
                                  /* Total stats fabrications                 */
#define SQLM_ELM_TOTAL_STATS_FABRICATIONS                                   1040
                                  /* Total synchronous runstats time          */
#define SQLM_ELM_TOTAL_SYNC_RUNSTATS_TIME                                   1041
                                  /* Total synchronous runstats               */
#define SQLM_ELM_TOTAL_SYNC_RUNSTATS                                        1042
                                  /* Total connect request time               */
#define SQLM_ELM_TOTAL_CONNECT_REQUEST_TIME                                 1043
                                  /* Total connect requests                   */
#define SQLM_ELM_TOTAL_CONNECT_REQUESTS                                     1044
                                  /* Total connect authentication time        */
#define SQLM_ELM_TOTAL_CONNECT_AUTHENTICATION_TIME                          1045
                                  /* Total connect authentications            */
#define SQLM_ELM_TOTAL_CONNECT_AUTHENTICATIONS                              1046

/* new to Galileo */

                                  /* Monitoring interval ID                   */
#define SQLM_ELM_MON_INTERVAL_ID                                            1047
                                  /* total # of non-nested coordinator        */
                                  /* completed activities                     */
#define SQLM_ELM_COORD_APP_ACT_COMPLETED_TOTAL                              1048
                                  /* total # of non-nested coordinator        */
                                  /* aborted activities                       */
#define SQLM_ELM_COORD_APP_ACT_ABORTED_TOTAL                                1049
                                  /* total # of non-nested coordinator        */
                                  /* rejected activities                      */
#define SQLM_ELM_COORD_APP_ACT_REJECTED_TOTAL                               1050
                                  /*  Delta metrics exposed as an XML         */
                                  /* document. For details please see the XML */
                                  /* Schema in sqllib/misc/DB2MonMetrics.xsd  */
#define SQLM_ELM_METRICS                                                    1051
/* client port number*/
                                  /* client port number                       */
#define SQLM_ELM_CLIENT_PORT_NUMBER                                         1052
/* connection start time */
                                  /* connection start time                    */
#define SQLM_ELM_CONNECTION_START_TIME                                      1053
                                  /* statement number for static statements   */
#define SQLM_ELM_STMTNO                                                     1054
                                  /* number of routines that may be invoked   */
                                  /* by statement                             */
#define SQLM_ELM_NUM_ROUTINES                                               1055
/* New to Kepler - Part of os_metrics logical group */
                                       /* CPU total                           */
#define SQLM_ELM_CPU_TOTAL                                                  1056
                                       /* CPU online                          */
#define SQLM_ELM_CPU_ONLINE                                                 1057
                                       /* CPU configured                      */
#define SQLM_ELM_CPU_CONFIGURED                                             1058
                                       /* CPU speed                           */
#define SQLM_ELM_CPU_SPEED                                                  1059
                                       /* CPU timebase                        */
#define SQLM_ELM_CPU_TIMEBASE                                               1060
                                       /* CPU hmt degree                      */
#define SQLM_ELM_CPU_HMT_DEGREE                                             1061
                                       /* Number of CPU cores for each socket */
#define SQLM_ELM_CPU_CORES_PER_SOCKET                                       1062
                                       /* Memory total                        */
#define SQLM_ELM_MEMORY_TOTAL                                               1063
                                       /* Memory free                         */
#define SQLM_ELM_MEMORY_FREE                                                1064
                                       /* Memory swap total                   */
#define SQLM_ELM_MEMORY_SWAP_TOTAL                                          1065
                                       /* Memory swap free                    */
#define SQLM_ELM_MEMORY_SWAP_FREE                                           1066
                                       /* Virtual memory total                */
#define SQLM_ELM_VIRTUAL_MEM_TOTAL                                          1067
                                       /* Virtual memory reserved             */
#define SQLM_ELM_VIRTUAL_MEM_RESERVED                                       1068
                                       /* Virtual memory free                 */
#define SQLM_ELM_VIRTUAL_MEM_FREE                                           1069
                                       /* CPU load short                      */
#define SQLM_ELM_CPU_LOAD_SHORT                                             1070
                                       /* CPU load medium                     */
#define SQLM_ELM_CPU_LOAD_MEDIUM                                            1071
                                       /* CPU load long                       */
#define SQLM_ELM_CPU_LOAD_LONG                                              1072
                                       /* CPU usage total                     */
#define SQLM_ELM_CPU_USAGE_TOTAL                                            1073
                                       /* CPU user                            */
#define SQLM_ELM_CPU_USER                                                   1074
                                       /* CPU idle                            */
#define SQLM_ELM_CPU_IDLE                                                   1075
                                       /* CPU IO wait time                    */
#define SQLM_ELM_CPU_IOWAIT                                                 1076
                                       /* CPU system                          */
#define SQLM_ELM_CPU_SYSTEM                                                 1077
                                       /* Swap page size                      */
#define SQLM_ELM_SWAP_PAGE_SIZE                                             1078
                                       /* Swap page in                        */
#define SQLM_ELM_SWAP_PAGES_IN                                              1079
                                       /* Swap page out                       */
#define SQLM_ELM_SWAP_PAGES_OUT                                             1080
                                      /*  Intra Parallel state                */
#define SQLM_ELM_INTRA_PARALLEL_STATE                                       1081
                                      /* Unique identifier of a member subset */
#define SQLM_ELM_MEMBER_SUBSET_ID                                          47045
                                            /* active hash grpbys HWM         */
#define SQLM_ELM_ACTIVE_HASH_GRPBYS_TOP                                     1082
                                            /* active hash joins HWM          */
#define SQLM_ELM_ACTIVE_HASH_JOINS_TOP                                      1083
                                            /* active olap funs HWM           */
#define SQLM_ELM_ACTIVE_OLAP_FUNCS_TOP                                      1084
                                            /* active peas HWM                */
#define SQLM_ELM_ACTIVE_PEAS_TOP                                            1085
                                            /* active peds HWM                */
#define SQLM_ELM_ACTIVE_PEDS_TOP                                            1086
                                            /* active sort consumers HWM      */
#define SQLM_ELM_ACTIVE_SORT_CONSUMERS_TOP                                  1087
                                            /* active sort consumers HWM      */
#define SQLM_ELM_ACTIVE_SORTS_TOP                                           1088
                                            /* active work unit consumers HWM */
#define SQLM_ELM_ACTIVE_COL_VECTOR_CONSUMERS_TOP                            1089
                                            /* sort consumer heap HWM         */
#define SQLM_ELM_SORT_CONSUMER_HEAP_TOP                                     1090
                                            /* sort consumer shrheap HWM      */
#define SQLM_ELM_SORT_CONSUMER_SHRHEAP_TOP                                  1091
                                   /* Query's effective degree of parallelism */
#define SQLM_ELM_EFFECTIVE_QUERY_DEGREE                                    55358
                                   /* Query bypassed admission control        */
#define SQLM_ELM_ADM_BYPASSED                                               1092
                                   /* Estimated peak shared sort memory usage */
#define SQLM_ELM_ESTIMATED_SORT_SHRHEAP_TOP                                 1093
                                   /* Estimated peak sort memory consumers    */
#define SQLM_ELM_ESTIMATED_SORT_CONSUMERS_TOP                               1094
                                   /* Estimated runtime                       */
#define SQLM_ELM_ESTIMATED_RUNTIME                                          1095
#define SQLM_ELM_STMT_COMMENTS            1096 /* Comments from SQL statement */



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
#define SQLM_ELM_HI_ID                                                     55001
                                               /* health indicator value      */
#define SQLM_ELM_HI_VALUE                                                  55002
                                               /* health indicator state      */
#define SQLM_ELM_HI_ALERT_STATE                                            55003
                                               /* state of sub dbm obj        */
#define SQLM_ELM_DB2_ROLLED_UP_ALERT_STATE                                 55004
                                               /* state of sub db obj         */
#define SQLM_ELM_DATABASE_ROLLED_UP_ALERT_STATE                            55005
                                               /* state of sub ts obj         */
#define SQLM_ELM_TABLESPACE_ROLLED_UP_ALERT_STATE                          55006
                                               /* state of TSContainer        */
#define SQLM_ELM_CONTAINER_ROLLED_UP_ALERT_STATE                           55007
                                               /* hi collection object        */
#define SQLM_ELM_HI_OBJ_NAME                                               55008
                                               /* hi collection object detail */
#define SQLM_ELM_HI_OBJ_DETAIL                                             55009
                                               /* hi collection object state  */
#define SQLM_ELM_HI_OBJ_STATE                                              55010

/* the following are for health snapshot with detail only                     */
                                               /* formula used for value      */
#define SQLM_ELM_HI_FORMULA                                                55101
                                               /* more info available         */
#define SQLM_ELM_HI_ADDITIONAL_INFO                                        55102



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

/******************************************************************************/
/* NOTE: 60000 - 65535 reserved for internal IBM use                          */
/******************************************************************************/

/* End Of Monitor Definitions */

/******************************************************************************/
/******************************************************************************/
/* Database System Monitor data structures                                    */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* Timestamp                                                                  */
/******************************************************************************/
/******************************************************************************
** sqlm_timestamp data structure
******************************************************************************/
typedef struct sqlm_timestamp
{
  sqluint32     seconds;          /* GMT time in seconds since Jan.1,1970     */
  sqluint32     microsec;         /* microseconds, range 0 to 999999          */
}sqlm_timestamp;

/******************************************************************************
** Elapsed time (for CPU times)
*******************************************************************************/
typedef struct sqlm_time
{
  sqluint32     seconds;           /* elapsed seconds                         */
  sqluint32     microsec;          /* elapsed microseconds, range 0 to 999999 */
}sqlm_time;


/******************************************************************************/
/* Header structure for self-describing data stream                           */
/******************************************************************************/
typedef struct sqlm_header_info{
  sqluint32      size;
  sqluint16      type;
  sqluint16      element;
}sqlm_header_info;

typedef struct sqlm_header_data{
  struct sqlm_header_info header;
  char                    data[1];
}sqlm_header_data;

/******************************************************************************/
/******************************************************************************/
/* Snapshot Monitoring API (sqlmonss, sqlmon, sqlmrset) data structures       */
/* Used by version 5.2 snapshot and under exclusively                         */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/*  Snapshot Object Structure - Specifies a snapshot request (sqlmonss input) */
/*                                                                            */
/*  Specifies what information to collect (e.g., list of locks) for a given   */
/*  object, such as a database or an application.                             */
/*                                                                            */
/*  note: 'agent_id', and 'object' are required, only if applicable for the   */
/*        request type, and are mutually exclusive.                           */
/*        For example: a database name is required when the type is           */
/*        SQLMA_DBASE_LOCKS (get snapshot for locks on database), whereas     */
/*        an agent_id is required when the type is SQLMA_APPL_LOCKS_AGENT_ID. */
/*        Note that AGENT ID is the *APPLICATION HANDLE* of an application,   */
/*        which can be retrieved with an SQLMA_APPLINFO_ALL (list             */
/*        applications) request. It does not correspond to any Operating      */
/*        System process id. (It is named 'agent' for source compatibility    */
/*        with older releases of DB2.                                         */
/*                                                                            */
/*        Both agent_id and object are ignored for requests such              */
/*        as SQLMA_APPLINFO_ALL (list applications).                          */
/******************************************************************************/
/******************************************************************************
** sqlm_obj_struct data structure
**
** Table: Fields in the SQLM-OBJ-STRUCT Structure
** |--------------------------------------------------------------------|
** |Field Name|Data Type|Description                                    |
** |----------|---------|-----------------------------------------------|
** |AGENT_ID  |INTEGER  |The application handle of the application to   |
** |          |         |be monitored. Specified only if OBJ_TYPE       |
** |          |         |requires an agent_id (application handle). To  |
** |          |         |retrieve a health snapshot with full collection|
** |          |         |information, specify SQLM_HMON_OPT_COLL_FULL   |
** |          |         |in this field.                                 |
** |----------|---------|-----------------------------------------------|
** |OBJ_TYPE  |INTEGER  |The type of object to be monitored.            |
** |----------|---------|-----------------------------------------------|
** |OBJECT    |CHAR(36) |The name of the object to be monitored.        |
** |          |         |Specified only if OBJ_TYPE requires a name,    |
** |          |         |such as appl_id, or a database alias.          |
** |----------|---------|-----------------------------------------------|
**
** Valid values for OBJ_TYPE (defined in the sqlmon header file, found in the
** include directory) are:
**
** - SQLMA_DB2
** Instance related information.
** - SQLMA_DBASE
** Database related information for a particular database. If you use the
** SQLMA_DBASE value, you must provide the database name in the object
** parameter of sqlm_obj_struct structure.
** - SQLMA_APPL
** Application information for an application that matches the provided
** application ID. If you use the SQLMA_APPL value, you must provide an
** application ID in the object parameter of sqlm_obj_struct structure.
** - SQLMA_AGENT_ID
** Application information for an application that matches the provided
** agent ID. If you use the SQLMA_AGENT_ID value, you must provide an
** agent ID in the agent_id parameter of sqlm_obj_struct structure.
** - SQLMA_DBASE_TABLES
** Table information for a particular database. If you use the
** SQLMA_DBASE_TABLES value, you must provide the database name in the object
** parameter of sqlm_obj_struct structure.
** - SQLMA_DBASE_APPLS
** Application information for all applications connected to a particular
** database. If you use the SQLMA_DBASE_APPLS value, you must provide the
** database name in the object parameter of sqlm_obj_struct structure.
** - SQLMA_DBASE_APPLINFO
** Summary application information for connections to a particular database.
** If you use the SQLMA_DBASE_APPLINFO value, you must provide the database
** name in the object parameter of sqlm_obj_struct structure.
** - SQLMA_DBASE_LOCKS
** List of locks held on a particular database. If you use the
** SQLMA_DBASE_LOCKS value, you must provide the database name in the object
** parameter of sqlm_obj_struct structure.
** - SQLMA_APPL_LOCKS
** List of locks held by an application with the matching application ID. If
** you use the SQLMA_APPL_LOCKS value, you must provide an application ID in
** the object parameter of sqlm_obj_struct structure.
** - SQLMA_APPL_LOCKS_AGENT_ID
** List of locks held by an application with the matching agent ID. If you
** use the SQLMA_APPL_LOCKS_AGENT_ID value, you must provide an agent ID in
** the agent_id parameter of sqlm_obj_struct structure.
** - SQLMA_DBASE_ALL
** Database information for all active databases in the instance.
** - SQLMA_APPL_ALL
** Application information for all database connections in the instance.
** - SQLMA_APPLINFO_ALL
** Summary application information for all connections to the instance.
** - SQLMA_DCS_APPLINFO_ALL
** List of Database Connection Services (DCS) connections to the instance.
** - SQLMA_DYNAMIC_SQL
** Dynamic SQL statement information for a particular database. If you use the
** SQLMA_DYNAMIC_SQL value, you must provide the database name in the object
** parameter of sqlm_obj_struct structure.
** - SQLMA_DCS_DBASE
** Information for a particular Database Connection Services (DCS) database.
** If you use the SQLMA_DCS_DBASE value, you must provide the database name in
** the object parameter of sqlm_obj_struct structure.
** - SQLMA_DCS_DBASE_ALL
** Information for all active Database Connection Services (DCS) databases.
** - SQLMA_DCS_APPL_ALL
** Database Connection Services (DCS) application information for all
** connections.
** - SQLMA_DCS_APPL
** Database Connection Services (DCS) application information for an
** application that matches the provided application ID. If you use the
** SQLMA_DCS_APPL value, you must provide an application ID in the object
** parameter of sqlm_obj_struct structure.
** - SQLMA_DCS_APPL_HANDLE
** Database Connection Services (DCS) application information for an
** application that matches the provided agent ID. If you use the
** SQLMA_DCS_APPL_HANDLE value, you must provide an agent ID in the agent_id
** parameter of sqlm_obj_struct structure.
** - SQLMA_DCS_DBASE_APPLS
** Database Connection Services (DCS) application information for all active
** connections to a particular database. If you use the SQLMA_DCS_DBASE_APPLS
** value, you must provide the database name in the object parameter of
** sqlm_obj_struct structure.
** - SQLMA_DBASE_TABLESPACES
** Table space information for a particular database. If you use the
** SQLMA_DBASE_TABLESPACES value, you must provide the database name in the
** object parameter of sqlm_obj_struct structure.
** - SQLMA_DBASE_BUFFERPOOLS
** Bufferpool information for a particular database. If you use the
** SQLMA_DBASE_BUFFERPOOLS value, you must provide the database name in the
** object parameter of sqlm_obj_struct structure.
** - SQLMA_BUFFERPOOLS_ALL
** Information for all bufferpools.
** - SQLMA_DBASE_REMOTE
** Remote access information for a particular federated database. If you use
** the SQLMA_DBASE_REMOTE value, you must provide the database name in the
** object parameter of sqlm_obj_struct structure.
** - SQLMA_DBASE_REMOTE_ALL
** Remote access information for all federated databases.
** - SQLMA_DBASE_APPLS_REMOTE
** Remote access information for an application connected to a particular
** federated database. If you use the SQLMA_DBASE_APPLS_REMOTE value, you must
** provide the database name in the object parameter of sqlm_obj_struct
** structure.
** - SQLMA_APPL_REMOTE_ALL
** Remote access information for all applications.
******************************************************************************/
typedef struct sqlm_obj_struct      /* specifies a snapshot request           */
{
   sqluint32     agent_id;          /* used for requests based on appl-handle */
   sqluint32     obj_type;          /* Snapshot Request Type (SQLMA_XXXX)     */
   _SQLOLDCHAR   object[SQLM_OBJECT_SZ];/* used for requests based on object  */
                                 /* name, such as 'get snapshot for database' */
}sqlm_obj_struct;

/******************************************************************************/
/*  SQL Monitor Area  - A list of snapshot requests - (sqlmonss input)        */
/******************************************************************************/
/******************************************************************************
** sqlma data structure
** The SQL monitor area (SQLMA) structure is used to send database monitor
** snapshot requests to the database manager. It is also used to estimate
** the size (in bytes) of the snapshot output.
**
** Table: Fields in the SQLMA Structure
** |-------------------------------------------------------------------|
** |Field Name|  Data Type|  Description                               |
** |----------|-----------|--------------------------------------------|
** |OBJ_NUM   |  INTEGER  |  Number of objects to be monitored.        |
** |----------|-----------|--------------------------------------------|
** |OBJ_VAR   |  Array    |  An array of sqlm_obj_struct structures    |
** |          |           |  containing descriptions of objects to be  |
** |          |           |  monitored. The length of the array is     |
** |          |           |  determined by OBJ_NUM.                    |
** |----------|-----------|--------------------------------------------|
**
** COBOL Structure
**
** * File: sqlmonct.cbl
** 01 SQLMA.
**     05 OBJ-NUM                 PIC 9(9) COMP-5.
**     05 OBJ-VAR OCCURS 0 TO 100 TIMES DEPENDING ON OBJ-NUM.
**         10 AGENT-ID             PIC 9(9) COMP-5.
**         10 OBJ-TYPE             PIC 9(9) COMP-5.
**         10 OBJECT               PIC X(36).
** *
**
******************************************************************************/
typedef struct sqlma
{
   sqluint32     obj_num;     /* number of snapshot requests */
   sqlm_obj_struct obj_var[1];/* A req: which object and what info to collect */
}sqlma;

/******************************************************************************/
/* macro for estimating SQLMA size (use to allocate an sqlma)                 */
/* where 'n' is the number of requests for the snapshot                       */
/******************************************************************************/
#define SQLMASIZE(n) (offsetof(struct sqlma, obj_var)+(n)*(sizeof(struct sqlm_obj_struct)) )

/******************************************************************************/
/* Monitor Switch status                                                      */
/******************************************************************************/
/******************************************************************************
** sqlm_recording_group data structure
******************************************************************************/
typedef struct sqlm_recording_group
{
  sqluint32      input_state;        /* input state to set group (sqlmon())   */
  sqluint32      output_state;       /* returned current state                */
  sqlm_timestamp start_time;         /* monitor switch set time               */
}sqlm_recording_group;

/******************************************************************************/
/* sqlmonss output                                                            */
/******************************************************************************/
/******************************************************************************
** sqlm_collected data structure
******************************************************************************/

typedef struct sqlm_collected
{
  sqluint32      size;            /* size of sqlm_collected                   */

  sqluint32      db2;             /* OBSOLETE - use num_top_level_structs     */
  sqluint32      databases;       /* OBSOLETE - use num_top_level_structs     */
  sqluint32      table_databases; /* OBSOLETE - use num_top_level_structs     */
  sqluint32      lock_databases;  /* OBSOLETE - use num_top_level_structs     */
  sqluint32      applications;    /* OBSOLETE - use num_top_level_structs     */
  sqluint32      applinfos;       /* OBSOLETE - use num_top_level_structs     */
  sqluint32      dcs_applinfos;   /* OBSOLETE - use num_top_level_structs     */

  sqluint32      server_db2_type; /* Server DB2 Type (defined in sqlutil.h)   */
  sqlm_timestamp time_stamp;      /* Snapshot time                            */
  sqlm_recording_group group_states[SQLM_NUM_GROUPS_PREV8];/* current sw settings */
  _SQLOLDCHAR    server_prdid[SQLM_IDENT_SZ]; /* product/version on server    */
  _SQLOLDCHAR    server_nname[SQLM_IDENT_SZ]; /* Config NNAME of server       */
  _SQLOLDCHAR    server_instance_name[SQLM_IDENT_SZ]; /* instance name of DB2 */
  sqluint32      dbase_remote;  /* # of remote datasource/db for which information
                                     was collected                     */
  sqluint32      appl_remote;  /* # of remote datasource/appl for which information
                                    was collected                     */
  _SQLOLDCHAR    reserved[14];         /* reserved for future use  */
  sqluint16      node_number;          /* Node sending data                */
  sqlint32       time_zone_disp; /* Diff. in secs between GMT and local time  */
  sqluint32      num_top_level_structs; /* # of high level structs returned */
  sqluint32      tablespace_databases; /* OBSOLETE: use num_top_level_structs */
  sqluint32      server_version;       /* Version of server returning data    */
}sqlm_collected;

/******************************************************************************
*******************************************************************************
** The following are returned in the sqlmonss (user supplied) output buffer:
*******************************************************************************
*******************************************************************************/

/******************************************************************************/
/* Application Identification Information                                     */
/******************************************************************************/
typedef struct sqlm_appl_id_info
{
  sqluint32      agent_id;                   /* Application handle            */
  sqluint32      appl_status;                /* Application Status            */
  sqluint32      codepage_id;                /* codepage/CCSID at node        */
                                             /* where app started             */
  sqlm_timestamp status_change_time;         /* last appl status change time  */
  _SQLOLDCHAR    appl_name[SQLM_IDENT_SZ];   /* Application Program Name      */
  _SQLOLDCHAR    appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  _SQLOLDCHAR    sequence_no[SQLM_SEQ_SZ_V8];/* application id sequence number*/
  _SQLOLDCHAR    auth_id[SQLM_IDENT_SZ];     /* Authorization Id              */
  _SQLOLDCHAR    client_nname[SQLM_IDENT_SZ]; /* Config NNAME of client       */
  _SQLOLDCHAR    client_prdid[SQLM_IDENT_SZ]; /* product/version on client    */
  _SQLOLDCHAR    input_db_alias[SQLM_IDENT_SZ]; /* Input Database Alias       */
  _SQLOLDCHAR    client_db_alias[SQLM_IDENT_SZ]; /* Client Database Alias     */
  _SQLOLDCHAR    db_name[SQLM_IDENT_SZ];     /* Database name                 */
  _SQLOLDCHAR    db_path[SQLM_DBPATH_SZ];    /* Database Path                 */
}sqlm_appl_id_info;

/******************************************************************************/
/* Application Id Information                                                 */
/******************************************************************************/
typedef struct sqlm_applinfo
{
  sqluint32      size;                       /* size of sqlm_applinfo         */
  _SQLOLDCHAR    info_type;                  /* Always set to SQLM_APPLINFO_SS*/
  _SQLOLDCHAR    pad[3];                     /* padding for 4-byte alignment  */
  sqlm_appl_id_info   id_info;               /* Identification information    */

  _SQLOLDCHAR    reserved[20];               /* reserved for future use       */
  sqluint32      num_assoc_agents;           /* Number of agents associated   */
                                             /* with this application         */
  sqluint32      coord_node_num;             /* Coordinating node number      */
  sqluint32      authority_lvl;              /* User authorizations           */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Client Identification Information                   */
  /****************************************************************************/
  char           execution_id[SQLM_IDENT_SZ]; /* login ID */
  char           corr_token[SQLM_APPLID_SZ_V8];  /* DRDA AS Correlation Token    */
  sqluint32      client_pid;           /* Process/thread ID of client appl.   */
  sqluint16      client_platform;      /* Platform of client application      */
  sqluint16      client_protocol;      /* Communications protocol of client   */
  sqluint16      country_code;         /* Country code of client application  */
  char           pad2[2];
  sqlint32       coord_agent_pid;      /* Coordinator agent process/thread id */
}sqlm_applinfo;

/******************************************************************************/
/* LIST DCS APPLICATIONS  output                                              */
/******************************************************************************/
/* DCS Application Identification Information                                 */
/* In V5.1 and beyond, it is always followed by sqlm_dcs_applid_info.         */
/*                                                                            */
/*     high-level struct      secondary-level structures                      */
/*  +--------------------------+----------------------+                       */
/*  |sqlm_dcs_applinfo         |sqlm_dcs_applid_info  |                       */
/*  |num_sec_dcs_app_structs:1 |                      |                       */
/*  +--------------------------+----------------------+                       */
/*                                                                            */
/******************************************************************************/
typedef struct sqlm_dcs_applinfo
{
  sqluint32      size;                       /* size of sqlm_dcs_applinfo     */
  _SQLOLDCHAR    info_type;                  /* set to SQLM_DCS_APPLINFO_SS   */
  _SQLOLDCHAR    pad[3];                     /* padding for 4-byte alignment  */

/* The following fields have been moved to the sqlm_dcs_applid_info secondary */
/* structure.  They are only returned for down-level (V5.0.0 and lower)       */
/* list application requests.                                                 */
  sqluint32      agent_id;  /* OBSOLETE, MOVED to sqlm_dcs_applid_info */
  sqluint32      codepage_id;                      /* OBSOLETE */
                                                   /* OBSOLETE */
  _SQLOLDCHAR    appl_name[SQLM_IDENT_SZ];         /* OBSOLETE */
  _SQLOLDCHAR    appl_id[SQLM_APPLID_SZ_V8];          /* OBSOLETE */
  _SQLOLDCHAR    sequence_no[SQLM_SEQ_SZ_V8];         /* OBSOLETE */
  _SQLOLDCHAR    auth_id[SQLM_IDENT_SZ];           /* OBSOLETE */
  _SQLOLDCHAR    client_nname[SQLM_IDENT_SZ];      /* OBSOLETE */
  _SQLOLDCHAR    client_prdid[SQLM_IDENT_SZ];      /* OBSOLETE */
  _SQLOLDCHAR    client_db_alias[SQLM_IDENT_SZ];   /* OBSOLETE */
  _SQLOLDCHAR    db_name[SQLM_IDENT_SZ];           /* OBSOLETE */
  _SQLOLDCHAR    host_prdid[SQLM_IDENT_SZ];        /* OBSOLETE */
  _SQLOLDCHAR    outbound_appl_id[SQLM_APPLID_SZ_V8]; /* OBSOLETE */
  _SQLOLDCHAR    outbound_sequence_no[SQLM_SEQ_SZ_V8];/* OBSOLETE */
  sqluint32      dcs_appl_status;                  /* OBSOLETE */
  sqlm_timestamp status_change_time;               /* OBSOLETE */
  sqluint16      client_platform;                  /* OBSOLETE */
  sqluint16      client_protocol;                  /* OBSOLETE */
  sqluint16      host_ccsid;                       /* OBSOLETE */
  sqluint32      num_sec_dcs_app_structs; /* number of structs following    */
  char           reserved[10];            /* reserved for future use        */
}sqlm_dcs_applinfo;

/******************************************************************************/
/* Identification information returned for a DCS application                  */
/* in V5.1 and beyond.                                                        */
/* (Duplicated for backward compatibility in sqlm_dcs_applinfo.)              */
/******************************************************************************/
typedef struct sqlm_dcs_applid_info
{
  sqluint32      size;                       /* size of sqlm_dcs_applid_info  */
  char           info_type;                  /* set to SQLM_DCS_APPLID_SS     */
  char           pad[3];                     /* padding for 4-byte alignment  */

  /****************************************************************************/
  /* Client Identification Information                                        */
  /****************************************************************************/
  sqluint32      agent_id;                   /* Application handle            */
  sqluint32      codepage_id;                /* codepage/CCSID at node        */
                                             /* where app started             */
  sqluint32      client_pid;           /* Process/thread ID of client appl.   */
  char           appl_name[SQLM_IDENT_SZ];   /* Application Program Name      */
  char           appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  char           sequence_no[SQLM_SEQ_SZ_V8];   /* application id sequence number*/
  char           auth_id[SQLM_IDENT_SZ];     /* Authorization Id              */
  char           client_nname[SQLM_IDENT_SZ]; /* Config NNAME of client       */
  char           client_prdid[SQLM_IDENT_SZ]; /* product/version on client    */
  char           gw_db_alias[SQLM_IDENT_SZ];  /* gateway  Database Alias      */
  char           execution_id[SQLM_IDENT_SZ]; /* Client Login ID              */

  char     outbound_comm_address[SQLM_COMM_ADDR_SZ_V8];/* Outb. comm. address */
  char     inbound_comm_address[SQLM_COMM_ADDR_SZ_V8];/* Inbound comm. address*/
  sqluint16      outbound_comm_protocol;     /* Outbound comm. protocol       */

  sqluint16      client_platform;            /* Client platform               */
  sqluint16      client_protocol;            /* Client protocol               */
  char           pad2[2];

  /****************************************************************************/
  /* Gateway and Host Identification Information                              */
  /****************************************************************************/
  char           dcs_db_name[SQLM_IDENT_SZ];/* DCS Database name              */
  char           host_db_name[SQLM_IDENT_SZ]; /* Host Database name           */
  char           host_prdid[SQLM_IDENT_SZ]; /* Host Product id                */
  char           outbound_appl_id[SQLM_APPLID_SZ_V8]; /* Outbound LUWID          */
  char           outbound_sequence_no[SQLM_SEQ_SZ_V8]; /* Outbound sequence #    */
  sqluint32      dcs_appl_status;         /* Status of DCS application        */
  sqlm_timestamp status_change_time;      /* Time status last changed         */
  sqluint16      host_ccsid;              /* Host database Coded Char Set ID  */
  char           pad3[2];
}sqlm_dcs_applid_info;

/******************************************************************************/
/* Counters for SNAPSHOT DCS APPLICATION                                      */
/******************************************************************************/
typedef struct sqlm_dcs_appl_stats {

  sqlm_timestamp  gw_con_time;          /* Connect start date/time            */

  /****************************************************************************/
  /* Application level cumulative counters                                    */
  /****************************************************************************/
  sqlm_time      gw_exec_time;         /* Time spent on gateway processing    */
  sqluint32      rows_selected;        /* # of rows selected                  */

  /****************************************************************************/
  /* SQL statement counters                                                   */
  /****************************************************************************/
  sqluint32      sql_stmts;        /* # of sql stmts attempted since conn     */
  sqluint32      failed_sql_stmts;       /* # of Failed SQL stmts since conn  */
  sqluint32      commit_sql_stmts;       /* # of Commit SQL stmts since conn  */
  sqluint32      rollback_sql_stmts;     /* # of Rollback SQL stmts since conn*/

  /****************************************************************************/
  /* DB2 Connect elements                                                     */
  /****************************************************************************/
  sqluint32       inbound_bytes_received; /* inbound # of bytes received      */
  sqluint32       outbound_bytes_sent;    /* outbound # of bytes sent         */
  sqluint32       outbound_bytes_received;/* outbound # of bytes received     */
  sqluint32       inbound_bytes_sent;     /* inbound # of bytes sent          */
}sqlm_dcs_appl_stats;

/******************************************************************************/
/* The following structure uses the previous one and also contains the size   */
/* and info_type fields. It is used as a secondary structure that occurs      */
/* after sqlm_dcs_appl structure in GET SNAPSHOT FOR DCS APPLICATION output.  */
/******************************************************************************/
typedef struct sqlm_dcs_appl_snap_stats {
  sqluint32           size;              /* size of sqlm_dcs_appl_snap_stats  */
  char                info_type;         /* set to SQLM_DCS_APPL_STATS_SS     */
  char                pad[3];            /* padding for 4-byte alignment      */
  sqlm_dcs_appl_stats appl_stats;
}sqlm_dcs_appl_snap_stats;

/******************************************************************************/
/* GET SNAPSHOT FOR DCS APPLICATIONS                                          */
/*                                                                            */
/*  Secondary-level structures are returned, if applicable.                   */
/*  They provide extra information about the connection.                      */
/*                                                                            */
/*  The secondary-level structures sqlm_dcs_applid_info and                   */
/*  sqlm_appl_snap_stats are always returned (in that order).                 */
/*  They immediately follow the high-level structure sqlm_dcs_appl in the     */
/*  sqlmonss buffer.                                                          */
/*                                                                            */
/*    high-level struct     secondary-level structures                        */
/* |-----------+----------|--------------------+--------------------+ ...     */
/* +----------------------+--------------------+--------------------+ ...     */
/* |sqlm_dcs_appl         |sqlm_dcs_applid_info|sqlm_appl_snap_stats|         */
/* |num_sec_dcs_structs:5 |                    |                    |         */
/* +----------------------+-----------------------------------------  ...     */
/*                                                                            */
/*     secondary-level structures (continued)                                 */
/* ... +-------------+----------------+-------------|                         */
/*     +-------------+----------------+-------------+                         */
/* ... |sqlm_appl_xid|sqlm_tpmon_info |sqlm_dcs_stmt|                         */
/*     |             |                |             |                         */
/* ... -------------------------------+-------------+                         */
/******************************************************************************/
typedef struct sqlm_dcs_appl
{
  sqluint32      size;                  /* size of sqlm_dcs_appl              */
  char           info_type;             /* always set to SQLM_DCS_APPL_SS     */
  char           pad[3];                /* padding for 4-byte alignment       */

  sqluint32      num_sec_dcs_structs;   /* number of structures that follow   */
                                        /* this one in the snapshot output    */
                                        /* buffer to provide info for this    */
                                        /* DCS application                    */
  sqluint32      stmt_operation;        /* most recent SQL stmt operation     */
  sqluint32      section_number;        /* most recent SQL stmt section number*/
  sqlm_timestamp stmt_start;      /* when received from client at the gateway */
  sqlm_timestamp stmt_stop;       /* when sent to client from the gateway     */
  char    creator[SQLM_IDENT_SZ];
  char    package_name[SQLM_OLD_PACKAGE_NAME_SZ];
  sqluint32       appl_idle_time; /* time (seconds) since last stmt completed */
  sqluint32       open_cursors;         /* currently open cursors             */

  /****************************************************************************/
  /* Unit-Of-Work Information                                                 */
  /****************************************************************************/
  sqluint32       uow_comp_status;      /* previous uow completion status     */
  sqlm_timestamp  prev_uow_stop_time;   /* prev commit or rollback time       */
  sqlm_timestamp  uow_start_time;       /* time trans exec started            */
  sqlm_timestamp  uow_stop_time;        /* unit-of-work stop time             */
  sqluint32       inbound_bytes_received; /* OBSOLETE                         */
  sqluint32       outbound_bytes_sent;    /* OBSOLETE                         */
  sqluint32       outbound_bytes_received;/* OBSOLETE                         */
  sqluint32       inbound_bytes_sent;     /* OBSOLETE                         */

  /****************************************************************************/
  /* Last snapshot reset                                                      */
  /****************************************************************************/
  sqlm_timestamp  last_reset;           /* Last snapshot reset date and time  */
}sqlm_dcs_appl;

/******************************************************************************/
/* XID Information - returned on application and DCS application snapshot     */
/******************************************************************************/
/* 2-phase commit transaction id - generated by our own TM database           */
/* or external TM                                                             */

typedef struct sqlm_appl_xid {
  sqluint32      size;               /* Use instead of sizeof(sqlm_appl_xid)  */
  char           info_type;          /* Always set to SQLM_APPL_XID_SS        */
  char           pad[3];             /* padding for 4-byte alignment          */
  sqluint32      xid_size;           /* XID size                              */
  char           xid [1];            /* XID                                   */
}sqlm_appl_xid;

/******************************************************************************/
/* 3-tier client information - returned on application and DCS application    */
/*                             snapshot if sqleseti call is done in app.      */
/*                                                                            */
/* layout:                                                                    */
/* sqlm_tpmon_info may be followed by the text, if any, provided as           */
/* accounting information to the Set Client api                               */
/*                                                                            */
/*  +------------------------+--------------------------+                     */
/*  |sqlm_tpmon_info         |"ACCOUNTING INFO PDADFBW "|                     */
/*  |  size: 300             |                          |                     */
/*  |  acc_str_length: 200   |                          |                     */
/*  |  acc_str_offset: 100   |                          |                     */
/*  +------------------------+--------------------------+                     */
/*                                                                            */
/******************************************************************************/
typedef struct sqlm_tpmon_info  {
  sqluint32      size;             /* Use instead of sizeof(sqlm_tpmon_info)  */
  char           info_type;        /* Always set to SQLM_TPMON_INFO_SS        */
  char           pad[3];           /* padding for 4-byte alignment            */

  char tpmon_client_userid[SQLM_IDENT_SZ]; /* TP Monitor client user ID       */
  char tpmon_client_wkstn[SQLM_IDENT_SZ]; /* TP Monitor client workstation    */
  char tpmon_client_app[SQLM_IDENT_SZ]; /* TP Monitor client app. name        */

  sqluint16      acc_str_length;   /* Client accounting string size in bytes  */
  sqluint16      acc_str_offset;  /*  Offset from start of sqlm_tpmon_info    */
}sqlm_tpmon_info;

/******************************************************************************/
/*                                                                            */
/* Statement that is running on a host                                        */
/*                                                                            */
/* (info returned for DCS applications, only if the statement switch is ON    */
/*                                                                            */
/* layout:                                                                    */
/* sqlm_dcs_stmt may be followed by statement text.                           */
/*                                                                            */
/*  +------------------------+--------------------------+                     */
/*  |sqlm_dcs_stmt           |"SELECT * FROM TABLE1    "|                     */
/*  |  size: 132             |                          |                     */
/*  |  stmt_length: 24       |                          |                     */
/*  |  stmt_text_offset: 108 |                          |                     */
/*  +------------------------+--------------------------+                     */
/*                                                                            */
/******************************************************************************/
typedef struct sqlm_dcs_stmt {
  sqluint32      size;               /* use instead of sizeof(sqlm_dcs_stmt)  */
                                     /* *INCLUDES* variable length SQL text   */
  char           info_type;          /* always set to SQLM_DCS_STMT_SS        */
  char           pad[3];             /* padding for 4-byte alignment          */

  char           creator[SQLM_IDENT_SZ];      /* auth id for precompile       */
  char           package_name[SQLM_OLD_PACKAGE_NAME_SZ]; /* Package name      */
  sqluint32      section_number;     /* section number                        */
  sqluint32      query_cost_estimate;/* SQL compiler estim. in TIMERONS       */
  sqluint32      query_card_estimate;/* SQL compiler estim. number of rows    */

  sqlm_timestamp stmt_start;         /* SQL statement operation start time    */
  sqlm_timestamp stmt_stop;          /* SQL statement operation stop time     */
  sqluint32      stmt_operation;     /* most recent operation executed        */
  sqluint32      fetch_count;        /* total number of rows fetched          */

  /* Gateway statistics */
  sqlm_time       gw_exec_time;      /* Time spent executing in the gateway   */
  sqluint32       inbound_bytes_received; /* client  -> gateway               */
  sqluint32       outbound_bytes_sent;    /* gateway -> host                  */
  sqluint32       outbound_bytes_received;/* host    -> gateway               */
  sqluint32       inbound_bytes_sent;     /* gateway -> client                */

  sqluint16      stmt_length;        /* length of SQL stmt text, which is     */
                                     /* blank-padded to a 4-byte boundary     */
  sqluint16      stmt_text_offset;   /* text offset from start of sqlm_stmt   */
}sqlm_dcs_stmt;

/******************************************************************************/
/*                                                                            */
/* DCS database statistics                                                    */
/*                                                                            */
/******************************************************************************/
typedef struct sqlm_dcs_dbase
{
  sqluint32      size;                  /* size of sqlm_dcs_dbase             */
  char           info_type;             /* always set to SQLM_DCS_DBASE_SS    */
  char           pad[3];                /* padding for 4-byte alignment       */

  char           dcs_db_name[SQLM_IDENT_SZ];/* dcs database name              */
  char           host_db_name[SQLM_IDENT_SZ]; /* host database name           */
  sqlm_timestamp gw_con_time;           /* first connect date/time            */
  sqlm_timestamp last_reset;            /* last monitor reset                 */

  /****************************************************************************/
  /* SQL statement counts                                                     */
  /****************************************************************************/
  sqluint32      sql_stmts;              /* # of sql stmts since connection   */
  sqluint32      failed_sql_stmts;       /* # of failed SQL stmts since conn  */
  sqluint32      commit_sql_stmts;       /* # of commit SQL stmts since conn  */
  sqluint32      rollback_sql_stmts;     /* # of rollback SQL stmts since conn*/
  sqluint32      rows_selected;          /* # of rows selected                */

  /****************************************************************************/
  /* Gateway statistics                                                       */
  /****************************************************************************/
  sqluint32      gw_total_cons;          /* connects since db activations     */
  sqluint32      gw_cur_cons;            /* appls currently connected         */
  sqluint32      gw_cons_wait_host;      /* appls waiting for host's reply    */
  sqluint32      gw_cons_wait_client;    /* appls waiting for client to send  */
  sqluint32      gw_connections_top; /* high water mark for concurrent conn's */
}sqlm_dcs_dbase;

/******************************************************************************/
/* Remote Data Source Related Snapshot Information by DB                      */
/******************************************************************************/

typedef struct sqlm_dbase_remote
{
  sqluint32 size;                 /* size of sqlm_dbase_remote            */
  char info_type;                 /* collected information type           */
  char datasource_name[SQLM_SERVERNAME_SZ]; /* Remote data source name    */
  char db_name[SQLM_IDENT_SZ];    /* Database name                        */
  sqluint32  total_cons;          /* # of connects                        */
  sqluint32  disconnects;         /* # of disconnects                     */
  sqluint32  commit_sql_stmts;    /* # of commits                         */
  sqluint32  rollback_sql_stmts;  /* # of rollbacks                       */
  sqluint32  select_sql_stmts;    /* # of queries                         */
  sqluint32  insert_sql_stmts;    /* # of inserts                         */
  sqluint32  update_sql_stmts;    /* # of updates                         */
  sqluint32  delete_sql_stmts;    /* # of deletes                         */
  sqluint32  create_nickname;     /* # of create nickname statements      */
  sqluint32  passthrus;           /* # of statements passed through       */
  sqluint32  stored_procs;        /* # of stored procedures               */
  sqluint32  rows_selected;       /* # of rows returned                   */
  sqluint32  rows_updated;        /* # of rows updated                    */
  sqluint32  rows_deleted;        /* # of rows deleted                    */
  sqluint32  rows_inserted;       /* # of rows inserted                   */
  sqluint32  sp_rows_selected;    /* # of rows returned from stored proc  */
  sqluint32  failed_sql_stmts;    /* # of statements that failed          */
  sqlm_time  select_time;         /* Aggregate response time to queries   */
  sqlm_time  insert_time;         /* Aggregate response time to inserts   */
  sqlm_time  update_time;         /* Aggregate response time to updates   */
  sqlm_time  delete_time;         /* Aggregate response time to deletes   */
  sqlm_time  create_nickname_time;/* Aggregate response time to create nick */
  sqlm_time  passthru_time;       /* Aggregate response time to passthru    */
  sqlm_time  stored_proc_time;    /* Aggregate response time to passthru    */
} sqlm_dbase_remote;

/******************************************************************************/
/* Remote Data Source Related Snapshot Information by Application             */
/******************************************************************************/

typedef struct sqlm_appl_remote
{
  sqluint32  size;                /* size of sqlm_appl_remote                */
  char   info_type;               /* collected information type              */
  sqlm_appl_id_info   id_info;    /* appl identification information         */
  char       datasource_name[SQLM_SERVERNAME_SZ]; /* Remote data source name */
  char       db_name[SQLM_IDENT_SZ];/* Database name                         */
  sqluint32  commit_sql_stmts;    /* # of commits                            */
  sqluint32  rollback_sql_stmts;  /* # of rollbacks                          */
  sqluint32  select_sql_stmts;    /* # of queries                            */
  sqluint32  insert_sql_stmts;    /* # of inserts                            */
  sqluint32  update_sql_stmts;    /* # of updates                            */
  sqluint32  delete_sql_stmts;    /* # of deletes                            */
  sqluint32  create_nickname;     /* # of create nickname statements         */
  sqluint32  passthrus;           /* # of statements passed through          */
  sqluint32  stored_procs;        /* # of stored procedures                  */
  sqluint32  rows_selected;       /* # of rows returned                      */
  sqluint32  rows_updated;        /* # of rows updated                       */
  sqluint32  rows_deleted;        /* # of rows deleted                       */
  sqluint32  rows_inserted;       /* # of rows inserted                      */
  sqluint32  sp_rows_selected;    /* # of rows returned from stored proc     */
  sqluint32  failed_sql_stmts;    /* # of statements that failed             */
  sqlm_time  select_time;         /* Aggregate response time to queries      */
  sqlm_time  insert_time;         /* Aggregate response time to inserts      */
  sqlm_time  update_time;         /* Aggregate response time to updates      */
  sqlm_time  delete_time;         /* Aggregate response time to deletes      */
  sqlm_time  create_nickname_time;/* Aggregate response time to create nick  */
  sqlm_time  passthru_time;       /* Aggregate response time to passthru     */
  sqlm_time  stored_proc_time;    /* Aggregate response time to passthru     */
} sqlm_appl_remote;


/******************************************************************************/
/* Database manager Snapshot                                                  */
/******************************************************************************/
/* DB2 snapshot layout.  If running in a parallel environment,  'secondary'   */
/* level structures may also be returned.  For example:                       */
/*                                                                            */
/*      high-level struct      secondary-level                                */
/*  |------------+-----------|--------+--------|                              */
/*  +------------------------+-----------------+-------------+-------------+  */
/*  |sqlm_db2                |sqlm_fcm         |sqlm_fcm_node|sqlm_fcm_node|  */
/*  |  num_sec_dbm_structs: 1|  number_nodes: 2|             |             |  */
/*  +------------------------+-----------------+-------------+-------------+  */
/*----------------------------------------------------------------------------*/
typedef struct sqlm_db2
{
  sqluint32      size;                  /* size of sqlm_db2                   */
  _SQLOLDCHAR    info_type;             /* Always set to SQLM_DB2_SS          */
  _SQLOLDCHAR    pad1[3];               /* padding for 4-byte alignment       */

  /****************************************************************************/
  /* Sorting Information                                                      */
  /****************************************************************************/
  sqluint32      sort_heap_allocated;   /* Sort heap currently allocated      */
  sqluint32      post_threshold_sorts;  /* # sorts started after heap         */
                                        /* threshold exceeded                 */
  sqluint32      piped_sorts_requested; /* # of piped sorts requested         */
                                        /* by RDS to SLS                      */
  sqluint32      piped_sorts_accepted;  /* # of piped sorts accepted by SLS   */

  /****************************************************************************/
  /* Timestamps                                                               */
  /****************************************************************************/
  sqlm_timestamp db2start_time;          /* DB2START timestamp                */
  sqlm_timestamp last_reset;             /* Date/Time of Last Reset           */

  /****************************************************************************/
  /* Connection Information                                                   */
  /****************************************************************************/
  sqluint32      rem_cons_in;           /* Remote connects to target DB2      */
  sqluint32      rem_cons_in_exec;      /* Remote connects to target exec DB2 */
  sqluint32      local_cons;            /* Current Local Connections          */
  sqluint32      local_cons_in_exec;    /* Local connects curr exec in DB2    */
  sqluint32      con_local_dbases;      /* Local databases w/current connects */
  sqluint32      agents_registered;     /* Number of agents registered in DB2 */
  sqluint32      agents_waiting_on_token;   /* # of agents waiting on a token */

  /****************************************************************************/
  /* Server Switch settings - indicate if the DBMS is collecting monitor data */
  /****************************************************************************/
  unsigned char  dbmon_sw_settings[SQLM_NUM_GROUPS];     /* SQLM_OFF, SQLM_ON */
  char    pad2[1];                            /* padding for 4-byte alignment */
  sqluint32      dbmon_sw_set_time[SQLM_NUM_GROUPS];/* GMT time (in seconds)  */
                                  /* when switch was set - 0 if switch is OFF */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  DB2 Instance Status                                 */
  /****************************************************************************/
  sqluint32      db2_status;            /* status of the DB2 instance         */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  High Water Marks                                    */
  /****************************************************************************/
  sqluint32      agents_registered_top; /* agents_registered high water mark  */
  sqluint32      agents_waiting_top;    /* agents_waiting high water mark     */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  DB2 Instance Memory Usage Information               */
  /****************************************************************************/
  sqluint32      comm_private_mem;      /* Committed Private Memory           */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Agent Information                                   */
  /****************************************************************************/
  sqluint32      idle_agents;           /* number of unassigned agents in pool*/

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Agent Information                                   */
  /****************************************************************************/
  sqluint32      agents_from_pool;      /* # agents assigned from pool        */
  sqluint32      agents_created_empty_pool; /* # agents created because the   */
                                        /* pool was empty                     */
  sqluint32      coord_agents_top;      /* coordinating agents high water mark*/
  sqluint32      max_agent_overflows;   /* # of attempts to exceed the        */
                                        /* MAXAGENTS configuration parameter. */
  sqluint32      agents_stolen;         /* # agents stolen                    */
  sqluint32      num_sec_dbm_structs;   /* Secondary database manager info    */
  char product_name[SQLM_LG_IDENT_SZ];  /* Product Name                       */
  char component_id[SQLM_IDENT_SZ];     /* Product Identificiation            */
  char service_level[SQLM_SH_IDENT_SZ]; /* Service Level                      */
  /****************************************************************************/
  /* SQLM_DBMON_VERSION5_2 DB2 CONNECT (DDCS) information                     */
  /****************************************************************************/
  sqluint32      gw_total_cons; /* Total number of gateway connections        */
  sqluint32      gw_cur_cons;   /* Current number of gateway connections      */
  sqluint32      gw_cons_wait_host; /* # gateway conns waiting for host reply */
  sqluint32      gw_cons_wait_client;/* Gateway conns waiting for client reply*/
  sqluint32      post_threshold_hash_joins; /* # hash joins started after heap*/
                                            /* threshold exceeded             */
}sqlm_db2;

/******************************************************************************/
/* Fast Communication Manager (FCM) related Snapshot Information              */
/******************************************************************************/
typedef struct sqlm_fcm
{
  sqluint32      size;                  /* size of sqlm_fcm                   */
  _SQLOLDCHAR    info_type;             /* Always set to SQLM_FCM_SS          */
  _SQLOLDCHAR    pad[3];                /* padding for 4-byte alignment       */

  /****************************************************************************/
  /* FCM Buffer Information                                                   */
  /****************************************************************************/
  sqluint32      buff_free;              /* # of FCM buffers free             */
  sqluint32      buff_free_bottom;       /* low water mark of buffers free    */

  /****************************************************************************/
  /* FCM Message Anchor Information                                           */
  /****************************************************************************/
  sqluint32      MA_free;                /* # of FCM message anchors free     */
  sqluint32      MA_free_bottom;         /* low water mark of anchors free    */

  /****************************************************************************/
  /* FCM Connection Entry Information                                         */
  /****************************************************************************/
  sqluint32      CE_free;                /* # of FCM connection entries free  */
  sqluint32      CE_free_bottom;         /* low water mark of free CEs        */

  /****************************************************************************/
  /* FCM Request Blocks Information                                           */
  /****************************************************************************/
  sqluint32      RB_free;                /* # of FCM request blocks free      */
  sqluint32      RB_free_bottom;         /* low water mark of free RBs        */

  /****************************************************************************/
  /* FCM Node Status Information                                              */
  /****************************************************************************/
  sqluint32      number_nodes;           /* # of FCM node structures which    */
                                         /* follow.                           */
}sqlm_fcm;

/******************************************************************************/
/* FCM Node Snapshot Information                                              */
/******************************************************************************/
typedef struct sqlm_fcm_node
{
  sqluint32      size;                  /* size of sqlm_fcm_node              */
  _SQLOLDCHAR    info_type;             /* Always set to SQLM_NODE_SS         */
  _SQLOLDCHAR    pad1[1];               /* padding for half-word aligment     */
  sqluint16      node_number;           /* Remote node number                 */
  sqluint32      connection_status;     /* FCM Connnection status to node     */

  /****************************************************************************/
  /* FCM Buffer Counts                                                        */
  /****************************************************************************/
  sqluint32      total_buffers_sent;     /* Total # of buffers sent           */
  sqluint32      total_buffers_rcvd;     /* Total # of buffers received       */
}sqlm_fcm_node;

/******************************************************************************/
/* Database Snapshot                                                          */
/******************************************************************************/
/* Database snapshot layout. If a rollforward is in progress, a 'secondary'   */
/* level structure is also returned, for example:                             */
/*                                                                            */
/*          high-level struct        secondary-level                          */
/*      |------------+-------------|---------+---------|                      */
/*      +--------------------------+-------------------+--------------------+ */
/*      |sqlm_dbase                |sqlm_rollfwd_info  |sqlm_rollfwd_ts_info| */
/*      |  num_sec_dbase_structs: 1|  rf_num_tspaces: 1|                    | */
/*      +--------------------------+-------------------+--------------------+ */
/*----------------------------------------------------------------------------*/
typedef struct sqlm_dbase
{
  sqluint32      size;                  /* size of sqlm_dbase                 */
  _SQLOLDCHAR    info_type;             /* Always set to SQLM_DBASE_SS        */
  _SQLOLDCHAR    pad1[3];               /* padding for 4-byte alignment       */
  _SQLOLDCHAR    input_db_alias[SQLM_IDENT_SZ]; /* Input Database Alias       */
  _SQLOLDCHAR    db_name[SQLM_IDENT_SZ];        /* Database name              */
  _SQLOLDCHAR    db_path[SQLM_DBPATH_SZ];       /* Database Path              */

  /****************************************************************************/
  /* Locking Information                                                      */
  /****************************************************************************/
  sqluint32      locks_held;             /* Locks currently held              */
  sqluint32      lock_waits;             /* Lock waits since 1st connect      */
  sqluint32      lock_wait_time;         /* Total time dbase waited on locks  */
  sqluint32      lock_list_in_use;       /* total lock list memory in use     */
  sqluint32      deadlocks;              /* Deadlocks since 1st db connect    */
  sqluint32      lock_escals;            /* lock escals since 1st db connect  */
  sqluint32      x_lock_escals;          /* X lock escals since 1st db connect*/
  sqluint32      locks_waiting;          /* Agents currently waiting on locks */

  /****************************************************************************/
  /* Sorting Information                                                      */
  /****************************************************************************/
  sqluint32      sort_heap_allocated;    /* Total sort heap allocated         */
  sqluint32      total_sorts;            /* number of sorts since 1st connect */
  sqluint32      total_sort_time;        /* elapsed time spent in sorts       */
  sqluint32      sort_overflows;         /* number of sort overflows          */
  sqluint32      active_sorts;           /* sorts currently active            */

  /****************************************************************************/
  /* Buffer Pool Information                                                  */
  /****************************************************************************/
  sqluint32      pool_data_l_reads;      /* pool data logical reads since conn*/
  sqluint32      pool_data_p_reads;      /* pool data reads since 1st connect */
  sqluint32      pool_data_writes;       /* pool data writes since 1st connect*/
  sqluint32      pool_index_l_reads;     /* pool indx logical reads since conn*/
  sqluint32      pool_index_p_reads;     /* pool indx reads since 1st connect */
  sqluint32      pool_index_writes;      /* pool indx writes since 1st connect*/
  sqluint32      pool_read_time;         /* Buff pool read time since 1st conn*/
  sqluint32      pool_write_time;        /* Buff pool write time since 1st con*/

  sqluint32      files_closed;           /* files closed since first db conn  */

  /****************************************************************************/
  /* SQL statement counts                                                     */
  /****************************************************************************/
  sqluint32      commit_sql_stmts;       /* # of Commit SQL stmts since conn  */
  sqluint32      rollback_sql_stmts;     /* # of Rollback SQL stmts since conn*/
  sqluint32      dynamic_sql_stmts;      /* # of Dynamic SQL stmts since conn */
  sqluint32      static_sql_stmts;       /* # of Static SQL stmts since conn  */
  sqluint32      failed_sql_stmts;       /* # of Failed SQL stmts since conn  */
  sqluint32      select_sql_stmts;       /* # of SQL select stmts since conn  */
  sqluint32      ddl_sql_stmts;          /* # of data definition lang. stmts  */
  sqluint32      uid_sql_stmts;          /* # of update/insert/delete stmts   */

  /****************************************************************************/
  /* Internal counts                                                          */
  /****************************************************************************/
  sqluint32      int_auto_rebinds;       /* # of Auto Rebinds since 1st conn  */
  sqluint32      int_rows_deleted;       /* # of Casc. Deletes since 1st conn */
  sqluint32      int_rows_updated;       /* # of Set Null Deletes since conn  */
  sqluint32      int_commits;            /* # of int. Commits since 1st conn  */
  sqluint32      int_rollbacks;          /* # of int. Rollbacks since 1st conn*/
  sqluint32      int_deadlock_rollbacks; /* # of Rollbacks due to deadlock    */
                                         /*      since 1st connect            */

  /****************************************************************************/
  /* Row counts                                                               */
  /****************************************************************************/
  sqluint32      rows_deleted;           /* # of Rows Deleted since connect   */
  sqluint32      rows_inserted;          /* # of Rows Inserted since connect  */
  sqluint32      rows_updated;           /* # of Rows Updated since connect   */
  sqluint32      rows_selected;          /* # of Rows Selected since connect  */

  /****************************************************************************/
  /* Binds/Precompiles                                                        */
  /****************************************************************************/
  sqluint32      binds_precompiles;      /* # of Binds/Precomps since 1st conn*/

  /****************************************************************************/
  /* Timestamps                                                               */
  /****************************************************************************/
  sqlm_timestamp  db_conn_time;           /* Time of 1st database connection  */
  sqlm_timestamp  last_reset;             /* Date/Time of Last Reset          */
  sqlm_timestamp  last_backup;            /* Date/Time of Last Backup         */

  /****************************************************************************/
  /* Application connection counters                                          */
  /****************************************************************************/
  sqluint32      total_cons;             /* Connects since 1st db connect     */
  sqluint32      appls_cur_cons;         /* Appls currently connected         */
  sqluint32      appls_in_db2;           /* Appls executing in the DB2        */

  /****************************************************************************/
  /* Logging Information                                                      */
  /****************************************************************************/
  sqluint32      sec_log_used_top;       /* Maximum secondary log space used  */
  sqluint32      tot_log_used_top;       /* Maximum total log space used      */
  sqluint32      sec_logs_allocated;     /* Number of secondary logs allocated*/

  _SQLOLDCHAR    reserved[8];                /* reserved for future use      */

  sqluint32     num_sec_dbase_structs;      /* Secondary Database information */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Buffer Pool and I/O Information                     */
  /****************************************************************************/
  sqluint32      pool_async_index_reads;   /* asynchronous pool index reads   */
  sqluint32      pool_data_to_estore;    /* #pages copied from BP to estore   */
  sqluint32      pool_index_to_estore;   /* #pages copied from BP to estore   */
  sqluint32      pool_index_from_estore; /* #pages copied from estore to BP   */
  sqluint32      pool_data_from_estore;  /* #pages copied from estore to BP   */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Database Status                                     */
  /****************************************************************************/
  sqluint32      db_status;             /* status of the Database             */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  lock information                                    */
  /****************************************************************************/
  sqluint32      lock_timeouts;        /* # of lock timeouts since 1st conn   */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  High Water Marks                                    */
  /****************************************************************************/
  sqluint32      connections_top;  /* high water mark for current connections */
  sqluint32      db_heap_top;      /* high water mark for database heap(bytes)*/

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Buffer Pool and I/O Information                     */
  /****************************************************************************/
  sqluint32      pool_async_data_reads;    /* asynchronous pool data reads    */
  sqluint32      pool_async_data_writes;   /* asynchronous pool data writes   */
  sqluint32      pool_async_index_writes;  /* asynchronous pool index writes  */
  sqluint32      pool_async_read_time;     /* total async read time           */
  sqluint32      pool_async_write_time;    /* total async write time          */
  sqluint32      pool_async_data_read_reqs; /* # async read requests          */
  sqluint32      pool_lsn_gap_clns;        /* LSN Gap cleaner triggers        */
  sqluint32      pool_drty_pg_steal_clns;  /* dirty page steal cleaner trig.  */
  sqluint32      pool_drty_pg_thrsh_clns;  /* dirty list threshold cln trig.  */
  sqluint32      direct_reads;             /* direct reads since 1st connect  */
  sqluint32      direct_writes;            /* direct writes since 1st conn    */
  sqluint32      direct_read_reqs;         /* direct read requests            */
  sqluint32      direct_write_reqs;        /* direct write requests           */
  sqluint32      direct_read_time;         /* direct read time since 1st conn */
  sqluint32      direct_write_time;        /* direct write time since 1st conn*/

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2 Internal counts                                      */
  /****************************************************************************/
  sqluint32      int_rows_inserted;      /* # rows insrted for Trigger        */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2 Logging Information                                  */
  /****************************************************************************/
  sqluint32      log_reads;             /* # of log pages read since 1st conn */
  sqluint32      log_writes;            /* # of log pages read since 1st conn */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2 Package Cache Information                            */
  /****************************************************************************/
  sqluint32      pkg_cache_lookups;     /* # of section lookups               */
  sqluint32      pkg_cache_inserts;     /* # of sections inserted into cache  */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2 Catalog Cache Information                            */
  /****************************************************************************/
  sqluint32      cat_cache_lookups;     /* # of table descriptor lookups      */
  sqluint32      cat_cache_inserts;     /* # of table descriptors inserted    */
  sqluint32      cat_cache_overflows;   /* # of catalog cache overflows       */
  sqluint32      cat_cache_heap_full;   /* # of overflows due to db heap full */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5                                                      */
  /****************************************************************************/
  sqluint32      catalog_node;          /* Catalog node number                */
  sqluint32      total_sec_cons;        /* Secondary connects since 1st       */
                                        /* database connection.               */
  sqluint32      num_assoc_agents;      /* Current number of agents associated*/
                                        /* with appls connected to this db.   */
  sqluint32      agents_top;            /* max # of agents associated at once */
                                        /* with appls connected to this db.   */
  sqluint32      coord_agents_top;      /* max # of coordinating agents       */
                                        /* connected to this db. at one time. */
  sqluint16      db_location;           /* local or remote to snapshot appl.  */
  sqluint16      server_platform;       /* OS on which dbm runs               */
  char catalog_node_name[SQLM_LG_IDENT_SZ];/* Catalog network node name       */
  sqluint32      prefetch_wait_time;    /* Time waited for prefetch (ms)      */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5 Application Section Retrieval Information            */
  /****************************************************************************/
  sqluint32      appl_section_lookups;  /* # of section lookups               */
  sqluint32      appl_section_inserts;  /* # of sections inserted             */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5_2 Hash join information                              */
  /****************************************************************************/
  sqluint32      total_hash_joins;          /* number of hash joins           */
  sqluint32      total_hash_loops;          /* number of hash loops           */
  sqluint32      hash_join_overflows;       /* number of hash join overflows  */
  sqluint32      hash_join_small_overflows; /* small hash join overflows      */
}sqlm_dbase;

/******************************************************************************/
/* Application snapshot                                                       */
/******************************************************************************/
/* layout:                                                                    */
/* sqlm_appl may be followed by secondary structures that provide more        */
/* information about the application.                                         */
/*                                                                            */
/* The secondary structures are returned in the following order.              */
/*   1) List of associated agents                                             */
/*      sqlm_agent for each *associated* agent (either active or idle)        */
/*   2) Lock Wait info                                                        */
/*      sqlm_lock_wait for each lock waited on (returned if lock switch       */
/*      is set)                                                               */
/*   3) Statement level information   (returned if statement switch is set)   */
/*      Statement information is returned using the following structures,     */
/*      returned in order:                                                    */
/*                                                                            */
/*       +---------------------------------+----------------------+           */
/*       |Non-Partitioned Databases        |Partitionned Databases|           */
/*       +----------------+----------------+----------------------+           */
/*       |Query degree = 1|Query degree > 1|Query degree = n      |           */
/*       +----------------+----------------+----------------------+           */
/*       |sqlm_stmt       |sqlm_stmt       |sqlm_stmt             |           */
/*       |                |sqlm_agent      |sqlm_subsection       |           */
/*       |                |                |sqlm_agent            |           */
/*       +----------------+----------------+----------------------+           */
/*                                                                            */
/*      An sqlm_stmt is returned for each currently open cursor, and for      */
/*      the most recent statement processed (either the statement still       */
/*      running, if any, or last one terminated). Each sqlm_stmt may be       */
/*      followed by subsection and/or agent information for the statement.    */
/*                                                                            */
/*      On partitioned systems, an sqlm_subsection is returned for each       */
/*      subsection processed.                                                 */
/*                                                                            */
/*      An sqlm_agent is returned for each agent *currently working* on       */
/*      either a statement or subsection.                                     */
/*                                                                            */
/* For example, assuming a partitioned database:                              */
/*                                                                            */
/*     high-level struct            secondary-level structures                */
/*  |-----------+-----------|--------------------+---------------- ...        */
/*  +-----------------------+----------+----------+--------------+            */
/*  |sqlm_appl              |sqlm_agent|sqlm_agent|sqlm_lock_wait|            */
/*  |num_sec_appl_structs:10|          |          |              | ...        */
/*  |num_assoc_agents:    2 |          |          |              |            */
/*  +-----------------------+----------+----------+--------------+            */
/*                                                                            */
/*          secondary-level structures (continued)                            */
/*  ... ---------------------+-------------------------------------- ...      */
/*      +---------------+---------------+----------+---------------+          */
/*      |sqlm_stmt      |sqlm_subsection|sqlm_agent|sqlm_subsection|          */
/*  ... |num_ss: 2      |               |          |               | ...      */
/*      |num_agents: 2  |num_agents: 1  |          |num_agents: 1  |          */
/*      +---------------+---------------+----------+---------------+          */
/*                                                                            */
/*          secondary-level structures (continued)                            */
/*  ... ----------------------------------------------|                       */
/*      +-------------+---------------+---------------+                       */
/*      |sqlm_agent   |sqlm_stmt      |sqlm_subsection|                       */
/*  ... |             |num_ss: 1      |               |                       */
/*      |             |num_agents: 0  |num_agents: 0  |                       */
/*      +-------------+---------------+---------------+                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/
typedef struct sqlm_appl
{
  sqluint32      size;                  /* size of sqlm_appl                  */
  _SQLOLDCHAR    info_type;             /* Always set to SQLM_APPL_SS         */
  _SQLOLDCHAR    pad1[3];               /* padding for 4-byte alignment       */

  /****************************************************************************/
  /* Identification Information                                               */
  /****************************************************************************/
  sqlm_appl_id_info   id_info;               /* identification information    */

  /****************************************************************************/
  /* Lock Information                                                         */
  /****************************************************************************/
  sqluint32      locks_held;             /* locks currently held by appl.     */
  sqluint32      lock_waits;             /* Lock waits since appl. connect    */
  sqluint32      lock_wait_time;         /* total time appl waited on locks   */
  sqluint32      lock_escals;            /* Lock Escalations since appl conn. */
  sqluint32      x_lock_escals;          /* X lock escals since appl connect  */
  sqluint32      deadlocks;              /* Deadlocks since appl. connect     */
  sqluint32      uow_lock_wait_time;     /* time UOW waited on locks (ms)     */
  sqluint32      agent_id_holding_lk;    /* OBSOLETE : use sqlm_lock_wait     */
  sqluint32      table_file_id;          /* OBSOLETE : use sqlm_lock_wait     */
  sqluint32      lock_mode;              /* OBSOLETE : use sqlm_lock_wait     */
  sqluint32      lock_object_type;       /* OBSOLETE : use sqlm_lock_wait     */
  sqluint32      lock_object_name;       /* OBSOLETE : use sqlm_lock_wait     */
  sqlm_timestamp lock_wait_start_time;   /* OBSOLETE : use sqlm_lock_wait     */
  _SQLOLDCHAR    appl_id_holding_lk[SQLM_APPLID_SZ_V8]; /* OBSOLETE  */
  _SQLOLDCHAR    sequence_no_holding_lk[SQLM_SEQ_SZ_V8];/* OBSOLETE  */

  /****************************************************************************/
  /* Sorting Information                                                      */
  /****************************************************************************/
  sqluint32      total_sorts;            /* Total Sorts since connect         */
  sqluint32      total_sort_time;        /* elapsed time spent in sorts       */
  sqluint32      sort_overflows;         /* number of sort overflows          */

  /****************************************************************************/
  /* Buffer Pool Information                                                  */
  /****************************************************************************/
  sqluint32      pool_data_l_reads;      /* pool data logical reads since conn*/
  sqluint32      pool_data_p_reads;      /* pool data reads since 1st connect */
  sqluint32      pool_data_writes;       /* pool data writes since 1st connect*/
  sqluint32      pool_index_l_reads;     /* pool indx logical reads since conn*/
  sqluint32      pool_index_p_reads;     /* pool indx reads since 1st connect */
  sqluint32      pool_index_writes;      /* pool indx writes since 1st connect*/
  sqluint32      pool_read_time;         /* Buff pool read time since 1st conn*/
  sqluint32      pool_write_time;        /* Buff pool write time since 1st con*/

  /****************************************************************************/
  /* SQL statement counts                                                     */
  /****************************************************************************/
  sqluint32      commit_sql_stmts;       /* # of Commit SQL stmts since conn  */
  sqluint32      rollback_sql_stmts;     /* # of Rollback SQL stmts since conn*/
  sqluint32      dynamic_sql_stmts;      /* # of Dynamic SQL stmts since conn */
  sqluint32      static_sql_stmts;       /* # of Static SQL stmts since conn  */
  sqluint32      failed_sql_stmts;       /* # of Failed SQL stmts since conn  */
  sqluint32      select_sql_stmts;       /* # of SQL select stmts since conn  */
  sqluint32      ddl_sql_stmts;          /* # of data definition lang. stmts  */
  sqluint32      uid_sql_stmts;          /* # of update/insert/delete stmts   */

  /****************************************************************************/
  /* Internal counts                                                          */
  /****************************************************************************/
  sqluint32      int_auto_rebinds;       /* # of Auto Rebinds since 1st conn  */
  sqluint32      int_rows_deleted;       /* # of Casc. Deletes since 1st conn */
  sqluint32      int_rows_updated;       /* # of Set Null Deletes since conn  */
  sqluint32      int_commits;            /* # of int. Commits since 1st conn  */
  sqluint32      int_rollbacks;          /* # of int. Rollbacks since 1st conn*/
  sqluint32      int_deadlock_rollbacks; /* # of Rollbacks due to deadlock    */
                                         /*      since 1st connect            */

  /****************************************************************************/
  /* Row counts                                                               */
  /****************************************************************************/
  sqluint32      rows_deleted;           /* # of Rows Deleted since connect   */
  sqluint32      rows_inserted;          /* # of Rows Inserted since connect  */
  sqluint32      rows_updated;           /* # of Rows Updated since connect   */
  sqluint32      rows_selected;          /* # of Rows Selected since connect  */

  /****************************************************************************/
  /* Binds/Precompiles                                                        */
  /****************************************************************************/
  sqluint32      binds_precompiles;      /* # of Binds/Precomps since 1st conn*/

  /****************************************************************************/
  /* SQL Statement Information - current operation performed on coordinator   */
  /****************************************************************************/
  sqluint32      stmt_type;
  sqluint32      stmt_operation;
  sqluint32      section_number;
  sqluint32      stmt_length;                 /* OBSOLETE (use sqlm_stmt) */
  sqluint32      stmt_sorts;                  /* OBSOLETE (use sqlm_stmt) */
  sqlm_timestamp stmt_start;
  sqlm_timestamp stmt_stop;   /* Last statement stop time, 0 if still running */
  _SQLOLDCHAR    cursor_name[SQLM_IDENT_SZ];
  _SQLOLDCHAR    creator[SQLM_IDENT_SZ];
  _SQLOLDCHAR    package_name[SQLM_OLD_PACKAGE_NAME_SZ]; /* Package name      */

  /****************************************************************************/
  /* Unit-Of-Work Information                                                 */
  /****************************************************************************/
  sqluint32       uow_log_space_used;   /* Log space used in most recent UOW  */
  sqluint32       uow_comp_status;      /* previous uow completion status     */
  sqlm_timestamp  prev_uow_stop_time;   /* prev commit or rollback time       */
  sqlm_timestamp  uow_start_time;       /* time trans exec started            */
  sqlm_timestamp  uow_stop_time;        /* unit-of-work stop time             */

  /****************************************************************************/
  /* Remote cursor Information                                                */
  /****************************************************************************/
  sqluint32      open_rem_curs;         /* Currently open remote cursors      */
  sqluint32      open_rem_curs_blk;     /* Currently open remote cursors w/blk*/
  sqluint32      rej_curs_blk;          /* Rej block remote cursor requests   */
  sqluint32      acc_curs_blk;          /* Acc block remote cursor requests   */

  /****************************************************************************/
  /* Timestamps                                                               */
  /****************************************************************************/
  sqlm_timestamp  appl_con_time;        /* Connect start date/time            */
  sqlm_timestamp  conn_complete_time;   /* Connect complete date/time         */
  sqlm_timestamp  last_reset;           /* Last reset date and time           */

  sqluint32      curr_comm_heap_size;   /* OBSOLETE */
  sqluint32      max_comm_heap_size;    /* OBSOLETE */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Agent CPU times                                     */
  /****************************************************************************/
  sqluint32      appl_idle_time;        /* Application idle time (seconds)    */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Buffer Pool and I/O Information                     */
  /****************************************************************************/
  sqluint32      pool_data_to_estore;    /* #pages copied from BP to estore   */
  sqluint32      pool_index_to_estore;   /* #pages copied from BP to estore   */
  sqluint32      pool_index_from_estore; /* #pages copied from estore to BP   */
  sqluint32      pool_data_from_estore;  /* #pages copied from estore to BP   */

  sqluint32      authority_lvl;         /* User authorizations                */
  sqluint32      sql_reqs_since_commit; /* # SQL requests since last commit   */
  sqluint32      num_sec_appl_structs;  /* Secondary application information  */

  char  table_name[SQLM_IDENT_SZ];      /* OBSOLETE (moved to sqlm_lock_wait) */
  char  table_schema[SQLM_IDENT_SZ];    /* OBSOLETE (moved to sqlm_lock_wait) */
  char  tablespace_name[SQLM_IDENT_SZ]; /* OBSOLETE (moved to sqlm_lock_wait) */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  lock information                                    */
  /****************************************************************************/
  sqluint32      lock_timeouts;        /* number of lock timeouts since conn  */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Agent CPU times                                     */
  /****************************************************************************/
  sqlm_time      agent_usr_cpu_time;   /* total user CPU time of application  */
  sqlm_time      agent_sys_cpu_time;   /* total application system cpu time   */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  SQL Statement CPU times                             */
  /****************************************************************************/
  sqlm_time      stmt_usr_cpu_time;    /* OBSOLETE (moved to sqlm_stmt)       */
  sqlm_time      stmt_sys_cpu_time;    /* OBSOLETE (moved to sqlm_stmt)       */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Internal counts                                     */
  /****************************************************************************/
  sqluint32      int_rows_inserted;      /* # rows insrted for Trigger        */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Row Counts                                          */
  /****************************************************************************/
  sqluint32      rows_read;              /* # rows read since connection      */
  sqluint32      rows_written;           /* # rows written since connetion    */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  I/O Information                                     */
  /****************************************************************************/
  sqluint32      direct_reads;             /* direct reads since connect      */
  sqluint32      direct_writes;            /* direct writes since connect     */
  sqluint32      direct_read_reqs;         /* direct read requests since conn */
  sqluint32      direct_write_reqs;        /* direct write requests since conn*/
  sqluint32      direct_read_time;         /* direct read time since connect  */
  sqluint32      direct_write_time;        /* direct write time since connect */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Local Cursor Information                            */
  /****************************************************************************/
  sqluint32      open_loc_curs;         /* Currently open local cursors       */
  sqluint32      open_loc_curs_blk;     /* Currently open local cursors w/blk */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Client Identification Information                   */
  /****************************************************************************/
  char           execution_id[SQLM_IDENT_SZ]; /* login ID                     */
  char           corr_token[SQLM_APPLID_SZ_V8];  /* DRDA AS Correlation Token    */
  sqluint32      client_pid;           /* Process thread ID of client appl.   */
  sqluint16      client_platform;      /* Platform of client application      */
  sqluint16      client_protocol;      /* Communications protocol of client   */
  sqluint16      country_code;         /* Country code of client application  */
  char           pad2[2];              /* Padding for 4-byte alignment        */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2 Package Cache Information                            */
  /****************************************************************************/
  sqluint32      pkg_cache_lookups;     /* # of section lookups               */
  sqluint32      pkg_cache_inserts;     /* # of sections inserted into cache  */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2 Catalog Cache Information                            */
  /****************************************************************************/
  sqluint32      cat_cache_lookups;     /* # of table descriptor lookups      */
  sqluint32      cat_cache_inserts;     /* # of table descriptors inserted    */
  sqluint32      cat_cache_overflows;   /* # of catalog cache overflows       */
  sqluint32      cat_cache_heap_full;   /* # of overflows due to db heap full */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5                                                      */
  /****************************************************************************/
  sqluint32      coord_node;            /* Coordinating node number.          */
  sqluint32      num_assoc_agents;      /* # of agents currently associated   */
  sqluint32      num_agents;            /* # of agents currently active       */
  sqluint32      agents_stolen;         /* total # of agents stolen from appl.*/
  sqluint32      associated_agents_top; /* # of agents associated with this   */
                                        /* application  high water mark.      */
  sqlint32       appl_priority;         /* priority at which appl agents work */
  sqluint32      appl_priority_type;    /* Dynamic or Static                  */
  sqluint32      prefetch_wait_time;    /* Time waited for prefetch (ms)      */
  sqlint32       coord_agent_pid;       /* Coordinator agent process/thread id*/

  sqluint32      appl_section_lookups;  /* # of section lookups               */
  sqluint32      appl_section_inserts;  /* # of sections inserted             */
  sqluint32      locks_waiting;         /* # agents currently waiting on locks*/
  char           outbound_comm_address[SQLM_COMM_ADDR_SZ_V8];/*Outb.comm. addr*/
  char           inbound_comm_address[SQLM_COMM_ADDR_SZ_V8];/*Inb. comm. addr.*/
  sqluint16      outbound_comm_protocol;     /* Outbound comm. protocol       */
  char           pad3[2];

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5_2 Hash join information                              */
  /****************************************************************************/
  sqluint32      total_hash_joins;          /* number of hash joins           */
  sqluint32      total_hash_loops;          /* number of hash loops           */
  sqluint32      hash_join_overflows;       /* number of hash join overflows  */
  sqluint32      hash_join_small_overflows; /* small hash join overflows      */
}sqlm_appl;

/******************************************************************************/
/* SQL Statement snapshot - returned on application snapshot (SQLMA_APPL)     */
/******************************************************************************/
/* layout:                                                                    */
/* sqlm_stmt may be followed by dynamic statement text, and agent structures. */
/* On Partitioned database systems, it may be followed by subsection          */
/* statistics. For example:                                                   */
/*                                                                            */
/*  Non-Partitioned database (query degree=2):                                */
/*  +-----------------+--------------------------+----------+----------+      */
/*  |sqlm_stmt        |"SELECT * FROM TABLE1    "|sqlm_agent|sqlm_agent|      */
/*  |  stmt_length: 24|                          |          |          |      */
/*  |  num_ss:       1|                          |          |          |      */
/*  |  num_agents:   2|                          |          |          |      */
/*  +-----------------+--------------------------+----------+----------+      */
/*                                                                            */
/*  Partitioned database output (query degree=1):                             */
/*  +-----------------+--------------------------+---------------+----------+ */
/*  |sqlm_stmt        |"SELECT * FROM TABLE1    "|sqlm_subsection|sqlm_agent| */
/*  |  stmt_length: 24|                          |ss_number: 0   |          | */
/*  |  num_ss:       1|                          |               |          | */
/*  |  num_agents:   1|                          |num_agents: 1  |          | */
/*  +-----------------+--------------------------+---------------+----------+ */
/*                                                                            */
/* The statement text length is rounded up to a multiple of 4 bytes and is    */
/* blank padded. It is *NOT* null terminated.  It is retrieved as follows:    */
/*                                                                            */
/*    char*       snapshot_buffer;                                            */
/*    sqlm_stmt*  stmt_snapshot = (sqlm_stmt*) snapshot_buffer;               */
/*    char *stmt_text = snapshot_buffer + stmt_snapshot->stmt_text_offset;    */
/*                                                                            */
/* note: num_sec_appl_structs in sqlm_appl includes the count of              */
/*       sqlm_subsection and sqlm_agent structures.                           */
/*----------------------------------------------------------------------------*/
typedef struct sqlm_stmt {
  sqluint32      size;               /* Use instead of sizeof(sqlm_stmt)      */
                                     /* *INCLUDES* variable length SQL text   */
  char           info_type;          /* Always set to SQLM_STMT_SS            */
  char           pad[1];             /* padding for half-word alignment       */
  sqluint16      stmt_node_number;   /* Node where the statement is executing */
  sqluint32      stmt_type;          /* type of stmt: Dynamic or static       */
  sqluint32      stmt_operation;     /* Current Operation                     */
  sqluint32      section_number;     /* Section Number                        */
  sqluint32      query_cost_estimate;/* SQL compiler estim. in TIMERONS       */
  sqluint32      query_card_estimate;/* SQL compiler estim. number of rows    */
  sqluint32      degree_parallelism; /* SMP Intraquery Parallelism requested  */
  sqluint32      stmt_sorts;         /* number of sorts for this statement    */
  sqluint32      total_sort_time;    /* Total sort time for this statement    */
  sqluint32      sort_overflows;     /* # of sort overflows for this stmt     */
  sqluint32      rows_read;          /* # of DMS rows read                    */
  sqluint32      rows_written;       /* # of DMS rows read                    */
  sqluint32      int_rows_deleted;   /* # of internal deletes by the stmt     */
  sqluint32      int_rows_updated;   /* # of internal updates by the stmt     */
  sqluint32      int_rows_inserted;  /* # of internal inserts by the stmt     */
  sqluint32      fetch_count;        /* Count of fetches                      */

  sqlm_timestamp stmt_start;         /* SQL statement operation start time    */
  sqlm_timestamp stmt_stop;          /* SQL statement operation stop time     */
  char           cursor_name[SQLM_IDENT_SZ];  /* sql stmt.cursor name         */
  char           creator[SQLM_IDENT_SZ];      /* auth id for precompile       */
  char           package_name[SQLM_OLD_PACKAGE_NAME_SZ]; /* Package name      */
  sqlm_time      stmt_usr_cpu_time;  /* total user CPU time of SQL stmt       */
  sqlm_time      stmt_sys_cpu_time;  /* total system CPU time for SQL stmt    */

  sqluint32      num_ss;             /* number of subsections                 */
  sqluint32      num_agents;         /* # of agents currently working on stmt */
  sqluint32      agents_top;         /* # of agents created for statement     */
  sqluint16      stmt_length;        /* length of dynamic SQL text, which is  */
                                     /* blank padded to a 4-byte boundary     */
  sqluint16      stmt_text_offset;   /* Text offset from start of sqlm_stmt   */
}sqlm_stmt;

/******************************************************************************/
/* SQL Subsection -  returned on application snapshot (SQLMA_APPL)            */
/******************************************************************************/
typedef struct sqlm_subsection
{
  sqluint32      size;              /* Use instead of sizeof(sqlm_subsection) */
  char           info_type;         /* Always set to SQLM_SUBSECTION_SS       */
  char           pad1[1];           /* padding for memory alignment           */

  sqluint16      ss_number;         /* Subsection number                      */
  sqluint16      ss_status;         /* Subsection status                      */
  sqluint16      ss_node_number;    /* Node where the subsection is executing */
  sqluint32      ss_exec_time;      /* Execution elapsed time in seconds      */

  sqlm_time      ss_usr_cpu_time;   /* total user CPU time (sec.microsec)     */
  sqlm_time      ss_sys_cpu_time;   /* total system CPU time (sec.microsec)   */

  /* Tablequeue information */
  sqluint16      tq_node_waited_for;/* If blocked when sending or receiving   */
                                    /* on a tablequeue, node for which we wait*/
  sqluint16      tq_wait_for_any;   /* TRUE if waiting for any node to send   */
  sqluint16      tq_id_waiting_on;  /* tablequeue waiting to send/receive     */
  char           pad2[2];           /* padding for 4-byte memory alignment    */
  sqluint32      tq_tot_send_spills;/* Total # of buffers overflowed to a     */
                                    /*  temp table when sending data on a tq  */
  sqluint32      tq_cur_send_spills;/* Current # of tq send buffers overflowed*/
  sqluint32      tq_max_send_spills;/* Maximum # of tq send buffers overflowed*/
  sqluint32      tq_rows_read;      /* Total # rows received on tablequeues   */
  sqluint32      tq_rows_written;   /* Total # rows sent on tablequeues       */

  sqluint32      rows_read;         /* # of Data Manager (DMS) rows read      */
  sqluint32      rows_written;      /* # of DMS rows written                  */

  sqluint32      num_agents;        /* # of agents currently working on subs  */
}sqlm_subsection;

/******************************************************************************/
/* SQL Agent -  returned on application snapshot (SQLMA_APPL)                 */
/******************************************************************************/
typedef struct sqlm_agent {
  sqluint32      size;               /* Use instead of sizeof(sqlm_agent)     */
  char           info_type;          /* Always set to SQLM_AGENT_SS           */
  char           pad1[3];            /* padding for 4-byte alignment          */

  sqlint32       agent_pid;          /* db2agent process/thread id            */
}sqlm_agent;

/******************************************************************************/
/* Lock Wait Snapshot Information                                             */
/******************************************************************************/
typedef struct sqlm_lock_wait
{
  sqluint32      size;                 /* Use over sizeof(sqlm_lock_wait)     */
  char           info_type;            /* Always set to SQLM_LOCK_WAIT_SS     */
  unsigned char  lock_escalation;      /* Was this lock part of an escalation */
  char           pad1[2];              /* padding for 4 byte alignment        */
  sqluint32      subsection_number;    /* Subsection waiting for lock  */

  sqluint32      lock_mode;            /* Mode of Lock waited on              */
  sqluint32      lock_object_type;     /* lock object type: row, table, ...   */
  sqlm_timestamp lock_wait_start_time; /* Time when lock wait entered         */
  char           table_name[SQLM_IDENT_SZ];
  char           table_schema[SQLM_IDENT_SZ];
  char           tablespace_name[SQLM_IDENT_SZ];

  sqluint32      agent_id_holding_lk;  /* Application holding the lock */
  char           appl_id_holding_lk[SQLM_APPLID_SZ_V8];/* Appl. holding the lock */
} sqlm_lock_wait;

/******************************************************************************/
/* Table Related Snapshot Information                                         */
/******************************************************************************/
typedef struct sqlm_table_header
{
  sqluint32      size;                   /* size of sqlm_table_header         */
  _SQLOLDCHAR    info_type;              /* Always set to SQLM_TABLE_HEADER_SS*/
  _SQLOLDCHAR    pad1[3];                /* padding for 4-byte alignment      */
  sqluint32      num_tables;             /* # of sqlm_table struct returned   */
  sqlm_timestamp db_conn_time;           /* Time of 1st database connection   */
  sqlm_timestamp last_reset;             /* last reset date and time          */
  _SQLOLDCHAR    input_db_alias[SQLM_IDENT_SZ]; /* Input Database Alias       */
  _SQLOLDCHAR    db_name[SQLM_IDENT_SZ];        /* Database name              */
  _SQLOLDCHAR    db_path[SQLM_DBPATH_SZ];       /* Database Path              */
}sqlm_table_header;

typedef struct sqlm_table
{
  sqluint32      size;                    /* size of sqlm_table               */
  _SQLOLDCHAR    info_type;               /* Always set to SQLM_TABLE_SS      */
  _SQLOLDCHAR    pad1[3];                 /* padding for 4 byte alignment     */
  sqluint32      table_file_id;           /* the file ID for the table        */
  sqluint32      table_type;              /* table type                       */
  sqluint32      rows_written;            /* number of changes to the table   */
  sqluint32      rows_read;               /* number of reads from the table   */
  sqluint32      overflow_accesses;       /* no. of accesses to overflow rec  */
  sqluint32      page_reorgs;             /* no. of page reorgs for table     */
  _SQLOLDCHAR    reserved[28];            /* reserved for future use          */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Table Identification                                */
  /****************************************************************************/
  char           table_name[SQLM_IDENT_SZ];   /* table name                   */
  char           table_schema[SQLM_IDENT_SZ]; /* table schema                 */
}sqlm_table;

/******************************************************************************/
/* lock related information                                                   */
/******************************************************************************/
/* Database lock snapshot layout, example:                                    */
/*                                                                            */
/*              high-level struct                                             */
/*           |-----------+------------|                                       */
/* buffer--->+------------------------+--------------+     +--------------+   */
/*           |sqlm_dbase_lock         |sqlm_appl_lock| ... |sqlm_appl_lock|   */
/*           |  num_appls: 2          |          (1) |     |              |   */
/*           +------------------------+--------------+     +--------------+   */
/*                                                                            */
/*             (1) see sqlm_appl_lock layout                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
typedef struct sqlm_dbase_lock
{
  sqluint32      size;                   /* size of sqlm_dbase_lock           */
  _SQLOLDCHAR    info_type;              /* Always set to SQLM_DBASE_LOCK_SS  */
  _SQLOLDCHAR    pad[3];                 /* padding for 4-byte alignment      */
  sqluint32      locks_held;             /* number of locks currently held    */
  sqluint32      appls_cur_cons;         /* Appls currently connected         */
  sqluint32      num_appls;              /* # sqlm_appl_lock structs returned */
  sqluint32      locks_waiting;          /* Agents currently waiting on locks */
  _SQLOLDCHAR    input_db_alias[SQLM_IDENT_SZ]; /* Input Database Alias       */
  _SQLOLDCHAR    db_name[SQLM_IDENT_SZ];        /* Database name              */
  _SQLOLDCHAR    db_path[SQLM_DBPATH_SZ];       /* Database Path              */
}sqlm_dbase_lock;

/******************************************************************************/
/* Application lock snapshot                                                  */
/******************************************************************************/
/* Application lock snapshot layout, example:                                 */
/*                                                                            */
/*              high-level struct                                             */
/*           |-----------+------------|                                       */
/* buffer--->+------------------------+--------------+---------+---------+    */
/*           |sqlm_appl_lock          |sqlm_lock_wait|sqlm_lock|sqlm_lock|    */
/*           |  num_locks: 2          |              |         |         |    */
/*           |  num_lockwaits: 1      |              |         |         |    */
/*           +------------------------+--------------+---------+---------+    */
/*                                                                            */
/* Lock waits, if any, *always precede the locks*. That is, read the buffer   */
/* in the following manner:                                                   */
/*                                                                            */
/*    sqlm_appl_lock *app_lock_info = (sqlm_appl_lock*) buffer;               */
/*    while (app_lock_info->num_lockwaits--)                                  */
/*    {                                                                       */
/*       sqlm_lock_wait *appl_lock = (sqlm_lock_wait*) buffer;                */
/*                . . .                                                       */
/*       buffer += appl_lock->size;                                           */
/*    }                                                                       */
/*    while (app_lock_info->num_locks--)                                      */
/*    {                                                                       */
/*       sqlm_lock *lock = (sqlm_lock*) buffer;                               */
/*                 . . .                                                      */
/*       buffer += lock->size;                                                */
/*    }                                                                       */
/*                                                                            */
/*----------------------------------------------------------------------------*/
typedef struct sqlm_appl_lock
{
  sqluint32      size;                   /* size of sqlm_appl_lock            */
  _SQLOLDCHAR    info_type;              /* Always set to SQLM_APPL_LOCK_SS   */
  _SQLOLDCHAR    pad[3];                 /* padding for 4-byte alignment      */

  /****************************************************************************/
  /* Application Identification Information                                   */
  /****************************************************************************/
  sqluint32      agent_id;                 /* Application handle              */
  sqluint32      appl_status;              /* Application Status              */
  sqluint32      codepage_id;              /* codepage/CCSID at node          */
                                           /* where app started               */
  sqluint32      locks_held;               /* locks currently held by appl.   */
  sqluint32      num_locks;                /* # sqlm_lock structures returned */
  sqlm_timestamp status_change_time;       /* last appl status change time    */
  _SQLOLDCHAR    appl_id[SQLM_APPLID_SZ_V8];  /* Application Id                  */
  _SQLOLDCHAR    sequence_no[SQLM_SEQ_SZ_V8]; /* appl id sequence number         */
  _SQLOLDCHAR    appl_name[SQLM_IDENT_SZ]; /* Application Name                */
  _SQLOLDCHAR    auth_id[SQLM_IDENT_SZ];   /* Authorization Id                */
  _SQLOLDCHAR    client_db_alias[SQLM_IDENT_SZ]; /* Client Database Alias     */

  sqluint32      agent_id_holding_lk;                 /* OBSOLETE */
  sqluint32      lock_object_name;                    /* OBSOLETE */
  sqluint32      lock_object_type;                    /* OBSOLETE */
  sqluint32      table_file_id;                       /* OBSOLETE */
  _SQLOLDCHAR    appl_id_holding_lk[SQLM_APPLID_SZ_V8];  /* OBSOLETE */
  _SQLOLDCHAR    sequence_no_holding_lk[SQLM_SEQ_SZ_V8]; /* OBSOLETE */
  _SQLOLDCHAR    reserved[24];                        /* OBSOLETE */

  sqluint32      lock_wait_time;           /* total wait time in millisec     */
  sqluint32      num_lockwaits;            /* # sqlm_lock_wait following      */

  char           table_name[SQLM_IDENT_SZ];           /* OBSOLETE */
  char           table_schema[SQLM_IDENT_SZ];         /* OBSOLETE */
  char           tablespace_name[SQLM_IDENT_SZ];      /* OBSOLETE */
}sqlm_appl_lock;

typedef struct sqlm_lock
{
  sqluint32      size;                   /* size of sqlm_lock                 */
  _SQLOLDCHAR    info_type;              /* Always set to SQLM_LOCK_SS        */
  unsigned char  lock_escalation;      /* Was this lock part of an escalation */
  _SQLOLDCHAR    pad[2];                 /* padding for 4-byte alignment      */
  sqluint32      table_file_id;          /* FID of table involved in lock     */
  sqluint32      lock_object_type;       /* lock object type: row, table      */
  sqluint32      lock_mode;              /* Lock mode                         */
  sqluint32      lock_status;            /* Lock status                       */
  sqluint32      lock_object_name;       /* Lock Object Name -                */
                                         /* RID or FID of lock obj            */
  _SQLOLDCHAR    reserved[32];           /* reserved for future use           */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION2  Lock Information                                    */
  /****************************************************************************/
  char           table_name[SQLM_IDENT_SZ];       /* table name               */
  char           table_schema[SQLM_IDENT_SZ];     /* table schema             */
  char           tablespace_name[SQLM_IDENT_SZ];  /* name of the tablespace   */
}sqlm_lock;

/******************************************************************************/
/* Tablespace Related Snapshot Information                                    */
/******************************************************************************/
typedef struct sqlm_tablespace_header
{
  sqluint32      size;                   /* size of sqlm_tablespace_header    */
  char           info_type;              /* Set to SQLM_TABLESPACE_HEADER_SS  */
  char           pad[3];                 /* padding for 4-byte alignment      */
  sqluint32      num_tablespaces;        /* # sqlm_tablespace structs returned*/
  sqlm_timestamp db_conn_time;           /* Time of 1st database connection   */
  sqlm_timestamp last_reset;             /* last reset date and time          */
  char           input_db_alias[SQLM_IDENT_SZ]; /* Input Database Alias       */
  char           db_name[SQLM_IDENT_SZ];        /* Database name              */
  char           db_path[SQLM_DBPATH_SZ];       /* Database Path              */
}sqlm_tablespace_header;


typedef struct sqlm_tablespace
{
  sqluint32      size;                   /* size of sqlm_table                */
  char           info_type;              /* Always set to SQLM_TABLESPACE_SS  */
  char           pad[3];                 /* padding for 4 byte alignment      */

  char           tablespace_name[SQLM_IDENT_SZ];  /* name of the tablespace   */

  sqluint32      pool_data_l_reads;      /* pool data logical reads since conn*/
  sqluint32      pool_data_p_reads;      /* pool data physical reads since con*/
  sqluint32      pool_async_data_reads;  /* asynchronous pool data reads      */
  sqluint32      pool_data_writes;       /* pool data writes since connect    */
  sqluint32      pool_async_data_writes; /* asynchronous pool data writes     */
  sqluint32      pool_index_l_reads;     /* pool index logical reads since con*/
  sqluint32      pool_index_p_reads;     /* pool index physical reads since cn*/
  sqluint32      pool_index_writes;      /* pool index writes since connect   */
  sqluint32      pool_async_index_writes; /* asynchronous pool index writes   */
  sqluint32      pool_read_time;         /* Buff pool read time since 1st conn*/
  sqluint32      pool_write_time;        /* Buff pool write time since 1st con*/
  sqluint32      pool_async_read_time;   /* asynchronous read time            */
  sqluint32      pool_async_write_time;  /* asynchronous write time           */
  sqluint32      pool_async_data_read_reqs; /* # async read requests          */

  sqluint32      direct_reads;           /* direct reads since 1st connect    */
  sqluint32      direct_writes;          /* direct writes since 1st conn      */
  sqluint32      direct_read_reqs;       /* direct read requests              */
  sqluint32      direct_write_reqs;      /* direct write requests             */
  sqluint32      direct_read_time;       /* direct read time since 1st conn   */
  sqluint32      direct_write_time;      /* direct write time since 1st conn  */

  sqluint32      files_closed;           /* files closed for tablespace       */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Buffer Pool and I/O Information                     */
  /****************************************************************************/
  sqluint32      pool_async_index_reads; /* asynchronous pool index reads     */
  sqluint32      pool_data_to_estore;    /* #pages copied from BP to estore   */
  sqluint32      pool_index_to_estore;   /* #pages copied from BP to estore   */
  sqluint32      pool_index_from_estore; /* #pages copied from estore to BP   */
  sqluint32      pool_data_from_estore;  /* #pages copied from estore to BP   */
}sqlm_tablespace;

typedef struct sqlm_rollfwd_info {
 sqluint32      size;             /* Use instead of sizeof(sqlm_rollfwd_info) */
 char           info_type;        /* Always set to SQLM_DBASE_ROLLFWD_SS      */
 char           pad[1];           /* For 2-byte alignment                     */
 sqluint16      node_number;      /* Node for which this info is about        */
 sqluint32      rf_type;          /* database or tablespace rollforward       */
 sqluint32      rf_log_num;       /* Current log being processed              */
 sqluint32      rf_status;        /* Log phase in progress                    */
 sqluint32      rf_timestamp;     /* Time of Log record currently processed,  */
                                  /* GMT time in seconds since Jan 1st, 1970  */
 sqluint32      rf_num_tspaces;   /* number of sqlm_rollfwd_ts_info following */
} sqlm_rollfwd_info;

typedef struct sqlm_rollfwd_ts_info
{
 sqluint32     size;            /* Must use to skip this record in buffer     */
 char           info_type;      /* Always set to SQLM_DBASE_ROLLFWD_TS_NAME_SS*/
 char           pad[3];         /* For 4-byte alignment                       */
 char    ts_name[SQLM_IDENT_SZ];/* Tablespace being rolled forward            */
} sqlm_rollfwd_ts_info;


/******************************************************************************/
/* Bufferpool Related Snapshot Information                                    */
/******************************************************************************/
typedef struct sqlm_bp_info {
  /* Version 1 counters */
  sqluint32      pool_data_l_reads;      /* pool data logical reads           */
  sqluint32      pool_data_p_reads;      /* pool data physical reads          */
  sqluint32      pool_data_writes;       /* pool data writes                  */
  sqluint32      pool_index_l_reads;     /* pool index logical reads          */
  sqluint32      pool_index_p_reads;     /* pool index physical reads         */
  sqluint32      pool_index_writes;      /* pool index writes                 */
  sqluint32      pool_read_time;         /* Buff pool read time               */
  sqluint32      pool_write_time;        /* Buff pool write time              */
  sqluint32      files_closed;           /* files closed for bufferpool       */

  /* Version 2 counters */
  sqluint32      pool_async_data_reads;  /* asynchronous pool data reads      */
  sqluint32      pool_async_data_writes; /* asynchronous pool data writes     */
  sqluint32      pool_async_index_writes;/* asynchronous pool index writes    */
  sqluint32      pool_async_read_time;   /* asynchronous read time            */
  sqluint32      pool_async_write_time;  /* asynchronous write time           */
  sqluint32      pool_async_data_read_reqs; /* # async read requests          */
  sqluint32      direct_reads;           /* direct reads                      */
  sqluint32      direct_writes;          /* direct writes                     */
  sqluint32      direct_read_reqs;       /* direct read requests              */
  sqluint32      direct_write_reqs;      /* direct write requests             */
  sqluint32      direct_read_time;       /* direct read time                  */
  sqluint32      direct_write_time;      /* direct write time                 */

  /* Version 3 counters */
  sqluint32      pool_async_index_reads; /* asynchronous pool index reads     */
  sqluint32      pool_data_to_estore;    /* #pages copied from BP to estore   */
  sqluint32      pool_index_to_estore;   /* #pages copied from BP to estore   */
  sqluint32      pool_index_from_estore; /* #pages copied from estore to BP   */
  sqluint32      pool_data_from_estore;  /* #pages copied from estore to BP   */

} sqlm_bp_info;

typedef struct sqlm_bufferpool
{
   sqluint32        size;         /* Use instead of sizeof(sqlm_bufferpool)   */
   char             info_type;    /* Always set to SQLM_BUFFERPOOL_SS         */
   char             pad[3];       /* For 4-byte memory alignment              */
   char             bp_name[SQLM_IDENT_SZ];        /* Bufferpool name         */
   char             input_db_alias[SQLM_IDENT_SZ]; /* Database alias          */
   char             db_name[SQLM_IDENT_SZ];        /* Database name           */
   char             db_path[SQLM_DBPATH_SZ];       /* Database Path           */
   sqlm_bp_info     bp_info;      /* total stats from all tspaces for this bp */
} sqlm_bufferpool;

/******************************************************************************/
/******************************************************************************/
/* Event Monitoring event records                                             */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* Log Stream Event Header for event monitors v6 and later                    */
/******************************************************************************/
typedef struct sqlm_event_log_stream_header
{
   sqlint32   byte_order;
   sqluint32  size;
   sqluint32  version;
}sqlm_event_log_stream_header;

/******************************************************************************/
/*  Event Monitor Log Header Record                                           */
/******************************************************************************/
typedef struct sqlm_event_log_header
{
  sqlint32       byte_order;                   /* Big Endian or Little Endian */
  sqluint32      size;                         /* Size of this record         */
  sqluint32      version;                      /* Event Monitor Version       */
  char           event_monitor_name[SQLM_IDENT_SZ];  /* Name of the Event Mon */
  sqluint16      codepage_id;                  /* Code page of Database       */
  sqluint16      country_code;                 /* Country Code of Database    */
  char           server_prdid[SQLM_IDENT_SZ];  /* Server Product Id           */
  char           server_instance_name[SQLM_IDENT_SZ]; /*instance name of DB2  */
  sqluint32      num_nodes_in_db2_instance;    /* 1 if SERIAL                 */
}sqlm_event_log_header;

/******************************************************************************/
/* Event Monitor Record Header                                                */
/******************************************************************************/
typedef struct sqlm_event_rec_header {
  /*
     All event monitor event records have size and type as their first data
     elements.  These fields can be viewed as a 'header' that has to be read
     first to determine how to read the rest of the data.
     The record size for a given event type may vary between releases of DB2.
   */
   sqluint32     size;               /* size of Event (size of entire struct) */
   sqluint32     type;               /* type of Event                         */
} sqlm_event_rec_header;

/******************************************************************************/
/*  Event Monitor Database Event Record                                       */
/******************************************************************************/
typedef struct sqlm_db_event
{
  sqluint32      size;                   /* event record size                 */
  sqluint32      event_type;             /* event type identifier             */

  /****************************************************************************/
  /* Locking Information                                                      */
  /****************************************************************************/
  sqluint32      lock_waits;             /* Lock waits                        */
  sqluint32      lock_wait_time;         /* Total time dbase waited on locks  */
  sqluint32      deadlocks;              /* Deadlocks                         */
  sqluint32      lock_escals;            /* lock escalations                  */
  sqluint32      x_lock_escals;          /* X lock escalations                */
  sqluint32      lock_timeouts;          /* Lock timeouts                     */

  /****************************************************************************/
  /* Sorting Information                                                      */
  /****************************************************************************/
  sqluint32      total_sorts;            /* number of sorts                   */
  sqluint32      total_sort_time;        /* elapsed time spent in sorts       */
  sqluint32      sort_overflows;         /* number of sort overflows          */

  /****************************************************************************/
  /* Buffer Pool and I/O Information                                          */
  /****************************************************************************/
  sqluint32      pool_data_l_reads;      /* pool data logical reads           */
  sqluint32      pool_data_p_reads;      /* pool data physical reads          */
  sqluint32      pool_async_data_reads;  /* asynchronous pool data reads      */
  sqluint32      pool_data_writes;       /* pool data writes                  */
  sqluint32      pool_async_data_writes; /* asynchronous pool data writes     */
  sqluint32      pool_index_l_reads;     /* pool index logical reads          */
  sqluint32      pool_index_p_reads;     /* pool index physicl reads          */
  sqluint32      pool_index_writes;      /* pool index page writes            */
  sqluint32      pool_async_index_writes; /* asynchronous pool index writes   */
  sqluint32      pool_read_time;         /* Buff pool read time               */
  sqluint32      pool_write_time;        /* Buff pool write time              */
  sqluint32      pool_async_read_time;   /* asynchronous read time            */
  sqluint32      pool_async_write_time;  /* asynchronous write time           */
  sqluint32      pool_async_data_read_reqs; /* # async read requests          */
  sqluint32      pool_lsn_gap_clns;      /* LSN Gap cleaner triggers          */
  sqluint32      pool_drty_pg_steal_clns;    /* dirty page steal cleaner trig.*/
  sqluint32      pool_drty_pg_thrsh_clns;    /* dirty list threshold cln trig.*/
  sqluint32      direct_reads;           /* direct reads                      */
  sqluint32      direct_writes;          /* direct writes                     */
  sqluint32      direct_read_reqs;       /* direct read requests              */
  sqluint32      direct_write_reqs;      /* direct write requests             */
  sqluint32      direct_read_time;       /* direct read time                  */
  sqluint32      direct_write_time;      /* direct write time                 */

  sqluint32      files_closed;           /* files closed                      */

  /****************************************************************************/
  /* SQL statement counts                                                     */
  /****************************************************************************/
  sqluint32      commit_sql_stmts;       /* # of Commit SQL statements        */
  sqluint32      rollback_sql_stmts;     /* # of Rollback SQL statements      */
  sqluint32      dynamic_sql_stmts;      /* # of Dynamic SQL statements       */
  sqluint32      static_sql_stmts;       /* # of Static SQL statements        */
  sqluint32      failed_sql_stmts;       /* # of Failed SQL statements        */
  sqluint32      select_sql_stmts;       /* # of SQL select statements        */
  sqluint32      ddl_sql_stmts;          /* # of data definition lang. stmts  */
  sqluint32      uid_sql_stmts;          /* # of update/insert/delete stmts   */

  /****************************************************************************/
  /* Internal counts                                                          */
  /****************************************************************************/
  sqluint32      int_auto_rebinds;       /* # of interanl auto rebinds        */
  sqluint32      int_rows_deleted;       /* # of internal rows deleted        */
  sqluint32      int_rows_updated;       /* # of internal rows updated        */
  sqluint32      int_rows_inserted;      /* # of internal rows inserted       */
  sqluint32      int_commits;            /* # of internal commits             */
  sqluint32      int_rollbacks;          /* # of internal rollbacks           */

  /****************************************************************************/
  /* Row counts                                                               */
  /****************************************************************************/
  sqluint32      rows_deleted;           /* # of Rows Deleted                 */
  sqluint32      rows_inserted;          /* # of Rows Inserted                */
  sqluint32      rows_updated;           /* # of Rows Updated                 */
  sqluint32      rows_selected;          /* # of Rows Selected                */

  /****************************************************************************/
  /* Binds/Precompiles                                                        */
  /****************************************************************************/
  sqluint32      binds_precompiles;      /* # of Binds/Precomps/Rebinds       */

  /****************************************************************************/
  /* Timestamps                                                               */
  /****************************************************************************/
  sqlm_timestamp disconn_time;            /* Time of last database disconnect */

  /****************************************************************************/
  /* Application connection counters                                          */
  /****************************************************************************/
  sqluint32      total_cons;             /* Total Connects                    */
  sqluint32      connections_top;        /* High water mark for connections   */

  /****************************************************************************/
  /* Database memory pool high water marks                                    */
  /****************************************************************************/
  sqluint32      db_heap_top;            /* High water mark for dbheap        */


  /****************************************************************************/
  /* Logging Information                                                      */
  /****************************************************************************/
  sqluint32      sec_log_used_top;       /* Maximum secondary log space used  */
  sqluint32      tot_log_used_top;       /* Maximum total log space used      */
  sqluint32      log_reads;              /* # of log pages read               */
  sqluint32      log_writes;             /* # of log pages written            */

  /****************************************************************************/
  /* Package Cache Information                                                */
  /****************************************************************************/
  sqluint32      pkg_cache_lookups;     /* # of section lookups               */
  sqluint32      pkg_cache_inserts;     /* # of sections inserted into cache  */

  /****************************************************************************/
  /* Catalog Cache Information                                                */
  /****************************************************************************/
  sqluint32      cat_cache_lookups;     /* # of table descriptor lookups      */
  sqluint32      cat_cache_inserts;     /* # of table descriptors inserted    */
  sqluint32      cat_cache_overflows;   /* # of catalog cache overflows       */
  sqluint32      cat_cache_heap_full;   /* # of overflows due to db heap full */

  /****************************************************************************/
  /* Application Section Retrieval Information                                */
  /****************************************************************************/
  sqluint32      appl_section_lookups;  /* # of section lookups               */
  sqluint32      appl_section_inserts;  /* # of sections inserted             */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Buffer Pool and I/O Information                     */
  /****************************************************************************/
  sqluint32      pool_async_index_reads; /* asynchronous pool index reads     */
  sqluint32      pool_data_to_estore;    /* #pages copied from BP to estore   */
  sqluint32      pool_index_to_estore;   /* #pages copied from BP to estore   */
  sqluint32      pool_index_from_estore; /* #pages copied from estore to BP   */
  sqluint32      pool_data_from_estore;  /* #pages copied from estore to BP   */
  sqluint32      prefetch_wait_time;    /* Time spent waiting for prefetch(ms)*/

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Server details                                      */
  /****************************************************************************/
  sqluint32     catalog_node;            /* catalog node number               */
  sqluint16      server_platform;        /* OS on which the db manager runs   */
  char catalog_node_name[SQLM_LG_IDENT_SZ];/* Catalog network node name       */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5_2 Hash join information                              */
  /****************************************************************************/
  sqluint32      total_hash_joins;          /* number of hash joins           */
  sqluint32      total_hash_loops;          /* number of hash loops           */
  sqluint32      hash_join_overflows;       /* number of hash join overflows  */
  sqluint32      hash_join_small_overflows; /* small hash join overflows      */
}sqlm_db_event;


/******************************************************************************/
/*  Event Monitor Connection Event Record                                     */
/******************************************************************************/
typedef struct sqlm_conn_event
{
  sqluint32      size;                   /* event record size                 */
  sqluint32      event_type;             /* event type identifier             */
  char           appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  char           sequence_no[SQLM_SEQ_SZ_V8];   /* application id sequence number*/

  /****************************************************************************/
  /* Locking Information                                                      */
  /****************************************************************************/
  sqluint32      lock_waits;             /* Lock waits since appl. connect    */
  sqluint32      lock_wait_time;         /* total time waited on locks in ms  */
  sqluint32      lock_escals;            /* Lock Escalations since appl conn. */
  sqluint32      x_lock_escals;          /* X lock escals since appl connect  */
  sqluint32      deadlocks;              /* Deadlocks since appl. connect     */
  sqluint32      lock_timeouts;          /* Lock timeouts since 1st db connect*/

  /****************************************************************************/
  /* Sorting Information                                                      */
  /****************************************************************************/
  sqluint32      total_sorts;            /* Total Sorts since connect         */
  sqluint32      total_sort_time;        /* elapsed time spent in sorts       */
  sqluint32      sort_overflows;         /* number of sort overflows          */

  /****************************************************************************/
  /* Buffer Pool and I/O Information                                          */
  /****************************************************************************/
  sqluint32      pool_data_l_reads;      /* pool data logical reads since conn*/
  sqluint32      pool_data_p_reads;      /* pool data physical reads since con*/
  sqluint32      pool_data_writes;       /* pool data writes since 1st connect*/
  sqluint32      pool_index_l_reads;     /* pool indx logical reads since conn*/
  sqluint32      pool_index_p_reads;     /* pool indx physical reads since con*/
  sqluint32      pool_index_writes;      /* pool indx writes since 1st connect*/
  sqluint32      pool_read_time;         /* Buff pool read time since 1st conn*/
  sqluint32      pool_write_time;        /* Buff pool write time since 1st con*/
  sqluint32      direct_reads;           /* direct reads since connect        */
  sqluint32      direct_writes;          /* direct writes since connect       */
  sqluint32      direct_read_reqs;       /* direct read requests since conn   */
  sqluint32      direct_write_reqs;      /* direct write requests since conn  */
  sqluint32      direct_read_time;       /* direct read time since connect    */
  sqluint32      direct_write_time;      /* direct write time since connect   */

  /****************************************************************************/
  /* SQL statement counts                                                     */
  /****************************************************************************/
  sqluint32      commit_sql_stmts;       /* # of Commit SQL stmts since conn  */
  sqluint32      rollback_sql_stmts;     /* # of Rollback SQL stmts since conn*/
  sqluint32      dynamic_sql_stmts;      /* # of Dynamic SQL stmts since conn */
  sqluint32      static_sql_stmts;       /* # of Static SQL stmts since conn  */
  sqluint32      failed_sql_stmts;       /* # of Failed SQL stmts since conn  */
  sqluint32      select_sql_stmts;       /* # of SQL select stmts since conn  */
  sqluint32      ddl_sql_stmts;          /* # of data definition lang. stmts  */
  sqluint32      uid_sql_stmts;          /* # of update/insert/delete stmts   */

  /****************************************************************************/
  /* Internal counts                                                          */
  /****************************************************************************/
  sqluint32      int_auto_rebinds;       /* # of Auto Rebinds since connect   */
  sqluint32      int_rows_deleted;       /* # of internal deletes since conn  */
  sqluint32      int_rows_updated;       /* # of internal updates since conn  */
  sqluint32      int_rows_inserted;      /* # of internal inserts since conn  */
  sqluint32      int_commits;            /* # of int. Commits since 1st conn  */
  sqluint32      int_rollbacks;          /* # of int. Rollbacks since 1st conn*/
  sqluint32      int_deadlock_rollbacks; /* # of Rollbacks due to deadlock    */
                                         /*      since 1st connect            */

  /****************************************************************************/
  /* Row counts                                                               */
  /****************************************************************************/
  sqluint32      rows_deleted;           /* # of Rows Deleted since connect   */
  sqluint32      rows_inserted;          /* # of Rows Inserted since connect  */
  sqluint32      rows_updated;           /* # of Rows Updated since connect   */
  sqluint32      rows_selected;          /* # of Rows Selected since connect  */
  sqluint32      rows_read;              /* # of Rows read since connect      */
  sqluint32      rows_written;           /* # of Rows written since connect   */

  /****************************************************************************/
  /* Binds/Precompiles                                                        */
  /****************************************************************************/
  sqluint32      binds_precompiles;      /* # of Binds/Precomps/Rebinds       */

  /****************************************************************************/
  /* Blocking Cursor Information                                              */
  /****************************************************************************/
  sqluint32      rej_curs_blk;          /* Rejected block cursor requests     */
  sqluint32      acc_curs_blk;          /* Accepted block cursor requests     */

  /****************************************************************************/
  /* Timestamps                                                               */
  /****************************************************************************/
  sqlm_timestamp  disconn_time;         /* Disconnection  date/time           */

  /****************************************************************************/
  /* Agents activity                                                          */
  /****************************************************************************/
  sqlm_time       user_cpu_time;    /* Total user CPU time of appl agents     */
  sqlm_time       system_cpu_time;  /* Total system CPU time of appl agents   */

  /****************************************************************************/
  /* Package Cache Information                                                */
  /****************************************************************************/
  sqluint32      pkg_cache_lookups;     /* # of section lookups               */
  sqluint32      pkg_cache_inserts;     /* # of sections inserted into cache  */

  /****************************************************************************/
  /* Catalog Cache Information                                                */
  /****************************************************************************/
  sqluint32      cat_cache_overflows;   /* # of catalog cache overflows       */
  sqluint32      cat_cache_heap_full;   /* # of overflows due to db heap full */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5                                                      */
  /****************************************************************************/
  sqluint32      appl_section_lookups;  /* # of section lookups               */
  sqluint32      appl_section_inserts;  /* # of sections inserted             */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Buffer Pool and I/O Information                     */
  /****************************************************************************/
  sqluint32      prefetch_wait_time;     /* Time waited for prefetch (ms)     */
  sqluint32      pool_data_to_estore;    /* #pages copied from BP to estore   */
  sqluint32      pool_index_to_estore;   /* #pages copied from BP to estore   */
  sqluint32      pool_index_from_estore; /* #pages copied from estore to BP   */
  sqluint32      pool_data_from_estore;  /* #pages copied from estore to BP   */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5                                                      */
  /****************************************************************************/
  sqluint32      authority_lvl;          /* user authorizations               */
  sqluint32      coord_node;             /* coordinating node number          */
  sqlint32       appl_priority;          /* priority at which appl agents work*/
  sqluint32      appl_priority_type;     /* dynamic or static                 */
  sqluint32      agent_id;               /* Application handle                */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5_2 Hash join information                              */
  /****************************************************************************/
  sqluint32      total_hash_joins;          /* number of hash joins           */
  sqluint32      total_hash_loops;          /* number of hash loops           */
  sqluint32      hash_join_overflows;       /* number of hash join overflows  */
  sqluint32      hash_join_small_overflows; /* small hash join overflows      */
  sqluint32      cat_cache_inserts;     /* # of catalog cache inserts         */
  sqluint32      cat_cache_lookups;     /* # of catalog cache overflows       */
}sqlm_conn_event;


/******************************************************************************/
/*  Event Monitor Table Event Record                                          */
/******************************************************************************/
typedef struct sqlm_table_event
{
  sqluint32      size;                   /* event record size                 */
  sqluint32      event_type;             /* event type identifier             */
  char           table_name[SQLM_IDENT_SZ];     /* the name of the table      */
  char           table_schema[SQLM_IDENT_SZ];   /* the name of the table      */
  sqluint32      table_type;             /* table type                        */
  sqluint32      rows_written;           /* number of changes to the table    */
  sqluint32      rows_read;              /* number of reads from the table    */
  sqluint32      overflow_accesses;      /* no. of accesses to overflow rec   */
  sqlm_timestamp table_event_time;       /* Table Event Date and Time         */
  sqluint32      page_reorgs;            /* no. of reorgs for the table       */

}sqlm_table_event;

/******************************************************************************/
/*  Event Monitor Statement record                                            */
/******************************************************************************/
/* NOTE: Text follows the record, its length is rounded up to a 4 bytes       */
/*       boundary, and the text is padded with blanks. It is *NOT* null       */
/*       terminated.  For example:                                            */
/*          +-------------------------+----------------------+                */
/*          |sqlm_stmt_event          |"SELECT * FROM T18   "|                */
/*          |  size:             352  |                      |                */
/*          |  stmt_length:       20  |                      |                */
/*          |  stmt_text_offset: 332  |                      |                */
/*          +-------------------------+----------------------+                */
/*----------------------------------------------------------------------------*/
typedef struct sqlm_stmt_event
{
  sqluint32      size;                   /* event record size *INCLUDING*     */
                                         /* dynamic SQL statement text        */
  sqluint32      event_type;             /* Always set to SQLM_EVENT_STMT     */
  char           appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  char           sequence_no[SQLM_SEQ_SZ_V8];   /* Application Id sequence number*/
  sqluint32      stmt_type;              /* type of stmt: Dynamic or static   */
  sqluint32      operation;              /* Statement Operation               */
  sqluint32      fetch_count;            /* Count of fetches                  */
  sqluint32      section_number;         /* Section Number                    */
  sqlm_timestamp start_time;             /* SQL statement operation start time*/
  sqlm_timestamp stop_time;              /* SQL statement operation stop time */
  char           cursor_name[SQLM_IDENT_SZ];  /* sql stmt.cursor name         */
  char           creator[SQLM_IDENT_SZ];      /* auth id for precompile       */
  char           package_name[SQLM_OLD_PACKAGE_NAME_SZ]; /* Package name      */
  sqlm_time      user_cpu_time;         /* Total user CPU time of statement   */
  sqlm_time      system_cpu_time;       /* Total system CPU time of statement */
  sqluint32      total_sorts;           /* Total number of sorts for this stmt*/
  sqluint32      total_sort_time;       /* Total sort time for this statement */
  sqluint32      sort_overflows;        /* # of sort overflows for this stmt  */
  sqluint32      rows_read;             /* # of rows read by this statement   */
  sqluint32      rows_written;          /* # of rows upd/ins/del for this stmt*/
  sqluint32      int_rows_deleted;      /* # of internal deletes by the stmt  */
  sqluint32      int_rows_updated;      /* # of internal updates by the stmt  */
  sqluint32      int_rows_inserted;     /* # of internal inserts by the stmt  */
  struct sqlca   sqlca;                 /* sqlca from statement               */
  sqluint32      agent_id;              /* Application handle                 */
  sqluint32      agents_top;            /* # of agents created for statement  */
  sqluint16      stmt_length;           /* length of SQL text, 0 if none. It  */
                                        /* is only returned for dynamic SQL   */
  sqluint16      stmt_text_offset;      /* offset from sqlm_stmt_event start  */
}sqlm_stmt_event;

/* The following event is only logged by VERSION 2 servers                    */
/* Starting with UDB V5, the text became part of the sqlm_stmt_event          */
typedef struct sqlm_stmttext_event /* OBSOLETE */
{
  sqluint32      size;                   /* event record size                 */
                                         /* INCLUDES statement text           */
  sqluint32      event_type;             /* Set to SQLM_EVENT_STMTTEXT        */
  char           appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  char           sequence_no[SQLM_SEQ_SZ_V8];   /* application id sequence number*/
  char           creator[SQLM_IDENT_SZ];      /* auth id for precompile       */
  char           package_name[SQLM_OLD_PACKAGE_NAME_SZ]; /* Package name      */
  sqluint32      section_number;         /* Section Number                    */
  sqluint32      stmt_length;           /* length of SQL statement following  */
  char           stmt_text[1];          /* dynamic sql statement text         */
}sqlm_stmttext_event; /* OBSOLETE */

typedef struct sqlm_subsection_event
{
  sqluint32      size;              /* event record size                      */
  sqluint32      event_type;        /* Set to SQLM_EVENT_SUBSECTION           */

  sqluint32      agent_id;          /* Application handle                     */
  sqluint16      ss_number;         /* Subsection number                      */
  sqluint16      ss_node_number;    /* Node where the subsection was executed */

  /* Execution stats */
  sqluint32      ss_exec_time;      /* total (elapsed) Execution time in ms   */
  sqlm_time      ss_usr_cpu_time;   /* total user CPU time (sec.microsec)     */
  sqlm_time      ss_sys_cpu_time;   /* total system CPU time (sec.microsec)   */

  /* Tablequeue information */
  sqluint32      tq_tot_send_spills;/* total # of buffers overflowed to a     */
                                    /*  temp table when sending data on a tq  */
  sqluint32      tq_max_send_spills;/* maximum # of tq buffers overflowed     */
  sqluint32      tq_rows_read;      /* Total # rows received on tablequeues   */
  sqluint32      tq_rows_written;   /* Total # rows sent on tablequeues       */
  sqluint16      num_agents;        /* # agents that were executing this ss.  */
  char           pad[2];            /* Explicit pad bytes                     */
}sqlm_subsection_event;

/******************************************************************************/
/*  Event Monitor Transaction Event Record                                    */
/******************************************************************************/
typedef struct sqlm_xaction_event
{
  sqluint32      size;                   /* event record size                 */
  sqluint32      event_type;                 /* event type identifier         */
  char           appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  char           sequence_no[SQLM_SEQ_SZ_V8];   /* application id sequence number*/
  sqluint32      log_space_used;        /* Log space used in transaction      */
  sqluint32      status;                /* transaction completion status      */
  sqluint32      lock_wait_time;        /* transaction lock wait time (ms)    */
  sqluint32      locks_held_top;        /* max locks held in transaction      */
  sqluint32      lock_escals;           /* # of lock escalation in transaction*/
  sqluint32      x_lock_escals;         /* # of x lock escals in transaction  */
  sqluint32      rows_read;             /* # of rows read by this transaction */
  sqluint32      rows_written;          /* # of rows upd/ins/del for this xact*/
  sqlm_time      user_cpu_time;         /* Total user CPU time of transaction */
  sqlm_time      system_cpu_time;       /* Total system CPU time of xaction   */
  sqlm_timestamp prev_stop_time;        /* prev commit or rollback time       */
  sqlm_timestamp start_time;            /* time trans exec started            */
  sqlm_timestamp stop_time;             /* trans stop time                    */
  sqluint32      agent_id;              /* Application handle                 */
}sqlm_xaction_event;


/******************************************************************************/
/*  Event Monitor Deadlock and Deadlocked Connection Event Records            */
/******************************************************************************/
typedef struct sqlm_deadlock_event
{
  sqluint32      size;                       /* event record size             */
  sqluint32      event_type;                 /* event type identifier         */
  sqluint32      dl_conns;                   /* number of conns deadlocked    */
  sqlm_timestamp start_time;                 /* Time when deadlock detected   */
  char           rolled_back_appl_id[SQLM_APPLID_SZ_V8]; /* victim's appl id     */
  char           rolled_back_sequence_no[SQLM_SEQ_SZ_V8]; /* victim's seq no.    */
  sqluint32      rolled_back_agent_id;       /* Application handle            */
}sqlm_deadlock_event;

typedef struct sqlm_dlconn_event
{
  sqluint32      size;                       /* event record size             */
  sqluint32      event_type;                 /* event type identifier         */
  char           appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  char           sequence_no[SQLM_SEQ_SZ_V8];   /* application id sequence number*/
  char           appl_id_holding_lk[SQLM_APPLID_SZ_V8]; /* id of appl holding lk */
  char           sequence_no_holding_lk[SQLM_SEQ_SZ_V8]; /* seq no. holding lock */
  char           table_name[SQLM_IDENT_SZ];   /* name of tb of lock waited on */
  char           table_schema[SQLM_IDENT_SZ]; /* table schema of lk waited on */
  char           tablespace_name[SQLM_IDENT_SZ];  /* name of the tablespace   */
  sqluint32      lock_mode;              /* Mode of Lock waited on            */
  sqluint32      lock_object_type;       /* Lock Obj type for lock waited on  */
  sqluint32      lock_object_name;       /* Waited On lock obj name           */
  sqlm_timestamp lock_wait_start_time;   /* Time when lock wait started       */
  sqlm_timestamp start_time;             /* Time when deadlock detected       */
  sqluint32      lock_node;              /* Node on which app waited for lock */
  sqluint32      agent_id;               /* Application handle                */
  unsigned char  lock_escalation;      /* Was this lock part of an escalation */
}sqlm_dlconn_event;

/******************************************************************************/
/*  Event Monitor Tablespace Event Record                                     */
/******************************************************************************/
typedef struct sqlm_tablespace_event
{
  sqluint32      size;                   /* event record size                 */
  sqluint32      event_type;             /* event type identifier             */

  char           tablespace_name[SQLM_IDENT_SZ];  /* name of tablespace       */
  sqluint32      pool_data_l_reads;      /* pool data logical reads since conn*/
  sqluint32      pool_data_p_reads;      /* pool data physical reads since con*/
  sqluint32      pool_async_data_reads;  /* asynchronous pool data reads      */
  sqluint32      pool_data_writes;       /* pool data writes since connect    */
  sqluint32      pool_async_data_writes; /* asynchronous pool data writes     */
  sqluint32      pool_index_l_reads;     /* pool index logical reads since con*/
  sqluint32      pool_index_p_reads;     /* pool index physical reads since cn*/
  sqluint32      pool_index_writes;      /* pool index writes since connect   */
  sqluint32      pool_async_index_writes; /* asynchronous pool index writes   */
  sqluint32      pool_read_time;         /* Buff pool read time since 1st conn*/
  sqluint32      pool_write_time;        /* Buff pool write time since 1st con*/
  sqluint32      pool_async_read_time;   /* asynchronous read time            */
  sqluint32      pool_async_write_time;  /* asynchronous write time           */
  sqluint32      pool_async_data_read_reqs; /* # async read requests          */

  sqluint32      direct_reads;           /* direct reads since 1st connect    */
  sqluint32      direct_writes;          /* direct writes since 1st conn      */
  sqluint32      direct_read_reqs;       /* direct read requests              */
  sqluint32      direct_write_reqs;      /* direct write requests             */
  sqluint32      direct_read_time;       /* direct read time since 1st conn   */
  sqluint32      direct_write_time;      /* direct write time since 1st conn  */

  sqluint32      files_closed;           /* files closed since first db conn  */
  sqlm_timestamp ts_event_time;          /* Tablespace event date and time    */

  /****************************************************************************/
  /* SQLM_DBMON_VERSION5  Buffer Pool and I/O Information                     */
  /****************************************************************************/
  sqluint32      pool_async_index_reads; /* asynchronous pool index reads     */
  sqluint32      pool_data_to_estore;    /* #pages copied from BP to estore   */
  sqluint32      pool_index_to_estore;   /* #pages copied from BP to estore   */
  sqluint32      pool_index_from_estore; /* #pages copied from estore to BP   */
  sqluint32      pool_data_from_estore;  /* #pages copied from estore to BP   */
}sqlm_tablespace_event;


/******************************************************************************/
/*  Event Monitor Database Header Event Record                                */
/******************************************************************************/
typedef struct sqlm_dbheader_event
{
  sqluint32      size;                    /* event record size                */
  sqluint32      event_type;              /* event type identifier            */
  char           db_name[SQLM_IDENT_SZ];  /* Database name                    */
  char           db_path[SQLM_DBPATH_SZ]; /* Database Path                    */
  sqlm_timestamp conn_time;               /* Time of 1st database connection  */

}sqlm_dbheader_event;


/******************************************************************************/
/*  Event Monitor Start Event Record                                          */
/******************************************************************************/
typedef struct sqlm_evmon_start_event
{
  sqluint32      size;                    /* event record size                */
  sqluint32      event_type;              /* event type identifier            */
  sqlm_timestamp start_time;              /* Time event monitor started       */
} sqlm_evmon_start_event;

/******************************************************************************/
/*  Event Monitor Connection Header Event Record                              */
/******************************************************************************/
typedef struct sqlm_connheader_event
{
  sqluint32      size;                       /* event record size             */
  sqluint32      event_type;                 /* event type identifier         */
  char           appl_id[SQLM_APPLID_SZ_V8];    /* Application Id                */
  char           sequence_no[SQLM_SEQ_SZ_V8];   /* application id sequence number*/
  char           corr_token[SQLM_APPLID_SZ_V8]; /* DRDA AS Correlation Token     */
  char           appl_name[SQLM_IDENT_SZ];   /* Application Program Name      */
  char           auth_id[SQLM_IDENT_SZ];     /* Authorization Id              */
  char           execution_id[SQLM_IDENT_SZ]; /* Login ID                     */
  char           client_nname[SQLM_IDENT_SZ]; /* Config NNAME of client       */
  char           client_prdid[SQLM_IDENT_SZ]; /* product/version on client    */
  char           client_db_alias[SQLM_IDENT_SZ]; /* Client Database Alias     */
  sqluint32      client_pid;                 /* PID of client                 */
  sqluint32      agent_id;                   /* Application handle            */
  sqluint16      codepage_id;                /* codepage at client node       */
  sqluint16      country_code;               /* country code of client app    */
  sqluint16      client_platform;            /* platform of client app        */
  sqluint16      client_protocol;            /* Comms protocol of client      */
  sqlm_timestamp conn_time;                  /* Connect start date/time       */
  sqluint16      node_number;                /* Node number conn was establ.  */
  char           pad[2];                     /* for 4 bytes memory alignment  */
} sqlm_connheader_event;

/******************************************************************************/
/*  Event Monitor Overflow Event Record                                       */
/******************************************************************************/
typedef struct sqlm_overflow_event
{
  sqluint32      size;                       /* event record size             */
  sqluint32      event_type;                 /* event type identifier         */
  sqluint32      count;                      /* The number of overflows       */
  sqlm_timestamp first_overflow_time;        /* The time of the first overflow*/
  sqlm_timestamp last_overflow_time;         /* The time of the last overflow */
  sqluint16      node_number;                /* Node on which overflow occured*/
  char           pad[2];                     /* padding for word alignment    */
} sqlm_overflow_event;

/******************************************************************************/
/*  Event Monitor Bufferpool Event Record                                     */
/******************************************************************************/
typedef struct sqlm_bufferpool_event
{
  sqluint32      size;        /* Use instead of sizeof(sqlm_bufferpool_event) */
  sqluint32      event_type;  /* always set to SQLM_EVENT_BUFFERPOOL          */
  sqlm_timestamp event_time;  /* GMT time in seconds.microsec since 01/01/70  */
  char           bp_name[SQLM_IDENT_SZ];           /* Bufferpool name         */
  char           db_name[SQLM_IDENT_SZ];           /* Database name           */
  char           db_path[SQLM_DBPATH_SZ];          /* Database Path           */
  sqlm_bp_info   bp_info;     /* total stats from all tspaces for this bp     */
} sqlm_bufferpool_event;

/******************************************************************************/
/* VERSION 1 - Data structure sizes  - *****OBSOLETE***** -                   */
/* ****DON'T USE THESE CONSTANTS**** THEY ARE PROVIDED FOR COMPATIBILITY ONLY */
/******************************************************************************/
#define SQLM_APPLINFO_SZ        492    /* size of V1 sqlm_applinfo struct     */
#define SQLM_DB2_SZ             100    /* size of V1 sqlm_db2 structure       */
#define SQLM_DBASE_SZ           548    /* size of V1 sqlm_dbase structure     */
#define SQLM_TABLE_HEADER_SZ    356    /* size of V1 sqlm_table_header struct */
#define SQLM_TABLE_SZ           60     /* size of V1 sqlm_table structure     */
#define SQLM_APPL_SZ            880    /* size of V1 sqlm_appl structure      */
#define SQLM_DBASE_LOCK_SZ      352    /* size of V1 sqlm_dbase_lock struct   */
#define SQLM_APPL_LOCK_SZ       216    /* size of V1 sqlm_appl_lock struct    */
#define SQLM_LOCK_SZ            60     /* size of V1 sqlm_lock structure      */
#define SQLM_COLLECTED_SZ       232    /* size of V1 sqlm_collected structure */
#define SQLM_DCS_APPLINFO_SZ    260    /* size of V1 sqlm_dcs_applinfo struct */
#define SQLM_TIMESTAMP_SZ       sizeof(sqlm_timestamp)

/******************************************************************************/
/* Database Monitor APIs                                                      */
/******************************************************************************/

/* Set or query Database Monitor switch settings */
int SQL_API_FN sqlmon(sqluint32            version,       /* Version Id       */
                      _SQLOLDCHAR          *reserved,     /* reserved         */
                      sqlm_recording_group group_states[],
                                      /* monitor switches and current states  */
                      struct sqlca         *sqlca         /* sqlca            */
                     );

/* Take a Snapshot of some Database System Monitor data */
int SQL_API_FN sqlmonss(sqluint32         version,        /* Version id       */
                        _SQLOLDCHAR       *reserved,      /* reserved         */
                        sqlma             *sqlma_ptr,     /* monitoring area  */
                        sqluint32         buffer_length,  /* buffer length    */
                        void              *buffer_area,   /* buffer area      */
                        sqlm_collected    *collected,     /* num collected    */
                        struct sqlca      *sqlca          /* sqlca            */
                       );

/* Estimate the buffer size that user need to allocate for sqlmonss */
int SQL_API_FN sqlmonsz(sqluint32             version,    /* Version id       */
                        _SQLOLDCHAR           *reserved,  /* reserved         */
                        sqlma                 *sqlma_ptr, /* sqlma pointer    */
                        sqluint32             *buff_size, /* est. buffer sz   */
                        struct sqlca          *sqlca      /* sqlca structure  */
                       );

/* Re-initialize Database System Monitor data */
int SQL_API_FN sqlmrset(sqluint32              version,   /* Version Id       */
                        _SQLOLDCHAR            *reserved, /* reserved         */
                        sqluint32              reset_all, /* reset db or all  */
                        _SQLOLDCHAR            *db_alias, /* ptr to db_alias  */
                        struct sqlca           *sqlca     /* sqlca            */
                       );

/******************************************************************************/
/* Database Monitor Generic APIs                                              */
/******************************************************************************/

/* Generic Database Monitor Switch API  */
int SQL_API_FN sqlgmon
   (
     sqluint32              reserved_lgth,   /* length of reserved field      */
     struct   sqlca         *sqlca,          /* pointer to sqlca              */
     sqlm_recording_group   group_states[],  /* ptr to returned states        */

     _SQLOLDCHAR            *reserved,       /* reserved for future use       */
     sqluint32              version          /* Version id                    */
   );


/* Generic Database Monitor Snapshot API */
int SQL_API_FN sqlgmnss
   (
     sqluint32               reserved_lgth,  /* length of reserved field      */
     struct   sqlca          *sqlca,         /* pointer to sqlca              */
     sqlm_collected          *collected,     /* pointer to # collected        */
     void                    *buffer_area,   /* pointer to buffer area        */
     sqluint32               buffer_length,  /* length of buffer              */
     sqlma                   *sqlma_ptr,     /* pointer to monitor area       */
     _SQLOLDCHAR             *reserved,      /* reserved for future use       */
     sqluint32               version         /* Version id                    */
   );


/* Generic Database Monitor Estimate Buffer Size API */
int SQL_API_FN sqlgmnsz
   (
     sqluint32               reserved_lgth,  /* length of reserved field      */
     struct   sqlca          *sqlca,         /* pointer to sqlca              */
     sqluint32               *buff_size,     /* length of buffer              */
     sqlma                   *sqlma_ptr,     /* pointer to sqlma              */
     _SQLOLDCHAR             *reserved,      /* reserved for future use       */
     sqluint32               version         /* Version id                    */
   );



/* Generic Database Monitor Reset API */
int SQL_API_FN sqlgmrst
   (
     sqluint16                dbnamel,       /* length of database            */
     sqluint32                reserved_lgth, /* length of reserved field      */
     struct   sqlca           *sqlca,        /* pointer to sqlca              */
     _SQLOLDCHAR              *db_alias,     /* database alias                */
     sqluint32                reset_all,     /* reset db or all info          */
     _SQLOLDCHAR              *reserved,     /* reserved for future use       */
     sqluint32                version        /* Version id                    */
   );

#if defined(DB2NT)
#pragma pack()
#elif defined(DB2AIX)
#pragma options align=reset
#endif

#ifdef __cplusplus
}
#endif
#endif  /* SQL_H_SQLMON */
