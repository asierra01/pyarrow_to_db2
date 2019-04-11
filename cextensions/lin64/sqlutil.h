/******************************************************************************
** 
** Source File Name: SQLUTIL
** 
** (C) COPYRIGHT International Business Machines Corp. 1987, 2004
** All Rights Reserved
** Licensed Materials - Property of IBM
** 
** US Government Users Restricted Rights - Use, duplication or
** disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
** 
** Function = Include File defining:
**              Utility / Configuration Commands - Constants
**              Utility / Configuration Commands - Data Structures
**              Utility / Configuration Commands - Function Prototypes
**              Utility / Configuration Commands - Labels for SQLCODES
** 
** Operating System:LINUX
** 
*******************************************************************************/
#ifndef SQL_H_SQLUTIL
#define SQL_H_SQLUTIL

#ifdef __cplusplus
extern "C" {
#endif

/* Note: _SQLOLDCHAR defaults to 'char'.  See sqlsystm.h for details.         */

/* Note: When adding a new load warning make sure to update the clp code      */
/*       determining whether prompting is required (clpfcmd1.C).              */

#include "sql.h"                       /* Includes sqlca.h & sqlsystm.h */

/* The device_type define in /usr/include/term.h can conflict with the        */
/* sqluhinfo field.                                                           */
#ifdef device_type
#undef device_type
#endif

/* Interface Parameters/Structures/Return Codes                               */

/* Parameters for Rollforward caller action                                   */
#define SQLUM_ROLLFWD          1       /* Roll forward to requested point     */
#define SQLUM_STOP             2       /* End roll-forward recovery           */
#define SQLUM_COMPLETE         2       /* End roll-forward recovery           */
#define SQLUM_ROLLFWD_STOP     3       /* Roll forward to requested point     */
                                       /* and end roll-forward recovery       */
#define SQLUM_ROLLFWD_COMPLETE 3       /* Roll forward to requested point     */
                                       /* and end roll-forward recovery       */
#define SQLUM_QUERY            4       /* Query nextArcFile, firstDeleteArc,  */
                                       /* lastDeleteArc, lastCommitTime       */
#define SQLUM_CANCEL           8       /* Cancel current rollforward          */
#define SQLUM_PARM_CHECK       10      /* Parameter check                     */
#define SQLUM_LOADREC_CONTINUE 11      /* Continue load recovery.             */
#define SQLUM_LOADREC_TERMINATE 12     /* Terminate load recovery.            */
#define SQLUM_LOADREC_DEVICE_TERMINATE 13 /* Terminate device.Caller action   */
                                       /* codes 31 - 50 reserved for          */
                                       /* internal use.                       */

/* Constants used for Rollforward                                             */
#define SQLUM_INFINITY_TIMESTAMP "9999-12-31-23.59.59.999999" /* Roll         */
                                       /* forward until STOP specified        */
#define SQLUM_ARCHIVE_FILE_LEN 12      /* Length of Archive File name         */
#define SQLUM_TIMESTAMP_LEN    26      /* Length of ISO format Timestamp      */

/* Roll forward input version values                                          */
#define SQLUM_RFWD_VERSION     5       /* current rollforward input version   */

/* Roll forward allNodeFlag values                                            */
#define SQLURF_NODE_LIST       0       /* submit to all nodes in the node     */
                                       /* list                                */
#define SQLURF_ALL_NODES       1       /* submit to all nodes in the          */
                                       /* nodeconfiguration file              */
#define SQLURF_ALL_EXCEPT      2       /* submit to all nodes except the      */
                                       /* onesspecified by the nodelist       */
                                       /* parameter                           */
#define SQLURF_CAT_NODE_ONLY   3       /* submit to catalog node only         */

/* Roll forward query status codes                                            */
#define SQLURFQ_NOT_AVAILABLE  0       /* cannot query node                   */
#define SQLURFQ_NOT_RFW_PENDING 1      /* rollforward is not pending          */
#define SQLURFQ_DB_RFW_PENDING 2       /* database rollforward pending        */
#define SQLURFQ_TBL_RFW_PENDING 3      /* tablespace rollforward pending      */
#define SQLURFQ_DB_RFW_IN_PROGRESS 4   /* database rollforward in progress    */
#define SQLURFQ_TBL_RFW_IN_PROGRESS 5  /* tablespace rollforward in progress  */
#define SQLURFQ_DB_RFW_STOPPING 6      /* database rollforward processing     */
                                       /* STOP                                */
#define SQLURFQ_TBL_RFW_STOPPING 7     /* tablespace rollforward processing   */
                                       /* STOP                                */

/* Rollforward connect mode                                                   */
#define SQLUM_OFFLINE          0x0     /* Offline rollforward mode            */
#define SQLUM_ONLINE           0x1     /* Online rollforward mode             */

/* Backup mode                                                                */
#define SQLUB_OFFLINE          0x0     /* Offline backup mode                 */
#define SQLUB_ONLINE           0x1     /* Online backup mode                  */
#define SQLUB_SPLITMIRROR      0x10    /* Split mirror backup                 */
#define SQLUB_MODE_MASK        0xf     /* Backup modes                        */
#define SQLUB_OPT_MASK         0x0     /* Backup options                      */

/* Backup type                                                                */
#define SQLUB_DB               0x0
#define SQLUB_FULL             0x0
#define SQLUB_TABLESPACE       0x3
#define SQLUB_INCREMENTAL      0x10
#define SQLUB_DELTA            0x30
#define SQLUB_INC_LEVEL_MASK   0xff00

/* Backup type masks                                                          */
#define SQLUB_TYPE_MASK        0xf     /* Determines if full/tbsp bckp.       */
#define SQLUB_INCR_MASK        0xf0    /* Determines if incr/delta bckp.      */

/* Backup calling action values                                               */
#define SQLUB_BACKUP           0       /* initial call                        */
#define SQLUB_CONTINUE         1       /* Subsequent call                     */
#define SQLUB_TERMINATE        2       /* Terminating call                    */
#define SQLUB_NOINTERRUPT      3       /* Initial call to run without         */
                                       /* prompting                           */
#define SQLUB_DEVICE_TERMINATE 9       /* End media device.                   */
#define SQLUB_PARM_CHECK       10      /* for parameter check and             */
                                       /* initialization.                     */
#define SQLUB_PARM_CHECK_INIT_AND_WAIT 10 /* for parameter check and          */
                                       /* initialization.                     */
#define SQLUB_PARM_CHECK_ONLY  11      /* for parameter checking only.        */

/* Restore rollforward mode                                                   */
#define SQLUD_ROLLFWD          0x0
#define SQLUD_NOROLLFWD        0x1

/* Restore mode                                                               */
#define SQLUD_OFFLINE          0x0     /* Offline restore mode                */
#define SQLUD_ONLINE           0x1     /* Online restore mode                 */

/* Datalink mode                                                              */
#define SQLUD_DATALINK         0x0
#define SQLUD_NODATALINK       0x1

/* Restore calling action values                                              */
#define SQLUD_RESTORE          0       /* initial call                        */
#define SQLUD_CONTINUE         1       /* Subsequent call                     */
#define SQLUD_TERMINATE        2       /* Terminating call                    */
#define SQLUD_NOINTERRUPT      3       /* Initial call to run without         */
                                       /* prompting                           */
#define SQLUD_DEVICE_TERMINATE 9       /* End media device.                   */
#define SQLUD_PARM_CHECK       10      /* for parameter check and             */
                                       /* initialization.                     */
#define SQLUD_PARM_CHECK_INIT_AND_WAIT 10 /* for parameter check and          */
                                       /* initialization.                     */
#define SQLUD_PARM_CHECK_ONLY  11      /* for parameter checking only.        */
#define SQLUD_RESTORE_TABLESPACE_LIST 12 /* list of tablespaces/containers.   */
#define SQLUD_TERMINATE_INCREMENTAL 13 /* abort incremental restore           */
#define SQLUD_RESTORE_STORDEF  100     /* initial call, tablespace container  */
                                       /* redefinition requested              */
#define SQLUD_STORDEF_NOINTERRUPT 101  /* initial call, tablespace container  */
                                       /* redefinition requested without      */
                                       /* prompting                           */

/* Restore type                                                               */
#define SQLUD_DB               0x0
#define SQLUD_FULL             0x0
#define SQLUD_ONLINE_TABLESPACE 0x3
#define SQLUD_TABLESPACE       0x4
#define SQLUD_HISTORY          0x5
#define SQLUD_INCREMENTAL      0x10
#define SQLUD_AUTOMATIC        0x100

/* The following are not supported in V2.1.0                                  */
#define SQLUD_TABLESPACE_TBL   6
#define SQLUD_HIST_TBLSPACE_TBL 7

/* Restore type masks                                                         */
#define SQLUD_TYPE_MASK        0xf     /* Determines if full/tbsp restore     */
#define SQLUD_INCR_MASK        0xf0    /* Determines if incr. restore         */

/* Backup/Restore Definitions                                                 */
#define SQLU_ALIAS_SZ          8       /* length of database alias name       */
#define SQLU_USERID_LEN        1024    /* Maximum length of userid            */
#define SQLU_PWD_LEN           18      /* length of password.Deprecated       */
                                       /* constant. Use ONLY for V9 and       */
                                       /* lower versions. For newer versions  */
                                       /* use SQLU_PASSWORD_LEN               */
#define SQLU_PASSWORD_LEN      255     /* length of password. Use for V9.5    */
                                       /* and later versions of DB2           */
#define SQLU_TIME_STAMP_LEN    14      /* length of the backup timestamp in   */
                                       /* yyyymmddhhmmss format               */

#define SQLU_INSTNAME_SZ       8       /* max length of an instance name      */
/* length of filename of backup image:                                        */
/* dbalias.type.db2instance.node.timestamp.seq                                */
#define SQLU_BACKUP_NAME_SZ    (SQLU_ALIAS_SZ+5+SQLU_INSTNAME_SZ+5+SQLU_TIME_STAMP_LEN+4)

/* length of directory where backup file will reside:dir - '/' - filename     */
#define SQLU_BACKUP_DIR_SZ     (1023-1-SQLU_BACKUP_NAME_SZ)

/* Data map separator for LOAD utility;  Partition Key Identifier             */
#define SQL_HEADER_DATA_SEPARATOR "===PDB==="
#define SQLU_PARTITIONKEY      "Key:"

/* Parameters for Backup/Restore old api's                                    */
#define SQLU_NSD_ID            '0'     /* User exit used, not SD interface    */

/* Parameters for SQLUHPRN force option                                       */
#define SQLUH_NO_FORCE                 0
#define SQLUH_FORCE                    1

/* Parameters for SQLUHOPS caller action                                      */
#define SQLUH_LIST_BACKUP              0
#define SQLUH_LIST_HISTORY             1
#define SQLUH_LIST_ADM_BACKUP          2
#define SQLUH_LIST_ADM_ROLLFORWARD     3
#define SQLUH_LIST_ADM_RUNSTATS        4
#define SQLUH_LIST_ADM_REORG           5
#define SQLUH_LIST_ADM_ALT_TABLESPACE  6
#define SQLUH_LIST_ADM_DROPPED_TABLE   7
#define SQLUH_LIST_ADM_LOAD            8
#define SQLUH_LIST_ADM_HISTORY         9

/* Parameters for SQLUHGNE caller action                                      */
#define SQLUH_GET_NEXT_ENTRY           0
#define SQLUH_GET_DDL                  1
#define SQLUH_GET_NEXT_ENTRY_DDL       2

/* History File structure sizes                                               */
#define SQLUH_OP_SZ                    1
#define SQLUH_OBJ_SZ                   1
#define SQLUH_OBJPART_SZ               17
#define SQLUH_OPTYPE_SZ                1
#define SQLUH_DEVTYPE_SZ               1
#define SQLUH_FIRSTLOG_SZ              12
#define SQLUH_LASTLOG_SZ               12
#define SQLUH_BACKID_SZ                14
#define SQLUH_TCREATE_SZ               8
#define SQLUH_TNAME_SZ                 18
#define SQLUH_NUMTABLESPACE_SZ         5
#define SQLUH_LOC_SZ                   255
#define SQLUH_COMMENT_SZ               30
#define SQLUH_TABLESPACENAME_SZ        18
#define SQLUH_TIMESTAMP_SZ             14
#define SQLUH_ID_SZ                    24

/* Parameters for RUNSTATS                                                    */
#define SQL_STATS_TABLE           'T'  /* TABLEOPT = Table w/o Indexes        */
#define SQL_STATS_BOTH            'B'  /* TABLEOPT = Table and Indexes        */
#define SQL_STATS_INDEX           'I'  /* TABLEOPT = Indexes w/o Table        */
#define SQL_STATS_EXTTABLE_ONLY   'D'  /* TABLEOPT = Table and dist stats     */
#define SQL_STATS_EXTTABLE_INDEX  'E'  /* TABLEOPT = Table and dist stats     */
                                       /* and basic indexes                   */
#define SQL_STATS_EXTINDEX_ONLY   'X'  /* TABLEOPT = Ext stats for indexes    */
                                       /* only                                */
#define SQL_STATS_EXTINDEX_TABLE  'Y'  /* TABLEOPT = Ext stats for indexes    */
                                       /* and basic table stats               */
#define SQL_STATS_ALL             'A'  /* TABLEOPT = Ext stats for indexes    */
                                       /* and table with dist stats           */
#define SQL_STATS_REF             'R'  /* SHAREOPT = Reference                */
#define SQLU_STATS_USE_PROFILE    'P'  /* TABLEOPT - statistics are to be     */
                                       /* gathered using the profile - Load   */
                                       /* only                                */
#define SQL_STATS_CHG             'C'  /* SHAREOPT = Change                   */

#define SQLU_STATS_DEFAULT        'F'  /* TABLEOPT - default statistics       */
                                       /* collection for the table - Load     */
                                       /* only                                */
#define SQLU_STATS_NONE           ' '  /* TABLEOPT - no statistics are to be  */
                                       /* gathered - Load only                */

/* Parameters for selection method in sqldcol                                 */
#define SQL_METH_N             78      /* Names                               */
#define SQL_METH_P             80      /* Positional                          */
#define SQL_METH_D             68      /* Default                             */
#define SQL_METH_L             76      /* Locations                           */

/* File Types for Import/Export                                               */
#define SQL_IXF                "IXF"
#define SQL_WSF                "WSF"
#define SQL_DEL                "DEL"
#define SQL_ASC                "ASC"
#define SQL_CURSOR             "CURSOR"
#define SQL_DB2CS              "DB2CS" /* load/unload                         */

/* Import/Export/Load/Unload calling action values                            */
#define SQLU_INITIAL           0x0     /* Initial call                        */
#define SQLU_CONTINUE          0x1     /* Subsequent call                     */
#define SQLU_TERMINATE         0x2     /* Terminating call                    */
#define SQLU_NOINTERRUPT       0x3     /* Initial call - Load/Unload only     */
#define SQLU_ABORT             0x4     /* Abort call - Load only              */
#define SQLU_RESTART           0x5     /* Restart call - Load only            */
#define SQLU_DEVICE_TERMINATE  0x9     /* Subsequent call - Load/Unload only  */

/* Actions for quiesce tablespaces for table                                  */
#define SQLU_QUIESCEMODE_SHARE              0
#define SQLU_QUIESCEMODE_INTENT_UPDATE      1
#define SQLU_QUIESCEMODE_EXCLUSIVE          2
#define SQLU_QUIESCEMODE_RESET              9
#define SQLU_QUIESCEMODE_RESET_OWNED        10

/* Equates for Configuration Utilities                                        */

/* Token equates for SQLFupd structure for Database Manager config file       */
#define SQLF_KTN_RQRIOBLK      1
#define SQLF_KTN_NUMDB         6
#define SQLF_KTN_NNAME         7
#define SQLF_KTN_ASLHEAPSZ     15
#define SQLF_KTN_BACKBUFSZ     18
#define SQLF_KTN_RESTBUFSZ     19
#define SQLF_KTN_INDEXREC      20
#define SQLF_KTN_SHEAPTHRES    21
#define SQLF_KTN_MAXDARI       80
#define SQLF_KTN_FENCED_POOL   80
#define SQLF_KTN_KEEPDARI      81
#define SQLF_KTN_KEEPFENCED    81
#define SQLF_KTN_SVCENAME      24
#define SQLF_KTN_TPNAME        25
#define SQLF_KTN_AGENTPRI      26
#define SQLF_KTN_DFTDBPATH     27
/* You may manipulate the bits of SQLF_KTN_DFT_MONSWITCHES or you can enable  */
/* disable, or query the current setting through the individual tokens        */
#define SQLF_KTN_DFT_MONSWITCHES  29
#define SQLF_KTN_DFT_MON_UOW      30   /* Bit 1 of SQLF_KTN_DFT_MONSWITCHES   */
#define SQLF_KTN_DFT_MON_STMT     31   /* Bit 2 of SQLF_KTN_DFT_MONSWITCHES   */
#define SQLF_KTN_DFT_MON_TABLE    32   /* Bit 3 of SQLF_KTN_DFT_MONSWITCHES   */
#define SQLF_KTN_DFT_MON_BUFPOOL  33   /* Bit 4 of SQLF_KTN_DFT_MONSWITCHES   */
#define SQLF_KTN_DFT_MON_LOCK     34   /* Bit 5 of SQLF_KTN_DFT_MONSWITCHES   */
#define SQLF_KTN_DFT_MON_SORT     35   /* Bit 6 of SQLF_KTN_DFT_MONSWITCHES   */
#define SQLF_KTN_DFT_MON_TIMESTAMP 36  /* Bit 7 of SQLF_KTN_DFT_MONSWITCHES   */
#define SQLF_KTN_DFT_ACCOUNT_STR  28
#define SQLF_KTN_SYSADM_GROUP     39
#define SQLF_KTN_DIR_CACHE        40
#define SQLF_KTN_DRDA_HEAP_SZ     41
#define SQLF_KTN_CPUSPEED         42
#define SQLF_KTN_MAXTOTFILOP      45
#define SQLF_KTN_FILESERVER       47
#define SQLF_KTN_OBJECTNAME       48
#define SQLF_KTN_QUERY_HEAP_SZ    49   /* Deprecated in V95.                  */
#define SQLF_KTN_AGENT_STACK_SZ   61
#define SQLF_KTN_SYSMAINT_GROUP   62
#define SQLF_KTN_SYSCTRL_GROUP    63
#define SQLF_KTN_DIAGLEVEL        64
#define SQLF_KTN_DIAGPATH         65
#define SQLF_KTN_TP_MON_NAME      66
#define SQLF_KTN_TM_DATABASE      67
#define SQLF_KTN_RESYNC_INTERVAL  68
#define SQLF_KTN_IPX_SOCKET       71
#define SQLF_KTN_AUTHENTICATION   78
#define SQLF_KTN_MON_HEAP_SZ      79
#define SQLF_KTN_SPM_LOG_FILE_SZ  90
#define SQLF_KTN_SPM_MAX_RESYNC   91
#define SQLF_KTN_SPM_NAME         92
#define SQLF_KTN_NUM_INITAGENTS   500
#define SQLF_KTN_MAX_COORDAGENTS  501
#define SQLF_KTN_NUM_POOLAGENTS   502
#define SQLF_KTN_FCM_NUM_BUFFERS  503
#define SQLF_KTN_CONN_ELAPSE      508
#define SQLF_KTN_MAX_CONNRETRIES  509
#define SQLF_KTN_MAX_TIME_DIFF    510
#define SQLF_KTN_START_STOP_TIME  511
#define SQLF_KTN_TRUST_ALLCLNTS   301
#define SQLF_KTN_TRUST_CLNTAUTH   302
#define SQLF_KTN_MAX_QUERYDEGREE  303
#define SQLF_KTN_DISCOVER         304
#define SQLF_KTN_DISCOVER_COMM    305
#define SQLF_KTN_INTRA_PARALLEL   306
#define SQLF_KTN_COMM_BANDWIDTH   307
#define SQLF_KTN_DISCOVER_INST    308
#define SQLF_KTN_JAVA_HEAP_SZ     310
#define SQLF_KTN_JDK11_PATH       311
#define SQLF_KTN_JDK_PATH         311
#define SQLF_KTN_AUDIT_BUF_SZ     312
#define SQLF_KTN_SPM_LOG_PATH     313
#define SQLF_KTN_CATALOG_NOAUTH   314
#define SQLF_KTN_NUM_INITDARIS    601
#define SQLF_KTN_NUM_INITFENCED   601
#define SQLF_KTN_INITDARI_JVM     602
#define SQLF_KTN_INITFENCED_JVM   602
#define SQLF_KTN_DATALINKS        603
#define SQLF_KTN_FEDERATED        604
#define SQLF_KTN_NOTIFYLEVEL      605
#define SQLF_KTN_MAX_LOGICAGENTS  701
#define SQLF_KTN_DF_ENCRYPT_LIST  801
#define SQLF_KTN_MAX_CONNECTIONS  802
#define SQLF_KTN_INSTANCE_MEMORY  803
#define SQLF_KTN_HEALTH_MON       804
#define SQLF_KTN_USE_SNA_AUTH     805
#define SQLF_KTN_FED_NOAUTH       806
#define SQLF_KTN_UTIL_IMPACT_LIM  807
#define SQLF_KTN_SRV_PLUGIN_MODE  809
#define SQLF_KTN_GROUP_PLUGIN     810
#define SQLF_KTN_CLNT_PW_PLUGIN   811
#define SQLF_KTN_CLNT_KRB_PLUGIN  812
#define SQLF_KTN_SRVCON_PW_PLUGIN 813
#define SQLF_KTN_SRVCON_GSSPLUGIN_LIST 814
#define SQLF_KTN_SRVCON_AUTH      815
#define SQLF_KTN_LOCAL_GSSPLUGIN  816
#define SQLF_KTN_SYSMON_GROUP     808
#define SQLF_KTN_SYSADM_GRP       844
#define SQLF_KTN_SYSMAINT_GRP     845
#define SQLF_KTN_SYSCTRL_GRP      846
#define SQLF_KTN_SYSMON_GRP       847
#define SQLF_KTN_FCM_PARALLELISM  848
#define SQLF_KTN_FEDERATED_ASYNC  849
#define SQLF_KTN_DBMRESERVEDBITMAP 901
#define SQLF_KTN_FCM_NUM_CHANNELS 902
#define SQLF_KTN_CLUSTER_MGR      920
#define SQLF_KTN_SSL_SVR_KEYDB    930
#define SQLF_KTN_SSL_SVR_STASH    931
#define SQLF_KTN_SSL_SVR_LABEL    932
#define SQLF_KTN_SSL_SVCENAME     933
#define SQLF_KTN_SSL_CIPHERSPECS  934
#define SQLF_KTN_SSL_VERSIONS     935
#define SQLF_KTN_SSL_CLNT_KEYDB   936
#define SQLF_KTN_SSL_CLNT_STASH   937
#define SQLF_KTN_ALTERNATE_AUTH_ENC 938
#define SQLF_KTN_DIAGSIZE         939
#define SQLF_KTN_ALT_DIAGPATH     941
#define SQLF_KTN_CF_MEM_SZ        960
#define SQLF_KTN_CF_NUM_WORKERS   961
#define SQLF_KTN_CF_NUM_CONNS     966
#define SQLF_KTN_RSTRT_LIGHT_MEM  967
#define SQLF_KTN_CF_DIAGLEVEL     968
#define SQLF_KTN_CF_DIAGPATH      969
#define SQLF_KTN_WLM_DISPATCHER   976
#define SQLF_KTN_WLM_DISP_CONCUR  977
#define SQLF_KTN_WLM_DISP_CPU_SHARES 978
#define SQLF_KTN_WLM_DISP_MIN_UTIL 979
#define SQLF_KTN_COMM_EXIT_LIST   10121
#define SQLF_KTN_DIAGPATH_RESOLVED 10123
#define SQLF_KTN_CF_DIAGPATH_RESOLVED 10124
#define SQLF_KTN_ALT_DIAGPATH_RESOLVED 10125
#define SQLF_KTN_CF_TRANSPORT_METHOD 10126
#define SQLF_KTN_KEYSTORE_LOCATION 10145
#define SQLF_KTN_KEYSTORE_TYPE    10147
#define SQLF_KTN_FCM_BUFFER_SIZE  10154
#define SQLF_KTN_MONHEAP_SZ       10156
/* tokens for informational parameters                                        */
#define SQLF_KTN_NODETYPE         100
#define SQLF_KTN_RELEASE          101
#define SQLF_KTN_NOTOKEN          200

/* defines for database manager configuration parameter values                */
/* equates for directory type (for dir_type configuration parameter)          */
#define SQLF_DIRTYPE_NONE         0
#define SQLF_DIRTYPE_DCE          1

/* Nodetype equates                                                           */
#define SQLF_NT_STANDALONE        0
#define SQLF_NT_SERVER            1
#define SQLF_NT_REQUESTOR         2
#define SQLF_NT_STAND_REQ         3
#define SQLF_NT_MPP               4
#define SQLF_NT_SATELLITE         5
/* Note: SQLF_NT_DCS is not a possible instance nodetype.  It represents a    */
/* host database server                                                       */
#define SQLF_NT_DCS               6    /* reserved for host database server   */
/* Note: SQLF_NT_DAS is not a possible instance nodetype.  It represents an   */
/* ADMIN server                                                               */
#define SQLF_NT_DAS               7    /* reserved for ADMIN server           */
/* Note: SQLF_NT_SD is not a possible instance nodetype.  It represents a     */
/* Shared Data server                                                         */
#define SQLF_NT_SD                8    /* reserved for Shared Data server     */

/* Defines for Database Monitor Switches - SQLF_KTN_DFT_MONSWITCHES:          */
/* The following meanings apply when the bits are set on:                     */
/* SQLF_ENABLE_MON_UOW       -                                                */
/* SQLF_ENABLE_MON_STMT      -                                                */
/* SQLF_ENABLE_MON_TABLE     -                                                */
/* SQLF_ENABLE_MON_BUFPOOL   -                                                */
/* SQLF_ENABLE_MON_LOCK      -                                                */
/* SQLF_ENABLE_MON_SORT      -                                                */
/* SQLF_ENABLE_MON_TIMESTAMP -                                                */
#define SQLF_ENABLE_MON_UOW       0x1  /* xxxx xxxx xxxx xxx1                 */
#define SQLF_ENABLE_MON_STMT      0x2  /* xxxx xxxx xxxx xx1x                 */
#define SQLF_ENABLE_MON_TABLE     0x4  /* xxxx xxxx xxxx x1xx                 */
#define SQLF_ENABLE_MON_BUFPOOL   0x8  /* xxxx xxxx xxxx 1xxx                 */
#define SQLF_ENABLE_MON_LOCK      0x10 /* xxxx xxxx xxx1 xxxx                 */
#define SQLF_ENABLE_MON_SORT      0x20 /* xxxx xxxx xx1x xxxx                 */
#define SQLF_ENABLE_MON_TIMESTAMP 0x40 /* xxxx xxxx x1xx xxxx                 */

/* Communication Protocols                                                    */
#define SQLF_PROTOCOL_TCPIP       "TCPIP"
#define SQLF_PROTOCOL_APPC        "APPC"
#define SQLF_PROTOCOL_NETB        "NETBIOS"
#define SQLF_PROTOCOL_IPXSPX      "IPXSPX"

/* Admin. server discover definitions (discover parameter)                    */
#define SQLF_DSCVR_KNOWN          1
#define SQLF_DSCVR_SEARCH         2

/* Constants for trusted client options                                       */
#define SQLF_TRUST_ALLCLNTS_NO    0
#define SQLF_TRUST_ALLCLNTS_YES   1
#define SQLF_TRUST_ALLCLNTS_DRDAONLY 2

/* Size of cluster manager.                                                   */
#define SQLF_CLUSTER_MGR_SZ       262
/* Token equates for SQLFupd structure for Database configuration file        */
#define SQLF_DBTN_BUFF_PAGE       90
#define SQLF_DBTN_MAXFILOP        3
#define SQLF_DBTN_SOFTMAX         5
#define SQLF_DBTN_MAXAPPLS        6
#define SQLF_DBTN_APPLHEAPSZ      51
#define SQLF_DBTN_DB_HEAP         58
#define SQLF_DBTN_DLCHKTIME       9
#define SQLF_DBTN_SORT_HEAP       52
#define SQLF_DBTN_MAXLOCKS        15
#define SQLF_DBTN_LOGPRIMARY      16
#define SQLF_DBTN_LOGSECOND       17
#define SQLF_DBTN_LOGFIL_SIZ      92
#define SQLF_DBTN_STMTHEAP        53
#define SQLF_DBTN_NEWLOGPATH      20
#define SQLF_DBTN_COPY_PROTECT    22
#define SQLF_DBTN_AUTO_RESTART    25
#define SQLF_DBTN_INDEXREC        30
#define SQLF_DBTN_PCKCACHESZ      31
#define SQLF_DBTN_MINCOMMIT       32   /* Deprecated.                         */
#define SQLF_DBTN_LOGBUFSZ        33
#define SQLF_DBTN_LOGBUFSZ32      946
#define SQLF_DBTN_LOCKTIMEOUT     34
#define SQLF_DBTN_INDEXSORT       35
#define SQLF_DBTN_NUM_FREQVALUES  36
#define SQLF_DBTN_NUM_IOCLEANERS  37
#define SQLF_DBTN_CHNGPGS_THRESH  38
#define SQLF_DBTN_NUM_IOSERVERS   39
#define SQLF_DBTN_DFT_PREFETCH_SZ 40
#define SQLF_DBTN_SEQDETECT       41
#define SQLF_DBTN_DFT_LOADREC_SES 42
#define SQLF_DBTN_REC_HIS_RETENTN 43
#define SQLF_DBTN_STAT_HEAP_SZ    45
#define SQLF_DBTN_DIR_OBJ_NAME    46   /* token for directory services        */
#define SQLF_DBTN_AVG_APPLS       47
#define SQLF_DBTN_NUM_QUANTILES   48
#define SQLF_DBTN_DFT_EXTENT_SZ   54
#define SQLF_DBTN_UTIL_HEAP_SZ    55
#define SQLF_DBTN_CATALOGCACHE_SZ 56
#define SQLF_DBTN_DFT_QUERYOPT    57
#define SQLF_DBTN_APP_CTL_HEAP_SZ 500
#define SQLF_DBTN_TSM_PASSWORD    501
#define SQLF_DBTN_PCKCACHE_SZ     505
#define SQLF_DBTN_MULTIPAGE_ALLOC 506
#define SQLF_DBTN_DFT_DEGREE      301
#define SQLF_DBTN_TSM_OWNER       305
#define SQLF_DBTN_TSM_NODENAME    306
#define SQLF_DBTN_TSM_MGMTCLASS   307
#define SQLF_DBTN_DISCOVER        308
#define SQLF_DBTN_DFT_SQLMATHWARN 309
#define SQLF_DBTN_DL_EXPINT       350
#define SQLF_DBTN_DL_NUM_COPIES   351
#define SQLF_DBTN_DL_TIME_DROP    353
#define SQLF_DBTN_NUM_DB_BACKUPS  601
#define SQLF_DBTN_DL_TOKEN        602
#define SQLF_DBTN_DL_UPPER        603
#define SQLF_DBTN_DL_WT_IEXPINT   354
#define SQLF_DBTN_DYN_QUERY_MGMT  604
#define SQLF_DBTN_MIN_DEC_DIV_3   605
#define SQLF_DBTN_DFT_REFRESH_AGE 702
#define SQLF_DBTN_LOCK_LIST       704
#define SQLF_DBTN_TRACKMOD        703
#define SQLF_DBTN_APPGROUP_MEM_SZ 800
#define SQLF_DBTN_GROUPHEAP_RATIO 801
#define SQLF_DBTN_SHEAPTHRES_SHR  802
#define SQLF_DBTN_DATABASE_MEMORY 803
#define SQLF_DBTN_BLK_LOG_DSK_FUL 804
#define SQLF_DBTN_OVERFLOWLOGPATH 805
#define SQLF_DBTN_MIRRORLOGPATH   806
#define SQLF_DBTN_MAX_LOG         807
#define SQLF_DBTN_NUM_LOG_SPAN    808
#define SQLF_DBTN_ALT_COLLATE     809
#define SQLF_DBTN_HADR_DB_ROLE    810
#define SQLF_DBTN_HADR_LOCAL_HOST 811
#define SQLF_DBTN_HADR_LOCAL_SVC  812
#define SQLF_DBTN_HADR_REMOTE_HOST 813
#define SQLF_DBTN_HADR_REMOTE_SVC 814
#define SQLF_DBTN_HADR_REMOTE_INST 815
#define SQLF_DBTN_HADR_TIMEOUT    816
#define SQLF_DBTN_HADR_SYNCMODE   817
#define SQLF_DBTN_LOGINDEXBUILD   818
#define SQLF_DBTN_SHEAPTHRES      820
#define SQLF_DBTN_STMT_HEAP       821
#define SQLF_DBTN_LOGARCHMETH1    822
#define SQLF_DBTN_LOGARCHMETH2    823
#define SQLF_DBTN_LOGARCHOPT1     824
#define SQLF_DBTN_LOGARCHOPT2     825
#define SQLF_DBTN_FAILARCHPATH    826
#define SQLF_DBTN_NUMARCHRETRY    827
#define SQLF_DBTN_ARCHRETRYDELAY  828
#define SQLF_DBTN_VENDOROPT       829
#define SQLF_DBTN_AUTONOMIC_SWITCHES 830
#define SQLF_DBTN_AUTO_MAINT      831
#define SQLF_DBTN_AUTO_MAINT_EFF  832
#define SQLF_DBTN_AUTO_DB_BACKUP  833
#define SQLF_DBTN_AUTO_DB_BACKUP_EFF 834
#define SQLF_DBTN_AUTO_TBL_MAINT  835
#define SQLF_DBTN_AUTO_TBL_MAINT_EFF 836
#define SQLF_DBTN_AUTO_RUNSTATS   837
#define SQLF_DBTN_AUTO_RUNSTATS_EFF 838
#define SQLF_DBTN_AUTO_STATS_PROF 839  /* Deprecated.                         */
#define SQLF_DBTN_AUTO_STATS_PROF_EFF 840 /* Deprecated.                      */
#define SQLF_DBTN_PAGESIZE        846
#define SQLF_DBTN_AUTO_REORG      841
#define SQLF_DBTN_AUTO_REORG_EFF  842
#define SQLF_DBTN_DFT_MTTB_TYPES  843
#define SQLF_DBTN_AUTO_PROF_UPD   844  /* Deprecated.                         */
#define SQLF_DBTN_AUTO_PROF_UPD_EFF 845 /* Deprecated.                        */
#define SQLF_DBTN_SELF_TUNING_MEM 848
#define SQLF_DBTN_DB_MEM_THRESH   849
#define SQLF_DBTN_ENABLE_XMLCHAR  853
#define SQLF_DBTN_APPL_MEMORY     904
#define SQLF_DBTN_AUTO_STMT_STATS 905
#define SQLF_DBTN_AUTO_STMT_STATS_EFF 906
#define SQLF_DBTN_WLM_COLLECT_INT 907
#define SQLF_DBTN_BLOCKNONLOGGED  940
/* Monitoring Database Control Parameters                                     */
#define SQLF_DBTN_MON_REQ_METRICS 930
#define SQLF_DBTN_MON_ACT_METRICS 931
#define SQLF_DBTN_MON_UOW_DATA    932
#define SQLF_DBTN_MON_LOCKTIMEOUT 933
#define SQLF_DBTN_MON_DEADLOCK    934
#define SQLF_DBTN_MON_LOCKWAIT    935
#define SQLF_DBTN_MON_LW_THRESH   936
#define SQLF_DBTN_MON_OBJ_METRICS 937
#define SQLF_DBTN_MON_PKGLIST_SZ  950
#define SQLF_DBTN_MON_LCK_MSG_LVL 951
#define SQLF_DBTN_SYSTIME_PERIOD_ADJ 955
#define SQLF_DBTN_MON_UOW_PKGLIST 956
#define SQLF_DBTN_MON_UOW_EXECLIST 957
#define SQLF_DBTN_AUTO_STATS_VIEWS 958
#define SQLF_DBTN_AUTO_STATS_VIEWS_EFF 959
#define SQLF_DBTN_AUTO_SAMPLING   960
#define SQLF_DBTN_AUTO_SAMPLING_EFF 961
#define SQLF_DBTN_LOGGING_DETAIL  10109
#define SQLF_DBTN_LOG_DDL_STMTS   10110
#define SQLF_DBTN_LOG_APPL_INFO   10111
#define SQLF_DBTN_DFT_SCHEMAS_DCC 10115

#define SQLF_DBTN_HADR_TARGET_LIST 10114
#define SQLF_DBTN_HADR_SPOOL_LIMIT 10112
#define SQLF_DBTN_HADR_REPLAY_DELAY 10119
#define SQLF_DBTN_LOGARCHCOMPR1   10123
#define SQLF_DBTN_LOGARCHCOMPR2   10124
#define SQLF_DBTN_OPT_DIRECT_WRKLD 10127
#define SQLF_DBTN_AUTO_DEL_REC_OBJ 912
#define SQLF_DBTN_DECFLT_ROUNDING 913
#define SQLF_DBTN_HADR_PEER_WINDOW 914
#define SQLF_DBTN_CF_GBP_SZ       920
#define SQLF_DBTN_CF_LOCK_SZ      921
#define SQLF_DBTN_CF_SCA_SZ       922
#define SQLF_DBTN_CF_DB_MEM_SZ    923
#define SQLF_DBTN_CF_CATCHUP_TRGT 970
#define SQLF_DBTN_DBRESERVEDBITMAP 901
#define SQLF_DBTN_STMT_CONC       919
#define SQLF_DBTN_CONNECT_PROC    954
#define SQLF_DBTN_DFT_TABLE_ORG   10126
#define SQLF_DBTN_MON_RTN_EXECLIST 10128
#define SQLF_DBTN_MON_RTN_DATA    10130
#define SQLF_DBTN_STRING_UNITS    10132
#define SQLF_DBTN_NCHAR_MAPPING   10133
/* tokens for informational (non-modifiable) parameters                       */
#define SQLF_DBTN_COLLATE_INFO    44
#define SQLF_DBTN_DB_COLLNAME     850
#define SQLF_DBTN_COUNTRY         100
#define SQLF_DBTN_DFT_OVERHEAD    902
#define SQLF_DBTN_DFT_TRANSFERRATE 903

#define SQLF_DBTN_EXTBL_STRICT_IO 10135
#define SQLF_DBTN_EXTBL_LOCATION  10134

#define SQLF_DBTN_PAGE_AGE_TRGT_MCR 10137
#define SQLF_DBTN_PAGE_AGE_TRGT_GCR 10136
#define SQLF_DBTN_CF_SELF_TUNING_MEM 10143
#define SQLF_DBTN_ENCRLIB         10142
#define SQLF_DBTN_ENCROPTS        10141
#define SQLF_DBTN_APPLHEAP_SZ     10157
#define SQLF_DBTN_PL_STACK_TRACE  10168
#define SQLF_DBTN_HADR_SSL_LABEL  10170
#define SQLF_DBTN_DEC_ARITHMETIC  10173
#define SQLF_DEC_ARITHMETIC_LEN   6    /* Maximum size of dec_arithmetic.     */
#define SQLF_DBTN_TERRITORY_CODE  100
#define SQLF_DBTN_CODEPAGE        101
#define SQLF_DBTN_RELEASE         102
#define SQLF_DBTN_LOGPATH         103
#define SQLF_DBTN_LOGHEAD         105
#define SQLF_DBTN_CONSISTENT      111
#define SQLF_DBTN_BACKUP_PENDING  112
#define SQLF_DBTN_ROLLFWD_PENDING 113
#define SQLF_DBTN_LOG_RETAIN_STATUS 114
#define SQLF_DBTN_USER_EXIT_STATUS 115
#define SQLF_DBTN_CODESET         120
#define SQLF_DBTN_TERRITORY       121
#define SQLF_DBTN_NUMSEGS         122
#define SQLF_DBTN_DATABASE_LEVEL  124
#define SQLF_DBTN_NOTOKEN         200
#define SQLF_DBTN_RESTORE_PENDING 503
#define SQLF_DBTN_RESTRICT_ACCESS 852
#define SQLF_DBTN_NUMBER_COMPAT   915
#define SQLF_DBTN_VARCHAR2_COMPAT 916
#define SQLF_DBTN_CUR_COMMIT      917
#define SQLF_DBTN_DATE_COMPAT     918
#define SQLF_DBTN_AUTO_REVAL      924
#define SQLF_DBTN_DEC_TO_CHAR_FMT 925
#define SQLF_DBTN_SMTP_SERVER     926
#define SQLF_DBTN_SQL_CCFLAGS     927
#define SQLF_DBTN_SECTION_ACTUALS 952
#define SQLF_DBTN_SUSPEND_IO      953
#define SQLF_DBTN_EXTENDED_ROW_SZ 10131
#define SQLF_DBTN_ENCRYPTED_DATABASE 10148

/* These are internal optimizer parameters that the DB2 Config Advisorgives   */
/* recommendations for.  They can only be set via theConfiguration Advisor    */
/* or through the db2fopt command                                             */
#define SQLF_DBTN_OPT_BUFFPAGE    1005 /* (Internal) Optimizer bufferppol     */
                                       /* page                                */
#define SQLF_DBTN_OPT_SORTHEAP    1006 /* (Internal) Optimizer sort heap      */
#define SQLF_DBTN_OPT_LOCKLIST    1011 /* (Internal) Optimizer lock list      */
#define SQLF_DBTN_OPT_MAXLOCKS    1013 /* (Internal) Optimizer max locks      */

/* WLM admission control parameters                                           */
#define SQLF_DBTN_WLM_ADMISSION_CTRL 10162 /* WLM admission control enabled   */
#define SQLF_DBTN_WLM_CPU_SHARES  10164 /* Allocated share of CPU resources   */
#define SQLF_DBTN_WLM_CPU_SHARE_MODE 10165 /* CPU share behavior (hard/soft)  */
#define SQLF_DBTN_WLM_CPU_LIMIT   10166 /* Maximum allowable CPU utilization  */
                                       /* (%)                                 */
#define SQLF_DBTN_WLM_AGENT_LOAD_TRGT 10167 /* Target agent load per CPU      */
                                       /* core                                */

/* defines for database configuration parameter values                        */

/* Generic Disable/Enable values for configuration parameters                 */
#define SQLF_DISABLE              0
#define SQLF_ENABLE               1

/* Defines for logarchcompr1/2                                                */
#define SQLF_LOGARCHCOMPR_DISABLE 0
#define SQLF_LOGARCHCOMPR_ENABLE  1
#define SQLF_LOGARCHCOMPR_NX842   2
#define SQLF_LOGARCHCOMPR_ZLIB    3

/* Decimal floating point rounding modes (DECFLT_ROUNDING)                    */
#define SQLF_DFP_ROUND_HALF_EVEN  0
#define SQLF_DFP_ROUND_HALF_UP    1
#define SQLF_DFP_ROUND_DOWN       2
#define SQLF_DFP_ROUND_CEILING    3
#define SQLF_DFP_ROUND_FLOOR      4

/* Index recreate type (INDEXREC values)                                      */
#define SQLF_INX_REC_SYSTEM       0
#define SQLF_INX_REC_REFERENCE    1
#define SQLF_INX_REC_RESTART      2
#define SQLF_INX_REC_RESTART_NO_REDO 3
#define SQLF_INX_REC_ACCESS_NO_REDO 4
#define SQLF_INX_REC_RESTART_ASYNC 5
#define SQLF_INX_REC_RESTART_ASCNOREDO 6

/* Possible values for: SQLF_DBTN_ROLLFWD_PENDING are:                        */
/* SQLF_DISABLE, SQLF_ENABLE, and SQLF_ROLLFWD_TABLESPACE                     */
#define SQLF_ROLLFWD_TABLESPACE   2    /* The third state of rollfwd_pending  */

/* Defines for SQLF_DBTN_LOG_RETAIN (obsolete) and SQLF_DBTN_LOG_RETAIN       */
/* STATUS                                                                     */
#define SQLF_LOGRETAIN_DISABLE    0    /* Not configured with LOGRETAIN       */
#define SQLF_LOGRETAIN_RECOVERY   1    /* Log file retained for recovery      */
#define SQLF_LOGRETAIN_CAPTURE    2    /* Log file retained for CAPTURE,      */
                                       /* will be deleted after CAPTURE       */
                                       /* finished processing                 */

/* AUTO_REVALIDATION values                                                   */
#define SQLF_AUTO_REVAL_DISABLED  0    /* No auto-revalidation                */
#define SQLF_AUTO_REVAL_IMMEDIATE 1    /* Immediate auto-revalidation         */
#define SQLF_AUTO_REVAL_DEFERRED  2    /* Deferred auto-revalidation          */
#define SQLF_AUTO_REVAL_DEFERRED_FORCE 3 /* Deferred auto-revalidation        */

/* HADR - High Availability Disaster Recovery parameters                      */
#define SQLF_HADR_HOSTNAME_SZ     255  /* Internet std for hostname is 255    */
#define SQLF_HADR_TARGET_LIST_SZ  2048 /* HADR Stand-by list size             */
#define SQLF_HADR_SVCENAME_SZ     40   /* Internet std for svcename is 40     */
#define SQLF_HADR_INSTANCE_SZ     8    /* HADR instance name                  */

/* HADR_DB_ROLE values                                                        */
#define SQLF_HADR_DB_ROLE_STANDARD 0   /* Not an HADR database                */
#define SQLF_HADR_DB_ROLE_PRIMARY 1    /* An HADR primary db                  */
#define SQLF_HADR_DB_ROLE_STANDBY 2    /* An HADR standby db                  */

/* HADR_SYNCMODE values                                                       */
#define SQLF_HADR_SYNCMODE_SYNC   0    /* Synchronous mode                    */
#define SQLF_HADR_SYNCMODE_NEARSYNC 1  /* Near-synchronous mode               */
#define SQLF_HADR_SYNCMODE_ASYNC  2    /* Asynchronous mode                   */
#define SQLF_HADR_SYNCMODE_SUPERASYNC 3 /* Super Asynchronous mode            */

/* DFT_MTTB_TYPES values                                                      */
#define SQLF_DFT_MTTB_TYPES_SYSTEM 1   /* SYSTEM                              */
#define SQLF_DFT_MTTB_TYPES_USER  2    /* USER                                */
#define SQLF_DFT_MTTB_TYPES_NONE  4    /* NONE                                */
#define SQLF_DFT_MTTB_TYPES_ALL   8    /* ALL                                 */
#define SQLF_DFT_MTTB_TYPES_FED_TOOL 16 /* FEDERATED_TOOL                     */
#define SQLF_DFT_MTTB_TYPES_REPL  32   /* REPLICATION                         */

/* Monitor Database Configuration Values                                      */
#define SQLF_NONE                 0
#define SQLF_BASE                 1
#define SQLF_EXTENDED             2
#define SQLF_WITHOUT_HIST         1
#define SQLF_HISTORY              2
#define SQLF_HIST_AND_VALUES      3
#define SQLF_PKGLIST              2

/* Monitor Lock events notification levels                                    */
#define SQLF_LCK_MSG_LVL0         0
#define SQLF_LCK_MSG_LVL1         1
#define SQLF_LCK_MSG_LVL2         2
#define SQLF_LCK_MSG_LVL3         3

#define SQLF_MAX_CCFLAGS_LEN      1023

/* Defines for SQLF_DBTN_STMT_CONC                                            */
#define SQLF_STMT_CONC_OFF        0    /* Statement concentrator off          */
#define SQLF_STMT_CONC_LITERALS   1    /* SQL statements that are identical,  */
                                       /* except for the values of literals,  */
                                       /* may share package cache entries     */
#define SQLF_STMT_CONC_COMMENTS   2    /* SQL statements that are identical,  */
                                       /* except for the values of comments,  */
                                       /* may share package cache entries     */
#define SQLF_STMT_CONC_COMM_LIT   3    /* SQL statements that are identical,  */
                                       /* except for the values of literals   */
                                       /* or comments, may share package      */
                                       /* cache entries                       */

/* Defines for SQLF_DBTN_SECTION_ACTUALS                                      */
#define SQLF_SECTION_ACTUALS_NONE 0    /* All section actuals are disabled    */
#define SQLF_SECTION_ACTUALS_BASE 1    /* Basic section actuals, including    */
                                       /* operator cardinality counts, are    */
                                       /* enabled                             */

/* Defines for SQLF_DBTN_SUSPEND_IO                                           */
#define SQLF_SUSPEND_IO_NONE      0    /* Database is in write suspend        */
                                       /* state: NO                           */
#define SQLF_SUSPEND_IO_IN_PROGRESS 1  /* Database is in write suspend        */
                                       /* state: IN PROGRESS                  */
#define SQLF_SUSPEND_IO_ACTIVE    2    /* Database is in write suspend        */
                                       /* state: YES                          */
/* Defines for SQLF_DBTN_WLM_CPU_SHARE_MODE                                   */
#define SQLF_SHARE_SOFT           0    /* Soft CPU Share                      */
#define SQLF_SHARE_HARD           1    /* Hard CPU Share                      */
/* Defines for SQLF_DBTN_DFT_TABLE_ORG                                        */
#define SQLF_DFT_TABLE_ORG_ROW    0    /* Table organized by ROW unless       */
                                       /* otherwise specified                 */
#define SQLF_DFT_TABLE_ORG_COLUMN 1    /* Table organized by COLUMN unless    */
                                       /* otherwise specified                 */

/* Defines for SQLF_DBTN_STRING_UNITS                                         */
#define SQLF_STRING_UNITS_SYSTEM  0    /* Unless otherwise specified,         */
                                       /* character strings default to        */
                                       /* OCTETS and graphic strings default  */
                                       /* to CODEUNITS16.                     */
#define SQLF_STRING_UNITS_CODEUNITS32 4 /* Unless otherwise specified,        */
                                       /* character and graphic strings       */
                                       /* default to CODEUNITS32.             */

/* Defines for SQLF_DBTN_NCHAR_MAPPING                                        */
#define SQLF_NCHAR_MAPPING_NOT_APPLIC 0 /* National character strings         */
                                       /* mapping is not applicable.          */
#define SQLF_NCHAR_MAPPING_GRAPH_CU32 4 /* National character strings map to  */
                                       /* graphic strings with string units   */
                                       /* CODEUNITS32.                        */
#define SQLF_NCHAR_MAPPING_CHAR_CU32 8 /* National character strings map to   */
                                       /* character strings with string       */
                                       /* units CODEUNITS32.                  */
#define SQLF_NCHAR_MAPPING_GRAPH_CU16 16 /* National character strings map    */
                                       /* to graphic strings with string      */
                                       /* units CODEUNITS16.                  */

/* Defines for SQLF_DBTN_PL_STACK_TRACE                                       */
#define SQLF_PL_STACK_TRACE_NONE  0    /* Do not log stack traces for any     */
                                       /* SQL PL error.                       */
#define SQLF_PL_STACK_TRACE_UNHANDLED 1 /* Log stack traces for unhandled     */
                                       /* SQL PL errors only.                 */
#define SQLF_PL_STACK_TRACE_ALL   2    /* Log stack traces for all SQL PL     */
                                       /* errors.                             */

/* Defines for SQLF_DBTN_HADR_SSL_LABEL                                       */
#define SQLF_HADR_SSL_LABEL_LEN   127  /* Maximum size of SSL certificate     */
                                       /* label.                              */

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

/* Constants for configuration parameter maximum lengths                      */
#define SQL_SPM_NAME_SZ           8    /* length of syncpoint manager name    */
#define SQL_LOGPATH_SZ            242  /* max length of log parms             */
#define SQL_LOGFILE_NAME_SZ       12   /* max length of log file name         */
#define SQL_DBPATH_SZ             215  /* max length of db path parm          */
#define SQL_DFENCRYPTLIST_SZ      24   /* size of dataflow encrypt list       */
#define SQL_FFDCPATH_SZ           215  /* max length of diagpath parm         */
#define SQL_FILENAME_SZ           254  /* max filename size (see SQLZ_FNAME   */
                                       /* SZ)                                 */
#define SQL_CONNECT_PROC_SZ       257  /* max length including schema,        */
                                       /* delimiter ('.') and procedure name  */
#define SQL_FILE_PATHS_SZ         1023 /* max length of file_paths parm       */

/* Constants for types of Data Redistribution operation                       */
#define SQLUT_UNIFORM          'U'     /* Uniform redistribution              */
#define SQLUT_TARGETMAP        'T'     /* Using target partitioning map       */
#define SQLUT_CONTINUE         'C'     /* Resuming a stopped data redist.     */
#define SQLUT_ABORT            'A'     /* Aborting a stopped data redist.     */
#define SQLUT_ROLLBACK         'A'     /* Aborting a stopped data redist.     */
#define SQLUT_PRECHECK_Y       'Y'     /* Perform precondition validation     */
#define SQLUT_PRECHECK_N       'N'     /* Don't perform precondition          */
                                       /* validation                          */
#define SQLUT_PRECHECK_O       'O'     /* Perform precondition validation     */
                                       /* and quit                            */
#define SQLUT_PRECHECK_U       'U'     /* Not provided value                  */
#define SQLUT_QUIESCE_Y        'Y'     /* Quiesce database connections        */
#define SQLUT_QUIESCE_N        'N'     /* Don't quiesce database connections  */
#define SQLUT_UNQUIESCE_ONLY   'O'     /* Don't quiesce database connections  */
                                       /* but we need to unquiesce            */
#define SQLUT_QUIESCE_U        'U'     /* Not provided value                  */
/* LOAD and UNLOAD defines                                                    */
#define SQLU_AUTOMATIC_RESTART 'A'     /* Automatic Restart                   */
#define SQLU_LOAD_PHASE        'L'     /* Reserved for backward compability   */
#define SQLU_BUILD_PHASE       'B'     /* Reserved for backward compability   */
#define SQLU_DELETE_PHASE      'D'     /* Reserved for backward compability   */

/* Constants for LOAD indexing_mode                                           */

#define SQLU_INX_AUTOSELECT    0       /* Load chooses between REBUILD and    */
                                       /* INCRMENTAL                          */
#define SQLU_INX_REBUILD       1       /* Rebuild table indexes               */
#define SQLU_INX_INCREMENTAL   2       /* Extend table indexes                */
#define SQLU_INX_DEFERRED      3       /* Do not update table indexes         */

/* Set Integrity Pending Constants                                            */

#define SQLU_SI_PENDING_CASCADE_DEFERRED 0 /* Only loaded table placed into   */
                                       /* Set Integrity Pending State         */
#define SQLU_CHECK_PENDING_CASCADE_DEFERRED 0 /* For backward source          */
                                       /* compatibility.                      */
#define SQLU_SI_PENDING_CASCADE_IMMEDIATE 1 /* Descendants tables put into    */
                                       /* Set Integrity Pending State         */
#define SQLU_CHECK_PENDING_CASCADE_IMMEDIATE 1 /* For backward source         */
                                       /* compatibility                       */

/* Access Level Defines                                                       */

#define SQLU_ALLOW_NO_ACCESS   0       /* No access to table during load or   */
                                       /* import                              */
#define SQLU_ALLOW_READ_ACCESS 1       /* Read access to table during load    */
#define SQLU_ALLOW_WRITE_ACCESS 2      /* Write access to table during        */
                                       /* import                              */

/* Lock With Force Option                                                     */

#define SQLU_NO_FORCE          0       /* Does not use force during locks     */
#define SQLU_LOCK_WITH_FORCE   1       /* Forces applications off table       */

/* KEYSTORE_TYPE Constanst                                                    */

#define SQLF_KEYSTORE_NONE     0       /* No keystore defined                 */
#define SQLF_KEYSTORE_PKCS12   1       /* PKCS12 keystore                     */
#define SQLF_KEYSTORE_KMIP     2       /* KMIP keystore                       */
#define SQLF_KEYSTORE_PKCS11   3       /* PKCS11 keystore                     */

/******************************************************************************
** sqldcoln data structure
** Table: Fields in the SQLDCOLN Structure
** --------------------------------------------------------------------
** |Field Name|  Data Type |Description                               |
** |----------|------------|------------------------------------------|
** |DCOLNLEN  |  SMALLINT  |Length of the data pointed to by DCOLNPTR.|
** |----------|------------|------------------------------------------|
** |DCOLNPTR  |  Pointer   |Pointer to a data element determined by   |
** |          |            |DCOLMETH.                                 |
** |----------|------------|------------------------------------------|
** |Note:                                                             |
** |The DCOLNLEN and DCOLNPTR fields are repeated for each column     |
** |specified.                                                        |
** |------------------------------------------------------------------|
** 
*******************************************************************************/
SQL_STRUCTURE sqldcoln
{
   short           dcolnlen;
   char            *dcolnptr;
};

/******************************************************************************
** sqldcol data structure
** This structure is used to pass variable column information to the
** db2Export, db2Import, and db2Load APIs.
** 
** Table: Fields in the SQLDCOL Structure
** ---------------------------------------------------------------------
** |Field Name|Data Type|Description                                   |
** |----------|---------|----------------------------------------------|
** |DCOLMETH    |SMALLINT |A character indicating the method to be used  |
** |          |         |to select columns within the data file.       |
** |----------|---------|----------------------------------------------|
** |DCOLNUM   |SMALLINT |The number of columns specified in the array  |
** |          |         |DCOLNAME .                                    |
** |----------|---------|----------------------------------------------|
** |DCOLNAME    |Array     |An array of DCOLNUM sqldcoln structures.      |
** |----------|---------|----------------------------------------------|
** 
** The valid values for DCOLMETH (defined in sqlutil) are:
** 
** - SQL_METH_N
** 
** Names. When importing or loading, use the column names provided via
** this structure to identify the data to import or load from the
** external file. The case of these column names must match the case of
** the corresponding names in the system catalogs. When exporting, use
** the column names provided via this structure as the column names in
** the output file.
** 
** The dcolnptr pointer of each element of the dcolname array points to
** an array of characters, of length dcolnlen bytes, that make up the
** name of a column to be imported or loaded. The dcolnum field, which
** must be positive, indicates the number of elements in the dcolname
** array.
** 
** This method is invalid if the external file does not contain column
** names (DEL or ASC format files, for example).
** 
** - SQL_METH_P
** 
** Positions. When importing or loading, use starting column positions
** provided via this structure to identify the data to import or load
** from the external file. This method is not valid when exporting data.
** 
** The dcolnptr pointer of each element of the dcolname array is
** ignored, while the dcolnlen field contains a column position in the
** external file. The dcolnum field, which must be positive, indicates
** the number of elements in the dcolname array.
** 
** The lowest valid column position value is 1 (indicating the first
** column), and the highest valid value depends on the external file
** type. Positional selection is not valid for import of ASC files.
** 
** - SQL_METH_L
** 
** Locations. When importing or loading, use starting and ending column
** positions provided via this structure to identify the data to import
** or load from the external file. This method is not valid when
** exporting data.
** 
** The dcolnptr field of the first element of the dcolname array points
** to an sqlloctab structure, which consists of an array of sqllocpair
** structures. The number of elements in this array is determined by the
** dcolnum field of the sqldcol structure, which must be positive. Each
** element in the array is a pair of 2-byte integers that indicate where
** the column begins and ends. The first element of each location pair
** is the byte within the file where the column begins, and the second
** element is the byte where the column ends. The first byte position
** within a row in the file is considered byte position 1. The columns
** can overlap.
** 
** - SQL_METH_D
** Default. When importing or loading DEL and IXF files, the first
** column of the file is loaded or imported into the first column of the
** table, and so on. When importing or loading ASC files, the selection
** of columns is in a file where the name of which is included in the
** file type modifier POSITIONSFILE. When exporting, the default names
** are used for the columns in the external file.
** 
** The dcolnum and dcolname fields of the sqldcol structure are both
** ignored, and the columns from the external file are taken in their
** natural order.
** 
** A column from the external file can be used in the array more than
** once. It is not necessary to use every column from the external file.
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQL-DCOLDATA.
**     05 SQL-DCOLMETH           PIC S9(4) COMP-5.
**     05 SQL-DCOLNUM            PIC S9(4) COMP-5.
**     05 SQLDCOLN OCCURS 0 TO 255 TIMES DEPENDING ON SQL-DCOLNUM.
**         10 SQL-DCOLNLEN       PIC S9(4) COMP-5.
**         10 FILLER             PIC X(2).
**         10 SQL-DCOLN-PTR      USAGE IS POINTER.
** * 
** 
*******************************************************************************/
SQL_STRUCTURE sqldcol
{
   short           dcolmeth;
   short           dcolnum;
   struct sqldcoln dcolname[1];   /* actual size must be dcolnum              */
};

/* Structure for Pairs of Locations for ASC files                             */
/******************************************************************************
** sqllocpair data structure
** Table: Fields in the SQLLOCPAIR Structure
** ---------------------------------------------------------------------
** |Field Name |Data Type|   Description                                |
** |-----------|---------|---------------------------------------------|
** |BEGIN_LOC  |SMALLINT |  Starting position of the column data in the|
** |           |         |  external file.                             |
** |-----------|---------|---------------------------------------------|
** |END_LOC    |SMALLINT |  Ending position of the column data in the  |
** |           |         |  external file.                             |
** |-----------|---------|---------------------------------------------|
** 
*******************************************************************************/
SQL_STRUCTURE sqllocpair
{
   short           begin_loc;
   short           end_loc;
};

/******************************************************************************
** sqlloctab data structure
** Table: Fields in the SQLLOCTAB Structure
** ------------------------------------------------------------
** |Field Name| Data Type|  Description                       |
** |----------|----------|------------------------------------|
** |LOCPAIR   | Array    |  An array of sqllocpair structures.|
** |----------|----------|------------------------------------|
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQL-LOCTAB.
**     05 SQL-LOC-PAIR OCCURS 1 TIMES.
**         10 SQL-BEGIN-LOC      PIC S9(4) COMP-5.
**         10 SQL-END-LOC        PIC S9(4) COMP-5.
** * 
** 
*******************************************************************************/
SQL_STRUCTURE sqlloctab
{
   struct sqllocpair locpair[1];  /* actual size must be dcolnum              */
};

/* Structures for Input and Output Data for Import and Export                 */

/******************************************************************************
** sqluimpt_in data structure
*******************************************************************************/
SQL_STRUCTURE sqluimpt_in
{
   sqluint32       sizeOfStruct;
   sqluint32       commitcnt;
   sqluint32       restartcnt;
};

/******************************************************************************
** sqluimpt_out data structure
*******************************************************************************/
SQL_STRUCTURE sqluimpt_out
{
   sqluint32       sizeOfStruct;
   sqluint32       rowsRead;
   sqluint32       rowsSkipped;
   sqluint32       rowsInserted;
   sqluint32       rowsUpdated;
   sqluint32       rowsRejected;
   sqluint32       rowsCommitted;
};

/******************************************************************************
** sqluexpt_out data structure
*******************************************************************************/
SQL_STRUCTURE sqluexpt_out
{
   sqluint32       sizeOfStruct;
   sqluint32       rowsExported;
};

#define SQLUIMPT_IN_SIZE sizeof(struct sqluimpt_in)
#define SQLUIMPT_OUT_SIZE sizeof(struct sqluimpt_out)
#define SQLUEXPT_OUT_SIZE sizeof(struct sqluexpt_out)

/* Structures for Input and Output Data for Load and Unload                   */

/******************************************************************************
** sqluload_in data structure
*******************************************************************************/
SQL_STRUCTURE sqluload_in
{
   sqluint32       sizeOfStruct;
   sqluint32       savecnt;
   sqluint32       restartcnt;
   sqluint32       rowcnt;
   sqluint32       warningcnt;
   sqluint32       data_buffer_size;
   sqluint32       sort_buffer_size;
   unsigned short  hold_quiesce;
   char            restartphase;
   char            statsopt;
   unsigned short  cpu_parallelism;
   unsigned short  disk_parallelism;
   unsigned short  non_recoverable;
   unsigned short  indexing_mode;
};

/******************************************************************************
** sqluload_out data structure
*******************************************************************************/
SQL_STRUCTURE sqluload_out
{
   sqluint32       sizeOfStruct;
   sqluint32       rowsRead;
   sqluint32       rowsSkipped;
   sqluint32       rowsLoaded;
   sqluint32       rowsRejected;
   sqluint32       rowsDeleted;
   sqluint32       rowsCommitted;
};

/******************************************************************************
** sqluunld_in data structure
*******************************************************************************/
SQL_STRUCTURE sqluunld_in
{
   sqluint32       sizeOfStruct;
   sqluint32       data_buffer_size;
   sqluint32       sort_buffer_size;
   unsigned short  hold_quiesce;
   unsigned short  intent_update;
   unsigned short  serial_write;
   unsigned short  num_buffers;
   unsigned short  reorg_lobs;
   unsigned short  filler;
};

/******************************************************************************
** sqluunld_out data structure
*******************************************************************************/
SQL_STRUCTURE sqluunld_out
{
   sqluint32       sizeOfStruct;
   sqluint32       rowsUnloaded;
};

#define SQLULOAD_IN_SIZE sizeof(struct sqluload_in)
#define SQLULOAD_OUT_SIZE sizeof(struct sqluload_out)
#define SQLUUNLD_IN_SIZE sizeof(struct sqluunld_in)
#define SQLUUNLD_OUT_SIZE sizeof(struct sqluunld_out)

/* Constants and Structures for the Asynchronous Read Log API                 */

#define SQLU_RLOG_READ 1               /* read the database log               */
#define SQLU_RLOG_READ_SINGLE 2        /* read a single log record            */
#define SQLU_RLOG_QUERY 3              /* query the database log              */

/******************************************************************************
** SQLU_LSN union
** This union, used by the db2ReadLog API, contains the definition of the
** log sequence number. A log sequence number (LSN) represents a relative
** byte address within the database log. All log records are identified
** by this number. An LSN represents the byte offset of the log record
** from the beginning of the database log.
** 
** Table: Fields in the SQLU-LSN Union
** |---------------------------------------------------------------|
** |Field Name|Data Type              |Description                 |
** |----------|-----------------------|----------------------------|
** |lsnChar   |Array of UNSIGNED CHAR |Specifies the 6-member      |
** |          |                       |character array log         |
** |          |                       |sequence number.            |
** |----------|-----------------------|----------------------------|
** |lsnWord   |Array of UNSIGNED SHORT|Specifies the 3-member short|
** |          |                       |array log sequence number.  |
** |----------|-----------------------|----------------------------|
** 
*******************************************************************************/
typedef union SQLU_LSN
{
   unsigned char   lsnChar[6];         /* 6 byte character representation     */
   unsigned short  lsnWord[3];         /* 6 byte short representation         */
} SQLU_LSN;

/******************************************************************************
** SQLU_RLOG_INFO data structure
** This structure contains information about the status of calls to the
** db2ReadLog API; and to the database log.
** 
** Table: Fields in the SQLU-RLOG-INFO Structure
** |---------------------------------------------------------------|
** |Field Name     |Data Type|Description                          |
** |---------------|---------|-------------------------------------|
** |initialLSN     |SQLU_LSN |Specifies the LSN value of the first |
** |               |         |log record that is written after the |
** |               |         |first database CONNECT statement is  |
** |               |         |issued. For more information, see    |
** |               |         |SQLU-LSN.                            |
** |---------------|---------|-------------------------------------|
** |firstReadLSN   |SQLU_LSN |Specifies the LSN value of the first |
** |               |         |log record read.                     |
** |---------------|---------|-------------------------------------|
** |lastReadLSN    |SQLU_LSN |Specifies the LSN value of the last  |
** |               |         |log record read.                     |
** |---------------|---------|-------------------------------------|
** |curActiveLSN   |SQLU_LSN |Specifies the LSN value of the       |
** |               |         |current (active) log.                |
** |---------------|---------|-------------------------------------|
** |logRecsWritten |sqluint32|Specifies the number of log records  |
** |               |         |written to the buffer.               |
** |---------------|---------|-------------------------------------|
** |logBytesWritten|sqluint32|Specifies the number of bytes written|
** |               |         |to the buffer.                       |
** |---------------|---------|-------------------------------------|
** 
*******************************************************************************/
typedef SQL_STRUCTURE SQLU_RLOG_INFO
{
   SQLU_LSN        initialLSN;         /* initial lsn at first connect        */
   SQLU_LSN        firstReadLSN;       /* first lsn read on call              */
   SQLU_LSN        lastReadLSN;        /* last lsn read on call               */
   SQLU_LSN        curActiveLSN;       /* current active lsn                  */
   sqluint32       logRecsWritten;     /* number of log records returned      */
   sqluint32       logBytesWritten;    /* number of log bytes returned        */
} SQLU_RLOG_INFO;

/* Structures for Configuration Utility APIs.                                 */

/******************************************************************************
** sqlfupd data structure
** This structure passes information about database configuration files
** and the database manager configuration file.
** 
** Table: Fields in the SQLFUPD Structure
** |----------------------------------------------------------------------|
** |Field Name|Data Type|  Description                                    |
** |----------|---------|-------------------------------------------------|
** |TOKEN     |UINT16   |  Specifies the configuration value to return or |
** |          |         |  update.                                        |
** |----------|---------|-------------------------------------------------|
** |PTRVALUE  |Pointer  |  A pointer to an application allocated buffer   |
** |          |         |  that holds the data specified by TOKEN.        |
** |----------|---------|-------------------------------------------------|
** 
** Valid data types for the token element are:
** Uint16 
** Unsigned 2-byte integer 
** Sint16 
** Signed 2-byte integer 
** Uint32 
** Unsigned 4-byte integer 
** Sint32 
** Signed 4-byte integer 
** Uint64 
** Unsigned 8-byte integer 
** double 
** 8-byte floating-point decimal 
** char(n) 
** String of length n (not including null termination). 
** 
** Valid entries for the SQLFUPD token element are listed below:
** 
** Table: Updatable Database Configuration Parameters
** |------------------------------------------------------------------------|
** | Parameter Name  | Token                     |  Token Value| Data Type  |
** |-----------------|---------------------------|-------------|------------|
** | app_ctl_heap_sz | SQLF_DBTN_APP_CTL_HEAP_SZ | 500        | Uint16      |
** | appgroup_mem_sz | SQLF_DBTN_APPGROUP_MEM_SZ | 800        | Uint32      |
** | appl_memory     | SQLF_DBTN_APPL_MEMORY     | 904        | Uint64      |
** | old_applheapsz  | SQLF_DBTN_APPLHEAPSZ      | 51         | Uint16      |
** | auto_del_rec_obj| SQLF_DBTN_AUTO_DEL_REC_OBJ| 908        | Uint16      |
** | autorestart     | SQLF_DBTN_AUTO_RESTART    | 25         | Uint16      |
** | avg_appls       | SQLF_DBTN_AVG_APPLS       | 47         | Uint16      |
** | blk_log_dsk_ful | SQLF_DBTN_BLK_LOG_DSK_FUL | 804        | Uint16      |
** | cf_db_mem_sz    | SQLF_DBTN_CF_DB_MEM_SZ    | 923        | Uint32      |
** | cf_catchup_trgt | SQLF_DBTN_CF_CATCHUP_TRGT | 970        | Uint16      |
** | cf_gbp_sz       | SQLF_DBTN_CF_GBP_SZ       | 920        | Uint32      |
** | cf_lock_sz      | SQLF_DBTN_CF_LOCK_SZ      | 921        | Uint32      |
** | cf_sca_sz       | SQLF_DBTN_CF_SCA_SZ       | 922        | Uint32      |
** | catalogcache_sz | SQLF_DBTN_CATALOGCACHE_SZ | 56         | Sint32      |
** | chngpgs_thresh  | SQLF_DBTN_CHNGPGS_THRESH  | 38         | Uint16      |
** | connect_proc    | SQLF_DBTN_CONNECT_PROC    | 954        | char(257)   |
** | database_memory | SQLF_DBTN_DATABASE_MEMORY | 803        | Uint64      |
** | db_mem_thresh   | SQLF_DBTN_DB_MEM_THRESH   | 849        | Uint16      |
** | dbheap          | SQLF_DBTN_DB_HEAP         | 58         | Uint64      |
** | decflt_rounding | SQLF_DBTN_DECFLT_ROUNDING | 913        | Uint16      |
** | dft_degree      | SQLF_DBTN_DFT_DEGREE      | 301        | Sint32      |
** | dft_extent_sz   | SQLF_DBTN_DFT_EXTENT_SZ   | 54         | Uint32      |
** | dft_loadrec_ses | SQLF_DBTN_DFT_LOADREC_SES | 42         | Sint16      |
** | dft_prefetch_sz | SQLF_DBTN_DFT_PREFETCH_SZ | 40         | Sint16      |
** | dft_queryopt    | SQLF_DBTN_DFT_QUERYOPT    | 57         | Sint32      |
** | dft_refresh_age | SQLF_DBTN_DFT_REFRESH_AGE | 702        | char(22)    |
** | dft_sqlmathwarn | SQLF_DBTN_DFT_SQLMATHWARN | 309        | Sint16      |
** | dir_obj_name    | SQLF_DBTN_DIR_OBJ_NAME    | 46         | char(255)   |
** | discover        | SQLF_DBTN_DISCOVER        | 308        | Uint16      |
** | dl_expint       | SQLF_DBTN_DL_EXPINT       | 350        | Sint32      |
** | dl_num_copies   | SQLF_DBTN_DL_NUM_COPIES   | 351        | Uint16      |
** | dl_time_drop    | SQLF_DBTN_DL_TIME_DROP    | 353        | Uint16      |
** | dl_token        | SQLF_DBTN_DL_TOKEN        | 602        | char(10)    |
** | dl_upper        | SQLF_DBTN_DL_UPPER        | 603        | Sint16      |
** | dl_w__expint    | SQLF_DBTN_DL_WT_IEXPINT   | 354        | Sint32      |
** | dlchktime       | SQLF_DBTN_DLCHKTIME       | 9          | Uint32      |
** | dyn_query_mgmt  | SQLF_DBTN_DYN_QUERY_MGMT  | 604        | Uint16      |
** | groupheap_ratio | SQLF_DBTN_GROUPHEAP_RATIO | 801        | Uint16      |
** | hadr_target_list| SQLF_DBTN_HADR_TARGET_LIST| 10114      | char(890)   |
** | hadr_ssl_label  | SQLF_DBTN_HADR_SSL_LABEL  | 10170      | char(127)   |
** | indexrec        | SQLF_DBTN_INDEXREC        | 30         | Uint16      |
** | indexsort       | SQLF_DBTN_INDEXSORT       | 35         | Uint16      |
** | locklist        | SQLF_DBTN_LOCK_LIST       | 704        | Uint64      |
** | locktimeout     | SQLF_DBTN_LOCKTIMEOUT     | 34         | Sint16      |
** | oldlogbufsz     | SQLF_DBTN_LOGBUFSZ        | 33         | Uint16      |
** | logbufsz        | SQLF_DBTN_LOGBUFSZ32      | 946        | Uint32      |
** | logfilsiz       | SQLF_DBTN_LOGFIL_SIZ      | 92         | Uint32      |
** | logprimary      | SQLF_DBTN_LOGPRIMARY      | 16         | Uint16      |
** | logretain       | SQLF_DBTN_LOG_RETAIN      | 23         | Uint16      |
** | logsecond       | SQLF_DBTN_LOGSECOND       | 17         | Uint16      |
** | max_connections | SQLF_DBTN_MAX_CONNECTIONS | 802        | Sint32      |
** | maxappls        | SQLF_DBTN_MAXAPPLS        | 6          | Uint16      |
** | maxfilop        | SQLF_DBTN_MAXFILOP        | 3          | Uint16      |
** | maxlocks        | SQLF_DBTN_MAXLOCKS        | 15         | Uint16      |
** | maxlog          | SQLF_DBTN_MAX_LOG         | 807        | Uint16      |
** | mincommit       | SQLF_DBTN_MINCOMMIT       | 32         | Uint16      |
** | mirrorlogpath   | SQLF_DBTN_MIRRORLOGPATH   | 806        | char(242)   |
** | newlogpath      | SQLF_DBTN_NEWLOGPATH      | 20         | char(242)   |
** | num_db_backups  | SQLF_DBTN_NUM_DB_BACKUPS  | 601        | Uint16      |
** | num_freqvalues  | SQLF_DBTN_NUM_FREQVALUES  | 36         | Uint16      |
** | num_iocleaners  | SQLF_DBTN_NUM_IOCLEANERS  | 37         | Uint16      |
** | num_ioservers   | SQLF_DBTN_NUM_IOSERVERS   | 39         | Uint16      |
** | numlogspan      | SQLF_DBTN_NUM_LOG_SPAN    | 808        | Uint16      |
** | num_quantiles   | SQLF_DBTN_NUM_QUANTILES   | 48         | Uint16      |
** | overflowlogpath | SQLF_DBTN_OVERFLOWLOGPATH | 805        | char(242)   |
** | pckcachesz      | SQLF_DBTN_PCKCACHE_SZ     | 505        | Uint32      |
** | pl_stack_trace  | SQLF_DBTN_PL_STACK_TRACE  | 10168      | Uint16      |
** | rec_his_retentn | SQLF_DBTN_REC_HIS_RETENTN | 43         | Sint16      |
** | restrict_access | SQLF_DBTN_RESTRICT_ACCESS | 852        | Sint32      |
** | self_tuning_mem | SQLF_DBTN_SELF_TUNING_MEM | 848        | Uint32      |
** | seqdetect       | SQLF_DBTN_SEQDETECT       | 41         | Uint16      |
** | sheapthres_shr  | SQLF_DBTN_SHEAPTHRES_SHR  | 802        | Uint32      |
** | softmax         | SQLF_DBTN_SOFTMAX         | 5          | Uint16      |
** | sortheap        | SQLF_DBTN_SORT_HEAP       | 52         | Uint32      |
** | stat_heap_sz    | SQLF_DBTN_STAT_HEAP_SZ    | 45         | Uint32      |
** | stmtheap        | SQLF_DBTN_STMTHEAP        | 53         | Uint16      |
** | trackmod        | SQLF_DBTN_TRACKMOD        | 703        | Uint16      |
** | tsm_mgmtclass   | SQLF_DBTN_TSM_MGMTCLASS   | 307        | char(30)    |
** | tsm_nodename    | SQLF_DBTN_TSM_NODENAME    | 306        | char(64)    |
** | tsm_owner       | SQLF_DBTN_TSM_OWNER       | 305        | char(64)    |
** | tsm_password    | SQLF_DBTN_TSM_PASSWORD    | 501        | char(64)    |
** | userexit        | SQLF_DBTN_USER_EXIT       | 24         | Uint16      |
** | util_heap_sz    | SQLF_DBTN_UTIL_HEAP_SZ    | 55         | Uint32      |
** | log_ddl_stmts   | SQLF_DBTN_LOG_DDL_STMTS   | 10110      | Uint16      |
** | log_appl_info   | SQLF_DBTN_LOG_APPL_INFO   | 10111      | Uint16      |
** | encrlib         | sqlf_dbtn_encrlib         | 10142      | char(254)   |
** | encropts        | sqlf_dbtn_encropts        | 10141      | char(1023)  |
** | dft_schemas_dcc | SQLF_DBTN_DFT_SCHEMAS_DCC | 10115      | Uint16      |
** | hadr_spool_limit| SQLF_DBTN_HADR_SPOOL_LIMIT| 10112      | Sint32      |
** | hadr_replay_delay| SQLF_DBTN_HADR_REPLAY_DELAY| 10119    | Sint32      |
** | extended_row_sz | SQLF_DBTN_EXTENDED_ROW_SZ | 10131      | Uint16      |
** | opt_direct_wrkld| SQLF_DBTN_OPT_DIRECT_WRKLD| 10127      | Uint16      |
** | page_age_trgt_mcr| SQLF_DBTN_SOFTMAX_MCR    | 10137      | Uint16      |
** | page_age_trgt_gcr| SQLF_DBTN_SOFTMAX_GCR    | 10136      | Uint16      |
** | applheapsz       | SQLF_DBTN_APPLHEAP_SZ    | 10157      | Uint64      |
** | dec_arithmetic   | SQLF_DBTN_DEC_ARITHMETIC | 10173      | char(6)     |
** |------------------------------------------------------------------------|
** 
** Valid values for indexrec (defined in sqlutil .h):
** - SQLF_INX_REC_SYSTEM (0)
**  - SQLF_INX_REC_REFERENCE (1 )
** - SQLF_INX_REC_RESTART (2)
** - SQLF_INX_REC_RESTART_NO_REDO (3)
** - SQLF_INX_REC_ACCESS_NO_REDO (4) 
** - SQLF_INX_REC_RESTART_ASYNC (5) 
** - SQLF_INX_REC_RESTART_ASCNOREDO (6) 
** 
** Valid values for logretain (defined in sqlutil.h):
** - SQLF_LOGRETAIN_NO (0)
** - SQLF_LOGRETAIN_RECOVERY (1)
** - SQLF_LOGRETAIN_CAPTURE (2) 
** Note: MINCOMMIT parameter has been deprecated.
** 
** Table: Non-updatable Database Configuration Parameters
** |-----------------------------------------------------------------------|
** | Parameter Name     |Token                      |Token Value|Data Type |
** |--------------------|---------------------------|-----------|----------|
** | backup_pending     | SQLF_DBTN_BACKUP_PENDING   | 112      |Uint16    |
** | codepage           | SQLF_DBTN_CODEPAGE         | 101      |Uint16    |
** | codeset            | SQLF_DBTN_CODESET          | 120      |char(9)   |
** |                    |                            |          |(see note |
** |                    |                            |          |1 below)  |
** | collate_info       | SQLF_DBTN_COLLATE_INFO     | 44       |char(260) |
** | db_collname        | SQLF_DBTN_DB_COLLNAME      | 850      |char(128) |
** | country            | SQLF_DBTN_COUNTRY          | 100      |Uint16    |
** | database_consistent| SQLF_DBTN_CONSISTENT       | 111      |Uint16    |
** | database_level     | SQLF_DBTN_DATABASE_LEVEL   | 124      |Uint16    |
** | log_retain_status  | SQLF_DBTN_LOG_RETAIN_STATUS| 114      |Uint16    |
** | loghead            | SQLF_DBTN_LOGHEAD          | 105      |char(12)  |
** | logpath            | SQLF_DBTN_LOGPATH          | 103      |char(242) |
** | multipage_alloc    | SQLF_DBTN_MULTIPAGE_ALLOC  | 506      |Uint16    |
** | numsegs            | SQLF_DBTN_NUMSEGS          | 122      |Uint16    |
** | release            | SQLF_DBTN_RELEASE          | 102      |Uint16    |
** | restore_pending    | SQLF_DBTN_RESTORE_PENDING  | 503      |Uint16    |
** | rollfwd_pending    | SQLF_DBTN_ROLLFWD_PENDING  | 113      |Uint16    |
** | territory          | SQLF_DBTN_TERRITORY        | 121      |char(5)   |
** |                    |                            |          |(see note |
** |                    |                            |          |2 below)  |
** | user_exit_status   | SQLF_DBTN_USER_EXIT_STATUS | 115      |Uint16    |
** | dft_overhead       | SQLF_DBTN_DFT_OVERHEAD     | 902      |double    |
** | dft_transferrate   | SQLF_DBTN_DFT_TRANSFERRATE | 903      |double    |
** | suspend_io         | SQLF_DBTN_SUSPEND_IO       | 953      |Uint16    |
** | encrypted_database | SQLF_DBTN_ENCRYPTED_DB     | 10148    |Uint16    |
** |-----------------------------------------------------------------------|
** Note:
** 1. char(17) on HP-UX and Solaris Operating Environment.
** 2. char(33) on HP-UX and Solaris Operating Environment.
** Valid entries for the SQLFUPD token element are listed below:
** 
** Table: Updatable Database Manager Configuration Parameters
** |----------------------------------------------------------------------|
** |Parameter Name       |Token                        |Token  |Data Type |
** |                     |                             |Value  |          |
** |---------------------|-----------------------------|-------|----------|
** | agent_stack_sz      | SQLF_KTN_AGENT_STACK_SZ     | 61    | Uint16   |
** | agentpri            | SQLF_KTN_AGENTPRI           | 26    | Sint16   |
** | alt_diagpath        | SQLF_KTN_ALT_DIAGPATH       | 941   | char(215)|
** | aslheapsz           | SQLF_KTN_ASLHEAPSZ          | 15    | Uint32   |
** | audit_buf_sz        | SQLF_KTN_AUDIT_BUF_SZ       | 312   | Sint32   |
** | authentication      | SQLF_KTN_AUTHENTICATION     | 78    | Uint16   |
** | backbufsz           | SQLF_KTN_BACKBUFSZ          | 18    | Uint32   |
** | cf_mem_sz           | SQLF_KTN_CF_MEM_SZ          | 960   | Uint32   |
** | cf_num_workers      | SQLF_KTN_CF_NUM_WORKERS     | 961   | Uint32   |
** | cf_num_conns        | SQLF_KTN_CF_NUM_CONNS       | 966   | Uint32   |
** | cf_diaglevel        | SQLF_KTN_CF_DIAGLEVEL       | 968   | Uint16   |
** | cf_diagpath         | SQLF_KTN_CF_DIAGPATH        | 969   | char(215)|
** | catalog_noauth      | SQLF_KTN_CATALOG_NOAUTH     | 314   | Uint16   |
** | comm_bandwidth      | SQLF_KTN_COMM_BANDWIDTH     | 307   | float    |
** | conn_elapse         | SQLF_KTN_CONN_ELAPSE        | 508   | Uint16   |
** | cpuspeed            | SQLF_KTN_CPUSPEED           | 42    | float    |
** | datalinks           | SQLF_KTN_DATALINKS          | 603   | Sint16   |
** | dft_account_str     | SQLF_KTN_DFT_ACCOUNT_STR    | 28    | char(25) |
** | dft_monswitches     | SQLF_KTN_DFT_MONSWITCHES    | 29    | Uint16   |
** | dft_mon_bufpool     | SQLF_KTN_DFT_MON_BUFPOOL    | 33    | Uint16   |
** | dft_mon_lock        | SQLF_KTN_DFT_MON_LOCK       | 34    | Uint16   |
** | dft_mon_sort        | SQLF_KTN_DFT_MON_SORT       | 35    | Uint16   |
** | dft_mon_stmt        | SQLF_KTN_DFT_MON_STMT       | 31    | Uint16   |
** | dft_mon_table       | SQLF_KTN_DFT_MON_TABLE      | 32    | Uint16   |
** | dft_mon_uow         | SQLF_KTN_DFT_MON_UOW        | 30    | Uint16   |
** | dftdbpath           | SQLF_KTN_DFTDBPATH          | 27    | char(215)|
** | diaglevel           | SQLF_KTN_DIAGLEVEL          | 64    | Uint16   |
** | diagpath            | SQLF_KTN_DIAGPATH           | 65    | char(215)|
** | diagsize            | SQLF_KTN_DIAGSIZE           | 939   | Uint64   |
** | dir_cache           | SQLF_KTN_DIR_CACHE          | 40    | Uint16   |
** | discover            | SQLF_KTN_DISCOVER           | 304   | Uint16   |
** | discover_comm       | SQLF_KTN_DISCOVER_COMM      | 305   | char(35) |
** | discover_inst       | SQLF_KTN_DISCOVER_INST      | 308   | Uint16   |
** | fcm_num_buffers     | SQLF_KTN_FCM_NUM_BUFFERS    | 503   | Uint32   |
** | fcm_num_channels    | SQLF_KTN_FCM_NUM_CHANNELS   | 902   | Uint32   |
** | fed_noauth          | SQLF_KTN_FED_NOAUTH         | 806   | Uint16   |
** | federated           | SQLF_KTN_FEDERATED          | 604   | Sint16   |
** | federated_async     | SQLF_KTN_FEDERATED_ASYNC    | 849   | Sint32   |
** | fileserver          | SQLF_KTN_FILESERVER         | 47    | char(48) |
** | health_mon          | SQLF_KTN_HEALTH_MON         | 804   | Uint16   |
** | indexrec            | SQLF_KTN_INDEXREC           | 20    | Uint16   |
** | initdari_jvm        | SQLF_KTN_INITDARI_JVM       | 602   | Sint16   |
** | instance_memory     | SQLF_KTN_INSTANCE_MEMORY    | 803   | Uint64   |
** | rstrt_light_mem     | SQLF_KTN_RSTRT_LIGHT_MEM    | 967   | Uint16   |
** | intra_parallel      | SQLF_KTN_INTRA_PARALLEL     | 306   | Sint16   |
** | ipx_socket          | SQLF_KTN_IPX_SOCKET         | 71    | char(4)  |
** | java_heap_sz        | SQLF_KTN_JAVA_HEAP_SZ       | 310   | Sint32   |
** | jdk11_path          | SQLF_KTN_JDK11_PATH         | 311   | char(255)|
** | keepfenced          | SQLF_KTN_KEEPFENCED         | 81    | Uint16   |
** | max_connretries     | SQLF_KTN_MAX_CONNRETRIES    | 509   | Uint16   |
** | max_coordagents     | SQLF_KTN_MAX_COORDAGENTS    | 501   | Sint32   |
** | max_querydegree     | SQLF_KTN_MAX_QUERYDEGREE    | 303   | Sint32   |
** | max_time_diff       | SQLF_KTN_MAX_TIME_DIFF      | 510   | Uint16   |
** | fenced_pool         | SQLF_KTN_FENCED_POOL        | 80    | Sint32   |
** | old_mon_heap_sz     | SQLF_KTN_MON_HEAP_SZ        | 79    | Uint16   |
** | nname               | SQLF_KTN_NNAME              | 7     | char(8)  |
** | notifylevel         | SQLF_KTN_NOTIFYLEVEL        | 605   | Sint16   |
** | num_initagents      | SQLF_KTN_NUM_INITAGENTS     | 500   | Uint32   |
** | num_initfenced      | SQLF_KTN_NUM_INITFENCED     | 601   | Sint32   |
** | num_poolagents      | SQLF_KTN_NUM_POOLAGENTS     | 502   | Sint32   |
** | numdb               | SQLF_KTN_NUMDB              | 6     | Uint16   |
** | objectname          | SQLF_KTN_OBJECTNAME         | 48    | char(48) |
** | query_heap_sz       | SQLF_KTN_QUERY_HEAP_SZ      | 49    | Sint32   |
** | restbufsz           | SQLF_KTN_RESTBUFSZ          | 19    | Uint32   |
** | resync_interval     | SQLF_KTN_RESYNC_INTERVAL    | 68    | Uint16   |
** | rqrioblk            | SQLF_KTN_RQRIOBLK           | 1     | Uint16   |
** | sheapthres          | SQLF_KTN_SHEAPTHRES         | 21    | Uint32   |
** | spm_log_file_sz     | SQLF_KTN_SPM_LOG_FILE_SZ    | 90    | Sint32   |
** | spm_max_resync      | SQLF_KTN_SPM_MAX_RESYNC     | 91    | Sint32   |
** | spm_name            | SQLF_KTN_SPM_NAME           | 92    | char(8)  |
** | start_stop_time     | SQLF_KTN_START_STOP_TIME    | 511   | Uint16   |
** | svcename            | SQLF_KTN_SVCENAME           | 24    | char(14) |
** | sysadm_group        | SQLF_KTN_SYSADM_GROUP       | 39    | char(16) |
** | sysctrl_group       | SQLF_KTN_SYSCTRL_GROUP      | 63    | char(16) |
** | sysmaint_group      | SQLF_KTN_SYSMAINT_GROUP     | 62    | char(16) |
** | tm_database         | SQLF_KTN_TM_DATABASE        | 67    | char(8)  |
** | tp_mon_name         | SQLF_KTN_TP_MON_NAME        | 66    | char(19) |
** | trust_allclnts      | SQLF_KTN_TRUST_ALLCLNTS     | 301   | Uint16   |
** | trust_clntauth      | SQLF_KTN_TRUST_CLNTAUTH     | 302   | Uint16   |
** | cf_transport_method | SQLF_KTN_CF_TRANSPORT_METHOD| 10126 | Uint16   |
** | keystore_location   | SQLF_KTN_KEYSTORE_LOCATION  | 10145 | char(255)|
** | keystore_type       | SQLF_KTN_KEYSTORE_TYPE      | 10147 | Uint16   |
** | mon_heap_sz         | SQLF_KTN_MONHEAP_SZ         | 10156 | Uint64   |
** |---------------------------------------------------------------------|
** Valid values for authentication (defined in sqlenv.h):
** - SQL_AUTHENTICATION_SERVER (0)
** - SQL_AUTHENTICATION_CLIENT (1)
** - SQL_AUTHENTICATION_DCS (2)
** - SQL_AUTHENTICATION_DCE (3)
** - SQL_AUTHENTICATION_SVR_ENCRYPT (4)
** - SQL_AUTHENTICATION_DCS_ENCRYPT (5)
** - SQL_AUTHENTICATION_DCE_SVR_ENC (6)
** - SQL_AUTHENTICATION_KERBEROS (7)
** - SQL_AUTHENTICATION_KRB_SVR_ENC (8)
** - SQL_AUTHENTICATION_NOT_SPEC (255) 
** 
** - SQLF_KTN_DFT_MONSWITCHES is a Uint16 parameter, the bits of which
** indicate the default monitor switch settings. This allows for the
** specification of a number of parameters at once. The individual bits
** making up this composite parameter are:
** Bit 1 (xxxx xxx1): dft_mon_uow
** Bit 2 (xxxx xx1x): dft_mon_stmt
** Bit 3 (xxxx x1xx): dft_mon_table
** Bit 4 (xxxx 1xxx): dft_mon_buffpool
** Bit 5 (xxx1 xxxx): dft_mon_lock
** Bit 6 (xx1x xxxx): dft_mon_sort
** 
** Valid values for discover (defined in sqlutil.h):
** - SQLF_DSCVR_KNOWN (1)
** - SQLF_DSCVR_SEARCH (2)
** 
** Valid values for indexrec (defined in sqlutil.h):
** - SQLF_INX_REC_SYSTEM (0)
** - SQLF_INX_REC_REFERENCE (1)
** - SQLF_INX_REC_RESTART (2)
** - SQLF_INX_REC_RESTART_NO_REDO (3)
** - SQLF_INX_REC_ACCESS_NO_REDO (4) 
** - SQLF_INX_REC_RESTART_ASYNC (5) 
** - SQLF_INX_REC_RESTART_ASCNOREDO (6) 
** 
** Valid values for trust_allclnts (defined in sqlutil.h):
** - SQLF_TRUST_ALLCLNTS_NO (0)
** - SQLF_TRUST_ALLCLNTS_YES (1)
** - SQLF_TRUST_ALLCLNTS_DRDAONLY (2)
** Valid values for cf_transport_method (defined in sqlutil.h):
** - SQL_CF_TRANSPORT_RDMA (0)
** Note: QUERY_HEAP_SZ parameter has been deprecated as of V95.
** 
** Table: Non-updatable Database Manager Configuration Parameters
** |---------------------------------------------------------------|
** |Parameter Name |Token            |Token Value|Data Type        |
** |---------------|-----------------|-----------|-----------------|
** |nodetype       |SQLF_KTN_NODETYPE|100        |Uint16           |
** |release        |SQLF_KTN_RELEASE |101        |Uint16           |
** |---------------------------------------------------------------|
** Valid values for nodetype (defined in sqlutil.h):
** - SQLF_NT_STANDALONE (0)
** - SQLF_NT_SERVER (1)
** - SQLF_NT_REQUESTOR (2)
** - SQLF_NT_STAND_REQ (3)
** - SQLF_NT_MPP (4)
** - SQLF_NT_SATELLITE (5)
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQL-FUPD.
**     05 SQL-TOKEN              PIC 9(4) COMP-5.
**     05 FILLER                 PIC X(2).
**     05 SQL-VALUE-PTR          USAGE IS POINTER.
** * 
*******************************************************************************/
SQL_STRUCTURE sqlfupd
{
   unsigned short  token;
   char            *ptrvalue;
};

/* Constants and structure used by sqlgadau and sqluadau.                     */
#define SQL_USER_AUTHORIZED                 1
#define SQL_USER_UNAUTHORIZED               0
#define SQL_AUTHORIZATION_SIZE_OLD          22
#define SQL_AUTHORIZATION_SIZE_V2           34
#define SQL_AUTHORIZATION_SIZE_V3           38
#define SQL_AUTHORIZATION_SIZE_V7           42
#define SQL_AUTHORIZATION_SIZE_V8           58
#define SQL_AUTHORIZATION_SIZE              62

/******************************************************************************
** sql_authorizations data structure
** This structure is used to return information after a call to the
** sqluadau API. The data type of all fields is SMALLINT. The first half
** of the following table contains authorities granted directly to a
** user. The second half of the table contains authorities granted to the
** groups to which a user belongs.
** 
** Table: Fields in the SQL-AUTHORIZATIONS Structure
** -----------------------------------------------------------------------
** |Field Name                  |  Description                            |
** |----------------------------|-----------------------------------------|
** |SQL_AUTHORIZATIONS_LEN      |  Size of structure.                     |
** |SQL_SYSADM_AUTH             |  SYSADM authority.                      |
** |SQL_SYSCTRL_AUTH            |  SYSCTRL authority.                     |
** |SQL_SYSMAINT_AUTH           |  SYSMAINT authority.                    |
** |SQL_DBADM_AUTH              |  DBADM authority.                       |
** |SQL_CREATETAB_AUTH          |  CREATETAB authority.                   |
** |SQL_CREATET_NOT_FENC_AUTH   |  CREATE_NOT_FENCED authority.           |
** |SQL_BINDADD_AUTH            |  BINDADD authority.                     |
** |SQL_CONNECT_AUTH            |  CONNECT authority.                     |
** |SQL_IMPLICIT_SCHEMA_AUTH    |  IMPLICIT_SCHEMA authority.             |
** |SQL_LOAD_AUTH               |  LOAD authority.                        |
** |SQL_SYSADM_GRP_AUTH         |  User belongs to a group which holds    |
** |                            |  SYSADM authority.                      |
** |SQL_SYSCTRL_GRP_AUTH        |  User belongs to a group which holds    |
** |                            |  SYSCTRL authority.                     |
** |SQL_SYSMAINT_GRP_AUTH       |  User belongs to a group which holds    |
** |                            |  SYSMAINT authority.                    |
** |SQL_DBADM_GRP_AUTH          |  User belongs to a group which holds    |
** |                            |  DBADM authority.                       |
** |SQL_CREATETAB_GRP_AUTH      |  User belongs to a group which holds    |
** |                            |  CREATETAB authority.                   |
** |SQL_CREATE_NON_FENC_GRP_AUTH|  User belongs to a group which holds    |
** |                            |  CREATE_NOT_FENCED authority.           |
** |SQL_BINDADD_GRP_AUTH        |  User belongs to a group which holds    |
** |                            |  BINDADD authority.                     |
** |SQL_CONNECT_GRP_AUTH        |  User belongs to a group which holds    |
** |                            |  CONNECT authority.                     |
** |SQL_IMPLICIT_SCHEMA_GRP_AUTH|  User belongs to a group which holds    |
** |                            |  IMPLICIT_SCHEMA authority.             |
** |SQL_LOAD_GRP_AUTH           |  User belongs to a group which holds    |
** |                            |  LOAD authority.                        |
** |SQL_CREATE_EXT_RTN_AUTH     |  CREATE_EXTERNAL_ROUTINE authority.     |
** |SQL_CREATE_EXT_RTN_GRP_AUTH |  User belongs to a group which holds    |
** |                            |  CREATE_EXTERNAL_ROUTINE authority.     |
** |SQL_QUIESCE_CONNECT_AUTH    |  QUIESCE CONNECT authority.             |
** |SQL_QUIESCE_CONNECT_GRP_AUTH|  User belongs to a group which holds    |
** |                            |  QUIESCE CONNECT authority.             |
** |SQL_SECURITY_ADMIN_AUTH     |  SECADM authority.                      |
** |SQL_SECURITY_ADMIN_GRP_AUTH |  User belongs to a group which holds    |
** |                            |  SECADM authority.                      |
** |SQL_SYSMON_AUTH             |  SYSMON authority.                      |
** |SQL_SYSMON_GRP_AUTH         |  User belongs to a group which holds    |
** |                            |  SYSMON authority.                      |
** |----------------------------|-----------------------------------------|
** |Note:                                                                 |
** |SYSADM, SYSMAINT, and SYSCTRL are only indirect authorities and cannot|
** |be granted directly to the user. They are available only through the  |
** |groups to which the user belongs.                                     |
** |----------------------------------------------------------------------|
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQL-AUTHORIZATIONS.
**     05 SQL-AUTHORIZATIONS-LEN PIC S9(4) COMP-5.
**     05 SQL-SYSADM-AUTH        PIC S9(4) COMP-5.
**     05 SQL-DBADM-AUTH         PIC S9(4) COMP-5.
**     05 SQL-CREATETAB-AUTH     PIC S9(4) COMP-5.
**     05 SQL-BINDADD-AUTH       PIC S9(4) COMP-5.
**     05 SQL-CONNECT-AUTH       PIC S9(4) COMP-5.
**     05 SQL-SYSADM-GRP-AUTH    PIC S9(4) COMP-5.
**     05 SQL-DBADM-GRP-AUTH     PIC S9(4) COMP-5.
**     05 SQL-CREATETAB-GRP-AUTH PIC S9(4) COMP-5.
**     05 SQL-BINDADD-GRP-AUTH   PIC S9(4) COMP-5.
**     05 SQL-CONNECT-GRP-AUTH   PIC S9(4) COMP-5.
**     05 SQL-SYSCTRL-AUTH       PIC S9(4) COMP-5.
**     05 SQL-SYSCTRL-GRP-AUTH   PIC S9(4) COMP-5.
**     05 SQL-SYSMAINT-AUTH      PIC S9(4) COMP-5.
**     05 SQL-SYSMAINT-GRP-AUTH  PIC S9(4) COMP-5.
**     05 SQL-CREATE-NOT-FENC-AUTH PIC S9(4) COMP-5.
**     05 SQL-CREATE-NOT-FENC-GRP-AUTH PIC S9(4) COMP-5.
**     05 SQL-IMPLICIT-SCHEMA-AUTH PIC S9(4) COMP-5.
**     05 SQL-IMPLICIT-SCHEMA-GRP-AUTH PIC S9(4) COMP-5.
**     05 SQL-LOAD-AUTH PIC S9(4) COMP-5.
**     05 SQL-LOAD-GRP-AUTH PIC S9(4) COMP-5.
** *
** 
*******************************************************************************/
SQL_STRUCTURE sql_authorizations
{
   short           sql_authorizations_len;
   short           sql_sysadm_auth;
   short           sql_dbadm_auth;
   short           sql_createtab_auth;
   short           sql_bindadd_auth;
   short           sql_connect_auth;
   short           sql_sysadm_grp_auth;
   short           sql_dbadm_grp_auth;
   short           sql_createtab_grp_auth;
   short           sql_bindadd_grp_auth;
   short           sql_connect_grp_auth;
   short           sql_sysctrl_auth;
   short           sql_sysctrl_grp_auth;
   short           sql_sysmaint_auth;
   short           sql_sysmaint_grp_auth;
   short           sql_create_not_fenc_auth;
   short           sql_create_not_fenc_grp_auth;
   short           sql_implicit_schema_auth;
   short           sql_implicit_schema_grp_auth;
   short           sql_load_auth;
   short           sql_load_grp_auth;
   short           sql_create_ext_rtn_auth;
   short           sql_create_ext_rtn_grp_auth;
   short           sql_quiesce_connect_auth;
   short           sql_quiesce_connect_grp_auth;
   short           sql_security_admin_auth;
   short           sql_security_admin_grp_auth;
   short           sql_library_admin_auth;
   short           sql_library_admin_grp_auth;
   short           sql_sysmon_auth;
   short           sql_sysmon_grp_auth;
};

/* Constants and structure used for backup and restore                        */
#define SQLU_MAX_TBS_NAME_LEN     18
#define SQLU_DB_DIR_LEN           215
#define SQLU_SHR_LIB_LEN          255
#define SQLU_MEDIA_LOCATION_LEN   255
#define SQLU_APPLID_LEN           32
#define SQLU_MAX_SESSIONS         999

/******************************************************************************
** sqlu_tablespace_entry data structure
** sqlu_tablespace_entry data structure parameters
** 
** reserve_len
** Input. Specifies the length in bytes of the tablespace_entry
** parameter.
** 
** tablespace_entry
** Input. The name of the table space to rollforward.
** 
** filler
** Filler used for proper alignment of data structure in memory.
** 
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_tablespace_entry
{
   sqluint32       reserve_len;
   char            tablespace_entry[SQLU_MAX_TBS_NAME_LEN+1];
   char            filler[1];
} sqlu_tablespace_entry;

/******************************************************************************
** sqlu_tablespace_bkrst_list data structure
** sqlu_tablespace_bkrst_list data structure parameters
** 
** num_entry
** Input. The number of structures contained in the list pointed to by the
** tablespace parameter.
** 
** tablespace
** Input. A pointer to a list of sqlu_tablespace_entry structures.
** 
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_tablespace_bkrst_list
{
   sqlint32        num_entry;
   struct sqlu_tablespace_entry *tablespace;
} sqlu_tablespace_bkrst_list;

/******************************************************************************
** sqlu_media_entry data structure
** Table: Fields in the SQLU-MEDIA-ENTRY Structure
** |---------------------------------------------------------------|
** |Field Name | Data Type| Description                            |
** |-----------|----------|----------------------------------------|
** |RESERVE_LEN| INTEGER  | Length of the media_entry field. For   |
** |           |          | languages other than C.                |
** |MEDIA_ENTRY| CHAR(215)| Path for a backup image used by the    |
** |           |          | backup and restore utilities.          |
** |-----------|----------|----------------------------------------|
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQLU-MEDIA-ENTRY.
**     05 SQL-MEDENT-LEN         PIC 9(9) COMP-5.
**     05 SQL-MEDIA-ENTRY        PIC X(215).
**     05 FILLER                 PIC X.
** * 
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_media_entry
{
   sqluint32       reserve_len;
   char            media_entry[SQLU_DB_DIR_LEN+1];
} sqlu_media_entry;

/******************************************************************************
** sqlu_vendor data structure
** Table: Fields in the SQLU-VENDOR Structure
** |---------------------------------------------------------------|
** |Field Name  |Data Type| Description                            |
** |------------|---------|----------------------------------------|
** |RESERVE_LEN1|INTEGER  | Length of the shr_lib field. For       |
** |            |         | languages other than C.                |
** |------------|---------|----------------------------------------|
** |SHR_LIB     |CHAR(255)| Name of a shared library supplied by   |
** |            |         | vendors for storing or retrieving data.|
** |------------|---------|----------------------------------------|
** |RESERVE_LEN2|INTEGER  | Length of the filename field. For      |
** |            |         | languages other than C.                |
** |------------|---------|----------------------------------------|
** |FILENAME    |CHAR(255)| File name to identify the load input   |
** |            |         | source when using a shared library.    |
** |------------|---------|----------------------------------------|
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQLU-VENDOR.
**     05 SQL-SHRLIB-LEN         PIC 9(9) COMP-5.
**     05 SQL-SHR-LIB            PIC X(255).
**     05 FILLER                 PIC X.
**     05 SQL-FILENAME-LEN       PIC 9(9) COMP-5.
**     05 SQL-FILENAME           PIC X(255).
**     05 FILLER                 PIC X.
** *
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_vendor
{
   sqluint32       reserve_len1;
   char            shr_lib[SQLU_SHR_LIB_LEN+1];
   sqluint32       reserve_len2;
   char            filename[SQLU_SHR_LIB_LEN+1];
} sqlu_vendor;

/******************************************************************************
** sqlu_location_entry data structure
** Table: Fields in the SQLU-LOCATION-ENTRY Structure
** |---------------------------------------------------------------|
** |Field Name    |Data Type|Description                           |
** |--------------|---------|--------------------------------------|
** |RESERVE_LEN   |INTEGER  |Length of the location_entry field.   |
** |              |         |For languages other than C.           |
** |LOCATION_ENTRY|CHAR(256)|Name of input data files for the load |
** |              |         |utility.                              |
** |--------------|---------|--------------------------------------|
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQLU-LOCATION-ENTRY.
**     05 SQL-LOCATION-LEN       PIC 9(9) COMP-5.
**     05 SQL-LOCATION-ENTRY     PIC X(255).
**     05 FILLER                 PIC X.
** *
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_location_entry
{
   sqluint32       reserve_len;
   char            location_entry[SQLU_MEDIA_LOCATION_LEN+1];
} sqlu_location_entry;

/******************************************************************************
** sqlu_statement_entry data structure
** Table: Fields in the SQLU-STATEMENT-ENTRY Structure
** |---------------------------------------------------------------|
** |Field Name|  Data Type|  Description                           |
** |----------|-----------|----------------------------------------|
** |LENGTH    |  INTEGER  |  Length of the data field.             |
** |PDATA     |  Pointer  |  Pointer to the SQL query.             |
** |----------|-----------|----------------------------------------|
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQLU-STATEMENT-ENTRY.
**     05 SQL-STATEMENT-LEN       PIC 9(9) COMP-5.
**     05 SQL-STATEMENT-ENTRY     USAGE IS POINTER.
** *
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_statement_entry
{
   sqluint32       length;
   char            *pEntry;
} sqlu_statement_entry;

/******************************************************************************
** sqlu_remotefetch_entry data structure
** Table: Fields in the SQLU-REMOTEFETCH-ENTRY Structure
** |--------------------------------------------------------------------|
** |Field Name       |  Data Type|  Description                         |
** |-----------------|-----------|--------------------------------------|
** |pDatabaseName    |  Pointer  |  Source Database Name.               |
** |iDatabaseNameLen |  INTEGER  |  Source Database Name Length         |
** |pUserID          |  Pointer  |  Pointer to UserID.                  |
** |iUserIDLen       |  INTEGER  |  UserID Length.                      |
** |pPassword        |  Pointer  |  Pointer to Password.                |
** |iPasswordLen     |  INTEGER  |  Password Length.                    |
** |pTableSchema     |  Pointer  |  Pointer to schema of source table.  |
** |iTableSchemaLen  |  INTEGER  |  Schema Length.                      |
** |pTableName       |  Pointer  |  Pointer to name of source table.    |
** |iTableNameLen    |  INTEGER  |  Source table name Length.           |
** |pStatement       |  Pointer  |  Pointer to name of statement.       |
** |iStatementLen    |  INTEGER  |  Statement Length.                   |
** |pIsolationLevel  |  Pointer  |  Pointer to isolation level.         |
** |                 |           | (default SQL_CURSPR_STAB).           |
** |piEnableParallel |  Pointer  |  Ptr to TRUE / FALSE (default TRUE ).|
** |-----------------|-----------|--------------------------------------|
** 
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_remotefetch_entry
{
   char            *pDatabaseName;
   sqluint32       iDatabaseNameLen;
   char            *pUserID;
   sqluint32       iUserIDLen;
   char            *pPassword;
   sqluint32       iPasswordLen;
   char            *pTableSchema;
   sqluint32       iTableSchemaLen;
   char            *pTableName;
   sqluint32       iTableNameLen;
   char            *pStatement;
   sqluint32       iStatementLen;
   sqluint32       *pIsolationLevel;
   sqluint32       *piEnableParallel;
} sqlu_remotefetch_entry;

/******************************************************************************
** sqlu_histFile data structure
** sqlu_histFile data structure parameters
** 
** nodeNum
** Input. Specifies which database partition this entry should be used for.
** 
** filenameLen
** Input. Length in bytes of filename.
** 
** filename
** Input. Path to the history file for this database partition. The path
** must end with a slash.
*******************************************************************************/
SQL_STRUCTURE sqlu_histFile
{
   SQL_PDB_NODE_TYPE nodeNum;          /* node number                         */
   unsigned short  filenameLen;        /* length of filename                  */
   char            filename[SQL_FILENAME_SZ+1]; /* name of the history file   */
};

/******************************************************************************
** sqlurf_newlogpath data structure
** sqlurf_newlogpath data structure parameters
** 
** nodenum
** Input. The number of the database partition that this structure details.
** 
** pathlen
** Input. The total length of the logpath field.
** 
** logpath
** Input. A fully qualified path to be used for a specific node for the
** rollforward operation.
** 
*******************************************************************************/
SQL_STRUCTURE sqlurf_newlogpath
{
   SQL_PDB_NODE_TYPE nodenum;          /* node number                         */
   unsigned short  pathlen;            /* length of new logpath               */
   char            logpath[SQL_LOGPATH_SZ+SQL_LOGFILE_NAME_SZ+1]; /* new      */
                                       /* overflow log path                   */
};

/******************************************************************************
** sqlurf_info data structure
** sqlurf_info data structure parameters
** 
** nodenum
** Output. The number of the database partition that this structure
** contains information for.
** 
** state
** Output. The current state of the database or tablespaces that were included
** in the rollfoward on a database partition.
** 
** nextarclog
** Output. If the rollforward has completed, this field will be empty. If the
** rollforward has not yet completed, this will be the name of the next log
** file which will be processed for the rollforward.
** 
** firstarcdel
** Output. The first log file replayed by the rollforward.
** 
** lastarcdel
** Output. The last log file replayed by the rollforward.
** 
** lastcommit
** Output. The time of the last committed transaction.
** 
*******************************************************************************/
SQL_STRUCTURE sqlurf_info
{
   SQL_PDB_NODE_TYPE nodenum;          /* node number                         */
   sqlint32        state;              /* state information                   */
   unsigned char   nextarclog[SQLUM_ARCHIVE_FILE_LEN+1]; /* next archive      */
                                       /* file needed                         */
   unsigned char   firstarcdel[SQLUM_ARCHIVE_FILE_LEN+1]; /* first archive    */
                                       /* file to be deleted                  */
   unsigned char   lastarcdel[SQLUM_ARCHIVE_FILE_LEN+1]; /* last archive      */
                                       /* file to be deleted                  */
   unsigned char   lastcommit[SQLUM_TIMESTAMP_LEN+1]; /* returned timestamp   */
};

/******************************************************************************
** sqlurf_stat data structure
*******************************************************************************/
SQL_STRUCTURE sqlurf_stat
{
   sqlint32        numNodes;
   struct sqlurf_info nodeInfo[SQL_PDB_MAX_NUM_NODE];
};

/******************************************************************************
** rfwd_input data structure
*******************************************************************************/
SQL_STRUCTURE rfwd_input
{
   sqluint32       version;            /* rollforward version                 */
   char            *pDbAlias;          /* database alias                      */
   unsigned short  CallerAction;       /* action                              */
   char            *pStopTime;         /* stop time                           */
   char            *pUserName;         /* user name                           */
   char            *pPassword;         /* password                            */
   char            *pOverflowLogPath;  /* overflow log path                   */
   unsigned short  NumChngLgOvrflw;    /* no. of changed overflow log paths   */
   struct sqlurf_newlogpath *pChngLogOvrflw; /* changed overflow log paths    */
   unsigned short  ConnectMode;        /* connect mode                        */
   struct sqlu_tablespace_bkrst_list *pTablespaceList; /* tablespace list     */
   short           AllNodeFlag;        /* all node flag                       */
   short           NumNodes;           /* size of nodelist                    */
   SQL_PDB_NODE_TYPE *pNodeList;       /* list of node numbers                */
   short           NumNodeInfo;        /* size of pNodeInfo in rfwd_output    */
   unsigned short  DlMode;             /* not used                            */
   char            *pReportFile;       /* not used                            */
   char            *pDroppedTblID;     /* dropped table id                    */
   char            *pExportDir;        /* dropped table export directory      */
};

/******************************************************************************
** grfwd_input data structure
*******************************************************************************/
SQL_STRUCTURE grfwd_input
{
   unsigned short  DbAliasLen;         /* length in bytes of DbAlias          */
   unsigned short  StopTimeLen;        /* length in bytes of StopTime         */
   unsigned short  UserNameLen;        /* length in bytes of UserName         */
   unsigned short  PasswordLen;        /* length in bytes of Password         */
   unsigned short  OvrflwLogPathLen;   /* length in bytes of OverflowLogPath  */
   unsigned short  ReportFileLen;      /* length in bytes of ReportFile       */
   sqluint32       Version;            /* rollforward version                 */
   char            *pDbAlias;          /* database alias                      */
   unsigned short  CallerAction;       /* action                              */
   char            *pStopTime;         /* stop time                           */
   char            *pUserName;         /* user name                           */
   char            *pPassword;         /* password                            */
   char            *pOverflowLogPath;  /* overflow log path                   */
   unsigned short  NumChngLgOvrflw;    /* no. of changed overflow log paths   */
   struct sqlurf_newlogpath *pChngLogOvrflw; /* changed overflow log paths    */
   unsigned short  ConnectMode;        /* connect mode                        */
   struct sqlu_tablespace_bkrst_list *pTablespaceList; /* tablespace list     */
   short           AllNodeFlag;        /* all node flag                       */
   short           NumNodes;           /* size of nodelist                    */
   SQL_PDB_NODE_TYPE *pNodeList;       /* list of node numbers                */
   short           NumNodeInfo;        /* size of pNodeInfo in rfwd_output    */
   unsigned short  DlMode;             /* not used                            */
   char            *pReportFile;       /* not used                            */
   char            *pDroppedTblID;     /* dropped table id                    */
   char            *pExportDir;        /* dropped table export directory      */
};

/******************************************************************************
** rfwd_output data structure
*******************************************************************************/
SQL_STRUCTURE rfwd_output
{
   char            *pApplicationId;    /* application id                      */
   sqlint32        *pNumReplies;       /* number of replies received          */
   struct sqlurf_info *pNodeInfo;      /* node reply info                     */
};

/* Media types                                                                */
#define SQLU_LOCAL_MEDIA 'L'           /* path/device                         */
#define SQLU_SERVER_LOCATION 'S'       /* remote file/device/named pipe       */
#define SQLU_CLIENT_LOCATION 'C'       /* local file/device/named pipe        */
#define SQLU_SQL_STMT 'Q'              /* SQL Statement                       */
#define SQLU_TSM_MEDIA 'A'             /* Tivoli Storage Manager              */
#define SQLU_XBSA_MEDIA 'X'            /* X/Open XBSA interface               */
#define SQLU_OTHER_MEDIA 'O'           /* vendor library                      */
#define SQLU_SNAPSHOT_MEDIA 'F'        /* Snapshot capable storage device     */
#define SQLU_SNAPSHOT_SCRIPT_MEDIA 'f' /* Scripted snapshot ACS interface     */
#define SQLU_REMOTEFETCH 'R'           /* remote fetch data                   */
#define SQLU_USER_EXIT 'U'             /* user exit                           */
#define SQLU_DISK_MEDIA 'D'            /* Generated only by vendors           */
#define SQLU_DISKETTE_MEDIA 'K'        /* Generated only by vendors           */
#define SQLU_NULL_MEDIA 'N'            /* Generated internally by DB2         */
#define SQLU_TAPE_MEDIA 'T'            /* Generated only by vendors           */
#define SQLU_PIPE_MEDIA 'P'            /* Generated only by vendors           */

/******************************************************************************
** sqlu_media_list_targets union
** Table: Fields in the SQLU-MEDIA-LIST-TARGETS Structure
** |-----------------------------------------------------------------|
** |Field Name  |Data Type|Description                               |
** |------------|---------|------------------------------------------|
** |MEDIA       |Pointer  |A pointer to an sqlu_media_entry          |
** |            |         |structure.                                |
** |------------|---------|------------------------------------------|
** |VENDOR      |Pointer  |A pointer to an sqlu_vendor structure.    |
** |------------|---------|------------------------------------------|
** |LOCATION    |Pointer  |A pointer to an sqlu_location_entry       |
** |            |         |structure.                                |
** |------------|---------|------------------------------------------|
** |PSTATEMENT  |Pointer  |A pointer to an sqlu_statement_entry      |
** |            |         |structure.                                |
** |------------|---------|------------------------------------------|
** |PREMOTEFETCH|Pointer  |A pointer to an sqlu_remotefetch_entry    |
** |            |         |structure.                                |
** |------------|---------|------------------------------------------|
** 
*******************************************************************************/
union sqlu_media_list_targets
{
   struct sqlu_media_entry        *media;      /* For media_type L - for      */
                                               /* BACKUP, RESTORE and LOAD    */
                                               /* copytarget, workdirectory,  */
                                               /* lobpaths, IMPORT and        */
                                               /* EXPORT lobpaths             */
   struct sqlu_vendor             *vendor;     /* For media_type O            */
   struct sqlu_location_entry     *location;   /* For media_type S - for      */
                                               /* LOAD and LOAD recovery      */
                                               /* For media type C - for      */
                                               /* EXPORT lobfile              */
   struct sqlu_statement_entry    *pStatement; /* For media_type S - for      */
                                               /* LOAD and LOAD recovery      */
   struct sqlu_remotefetch_entry  *pRemoteFetch; /* For media_type R - for    */
                                               /* LOAD and LOAD recovery      */
};

/******************************************************************************
** sqlu_media_list data structure
** This structure is used to pass information to the db2Load API.
** Table: Fields in the SQLU-MEDIA-LIST Structure
** |---------------------------------------------------------------|
** |Field Name|Data Type|Description                               |
** |----------|---------|------------------------------------------|
** |MEDIA_TYPE|CHAR(1)  |A character indicating media type.        |
** |----------|---------|------------------------------------------|
** |SESSIONS  |INTEGER  |Indicates the number of elements in the   |
** |          |         |array pointed to by the target field of   |
** |          |         |this structure.                           |
** |----------|---------|------------------------------------------|
** |TARGET    |Union    |This field is a pointer to one of four    |
** |          |         |types of structures. The type of          |
** |          |         |structure pointed to is determined by the |
** |          |         |value of the media_type field. For more   |
** |          |         |information on what to provide in this    |
** |          |         |field, see the appropriate API.           |
** |----------|---------|------------------------------------------|
** |FILLER    |CHAR(3)  |Filler used for proper alignment of data  |
** |          |         |structure in memory.                      |
** |----------|---------|------------------------------------------|
** 
** Valid values for MEDIA_TYPE (defined in sqlutil) are:
** 
** - SQLU_LOCAL_MEDIA 
** Local devices (tapes, disks, or diskettes) 
** - SQLU_SERVER_LOCATION 
** Server devices (tapes, disks, or diskettes; load only). Can be
** specified only for the piSourceList parameter.
** - SQLU_CLIENT_LOCATION 
** Client devices (files or named pipes; load only). Can be specified
** only for the piSourceList parameter. 
** - SQLU_SQL_STMT 
** SQL query (load only). Can be specified only for the piSourceList
** parameter. 
** - SQLU_TSM_MEDIA 
** TSM 
** - SQLU_OTHER_MEDIA 
** Vendor library 
** - SQLU_USER_EXIT 
** User exit (OS/2 only) 
** - SQLU_PIPE_MEDIA 
** Named pipe (for vendor APIs only) 
** - SQLU_DISK_MEDIA 
** Disk (for vendor APIs only) 
** - SQLU_DISKETTE_MEDIA 
** Diskette (for vendor APIs only) 
** - SQLU_TAPE_MEDIA 
** Tape (for vendor APIs only).
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQLU-MEDIA-LIST.
**     05 SQL-MEDIA-TYPE         PIC X.
**     05 SQL-FILLER             PIC X(3).
**     05 SQL-SESSIONS           PIC S9(9) COMP-5.
**     05 SQL-TARGET.
**         10 SQL-MEDIA          USAGE IS POINTER.
**         10 SQL-VENDOR         REDEFINES SQL-MEDIA
**         10 SQL-LOCATION       REDEFINES SQL-MEDIA
**         10 SQL-STATEMENT      REDEFINES SQL-MEDIA
**         10 FILLER             REDEFINES SQL-MEDIA
** *
*******************************************************************************/
typedef SQL_STRUCTURE sqlu_media_list
{
   char            media_type;
   char            filler[3];
   sqlint32        sessions;
   union sqlu_media_list_targets target;
} sqlu_media_list;

/* Struct used by sqlugtpi, sqlugrpi and sqlugrpn to store partitioning       */
/* information                                                                */
/******************************************************************************
** sqlpartkey data structure
** sqlpartkey data structure parameter descriptions
** 
** sqltype
** Input. Data type of the distribution key.
** 
** sqllen
** Input. Data length of the distribution key.
*******************************************************************************/
SQL_STRUCTURE sqlpartkey
{
   unsigned short  sqltype;    /* Date Type of Key                            */
   unsigned short  sqllen;     /* Data Length of Key                          */
};

/******************************************************************************
** sqlupi data structure
** This structure is used to store partitioning information, such as
** the distribution map and the distribution key of a table.
** 
** Table: Fields in the SQLUPI Structure
** |---------------------------------------------------------------|
** |Field Name|Data Type        |Description                       |
** |----------|-----------------|----------------------------------|
** |PMAPLEN   |UNSIGNED SHORT   |The length of the distribution    |
** |          |                 |map in bytes. For a single-node   |
** |          |                 |table, the value is               |
** |          |                 |sizeof(SQL_PDB_NODE_TYPE). For a  |
** |          |                 |multi-node table, the value is    |
** |          |                 |SQL_PDB_MAP_SIZE *                |
** |          |                 |sizeof(SQL_PDB_NODE_TYPE).        |
** |----------|-----------------|----------------------------------|
** |PMAP      |SQL_PDB_NODE_TYPE|The distribution map.             |
** |----------|-----------------|----------------------------------|
** |SQLD      |INTEGER          |The number of used SQLPARTKEY     |
** |          |                 |elements; that is, the number of  |
** |          |                 |key parts in a distribution key.  |
** |----------|-----------------|----------------------------------|
** |SQLPARTKEY|Structure        |The description of a distribution |
** |          |                 |column in a distribution key. The |
** |          |                 |maximum number of distribution    |
** |          |                 |columns is SQL_MAX_NUM_PART_KEYS. |
** |----------|-----------------|----------------------------------|
** 
** The following table shows the SQL data types and lengths for the
** SQLUPI data structure. The SQLTYPE column specifies the numeric
** value that represents the data type of an item.
** 
** Table: SQL Data Types and Lengths for the SQLUPI Structure
** |----------------------------------------------------------------|
** |Data type          |SQLTYPE (Nulls|SQLTYPE (Nulls|SQLLEN    |AIX|
** |                   |Not Allowed)  |Allowed)      |          |   |
** |-------------------|--------------|--------------|----------|---|
** |Date               |384           |385           |Ignored   |Yes|
** |-------------------|--------------|--------------|----------|---|
** |Time               |388           |389           |Ignored   |Yes|
** |-------------------|--------------|--------------|----------|---|
** |Timestamp          |392           |393           |Ignored   |Yes|
** |-------------------|--------------|--------------|----------|---|
** |Variable-length    |448           |449           |Length    |Yes|
** |character string   |              |              |of the    |   |
** |                   |              |              |string    |   |
** |-------------------|--------------|--------------|----------|---|
** |Fixed-length       |452           |453           |Length    |Yes|
** |character string   |              |              |of the    |   |
** |                   |              |              |string    |   |
** |-------------------|--------------|--------------|----------|---|
** |Long character     |456           |457           |Ignored   |No |
** |string             |              |              |          |   |
** |-------------------|--------------|--------------|----------|---|
** |Null-terminated    |460           |461           |Length    |Yes|
** |character string   |              |              |of the    |   |
** |                   |              |              |string    |   |
** |-------------------|--------------|--------------|----------|---|
** |Floating point     |480           |481           |Ignored   |Yes|
** |-------------------|--------------|--------------|----------|---|
** |Decimal            |484           |485           |Byte 1 =  |Yes|
** |                   |              |              |precision |   |
** |                   |              |              |Byte 2 =  |   |
** |                   |              |              |scale     |   |
** |-------------------|--------------|--------------|----------|---|
** |Large integer      |496           |497           |Ignored   |Yes|
** |-------------------|--------------|--------------|----------|---|
** |Small integer      |500           |501           |Ignored   |Yes|
** |-------------------|--------------|--------------|----------|---|
** |Variable-length    |464           |465           |Length    |Yes|
** |graphic string     |              |              |in        |   |
** |                   |              |              |double-   |   |
** |                   |              |              |byte      |   |
** |                   |              |              |characters|   |
** |-------------------|--------------|--------------|----------|---|
** |Fixed-length       |468           |469           |Length    |Yes|
** |graphic string     |              |              |in        |   |
** |                   |              |              |double-   |   |
** |                   |              |              |byte      |   |
** |                   |              |              |characters|   |
** |-------------------|--------------|--------------|----------|---|
** |Long graphic string|472           |473           |Ignored   |No |
** |-------------------|--------------|--------------|----------|---|
** 
*******************************************************************************/
SQL_STRUCTURE sqlupi
{
   unsigned short  pmaplen;    /* Length of partitioning map                  */
   SQL_PDB_NODE_TYPE pmap[SQL_PDB_MAP_SIZE]; /* Partitioning map              */
   unsigned short  sqld;       /* # of used SQLPARTKEY elements               */
   struct sqlpartkey sqlpartkey[SQL_MAX_NUM_PART_KEYS]; /* Partitioning Keys  */
};

/******************************************************************************
** sqluhtsp data structure
*******************************************************************************/
SQL_STRUCTURE sqluhtsp
{
   char      tablespace_name[SQLUH_TABLESPACENAME_SZ+1]; /* tablespace name   */
   char      filler;
};

/******************************************************************************
** sqluhadm data structure
*******************************************************************************/
SQL_STRUCTURE sqluhadm
{
   char      end_time[SQLUH_TIMESTAMP_SZ+1];   /* Completion time of          */
                                               /* operation                   */
   char      id[SQLUH_ID_SZ+1];                /* Unique object identifier    */
   struct sqlca event_sqlca;                   /* Result SQLCA from event     */
   struct sqlchar command;                     /* Command text                */
};

/******************************************************************************
** sqluhinfo data structure
*******************************************************************************/
SQL_STRUCTURE sqluhinfo
{
   char      sqluhinfoid[8];                   /* Eye catcher = 'SQLUHINF'    */
   sqlint32  sqluhinfobc;                      /* SQLUHINFO  in bytes=(   )   */
   short     sqln;                             /* # of tablespace elements    */
                                               /* available                   */
   short     sqld;                             /* # of used tablespace        */
                                               /* elements                    */
   char      operation[SQLUH_OP_SZ+1];         /* Type of event               */
   char      object[SQLUH_OBJ_SZ+1];           /* Granularity of operation    */
   char      object_part[SQLUH_OBJPART_SZ+1];  /* Start time + sequence       */
                                               /* number.                     */
   char      optype[SQLUH_OPTYPE_SZ+1];        /* More details of operation   */
   char      device_type[SQLUH_DEVTYPE_SZ+1];
   char      first_log[SQLUH_FIRSTLOG_SZ+1];
   char      last_log[SQLUH_LASTLOG_SZ+1];
   char      backup_id[SQLUH_BACKID_SZ+1];
   char      table_creator[SQLUH_TCREATE_SZ+1];
   char      table_name[SQLUH_TNAME_SZ+1];
   char      num_of_tablespaces[SQLUH_NUMTABLESPACE_SZ+1];
   char      location[SQLUH_LOC_SZ+1];
   char      comment[SQLUH_COMMENT_SZ+1];
   struct sqluhtsp tablespace[1];
};

/******************************************************************************
** Macro for size of sqluhinfo
*******************************************************************************/
#define   SQLUHINFOSIZE(n) \
   (sizeof(struct sqluhinfo) \
   + ((n > 0) ? ((n-1) * sizeof(struct sqluhtsp)) : 0))

/******************************************************************************
** Macro for size of sqluhadm
*******************************************************************************/
#define  SQLUHADMSIZE(n) \
   (sizeof(struct sqluhadm) \
   + ((n > 0) ? ((n-1) * sizeof(_SQLOLDCHAR)) : 0))

#define NATIVE_DLFF 0                  /* JFS support for Datalinks           */
#define DFS_DLFF   1                   /* DFS support for Datalinks           */
#define ACTIVE_DLFM 0                  /* Active Datalinks Manager            */
#define INACTIVE_DLFM 1                /* Deleted Datalinks Manager           */
/* Definitions needed for the sqlb api calls                                  */
/*                                                                            */
/* nb: 'tbs' is an abbreviaton for 'TABLESPACE'                               */

#define SQLB_SVERSION_SIZE 8           /* length of structure version         */
#define SQLB_MAX_TBS_NAME_SZ 128       /* maximum length of a table space     */
                                       /* name                                */
/* NB: this constant is set to the maximum size that is likely to be needed   */
/* in future.  Don't confuse this with SQLU_MAX_TBS_NAME_LEN which is set to  */
/* the current maximum size (18).                                             */

/* Externally visibile flags of a table space                                 */
/* storage manager class                                                      */
#define SQLB_TBS_SMS 0x1               /* System   Managed Space              */
#define SQLB_TBS_DMS 0x2               /* Database Managed Space              */
/* table space contents                                                       */
#define SQLB_TBS_ANY 0x0               /* All permanent data. Regular table   */
                                       /* space.                              */
#define SQLB_TBS_LARGE 0x20            /* All permanent data. Large table     */
                                       /* space.                              */
#define SQLB_TBS_LONG SQLB_TBS_LARGE   /* Kept for compatibility.             */
#define SQLB_TBS_SYSTMP 0x10           /* system temp data                    */
#define SQLB_TBS_USRTMP 0x40           /* user temp data                      */
#define SQLB_TBS_TMP SQLB_TBS_SYSTMP   /* kept for compatibility              */
/* other flags values                                                         */
#define SQLB_TBS_TMP_RECOVERY 0x20000  /* temp table space is reserved for    */
                                       /* completion of reorg recovery        */

/* CUR_COMMIT values                                                          */
#define SQLF_CUR_COMMIT_DISABLED 0     /* No scans will be compiled with      */
                                       /* currently committed                 */
#define SQLF_CUR_COMMIT_ON 1           /* All applicable cursor stability     */
                                       /* scans will be flagged at compile    */
                                       /* time as curently committed          */
#define SQLF_CUR_COMMIT_AVAILABLE 2    /* Applicable cursor stability scans   */
                                       /* will be flagged at compile time     */
                                       /* for currently committed only when   */
                                       /* the client explicitly requests it   */

/* DEC_TO_CHAR_FMT values                                                     */
#define SQLF_DEC_TO_CHAR_FMT_V95 0     /* DECIMAL to CHAR will have leading   */
                                       /* zeros and trailing decimal          */
                                       /* character, which is decided at      */
                                       /* compile time                        */
#define SQLF_DEC_TO_CHAR_FMT_NEW 1     /* DECIMAL to CHAR will not have       */
                                       /* leading zeros and trailing decimal  */
                                       /* character, which is decided at      */
                                       /* compile time                        */

/* The externally visible state of a table space is composed of the           */
/* hexadecimal sum of various of the following state values.  For example if  */
/* the state is 'quiesced exclusive' and 'load pending', the value would be   */
/* 0x0004 + 0x0008 which is 0x000c.                                           */
/*                                                                            */
/* You may use the tool db2tbst to do the reverse calculation (from 0x000c    */
/* to 'load pending' and 'quiesced exclusive', for example) which is more     */
/* complex. In our example, execute:                                          */
/*                                                                            */
/*  db2tbst 0x000c                                                            */
/*                                                                            */
/* which yields:                                                              */
/*                                                                            */
/* State = Quiesced Exclusive                                                 */
/*       + Load Pending                                                       */
#define SQLB_NORMAL                  0x0    /* Normal                         */
#define SQLB_QUIESCED_SHARE          0x1    /* Quiesced: SHARE                */
#define SQLB_QUIESCED_UPDATE         0x2    /* Quiesced: UPDATE               */
#define SQLB_QUIESCED_EXCLUSIVE      0x4    /* Quiesced: EXCLUSIVE            */
#define SQLB_LOAD_PENDING            0x8    /* Load pending                   */
#define SQLB_DELETE_PENDING          0x10   /* Delete pending                 */
#define SQLB_BACKUP_PENDING          0x20   /* Backup pending                 */
#define SQLB_ROLLFORWARD_IN_PROGRESS 0x40   /* Roll forward in progress       */
#define SQLB_ROLLFORWARD_PENDING     0x80   /* Roll forward pending           */
#define SQLB_RESTORE_PENDING         0x100  /* Restore pending                */
#define SQLB_RECOVERY_PENDING        0x100  /* Recovery pending (use SQLB     */
                                            /* RESTORE_PENDING)               */
#define SQLB_DISABLE_PENDING         0x200  /* Disable pending                */
#define SQLB_REORG_IN_PROGRESS       0x400  /* Reorg in progress              */
#define SQLB_BACKUP_IN_PROGRESS      0x800  /* Backup in progress             */
#define SQLB_STORDEF_PENDING         0x1000 /* storage must be defined        */
#define SQLB_RESTORE_IN_PROGRESS     0x2000 /* Restore in progress            */
#define SQLB_OFFLINE                 0x4000 /* Offline and not accessible     */
#define SQLB_DROP_PENDING            0x8000 /* Only action is to drop         */
#define SQLB_SUSPEND_WRITE           0x10000 /* No write is allowed           */
#define SQLB_LOAD_IN_PROGRESS        0x20000 /* Load in progress              */
#define SQLB_REDIST_IN_PROGRESS      0x40000 /* Redistribute in progress      */
#define SQLB_MOVE_IN_PROGRESS        0x80000 /* TBS extent movement in        */
                                            /* progress                       */
#define SQLB_EM_STARTED              0x100000 /* TBS extent movement has      */
                                            /* started                        */
#define SQLB_EM_TERMINATING          0x200000 /* TBS extent movement is       */
                                            /* terminating                    */
#define SQLB_STORDEF_ALLOWED         0x2000000 /* storage may be defined      */
#define SQLB_STORDEF_FINAL_VERSION   0x4000000 /* storDef is in 'final'       */
                                            /* state                          */
#define SQLB_STORDEF_CHANGED         0x8000000 /* storDef was changed prior   */
                                            /* to rollforward                 */
#define SQLB_REBAL_IN_PROGRESS       0x10000000 /* dms rebalancer is active   */
#define SQLB_PSTAT_DELETION          0x20000000 /* TBS deletion in progress   */
#define SQLB_PSTAT_CREATION          0x40000000 /* TBS creation in progress   */

#define SQLB_STATE_SET               0x8    /* For service use only.          */

/* provide information about the quiescers of a tablespace                    */
/******************************************************************************
** SQLB_QUIESCER_DATA data structure
** SQLB_QUIESCER_DATA data structure parameters
** 
** quiesceId
** Input. ID of the tablespace that the quiesced object was created in.
** 
** quiesceObject
** Input. Object ID of the quiesced object.
** 
*******************************************************************************/
SQL_STRUCTURE SQLB_QUIESCER_DATA
{
   sqluint32       quiesceId;          /* tablespace id of quiesceObject      */
   sqluint32       quiesceObject;      /* object in quiesceId                 */
};

#define SQLB_MAX_QUIESCERS 5           /* Maximum number of quiescers         */
#define SQLB_TBSPQRY_DATA_ID "TBSQ0097" /* SQLB_TBSQRY_DATA version id        */

/* Provide info about a tableSpace in a database                              */
/******************************************************************************
** SQLB_TBSPQRY_DATA data structure
** This structure is used to return table space data to an application
** program.
** 
** Table: Fields in the SQLB-TBSPQRY-DATA Structure
** -------------------------------------------------------------------------
** |Field Name    | Data Type    |Description                               |
** |--------------|--------------|------------------------------------------|
** |TBSPQVER      | CHAR(8)      |Structure version identifier.             |
** |--------------|--------------|------------------------------------------|
** |ID            | INTEGER      |Internal identifier for the table space.  |
** |--------------|--------------|------------------------------------------|
** |NAMELEN       | INTEGER      |Length of the table space name.           |
** |--------------|--------------|------------------------------------------|
** |NAME          | CHAR(128)    |Null-terminated name of the table space.  |
** |--------------|--------------|------------------------------------------|
** |TOTALPAGES    | INTEGER      |Number of pages specified by CREATE       |
** |              |              |TABLESPACE (DMS only).                    |
** |--------------|--------------|------------------------------------------|
** |USEABLEPAGES  | INTEGER      |TOTALPAGES minus overhead (DMS only).     |
** |              |              |This value is rounded down to the next    |
** |              |              |multiple of 4KB.                          |
** |--------------|--------------|------------------------------------------|
** |FLAGS         | INTEGER      |Bit attributes for the table space.       |
** |--------------|--------------|------------------------------------------|
** |PAGESIZE      | INTEGER      |Page size (in bytes) of the table space.  |
** |              |              |Currently fixed at 4KB.                   |
** |--------------|--------------|------------------------------------------|
** |EXTSIZE       | INTEGER      |Extent size (in pages) of the table space.|
** |--------------|--------------|------------------------------------------|
** |PREFETCHSIZE  | INTEGER      |Prefetch size.                            |
** |--------------|--------------|------------------------------------------|
** |NCONTAINERS   | INTEGER      |Number of containers in the table space.  |
** |--------------|--------------|------------------------------------------|
** |TBSSTATE      | INTEGER      |Table space states.                       |
** |--------------|--------------|------------------------------------------|
** |LIFELSN       | INTEGER      |Time stamp identifying the origin of the  |
** |              | (64-BIT)     |table space.                              |
** |--------------|--------------|------------------------------------------|
** |FLAGS2        | INTEGER      |Bit attributes for the table space.       |
** |--------------|--------------|------------------------------------------|
** |MINIMUMRECTIME| CHAR(27)     |Earliest point in time that may be        |
** |              |              |specified by point-in-time table space    |
** |              |              |rollforward.                              |
** |--------------|--------------|------------------------------------------|
** |STATECHNGOBJ  | INTEGER      |If TBSSTATE is SQLB_LOAD_PENDING or       |
** |              |              |SQLB_DELETE_PENDING, the object ID in     |
** |              |              |table space STATECHANGEID that caused the |
** |              |              |table space state to be set. Otherwise    |
** |              |              |zero.                                     |
** |--------------|--------------|------------------------------------------|
** |STATECHNGID   | INTEGER      |If TBSSTATE is SQLB_LOAD_PENDING or       |
** |              |              |SQLB_DELETE_PENDING, the table space ID   |
** |              |              |of the object STATECHANGEOBJ that caused  |
** |              |              |the table space state to be set.          |
** |              |              |Otherwise zero.                           |
** |--------------|--------------|------------------------------------------|
** |NQUIESCERS    | INTEGER      |If TBSSTATE is SQLB_QUIESCED_SHARE,       |
** |              |              |UPDATE, or EXCLUSIVE, the number of       |
** |              |              |quiescers of the table space and the      |
** |              |              |number of entries in QUIESCERS.           |
** |--------------|--------------|------------------------------------------|
** |QUIESCER      |Array of      |Each array entry consists of the quiesce  |
** |              |SQLB_QUIESCER_|data for a quiesced object.               |
** |              |DATA          |                                          |
** |              |structures    |                                          |
** |--------------|--------------|------------------------------------------|
** |FSCACHING     | UNSIGNED CHAR|File system caching policy to support     |
** |              |              |Direct I/O.  This is a 31-bit field.      |
** |--------------|--------------|------------------------------------------|
** |RESERVED      | CHAR(31)     |Reserved for future use.                  |
** |--------------|--------------|------------------------------------------|
** 
** pad
** Reserved. Used for structure alignment and should not be populated by
** user data.
** 
** pad1
** Reserved. Used for structure alignment and should not be populated by
** user data.
** 
** Possible values for FLAGS (defined in sqlutil) are:
** 
** - SQLB_TBS_SMS
** System Managed Space 
** - SQLB_TBS_DMS
** Database Managed Space 
** - SQLB_TBS_ANY
** Regular contents 
** - SQLB_TBS_LONG
** Long field data 
** - SQLB_TBS_SYSTMP
** System temporary data. 
** - SQLB_TBS_USRTMP
** User temporary data. 
** 
** Possible values for TBSSTATE (defined in sqlutil) are:
** 
** - SQLB_NORMAL
** Normal 
** - SQLB_QUIESCED_SHARE
** Quiesced: SHARE 
** - SQLB_QUIESCED_UPDATE
** Quiesced: UPDATE 
** - SQLB_QUIESCED_EXCLUSIVE
** Quiesced: EXCLUSIVE 
** - SQLB_LOAD_PENDING
** Load pending 
** - SQLB_DELETE_PENDING
** Delete pending 
** - SQLB_BACKUP_PENDING
** Backup pending 
** - SQLB_ROLLFORWARD_IN_PROGRESS
** Roll forward in progress 
** - SQLB_ROLLFORWARD_PENDING
** Roll forward pending 
** - SQLB_RESTORE_PENDING
** Restore pending 
** - SQLB_DISABLE_PENDING
** Disable pending 
** - SQLB_REORG_IN_PROGRESS
** Reorganization in progress 
** - SQLB_BACKUP_IN_PROGRESS
** Backup in progress 
** - SQLB_STORDEF_PENDING
** Storage must be defined 
** - SQLB_RESTORE_IN_PROGRESS
** Restore in progress 
** - SQLB_STORDEF_ALLOWED
** Storage may be defined 
** - SQLB_STORDEF_FINAL_VERSION
** Storage definition is in 'final' state 
** - SQLB_STORDEF_CHANGED
** Storage definition was changed prior to roll forward 
** - SQLB_REBAL_IN_PROGRESS
** DMS rebalancer is active 
** - SQLB_PSTAT_DELETION
** Table space deletion in progress 
** - SQLB_PSTAT_CREATION
** Table space creation in progress. 
** 
** Possible values for FLAGS2 (defined in sqlutil) are:
** 
** - SQLB_STATE_SET
** For service use only. 
** 
** COBOL Structure
** 
** * File: sqlutbsp.cbl
** 01 SQLB-TBSPQRY-DATA.
**     05 SQL-TBSPQVER           PIC X(8).
**     05 SQL-ID                 PIC 9(9) COMP-5.
**     05 SQL-NAME-LEN           PIC 9(9) COMP-5.
**     05 SQL-NAME               PIC X(128).
**     05 SQL-TOTAL-PAGES        PIC 9(9) COMP-5.
**     05 SQL-USEABLE-PAGES      PIC 9(9) COMP-5.
**     05 SQL-FLAGS              PIC 9(9) COMP-5.
**     05 SQL-PAGE-SIZE          PIC 9(9) COMP-5.
**     05 SQL-EXT-SIZE           PIC 9(9) COMP-5.
**     05 SQL-PREFETCH-SIZE      PIC 9(9) COMP-5.
**     05 SQL-N-CONTAINERS       PIC 9(9) COMP-5.
**     05 SQL-TBS-STATE          PIC 9(9) COMP-5.
**     05 SQL-LIFE-LSN           PIC 9(18) COMP-5.
**     05 SQL-FLAGS2             PIC 9(9) COMP-5.
**     05 SQL-MINIMUM-REC-TIME   PIC X(26).
**     05 FILLER                 PIC X.
**     05 SQL-PAD1               PIC X(1).
**     05 SQL-STATE-CHNG-OBJ     PIC 9(9) COMP-5.
**     05 SQL-STATE-CHNG-ID      PIC 9(9) COMP-5.
**     05 SQL-N-QUIESCERS        PIC 9(9) COMP-5.
**     05 SQL-QUIESCER OCCURS 5 TIMES.
**         10 SQL-QUIESCE-ID     PIC 9(9) COMP-5.
**         10 SQL-QUIESCE-OBJECT PIC 9(9) COMP-5.
**     05 SQL-FSCACHING          PIC X(1).
**     05 SQL-RESERVED           PIC X(31).
** * 
** 
*******************************************************************************/
SQL_STRUCTURE SQLB_TBSPQRY_DATA
{
   char            tbspqver[SQLB_SVERSION_SIZE]; /* version                   */
   sqluint32       id;                 /* internal id for the pool            */
   sqluint32       nameLen;            /* length of the name (for cobol &     */
                                       /* other nonC lang.)                   */
   char            name[SQLB_MAX_TBS_NAME_SZ]; /* NUL terminated name         */
   sqluint32       totalPages;         /* DMS : Pages specified by CREATE     */
                                       /* TABLESPACE.                         */
                                       /* SMS : N/A                           */
   sqluint32       useablePages;       /* DMS : totalPages - overhead         */
                                       /* SMS : N/A                           */
   sqluint32       flags;              /* bit attributes for the pool --      */
                                       /* includes 'class' & other stuff to   */
                                       /* be defined                          */
   sqluint32       pageSize;           /* pagesize of tablespace (in bytes)   */
                                       /* .. one of 4K, 8K, 16K, or 32K       */
   sqluint32       extSize;            /* extent size (in pages)              */
   sqluint32       prefetchSize;       /* prefetch size                       */
   sqluint32       nContainers;        /* number of containers                */
   sqluint32       tbsState;           /* SQLB_NORMAL, SQLB_LOAD_PENDING,     */
                                       /* etc.                                */
   sqluint64       lifeLSN;            /* 'timestamp' identifying the origin  */
                                       /* of the tbs                          */
   sqluint32       flags2;             /* bit attributes for the pool         */
   char            minimumRecTime[SQL_STAMP_DEF_STRLEN+1]; /* Minimum         */
                                       /* Recovery Time                       */
   char            pad1[1];            /* for alignment                       */
   sqluint32       StateChngObj;       /* For Load or Delete Pending          */
   sqluint32       StateChngID;        /* For Load or Delete Pending          */
   sqluint32       nQuiescers;         /* Number of queiscers                 */
   struct SQLB_QUIESCER_DATA quiescer[SQLB_MAX_QUIESCERS]; /* quiescer info   */
   unsigned char   fsCaching;          /* File system caching policy          */
   char            reserved[31];       /* for future use                      */
};

/* container types                                                            */
#define SQLB_CONT_PATH 0               /* SMS: directory path specs           */
#define SQLB_CONT_DISK_PAGE_TAG 1      /* DMS: a 'raw' or 'device' spec, tag  */
                                       /* size = one page                     */
#define SQLB_CONT_FILE_PAGE_TAG 2      /* DMS: a 'cooked file' -> file spec,  */
                                       /* tag size = one page                 */
#define SQLB_CONT_DISK_EXTENT_TAG 5    /* DMS: a 'raw' or 'device' spec, tag  */
                                       /* size = one extent                   */
#define SQLB_CONT_FILE_EXTENT_TAG 6    /* DMS: a 'cooked file' -> file spec,  */
                                       /* tag size = one extent               */

/* pre-version 8 container types - kept for compatibility                     */
#define SQLB_CONT_DISK         SQLB_CONT_DISK_PAGE_TAG
#define SQLB_CONT_FILE         SQLB_CONT_FILE_PAGE_TAG
#define SQLB_CONT_STRIPED_DISK SQLB_CONT_DISK_EXTENT_TAG
#define SQLB_CONT_STRIPED_FILE SQLB_CONT_FILE_EXTENT_TAG

/* provide information about the containers on which tablespaces are based    */
/******************************************************************************
** SQLB_TBSCONTQRY_DATA data structure
** This structure is used to return container data to an application
** program.
** 
** Table: Fields in the SQLB-TBSCONTQRY-DATA Structure
** ----------------------------------------------------------------------
** |Field Name  |Data Type|Description                                   |
** |------------|---------|----------------------------------------------|
** |ID          |INTEGER  |Container identifier.                         |
** |------------|---------|----------------------------------------------|
** |NTBS        |INTEGER  |Always 1.                                     |
** |------------|---------|----------------------------------------------|
** |TBSID       |INTEGER  |Table space identifier.                       |
** |------------|---------|----------------------------------------------|
** |NAMELEN     |INTEGER  |Length of the container name (for languages   |
** |            |         |other than C).                                |
** |------------|---------|----------------------------------------------|
** |NAME        |CHAR(256)|Container name.                               |
** |------------|---------|----------------------------------------------|
** |UNDERDBDIR  |INTEGER  |Either 1 (container is under the DB directory)|
** |            |         |or 0 (container is not under the DB directory)|
** |------------|---------|----------------------------------------------|
** |CONTTYPE    |INTEGER  |Container type.                               |
** |------------|---------|----------------------------------------------|
** |TOTALPAGES  |INTEGER  |Total number of pages occupied by the table   |
** |            |         |space container.                              |
** |------------|---------|----------------------------------------------|
** |USEABLEPAGES|INTEGER  |For DMS, TOTALPAGES minus overhead. For SMS,  |
** |            |         |equal to TOTALPAGES.                          |
** |------------|---------|----------------------------------------------|
** |OK          |INTEGER  |Either 1 (container is accessible) or 0       |
** |            |         |(container is inaccessible). Zero indicates   |
** |            |         |an abnormal situation that usually requires   |
** |            |         |the attention of the database administrator.  |
** |------------|---------|----------------------------------------------|
** 
** Possible values for CONTTYPE (defined in sqlutil) are:
** - SQLB_CONT_PATH
** Specifies a directory path (SMS only). 
** - SQLB_CONT_DISK
** Specifies a raw device (DMS only). 
** - SQLB_CONT_FILE
** Specifies a file (DMS only). 
** 
** COBOL Structure
** 
** * File: sqlutbcq.cbl
** 01 SQLB-TBSCONTQRY-DATA.
**     05 SQL-ID                 PIC 9(9) COMP-5.
**     05 SQL-N-TBS              PIC 9(9) COMP-5.
**     05 SQL-TBS-ID             PIC 9(9) COMP-5.
**     05 SQL-NAME-LEN           PIC 9(9) COMP-5.
**     05 SQL-NAME               PIC X(256).
**     05 SQL-UNDER-DBDIR        PIC 9(9) COMP-5.
**     05 SQL-CONT-TYPE          PIC 9(9) COMP-5.
**     05 SQL-TOTAL-PAGES        PIC 9(9) COMP-5.
**     05 SQL-USEABLE-PAGES      PIC 9(9) COMP-5.
**     05 SQL-OK                 PIC 9(9) COMP-5.
** * 
** 
*******************************************************************************/
SQL_STRUCTURE SQLB_TBSCONTQRY_DATA
{
   sqluint32       id;                 /* container id                        */
   sqluint32       nTbs;               /* num table spaces sharing this       */
                                       /* container (is always 1 for DMS      */
                                       /* tablespaces)                        */
   sqluint32       tbsID;              /* tableSpace id, when 'nTbs' is 1     */
   sqluint32       nameLen;            /* length of name (for non-C lang.)    */
   char            name[SQLB_MAX_CONTAIN_NAME_SZ]; /* null term. name         */
   sqluint32       underDBDir;         /* 1 if container is under the DB      */
                                       /* directory, 0 if not                 */
   sqluint32       contType;           /* SQLB_CONT_PATH/DISK/FILE            */
   sqluint32       totalPages;         /* DMS : Pages specified by CREATE     */
                                       /* TABLESPACE. SMS : N/A               */
   sqluint32       useablePages;       /* DMS : totalPages - overhead SMS :   */
                                       /* N/A                                 */
   sqluint32       ok;                 /* 1 if container is accessible, 0 if  */
                                       /* there is a problem                  */
};

/* provide statistics on a tablespace                                         */
/* BETA NOTE: currently, we only provide stats on DMS tablespaces             */
/* SRSFIX: determine what SMS support to ship with V2                         */
/******************************************************************************
** SQLB_TBS_STATS data structure
** This structure is used to return additional table space statistics to
** an application program.
** 
** Table: Fields in the SQLB-TBS-STATS Structure
** ----------------------------------------------------------------------
** |Field Name   |Data Type|Description                                 |
** |-------------|---------|--------------------------------------------|
** |TOTALPAGES   |INTEGER  |Total operating system space occupied by the|
** |             |         |table space (in 4KB pages). For DMS, this is|
** |             |         |the sum of the container sizes (including   |
** |             |         |overhead). For SMS, this is the sum of all  |
** |             |         |file space used for the tables stored in    |
** |             |         |this table space. This is the only piece of |
** |             |         |information returned for SMS table spaces;  |
** |             |         |the other fields are set to this value or   |
** |             |         |zero.                                       |
** |-------------|---------|--------------------------------------------|
** |USEABLEPAGES |INTEGER  |For DMS, equal to TOTALPAGES minus (overhead|
** |             |         |plus partial extents). For SMS, equal to    |
** |             |         |TOTALPAGES.                                 |
** |-------------|---------|--------------------------------------------|
** |USEDPAGES    |INTEGER  |For DMS, the total number of pages in use.  |
** |             |         |For SMS, equal to TOTALPAGES.               |
** |-------------|---------|--------------------------------------------|
** |FREEPAGES    |INTEGER  |For DMS, equal to USEABLEPAGES minus        |
** |             |         |USEDPAGES. For SMS, not applicable.         |
** |-------------|---------|--------------------------------------------|
** |HIGHWATERMARK|INTEGER  |For DMS, the high water mark is the current |
** |             |         |"end" of the table space address space. In  |
** |             |         |other words, the page number of the first   |
** |             |         |free extent following the last allocated    |
** |             |         |extent of a table space.                    |
** |             |         |                                            |
** |-------------|---------|--------------------------------------------|
** |Note that this is not really a "high water mark", but rather a      |
** |"current water mark", since the value can decrease. For SMS, this is|
** |not applicable.                                                     |
** |--------------------------------------------------------------------|
** 
** During a table space rebalance, the number of useable pages will
** include pages for the newly added container, but these new pages
** will not be reflected in the number of free pages until the rebalance
** is complete. When a table space rebalance is not taking place, the
** number of used pages plus the number of free pages will equal the
** number of useable pages.
** 
** COBOL Structure
** 
** * File: sqlutil.cbl
** 01 SQLB-TBS-STATS.
**     05 SQL-TOTAL-PAGES        PIC 9(9) COMP-5.
**     05 SQL-USEABLE-PAGES      PIC 9(9) COMP-5.
**     05 SQL-USED-PAGES         PIC 9(9) COMP-5.
**     05 SQL-FREE-PAGES         PIC 9(9) COMP-5.
**     05 SQL-HIGH-WATER-MARK    PIC 9(9) COMP-5.
** * 
** 
*******************************************************************************/
SQL_STRUCTURE SQLB_TBS_STATS
{
   sqluint32       totalPages;         /* DMS : Pages specified by CREATE     */
                                       /* TABLESPACE.                         */
                                       /* SMS : Pages of all files in the     */
                                       /* directories.                        */
   sqluint32       useablePages;       /* DMS : totalPages - overhead         */
                                       /* SMS : same as totalPages            */
   sqluint32       usedPages;          /* DMS : used and allocated pages in   */
                                       /* the pool                            */
                                       /* SMS : same as totalPages            */
   sqluint32       freePages;          /* DMS : useablePages - usedPages      */
                                       /* SMS : N/A                           */
   sqluint32       highWaterMark;      /* DMS : high water mark of used page  */
                                       /* number                              */
                                       /* SMS : N/A                           */
};

/* Function proto-types: 'sqlb' prefix for internal use. All functions        */
/* require a database connection, and return info about that database.        */

/* stpq - Single TableSpace Query                                             */
/******************************************************************************
** sqlbstpq API
** Retrieves information about a single currently defined table space.
** 
** Scope
** 
** In a partitioned database environment, only the table spaces on the current
** database partition are listed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - load
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbstpq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** TablespaceId
** 
** Input. Identifier for the table space which is to be queried.
** 
** pTablespaceData
** 
** Input and output. Pointer to a user-supplied SQLB_TBSPQRY_DATA structure
** where the table space information will be placed upon return. The caller
** of this API must initialize the structure and set TBSPQVER to
** SQLB_TBSPQRY_DATA_ID (in sqlutil).
** 
** reserved
** Input. Always SQLB_RESERVED1.
** 
** Usage notes
** 
** This API retrieves information about a single table space if the table space
** identifier to be queried is known. This API provides an alternative to
** the more expensive OPEN TABLESPACE QUERY, FETCH, and CLOSE combination of
** APIs, which must be used to scan for the desired table space when the table
** space identifier is not known in advance. The table space IDs can be found
** in the system catalogs. No agent snapshot is taken; since there is only one
** entry to return, it is returned directly.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Single Tablespace Query   */
  sqlbstpq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 TablespaceId,                       /* in: tableSpace id         */
   struct SQLB_TBSPQRY_DATA * pTablespaceData,   /* out: tableSpace data      */
   sqluint32 reserved);                          /* in: SQLB_RESERVED1        */

/* otsq - Open TableSpace Query -> use for retrieving a full list             */
#define SQLB_OPEN_TBS_ALL 0x0                    /* all tablespaces in        */
                                                 /* database                  */
#define SQLB_OPEN_TBS_RESTORE 0x1                /* all tablespaces my agent  */
                                                 /* is restoring              */
#define SQLB_OPEN_TBS_STORDEF 0x2                /* all tablespaces where     */
                                                 /* storage definition is     */
                                                 /* allowed                   */
#define SQLB_OPEN_TBS_RESERVED 0x4               /* reserved                  */
/******************************************************************************
** sqlbotsq API
** Prepares for a table space query operation, and returns the number of table
** spaces currently in the database.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - load
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbotsq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** TablespaceQueryOptions
** Input. Indicates which table spaces to process. Valid values (defined in
** sqlutil) are:
** - SQLB_OPEN_TBS_ALL
** Process all the table spaces in the database.
** - SQLB_OPEN_TBS_RESTORE
** Process only the table spaces that the user's agent is restoring.
** 
** pNumTablespaces
** Output. The number of table spaces in the connected database.
** 
** Usage notes
** 
** This API is normally followed by one or more calls to sqlbftpq, and then
** by one call to sqlbctsq.
** 
** An application can use the following APIs to fetch information about the
** currently defined table spaces:
** 
** - sqlbstpq
** Fetches information about a given table space. Only one table space entry is
** returned (into a space provided by the caller). Use this API when the table
** space identifier is known, and information about only that table space is
** desired.
** 
** - sqlbmtsq
** Fetches information about all table spaces. The API allocates the space
** required to hold the information for all table spaces, and returns a pointer
** to this information. Use this API to scan the list of table spaces when
** searching for specific information. Using this API is identical to calling
** the three APIs below, except that this API automatically allocates the
** memory for the output information. A call to this API must be followed by
** a call to sqlefmem to free the memory.
** - sqlbotsq
** - sqlbftpq
** - sqlbctsq
** 
** These three APIs function like an SQL cursor, in that they use the
** OPEN/FETCH/CLOSE paradigm. The caller must provide the output area for the
** fetch. Unlike an SQL cursor, only one table space query may be active at a
** time. Use this set of APIs to scan the list of table spaces when searching
** for specific information. This set of APIs allows the user to control the
** memory requirements of an application (compared with sqlbmtsq).
** 
** When sqlbotsq is called, a snapshot of the current table space information is
** buffered in the agent servicing the application. If the application issues a
** second table space query call (sqlbmtsq or sqlbotsq), this snapshot is
** replaced with refreshed information.
** 
** No locking is performed, so the information in the buffer may not reflect
** more recent changes made by another application. The information is not
** part of a transaction.
** 
** There is one snapshot buffer for table space queries and another for table
** space container queries. These buffers are independent of one another.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Open Tablespace Query     */
  sqlbotsq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 TablespaceQueryOptions,             /* in: processing options:   */
                                                 /* SQLB_TBS_OPEN_xxx         */
   sqluint32 * pNumTablespaces);                 /* out: # tablespaces        */
                                                 /* defined in db             */

/* ftpq - Fetch TableSpace Query -> fetch the next block of tbs data          */
/******************************************************************************
** sqlbftpq API
** Fetches a specified number of rows of table space query data, each row
** consisting of data for a table space.
** 
** Scope
** 
** In a partitioned database environment, only the table spaces on the current
** database partition are listed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - load
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbftpq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** MaxTablespaces
** Input. The maximum number of rows of data that the user allocated output area
** (pointed to by pTablespaceData) can hold.
** 
** pTablespaceData
** Input and output. Pointer to the output area, a structure for query data. For
** more information about this structure, see SQLB-TBSPQRY-DATA. The caller of
** this API must:
** - Allocate space for MaxTablespaces of these structures
** - Initialize the structures
** - Set TBSPQVER in the first structure to SQLB_TBSPQRY_DATA_ID
** - Set pTablespaceData to point to this space. The API will use this space to
** return the table space data.
** 
** pNumTablespaces
** Output. Number of rows of output returned.
** 
** Usage notes
** 
** The user is responsible for allocating and freeing the memory pointed to
** by the pTablespaceData parameter. This API can only be used after a
** successful sqlbotsq call. It can be invoked repeatedly to fetch the list
** generated by sqlbotsq.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Fetch Tablespace Query    */
  sqlbftpq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 MaxTablespaces,                     /* max num of tbs the        */
                                                 /* output area can hold      */
   struct SQLB_TBSPQRY_DATA * pTablespaceData,   /* out: array of length      */
                                                 /* maxTbs                    */
   sqluint32 * pNumTablespaces);                 /* out: #data entries        */
                                                 /* returned                  */

/* ctsq - Close TableSpace Query -> terminate the query opened by sqlbotsq    */
/******************************************************************************
** sqlbctsq API
** Ends a table space query request, and frees up associated resources.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - load
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbctsq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Close Tablespace Query    */
  sqlbctsq (
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* mtsq - TableSpace Query -> uses the above primitives to return the FULL    */
/* list of tablespaces in an array allocated and returned to the              */
/* application.  The application should free this memory with the sqlefmem()  */
/* api when it is finished with it. Even if this api fails with an            */
/* 'insufficient memory' error, 'nTbs' is set to the number of tablespaces    */
/* in the database. 'nTbs' is set to zero if we fail to sucessfully open a    */
/* query. 'tbsData' is returned as NULL (0;no mem alloc) if we fail for any   */
/* reason.                                                                    */
/******************************************************************************
** sqlbmtsq API
** Provides a one-call interface to the table space query data. The query data
** for all table spaces in the database is returned in an array.
** 
** Scope
** 
** In a partitioned database environment, only the table spaces on the current
** database partition are listed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - load
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbmtsq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** pNumTablespaces
** Output. The total number of table spaces in the connected database.
** 
** pppTablespaceData
** Output. The caller supplies the API with the address of a pointer. The
** space for the table space query data is allocated by the API, and a pointer
** to that space is returned to the caller. On return from the call, the
** pointer points to an array of SQLB_TBSPQRY_DATA pointers to the complete
** set of table space query data.
** 
** reserved1
** Input. Always SQLB_RESERVED1.
** 
** reserved2
** Input. Always SQLB_RESERVED2.
** 
** Usage notes
** 
** This API uses the lower level services, namely:
** - sqlbotsq
** - sqlbftpq
** - sqlbctsq
** to get all of the table space query data at once.
** 
** If sufficient memory is available, this function returns the number of
** table spaces, and a pointer to the memory location of the table space query
** data. It is the user's responsibility to free this memory with a call to
** sqlefmem.
** 
** If sufficient memory is not available, this function simply returns the
** number of table spaces, and no memory is allocated. If this should happen,
** use sqlbotsq, sqlbftpq, and sqlbctsq, to fetch less than the whole list at
** once.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Tablespace Query          */
  sqlbmtsq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 * pNumTablespaces,                  /* out: total number of      */
                                                 /* table spaces              */
   struct SQLB_TBSPQRY_DATA *** pppTablespaceData, /* out: mem returned to    */
                                                 /* application               */
   sqluint32 reserved1,                          /* in: SQLB_RESERVED1        */
   sqluint32 reserved2);                         /* in: SQLB_RESERVED2        */

/* container level queries.They all accept either a tableSpace id (a single   */
/* tbs) ora special id (SQLB_ALL_TABLESPACES) which triggers the fetchof a    */
/* list of containers for the entire database.                                */

/* constant used in place of tablespace id to indicate all table spaces in    */
/* db                                                                         */
#define SQLB_ALL_TABLESPACES 0xfffe

/* constants used for reserved parameters                                     */
#define SQLB_RESERVED1 0xfffd
#define SQLB_RESERVED2 0xfffe

/* otcq - Open Tablespace Container Query -- prepares for fetching a list of  */
/* container data                                                             */
/******************************************************************************
** sqlbotcq API
** Prepares for a table space container query operation, and returns the
** number of containers currently in the table space.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbotcq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** TablespaceId
** Input. ID of the table space for which container data is desired. If the
** special identifier SQLB_ALL_TABLESPACES (in sqlutil.h) is specified, a 
** complete list of containers for the entire database is produced.
** 
** pNumContainers
** Output. The number of containers in the specified table space.
** 
** Usage notes
** 
** This API is normally followed by one or more calls to sqlbftcq, and then
** by one call to sqlbctcq.
** 
** An application can use the following APIs to fetch information about
** containers in use by table spaces:
** 
** - sqlbtcq
** Fetches a complete list of container information. The API allocates the
** space required to hold the information for all the containers, and returns a
** pointer to this information. Use this API to scan the list of containers for
** specific information. Using this API is identical to calling the three APIs
** below (sqlbotcq, sqlbftcq, sqlbctcq), except that this API automatically
** allocates the memory for the output information. A call to this API must be
** followed by a call to sqlefmem to free the memory.
** 
** - sqlbotcq
** - sqlbftcq
** - sqlbctcq
** 
** These three APIs function like an SQL cursor, in that they use the
** OPEN/FETCH/CLOSE paradigm. The caller must provide the output area
** for the fetch. Unlike an SQL cursor, only one table space container query
** can be active at a time. Use this set of APIs to scan the list of table space
** containers for specific information. These APIs allows the user to control
** the memory requirements of an application (compared with sqlbtcq).
** 
** When sqlbotcq is called, a snapshot of the current container information is
** formed in the agent servicing the application. If the application issues a
** second table space container query call (sqlbtcq or sqlbotcq), this snapshot
** is replaced with refreshed information.
** 
** No locking is performed, so the information in the buffer may not reflect
** changes made by another application after the snapshot was generated. The
** information is not part of a transaction.
** 
** There is one snapshot buffer for table space queries and another for table
** space container queries. These buffers are independent of one another.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Open Tablespace           */
                                                 /* Container Query           */
  sqlbotcq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 TablespaceId,                       /* in: id tbs or SQLB_ALL    */
                                                 /* TABLESPACES               */
   sqluint32 * pNumContainers);                  /* out:  output...the        */
                                                 /* number of containers for  */
                                                 /* the table space           */

/* ftcq - Fetch Tablespace Container Query. Fetch the next block of           */
/* container info.                                                            */
/******************************************************************************
** sqlbftcq API
** Fetches a specified number of rows of table space container query data, each
** row consisting of data for a container.
** 
** Scope
** 
** In a partitioned database environment, only the table spaces on the current
** database partition are listed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbftcq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** MaxContainers
** Input. The maximum number of rows of data that the user allocated output area
** (pointed to by pContainerData) can hold.
** 
** pContainerData
** Output. Pointer to the output area, a structure for query data. For more
** information about this structure, see SQLB-TBSCONTQRY-DATA. The caller of
** this API must allocate space for MaxContainers of these structures, and set
** pContainerData to point to this space. The API will use this space to return
** the table space container data.
** 
** pNumContainers
** Output. Number of rows of output returned.
** 
** Usage notes
** 
** The user is responsible for allocating and freeing the memory pointed to
** by the pContainerData parameter. This API can only be used after a
** successful sqlbotcq call. It can be invoked repeatedly to fetch the list
** generated by sqlbotcq.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Fetch Tablespace          */
                                                 /* Container Query           */
  sqlbftcq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 MaxContainers,                      /* in:  max # entries to     */
                                                 /* return in 'data'          */
   struct SQLB_TBSCONTQRY_DATA * pContainerData, /* out: array of 'maxCont'   */
                                                 /* entries                   */
   sqluint32 * pNumContainers);                  /* out: # data entries       */
                                                 /* returned on this query    */

/* ctcq - Close Tablespace Container Query. Terminate processing for this     */
/* query                                                                      */
/******************************************************************************
** sqlbctcq API
** Ends a table space container query request and frees the associated
** resources.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbctcq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Close Tablespace          */
                                                 /* Container Query           */
  sqlbctcq (
   struct sqlca * pSqlca);

/* tcq - Tablespace Container Query                                           */
/* Like 'sqlbmtsq', this api generates a complete list, allocating            */
/* sufficient memory.  The application is responsible for freeing the memory  */
/* when it is finished with it: call sqlefmem(ca,ptr).                        */
/******************************************************************************
** sqlbtcq API
** Provides a one-call interface to the table space container query data. The
** query data for all containers in a table space, or for all containers in all
** table spaces, is returned in an array.
** 
** Scope
** 
** In a partitioned database environment, only the table spaces on the current
** database partition are listed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbtcq API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** TablespaceId
** Input. ID of the table space for which container data is desired, or
** a special ID, SQLB_ALL_TABLESPACES (defined in sqlutil), which produces
** a list of all containers for the entire database.
** 
** pNumContainers
** Output. The number of containers in the table space.
** 
** ppContainerData
** Output. The caller supplies the API with the address of a pointer to a
** SQLB_TBSCONTQRY_DATA structure. The space for the table space
** container query data is allocated by the API, and a pointer to that space is
** returned to the caller. On return from the call, the pointer to the
** SQLB_TBSCONTQRY_DATA structure points to the complete set of table
** space container query data.
** 
** Usage notes
** 
** This API uses the lower level services, namely:
** - sqlbotcq
** - sqlbftcq
** - sqlbctcq
** to get all of the table space container query data at once.
** 
** If sufficient memory is available, this function returns the number of
** containers, and a pointer to the memory location of the table space container
** query data. It is the user's responsibility to free this memory with a
** call to sqlefmem. If sufficient memory is not available, this function
** simply returns the number of containers, and no memory is allocated. If
** this should happen, use sqlbotcq, sqlbftcq, and sqlbctcq to fetch less
** than the whole list at once.
*******************************************************************************/
SQL_API_RC SQL_API_FN
  sqlbtcq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 TablespaceId,                       /* in: id a tbs or SQLB_ALL  */
                                                 /* TABLESPACES               */
   sqluint32 * pNumContainers,                   /* out: # entries returned   */
   struct SQLB_TBSCONTQRY_DATA ** ppContainerData);

/* stsc - Set TableSpace Containers                                           */
/* This api is to be used when the tablespace is in a 'storage definition     */
/* pending' or 'storage definition allowed' state.  These states are          */
/* possible during a restore operation, immediately prior to the restoration  */
/* of database pages.  This API is intended to assist in the provision of a   */
/* 'redirected' restore, where the user is restoring a database and a         */
/* different set of OS storage containers is desired/required.                */
/*                                                                            */
/* As input the application provides a list of storage definitions in the     */
/* SQLB_TBSCONTQRY_DATA structure (also used for query purposes). For this    */
/* api only the following fields are examined:                                */
/*                                                                            */
/* sqluint32       nameLen;    length of name (for non-C lang.)               */
/* char            name[SQLB_MAX_CONTAIN_NAME_SZ];  null term. name           */
/* sqluint32       contType;    SQLB_CONT_PATH/DISK/FILE                      */
/* sqluint32       totalPages;  DMS only                                      */
/*                                                                            */
/* processing options...pass 0 for 'nothing-special', OR in the special       */
/* bits.                                                                      */
/*                                                                            */
/* when setting containers prior to a restore/rollforward, the user may want  */
/* to IGNORE any 'add containers' in the logs.  He may simply be providing a  */
/* different 'final' state for the tablespace configuration.  The default     */
/* behavior is to redo 'alter' logrecords after a new container list has      */
/* been set.                                                                  */

#define SQLB_SET_CONT_INIT_STATE 0
#define SQLB_SET_CONT_FINAL_STATE 1

/******************************************************************************
** sqlbstsc API
** This API facilitates the provision of a redirected restore, in which the user
** is restoring a database, and a different set of operating system storage
** containers is desired or required.
** 
** Use this API when the table space is in a storage definition pending or a
** storage definition allowed state. These states are possible during a restore
** operation, immediately prior to the restoration of database pages.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbstsc API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** SetContainerOptions
** Input. Use this field to specify additional options. Valid values (defined in
** sqlutil) are:
** - SQLB_SET_CONT_INIT_STATE
** Redo alter table space operations when performing a roll forward.
** - SQLB_SET_CONT_FINAL_STATE
** Ignore alter table space operations in the log when performing a roll
** forward.
** 
** TablespaceId
** Input. Identifier for the table space which is to be changed.
** 
** NumContainers
** Input. The number of rows the structure pointed to by pContainerData holds.
** 
** pContainerData
** Input. Container specifications. Although the SQLB_TBSCONTQRY_DATA
** structure is used, only the contType, totalPages, name, and nameLen (for
** languages other than C) fields are used; all other fields are ignored.
** 
** Usage notes
** 
** This API is used in conjunction with db2Restore.
** 
** A backup of a database, or one or more table spaces, keeps a record of
** all the table space containers in use by the table spaces being backed up.
** During a restore, all containers listed in the backup are checked to see
** if they currently exist and are accessible. If one or more of the
** containers is inaccessible for any reason, the restore will fail. In order
** to allow a restore in such a case, the redirecting of table space
** containers is supported during the restore. This support includes adding,
** changing, or removing of table space containers. It is this API that
** allows the user to add, change or remove those containers.
** 
** Typical use of this API would involve the following sequence of actions:
** 
** 1. Invoke db2Restore with CallerAction set to SQLUD_RESTORE_STORDEF.
** The restore utility returns an sqlcode indicating that some of the containers
** are inaccessible.
** 
** 2. Invoke sqlbstsc to set the table space container definitions with the
** SetContainerOptions parameter set to SQLB_SET_CONT_FINAL_STATE.
** 
** 3. Invoke sqlurst a second time with CallerAction set to SQLUD_CONTINUE.
** 
** The above sequence will allow the restore to use the new table space
** container definitions and will ignore table space add container
** operations in the logs when db2Rollforward is called after the restore
** is complete.
** 
** The user of this API should be aware that when setting the container list,
** there must be sufficient disk space to allow for the restore or rollforward
** operation to replace all of the original data into these new containers. If
** there is not sufficient space, such table spaces will be left in the recovery
** pending state until sufficient disk space is made available. A prudent
** Database Administrator will keep records of disk utilization on a regular
** basis. Then, when a restore or rollforward operation is needed, the required
** disk space will be known.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Set Tablespace            */
                                                 /* Containers                */
  sqlbstsc (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 SetContainerOptions,                /* in: processing options:   */
                                                 /* SQLB_SET_CONT_xxx         */
   sqluint32 TablespaceId,                       /* in: table space which is  */
                                                 /* to be changed             */
   sqluint32 NumContainers,                      /* in:#containers in the     */
                                                 /* list                      */
   struct SQLB_TBSCONTQRY_DATA * pContainerData); /* container                */
                                                 /* specifications            */

/* gtss - Get TableSpace Statistics                                           */
/* Provide some basic info about the utilization of a tablespace. BETA NOTE:  */
/* only DMS tablespace are supported at this time - SRSFIX                    */
/******************************************************************************
** sqlbgtss API
** Provides information on the space utilization of a table space.
** 
** Scope
** 
** In a partitioned database environment, only the table spaces on the current
** database partition are listed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - load
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqlbgtss API parameters
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** TablespaceId
** Input. ID of the single table space to be queried.
** 
** pTablespaceStats
** Output. A pointer to a user-allocated SQLB_TBS_STATS structure. The
** information about the table space is returned in this structure.
** 
** Usage notes
** 
** See SQLB-TBS-STATS for information about the fields returned and
** their meaning.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get Tablespace            */
                                                 /* Statistics                */
  sqlbgtss (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 TablespaceId,
   struct SQLB_TBS_STATS * pTablespaceStats);

/* END OF TABLESPACE RELATED API'S                                            */

/******************************************************************************
** Database Utility Commands -- Function Prototypes
*******************************************************************************/

#ifndef SQLZ_STACK

#ifdef SQL_REL_10
#define sqluauth(ca) sqluauth_api(ca)
#define sqlustat(tn,idx,ilst,op,sl,ca) sqlustat_api(tn,idx,ilst,op,sl,ca)
#else
#define sqluauth(ca) sqluauth_api(ca)
#define sqludrdt(ngn,tpm,dstf,alst,acnt,dlst,dcnt,ope,ca)\
        sqludrdt_api(ngn,tpm,dstf,alst,acnt,dlst,dcnt,ope,ca)
#define sqluexpt(df,dcol,tcol,ft,ftm,mf,ac,out,ca)\
        sqluexpr_api(df,NULL,NULL,dcol,tcol,ft,ftm,mf,ac,out,NULL,ca)
#define sqluflsh(tn,lsn,ca)\
        sqluflsh_api(tn,lsn,ca)
#define sqluimpt(df,dcol,tcol,ft,ftm,mf,ac,in,out,ca)\
        sqluimpr_api(df,NULL,dcol,tcol,ft,ftm,mf,ac,in,out,NULL,NULL,ca)
#define sqluexpr(df,lp,lf,dcol,tcol,ft,ftm,mf,ac,out,r,ca)\
        sqluexpr_api(df,lp,lf,dcol,tcol,ft,ftm,mf,ac,out,r,ca)
#define sqluimpr(df,lp,dcol,tcol,ft,ftm,mf,ac,in,out,ni,r,ca)\
        sqluimpr_api(df,lp,dcol,tcol,ft,ftm,mf,ac,in,out,ni,r,ca)
#define sqlureot(tn,in,df,ca) sqlureot_api(tn,in,df,ca)
#define sqluroll(rfin,rfout,ca)\
        sqluroll_api(rfin,rfout,ca)
#define sqluload(df,lp,dc,tc,ft,fm,msg,rf,ac,in,out,wd,ct,ni,r,ca)\
        sqluload_api(df,lp,dc,tc,ft,fm,msg,rf,ac,in,out,wd,ct,ni,r,ca)
#define sqluqry(lf,rf,ca)  sqluqry_api(lf,rf,ca)
#define sqlustat(tn,idx,ilst,op,sl,ca) sqlustat_api(tn,idx,ilst,op,sl,ca)
#define sqlurlog(ac,sl,el,lb,lbs,rli,ca)\
        sqlurlog_api(ac,sl,el,lb,lbs,rli,ca)
#define sqlugrpi(nptrs,aptrs,alens,cc,cp,pinfo,pno,nno,chk,ca)\
        sqlugrpi_api(nptrs,aptrs,alens,cc,cp,pinfo,pno,nno,chk,ca)
#define sqlugrpn(nptrs,aptrs,alens,cc,cp,pinfo,pno,nno,chk,ca,df,re1,re2)\
        sqlugrpn_api(nptrs,aptrs,alens,cc,cp,pinfo,pno,nno,chk,ca,df,re1,re2)
#define sqlugtpi(tn,pinfo,ca) sqlugtpi_api(tn,pinfo,ca)

#endif

#endif

/* General Utility Commands                                                   */

/******************************************************************************
** sqluhops API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Open Recovery History File     */
                                            /* Scan                           */
  sqluhops (
   char * pDbAlias,                         /* database alias to open the     */
                                            /* scan for                       */
   char * pTimestamp,                       /* complete/partial timestamp     */
   char * pObjectName,                      /* table name or tablespace name  */
   unsigned short * pNumRows,               /* rows that match parameters     */
   unsigned short * pHandle,                /* handle used for gne/cls        */
   unsigned short CallerAction,             /* list: 0-backup; 1-history      */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluhgne API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Next Recovery History      */
                                            /* File Entry                     */
  sqluhgne (
   unsigned short Handle,                   /* handle returned from open      */
   struct sqluhadm * pAdminInfo,            /* pointer to enhanced data       */
   struct sqluhinfo * pHistoryInfo,         /* pointer to entry               */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluhget API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Next Recovery History      */
                                            /* File Entry - Enhanced for      */
                                            /* V5.2                           */
  sqluhget (
   unsigned short Handle,                   /* handle returned from open      */
   unsigned short CallerAction,             /* special handling of DDL data   */
   sqluint32 Reserved_1,                    /* reserved for future use        */
   struct sqluhinfo * pHistoryInfo,         /* pointer to entry               */
   struct sqluhadm * pAdminInfo,            /* pointer to enhanced data       */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluhcls API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Close Recovery History File    */
                                            /* Scan                           */
  sqluhcls (
   unsigned short Handle,                   /* handle returned from open      */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluhprn API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Prune Recovery History File    */
  sqluhprn (
   char * pTimestamp,                       /* timestamp (or partial one)     */
   unsigned short ForceOption,              /* 0 for DON'T FORCE              */
                                            /*  1 for FORCE                   */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluhupd API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update Recovery History File   */
  sqluhupd (
   char * pObjectPart,                      /* timestamp||(001 -> 999)        */
   char * pNewLocation,                     /* the new location               */
   char * pNewDeviceType,                   /* the new device type            */
   char * pNewComment,                      /* new comment                    */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluvqdp API
** Quiesces table spaces for a table. There are three valid quiesce modes:
** share, intent to update, and exclusive. There are three possible table
** space states resulting from the quiesce function:
** - Quiesced: SHARE,
** - Quiesced: UPDATE
** - Quiesced: EXCLUSIVE.
** 
** Scope
** 
** In a single-partition database environment, this API quiesces all
** table spaces involved in a load operation in exclusive mode for the
** duration of the load. In a partitioned database environment, this API
** acts locally on a database partition. It quiesces only that portion
** of table spaces belonging to the database partition on which the load
** is performed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - load
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqluvqdp API parameters
** 
** pTableName
** Input. A string containing the table name as used in the system catalog. This
** may be a two-part name with the schema and the table name separated by a
** period (.). If the schema is not provided, the CURRENT SCHEMA will be used.
** The table cannot be a system catalog table. This field is mandatory.
** 
** QuiesceMode
** Input. Specifies the quiesce mode. Valid values (defined in sqlutil) are:
** - SQLU_QUIESCEMODE_SHARE
** For share mode
** - SQLU_QUIESCEMODE_INTENT_UPDATE
** For intent to update mode
** - SQLU_QUIESCEMODE_EXCLUSIVE
** For exclusive mode
** - SQLU_QUIESCEMODE_RESET
** To reset the state of the table spaces to normal if either of the
** following is true:
** - The caller owns the quiesce
** - The caller who sets the quiesce disconnects, creating a "phantom
** quiesce"
** SQLU_QUIESCEMODE_RESET_OWNED
** To reset the state of the table spaces to normal if the caller owns
** the quiesce.
** 
** This field is mandatory.
** 
** pReserved
** Reserved for future use.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** This API is not supported for declared temporary tables.
** 
** When the quiesce share request is received, the transaction requests intent
** share locks for the table spaces and a share lock for the table. When the
** transaction obtains the locks, the state of the table spaces is changed to
** QUIESCED SHARE. The state is granted to the quiescer only if there is no
** conflicting state held by other users. The state of the table spaces is
** recorded in the table space table, along with the authorization ID and the
** database agent ID of the quiescer, so that the state is persistent.
** 
** The table cannot be changed while the table spaces for the table are in
** QUIESCED SHARE state. Other share mode requests to the table and table
** spaces will be allowed. When the transaction commits or rolls back, the locks
** are released, but the table spaces for the table remain in QUIESCED SHARE
** state until the state is explicitly reset.
** 
** When the quiesce exclusive request is made, the transaction requests super
** exclusive locks on the table spaces, and a super exclusive lock on the table.
** When the transaction obtains the locks, the state of the table spaces changes
** to QUIESCED EXCLUSIVE. The state of the table spaces, along with the
** authorization ID and the database agent ID of the quiescer, are recorded
** in the table space table. Since the table spaces are held in super
** exclusive mode, no other access to the table spaces is allowed. The
** user who invokes the quiesce function (the quiescer), however, has
** exclusive access to the table and the table spaces.
** 
** When a quiesce update request is made, the table spaces are locked in intent
** exclusive (IX) mode, and the table is locked in update (U) mode. The state of
** the table spaces with the quiescer is recorded in the table space table.
** 
** There is a limit of five quiescers on a table space at any given time. Since
** QUIESCED EXCLUSIVE is incompatible with any other state, and QUIESCED
** UPDATE is incompatible with another QUIESCED UPDATE, the five quiescer limit,
** if reached, must have at least four QUIESCED SHARE and at most one
** QUIESCED UPDATE.
** 
** A quiescer can upgrade the state of a table space from a less restrictive
** state to a more restrictive one (for example, S to U, or U to X). If a
** user requests a state lower than one that is already held, the original
** state is returned. States are not downgraded.
** 
** The quiesced state of a table space must be reset explicitly by using
** SQLU_QUIESCEMODE_RESET.
** 
** REXX API syntax
** 
** QUIESCE TABLESPACES FOR TABLE table_name
** {SHARE | INTENT TO UPDATE | EXCLUSIVE | RESET}
** 
** REXX API parameters
** 
** table_name
** Name of the table as used in the system catalog. This may be a two-part name
** with the schema and the table name separated by a period (.). If the
** schema is not provided, the CURRENT SCHEMA will be used.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Quiesce Tablespaces for Table  */
  sqluvqdp (
   char * pTableName,                       /* fully qualified table name     */
   sqlint32 QuiesceMode,                    /* 0 for share                    */
                                            /* 1 for intent to update         */
                                            /* 2 for exclusive                */
                                            /* 9 to reset                     */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluadau API
** Reports the instance level and database level authorities of the current
** user from values found in the database manager configuration file and
** the authorization system catalog view (SYSCAT.DBAUTH) respectively. The
** instance level authorities reported are the ones that you can set in the
** sysadm_group, sysmaint_group and sysctrl_group database manager
** configuration parameters and the database level authorities are the ones
** that can be granted via the GRANT (Database Authorities) statement.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Database
** 
** API include file
** 
** sqlutil.h
** 
** sqluadau API parameters
** 
** pAuthorizations
** Input or Output. Pointer to the sql_authorizations structure. This array
** of short integers indicates which authorizations the current user holds.
** The first element in the structure, sql_authorizations_len, must be
** initialized to the size of the buffer being passed, prior to calling this
** API.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Direct authorities are acquired by explicit commands that grant the
** authorities to a user ID. Indirect authorities are based on authorities
** acquired by the groups to which a user belongs.
** 
** Note:
** PUBLIC is a special group to which all users belong.
** 
** If there are no errors, each element of the sql_authorizations structure
** contains a 0 or a 1. A value of 1 indicates that the user holds that
** authorization; 0 indicates that the user does not.
** 
** REXX API syntax
** 
** GET AUTHORIZATIONS :value
** 
** REXX API parameters
** 
** value
** A compound REXX host variable to which the authorization level is
** returned. In the following, XXX represents the host variable name.
** Values are 0 for no, and 1 for yes.
** 
** - XXX.0
** Number of elements in the variable (always 18)
** - XXX.1
** Direct SYSADM authority
** - XXX.2
** Direct DBADM authority
** - XXX.3
** Direct CREATETAB authority
** - XXX.4
** Direct BINDADD authority
** - XXX.5
** Direct CONNECT authority
** - XXX.6
** Indirect SYSADM authority
** - XXX.7
** Indirect DBADM authority
** - XXX.8
** Indirect CREATETAB authority
** - XXX.9
** Indirect BINDADD authority
** - XXX.10
** Indirect CONNECT authority
** - XXX.11
** Direct SYSCTRL authority
** - XXX.12
** Indirect SYSCTRL authority
** - XXX.13
** Direct SYSMAINT authority
** - XXX.14
** Indirect SYSMAINT authority
** - XXX.15
** Direct CREATE_NOT_FENC authority
** - XXX.16
** Indirect CREATE_NOT_FENC authority
** - XXX.17
** Direct IMPLICIT_SCHEMA authority
** - XXX.18
** Indirect IMPLICIT_SCHEMA authority.
** - XXX.19
** Direct LOAD authority.
** - XXX.20
** Indirect LOAD authority.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Authorizations             */
  sqluadau (
   struct sql_authorizations * pAuthorizations,
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluauth API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Authorizations             */
  sqluauth_api (
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqlubkp API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Backup Database                */
  sqlubkp (
   char * pDbAlias,                         /* database alias                 */
   sqluint32 BufferSize,                    /* backup buffer size             */
   sqluint32 BackupMode,                    /* online or offline              */
   sqluint32 BackupType,                    /* backup type.                   */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application ID.                */
   char * pTimestamp,                       /* timestamp returned             */
   sqluint32 NumBuffers,                    /* num of buffers                 */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* list of            */
                                            /* tablespace                     */
   struct sqlu_media_list * pMediaTargetList, /* list of media targ           */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future            */
   sqluint32 VendorOptionsSize,             /* size of options                */
   void * pVendorOptions,                   /* reserved for vendor            */
   sqluint32 Parallelism,                   /* Degree of parallelism          */
   sqluint32 * pBackupSize,                 /* Size of backup                 */
   void * pReserved4,                       /* reserved for future            */
   void * pReserved3,                       /* reserved for future            */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlubkup API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* V2 Backup Database             */
  sqlubkup (
   char * pDbAlias,                         /* database alias                 */
   sqluint32 BufferSize,                    /* backup buffer size             */
   sqluint32 BackupMode,                    /* online or offline              */
   sqluint32 BackupType,                    /* backup type.                   */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application ID.                */
   char * pTimestamp,                       /* timestamp returned             */
   sqluint32 NumBuffers,                    /* num of buffers                 */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* list of            */
                                            /* tablespace                     */
   struct sqlu_media_list * pMediaTargetList, /* list of media targ           */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future            */
   sqluint32 VendorOptionsSize,             /* size of options                */
   void * pVendorOptions,                   /* reserved for vendor            */
   void * pReserved3,                       /* reserved for future            */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqludsdb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Describe Database              */
  sqludsdb (
   unsigned char * targetPath,              /* Target path                    */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqludrdt API
** Redistributes data across the database partitions in a database partition
** group. The current data distribution, whether it is uniform or skewed, can be
** specified. The redistribution algorithm selects the data basepartitions to
** be moved based on the current data distribution.
** 
** This API can only be called from the catalog partition. Use the LIST DATABASE
** DIRECTORY command to determine which database partition server is the catalog
** partition for each database.
** 
** Scope
** 
** This API affects all database partitions in the database partition group.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - dbadm
** 
** API include file
** 
** sqlutil.h
** 
** sqludrdt API parameters
** 
** pNodeGroupName
** The name of the database partition group to be redistributed.
** 
** pTargetPMapFileName
** The name of the file that contains the target distribution map. If a
** directory path is not specified as part of the file name, the current
** directory is used. This parameter is used when the DataRedistOption
** value is T. The file should be in character format and contain either
** 4 096 entries (for a multiple-partition database partition group) or
** 1 entry (for a single-partition database partition group). Entries
** in the file indicate node numbers. Entries can be in free format.
** 
** pDataDistFileName
** The name of the file that contains input distribution information. If a
** directory path is not specified as part of the file name, the current
** directory is used. This parameter is used when the DataRedistOption value
** is U. The file should be in character format and contain 4 096 positive
** integer entries. Each entry in the file should indicate the weight of the
** corresponding database partition. The sum of the 4 096 values should be
** less than or equal to 4 294 967 295.
** 
** pAddList
** The list of database partitions to add to the database partition group during
** the data redistribution. Entries in the list must be in the form:
** SQL_PDB_NODE_TYPE.
** 
** AddCount
** The number of database partitions to add to the database partition group.
** 
** pDropList
** The list of database partitions to drop from the database partition group
** during the data redistribution. Entries in the list must be in the form:
** SQL_PDB_NODE_TYPE.
** 
** DropCount
** The number of database partitions to drop from the database partition group.
** 
** DataRedistOption
** A single character that indicates the type of data redistribution to be done.
** Possible values are:
** 
** - U
** Specifies to redistribute the database partition group to achieve a balanced
** distribution. If pDataDistFileName is null, the current data distribution is
** assumed to be uniform (that is, each database partition represents the same
** amount of data). If pDataDistFileName parameter is not null, the values in
** this file are assumed to represent the current data distribution. When the
** DataRedistOption is U, the pTargetPMapFileName parameter should be null.
** Database partitions specified in the add list are added, and database
** partitions specified in the drop list are dropped from the database
** partition group.
** 
** - T
** Specifies to redistribute the database partition group using the
** pTargetPMapFileName parameter. For this option, the parameters,
** pDataDistFileName, pAddList, and pDropList should be null, and both
** the parameters, AddCount and DropCount must be zero.
** 
** - C
** Specifies to continue a redistribution operation that failed. For this
** option, the parameters, pTargetPMapFileName, pDataDistFileName,
** pAddList, and pDropList should be null, and both the parameters,
** AddCount and DropCount must be zero.
** 
** - R
** Specifies to roll back a redistribution operation that failed. For this
** option, the parameters, pTargetPMapFileName, pDataDistFileName,
** pAddList, and pDropList should be null, and both the parameters,
** AddCount and DropCount must be zero.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** When a redistribution operation is done, a message file is written to:
** 
** - The $HOME/sqllib/redist directory on UNIX based systems, using the
** following format for subdirectories and file name:
** database-name.nodegroup-name.timestamp.
** 
** - The $HOME\sqllib\redist\ directory on the Windows operating system,
** using the following format for subdirectories and file name:
** database-name\first-eight-characters-of-the-nodegroup-name\date\time.
** 
** The time stamp value is the time at which the API was called.
** 
** This utility performs intermittent COMMITs during processing.
** 
** Use the ALTER DATABASE PARTITION GROUP statement to add database
** partitions to a database partition group. This statement permits one
** to define the containers for the table spaces associated with the
** database partition group.
** 
** All packages having a dependency on a table that has undergone redistribution
** are invalidated. It is recommended to explicitly rebind such packages after
** the redistribute database partition group operation has completed. Explicit
** rebinding eliminates the initial delay in the execution of the first SQL
** request for the invalid package. The redistribute message file contains
** a list of all the tables that have undergone redistribution.
** 
** It is also recommended to update statistics by issuing the db2Runstats API
** after the redistribute database partition group operation has completed.
** 
** Database partition groups containing replicated summary tables or tables
** defined with the DATA CAPTURE CHANGES clause cannot be redistributed.
** 
** Redistribution is not allowed if there are user temporary table spaces with
** existing declared temporary tables in the database partition group.
** 
** REXX API syntax
** 
** This API can be called from REXX through the SQLDB2 interface.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Data Redistribution            */
  sqludrdt_api (
   char * pNodeGroupName,                   /* Nodegroup name                 */
   char * pTargetPMapFileName,              /* Target partition map file      */
                                            /* name                           */
   char * pDataDistFileName,                /* Data distribution file name    */
   SQL_PDB_NODE_TYPE * pAddList,            /* List of nodes to be added      */
   unsigned short AddCount,                 /* No. of nodes to be added       */
   SQL_PDB_NODE_TYPE * pDropList,           /* List of nodes to be dropped    */
   unsigned short DropCount,                /* No. of nodes to be dropped     */
   unsigned char DataRedistOption,          /* Data redistribution option     */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlurestore API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Restore Database               */
  sqlurestore (
   char * pSourceDbAlias,                   /* source alias name              */
   char * pTargetDbAlias,                   /* target dbalias                 */
   sqluint32 BufferSize,                    /* restore buffer size            */
   sqluint32 RollforwardMode,               /* 0 - roll forward               */
                                            /* 1 - do not roll fwd            */
   sqluint32 DatalinkMode,                  /* 0 - with datalink              */
                                            /* 1 - without datalink           */
   sqluint32 RestoreType,                   /* 0 - normal restore             */
                                            /* 3 - online restore for         */
                                            /* tablespace only                */
                                            /* 5 - history file only          */
   sqluint32 RestoreMode,                   /* Online/Offline                 */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application ID.                */
   char * pTimestamp,                       /* timestamp for backup image     */
   char * pTargetPath,                      /* target path for new database   */
   sqluint32 NumBuffers,                    /* num of buffers                 */
   char * pReportFile,                      /* Report filename                */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* reserved for       */
                                            /* future use.                    */
   struct sqlu_media_list * pMediaSourceList, /* list of media controllers    */
                                            /* to use.                        */
   char * pUserName,                        /* userid                         */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   sqluint32 Parallelism,                   /* Degree of parallelism          */
   void * pRestoreInfo,                     /* reserved                       */
   void * pContainerPageList,               /* Container/Page restore list    */
   void * pReserved3,                       /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlurst API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Restore Database               */
  sqlurst (
   char * pSourceDbAlias,                   /* source alias name              */
   char * pTargetDbAlias,                   /* target dbalias                 */
   sqluint32 BufferSize,                    /* restore buffer size            */
   sqluint32 RollforwardMode,               /* 0 - roll forward               */
                                            /* 1 - do not roll fwd            */
   sqluint32 RestoreType,                   /* 0 - normal restore             */
                                            /* 3 - online restore for         */
                                            /* tablespace only                */
                                            /* 5 - history file only          */
   sqluint32 RestoreMode,                   /* Online/Offline                 */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application ID.                */
   char * pTimestamp,                       /* timestamp for backup image     */
   char * pTargetPath,                      /* target path for new database   */
   sqluint32 NumBuffers,                    /* num of buffers                 */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* reserved for       */
                                            /* future use.                    */
   struct sqlu_media_list * pMediaSourceList, /* list of media controllers    */
                                            /* to use.                        */
   char * pUserName,                        /* userid                         */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   sqluint32 Parallelism,                   /* Degree of parallelism          */
   void * pRestoreInfo,                     /* reserved                       */
   void * pContainerPageList,               /* Container/Page restore list    */
   void * pReserved3,                       /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlursto API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* V2 Restore Database            */
  sqlursto (
   char * pSourceDbAlias,                   /* source alias name              */
   char * pTargetDbAlias,                   /* target dbalias                 */
   sqluint32 BufferSize,                    /* restore buffer size            */
   sqluint32 RollforwardMode,               /* 0 - roll forward               */
                                            /* 1 - do not roll fwd            */
   sqluint32 RestoreType,                   /* 0 - normal restore             */
                                            /* 3 - online restore for         */
                                            /* tablespace only                */
                                            /* 5 - history file only          */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application ID.                */
   char * pTimestamp,                       /* timestamp for backup image     */
   char * pTargetPath,                      /* target path for new database   */
   sqluint32 NumBuffers,                    /* num of buffers                 */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* reserved for       */
                                            /* future use.                    */
   struct sqlu_media_list * pMediaSourceList, /* list of media controllers    */
                                            /* to use.                        */
   char * pUserName,                        /* userid                         */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   void * pReserved3,                       /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlurllf API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Old Rollforward Database       */
  sqlurllf_api (
   char * pDbAlias,                         /* database alias                 */
   unsigned short CallerAction,             /* action                         */
   char * pApplicationId,                   /* application id                 */
   char * pStopTime,                        /* stop time                      */
   char * pNextArcFileName,                 /* next archive file needed       */
   char * pFirstDelArcFileName,             /* first archive file to be       */
                                            /* deleted                        */
   char * pLastDelArcFileName,              /* last archive file to be        */
                                            /* deleted                        */
   char * pLastCommitTime,                  /* last commit time               */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   char * pOverflowLogPath,                 /* overflow log path              */
   unsigned short ConnectMode,              /* connect mode                   */
   void * pReserved,                        /* reserved                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluprfw API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Old PE Rollforward Database    */
  sqluprfw_api (
   char *,                                  /* database name                  */
   char *,                                  /* userid                         */
   char *,                                  /* password                       */
   unsigned short,                          /* action                         */
   char *,                                  /* Stop Timestamp                 */
   sqluint32,                               /* all node flag                  */
   sqluint32,                               /* number of nodes in nodelist    */
   SQL_PDB_NODE_TYPE *,                     /* list of node numbers           */
   struct sqlurf_stat *,                    /* status                         */
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqlurfwd API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Old Rollforward Database       */
  sqlurfwd_api (
   char *,                                  /* database name                  */
   unsigned short,                          /* action                         */
   char *,                                  /* Stop Timestamp                 */
   char *,                                  /* Next Archive File needed       */
   char *,                                  /* First Archive File to be       */
                                            /* deleted                        */
   char *,                                  /* Last Archive File to be        */
                                            /* deleted                        */
   char *,                                  /* Returned Timestamp             */
   char *,                                  /* userid                         */
   char *,                                  /* password                       */
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqluroll API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Rollforward Database           */
  sqluroll_api (
   struct rfwd_input * pRfwdInput,          /* input structure                */
   struct rfwd_output * pRfwdOuput,         /* output structure               */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluexpr API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Export                         */
  sqluexpr_api (
   char * pDataFileName,                    /* data file                      */
   sqlu_media_list * pLobPathList,          /* lob paths                      */
   sqlu_media_list * pLobFileList,          /* lob files                      */
   struct sqldcol * pDataDescriptor,        /* dcoldata                       */
   struct sqlchar * pActionString,          /* tcolstrg                       */
   char * pFileType,                        /* file type                      */
   struct sqlchar * pFileTypeMod,           /* file type mod                  */
   char * pMsgFileName,                     /* msg file                       */
   short CallerAction,                      /* caller action                  */
   struct sqluexpt_out*  pOutputInfo,       /* rows exported                  */
   void * pReserved,                        /* reserved                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluflsh API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Flush Table                    */
  sqluflsh_api (
   char *,                                  /* Fully qualified table name     */
   SQLU_LSN *,                              /* Log Sequence Nbr               */
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqluexpt API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Export                         */
  sqluexpt_api (
   _SQLOLDCHAR *,                           /* datafile                       */
   struct sqldcol *,                        /* dcoldata                       */
   struct sqlchar *,                        /* tcolstrg                       */
   _SQLOLDCHAR *,                           /* filetype                       */
   struct sqlchar *,                        /* filetmod                       */
   _SQLOLDCHAR *,                           /* msgfile                        */
   short,                                   /* caller action                  */
   struct sqluexpt_out* ,                   /* rows exported                  */
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqlugrpn API is a deprecated API.
** It should not be used to retrieve row information since it can.
** only use a 4K partition map.
** Use the new API: db2GetRowPartNum.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Deprecated API - Get Row       */
                                            /* Partitioning Number            */
  sqlugrpn_api (
   unsigned short num_ptrs,                 /* Number of pointers             */
   unsigned char ** ptr_array,              /* An array of pointers           */
   unsigned short * ptr_lens,               /* An array of string lengths     */
   unsigned short territory_ctrycode,       /* Territory Code                 */
   unsigned short codepage,                 /* Codepage                       */
   struct sqlupi * part_info,               /* Partitioning Information       */
   short * part_num,                        /* Partition number               */
   SQL_PDB_NODE_TYPE * node_num,            /* Node number                    */
   unsigned short chklvl,                   /* Check level                    */
   struct sqlca * sqlca,                    /* SQLCA                          */
   short dataformat,                        /* data format                    */
   void * pReserved1,                       /* reserved for future use        */
   void * pReserved2);                      /* reserved for future use        */

/******************************************************************************
** sqlugrpi API is a deprecated API.
** It should not be used to retrieve row information since it can.
** only use a 4K partition map.
** Use the new API: db2GetRowPartNum.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Deprecated API - Get Row       */
                                            /* Partitioning Information       */
  sqlugrpi_api (
   unsigned short num_ptrs,                 /* Number of pointers             */
   unsigned char ** ptr_array,              /* An array of pointers           */
   unsigned short * ptr_lens,               /* An array of string lengths     */
   unsigned short territory_ctrycode,       /* Territory Code                 */
   unsigned short codepage,                 /* Codepage                       */
   struct sqlupi * part_info,               /* Partitioning Information       */
   short * part_num,                        /* Partition number               */
   SQL_PDB_NODE_TYPE * node_num,            /* Node number                    */
   unsigned short chklvl,                   /* Check level                    */
   struct sqlca * sqlca);                   /* SQLCA                          */

/******************************************************************************
** sqlugtpi is a deprecated API.
** It should not be used to retrieve the partition map since it can.
** only get the first 4K of the partition map.
** Use the new API to get the distribution map: db2GetDistMap.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Deprecated API - Get Table     */
                                            /* Partitioning Information       */
  sqlugtpi_api (
   unsigned char * tablename,               /* Table name                     */
   struct sqlupi * part_info,               /* Partitioning Information       */
   struct sqlca * sqlca);                   /* SQLCA                          */

/******************************************************************************
** sqluimpt API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Import                         */
  sqluimpt_api (
   _SQLOLDCHAR *,                           /* datafile                       */
   struct sqldcol *,                        /* dcoldata                       */
   struct sqlchar *,                        /* tcolstrg                       */
   _SQLOLDCHAR *,                           /* filetype                       */
   struct sqlchar *,                        /* filetmod                       */
   _SQLOLDCHAR *,                           /* msgfile                        */
   short,                                   /* caller action                  */
   struct sqluimpt_in* ,                    /* input parms                    */
   struct sqluimpt_out* ,                   /* output parms                   */
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqluimpr API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Import                         */
  sqluimpr_api (
   char * pDataFileName,                    /* datafile                       */
   sqlu_media_list * pLobPathList,          /* lobpath                        */
   struct sqldcol * pDataDescriptor,        /* dcoldata                       */
   struct sqlchar * pActionString,          /* tcolstrg                       */
   char * pFileType,                        /* filetype                       */
   struct sqlchar * pFileTypeMod,           /* filetmod                       */
   char * pMsgFileName,                     /* msgfile                        */
   short CallerAction,                      /* caller action                  */
   struct sqluimpt_in*  pImportInfoIn,      /* input parms                    */
   struct sqluimpt_out*  pImportInfoOut,    /* output parms                   */
   sqlint32 * pNullIndicators,              /* nullind                        */
   void * pReserved,                        /* reserved                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluload API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Load                           */
  sqluload_api (
   sqlu_media_list * pDataFileList,         /* input data files               */
   sqlu_media_list * pLobPathList,          /* input lob paths                */
   struct sqldcol * pDataDescriptor,        /* dcoldata - describes input     */
                                            /* data                           */
   struct sqlchar * pActionString,          /* tcolstrg - describes the       */
                                            /* columns of the table to load   */
   char * pFileType,                        /* file type                      */
   struct sqlchar * pFileTypeMod,           /* filetmod                       */
   char * pLocalMsgFileName,                /* message file name              */
   char * pRemoteMsgFileName,               /* remote file name               */
   short CallerAction,                      /* caller action                  */
   struct sqluload_in * pLoadInfoIn,        /* input                          */
   struct sqluload_out * pLoadInfoOut,      /* output                         */
   sqlu_media_list * pWorkDirectoryList,    /* work dirs                      */
   sqlu_media_list * pCopyTargetList,       /* copy targets                   */
   sqlint32 * pNullIndicators,              /* null ind                       */
   void * pReserved,                        /* reserved                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqluqry API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Query                          */
  sqluqry_api (
   char * pLocalMsgFileName,                /* local msg file                 */
   char * pRemoteMsgFileName,               /* remote msg file                */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlurlog API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Asynchronous Read Log          */
  sqlurlog_api (
   sqluint32 CallerAction,                  /* caller action                  */
   SQLU_LSN * pStartLsn,                    /* read start log sequence        */
                                            /* number                         */
   SQLU_LSN * pEndLsn,                      /* read end log sequence number   */
   char * pLogBuffer,                       /* user buffer                    */
   sqluint32 LogBufferSize,                 /* size of user buffer            */
   SQLU_RLOG_INFO * pReadLogInfo,           /* read log information           */
                                            /* structure                      */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlureot API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reorganize Table               */
  sqlureot_api (
   _SQLOLDCHAR * pTableName,                /* table name                     */
   _SQLOLDCHAR * pIndexName,                /* fully-qualified index name     */
   _SQLOLDCHAR * pTablespace,               /* tablespace                     */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlustat API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Run Statistics                 */
  sqlustat_api (
   _SQLOLDCHAR * pTableName,                /* table name                     */
   unsigned short NumIndexes,               /* number of indexes              */
   _SQLOLDCHAR ** ppIndexList,              /* indexlist                      */
   unsigned char StatsOption,               /* statsopt                       */
   unsigned char ShareLevel,                /* sharelvl                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlutbau API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Table Authorizations       */
  sqlutbau (
   _SQLOLDCHAR *,                           /* fully-qualified table name     */
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqluihsh API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Int Col Part Key Value     */
                                            /* For Given Part Map Index       */
  sqluihsh (
   sqlint32 InIndex,                        /* input partition map index      */
   sqlint32 * OutInt,                       /* output integer column part     */
                                            /* key value                      */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/* Generic APIs                                                               */

/******************************************************************************
** sqlgadau API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Authorizations             */
  sqlgadau (
   struct sql_authorizations * pAuthorizations,
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgddb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Default Database           */
                                            /* Configuration                  */
  sqlgddb (
   unsigned short DbAliasLen,               /* database alias length          */
   unsigned short NumItems,                 /* count of requested no of       */
                                            /* items                          */
   struct sqlfupd * pItemList,              /* list of items returned         */
   struct sqlca * pSqlca,                   /* SQLCA                          */
   char * pDbAlias);                        /* database  alias                */

/******************************************************************************
** sqlgrdb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reset Database Configuration   */
  sqlgrdb (
   unsigned short DbAliasLen,               /* database alias length          */
   struct sqlca * pSqlca,                   /* SQLCA                          */
   char * pDbAlias);                        /* database alias                 */

/******************************************************************************
** sqlgudb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update Database Configuration  */
  sqlgudb (
   unsigned short DbAliasLen,               /* database alias length          */
   unsigned short NumItems,                 /* count                          */
   unsigned short * pItemListLens,          /* List of item lengths           */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca,                   /* SQLCA                          */
   char * pDbAlias);                        /* database                       */

/******************************************************************************
** sqlgxdb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Database Configuration     */
  sqlgxdb (
   unsigned short DbAliasLen,               /* database alias length          */
   unsigned short NumItems,                 /* count of items being returned  */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca,                   /* SQLCA                          */
   char * pDbAlias);                        /* database alias                 */

/******************************************************************************
** sqlgdsys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Database Manager           */
                                            /* Configuration Defaults         */
  sqlgdsys (
   unsigned short NumItems,                 /* count of items being returned  */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgbkp API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Backup Database                */
  sqlgbkp (
   unsigned short DbAliasLen,               /* database alias length          */
   unsigned short UserNameLen,              /* user name length               */
   unsigned short PasswordLen,              /* password length                */
   unsigned short * pReserved1,             /* reserved for future use        */
   char * pDbAlias,                         /* database alias                 */
   sqluint32 BufferSize,                    /* buffer size in 4K units        */
   sqluint32 BackupMode,                    /* online or offline              */
   sqluint32 BackupType,                    /* 0 - full dB; 3 - tablespace    */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application ID.                */
   char * pTimestamp,                       /* timestamp returned             */
   sqluint32 NumBuffers,                    /* number of buffers to use       */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* list of            */
                                            /* tablespace names               */
   struct sqlu_media_list * pMediaTargetList, /* list of media targets        */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   sqluint32 Parallelism,                   /* Degree of parallelism          */
   sqluint32 * pBackupSize,                 /* Size of backup                 */
   void * pReserved4,                       /* reserved for future            */
   void * pReserved3,                       /* reserved for future use        */
   struct sqlca * pSqlca);                  /* sqlca structure                */

/******************************************************************************
** sqlgbkup API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Backup Database                */
  sqlgbkup (
   unsigned short DbAliasLen,               /* database alias length          */
   unsigned short UserNameLen,              /* user name length               */
   unsigned short PasswordLen,              /* password length                */
   unsigned short * pReserved1,             /* reserved for future use        */
   char * pDbAlias,                         /* database alias                 */
   sqluint32 BufferSize,                    /* buffer size in 4K units        */
   sqluint32 BackupMode,                    /* online or offline              */
   sqluint32 BackupType,                    /* 0 - full dB; 3 - tablespace    */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application ID.                */
   char * pTimestamp,                       /* timestamp returned             */
   sqluint32 NumBuffers,                    /* number of buffers to use       */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* list of            */
                                            /* tablespace names               */
   struct sqlu_media_list * pMediaTargetList, /* list of media targets        */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   void * pReserved3,                       /* reserved for future use        */
   struct sqlca * pSqlca);                  /* sqlca structure                */

/******************************************************************************
** sqlgdsdb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Describe Database              */
  sqlgdsdb (
   unsigned short targetPathLen,            /* Target path length             */
   unsigned char * targetPath,              /* Target path                    */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlghcls API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Close Recovery History File    */
                                            /* Scan                           */
  sqlghcls (
   unsigned short Handle,                   /* handle returned from open      */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlghgne API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Next Recovery History      */
                                            /* File Entry                     */
  sqlghgne (
   unsigned short Handle,                   /* handle returned from open      */
   struct sqluhadm * pAdminInfo,            /* special handling of command    */
                                            /* text                           */
   struct sqluhinfo * pHistoryInfo,         /* pointer to the address of the  */
                                            /* history file entry info        */
                                            /* buffer                         */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlghget API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Next Recovery History      */
                                            /* File Entry - Enhanced for      */
                                            /* V5.2                           */
  sqlghget (
   unsigned short Handle,                   /* handle returned from open      */
   unsigned short CallerAction,             /* special handling of DDL data   */
   sqluint32 Reserved_1,                    /* reserved for future use        */
   struct sqluhinfo * pHistoryInfo,         /* pointer to entry               */
   struct sqluhadm * pAdminInfo,            /* pointer to enhanced data       */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlghops API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Open Recovery History File     */
                                            /* Scan                           */
  sqlghops (
   unsigned short DbAliasLen,               /* database alias length          */
   unsigned short TimestampLen,             /* timestamp length               */
   unsigned short ObjectNameLen,            /* object name length             */
   char * pDbAlias,                         /* database alias                 */
   char * pTimestamp,                       /* timestamp used to select       */
                                            /* records                        */
   char * pObjectName,                      /* object name used to select     */
                                            /* records                        */
   unsigned short * pNumRows,               /* return no. of matching         */
                                            /* history file entries           */
   unsigned short * pHandle,                /* return handle used for future  */
                                            /* access                         */
   unsigned short CallerAction,             /* '0' for backup                 */
                                            /* '1' for history                */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlghrpn API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Prune Recovery History File    */
  sqlghprn (
   unsigned short TimestampLen,             /* timestamp id length            */
   char * pTimestamp,                       /* timestamp (whole or part)      */
   unsigned short ForceOption,              /* force option                   */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlghupd API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update Recovery History File   */
  sqlghupd (
   unsigned short ObjectPartLen,            /* object_part length             */
   unsigned short NewLocationLen,           /* new_location length            */
   unsigned short NewDeviceTypeLen,         /* new_device_type length         */
   unsigned short NewCommentLen,            /* new_comment length             */
   char * pObjectPart,                      /* timestamp||(001 -> 999)        */
   char * pNewLocation,                     /* the new location               */
   char * pNewDeviceType,                   /* the new device type            */
   char * pNewComment,                      /* new comment                    */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgroll API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Rollforward Database           */
  sqlgroll (
   struct grfwd_input * grfwdin,            /* input structure                */
   struct rfwd_output * rfwdout,            /* output structure               */
   struct sqlca * Sqlca);                   /* SQLCA                          */

/******************************************************************************
** sqlgrestore API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Restore Database               */
  sqlgrestore (
   unsigned short SourceDbAliasLen,         /* source database alias length   */
   unsigned short TargetDbAliasLen,         /* target database alias length   */
   unsigned short TimestampLen,             /* timestamp length               */
   unsigned short TargetPathLen,            /* target path length             */
   unsigned short UserNameLen,              /* user name length               */
   unsigned short PasswordLen,              /* password  length               */
   unsigned short ReportLen,                /* dl report length               */
   unsigned short * pReserved1,             /* nodename length                */
   char * pSourceDbAlias,                   /* source database alias          */
   char * pTargetDbAlias,                   /* target database alias          */
   sqluint32 BufferSize,                    /* buffer size in 4K units        */
   sqluint32 RollforwardMode,               /* 0 - roll forward               */
                                            /* 1 - do not roll forward        */
   sqluint32 DatalinksMode,                 /* 0 - with datalinks             */
                                            /* 1 - without datalinks          */
   sqluint32 RestoreType,                   /* 0 - normal restore             */
                                            /* 3 - online restore             */
                                            /*     for tablespace only        */
                                            /* 5 - history file only          */
   sqluint32 RestoreMode,                   /* Online/Offline                 */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application id returned        */
   char * pTimestamp,                       /* timestamp of backup            */
   char * pTargetPath,                      /* target: new path               */
   sqluint32 NumBuffers,                    /* number of buffers to use       */
   char * pReportFile,                      /* report filename                */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* reserved for       */
                                            /* future use                     */
   struct sqlu_media_list * pMediaSourceList, /* list of media sources        */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 Parallelism,                   /* Degree of parallelism          */
   unsigned short RestoreInfoSize,          /* reserved                       */
   void * pRestoreInfo,                     /* reserved                       */
   unsigned short ContainerPageListSize,    /* Size of Container/Page         */
                                            /* restore list                   */
   void * pContainerPageList,               /* Container/Page restore list    */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   void * pRestoreLogPath,                  /* Restore Log Path               */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgrst API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Restore Database               */
  sqlgrst (
   unsigned short SourceDbAliasLen,         /* source database alias length   */
   unsigned short TargetDbAliasLen,         /* target database alias length   */
   unsigned short TimestampLen,             /* timestamp length               */
   unsigned short TargetPathLen,            /* target path length             */
   unsigned short UserNameLen,              /* user name length               */
   unsigned short PasswordLen,              /* password  length               */
   unsigned short * pReserved1,             /* nodename length                */
   char * pSourceDbAlias,                   /* source database alias          */
   char * pTargetDbAlias,                   /* target database alias          */
   sqluint32 BufferSize,                    /* buffer size in 4K units        */
   sqluint32 RollforwardMode,               /* 0 - roll forward               */
                                            /* 1 - do not roll forward        */
   sqluint32 RestoreType,                   /* 0 - normal restore             */
                                            /* 3 - online restore             */
                                            /*     for tablespace only        */
                                            /* 5 - history file only          */
   sqluint32 RestoreMode,                   /* Online/Offline                 */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application id returned        */
   char * pTimestamp,                       /* timestamp of backup            */
   char * pTargetPath,                      /* target: new path               */
   sqluint32 NumBuffers,                    /* number of buffers to use       */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* reserved for       */
                                            /* future use                     */
   struct sqlu_media_list * pMediaSourceList, /* list of media sources        */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 Parallelism,                   /* Degree of parallelism          */
   unsigned short RestoreInfoSize,          /* reserved                       */
   void * pRestoreInfo,                     /* reserved                       */
   unsigned short ContainerPageListSize,    /* Size of Container/Page         */
                                            /* restore list                   */
   void * pContainerPageList,               /* Container/Page restore list    */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   void * pReserved3,                       /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgrsto API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Restore Database               */
  sqlgrsto (
   unsigned short SourceDbAliasLen,         /* source database alias length   */
   unsigned short TargetDbAliasLen,         /* target database alias length   */
   unsigned short TimestampLen,             /* timestamp length               */
   unsigned short TargetPathLen,            /* target path length             */
   unsigned short UserNameLen,              /* user name length               */
   unsigned short PasswordLen,              /* password  length               */
   unsigned short * pReserved1,             /* nodename length                */
   char * pSourceDbAlias,                   /* source database alias          */
   char * pTargetDbAlias,                   /* target database alias          */
   sqluint32 BufferSize,                    /* buffer size in 4K units        */
   sqluint32 RollforwardMode,               /* 0 - roll forward               */
                                            /* 1 - do not roll forward        */
   sqluint32 RestoreType,                   /* 0 - normal restore             */
                                            /* 3 - online restore             */
                                            /*     for tablespace only        */
                                            /* 5 - history file only          */
   sqluint32 CallerAction,                  /* caller action                  */
   char * pApplicationId,                   /* application id returned        */
   char * pTimestamp,                       /* timestamp of backup            */
   char * pTargetPath,                      /* target: new path               */
   sqluint32 NumBuffers,                    /* number of buffers to use       */
   struct sqlu_tablespace_bkrst_list * pTablespaceList, /* reserved for       */
                                            /* future use                     */
   struct sqlu_media_list * pMediaSourceList, /* list of media sources        */
   char * pUserName,                        /* user name                      */
   char * pPassword,                        /* password                       */
   void * pReserved2,                       /* reserved for future use        */
   sqluint32 VendorOptionsSize,             /* size of options field          */
   void * pVendorOptions,                   /* reserved for vendor use        */
   void * pReserved3,                       /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgvqdp API
** sqlgvqdp API-specific parameters
** 
** TableNameLen
** Input. A 2-byte unsigned integer representing the length in bytes of
** the table name.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Quiesce Tablespaces for Table  */
  sqlgvqdp (
   unsigned short TableNameLen,             /* length of table_name           */
   char * pTableName,                       /* table name                     */
   sqlint32 QuiesceMode,                    /* 0 for share                    */
                                            /* 1 for intent to update         */
                                            /* 2 for exclusive                */
                                            /* 9 to reset                     */
   void * pReserved,                        /* reserved for future use        */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgdrdt API
** sqlgdrdt API-specific parameters
** 
** NodeGroupNameLen
** The length of the name of the database partition group.
** 
** TargetPMapFileNameLen
** The length of the name of the target distribution map file.
** 
** DataDistFileNameLen
** The length of the name of the data distribution file.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Data Redistribution            */
  sqlgdrdt (
   unsigned short NodeGroupNameLen,         /* Length of nodegroup name       */
   unsigned short TargetPMapFileNameLen,    /* Length of target partition     */
                                            /* map file name                  */
   unsigned short DataDistFileNameLen,      /* Length of data distribution    */
                                            /* file name                      */
   char * pNodeGroupName,                   /* Nodegroup name                 */
   char * pTargetPMapFileName,              /* Target partition map file      */
                                            /* name                           */
   char * pDataDistFileName,                /* Data distribution file name    */
   SQL_PDB_NODE_TYPE * pAddList,            /* List of nodes to be added      */
   unsigned short AddCount,                 /* No. of nodes to be added       */
   SQL_PDB_NODE_TYPE * pDropList,           /* List of nodes to be dropped    */
   unsigned short DropCount,                /* No. of nodes to be dropped     */
   unsigned char DataRedistOption,          /* Data redistribution option     */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgexpr API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* EXPORT FROM                    */
  sqlgexpr (
   unsigned short DataFileNameLen,          /* data file name length          */
   unsigned short FileTypeLen,              /* file type length               */
   unsigned short MsgFileNameLen,           /* msg file name length           */
   char * pDataFileName,                    /* data file                      */
   sqlu_media_list * pLobPathList,          /* lob paths                      */
   sqlu_media_list * pLobFileList,          /* lob file names                 */
   struct sqldcol * pDataDescriptor,        /* dcoldata                       */
   struct sqlchar * pActionString,          /* tcolstrg                       */
   char * pFileType,                        /* file type                      */
   struct sqlchar * pFileTypeMod,           /* file type mod                  */
   char * pMsgFileName,                     /* msg file name                  */
   short CallerAction,                      /* caller action                  */
   struct sqluexpt_out*  pOutputInfo,       /* rows exported                  */
   void * pReserved,                        /* reserved                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgexpt API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Export                         */
  sqlgexpt (
   unsigned short,                          /* message file name length       */
   unsigned short,                          /* file type length               */
   unsigned short,                          /* data file name length          */
   struct sqlca *,                          /* SQLCA                          */
   struct sqluexpt_out* ,                   /* ptr to rows exported           */
   short,                                   /* caller action                  */
   _SQLOLDCHAR *,                           /* message file name              */
   struct sqlchar *,                        /* ptr to file type mod           */
   _SQLOLDCHAR *,                           /* ptr to filetype                */
   struct sqlchar *,                        /* ptr to tcolstrg                */
   struct sqldcol *,                        /* ptr to dcoldata                */
   _SQLOLDCHAR *);                          /* data file name                 */

/******************************************************************************
** sqlgimpr API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Import                         */
  sqlgimpr (
   unsigned short DataFileNameLen,          /* datafile length                */
   unsigned short FileTypeLen,              /* file type length               */
   unsigned short MsgFileNameLen,           /* msgfile length                 */
   char * pDataFileName,                    /* data file name                 */
   sqlu_media_list * pLobPathList,          /* lobpaths                       */
   struct sqldcol * pDataDescriptor,        /* dcoldata                       */
   struct sqlchar * pActionString,          /* tcolstrg                       */
   char * pFileType,                        /* filetype                       */
   struct sqlchar * pFileTypeMod,           /* filetmod                       */
   char * pMsgFileName,                     /* message file name              */
   short CallerAction,                      /* caller action                  */
   struct sqluimpt_in*  pImportInfoIn,      /* input parms                    */
   struct sqluimpt_out*  pImportInfoOut,    /* output parms                   */
   sqlint32 * NullIndicators,               /* nullind                        */
   void * pReserved,                        /* reserved                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlggrpi API - Deprecated API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Row Partitioning           */
                                            /* Information                    */
  sqlggrpi (
   unsigned short num_ptrs,                 /* Number of pointers             */
   unsigned char ** ptr_array,              /* An array of pointers           */
   unsigned short * ptr_lens,               /* An array of string lengths     */
   unsigned short territory_code,           /* Territory Code                 */
   unsigned short codepage,                 /* Codepage                       */
   struct sqlupi * part_info,               /* Partitioning Information       */
   short * part_num,                        /* Partition number               */
   SQL_PDB_NODE_TYPE * node_num,            /* Node number                    */
   unsigned short chklvl,                   /* Check level                    */
   struct sqlca * sqlca);                   /* SQLCA                          */

/******************************************************************************
** sqlggrpn API - Deprecated API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Row Partitioning Number    */
  sqlggrpn (
   unsigned short num_ptrs,                 /* Number of pointers             */
   unsigned char ** ptr_array,              /* An array of pointers           */
   unsigned short * ptr_lens,               /* An array of string lengths     */
   unsigned short territory_code,           /* Territory Code                 */
   unsigned short codepage,                 /* Codepage                       */
   struct sqlupi * part_info,               /* Partitioning Information       */
   short * part_num,                        /* Partition number               */
   SQL_PDB_NODE_TYPE * node_num,            /* Node number                    */
   unsigned short chklvl,                   /* Check level                    */
   struct sqlca * sqlca,                    /* SQLCA                          */
   short dataformat,                        /* dataformat                     */
   void * pReserved1,                       /* reserved for future use        */
   void * pReserved2);                      /* reserved for future use        */

/******************************************************************************
** sqlggtpi API - Deprecated API, use db2gGetDistMap instead.
** sqlggtpi API - specific parameters
** 
** tn_length
** A 2-byte unsigned integer with the length of the table name.
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Table Partitioning         */
                                            /* Information                    */
  sqlggtpi (
   unsigned short tn_length,                /* Length of table name           */
   unsigned char * tablename,               /* Table name                     */
   struct sqlupi * part_info,               /* Partitioning Information       */
   struct sqlca * sqlca);                   /* SQLCA                          */

/******************************************************************************
** sqlgimpt API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Import                         */
  sqlgimpt (
   unsigned short,                          /* message file name length       */
   unsigned short,                          /* file type length               */
   unsigned short,                          /* data file name length          */
   struct sqlca *,                          /* SQLCA                          */
   struct sqluimpt_out *,                   /* ptr to output parms            */
   struct sqluimpt_in *,                    /* ptr to input parms             */
   short,                                   /* caller action                  */
   _SQLOLDCHAR *,                           /* message file name              */
   struct sqlchar *,                        /* file mode description          */
   _SQLOLDCHAR *,                           /* file type                      */
   struct sqlchar *,                        /* ptr to table/column            */
   struct sqldcol *,                        /* ptr to column data             */
   _SQLOLDCHAR *);                          /* data file name                 */

/******************************************************************************
** sqlgload API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Load                           */
  sqlgload (
   unsigned short FileTypeLen,              /* file type length               */
   unsigned short LocalMsgFileNameLen,      /* message file length            */
   unsigned short RemoteMsgFileNameLen,     /* remote file length             */
   sqlu_media_list * pDataFileList,         /* data file name                 */
   sqlu_media_list * pLobPathList,          /* lobpaths                       */
   struct sqldcol * pDataDescriptor,        /* dcoldata                       */
   struct sqlchar * pActionString,          /* tcolstrg                       */
   char * pFileType,                        /* file type                      */
   struct sqlchar * pFileTypeMod,           /* filetmod                       */
   char * pLocalMsgFileName,                /* message file name              */
   char * pRemoteMsgFileName,               /* remote file name               */
   short CallerAction,                      /* caller action                  */
   struct sqluload_in * pLoadInfoIn,        /* input                          */
   struct sqluload_out * pLoadInfoOut,      /* output                         */
   sqlu_media_list * pWorkDirectoryList,    /* work directory                 */
   sqlu_media_list * pCopyTargetList,       /* copy target                    */
   sqlint32 * pNullIndicators,              /* null ind                       */
   void * pReserved,                        /* reserved                       */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgqry API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Query                          */
  sqlgqry (
   unsigned short LocalMsgFileNameLen,      /* lf_length                      */
   unsigned short RemoteMsgFileNameLen,     /* rf_length                      */
   char * pLocalMsgFileName,                /* local file                     */
   char * pRemoteMsgFileName,               /* remote file                    */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgreot API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reorganize Table               */
  sqlgreot (
   unsigned short TablespaceLen,            /* tablespace length              */
   unsigned short IndexNameLen,             /* index name length              */
   unsigned short TableNameLen,             /* table name length              */
   struct sqlca * pSqlca,                   /* SQLCA                          */
   _SQLOLDCHAR * pTablespace,               /* tablespace                     */
   _SQLOLDCHAR * pIndexName,                /* index name                     */
   _SQLOLDCHAR * pTableName);               /* table name                     */

/******************************************************************************
** sqlgstat API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Run Statistics                 */
  sqlgstat (
   unsigned short TableNameLen,             /* table name length              */
   unsigned short NumIndexes,               /* number of indices              */
   unsigned char StatsOption,               /* stats option                   */
   unsigned char ShareLevel,                /* share level                    */
   unsigned short * pIndexLens,             /* index lengths                  */
   struct sqlca * pSqlca,                   /* SQLCA                          */
   _SQLOLDCHAR ** ppIndexList,              /* index list                     */
   _SQLOLDCHAR * pTableName);               /* table name                     */

/******************************************************************************
** sqlgdref API
** Copies data from a buffer that is defined by a pointer, into a variable
** that is directly accessible by the application. This API is used in
** host programming languages, FORTRAN and COBOL, which do not provide
** pointer manipulation. This API can be used to obtain results from APIs
** that return a pointer to the desired data.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** None
** 
** API include file
** 
** sqlutil.h
** 
** sqlgdref API parameters
** 
** NumBytes
** Input. An integer representing the number of bytes to be transferred.
** 
** pTargetBuffer
** Output. Area into which the data are moved.
** 
** ppSourceBuffer
** Input. A pointer to the area containing the desired data.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Dereference Address            */
  sqlgdref (
   unsigned int NumBytes,                   /* number of bytes to transfer    */
   char * pTargetBuffer,                    /* target area for transfer       */
   char ** ppSourceBuffer);                 /* source area for transfer       */

/******************************************************************************
** sqlgmcpy API
** Copies data from one memory area to another. This API is used in host
** programming languages, FORTRAN and COBOL, that do not provide memory
** block copy functions.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** None
** 
** API include file
** 
** sqlutil.h
** 
** sqlgmcpy API parameters
** 
** pTargetBuffer
** Output. Area into which to move the data.
** 
** pSource
** Input. Area from which to move the data.
** 
** NumBytes
** Input. A 4-byte unsigned integer representing the number of bytes to be
** transferred.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Copy Memory                    */
  sqlgmcpy (
   void * pTargetBuffer,                    /* area into which to move the    */
                                            /* data                           */
   const void * pSource,                    /* area from which to move the    */
                                            /* data                           */
   sqluint32 NumBytes);                     /* number of bytes to move        */

/******************************************************************************
** sqlgaddr API
** Places the address of a variable into another variable. This API is used
** in host programming languages, FORTRAN and COBOL, which do not provide
** pointer manipulation.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** None
** 
** API include file
** 
** sqlutil.h
** 
** sqlgaddr API parameters
** 
** pVariable
** Input. Variable whose address is to be returned.
** 
** ppOutputAddress
** Output. A 4-byte area into which the variable address is returned.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Return address                 */
  sqlgaddr (
   char * pVariable,                        /* variable                       */
   char ** ppOutputAddress);                /* ptr to an area containing the  */
                                            /* address                        */

/* Configuration Utility Commands                                             */

/******************************************************************************
** sqlfrsys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reset Database Manager         */
                                            /* Configuration                  */
  sqlfrsys (
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlfrdb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reset Database Configuration   */
  sqlfrdb (
   _SQLOLDCHAR * pDbAlias,                  /* database alias                 */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlfusys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update Database Manager        */
                                            /* Configuration                  */
  sqlfusys (
   unsigned short NumItems,                 /* count of entries being         */
                                            /* modified                       */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlfudb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update Database Configuration  */
  sqlfudb (
   _SQLOLDCHAR * pDbAlias,                  /* database alias                 */
   unsigned short NumItems,                 /* count of entries being         */
                                            /* modified                       */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlfxsys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Database Manager           */
                                            /* Configuration                  */
  sqlfxsys (
   unsigned short NumItems,                 /* count of entries being         */
                                            /* returned                       */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlfxdb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Database Configuration     */
  sqlfxdb (
   _SQLOLDCHAR * pDbAlias,                  /* database alias                 */
   unsigned short NumItems,                 /* count of entries being         */
                                            /* returned                       */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlfdsys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Database Manager           */
                                            /* Configuration Defaults         */
  sqlfdsys (
   unsigned short NumItems,                 /* count of items being returned  */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlfddb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Database Configuration     */
                                            /* Defaults                       */
  sqlfddb (
   char * pDbAlias,                         /* database alias                 */
   unsigned short NumItems,                 /* count of entries to return     */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgrsys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reset Database Manager         */
                                            /* Configuration                  */
  sqlgrsys (
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgusys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update Database Manager        */
                                            /* Configuration                  */
  sqlgusys (
   unsigned short NumItems,                 /* count of entries being         */
                                            /* modified                       */
   unsigned short * pItemListLens,          /* list of item lengths           */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgxsys API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Database Manager           */
                                            /* Configuration                  */
  sqlgxsys (
   unsigned short NumItems,                 /* count of entries being         */
                                            /* returned                       */
   struct sqlfupd * pItemList,              /* list of items                  */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** sqlgstpq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Single TableSpace Query   */
  sqlgstpq (
   struct sqlca * pSqlca,
   sqluint32 TablespaceId,                       /* in: tableSpace id         */
   struct SQLB_TBSPQRY_DATA * pTablespaceData,   /* out: tableSpace data      */
   sqluint32 reserved);                          /* in: SQLB_RESERVED1        */

/******************************************************************************
** sqlgotsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Open TableSpace Query     */
  sqlgotsq (
   struct sqlca * pSqlca,
   sqluint32 TablespaceQueryOptions,             /* in: processing options:   */
                                                 /* SQLB_TBS_OPEN_xxx         */
   sqluint32 * pNumTablespaces);                 /* out: # tablespaces        */
                                                 /* defined in db             */

/******************************************************************************
** sqlgftpq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Fetch TableSpace Query    */
  sqlgftpq (
   struct sqlca * pSqlca,
   sqluint32 MaxTablespaces,                     /* size of output area       */
   struct SQLB_TBSPQRY_DATA * pTablespaceData,   /* out: array of length      */
                                                 /* maxTbs                    */
   sqluint32 * pNumTablespaces);                 /* out: #data entries        */
                                                 /* returned                  */

/******************************************************************************
** sqlgctsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Close TableSpace Query    */
  sqlgctsq (
   struct sqlca * pSqlca);

/******************************************************************************
** sqlgmtsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* TableSpace Query          */
  sqlgmtsq (
   struct sqlca * pSqlca,
   sqluint32 * pNumTablespaces,                  /* out: total number of      */
                                                 /* table spaces              */
   struct SQLB_TBSPQRY_DATA *** pppTablespaceData, /* out: mem returned to    */
                                                 /* application               */
   sqluint32 reserved1,                          /* in: SQLB_RESERVED1        */
   sqluint32 reserved2);                         /* in: SQLB_RESERVED2        */

/******************************************************************************
** sqlgotcq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Open Tablespace           */
                                                 /* Container Query           */
  sqlgotcq (
   struct sqlca * pSqlca,
   sqluint32 TablespaceId,                       /* in: id tbs or SQLB_ALL    */
                                                 /* TABLESPACES               */
   sqluint32 * pNumContainers);                  /* out:  output...the        */
                                                 /* number of containers for  */
                                                 /* the table space           */

/******************************************************************************
** sqlgftcq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Fetch Tablespace          */
                                                 /* Container Query           */
  sqlgftcq (
   struct sqlca * pSqlca,
   sqluint32 MaxContainers,                      /* in:  max # entries to     */
                                                 /* return in 'data'          */
   struct SQLB_TBSCONTQRY_DATA * pContainerData, /* out: array of 'maxCont'   */
                                                 /* entries                   */
   sqluint32 * pNumContainers);                  /* out: # data entries       */
                                                 /* returned on this query    */

/******************************************************************************
** sqlgctcq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Close Tablespace          */
                                                 /* Container Query           */
  sqlgctcq (
   struct sqlca * pSqlca);

/******************************************************************************
** sqlgtcq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Tablespace Container      */
                                                 /* Query                     */
  sqlgtcq (
   struct sqlca * pSqlca,
   sqluint32 TablespaceId,                       /* in: id a tbs or SQLB_ALL  */
                                                 /* TABLESPACES               */
   sqluint32 * pNumContainers,                   /* out: # entries returned   */
   struct SQLB_TBSCONTQRY_DATA ** ppContainerData);

/******************************************************************************
** sqlgstsc API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Set TableSpace            */
                                                 /* Containers                */
  sqlgstsc (
   struct sqlca * pSqlca,
   sqluint32 SetContainerOptions,                /* in: processing options:   */
                                                 /* SQLB_SET_CONT_xxx         */
   sqluint32 TablespaceId,                       /* in: table space which is  */
                                                 /* to be changed             */
   sqluint32 NumContainers,                      /* in:#containers in the     */
                                                 /* list                      */
   struct SQLB_TBSCONTQRY_DATA * pContainerData); /* container                */
                                                 /* specifications            */

/******************************************************************************
** sqlggtss API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get TableSpace            */
                                                 /* Statistics                */
  sqlggtss (
   struct sqlca * pSqlca,
   sqluint32 TablespaceId,
   struct SQLB_TBS_STATS * pTablespaceStats);

/******************************************************************************
** sqlgauth API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get Authorizations        */
  sqlgauth (
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** sqlgtbau API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get table authorizations  */
  sqlgtbau (
   unsigned short,                               /* table name length         */
   _SQLOLDCHAR *,                                /* fully-qualified table     */
                                                 /* name                      */
   struct sqlca *);                              /* SQLCA                     */

/* SQL Return Codes in SQLCODE for UTILITY/CONFIGURATION Commands             */

#ifndef SQL_RC_OK
#define SQL_RC_OK               0   /* everything is ok                */
#endif
#ifndef SQL_RC_INVALID_SQLCA
#define SQL_RC_INVALID_SQLCA   -1   /* invalid sqlca                   */
#endif

/* ROLL FORWARD Return Codes - more in the 4900's                             */

#define SQLU_RC_RFNOTEN                -1260   /* DB not enabled for Roll     */
                                               /* Fwd                         */
#define SQLU_RC_RFNOTP                 -1261   /* Roll Forward is not         */
                                               /* Pending                     */
#define SQLU_RC_BADPIT                 -1262   /* Bad Point in Time           */
                                               /* specified                   */
#define SQLU_RC_INVEXT                 -1263   /* Invalid Log Extent file     */
#define SQLU_RC_NOTEXT                 -1264   /* Log Extent file does not    */
                                               /* belong to DB                */
#define SQLU_RC_IVREXT                 -1265   /* Log extent file is          */
                                               /* incorrect version           */
#define SQLU_RC_PRTIME                 -1266   /* Time specified is before    */
                                               /* previous roll-forward time  */
#define SQLU_RC_UEXIT_ERR              -1268   /* User exit encountered an    */
                                               /* error (other than retry)    */
                                               /* while attempting to         */
                                               /* retrieve a log extent file  */
                                               /* for roll forward            */
#define SQLU_RC_RFINPRG                -1269   /* Rollforward by tablespace   */
                                               /* in progress.                */
#define SQLU_RC_RCVIOERR               1271    /* Roll forward complete but   */
                                               /* I/O errors encountered      */
#define SQLU_RC_RFSTOP                 -1272   /* Rollforward by tablespace   */
                                               /* has stopped.                */
#define SQLU_RC_MISSING_EXT            -1273   /* Missing log extent file.    */
#define SQLU_RC_INVTSP_STOPTIME        -1274   /* Invalid stop time for       */
                                               /* tablespace rollforward.     */
#define SQLU_INVRFR_STOPTIME           -1275   /* invalid stop time           */
                                               /* specified                   */
#define SQLU_INVRFR_STOP               -1276   /* invalid time to issue a     */
                                               /* stop                        */
#define SQLUD_INACCESSABLE_CONTAINER   1277    /* Restore found one or more   */
                                               /* containers are              */
                                               /* inaccessable                */
#define SQL_RC_RECREATE_INDEXES        1279    /* Restart complete but not    */
                                               /* all invalid  indexes were   */
                                               /* recreated                   */
#define SQLU_INVRFR_TBSPITTIME         -1280   /* invalid stop time           */
                                               /* specified for tablespace    */
                                               /* rollforward                 */
#define SQLU_RFR_REACHED_UPGRADE_OP    -2463   /* rollforward has reached an  */
                                               /* upgrade operation           */
#define SQLU_RFR_UPGRADE_CHECKS_FAILED -2464   /* rollforward has reached an  */
                                               /* upgrade operation but pre   */
                                               /* upgrade checks failed       */

#define SQLF_RC_INV_CLIENT_COMM        -1290   /* invalid client comm.        */
                                               /* protocols                   */
#define SQLF_RC_INV_DIR_FIELD          -1296   /* invalid directory services  */
                                               /* field                       */

#define SQLCC_RC_UNKNOWN_HOST          -1336   /* hostname in node dir        */
                                               /* unknown                     */
#define SQLCC_RC_UNKNOWN_SERVICE       -1337   /* service name in node        */
                                               /* directory is unknown        */
#define SQLCC_RC_UNKNOWN_SYM_DEST_NAME -1338   /* CPI-C symdestname is        */
                                               /* unknown                     */
#define SQLCC_RC_NNAME_NOTFOUND        -1341   /* wrkstn name (nname)         */
#define SQLCC_RC_NO_SOCKS_ENV_VAR      -1460   /* SOCKS env vars not found    */
#define SQLCC_RC_SOCKADDR_IN_USE       -5040   /* socket address in use       */
#define SQLCC_RC_COMM_SUPPORT_FAILED   -5042   /* general failure in          */
                                               /* servercommunications        */
                                               /* support                     */

#define SQLF_RC_INV_DISCOVER_TYPE      -1480   /* invalid discover type       */
#define SQLF_RC_INV_DISCOVER_COMM      -1481   /* invalid discover comm       */

#define SQLF_WARNING_BUFFPAGE          1482    /* buffpage may be ignored     */

/* GENERAL UTILITY Return Codes                                               */

#define SQLU_NO_XML_EXCEPTION_TABLE    -1539   /* Load block XML and          */
                                               /* Exception table             */
#define SQLU_RFR_NONRECOV_OP           -1546   /* Rollforward has reached a   */
                                               /* non-recoverable operation.  */
#define SQLU_GLOBAL_CHAIN_BREAK        -1579   /* Two or more log streams     */
                                               /* are following different     */
                                               /* log chains.                 */
#define SQLU_FUNCTION_NOT_SUPPORTED    -1651   /* Server does not support     */
                                               /* functionality               */
#define SQLU_INV_RFR_ADD_TOPOLOGY_CHG  -1715   /* Invalid add member          */
                                               /* topology change during      */
                                               /* rollforward.                */
#define SQLU_RECONCILE_GROUP_UNDEFINED 1161    /* Group not defined on DLM    */
#define SQLU_RECONCILE_EXCP_DLM_DOWN   1162    /* DLM down during exception   */
#define SQLU_BACKUP_DLM_DOWN           1196    /* DLM down during backup      */

#define SQLU_BAD_DRIVE                 -2000   /* Invalid output drive        */
#define SQLU_USER_TERM                 -2001   /* Backup terminated by user   */
#define SQLU_NOT_LOCAL                 -2002   /* database not local          */
#define SQLU_DOS_ERROR                 -2003   /* base op system error        */
#define SQLU_SQL_ERROR                 -2004   /* SQL error occurred          */
#define SQLU_READ_ERROR                -2005   /* read wrong # of bytes       */
#define SQLU_BUFF_TOO_SMALL            -2007   /* too few buffers for         */
                                               /* pagesize                    */
#define SQLU_INVALID_ACTION            -2008   /* call out of sequence        */
#define SQLU_INSUFF_MEMORY             -2009   /* insufficient memory         */
#define SQLU_STRD_ERROR                -2010   /* error in Start Using        */
#define SQLU_STPD_ERROR                -2011   /* error in Stop Using         */
#define SQLU_DIR_ERROR                 -2013   /* directory Scan error        */
#define SQLU_INVALID_DBNAME            -2015   /* invalid database name       */
#define SQLU_INVALID_PATH              -2016   /* invalid path in             */
                                               /* environment                 */
#define SQLU_START_SESSION             -2017   /* Start Session failed        */
#define SQLU_INVALID_AUTHS             -2018   /* invalid authorizations      */
#define SQLU_AUTOBIND                  -2019   /* auto-binding failed         */
#define SQLU_TIMESTAMP                 -2020   /* conflict after auto-bind    */
                                               /* control file                */
#define SQLU_IO_ERROR_LFH              -2023   /* I/O error in accessing the  */
                                               /* log                         */
#define SQLU_IO_ERROR_BRG              -2024   /* I/O error in accessing the  */
                                               /* Backup/Restore flag file    */
#define SQLU_IO_ERROR                  -2025   /* System I/O error occurred   */
#define SQLU_PAUSE_ERROR               -2026   /* error in PAUSE the started  */
                                               /* DB                          */
#define SQLU_CONT_ERROR                -2027   /* error in CONTINUE the       */
                                               /* stoped DB                   */
#define SQLU_INT_INST_ERR              -2028   /* interruption installing     */
                                               /* error                       */
#define SQLU_UEXIT_RC                  -2029   /* user exit returned non      */
                                               /* zero rc                     */

#define SQLU_FIRST_TAPE_WARNING        2031    /* warning to mount tape       */
#define SQLU_INVALID_PARM              -2032   /* parameter to utility        */
                                               /* incorrect                   */
#define SQLU_TSM_ERROR                 -2033   /* TSM reported error          */
#define SQLU_INVALID_PARM_ADDRESS      -2034   /* address of parameter        */
                                               /* incorrect                   */
#define SQLU_NOINT_ERROR               -2035   /* error during nointerrupt    */
                                               /* action                      */
#define SQLU_PATH_ERROR                -2036   /* directory does not exist    */
#define SQLU_LOAD_TSM_ERROR            -2037   /* unable to load TSM          */
#define SQLU_DBSYSTEM_ERROR            -2038   /* database system error       */
#define SQLU_NO_APP_ERROR              -2039   /* application terminated      */
#define SQLU_ALIAS_ERROR               -2040   /* alias parameter error       */
#define SQLU_BUFFSIZE_ERROR            -2041   /* buff_size parameter error   */
#define SQLU_IO_WARNING                2042    /* I/O error during change     */
                                               /* tape                        */
#define SQLU_SPAWN_EDU_ERROR           -2043   /* Spawn child process error   */
#define SQLU_QUEUE_ERROR               -2044   /* Message queue error         */
#define SQLU_OBJECT_ACCESS_ERROR       -2048   /* Object access error         */
#define SQLU_CORRUPT_IMAGE_ERROR       -2054   /* Bad backup image            */
#define SQLU_MEMORY_ACCESS_ERROR       -2055   /* Unable to access memory     */
                                               /* set                         */
#define SQLU_UNKNOWN_MEDIA_TYPE        -2056   /* device path point to        */
                                               /* unknown device type         */
#define SQLU_MEDIA_CANNOT_BE_SHARED    -2057   /* device or file already      */
                                               /* opened by other process     */
#define SQLU_END_OF_MEDIA_WARNING      2058    /* End of tape or file         */
                                               /* encountered during read     */
#define SQLU_DEVICE_FULL_WARNING       2059    /* Device is full during       */
                                               /* write                       */
#define SQLU_MEDIA_EMPTY_WARNING       2060    /* Empty device or file not    */
                                               /* found during read           */
#define SQLU_MEDIA_ACCESS_DENIED       -2061   /* Access denied due to        */
                                               /* authority level             */
#define SQLU_MEDIA_ACCESS_ERROR        -2062   /* Access error                */
#define SQLU_TERM_LAST_MEDIA_WARNING   2065    /* Terminate last Media IO.    */
#define SQLU_BAD_TABLESPACE_NAME       -2066   /* Invalid tablespace name     */
#define SQLU_NO_MEDIA_HEADER           -2068   /* Could not locate media      */
                                               /* header in backup or copy    */
                                               /* image                       */
#define SQLU_INCORRECT_DBALIAS         -2069   /* Mismatch alias name from    */
                                               /* media                       */
#define SQLU_INCORRECT_TIMESTAMP       -2070   /* Mismatch timestamp read     */
                                               /* from media                  */

#define SQLU_SHR_LIB_ACCESS_ERROR      -2071   /* Shared library access       */
                                               /* error                       */
#define SQLU_BIND_SHR_LIB_ERROR        -2072   /* Bind shared library error   */

#define SQLU_DATALINK_INTERNAL_ERROR   -2073   /* Error at DB2 or DLFM        */
#define SQLU_DATALINK_DB_ERROR         -2074   /* Error at DB2 end            */
#define SQLU_DATALINK_DLFM_ERROR       -2075   /* Error at DLFM end           */
#define SQLU_REGISTER_DLFM_WARNING     2076    /* Unable to register DLM      */
                                               /* Server                      */
#define SQLU_RECONCILE_DLM_PEND_WARN   2077    /* DLMs down during reconcile  */
#define SQLU_SHR_LIB_VENDOR_API_ERROR  -2079   /* Shared library vendor API   */
                                               /* error                       */
#define SQLUB_NOTUNIQUE_DB_ERROR       -2080   /* Database is not unique      */
                                               /* enough for backup           */
#define SQLUD_NOTUNIQUE_DB_ERROR       -2081   /* Database is not unique      */
                                               /* enough for restore          */
#define SQLUD_TSP_RESTORE_OUT_OF_SEQ   -2154   /* Out of sequence tablespace  */
                                               /* restore                     */

/* ARCHIVE LOG Return Codes                                                   */
#define SQLU_ARCHIVELOG_ERROR          -1259   /* Archive log error.          */
#define SQLU_ARCHIVELOG_NONRECOV_DB    -2417   /* Database is not in          */
                                               /* recoverable mode.           */

/* HISTORY TABLE Return Codes                                                 */
#define SQLUH_SCAN_UPDATED_WARNING     2155    /* Changes were made to        */
                                               /* historyfile during update.  */
#define SQLUH_MAX_SCANS_EXCEEDED       -2157   /* MAX # open scans exceeded   */
#define SQLUH_FILE_REPLACED_WARNING    2160    /* History file fixed          */
#define SQLUH_DAMAGED_FILE             -2161   /* History file is unfixable   */
#define SQLU_INV_PERM_LOGFILE          -2162   /* A log file does not have    */
                                               /* read/write permission       */
#define SQLU_RECOVER_NO_IMAGE_FOUND    -2163   /* No suitable backup image    */
                                               /* could be found for use in   */
                                               /* the recover operation       */
#define SQLU_RECOVER_FILE_NOT_FOUND    -2164   /* RECOVER could not locate a  */
                                               /* history file                */
#define SQLUH_SQLUHINFO_VARS_WARNING   2165    /* number of tablespaces       */
                                               /* changed                     */
#define SQLUH_INSUF_LOGSTREAMS_WARNING 2167    /* Insufficient number of log  */
                                               /* streams were allocated by   */
                                               /* caller                      */
#define SQLU_RECOVER_DB_NOT_FOUND      -2166   /* RECOVER failed because      */
                                               /* database does not exist     */
#define SQLUH_DUPLICATE_ENTRY          -2170   /* Duplicate timestamp found   */
#define SQLUH_ENTRY_NOT_FOUND          -2171   /* Entry not found on update   */
#define SQLU_ACCESS_HIST_WARNING       2172    /* Access history file         */
                                               /* warning                     */

/* PRUNE command return codes                                                 */
#define SQLU_PRUNE_LOG_NOT_ALLOWED     -1206   /* PRUNE LOGFILE not allowed   */
                                               /* in this database            */
                                               /* configuration               */

/* REORGANIZE TABLE Return Codes                                              */
#define SQLUR_INVALID_AUTHID           -2200   /* invalid authid on index     */
                                               /* name                        */
#define SQLUR_INVALID_TABLENAME        -2203   /* invalid tablename syntax    */
#define SQLUR_INVALID_INDEXNAME        -2204   /* invalid tablename syntax    */
#define SQLUR_INDEX_NOT_FOUND          -2205   /* index doesn't exist         */
#define SQLUR_INVALID_FILEPATH         -2207   /* invalid filepath pointer    */
#define SQLUR_INVALID_TABLESPACE       -2208   /* invalid tablespace pointer  */
#define SQLUR_TABLE_NOT_FOUND          -2211   /* table does not exist        */
#define SQLUR_VIEW_ERROR               -2212   /* cannot reorg a view         */
#define SQLUR_INCORRECT_TABLESPACE     -2213   /* Incorrect tablespace type   */
#define SQLUR_INSAUTH                  -2214   /* insuffic authority          */
#define SQLUR_SQLERR_COMPREV           -2215   /* SQL error commiting prev    */
                                               /* work                        */
#define SQLUR_SQLERR_REORG             -2216   /* SQL error during            */
                                               /* reorganization              */
#define SQLUR_INV_TEMP                 -2217   /* Invalid temp tablespace     */
                                               /* for reorg table             */
#define SQLUR_INCOMPAT_OPTS            -2218   /* Incompatible options        */
                                               /* specified for reorg table   */
#define SQLUR_INV_ACTION               -2219   /* Invalid action for reorg    */
                                               /* table INPLACE               */
#define SQLUR_ROW_COMP_NO_DATA         2220    /* Insufficient data for       */
                                               /* dictionary build            */
#define SQLUR_INV_DATA_PARTITION       -2222   /* Invalid data partition      */
                                               /* name                        */

/* RUN STATISTICS Return Codes                                                */
#define SQLUS_INVALID_AUTHID           -2300   /* invalid authid              */
#define SQLUS_INVALID_TABLE_NAME       -2301   /* invalid table name          */
#define SQLUS_INVALID_INDEX_LIST       -2302   /* invalid index pointer       */
#define SQLUS_INVALID_STATS_OPT        -2303   /* statsopt parameter invalid  */
#define SQLUS_INVALID_SHARE_LEV        -2304   /* sharelev parameter invalid  */
#define SQLUS_VIEWS_NICKS_NOT_ALLOWED  -2305   /* table specified is a view   */
                                               /* or nickname                 */
#define SQLUS_OBJ_DOES_NOT_EXIST       -2306   /* object doesn't exist        */
#define SQLUS_SYS_TABLE_NOT_ALLOWED    -2307   /* system table not allowed    */
#define SQLUS_INVALID_INDEX_AUTHID     -2308   /* index authid invalid        */
#define SQLUS_INVALID_INDEX_NAME       -2309   /* index name invalid          */
#define SQLUS_ERROR_STAT               -2310   /* error running statistics    */
#define SQLUS_INSAUTH                  -2311   /* insuffic authority for      */
                                               /* runstats                    */
#define SQLUS_STATS_HEAP_TOO_SMALL     -2312   /* statistics heap is too      */
                                               /* small                       */
#define SQLUS_PARTIAL_SUCCESS          2313    /* incomplete statistics       */
                                               /* collected                   */
#define SQLUS_INCONSISTENT_STATS       2314    /* Statistics are in an        */
                                               /* inconsistent state          */

#define SQLUD_RST_NOROLLFWD            3       /* Rst DB turn off roll fwd    */
                                               /* pend, old OS/2 API only     */
/* Old OS/2 Backup calling action values                                      */
#define SQLU_BACK_ALL                  0x0     /* backup entire database      */
#define SQLU_BACK_CHANGES              0x1     /* backup changes only         */
#define SQLU_BACK_QUIESCE              0x800   /* quiesce during backup       */
#define SQLU_NEW_UOW_RETURN_ERROR      0x400   /* New UOW return error immed  */

#define SQLU_DBM_ERROR                 -2014   /* pause or Continue or        */
                                               /* migration error             */
#define SQLU_WRONG_DISKETTE            -2021   /* Wrong diskette inserted     */
#define SQLU_DISK_FULL                 -2030   /* a specific fixed disk is    */
                                               /* full                        */

#define SQLUB_LOG_NOT_TRUNC            2425    /* Log not truncated during    */
                                               /* backup                      */
#define SQLUD_BIND_WARNING             2507    /* Restore utility not bound   */
#define SQLUD_DROP_ERROR               -2511   /* error dropping database     */

/* BACKUP Return Codes                                                        */
#define SQLUB_ROLLFWD_PENDING          -2406   /* The Backup can't run        */
                                               /* because roll forward is     */
                                               /* pending                     */
#define SQLUB_CORRUPT_PAGE             -2412   /* data page encountered       */
                                               /* during backup is corrupted  */
#define SQLUB_LOGRETAIN_ONLINE_ERROR   -2413   /* retain req'd for online     */
                                               /* backup                      */
#define SQLUB_NEXT_TAPE_WARNING        2416    /* tape full, mount another    */
#define SQLUB_DBASE_DOES_NOT_EXIST     -2418   /* database does not exist     */
#define SQLUB_DISK_FULL_ERROR          -2419   /* disk full during backup     */

#define SQLUB_FIRST_TAPE_ERROR         -2420   /* first tape cannot hold      */
                                               /* header                      */
#define SQLUB_LOGRETAIN_TBS_ERROR      -2421   /* retain req'd for tbs        */
                                               /* backup                      */
#define SQLUB_MISSING_INDEX            -2423   /* A required index is         */
                                               /* missing during an offline   */
                                               /* backup                      */
#define SQLUB_COPY_IN_PROGRESS         -2424   /* Copy operation at DLFMend   */
                                               /* is still in progress        */
#define SQLUB_TRACKMOD_INCR_ERROR      -2426   /* TRACKMOD req'd for          */
                                               /* incremental backup          */
#define SQLUB_MISSING_ENTRYPOINT       -2427   /* Saved library is missing    */
                                               /* an entry point              */
#define SQLUB_BACKUP_LOGS_ERROR        -2428   /* Failed to backup requested  */
                                               /* logfile                     */
#define SQLUB_DPF_BACKUP_FAILED        -2429   /* Multi-node backup           */
                                               /* operation failed            */
#define SQLUB_DPF_TBS_DO_NOT_EXIST     2430    /* One or more tablespaces do  */
                                               /* not exist on this           */
                                               /* partition                   */
#define SQLUB_DPF_INCLUDES_LOGS        2431    /* Backup contains logs        */
#define SQLUB_CANNOT_EXCLUDE_LOGS_ERR  -2432   /* Backup cannot exclude logs  */
#define SQLUB_BACKUP_LOGS_WARNING      2440    /* Warn that not all log       */
                                               /* files were backed up        */
#define SQLUB_ENCR_OPTIONS_ERROR       -2459   /* Duplicate or conflicting    */
                                               /* encryption options were     */
                                               /* supplied                    */
#define SQLUB_RAWLOGS_NOT_SUPPORTED    -21002  /* Backup of database with     */
                                               /* raw logs is not supported   */

/* RESTORE Return Codes                                                       */
#define SQLUD_NO_ENCR_EXPECTED         -1743   /* the database in the backup  */
                                               /* image is encrypted but the  */
                                               /* existing database on disk   */
                                               /* is not encrypted.           */
#define SQLUD_INV_ENCR_OPTS            -1744   /* the target database         */
                                               /* already exists and          */
                                               /* encryption options were     */
                                               /* specified.                  */
#define SQLUD_CANNOT_RESTORE           -2501   /* can't read restored         */
                                               /* database                    */
#define SQLUD_DISKETTE_ERROR           -2502   /* error reading backup        */
                                               /* diskette                    */
#define SQLUD_WRONG_DATABASE           -2503   /* wrong backup diskette       */
#define SQLUD_DISKETTE_PROMPT          2504    /* prompt for backup diskette  */
#define SQLUD_DROP_WARNING             2505    /* warn that drop will be      */
                                               /* done                        */
#define SQLUD_DATABASE_WARNING         2506    /* Restore worked, but not     */
                                               /* cleanup                     */
#define SQLUD_INVALID_TIMESTAMP        -2508   /* timestamp incorrectly       */
                                               /* specified                   */
#define SQLUD_INVALID_DBDRV            -2509   /* invalid database drive      */
#define SQLUD_SEM_ERROR                -2510   /* semaphore error             */
#define SQLUD_CREATE_ERROR             -2512   /* error creating database     */
#define SQLUD_REN_ERROR                -2513   /* error renaming database     */
#define SQLUD_BAD_VERSION              -2514   /* restored database wrong     */
                                               /* version                     */
#define SQLUD_INSAUTH                  -2515   /* insuffic authority to       */
                                               /* restore                     */
#define SQLUD_DBACT                    -2516   /* a database active           */
#define SQLUD_MIGRATE_WARNING          2517    /* database migrated with      */
                                               /* warning(s)                  */
#define SQLUD_MIGRATED                 SQLUD_MIGRATE_WARNING
#define SQLUD_RST_DBCONG_ERR           -2518   /* error in restoring DB       */
                                               /* config.                     */
#define SQLUD_MIGRATE_ERROR            -2519   /* error in migrating the      */
                                               /* database                    */
#define SQLUD_DBCON_WARN               2520    /* DBCON file is restored      */
                                               /* using the backup version    */
#define SQLUD_TOO_MANY_BACKUP_FILES    -2522   /* more than one file match    */
#define SQLUD_MEDIA_CORRUPT            -2530   /* corrupted backup image      */
#define SQLUD_WRGIMAGE_ERROR           -2532   /* image of wrong database     */
#define SQLUD_WRGIMAGE_WARNING         2533    /* image of wrong database     */
#define SQLUD_WRONGSEQ_WARNING         2536    /* seq number of backup        */
                                               /* incorrect                   */
#define SQLUD_MUST_ROLLFWD             -2537   /* roll forward required       */
#define SQLUD_UNEXPECT_EOF_ERROR       -2538   /* end of file reached         */
                                               /* unexpectedly                */
#define SQLUD_NOINT_WARNING            2540    /* noint type restore had      */
                                               /* warning                     */
#define SQLUD_CLOSE_MEDIA_WARNING      2541    /* unable to close backup      */
                                               /* file                        */
#define SQLUD_NO_BACKUP_FILE_MATCH     -2542   /* no backup file match found  */
#define SQLUD_DB_DIR_ERROR             -2543   /* invalid directory for new   */
                                               /* dbase                       */
#define SQLUD_DISK_FULL_ERROR          -2544   /* disk full during restore    */
#define SQLUD_NOT_FIRST_IMAGE          -2546   /* restore requires first      */
                                               /* image first                 */
#define SQLUD_OLD_ONLINE_IMAGE_ERROR   -2547   /* cannot restore online       */
                                               /* backup from a previous      */
                                               /* release                     */
#define SQLUD_IMAGE_DB_CP_MISMATCH     -2548   /* backup has diff codepage    */
                                               /* from disk DB                */
#define SQLUD_ALL_TBLSPACES_SKIPPED    -2549   /* all tablespaces skipped     */
                                               /* during restore              */
#define SQLUD_WRONG_NODE               -2550   /* backup from a different     */
                                               /* node                        */
#define SQLUD_WRONG_CAT_NODE           -2551   /* backup of a database with   */
                                               /* a different catalog node    */
#define SQLUD_REPORTFILE_ERROR         -2552   /* Report filename length      */
                                               /* >255                        */
#define SQLU_RECONCILE_GENERIC_ERROR   -2554   /* Reconcile Genereic Error    */
#define SQLUD_MIGRATED_OK              2555    /* database migrated           */
                                               /* successfully                */
#define SQLUD_RESTORE_LOGS_WARNING     2556    /* Not all required log files  */
                                               /* were backed up              */

/*  the meaning of the following 8 warnings :                                 */
/*        A -> database alias                                                 */
/*        N -> database name                                                  */
/*        S -> database seed                                                  */
/*        0 -> target db value DOES NOT matches backup image value            */
/*        1 -> target db value matches backup image value                     */
#define SQLUD_A0N0S0_WARNING           2529
#define SQLUD_A0N0S1_WARNING           2528
#define SQLUD_A0N1S0_WARNING           2525
#define SQLUD_A0N1S1_WARNING           2524
#define SQLUD_A1N0S0_WARNING           2527
#define SQLUD_A1N0S1_WARNING           2526
#define SQLUD_A1N1S0_WARNING           2523
#define SQLUD_A1N1S1_WARNING           2539
#define SQLUD_TBLSP_TO_OTHER_DB        -2560   /* Restoring a table space     */
                                               /* into another database.      */
#define SQLUD_REBUILD_DB               2561    /* Rebuild a database from     */
                                               /* tablespace images or a      */
                                               /* subset of tablespaces from  */
                                               /* any image.                  */

/* SQLUD_TBLSP_TO_NEW_DB has been deprecated and now SQLUD_REBUILD_DB should  */
/* be used.                                                                   */

#define SQLUD_NOTALL_TBS_RESTORED      2563    /* Not all table spaces were   */
                                               /* restored                    */
#define SQLUD_DB_MISMATCH              2565    /* Deprecated.                 */
#define SQLUD_WRONG_DB                 -2565   /* Database in backup image    */
                                               /* and database on disk being  */
                                               /* restored to are different;  */
                                               /* must be the same.           */
#define SQLUD_TBS_DATALINK_PENDING     2566    /* Tables in tablespaces are   */
                                               /* in DRP/RNP state            */
#define SQLUD_WRONG_PLATFORM           -2570   /* Image is being restored on  */
                                               /* the wrong platform          */
#define SQLU_HEADER_WRITE_ERR          2045    /* Problem on first media      */
                                               /* write                       */
#define SQLUD_AUTO_PROCESSING_ERROR    -2571   /* Error encountered during    */
                                               /* automatic restore           */
                                               /* processing                  */
#define SQLUD_INCR_HISTORY_ERROR       SQLUD_AUTO_PROCESSING_ERROR /*         */
#define SQLUD_INCR_RESTORE_OUT_OF_SEQ  -2572   /* Incremental restore out of  */
                                               /* sequence                    */
#define SQLUD_NON_INCR_RESTORE         -2573   /* Incremental image being     */
                                               /* restored non-incrementally  */
#define SQLUD_INCR_TOO_NEW             -2574   /* Incremental image being     */
                                               /* restored is newer than      */
                                               /* target image                */
#define SQLUD_INCR_TOO_OLD             -2575   /* Incremental image being     */
                                               /* restored is older than      */
                                               /* previous image              */
#define SQLUD_MISSING_INCR_CLAUSE      -2576   /* Incremental restore is      */
                                               /* missing "incremental"       */
                                               /* clause                      */
#define SQLUD_NO_DECOMPR_LIBRARY       -2577   /* No decompression library    */
                                               /* was found for this restore  */
                                               /* operation                   */
#define SQLUD_OBJ_NOT_FOUND            -2578   /* Specified object was not    */
                                               /* found in restore image      */
#define SQLUD_LOGS_RESTORE_WARNING     2580    /* Restore completed but       */
                                               /* error extracting logs.      */
#define SQLUD_LOGS_RESTORE_ERROR       -2581   /* Restore only logfiles       */
                                               /* failed.                     */
#define SQLUD_REBUILD_IN_PROGRESS      2582    /* Rebuild already in          */
                                               /* progress.                   */
#define SQLUD_INCR_IN_PROGRESS         -2583   /* Incremental restore is      */
                                               /* already in progress.        */
#define SQLUD_LOGS_MUST_BE_RESTORED    -2584   /* Logs must be restored       */
                                               /* during restore error.       */
#define SQLUD_WRONG_INSTANCE_ERROR     -2585   /* Image from wrong instance.  */
#define SQLUD_TRANSPORT_ERROR          -2590   /* Schema Transport failed.    */

/* sqlgadau and sqluadau Return codes                                         */
#define SQLUA_BAD_INPUT_PARAMETER      -2600   /* sql_authorizations parm is  */
                                               /* bad                         */

/* Asynchronous Read Log SQLCODES                                             */
#define SQLU_RLOG_INVALID_PARM         -2650   /* invalid parameter(s)        */
                                               /* detected                    */
#define SQLU_RLOG_DB_NOT_READABLE      -2651   /* database has circular logs  */
#define SQLU_RLOG_INSUFF_MEMORY        -2652   /* insufficient memory for     */
                                               /* internal buffer             */
#define SQLU_RLOG_LSNS_REUSED           2653   /* log sequence numbers        */
                                               /* reused                      */
#define SQLU_RLOG_READ_TO_CURRENT       2654   /* read to end of database     */
                                               /* log                         */
#define SQLU_RLOG_EXTDB_INCORRECT      -2655   /* log extent not for this     */
                                               /* database                    */
#define SQLU_RLOG_INVALID_EXTENT       -2656   /* invalid extent encountered  */
#define SQLU_RLOG_EXTENT_REQUIRED      -2657   /* log reader requires an      */
                                               /* extent not in the log path  */

/* DB2SPLIT Return codes                                                      */
#define SQLUSP_CMD_LINE_OPT_ERR        -2701   /* invalid command line        */
                                               /* options                     */
#define SQLUSP_OPEN_CFG_FILE_ERR       -2702   /* fail to open config file    */
#define SQLUSP_OPEN_LOG_FILE_ERR       -2703   /* fail to open log file       */
#define SQLUSP_OPEN_IN_DATA_FILE_ERR   -2704   /* fail to open input data     */
                                               /* file                        */
#define SQLUSP_OPEN_INPUT_MAP_FILE_ERR -2705   /* fail to open input          */
                                               /* partition map file          */
#define SQLUSP_OPEN_OUTMAP_FILE_ERR    -2706   /* fail to open output         */
                                               /* partition map file          */
#define SQLUSP_OPEN_DIST_FILE_ERR      -2707   /* fail to open distribution   */
                                               /* file                        */
#define SQLUSP_OPEN_OUTDATA_FILE_ERR   -2708   /* fail to open output data    */
                                               /* file                        */
#define SQLUSP_CFG_SYNTAX_ERR          -2709   /* syntax error in config      */
                                               /* file                        */
#define SQLUSP_INVALID_CFG_KEYWORD     -2710   /* invalid keyword in config   */
                                               /* file                        */
#define SQLUSP_INVALID_COL_DELIMITER   -2711   /* column delimiter can't be   */
                                               /* a blank                     */
#define SQLUSP_INVALID_STR_DELIMITER   -2712   /* string delimiter can't be   */
                                               /* a period                    */
#define SQLUSP_INVALID_RUNTYPE         -2713   /* invalid run type in config  */
                                               /* file                        */
#define SQLUSP_INVALID_MSG_LEVEL       -2714   /* invalid Message Level in    */
                                               /* config file                 */
#define SQLUSP_INVALID_CHK_LEVEL       -2715   /* invalid Check Level in      */
                                               /* config file                 */
#define SQLUSP_INVALID_REC_LEN         -2716   /* record length out of range  */
#define SQLUSP_INVALID_NODE            -2717   /* invalid node specification  */
#define SQLUSP_INVALID_OUTPUTNODE      -2718   /* invalid output node         */
                                               /* specification               */
#define SQLUSP_INVALID_OUTPUTTYPE      -2719   /* invalid output type         */
#define SQLUSP_TOO_MANY_PTITN_KEYS     -2720   /* too many partitioning keys  */
#define SQLUSP_INVALID_PTITN_KEYS      -2721   /* invalid partition key       */
                                               /* specification               */
#define SQLUSP_INVALID_LOG_FILE        -2722   /* invalid log file            */
                                               /* specification               */
#define SQLUSP_INVALID_TRACE           -2723   /* invalid trace               */
                                               /* specification               */
#define SQLUSP_NODE_ERR                -2724   /* specify one and only one:   */
                                               /* MAPFILI or NODE             */
#define SQLUSP_NO_OUTMAP               -2725   /* Output partition map is     */
                                               /* needed                      */
#define SQLUSP_NO_PTITN_KEY            -2726   /* no partitioning key         */
                                               /* defined                     */
#define SQLUSP_KEY_OUT_RANGE           -2727   /* key exceeds record length   */
#define SQLUSP_NODE_NOT_EXISTED        -2728   /* output node list is not a   */
                                               /* subset of node list         */
#define SQLUSP_INPUT_MAP_ERR           -2729   /* invalid data entry in       */
                                               /* input map                   */
#define SQLUSP_WRITE_HEAD_ERR          -2730   /* error writing header of     */
                                               /* out data file               */
#define SQLUSP_DATA_READ_ERR           -2731   /* error processing input      */
                                               /* data file                   */
#define SQLUSP_DATA_BIN_ERR            -2732   /* binary data if VMMVS        */
#define SQLUSP_NO_RUNTYPE              -2733   /* run type not specified      */
#define SQLUSP_32KLIMIT_DEF_ERR        -2734   /* 32kLimit definition error   */
#define SQLUSP_DISCARD_REC_WARN        2735    /* discard empty record        */
#define SQLUSP_GRPI_ERR                -2736   /* error from sqlugrpi or      */
                                               /* sqlugrpn                    */
#define SQLUSP_DATA_WRITE_ERR          -2737   /* error writing data file     */
#define SQLUSP_DATA_WRITE_WARN         2738    /* data is truncated in        */
                                               /* writing                     */
#define SQLUSP_BIN_NO_RECLEN           -2739   /* reclen must be defined for  */
                                               /* BIN                         */
#define SQLUSP_FLOAT_NOT_ALLOWED       -2740   /* FLOAT is not supported for  */
                                               /* DEL/ASC                     */
#define SQLUSP_FILETYPE_DEF_ERR        -2741   /* invalid file type           */
#define SQLUSP_DECIMAL_LEN_NOT_MATCH   -2742   /* decimal len not match its   */
                                               /* precision                   */
#define SQLUSP_DATA_LEN_NOT_MATCH      -2743   /* len not match for binary    */
                                               /* type data                   */
#define SQLUSP_ILLEGAL_FILENAME        -2744   /* illegal filename in cfg     */
                                               /* file                        */
#define SQLUSP_NEWLINE_DEF_ERR         -2745   /* Invalid NEWLINE flag in     */
                                               /* cfg file                    */
#define SQLUSP_INCOMPLETE_RECORD       -2746   /* Incomplete record in input  */
                                               /* data file                   */
#define SQLUSP_RECORD_TOO_LONG         -2747   /* ASC record must be no       */
                                               /* longer than 32K             */
#define SQLUSP_RECORD_TOO_SHORT        -2748   /* ASC record not long enough  */
#define SQLUSP_KEY_NOT_IN_32K          -2749   /* partition key not in the    */
                                               /* first 32k bytes of the      */
                                               /* record.                     */
#define SQLUSP_CFG_LINE_TOO_LONG       -2750   /* line too long in cfg file   */
#define SQLUSP_REC_LEN_ERR             -2751   /* expected reclen not         */
                                               /* matching actual reclen      */
#define SQLUSP_INVALID_CODEPAGE        -2752   /* invalid codepage            */
                                               /* specification               */
#define SQLUSP_APP_CODEPAGE_ERR        -2753   /* failed to get application   */
                                               /* CP                          */
#define SQLUSP_CODEPAGE_NOTABLE        -2754   /* codepages not convertable   */
#define SQLUSP_DELIMITER_ERROR         -2755   /* codepage-related delimiter  */
                                               /* error                       */
#define SQLUSP_CP_DATA_TO_DB           -2756   /* error converting data to    */
                                               /* DB CP                       */
#define SQLUSP_EBCDIC_NO_BIN           -2757   /* binary numerics not         */
                                               /* allowed in EBCDIC data      */

/* DB2GPMAP Return Codes                                                      */
#define SQLUGPMAP_TBL_AND_NDGRP        -2761   /* Specify only tbl or         */
                                               /* nodegrp                     */
#define SQLUGPMAP_NO_INST_PATH         -2762   /* fail to find DB install     */
                                               /* path                        */
#define SQLUGPMAP_TBL_NOT_FOUND        -2763   /* tbl not found               */
#define SQLUGPMAP_NODEGRP_NOT_FOUND    -2764   /* nodegrp not found           */
#define SQLUGPMAP_OPEN_OUTMAPFILE_WARN 2765    /* fail to open file           */
#define SQLUGPMAP_PTITN_MAP_ERR        -2766   /* incorrect ptitn map size    */
#define SQLUGPMAP_INVALID_CMD_OPT      -2767   /* invalid cmd line option     */
#define SQLUGPMAP_UGTPI_API_DEP        -2768   /* sqlugtpi API deprecated     */

/* IMPORT/EXPORT Return codes                                                 */
#define SQLUE_DFO                      -3001   /* error opening output file   */
#define SQLUE_IOE                      -3002   /* i/o error writing output    */
                                               /* file                        */
#define SQLUE_CLS                      -3003   /* i/o error closing output    */
                                               /* file                        */
#define SQLUE_IFT                      -3004   /* invalid filetype parameter  */
#define SQLUE_CBI                      -3005   /* function interrupted        */
#define SQLUE_MFO                      -3006   /* i/o error opening message   */
                                               /* file                        */
#define SQLUE_MFW                      -3007   /* i/o error writing message   */
                                               /* file                        */
#define SQLUE_STA                      -3008   /* start using database        */
                                               /* failed                      */
#define SQLUE_STR                      -3009   /* invalid tcolstrg            */
#define SQLUE_COL                      -3010   /* invalid dcoldata            */

#define SQLUE_MEM                      -3011   /* memory allocation error     */
#define SQLUE_SYSERR                   -3012   /* system error                */
#define SQLUE_FTMOD                    -3013   /* invalid filetmod            */
#define SQLUE_MFC                      -3014   /* failure on closing message  */
                                               /* file                        */
#define SQLUE_SQLERR                   -3015   /* SQL error occurred          */
#define SQLUE_FMODNK                   -3016   /* no keywords found           */
#define SQLUE_FMODID                   -3017   /* invalid delimiter or        */
                                               /* duplicate                   */
#define SQLUE_FMODDEC                  -3018   /* decimal used for char       */
                                               /* delimiter                   */
#define SQLUE_NTS                      -3019   /* no tcolstrg                 */
#define SQLUE_RC_INSAUTH               -3020   /* insufficient authority for  */
                                               /* exp.                        */

#define SQLUI_RC_INSAUTH               -3021   /* insufficient authority for  */
                                               /* imp.                        */
#define SQLUE_SQL_PREP_ERR             -3022   /* SQL error on input string   */
#define SQLUE_DATABASE                 -3023   /* invalid database name       */
#define SQLUE_DATAFILE                 -3025   /* invalid datafile            */
#define SQLUE_MSGFILE                  -3026   /* invalid msgfile             */
#define SQLUE_DCOLMETH                 -3028   /* Export method indicator     */
                                               /* not n/d                     */
#define SQLUE_NUL_FTYPE                -3029   /* filetype is null            */

#define SQLUI_DFO                      -3030   /* error opening input data    */
                                               /* file                        */
#define SQLUI_IOE                      -3031   /* i/o error reading input     */
                                               /* file                        */
#define SQLUI_DCOLMETH                 -3032   /* Import method not n/d/p     */
#define SQLUI_TINSERT                  -3033   /* invalid insert in tcolstrg  */
#define SQLUI_TINTO                    -3034   /* invalid into in tcolstrg    */
#define SQLUI_TABLENAME                -3035   /* invalid tablename in        */
                                               /* tcolstrg                    */
#define SQLUI_CPAREN                   -3036   /* close paren not in          */
                                               /* tcolstrg                    */
#define SQLUE_SQL_PREP_INSERT          -3037   /* SQL error on insert string  */
#define SQLUI_TCOLJUNK                 -3038   /* tcolstrg invalid            */
#define SQLU_REDUCE_CPUPAR             3039    /* load parallelism reduced    */
#define SQLUE_LOBFILE_ERROR            -3040   /* lob file error              */

#define SQLUI_DL_ILLEGAL_LINKTYPE      -3042   /* LINKTYPE is not URL         */
#define SQLUI_DL_COL_JUNK              -3043   /* dl_specification invalid    */
#define SQLUI_DL_COL_DUP_PREFIX        -3044   /* multiple prefix decl per    */
                                               /* col                         */

#define SQLUIC_BAD_DCOL_POS            -3045   /* invalid dcol position for   */
                                               /* CSV                         */
#define SQLUI_NONDEF_DCOL_NOCOLS       -3046   /* non-default dcol and no     */
                                               /* cols                        */
#define SQLUI_BAD_DCOL_METH            -3047   /* dcolinfo has invalid        */
                                               /* method                      */
#define SQLUI_NODCOL_FOR_NONNULL_DBCOL -3048   /* non nullable column         */
#define SQLUIC_UNSUPTYP_NONULLS        -3049   /* unsupported column type     */

#define SQLUII_CONVERSION              3050    /* conversion for cdpg         */
#define SQLU_PATH_MISSING              -3052   /* Required path is missing    */
#define SQLUII_HEOF                    -3054   /* eof reading first rec in    */
                                               /* IXF                         */
#define SQLUII_HLEN_CONV               -3055   /* length of 'H' rec not       */
                                               /* numeric                     */
#define SQLUII_HLEN_SHORT              -3056   /* first record too short      */
#define SQLUII_HTYP                    -3057   /* first IXF rec is not 'H'    */
#define SQLUII_HID                     -3058   /* no IXF identifier in 'H'    */
#define SQLUII_HVERS                   -3059   /* invalid version field in    */
                                               /* 'H'                         */

#define SQLUII_HCNT                    -3060   /* HCNT in 'H' not numeric     */
#define SQLUII_HSBCP_BAD               -3061   /* SBCP in 'H' not numeric     */
#define SQLUII_HDBCP_BAD               -3062   /* DBCP in 'H' not numeric     */
#define SQLUII_HSBCP_CMP               -3063   /* 'H' SBCP not compat w/data  */
                                               /* SBCP                        */
#define SQLUII_HDBCP_CMP               -3064   /* 'H' DBCP not compat w/data  */
                                               /* DBCP                        */
#define SQLUII_DB_CODEPG               -3065   /* can't get codepages         */
#define SQLUII_TEOF                    -3066   /* eof reading/looking for     */
                                               /* 'T' rec                     */
#define SQLUII_TLEN_CONV               -3067   /* length of 'T' rec not       */
                                               /* numeric                     */
#define SQLUII_TLEN_SHORT              -3068   /* 'T' record is too short     */
#define SQLUII_TTYP                    -3069   /* first non-'A' rec not 'T'   */
                                               /* rec                         */

#define SQLUII_ALEN_BAD                -3070   /* invalid rec length of 'A'   */
                                               /* rec                         */
#define SQLUII_TCONV                   -3071   /* invalid data convention in  */
                                               /* 'T'                         */
#define SQLUII_TFORM                   -3072   /* invalid data format in 'T'  */
#define SQLUII_TMFRM                   -3073   /* invalid machine form in     */
                                               /* 'T'                         */
#define SQLUII_TLOC                    -3074   /* invalid data location in    */
                                               /* 'T'                         */
#define SQLUII_TCCNT                   -3075   /* 'C' rec cnt in 'T' not      */
                                               /* numeric                     */
#define SQLUII_TNAML                   -3076   /* name len fld in 'T' not     */
                                               /* numeric                     */
#define SQLUII_CCNT_HIGH               -3077   /* too many 'C' records        */
#define SQLUII_ALEN_CONV               -3078   /* length of 'A' rec not       */
                                               /* numeric                     */
#define SQLUII_CLEN_CONV               -3079   /* length of 'C' rec not       */
                                               /* numeric                     */

#define SQLUII_CLEN_SHORT              -3080   /* 'C' record is too short     */
#define SQLUII_CTYP                    -3081   /* wrong rec type / 'C'        */
                                               /* expected                    */
#define SQLUII_CEOF                    -3082   /* EOF while processing 'C'    */
                                               /* recs                        */
#define SQLUII_CDRID                   -3083   /* 'D' rec id field not        */
                                               /* numeric                     */
#define SQLUII_CPOSN                   -3084   /* 'D' rec posn field not      */
                                               /* numeric                     */
#define SQLUII_CIDPOS                  -3085   /* 'D' id/position not         */
                                               /* consistent                  */
#define SQLUII_NOCREC_FOR_NONNULL_DBCOL -3086  /* IXF column does not exist   */
#define SQLUII_INVCREC_NONNULL_DBCOL   -3087   /* IXF column not valid        */
#define SQLUII_CRECCOMP_NONNULL_DBCOL  -3088   /* IXF column not compatible   */
#define SQLUII_DTYP                    -3089   /* wrong rec type / 'D'        */
                                               /* expected                    */

#define SQLUII_DLEN_CONV               -3090   /* length of 'D' rec not       */
                                               /* numeric                     */
#define SQLUII_DLEN_RANGE              -3091   /* length of 'D' rec not       */
                                               /* valid                       */
#define SQLUII_DID                     -3092   /* invalid id field in 'D'     */
                                               /* rec                         */
#define SQLUIW_NNCOL_LOST              -3094   /* DOS non-nullable name not   */
                                               /* found                       */
#define SQLUIW_PCOL_INV                -3095   /* col position out of range   */

#define SQLUE_COL_TOOBIG               3100    /* column longer than 254      */
                                               /* chars                       */
#define SQLUE_DATA_CHARDEL             3101    /* column has char delimiter   */
#define SQLUE_DCNUM_HIGH               3102    /* dcol column nbr > tcol      */
                                               /* number                      */
#define SQLUE_DCNUM_LOW                3103    /* dcol column nbr < tcol      */
                                               /* number                      */
#define SQLUE_MFE                      -3106   /* error formatting a message  */
#define SQLUE_WARNING                  3107    /* warning message issued      */

#define SQLUI_DLFM_LINK                3108    /* file not linked             */

#define SQLUI_FEWER_DCOLS_DBCOLS_NULLED 3112   /* extra database cols         */
#define SQLUIC_UNSUPTYP_NULLABLE       3113    /* column will be nulled       */
#define SQLUIC_IGNORED_CHAR            3114    /* character ignored           */
#define SQLUIC_FIELD_TOO_LONG          3115    /* input CSV field too long    */
#define SQLUIC_CF_REQFIELD_MISSING     3116    /* field value missing         */
#define SQLUIC_CF_GENALWAYS_NOTNULL    3550    /* non NULL found for          */
                                               /* GENERATED ALWAYWS col       */
#define SQLUIC_CFINT2_NULLED           3117    /* smallint field nulled       */
#define SQLUIC_CFINT2_ROWREJ           3118    /* smallint field error        */
#define SQLUIC_CFINT4_NULLED           3119    /* int field nulled            */
#define SQLUIC_CFBOOL_NULLED           27923   /* boolean field nulled        */
#define SQLUIC_CFBOOL_ROWREJ           27924   /* boolean field error         */

#define SQLUIC_CFINT4_ROWREJ           3120    /* int field error             */
#define SQLUIC_CFFLOAT_NULLED          3121    /* float field nulled          */
#define SQLUIC_CFFLOAT_ROWREJ          3122    /* float field error           */
#define SQLUIC_CFDEC_NULLED            3123    /* decimal field nulled        */
#define SQLUIC_CFDEC_ROWREJ            3124    /* decimal field error         */
#define SQLUIC_CFTRUNC                 3125    /* char field truncated        */

#define SQLU_RMTCLNT_NEEDS_ABSPATH     -3126   /* Absolute path must be       */
                                               /* specified for load from     */
                                               /* remote client               */
#define SQLUIC_CFDATETRUNC             3128    /* date field truncated        */
#define SQLUIC_CFDTPAD                 3129    /* date/time/stamp field       */
                                               /* padded                      */

#define SQLUIC_CFTIMETRUNC             3130    /* time field truncated        */
#define SQLUIC_CFSTAMPTRUNC            3131    /* stamp field truncated       */
#define SQLUE_TRUNCATE                 3132    /* char field truncated        */
#define SQLUI_DATALINK_NULLED          3133    /* Datalink field nulled       */
#define SQLUI_DATALINK_ROWREJ          3134    /* Datalink field error        */
#define SQLU_DCOL_TOO_MANY             -3135   /* Too many METHOD cols        */
#define SQLUIC_ROWTOOSHORT             3137    /* not enough columns          */
#define SQLUIC_EOF_IN_CHARDELS         3138    /* end of input data file      */
#define SQLUE_SQLSTPDB_ERR             3139    /* stop using database failed  */

#define SQLUIC_CFDECFLOAT_NULLED       3140    /* decfloat field nulled       */
#define SQLUIC_CFDECFLOAT_ROWREJ       3141    /* decfloat field error        */
#define SQLUE_3148                     3148    /* row not inserted            */

#define SQLUII_TCNTCMP                 3154    /* 'H' hcnt not equal 'T' rec  */
                                               /* ccnt                        */
#define SQLUII_CNAML                   3155    /* invalid name length in 'C'  */
                                               /* rec                         */
#define SQLUII_CNULL                   3156    /* invalid null field in 'C'   */
                                               /* rec                         */
#define SQLUII_CTYPE                   3157    /* invalid type field in 'C'   */
                                               /* rec                         */
#define SQLUII_CSBCP                   3158    /* invalid SBCP field in 'C'   */
                                               /* rec                         */
#define SQLUII_CDBCP                   3159    /* invalid DBCP field in 'C'   */
                                               /* rec                         */

#define SQLUII_CLENG                   3160    /* invalid col len fld in 'C'  */
                                               /* rec                         */
#define SQLUII_CPREC                   3161    /* invalid precision in 'C'    */
                                               /* rec                         */
#define SQLUII_CSCAL                   3162    /* invalid scale field in 'C'  */
                                               /* rec                         */
#define SQLUII_CFLOAT_BLANKLENG        3163    /* use 00008 for float col     */
                                               /* length                      */
#define SQLUII_CFLOAT_BADLENG          3164    /* invalid float col len in    */
                                               /* 'C'.                        */
#define SQLUII_CUTYPE                  3165    /* 'C' record has invalid      */
                                               /* type                        */
#define SQLUII_NOCREC_FOR_NULL_DBCOL   3166    /* IXF col does not exist      */
#define SQLUII_INVCREC_FOR_NULL_DBCOL  3167    /* IXF col is invalid          */
#define SQLUII_CRECCOMP_NULL_DBCOL     3168    /* IXF col not compatible      */

#define SQLUII_DEOF_INROW              3170    /* EOF found in row of data    */

#define SQLUE_INSERT_DISK              3180    /* insert diskette request     */
#define SQLUII_AE_NOTFOUND             3181    /* file ended before AE rec    */
#define SQLUII_INSERT_DISK_RETRY       3182    /* retry to insert diskette    */
#define SQLUEC_NOBLANK_B4KW            3183    /* mult del o'rides/no blanks  */
#define SQLUI_PREVMESG_ROWNO           3185    /* row of previous warning     */
#define SQLUI_LOGFULL_INSWARN          3186    /* log full inserting row      */
#define SQLUI_INDEX_WARN               3187    /* error creating index        */
#define SQLUI_TRUNCATE_TABLE           -3188   /* error truncating table      */

#define SQLUI_INDEXIXF                 -3190   /* invalid INDEXIXF option     */
#define SQLUE_INVALID_DATE_DATA        3191    /* data not fit modifier       */
#define SQLUE_INVALID_DATE_SPEC        -3192   /* invalid user date modifier  */
#define SQLUI_VIEW_ERROR               -3193   /* cannot import to this view  */
#define SQLUI_SYSTBL_ERROR             -3194   /* cannot import system table  */
#define SQLUE_RETRY_DISK               3195    /* not enough space            */
#define SQLUI_IN_NOTFD                 -3196   /* input file not found        */
#define SQLUI_IMPBUSY                  -3197   /* import/export in use        */
#define SQLUII_CDECFLOAT_BLANKLENG     3198    /* use 00008 for decfloat col  */
                                               /* length                      */
#define SQLUII_CDECFLOAT_BADLENG       3199    /* invalid decfloat col len    */
                                               /* in 'C'.                     */

#define SQLUI_REPL_PAR                 -3201   /* cant replace parent table   */
#define SQLUI_IUOPT_NOPK               -3203   /* cant update without PK's    */
#define SQLUI_IUOPT_NOVIEW             -3204   /* cant update views           */
#define SQLUI_VIEW_REF                 -3205   /* cant replace ref cons view  */
#define SQLUI_VIEW_SQUERY              -3206   /* cant replace subquery view  */

#define SQLU_INVALID_TABLES_LIST       -3207   /* Invalid table list          */
#define SQLU_TYPED_IMPORT_INTO_REGULAR 3208    /* Import Typed-table to Reg   */
#define SQLU_CANT_RENAM_SUBTAB_OR_ATTR -3209   /* Cannot rename sub-table     */
                                               /* attr                        */
#define SQLU_INCOMPATIBLE_HIERARCHY    -3210   /* Options incompatible w/     */
                                               /* hier                        */
#define SQLU_LOAD_DOESNT_SUPP_RT       -3211   /* Load doesn't supp RT        */
#define SQLU_NOSUPP_LD_TERM_OP         -3212   /* not supported Load          */
                                               /* Terminate operation         */

#define SQLU_INXMODE_INFO              3213    /* Load indexing mode          */
#define SQLU_INXMODE_DEFBUTUNIQUE      -3214   /* Deferred indexing, but      */
                                               /* unique inx                  */
#define SQLU_INXMODE_DMS_RESTRICTION   3215    /* Load incrmental indexing +  */
                                               /* DMS + copy + same TS        */
#define SQLU_INXMODE_INC_BUTBADINX     3216    /* Load incrmental indexing    */
                                               /* but inx invalid             */
#define SQLU_INXMODE_INC_BUTNOTINSERT  3217    /* Load incrmental indexing    */
                                               /* but not insert              */
#define SQLU_INDEX_FILE_MISSING        -3218   /* Index file is damaged       */
                                               /* missing                     */
#define SQLU_CONSTRAINTS_OFF_FAILED    -3219   /* Load unable to turn off     */
                                               /* constraints                 */

#define SQLUE_PROVIDE_FILE_PART        3220    /* AIX req next file           */
#define SQLUI_START_COMMIT             3221    /* start commit                */
#define SQLUI_FINISH_COMMIT            3222    /* finish commit               */
#define SQLUI_BAD_STRUCT_PARM          -3223   /* bad input parms             */
#define SQLUI_SKIPPED_ALL_ROWS         -3225   /* restartcnt too big          */
#define SQLU_WHICH_USER_RECORD         3227    /* map special token to user   */
                                               /* record                      */
#define SQLU_DL_AND_DEFERRED_INX       -3228   /* Datalink table, deferred    */
                                               /* indexing not allowed on     */
                                               /* load                        */

#define SQLUI_INVALID_DATA             3229    /* Row contains invalid data,  */
                                               /* will be rejected            */
#define SQLU_INCOMPAT_TYPE_CODEPAGE    -3230   /* Data type incompatible      */
                                               /* with given codepage         */
#define SQLUE_LOB_XML_WRITE_ERROR      3232    /* Write to file failed,       */
                                               /* different file name used    */
#define SQLUI_IGNORE_XDS_ATTR          3233    /* Invalid XDS attribute       */
                                               /* ignored                     */
#define SQLUI_INVALID_XDS              -3234   /* Invalid XDS                 */
#define SQLUE_PATH_ERROR               -3235   /* Path error                  */
#define SQLUI_XMLSCHEMA_CONFLICT       -3236   /* XML schema conflict         */
                                               /* between IGNORE and          */
                                               /* XMLVALIDATE options         */
#define SQLUE_ACTION_STRING_XML_ERROR  -3237   /* Export Action String error  */
                                               /* due to XML processing       */
#define SQLUE_NO_SCHEMA_IN_XDS         3239    /* XML schema not written out  */
                                               /* to XDS                      */
#define SQLU_INVALID_SECLABEL          3241    /* Invalid security label      */
#define SQLU_MALFORMED_SECLABEL        3242    /* Security label is           */
                                               /* syntactically incorrect.    */
#define SQLU_INVALID_SECLABEL_ELEMENT  3243    /* Invalid element for the     */
                                               /* security policy             */
#define SQLU_INVALID_SECLABELNAME      3244    /* Invalid security label      */
                                               /* name                        */
#define SQLU_LBAC_ENFORCE_FAILED       3245    /* Enforcement of security     */
                                               /* label failed                */

#define SQLUI_COMPOUND_ERR             -3250   /* compound=x error            */

#define SQLUIW_EARLY_EOF               -3302   /* unexpected EOF              */
#define SQLUI_IXFONLY                  -3303   /* filetype not ixf            */
#define SQLUI_DELTABLE                 -3304   /* table does not exist        */
#define SQLUI_CREATE_ERR               -3305   /* table already exists        */
#define SQLUI_EXECUTE_ERR              -3306   /* SQL error during insert     */
#define SQLUI_INC_COL                  -3307   /* incomplete col info         */
#define SQLUI_CP_MISMATCH              -3308   /* codepage mismatch           */
#define SQLUI_DBLDATA                  -3309   /* double byte data found      */

#define SQLUI_UNREC_CTYPE              -3310   /* unrec col type              */
#define SQLUI_INVCREC_FOR_CREATE       -3310   /* invalid IXF column          */

#define SQLUE_DISK_FULL_DB2OS2         -3313   /* disk full - OS/2            */
#define SQLUE_DISK_FULL_DB2NT          -3313   /* disk full - Windows NT      */
#define SQLUE_DISK_FULL_DB2DOS         -3313   /* disk full - DOS             */
#define SQLUE_DISK_FULL_DB2WIN         -3313   /* disk full - Windows         */
#define SQLUE_DISK_FULL_DB2AIX         -10018  /* disk full - AIX             */
#define SQLUE_DISK_FULL_DB2MAC         -3313   /* disk full - MacOS           */

#define SQLUE_DISK_FULL                SQLUE_DISK_FULL_DB2AIX

#define SQLUII_ASTAMP_NOMATCH          -3314   /* 'A' data/ time not as 'H'.  */
#define SQLUII_ACREC_BADVOL            -3315   /* invalid volume info         */
#define SQLUII_CLOSE_NOTLAST           -3316   /* error closing IXF file      */
#define SQLUW_FTMOD_INV                -3317   /* conflict in filetmod        */
#define SQLUEC_DUP_KEYWORD             -3318   /* keyword repeated/filetmod   */
#define SQLUI_ERR_CREATETAB            -3319   /* error creating table        */

#define SQLUEC_NOROOM_AFTERKW          -3320   /* keyword at end of filetmod  */
#define SQLUI_LOGFULL_INSERR           -3321   /* circular log full           */
#define SQLUE_SEM_ERROR                -3322   /* semaphore error             */
#define SQLUE_INVCOLTYPE               -3324   /* column type invalid         */
#define SQLUI_COL_LIST                 -3326   /* column list invalid         */
#define SQLUEI_SYSERROR                -3327   /* system error                */
#define SQLUI_NICKNAME_ERR             -27999  /* Error importing to          */
                                               /* nickname                    */
#define SQLUE_NO_IXF_INFO              27984   /* Some metadata will not be   */
                                               /* saved to IXF on Export      */
#define SQLUEW_COL_TRUNC               27986   /* Column name truncated       */
                                               /* during Export               */
#define SQLUE_IXF_NO_SUPP_N            -27987  /* IXF file not supported in   */
                                               /* Import using Method N       */
#define SQLUE_NO_IXF_INFO_ERR          -3311   /* IXF file not supported in   */
                                               /* IMPORT CREATE               */

#define SQLUII_ODD2GRAPH               3330    /* odd leng char -> graphic    */
#define SQLUE_OEACCESS                 -3331   /* permission denied           */
#define SQLUE_OEMFILE                  -3332   /* too many files open         */
#define SQLUE_OENOENT                  -3333   /* no such file or directory   */
#define SQLUE_OENOMEM                  -3334   /* not enough memory           */
#define SQLUE_OENOSPC                  -3335   /* no space left               */
#define SQLU_READ_ACCESS_NOT_ALLOWED   -3340   /* read access load            */
                                               /* conditions not met          */
#define SQLU_INVALID_USE_TABLESPACE    -3341   /* use tablespace incorrect    */
#define SQLU_LOCK_WITH_FORCE_DENIED    -3342   /* insufficient authority to   */
                                               /* issue lock with force       */
#define SQLU_NO_RSTART_POST_RLFWARD    -3343   /* cant load restart after     */
                                               /* rollforward                 */
#define SQLU_USE_TABLESPACE_WARNING    3346    /* use tablespace warning      */
                                               /* message                     */

#define SQLUIA_BAD_DCOL_METH           -3400   /* invalid method for ASC      */
#define SQLUI_DCOLM_ALL                -3401   /* invalid import method       */
#define SQLUIA_NULLLOC                 -3402   /* zeroes as begin/end         */
#define SQLUIA_LOCPAIR                 -3403   /* invalid pair                */
#define SQLUIA_LOCNUM                  -3404   /* invalid pair for number     */
#define SQLUIA_LOCDATE                 -3405   /* invalid pair for date       */
#define SQLUIA_LOCTIME                 -3406   /* invalid pair for time       */
#define SQLUIA_LOCSTAMP                -3407   /* invalid pair for timestamp  */
#define SQLUIA_LOCLONG                 3408    /* pair defines long field     */
#define SQLUIA_LOCSHORT                3409    /* pair defines short field    */
#define SQLUIA_LOCODD                  -3410   /* invalid pair for graphic    */
#define SQLUIA_CFGRAPH_NULLED          3411    /* value not graphic--null     */
#define SQLUIA_CFGRAPH_ROWREJ          3412    /* value not graphic--not      */
                                               /* null                        */
#define SQLUIA_SHORTFLDNULLED          3413    /* field too short--nulled     */
#define SQLU_NO_LIFEBOAT               -3414
#define SQLUIA_CFCPCV_NULLED           3415    /* CPCV failed--null           */
#define SQLUIA_CFCPCV_ROWREJ           3416    /* CPCV failed--not null       */
#define SQLU_NOCHARDEL_WARNING         3418    /* Modified by NOCHARDEL       */
                                               /* usage warning               */
#define SQLU_VENDOR_SORT_IGNORED       3419    /* Vendor sort for collating   */
                                               /* type is unsupported, using  */
                                               /* default db2 sort            */

#define SQLU_TOO_MANY_WARNINGS         -3502   /* number of warnings hit      */
                                               /* threshold                   */
#define SQLU_ROWCNT                    3503    /* number of rows hit          */
                                               /* threshold                   */
#define SQLULA_INVALID_RECLEN          -3505   /* reclen > 32767              */
#define SQLULA_NULLIND_IGNORED         3506    /* null ind value not Y or N   */
#define SQLUI_NULLIND                  -3507   /* nullind column is invalid   */
#define SQLUL_FILE_ERROR               -3508   /* file access error during    */
                                               /* load                        */
#define SQLUL_NUM_ROW_DELETED          3509    /* num of row deleted after    */
                                               /* load                        */
#define SQLU_SORT_WORK_DIR_ERROR       -3510   /* work directory is invalid   */
#define SQLU_NB_LOBFILE_MISSING        3511    /* lobfile missing but         */
                                               /* nullable col                */
#define SQLU_NNB_LOBFILE_MISSING       3512    /* lobfile missing,            */
                                               /* nonnullable col             */
#define SQLUL_UNMATCHED_CODEPAGE       -3513   /* codepage doesn't match db   */
#define SQLUL_SYSERR_WITH_REASON       -3514   /* system error with reason    */
                                               /* code                        */
#define SQLUL_UNEXPECTED_RECORD        -3517   /* unexpected rec in db2cs     */
#define SQLUL_INCOMPATIBLE_TABLE       -3518   /* coltype incompatible for    */
                                               /* db2cs                       */
#define SQLUL_FILE_NOT_FOUND           -3521   /* missing file                */
#define SQLUL_COPY_LOGRETAIN_OFF       -3522   /* copy spec, no logretain     */
                                               /* userexit                    */
#define SQLUL_NO_MESSAGES              3523    /* no messages to be           */
                                               /* retrieved                   */
#define SQLUL_FREESPACE_OPT            -3524   /* freespace option invalid    */
#define SQLU_INCOMPAT_OPT              -3525   /* incompatible options        */
#define SQLU_MOD_INCOMPAT_WITH_OPT     -3526   /* modifier incompatible with  */
                                               /* load options                */
#define SQLULA_INVALID_CODEPAGE        -3527   /* invalid codepage            */
#define SQLUL_DELIMITER_CONV_W         3528    /* delimiter may be converted  */
                                               /* from app to DB              */
#define SQLUL_UNSUPPORTED_DATA_TYPE    -3529   /* Unsupported data type       */
#define SQLUL_OBSOLETETE_SORT_PARM     3535    /* Load index creation         */
                                               /* parameter no longer         */
                                               /* supported                   */
#define SQLUL_GENERATED_OVERRIDE       3551    /* Generated override warning  */
#define SQLU_NEXT_TAPE_WARNING         3700    /* mount new tape              */
#define SQLU_LOBPATHS_IGNORED          3701    /* no lobs/longs but lobpath   */
                                               /* nonull                      */
#define SQLU_DEVICE_IGNORED            3702    /* device error but ignored    */
#define SQLU_NUM_BUFFERS               -3704   /* invalid number of buffers   */
#define SQLU_BUFFER_SIZE_ERROR         -3705   /* invalid load/unload buffer  */
                                               /* size                        */
#define SQLUL_DISK_FULL                -3706   /* copy target full            */
#define SQLU_SORT_BUFFSIZE_ERROR       -3707   /* invalid sort buffer size    */
#define SQLUE_NOSPACE_IN_HASH          -3708   /* Hash table is full          */

/* Load / unload / load recovery SQLCODES                                     */
#define SQLU_OPEN_COPY_LOC_FILE_ERROR  -3783
#define SQLU_INV_COPY_LOC_FILE_INPUT   -3784
#define SQLU_LOAD_RECOVERY_FAILED      -3785
#define SQLU_INVALID_PARM_WARNING      3798
#define SQLU_LOAD_RECOVERY_PENDING     3799

/* load recovery - copy location input error type                             */
#define SQLU_KEYWORD_CODE              1
#define SQLU_OVERRIDE_CODE             2
#define SQLU_UNEXPECTED_EOF_CODE       3
#define SQLU_IOERROR_CODE              4

/* load recovery - Different Load recovery options                            */
#define SQLU_RECOVERABLE_LOAD          0
#define SQLU_NON_RECOVERABLE_LOAD      1

/* Loadapi SQLCODES                                                           */
#define SQLU_INVALID_QUIESCEMODE       -3802
#define SQLU_INVALID_INDEX             -3804
#define SQLU_INVALID_LOADAPI_ACTION    -3805
#define SQLU_CONSTRAINTS_NOT_OFF       -3806

/* Export SQLCODES                                                            */
#define SQLUE_MSG                      -3999   /* Export message              */

/* Roll-Forward Recovery SQLCODES                                             */
#define SQLU_INVALID_PARAM             -4904   /* invalid parameter           */
#define SQLU_INVALID_RANGE             -4905   /* invalid parameter range     */
#define SQLUM_INVALID_TPS_SET          -4906   /* invalid tablespace set      */
#define SQLUM_CHECK_PENDING_SET        4907    /* tables set to check         */
                                               /* pending state               */
#define SQLUM_TSP_NOT_READY            -4908   /* tablespace not ready to     */
                                               /* roll forward                */
#define SQLU_INVALID_OFLOGPATH         -4910   /* Invalid overflow log path   */
#define SQLU_RC_MISSING_LOGFILES       -4970   /* missing log files           */
#define SQLU_RC_LOG_TRUNCATED          -4971   /* log truncation failed       */
#define SQLU_RC_LOGPATH_FULL           -4972   /* log path full               */
#define SQLU_RC_LOG_MISMATCH           -4973   /* log mismatch with catalog   */
                                               /* node                        */
#define SQLU_RC_QRY_ERR_WARN           4974    /* query status warning        */
#define SQLU_RC_CANCELED_WARN          4975    /* rollforward canceled        */
#define SQLU_RC_NOT_ON_CATALOG_NODE    -4976   /* not on catalog node         */
#define SQLU_RC_EXPORT_DIR             -4977   /* bad export directory        */
#define SQLU_RC_DROPPED_TBL            -4978   /* bad dropped table recovery  */
                                               /* option                      */
#define SQLU_RC_EXPORT_DATA            4979    /* error while exporting       */
                                               /* table data                  */
#define SQLU_RC_LOGFILE_CORRUPT        -4980   /* Corrupt Log file            */
#define SQLU_RC_EXPORT_PART            4981    /* error while exporting       */
                                               /* partition data              */

/* Configuration SQLCODES                                                     */
#define SQLF_RC_STANDBY_MIGR           -1776   /* command not valid for       */
                                               /* standby.                    */
#define SQLF_RC_SYSAUTH                -5001   /* only SYSADM_GROUP can       */
                                               /* change db2 configuration    */
                                               /* file                        */
#define SQLF_RC_SYSERR                 -5005   /* system error                */
#define SQLF_RC_PATHNAME               -5010   /* path name error             */
#define SQLF_RC_INVNODENAME            -5020   /* invalid node name           */
#define SQLF_RC_REL                    -5030   /* invalid release number      */
#define SQLF_RC_NEEDMIG                -5035   /* database needs migration;   */
                                               /* release number is back      */
                                               /* level                       */
#define SQLF_RC_INSMEM                 -5047   /* insufficient memory to      */
                                               /* support stack switching     */
#define SQLF_RC_SYSCSUM                -5050   /* invalid db2 configuration   */
                                               /* file                        */
#define SQLF_RC_DBCSUM                 -5055   /* invalid db configuration    */
                                               /* file                        */
#define SQLF_RC_INVTKN                 -5060   /* invalid token parameter     */
#define SQLF_RC_INVTKN_STRUCT          -5061   /* invalid ptr to sqlfupd      */
#define SQLF_RC_INVTKN_PTR             -5062   /* invalid token ptr value     */
#define SQLF_RC_OLD_DB_CFG_TKN_TRUNC   5066    /* warning - truncated result  */
                                               /* due to obsolete db cfg      */
                                               /* token                       */
#define SQLF_RC_CNTINV                 -5070   /* invalid count parameter     */
#define SQLF_RC_INVLOGCFG              -5099   /* invalid logging db cfg      */
                                               /* parameter                   */
#define SQLF_RC_INVNEWLOGP             -5099   /* invalid new log path - use  */
                                               /* SQLF_RC_INVLOGCFG instead   */

#define SQLF_RC_INV_BIT_VALUE          -5112   /* invalid bit value - must    */
                                               /* be 0 or 1                   */
#define SQLF_RC_ALT_COLLATE            -5113   /* set alt_collate on unicode  */
                                               /* db not allowed              */

#define SQLF_RC_INVDETS                -5121   /* invalid DB configuration    */
                                               /* details                     */
#define SQLF_RC_PROTECT                -5122   /* database is copy protected  */
#define SQLF_RC_LOGIO                  -5123   /* I/O Error with log header   */
#define SQLF_RC_UPDATE_FAILED          -5124   /* Failed to update the DB     */
                                               /* configuration on one or     */
                                               /* more nodes                  */
#define SQLF_RC_INV_DBMENT             -5126   /* DBM Param not supported by  */
                                               /* nodetype                    */
#define SQLF_RC_INV_RANGE              -5130   /* integer out of range        */
#define SQLF_RC_INV_RANGE_2            -5131   /* integer out of range (-1)   */
#define SQLF_RC_INV_STRING             -5132   /* string null or too long     */
#define SQLF_RC_INV_SET                -5133   /* char/int not in set         */
#define SQLF_RC_INVTPNAME              -5134   /* tpname not valid            */
#define SQLF_RC_INV_DBPATH             -5136   /* dftdbpath not valid         */
#define SQLF_RC_INV_DIAGPATH           -5137   /* diagpath not valid          */
#define SQLF_RC_INV_CF_DIAGPATH        -1565   /* cf_diagpath not valid       */
#define SQLF_RC_INV_AGENTPRI           -5131   /* invalid agent priority      */
#define SQLF_RC_WRN_SELF_TUN_ON        5144    /* tuning won't occur until    */
                                               /* self_tun is ON              */
#define SQLF_RC_WRN_AUTO_DEACTIV       5145    /* tuning deactivated because  */
                                               /* not enough auto parms       */
#define SQLF_RC_WRN_PARM_SET_AUTO      5146    /* db2 set param 2 to auto     */
                                               /* because parm 1 set auto by  */
                                               /* user                        */
#define SQLF_RC_INV_NO_MAN_IF_AUTO     -5147   /* param 1 can't be set to     */
                                               /* manual if param 2 auto      */
#define SQLF_RC_WRN_SHEAPTHRES_NOT_0   5148    /* no tuning until sheapthres  */
                                               /* set to 0                    */
#define SQLF_RC_CFG_LATCH_NOT_AVAIL    -5149   /* cfg latch not available     */
#define SQLF_RC_INV_RANGE_TOO_SMALL    -5150   /* out of range - value too    */
                                               /* small                       */
#define SQLF_RC_INV_RANGE_TOO_SMALL_2  -5151   /* out of range - value too    */
                                               /* small (-1 is allowed)       */
#define SQLF_RC_INV_RANGE_TOO_BIG      -5152   /* out of range - value too    */
                                               /* large                       */
#define SQLF_RC_INV_RANGE_CONDITION    -5153   /* out of range - condition    */
                                               /* violated                    */
#define SQLF_RC_INV_CFG_SETTING        -6112   /* cfg param settings not      */
                                               /* valid                       */
#define SQLF_RC_INV_AUTH_TRUST         -5154   /* authentication must be      */
                                               /* CLIENT for trust_allcnts =  */
                                               /* NO or trust_clntauth =      */
                                               /* SERVER                      */
#define SQLF_RC_SORTHEAP_PERF          5155    /* sortheap performance        */
                                               /* warning                     */
#define SQLF_RC_NO_MORE_DB_CFG_UPD     -5160   /* No more db cfg updates      */
                                               /* allowed in HA               */
#define SQLF_RC_NO_MORE_DBM_CFG_UPD    -5161   /* No more dbm cfg updates     */
                                               /* allowed in HA               */
#define SQLF_RC_INVHADRTARGETLIST      -5165   /* invalid hadr target list    */
#define SQLF_RC_INV_DBCFG_VAL_NT       -5195   /* DB cfg parameter value not  */
                                               /* valid on this instance      */
                                               /* type.                       */
#define SQLF_RC_INV_DBCFG_PARM_NT      -5196   /* DB cfg parameter not valid  */
                                               /* on this instance type.      */

/* Data Redistribution Return Codes                                           */
#define SQLUT_NGNAME_UNDEF             -204    /* nodegroup name is           */
                                               /* undefined                   */
#define SQLUT_NODE_DUP                 -265    /* node is a duplicate node    */
#define SQLUT_NODE_UNDEF               -266    /* node is undefined           */
#define SQLUT_OVER_MAX_PARTNO          -269    /* max no. of part. map        */
                                               /* reached                     */
#define SQLUT_REDIST_UNDEF             -607    /* redist undefined for sys    */
                                               /* obj.                        */
#define SQLUT_INSAUTH                  -1092   /* insufficient authority      */
#define SQLUT_ACCESS_DENIED            -1326   /* file or dir access denied   */
#define SQLUT_NO_CONTAINERS            -1755   /* for tablespaces on a node   */
#define SQLUT_INVALID_AUTHS            SQLU_INVALID_AUTHS /* invalid          */
                                               /* authorizations -2018        */
#define SQLUT_INVALID_PARM             SQLU_INVALID_PARM /* parm to utility   */
                                               /* incorrect -2032             */
#define SQLUT_INVALID_PARM_ADDRESS     SQLU_INVALID_PARM_ADDRESS /* addr of   */
                                               /* parm incorrect -2034        */
#define SQLUT_RC_REDIST_CHECK_ERR      -2436   /* Redistribution cannot be    */
                                               /* performed                   */
#define SQLUT_CBI                      SQLUE_CBI /* function interruption     */
                                               /* 3005                        */
#define SQLUT_REDIST_NO_PARTKEY        -6047   /* redist failed - no part     */
                                               /* key                         */
#define SQLUT_ERR_IN_FILE              -6053   /* error found in the input    */
                                               /* file                        */
#define SQLUT_RC_REDIST_ERR            -6056   /* redistribution not          */
                                               /* performed                   */
#define SQLUT_ERROR_REDIST             -6064   /* error during data           */
                                               /* redistbution                */
#define SQLUT_WRT_OUT_FILE             -6065   /* error writing output file   */
#define SQLUT_BAD_PARM                 -1385   /* error input paramenters     */
#define SQLUT_PARTIAL                  1379    /* database partition group    */
                                               /* has been partially          */
                                               /* redistributed               */
/* Load Header Return Codes                                                   */
#define SQLU_PARTITIONMAP              -6100   /* Invalid partition map       */
#define SQLU_NODE_NUMBER               -6101   /* Invalid node number         */
#define SQLU_FUTURE_PARM               -6102   /* Parameter reserved for      */
                                               /* future                      */
#define SQLU_LOAD_SYSERR               -6103   /* Unexpected load system      */
                                               /* error                       */
#define SQLU_NO_INDICES                -6104   /* Load does not support       */
                                               /* indices                     */
#define SQLU_LOAD_COMPLETE             -6105   /* Load complete - backup NOW  */
                                               /* !                           */
#define SQLU_NOHEADER                  -6106   /* Invalid use of NOHEADER     */
#define SQLU_PARTITION_KEY             -6107   /* Invalid partitioning key    */
#define SQLU_PARTITION_KEY_NUM         -6108   /* Wrong number of partition   */
                                               /* keys                        */
#define SQLU_PARTITION_KEY_NAME        -6109   /* Unexpected partitioning     */
                                               /* key                         */
#define SQLU_PARTITION_KEY_TYPE        -6110   /* Unexpected partition key    */
                                               /* type                        */
/* Repository for obsolete Return Codes                                       */

#define SQLU_WRITE_ERROR               -2006   /* wrote wrong # of bytes      */
#define SQLU_CONNECT_ERROR             -2010   /* error in Start Using        */
#define SQLU_INT_ERROR                 -2012   /* error in ints               */
#define SQLU_ADSM_ERROR                SQLU_TSM_ERROR /* ADSM reported error  */
#define SQLU_LOAD_ADSM_ERROR           SQLU_LOAD_TSM_ERROR /* unable to load  */
                                               /* ADSM                        */
#define SQLUD_NO_MHEADER_ERROR         -2531   /* media header not present    */
#define SQLUD_NO_MHEADER_WARNING       2534    /* media header missing        */
#define SQLUD_NEXT_TAPE_WARNING        2535    /* another tape mount          */
                                               /* required                    */
#define SQLUD_TSM_MOUNT_WAIT           2545    /* waiting for TSM server to   */
                                               /* access data on removable    */
                                               /* media                       */
#define SQLUD_ADSM_MOUNT_WAIT          SQLUD_TSM_MOUNT_WAIT /* waiting for    */
                                               /* ADSM server to access data  */
                                               /* on removable media          */

/* Configuration parameter obsolete return codes defines - Some               */
/* configuration parameters had specific out of range return codes; these     */
/* have been replaced by generic out of range messages In these cases the     */
/* old token names for the specific return codes are given, but the values    */
/* are replaced by the new values returned when out of range.                 */

#define SQLF_RC_DBAUTH                 -5002   /* only SYSADM can             */
                                               /* changedatabase              */
                                               /* configuration file          */
#define SQLF_RC_INVNDB                 -5130   /* invalid # of concurrent db  */
#define SQLF_RC_INVRIO                 -5130   /* invalid req I/O blk size    */
#define SQLF_RC_INVSIO                 -5015   /* invalid serv I/O blk size   */
#define SQLF_RC_INVCHEAP               -5016   /* invalid communications      */
                                               /* heap                        */
#define SQLF_RC_INVRSHEAP              -5017   /* invalid remote services     */
                                               /* heap                        */
#define SQLF_RC_INVSHPTHR              -5130   /* invalid sort heap           */
                                               /* threshold                   */
#define SQLCC_RC_BAD_DB2COMM           -5036   /* invalid DB2COMM value       */
#define SQLCC_RC_NO_SERV_IN_DBMCFG     -5037   /* service name not definein   */
                                               /* db2 config file             */
#define SQLCC_RC_SERV_NOT_FOUND        -5038   /* service name not found in   */
                                               /* etc/services file           */
#define SQLCC_RC_INT_PORT_NOT_FOUND    -5039   /* interrupt port not found    */
                                               /* in/etc/services file        */
#define SQLCC_RC_NO_TPN_IN_DBMCFG      -5041   /* trans program name not      */
                                               /* definedin db2               */
                                               /* configuration file          */
#define SQLF_RC_INVNLL                 -5130   /* invalid # of locklist       */
#define SQLF_RC_INVNBP                 -5130   /* invalid # bufr pool pages   */
#define SQLF_RC_INVNDBF                -5130   /* invalid # of DB files open  */
#define SQLF_RC_INVSCP_DB2OS2          -5130   /* invalid soft check point    */
                                               /* value                       */
#define SQLF_RC_INVSCP_DB2AIX          -5130   /* invalid soft check point    */
                                               /* value                       */
#define SQLF_RC_INVSCP                 -5130   /* invalid soft check point    */
                                               /* value                       */
#define SQLF_RC_INVNAP                 -5130   /* invalid # of active appls   */
#define SQLF_RC_INVAHP                 -5130   /* invalid application heapsz  */
#define SQLF_RC_INVDHP                 -5130   /* invalid database heap size  */
#define SQLF_RC_INVDLT                 -5130   /* invalid deadlock detection  */
#define SQLF_RC_INVTAF                 -5130   /* invalid # of total files    */
                                               /* openper application         */
#define SQLF_RC_INVSHP                 -5130   /* invalid sortlist heap       */
#define SQLF_RC_INVMAL                 -5130   /* invalid maxlocks per        */
                                               /* application                 */
#define SQLF_RC_INVSTMHP               -5130   /* invalid statement heap      */
#define SQLF_RC_INVLOGPRIM             -5130   /* invalid number primary log  */
                                               /* files                       */
#define SQLF_RC_INVLOG2ND              -5130   /* invalid number of           */
                                               /* secondary log files         */
#define SQLF_RC_INVLOGFSZ              -5130   /* invalid log file size       */
#define SQLF_RC_INVDB2                 -5102   /* incompatible file open      */
                                               /* parmeter                    */
#define SQLF_RC_INVK2                  -5104   /* no DB's / requestor only    */
#define SQLF_RC_INVK3                  -5126   /* standalone nodetype does    */
                                               /* notsupport nodename         */
#define SQLF_RC_RWS_EXIST              -5106   /* remote workstation has      */
                                               /* alreadybeen configured      */
#define SQLF_RC_RWS_SYSADM             -5107   /* <authid> does not           */
                                               /* haveauthority to add or     */
                                               /* drop a remote workstation   */
#define SQLF_RC_RWS_NOT_EXIST          -5108   /* remote workstation has      */
                                               /* notbeen previously setup    */
                                               /* using sqlarws               */
#define SQLF_RC_RWS_MACHINENAME        -5109   /* machine name is missing     */
                                               /* ors too long.               */
#define SQLF_RC_RWS_INV_OPT            -5110   /* configuration option is     */
                                               /* invalid                     */
#define SQLF_RC_ENV_VAR_NOTDEF         -5111   /* environment                 */
                                               /* variableDB2WKSTPROF is not  */
                                               /* defined                     */
#define SQLF_RC_INVDB3                 -5146   /* incompatible buffer pool    */
                                               /* and maximum # of            */
                                               /* applications                */
#define SQLF_RC_INV_QUERY_HEAP_SZ      -5143   /* invalid QUERY_HEAP_SZ       */
#define SQLF_RC_INV_RANGE_3            -5144   /* out of range - limited by   */
                                               /* a parm                      */
#define SQLF_RC_INV_RANGE_MAX_EXPR     -5144   /* out of range - maximum      */
                                               /* limited by an expression    */
#define SQLF_RC_INV_RANGE_MAX_EXPR_2   -5145   /* out of range - maximum      */
                                               /* limited by an expression    */
                                               /* (range includes -1)         */
#define SQLF_RC_INV_RANGE_MIN_EXPR     -5146   /* out of range - minimum      */
                                               /* limited by an expression    */
#define SQLF_RC_INV_RANGE_MIN_EXPR_2   -5147   /* out of range - minimum      */
                                               /* limited by an expression    */
                                               /* (range includes -1)         */
#define SQLF_RC_KCON                   -5025   /* not current db2             */
                                               /* configuration               */
#define SQLF_RC_INVILF                 -5083   /* invalid initial log size    */
#define SQLF_RC_INVLFE                 -5091   /* invalid logfile extention   */
#define SQLF_RC_INVNLE                 -5092   /* invalid # of log extention  */
#define SQLF_RC_INVDB1                 -5101   /* incompatible logfile        */
                                               /* parameter                   */
#define SQLF_RC_LF_1_3                 -5120   /* both R1 & R3 Log            */
                                               /* parameters may not be       */
                                               /* modified                    */
#define SQLF_RC_LOW_APPLS_AND_LOCKS    -5135   /* maxappls*maxlocks too low   */
#define SQLF_RC_INV_AVG_APPLS          -5141   /* invalid AVG_APPLS           */
#define SQLF_RC_INVSYSIDX              -5021   /* invalid system flag         */
#define SQLF_RC_INVDBIDX               -5022   /* invalid database flag       */
#define SQLF_RC_INVSYSADM              -5028   /* invalid sysadm_group        */
#define SQLF_RC_INVNT                  -5065   /* invalid node type           */
#define SQLF_RC_CNTBRK                 -5075   /* interrupt received          */
#define SQLF_RC_INV_AUTHENTICATION     -5140   /* invalid authentication      */
#define SQLF_RC_INV_TRUST_ALLCLNTS     -5156   /* invalid trust_allclnts      */
#define SQLU_ATLD_RESTARTCOUNT_WARN    6500    /* db2atld restartcount        */
                                               /* warning                     */
#define SQLU_ATLD_SAVECOUNT_ERROR      -6532   /* db2atld savecount error     */
#define SQLU_ATLD_RESTARTCOUNT_ERROR   -6533   /* db2atld restartcount error  */
#define SQLU_ATLD_SPLIT_NOT_NEEDED     -6535   /* db2atld does not need       */
                                               /* splitting                   */
#define SQLU_PMAP_OPEN_ERR             -6550   /* db2atld unable to open      */
                                               /* pmap                        */
#define SQLU_PMAP_WRITE_ERR            -6551   /* db2atld failed to write     */
                                               /* pmap                        */
#define SQLU_TEMPCFG_OPEN_ERR          -6552   /* db2atld failed to open      */
                                               /* temp file                   */
#define SQLU_TEMPCFG_WRITE_ERR         -6553   /* db2atld failed to write to  */
                                               /* tmp file                    */
#define SQLU_REXEC_ERR                 -6554   /* db2atld failed to spawn     */
                                               /* remote child                */
#define SQLU_ATLD_COMM_ERR             -6555   /* db2atld comm error          */
#define SQLU_ATLD_PARTIAL_REC          6556    /* db2atld partial record      */
                                               /* found                       */
#define SQLU_GET_DEFAULT_NODE_ERR      -6557   /* db2atld failed to get       */
                                               /* default node                */
#define SQLU_GET_CURDIR_ERR            -6558   /* db2atld unable to get cur   */
                                               /* working dir                 */
#define SQLU_ATLD_BAD_CLP_ERR          -6559   /* db2atld incorrect usage     */
#define SQLU_BAD_SPLIT_NODE            -6560   /* db2atld split node          */
                                               /* incorrect                   */
#define SQLU_BAD_LOAD_NODE             -6561   /* db2atld invalid load node   */
#define SQLU_GET_INSTANCE_ERR          -6562   /* db2atld failed to get       */
                                               /* instance                    */
#define SQLU_GET_UID_ERR               -6563   /* db2atld failed to get cur   */
                                               /* UID                         */
#define SQLU_BAD_PASSWORD              -6564   /* db2atld invalid password    */
#define SQLU_ATLD_HELP                 6565    /* db2atld help msg            */
#define SQLU_MISSING_LOAD_COMMAND      -6566   /* db2atld load command not    */
                                               /* specified                   */
#define SQLU_ATLD_DUP_OPTION           -6567   /* db2atld option specified    */
                                               /* twice                       */
#define SQLU_STARTING_ALL_LOADS        6568    /* db2atld starting all the    */
                                               /* load jobs                   */
#define SQLU_STARTING_ALL_SPLITTERS    6569    /* db2atld starting all the    */
                                               /* splitters                   */
#define SQLU_WAITING_FOR_SPLITTERS     6570    /* db2atld waiting for         */
                                               /* splitters to finish         */
#define SQLU_WAITING_FOR_LOADS         6571    /* db2atld waiting for load    */
                                               /* to complete                 */
#define SQLU_LOAD_STARTED              6572    /* db2atld load has started    */
#define SQLU_SPLIT_RESULT              6573    /* db2atld splitters has       */
                                               /* finished                    */
#define SQLU_DATA_READ_STATUS          6574    /* db2atld Bytes read thus     */
                                               /* far                         */
#define SQLU_TOTAL_DATA_READ           6575    /* db2atld total size of data  */
                                               /* read                        */
#define SQLU_THREAD_ERR                -6576   /* db2atld threading error     */
#define SQLU_ATLD_ROWCOUNT_ERROR       -27961  /* rowcount not supported in   */
                                               /* this mode                   */
#define SQLU_ATLD_TOO_MANY_SPLITTERS   -27991  /* too many splitters          */
#define SQLU_COPYNO_OVERRIDE_INVALID   -27965  /* invalid DB2_LOAD_COPY_NO    */
                                               /* OVERRIDE reg variable       */
#define SQLU_COPYNO_OVERRIDE_WARNING   27966   /* COPY NO was overridden      */
                                               /* warning                     */
#define SQLU_COPYNO_OVERRIDE_DFLTWARN  27967   /* COPY NO was overriden with  */
                                               /* default (nonrecov)          */
#define SQLU_NOREBUILD_DETACHEDMQT     -27983  /* Can't REBUILD when          */
                                               /* partition is detached and   */
                                               /* MQT exists                  */
#define SQLU_SPEC_REGSTR_TRUNC_WARN    27994   /* Special Register Default    */
                                               /* value truncated.            */
#define SQLU_LOAD_INCOMPATIBLE_OPTS    -1159   /* Incompatible LOAD options.  */
#define SQLU_LOAD_INV_REMOTEFETCH_OPTS -1151   /* Invalid REMOTEFETCH media   */
                                               /* options.                    */
#define SQLU_LOAD_REMOTEFETCH_ERROR    -1168   /* Load REMOTEFETCH media      */
                                               /* error.                      */
#define SQLU_LOAD_REMOTEFETCH_WARNING  1175    /* Load REMOTEFETCH media      */
                                               /* warning.                    */

/* Flush Table API Return Codes                                               */
#define SQLUF_TABLE_NOT_AT_NODE        -6024   /* Table not at this node      */

/* sqlugrpi, sqlugrpn, and sqlugtpi return codes                              */
#define SQLUG_INVALID_AUTHID           SQLUS_INVALID_AUTHID /* Invalid        */
                                               /* authid                      */
#define SQLUG_INVALID_TABLE_NAME       SQLUS_INVALID_TABLE_NAME /* invalid    */
                                               /* table                       */
#define SQLUG_CBI                      SQLUE_CBI /* Interrupt                 */
#define SQLUG_TABLE_NOT_FOUND          SQLUR_TABLE_NOT_FOUND /* Table not     */
                                               /* exist                       */
#define SQLUG_RC_INSAUTH               -6023   /* Insufficient authorization  */
#define SQLUG_NULL_PARTKEY             -6038   /* No partitioning key         */
#define SQLUG_NULL_NOTALLOWED          -6039   /* Nulls not allowed           */
#define SQLUG_DECIMAL_FORMAT_CONFLICT  -2755   /* decimal format conflict     */
#define SQLUG_INVALID_SYNTAX           -6044   /* Invalid syntax              */
#define SQLUG_INVALID_DATATYPE         -6045   /* Invalid datatype            */
#define SQLF_RC_INVALID_DYNQUERYMGMT   -29000  /* Invalid dynamic query mgmt  */
                                               /* flag                        */

/* Load error codes continued                                                 */
#define SQLU_INV_RESTART_TERMINATE     -27902  /* Load restart/terminate is   */
                                               /* not necessary               */
#define SQLU_BAD_PARM_FOR_COL_TABLE    -27906  /* Unsupported LOAD            */
                                               /* parameters for column       */
                                               /* organized table             */
#define SQLU_BAD_PARM_AFT_FAILED_LOAD  -27917  /* Unsupported LOAD            */
                                               /* parameters for table in     */
                                               /* load pending                */
#define SQLU_PARTLOAD_BAD_PARAMETER    -27959  /* Invalid input parameter     */
                                               /* for partitioned database    */
                                               /* load                        */
#define SQLU_PARTLOAD_PART_FILE_CURSOR -27960  /* Invalid PART_FILE_LOCATION  */
                                               /* specified for source type   */
                                               /* CURSOR                      */
#define SQLU_PARTLOAD_BAD_ROWCOUNT     -27961  /* Invalid rowcount specified  */
                                               /* for partitioned database    */
                                               /* load                        */
#define SQLU_PARTITION_VIOLATIONS      27990   /* Load partition violations   */
                                               /* detected                    */
#define SQLU_PARTITIONING_MAP_FOUND    -27992  /* Partitioning map was        */
                                               /* found, but load mode is     */
                                               /* not load_only               */
#define SQLU_INCOMPAT_FEATURE          -1407   /* The table contains a        */
                                               /* feature that is             */
                                               /* incompatible with the       */
                                               /* specified option            */
#define SQLU_SHARED_SORT_MEM_REQUIRED  -1406   /* Shared sort memory is       */
                                               /* required for this           */
                                               /* operation                   */

/* Utility control error codes                                                */
#define SQLUTH_INVALID_PRIORITY        -1152   /* Invalid priority            */
#define SQLUTH_UTILITY_NOT_FOUND       -1153   /* Utility not found           */
#define SQLUTH_NO_THROTTLE_SUPPORT     -1154   /* Utility does not support    */
                                               /* throttling                  */

/* obsolete database manager configuration parameter tokens                   */
#define SQLF_KTN_SVRIOBLK              3
#define SQLF_KTN_SQLENSEG              5
#define SQLF_KTN_COMHEAPSZ             8
#define SQLF_KTN_RSHEAPSZ              9
#define SQLF_KTN_NUMRC                 10
#define SQLF_KTN_CUINTERVAL            14
#define SQLF_KTN_SQLSTMTSZ             17
#define SQLF_KTN_COMHEAPSZ_P           50
#define SQLF_KTN_RSHEAPSZ_P            51
#define SQLF_KTN_IPX_FILESERVER        SQLF_KTN_FILESERVER
#define SQLF_KTN_IPX_OBJECTNAME        SQLF_KTN_OBJECTNAME
#define SQLF_KTN_ADSM_PASSWORD         93
#define SQLF_KTN_ADSM_NODENAME         94
#define SQLF_KTN_ADSM_OWNER            95
#define SQLF_KTN_MAX_IDLEAGENTS        60
#define SQLF_KTN_DOS_RQRIOBLK          72
#define SQLF_KTN_DIR_TYPE              73
#define SQLF_KTN_DIR_PATH_NAME         74
#define SQLF_KTN_DIR_OBJ_NAME          75
#define SQLF_KTN_ROUTE_OBJ_NAME        76
#define SQLF_KTN_DFT_CLIENT_COMM       77
#define SQLF_KTN_DFT_CLIENT_ADPT       82
#define SQLF_KTN_SS_LOGON              309
#define SQLF_KTN_UDF_MEM_SZ            69
#define SQLF_KTN_FCM_NUM_RQB           504
#define SQLF_KTN_FCM_NUM_CONNECT       505
#define SQLF_KTN_FCM_NUM_ANCHORS       506
#define SQLF_KTN_MIN_PRIV_MEM          43
#define SQLF_DBTN_ESTORE_SEG_SZ        303
#define SQLF_DBTN_NUM_ESTORE_SEGS      304
#define SQLF_KTN_PRIV_MEM_THRESH       44
#define SQLF_KTN_MAXAGENTS             12
#define SQLF_KTN_MAXCAGENTS            13

/* obsolete database configuration parameter tokens                           */
#define SQLF_DBTN_LOGFILE              4
#define SQLF_DBTN_MAXTOTFILOP          10
#define SQLF_DBTN_LOGEXT               12
#define SQLF_DBTN_LOGMAXEXT            13
#define SQLF_DBTN_AGENTHEAP            14
#define SQLF_DBTN_LOG_RETAIN           23
#define SQLF_DBTN_USER_EXIT            24
#define SQLF_DBTN_SEGPAGES             123
#define SQLF_DBTN_BUFFPAGE             2
#define SQLF_DBTN_SORTHEAP             91
#define SQLF_DBTN_SORTHEAPSZ_P         SQLF_DBTN_SORT_HEAP
#define SQLF_DBTN_DBHEAP               50
#define SQLF_DBTN_DBHEAP_P             SQLF_DBTN_DBHEAP
#define SQLF_DBTN_APPLHEAPSZ_P         SQLF_DBTN_APPLHEAPSZ
#define SQLF_DBTN_STMTHEAPSZ_P         SQLF_DBTN_STMTHEAP
#define SQLF_DBTN_LOGFILSIZ            18
#define SQLF_DBTN_MULTIPGAL            504
#define SQLF_DBTN_ADSM_PASSWD          501
#define SQLF_DBTN_NEXTACTIVE           107
#define SQLF_DBTN_DL_NUM_BACKUP        352
#define SQLF_DBTN_ADSM_PASSWORD        SQLF_DBTN_TSM_PASSWORD
#define SQLF_DBTN_ADSM_OWNER           SQLF_DBTN_TSM_OWNER
#define SQLF_DBTN_ADSM_NODENAME        SQLF_DBTN_TSM_NODENAME
#define SQLF_DBTN_ADSM_MGMTCLASS       SQLF_DBTN_TSM_MGMTCLASS
#define SQLF_DBTN_LOCKLIST             1


/* obsolete config parm assorted defines                                      */
#define SQLFDMCA                       -1      /* Default maxcagents          */
#define SQLFDMXD                       -1      /* Default maxdari             */
#define SQLFDAPR                       -1      /* Default agentpri            */
#define SQLFMKPD                       0       /* keepdari - no               */
#define SQLFXKPD                       1       /* keepdari - yes              */

/* obsolete defines for SQLF_DBTN_DETS                                        */
#define SQLF_COPY_NOPROT               0x0     /* xxxx xxxx xxxx xxx0         */
#define SQLF_COPY_PROTECT              0x1     /* xxxx xxxx xxxx xxx1         */
#define SQLF_ENABLE_LOG_RETAIN         0x2     /* xxxx xxxx xxxx xx1x         */
#define SQLF_ENABLE_USER_EXIT          0x4     /* xxxx xxxx xxxx x1xx         */
#define SQLF_ENABLE_AUTO_RESTART       0x8     /* xxxx xxxx xxxx 1xxx         */
#define SQLF_ENABLE_LOGRETAIN_CAPTURE  0x10    /* xxxx xxxx xxx1 xxxx         */
#define SQLF_ENABLE_TRACKMOD           0x20    /* xxxx xxxx xx1x xxxx         */

/* Obsolete media types                                                       */
#define SQLU_ADSM_MEDIA                'A'     /* ADSM                        */


/* Repository for obsolete prototypes                                         */

/******************************************************************************
** sqlfeudb API
*******************************************************************************/
SQL_API_RC SQL_API_FN
  sqlfeudb (
   _SQLOLDCHAR *,                           /* database                       */
   _SQLOLDCHAR *,                           /* password                       */
   unsigned short,                          /* count                          */
   struct sqlfupd *,                        /* list of items                  */
   struct sqlca *);                         /* SQLCA                          */

/******************************************************************************
** sqlgeudb API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update Database Configuration  */
  sqlgeudb (
   unsigned short,                          /* reserved                       */
   unsigned short,                          /* database alias length          */
   unsigned short,                          /* number of entries being        */
                                            /* modified                       */
   unsigned short *,                        /* list of item lengths           */
   struct sqlfupd *,                        /* list of items                  */
   struct sqlca *,                          /* SQLCA                          */
   _SQLOLDCHAR *,                           /* reserved                       */
   _SQLOLDCHAR *);                          /* database alias                 */

/******************************************************************************
** sqlgrdbc API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reset Database Configuration   */
  sqlgrdbc (
   unsigned short,                          /* Spare1                         */
   unsigned short,                          /* Database name length           */
   struct sqlca *,                          /* SQLCA                          */
   _SQLOLDCHAR *,                           /* Spare2                         */
   _SQLOLDCHAR *);                          /* database                       */

/******************************************************************************
** sqlgxdbc API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Return Database Configuration  */
  sqlgxdbc (
   unsigned short,                          /* Spare1                         */
   unsigned short,                          /* Database name length           */
   unsigned short,                          /* count                          */
   struct sqlfupd *,                        /* list of items                  */
   struct sqlca *,                          /* SQLCA                          */
   _SQLOLDCHAR *,                           /* Spare2                         */
   _SQLOLDCHAR *);                          /* Database                       */

/* The following functions and symbols are obsolete and may not be supported  */
/* in future releases. The obsolete functions are provided for backward       */
/* compatibility and exported from DB2API.LIB. All applications should be     */
/* migrated to use new APIs. Note: Some of the function parameters may be NO  */
/* OP.                                                                        */
/******************************************************************************
** sqlfrdbc API
*******************************************************************************/
SQL_API_RC SQL_API_FN
  sqlfrdbc (
        _SQLOLDCHAR *,                         /* database                    */
        _SQLOLDCHAR *,                         /* password                    */
        struct sqlca *);                       /* SQLCA                       */

/******************************************************************************
** sqlfxdbc API
*******************************************************************************/
SQL_API_RC SQL_API_FN
  sqlfxdbc (
        _SQLOLDCHAR *,                         /* database alias              */
        _SQLOLDCHAR *,                         /* password                    */
        unsigned short,                        /* count of entries being      */
                                               /* returned                    */
        struct sqlfupd *,                      /* list of items               */
        struct sqlca *);                       /* SQLCA                       */

/* Provide info about a tableSpace in a database                              */
/******************************************************************************
** SQLB_TBSQRY_DATA data structure
*******************************************************************************/
SQL_STRUCTURE SQLB_TBSQRY_DATA
{
   sqluint32       id;                 /* internal id for the pool            */
   sqluint32       nameLen;            /* length of the name (for cobol &     */
                                       /* other nonC lang.)                   */
   char            name[SQLB_MAX_TBS_NAME_SZ]; /* NUL terminated name         */
   sqluint32       totalPages;         /* DMS : Pages specified by CREATE     */
                                       /* TABLESPACE.                         */
                                       /* SMS : N/A                           */
   sqluint32       useablePages;       /* DMS : totalPages - overhead         */
                                       /* SMS : N/A                           */
   sqluint32       flags;              /* bit attributes for the pool --      */
                                       /* includes 'class' & other stuff to   */
                                       /* be defined                          */
   sqluint32       pageSize;           /* pagesize of tablespace (in bytes)   */
                                       /* .. one of 4K, 8K, 16K, or 32K       */
   sqluint32       extSize;            /* extent size (in pages)              */
   sqluint32       prefetchSize;       /* prefetch size                       */
   sqluint32       nContainers;        /* number of containers                */
   sqluint32       tbsState;           /* SQLB_NORMAL, SQLB_LOAD_PENDING,     */
                                       /* etc.                                */
   char            lifeLSN[6];         /* 'timestamp' identifying the origin  */
                                       /* of the tbs                          */
   char            pad[2];             /* for alignment                       */
};

/******************************************************************************
** sqlgstsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Single TableSpace Query   */
  sqlgstsq (
   struct sqlca * pSqlca,
   sqluint32 TablespaceId,                       /* in: tableSpace id         */
   struct SQLB_TBSQRY_DATA * pTablespaceData);   /* out: tableSpace data      */

/******************************************************************************
** sqlgftsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Fetch TableSpace Query    */
  sqlgftsq (
   struct sqlca * pSqlca,
   sqluint32 MaxTablespaces,                     /* size of output area       */
   struct SQLB_TBSQRY_DATA * pTablespaceData,    /* out: array of length      */
                                                 /* maxTbs                    */
   sqluint32 * pNumTablespaces);                 /* out: #data entries        */
                                                 /* returned                  */

/******************************************************************************
** sqlgtsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* TableSpace Query          */
  sqlgtsq (
   struct sqlca * pSqlca,
   sqluint32 * pNumTablespaces,                  /* out: total number of      */
                                                 /* table spaces              */
   struct SQLB_TBSQRY_DATA ** ppTablespaceData); /* out: mem returned to      */
                                                 /* application               */

/* stsq - Single TableSpace Query                                             */
/******************************************************************************
** sqlbstsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Single Tablespace Query   */
  sqlbstsq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 TablespaceId,                       /* in: tableSpace id         */
   struct SQLB_TBSQRY_DATA * pTablespaceData);   /* out: tableSpace data      */

/* ftsq - Fetch TableSpace Query -> fetch the next block of tbs data          */
/******************************************************************************
** sqlbftsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Fetch Tablespace Query    */
  sqlbftsq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 MaxTablespaces,                     /* max num of tbs the        */
                                                 /* output area can hold      */
   struct SQLB_TBSQRY_DATA * pTablespaceData,    /* out: array of length      */
                                                 /* maxTbs                    */
   sqluint32 * pNumTablespaces);                 /* out: #data entries        */
                                                 /* returned                  */

/* tsq - TableSpace Query -> uses the above primitives to return the FULL     */
/* list of tablespaces in an array allocated and returned to the              */
/* application.  The application should free this memory with the sqlefmem()  */
/* api when it is finished with it. Even if this api fails with an            */
/* 'insufficient memory' error, 'nTbs' is set to the number of tablespaces    */
/* in the database. 'nTbs' is set to zero if we fail to sucessfully open a    */
/* query. 'tbsData' is returned as NULL (0;no mem alloc) if we fail for any   */
/* reason.                                                                    */
/******************************************************************************
** sqlbtsq API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Tablespace Query          */
  sqlbtsq (
   struct sqlca * pSqlca,                        /* SQLCA                     */
   sqluint32 * pNumTablespaces,                  /* out: total number of      */
                                                 /* table spaces              */
   struct SQLB_TBSQRY_DATA ** ppTablespaceData); /* out: mem returned to      */
                                                 /* application               */

#define DB2_DB_SUSPEND_NONE 0                    /* No action at all          */
#define DB2_DB_SUSPEND_WRITE 1                   /* Set write suspend for     */
                                                 /* database                  */
#define DB2_DB_RESUME_WRITE 2                    /* Set write resume for      */
                                                 /* database                  */
#define DB2_DB_SUSPEND_EXCLUDE_LOGS 4            /* Exclude LOGS flag         */
#define SLQUI_TINTO SQLUI_TINTO                  /* invalid into in tcolstrg  */
/* End of obsolete functions and symbols                                      */

#ifdef __cplusplus 
}
#endif

#endif /* SQL_H_SQLUTIL */
