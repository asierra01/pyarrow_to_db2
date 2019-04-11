/******************************************************************************
** 
** Source File Name: db2ApiDf
** 
** (C) COPYRIGHT International Business Machines Corp. 1987, 1997
** All Rights Reserved
** Licensed Materials - Property of IBM
** 
** US Government Users Restricted Rights - Use, duplication or
** disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
** 
** Function = Include File defining:
**              Environment Commands - Constants
**              Environment Commands - Structures
**              Environment Commands - Function Prototypes
**              Environment Commands - Labels for SQLCODES
** 
** Operating System: LINUX
** 
*******************************************************************************/
#ifndef SQL_H_DB2APIDF
#define SQL_H_DB2APIDF

#ifdef __cplusplus
extern "C" {
#endif

/* Note: _SQLOLDCHAR defaults to 'char'.  See sqlsystm.h for details.         */

#include "sqlsystm.h"                  /* System dependent defines  */

/* Required Include Files */

#include "sql.h"                       /* Includes sqlsystm & sqlca */
#include "sqlda.h"
#include "sqlmon.h"
#include "sqlaprep.h"
#include "sqlutil.h"
#include <stddef.h>                    /* needed for offsetof */


/* Version, Release PTF identifier                                            */
#define db2Version6Prior SQL_RELPRE6                 /* Pre Version 6.1.0.0   */
#define db2Version610    SQL_REL6100                 /* Version 6.1.0.0       */
#define db2Version710    SQL_REL7100                 /* Version 7.1.0.0       */
#define db2Version810    SQL_REL8100                 /* Version 8.1.0.0       */
#define db2Version812    SQL_REL8102                 /* Version 8.1.0.2       */
#define db2Version814    SQL_REL8104                 /* Version 8.1.0.4       */
#define db2Version820    SQL_REL8200                 /* Version 8.2.0.0       */
#define db2Version822    SQL_REL8202                 /* Version 8.2.0.2       */
#define db2Version900    SQL_REL9000                 /* Version 9.0.0.0       */
#define db2Version950    SQL_REL9500                 /* Version 9.5.0.0       */
#define db2Version956    SQL_REL9506                 /* Version 9.5.0.6       */
#define db2Version958    SQL_REL9508                 /* Version 9.5.0.8       */
#define db2Version970    SQL_REL9700                 /* Version 9.7.0.0       */
#define db2Version972    SQL_REL9702                 /* Version 9.7.0.2       */
#define db2Version974    SQL_REL9704                 /* Version 9.7.0.4       */
#define db2Version975    SQL_REL9705                 /* Version 9.7.0.5       */
#define db2Version980    SQL_REL9800                 /* Version 9.8.0.0       */
#define db2Version1010   SQL_REL10100                /* Version 10.1.0.0      */
#define db2Version1014   SQL_REL10104                /* Version 10.1.0.4      */
#define db2Version1015   SQL_REL10105                /* Version 10.1.0.5      */
#define db2Version1016   SQL_REL10106                /* Version 10.1.0.6      */
#define db2Version1050   SQL_REL10500                /* Version 10.5.0.0      */
#define db2Version1053   SQL_REL10503                /* Version 10.5.0.3      */
#define db2Version1054   SQL_REL10504                /* Version 10.5.0.4      */
#define db2Version1056   SQL_REL10506                /* Version 10.5.0.6      */
#define db2Version1059   SQL_REL10509                /* Version 10.5.0.9      */
#define db2Version1060   SQL_REL10600                /* Version 10.6.0.0      */
#define db2Version1070   SQL_REL10700                /* Version 10.7.0.0      */
#define db2Version1080   SQL_REL10800                /* Version 10.8.0.0      */
#define db2Version1110   SQL_REL11100                /* Version 11.1.0.0      */
#define db2Version1111   SQL_REL11010101             /* Version 11.1.1.1      */
#define db2Version1112   SQL_REL11010202             /* Version 11.1.2.2      */
#define db2Version1113   SQL_REL11010303             /* Version 11.1.3.3      */

/* Type definition names                                                      */
typedef sqluint64 db2Uint64;                         /* 64 bit unsigned int  */
typedef sqlint64  db2int64;                          /* 64 bit signed int  */
typedef sqluint32 db2Uint32;                         /* 32 bit unsigned int   */
typedef sqlint32  db2int32;                          /* 32 bit signed int     */
typedef sqluint16 db2Uint16;                         /* 16 bit unsigned int   */
typedef sqlint16  db2int16;                          /* 16 bit signed int     */
typedef sqluint8  db2Uint8;                          /*  8 bit unsigned int   */
typedef sqlint8   db2int8;                           /*  8 bit signed int   */
typedef SQL_PDB_NODE_TYPE db2NodeType;               /* Node                  */
typedef sqluint16 db2LogStreamIDType;                /* Log Stream ID         */
typedef SQL_PDB_PORT_TYPE db2PortType;               /* Port                  */

#define db2LogStreamIDUndefined 0xFFFF /* Indicates logStreamID is            */
                                       /* undefined.                          */
#define db2LogExtentUndefined 0xFFFFFFFF /* Indicates log extent is           */
                                       /* undefined.                          */
#define db2NodeUndefined ((db2NodeType)-1)           /* Invalid or unknown member number */

/******************************************************************************
** db2Char data structure
** db2Char data structure parameters
** 
** pioData
** A pointer to a character data buffer. If NULL, no data will be
** returned.
** 
** iLength
** Input. The size of the pioData buffer.
** 
** oLength
** Output. The number of valid characters of data in the pioData buffer.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2Char
{
   char            *pioData;           /* Character data                      */
   db2Uint32       iLength;            /* I:  Length of pioData               */
   db2Uint32       oLength;            /* O:  Untruncated length of data      */
} db2Char;

/******************************************************************************
** db2LSN data structure
** db2LSN data structure parameters
** 
** lsnU64
** Represents the log sequence number (LSN).
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LSN
{
   db2Uint64       lsnU64;             /* Log sequence number                 */
} db2LSN;

/******************************************************************************
** db2LRI data structure
** db2LRI data structure parameters
** 
** lriType
** The type of LRI structure.
** 
** part1
** Part 1 of the LRI structure.
** 
** part2
** Part 2 of the LRI structure.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LRI
{
   db2Uint64       lriType;            /* LRI type                            */
   db2Uint64       part1;              /* Part 1 of the LRI structure         */
   db2Uint64       part2;              /* Part 2 of the LRI structure         */
} db2LRI;

/* db2LRI types                                                               */
#define DB2READLOG_LRI_1 1             /* LRI type 1                          */
#define DB2READLOG_LRI_2 2             /* LRI type 2                          */



/* Database and Database Manager Configuration Structures, Constants, and     */
/* Function Prototypes                                                        */

#define db2CfgDatabase                 1         /* act on database cfg, or   */
#define db2CfgDatabaseManager          2         /* act on database manager   */
                                                 /* cfg                       */
#define db2CfgImmediate                4         /* get/set current values,   */
                                                 /* or                        */
#define db2CfgDelayed                  8         /* get/set delayed values    */
#define db2CfgGetDefaults              64        /* get default values        */
#define db2CfgSingleDbpartition        512       /* update on specific db     */
                                                 /* partition                 */
#define db2CfgSingleMember             1024      /* update on specific db     */
                                                 /* member                    */
#define db2CfgReset                    64        /* set to default values     */
                                                 /* (reset)                   */
#define db2CfgMaxParam                 64        /* maximum number of params  */
                                                 /* in db2Cfg paramArray      */


/* Constants describing a single configuration parameter                      */
#define db2CfgParamAutomatic           1         /* let db2 set this value    */
#define db2CfgParamComputed            2         /* set to computed. An       */
                                                 /* automatic param           */
                                                 /* calculated once.          */
#define db2CfgParamManual              16        /* unset the automatic or    */
                                                 /* computed feature,         */
                                                 /* leaving the value         */
                                                 /* intact.                   */


/******************************************************************************
** Constants for updating and getting self_tuning_mem.
** The self_tuning_mem parameter can be updated to ON or OFF
** and it can return ON, OFF, ON_ACTIVE or ON_INACTIVE.
** Please refer to the documentation on Self-Tuning Memory.
*******************************************************************************/
#define db2SelfTuningOff               0         /* Self tuning is disabled.  */
#define db2SelfTuningOn                1         /* Self tuning is enabled.   */
#define db2SelfTuningOnActive          2         /* Self tuning is enabled    */
                                                 /* and active.               */
#define db2SelfTuningOnInactive        3         /* Self tuning is enabled    */
                                                 /* but inactive.             */


/* Structure for a single Configuration Parameter                             */
/******************************************************************************
** db2CfgParam data structure
** db2CfgParam data structure parameters
** 
** token
** Input. The configuration parameter identifier.
** 
** Valid entries and data types for the db2CfgParam token element are listed in
** "Configuration parameters summary".
** 
** ptrvalue
** Output. The configuration parameter value. 
** 
** flags
** Input. Provides specific information for each parameter in a request. Valid
** values (defined in db2ApiDf header file, located in the include
** directory) are:
** - db2CfgParamAutomatic
** Indicates whether the retrieved parameter has a value of automatic. To
** determine whether a given configuration parameter has been set to
** automatic, perform a boolean AND operation against the value returned by
** the flag and the db2CfgParamAutomatic keyword defined in db2ApiDf.h.
** - db2CfgParamComputed
** Indicates whether the retrieved parameter has a value of computed.
** To determine whether a given configuration parameter has been set to
** computed, perform a boolean AND operation against the value returned by the
** flag and the db2CfgParamComputed keyword defined in db2ApiDf.h.
** -  db2CfgParamManual
** Used to unset the automatic or computed setting of a parameter and set the
** parameter to the current value. The ptrvalue field is ignored and can be
** set to NULL.
**  *******************************************************************************/
typedef SQL_STRUCTURE db2CfgParam
{
   db2Uint32                           token;    /* Parameter Identifier      */
   char                                *ptrvalue; /* Parameter value          */
   db2Uint32                           flags;    /* flags for this parameter  */
} db2CfgParam;

/* Main structure for db2CfgSet() and db2CfgGet()                             */
/******************************************************************************
** db2Cfg data structure
** db2Cfg data structure parameters
** 
** numItems
** Input. The number of configuration parameters in the paramArray array. Set
** this value to db2CfgMaxParam to specify the largest number of elements in
** the paramArray.
** 
** paramArray
** Input. A pointer to the db2CfgParam structure.
** 
** flags
** Input. Specifies the type of action to be taken. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** - db2CfgDatabase
** Specifies to return the values in the database configuration file.
** - db2CfgDatabaseManager
** Specifies to return the values in the database manager configuration file.
** - db2CfgImmediate
** Returns the current values of the configuration parameters stored in
** memory.
** - db2CfgDelayed
** Gets the values of the configuration parameters on disk. These do not
** become the current values in memory until the next database connection
** or instance attachment.
** - db2CfgGetDefaults
** Returns the default values for the configuration parameter.
** - db2CfgReset
** Reset to default values.
** - db2CfgSingleDbpartition
** To update or reset the database configuration on a specific database
** partition, set this flag and provide a value for dbpartitionnum. This is only
** applicable in a partitioned database environment and ignored in other environments.
** - db2CfgSingleMember
** To update or reset the database configuration on a specific member, set this flag
** and provide a value for member. This is only applicable in a DB2® pureScale™environment
** and ignored in other environments.
** 
** dbname
** Input. The database name.
** 
** dbpartitionnum
** Input. Specifies on which database partition this API will set the configuration value.
** The DBPARTITIONNUM parameter is only applicable in a partitioned database environment
** and must be 0 in a DB2 pureScale environment.
** 
** member
** Input. Specifies on which member this API will set the configuration value. The MEMBER
** parameter is only applicable in a DB2 pureScale environment and ignored in other environments.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2Cfg
{
   db2Uint32                           numItems; /* Number of configuration   */
                                                 /* parameters in the         */
                                                 /* following array           */
   struct db2CfgParam                  *paramArray; /* Array of cfg           */
                                                 /* parameters                */
   db2Uint32                           flags;    /* Various properties        */
   char                                *dbname;  /* Database Name, if needed  */
   SQL_PDB_NODE_TYPE                   dbpartitionnum; /* Specific database   */
                                                 /* partition number          */
   SQL_PDB_NODE_TYPE                   member;   /* Specific member number    */
} db2Cfg;

/* API for Setting/Reading the Configuration Parameters                       */
/******************************************************************************
** db2CfgSet API
** Modifies individual entries in a specific database configuration file or a
** database manager configuration file. A database configuration file resides
** on every database partition on which the database has been created.
** 
** Scope
** 
** Modifications to the database configuration file affect all database partitions by default.
** 
** Authorization
** 
** For modifications to the database configuration file, one of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** For modifications to the database manager configuration file:
** - sysadm
** 
** Required connection
** 
** To make an online modification of a configuration parameter for a specific
** database, a connection to the database is required. To make an online
** modification of a configuration parameter for the database manager,
** or an attachment to an instance is not required.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2CfgSet API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2Cfg structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Set/Reset Config Params   */
  db2CfgSet (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2CfgGet API
** Returns the values of individual entries in a specific database configuration
** file or a database manager configuration file.
** 
** Scope
** 
** Information about a specific database configuration file is returned only for
** the member on which it is executed.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** To obtain the current online value of a configuration parameter for a
** specific database configuration file, a connection to the database is
** required. To obtain the current online value of a configuration parameter
** for the database manager, an instance attachment is required. Otherwise, a
** connection to a database or an attachment to an instance is not required.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2CfgGet API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2Cfg structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Read Config Params        */
  db2CfgGet (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Structure (generic) for a single Configuration Parameter                   */
/******************************************************************************
** db2gCfgParam data structure
** db2gCfgParam data structure specific parameters
** 
** token
** Input. The configuration parameter identifier.
** Valid entries and data types for the db2CfgParam token element are listed
** in 'Configuration parameters summary'.
** Note: Additional db2Cfg tokens are added to support getting (or setting) of
** cluster caching facility configuration parameters and cluster caching facility
** structure configuration parameters in a DB2® pureScale™environment.
** 
** ptrvalue
** Output. The configuration parameter value.
** 
** flags
** Output. Provides specific information for each parameter in a request. Valid values
** (defined in db2ApiDf header file, located in the include directory) are:
** - db2CfgParamAutomatic
** Indicates whether the retrieved parameter has a value of AUTOMATIC. To determine
** whether a given configuration parameter has been set to AUTOMATIC, perform a boolean
** AND operation against the value returned by the flag and the db2CfgParamAutomatic
** keyword defined in db2ApiDf.h.
** - db2CfgParamComputed
** Indicates whether the retrieved parameter has a value of COMPUTED. To determine
** whether a given configuration parameter has been set to COMPUTED, perform a boolean
** AND operation against the value returned by the flag and the db2CfgParamComputed
** keyword defined in db2ApiDf.h.
** 
** If the boolean AND operation is false for both of the keywords above, it means that the
** retrieved parameter value is set manually.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gCfgParam
{
   db2Uint32                           token;    /* Parameter Identifier      */
   db2Uint32                           ptrvalue_len; /* length of ptrvalue    */
   char                                *ptrvalue; /* Parameter value          */
   db2Uint32                           flags;    /* flags for this parameter  */
} db2gCfgParam;

/* Main (generic) structure for db2CfgSet() and db2CfgGet()                   */
/******************************************************************************
** db2gCfg data structure
** db2gCfg data structure specific parameters
** 
** numItems
** Input. The number of configuration parameters in the paramArray array. Set this
** value to db2CfgMaxParam to specify the largest number of elements in the paramArray.
** 
** paramArray
** Input. A pointer to the db2CfgParam structure.
** 
** flags
** Input. Specifies the type of action to be taken. Valid values (defined in db2ApiDf header
** file, located in the include directory) are:
** -_ db2CfgDatabase
** Specifies to return the values in the database configuration file.
** - db2CfgDatabaseManager
** Specifies to return the values in the database manager configuration file.
** - db2CfgImmediate
** Returns the current values of the configuration parameters stored in memory.
** - db2CfgDelayed
** Gets the values of the configuration parameters on disk. These do not become
** the current values in memory until the next database connection or instance attachment.
** - db2CfgGetDefaults
** Returns the default values for the configuration parameter.
** 
** dbname
** Input. The database name.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gCfg
{
   db2Uint32                           numItems; /* Number of configuration   */
                                                 /* parameters in the         */
                                                 /* following array           */
   struct db2gCfgParam                 *paramArray; /* Array of cfg           */
                                                 /* parameters                */
   db2Uint32                           flags;    /* Various properties        */
   db2Uint32                           dbname_len; /* length of dbname        */
   char                                *dbname;  /* Database Name, if needed  */
} db2gCfg;

/* (Generic) API for Setting/Reading the Configuration Parameters             */
/******************************************************************************
** db2gCfgSet API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Set/Reset Config Params   */
  db2gCfgSet (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gCfgGet API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Read Config Params        */
  db2gCfgGet (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */


/* Struct used by db2PartitioningInfo to store                                */
/* partitioning information                                                   */
/******************************************************************************
** db2PartitioningKey data structure
** db2PartitioningKey data structure parameter descriptions
** 
** sqltype
** Input. Data type of the distribution key.
** 
** sqllen
** Input. Data length of the distribution key.
*******************************************************************************/
SQL_STRUCTURE db2PartitioningKey
{
   unsigned short                      sqltype;  /* Date Type of Key          */
   unsigned short                      sqllen;   /* Data Length of Key        */
};

/******************************************************************************
** db2PartitioningInfo data structure
** This structure is used to store partitioning information, such as
** the distribution map and the distribution key of a table.
** 
** Table: Fields in the db2PartitioningInfo Structure
** |---------------------------------------------------------------|
** |Field Name|Data Type        |Description                       |
** |----------|-----------------|----------------------------------|
** |PMAPLEN   |INTEGER          |The length of the distribution map|
** |          |                 |in bytes. For a single-database   |
** |          |                 |partition table, the value is     |
** |          |                 |sizeof(SQL_PDB_NODE_TYPE). For a  |
** |          |                 |multi-database partition table,   |
** |          |                 |the value is                      |
** |          |                 |SQL_PDB_MAP_SIZE_32K *            |
** |          |                 |sizeof(SQL_PDB_NODE_TYPE).        |
** |----------|-----------------|----------------------------------|
** |PMAP      |SQL_PDB_NODE_TYPE|The distribution map.             |
** |----------|-----------------|----------------------------------|
** |SQLD      |INTEGER          |The number of used                |
** |          |                 |db2PartitioningKey elements;      |
** |          |                 |that is, the number of key        |
** |          |                 |parts in a distribution key.      |
** |----------|-----------------|----------------------------------|
** |db2PartitioningKey|Structure|The description of a distribution |
** |          |                 |column in a distribution key. The |
** |          |                 |maximum number of distribution    |
** |          |                 |columns is SQL_MAX_NUM_PART_KEYS. |
** |----------|-----------------|----------------------------------|
** 
** The following table shows the SQL data types and lengths for the
** db2PartitioningInfo data structure. The SQLTYPE column specifies
** the numeric value that represents the data type of an item.
** 
** Table: SQL Data Types and Lengths for the db2PartitioningInfo
** structure.
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
SQL_STRUCTURE db2PartitioningInfo
{
   sqluint32                           pmaplen;  /* Length of partitioning    */
                                                 /* map                       */
   SQL_PDB_NODE_TYPE                   *pmap;    /* Partitioning map          */
   unsigned short                      sqld;     /* # of used                 */
                                                 /* db2PartitioningKey        */
                                                 /* elements                  */
   struct db2PartitioningKey           sqlpartkey[SQL_MAX_NUM_PART_KEYS]; /*  */
                                                 /* KEYS                      */
};

SQL_STRUCTURE db2DistMapStruct
{
   unsigned char                       *tname;   /* Fully qualified table     */
                                                 /* name                      */
   struct db2PartitioningInfo          *partinfo; /* Partitioning             */
                                                 /* Information               */
};

SQL_STRUCTURE db2gDistMapStruct
{
   unsigned short                      tname_len; /* Length of table name     */
   unsigned char                       *tname;   /* Fully qualified table     */
                                                 /* name                      */
   struct db2PartitioningInfo          *partinfo; /* Partitioning             */
                                                 /* Information               */
};

SQL_STRUCTURE db2RowPartNumStruct
{
   unsigned short                      num_ptrs; /* Number of pointers        */
   unsigned char                       **ptr_array; /* An array of pointers   */
                                                 /* to char string            */
   unsigned short                      *ptr_lens; /* An array of character    */
                                                 /* string lengths            */
   unsigned short                      countrycode; /* Territory/Country      */
                                                 /* code                      */
   unsigned short                      codepage; /* Code page                 */
   struct db2PartitioningInfo          *partinfo; /* Partitioning             */
                                                 /* Information               */
   short                               *part_num; /* Partition number         */
   SQL_PDB_NODE_TYPE                   *node_num; /* database partition       */
                                                 /* number                    */
   unsigned short                      chklvl;   /* Check level               */
   short                               dataFormat; /* Data format             */
};

/******************************************************************************
** db2GetDistMap API
** Allows an application to obtain the distribution information for a table. The
** distribution information includes the distribution map and the column
** definitions of the distribution key. Information returned by this API can be
** passed to the sqlugrpn API to determine the database partition number and
** the database partition server number for any row in the table.
** 
** To use this API, the application must be connected to the database that
** contains the table for which distribution information is being requested.
** 
** Scope
** 
** This API can be executed on any database partition server defined in the
** db2nodes.cfg file.
** 
** Authorization
** 
** For the table being referenced, a user must have at least one of the
** following:
** - sysadm authority
** - dbadm authority
** - CONTROL privilege
** - SELECT privilege
** 
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2GetDistMap API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DistMapStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get Table Distribution    */
                                                 /* Map                       */
  db2GetDistMap (
   sqluint32 db2VersionNumber,                   /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2GetRowPartNum API
** Returns the database partition number and the database partition server
** number based on the distribution key values. An application can use this
** information to determine on which database partition server a specific
** row of a table is stored.
** 
** The partitioning data structure, db2PartitioningInfo, is the input for this API. The
** structure can be returned by the db2GetDistMap API. Another input is the character
** representations of the corresponding distribution key values. The output is a
** database partition number generated by the distribution strategy and the
** corresponding database partition server number from the distribution map.
** If the distribution map information is not provided, only the database
** partition number is returned. This can be useful when analyzing data
** distribution.
** 
** The database manager does not need to be running when this API is called.
** 
** Scope
** 
** This API must be invoked from a database partition server in the
** db2nodes.cfg file. This API should not be invoked from a client, since it
** could result in erroneous database partitioning information being returned
** due to differences in codepage and endianness between the client and the
** server.
** 
** Authorization
** 
** None
** 
** API include file
** 
** sqlutil.h
** 
** sqlugrpn API parameters
** 
** num_ptrs
** The number of pointers in ptr_array. The value must be the same as the one
** specified for the part_info parameter; that is, part_info->sqld.
** 
** ptr_array
** An array of pointers that points to the character representations of the
** corresponding values of each part of the distribution key specified in
** part_info. If a null value is required, the corresponding pointer is set to
** null. For generated columns, this function does not generate values for the
** row. The user is responsible for providing a value that will lead to the
** correct partitioning of the row.
** 
** ptr_lens
** An array of unsigned integers that contains the lengths of the character
** representations of the corresponding values of each part of the partitioning
** key specified in part_info.
** 
** territory_ctrycode
** The country/region code of the target database.
** 
** This value can also be obtained from the database configuration file
** using the GET DATABASE CONFIGURATION command.
** 
** codepage
** The code page of the target database.
** 
** This value can also be obtained from the database configuration file
** using the GET DATABASE CONFIGURATION command.
** 
** part_info
** A pointer to the db2PartitioningInfo structure.
** 
** part_num
** A pointer to a 2-byte signed integer that is used to store the database
** partition number.
** 
** node_num
** A pointer to an SQL_PDB_NODE_TYPE field used to store the node number. If
** the pointer is null, no node number is returned.
** 
** chklvl
** An unsigned integer that specifies the level of checking that is done
** on input parameters. If the value specified is zero, no checking is done.
** If any non-zero value is specified, all input parameters are checked.
** 
** sqlca
** Output. A pointer to the sqlca structure.
** 
** dataformat
** Specifies the representation of distribution key values. Valid values are:
** - SQL_CHARSTRING_FORMAT
** All distribution key values are represented by character strings. This is the
** default value.
** - SQL_IMPLIEDDECIMAL_FORMAT
** The location of an implied decimal point is determined by the column
** definition. For example, if the column definition is DECIMAL(8,2), the value
** 12345 is processed as 123.45.
** - SQL_PACKEDDECIMAL_FORMAT
** All decimal column distribution key values are in packed decimal format.
** - SQL_BINARYNUMERICS_FORMAT
** All numeric distribution key values are in big-endian binary format.
** 
** pReserved1
** Reserved for future use.
** 
** pReserved2
** Reserved for future use.
** 
** Usage notes
** 
** Data types supported on the operating system are the same as those that
** can be defined as a distribution key.
** 
** Note: CHAR, VARCHAR, GRAPHIC, and VARGRAPHIC data types must be converted
** to the database code page before this API is called.
** 
** For numeric and datetime data types, the character representations must be at
** the code page of the respective system where the API is invoked.
** 
** If node_num is not null, the distribution map must be supplied; that is,
** pmaplen field in part_info parameter (part_info->pmaplen) is either 2 or
** 8192. Otherwise, SQLCODE -6038 is returned. The distribution key must be
** defined; that is, sqld field in part_info parameter (part_info->sqld)
** must be greater than zero. Otherwise, SQLCODE -2032 is returned.
** 
** If a null value is assigned to a non-nullable partitioning column, SQLCODE
** -6039 is returned.
** 
** All the leading blanks and trailing blanks of the input character string are
** stripped, except for the CHAR, VARCHAR, GRAPHIC, and VARGRAPHIC data types,
** where only trailing blanks are stripped.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get Table Distribution    */
                                                 /* Map                       */
  db2GetRowPartNum (
   sqluint32 db2VersionNumber,                   /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */




#define SQL_CS_SYSTEM_NLSCHAR          -8        /* SYSTEM table + NLS        */
                                                 /* function                  */
#define SQL_CS_USER_NLSCHAR            -9        /* USER table + NLS          */
                                                 /* function                  */
/* Node List Operations Constants                                             */
#define DB2_NODE_LIST        0            /* submit to all nodes in the node  */
                                          /* list                             */
#define DB2_ALL_NODES        1            /* submit to all nodes in the node  */
                                          /* configuration file               */
#define DB2_ALL_EXCEPT       2            /* submit to all nodes except the   */
                                          /* ones specified by the nodelist   */
                                          /* parameter                        */
#define DB2_CAT_NODE_ONLY    3            /* submit to catalog node only      */
/* Load Query Structures and Constants                                        */

/* Possible values for "iStringType"                                          */
#define DB2LOADQUERY_TABLENAME         0         /* Tablename specified       */
#define DB2LOADQUERY_TEMPPATHNAME      1

/* Possible values for "iShowLoadMessages"                                    */
#define DB2LOADQUERY_SHOW_ALL_MSGS     0         /* Show ALL LOAD messages    */
#define DB2LOADQUERY_SHOW_NO_MSGS      1         /* Show NO LOAD messages     */
#define DB2LOADQUERY_SHOW_NEW_MSGS     2         /* Show only NEW LOAD        */
                                                 /* messages                  */

/* Possible values for "oWhichPhase"                                          */
#define DB2LOADQUERY_CDEANALYZE_PHASE  5         /* Cde Analyze Phase         */
#define DB2LOADQUERY_LOAD_PHASE        1         /* Load Phase                */
#define DB2LOADQUERY_BUILD_PHASE       2         /* Build Phase               */
#define DB2LOADQUERY_DELETE_PHASE      3         /* Delete Phase              */
#define DB2LOADQUERY_INDEXCOPY_PHASE   4         /* Index Copy Phase          */

/* Possible values for "oTablestate"                                          */
#define DB2LOADQUERY_NORMAL            0x0       /* Normal tablestate         */
#define DB2LOADQUERY_SI_PENDING        0x1       /* Table in Set Integrity    */
                                                 /* pending state             */
#define DB2LOADQUERY_CHECK_PENDING     0x1       /* For backward source       */
                                                 /* compatibility             */
#define DB2LOADQUERY_LOAD_IN_PROGRESS  0x2       /* Load in progress on       */
                                                 /* table                     */
#define DB2LOADQUERY_READ_ACCESS       0x4       /* Table in read access      */
                                                 /* only state                */
#define DB2LOADQUERY_NOTAVAILABLE      0x8       /* Table in unavailable      */
                                                 /* state                     */
#define DB2LOADQUERY_NO_LOAD_RESTART   0x10      /* Table not in load         */
                                                 /* restartable state         */
#define DB2LOADQUERY_UNCHANGED         0x20      /* Table state has not       */
                                                 /* changed                   */
#define DB2LOADQUERY_LOAD_PENDING      0x40      /* Table pending completion  */
                                                 /* of load                   */
#define DB2LOADQUERY_NO_DATA_MOVEMENT  0x80      /* Table in no data          */
                                                 /* movement state            */
#define DB2LOADQUERY_RECONCILE_PENDING 0x100     /* Table in datalink         */
                                                 /* reconcile pending state   */
#define DB2LOADQUERY_RECONCILE_NOT_POS 0x200     /* Table in datalink         */
                                                 /* reconcile not possible    */
                                                 /* state                     */
#define DB2LOADQUERY_TYPE1_INDEXES     0x400     /* Table has type-1 indexes  */
#define DB2LOADQUERY_REORG_PENDING     0x800     /* Table in reorg pending    */
                                                 /* state                     */
#define DB2LOADQUERY_RDST_IN_PROGRESS  0x1000    /* Redistribute in progress  */
                                                 /* on table                  */

/* Load Query Output Structure                                                */
/******************************************************************************
** db2LoadQueryOutputStruct data structure
** db2LoadQueryOutputStruct data structure parameters
** 
** oRowsRead
** Output. Number of records read so far by the load utility.
** 
** oRowsSkipped
** Output. Number of records skipped before the load operation began.
** 
** oRowsCommitted
** Output. Number of rows committed to the target table so far.
** 
** oRowsLoaded
** Output. Number of rows loaded into the target table so far.
** 
** oRowsRejected
** Output. Number of rows rejected from the target table so far.
** 
** oRowsDeleted
** Output. Number of rows deleted from the target table so far (during the
** delete phase).
** 
** oCurrentIndex
** Output. Index currently being built (during the build phase).
** 
** oNumTotalIndexes
** Output. Total number of indexes to be built (during the build phase).
** 
** oCurrentMPPNode
** Output. Indicates which database partition server is being queried (for
** partitioned database environment mode only).
** 
** oLoadRestarted
** Output. A flag whose value is TRUE if the load operation being queried is a
** load restart operation.
** 
** oWhichPhase
** Output. Indicates the current phase of the load operation being queried.
** Valid values (defined in db2ApiDf header file, located in the include
** directory) are: 
** - DB2LOADQUERY_CDEANALYZE_PHASE 
** Cde analyze phase. 
** - DB2LOADQUERY_LOAD_PHASE 
** Load phase. 
** - DB2LOADQUERY_BUILD_PHASE 
** Build phase. 
** - DB2LOADQUERY_DELETE_PHASE 
** Delete phase.
** - DB2LOADQUERY_INDEXCOPY_PHASE 
** Index copy phase. 
** 
** oWarningCount
** Output. Total number of warnings returned so far.
** 
** oTableState
** Output. The table states. Valid values (defined in db2ApiDf header
** file, located in the include directory) are:
** 
** - DB2LOADQUERY_NORMAL
** No table states affect the table. 
** 
** - DB2LOADQUERY_CHECK_PENDING 
** The table has constraints and the constraints have yet to be verified. Use
** the SET INTEGRITY command to take the table out of the
** DB2LOADQUERY_CHECK_PENDING state. The load utility puts a table into the
** DB2LOADQUERY_CHECK_PENDING state when it begins a load on a table with
** constraints. 
** 
** - DB2LOADQUERY_LOAD_IN_PROGRESS
** There is a load actively in progress on this table. 
** 
** - DB2LOADQUERY_LOAD_PENDING 
** A load has been active on this table but has been aborted before the load
** could commit. Issue a load terminate, a load restart, or a load replace
** to bring the table out of the DB2LOADQUERY_LOAD_PENDING state. 
** 
** - DB2LOADQUERY_READ_ACCESS 
** The table data is available for read access queries. Loads using the
** DB2LOADQUERY_READ_ACCESS option put the table into Read Access Only state.
** 
** - DB2LOADQUERY_NOTAVAILABLE 
** The table is unavailable. The table may only be dropped or it may be restored
** from a backup. Rollforward through a non-recoverable load will put a table
** into the unavailable state. 
** 
** - DB2LOADQUERY_NO_LOAD_RESTART 
** The table is in a partially loaded state that will not allow a load
** restart. The table will also be in the Load Pending state. Issue a
** load terminate or a load replace to bring the table out of the No
** Load Restartable state. The table can be placed in the
** DB2LOADQUERY_NO_LOAD_RESTART state during a rollforward
** operation. This can occur if you rollforward to a point in time that
** is prior to the end of a load operation, or if you roll forward through
** an aborted load operation but do not roll forward to the end of the load
** terminate or load restart operation.
** 
** - DB2LOADQUERY_TYPE1_INDEXES
** The table currently uses type-1 indexes. Type-1 indexes are no longer
** supported and are converted to type-2 indexes when the table is next
** accessed. As a result, this value is deprecated and might be removed in
** a future release.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadQueryOutputStruct
{
   db2Uint32                           oRowsRead; /* Rows Read                */
   db2Uint32                           oRowsSkipped; /* Rows Skipped          */
   db2Uint32                           oRowsCommitted; /* Rows Committed      */
   db2Uint32                           oRowsLoaded; /* Rows Loaded            */
   db2Uint32                           oRowsRejected; /* Rows Rejected        */
   db2Uint32                           oRowsDeleted; /* Rows Deleted          */
   db2Uint32                           oCurrentIndex; /* Current Index        */
                                                 /* (BUILD PHASE)             */
   db2Uint32                           oNumTotalIndexes; /* Total # of        */
                                                 /* Indexes to build (BUILD   */
                                                 /* PHASE)                    */
   db2Uint32                           oCurrentMPPNode; /* Node being         */
                                                 /* queried (MPP only)        */
   db2Uint32                           oLoadRestarted; /* Load Restart        */
                                                 /* indicator                 */
   db2Uint32                           oWhichPhase; /* Phase of queried Load  */
   db2Uint32                           oWarningCount; /* Warning Count        */
   db2Uint32                           oTableState; /* Table State            */
} db2LoadQueryOutputStruct;

/* Load Query Parameter Structure                                             */
/******************************************************************************
** db2LoadQueryStruct data structure
** db2LoadQueryStruct data structure parameters
** 
** iStringType
** Input. Specifies a type for piString. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** - DB2LOADQUERY_TABLENAME
** Specifies a table name for use by the db2LoadQuery API.
** 
** piString
** Input. Specifies a temporary files path name or a table name, depending on
** the value of iStringType.
** 
** iShowLoadMessages
** Input. Specifies the level of messages that are to be returned by the load
** utility. Valid values (defined in db2ApiDf header file, located in the
** include directory) are: 
** 
** - DB2LOADQUERY_SHOW_ALL_MSGS
** Return all load messages.
** - DB2LOADQUERY_SHOW_NO_MSGS
** Return no load messages.
** - DB2LOADQUERY_SHOW_NEW_MSGS
** Return only messages that have been generated since the last call to
** this API.
** 
** poOutputStruct
** Output. A pointer to the db2LoadQueryOutputStruct structure, which
** contains load summary information. Set to NULL if a summary is not
** required. 
** 
** piLocalMessageFile
** Input. Specifies the name of a local file to be used for output messages.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadQueryStruct
{
   db2Uint32                           iStringType; /* Type of piString       */
   char                                *piString; /* Name to query            */
   db2Uint32                           iShowLoadMessages; /* Level of Load    */
                                                 /* message reporting         */
   struct db2LoadQueryOutputStruct     *poOutputStruct; /* Load Query Output  */
                                                 /* Structure                 */
   char                                *piLocalMessageFile; /* Message File   */
} db2LoadQueryStruct;

/* Load Query Output Structure - 64 bit counters                              */
/******************************************************************************
** db2LoadQueryOutputStruct64 data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadQueryOutputStruct64
{
   db2Uint64                           oRowsRead; /* Rows Read                */
   db2Uint64                           oRowsSkipped; /* Rows Skipped          */
   db2Uint64                           oRowsCommitted; /* Rows Committed      */
   db2Uint64                           oRowsLoaded; /* Rows Loaded            */
   db2Uint64                           oRowsRejected; /* Rows Rejected        */
   db2Uint64                           oRowsDeleted; /* Rows Deleted          */
   db2Uint32                           oCurrentIndex; /* Current Index        */
                                                 /* (BUILD PHASE)             */
   db2Uint32                           oNumTotalIndexes; /* Total # of        */
                                                 /* Indexes to build (BUILD   */
                                                 /* PHASE)                    */
   db2Uint32                           oCurrentMPPNode; /* Node being         */
                                                 /* queried (MPP only)        */
   db2Uint32                           oLoadRestarted; /* Load Restart        */
                                                 /* indicator                 */
   db2Uint32                           oWhichPhase; /* Phase of queried Load  */
   db2Uint32                           oWarningCount; /* Warning Count        */
   db2Uint32                           oTableState; /* Table State            */
} db2LoadQueryOutputStruct64;

/* Load Query Parameter Structure - 64 bit counters                           */
/******************************************************************************
** db2LoadQueryStruct64 data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadQueryStruct64
{
   db2Uint32                           iStringType; /* Type of piString       */
   char                                *piString; /* Name to query            */
   db2Uint32                           iShowLoadMessages; /* Level of Load    */
                                                 /* message reporting         */
   struct db2LoadQueryOutputStruct64   *poOutputStruct; /* Load Query Output  */
                                                 /* Structure                 */
   char                                *piLocalMessageFile; /* Message File   */
} db2LoadQueryStruct64;

/******************************************************************************
** db2LoadQuery API
** Checks the status of a load operation during processing.
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
** db2ApiDf.h
** 
** db2LoadQuery API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2LoadQueryStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** This API reads the status of the load operation on the table specified
** by piString, and writes the status to the file specified by
** pLocalMsgFileName.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Load Query                */
  db2LoadQuery (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Generic Load Query Parameter Structure                                     */
/******************************************************************************
** db2gLoadQueryStruct data structure
** db2gLoadQueryStruct data structure specific parameters
** 
** iStringLen
** Input. Specifies the length in bytes of piString parameter.
** 
** iLocalMessageFileLen
** Input. Specifies the length in bytes of piLocalMessageFile
** parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gLoadQueryStruct
{
   db2Uint32                           iStringType; /* Type of piString       */
   db2Uint32                           iStringLen; /* Length in bytes of      */
                                                 /* piString                  */
   char                                *piString; /* Name to query            */
   db2Uint32                           iShowLoadMessages; /* Level of Load    */
                                                 /* message reporting         */
   struct db2LoadQueryOutputStruct     *poOutputStruct; /* Load Query Output  */
                                                 /* Structure                 */
   db2Uint32                           iLocalMessageFileLen; /* Length in     */
                                                 /* bytes of message file     */
                                                 /* variable                  */
   char                                *piLocalMessageFile; /* Message File   */
} db2gLoadQueryStruct;

/* Generic Load Query Parameter Structure - 64 bit counters                   */
/******************************************************************************
** db2gLoadQueryStru64 data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gLoadQueryStru64
{
   db2Uint32                           iStringType; /* Type of piString       */
   db2Uint32                           iStringLen; /* Length in bytes of      */
                                                 /* piString                  */
   char                                *piString; /* Name to query            */
   db2Uint32                           iShowLoadMessages; /* Level of Load    */
                                                 /* message reporting         */
   struct db2LoadQueryOutputStruct64   *poOutputStruct; /* Load Query Output  */
                                                 /* Structure                 */
   db2Uint32                           iLocalMessageFileLen; /* Length in     */
                                                 /* bytes of message file     */
                                                 /* variable                  */
   char                                *piLocalMessageFile; /* Message File   */
} db2gLoadQueryStru64;

/******************************************************************************
** db2gLoadQuery API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Generic Load Query        */
  db2gLoadQuery (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** Common Structures and Constants for Data Movement Utilities
*******************************************************************************/

/* Definitions for piXmlParse value                                           */
#define DB2DMU_XMLPARSE_PRESERVE_WS    1         /* Preserve whitespace       */
#define DB2DMU_XMLPARSE_STRIP_WS       2         /* Strip whitespace          */

/* Definitions for iUsing value of db2DMUXmlValidate structure                */
#define DB2DMU_XMLVAL_XDS              1         /* Use XDS                   */
#define DB2DMU_XMLVAL_SCHEMA           2         /* Use a specified schema    */
#define DB2DMU_XMLVAL_SCHEMALOC_HINTS  3         /* Use schemaLocation hints  */

/* MAP structure for XMLVALIDATE USING XDS                                    */
/******************************************************************************
** db2DMUXmlMapSchema data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2DMUXmlMapSchema
{
   struct db2Char                      iMapFromSchema; /* Schema to map FROM  */
   struct db2Char                      iMapToSchema; /* Schema to map TO      */
} db2DMUXmlMapSchema;

/* XML Validate USING XDS structure                                           */
/******************************************************************************
** db2DMUXmlValidate data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2DMUXmlValidateXds
{
   struct db2Char                      *piDefaultSchema; /* DEFAULT schema    */
                                                 /* when using XDS            */
   db2Uint32                           iNumIgnoreSchemas; /* Number of        */
                                                 /* schemas to ignore when    */
                                                 /* using XDS                 */
   struct db2Char                      *piIgnoreSchemas; /* Schemas to        */
                                                 /* ignore when using XDS     */
   db2Uint32                           iNumMapSchemas; /* Number of schemas   */
                                                 /* to map when using XDS     */
   struct db2DMUXmlMapSchema           *piMapSchemas; /* Schemas to map when  */
                                                 /* using XDS                 */
} db2DMUXmlValidateXds;

/* XML Validate USING SCHEMA structure                                        */
typedef SQL_STRUCTURE db2DMUXmlValidateSchema
{
   struct db2Char                      *piSchema; /* Schema to use for        */
                                                 /* validation                */
} db2DMUXmlValidateSchema;

/* XML Validate structure                                                     */
typedef SQL_STRUCTURE db2DMUXmlValidate
{
   db2Uint16                           iUsing;   /* What to use to perform    */
                                                 /* validation                */
   struct db2DMUXmlValidateXds         *piXdsArgs; /* Arguments for           */
                                                 /* XMLVALIDATE USING XDS     */
   struct db2DMUXmlValidateSchema      *piSchemaArgs; /* Arguments for        */
                                                 /* XMLVALIDATE USING SCHEMA  */
} db2DMUXmlValidate;

/* SourceUserExit structure                                                   */
typedef SQL_STRUCTURE db2LoadUserExit
{
   db2Char                             iSourceUserExitCmd; /* SourceUserExit  */
                                                 /* Command                   */
   struct db2Char                      *piInputStream; /* Stdin redirect      */
                                                 /* from buffer for           */
                                                 /* iSourceUserExitCmd        */
   struct db2Char                      *piInputFileName; /* Stdin redirect    */
                                                 /* from file to              */
                                                 /* iSourceUserExitCmd        */
   struct db2Char                      *piOutputFileName; /* Stdout/stderr    */
                                                 /* redirect to file for      */
                                                 /* iSourceUserExitCmd        */
   db2Uint16                           *piEnableParallelism; /* Enable        */
                                                 /* Parallelism for           */
                                                 /* SourceUserExit cmd        */
} db2LoadUserExit;

/* Load Structures and Constants                                              */

/* General db2Load constants                                                  */
#define DB2LOAD_MAX_HOSTNAME_SZ        255       /* Max size of               */
                                                 /* db2PartLoadIn -           */
                                                 /* iHostName                 */
#define DB2LOAD_MAX_FILETRANSFERCMD_SZ 1023      /* Max size of               */
                                                 /* db2PartLoadIn -           */
                                                 /* iFileTransferCmd          */
#define DB2LOAD_MAX_USEREXITCMD_SZ     1023      /* Max size of               */
                                                 /* db2LoadUserExit -         */
                                                 /* iSourceUserExitCmd        */
#define DB2LOAD_MAX_PATH_SZ            1023      /* Max size of Load path     */
                                                 /* strings                   */

/* Load input structure                                                       */
/******************************************************************************
** db2LoadIn data structure
** db2LoadIn data structure parameters
** 
** iRowcount
** Input. The number of physical records to be loaded. Allows a user to load
** only the first rowcnt rows in a file.
** 
** iRestartcount
** Input. Reserved for future use.
** 
** piUseTablespace
** Input. If the indexes are being rebuilt, a shadow copy of the index is built
** in tablespace iUseTablespaceName and copied over to the original
** tablespace at the end of the load. Only system temporary table spaces
** can be used with this option. If not specified then the shadow index will
** be created in the same tablespace as the index object.
** 
** If the shadow copy is created in the same tablespace as the index
** object, the copy of the shadow index object over the old index object is
** instantaneous. If the shadow copy is in a different tablespace from the
** index object a physical copy is performed. This could involve
** considerable I/O and time. The copy happens while the table is offline at
** the end of a load.
** 
** This field is ignored if iAccessLevel is SQLU_ALLOW_NO_ACCESS.
** 
** This option is ignored if the user does not specify INDEXING MODE
** REBUILD or INDEXING MODE AUTOSELECT. This option will also be
** ignored if INDEXING MODE AUTOSELECT is chosen and load chooses
** to incrementally update the index.
** 
** iSavecount
** The number of records to load before establishing a consistency point.
** This value is converted to a page count, and rounded up to intervals of the
** extent size. Since a message is issued at each consistency point, this
** option should be selected if the load operation will be monitored using
** db2LoadQuery - Load Query. If the value of savecnt is not sufficiently
** high, the synchronization of activities performed at each consistency
** point will impact performance.
** 
** The default value is 0, meaning that no consistency points will be
** established, unless necessary.
** 
** iDataBufferSize
** The number of 4KB pages (regardless of the degree of parallelism) to use
** as buffered space for transferring data within the utility. If the value
** specified is less than the algorithmic minimum, the required minimum is
** used, and no warning is returned.
** 
** This memory is allocated directly from the utility heap, whose size can
** be modified through the util_heap_sz database configuration parameter.
** 
** If a value is not specified, an intelligent default is calculated by the
** utility at run time. The default is based on a percentage of the free
** space available in the utility heap at the instantiation time of the
** loader, as well as some characteristics of the table.
** 
** iSortBufferSize
** Input. This option specifies a value that overrides the SORTHEAP
** database configuration parameter during a load operation. It is relevant
** only when loading tables with indexes and only when the iIndexingMode
** parameter is not specified as SQLU_INX_DEFERRED. The value that is
** specified cannot exceed the value of SORTHEAP. This parameter is
** useful for throttling the sort memory used by LOAD without changing the
** value of SORTHEAP, which would also affect general query processing.
** 
** iWarningcount
** Input. Stops the load operation after warningcnt warnings. Set this
** parameter if no warnings are expected, but verification that the correct file
** and table are being used is desired. If the load file or the target table is
** specified incorrectly, the load utility will generate a warning for each row
** that it attempts to load, which will cause the load to fail. If warningcnt is
** 0, or this option is not specified, the load operation will continue
** regardless of the number of warnings issued.
** 
** If the load operation is stopped because the threshold of warnings was
** exceeded, another load operation can be started in RESTART mode. The
** load operation will automatically continue from the last consistency point.
** Alternatively, another load operation can be initiated in REPLACE mode,
** starting at the beginning of the input file.
** 
** iHoldQuiesce
** Input. A flag whose value is set to TRUE if the utility is to leave the
** table in quiesced exclusive state after the load, and to FALSE if it is
** not.
** 
** iCpuParallelism
** Input. The number of processes or threads that the load utility will spawn
** for parsing, converting and formatting records when building table objects.
** This parameter is designed to exploit intra-partition parallelism. It is
** particularly useful when loading presorted data, because record order in
** the source data is preserved. If the value of this parameter is zero, the
** load utility uses an intelligent default value at run time. Note: If this
** parameter is used with tables containing either LOB or LONG VARCHAR
** fields, its value becomes one, regardless of the number of system CPUs,
** or the value specified by the user.
** 
** iDiskParallelism
** Input. The number of processes or threads that the load utility will spawn
** for writing data to the table space containers. If a value is not specified,
** the utility selects an intelligent default based on the number of table
** space containers and the characteristics of the table.
** 
** iNonrecoverable
** Input. Set to SQLU_NON_RECOVERABLE_LOAD if the load transaction
** is to be marked as non-recoverable, and it will not be possible to recover
** it by a subsequent roll forward action. The rollforward utility will skip the
** transaction, and will mark the table into which data was being loaded as
** "invalid". The utility will also ignore any subsequent transactions against
** that table. After the roll forward is completed, such a table can only be
** dropped. With this option, table spaces are not put in backup pending
** state following the load operation, and a copy of the loaded data does not
** have to be made during the load operation. Set to
** SQLU_RECOVERABLE_LOAD if the load transaction is to be marked as
** recoverable. 
** 
** iIndexingMode
** Input. Specifies the indexing mode. Valid values (defined in sqlutil header
** file, located in the include directory) are:
** - SQLU_INX_AUTOSELECT
** LOAD chooses between REBUILD and INCREMENTAL indexing
** modes.
** - SQLU_INX_REBUILD
** Rebuild table indexes.
** - SQLU_INX_INCREMENTAL
** Extend existing indexes.
** - SQLU_INX_DEFERRED
** Do not update table indexes.
** 
** iAccessLevel
** Input. Specifies the access level. Valid values are:
** - SQLU_ALLOW_NO_ACCESS
** Specifies that the load locks the table exclusively.
** - SQLU_ALLOW_READ_ACCESS
** Specifies that the original data in the table (the non-delta portion)
** should still be visible to readers while the load is in progress. This
** option is only valid for load appends, such as a load insert, and will be
** ignored for load replace.
** 
** iLockWithForce
** Input. A boolean flag. If set to TRUE load will force other applications as
** necessary to ensure that it obtains table locks immediately. This option
** requires the same authority as the FORCE APPLICATIONS command
** (SYSADM or SYSCTRL).
** 
** SQLU_ALLOW_NO_ACCESS loads may force conflicting applications at
** the start of the load operation. At the start of the load the utility may
** force applications that are attempting to either query or modify the
** table.
** 
** SQLU_ALLOW_READ_ACCESS loads may force conflicting applications
** at the start or end of the load operation. At the start of the load the load
** utility may force applications that are attempting to modify the table. At
** the end of the load the load utility may force applications that are
** attempting to either query or modify the table.
** 
** iCheckPending
** This parameter is deprecated and might be removed in a future release.
** Use the iSetIntegrityPending parameter instead.
** 
** iRestartphase
** Input. Reserved. Valid value is a single space character ' '. 
** 
** iStatsOpt
** Input. Granularity of statistics to collect. Valid values are:
** - SQLU_STATS_NONE
** No statistics to be gathered.
** - SQLU_STATS_USE_PROFILE
** Statistics are collected based on the profile defined for the current
** table. This profile must be created using the RUNSTATS command. If
** no profile exists for the current table, a warning is returned and no
** statistics are collected.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadIn
{
   db2Uint64                           iRowcount; /* Row count                */
   db2Uint64                           iRestartcount; /* Restart count        */
   char                                *piUseTablespace; /* Alternative       */
                                                 /* Tablespace to rebuild     */
                                                 /* index                     */
   db2Uint32                           iSavecount; /* Save count              */
   db2Uint32                           iDataBufferSize; /* Data buffer        */
   db2Uint32                           iSortBufferSize; /* Sort buffer (for   */
                                                 /* vendor load sort)         */
   db2Uint32                           iWarningcount; /* Warning count        */
   db2Uint16                           iHoldQuiesce; /* Hold quiesce between  */
                                                 /* loads                     */
   db2Uint16                           iCpuParallelism; /* CPU parallelism    */
   db2Uint16                           iDiskParallelism; /* Disk parallelism  */
   db2Uint16                           iNonrecoverable; /* Non-recoverable    */
                                                 /* load                      */
   db2Uint16                           iIndexingMode; /* Indexing mode        */
   db2Uint16                           iAccessLevel; /* Access Level          */
   db2Uint16                           iLockWithForce; /* Lock With Force     */
   db2Uint16                           iCheckPending; /* Depricated Check     */
                                                 /* Pending Option            */
   char                                iRestartphase; /* Restart phase        */
   char                                iStatsOpt; /* Statistics option        */
   db2Uint16                           iSetIntegrityPending; /* Set           */
                                                 /* Integrity Pending Option  */
   struct db2LoadUserExit              *piSourceUserExit; /* SourceUserExit   */
   db2Uint16                           *piXmlParse; /* XML parsing            */
   struct db2DMUXmlValidate            *piXmlValidate; /* XML validation      */
} db2LoadIn;

/* Load output structure                                                      */
/******************************************************************************
** db2LoadOut data structure
** db2LoadOut data structure parameters
** 
** oRowsRead
** Output. Number of records read during the load operation.
** 
** oRowsSkipped
** Output. Number of records skipped before the load operation begins.
** 
** oRowsLoaded
** Output. Number of rows loaded into the target table.
** 
** oRowsRejected
** Output. Number of records that could not be loaded.
** 
** oRowsDeleted
** Output. Number of duplicate rows deleted.
** 
** oRowsCommitted
** Output. The total number of processed records: the number of records loaded
** successfully and committed to the database, plus the number of skipped and
** rejected records.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadOut
{
   db2Uint64                           oRowsRead; /* Number of rows read      */
   db2Uint64                           oRowsSkipped; /* Number of rows        */
                                                 /* skipped                   */
   db2Uint64                           oRowsLoaded; /* Number of rows loaded  */
   db2Uint64                           oRowsRejected; /* Number of rows       */
                                                 /* rejected                  */
   db2Uint64                           oRowsDeleted; /* Number of rows        */
                                                 /* deleted                   */
   db2Uint64                           oRowsCommitted; /* Number of rows      */
                                                 /* committed                 */
} db2LoadOut;

/*                                                                            */
/* Partitioned Load structures and constants. These structures are only       */
/* needed when loading into partitioned databases                             */
/*                                                                            */

/* Load node list structure                                                   */
/******************************************************************************
** db2LoadNodeList data structure
** db2LoadNodeList data structure parameters
** 
** piNodeList
** Input. An array of node numbers.
** 
** iNumNodes
** Input. The number of database partitions in the piNodeList array. 
** A 0 indicates the default, which is all nodes on which the target 
** table is defined.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadNodeList
{
   SQL_PDB_NODE_TYPE                   *piNodeList; /* Array of database      */
                                                 /* partitions                */
   db2Uint16                           iNumNodes; /* Number of database       */
                                                 /* partitions                */
} db2LoadNodeList;

/* Load port range structure                                                  */
/******************************************************************************
** db2LoadPortRange data structure
** db2LoadPortRange data structure parameters
** 
** iPortMin
** Input. Lower port number.
** 
** iPortMax
** Input. Higher port number.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadPortRange
{
   db2Uint16                           iPortMin; /* Minimum port number       */
   db2Uint16                           iPortMax; /* Maximum port number       */
} db2LoadPortRange;

/* Possible values for db2PartLoadInfoIn - iMode                              */
#define DB2LOAD_PARTITION_AND_LOAD     0         /* Partition and Load mode   */
#define DB2LOAD_PARTITION_ONLY         1         /* Partition only mode       */
#define DB2LOAD_LOAD_ONLY              2         /* Load only mode            */
#define DB2LOAD_LOAD_ONLY_VERIFY_PART  3         /* Load file with no         */
                                                 /* partition header          */
#define DB2LOAD_ANALYZE                4         /* Generate optimal          */
                                                 /* partition map             */

/* Possible values for db2PartLoadInfoIn - iIsolatePartErrs                   */
#define DB2LOAD_SETUP_ERRS_ONLY        0         /* Setup errors only         */
#define DB2LOAD_LOAD_ERRS_ONLY         1         /* Load errors only          */
#define DB2LOAD_SETUP_AND_LOAD_ERRS    2         /* Setup and Load errors     */
#define DB2LOAD_NO_ISOLATION           3         /* No partition error        */
                                                 /* isolation                 */

/* Partitioned Load input structure                                           */
/*   -- assign NULL to a field to indicate default value is desired           */
/******************************************************************************
** db2PartLoadIn data structure
** db2PartLoadIn data structure parameters
** 
** piHostname
** Input. The hostname for the iFileTransferCmd parameter. If NULL, the hostname
** will default to "nohost". 
** 
** piFileTransferCmd
** Input. File transfer command parameter. If not required, it must be set
** to NULL. See the Data Movement Guide for a full description of this
** parameter.
** 
** piPartFileLocation
** Input. In PARTITION_ONLY, LOAD_ONLY, and LOAD_ONLY_VERIFY_PART
** modes, this parameter can be used to specify the location of the partitioned
** files. This location must exist on each database partition specified by the
** piOutputNodes option.
** 
** For the SQL_CURSOR file type, this parameter cannot be NULL and the
** location does not refer to a path, but to a fully qualified file name.
** This will be the fully qualified base file name of the partitioned files
** that are created on each output database partition for PARTITION_ONLY mode,
** or the location of the files to be read from each database partition for
** LOAD_ONLY mode. For PARTITION_ONLY mode, multiple files may be created
** with the specified base name if there are LOB columns in the target table.
** For file types other than SQL_CURSOR, if the value of this parameter is
** NULL, it will default to the current directory.
** 
** piOutputNodes
** Input. The list of Load output database partitions. A NULL indicates that
** all database partitions on which the target table is defined.
** 
** piPartitioningNodes
** Input. The list of partitioning database partitions. A NULL indicates the
** default. Refer to the Load command in the Data Movement Guide and Reference
** for a description of how the default is determined.
** 
** piMode
** Input. Specifies the load mode for partitioned databases. Valid values
** (defined in db2ApiDf header file, located in the include directory) are:
** 
** - DB2LOAD_PARTITION_AND_LOAD
** Data is distributed (perhaps in parallel) and loaded simultaneously on
** the corresponding database partitions.
** 
** - DB2LOAD_PARTITION_ONLY
** Data is distributed (perhaps in parallel) and the output is written to files
** in a specified location on each loading database partition. For file types
** other than SQL_CURSOR, the name of the output file on each database
** partition will have the form filename.xxx, where filename is the name of
** the first input file specified by piSourceList and xxx is the database
** partition number.For the SQL_CURSOR file type, the name of the output file
** on each database partition will be determined by the piPartFileLocation
** parameter. Refer to the piPartFileLocation parameter for information about
** how to specify the location of the database partition file on each
** database partition.
** Note:
** This mode cannot be used for a CLI LOAD.
** 
** - DB2LOAD_LOAD_ONLY
** Data is assumed to be already distributed; the distribution process is
** skipped, and the data is loaded simultaneously on the corresponding
** database partitions. For file types other than SQL_CURSOR, the input
** file name on each database partition is expected to be of the form
** filename.xxx, where filename is the name of the first file specified
** by piSourceList and xxx is the 13-digit database partition number.
** For the SQL_CURSOR file type, the name of the input file on each
** database partition will be determined by the piPartFileLocation
** parameter. Refer to the piPartFileLocation parameter for information
** about how to specify the location of the database partition file on
** each database partition.
** Note:
** This mode cannot be used when loading a data file located on a
** remote client, nor can it be used for a CLI LOAD.
** 
** - DB2LOAD_LOAD_ONLY_VERIFY_PART
** Data is assumed to be already distributed, but the data file does not
** contain a database partition header. The distribution process is
** skipped, and the data is loaded simultaneously on the corresponding
** database partitions. During the load operation, each row is checked to
** verify that it is on the correct database partition. Rows containing
** database partition violations are placed in a dumpfile if the dumpfile
** file type modifier is specified. Otherwise, the rows are discarded. If
** database partition violations exist on a particular loading database
** partition, a single warning will be written to the load message file for
** that database partition. The input file name on each database partition
** is expected to be of the form filename.xxx, where filename is the name
** of the first file specified by piSourceList and xxx is the 13-digit
** database partition number.
** Note:
** This mode cannot be used when loading a data file located on a remote client,
** nor can it be used for a CLI LOAD.
** 
** - DB2LOAD_ANALYZE
** An optimal distribution map with even distribution across all database
** partitions is generated.
** 
** piMaxNumPartAgents
** Input. The maximum number of partitioning agents. A NULL value indicates the
** default, which is 25.
** 
** piIsolatePartErrs
** Input. Indicates how the load operation will react to errors that occur on
** individual database partitions. Valid values (defined in db2ApiDf header
** file, located in the include directory) are:
** 
** - DB2LOAD_SETUP_ERRS_ONLY
** In this mode, errors that occur on a database partition during setup, such
** as problems accessing a database partition or problems accessing a table
** space or table on a database partition, will cause the load operation to
** stop on the failing database partitions but to continue on the remaining
** database partitions. Errors that occur on a database partition while data
** is being loaded will cause the entire operation to fail and rollback to
** the last point of consistency on each database partition.
** 
** - DB2LOAD_LOAD_ERRS_ONLY
** In this mode, errors that occur on a database partition during setup
** will cause the entire load operation to fail. When an error occurs while
** data is being loaded, the database partitions with errors will be rolled
** back to their last point of consistency. The load operation will
** continue on the remaining database partitions until a failure occurs or
** until all the data is loaded. On the database partitions where all of the
** data was loaded, the data will not be visible following the load operation.
** Because of the errors in the other database partitions the transaction will
** be aborted. Data on all of the database partitions will remain invisible
** until a load restart operation is performed. This will make the newly
** loaded data visible on the database partitions where the load operation
** completed and resume the load operation on database partitions that
** experienced an error.
** Note:
** This mode cannot be used when iAccessLevel is set to SQLU_ALLOW_READ_ACCESS
** and a copy target is also specified.
** 
** - DB2LOAD_SETUP_AND_LOAD_ERRS
** In this mode, database partition-level errors during setup or loading data
** cause processing to stop only on the affected database partitions. As with
** the DB2LOAD_LOAD_ERRS_ONLY mode, when database partition errors do occur
** while data is being loaded, the data on all database partitions will
** remain invisible until a load restart operation is performed.
** 
** Note:
** This mode cannot 1be used when iAccessLevel is set to SQLU_ALLOW_READ_ACCESS
** and a copy target is also specified.
** 
** - DB2LOAD_NO_ISOLATION
** Any error during the Load operation causes the transaction to be aborted.
** If this parameter is NULL, it will default to DB2LOAD_LOAD_ERRS_ONLY, unless
** iAccessLevel is set to SQLU_ALLOW_READ_ACCESS and a copy target is also
** specified, in which case the default is DB2LOAD_NO_ISOLATION.
** 
** piStatusInterval
** Input. Specifies the number of megabytes (MB) of data to load before
** generating a progress message. Valid values are whole numbers in the
** range of 1 to 4000. If NULL is specified, a default value of 100 will
** be used.
** 
** piPortRange
** Input. The TCP port range for internal communication. If NULL, the port range
** used will be 6000-6063.
** 
** piCheckTruncation
** Input. Causes Load to check for record truncation at Input/Output. Valid
** values are TRUE and FALSE. If NULL, the default is FALSE.
** 
** piMapFileInput
** Input. Distribution map input filename. If the mode is not ANALYZE, this
** parameter should be set to NULL. If the mode is ANALYZE, this parameter
** must be specified.
** 
** piMapFileOutput
** Input. Distribution map output filename. The rules for piMapFileInput apply
** here as well.
** 
** piTrace
** Input. Specifies the number of records to trace when you need to review
** a dump of all the data conversion process and the output of hashing
** values. If NULL, the number of records defaults to 0.
** 
** piNewline
** Input. Forces Load to check for newline characters at end of ASC data records
** if RECLEN file type modifier is also specified. Possible values are TRUE and
** FALSE. If NULL, the value defaults to FALSE.
** 
** piDistfile
** Input. Name of the database partition distribution file. If a NULL is
** specified, the value defaults to "DISTFILE". 
** 
** piOmitHeader
** Input. Indicates that a distribution map header should not be included in the
** database partition file when using DB2LOAD_PARTITION_ONLY mode. Possible
** values are TRUE and FALSE. If NULL, the default is FALSE.
** 
** piRunStatDBPartNum
** Specifies the database partition on which to collect statistics. The default
** value is the first database partition in the output database partition list.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2PartLoadIn
{
   char                                *piHostname; /* Hostname for           */
                                                 /* iFileTransferCmd          */
                                                 /* parameter                 */
   char                                *piFileTransferCmd; /* File transfer   */
                                                 /* command                   */
   char                                *piPartFileLocation; /* Partition      */
                                                 /* file location             */
   struct db2LoadNodeList              *piOutputNodes; /* Output nodes        */
   struct db2LoadNodeList              *piPartitioningNodes; /* Partitioning  */
                                                 /* database partitions       */
   db2Uint16                           *piMode;  /* Partitioned Load mode     */
   db2Uint16                           *piMaxNumPartAgents; /* Max number of  */
                                                 /* partitioning agents       */
   db2Uint16                           *piIsolatePartErrs; /* Partition       */
                                                 /* error isolation mode      */
   db2Uint16                           *piStatusInterval; /* Status report    */
                                                 /* interval                  */
   struct db2LoadPortRange             *piPortRange; /* Port number range     */
   db2Uint16                           *piCheckTruncation; /* Check for       */
                                                 /* record truncation         */
   char                                *piMapFileInput; /* Map file input     */
   char                                *piMapFileOutput; /* Map file output   */
   db2Uint16                           *piTrace; /* Number of records to      */
                                                 /* trace                     */
   db2Uint16                           *piNewline; /* Check for newlines at   */
                                                 /* end of ASC records        */
   char                                *piDistfile; /* Partition              */
                                                 /* distribution output file  */
   db2Uint16                           *piOmitHeader; /* Don't generate       */
                                                 /* partition header in       */
                                                 /* output file               */
   SQL_PDB_NODE_TYPE                   *piRunStatDBPartNum; /* runstat        */
                                                 /* database partition        */
} db2PartLoadIn;

/* Possible values for db2LoadAgentInfo - oAgentType                          */
#define DB2LOAD_LOAD_AGENT             0         /* Load agent (one per       */
                                                 /* output database           */
                                                 /* partition, not used for   */
                                                 /* PARTITION_ONLY and        */
                                                 /* ANALYZE modes)            */
#define DB2LOAD_PARTITIONING_AGENT     1         /* Partitioning agent (one   */
                                                 /* per partitioning          */
                                                 /* database partition, not   */
                                                 /* used for LOAD_ONLY and    */
                                                 /* LOAD_ONLY_VERIFY_PART     */
                                                 /* modes)                    */
#define DB2LOAD_PRE_PARTITIONING_AGENT 2         /* Pre-partitioning agent    */
                                                 /* (one at coordinator       */
                                                 /* database partition, not   */
                                                 /* used for LOAD_ONLY and    */
                                                 /* LOAD_ONLY_VERIFY_PART     */
                                                 /* modes)                    */
#define DB2LOAD_FILE_TRANSFER_AGENT    3         /* File transfer agent       */
                                                 /* (only for FILE_TRANSFER   */
                                                 /* CMD option)               */
#define DB2LOAD_LOAD_TO_FILE_AGENT     4         /* For PARTITION_ONLY mode   */
                                                 /* (one per output database  */
                                                 /* partition)                */

/* Load agent info structure.  Load will generate an agent info structure     */
/* for each agent working on behalf of the Load command                       */
/******************************************************************************
** db2LoadAgentInfo data structure
** db2LoadAgentInfo data structure parameters
** 
** oSqlcode
** Output. The final sqlcode resulting from the agent's processing.
** 
** oTableState
** Output. The purpose of this output parameter is not to report every possible
** state of the table after the load operation. Rather, its purpose is to report
** only a small subset of possible tablestates in order to give the caller a
** general idea of what happened to the table during load processing. This value
** is relevant for load agents only. The possible values are:
** 
** - DB2LOADQUERY_NORMAL
** Indicates that the load completed successfully on the database partition and
** the table was taken out of the LOAD IN PROGRESS (or LOAD PENDING) state. In
** this case, the table still could be in CHECK PENDING state due to the need
** for further constraints processing, but this will not reported as this is
** normal. 
** 
** - DB2LOADQUERY_UNCHANGED
** Indicates that the load job aborted processing due to an error but did
** not yet change the state of the table on the database partition from
** whatever state it was in prior to calling db2Load. It is not necessary to
** perform a load restart or terminate operation on such database partitions.
** 
** - DB2LOADQUERY_LOADPENDING
** Indicates that the load job aborted during processing but left the table
** on the database partition in the LOAD PENDING state, indicating that the
** load job on that database partition must be either terminated or restarted.
** 
** oNodeNum
** Output. The number of the database partition on which the agent executed.
** 
** oAgentType
** Output. The agent type. Valid values (defined in db2ApiDf header file,
** located in the include directory) are :
** - DB2LOAD_LOAD_AGENT
** - DB2LOAD_PARTITIONING_AGENT
** - DB2LOAD_PRE_PARTITIONING_AGENT
** - DB2LOAD_FILE_TRANSFER_AGENT
** - DB2LOAD_LOAD_TO_FILE_AGENT
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadAgentInfo
{
   db2int32                            oSqlcode; /* Agent sqlcode             */
   db2Uint32                           oTableState; /* Table state (only      */
                                                 /* relevant for agents of    */
                                                 /* type DB2LOAD_LOAD_AGENT)  */
   SQL_PDB_NODE_TYPE                   oNodeNum; /* database partition on     */
                                                 /* which agent executed      */
   db2Uint16                           oAgentType; /* Agent type (see above   */
                                                 /* for possible values)      */
} db2LoadAgentInfo;

/* Partitioned Load output structure                                          */
/******************************************************************************
** db2PartLoadOut data structure
** db2PartLoadOut data structure parameters
** 
** oRowsRdPartAgents
** Output. Total number of rows read by all partitioning agents.
** 
** oRowsRejPartAgents
** Output. Total number of rows rejected by all partitioning agents.
** 
** oRowsPartitioned
** Output. Total number of rows partitioned by all partitioning agents.
** 
** poAgentInfoList
** Output. During a load operation into a partitioned database, the following
** load processing entities may be involved: load agents, partitioning agents,
** pre-partitioing agents, file transfer command agents and load-to-file agents
** (these are described in the Data Movement Guide). The purpose of the
** poAgentInfoList output parameter is to return to the caller information about
** each load agent that participated in a load operation. Each entry in the list
** contains the following information:
** - oAgentType. A tag indicating what kind of load agent the entry describes.
** - oNodeNum. The number of the database partition on which the agent executed.
** - oSqlcode. The final sqlcode resulting from the agent's processing.
** - oTableState. The final status of the table on the database partition on
** which the agent executed (relevant only for load agents).
** It is up to the caller of the API to allocate memory for this list prior to
** calling the API. The caller should also indicate the number of entries for
** which they allocated memory in the iMaxAgentInfoEntries parameter. If the
** caller sets poAgentInfoList to NULL or sets iMaxAgentInfoEntries to 0,
** then no information will be returned about the load agents. 
** 
** iMaxAgentInfoEntries
** Input. The maximum number of agent information entries allocated by the user
** for poAgentInfoList. In general, setting this parameter to 3 times the number
** of database partitions involved in the load operation should be sufficient.
** 
** oNumAgentInfoEntries
** Output. The actual number of agent information entries produced by the load
** operation. This number of entries will be returned to the user in the
** poAgentInfoList parameter as long as iMaxAgentInfoEntries is greater than
** or equal to oNumAgentInfoEntries. If iMaxAgentInfoEntries is less than
** oNumAgentInfoEntries, then the number of entries returned in poAgentInfoList
** is equal to iMaxAgentInfoEntries.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2PartLoadOut
{
   db2Uint64                           oRowsRdPartAgents; /* Rows read by     */
                                                 /* partitioning agents       */
   db2Uint64                           oRowsRejPartAgents; /* Rows rejected   */
                                                 /* by partitioning agents    */
   db2Uint64                           oRowsPartitioned; /* Rows partitioned  */
                                                 /* by partitioning agents    */
   struct db2LoadAgentInfo             *poAgentInfoList; /* Node output info  */
                                                 /* list                      */
   db2Uint32                           iMaxAgentInfoEntries; /* Max number    */
                                                 /* of agent info entries     */
                                                 /* allocated by user for     */
                                                 /* poAgentInfoList. This     */
                                                 /* should at least include   */
                                                 /* space for the             */
                                                 /* partitioning agents,      */
                                                 /* load agents, and one pre  */
                                                 /* partitioning agent        */
   db2Uint32                           oNumAgentInfoEntries; /* Number of     */
                                                 /* agent info entries        */
                                                 /* produced by load.  The    */
                                                 /* number of entries in      */
                                                 /* poAgentInfoList is        */
                                                 /* min(iMaxAgentInfoEntries  */
                                                 /*  oNumAgentInfoEntries).   */
} db2PartLoadOut;

/*                                                                            */
/* db2Load parameter structure                                                */
/*   -- For non-partitioned database loads, set piLoadInfoIn and              */
/* poLoadInfoOut to NULL                                                      */
/*   -- For partitioned database loads, set piLoadInfoIn to NULL to request   */
/* default values for all partitioned database load options                   */
/*                                                                            */
/******************************************************************************
** db2LoadStruct data structure
** db2LoadStruct data structure parameters
** 
** piSourceList
** Input. A pointer to an sqlu_media_list structure used to provide a list of
** source files, devices, vendors, pipes, or SQL statements.
** 
** The information provided in this structure depends on the value of the
** media_type field. Valid values (defined in sqlutil header file, located
** in the include directory) are:
** 
** - SQLU_SQL_STMT
** If the media_type field is set to this value, the caller provides an SQL
** query through the pStatement field of the target field. The pStatement
** field is of type sqlu_statement_entry. The sessions field must be set to
** the value of 1, since the load utility only accepts a single SQL query
** per load.
** 
** - SQLU_SERVER_LOCATION
** If the media_type field is set to this value, the caller provides
** information through sqlu_location_entry structures. The sessions field
** indicates the number of sqlu_location_entry structures provided. This
** is used for files, devices, and named pipes.
** 
** - SQLU_CLIENT_LOCATION
** If the media_type field is set to this value, the caller provides
** information through sqlu_location_entry structures. The sessions field
** indicates the number of sqlu_location_entry structures provided. This
** is used for fully qualified files and named pipes. Note that this
** media_type is only valid if the API is being called via a remotely
** connected client.
** 
** - SQLU_TSM_MEDIA
** If the media_type field is set to this value, the sqlu_vendor structure is
** used, where filename is the unique identifier for the data to be loaded.
** There should only be one sqlu_vendor entry, regardless of the value of
** sessions. The sessions field indicates the number of TSM sessions to
** initiate. The load utility will start the sessions with different sequence
** numbers, but with the same data in the one sqlu_vendor entry.
** 
** - SQLU_OTHER_MEDIA
** If the media_type field is set to this value, the sqlu_vendor structure is
** used, where shr_lib is the shared library name, and filename is the
** unique identifier for the data to be loaded. There should only be one
** sqlu_vendor entry, regardless of the value of sessions. The sessions
** field indicates the number of other vendor sessions to initiate. The load
** utility will start the sessions with different sequence numbers, but with
** the same data in the one sqlu_vendor entry.
** 
** piLobPathList
** Input. A pointer to an sqlu_media_list structure. For IXF, ASC, and DEL
** file types, a list of fully qualified paths or devices to identify the
** location of the individual LOB files to be loaded. The file names are
** found in the IXF, ASC, or DEL files, and are appended to the paths
** provided.
** 
** The information provided in this structure depends on the value of the
** media_type field. Valid values (defined in sqlutil header file,
** located in the include directory) are:
** 
** - SQLU_LOCAL_MEDIA
** If set to this value, the caller provides information through
** sqlu_media_entry structures. The sessions field indicates the number
** of sqlu_media_entry structures provided.
** 
** - SQLU_TSM_MEDIA
** If set to this value, the sqlu_vendor structure is used, where filename
** is the unique identifier for the data to be loaded. There should only be
** one sqlu_vendor entry, regardless of the value of sessions. The
** sessions field indicates the number of TSM sessions to initiate. The
** load utility will start the sessions with different sequence numbers, but
** with the same data in the one sqlu_vendor entry.
** 
** - SQLU_OTHER_MEDIA
** If set to this value, the sqlu_vendor structure is used, where shr_lib
** is the shared library name, and filename is the unique identifier for the
** data to be loaded. There should only be one sqlu_vendor entry,
** regardless of the value of sessions. The sessions field indicates the
** number of other vendor sessions to initiate. The load utility will start the
** sessions with different sequence numbers, but with the same data in
** the one sqlu_vendor entry.
** 
** piDataDescriptor
** Input. Pointer to an sqldcol structure containing information about the
** columns being selected for loading from the external file.
** 
** If the pFileType parameter is set to SQL_ASC, the dcolmeth field of this
** structure must either be set to SQL_METH_L or be set to SQL_METH_D and
** specifies a file name with POSITIONSFILE pFileTypeMod modifier which
** contains starting and ending pairs and null indicator positions. The user
** specifies the start and end locations for each column to be loaded.
** 
** If the file type is SQL_DEL, dcolmeth can be either SQL_METH_P or
** SQL_METH_D. If it is SQL_METH_P, the user must provide the source column
** position. If it is SQL_METH_D, the first column in the file is loaded
** into the first column of the table, and so on.
** 
** If the file type is SQL_IXF, dcolmeth can be one of SQL_METH_P, SQL_METH_D,
** or SQL_METH_N. The rules for DEL files apply here, except that SQL_METH_N
** indicates that file column names are to be provided in the sqldcol
** structure.
** 
** piActionString
** Input. Pointer to an sqlchar structure, followed by an array of characters
** specifying an action that affects the table.
** 
** The character array is of the form:
** "INSERT|REPLACE|RESTART|TERMINATE
** INTO tbname [(column_list)]
** [DATALINK SPECIFICATION datalink-spec]
** [FOR EXCEPTION e_tbname]"
** 
** INSERT
** Adds the loaded data to the table without changing the existing table
** data.
** 
** REPLACE
** Deletes all existing data from the table, and inserts the loaded data.
** The table definition and the index definitions are not changed.
** 
** RESTART
** Restarts a previously interrupted load operation. The load operation will
** automatically continue from the last consistency point in the load,
** build, or delete phase.
** 
** TERMINATE
** Terminates a previously interrupted load operation, and rolls back the
** operation to the point in time at which it started, even if consistency
** points were passed. The states of any table spaces involved in the
** operation return to normal, and all table objects are made consistent
** (index objects may be marked as invalid, in which case index rebuild
** will automatically take place at next access). If the table spaces in
** which the table resides are not in load pending state, this option does
** not affect the state of the table spaces.
** 
** The load terminate option will not remove a backup pending state from
** table spaces.
** 
** tbname
** The name of the table into which the data is to be loaded. The table
** cannot be a system table or a declared temporary table. An alias, or
** the fully qualified or unqualified table name can be specified. A qualified
** table name is in the form schema.tablename. If an unqualified table
** name is specified, the table will be qualified with the CURRENT
** SCHEMA.
** 
** (column_list)
** A list of table column names into which the data is to be inserted. The
** column names must be separated by commas. If a name contains
** spaces or lowercase characters, it must be enclosed by quotation
** marks.
** 
** DATALINK SPECIFICATION datalink-spec
** Specifies parameters pertaining to DB2 Data Links. These parameters
** can be specified using the same syntax as in the LOAD command.
** 
** FOR EXCEPTION e_tbname
** Specifies the exception table into which rows in error will be copied.
** Any row that is in violation of a unique index or a primary key index is
** copied. DATALINK exceptions are also captured in the exception table.
** 
** piFileType
** Input. A string that indicates the format of the input data source.
** Supported external formats (defined in sqlutil) are:
** 
** SQL_ASC
** Non-delimited ASCII.
** 
** SQL_DEL
** Delimited ASCII, for exchange with dBase, BASIC, and the IBM
** Personal Decision Series programs, and many other database
** managers and file managers.
** 
** SQL_IXF
** PC version of the Integrated Exchange Format, the preferred method for
** exporting data from a table so that it can be loaded later into the same
** table or into another database manager table.
** 
** SQL_CURSOR
** An SQL query. The sqlu_media_list structure passed in through the
** piSourceList parameter is of type SQLU_SQL_STMT, and refers to an
** actual SQL query and not a cursor declared against one.
** 
** piFileTypeMod
** Input. A pointer to the sqlchar structure, followed by an array of
** characters that specify one or more processing options. If this pointer is
** NULL, or the structure pointed to has zero characters, this action is
** interpreted as selection of a default specification.
** 
** Not all options can be used with all of the supported file types. See
** related link "File type modifiers for the load utility."
** 
** piLocalMsgFileName
** Input. A string containing the name of a local file to which output
** messages are to be written.
** 
** piTempFilesPath
** Input. A string containing the path name to be used on the server for
** temporary files. Temporary files are created to store messages,
** consistency points, and delete phase information.
** 
** piVendorSortWorkPaths
** Input. A pointer to the sqlu_media_list structure which specifies the
** Vendor Sort work directories.
** 
** piCopyTargetList
** Input. A pointer to an sqlu_media_list structure used (if a copy image is
** to be created) to provide a list of target paths, devices, or a shared
** library to which the copy image is to be written.
** 
** The values provided in this structure depend on the value of the
** media_type field. Valid values for this parameter (defined in sqlutil
** header file, located in the include directory) are:
** 
** - SQLU_LOCAL_MEDIA
** If the copy is to be written to local media, set the media_type to this
** value and provide information about the targets in sqlu_media_entry
** structures. The sessions field specifies the number of
** sqlu_media_entry structures provided.
** 
** - SQLU_TSM_MEDIA
** If the copy is to be written to TSM, use this value. No further
** information is required.
** 
** - SQLU_OTHER_MEDIA
** If a vendor product is to be used, use this value and provide further
** information via an sqlu_vendor structure. Set the shr_lib field of this
** structure to the shared library name of the vendor product. Provide only
** one sqlu_vendor entry, regardless of the value of sessions. The
** sessions field specifies the number of sqlu_media_entry structures
** provided. The load utility will start the sessions with different sequence
** numbers, but with the same data provided in the one sqlu_vendor
** entry.
** 
** piNullIndicators
** Input. For ASC files only. An array of integers that indicate whether or not
** the column data is nullable. There is a one-to-one ordered
** correspondence between the elements of this array and the columns
** being loaded from the data file. That is, the number of elements must
** equal the dcolnum field of the pDataDescriptor parameter. Each element
** of the array contains a number identifying a location in the data file
** that is to be used as a NULL indicator field, or a zero indicating that
** the table column is not nullable. If the element is not zero, the
** identified location in the data file must contain a Y or an N. A Y
** indicates that the table column data is NULL, and N indicates that the
** table column data is not NULL.
** 
** piLoadInfoIn
** Input. A pointer to the db2LoadIn structure.
** 
** poLoadInfoOut
** Input. A pointer to the db2LoadOut structure.
** 
** piPartLoadInfoIn
** Input. A pointer to the db2PartLoadIn structure.
** 
** poPartLoadInfoOut
** Output. A pointer to the db2PartLoadOut structure.
** 
** iCallerAction
** Input. An action requested by the caller. Valid values (defined in sqlutil
** header file, located in the include directory)
** are:
** 
** - SQLU_INITIAL
** Initial call. This value (or SQLU_NOINTERRUPT) must be used on the
** first call to the API.
** 
** - SQLU_NOINTERRUPT
** Initial call. Do not suspend processing. This value (or SQLU_INITIAL)
** must be used on the first call to the API.
** 
** If the initial call or any subsequent call returns and requires the calling
** application to perform some action prior to completing the requested load
** operation, the caller action must be set to one of the following:
** 
** - SQLU_CONTINUE
** Continue processing. This value can only be used on subsequent calls
** to the API, after the initial call has returned with the utility requesting
** user input (for example, to respond to an end of tape condition). It
** specifies that the user action requested by the utility has completed,
** and the utility can continue processing the initial request.
** 
** - SQLU_TERMINATE
** Terminate processing. Causes the load utility to exit prematurely,
** leaving the table spaces being loaded in LOAD_PENDING state. This
** option should be specified if further processing of the data is not to be
** done.
** 
** - SQLU_ABORT
** Terminate processing. Causes the load utility to exit prematurely,
** leaving the table spaces being loaded in LOAD_PENDING state. This
** option should be specified if further processing of the data is not to be
** done.
** 
** - SQLU_RESTART
** Restart processing.
** 
** - SQLU_DEVICE_TERMINATE
** Terminate a single device. This option should be specified if the utility
** is to stop reading data from the device, but further processing of the
** data is to be done.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LoadStruct
{
   struct sqlu_media_list              *piSourceList; /* List of input        */
                                                 /* source names (files,      */
                                                 /* pipes, etc.)              */
   struct sqlu_media_list              *piLobPathList; /* Lob file paths      */
   struct sqldcol                      *piDataDescriptor; /* Data descriptor  */
                                                 /* list                      */
   struct sqlchar                      *piActionString; /* Deprecated         */
   char                                *piFileType; /* File type (ASC, DEL,   */
                                                 /* IXF, WSF, etc.)           */
   struct sqlchar                      *piFileTypeMod; /* File type modifier  */
                                                 /* string                    */
   char                                *piLocalMsgFileName; /* Message        */
                                                 /* filename                  */
   char                                *piTempFilesPath; /* Temporary files   */
                                                 /* path                      */
   struct sqlu_media_list              *piVendorSortWorkPaths; /* Vendor      */
                                                 /* Sort work directories     */
   struct sqlu_media_list              *piCopyTargetList; /* List of Load     */
                                                 /* copy targets              */
   db2int32                            *piNullIndicators; /* Null indicators  */
   struct db2LoadIn                    *piLoadInfoIn; /* Load input           */
                                                 /* structure                 */
   struct db2LoadOut                   *poLoadInfoOut; /* Load output         */
                                                 /* structure                 */
   struct db2PartLoadIn                *piPartLoadInfoIn; /* Partitioned      */
                                                 /* Load input structure      */
   struct db2PartLoadOut               *poPartLoadInfoOut; /* Partitioned     */
                                                 /* Load output structure     */
   db2int16                            iCallerAction; /* Caller action        */
   struct sqllob                       *piLongActionString; /* Long Load      */
                                                 /* action string             */
   struct sqlu_media_list              *piXmlPathList; /* XML file paths      */
} db2LoadStruct;

/* db2Load - API                                                              */
/******************************************************************************
** db2Load API
** Loads data into a DB2 table. Data residing on the server may be in the
** form of a file, cursor, tape, or named pipe. Data residing on a remotely
** connected client may be in the form of a fully qualified file, a cursor,
** or named pipe. The load utility does not support loading data at the
** hierarchy level.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - dbadm
** - load authority on the database and
** 
** -- INSERT privilege on the table when the load utility is invoked in
** INSERT mode, TERMINATE mode (to terminate a previous load
** insert operation), or RESTART mode (to restart a previous load insert
** operation)
** 
** -- INSERT and DELETE privilege on the table when the load utility is
** invoked in REPLACE mode, TERMINATE mode (to terminate a
** previous load replace operation), or RESTART mode (to restart a
** previous load replace operation)
** 
** -- INSERT privilege on the exception table, if such a table is used as
** part of the load operation.
** 
** Note:
** In general, all load processes and all DB2 server processes are owned by the
** instance owner. All of these processes use the identification of the instance
** owner to access needed files. Therefore, the instance owner must have read
** access to the input files, regardless of who invokes the command.
** 
** Required connection
** 
** Database. If implicit connect is enabled, a connection to the default
** database is established.
** 
** Instance. An explicit attachment is not required. If a connection to
** the database has been established, an implicit attachment to the local
** instance is attempted.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Load API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2LoadStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Data is loaded in the sequence that appears in the input file. If a
** particular sequence is
** desired, the data should be sorted before a load is attempted.
** 
** The load utility builds indexes based on existing definitions. The
** exception tables are used to handle duplicates on unique keys. The utility
** does not enforce referential integrity, perform constraints checking, or
** update summary tables that are dependent on the tables being loaded.
** Tables that include referential or check constraints are placed in
** check pending state. Summary tables that are defined with REFRESH
** IMMEDIATE, and that are dependent on tables being loaded, are also
** placed in check pending state. Issue the SET INTEGRITY statement to take
** the tables out of check pending state. Load operations cannot be carried
** out on replicated summary tables.
** 
** For clustering indexes, the data should be sorted on the clustering
** index prior to loading. The data need not be sorted when loading into
** an multi-dimensionally clustered (MDC) table.
** 
** DB2 Data Links Manager Considerations
** 
** For each DATALINK column, there can be one column specification within
** parentheses.
** 
** Each column specification consists of one or more of DL_LINKTYPE, prefix
** and a DL_URL_SUFFIX specification. The prefix information can be either
** DL_URL_REPLACE_PREFIX, or the DL_URL_DEFAULT_PREFIX specification.
** 
** There can be as many DATALINK column specifications as the number of DATALINK
** columns defined in the table. The order of specifications follows the order
** of DATALINK columns as found within the insert-column list (if specified by
** INSERT INTO (insert-column, ...)), or within the table definition (if
** insert-column is not specified).
** 
** For example, if a table has columns C1, C2, C3, C4, and C5, and among them
** only columns C2 and C5 are of type DATALINK, and the insert-column list is
** (C1, C5, C3, C2), there should be two DATALINK column specifications. The
** first column specification will be for C5, and the second column
** specification will be for C2. If an insert-column list is not specified,
** the first column specification will be for C2, and the second column
** specification will be for C5.
** 
** If there are multiple DATALINK columns, and some columns do not need
** any particular specification, the column specification should have at
** least the parentheses to unambiguously identify the order of
** specifications. If there are no specifications for any of the columns,
** the entire list of empty parentheses can be dropped. Thus, in cases
** where the defaults are satisfactory, there need not be any DATALINK
** specification.
** 
** If data is being loaded into a table with a DATALINK column that is
** defined with FILE LINK CONTROL, perform the following steps before
** invoking the load utility. (If all the DATALINK columns are defined
** with NO LINK CONTROL, these steps are not necessary).
** 
** 1. Ensure that the DB2 Data Links Manager is installed on the Data Links
** servers that will be referred to by the DATALINK column values.
** 
** 2. Ensure that the database is registered with the DB2 Data Links Manager.
** 
** 3. Copy to the appropriate Data Links servers, all files that will be
** inserted as DATALINK values.
** 
** 4. Define the prefix name (or names) to the DB2 Data Links Managers on
** the Data Links servers.
** 
** 5. Register the Data Links servers referred to by DATALINK data
** (to be loaded) in the DB2 Data Links Manager configuration file.
** 
** The connection between DB2 and the Data Links server may fail while
** running the load utility, causing the load operation to fail. If this
** occurs:
** 1. Start the Data Links server and the DB2 Data Links Manager.
** 2. Invoke a load restart operation.
** 
** Links that fail during the load operation are considered to be data
** integrity violations, and are handled in much the same way as unique
** index violations. Consequently, a special exception has been defined for
** loading tables that have one or more DATALINK columns.
** 
** Representation of DATALINK Information in an Input File
** The LINKTYPE (currently only URL is supported) is not specified as part of
** DATALINK information. The LINKTYPE is specified in the LOAD or the IMPORT
** command, and for input files of type PC/IXF, in the appropriate column
** descriptor records.
** 
** The syntax of DATALINK information for a URL LINKTYPE is as follows:
** >>-+---------+--+-----------------------+----------------------><
**    '-urlname-'  '-dl_delimiter--comment-'
** 
** Note that both urlname and comment are optional. If neither is provided,
** the NULL value is assigned.
** 
** urlname
** The URL name must conform to valid URL syntax.
** 
** Notes:
** 1. Currently "http", "file", and "unc" are permitted as a schema name.
** 
** 2. The prefix (schema, host, and port) of the URL name is optional. If a
** prefix is not present, it is taken from the DL_URL_DEFAULT_PREFIX or
** the DL_URL_REPLACE_PREFIX specification of the load or the import
** utility. If none of these is specified, the prefix defaults to
** "file://localhost". Thus, in the case of local files, the file name
** with full path name can be entered as the URL name, without the need
** for a DATALINK column specification within the LOAD or the IMPORT
** command.
** 
** 3. Prefixes, even if present in URL names, are overridden by a different
** prefix name on the DL_URL_REPLACE_PREFIX specification during a
** load or import operation.
** 
** 4. The "path" (after appending DL_URL_SUFFIX, if specified) is the full path
** name of the remote file in the remote server. Relative path names are not
** allowed. The http server default path-prefix is not taken into account.
** 
** dl_delimiter
** For the delimited ASCII (DEL) file format, a character specified via the
** dldel modifier, or defaulted to on the LOAD or the IMPORT command. For
** the non-delimited ASCII (ASC) file format, this should correspond to the
** character sequence \; (a backslash followed by a semicolon). Whitespace
** characters (blanks, tabs, and so on) are permitted before and after
** the value specified for this parameter.
** 
** comment
** The comment portion of a DATALINK value. If specified for the delimited ASCII
** (DEL) file format, the comment text must be enclosed by the character string
** delimiter, which is double quotation marks (") by default. This character
** string delimiter can be overridden by the MODIFIED BY filetype-mod
** specification of the LOAD or the IMPORT command.
** 
** If no comment is specified, the comment defaults to a string of length zero.
** 
** Following are DATALINK data examples for the delimited ASCII (DEL) file
** format: - http://www.almaden.ibm.com:80/mrep/intro.mpeg; "Intro Movie"
** This is stored with the following parts:
** --  scheme = http
** --  server = www.almaden.ibm.com
** --  path = /mrep/intro.mpeg
** --  comment = "Intro Movie"
** 
** - file://narang/u/narang; "InderPal's Home Page"
** This is stored with the following parts:
** --  scheme = file
** --  server = narang
** --  path = /u/narang
** --  comment = "InderPal's Home Page"
** 
** Following are DATALINK data examples for the non-delimited ASCII
** (ASC) file format:
** - http://www.almaden.ibm.com:80/mrep/intro.mpeg\;Intro Movie
** This is stored with the following parts:
** --  scheme = http
** --  server = www.almaden.ibm.com
** --  path = /mrep/intro.mpeg
** --  comment = "Intro Movie"
** 
** - file://narang/u/narang\; InderPal's Home Page
** This is stored with the following parts:
** --  scheme = file
** --  server = narang
** --  path = /u/narang
** --  comment = "InderPal's Home Page"
** 
** Following are DATALINK data examples in which the load or import
** specification for the column is assumed to be DL_URL_REPLACE_PREFIX
** ("http://qso"): - http://www.almaden.ibm.com/mrep/intro.mpeg
** This is stored with the following parts:
** --  schema = http
** --  server = qso
** --  path = /mrep/intro.mpeg
** --  comment = NULL string
** - /u/me/myfile.ps
** 
** This is stored with the following parts:
** --  schema = http
** --  server = qso
** --  path = /u/me/myfile.ps
** --  comment = NULL string
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Load                      */
  db2Load (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/*                                                                            */
/* db2gLoad structures                                                        */
/*                                                                            */

/* Generic Load input structure                                               */
/******************************************************************************
** db2gLoadIn data structure
** db2gLoadIn data structure specific parameters
** 
** iUseTablespaceLen
** Input. The length in bytes of piUseTablespace parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gLoadIn
{
   db2Uint64                           iRowcount; /* Row count                */
   db2Uint64                           iRestartcount; /* Restart count        */
   char                                *piUseTablespace; /* Alternative       */
                                                 /* Tablespace to rebuild     */
                                                 /* index                     */
   db2Uint32                           iSavecount; /* Save count              */
   db2Uint32                           iDataBufferSize; /* Data buffer        */
   db2Uint32                           iSortBufferSize; /* Sort buffer (for   */
                                                 /* vendor load sort)         */
   db2Uint32                           iWarningcount; /* Warning count        */
   db2Uint16                           iHoldQuiesce; /* Hold quiesce between  */
                                                 /* loads                     */
   db2Uint16                           iCpuParallelism; /* CPU parallelism    */
   db2Uint16                           iDiskParallelism; /* Disk parallelism  */
   db2Uint16                           iNonrecoverable; /* Non-recoverable    */
                                                 /* load                      */
   db2Uint16                           iIndexingMode; /* Indexing mode        */
   db2Uint16                           iAccessLevel; /* Access Level          */
   db2Uint16                           iLockWithForce; /* Lock With Force     */
   db2Uint16                           iCheckPending; /* Check Pending        */
                                                 /* Option                    */
   char                                iRestartphase; /* Restart phase        */
   char                                iStatsOpt; /* Statistics option        */
   db2Uint16                           iUseTablespaceLen; /* Length of        */
                                                 /* piUseTablespace string    */
   db2Uint16                           iSetIntegrityPending; /* Set           */
                                                 /* Integrity Pending Option  */
   struct db2LoadUserExit              *piSourceUserExit; /* SourceUserExit   */
   db2Uint16                           *piXmlParse; /* XML parsing            */
   struct db2DMUXmlValidate            *piXmlValidate; /* XML validation      */
} db2gLoadIn;

/* Generic Partitioned Load input structure                                   */
/******************************************************************************
** db2gPartLoadIn data structure
** db2gPartLoadIn data structure specific parameters
** 
** piReserved1
** Reserved for future use.
** 
** iHostnameLen
** Input. The length in bytes of piHostname parameter.
** 
** iFileTransferLen
** Input. The length in bytes of piFileTransferCmd parameter.
** 
** iPartFileLocLen
** Input. The length in bytes of piPartFileLocation parameter.
** 
** iMapFileInputLen
** Input. The length in bytes of piMapFileInput parameter.
** 
** iMapFileOutputLen
** Input. The length in bytes of piMapFileOutput parameter.
** 
** iDistfileLen
** Input. The length in bytes of piDistfile parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gPartLoadIn
{
   char                                *piHostname; /* Hostname for           */
                                                 /* iFileTransferCmd          */
                                                 /* parameter                 */
   char                                *piFileTransferCmd; /* File transfer   */
                                                 /* command                   */
   char                                *piPartFileLocation; /* Partition      */
                                                 /* file location             */
   struct db2LoadNodeList              *piOutputNodes; /* Output database     */
                                                 /* partitions                */
   struct db2LoadNodeList              *piPartitioningNodes; /* Partitioning  */
                                                 /* database partitions       */
   db2Uint16                           *piMode;  /* Partitioned Load mode     */
   db2Uint16                           *piMaxNumPartAgents; /* Max number of  */
                                                 /* partitioning agents       */
   db2Uint16                           *piIsolatePartErrs; /* Partition       */
                                                 /* error isolation mode      */
   db2Uint16                           *piStatusInterval; /* Status report    */
                                                 /* interval                  */
   struct db2LoadPortRange             *piPortRange; /* Port number range     */
   db2Uint16                           *piCheckTruncation; /* Check for       */
                                                 /* record truncation         */
   char                                *piMapFileInput; /* Map file input     */
   char                                *piMapFileOutput; /* Map file output   */
   db2Uint16                           *piTrace; /* Number of records to      */
                                                 /* trace                     */
   db2Uint16                           *piNewline; /* Check for newlines at   */
                                                 /* end of ASC records        */
   char                                *piDistfile; /* Partition              */
                                                 /* distribution output file  */
   db2Uint16                           *piOmitHeader; /* Don't generate       */
                                                 /* partition header in       */
                                                 /* output file               */
   void                                *piReserved1; /* Reserved parameter 1  */
   db2Uint16                           iHostnameLen; /* Length of iHostname   */
                                                 /* string                    */
   db2Uint16                           iFileTransferLen; /* Length of         */
                                                 /* iFileTransferCmd string   */
   db2Uint16                           iPartFileLocLen; /* Length of          */
                                                 /* iPartFileLocation string  */
   db2Uint16                           iMapFileInputLen; /* Length of         */
                                                 /* iMapFileInput string      */
   db2Uint16                           iMapFileOutputLen; /* Length of        */
                                                 /* iMapFileOutput string     */
   db2Uint16                           iDistfileLen; /* Length of iDistfile   */
                                                 /* string                    */
} db2gPartLoadIn;

/* db2gLoad parameter structure                                               */
/******************************************************************************
** db2gLoadStruct data structure
** db2gLoadStruct data structure specific parameters
** 
** iFileTypeLen
** Input. Specifies the length in bytes of iFileType parameter. 
** 
** iLocalMsgFileLen
** Input. Specifies the length in bytes of iLocalMsgFileName
** parameter.
** 
** iTempFilesPathLen
** Input. Specifies the length in bytes of iTempFilesPath parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gLoadStruct
{
   struct sqlu_media_list              *piSourceList; /* List of input        */
                                                 /* source names (files,      */
                                                 /* pipes, etc.)              */
   struct sqlu_media_list              *piLobPathList; /* Lob file paths      */
   struct sqldcol                      *piDataDescriptor; /* Data descriptor  */
                                                 /* list                      */
   struct sqlchar                      *piActionString; /* Deprecated         */
   char                                *piFileType; /* File type (ASC, DEL,   */
                                                 /* IXF, WSF, etc.)           */
   struct sqlchar                      *piFileTypeMod; /* File type modifier  */
                                                 /* string                    */
   char                                *piLocalMsgFileName; /* Message        */
                                                 /* filename                  */
   char                                *piTempFilesPath; /* Temporary files   */
                                                 /* path                      */
   struct sqlu_media_list              *piVendorSortWorkPaths; /* Vendor      */
                                                 /* Sort work directories     */
   struct sqlu_media_list              *piCopyTargetList; /* List of Load     */
                                                 /* copy targets              */
   db2int32                            *piNullIndicators; /* Null indicators  */
   struct db2gLoadIn                   *piLoadInfoIn; /* Load input           */
                                                 /* structure                 */
   struct db2LoadOut                   *poLoadInfoOut; /* Load output         */
                                                 /* structure                 */
   struct db2gPartLoadIn               *piPartLoadInfoIn; /* Partitioned      */
                                                 /* Load input structure      */
   struct db2PartLoadOut               *poPartLoadInfoOut; /* Partitioned     */
                                                 /* Load output structure     */
   db2int16                            iCallerAction; /* Caller action        */
   db2Uint16                           iFileTypeLen; /* Length of iFileType   */
                                                 /* string                    */
   db2Uint16                           iLocalMsgFileLen; /* Length of         */
                                                 /* iLocalMsgFileName string  */
   db2Uint16                           iTempFilesPathLen; /* Length of        */
                                                 /* iTempFilesPath string     */
   struct sqllob                       *piLongActionString; /* Long Load      */
                                                 /* action string             */
   struct sqlu_media_list              *piXmlPathList; /* XML file paths      */
} db2gLoadStruct;

/* db2Load - Generic API                                                      */
/******************************************************************************
** db2gLoad API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Load                      */
  db2gLoad (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Import Structures and Constants                                            */

#define DB2IMPORT_LOCKTIMEOUT          0         /* Respect db cfg            */
                                                 /* LOCKTIMEOUT               */
#define DB2IMPORT_NO_LOCKTIMEOUT       1         /* Override db cfg           */
                                                 /* LOCKTIMEOUT               */
#define DB2IMPORT_COMMIT_AUTO          -1        /* Use automatic             */
                                                 /* commitcount               */

/* Import input structure                                                     */
/******************************************************************************
** db2ImportIn data structure
** db2ImportIn data structure parameters
** 
** iRowcount
** Input. The number of physical records to be loaded. Allows a user to load
** only the first iRowcount rows in a file. If iRowcount is 0, import will
** attempt to process all the rows from the file.
** 
** iRestartcount
** Input. The number of records to skip before starting to insert or update
** records. Functionally equivalent to iSkipcount parameter. iRestartcount
** and iSkipcount parameters are mutually exclusive.
** 
** iSkipcount
** Input. The number of records to skip before starting to insert or update
** records. Functionally equivalent to iRestartcount.
** 
** piCommitcount
** Input. The number of records to import before committing them to the
** database. A commit is performed whenever piCommitcount records are
** imported. A NULL value specifies the default commit count value, which
** is zero for offline import and AUTOMATIC for online import. Commitcount
** AUTOMATIC is specified by passing in the value
** DB2IMPORT_COMMIT_AUTO.
** 
** iWarningcount
** Input. Stops the import operation after iWarningcount warnings. Set this
** parameter if no warnings are expected, but verification that the correct file
** and table are being used is desired. If the import file or the target table
** is specified incorrectly, the import utility will generate a warning for
** each row that it attempts to import, which will cause the import to fail.
** If iWarningcount is 0, or this option is not specified, the import
** operation will continue regardless of the number of warnings issued.
** 
** iNoTimeout
** Input. Specifies that the import utility will not time out while waiting for
** locks. This option supersedes the locktimeout database configuration
** parameter. Other applications are not affected. Valid values are:
** - DB2IMPORT_LOCKTIMEOUT
** Indicates that the value of the locktimeout configuration parameter is
** respected.
** - DB2IMPORT_NO_LOCKTIMEOUT
** Indicates there is no timeout.
** 
** iAccessLevel
** Input. Specifies the access level. Valid values are:
** - SQLU_ALLOW_NO_ACCESS
** Specifies that the import utility locks the table exclusively.
** - SQLU_ALLOW_WRITE_ACCESS
** Specifies that the data in the table should still be accessible to readers
** and writers while the import is in progress.
** 
** An intent exclusive (IX) lock on the target table is acquired when the
** first row is inserted. This allows concurrent readers and writers to access
** table data. Online mode is not compatible with the REPLACE, CREATE, or
** REPLACE_CREATE import options. Online mode is not supported in conjunction
** with buffered inserts. The import operation will periodically commit
** inserted data to prevent lock escalation to a table lock and to avoid 
** running out of active log space. These commits will be performed even if
** the piCommitCount parameter was not used. During each commit, import will
** lose its IX table lock, and will attempt to reacquire it after the commit.
** This parameter is required when you import to a nickname and piCommitCount
** parameter must be specified with a valid number (AUTOMATIC is not considered
** a valid option).
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ImportIn
{
   db2Uint64                           iRowcount; /* Row count                */
   db2Uint64                           iRestartcount; /* Restart count        */
   db2Uint64                           iSkipcount; /* Skip count              */
   db2int32                            *piCommitcount; /* Commit count        */
   db2Uint32                           iWarningcount; /* Warning count        */
   db2Uint16                           iNoTimeout; /* No lock timeout         */
   db2Uint16                           iAccessLevel; /* Access level          */
   db2Uint16                           *piXmlParse; /* XML parsing            */
   struct db2DMUXmlValidate            *piXmlValidate; /* XML validation      */
} db2ImportIn;

/* Import output structure                                                    */
/******************************************************************************
** db2ImportOut data structure
** db2ImportOut data structure parameters
** 
** oRowsRead
** Output. Number of records read from the file during import.
** 
** oRowsSkipped
** Output. Number of records skipped before inserting or updating begins.
** 
** oRowsInserted
** Output. Number of rows inserted into the target table.
** 
** oRowsUpdated
** Output. Number of rows in the target table updated with information from
** the imported records (records whose primary key value already exists in
** the table).
** 
** oRowsRejected
** Output. Number of records that could not be imported.
** 
** oRowsCommitted
** Output. Number of records imported successfully and committed to the
** database.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ImportOut
{
   db2Uint64                           oRowsRead; /* Rows read                */
   db2Uint64                           oRowsSkipped; /* Rows skipped          */
   db2Uint64                           oRowsInserted; /* Rows inserted        */
   db2Uint64                           oRowsUpdated; /* Rows updated          */
   db2Uint64                           oRowsRejected; /* Rows rejected        */
   db2Uint64                           oRowsCommitted; /* Rows committed      */
} db2ImportOut;

/* db2Import parameter structure                                              */
/******************************************************************************
** db2ImportStruct data structure
** db2ImportStruct data structure parameters
** 
** piDataFileName
** Input. A string containing the path and the name of the external input file
** from which the data is to be imported.
** 
** piLobPathList
** Input. An sqlu_media_list using media_type SQLU_LOCAL_MEDIA, and the
** sqlu_media_entry structure listing paths on the client where the LOB files
** can be found.
** 
** This parameter is not valid when you import to a nickname.
** 
** piDataDescriptor
** Input. Pointer to an sqldcol structure containing information about the
** columns being selected for import from the external file. The value of the
** dcolmeth field determines how the remainder of the information provided
** in this parameter is interpreted by the import utility. Valid values for this
** parameter are:
** 
** - SQL_METH_N
** Names. Selection of columns from the external input file is by column
** name.
** - SQL_METH_P
** Positions. Selection of columns from the external input file is by
** column position.
** - SQL_METH_L
** Locations. Selection of columns from the external input file is by
** column location. The database manager rejects an import call with a
** location pair that is invalid because of any one of the following
** conditions:
** 
** - Either the beginning or the ending location is not in the range
** from 1 to the largest signed 2-byte integer.
** - The ending location is smaller than the beginning location.
** - The input column width defined by the location pair is not
** compatible with the type and the length of the target column.
** 
** A location pair with both locations equal to zero indicates that a
** nullable column is to be filled with NULLs.
** - SQL_METH_D
** Default. If piDataDescriptor is NULL, or is set to SQL_METH_D, default
** selection of columns from the external input file is done. In this case,
** the number of columns and the column specification array are both
** ignored. For DEL, IXF, or WSF files, the first n columns of data in the
** external input file are taken in their natural order, where n is the
** number of database columns into which the data is to be imported.
** 
** piActionString
** Input. Pointer to an sqlchar structure containing a 2-byte long field,
** followed by an array of characters identifying the columns into which data
** is to be imported.
** 
** The character array is of the form:
** {INSERT | INSERT_UPDATE | REPLACE | CREATE | REPLACE_CREATE}
** INTO {tname[(tcolumn-list)] |
** [{ALL TABLES | (tname[(tcolumn-list)][, tname[(tcolumn-list)]])}]
** [IN] HIERARCHY {STARTING tname | (tname[, tname])}
** [UNDER sub-table-name | AS ROOT TABLE]}
** [DATALINK SPECIFICATION datalink-spec]
** 
** INSERT
** Adds the imported data to the table without changing the existing table
** data.
** 
** INSERT_UPDATE
** Adds the imported rows if their primary key values are not in the table,
** and uses them for update if their primary key values are found. This
** option is only valid if the target table has a primary key, and the
** specified (or implied) list of target columns being imported includes all
** columns for the primary key. This option cannot be applied to views.
** 
** REPLACE
** Deletes all existing data from the table by truncating the table object,
** and inserts the imported data. The table definition and the index
** definitions are not changed. (Indexes are deleted and replaced if
** indexixf is in FileTypeMod, and FileType is SQL_IXF.) If the table is not
** already defined, an error is returned.
** Attention: If an error occurs after the existing data is deleted, that data
** is lost.
** 
** This parameter is not valid when you import to a nickname.
** 
** CREATE
** Creates the table definition and the row contents using the information
** in the specified PC/IXF file, if the specified table is not defined. If
** the file was previously exported by DB2, indexes are also created. If
** the specified table is already defined, an error is returned. This
** option is valid for the PC/IXF file format only.
** 
** This parameter is not valid when you import to a nickname.
** 
** REPLACE_CREATE
** Replaces the table contents using the PC/IXF row information in the
** PC/IXF file, if the specified table is defined. If the table is not already
** defined, the table definition and row contents are created using the
** information in the specified PC/IXF file. If the PC/IXF file was previously
** exported by DB2, indexes are also created. This option is valid for the
** PC/IXF file format only.
** Attention: If an error occurs after the existing data is deleted, that data
** is lost.
** 
** This parameter is not valid when you import to a nickname.
** 
** tname
** The name of the table, typed table, view, or object view into which the
** data is to be inserted. An alias for REPLACE, INSERT_UPDATE, or
** INSERT can be specified, except in the case of a down-level server,
** when a qualified or unqualified name should be specified. If it is a view,
** it cannot be a read-only view.
** 
** tcolumn-list
** A list of table or view column names into which the data is to be
** inserted. The column names must be separated by commas. If column
** names are not specified, column names as defined in the CREATE
** TABLE or the ALTER TABLE statement are used. If no column list is
** specified for typed tables, data is inserted into all columns within each
** sub-table.
** 
** sub-table-name
** Specifies a parent table when creating one or more sub-tables under
** the CREATE option.
** 
** ALL TABLES
** An implicit keyword for hierarchy only. When importing a hierarchy, the
** default is to import all tables specified in the traversal-order-list.
** 
** HIERARCHY
** Specifies that hierarchical data is to be imported.
** 
** STARTING
** Keyword for hierarchy only. Specifies that the default order, starting
** from a given sub-table name, is to be used.
** 
** UNDER
** Keyword for hierarchy and CREATE only. Specifies that the new
** hierarchy, sub-hierarchy, or sub-table is to be created under a given
** sub-table.
** 
** AS ROOT TABLE
** Keyword for hierarchy and CREATE only. Specifies that the new
** hierarchy, sub-hierarchy, or sub-table is to be created as a stand-alone
** hierarchy.
** 
** DATALINK SPECIFICATION datalink-spec
** Specifies parameters pertaining to DB2 Data Links Manager. These
** parameters can be specified using the same syntax as in the IMPORT
** command.
** 
** The tname and the tcolumn-list parameters correspond to the
** tablename and the colname lists of SQL INSERT statements, and have
** the same restrictions.
** 
** The columns in tcolumn-list and the external columns (either specified
** or implied) are matched according to their position in the list or the
** structure (data from the first column specified in the sqldcol structure is
** inserted into the table or view field corresponding to the first element of
** the tcolumn-list).
** 
** If unequal numbers of columns are specified, the number of columns
** actually processed is the lesser of the two numbers. This could result in
** an error (because there are no values to place in some non-nullable table
** fields) or an informational message (because some external file columns
** are ignored).
** 
** This parameter is not valid when you import to a nickname.
** 
** piFileType
** Input. A string that indicates the format of the data within the external
** file. Supported external file formats are:
** 
** SQL_ASC
** Non-delimited ASCII.
** 
** SQL_DEL
** Delimited ASCII, for exchange with dBase, BASIC, and the IBM
** Personal Decision Series programs, and many other database
** managers and file managers.
** 
** SQL_IXF
** PC version of the Integrated Exchange Format, the preferred method for
** exporting data from a table so that it can be imported later into the
** same table or into another database manager table.
** 
** SQL_WSF
** Worksheet formats for exchange with Lotus Symphony and 1-2-3
** programs.
** 
** The WSF file type is not supported when you import to a nickname.
** 
** piFileTypeMod
** Input. A pointer to a structure containing a 2-byte long field, followed by
** an array of characters that specify one or more processing options. If this
** pointer is NULL, or the structure pointed to has zero characters, this
** action is interpreted as selection of a default specification.
** 
** Not all options can be used with all of the supported file types. See
** related link "File type modifiers for the import utility".
** 
** piMsgFileName
** Input. A string containing the destination for error, warning, and
** informational messages returned by the utility. It can be the path and the
** name of an operating system file or a standard device. If the file already
** exists, it is appended to. If it does not exist, a file is created.
** 
** iCallerAction
** Input. An action requested by the caller. Valid values are:
** 
** - SQLU_INITIAL
** Initial call. This value must be used on the first call to the API.
** If the initial call or any subsequent call returns and requires the calling
** application to perform some action prior to completing the requested
** import operation, the caller action must be set to one of the following:
** 
** - SQLU_CONTINUE
** Continue processing. This value can only be used on subsequent calls
** to the API, after the initial call has returned with the utility requesting
** user input (for example, to respond to an end of tape condition). It
** specifies that the user action requested by the utility has completed,
** and the utility can continue processing the initial request.
** 
** - SQLU_TERMINATE
** Terminate processing. This value can only be used on subsequent
** calls to the API, after the initial call has returned with the utility
** requesting user input (for example, to respond to an end of tape
** condition). It specifies that the user action requested by the utility was
** not performed, and the utility is to terminate processing the initial
** request.
** 
** piImportInfoIn
** Input. Pointer to the db2ImportIn structure.
** 
** poImportInfoOut
** Output. Pointer to the db2ImportOut structure.
** 
** piNullIndicators
** Input. For ASC files only. An array of integers that indicate whether or not
** the column data is nullable. The number of elements in this array must
** match the number of columns in the input file; there is a one-to-one
** ordered correspondence between the elements of this array and the
** columns being imported from the data file. Therefore, the number of
** elements must equal the dcolnum field of the piDataDescriptor
** parameter. Each element of the array contains a number identifying a
** column in the data file that is to be used as a null indicator field,
** or a zero indicating that the table column is not nullable. If the
** element is not zero, the identified column in the data file must
** contain a Y or an N. A Y indicates that the table column data is
** NULL, and N indicates that the table column data is not NULL.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ImportStruct
{
   char                                *piDataFileName; /* Data file name     */
   struct sqlu_media_list              *piLobPathList; /* Lob file paths      */
   struct sqldcol                      *piDataDescriptor; /* Data descriptor  */
                                                 /* list                      */
   struct sqlchar                      *piActionString; /* Deprecated         */
   char                                *piFileType; /* File type (ASC, DEL,   */
                                                 /* IXF, WSF, etc.)           */
   struct sqlchar                      *piFileTypeMod; /* File type modifier  */
                                                 /* string                    */
   char                                *piMsgFileName; /* Message filename    */
   db2int16                            iCallerAction; /* Caller action        */
   struct db2ImportIn                  *piImportInfoIn; /* Import input       */
                                                 /* structure                 */
   struct db2ImportOut                 *poImportInfoOut; /* Import output     */
                                                 /* structure                 */
   db2int32                            *piNullIndicators; /* Null indicators  */
   struct sqlu_media_list              *piXmlPathList; /* XML file paths      */
   struct sqllob                       *piLongActionString; /* Long Import    */
                                                 /* action string             */
} db2ImportStruct;

/******************************************************************************
** db2Import API
** Inserts data from an external file with a supported file format into a
** table, hierarchy, nickname or view. A faster alternative is using
** the load utility however, the load utility does not support loading
** data at the hierarchy level or loading into a nickname.
** 
** Authorization
** 
** - IMPORT using the INSERT option requires one of the following:
** -- sysadm
** -- dbadm
** -- CONTROL privilege on each participating table, view or nickname
** -- INSERT and SELECT privilege on each participating table or view
** 
** - IMPORT to an existing table using the INSERT_UPDATE option, requires
** one of the following:
** -- sysadm
** -- dbadm
** -- CONTROL privilege on the table, view or nickname
** -- INSERT, SELECT, UPDATE and DELETE privilege on each
** participating table or view
** 
** - IMPORT to an existing table using the REPLACE or REPLACE_CREATE
** option, requires one of the following:
** -- sysadm
** -- dbadm
** -- CONTROL privilege on the table or view
** -- INSERT, SELECT, and DELETE privilege on the table or view
** 
** - IMPORT to a new table using the CREATE or REPLACE_CREATE option,
** requires one of the following:
** -- sysadm
** -- dbadm
** -- CREATETAB authority on the database and USE privilege on the
** table space, as well as one of:
** --- IMPLICIT_SCHEMA authority on the database, if the implicit
** or explicit schema name of the table does not exist
** --- CREATIN privilege on the schema, if the schema name of the
** table refers to an existing schema
** 
** - IMPORT to a table or a hierarchy that does not exist using the CREATE, or
** the REPLACE_CREATE option, requires one of the following:
** -- sysadm
** -- dbadm
** -- CREATETAB authority on the database, and one of:
** --- IMPLICIT_SCHEMA authority on the database, if the schema
** name of the table does not exist
** --- CREATEIN privilege on the schema, if the schema of the
** table exists
** --- CONTROL privilege on every sub-table in the hierarchy, if the
** REPLACE_CREATE option on the entire hierarchy is used
** 
** - IMPORT to an existing hierarchy using the REPLACE option requires one
** of the following:
** -- sysadm
** -- dbadm
** -- CONTROL privilege on every sub-table in the hierarchy
** 
** Required connection
** 
** Database. If implicit connect is enabled, a connection to the default
** database is established.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Import API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter pParmStruct.
** 
** pParmStruct
** Input/Output. A pointer to the db2ImportStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Before starting an import operation, you must complete all table operations
** and release all locks in one of two ways:
** - Close all open cursors that were defined with the WITH HOLD clause, and
** commit the data changes by executing the COMMIT statement.
** - Roll back the data changes by executing the ROLLBACK statement.
** 
** The import utility adds rows to the target table using the SQL INSERT
** statement.
** 
** The utility issues one INSERT statement for each row of data in the input
** file. If an INSERT statement fails, one of two actions result:
** 
** - If it is likely that subsequent INSERT statements can be successful, a
** warning message is written to the message file, and processing continues.
** 
** - If it is likely that subsequent INSERT statements will fail, and there is
** potential for database damage, an error message is written to the message
** file, and processing halts.
** 
** The utility performs an automatic COMMIT after the old rows are deleted
** during a REPLACE or a REPLACE_CREATE operation. Therefore, if the system
** fails, or the application interrupts the database manager after the table
** object is truncated, all of the old data is lost. Ensure that the old
** data is no longer needed before using these options.
** 
** If the log becomes full during a CREATE, REPLACE, or REPLACE_CREATE
** operation, the utility performs an automatic COMMIT on inserted records.
** If the system fails, or the application interrupts the database manager
** after an automatic COMMIT, a table with partial data remains in the
** database. Use the REPLACE or the REPLACE_CREATE option to rerun the
** whole import operation, or use INSERT with the iRestartcount parameter
** set to the number of rows successfully imported.
** 
** By default, automatic COMMITs are not performed for the INSERT or the
** INSERT_UPDATE option. They are, however, performed if the *piCommitcount
** parameter is not zero. A full log results in a ROLLBACK.
** 
** Whenever the import utility performs a COMMIT, two messages are written
** to the message file: one indicates the number of records to be committed,
** and the other is written after a successful COMMIT. When restarting the
** import operation after a failure, specify the number of records to skip,
** as determined from the last successful COMMIT.
** 
** The import utility accepts input data with minor incompatibility problems
** (for example, character data can be imported using padding or truncation,
** and numeric data can be imported with a different numeric data type), but
** data with major incompatibility problems is not accepted.
** 
** One cannot REPLACE or REPLACE_CREATE an object table if it has any
** dependents other than itself, or an object view if its base table has any
** dependents (including itself). To replace such a table or a view, do the
** following:
** 
** 1. Drop all foreign keys in which the table is a parent.
** 2. Run the import utility.
** 3. Alter the table to recreate the foreign keys.
** 
** If an error occurs while recreating the foreign keys, modify the data to
** maintain referential integrity.
** 
** Referential constraints and foreign key definitions are not preserved when
** creating tables from PC/IXF files. (Primary key definitions are preserved
** if the data was previously exported using SELECT *.)
** 
** Importing to a remote database requires enough disk space on the server for a
** copy of the input data file, the output message file, and potential growth
** in the size of the database.
** 
** If an import operation is run against a remote database, and the output
** message file is very long (more than 60 KB), the message file returned to
** the user on the client may be missing messages from the middle of the
** import operation. The first 30 KB of message information and the last
** 30 KB of message information are always retained.
** 
** Importing PC/IXF files to a remote database is much faster if the PC/IXF
** file is on a hard drive rather than on diskettes. Non-default values for
** piDataDescriptor, or specifying an explicit list of table columns in
** piActionString, makes importing to a remote database slower.
** 
** The database table or hierarchy must exist before data in the ASC, DEL,
** or WSF file formats can be imported; however, if the table does not
** already exist, IMPORT CREATE or IMPORT REPLACE_CREATE creates the table
** when it imports data from a PC/IXF file. For typed tables, IMPORT CREATE
** can create the type hierarchy and the table hierarchy as well.
** 
** PC/IXF import should be used to move data (including hierarchical data)
** between databases. If character data containing row separators is
** exported to a delimited ASCII (DEL) file and processed by a text transfer
** program, fields containing the row separators will shrink or expand.
** 
** The data in ASC and DEL files is assumed to be in the code page of the client
** application performing the import. PC/IXF files, which allow for different
** code pages, are recommended when importing data in different code pages.
** If the PC/IXF file and the import utility are in the same code page,
** processing occurs as for a regular application. If the two differ, and
** the FORCEIN option is specified, the import utility assumes that data in
** the PC/IXF file has the same code page as the application performing the
** import. This occurs even if there is a conversion table for the two code
** pages. If the two differ, the FORCEIN option is not specified, and there
** is a conversion table, all data in the PC/IXF file will be converted from
** the file code page to the application code page. If the two differ, the
** FORCEIN option is not specified, and there is no conversion table,
** the import operation will fail. This applies only to PC/IXF files on DB2 for
** AIX clients.
** 
** For table objects on an 8KB page that are close to the limit of 1012 columns,
** import of PC/IXF data files may cause DB2 to return an error, because the
** maximum size of an SQL statement was exceeded. This situation can occur only
** if the columns are of type CHAR, VARCHAR, or CLOB. The restriction does not
** apply to import of DEL or ASC files.
** 
** DB2 Connect can be used to import data to DRDA servers such as DB2 for
** OS/390, DB2 for VM and VSE, and DB2 for OS/400. Only PC/IXF import (INSERT
** option) is supported. The restartcnt parameter, but not the commitcnt
** parameter, is also supported.
** 
** When using the CREATE option with typed tables, create every sub-table
** defined in the PC/IXF file; sub-table definitions cannot be altered. When
** using options other than CREATE with typed tables, the traversal order
** list enables one to specify the traverse order; therefore, the traversal
** order list must match the one used during the export operation. For the
** PC/IXF file format, one need only specify the target sub-table name, and
** use the traverse order stored in the file. The import utility can be
** used to recover a table previously exported to a PC/IXF file. The
** table returns to the state it was in when exported.
** 
** Data cannot be imported to a system table, a declared temporary table, or a
** summary table.
** 
** Views cannot be created through the import utility.
** 
** On the Windows operating system:
** - Importing logically split PC/IXF files is not supported.
** - Importing bad format PC/IXF or WSF files is not supported.
** 
** DB2 Data Links Manager Considerations
** 
** Before running the DB2 import utility, do the following:
** 
** 1. Copy the files that will be referenced to the appropriate Data Links
** servers. The dlfm_import utility can be used to extract files from an
** archive that is generated by the dlfm_export utility.
** 
** 2. Register the required prefix names to the DB2 Data Links Managers. There
** may be other administrative tasks, such as registering the database, if
** required.
** 
** 3. Update the Data Links server information in the URLs (of the DATALINK
** columns) from the exported data for the SQL table, if required. (If the
** original configuration's Data Links servers are the same at the target
** location, the Data Links server names need not be updated.)
** 
** 4. Define the Data Links servers at the target configuration in the DB2 Data
** Links Manager configuration file.
** 
** When the import utility runs against the target database, files referred
** to by DATALINK column data are linked on the appropriate Data Links
** servers. During the insert operation, DATALINK column processing links
** the files in the appropriate Data Links servers according to the column
** specifications at the target database.
** 
** Federated considerations
** 
** When using the db2Import API and the INSERT, UPDATE, or INSERT_UPDATE
** parameters, you must ensure that you have CONTROL privilege on the
** participating nickname. You must ensure that the nickname you wish to use
** when doing an import operation already exists.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Import                    */
  db2Import (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Generic Import input structure                                             */
/******************************************************************************
** db2gImportIn data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gImportIn
{
   db2Uint64                           iRowcount; /* Row count                */
   db2Uint64                           iRestartcount; /* Restart count        */
   db2Uint64                           iSkipcount; /* Skip count              */
   db2int32                            *piCommitcount; /* Commit count        */
   db2Uint32                           iWarningcount; /* Warning count        */
   db2Uint16                           iNoTimeout; /* No lock timeout         */
   db2Uint16                           iAccessLevel; /* Access level          */
   db2Uint16                           *piXmlParse; /* XML parsing            */
   struct db2DMUXmlValidate            *piXmlValidate; /* XML validation      */
} db2gImportIn;

/* Generic Import output structure                                            */
/******************************************************************************
** db2gImportOut data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gImportOut
{
   db2Uint64                           oRowsRead; /* Rows read                */
   db2Uint64                           oRowsSkipped; /* Rows skipped          */
   db2Uint64                           oRowsInserted; /* Rows inserted        */
   db2Uint64                           oRowsUpdated; /* Rows updated          */
   db2Uint64                           oRowsRejected; /* Rows rejected        */
   db2Uint64                           oRowsCommitted; /* Rows committed      */
} db2gImportOut;

/* db2gImport parameter structure                                             */
/******************************************************************************
** db2gImportStruct data structure
** db2gImportStruct data structure specific parameters
** 
** iDataFileNameLen
** Input. Specifies the length in bytes of piDataFileName parameter.
** 
** iFileTypeLen
** Input. Specifies the length in bytes of piFileType parameter.
** 
** iMsgFileNameLen
** Input. Specifies the length in bytes of piMsgFileName parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gImportStruct
{
   char                                *piDataFileName; /* Data file name     */
   struct sqlu_media_list              *piLobPathList; /* Lob file paths      */
   struct sqldcol                      *piDataDescriptor; /* Data descriptor  */
                                                 /* list                      */
   struct sqlchar                      *piActionString; /* Deprecated         */
   char                                *piFileType; /* File type (ASC, DEL,   */
                                                 /* IXF, WSF, etc.)           */
   struct sqlchar                      *piFileTypeMod; /* File type modifier  */
                                                 /* string                    */
   char                                *piMsgFileName; /* Message filename    */
   db2int16                            iCallerAction; /* Caller action        */
   struct db2gImportIn                 *piImportInfoIn; /* Import input       */
                                                 /* structure                 */
   struct dbg2ImportOut                *poImportInfoOut; /* Import output     */
                                                 /* structure                 */
   db2int32                            *piNullIndicators; /* Null indicators  */
   db2Uint16                           iDataFileNameLen; /* Length of         */
                                                 /* iDataFileName string      */
   db2Uint16                           iFileTypeLen; /* Length of iFileType   */
                                                 /* string                    */
   db2Uint16                           iMsgFileNameLen; /* Length of          */
                                                 /* iMsgFileName string       */
   struct sqlu_media_list              *piXmlPathList; /* XML file paths      */
   struct sqllob                       *piLongActionString; /* Long Import    */
                                                 /* action string             */
} db2gImportStruct;

/* db2gImport - Generic API                                                   */
/******************************************************************************
** db2gImport API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Import                    */
  db2gImport (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Ingest Utility Structures and Constants                                    */

/* Ingest Utility, Possible values for field "iCfgParam".                     */
#define DB2INGEST_CFG_COMMIT_COUNT     1
#define DB2INGEST_CFG_COMMIT_PERIOD    2
#define DB2INGEST_CFG_NUM_FLUSHERS_PER 3
#define DB2INGEST_CFG_NUM_FORMATTERS   4
#define DB2INGEST_CFG_PIPE_TIMEOUT     5
#define DB2INGEST_CFG_RETRY_COUNT      6
#define DB2INGEST_CFG_RETRY_PERIOD     7
#define DB2INGEST_CFG_SHM_MAX_SIZE     8

/* Ingest Utility - Config Parameter Structure                                */
/******************************************************************************
** db2IngestCfgParam data structure
** db2IngestCfgParam data structure parameters
** 
** iCfgParam
** Input. The configuration parameter.  Possible values are one of the
** DB2INGEST_CFG_xxx constants.
** 
** iCfgParamValue
** Input. The value of the configuration parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2IngestCfgParam
{
   db2Uint32                           iCfgParam; /* The configuration        */
                                                 /* parameter.                */
   db2Uint32                           iCfgParamValue; /* The value of the    */
                                                 /* configuration parameter.  */
} db2IngestCfgParam;

/* Ingest Utility - Config Parameter Structure List                           */
/******************************************************************************
** db2IngestCfgList data structure
** db2IngestCfgList data structure parameters
** 
** piCfgParam
** Input. Pointer to an array of configuration parameter setttings.
** 
** iNumCfgParams
** Input. The number of elements in the array that piCfgParam points to.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2IngestCfgList
{
   struct db2IngestCfgParam            *piCfgParam; /* Pointer to an array.   */
   db2Uint32                           iNumCfgParams; /* The number of        */
                                                 /* elements in the array.    */
} db2IngestCfgList;

/* Possible values for field "iDecimalFormat".                                */
#define DB2INGEST_DEC_FORMAT_DEFAULT   0
#define DB2INGEST_DEC_FORMAT_PACKED    1
#define DB2INGEST_DEC_FORMAT_ZONED     2

/* Possible values for field "iSecLabelFormat".                               */
#define DB2INGEST_SEC_FORMAT_NOT_SEC   0
#define DB2INGEST_SEC_FORMAT_ENCODED   1
#define DB2INGEST_SEC_FORMAT_NAME      2
#define DB2INGEST_SEC_FORMAT_STRING    3

/* Possible values for field "iEndian".                                       */
#define DB2INGEST_ENDIAN_DEFAULT       0
#define DB2INGEST_ENDIAN_LITTLE        1
#define DB2INGEST_ENDIAN_BIG           2

/* Possible values for field "iTrim".                                         */
#define DB2INGEST_TRIM_DEFAULT         0
#define DB2INGEST_TRIM_NO              1
#define DB2INGEST_TRIM_LEFT            2
#define DB2INGEST_TRIM_RIGHT           3
#define DB2INGEST_TRIM                 4

/* Ingest Utility - Field Definition Structure                                */
/******************************************************************************
** db2IngestFieldDefn data structure
** db2IngestFieldDefn data structure parameters
** 
** piDatetimeFormat
** Input. When the field type is date, time, or timestamp, this is
** the format string.  For the default format string, set this to
** NULL.  For other field types, it must be NULL.
** 
** piName
** Input. The field name, null terminated.  This cannot be NULL.
** 
** iStartPos
** Input. The field start position.
** If the file type is not positional, this field must be 0.
** 
** iEndPos
** Input. The field end position.
** If the file type is not positional, this field must be 0.
** 
** iLength
** Input. The field length.  This is set the same as the SQLLEN field
** in the SQLDA for DATE, TIME, INTEGER, BIGINT, SMALLINT, DOUBLE.
** For a description of the SQLLEN field in the SQLDA, see topic
** "SQLDA (SQL descriptor area)" in the DB2 Information Center.
** 
** For the default length as described in the DB2 V10.1 Information
** Center for the Ingest Utility, set this to 0.
** When iExternal = true, this field contains the external length.
** 
** If this field is specified, it must be valid for the data type.
** 
** Exceptions to this:
** 
** - when the format is DB2SECURITYLABEL, iSecLabelFormat=
**  DB2INGEST_SEC_FORMAT_NAME or DB2INGEST_SEC_FORMAT_STRING,
** then iLength is the external length.
** - when iExternal is TRUE, iLength is the external length.
** iExternal
** Input. TRUE or FALSE.
** If TRUE, the iLength field specifies the length after which
** the field will be truncated.
** 
** If the user specifies an iLength of 0, the field will be
** truncated at the default values specified in the
** DB2 V10.1 Information Center.
** 
** iDecimalFormat
** Input. The format of a DECIMAL field. Possible values are:
** 
** - DB2INGEST_DEC_FORMAT_DEFAULT (must be used if iExternal TRUE)
** - DB2INGEST_DEC_FORMAT_PACKED
** - DB2INGEST_DEC_FORMAT_ZONED
** These values are allowed only when the field type is DECIMAL.
** 
** iScale
** Input. Scale of a DECIMAL field, range allowed: 1 to SQL_MAXDECIMAL.
** 
** iPrecision
** Input. Precision of DECIMAL, DECFLOAT, FLOAT or TIMESTAMP in digits.
** - For a DECIMAL field, range allowed: 1 to SQL_MAXDECIMAL.
** - For a DECFLOAT field, values allowed: 0, SQL_DECFLOAT16_PRECISION or SQL_DECFLOAT34_PRECISION
** - For a TIMESTAMP field, range allowed: SQL_STAMP_MIN_PREC to SQL_STAMP_MAX_PREC.
** - For a FLOAT field, range allowed: SQL_MINSFLOATPREC to SQL_MAXFLOATPREC.
** - For a 4-byte FLOAT field, range allowed: SQL_MINSFLOATPREC to SQL_MAXSFLOATPREC.
** iSecLabelFormat
** Input. This indicates the format of a DB2SECURITYLABEL field. The iType
** for this field is SQL_TYP_CHAR, and iSecLabelFormat is one of:
** 
** - DB2INGEST_SEC_FORMAT_ENCODED
** - DB2INGEST_SEC_FORMAT_NAME
** - DB2INGEST_SEC_FORMAT_STRING
** These should only be specified when the field is a DB2SECURITYLABEL.
** 
** If the field is not a DB2SECURITYLABEL, then the value should be:
** 
** - DB2INGEST_SEC_FORMAT_NOT_SEC
** 
** iEndian
** Input. When the field type is binary numeric (except decimal), this
** is the endianess. For other field types or if the field
** format is EXTERNAL, this must be 0.
** 
** iForBitData
** Input. For CHAR field, set this TRUE to skip codepage conversion.
** 
** iTrim
** Input. When the field type is CHAR, this can be:
** 
** - DB2INGEST_TRIM_DEFAULT
** - DB2INGEST_TRIM_NO
** - DB2INGEST_TRIM_LEFT
** - DB2INGEST_TRIM_RIGHT
** - DB2INGEST_TRIM
** 
** For other field types, this must be 0.
** 
** iDefaultIfPos
** Input. When a DEFAULTIF character is specified, this can be the
** position in the input record.  When no DEFAULTIF character is
** specified or the format is DELIMITED, this must be 0.
** 
** iType
** Input. The field type.  The value is one of the SQL_TYP_xxx
** constants defined in sql.h.
** 
** iDefaultIfChar
** Input. The DEFAULTIF character. If there is none, set this to 0 or the null
** character '\0'.
** 
** iEnclosedBy
** Input. When the field type is CHAR, DATE, TIME, or TIMESTAMP, this
** is the character that encloses the data in the input source.
** For no enclosing character, set this to 0 or the null character '\0'.
** For other field types, this must be 0.
** 
** iRadixPoint
** Input. When the field type is numeric, this is the radix point. For
** the default radix point, set this to 0 or the null character '\0'.
** For other field types, this must be 0.
** 
** iReserved
** Input. This is reserved for future use and must be 0.
** This field is checked only if the versionNumber parameter passed to the db2Ingest
** API is greater than or equal to db2Version1015 and less than db2Version1050, or
** the versionNumber parameter is greater than or equal to db2Version1056.
** 
** iDefaultIfNull
** Input. Set to boolean true to use the column default value when the input field is empty.
** This field is used only if the versionNumber parameter passed to the db2Ingest
** API is greater than or equal to db2Version1015 and less than db2Version1050, or
** the versionNumber parameter is greater than or equal to db2Version1057.
** 
** 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2IngestFieldDefn
{
   struct db2Char                      *piDatetimeFormat; /* The format       */
                                                 /* string.                   */
   struct db2Char                      *piName;  /* The field name            */
   db2Uint32                           iStartPos; /* The field start          */
                                                 /* position.                 */
   db2Uint32                           iEndPos;  /* The field end position.   */
   db2Uint32                           iLength;  /* The field length.         */
   db2Uint32                           iExternal; /* Boolean true if          */
                                                 /* external truncation       */
                                                 /* length specified.         */
   db2Uint32                           iDecimalFormat; /* Format of a         */
                                                 /* DECIMAL field             */
   db2Uint32                           iScale;   /* Scale of a DECIMAL field  */
   db2Uint32                           iPrecision; /* Precision of a          */
                                                 /* DECIMAL, DECFLOAT, FLOAT  */
                                                 /* or TIMESTAMP field        */
   db2Uint32                           iSecLabelFormat; /* Format of a        */
                                                 /* DB2SECURITYLABEL field    */
   db2Uint32                           iEndian;  /* The endianness.           */
   db2Uint32                           iForBitData; /* Set if bit data.       */
   db2Uint32                           iTrim;    /* Trim policy.              */
   db2Uint32                           iDefaultIfPos; /* Position in input    */
                                                 /* record if defaultif is    */
                                                 /* set.                      */
   db2Uint16                           iType;    /* The field type.           */
   char                                iDefaultIfChar; /* The DEFAULTIF       */
                                                 /* character.                */
   char                                iEnclosedBy; /* The character that     */
                                                 /* encloses the data in the  */
                                                 /* input source.             */
   char                                iRadixPoint; /* The radix point.       */
   char                                iReserved[3]; /* Reserved for future   */
                                                 /* use, must be 0            */
   db2Uint32                           iDefaultIfNull; /* Set to boolean      */
                                                 /* true to use column        */
                                                 /* default value when input  */
                                                 /* field is empty            */
} db2IngestFieldDefn;

/* Possible values for field "iImplicitlyHidden".                             */
#define DB2INGEST_IMPLICIT_HID_DEFAULT 0
#define DB2INGEST_IMPLICIT_HID_MISSING 1
#define DB2INGEST_IMPLICIT_HID_INCLUDE 2

/* Ingest Utility - Format Structure                                          */
/******************************************************************************
** db2IngestFormat data structure
** db2IngestFormat data structure parameters
** 
** piFieldDefn
** Input. Pointer to an array of field definition structs.piFileType
** Input. The format of the input source.  Cannot be NULL.  Possible
** values are:
** 
** - SQL_DEL
** - SQL_ASC
** 
** iRecordLength
** Input. When the file type is positional, this can be the record
** length. When the file type is not positional, this must be 0.
** 
** iNumFields
** Input. The number of elements in the array that piFieldDefn points
** to.  This must be greater than 0 and less than or equal to
** the maximum number of fields (1012).
** 
** iCodepage
** Input. The codepage of the input file.  For the default codepage
** (the application codepage), set this to 0.
** 
** iImplicitlyHidden
** Input. When the SQL statement is INSERT or REPLACE, this field
** indicates whether the input records contain implicitly hidden
** columns. Possible values are:
** 
** - DB2INGEST_IMPLICIT_HID_DEFAULT
** - DB2INGEST_IMPLICIT_HID_MISSING
** - DB2INGEST_IMPLICIT_HID_INCLUDE
** 
** If this is set to DB2INGEST_IMPLICIT_HID_DEFAULT, then the
** utility determines its setting from DB2 registry variable
** DB2_DMU_DEFAULT. If that registry variable is not set and the
** target table contains hidden columns, the utility issues an error.
** 
** If the SQL statement is not INSERT or REPLACE, or the SQL
** statement specifies the table columns, this must be set to
** DB2INGEST_IMPLICIT_HID_DEFAULT.
** 
** iDelimiter
** Input. The delimiter.  For the default delimiter, specify 0. If the
** file type is positional, this must be 0.
** 
** iRadixPointImplied
** Input. Boolean. The location of an implied decimal point is determined
** by the field definition; it is no longer assumed to be at the end of
** the value. For example, the value 12345 is loaded into a DECIMAL(8,2)
** as 123.45, not 12345.00.  This field is checked only if the 
** versionNumber parameter passed to the db2Ingest API is greater than or
** equal to db2Version1015.
** 
** iDelPriorityChar
** Input. True if DELIMITED PRIORITY CHAR is specified.
** Row delimiters within quotation marks will be part of that string and 
** not the end of a record.
** This field is used only if the versionNumber parameter passed to the db2Ingest
** API is greater than or equal to db2Version1016.
** 
** iNoCharDel
** Input. True if NO CHAR DELIMITER is specified.
** No string delimiters will be used, so any quotation marks will be 
** part of the string.
** This field is used only if the versionNumber parameter passed to the db2Ingest
** API is greater than or equal to db2Version1059.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2IngestFormat
{
   struct db2IngestFieldDefn           *piFieldDefn; /* Pointer to an array   */
                                                 /* of field definition       */
                                                 /* structs.                  */
   struct db2Char                      *piFileType; /* The format of the      */
                                                 /* input source.             */
   db2Uint32                           iRecordLength; /* The record length.   */
   db2Uint32                           iNumFields; /* The number of elements  */
                                                 /* in the array that         */
                                                 /* piFieldDefn points to.    */
   db2Uint16                           iCodepage; /* The codepage of the      */
                                                 /* input file.               */
   db2Uint16                           iImplicitlyHidden; /* Specifiy         */
                                                 /* behaviour for Implicitly  */
                                                 /* hidden columns            */
   char                                iDelimiter; /* The delimiter.          */
   char                                iReserved3Bytes[3]; /* Reserved for    */
                                                 /* future use, should be 0.  */
   db2Uint32                           iRadixPointImplied; /* Boolean true    */
                                                 /* if the location of the    */
                                                 /* radix point is implied    */
                                                 /* by the field definition.  */
   db2Uint32                           iDelPriorityChar; /* Boolean true if   */
                                                 /* DELIMITED PRIORITY CHAR   */
                                                 /* is specified.             */
   db2Uint32                           iNoCharDel; /* Boolean true if NO      */
                                                 /* CHAR DELIMITER is         */
                                                 /* specified.                */
} db2IngestFormat;

/* Possible values for field "oMaxMsgSeverity".                               */
#define DB2INGEST_MSGSEV_UNDEFINED     0
#define DB2INGEST_MSGSEV_INFO          1
#define DB2INGEST_MSGSEV_NO_DATA       2
#define DB2INGEST_MSGSEV_WARNING       3
#define DB2INGEST_MSGSEV_ERROR         4
#define DB2INGEST_MSGSEV_SEVERE        5

/* Ingest Utility - Output Structure                                          */
/******************************************************************************
** db2IngestOut data structure
** db2IngestOut data structure parameters
** 
** oRowsRead
** Output. Number of records read.
** 
** oRowsSkipped
** Output. Number of records skipped.
** 
** oRowsInserted
** Output. Number of rows inserted.
** 
** oRowsUpdated
** Output. Number of rows updated.
** 
** oRowsDeleted
** Output. Number of rows deleted.
** 
** oRowsMerged
** Output. Number of rows merged.
** 
** oRowsRejected
** Output. Number of rows rejected.
** 
** oNumErrors
** Output. Number of errors.
** 
** oNumWarnings
** Output. Number of warnings.
** 
** oMaxMsgSeverity
** Output. Max Message severity.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2IngestOut
{
   db2Uint64                           oRowsRead; /* Rows read                */
   db2Uint64                           oRowsSkipped; /* Rows skipped (always  */
                                                 /* 0)                        */
   db2Uint64                           oRowsInserted; /* Rows inserted        */
   db2Uint64                           oRowsUpdated; /* Rows updated          */
   db2Uint64                           oRowsDeleted; /* Rows deleted          */
   db2Uint64                           oRowsMerged; /* Rows merged            */
   db2Uint64                           oRowsRejected; /* Rows rejected        */
   db2Uint64                           oNumErrors; /* Number of errors        */
   db2Uint64                           oNumWarnings; /* Number of warnings    */
   db2Uint64                           oMaxMsgSeverity; /* Max message        */
                                                 /* severity                  */
} db2IngestOut;

/* Possible values for field "iRestartMode".                                  */
#define DB2INGEST_RESTART_DEFAULT      0
#define DB2INGEST_RESTART_OFF          1
#define DB2INGEST_RESTART_NEW          2
#define DB2INGEST_RESTART_CONTINUE     3
#define DB2INGEST_RESTART_TERMINATE    4

/* Possible values for field "iSourceType".                                   */
#define DB2INGEST_SOURCE_DEFAULT       0
#define DB2INGEST_SOURCE_SOCKET        1

/* Ingest Utility - Parameter Structure                                       */
/******************************************************************************
** db2IngestStruct data structure
** db2IngestStruct data structure parameters
** 
** piCfgList
** Input. Pointer to the struct containing the ingest configuration
** parameters.
** 
** piSourceList
** Input. The input sources.
** 
** piFormat
** Input. Pointer to the struct containing information about the input
** format.
** 
** poIngestInfoOut
** Ouptut. Ingest output structure
** 
** piDumpFile
** Input. Pointer to the dump file name, null-terminated.  If there is
** no dump file, set this to NULL.
** 
** piExceptTableName
** Input. Pointer to the name of the exception table, null-terminated.
** If there is no exception table, set this to NULL.
** 
** piMsgFileName
** Input. Pointer to the messages file name, null-terminated.  Cannot be
** NULL.
** 
** piJobId
** Input. Pointer to the job ID, null-terminated.  For the default job
** ID, set this to NULL.  If the restart option is OFF, this must
** be NULL.
** 
** piSqlStatement
** Input. Pointer to the SQL statement, null-terminated.  This cannot
** be NULL.
** 
** iWarningcount
** Input. The warning count.
** 
** iRestartMode
** Input. The restart option.  Possible values are:
** - DB2INGEST_RESTART_DEFAULT
** - DB2INGEST_RESTART_OFF
** - DB2INGEST_RESTART_NEW
** - DB2INGEST_RESTART_CONTINUE
** - DB2INGEST_RESTART_TERMINATE
** 
** iSourceType
** Input. The source type.  Possible values are:
** - DB2INGEST_SOURCE_DEFAULT
** - DB2INGEST_SOURCE_SOCKET
** iListenPort
** Input. The port to connect to.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2IngestStruct
{
   struct db2IngestCfgList             *piCfgList; /* Pointer to ingest       */
                                                 /* configuration parameters  */
                                                 /* struct.                   */
   struct sqlu_media_list              *piSourceList; /* The input sources.   */
   struct db2IngestFormat              *piFormat; /* Pointer to ingest        */
                                                 /* format struct.            */
   struct db2IngestOut                 *poIngestInfoOut; /* Ingest output     */
                                                 /* structure                 */
   struct db2Char                      *piDumpFile; /* Pointer to the dump    */
                                                 /* file name.                */
   struct db2Char                      *piExceptTableName; /* Pointer to the  */
                                                 /* name of the exception     */
                                                 /* table.If there is no      */
                                                 /* exception table, set      */
                                                 /* this to NULL.             */
   struct db2Char                      *piMsgFileName; /* Pointer to the      */
                                                 /* messages file name.       */
   struct db2Char                      *piJobId; /* Pointer to the job ID,    */
                                                 /* null-terminated.          */
   struct db2Char                      *piSqlStatement; /* Pointer to the     */
                                                 /* SQL statement, null       */
                                                 /* terminated.               */
   db2Uint32                           iWarningcount; /* The warning count.   */
   db2Uint32                           iRestartMode; /* The restart option.   */
   db2Uint32                           iSourceType; /* The source type.       */
   db2Uint32                           iListenPort; /* The port to connect    */
                                                 /* to.                       */
} db2IngestStruct;

/******************************************************************************
** db2Ingest API
** Ingest data from an input file or pipe into a DB2 table.
** 
** Authorization
** 
** The privileges held by the authorization ID used to connect to the database
** must include:
** At least one of the following:
** - DATAACCESS authority
** - CONTROL privilege on the target table
** 
**  One or more of the following depending on the SQL statement specified:
** - If the INGEST command specifies the INSERT statement (including as part of a
** MERGE statement), SELECT and INSERT privilege on the target table
** - If the INGEST command specifies the UPDATE statement (including as part of a
** MERGE statement), SELECT and UPDATE privilege on the target table
** - If the INGEST command specifies the DELETE statement (including as part of a
** MERGE statement), SELECT and DELETE privilege on the target table
** - If the INGEST command specifies the REPLACE clause, SELECT, DELETE, and
** INSERT privilege on the target table
** 
** SELECT privilege on the following catalog views:
** - SYSCAT.COLUMNS
** - SYSCAT.DATATYPES
** - SYSCAT.INDEXES
** - SYSCAT.INDEXCOLUSE
** - SYSCAT.SECURITYPOLICIES (if the target table has a security label column)
** - SYSCAT.TABDEP
** - SYSCAT.TABLES
** - SYSCAT.VIEWS
** Note that users have these privileges by default unless the database was
** created with option RESTRICTIVE.
** 
** If the target table has any triggers, the authorization ID must have
** sufficient privileges to execute the operations that the triggers specify.
** - To insert into or update a table that has protected columns, the
** authorization ID must have LBAC credentials that allow write access to all
** protected columns in the table.  Otherwise the command fails and an error is
** returned (message SQL20264N, SQLSTATE 42512).
** - If an UPDATE or MERGE statement requires reading a protected column, the
** authorization ID must have LBAC credentials that allow read access to the
** column.  Otherwise the command fails and an error is returned (message
** SQL20264N, SQLSTATE 42512).
** - To insert into or update a table that has protected rows, the authorization
** ID must hold an LBAC credential that meets these criteria:
** -- The LBAC credential is part of the security policy protecting the table.
** -- If the security policy was defined as RESTRICT NOT AUTHORIZED WRITE
** SECURITY LABEL, then:
** --- The LBAC credential was granted to the authorization ID for write access.
** The label on the row to insert, the user's LBAC credentials, the security
** policy definition, and the LBAC rules determine the label on the row.
** 
** If the INGEST command specifies the RESTART NEW (the default) or RESTART
** CONTINUE option, then SELECT, INSERT, UPDATE, and DELETE privilege on the
** restart table.
** 
** If the INGEST command specifies the RESTART TERMINATE option, then SELECT
** and DELETE privilege on the restart table.
** 
** If the INGEST command specifies the EXCEPTION TABLE clause, then INSERT
** privilege on the exception table.
** 
** In addition, the SQL statement on the INGEST command is subject to the same
** fine grained access controls (FGAC) that it would be if the user running the
** ingest utility accessed the table outside of the ingest utility.
** 
** The user running the CLP must have the following file permissions:
** - If the INGEST command specifies the MESSAGES clause, then:
** -- Write access to the directory containing the messages file
** -- If the messages file already exists, then write access to the file
** - If the INGEST command specifies the DUMPFILE clause, then:
** -- Write access to the directory containing the dump file
** -- If the dump file already exists, then write access to the file
** 
** Required connection
** 
** Database.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Ingest API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter pIngestStruct.
** 
** pIngestStruct
** Input/Output. A pointer to the db2IngestStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Ingest                    */
  db2Ingest (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pIngestStruct,                         /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* db2gIngest - Generic API                                                   */
/******************************************************************************
** db2gIngest API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Ingest                    */
  db2gIngest (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pIngestStruct,                         /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gIngestCfgParam data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gIngestCfgParam
{
   db2Uint32                           iCfgParam; /* The configuration        */
                                                 /* parameter.                */
   db2Uint32                           iCfgParamValue; /* The value of the    */
                                                 /* configuration parameter.  */
} db2gIngestCfgParam;

/******************************************************************************
** db2gIngestCfgList data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gIngestCfgList
{
   struct db2gIngestCfgParam           *piCfgParam; /* Pointer to an array.   */
   db2Uint32                           iNumCfgParams; /* The number of        */
                                                 /* elements in the array.    */
} db2gIngestCfgList;

/******************************************************************************
** db2gIngestFieldDefn data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gIngestFieldDefn
{
   struct db2Char                      *piDatetimeFormat; /* The date time    */
                                                 /* format string.            */
   struct db2Char                      *piName;  /* The field name            */
   db2Uint32                           iStartPos; /* The field start          */
                                                 /* position.                 */
   db2Uint32                           iEndPos;  /* The field end position.   */
   db2Uint32                           iLength;  /* The field length.         */
   db2Uint32                           iExternal; /* Boolean true if          */
                                                 /* external truncation       */
                                                 /* length specified.         */
   db2Uint32                           iDecimalFormat; /* Format of a         */
                                                 /* DECIMAL field             */
   db2Uint32                           iScale;   /* Scale of a DECIMAL field  */
   db2Uint32                           iPrecision; /* Precision of a          */
                                                 /* DECIMAL, REAL, FLOAT or   */
                                                 /* DECFLOAT field            */
   db2Uint32                           iEndian;  /* The endianness.           */
   db2Uint32                           iForBitData; /* Set if bit data.       */
   db2Uint32                           iTrim;    /* Trim policy.              */
   db2Uint32                           iDefaultIfPos; /* Position in input    */
                                                 /* record if defaultif is    */
                                                 /* set.                      */
   db2Uint16                           iType;    /* The field type.           */
   char                                iDefaultIfChar; /* The DEFAULTIF       */
                                                 /* character.                */
   char                                iEnclosedBy; /* The character that     */
                                                 /* encloses the data in the  */
                                                 /* input source.             */
   char                                iRadixPoint; /* The radix point.       */
   char                                iReserved[3]; /* Reserved for future   */
                                                 /* use, must be 0            */
   db2Uint32                           iDefaultIfNull; /* Set to boolean      */
                                                 /* true to use column        */
                                                 /* default value when input  */
                                                 /* field is empty            */
} db2gIngestFieldDefn;

/******************************************************************************
** db2gIngestFormat data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gIngestFormat
{
   struct db2gIngestFieldDefn          *piFieldDefn; /* Pointer to an array   */
                                                 /* of field definition       */
                                                 /* structs.                  */
   struct db2Char                      *piFileType; /* The format of the      */
                                                 /* input source.             */
   db2Uint32                           iRecordLength; /* The record length.   */
   db2Uint32                           iNumFields; /* The number of elements  */
                                                 /* in the array that         */
                                                 /* piFieldDefn points to.    */
   db2Uint16                           iCodepage; /* The codepage of the      */
                                                 /* input file.               */
   db2Uint16                           iImplicitlyHidden; /* Specifiy         */
                                                 /* behaviour for Implicitly  */
                                                 /* hidden columns            */
   char                                iDelimiter; /* The delimiter.          */
   char                                iReserved3Bytes[3]; /* Reserved for    */
                                                 /* future use, should be 0.  */
   db2Uint32                           iRadixPointImplied; /* Boolean true    */
                                                 /* if the location of the    */
                                                 /* radix point is implied    */
                                                 /* by the field definition.  */
   db2Uint32                           iDelPriorityChar; /* Boolean true if   */
                                                 /* DELIMITED PRIORITY CHAR   */
                                                 /* is specified.             */
   db2Uint32                           iNoCharDel; /* Boolean true if NO      */
                                                 /* CHAR DELIMITER is         */
                                                 /* specified.                */
} db2gIngestFormat;

/******************************************************************************
** db2gIngestOut data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gIngestOut
{
   db2Uint64                           oRowsRead; /* Rows read                */
   db2Uint64                           oRowsSkipped; /* Rows skipped (always  */
                                                 /* 0)                        */
   db2Uint64                           oRowsInserted; /* Rows inserted        */
   db2Uint64                           oRowsUpdated; /* Rows updated          */
   db2Uint64                           oRowsDeleted; /* Rows deleted          */
   db2Uint64                           oRowsMerged; /* Rows merged            */
   db2Uint64                           oRowsRejected; /* Rows rejected        */
   db2Uint64                           oNumErrors; /* Number of errors        */
   db2Uint64                           oNumWarnings; /* Number of warnings    */
   db2Uint64                           oMaxMsgSeverity; /* Max message        */
                                                 /* severity                  */
} db2gIngestOut;

/******************************************************************************
** db2gIngestStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gIngestStruct
{
   struct db2gIngestCfgList            *piCfgList; /* Pointer to ingest       */
                                                 /* configuration parameters  */
                                                 /* struct.                   */
   struct sqlu_media_list              *piSourceList; /* The input sources.   */
   struct db2gIngestFormat             *piFormat; /* Pointer to ingest        */
                                                 /* format struct.            */
   struct db2gIngestOut                *poIngestInfoOut; /* Ingest output     */
                                                 /* structure                 */
   struct db2Char                      *piDumpFile; /* Pointer to the dump    */
                                                 /* file name.                */
   struct db2Char                      *piExceptTableName; /* Pointer to the  */
                                                 /* name of the exception     */
                                                 /* table.If there is no      */
                                                 /* exception table, set      */
                                                 /* this to NULL.             */
   struct db2Char                      *piMsgFileName; /* Pointer to the      */
                                                 /* messages file name.       */
   struct db2Char                      *piJobId; /* Pointer to the job ID,    */
                                                 /* null-terminated.          */
   struct db2Char                      *piSqlStatement; /* Pointer to the     */
                                                 /* SQL statement, null       */
                                                 /* terminated.               */
   db2Uint32                           iWarningcount; /* The warning count.   */
   db2Uint32                           iRestartMode; /* The restart option.   */
   db2Uint32                           iSourceType; /* The source type.       */
   db2Uint32                           iListenPort; /* The port to connect    */
                                                 /* to.                       */
} db2gIngestStruct;

/* Export Structures and Constants                                            */

/* Export input structure                                                     */
/******************************************************************************
** db2ExportIn data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2ExportIn
{
   db2Uint16                           *piXmlSaveSchema; /* Save XML schemas  */
                                                 /* used to validate XML      */
                                                 /* documents                 */
} db2ExportIn;

/* Export output structure                                                    */
/******************************************************************************
** db2ExportOut data structure
** db2ExportOut data structure parameters
** 
** oRowsExported
** Output. Returns the number of records exported to the target file.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ExportOut
{
   db2Uint64                           oRowsExported; /* Rows Exported        */
} db2ExportOut;

/* db2Export parameter structure                                              */
/******************************************************************************
** db2ExportStruct data structure
** db2ExportStruct data structure parameters
** 
** piDataFileName
** Input. A string containing the path and the name of the external file into
** which the data is to be exported.
** 
** piLobPathList
** Input. An sqlu_media_list using media_type SQLU_LOCAL_MEDIA, and the
** sqlu_media_entry structure listing paths on the client where the LOB files
** are to be stored.
** 
** When file space is exhausted on the first path in this list, the API will use
** the second path, and so on.
** 
** piLobFileList
** Input. An sqlu_media_list using media_type SQLU_CLIENT_LOCATION, and
** the sqlu_location_entry structure containing base file names.
** 
** When the name space is exhausted using the first name in this list, the
** API will use the second name, and so on.
** 
** When creating LOB files during an export operation, file names are
** constructed by appending the current base name from this list to the
** current path (from pLobFilePath), and then appending a 3-digit sequence
** number. For example, if the current LOB path is the directory
** /u/foo/lob/path, and the current LOB file name is bar, the created LOB
** files will be /u/foo/lob/path/bar.001, /u/foo/lob/pah/bar.002, and so on.
** 
** piDataDescriptor
** Input. Pointer to an sqldcol structure specifying the column names for
** the output file. The value of the dcolmeth field determines how the
** remainder of the information provided in this parameter is interpreted by
** the export utility. Valid values for this parameter (defined in sqlutil
** header file, located in the include directory) are:
** 
** - SQL_METH_N
** Names. Specify column names to be used in the output file.
** 
** - SQL_METH_D
** Default. Existing column names from the table are to be used in
** the output file. In this case, the number of columns and the
** column specification array are both ignored. The column names
** are derived from the output of the SELECT statement specified in
** pActionString.
** 
** piActionString
** Input. Pointer to an sqllob structure containing a valid dynamic SQL
** SELECT statement. The structure contains a 4-byte long field, followed
** by the characters that make up the SELECT statement. The SELECT
** statement specifies the data to be extracted from the database and
** written to the external file.
** 
** The columns for the external file (from piDataDescriptor), and the
** database columns from the SELECT statement, are matched according
** to their respective list/structure positions. The first column of data
** selected from the database is placed in the first column of the external
** file, and its column name is taken from the first element of the external
** column array.
** 
** piFileType
** Input. A string that indicates the format of the data within the
** external file. Supported external file formats (defined in sqlutil
** header file) are:
** 
** - SQL_DEL
** Delimited ASCII, for exchange with dBase, BASIC, and the IBM
** Personal Decision Series programs, and many other database
** managers and file managers.
** 
** - SQL_WSF
** Worksheet formats for exchange with Lotus Symphony and 1-2-3
** programs.
** 
** - SQL_IXF
** PC version of the Integrated Exchange Format, the preferred
** method for exporting data from a table. Data exported to this file
** format can later be imported or loaded into the same table or
** into another database manager table.
** 
** piFileTypeMod
** Input. A pointer to an sqldcol structure containing a 2-byte long field,
** followed by an array of characters that specify one or more processing
** options. If this pointer is NULL, or the structure pointed to has zero
** characters, this action is interpreted as selection of a default
** specification.
** 
** Not all options can be used with all of the supported file types. See
** related link below: "File type modifiers for the export utility."
** 
** piMsgFileName
** Input. A string containing the destination for error, warning, and
** informational messages returned by the utility. It can be the path and the
** name of an operating system file or a standard device. If the file already
** exists, the information is appended . If it does not exist, a file
** is created.
** 
** iCallerAction
** Input. An action requested by the caller. Valid values (defined in sqlutil
** header file, located in the include directory) are:
** 
** - SQLU_INITIAL
** Initial call. This value must be used on the first call to the API.
** 
** If the initial call or any subsequent call returns and requires the calling
** application to perform some action prior to completing the requested
** export operation, the caller action must be set to one of the following:
** 
** - SQLU_CONTINUE
** Continue processing. This value can only be used on subsequent
** calls to the API, after the initial call has returned with the utility
** requesting user input (for example, to respond to an end of tape
** condition). It specifies that the user action requested by the
** utility has completed, and the utility can continue processing the
** initial request.
** 
** - SQLU_TERMINATE
** Terminate processing. This value can only be used on
** subsequent calls to the API, after the initial call has returned
** with the utility requesting user input (for example, to respond to
** an end of tape condition). It specifies that the user action
** requested by the utility was not performed, and the utility is to
** terminate processing the initial request.
** 
** poExportInfoOut
** A pointer to the db2ExportOut structure.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ExportStruct
{
   char                                *piDataFileName; /* Data file name     */
   struct sqlu_media_list              *piLobPathList; /* Lob file paths      */
   struct sqlu_media_list              *piLobFileList; /* Lob file lists      */
   struct sqldcol                      *piDataDescriptor; /* Data descriptor  */
                                                 /* list                      */
   struct sqllob                       *piActionString; /* Export action      */
                                                 /* string                    */
   char                                *piFileType; /* File type (ASC, DEL,   */
                                                 /* IXF, WSF, etc.)           */
   struct sqlchar                      *piFileTypeMod; /* File type modifier  */
                                                 /* string                    */
   char                                *piMsgFileName; /* Message filename    */
   db2int16                            iCallerAction; /* Caller action        */
   struct db2ExportOut                 *poExportInfoOut; /* Export output     */
                                                 /* structure                 */
   struct db2ExportIn                  *piExportInfoIn; /* Export input       */
                                                 /* structure                 */
   struct sqlu_media_list              *piXmlPathList; /* XML file paths      */
   struct sqlu_media_list              *piXmlFileList; /* XML file lists      */
} db2ExportStruct;

/******************************************************************************
** db2Export API
** Exports data from a database to one of several external file formats.
** The user specifies the data to be exported by supplying an SQL SELECT
** statement, or by providing hierarchical information for typed tables.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - dbadm
** 
** or CONTROL or SELECT privilege on each participating table or view.
** 
** Required connection
** 
** Database. If implicit connect is enabled, a connection to the default
** database is established.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Export API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2ExportStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Before starting an export operation, you must complete all table operations
** and release all locks in one of two ways:
** - Close all open cursors that were defined with the WITH HOLD clause, and
** commit the data changes by executing the COMMIT statement.
** - Roll back the data changes by executing the ROLLBACK statement.
** 
** Table aliases can be used in the SELECT statement.
** 
** The messages placed in the message file include the information returned
** from the message retrieval service. Each message begins on a new line.
** 
** If the export utility produces warnings, the message will be written out
** to a message file, or standard output if one is not specified.
** 
** A warning message is issued if the number of columns (dcolnum field of
** sqldcol structure) in the external column name array, piDataDescriptor,
** is not equal to the number of columns generated by the SELECT statement.
** In this case, the number of columns written to the external file is the
** lesser of the two numbers. Excess database columns or external column
** names are not used to generate the output file.
** 
** If the db2uexpm.bnd module or any other shipped .bnd files are bound
** manually, the format option on the binder must not be used.
** 
** DB2 Connect can be used to export tables from DRDA servers such as DB2 for
** z/OS and OS/390, DB2 for VM and VSE, and DB2 for iSeries. Only PC/IXF export
** is supported.
** 
** PC/IXF import should be used to move data between databases. If character
** data containing row separators is exported to a delimited ASCII (DEL) file
** and processed by a text transfer program, fields containing the row
** separators will shrink or expand.
** 
** The export utility will not create multiple-part PC/IXF files when invoked
** from an AIX system.
** 
** Index definitions for a table are included in the PC/IXF file when the
** contents of a single database table are exported to a PC/IXF file with a
** pActionString parameter beginning with SELECT * FROM tablename, and the
** piDataDescriptor parameter specifying default names. Indexes are not
** saved for views, or if the SELECT clause of the piActionString includes a
** join. A WHERE clause, a GROUP BY clause, or a HAVING clause in the
** piActionString parameter will not prevent the saving of indexes. In all of
** these cases, when exporting from typed tables, the entire hierarchy must
** be exported.
** 
** The export utility will store the NOT NULL WITH DEFAULT attribute of the
** table in an IXF file if the SELECT statement provided is in the form: 
** SELECT * FROM tablename.
** 
** When exporting typed tables, subselect statements can only be expressed by
** specifying 7the target table name and the WHERE clause. Fullselect and
** select-statement cannot be specified when exporting a hierarchy.
** 
** For file formats other than IXF, it is recommended that the traversal
** order list be specified, because it tells DB2 how to traverse the
** hierarchy, and what sub-tables to export. If this list is not specified,
** all tables in the hierarchy are exported, and the default order is the
** OUTER order. The alternative is to use the default order, which is the
** order given by the OUTER function.
** 
** Note:
** Use the same traverse order during an import operation. The load utility does
** not support loading hierarchies or sub-hierarchies.
** 
** DB2 Data Links Manager considerations
** 
** To ensure that a consistent copy of the table and the corresponding files
** referenced by the DATALINK columns are copied for export, do the following:
** 1. Issue the command: QUIESCE TABLESPACES FOR TABLE tablename
** SHARE.
** 
** This ensures that no update transactions are in progress when EXPORT is
** run.
** 
** 2. Issue the EXPORT command.
** 
** 3. Run the dlfm_export utility at each Data Links server. Input to the
** dlfm_export utility is the control file name, which is generated by the
** export utility. This produces a tar (or equivalent) archive of the files
** listed within the control file. dlfm_export does not capture the ACLs
** information of the files that are archived.
** 
** 4. Issue the command: QUIESCE TABLESPACES FOR TABLE tablename
** RESET.
** 
** This makes the table available for updates.
** 
** EXPORT is executed as an SQL application. The rows and columns satisfying the
** SELECT statement conditions are extracted from the database. For the
** DATALINK columns, the SELECT statement should not specify any scalar
** function.
** 
** Successful execution of EXPORT results in generation of the following files:
** - An export data file as specified in the EXPORT command. A DATALINK
** column value in this file has the same format as that used by the IMPORT
** and LOAD utilities. When the DATALINK column value is the SQL NULL
** value, handling is the same as that for other data types.
** 
** - Control files server_name, which are generated for each Data Links server.
** On the Windows operating system, a single control file, ctrlfile.lst, is
** used by all Data Links servers. These control files are placed in the
** directory <data-file path>/dlfm/YYYYMMDD/HHMMSS (on the Windows
** operating system, ctrlfile.lst is placed in the directory <data-file
** path>\dlfm\YYYYMMDD\HHMMSS). YYYYMMDD represents the date
** (year month day), and HHMMSS represents the time (hour minute second).
** 
** REXX API syntax
** 
** EXPORT :stmt TO datafile OF filetype
** [MODIFIED BY :filetmod] [USING :dcoldata]
** MESSAGES msgfile [ROWS EXPORTED :number]
** 
** CONTINUE EXPORT
** 
** STOP EXPORT
** 
** REXX API parameters
** 
** stmt
** A REXX host variable containing a valid dynamic SQL SELECT statement. The
** statement specifies the data to be extracted from the database.
** 
** datafile
** Name of the file into which the data is to be exported.
** 
** filetype
** The format of the data in the export file. The supported file formats are:
** - DEL
** Delimited ASCII
** - WSF
** Worksheet format
** - IXF
** PC version of Integrated Exchange Format.
** 
** filetmod
** A host variable containing additional processing options.
** 
** dcoldata
** A compound REXX host variable containing the column names to be used in the
** export file. In the following, XXX represents the name of the host variable:
** - XXX.0
** Number of columns (number of elements in the remainder of the variable).
** - XXX.1
** First column name.
** - XXX.2
** Second column name.
** - XXX.3
** and so on.
** 
** If this parameter is NULL, or a value for dcoldata has not been
** specified, the utility uses the column names from the database table.
** 
** msgfile
** File, path, or device name where error and warning messages are to be sent.
** 
** number
** A host variable that will contain the number of exported rows.
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Export                    */
  db2Export (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* db2gExport parameter structure                                             */
/******************************************************************************
** db2gExportStruct data structure
** db2gExportStruct data structure specific parameters
** 
** iDataFileNameLen
** Input. A 2-byte unsigned integer representing the length in bytes of the
** data file name.
** 
** iFileTypeLen
** Input. A 2-byte unsigned integer representing the length in bytes of the
** file type.
** 
** iMsgFileNameLen
** Input. A 2-byte unsigned integer representing the length in bytes of the
** message file name.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gExportStruct
{
   char                                *piDataFileName; /* Data file name     */
   struct sqlu_media_list              *piLobPathList; /* Lob file paths      */
   struct sqlu_media_list              *piLobFileList; /* Lob file files      */
   struct sqldcol                      *piDataDescriptor; /* Data descriptor  */
                                                 /* list                      */
   struct sqllob                       *piActionString; /* Export action      */
                                                 /* string                    */
   char                                *piFileType; /* File type (ASC, DEL,   */
                                                 /* IXF, WSF, etc.)           */
   struct sqlchar                      *piFileTypeMod; /* File type modifier  */
                                                 /* string                    */
   char                                *piMsgFileName; /* Message filename    */
   db2int16                            iCallerAction; /* Caller action        */
   struct db2ExportOut                 *poExportInfoOut; /* Export output     */
                                                 /* structure                 */
   db2Uint16                           iDataFileNameLen; /* Length of         */
                                                 /* piDataFileName string     */
   db2Uint16                           iFileTypeLen; /* Length of piFileType  */
                                                 /* string                    */
   db2Uint16                           iMsgFileNameLen; /* Length of          */
                                                 /* piMsgFileName string      */
   struct db2ExportIn                  *piExportInfoIn; /* Export input       */
                                                 /* structure                 */
   struct sqlu_media_list              *piXmlPathList; /* XML file paths      */
   struct sqlu_media_list              *piXmlFileList; /* XML file lists      */
} db2gExportStruct;

/* db2gExport - Generic API                                                   */
/******************************************************************************
** db2gExport API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Export                    */
  db2gExport (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Open History Scan Definitions                                              */

/* Values for db2HistoryOpen - iCallerAction                                  */
#define DB2HISTORY_LIST_HISTORY        0
#define DB2HISTORY_LIST_BACKUP         1
#define DB2HISTORY_LIST_ROLLFORWARD    2
#define DB2HISTORY_LIST_REORG          4
#define DB2HISTORY_LIST_ALT_TABLESPACE 5
#define DB2HISTORY_LIST_DROPPED_TABLE  6
#define DB2HISTORY_LIST_LOAD           7
#define DB2HISTORY_LIST_REN_TABLESPACE 8
#define DB2HISTORY_LIST_CRT_TABLESPACE 9
#define DB2HISTORY_LIST_ARCHIVE_LOG    10

/* db2HistoryOpen input struct                                                */
/******************************************************************************
** db2HistoryOpenStruct data structure
** db2HistoryOpenStruct data structure parameters
** 
** piDatabaseAlias
** Input. A pointer to a string containing the database alias.
** 
** piTimestamp
** Input. A pointer to a string specifying the time stamp to be used for
** selecting records. Records whose time stamp is equal to or greater than
** this value are selected. Setting this parameter to NULL, or pointing to
** zero, prevents the filtering of entries using a time stamp.
** 
** piObjectName
** Input. A pointer to a string specifying the object name to be used for
** selecting records. The object may be a table or a table space. If it is a
** table, the fully qualified table name must be provided. Setting this
** parameter to NULL, or pointing to zero, prevents the filtering of entries
** using the object name.
** 
** oNumRows
** Output. Upon return from the API call, this parameter contains the number
** of matching history file entries.
** 
** oMaxTbspaces
** Output. The maximum number of table space names stored with any
** history entry.
** 
** oMaxLogStreams
** Output. The maximum number of log ranges (per log stream) stored with any
** history entry.
** 
** iCallerAction
** Input. Specifies the type of action to be taken. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** - DB2HISTORY_LIST_HISTORY
** Lists all events that are currently logged in the history file.
** - DB2HISTORY_LIST_BACKUP
** Lists backup and restore operations.
** - DB2HISTORY_LIST_ROLLFORWARD
** Lists rollforward operations.
** - DB2HISTORY_LIST_DROPPED_TABLE
** Lists dropped table records. The DDL field associated with an entry is
** not returned. To retrieve the DDL information for an entry,
** db2HistoryGetEntry must be called with a caller action of
** DB2HISTORY_GET_DDL immediately after the entry is fetched.
** - DB2HISTORY_LIST_LOAD
** Lists load operations.
** - DB2HISTORY_LIST_CRT_TABLESPACE
** Lists table space create and drop operations.
** - DB2HISTORY_LIST_REN_TABLESPACE
** Lists table space renaming operations.
** - DB2HISTORY_LIST_ALT_TABLESPACE
** Lists alter table space operations. The DDL field associated with an
** entry is not returned. To retrieve the DDL information for an entry,
** db2HistoryGetEntry must be called with a caller action of
** DB2HISTORY_GET_DDL immediately after the entry is fetched. 
** - DB2HISTORY_LIST_REORG
** Lists REORGANIZE TABLE operations. This value is not currently
** supported.
** 
** oHandle
** Output. Upon return from the API, this parameter contains the handle for
** scan access. It is subsequently used in the db2HistoryGetEntry, and
** db2HistoryCloseScan APIs.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryOpenStruct
{
   char                                *piDatabaseAlias; /* DB to fetch       */
                                                 /* history from              */
   char                                *piTimestamp; /* Since this timestamp  */
   char                                *piObjectName; /* Entries containing   */
                                                 /* this object               */
   db2Uint32                           oNumRows; /* # of entries matching     */
                                                 /* search                    */
   db2Uint32                           oMaxTbspaces; /* Max. # of tablespace  */
                                                 /* names stored with ANY     */
                                                 /* history entry             */
   db2Uint32                           oMaxLogStreams; /* Max. # of ranges    */
                                                 /* of log streams stored     */
                                                 /* with ANY history entry    */
   db2Uint16                           iCallerAction; /* Caller action        */
   db2Uint16                           oHandle;  /* Handle for this scan      */
} db2HistoryOpenStruct;


/******************************************************************************
** db2HistoryOpenScan API
** This API starts a history file scan.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Instance. If the database is cataloged as remote, call the sqleatin
** API before calling this API.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HistoryOpenScan API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input or Output. A pointer to the db2HistoryOpenStruct data structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The combination of time stamp, object name and caller action can be
** used to filter records. Only records that pass all specified filters
** are returned.
** 
** The filtering effect of the object name depends on the value specified:
** - Specifying a table will return records for load operations, because
** this is the only information for tables in the history file.
** - Specifying a table space will return records for backup, restore, and load
** operations for the table space.
** 
** Note:
** To return records for tables, they must be specified as schema.tablename.
** Specifying tablename will only return records for table spaces. 
** 
** A maximum of eight history file scans per process is permitted.
** 
** To list every entry in the history file, a typical application will
** perform the following steps:
** 
** 1. Call the db2HistoryOpenScan API, which returns parameter value
** oNumRows.
** 
** 2. Allocate a db2HistData structure with space for n oTablespace
** fields, where n is an arbitrary number.
** 
** 3. Set the iNumTablespaces field of the db2HistoryData structure to n.
** 
** 4. In a loop, perform the following:
** - Call the db2HistoryGetEntry API to fetch from the history file.
** - If db2HistoryGetEntry API returns an SQLCODE value of SQL_RC_OK, use the
** oNumTablespaces field of the db2HistoryData structure to determine the
** number of table space entries returned.
** - If db2HistoryGetEntry API returns an SQLCODE value of
** SQLUH_SQLUHINFO_VARS_WARNING, not enough space has been allocated
** for all of the table spaces that DB2 is trying to return; free and
** reallocate the db2HistoryData structure with enough space for
** oDB2UsedTablespace table space entries, and set iDB2NumTablespace
** to oDB2UsedTablespace.
** - If db2HistoryGetEntry API returns an SQLCODE value of SQLE_RC_NOMORE,
** all history file entries have been retrieved.
** - Any other SQLCODE indicates a problem.
** 
** 5. When all of the information has been fetched, call the
** db2HistoryCloseScan API to free the resources allocated by the call to
** db2HistoryOpenScan.
** 
** The macro SQLUHINFOSIZE(n) (defined in sqlutil header file) is provided to
** help determine how much memory is required for a db2HistoryData structure
** with space for n oTablespace entries.
** REXX API syntax
** 
** OPEN [BACKUP] RECOVERY HISTORY FILE FOR database_alias
** [OBJECT objname] [TIMESTAMP :timestamp]
** USING :value
** 
** REXX API parameters
** 
** database_alias
** The alias of the database that is to have its history file listed.
** 
** objname
** Specifies the object name to be used for selecting records. The object
** may be a table or a table space. If it is a table, the fully qualified
** table name must be provided. Setting this parameter to NULL prevents
** the filtering of entries using objname.
** 
** timestamp
** Specifies the time stamp to be used for selecting records. Records whose time
** stamp is equal to or greater than this value are selected. Setting this
** parameter to NULL prevents the filtering of entries using timestamp.
** 
** value
** A compound REXX host variable to which history file information is
** returned. In the following, XXX represents the host variable name.
** - XXX.0
** Number of elements in the variable (always 2)
** - XXX.1
** Identifier (handle) for future scan access
** - XXX.2
** Number of matching history file entries.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Open a history file scan            */
  db2HistoryOpenScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* db2gHistoryOpen input struct                                               */
/******************************************************************************
** db2gHistoryOpenStruct data structure
** db2gHistoryOpenStruct data structure specific parameters
** 
** iAliasLen
** Input. Specifies the length in bytes of the database alias string.
** 
** iTimestampLen
** Input. Specifies the length in bytes of the timestamp string.
** 
** iObjectNameLen
** Input. Specifies the length in bytes of the object name string.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gHistoryOpenStruct
{
   char                                *piDatabaseAlias; /* DB to fetch       */
                                                 /* history from              */
   char                                *piTimestamp; /* Since this timestamp  */
   char                                *piObjectName; /* Entries containing   */
                                                 /* this object               */
   db2Uint32                           iAliasLen; /* Length of database       */
                                                 /* alias string              */
   db2Uint32                           iTimestampLen; /* Length of timestamp  */
                                                 /* string                    */
   db2Uint32                           iObjectNameLen; /* Length of object    */
                                                 /* name string               */
   db2Uint32                           oNumRows; /* # of entries matching     */
                                                 /* search                    */
   db2Uint32                           oMaxTbspaces; /* Max. # of tablespace  */
                                                 /* names stored with ANY     */
                                                 /* history entry             */
   db2Uint32                           oMaxLogStreams; /* Max. # of ranges    */
                                                 /* of log streams stored     */
                                                 /* with ANY history entry    */
   db2Uint16                           iCallerAction; /* Caller action        */
   db2Uint16                           oHandle;  /* Handle for this scan      */
} db2gHistoryOpenStruct;

/* db2gHistoryOpenScan - Generic API                                          */
/******************************************************************************
** db2gHistoryOpenScan API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Open a history file scan            */
  db2gHistoryOpenScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Fetch Next History Entry Definitions                                       */

/* Structure db2HistoryEID                                                    */
/******************************************************************************
** db2HistoryEID data structure
** db2HistoryEID data structure parameters
** 
** ioNode
** This parameter can be used as either an input or output parameter.
** Indicates the database partition number.
** 
** ioHID
** This parameter can be used as either an input or output parameter.
** Indicates the local history file entry ID.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryEID
{
   SQL_PDB_NODE_TYPE                   ioNode;   /* database partition        */
                                                 /* number                    */
   db2Uint32                           ioHID;    /* Local history file entry  */
                                                 /* ID                        */
} db2HistoryEID;

/******************************************************************************
** db2HistoryLogStreamRange data structure
** This structure is used in the db2HistoryLogRange structure.
** 
** Table: Fields in the db2HistoryLogStreamRange Structure 
** ----------------------------------------------------------------------
** |Field Name      |Data Type |Description                              |
** |---------------------------------------------------------------------|
** |   oStreamID    |db2LogStreamIDType |Log stream ID of the log range  |
** |---------------------------------------------------------------------|
** |   oFirstLog    |DB2UINT32 |The earliest log file extent             |
** |                |          |                                         |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  for an online backup                   |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  for an offline backup                  |
** |                |          |- Applied after restoring a full database|
** |                |          |  or table space level backup that was   |
** |                |          |  current when the load started.         |
** |---------------------------------------------------------------------|
** |   oLastLog     |DB2UINT32 |The latest log file extent               |
** |                |          |                                         |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  for an online backup                   |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  to the current point in time for an    |
** |                |          |  offline backup                         |
** |                |          |- Applied after restoring a full database|
** |                |          |  or table space level backup that was   |
** |                |          |  current when the load operation        |
** |                |          |  finished (will be the same as oFirstLog|
** |                |          |  if roll forward recovery is not        |
** |                |          |  applied).                              |
** |---------------------------------------------------------------------|
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryLogStreamRange
{
   db2LogStreamIDType                  oStreamID; /* Log stream identifier    */
                                                 /* of a log file             */
   db2Uint32                           oFirstLog; /* Beginning Log Extent     */
                                                 /* Number                    */
   db2Uint32                           oLastLog; /* Final Log Extent Number   */
} db2HistoryLogStreamRange;

/******************************************************************************
** db2HistoryLogRange data structure
** db2HistoryLogRange data structure parameters
** 
** iNumLogStreams
** Allocated number of db2HistoryLogStreamRange's in oStream.
** 
** oNumLogStreams
** Number of valid log streams being returned in oStream.
** 
** oStream
** List of log ranges (by log stream).
** 
*******************************************************************************/
/******************************************************************************
** db2HistoryLogRange data structure
** This structure is used in the db2HistoryData structure.
** 
** Table: Fields in the db2HistoryLogRange Structure 
** ----------------------------------------------------------------------
** |Field Name      |Data Type |Description                              |
** |---------------------------------------------------------------------|
** | iNumLogStreams |DB2UINT32 |Allocated number of log streams in       |
** |                |          |oStream.                                 |
** |---------------------------------------------------------------------|
** | oNumLogStreams |DB2UINT32 |Number of valid log streams being        |
** |                |          |returned in oStream.                     |
** |---------------------------------------------------------------------|
** |   oStream      |db2HistoryLogStreamRange |List of log ranges        |
** |                |          |(by log stream)                          |
** |---------------------------------------------------------------------|
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryLogRange
{
   db2Uint32                           iNumLogStreams; /* Number of Log       */
                                                 /* streams                   */
   db2Uint32                           oNumLogStreams; /* Number of Log       */
                                                 /* streams                   */
   struct db2HistoryLogStreamRange     *oStream; /* list of log ranges by     */
                                                 /* log stream                */
} db2HistoryLogRange;

/* Max Sizes of db2HistoryDataStruct db2Char fields                           */
/* NOTE:  These lengths do not include NULL terminators                       */
#define DB2HISTORY_TIMESTAMP_SZ        14
#define DB2HISTORY_SEQNUM_SZ           3
#define DB2HISTORY_OBJPART_SZ          (DB2HISTORY_TIMESTAMP_SZ + DB2HISTORY_SEQNUM_SZ)
#define DB2HISTORY_LOGFILE_SZ          12
#define DB2HISTORY_ID_SZ               24
#define DB2HISTORY_TABLE_QUAL_SZ       128
#define DB2HISTORY_TABLE_NAME_SZ       128
#define DB2HISTORY_LOCATION_SZ         255
#define DB2HISTORY_COMMENT_SZ          30
#define DB2HISTORY_COMMAND_SZ          SQL_MAX_STMT_SIZ
#define DB2HISTORY_PRODUCT_ID_SZ       DB2HISTORY_COMMENT_SZ

/* Structure db2HistoryData                                                   */
/*                                                                            */
/* Description:                                                               */
/*      ioHistDataID      -- Eye catcher, must be set to "SQLUHINF"           */
/*                                                                            */
/*      oObjectPart       -- Start time + sequence number                     */
/*                        -- DB2HISTORY_OBJPART_SZ                            */
/*                                                                            */
/*      oEndTime          -- Completion timestamp                             */
/*                        -- DB2HISTORY_TIMESTAMP_SZ                          */
/*                                                                            */
/*      oFirstLog         -- First log file referrenced by event              */
/*                        -- DB2HISTORY_LOGFILE_SZ                            */
/*                                                                            */
/*      oLastLog          -- Last log file referrenced by event               */
/*                        -- DB2HISTORY_LOGFILE_SZ                            */
/*                                                                            */
/*      oID               -- Backup ID (timestamp), or unique table ID        */
/*                        -- DB2HISTORY_ID_SZ                                 */
/*                                                                            */
/*      oTableQualifier   -- Table qualifier                                  */
/*                        -- DB2HISTORY_TABLE_QUAL_SZ                         */
/*                                                                            */
/*      oTableName        -- Table name                                       */
/*                        -- DB2HISTORY_TABLE_NAME_SZ                         */
/*                                                                            */
/*      oLocation         -- Location of object used or produced by event     */
/*                        -- DB2HISTORY_LOCATION_SZ                           */
/*                                                                            */
/*      oComment          -- Text comment                                     */
/*                        -- DB2HISTORY_COMMENT_SZ                            */
/*                                                                            */
/*      oCommandText      -- Command text, or DDL                             */
/*                        -- DB2HISTORY_COMMAND_SZ                            */
/*                                                                            */
/*      oLastLSN          -- Last Log Sequence Number                         */
/*      poEventSQLCA      -- SQLCA returned at event completion               */
/*      poTablespace      -- LIST of tablespace names                         */
/*      iNumTablespaces   -- # of available entries in the poTablespace list  */
/*      oNumTablespaces   -- # of used entries in the poTablespace list       */
/*      ioLogRange        -- log file ranges for each log stream              */
/*      oEID              -- Unique history entry ID                          */
/*      oOperation        -- Event type:        DB2HISTORY_TYPE_*             */
/*      oObject           -- Event granularity: DB2HISTORY_GRAN_*             */
/*      oOptype           -- Event details:     DB2HISTORY_OPTYPE_*           */
/*      oStatus           -- Entry status:      DB2HISTORY_STATUS_*           */
/*      oDeviceType       -- Type of oLocation: DB2_MEDIA_*                   */

/******************************************************************************
** db2HistoryData data structure
** This structure is used to return information after a call to the
** db2HistoryGetEntry API.
** 
** Table: Fields in the db2HistoryData Structure 
** ----------------------------------------------------------------------
** |Field Name      |Data Type |Description                              |
** |---------------------------------------------------------------------|
** |ioHistDataID    |char(8)   |An 8-byte structure identifier and       |
** |                |          |"eye-catcher" for storage dumps. The     |
** |                |          |only valid value is SQLUHINF. No         |
** |                |          |symbolic definition for this string      |
** |                |          |exists.                                  |
** |---------------------------------------------------------------------|
** |oObjectPart     |db2Char   |The first 14 characters are a time stamp |
** |                |          |with format yyyymmddhhmmss, indicating   |
** |                |          |when the operation was begun. The next 3 |
** |                |          |characters are a sequence number. Each   |
** |                |          |backup operation can result in multiple  |
** |                |          |entries in this file when the backup     |
** |                |          |image is saved in multiple files or on   |
** |                |          |multiple tapes. The sequence number      |
** |                |          |allows multiple locations to be          |
** |                |          |specified. Restore and load operations   |
** |                |          |have only a single entry in this file,   |
** |                |          |which corresponds to sequence number     |
** |                |          |"001" of the corresponding backup. The   |
** |                |          |time stamp, combined with the sequence   |
** |                |          |number, must be unique.                  |
** |---------------------------------------------------------------------|
** |oEndTime        |db2Char   |A time stamp with format yyyymmddhhmmss, |
** |                |          |indicating when the operation was        |
** |                |          |completed.                               |
** |---------------------------------------------------------------------|
** |oFirstLog       |db2Char   |The earliest log file ID (ranging from   |
** |                |          |S0000000 to S9999999):                   |
** |                |          |                                         |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  for an online backup                   |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  for an offline backup                  |
** |                |          |- Applied after restoring a full database|
** |                |          |  or table space level backup that was   |
** |                |          |  current when the load started.         |
** |---------------------------------------------------------------------|
** |oLastLog        |db2Char   |The latest log file ID (ranging from     |
** |                |          |S0000000 to S9999999):                   |
** |                |          |                                         |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  for an online backup                   |
** |                |          |- Required to apply rollforward recovery |
** |                |          |  to the current point in time for an    |
** |                |          |  offline backup                         |
** |                |          |- Applied after restoring a full database|
** |                |          |  or table space level backup that was   |
** |                |          |  current when the load operation        |
** |                |          |  finished (will be the same as oFirstLog|
** |                |          |  if roll forward recovery is not        |
** |                |          |  applied).                              |
** |---------------------------------------------------------------------|
** |oID             |db2Char   |Unique backup or table identifier.       |
** |---------------------------------------------------------------------|
** |oTableQualifier |db2Char   |Table qualifier.                         |
** |---------------------------------------------------------------------|
** |oTableName      |db2Char   |Table name.                              |
** |---------------------------------------------------------------------|
** |oLocation       |db2Char   |For backups and load copies, this field  |
** |                |          |indicates where the data has been saved. |
** |                |          |For operations that require multiple     |
** |                |          |entries in the file, the sequence number |
** |                |          |defined by oObjectPart parameter         |
** |                |          |identifies which part of the backup is   |
** |                |          |found in the specified location. For     |
** |                |          |restore and load operations, the location|
** |                |          |always identifies where the first part of|
** |                |          |the data restored or loaded              |
** |                |          |(corresponding to sequence "001" for     |
** |                |          |multi-part backups) has been saved. The  |
** |                |          |data in oLocation is interpreted         |
** |                |          |differently, depending on oDeviceType    |
** |                |          |parameter:                               |
** |                |          |                                         |
** |                |          |-  For disk or diskette (D or K), a      |
** |                |          |   fully qualified file name             |
** |                |          |-  For tape (T), a volume label          |
** |                |          |-  For TSM (A), the server name          |
** |                |          |-  For user exit or other (U or O), free |
** |                |          |   form text.                            |
** |---------------------------------------------------------------------|
** |oComment        |db2Char   |Free form text comment.                  |
** |---------------------------------------------------------------------|
** |oCommandText    |db2Char   |Command text, or DDL.                    |
** |---------------------------------------------------------------------|
** |oLastLSN        |db2LSN    |Last log sequence number.                |
** |---------------------------------------------------------------------|
** |oEID            |Structure |Unique entry identifier.                 |
** |---------------------------------------------------------------------|
** |poEventSQLCA    |Structure |Result sqlca of the recorded event.      |
** |---------------------------------------------------------------------|
** |poTablespace    |db2Char   |A list of table space names.             |
** |---------------------------------------------------------------------|
** |iNumTablespaces |db2Uint32 |Number of entries in the poTablespace    |
** |                |          |list that are available for use by the   |
** |                |          |db2HistoryGetEntry API.                  |
** |---------------------------------------------------------------------|
** |oNumTablespaces |db2Uint32 |Number of entries in the poTablespace    |
** |                |          |list that were used by the               |
** |                |          |db2HistoryGetEntry API. Each table space |
** |                |          |backup contains one or more table spaces.|
** |                |          |Each table space restore operation       |
** |                |          |replaces one or more table spaces. If    |
** |                |          |this field is not zero (indicating a     |
** |                |          |table space level backup or restore), the|
** |                |          |next lines in this file contain the name |
** |                |          |of the table space backed up or restored,|
** |                |          |represented by an 18-character string.   |
** |                |          |One table space name appears on each     |
** |                |          |line.                                    |
** |---------------------------------------------------------------------|
** |ioLogRange      |db2HistoryLogRange| Log ranges for each log stream. |
** |---------------------------------------------------------------------|
** |oOperation      |char      |See following table.                     |
** |---------------------------------------------------------------------|
** |oObject         |char      |Granularity of the operation: D for full |
** |                |          |database, P for table space, and T for   |
** |                |          |table.                                   |
** |---------------------------------------------------------------------|
** |oOptype         |char      |See the table titled "Valid oOptype      |
** |                |          |Values in the db2HistData Structure".    |
** |---------------------------------------------------------------------|
** |oStatus         |char      |Entry status: A for action, D for deleted|
** |                |          |(future use), P for Pending Delete, E for|
** |                |          |expired, I for inactive, N for not yet   |
** |                |          |committed, Y for committed or active, a  |
** |                |          |for active backup, but some datalink     |
** |                |          |servers have not yet completed the backup|
** |                |          |, and i for inactive backup, but some    |
** |                |          |datalink servers have not yet completed  |
** |                |          |the backup.                              |
** |---------------------------------------------------------------------|
** |oDeviceType     |char      |Device type. This field determines how   |
** |                |          |the oLocation field is interpreted: A for|
** |                |          |TSM, C for client, D for disk, K for     |
** |                |          |diskette, L for local, O for other (for  |
** |                |          |other vendor device support), P for pipe,|
** |                |          |Q for cursor, S for server, T for tape,  |
** |                |          |and U for user exit.                     |
** |---------------------------------------------------------------------|
** 
** Table: Valid oOperation Values in the db2HistoryData Structure
** --------------------------------------------------------------------------
** |Value|Description       |C Definition           |COBOL/FORTRAN Definition|
** |-----|------------------|-----------------------|------------------------|
** |A    |add table space   |DB2HISTORY_OP_ADD_     |DB2HIST_OP_ADD_         |
** |     |                  |TABLESPACE             |TABLESPACE              |
** |-----|------------------|-----------------------|------------------------|
** |B    |backup            |DB2HISTORY_OP_BACKUP   |DB2HIST_OP_BACKUP       |
** |-----|------------------|-----------------------|------------------------|
** |C    |load copy         |DB2HISTORY_OP_LOAD_COPY|DB2HIST_OP_LOAD_COPY    |
** |-----|------------------|-----------------------|------------------------|
** |D    |dropped table     |DB2HISTORY_OP_DROPPED_ |DB2HIST_OP_DROPPED_TABLE|
** |     |                  |TABLE                  |                        |
** |-----|------------------|-----------------------|------------------------|
** |F    |rollforward       |DB2HISTORY_OP_ROLLFWD  |DB2HIST_OP_ROLLFWD      |
** |-----|------------------|-----------------------|------------------------|
** |G    |reorganize table  |DB2HISTORY_OP_REORG    |DB2HIST_OP_REORG        |
** |-----|------------------|-----------------------|------------------------|
** |L    |load              |DB2HISTORY_OP_LOAD     |DB2HIST_OP_LOAD         |
** |-----|------------------|-----------------------|------------------------|
** |M    |merged backup     |DB2HISTORY_OP_         |DB2HIST_OP_MERGEBACKUP  |
** |     |                  |MERGEBACKUP            |                        |
** |-----|------------------|-----------------------|------------------------|
** |N    |rename table space|DB2HISTORY_OP_REN_     |DB2HIST_OP_REN_         |
** |     |                  |TABLESPACE             |TABLESPACE              |
** |-----|------------------|-----------------------|------------------------|
** |O    |drop table space  |DB2HISTORY_OP_DROP_    |DB2HIST_OP_DROP_        |
** |     |                  |TABLESPACE             |TABLESPACE              |
** |-----|------------------|-----------------------|------------------------|
** |Q    |quiesce           |DB2HISTORY_OP_QUIESCE  |DB2HIST_OP_QUIESCE      |
** |-----|------------------|-----------------------|------------------------|
** |R    |restore           |DB2HISTORY_OP_RESTORE  |DB2HIST_OP_RESTORE      |
** |-----|------------------|-----------------------|------------------------|
** |T    |alter table space |DB2HISTORY_OP_ALT_     |DB2HIST_OP_ALT_TBS      |
** |     |                  |TABLESPACE             |                        |
** |-----|------------------|-----------------------|------------------------|
** |U    |unload            |DB2HISTORY_OP_UNLOAD   |DB2HIST_OP_UNLOAD       |
** |     |                  |                       |                        |
** |-----|------------------|-----------------------|------------------------|
** 
** Table: Valid oOptype Values in the db2HistData Structure
** -----------------------------------------------------------
** |oOperation|oOptype|Description|C/COBOL/FORTRAN Definition|
** |----------|-------|-----------|--------------------------|
** |B         |F      |offline    |DB2HISTORY_OPTYPE_OFFLINE |
** |          |N      |online     |DB2HISTORY_OPTYPE_ONLINE  |
** |          |I      |incremental|DB2HISTORY_OPTYPE_INCR_   |
** |          |       |offline    |OFFLINE                   |
** |          |O      |incremental|DB2HISTORY_OPTYPE_INCR_   |
** |          |       |online     |ONLINE                    |
** |          |D      |delta      |DB2HISTORY_OPTYPE_DELTA_  |
** |          |       |offline    |OFFLINE                   |
** |          |E      |delta      |DB2HISTORY_OPTYPE_DELTA_  |
** |          |       |online     |ONLINE                    |
** |----------|-------|-----------|--------------------------|
** |F         |E      |end of logs|DB2HISTORY_OPTYPE_EOL     |
** |          |P      |point in   |DB2HISTORY_OPTYPE_PIT     |
** |          |       |time       |                          |
** |----------|-------|-----------|--------------------------|
** |G         |F      |offline    |DB2HISTORY_OPTYPE_OFFLINE |
** |          |N      |online     |DB2HISTORY_OPTYPE_ONLINE  |
** |----------|-------|-----------|--------------------------|
** |L         |I      |insert     |DB2HISTORY_OPTYPE_INSERT  |
** |          |R      |replace    |DB2HISTORY_OPTYPE_REPLACE |
** |----------|-------|-----------|--------------------------|
** |Q         |S      |quiesce    |DB2HISTORY_OPTYPE_SHARE   |
** |          |       |share      |                          |
** |          |U      |quiesce    |DB2HISTORY_OPTYPE_UPDATE  |
** |          |       |update     |                          |
** |          |X      |quiesce    |DB2HISTORY_OPTYPE_EXCL    |
** |          |       |exclusive  |                          |
** |          |Z      |quiesce    |DB2HISTORY_OPTYPE_RESET   |
** |          |       |reset      |                          |
** |----------|-------|-----------|--------------------------|
** |R         |F      |offline    |DB2HISTORY_OPTYPE_OFFLINE |
** |          |N      |online     |DB2HISTORY_OPTYPE_ONLINE  |
** |          |I      |incremental|DB2HISTORY_OPTYPE_INCR_   |
** |          |       |offline    |OFFLINE                   |
** |          |O      |incremental|DB2HISTORY_OPTYPE_INCR_   |
** |          |       |online     |ONLINE                    |
** |----------|-------|-----------|--------------------------|
** |T         |C      |add        |DB2HISTORY_OPTYPE_ADD_CONT|
** |          |       |containers |                          |
** |          |R      |rebalance  |DB2HISTORY_OPTYPE_REB     |
** |----------|-------|-----------|--------------------------|
** 
** Table: Fields in the db2HistoryEID Structure
** ------------------------------------------------------------
** |Field Name|Data Type         | Description                 |
** |----------|------------------|-----------------------------|
** |ioNode    | SQL_PDB_NODE_TYPE| Database partition number.  |
** |ioHID     | db2Uint32        | Local history file entry ID.|
** |----------|------------------|-----------------------------|
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryData
{
   char                                ioHistDataID[8]; /* Eye catcher =      */
                                                 /* 'SQLUHINF'                */
   db2Char                             oObjectPart; /* Start time + sequence  */
                                                 /* number                    */
   db2Char                             oEndTime; /* Completion time of event  */
   db2Char                             oID;      /* Backup ID, or unique      */
                                                 /* table ID                  */
   db2Char                             oTableQualifier; /* Table qualifier    */
   db2Char                             oTableName; /* Table name              */
   db2Char                             oLocation; /* Location of referrenced  */
                                                 /* object                    */
   db2Char                             oComment; /* Text comment              */
   db2Char                             oCommandText; /* Command text          */
   db2LSN                              oLastLSN; /* Last log sequence number  */
   db2HistoryEID                       oEID;     /* Unique entry ID           */
   struct sqlca                        *poEventSQLCA; /* Resulting SQLCA of   */
                                                 /* event                     */
   struct db2Char                      *poTablespace; /* List of tablespace   */
                                                 /* names                     */
   db2Uint32                           iNumTablespaces; /* I: # of available  */
                                                 /* poTablespace fields       */
   db2Uint32                           oNumTablespaces; /* O: # of used       */
                                                 /* poTablespace fields       */
   db2HistoryLogRange                  ioLogRange; /* Log ranges 1 per        */
                                                 /* stream                    */
   char                                oOperation; /* Event type              */
   char                                oObject;  /* Operation granularity     */
   char                                oOptype;  /* Operation details         */
   char                                oStatus;  /* Status of entry           */
   char                                oDeviceType; /* Device type of         */
                                                 /* 'location'                */
} db2HistoryData;

/* Values for db2HistoryGetEntry - iCallerAction                              */
#define DB2HISTORY_GET_ENTRY 0     /* Next entry, without command data        */
#define DB2HISTORY_GET_DDL   1     /* ONLY command data from previous fetch   */
#define DB2HISTORY_GET_ALL   2     /* Next entry, with all data               */

/* db2HistoryGetEntry input struct                                            */
/******************************************************************************
** db2HistoryGetEntryStruct data structure
** db2HistoryGetEntryStruct data structure parameters
** 
** pioHistData
** Input. A pointer to the db2HistData structure.
** 
** iHandle
** Input. Contains the handle for scan access that was returned by the
** db2HistoryOpenScan API.
** 
** iCallerAction
** Input. Specifies the type of action to be taken. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** - DB2HISTORY_GET_ENTRY
** Get the next entry, but without any command data.
** - DB2HISTORY_GET_DDL
** Get only the command data from the previous fetch.
** - DB2HISTORY_GET_ALL
** Get the next entry, including all data.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryGetEntryStruct
{
   struct db2HistoryData               *pioHistData; /* History entry data    */
                                                 /* area                      */
   db2Uint16                           iHandle;  /* History scan handle       */
   db2Uint16                           iCallerAction; /* Caller action        */
} db2HistoryGetEntryStruct;

/******************************************************************************
** db2HistoryGetEntry API
** Gets the next entry from the history file. This API must be preceded by a
** successful call to the db2HistoryOpenScan API.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Instance. It is not necessary to call sqleatin before calling this API.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HistoryGetEntry API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2HistoryGetEntryStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The records that are returned will have been selected using the values
** specified in the call to the db2HistoryOpenScan API.
** 
** For a detailed description of the use of the history file APIs, refer
** to the db2HistoryOpenScan API.
** 
** REXX API syntax
** 
** GET RECOVERY HISTORY FILE ENTRY :scanid [USING :value]
** 
** REXX API parameters
** 
** scanid
** Host variable containing the scan identifier returned from OPEN RECOVERY
** HISTORY FILE SCAN.
** 
** value
** A compound REXX host variable into which the history file entry
** information is returned. In the following, XXX represents the host
** variable name:
** - XXX.0
** Number of first level elements in the variable (always 15)
** - XXX.1
** Number of table space elements
** - XXX.2
** Number of used table space elements
** - XXX.3
** OPERATION (type of operation performed)
** - XXX.4
** OBJECT (granularity of the operation)
** - XXX.5
** OBJECT_PART (time stamp and sequence number)
** - XXX.6
** OPTYPE (qualifier of the operation)
** - XXX.7
** DEVICE_TYPE (type of device used)
** - XXX.8
** FIRST_LOG (earliest log ID)
** - XXX.9
** LAST_LOG (current log ID)
** - XXX.10
** BACKUP_ID (identifier for the backup)
** - XXX.11
** SCHEMA (qualifier for the table name)
** - XXX.12
** TABLE_NAME (name of the loaded table)
** - XXX.13.0
** NUM_OF_TABLESPACES (number of table spaces involved in backup or restore)
** - XXX.13.1
** Name of the first table space backed up/restored
** - XXX.13.2
** Name of the second table space backed up/restored
** - XXX.13.3
** and so on
** - XXX.14
** LOCATION (where backup or copy is stored)
** - XXX.15
** COMMENT (text to describe the entry).
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Fetch the next history file entry   */
  db2HistoryGetEntry (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* db2gHistoryGetEntry - Generic API                                          */
/******************************************************************************
** db2gHistoryGetEntry API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Fetch the next history file entry   */
  db2gHistoryGetEntry (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* History Operations                                                         */
#define DB2HISTORY_OP_CRT_TABLESPACE   'A'
#define DB2HISTORY_OP_BACKUP           'B'
#define DB2HISTORY_OP_LOAD_COPY        'C'
#define DB2HISTORY_OP_DROPPED_TABLE    'D'
#define DB2HISTORY_OP_ROLLFWD          'F'
#define DB2HISTORY_OP_REORG            'G'
#define DB2HISTORY_OP_LOAD             'L'
#define DB2HISTORY_OP_MERGEBACKUP      'M'
#define DB2HISTORY_OP_REN_TABLESPACE   'N'
#define DB2HISTORY_OP_DROP_TABLESPACE  'O'
#define DB2HISTORY_OP_QUIESCE          'Q'
#define DB2HISTORY_OP_RESTORE          'R'
#define DB2HISTORY_OP_ALT_TABLESPACE   'T'
#define DB2HISTORY_OP_UNLOAD           'U'
#define DB2HISTORY_OP_ARCHIVE_LOG      'X'

/* History Objects                                                            */
#define DB2HISTORY_GRAN_DB             'D'
#define DB2HISTORY_GRAN_TBS            'P'
#define DB2HISTORY_GRAN_TABLE          'T'
#define DB2HISTORY_GRAN_RPTABLE        'R'
#define DB2HISTORY_GRAN_INDEX          'I'

/* Backup/Restore Optypes                                                     */
#define DB2HISTORY_OPTYPE_OFFLINE      'F'
#define DB2HISTORY_OPTYPE_ONLINE       'N'
#define DB2HISTORY_OPTYPE_INCR_OFFLINE 'I'
#define DB2HISTORY_OPTYPE_INCR_ONLINE  'O'
#define DB2HISTORY_OPTYPE_DELT_OFFLINE 'D'
#define DB2HISTORY_OPTYPE_DELT_ONLINE  'E'
#define DB2HISTORY_OPTYPE_REBUILD      'R'

/* Quiesce Optypes                                                            */
#define DB2HISTORY_OPTYPE_SHARE        'S'
#define DB2HISTORY_OPTYPE_UPDATE       'U'
#define DB2HISTORY_OPTYPE_EXCL         'X'
#define DB2HISTORY_OPTYPE_RESET        'Z'

/* Rollforward Optypes                                                        */
#define DB2HISTORY_OPTYPE_EOL          'E'
#define DB2HISTORY_OPTYPE_PIT          'P'

/* Load Optypes                                                               */
#define DB2HISTORY_OPTYPE_INSERT       'I'
#define DB2HISTORY_OPTYPE_REPLACE      'R'

/* Alter Tablespace Optypes                                                   */
#define DB2HISTORY_OPTYPE_ADD_CONT     'C'
#define DB2HISTORY_OPTYPE_REB          'R'

/* Archive Log Optypes                                                        */
#define DB2HISTORY_OPTYPE_ARCHIVE_CMD  'N'
#define DB2HISTORY_OPTYPE_PRIMARY      'P'
#define DB2HISTORY_OPTYPE_MIRROR       'M'
#define DB2HISTORY_OPTYPE_ARCHFAIL     'F'
#define DB2HISTORY_OPTYPE_ARCH1        '1'
#define DB2HISTORY_OPTYPE_ARCH2        '2'

/* History Entry Status Flags                                                 */
#define DB2HISTORY_STATUS_ACTIVE       'A'
#define DB2HISTORY_STATUS_INACTIVE     'I'
#define DB2HISTORY_STATUS_EXPIRED      'E'
#define DB2HISTORY_STATUS_DELETED      'D'
#define DB2HISTORY_STATUS_PENDING_DEL  'P'
#define DB2HISTORY_STATUS_NC           'N'
#define DB2HISTORY_STATUS_INCMP_ACTV   'a'
#define DB2HISTORY_STATUS_INCMP_INACTV 'i'
#define DB2HISTORY_STATUS_DO_NOT_DEL   'X'

/* Close History Scan Definitions                                             */

/******************************************************************************
** db2HistoryCloseScan API
** Ends a history file scan and frees DB2 resources required for the scan.
** This API must be preceded by a successful call to thedb2HistoryOpenScan API.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Instance. It is not necessary to call the sqleatin API before calling
** this API.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HistoryCloseScan API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the second parameter,
** piHandle.
** 
** piHandle
** Input. Specifies a pointer to the handle for scan access that was returned by
** the db2HistoryOpenScan API.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** For a detailed description of the use of the history file APIs, refer to the
** db2HistoryOpenScan API.
** 
** REXX API syntax
** 
** CLOSE RECOVERY HISTORY FILE :scanid
** 
** REXX API parameters
** 
** scanid
** Host variable containing the scan identifier returned from OPEN RECOVERY
** HISTORY FILE SCAN.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Close a history file scan           */
  db2HistoryCloseScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * piHandle,                /* History scan handle                 */
       struct sqlca * pSqlca);         /* SQLCA                               */


/* db2gHistoryCloseScan - Generic API                                         */
/******************************************************************************
** db2gHistoryCloseScan API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Close a history file scan           */
  db2gHistoryCloseScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * piHandle,                /* History scan handle                 */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Update History Entry Definitions                                           */

/* Update history API input struct                                            */
/******************************************************************************
** db2HistoryUpdateStruct data structure
** db2HistoryUpdateStruct data structure parameters
** 
** piNewLocation
** Input. A pointer to a string specifying a new location for the backup,
** restore, or load copy image. Setting this parameter to NULL, or pointing
** to zero, leaves the value unchanged.
** 
** piNewDeviceType
** Input. A pointer to a string specifying a new device type for storing the
** backup, restore, or load copy image. Setting this parameter to NULL, or
** pointing to zero, leaves the value unchanged.
** 
** piNewComment
** Input. A pointer to a string specifying a new comment to describe the
** entry. Setting this parameter to NULL, or pointing to zero, leaves the
** comment unchanged.
** 
** piNewStatus
** Input. A pointer to a string specifying a new status type for the entry.
** Setting this parameter to NULL, or pointing to zero, leaves the status
** unchanged.
** 
** iEID
** Input. A unique identifier that can be used to update a specific entry in
** the history file.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryUpdateStruct
{
   char                                *piNewLocation;
   char                                *piNewDeviceType;
   char                                *piNewComment;
   char                                *piNewStatus;
   db2HistoryEID                       iEID;     /* ID of the entry to be     */
                                                 /* updated                   */
} db2HistoryUpdateStruct;

/******************************************************************************
** db2HistoryUpdate API
** Updates the location, device type, or comment in a history file entry.
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
** Database. To update entries in the history file for a database other
** than the default database, a connection to the database must be
** established before calling this API.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HistoryUpdate API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2HistoryUpdateStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** This is an update function, and all information prior to the change is
** replaced and cannot be recreated. These changes are not logged.
** 
** The primary purpose of the database history file is to record
** information, but the data contained in the history is used directly by
** automatic restore operations. During any restore where the AUTOMATIC
** option is specified, the history of backup images and their locations
** will be referenced and used by the restore utility to fulfill the
** automatic restore request. If the automatic restore function is to
** be used and backup images have been relocated since they were created, it is
** recommended that the database history record for those images be updated to
** reflect the current location. If the backup image location in the database
** history is not updated, automatic restore will not be able to locate the
** backup images, but manual restore commands can still be used successfully.
** 
** REXX API syntax
** 
** UPDATE RECOVERY HISTORY USING :value
** 
** REXX API parameters
** 
** value
** A compound REXX host variable containing information pertaining to the new
** location of a history file entry. In the following, XXX represents the
** host variable
** name:
** - XXX.0
** Number of elements in the variable (must be between 1 and 4)
** - XXX.1
** OBJECT_PART (time stamp with a sequence number from 001 to 999)
** - XXX.2
** New location for the backup or copy image (this parameter is optional)
** - XXX.3
** New device used to store the backup or copy image (this parameter is
** optional)
** - XXX.4
** New comment (this parameter is optional).
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Update history entry data           */
  db2HistoryUpdate (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Update history API input struct                                            */
/******************************************************************************
** db2gHistoryUpdateStruct data structure
** db2gHistoryUpdateStruct data structure specific parameters
** 
** iNewLocationLen
** Input. Specifies the length in bytes of the piNewLocation parameter.
** 
** iNewDeviceLen
** Input. Specifies the length in bytes of the piNewDeviceType parameter.
** 
** iNewCommentLen
** Input. Specifies the length in bytes of the piNewComment parameter.
** 
** iNewStatusLen
** Input. Specifies the length in bytes of the piNewStatus paramter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gHistoryUpdateStruct
{
   char                                *piNewLocation;
   char                                *piNewDeviceType;
   char                                *piNewComment;
   char                                *piNewStatus;
   db2Uint32                           iNewLocationLen;
   db2Uint32                           iNewDeviceLen;
   db2Uint32                           iNewCommentLen;
   db2Uint32                           iNewStatusLen;
   db2HistoryEID                       iEID;     /* ID of the entry to be     */
                                                 /* updated                   */
} db2gHistoryUpdateStruct;

/* db2gHistoryUpdate - Generic API                                            */
/******************************************************************************
** db2gHistoryUpdate API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Update history entry data           */
  db2gHistoryUpdate (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Insert Backup History Entry Definitions                                    */

/* Insert Backup History Entry API input struct                               */
/******************************************************************************
** db2HistoryInsertBackupStruct data structure
** db2HistoryInsertBackupStruct data structure parameters
** 
** iProductID
** Input. The IBM-assigned product ID for the tool that created the backup being
**        inserted.
** 
** iTimestamp
** Input. The timestamp of the backup image.
** 
** iEndtime
** Input. The backup end time.
** 
** iBaseTimestamp
** Input. The timestamp of the backup image that the current image was based on.
** 
** iFirstLog
** Deprecated as of v105fp3, please use iLogRange instead.
** 
** iLastLog
** Deprecated as of v105fp3, please use iLogRange instead.
** 
** iLastLSN
** Input. End of backup LSN.
** 
** iOptions
** Input. Backup options bitmask.
** 
** piTablespaceList
** Input. List of tablespaces in backup.
** 
** piMediaList
** Input. List of backup locations, one for each backup sequence, in order.
** 
** iLogRange
** Input. Log file ranges for each log stream
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HistoryInsertBackupStruct
{
   char                                iProductID[DB2HISTORY_PRODUCT_ID_SZ+1];
   char                                iTimestamp[DB2HISTORY_TIMESTAMP_SZ+1];
   char                                iEndTime[DB2HISTORY_TIMESTAMP_SZ+1];
   char                                iBaseTimestamp[DB2HISTORY_TIMESTAMP_SZ+1];
   db2Uint32                           iFirstLog;
   db2Uint32                           iLastLog;
   db2LSN                              iLastLSN;
   db2Uint32                           iOptions;
   struct db2TablespaceStruct          *piTablespaceList;
   struct db2MediaListStruct           *piMediaList;
   db2HistoryLogRange                  iLogRange; /* Log ranges 1 per stream  */
} db2HistoryInsertBackupStruct;

/******************************************************************************
** db2HistoryInsertBackup API
** Creates and inserts backup entry (or entries, if there are multiple
** sequences in the backup) in the recovery history file.
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
** Database. To create entries in the history file for a database other
** than the default database, a connection to the database must be
** established before calling this API.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HistoryInsertBackup API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2HistoryInsertBackupStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** These changes are not logged.
** 
** This API can be used to register a backup in the recovery history file.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Insert Backup History Entry         */
  db2HistoryInsertBackup (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/******************************************************************************
** Precompiler API Related Definitions
*******************************************************************************/

/* Compile SQL Parmeter Structure                                             */
/******************************************************************************
** db2CompileSqlStruct data structure
*******************************************************************************/
typedef struct db2CompileSqlStruct
{
   db2Uint32                           *piSqlStmtLen; /* SQL statement text   */
                                                 /* length                    */
   char                                *piSqlStmt; /* SQL statement text      */
   db2Uint32                           *piLineNum; /* Source Line Number      */
   struct sqla_flaginfo                *pioFlagInfo; /* SQL Flagger           */
                                                 /* information               */
   struct sqla_tokens                  *pioTokenIdArray; /* Token ID Array    */
   struct sqla_tasks                   *poTaskArray; /* Task Array            */
   db2Uint16                           *poSectionNum; /* Section Number       */
   db2Uint16                           *poSqlStmtType; /* Type of SQL         */
                                                 /* statement                 */
   char                                *poBuffer1; /* 256 byte string buffer  */
                                                 /* 1                         */
   char                                *poBuffer2; /* 256 byte string buffer  */
                                                 /* 2                         */
   char                                *poBuffer3; /* 256 byte string buffer  */
                                                 /* 3                         */
   void                                *pioReserved; /* Reserved              */
} db2CompileSqlStruct;

/* Generic Compile SQL Parmeter Structure                                     */
/******************************************************************************
** db2gCompileSqlStruct data structure
*******************************************************************************/
typedef struct db2gCompileSqlStruct
{
   db2Uint32                           *piSqlStmtLen; /* SQL statement text   */
                                                 /* length                    */
   char                                *piSqlStmt; /* SQL statement text      */
   db2Uint32                           *piLineNum; /* Source Line Number      */
   struct sqla_flaginfo                *pioFlagInfo; /* SQL Flagger           */
                                                 /* information               */
   struct sqla_tokens                  *pioTokenIdArray; /* Token ID Array    */
   struct sqla_tasks                   *poTaskArray; /* Task Array            */
   db2Uint16                           *poSectionNum; /* Section Number       */
   db2Uint16                           *poSqlStmtType; /* Type of SQL         */
                                                 /* statement                 */
   char                                *poBuffer1; /* 256 byte string buffer  */
                                                 /* 1                         */
   char                                *poBuffer2; /* 256 byte string buffer  */
                                                 /* 2                         */
   char                                *poBuffer3; /* 256 byte string buffer  */
                                                 /* 3                         */
   void                                *pioReserved; /* Reserved              */
} db2gCompileSqlStruct;

/* Compile SQL API                                                            */
/******************************************************************************
** db2CompileSql API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Compile an SQL statement  */
  db2CompileSql (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Generic Compile SQL API                                                    */
/******************************************************************************
** db2gCompileSql API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Compile an SQL statement  */
  db2gCompileSql (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Initialization Parmeter Structure                                          */
/******************************************************************************
** db2InitStruct data structure
*******************************************************************************/
typedef struct db2InitStruct
{
   db2Uint16                           *piProgramNameLength; /* Program name  */
                                                 /* length                    */
   char                                *piProgramName; /* Program name        */
   db2Uint16                           *piDbNameLength; /* Database name      */
                                                 /* length                    */
   char                                *piDbName; /* Database name            */
   db2Uint16                           *piDbPasswordLength; /* Password       */
                                                 /* length                    */
   char                                *piDbPassword; /* Password             */
   db2Uint16                           *piBindNameLength; /* Bindfile name    */
                                                 /* length                    */
   char                                *piBindName; /* Bindfile name          */
   struct sqla_options                 *piOptionsArray; /* Precompiler        */
                                                 /* options array             */
   db2Uint16                           *piPidLength; /* Precompiler program   */
                                                 /* ID buffer length          */
   struct sqla_program_id              *poPrecompilerPid; /* Precompiler      */
                                                 /* program ID                */
} db2InitStruct;

/* Generic Initialization Parmeter Structure                                  */
/******************************************************************************
** db2gInitStruct data structure
*******************************************************************************/
typedef struct db2gInitStruct
{
   db2Uint16                           *piProgramNameLength; /* Program name  */
                                                 /* length                    */
   char                                *piProgramName; /* Program name        */
   db2Uint16                           *piDbNameLength; /* Database name      */
                                                 /* length                    */
   char                                *piDbName; /* Database name            */
   db2Uint16                           *piDbPasswordLength; /* Password       */
                                                 /* length                    */
   char                                *piDbPassword; /* Password             */
   db2Uint16                           *piBindNameLength; /* Bindfile name    */
                                                 /* length                    */
   char                                *piBindName; /* Bindfile name          */
   struct sqla_options                 *piOptionsArray; /* Precompiler        */
                                                 /* options array             */
   db2Uint16                           *piPidLength; /* Precompiler program   */
                                                 /* ID buffer length          */
   struct sqla_program_id              *poPrecompilerPid; /* Precompiler      */
                                                 /* program ID                */
} db2gInitStruct;

/* Initialization API                                                         */
/******************************************************************************
** db2Initialize API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Initialize an access      */
                                                 /* plan                      */
  db2Initialize (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Generic Initialization SQL API                                             */
/******************************************************************************
** db2gInitialize API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Initialize an access      */
                                                 /* plan                      */
  db2gInitialize (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Reorg Definitions                                                          */

/* Reorg type defines                                                         */
#define DB2REORG_OBJ_TABLE_OFFLINE 1      /* Define for reorg table offline,  */
                                          /* corresponds to CLASSIC keyword   */
#define DB2REORG_OBJ_TABLE_INPLACE 2      /* Define for reorg table inplace   */
#define DB2REORG_OBJ_INDEXESALL   4       /* Define for reorg indexes all     */
#define DB2REORG_OBJ_INDEX        8       /* Define for reorg index           */
#define DB2REORG_RECLAIM_EXTENTS  10      /* Define for reorg table reclaim   */
                                          /* extents                          */

/* Defines for reorg flags parameter                                          */
#define DB2REORG_OPTION_NONE      0x0     /* Take default action              */
#define DB2REORG_ALLOW_NONE       0x8     /* No read or write access to       */
                                          /* table                            */
#define DB2REORG_ALLOW_WRITE      0x10000000 /* Read and write access to      */
                                          /* table                            */
#define DB2REORG_ALLOW_READ       0x20000000 /* Allow only read access to     */
                                          /* table                            */

/* Offline Table Reorg Options                                                */
#define DB2REORG_LONGLOB          0x1     /* Reorg long fields and lobs       */
#define DB2REORG_CHOOSE_TEMP      0x2     /* System to choose temp            */
                                          /* tablespace for reorg work        */
#define DB2REORG_INDEXSCAN        0x4     /* Recluster utilizing index scan   */
#define DB2REORG_RESET_DICTIONARY 0x10    /* Rebuild dictionary               */
#define DB2REORG_KEEP_DICTIONARY  0x20    /* Keep original dictionary         */
#define DB2REORG_PART_COMP_STATIC 0x400   /* Use static compression for data  */
                                          /* partition                        */
#define DB2REORG_PART_COMP_ADAPTIVE 0x800 /* Use adaptive compression for     */
                                          /* data partition                   */

/* Table Reorg Reclaim extents                                                */
#define DB2REORG_RECLAIM_EXTS     0x40    /* Reclaim extents, used when       */
                                          /* DB2REORG_RECLAIM_EXTENTS is      */
                                          /* specified as the reorgType       */

/* Online Table Reorg Options                                                 */
#define DB2REORG_START_ONLINE     0x10000 /* Start online reorg               */
#define DB2REORG_PAUSE_ONLINE     0x20000 /* Pause an existing online reorg   */
#define DB2REORG_STOP_ONLINE      0x40000 /* Stop an existing online reorg    */
#define DB2REORG_RESUME_ONLINE    0x80000 /* Resume a paused online reorg     */
#define DB2REORG_FULL_ONLINE      0x80000000 /* Explicitly specify full       */
                                          /* online reorg                     */
#define DB2REORG_NOTRUNCATE_ONLINE 0x100000 /* Do not perform table           */
                                          /* truncation                       */
#define DB2REORG_CLN_OVFL_ONLINE  0x40000000 /* Perform a overflow cleanup    */
                                          /* reorg                            */

/* Index Reorg Options                                                        */
#define DB2REORG_INDEX_REBUILD    0x200   /* Rebuild index(es)                */
#define DB2REORG_CLEANUP_ALL      0x800000 /* Cleanup pages and keys          */
#define DB2REORG_CLEANUP_PAGES    0x1000000 /* Cleanup pages only             */
#define DB2REORG_INDEX_RECLAIM_EXTENTS 0x100 /* Index reclaim extents         */

/* Deprecated and discontinued flags                                          */
#define DB2REORG_CLEANUP_NONE     0x400000 /* This flag has been deprecated   */
                                          /* and may be removed in a future   */
                                          /* release.                         */
#define DB2REORG_CONVERT_NONE     0x2000000 /* This flag has been deprecated  */
                                          /* and may be removed in a future   */
                                          /* release.                         */
#define DB2REORG_CONVERT          0x4000000 /* This flag has been             */
                                          /* discontinued and may be removed  */
                                          /* in a future release.             */

/* MPP allNodeFlag values                                                     */
#define DB2REORG_NODE_LIST        DB2_NODE_LIST
#define DB2REORG_ALL_NODES        DB2_ALL_NODES
#define DB2REORG_ALL_EXCEPT       DB2_ALL_EXCEPT

/* Reorg Table input struct                                                   */
/******************************************************************************
** db2ReorgTable data structure
** db2ReorgTable data structure parameters
** 
** pTableName
** Input. Specifies the name of the object to reorganize.
** 
** pOrderByIndex
** Input. Specifies the index to order the table by. 
** 
** pSysTempSpace
** Input. Specifies the system temporary table space to create temporary object
** in. 
** 
** pPartitionName 
** Input. Specifies the name of the data partition to reorganize. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReorgTable
{
  char              *pTableName;      /* Name of table to reorganize          */
  char              *pOrderByIndex;   /* Index to order table by              */
  char              *pSysTempSpace;   /* Temp tablespace to create temp       */
                                      /* objects in                           */
  char              *pLongTempSpace;  /* Temp tablespace to create temp long  */
                                      /* objects in                           */
  char              *pPartitionName;  /* Name of data partition to            */
                                      /* reorganize                           */
} db2ReorgTable;


/* Reorg Indexes all input struct                                             */
/******************************************************************************
** db2ReorgIndexesAll data structure
** db2ReorgIndexesAll data structure parameters
** 
** pTableName
** Input. Specifies the name of the object to reorganize.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReorgIndexesAll
{
  char              *pTableName;      /* Name of table to reorganize indexes  */
                                      /* on                                   */
  char              *pIndexName;      /* Name of index to reorganize          */
  char              *pPartitionName;  /* Name of data partition to            */
                                      /* reorganize                           */
} db2ReorgIndexesAll;


/* Reorg object struct                                                        */
/******************************************************************************
** db2ReorgObject union
** db2ReorgObject union parameters
** 
** tableStruct
** Specifies the options for a table reorganization. 
** 
** indexesAllStruct 
** Specifies the options for an index reorganization. 
** 
*******************************************************************************/
union db2ReorgObject
{
  struct db2ReorgTable             tableStruct;            /* Table struct    */
  struct db2ReorgIndexesAll        indexesAllStruct;       /* Indexes struct  */
};


/******************************************************************************
** db2ReorgStruct data structure
** db2ReorgStruct data structure parameters
** 
** reorgType
** Input. Specifies the type of reorganization. Valid values (defined in
** db2ApiDf header file, located in the include directory) are: 
** - DB2REORG_OBJ_TABLE_OFFLINE 
** Reorganize the table offline.
** - DB2REORG_OBJ_TABLE_INPLACE
** Reorganize the table inplace.
** - DB2REORG_OBJ_INDEXESALL 
** Reorganize all indexes. 
** 
** - DB2REORG_RECLAIM_EXTENTS 
** Reclaim extents on an MDC table that is in a DMS table space. 
** 
** reorgFlags 
** Input. Reorganization options. Valid values (defined in db2ApiDf
** header file, located in the include directory) are: 
** - DB2REORG_OPTION_NONE 
** Default action. 
** - DB2REORG_LONGLOB 
** Reorganize long fields and lobs, used when DB2REORG_OBJ_TABLE_OFFLINE is
** specified as the reorgType . 
** - DB2REORG_INDEXSCAN 
** Recluster utilizing index scan, used when DB2REORG_OBJ_TABLE_OFFLINE is
** specified as the reorgType . 
** - DB2REORG_START_ONLINE 
** Start online reorganization, used when DB2REORG_OBJ_TABLE_INPLACE is
** specified as the reorgType . 
** - DB2REORG_PAUSE_ONLINE 
** Pause an existing online reorganization, used when DB2REORG_OBJ_TABLE_INPLACE
** is specified as the reorgType . 
** - DB2REORG_STOP_ONLINE 
** Stop an existing online reorganization, used when DB2REORG_OBJ_TABLE_INPLACE
** is specified as the reorgType . 
** - DB2REORG_RESUME_ONLINE 
** Resume a paused online reorganization, used when DB2REORG_OBJ_TABLE_INPLACE
** is specified as the reorgType . 
** - DB2REORG_NOTRUNCATE_ONLINE 
** Do not perform table truncation, used when DB2REORG_OBJ_TABLE_INPLACE is
** specified as the reorgType . 
** - DB2REORG_ALLOW_NONE 
** No read or write access to the table. This parameter is not supported when
** DB2REORG_OBJ_TABLE_INPLACE is specified as the reorgType . 
** - DB2REORG_ALLOW_WRITE 
** Allow read and write access to the table. This parameter is not supported
** when DB2REORG_OBJ_TABLE_OFFLINE is specified as the reorgType . 
** - DB2REORG_ALLOW_READ 
** Allow only read access to the table. 
** - DB2REORG_CLEANUP_ALL 
** Clean up the indexes on a table by removing the committed pseudo deleted keys
** and committed pseudo empty pages, used when DB2REORG_OBJ_INDEXESALL is
** specified as the reorgType . 
** - DB2REORG_CLEANUP_PAGES 
** Clean up committed pseudo empty pages only, but do not clean up pseudo
** deleted keys on pages that are not pseudo empty, used when
** DB2REORG_OBJ_INDEXESALL is specified as the reorgType . 
** - DB2REORG_INDEX_RECLAIM_EXTENTS 
** Reclaim extents in the index object, used when DB2REORG_OBJ_INDEXESALL or 
** DB2REORG_OBJ_INDEX is specified as the reorgType . 
** 
** nodeListFlag
** Input. Specifies which database partitions to reorganize. Valid values (defined
** in db2ApiDf header file, located in the include directory) are: 
** - DB2REORG_NODE_LIST 
** Submit to all database partitions in the nodelist array. 
** - DB2REORG_ALL_NODES 
** Submit to all database partitions in the database partition group. 
** - DB2REORG_ALL_EXCEPT 
** Submit to all database partitions except the ones specified by the nodelist parameter. 
** 
** numNodes 
** Input. Number of database partitions in the nodelist array. 
** 
** pNodeList 
** A pointer to the array of database partition numbers. 
** 
** reorgObject 
** Input. Specifies the type of object to be reorganized. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReorgStruct
{
  db2Uint32                   reorgType;    /* Type - Table or Indexes        */
  db2Uint32                   reorgFlags;   /* Reorg options - DB2REORG_xxxx  */
  db2int32                    nodeListFlag; /* Which database partition       */
                                            /* reorg applies to               */
  db2Uint32                   numNodes;     /* Number of database partitions  */
                                            /* in nodelist array              */
  SQL_PDB_NODE_TYPE           *pNodeList;   /* Pointer to array of database   */
                                            /* partition numbers              */
  union db2ReorgObject        reorgObject;  /* Table or Index struct          */
} db2ReorgStruct;


/******************************************************************************
** db2Reorg API
** Reorganizes a table or all indexes defined on a table by compacting the
** information and reconstructing the rows or index data to eliminate
** fragmented data.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - CONTROL privilege on the table
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Reorg API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter, pReorgStruct.
** 
** pReorgStruct
** Input. A pointer to the db2ReorgStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Performance of table access, index scans, and the effectiveness of index page
** prefetching can be adversely affected when the table data has been modified
** many times, becoming fragmented and unclustered. Use REORGCHK to determine
** whether a table or its indexes are candidates for reorganizing. All work
** will be committed and all open cursors will be closed. After reorganizing
** a table or its indexes, use db2Runstats to update the statistics and
** sqlarbnd to rebind the packages that use this table.
** 
** If the table data is distributed onto several database partitions and the
** reorganization fails on any of the affected nodes, then only the failing nodes
** will have the table reorganization rolled back.
** 
** Note:
** If table reorganization is not successful, temporary files should not be
** deleted. The database manager uses these files to recover the database.
** 
** If the name of an index is specified, the database manager reorganizes
** the data according to the order in the index. To maximize performance,
** specify an index that is often used in SQL queries. If the name of an
** index is not specified, and if a clustering index exists, the data
** will be ordered according to the clustering index.
** 
** The PCTFREE value of a table determines the amount of free space designated
** per page. If the value has not been set, the utility will fill up as much
** space as possible on each page.
** 
** To complete a table space roll-forward recovery following a table
** reorganization, both data and LONG table spaces must be roll-forward enabled.
** 
** If the table contains LOB columns not defined with the COMPACT option, the
** LOB DATA storage object can be significantly larger following table
** reorganization. This can be a result of the order in which the rows were
** reorganized, and the types of table spaces used (SMS/DMS).
** 
** When reorganizing indexes, use the access option to allow other transactions
** either read only or read-write access to the table. There is a brief
** lock-out period when the reorganized indexes are being made available during
** which no access to the table is allowed.
** 
** If an index reorganization with allow read or allow write access fails
** because the indexes need to be rebuilt, the reorganization will be switched
** to allow no access and carry on. A message will be written to both the
** administration notification log and the diagnostics log to warn the user
** about the change in access mode.
** 
** If an index reorganization with no access fails, the indexes are not
** available and have to be rebuilt on the next table access.
** 
** This API cannot be used with:
** - views or an index that is based on an index extension
** - a DMS table while an online backup of a table space in which the table
** resides is being performed
** - declared temporary tables
** 
*******************************************************************************/
/* Reorg Table API                                                            */
SQL_API_RC SQL_API_FN                        /* Reorganize Table              */
  db2Reorg (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pReorgStruct,            /* Reorg Table Info              */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Generic Reorg Table API input struct                                       */
/******************************************************************************
** db2gReorgTable data structure
** db2gReorgTable data structure specific parameters
** 
** tableNameLen
** Input. Specifies the length in bytes of pTableName.
** 
** orderByIndexLen
** Input. Specifies the length in byte of pOrderByIndex. 
** 
** sysTempSpaceLen
** Input. Specifies the length in bytes of pSysTempSpace. 
** 
** partitionNameLen
** Input. Specifies the length in bytes of pPartitionName.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gReorgTable
{
  db2Uint32  tableNameLen;        /* length in bytes of pTableName            */
  char       *pTableName;         /* Name of table to reorganize              */
  db2Uint32  orderByIndexLen;     /* length in bytes of pOrderByIndex         */
  char       *pOrderByIndex;      /* Index to order table by                  */
  db2Uint32  sysTempSpaceLen;     /* length in bytes of pSysTempSpace         */
  char       *pSysTempSpace;      /* Tablespace to create temp objects in     */
  db2Uint32  longTempSpaceLen;    /* length in bytes of pLongTempSpace        */
  char       *pLongTempSpace;     /* Tablespace to create temp long objects   */
                                  /* in                                       */
  db2Uint32  partitionNameLen;    /* length in bytes of pPartitionName        */
  char       *pPartitionName;     /* Name of data partition to reorganize     */
} db2gReorgTable;


/* Reorg Indexes all input struct                                             */
/******************************************************************************
** db2gReorgIndexesAll data structure
** db2gReorgIndexesAll data structure specific parameters
** 
** tableNameLen
** Input. Specifies the length in bytes of pTableName. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gReorgIndexesAll
{
  db2Uint32  tableNameLen;        /* length in bytes of pTableName            */
  char       *pTableName;         /* Name of table to reorganize indexes on   */
  db2Uint32  indexNameLen;        /* length in bytes of pIndexName            */
  char       *pIndexName;         /* Name of index to reorganize              */
  db2Uint32  partitionNameLen;    /* length in bytes of pPartitionName        */
  char       *pPartitionName;     /* Name of data partition to reorganize     */
} db2gReorgIndexesAll;


/* Reorg object struct                                                        */
/******************************************************************************
** db2gReorgObject union
*******************************************************************************/
union db2gReorgObject
{
  struct db2gReorgTable            tableStruct;            /* Table struct    */
  struct db2gReorgIndexesAll       indexesAllStruct;       /* Indexes struct  */
};


/******************************************************************************
** db2gReorgnodes data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gReorgNodes
{
  SQL_PDB_NODE_TYPE                nodeNum[SQL_PDB_MAX_NUM_NODE]; 
} db2gReorgNodes;


/******************************************************************************
** db2gReorgStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gReorgStruct
{
  db2Uint32                   reorgType;    /* Type - Table or Indexes        */
  db2Uint32                   reorgFlags;   /* Reorg options - DB2REORG_xxxx  */
  db2int32                    nodeListFlag; /* Which database partition       */
                                            /* reorg applies to               */
  db2Uint32                   numNodes;     /* Number of database partitions  */
                                            /* in nodelist array              */
  SQL_PDB_NODE_TYPE           *pNodeList;   /* Pointer to array of database   */
                                            /* partition numbers              */
  union db2gReorgObject       reorgObject;  /* Table or Index struct          */
} db2gReorgStruct;

/******************************************************************************
** db2gReorg API
*******************************************************************************/
/* Generic Reorg Table API                                                    */
SQL_API_RC SQL_API_FN                        /* Reorganize Table              */
  db2gReorg (
              db2Uint32 versionNumber,       /* Database version number       */
              void * pReorgStruct,           /* Input parameters              */
              struct sqlca * pSqlca);        /* SQLCA                         */


/* db2Runstats Definitions                                                    */

/******************************************************************************
** db2Runstats API
** Updates statistics about the characteristics of a table and/or any associated
** indexes. These characteristics include, among many others, number of records,
** number of pages, and average record length. The optimizer uses these
** statistics when determining access paths to the data.
** 
** This utility should be called when a table has had many updates, after
** reorganizing a table, or after creating a new index.
** 
** Statistics are based on the portion of the table that resides on the
** database partition where the API executes. Global table statistics are
** derived by multiplying the values obtained at a database partition by the
** number of database partitions on which the table is completely stored.
** The global statistics are stored in the catalog tables.
** 
** The database partition from which the API is called does not have to
** contain a portion of the table:
** 
** - If the API is called from a database partition that contains a portion
** of the table, the utility executes at this database partition.
** - If the API is called from a database partition that does not contain
** a portion of the table, the request is sent to the first database
** partition in the database partition group that contains a portion of the
** table. The utility then executes at this database partition.
** 
** Scope
** 
** This API can be called from any database partition server in the
** db2nodes.cfg file. It can be used to update the catalogs on the catalog
** database partition.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - CONTROL privilege on the table
** - LOAD
** 
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Runstats API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter data.
** 
** data
** Input. A pointer to the db2RunstatsData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Use db2Runstats to update statistics:
** 
** - On tables that have been modified many times (for example, if a large
** number of updates have been made, or if a significant amount of data has
**  been inserted or deleted)
** - On tables that have been reorganized
** - When a new index has been created.
** 
** After statistics have been updated, new access paths to the table can be
** created by rebinding the packages using sqlabndx - Bind.
** 
** If index statistics are requested, and statistics have never been run on
** the table containing the index, statistics on both the table and indexes
** are calculated.
** 
** If the db2Runstats API is collecting statistics on indexes only then
** previously collected distribution statistics are retained. Otherwise,
** the API will drop previously collected distribution statistics.
** 
** After calling this API, the application should issue a COMMIT to release
** the locks.
** 
** To allow new access plans to be generated, the packages that reference
** the target table must be rebound after calling this API.
** 
** Running this API on the table only may result in a situation where the
** table level statistics are inconsistent with the already existing index
** level statistics. For example, if index level statistics are collected
** on a particular table and later a significant number of rows is deleted
** from this table, issuing this API on the table only may end up with the
** table cardinality less than FIRSTKEYCARD (FIRSTKEYCARD is a catalog
** statistics field in SYSCAT.INDEXES and SYSSTAT.INDEXES catalog views)
** which is an inconsistent state. Likewise, issuing this API for indexes
** only may leave the already existing table level statistics in an
** inconsistent state. For example, if table level statistics are
** collected on a particular table and later a significant number of
** rows is deleted from this table, issuing the db2Runstats API for the
** indexes only may end up with some columns having a COLCARD (COLCARD
** is a catalog statistics field in SYSCAT.COLUMNS and SYSSTAT.COLUMNS
** catalog views) greater than the table cardinality. A warning will be
** returned if such an inconsistency is detected.
*******************************************************************************/
/* Function Prototype for db2Runstats API                                     */

SQL_API_RC SQL_API_FN                        /* Collect Statistics            */
  db2Runstats (
                db2Uint32 versionNumber,     /* database version number       */
                void * data,                 /* input parameters              */
                struct sqlca * pSqlca);      /* output SQLCA                  */

/* Options for iRunstatsFlags                                                 */
#define DB2RUNSTATS_ALL_COLUMNS 0x1         /* Gather stats on all columns    */
#define DB2RUNSTATS_KEY_COLUMNS 0x2         /* Gather stats on key columns    */
#define DB2RUNSTATS_ALL_INDEXES 0x4         /* Gather stats on all indexes    */
#define DB2RUNSTATS_DISTRIBUTION 0x8        /* Gather distribution stats on   */
                                            /* either all columns or key      */
                                            /* columns                        */
#define DB2RUNSTATS_EXT_INDEX 0x10          /* Gather extended index stats    */
#define DB2RUNSTATS_EXT_INDEX_SAMPLED 0x20  /* Gather sampled extended index  */
                                            /* stats                          */
#define DB2RUNSTATS_USE_PROFILE 0x40        /* Gather stats using profile     */
#define DB2RUNSTATS_SET_PROFILE 0x80        /* Gather stats and set the       */
                                            /* profile                        */
#define DB2RUNSTATS_SET_PROFILE_ONLY 0x100  /* Set the stats profile only     */
#define DB2RUNSTATS_ALLOW_READ 0x200        /* Allow others to only read      */
                                            /* table while Runstats is in     */
                                            /* progress                       */
#define DB2RUNSTATS_ALL_DBPARTITIONS 0x400  /* Gather stats on all DB         */
                                            /* partitions                     */
#define DB2RUNSTATS_UPDATE_PROFILE 0x800    /* Gather statistics and update   */
                                            /* statistics profile             */
#define DB2RUNSTATS_UPDA_PROFILE_ONLY 0x1000 /* Update statistics profile     */
                                            /* without gathering statistics   */
#define DB2RUNSTATS_SAMPLING_SYSTEM 0x2000  /* Page Level Sampling            */
#define DB2RUNSTATS_SAMPLING_REPEAT 0x4000  /* Generate Repeatable Sample     */
#define DB2RUNSTATS_EXCLUDING_XML 0x8000    /* Excluding XML columns          */
#define DB2RUNSTATS_UNSET_PROFILE 0x10000   /* Unset the profile              */
#define DB2RUNSTATS_INDEX_SYSTEM 0x20000    /* Page level index sampling      */

/* Options for iColumnFlags                                                   */
#define DB2RUNSTATS_COLUMN_LIKE_STATS 0x1   /* Gather stats for LIKE          */
                                            /* predicates                     */

/* Default options                                                            */
#define DB2RUNSTATS_PARALLELISM_DFLT 0      /* Default level of parallelism   */
#define DB2RUNSTATS_SAMPLING_DFLT 1.000000e+02 /* Default percentage of       */
                                            /* pages sampled (100%)           */


/*  Structures for db2Runstats API                                            */

/* Columns to Collect Stats on                                                */
/******************************************************************************
** db2ColumnData data structure
** db2ColumnData data structure parameters
** 
** piColumnName
** Input. Pointer to a string representing a column name.
** 
** iColumnFlags
** Input. A bit mask field used to specify statistics options for the column.
** Valid values are: 
** - DB2RUNSTATS_COLUMN_LIKE_STATS 
** Collect LIKE statistics on the column. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ColumnData
{
  unsigned char               *piColumnName;
  db2int16                    iColumnFlags;
} db2ColumnData;

/* Columns to Collect Distribution Stats on                                   */
/******************************************************************************
** db2ColumnDistData data structure
** db2ColumnDistData data structure parameters
** 
** piColumnName
** Input. Pointer to a string representing a column name.
** 
** iNumFreqValues
** Input. The number of frequent values to collect on the column. Valid
** values are: 
** - n 
** Collect n frequent values on the column. 
** - -1 
** Use the table default number of frequent values, such as
** iTableDefaultFreqValues if set, or the database configuration
** parameter NUM_FREQVALUES. 
** 
** iNumQuantiles 
** Input. The number of quantiles to collect on the column. Valid values are:
** - n 
** Collect n quantiles on the column. 
** - -1 
** Use the table default number of quantiles, iTableDefaultQuantiles if set,
** or the database configuration parameter NUM_QUANTILES. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ColumnDistData
{
  unsigned char               *piColumnName;
  db2int16                    iNumFreqValues;
  db2int16                    iNumQuantiles;
} db2ColumnDistData;

/* Columns Groups to Collect Stats on                                         */
/******************************************************************************
** db2ColumnGrpData data structure
** db2ColumnGrpData data structure parameters
** 
** piGroupColumnNames
** Input. An array of strings. Each string represents a column name that
** is part of the column group on which to collect statistics. 
** 
** iGroupSize
** Input. Number of columns in the column group. Valid values are: 
** - n 
** The column group is made up of n columns. 
** 
** iNumFreqValues 
** Input. Reserved for future use. 
** 
** iNumQuantiles 
** Input. Reserved for future use.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ColumnGrpData
{
  unsigned char               **piGroupColumnNames;
  db2int16                    iGroupSize;
  db2int16                    iNumFreqValues;
  db2int16                    iNumQuantiles;
} db2ColumnGrpData;

/* Struct containing db2Runstats options                                      */
/******************************************************************************
** db2RunstatsData data structure
** db2RunstatsData data structure parameters
** 
** iSamplingOption
** Input. Indicates that statistics are to be collected on a sample of
** table data. iSamplingOption represents the size of the sample as a
** percentage P. This value must be a positive number that is less than
** or equal to 100, but may be between 1 and 0. For example, a value of
** 0.01 represents one one-hundredth of a percent, such that 1 row in
** 10 000 would be sampled, on average. A value of 0 or 100 will be
** treated by DB2 as if table sampling was not specified, regardless of
** whether DB2RUNSTATS_SAMPLING_SYSTEM has been specified. A value greater than
** 100 or less than 0 will be treated by DB2 as an error (SQL1197N). The two
** possible types of sampling are BERNOULLI and SYSTEM. The sampling type
** specification is controlled by the indicated setting of
** DB2RUNSTATS_SAMPLING_SYSTEM in the iRunstatsFlags. 
** 
** piTablename
** Input. A pointer to the fully qualified name of the table on which statistics
** are to be gathered. The name can be an alias. For row types, piTablename must
** be the name of the hierarchy's root table. 
** 
** piColumnList 
** Input. An array of db2ColumnData elements. Each element of this array is made
** up of two sub-elements: 
** - a string that represents the name of the column on which to collect
** statistics
** - a flags field indicating statistic options for the column
** If iNumColumns is zero then piColumnList is ignored if provided. 
** 
** piColumnDistributionList 
** Input. An array of db2ColumnDistData elements. These elements are
** provided when collecting distribution statistics on a particular column
** or columns is desired. Each element of this array is made up of three
** sub-elements : 
** - a string that represents the name of the column on which to collect
** distribution statistics 
** - the number of frequent values to collect. 
** - the number of quantiles to collect.
** Any columns which appear in the piColumnDistributionList that do NOT appear
** in the piColumnList, will have basic column statistics collected on them.
** This would be the same effect as having included these columns in the
** piColumnList in the first place. If iNumColdist is zero then
** piColumnDistributionList is ignored. 
** 
** piColumnGroupList 
** Input. An array of db2ColumnGrpData elements. These elements are
** provided when collecting column statistics on a group of columns.
** That is, the values in each column of the group for each row will
** be concatenated together and treated as a single value. Each
** db2ColumnGrpData is made up of 3 integer fields and an array
** of strings. The first integer field represents the number of strings in the
** array of strings piGroupColumns. Each string in this array contains one
** column name. For example, if column combinations statistics are to be
** collected on column groups (c1,c2) and on (c3,c4,c5) then there are 2
** db2ColumnGrpData elements in piGroupColumns. 
** 
** The first db2ColumnGrpData element is as follows: piGroupSize = 2 and the
** array of strings contains 2 elements, namely, c1 and c2.
** 
** The second db2ColumnGrpData element is as follows: piGroupSize = 3 and the
** array of strings contains 3 elements, namely, c3, c4 and c5.
** 
** The second and the third integer fields represent the number of frequent
** values and the number of quantiles respectively when collecting
** distribution statistics on column groups. This is not currently supported.
** 
** Any columns which appear in the piColumnGroupList that do NOT appear in the
** piColumnList, will have basic column statistics collected on them. This would
** be the same effect as having included these columns in the piColumnList
** in the first place. If iNumColGroups is zero then piColumnGroupList is
** ignored.
** 
** piIndexList 
** Input. An array of strings. Each string contains one fully qualified index
** name. If NumIndexes is zero then piIndexList is ignored.
** 
** iRunstatsFlags
** Input. A bit mask field used to specify statistics options. Valid values
** (defined in db2ApiDf header file, located in the include directory) are:
** 
** - DB2RUNSTATS_ALL_COLUMNS 
** Collect statistics on all columns of the table. This option can be specified
** in combination with column, column distribution, column group or index
** structure lists. This is useful if you would like to collect statistics
** on all columns of the table but would like to provide statistics options
** for specific columns.
** 
** - DB2RUNSTATS_KEY_COLUMNS 
** Collect statistics only on the columns that make up all the indexes
** defined on the table. This option can be specified in combination with
** column, column distribution, column group or index structure lists. This
** is useful if you would like to collect statistics on all key columns of
** the table but would also like to gather statistics for some non-key
** columns or would like to provide statistics options for specific key
** columns. 
** 
** - DB2RUNSTATS_DISTRIBUTION 
** Collect distribution statistics. This option can only be used with
** DB2RUNSTATS_ALL_COLUMNS and DB2RUNSTATS_KEY_COLUMNS. When used with
** DB2RUNSTATS_ALL_COLUMNS, distribution statistics are gathered for all columns
** of the table. When used with DB2RUNSTATS_KEY_COLUMNS, distribution statistics
** are gathered for all columns that make up all the indexes defined on the
** table. When used with both DB2RUNSTATS_ALL_COLUMNS and
** DB2RUNSTATS_KEY_COLUMNS, basic statistics are gathered for all columns of
** the table and distribution statistics are gathered for only columns that
** make up all the indexes defined on the table.
** 
** - DB2RUNSTATS_ALL_INDEXES 
** Collect statistics on all indexes defined on the table. 
** 
** - DB2RUNSTATS_EXT_INDEX 
** Collect detailed index statistics. The option must be specified with either
** DB2RUNSTATS_ALL_INDEXES or an explicit list of index names (piIndexList and
** iNumIndexes > 0). 
** 
** - DB2RUNSTATS_EXT_INDEX_SAMPLED 
** Collect detailed index statistics using sampling methods. The option must be
** specified with either DB2RUNSTATS_ALL_INDEXES or an explicit list of
** index names (piIndexList and iNumIndexes > 0). DB2RUNSTATS_EXT_INDEX will
** be ignored if specified at the same time. 
** 
** - DB2RUNSTATS_ALLOW_READ 
** Allows others to have read-only access while the statistics are being
** gathered. The default is to allow read and write access.
** 
** - DB2RUNSTATS_SAMPLING_SYSTEM
** Collect statistics on a percentage of the data pages as specified by the user
** via the iSamplingOption parameter. SYSTEM sampling considers each page
** individually, including that page with probability P/100 (where P is the
** value of iSamplingOption) and excluding it with probability 1-P/100.
** Thus, if iSamplingOption is the value 10, representing a 10 percent sample,
** each page would be included with probability 0.1 and be excluded with
** probability 0.9.
** 
** If DB2RUNSTATS_SAMPLING_SYSTEM is not specified, DB2 will assume that
** BERNOULLI sampling is to be used as the sampling method. BERNOULLI sampling
** considers each row individually, including that row with probability P/100
** (where P is the value of iSamplingOption) and excluding it with probability
** 1-P/100.
** 
** In both SYSTEM and BERNOULLI sampling, unless the DB2RUNSTATS_SAMPLING_REPEAT
** flag is specified, each execution of statistics collection will usually yield
** a different sample of the table.
** 
** - DB2RUNSTATS_SAMPLING_REPEAT
** Specifies that a seed has been passed through the iSamplingRepeatable
** parameter. The iSamplingRepeatable value will be used as the seed to generate
** the data sample. The iSamplingOption parameter must also be specified to
** indicate the sampling rate.
** 
** - DB2RUNSTATS_USE_PROFILE
** Collect statistics for a table by using a statistics profile already
** registered in the catalogs of the table. If the USE PROFILE option is
** specified by this flag set in iRunstatsFlags bit mask, all other options
** in db2RunstatsData will be ignored.
** 
** - DB2RUNSTATS_SET_PROFILE
** Generate and store a profile in the catalogs recording the statistics options
** specified and collect statistics using those same options.
** 
** - DB2RUNSTATS_SET_PROFILE_ONLY
** Generate and store a profile in the catalogs recording the statistics options
** specified without actually collecting statistics for the table.
** 
** - DB2RUNSTATS_UPDATE_PROFILE
** Modify an existing statistics profile in the catalogs and collect statistics
** using the options from the updated profile.
** 
** - DB2RUNSTATS_UPDATE_PROFILE_ONLY
** Modify an existing statistics profile in the catalogs without actually
** collecting statistics for the table.
** 
** iNumColumns
** Input. The number of items specified in the piColumnList list. 
** 
** iNumColdist 
** Input. The number of items specified in the piColumnDistributionList list.
** 
** iNumColGroups 
** Input. The number of items specified in the piColumnGroupList list. 
** 
** iNumIndexes 
** Input. The number of items specified in the piIndexList list. 
** 
** iParallelismOption 
** Input. Reserved for future use. Valid value is 0. 
** 
** iTableDefaultFreqValues 
** Input. Specifies the default number of frequent values to collect for the
** table. Valid values are: 
** - n 
** n frequent values will be collected unless otherwise specified at the
** column level. 
** - 0 
** No frequent values will be collected unless otherwise specified at the column
** level. 
** - -1 
** Use the default database configuration parameter NUM_FREQVALUES for the
** number of frequent values to collect. 
** 
** iTableDefaultQuantiles 
** Input. Specifies the default number of quantiles to collect for the table.
** Valid values are: 
** - n 
** n quantiles will be collected unless otherwise specified at the column level.
** - 0 
** No quantiles will be collected unless otherwise specified at the column
** level.
** - -1 
** Use the default database configuration parameter NUM_QUANTILES for the number
** of quantiles to collect. 
** 
** iSamplingRepeatable
** Input. A non-negative integer representing the seed to be used in table
** sampling. Passing a negative seed will result in an error (SQL1197N). The
** DB2RUNSTATS_SAMPLING_REPEAT flag must be set to use this seed. This option is
** used in conjunction with the iSamplingOption parameter to generate the same
** sample of data in subsequent statistics collection. The sample set may still
** vary between repeatable requests if activity against the table resulted in
** changes to the table data since the last time a repeatable request was run.
** Also, the method by which the sample was obtained (BERNOULLI or SYSTEM) must
** also be the same to ensure consistent results.
** 
** iUtilImpactPriority
** Input. Priority for the runstats invocation. Valid values must fall in the
** range 0-100, with 70 representing unthrottled and 100 representing the
** highest possible priority. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RunstatsData
{
  double                      iSamplingOption;
  unsigned char               *piTablename;
  struct db2ColumnData        **piColumnList;
  struct db2ColumnDistData    **piColumnDistributionList;
  struct db2ColumnGrpData     **piColumnGroupList;
  unsigned char               **piIndexList;
  db2Uint32                   iRunstatsFlags;
  db2int16                    iNumColumns;
  db2int16                    iNumColdist;
  db2int16                    iNumColGroups;
  db2int16                    iNumIndexes;
  db2int16                    iParallelismOption;
  db2int16                    iTableDefaultFreqValues;
  db2int16                    iTableDefaultQuantiles;
  db2Uint32                   iSamplingRepeatable;
  db2Uint32                   iUtilImpactPriority;
  double                      iIndexSamplingOption;
} db2RunstatsData;


/******************************************************************************
** db2gRunstats API
*******************************************************************************/
/* Function Prototype for db2gRunstats API                                    */

SQL_API_RC SQL_API_FN                        /* Collect Statistics            */
  db2gRunstats (
                db2Uint32 versionNumber,     /* database version number       */
                void * data,                 /* input parameters              */
                struct sqlca * pSqlca);      /* output SQLCA                  */

/*  Structures for db2gRunstats API                                           */

/* Columns to Collect Stats on                                                */
/******************************************************************************
** db2gColumnData data structure
** db2gColumnData data structure specific parameters
** 
** piColumnName
** Input. Pointer to a string representing a column name.
** 
** iColumnNameLen
** Input. A value representing the length in bytes of the column name.
** 
** iColumnFlags
** Input. A bit mask field used to specify statistics options for the column.
** Valid values are:
** - DB2RUNSTATS_COLUMN_LIKE_STATS
** Collect LIKE statistics on the column.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gColumnData
{
  unsigned char               *piColumnName;
  db2Uint16                   iColumnNameLen;
  db2int16                    iColumnFlags;
} db2gColumnData;

/* Columns to Collect Distribution Stats on                                   */
/******************************************************************************
** db2gColumnDistData data structure
** db2gColumnDistData data structure specific parameters
** 
** piColumnName
** Input. Pointer to a string representing a column name.
** iColumnNameLen
** Input. A value representing the length in bytes of the column name.
** 
** iNumFreqValues
** Input. The number of frequent values to collect on the column. Valid values are:
** 
** - n
** Collect n frequent values on the column.
** - -1
** Use the table default number of frequent values, such as iTableDefaultFreqValues 
** if set, or the database configuration parameter NUM_FREQVALUES.
** 
** iNumQuantiles
** Input. The number of quantiles to collect on the column. Valid values are:
** 
** - n
** Collect n quantiles on the column.
**  -1
** Use the table default number of quantiles, iTableDefaultQuantiles if set, or the
** database configuration parameter NUM_QUANTILES.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gColumnDistData
{
  unsigned char               *piColumnName;
  db2Uint16                   iColumnNameLen;
  db2int16                    iNumFreqValues;
  db2int16                    iNumQuantiles;
} db2gColumnDistData;

/* Columns Groups to Collect Stats on                                         */
/******************************************************************************
** db2gColumnGrpData data structure
** db2gColumnGrpData data structure specific parameters
** 
** piGroupColumnNames
** Input. An array of strings. Each string represents a column name that
** is part of the column group on which to collect statistics.
** 
** piGroupColumnNamesLen
** Input. An array of values representing the length in bytes of each
** of the column names in the column names list. 
** 
** iGroupSize
** Input. Number of columns in the column group. Valid values are:
** - n
** The column group is made up of n columns.
** 
** iNumFreqValues
** Input. Reserved for future use.
** 
** iNumQuantiles
** Input. Reserved for future use.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gColumnGrpData
{
  unsigned char               **piGroupColumnNames;
  db2Uint16                   *piGroupColumnNamesLen;
  db2int16                    iGroupSize;
  db2int16                    iNumFreqValues;
  db2int16                    iNumQuantiles;
} db2gColumnGrpData;

/* Struct containing db2gRunstats options                                     */
/******************************************************************************
** db2gRunstatsData data structure
** db2gRunstatsData data structure specific parameters
** 
** See above for structure description.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gRunstatsData
{
  double                      iSamplingOption;
  unsigned char               *piTablename;
  struct db2gColumnData       **piColumnList;
  struct db2gColumnDistData   **piColumnDistributionList;
  struct db2gColumnGrpData    **piColumnGroupList;
  unsigned char               **piIndexList;
  db2Uint16                   *piIndexNamesLen;
  db2Uint32                   iRunstatsFlags;
  db2Uint16                   iTablenameLen;
  db2int16                    iNumColumns;
  db2int16                    iNumColdist;
  db2int16                    iNumColGroups;
  db2int16                    iNumIndexes;
  db2int16                    iParallelismOption;
  db2int16                    iTableDefaultFreqValues;
  db2int16                    iTableDefaultQuantiles;
  db2Uint32                   iSamplingRepeatable;
  db2Uint32                   iUtilImpactPriority;
} db2gRunstatsData;



/* Prune Database History Definitions                                         */

/* Values for db2Prune - iCallerAction                                        */
#define DB2PRUNE_ACTION_HISTORY        1         /* Remove history file       */
                                                 /* entries                   */
#define DB2PRUNE_ACTION_LOG            2         /* Remove log files from     */
                                                 /* active log path           */

/* Values for db2Prune - iOptions                                             */
#define DB2PRUNE_OPTION_NONE           0x0       /* Force removal of last     */
                                                 /* backup                    */
#define DB2PRUNE_OPTION_FORCE          0x1       /* Force removal of last     */
                                                 /* backup                    */
#define DB2PRUNE_OPTION_LSNSTRING      0x2       /* piString is an LSN        */
                                                 /* string, used by DB2PRUNE  */
                                                 /* ACTION_LOG                */
#define DB2PRUNE_OPTION_DELETE         0x4       /* Delete pruned files       */

/* Prune API input struct                                                     */
/******************************************************************************
** db2PruneStruct data structure
** db2PruneStruct data structure parameters
** 
** piString
** Input. A pointer to a string specifying a time stamp or a log sequence number
** (LSN). The time stamp or part of a time stamp (minimum yyyy, or year) is used
** to select records for deletion. All entries equal to or less than the time
** stamp will be deleted. A valid time stamp must be provided; a NULL parameter
** value is invalid.
** This parameter can also be used to pass an LSN, so that inactive logs can be
** pruned.
** 
** iEID
** Input. Specifies a unique identifier that can be used to prune a single
** entry from the history file.
** 
** iAction
** Input. Specifies the type of action to be taken. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** - DB2PRUNE_ACTION_HISTORY
** Remove history file entries.
** - DB2PRUNE_ACTION_LOG
** Remove log files from the active log path.
** 
** iOptions
** Input. Valid values (defined in db2ApiDf header file, located in the include
** directory) are:
** - DB2PRUNE_OPTION_FORCE
** Force the removal of the last backup.
** - DB2PRUNE_OPTION_DELETE
** Delete log files that are pruned from the history file.
** - DB2PRUNE_OPTION_LSNSTRING
** Specify that the value of piString is an LSN, used when a caller action of 
** - DB2PRUNE_ACTION_LOG is specified. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2PruneStruct
{
  char                        *piString;    /* Timestamp, or lastLSN          */
  db2HistoryEID               iEID;         /* Prune history since this EID   */
  db2Uint32                   iAction;      /* What to prune                  */
  db2Uint32                   iOptions;     /* Options relevent to            */
                                            /* particular iAction             */
} db2PruneStruct;

/******************************************************************************
** db2Prune API
** Deletes entries from the history file or log files from the active log path.
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
** Database. To delete entries from the history file for any database other
** than the default database, a connection to the database must be established
** before calling this API.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Prune API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed in
** as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2PruneStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Pruning the history file does not delete the actual backup or load files.
** The user must manually delete these files to free up the space they consume
** on storage media.
** 
** If the latest full database backup is deleted from the media (in addition to
** being pruned from the history file), the user must ensure that all table
** spaces, including the catalog table space and the user table spaces, are
** backed up. Failure to do so may result in a database that cannot be
** recovered, or the loss of some portion of the user data in the database.
** 
** REXX API syntax
** 
** PRUNE RECOVERY HISTORY BEFORE :timestamp [WITH FORCE OPTION]
** 
** REXX API parameters
** 
** timestamp
** A host variable containing a time stamp. All entries with time stamps equal
** to or less than the time stamp provided are deleted from the history file.
** 
** WITH FORCE OPTION
** 
** If specified, the history file will be pruned according to the time stamp
** specified, even if some entries from the most recent restore set are
** deleted from the file. If not specified, the most recent restore set will
** be kept, even if the time stamp is less than or equal to the time stamp
** specified as input.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Prune history / log                 */
  db2Prune (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Prune API input struct                                             */
/******************************************************************************
** db2gPruneStruct data structure
** db2gPruneStruct data structure specific parameters
** 
** iStringLen
** Input. Specifies the length in bytes of piString.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gPruneStruct
{
  db2Uint32                   iStringLen;   /* length in bytes of piString    */
  char                        *piString;    /* Timestamp, or lastLSN          */
  db2HistoryEID               iEID;         /* Prune history since this EID   */
  db2Uint32                   iAction;      /* What to prune                  */
  db2Uint32                   iOptions;     /* Options relevent to            */
                                            /* particular iAction             */
} db2gPruneStruct;

/******************************************************************************
** db2gPrune API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Prune history / log         */
  db2gPrune (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */


/* Backup Options                                                             */
#define DB2BACKUP_DB          0x0
#define DB2BACKUP_TABLESPACE  0x3
#define DB2BACKUP_MERGE       0x8
#define DB2BACKUP_INCREMENTAL 0x10
#define DB2BACKUP_DELTA       0x30
#define DB2BACKUP_OFFLINE     0x0
#define DB2BACKUP_ONLINE      0x100
#define DB2BACKUP_DEDUP_DEVICE 0x200        /* Dedup device                   */
#define DB2BACKUP_COMPRESS    0x400         /* Compress backup image          */
#define DB2BACKUP_INCLUDE_COMPR_LIB 0x0     /* Include compression lib in     */
                                            /* backup image                   */
#define DB2BACKUP_EXCLUDE_COMPR_LIB 0x800   /* Do not include compression     */
                                            /* lib in backup image            */
#define DB2BACKUP_INCLUDE_LOGS 0x1000       /* Include log files in online    */
                                            /* backup image                   */
#define DB2BACKUP_EXCLUDE_LOGS 0x2000       /* Exclude log files from backup  */
                                            /* image                          */
#define DB2BACKUP_MPP         0x4000        /* Perform multi-partition        */
                                            /* backup                         */
#define DB2BACKUP_COPY_ONLY   0x8000        /* Copy only backup               */
#define DB2BACKUP_ENCRYPT     0x10000
#define DB2BACKUP_INCLUDE_ENCR_LIB 0x0
#define DB2BACKUP_EXCLUDE_ENCR_LIB 0x20000

/* Backup Caller Actions                                                      */
#define DB2BACKUP_BACKUP      0
#define DB2BACKUP_CONTINUE    1
#define DB2BACKUP_TERMINATE   2
#define DB2BACKUP_NOINTERRUPT 3
#define DB2BACKUP_DEVICE_TERMINATE 9
#define DB2BACKUP_PARM_CHK    10
#define DB2BACKUP_PARM_CHK_INIT_WAIT 10
#define DB2BACKUP_PARM_CHK_ONLY 11

/* iAllNodeFlag values                                                        */
#define DB2BACKUP_NODE_LIST   DB2_NODE_LIST /* Submit to all database         */
                                            /* partitions in the node list    */
#define DB2BACKUP_ALL_NODES   DB2_ALL_NODES /* Submit to all database         */
                                            /* partitions in the node         */
                                            /* configuration file             */
#define DB2BACKUP_ALL_EXCEPT  DB2_ALL_EXCEPT /* Submit to all database        */
                                            /* partitions except the ones     */
                                            /* specified by the nodelist      */
                                            /* parameter                      */

/* Restore Options                                                            */
#define DB2RESTORE_DB         0x0
#define DB2RESTORE_TABLESPACE 0x4
#define DB2RESTORE_HISTORY    0x5
#define DB2RESTORE_COMPR_LIB  0x6           /* Restore only compression       */
                                            /* library                        */
#define DB2RESTORE_LOGS       0x7
#define DB2RESTORE_INCREMENTAL 0x10
#define DB2RESTORE_OFFLINE    0x0
#define DB2RESTORE_ONLINE     0x40
#define DB2RESTORE_DATALINK   0x0
#define DB2RESTORE_NODATALINK 0x80
#define DB2RESTORE_AUTOMATIC  0x100
#define DB2RESTORE_ROLLFWD    0x0
#define DB2RESTORE_NOROLLFWD  0x200
#define DB2RESTORE_NOREPLACE_HISTORY 0x0
#define DB2RESTORE_REPLACE_HISTORY 0x400
#define DB2RESTORE_TRANSPORT  0x800         /* Perform the transport          */
                                            /* operation                      */
#define DB2RESTORE_GENERATE_SCRIPT 0x8000   /* Generate redirect restore      */
                                            /* script                         */
#define DB2RESTORE_NOENCRYPT  0x10000       /* Force the new database to      */
                                            /* disale encryption              */

/* Restore Rebuild Types                                                      */
#define DB2RESTORE_NO_REBUILD 0x0           /* No rebuild                     */
#define DB2RESTORE_ALL_TBSP_IN_DB 0x1000    /* Rebuild with all tablespaces   */
                                            /* in database                    */
#define DB2RESTORE_ALL_TBSP_IN_IMG 0x2000   /* Rebuild with all tablespaces   */
                                            /* in image                       */
#define DB2RESTORE_ALL_TBSP_IN_LIST 0x3000  /* Rebuild with all tablespaces   */
                                            /* in list                        */
#define DB2RESTORE_ALL_TBSP_IN_DB_EXC 0x5000 /* Rebuild with all tablespaces  */
                                            /* in database except             */
#define DB2RESTORE_ALL_TBSP_IN_IMG_EXC 0x6000 /* Rebuild with all             */
                                            /* tablespaces in image except    */

/* Restore Caller Actions                                                     */
#define DB2RESTORE_RESTORE    0
#define DB2RESTORE_CONTINUE   1
#define DB2RESTORE_TERMINATE  2
#define DB2RESTORE_NOINTERRUPT 3
#define DB2RESTORE_DEVICE_TERMINATE 9
#define DB2RESTORE_PARM_CHK   10
#define DB2RESTORE_PARM_CHK_INIT_WAIT 10
#define DB2RESTORE_PARM_CHK_ONLY 11
#define DB2RESTORE_TERMINATE_INCRE 13
#define DB2RESTORE_RESTORE_STORDEF 100
#define DB2RESTORE_STORDEF_NOINTERRUPT 101

/* piNewLogPath values for restore                                            */
#define DB2RESTORE_NEWLOGPATH_DEFAULT "DEFAULT"

/* piLogTarget values for Non-Snapshot restore                                */
#define DB2RESTORE_LOGTARGET_DEFAULT "DEFAULT"

/* piLogTarget values for Snapshot restore                                    */
#define DB2RESTORE_LOGTARGET_INCLUDE "INCLUDE"
#define DB2RESTORE_LOGTARGET_EXCLUDE "EXCLUDE"
#define DB2RESTORE_LOGTARGET_INCFORCE "INCLUDE FORCE"
#define DB2RESTORE_LOGTARGET_EXCFORCE "EXCLUDE FORCE"

/* Backup Definitions                                                         */

/* Tablespace List Structure                                                  */
/******************************************************************************
** db2TablespaceStruct data structure
** db2TablespaceStruct data structure specific parameters
** 
** tablespaces
** Input. A pointer to the list of table spaces to be backed up. For C,
** the list is null-terminated strings. In the generic case, it is a
** list of db2Char structures.
** 
** numTablespaces
** Input. Number of entries in the tablespaces parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2TablespaceStruct
{
  char                        **tablespaces;
  db2Uint32                   numTablespaces;
} db2TablespaceStruct;

/* Media List Structure                                                       */
/******************************************************************************
** db2MediaListStruct data structure
** db2MediaListStruct data structure parameters
** 
** locations
** Input. A pointer to the list of media locations. For C, the list is
** null-terminated strings. In the generic case, it is a list of db2Char
** structures.
** 
** numLocations
** Input. The number of entries in the locations parameter.
** 
** locationType
** Input. A character indicated the media type. Valid values (defined in
** sqlutil header file, located in the include directory.) are:
** - SQLU_LOCAL_MEDIA
** Local devices (tapes, disks, diskettes, or named pipes).
** - SQLU_TSM_MEDIA
** Tivoli Storage Manager.
** - SQLU_OTHER_MEDIA
** Vendor library.
** - SQLU_USER_EXIT
** User exit (only available when the server is on OS/2).
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2MediaListStruct
{
  char                        **locations;
  db2Uint32                   numLocations;
  char                        locationType;
} db2MediaListStruct;

/* Multi-partition Backup output structure                                    */
/******************************************************************************
** db2BackupMPPOutputStruct data structure
** db2BackupMPPOutputStruct data structure parameters
** 
** nodeNumber
** Output. The number of the database partition that this structure
** contains information for.
** 
** backupSize
** Output. Size of the backup image (in MB) for this partition.
** 
** sqlca
** Output. The sqlca returned by this partition.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2BackupMPPOutputStruct
{
  db2NodeType                 nodeNumber;   /* Partition number that this     */
                                            /* structure applies to           */
  char                        pad[6];
  db2Uint64                   backupSize;   /* Size of backup generated on    */
                                            /* this partition                 */
  struct sqlca                sqlca;        /* sqlca returned from this       */
                                            /* partition                      */
} db2BackupMPPOutputStruct;

/* Backup Structure                                                           */
/******************************************************************************
** db2BackupStruct data structure
** db2BackupStruct data structure parameters
** 
** piDBAlias
** Input. A string containing the database alias (as cataloged in the system
** database directory) of the database to back up.
** 
** oApplicationId
** Output. The API will return a string identifying the agent servicing the
** application. Can be used to obtain information about the progress of the
** backup operation using the database monitor.
** 
** oTimestamp
** Output. The API will return the time stamp of the backup image
** 
** piTablespaceList
** Input. List of table spaces to be backed up. Required for table space level
** backup only. Must be NULL for a database level backup. See structure
** db2TablespaceStruct.
** 
** piMediaList
** Input. This structure allows the caller to specify the destination for the
** backup operation. The information provided depends on the value of the
** locationType parameter. The valid values for locationType parameter
** (defined in sqlutil header file, located in the include directory) are:
** - SQLU_LOCAL_MEDIA
** Local devices (a combination of tapes, disks, or diskettes).
** - SQLU_TSM_MEDIA
** TSM. If the locations pointer is set to NULL, the TSM shared library
** provided with DB2 is used. If a different version of the TSM shared
** library is desired, use SQLU_OTHER_MEDIA and provide the shared
** library name.
** - SQLU_OTHER_MEDIA
** Vendor product. Provide the shared library name in the locations field.
** - SQLU_SNAPSHOT_MEDIA
** Snapshot capable storage media.
** - SQLU_USER_EXIT
** User exit. No additional input is required (only available when server is on
** OS/2).
** 
** For more information, see the db2MediaListStruct structure.
** 
** piUsername
** Input. A string containing the user name to be used when attempting a
** connection. Can be NULL.
** 
** piPassword
** Input. A string containing the password to be used with the user name. Can
** be NULL.
** 
** piVendorOptions
** Input. Used to pass information from the application to the vendor functions.
** This data structure must be flat; that is, no level of indirection is
** supported. Note that byte-reversal is not done, and code page is not checked
** for this data. 
** 
** iVendorOptionsSize
** Input. The length of the piVendorOptions field, which cannot exceed 65535
** bytes.
** 
** oBackupSize
** Output. Size of the backup image (in MB).
** 
** iCallerAction
** Input. Specifies action to be taken. Valid values (defined in db2ApiDf
** header file, located in the include directory) are:
** - DB2BACKUP_BACKUP
** Start the backup.
** - DB2BACKUP_NOINTERRUPT
** Start the backup. Specifies that the backup will run unattended, and that
** scenarios which normally require user intervention will either be attempted
** without first returning to the caller, or will generate an error. Use this
** caller action, for example, if it is known that all of the media required
** for the backup have been mounted, and utility prompts are not desired.
** - DB2BACKUP_CONTINUE
** Continue the backup after the user has performed some action requested
** by the utility (mount a new tape, for example).
** - DB2BACKUP_TERMINATE
** Terminate the backup after the user has failed to perform some action
** requested by the utility.
** - DB2BACKUP_DEVICE_TERMINATE
** Remove a particular device from the list of devices used by backup. When
** a particular medium is full, backup will return a warning to the caller
** (while continuing to process using the remaining devices). Call backup
** again with this caller action to remove the device which generated the
** warning from the list of devices being used.
** - DB2BACKUP_PARM_CHK
** Used to validate parameters without performing a backup. This option does
** not terminate the database connection after the call returns. After
** successful return of this call, it is expected that the user will issue
** a call with SQLUB_CONTINUE to proceed with the action. 
** - DB2BACKUP_PARM_CHK_ONLY
** Used to validate parameters without performing a backup. Before this call
** returns, the database connection established by this call is terminated,
** and no subsequent call is required.
** 
** iBufferSize
** Input. Backup buffer size in 4 KB allocation units (pages). Minimum is 8
** units.
** 
** iNumBuffers
** Input. Specifies number of backup buffers to be used. Minimum is 2.
** Maximum is limited by memory.
** 
** iParallelism
** Input. Degree of parallelism (number of buffer manipulators). Minimum is 1.
** Maximum is 1024.
** 
** iOptions
** Input. A bitmap of backup properties. The options are to be combined using
** the bitwise OR operator to produce a value for iOptions. Valid values
** (defined in db2ApiDf header file, located in the include directory) are:
** DB2BACKUP_OFFLINE
** Offline gives an exclusive connection to the database.
** DB2BACKUP_ONLINE
** Online allows database access by other applications while the backup
** operation occurs.
** Note:
** An online backup operation may appear to hang if users are holding
** locks on SMS LOB data.
** DB2BACKUP_DB
** Full database backup.
** DB2BACKUP_TABLESPACE
** Table space level backup. For a table space level backup, provide a list of
** table spaces in the piTablespaceList parameter.
** DB2BACKUP_INCREMENTAL
** Specifies a cumulative (incremental) backup image. An incremental
** backup image is a copy of all database data that has changed since the
** most recent successful, full backup operation.
** DB2BACKUP_DELTA
** Specifies a noncumulative (delta) backup image. A delta backup image is
** a copy of all database data that has changed since the most recent
** successful backup operation of any type.
** DB2BACKUP_COMPRESS
** Specifies that the backup should be compressed.
** DB2BACKUP_INCLUDE_COMPR_LIB
** Specifies that the library used for compressing the backup should be
** included in the backup image.
** DB2BACKUP_EXCLUDE_COMPR_LIB
** Specifies that the library used for compressing the backup should be not
** included in the backup image.
** DB2BACKUP_INCLUDE_LOGS
** Specifies that the backup image should also include the range of log files
** required to restore and roll forward this image to some consistent point in
** time. This option is not valid for an offline backup or a multi-partition
** backup.
** DB2BACKUP_EXCLUDE_LOGS
** Specifies that the backup image should not include any log files.
** Note:
** When performing an offline backup operation, logs are excluded
** whether or not this option is specified.
** 
** iUtilImpactPriority
** Input. Specifies the priority value that will be used during a backup. The
** priority value can be any number between 0 and 100, with 0 representing
** unthrottled and 100 representing the highest priority.
** 
** piComprLibrary
** Input. Indicates the name of the external library to be used to perform
** compression of the backup image. The name must be a fully-qualified path
** referring to a file on the server. If the value is a null pointer or a
** pointer to an empty string, DB2 will use the default library for
** compression. If the specified library is not found, the backup will
** fail.
** 
** piComprOptions
** Input. Describes a block of binary data that will be passed to the
** initialization routine in the compression library. DB2 will pass this
** string directly from the client to the server, so any issues of
** byte-reversal or code-page conversion will have to be handled by the
** compression library. If the first character of the data block is '@',
** the remainder of the data will be interpreted by DB2 as the
** name of a file residing on the server. DB2 will then replace the contents of
** piComprOptions and iComprOptionsSize with the contents and size of this
** file respectively and will pass these new values to the initialization
** routine instead.
** 
** iComprOptionsSize
** Input. A four-byte unsigned integer representing the size of the block
** of data passed as piComprOptions. iComprOptionsSize shall be zero if
** and only if piComprOptions is a null pointer.
** 
** iAllNodeFlag
** Input. Partitioned database environments only. Indicates whether the
** backup operation is to be applied to all database partition servers
** defined in db2nodes.cfg. Valid values are:
** - DB2BACKUP_NODE_LIST
** Apply to database partition servers in a list that is passed in piNodeList.
** - DB2BACKUP_ALL_NODES
** Apply to all database partition servers. piNodeList should be NULL. This is
** the default value.
** - DB2BACKUP_ALL_EXCEPT
** Apply to all database partition servers except those in a list that is passed
** in piNodeList.
** 
** iNumNodes
** Input. Partitioned database environments only. Specifies the number of
** database partition servers in the piNodeList array.
** 
** piNodeList
** Input. Partitioned database environments only. A pointer to an array of
** database partition server numbers on which to perform the backup.
** 
** iNumMPPOutputStructs
** Input. Partitioned database environments only. Defines the size of the
** output parameter poMPPOutputStruct, which must be large enough to hold
** status information from each database partition that is being backed up.
** The value of this parameter must be the same as the number of database
** partition servers for which this API is being called. 
** 
** poMPPOutputStruct
** Output. Partitioned database environments only. Database partition reply
** information.
** 
** piEncrLibrary
** Input. Indicates the name of the external library to be used to perform
** encryption of the backup image. The name must be a fully-qualified path
** referring to a file on the server. If the value is a null pointer or a
** pointer to an empty string, DB2 will not encrypt the backup image.
** If the specified library is not found, the backup will fail.
** 
** piEncrOptions
** Input. Describes a block of binary data that will be passed to the
** initialization routine in the encryption library. DB2 will pass this
** string directly from the client to the server, so any issues of
** byte-reversal or code-page conversion will have to be handled by the
** encryption library. If the first character of the data block is '@',
** the remainder of the data will be interpreted by DB2 as the
** name of a file residing on the server. DB2 will then replace the contents of
** piEncrOptions and iEncrOptionsSize with the contents and size of this
** file respectively and will pass these new values to the initialization
** routine instead.
** 
** iEncrOptionsSize
** Input. A four-byte unsigned integer representing the size of the block
** of data passed as piEncrOptions. iEncrOptionsSize shall be zero if
** and only if piEncrOptions is a null pointer.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2BackupStruct
{
  char                        *piDBAlias;
  char                        oApplicationId[SQLU_APPLID_LEN+1];
  char                        oTimestamp[SQLU_TIME_STAMP_LEN+1];
  struct db2TablespaceStruct  *piTablespaceList;
  struct db2MediaListStruct   *piMediaList;
  char                        *piUsername;
  char                        *piPassword;
  void                        *piVendorOptions;
  db2Uint32                   iVendorOptionsSize;
  db2Uint32                   oBackupSize;
  db2Uint32                   iCallerAction;
  db2Uint32                   iBufferSize;
  db2Uint32                   iNumBuffers;
  db2Uint32                   iParallelism;
  db2Uint32                   iOptions;
  db2Uint32                   iUtilImpactPriority; /* Throttle Parameter      */
  char                        *piComprLibrary; /* Name of compression         */
                                            /* library                        */
  void                        *piComprOptions; /* Vendor-specific options     */
                                            /* for compression plug-in        */
  db2Uint32                   iComprOptionsSize; /* Size of piComprOptions    */
                                            /* block                          */
  db2Uint32                   iAllNodeFlag; /* Flag indicating how            */
                                            /* piNodeList should be used      */
  db2Uint32                   iNumNodes;    /* Number of partitions in        */
                                            /* piNodeList                     */
  db2NodeType                 *piNodeList;  /* Partition list                 */
  db2Uint32                   iNumMPPOutputStructs; /* Number of elements in  */
                                            /* piMPPOutputStruct array        */
  struct db2BackupMPPOutputStruct *poMPPOutputStruct; /* Per-partition        */
                                            /* backup output                  */
  char                        *piEncrLibrary; /* Name of encryption library   */
  void                        *piEncrOptions; /* Vendor-specific options for  */
                                            /* encryption plug-in             */
  db2Uint32                   iEncrOptionsSize; /* Size of piEncrOptions      */
                                            /* block                          */
} db2BackupStruct;

/* Backup API                                                                 */
/******************************************************************************
** db2Backup API
** Creates a backup copy of a database or a table space.
** 
** Scope
** 
** This API only affects the database partition on which it is executed.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** Database. This API automatically establishes a connection to the specified
** database.
** 
** The connection will be terminated upon the completion of the backup.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Backup API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pDB2BackupStruct.
** 
** pDB2BackupStruct
** Input. A pointer to the db2BackupStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** This API takes a back up of a database and Label-Based Access Control (LBAC)
** is not enforced when such back up occurs. Thus, an application that calls
** this API can gain access to table data if the caller has sufficient authority
** to call the API and is able to restore the backed up database somewhere else.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN
  db2Backup (
       db2Uint32 versionNumber,
       void * pDB2BackupStruct,
       struct sqlca * pSqlca);

/* Generic Backup Definitions                                                 */

/* Generic Tablespace List Structure                                          */
/******************************************************************************
** db2gTablespaceStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gTablespaceStruct
{
  struct db2Char              *tablespaces;
  db2Uint32                   numTablespaces;
} db2gTablespaceStruct;

/* Generic Media List Structure                                               */
/******************************************************************************
** db2gMediaListStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gMediaListStruct
{
  struct db2Char              *locations;
  db2Uint32                   numLocations;
  char                        locationType;
} db2gMediaListStruct;

/* Multi-partition Backup output structure                                    */
typedef SQL_STRUCTURE db2gBackupMPPOutputStruct
{
  db2NodeType                 nodeNumber;   /* Partition number that this     */
                                            /* structure applies to           */
  char                        pad[6];
  db2Uint64                   backupSize;   /* Size of backup generated on    */
                                            /* this partition                 */
  struct sqlca                sqlca;        /* sqlca returned from this       */
                                            /* partition                      */
} db2gBackupMPPOutputStruct;

/* Generic Backup Structure                                                   */
/******************************************************************************
** db2gBackupStruct data structure
** db2gBackupStruct data structure specific parameters
** 
** iDBAliasLen
** Input. A 4-byte unsigned integer representing the length in bytes of the
** database alias.
** 
** iApplicationIdLen
** Input. A 4-byte unsigned integer representing the length in bytes of the
** poApplicationId buffer. Should be equal to SQLU_APPLID_LEN+1 (defined in
** sqlutil.h).
** 
** iTimestampLen
** Input. A 4-byte unsigned integer representing the length in bytes of the
** poTimestamp buffer. Should be equal to SQLU_TIME_STAMP_LEN+1
** (defined in sqlutil.h).
** 
** iUsernameLen
** Input. A 4-byte unsigned integer representing the length in bytes of the user
** name. Set to zero if no user name is provided.
** 
** iPasswordLen
** Input. A 4-byte unsigned integer representing the length in bytes of the
** password. Set to zero if no password is provided.
** 
** iComprLibraryLen
** Input. A four-byte unsigned integer representing the length in bytes of the
** name of the library specified in piComprLibrary. Set to zero if no
** library name is given.
** 
** iEncrLibraryLen
** Input. A four-byte unsigned integer representing the length in bytes of the
** name of the library specified in piEncrLibrary. Set to zero if no
** library name is given.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gBackupStruct
{
  char                        *piDBAlias;
  db2Uint32                   iDBAliasLen;
  char                        *poApplicationId;
  db2Uint32                   iApplicationIdLen;
  char                        *poTimestamp;
  db2Uint32                   iTimestampLen;
  struct db2gTablespaceStruct *piTablespaceList;
  struct db2gMediaListStruct  *piMediaList;
  char                        *piUsername;
  db2Uint32                   iUsernameLen;
  char                        *piPassword;
  db2Uint32                   iPasswordLen;
  void                        *piVendorOptions;
  db2Uint32                   iVendorOptionsSize;
  db2Uint32                   oBackupSize;
  db2Uint32                   iCallerAction;
  db2Uint32                   iBufferSize;
  db2Uint32                   iNumBuffers;
  db2Uint32                   iParallelism;
  db2Uint32                   iOptions;
  db2Uint32                   iUtilImpactPriority; /* Throttle Parameter      */
  char                        *piComprLibrary; /* Name of compression         */
                                            /* library                        */
  db2Uint32                   iComprLibraryLen; /* Length of compression      */
                                            /* library name                   */
  void                        *piComprOptions; /* Vendor-specific options     */
                                            /* for compression plug-in        */
  db2Uint32                   iComprOptionsSize; /* Size of piComprOptions    */
                                            /* block                          */
  db2Uint32                   iAllNodeFlag; /* Flag indicating how            */
                                            /* piNodeList should be used      */
  db2Uint32                   iNumNodes;    /* Number of partitions in        */
                                            /* piNodeList                     */
  db2NodeType                 *piNodeList;  /* Partition list                 */
  db2Uint32                   iNumMPPOutputStructs; /* Number of elements in  */
                                            /* piMPPOutputStruct array        */
  struct db2gBackupMPPOutputStruct *poMPPOutputStruct; /* Per-partition       */
                                            /* backup output                  */
  char                        *piEncrLibrary; /* Name of encryption library   */
  db2Uint32                   iEncrLibraryLen; /* Length of encryption        */
                                            /* library name                   */
  void                        *piEncrOptions; /* Vendor-specific options for  */
                                            /* encryption plug-in             */
  db2Uint32                   iEncrOptionsSize; /* Size of piEncrOptions      */
                                            /* block                          */
} db2gBackupStruct;

/* Generic Backup API                                                         */
/******************************************************************************
** db2gBackup API
*******************************************************************************/
SQL_API_RC SQL_API_FN
  db2gBackup (
       db2Uint32 versionNumber,
       void * pDB2gBackupStruct,
       struct sqlca * pSqlca);

/* Restore Definitions                                                        */

/******************************************************************************
** db2StoragePathsStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2StoragePathsStruct
{
  char                        **storagePaths;
  db2Uint32                   numStoragePaths;
} db2StoragePathsStruct;

/******************************************************************************
** db2SchemaListStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2SchemaListStruct
{
  char                        **schemas;    /* A list of SCHEMA names to be   */
                                            /* transported                    */
  db2Uint32                   numSchemas;   /* The number of SCHEMAS in the   */
                                            /* list                           */
} db2SchemaListStruct;

/* Restore Structure                                                          */
/******************************************************************************
** db2RestoreStruct data structure
** db2RestoreStruct data structure parameters
** 
** piSourceDBAlias 
** Input. A string containing the database alias of the source database
** backup image. 
** 
** piTargetDBAlias
** Input. A string containing the target database alias. If this parameter
** is null, the value of the piSourceDBAlias parameter will be used. 
** 
** oApplicationId
** Output. The API will return a string identifying the agent servicing the
** application. Can be used to obtain information about the progress of the
** backup operation using the database monitor. 
** 
** piTimestamp 
** Input. A string representing the time stamp of the backup image. This field
** is optional if there is only one backup image in the source specified. 
** 
** piTargetDBPath
** Input. A string containing the relative or fully qualified name of the target
** database directory on the server. Used if a new database is to be created for
** the restored backup; otherwise not used.
** 
** piReportFile 
** Input. The file name, if specified, must be fully qualified. The datalinks
** files that become unlinked during a restore (as a result of a fast reconcile)
** will be reported. 
** 
** piTablespaceList
** Input. List of table spaces to be restored. Used when restoring a subset of
** table spaces from a database or table space backup image. See the
** DB2TablespaceStruct structure. The following restrictions apply: 
** - The database must be recoverable; that is, log retain or user exits
** must be enabled. 
** - The database being restored to must be the same database that was used
** to create the backup image. That is, table spaces can not be added to a
** database through the table space restore function. 
** - The rollforward utility will ensure that table spaces restored in a
** partitioned database environment are synchronized with any other database
** partition containing the same table spaces. If a table space restore
** operation is requested and the piTablespaceList is NULL, the restore
** utility will attempt to restore all of the table spaces in the backup image.
** 
** When restoring a table space that has been renamed since it was backed up,
** the new table space name must be used in the restore command. If the old
** table space name is used, it will not be found. 
** 
** piMediaList 
** Input. Source media for the backup image. The information provided depends on
** the value of the locationType parameter. The valid values for locationType
** parameter (defined in sqlutil header file, located in the include
** directory) are: 
** - SQLU_LOCAL_MEDIA 
** Local devices (a combination of tapes, disks, or diskettes). 
** - SQLU_XBSA_MEDIA 
** XBSA interface. Backup Services APIs (XBSA) are an open application
** programming interface for applications or facilities needing data storage
** management for backup or archiving purposes. 
** - SQLU_TSM_MEDIA 
** TSM. If the locations pointer is set to NULL, the TSM shared library provided
** with DB2 is used. If a different version of the TSM shared library is
** desired, use SQLU_OTHER_MEDIA and provide the shared library name. 
** - SQLU_OTHER_MEDIA 
** Vendor product. Provide the shared library name in the locations field. 
** - SQLU_SNAPSHOT_MEDIA
** Snapshot capable storage media.
** - SQLU_USER_EXIT 
** User exit. No additional input is required (only available when server is on
** OS/2).
** 
** piUsername 
** Input. A string containing the user name to be used when attempting a
** connection. Can be NULL.
** 
** piPassword
** Input. A string containing the password to be used with the user name.
** Can be NULL. 
** 
** piNewLogPath
** Input. A string representing the path to be used for logging after the
** restore has completed. If this field is null the default log path will
** be used. 
** 
** piVendorOptions
** Input. Used to pass information from the application to the vendor functions.
** This data structure must be flat; that is, no level of indirection is
** supported. Note that byte-reversal is not done, and the code page is not
** checked for this data. 
** 
** iVendorOptionsSize 
** Input. The length in bytes of the piVendorOptions parameter, which cannot
** exceed 65535 bytes. 
** 
** iParallelism 
** Input. Degree of parallelism (number of buffer manipulators). Minimum is 1.
** Maximum is 1024. 
** 
** iBufferSize 
** Input. Backup buffer size in 4 KB allocation units (pages). Minimum is
** 8 units. The size entered for a restore must be equal to or an integer
** multiple of the buffer size used to produce the backup image. 
** 
** iNumBuffers 
** Input. Specifies number of restore buffers to be used. 
** 
** iCallerAction 
** Input. Specifies action to be taken. Valid values (defined in db2ApiDf
** header file, located in the include directory) are: 
** 
** - DB2RESTORE_RESTORE 
** Start the restore operation. 
** 
** - DB2RESTORE_NOINTERRUPT 
** Start the restore. Specifies that the restore will run unattended, and that
** scenarios which normally require user intervention will either be attempted
** without first returning to the caller, or will generate an error. Use this
** caller action, for example, if it is known that all of the media required for
** the restore have been mounted, and utility prompts are not desired. 
** 
** - DB2RESTORE_CONTINUE 
** Continue the restore after the user has performed some action requested by
** the utility (mount a new tape, for example). 
** 
** - DB2RESTORE_TERMINATE 
** Terminate the restore after the user has failed to perform some action
** requested by the utility. 
** 
** - DB2RESTORE_DEVICE_TERMINATE 
** Remove a particular device from the list of devices used by restore. When
** a particular device has exhausted its input, restore will return a warning
** to the caller. Call restore again with this caller action to remove the
** device which generated the warning from the list of devices being used. 
** 
** - DB2RESTORE_PARM_CHK 
** Used to validate parameters without performing a restore. This option does
** not terminate the database connection after the call returns. After
** a successful return of this call, it is expected that the user will issue
** another call to this API with the iCallerAction parameter set to the value
** DB2RESTORE_CONTINUE to continue with the restore.
** 
** - DB2RESTORE_PARM_CHK_ONLY 
** Used to validate parameters without performing a restore. Before this call
** returns, the database connection established by this call is terminated, and
** no subsequent call is required. 
** 
** - DB2RESTORE_TERMINATE_INCRE 
** Terminate an incremental restore operation before completion. 
** 
** - DB2RESTORE_RESTORE_STORDEF 
** Initial call. Table space container redefinition requested. 
** 
** - DB2RESTORE_STORDEF_NOINTERRUPT 
** Initial call. The restore will run uninterrupted. Table space container
** redefinition requested. 
** 
** iOptions 
** Input. A bitmap of restore properties. The options are to be combined using
** the bitwise OR operator to produce a value for iOptions. Valid values
** (defined in db2ApiDf header file, located in the include directory) are: 
** 
** - DB2RESTORE_OFFLINE 
** Perform an offline restore operation. 
** 
** - DB2RESTORE_ONLINE 
** Perform an online restore operation. 
** 
** - DB2RESTORE_DB 
** Restore all table spaces in the database. This must be run offline.
** 
** - DB2RESTORE_TABLESPACE 
** Restore only the table spaces listed in the piTablespaceList parameter from
** the backup image. This can be online or offline. 
** 
** - DB2RESTORE_HISTORY 
** Restore only the history file.
** 
** - DB2RESTORE_COMPR_LIB
** Indicates that the compression library is to be restored. This option
** cannot be used simultaneously with any other type of restore process. If the
** object exists in the backup image, it will be restored into the database
** directory. If the object does not exist in the backup image, the restore
** operation will fail. 
** 
** - DB2RESTORE_LOGS
** Specifies that only the set of log files contained in the backup image are
** to be restored. If the backup image does not include log files, the restore
** operation will fail. If this option is specified, the piLogTarget parameter
** must also be specified.
** 
** - DB2RESTORE_INCREMENTAL 
** Perform a manual cumulative restore operation. 
** 
** - DB2RESTORE_AUTOMATIC 
** Perform an automatic cumulative (incremental) restore operation. Must be
** specified with DB2RESTORE_INCREMENTAL. 
** 
** - DB2RESTORE_NOENCRYPT 
** When restoring into a new database, force the new database to disable
** encryption. This option is ignored when restoring into an existing database,
** where the existing database's encryption settings are honoured.
** 
** - DB2RESTORE_DATALINK 
** Perform reconciliation operations. Tables with a defined DATALINK column must
** have RECOVERY YES option specified. 
** 
** - DB2RESTORE_NODATALINK 
** Do not perform reconciliation operations. Tables with DATALINK data type
** columns are placed into DataLink_Roconcile_pending (DRP) state. Tables
** with a defined DATALINK column must have the RECOVERY YES option specified.
** 
** - DB2RESTORE_ROLLFWD 
** Place the database in rollforward pending state after it has been
** successfully restored. 
** 
** - DB2RESTORE_NOROLLFWD 
** Do not place the database in rollforward pending state after it has been
** successfully restored. This cannot be specified for backups taken online or
** for table space level restores. If, following a successful restore, the
** database is in roll-forward pending state, the db2Rollforward API
** must be called before the database can be used.
** 
** - DB2RESTORE_TRNSPORT 
** Performs the transport operation. A list of tablespaces and schemas that form
** the transport set must be provided.
** 
** piComprLibrary
** Input. Indicates the name of the external library to use to decompress the
** backup image if the image is compressed. The name must be a fully-qualified
** path that refers to a file on the server. If the value is a null pointer or
** a pointer to an empty string, DB2 UDB attempts to use the library stored in
** the image. If the backup is not compressed, the value of this parameter will
** be ignored. If the specified library is not found, the restore operation will
** fail.
** 
** piComprOptions
** Input. This API parameter describes a block of binary data that will
** be passed to the initialization routine in the decompression library. DB2
** UDB passes this string directly from the client to the server, so any
** issues of byte-reversal or code-page conversion must be handled by the
** compression library. If the first character of the data block is '@',
** the remainder of the data is interpreted as the name of a file residing
** on the server. DB2 UDB then replaces the contents of the piComprOptions
** and iComprOptionsSize parameters with the contents and size of this
** file and passes these new values to the initialization routine.
** 
** iComprOptionsSize
** Input. A four-byte unsigned integer that represents the size of the block of
** data passed as piComprOptions. The iComprOptionsSize parameter should be
** zero if and only if the piComprOptions value is a null pointer.
** 
** piLogTarget
** Input. Specifies the absolute path of a directory on the database server that
** must be used as the target directory for extracting log files from a backup
** image. If this parameter is specified, any log files included in the backup
** image are extracted into the target directory. If this parameter is not
** specified, log files included in the backup image are not extracted. To
** extract only the log files from the backup image, DB2RESTORE_LOGS
** value should be passed to the iOptions parameter.
** 
** piStoragePaths
** Input. List of storage paths to be used. Used when restoring to a database
** that uses automatic storage. See the db2StoragePathsStruct structure.
** 
** piSchemaList
** The list of schemas to be transported.
** 
** piStagingDBAlias
** The staging database name to be used with the TRANSPORT option.
** If this parameter is NULL the staging database name will be
** internally generated and the database will be dropped after transport
** completes. If a name is provided the staging database will not be dropped.
** 
** piStogroup
** The target storage group for all AS tablespaces being transported to the 
** target database. The storage group name refers to the target storage group 
** on the target database.
** 
** If this parameter is NULL the default storage group on the target
** database will be used.
** 
** piEncrLibrary
** Input. Indicates the name of the external library to use to decrypt the
** backup image if the image is encrypted. The name must be a fully-qualified
** path that refers to a file on the server. If the value is a null pointer or
** a pointer to an empty string, DB2 UDB attempts to use the library stored in
** the image. If the backup is not encrypted, the value of this parameter will
** be ignored. If the specified library is not found, the restore operation will
** fail.
** 
** piEncrOptions
** Input. This API parameter describes a block of binary data that will
** be passed to the initialization routine in the decryption library. DB2
** UDB passes this string directly from the client to the server, so any
** issues of byte-reversal or code-page conversion must be handled by the
** encryption library. If the first character of the data block is '@',
** the remainder of the data is interpreted as the name of a file residing
** on the server. DB2 UDB then replaces the contents of the piEncrOptions
** and iEncrOptionsSize parameters with the contents and size of this
** file and passes these new values to the initialization routine.
** 
** iEncrOptionsSize
** Input. A four-byte unsigned integer that represents the size of the block of
** data passed as piEncrOptions. The iEncrOptionsSize parameter should be
** zero if and only if the piEncrOptions value is a null pointer.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RestoreStruct
{
  char                        *piSourceDBAlias;
  char                        *piTargetDBAlias;
  char                        oApplicationId[SQLU_APPLID_LEN+1];
  char                        *piTimestamp;
  char                        *piTargetDBPath;
  char                        *piReportFile;
  struct db2TablespaceStruct  *piTablespaceList;
  struct db2MediaListStruct   *piMediaList;
  char                        *piUsername;
  char                        *piPassword;
  char                        *piNewLogPath;
  void                        *piVendorOptions;
  db2Uint32                   iVendorOptionsSize;
  db2Uint32                   iParallelism;
  db2Uint32                   iBufferSize;
  db2Uint32                   iNumBuffers;
  db2Uint32                   iCallerAction;
  db2Uint32                   iOptions;
  char                        *piComprLibrary; /* Name of compression         */
                                            /* library                        */
  void                        *piComprOptions; /* Vendor-specific options     */
                                            /* for compression plug-in        */
  db2Uint32                   iComprOptionsSize; /* Size of piComprOptions    */
                                            /* block                          */
  char                        *piLogTarget;
  struct db2StoragePathsStruct *piStoragePaths;
  char                        *piRedirectScript; /* Redirect restore script   */
                                            /* file name                      */
  struct db2SchemaListStruct  *piSchemaList; /* The list of schemas to be     */
                                            /* transported                    */
  char                        *piStagingDBAlias; /* The staging database      */
                                            /* name for TRANSPORT             */
  char                        *piStogroup;  /* The target storage group for   */
                                            /* TRANSPORT                      */
  char                        *piEncrLibrary; /* Name of encryption library   */
  void                        *piEncrOptions; /* Vendor-specific options for  */
                                            /* encryption plug-in             */
  db2Uint32                   iEncrOptionsSize; /* Size of piEncrOptions      */
                                            /* block                          */
  struct sqleDbEncryptionOptions *piDbEncOpts; /* Database encryption         */
                                            /* options                        */
} db2RestoreStruct;

/* Restore API                                                                */
/******************************************************************************
** db2Restore API
** Rebuilds a damaged or corrupted database that has been backed up using
** db2Backup API. The restored database is in the same state
** it was in when the backup copy was made. This utility can also restore
** to a database with a name different from the database name in the
** backup image (in addition to being able to restore to a new database).
** 
** This utility can also be used to restore DB2 databases created in the
** two previous releases.
** 
** This utility can also restore from a table space level backup, or restore
** table spaces from within a database backup image.
** 
** Scope
** 
** This API only affects the database partition from which it is called.
** 
** Authorization
** 
** To restore to an existing database, one of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** To restore to a new database, one of the following:
** - sysadm
** - sysctrl
** 
** Required connection
** 
** Database, to restore to an existing database. This API automatically
** establishes a connection to the specified database and will release the
** connection when the restore operation finishes.
** 
** Instance and database, to restore to a new database. The instance
** attachment is required to create the database.
** 
** To restore to a new database at an instance different from the current
** instance (as defined by the value of the DB2INSTANCE environment
** variable), it is necessary to first attach to the instance where the
** new database will reside.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Restore API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pDB2RestoreStruct.
** 
** pDB2RestoreStruct
** Input. A pointer to the db2RestoreStruct structure
** 
** pSqlca
** Output. A pointer to the sqlca structure
** 
** Usage notes
** 
** For offline restore, this utility connects to the database in exclusive
** mode. The utility fails if any application, including the calling
** application, is already connected to the database that is being restored.
** In addition, the request will fail if the restore utility is being used
** to perform the restore, and any application, including the calling
** application, is already connected to any database on the same
** workstation. If the connect is successful, the API locks out other
** applications until the restore is completed.
** 
** The current database configuration file will not be replaced by the
** backup copy unless it is unusable. If the file is replaced, a warning
** message is returned.
** 
** The database or table space must have been backed up using the db2Backup API.
** 
** If the caller action value is DB2RESTORE_NOINTERRUPT, the restore
** continues without prompting the application. If the caller action
** value is DB2RESTORE_RESTORE, and the utility is restoring to an existing
** database, the utility returns control to the application with a message
** requesting some user interaction. After handling the user interaction,
** the application calls RESTORE DATABASE again, with the caller action
** value set to indicate whether processing is to continue
** (DB2RESTORE_CONTINUE) or terminate (DB2RESTORE_TERMINATE) on the
** subsequent call. The utility finishes processing, and returns an
** SQLCODE in the sqlca.
** 
** To close a device when finished, set the caller action value to
** DB2RESTORE_DEVICE_TERMINATE. If, for example, a user is restoring from 3
** tape volumes using 2 tape devices, and one of the tapes has been
** restored, the application obtains control from the API with an SQLCODE
** indicating end of tape. The application can prompt the user to mount
** another tape, and if the user indicates "no more", return to the
** API with caller action value SQLUD_DEVICE_TERMINATE to signal
** end of the media device. The device driver will be terminated, but
** the rest of the devices involved in the restore will continue to
** have their input processed until all segments of the restore set have been
** restored (the number of segments in the restore set is placed on the last
** media device during the backup process). This caller action can be used
** with devices other than tape (vendor supported devices).
** 
** To perform a parameter check before returning to the application, set
** caller action value to DB2RESTORE_PARM_CHK.
** 
** Set caller action value to DB2RESTORE_RESTORE_STORDEF when performing a
** redirected restore; used in conjunction with the sqlbstsc API.
** 
** If a system failure occurs during a critical stage of restoring a database,
** the user will not be able to successfully connect to the database until a
** successful restore is performed. This condition will be detected when the
** connection is attempted, and an error message is returned. If the
** backed-up database is not configured for roll-forward recovery, and there
** is a usable current configuration file with either of these parameters
** enabled, following the restore, the user will be required to either
** take a new backup of the database, or disable the log retain and user exit
** parameters before connecting to the database.
** 
** Although the restored database will not be dropped (unless restoring to a
** nonexistent database), if the restore fails, it will not be usable.
** 
** If the restore type specifies that the history file on the backup is to
** be restored, it will be restored over the existing history file for the
** database, effectively erasing any changes made to the history file
** after the backup that is being restored. If this is undesirable,
** restore the history file to a new or test database so that its 
** contents can be viewed without destroying any updates that have taken place.
** 
** If, at the time of the backup operation, the database was enabled for
** roll forward recovery, the database can be brought to the state it was in
** prior to the occurrence of the damage or corruption by issuing
** db2Rollforward after successful execution of db2Restore. If the database
** is recoverable, it will default to roll forward pending state after
** the completion of the restore.
** 
** If the database backup image is taken offline, and the caller does not
** want to roll forward the database after the restore, the
** DB2RESTORE_NOROLLFWD option can be used for the restore. This results
** in the database being useable immediately after the restore. If the
** backup image is taken online, the caller must roll forward through
** the corresponding log records at the completion of the restore.
** 
** To restore log files from a backup image that contains them, the LOGTARGET
** option must be specified, assuming a fully qualified and valid path
** exists on the DB2 server. If those conditions are satisfied, the restore
** utility writes the log files from the image to the target path. If
** LOGTARGET is specified during a restoration of a backup image that
** does not include logs, the restore operation returns an error
** before attempting to restore any table space data. A restore operation also
** fails with an error if an invalid or read-only LOGTARGET path is specified.
** 
** If any log files exist in the LOGTARGET path at the time the RESTORE command
** is issued, a warning prompt is returned to user. This warning is not
** returned if WITHOUT PROMPTING is specified.
** 
** During a restore operation in which a LOGTARGET is specified, if any log file
** cannot be extracted, the restore operation fails and returns an error. If
** any of the log files being extracted from the backup image have the same
** name as an existing file in the LOGTARGET path, the restore operation fails
** and an error is returned. The restore utility does not overwrite existing
** log files in the LOGTARGET directory.
** 
** You can restore only the saved log set from a backup image. To indicate
** that only the log files are to be restored, specify the LOGS option in
** addition to the LOGTARGET path. Specifying the LOGS option without a
** LOGTARGET path results in an error. If any problem occurs while restoring
** log files in this mode the restore operation terminates immediately and
** an error is returned.
** 
** During an automatic incremental restore operation, only the logs included
** in the target image of the restore operation are retrieved from the
** backup image. Any logs that are included in intermediate images that are
** referenced during the incremental restore process are not extracted from
** those intermediate backup images. During a manual incremental restore
** operation, the LOGTARGET path should be specified only with the final
** restore command.
** 
** If a backup is compressed, DB2 UDB detects this state and automatically
** decompresses the data before restoring it. If a library is specified on the
** db2Restore API, it is used for decompressing the data. If a library is not
** specified on the db2Restore API, the library stored in the backup image is
** used. And if there is no library stored in the backup image, the data
** cannot be decompressed and the restore operation fails.
** 
** If the compression library is being restored from a backup image (either
** explicitly by specifying the DB2RESTORE_COMPR_LIB restore type or
** implicitly by performing a normal restoration of a compressed backup), the
** restore operation must be done on the same platform and operating system
** that the backup was taken on. If the platforms are different, the restore
** operation will fail, even when DB2 UDB normally supports cross-platform
** restore operations involving the two systems.
** 
** If restoring a database that is enabled for automatic storage, the
** storage paths associated with the database can be redefined or they
** can remain as they were previously. To keep the storage path
** definitions as is, do not provide any storage paths as part of the
** restore operation. Otherwise, specify a new set of storage paths
** to associate with the database. Automatic storage table spaces will be
** automatically redirected to the new storage paths during the restore
** operation.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN
  db2Restore (
       db2Uint32 versionNumber,
       void * pDB2RestoreStruct,
       struct sqlca * pSqlca);

/* Generic Restore Definitions                                                */

/******************************************************************************
** db2gStoragePathsStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gStoragePathsStruct
{
  struct db2Char              *storagePaths;
  db2Uint32                   numStoragePaths;
} db2gStoragePathsStruct;

/******************************************************************************
** db2gSchemaListStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gSchemaListStruct
{
  struct db2Char              *schemas;     /* The list of SCHEMA names to    */
                                            /* be transported                 */
  db2Uint32                   numSchemas;   /* The number of SCHEMAS in the   */
                                            /* list                           */
} db2gSchemaListStruct;

/* Generic Restore Structure                                                  */
/******************************************************************************
** db2gRestoreStruct data structure
** db2gRestoreStruct data structure specific parameters
** 
** iSourceDBAliasLen
** Input. Specifies the length in bytes of the piSourceDBAlias parameter.
** 
** iTargetDBAliasLen
** Input. Specifies the length in bytes of the piTargetDBAlias parameter.
** 
** iApplicationIdLen
** Input. Specifies the length in bytes of the poApplicatoinId parameter.
** Should be equal to SQLU_APPLID_LEN + 1. The constant SQLU_APPLID_LEN is
** defined in sqlutil header file that is located in the include directory.
** 
** iTimestampLen
** Input. Specifies the length in bytes of the piTimestamp parameter.
** 
** iTargetDBPathLen
** Input. Specifies the length in bytes of the piTargetDBPath parameter.
** 
** iReportFileLen
** Input. Specifies the length in bytes of the piReportFile parameter.
** 
** iUsernameLen
** Input. Specifies the length in bytes of the piUsername parameter. Set
** to zero if no user name is provided.
** 
** iPasswordLen
** Input. Specifies the length in bytes of the piPassword parameter. Set
** to zero if no password is provided.
** 
** iNewLogPathLen 
** Input. Specifies the length in bytes of the piNewLogPath parameter.
** 
** iLogTargetLen
** Input. Specifies the length in bytes of the piLogTarget parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gRestoreStruct
{
  char                        *piSourceDBAlias;
  db2Uint32                   iSourceDBAliasLen;
  char                        *piTargetDBAlias;
  db2Uint32                   iTargetDBAliasLen;
  char                        *poApplicationId;
  db2Uint32                   iApplicationIdLen;
  char                        *piTimestamp;
  db2Uint32                   iTimestampLen;
  char                        *piTargetDBPath;
  db2Uint32                   iTargetDBPathLen;
  char                        *piReportFile;
  db2Uint32                   iReportFileLen;
  struct db2gTablespaceStruct *piTablespaceList;
  struct db2gMediaListStruct  *piMediaList;
  char                        *piUsername;
  db2Uint32                   iUsernameLen;
  char                        *piPassword;
  db2Uint32                   iPasswordLen;
  char                        *piNewLogPath;
  db2Uint32                   iNewLogPathLen;
  void                        *piVendorOptions;
  db2Uint32                   iVendorOptionsSize;
  db2Uint32                   iParallelism;
  db2Uint32                   iBufferSize;
  db2Uint32                   iNumBuffers;
  db2Uint32                   iCallerAction;
  db2Uint32                   iOptions;
  char                        *piComprLibrary; /* Name of compression         */
                                            /* library                        */
  db2Uint32                   iComprLibraryLen; /* Length of compression      */
                                            /* library name                   */
  void                        *piComprOptions; /* Vendor-specific options     */
                                            /* for compression plug-in        */
  db2Uint32                   iComprOptionsSize; /* Size of piComprOptions    */
                                            /* block                          */
  char                        *piLogTarget;
  db2Uint32                   iLogTargetLen;
  struct db2gStoragePathsStruct *piStoragePaths;
  char                        *piRedirectScript; /* Redirect restore script   */
                                            /* file name                      */
  db2Uint32                   iRedirectScriptLen; /* Length of                */
                                            /* piRedirectScript               */
  struct db2gSchemaListStruct *piSchemaList; /* The list of schemas to be     */
                                            /* transported                    */
  char                        *piStagingDBAlias; /* The staging database      */
                                            /* name for TRANSPORT             */
  db2Uint32                   iStagingDBAliasLen; /* The length of the        */
                                            /* staging database name          */
  char                        *piEncrLibrary; /* Name of encryption library   */
  db2Uint32                   iEncrLibraryLen; /* Length of encryption        */
                                            /* library name                   */
  void                        *piEncrOptions; /* Vendor-specific options for  */
                                            /* encryption plug-in             */
  db2Uint32                   iEncrOptionsSize; /* Size of piEncrOptions      */
                                            /* block                          */
} db2gRestoreStruct;

/* Generic Restore API                                                        */
/******************************************************************************
** db2gRestore API
*******************************************************************************/
SQL_API_RC SQL_API_FN
  db2gRestore (
       db2Uint32 versionNumber,
       void * pDB2gRestoreStruct,
       struct sqlca * pSqlca);

/* Recover Definitions                                                        */

/* Values for db2Recover - iRecoverCallerAction                               */
#define DB2RECOVER                     3
#define DB2RECOVER_RESTART             4
#define DB2RECOVER_DEVICE_TERMINATE    9
#define DB2RECOVER_PARM_CHK_ONLY       10
#define DB2RECOVER_CONTINUE            11
#define DB2RECOVER_LOADREC_TERM        12
#define DB2RECOVER_DEVICE_TERM         13

/* Values for db2Recover - iOptions                                           */
#define DB2RECOVER_EMPTY_FLAG          0         /* No flags specified        */
#define DB2RECOVER_LOCAL_TIME          1         /* Interpret stop time as    */
                                                 /* local time                */
#define DB2RECOVER_GMT_TIME            2         /* Interpret stop time as    */
                                                 /* GMT time                  */
#define DB2RECOVER_NOENCRYPT           4         /* If recovering to new db,  */
                                                 /* forces the new db to      */
                                                 /* disable encryption        */

/* Recover Structure                                                          */
/******************************************************************************
** db2RecoverStruct data structure
** db2RecoverStruct data structure parameters
** 
** piSourceDBAlias
** Input. A string containing the database alias of the database to be
** recovered.
** 
** piUserName
** Input. A string containing the user name to be used when attempting a
** connection. Can be NULL.
** 
** piPassword
** Input. A string containing the password to be used with the user name. Can
** be NULL.
** 
** iRecoverCallerAction
** Input. Valid values are:
** - DB2RESTORE_NOINTERRUPT
** Starts the restore operation. Specifies that the restore will run unattended,
** and that scenarios that normally require user intervention will either be
** attempted without first returning to the caller, or will generate an error.
** Use this caller action, 7for example, if it is known that all of the media
** required for the restore have 7been mounted, and utility prompts are not
** desired.
** 
** - DB2RESTORE_CONTINUE
** Continues the restore operation after the user has performed some action
** requested by the utility (mounting a new tape, for example).
** 
** - DB2RESTORE_TERMINATE
** Terminates the restore operation after the user has failed to perform some
** action requested by the utility.
** 
** - DB2RESTORE_DEVICE_TERMINATE
** Removes a particular device from the list of devices used by the restore
** operation. When a particular device has exhausted its input, restore will
** return a warning to the caller. Call the restore utility again with this
** caller action to remove the device that generated the warning from the
** list of devices being used.
** 
** - DB2RESTORE_PARM_CHK
** Used to validate parameters without performing a restore operation. This
** option does not terminate the database connection after the call
** returns. After successful return of this call, it is expected that the
** user will issue a call with DB2RESTORE_CONTINUE to proceed with the
** action.
** 
** - DB2RESTORE_PARM_CHK_ONLY
** Used to validate parameters without performing a restore operation. Before
** this call returns, the database connection established by this call is
** terminated, and no subsequent call is required.
** 
** - DB2RESTORE_TERMINATE_INCRE
** Terminates an incremental restore operation before completion.
** 
** - DB2ROLLFORWARD_LOADREC_CONT
** Continue using the device that generated the warning message (for example,
** when a new tape has been mounted).
** 
** - DB2ROLLFORWARD_DEVICE_TERM
** Stop using the device that generated the warning message (for example, when
** there are no more tapes).
** 
** - DB2ROLLFORWARD_LOAD_REC_TERM
** Terminate all devices being used by load recovery.
** 
** iOptions
** Input. Valid values are:
** - DB2RECOVER_EMPTY_FLAG
** No flags specified.
** 
** - DB2RECOVER_LOCAL_TIME
** Indicates that the value specified for the stop time by piStopTime is in
** local time, not GMT. This is the default setting.
** 
** - DB2RECOVER_GMT_TIME
** This flag indicates that the value specified for the stop time by piStopTime
** is in GMT (Greenwich Mean Time).
** 
** - DB2RECOVER_NOENCRYPT
** When recovering to a new database, force the new database to disable
** encryption. This option is ignored when recovering an existing database,
** where the existing database's encryption settings are honoured.
** 
** poNumReplies
** Output. The number of replies received.
** 
** poNodeInfo
** Output. Database partition reply information.
** 
** piStopTime
** Input. A character string containing a time stamp in ISO format. Database
** recovery will stop when this time stamp is exceeded. Specify
** SQLUM_INFINITY_TIMESTAMP to roll forward as far as possible. May be NULL for
** DB2ROLLFORWARD_QUERY, DB2ROLLFORWARD_PARM_CHECK, and any of the load recovery
** (DB2ROLLFORWARD_LOADREC_) caller actions.
** 
** piOverflowLogPath
** Input. This parameter is used to specify an alternate log path to be used. In
** addition to the active log files, archived log files need to be moved (by the
** user) into the location specified by the logpath configuration parameter
** before they can be used by this utility. This can be a problem if the
** user does not have sufficient space in the log path. The overflow log
** path is provided for this reason. During roll-forward recovery, the required
** log files are searched, first in the log path, and then in the overflow log
** path. The log files needed for table space rollforward recovery can be
** brought into either the log path or the overflow log path. If the caller
** does not specify an overflow log path, the default value is the log path.
** In a partitioned database environment, the overflow log path must be a
** valid, fully qualified path; the default path is the default overflow
** log path for each database partition. In a single-partition database
** environment, the overflow log path can be relative if the server is
** local.
** 
** iNumChngLgOvrflw
** Input. Partitioned database environments only. The number of changed overflow
** log paths. These new log paths override the default overflow log path for
** the specified database partition server only.
** 
** piChngLogOvrflw
** Input. Partitioned database environments only. A pointer to a structure
** containing the fully qualified names of changed overflow log paths. These
** new log paths override the default overflow log path for the specified
** database partition server only.
** 
** iAllNodeFlag
** Input. Partitioned database environments only. Indicates whether the
** rollforward operation is to be applied to all database partition servers
** defined in db2nodes.cfg. Valid values are:
** - DB2_NODE_LIST
** Apply to database partition servers in a list that is passed in piNodeList.
** 
** - DB2_ALL_NODES
** Apply to all database partition servers. piNodeList should be NULL. This is
** the default value.
** 
** - DB2_ALL_EXCEPT
** Apply to all database partition servers except those in a list that is passed
** in piNodeList.
** 
** - DB2_CAT_NODE_ONLY
** Apply to the catalog partition only. piNodeList should be NULL.
** 
** iNumNodes
** Input. Specifies the number of database partition servers in the piNodeList
** array.
** 
** piNodeList
** Input. A pointer to an array of database partition server numbers on which to
** perform the rollforward recovery.
** 
** iNumNodeInfo
** Input. Defines the size of the output parameter poNodeInfo, which must be
** large enough to hold status information from each database partition that
** is being rolled forward. In a single-partition database environment, this
** parameter should be set to 1. The value of this parameter should be the
** same as the number of database partition servers for which this API is
** being called.
** 
** piHistoryFile
** History file.
** 
** iNumChngHistoryFile
** Number of history files in list.
** 
** piChngHistoryFile
** List of history files.
** 
** piComprLibrary
** Input. Indicates the name of the external library to be used to perform
** decompression of the backup image if the image is compressed. The name must
** be a fully-qualified path referring to a file on the server. If the value
** is a null pointer or a pointer to an empty string, DB2 will attempt to use
** the library stored in the image. If the backup was not compressed, the
** value of this parameter will be ignored. If the specified library is not
** found, the restore will fail. 
** 
** piComprOptions
** Input. Describes a block of binary data that will be passed to the
** initialization routine in the decompression library. DB2 will pass this
** string directly from the client to the server, so any issues of
** byte-reversal or code-page conversion will have to be handled by the
** compression library. If the first character of the data block is '@', the
** remainder of the data will be interpreted by DB2 as the name of a file
** residing on the server. DB2 will then replace the contents of
** piComprOptions and iComprOptionsSize with the contents and size of this
** file respectively and will pass these new values to the initialization
** routine instead.
** 
** iComprOptionsSize
** Input. Represents the size of the block of data passed as piComprOptions.
** iComprOptionsSize shall be zero if and only if piComprOptions is a null
** pointer.
** 
** piEncrLibrary
** Input. Indicates the name of the external library to be used to perform
** decryption of the backup image if the image is encrypted. The name must
** be a fully-qualified path referring to a file on the server. If the value
** is a null pointer or a pointer to an empty string, DB2 will attempt to use
** the library stored in the image. If the backup was not encrypted, the
** value of this parameter will be ignored. If the specified library is not
** found, the restore will fail. 
** 
** piEncrOptions
** Input. Describes a block of binary data that will be passed to the
** initialization routine in the decryption library. DB2 will pass this
** string directly from the client to the server, so any issues of
** byte-reversal or code-page conversion will have to be handled by the
** encryption library. If the first character of the data block is '@', the
** remainder of the data will be interpreted by DB2 as the name of a file
** residing on the server. DB2 will then replace the contents of
** piEncrOptions and iEncrOptionsSize with the contents and size of this
** file respectively and will pass these new values to the initialization
** routine instead.
** 
** iEncrOptionsSize
** Input. Represents the size of the block of data passed as piEncrOptions.
** iEncrOptionsSize shall be zero if and only if piEncrOptions is a null
** pointer.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RecoverStruct
{
  char                        *piSourceDBAlias;
  char                        *piUsername;
  char                        *piPassword;
  db2Uint32                   iRecoverCallerAction;
  db2Uint32                   iOptions;
  sqlint32                    *poNumReplies; /* number of replies received    */
  struct sqlurf_info          *poNodeInfo;  /* database partition reply info  */
  char                        *piStopTime;  /* Stop time                      */
  char                        *piOverflowLogPath; /* Overflow log path        */
  db2Uint32                   iNumChngLgOvrflw; /* Number of changed          */
                                            /* overflow log paths             */
  struct sqlurf_newlogpath    *piChngLogOvrflw; /* Changed overflow log       */
                                            /* paths                          */
  db2int32                    iAllNodeFlag; /* Flag indicating how            */
                                            /* piNodeList should be used      */
  db2int32                    iNumNodes;    /* Number of database partitions  */
                                            /* in piNodeList                  */
  SQL_PDB_NODE_TYPE           *piNodeList;  /* Database partitions list       */
  db2int32                    iNumNodeInfo; /* Size of piNodeInfo in          */
                                            /* db2RfwdOutput                  */
  char                        *piHistoryFile; /* History file                 */
  db2Uint32                   iNumChngHistoryFile; /* Number of history       */
                                            /* files in list                  */
  struct sqlu_histFile        *piChngHistoryFile; /* list of history files    */
  char                        *piComprLibrary; /* Name of compression         */
                                            /* library                        */
  void                        *piComprOptions; /* Vendor-specific options     */
                                            /* for compression plug-in        */
  db2Uint32                   iComprOptionsSize; /* Size of piComprOptions    */
                                            /* block                          */
  char                        *piEncrLibrary; /* Name of encryption library   */
  void                        *piEncrOptions; /* Vendor-specific options for  */
                                            /* encryption plug-in             */
  db2Uint32                   iEncrOptionsSize; /* Size of piEncrOptions      */
                                            /* block                          */
  struct sqleDbEncryptionOptions *piDbEncOpts; /* Database encryption         */
                                            /* options                        */
} db2RecoverStruct;

/******************************************************************************
** db2gRecoverStruct data structure
** db2gRecoverStruct data structure specific parameters
** 
** iSourceDBAliasLen
** Specifies the length in bytes of the piSourceDBAlias parameter.
** 
** iUserNameLen
** Specified the length in bytes of the piUsername parameter.
** 
** iPasswordLen
** Specifies the length in bytes of the piPassword parameter.
** 
** iStopTimeLen
** Specifies the length in bytes of the piStopTime parameter.
** 
** iOverflowLogPathLen
** Specifies the length in bytes of the piOverflowLogPath parameter.
** 
** iHistoryFileLen
** Specifies the length in bytes of the piHistoryFile parameter.
** 
** iComprLibraryLen
** Input. Specifies the length in bytes of the name of the library
** specified in the piComprLibrary parameter. Set to zero if no
** library name is given.
** 
** iEncrLibraryLen
** Input. Specifies the length in bytes of the name of the library
** specified in the piEncrLibrary parameter. Set to zero if no
** library name is given.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gRecoverStruct
{
  char                        *piSourceDBAlias;
  db2Uint32                   iSourceDBAliasLen; /* Length in bytes of        */
                                            /* piSourceDBAlias                */
  char                        *piUserName;
  db2Uint32                   iUserNameLen; /* Length in bytes of piUsername  */
  char                        *piPassword;
  db2Uint32                   iPasswordLen; /* Length in bytes of piPassword  */
  db2Uint32                   iRecoverCallerAction;
  db2Uint32                   iOptions;
  sqlint32                    *poNumReplies; /* number of replies received    */
  struct sqlurf_info          *poNodeInfo;  /* database partition reply info  */
  char                        *piStopTime;  /* Stop time                      */
  db2Uint32                   iStopTimeLen; /* Length in bytes of piStopTime  */
  char                        *piOverflowLogPath; /* Overflow log path        */
  db2Uint32                   iOverflowLogPathLen; /* Length in bytes of      */
                                            /* piOverflowLogPath              */
  db2Uint32                   iNumChngLgOvrflw; /* Number of changed          */
                                            /* overflow log paths             */
  struct sqlurf_newlogpath    *piChngLogOvrflw; /* Changed overflow log       */
                                            /* paths                          */
  db2int32                    iAllNodeFlag; /* Flag indicating how            */
                                            /* piNodeList should be used      */
  db2int32                    iNumNodes;    /* Number of database partitions  */
                                            /* in piNodeList                  */
  SQL_PDB_NODE_TYPE           *piNodeList;  /* database partitions list       */
  db2int32                    iNumNodeInfo; /* Size of piNodeInfo in          */
                                            /* db2RfwdOutput                  */
  char                        *piHistoryFile; /* History file                 */
  db2Uint32                   iHistoryFileLen; /* Length in bytes of          */
                                            /* piHistoryFile                  */
  db2Uint32                   iNumChngHistoryFile; /* Number of history       */
                                            /* files in list                  */
  struct sqlu_histFile        *piChngHistoryFile; /* list of history files    */
  char                        *piComprLibrary; /* Name of compression         */
                                            /* library                        */
  db2Uint32                   iComprLibraryLen; /* Length of compression      */
                                            /* library name                   */
  void                        *piComprOptions; /* Vendor-specific options     */
                                            /* for compression plug-in        */
  db2Uint32                   iComprOptionsSize; /* Size of piComprOptions    */
                                            /* block                          */
  char                        *piEncrLibrary; /* Name of encryption library   */
  db2Uint32                   iEncrLibraryLen; /* Length of encryption        */
                                            /* library name                   */
  void                        *piEncrOptions; /* Vendor-specific options for  */
                                            /* encryption plug-in             */
  db2Uint32                   iEncrOptionsSize; /* Size of piEncrOptions      */
                                            /* block                          */
} db2gRecoverStruct;

/* Recover API                                                                */
/******************************************************************************
** db2Recover API
** Restores and rolls forward a database to a particular point in time or
** to the end of the logs.
** 
** Scope
** 
** In a partitioned database environment, this API can only be called from
** the catalog partition. If no database partition servers are specified,
** it affects all database partition servers that are listed in the
** db2nodes.cfg file. If a point in time is specified, the API affects
** all database partitions.
** 
** Authorization
** 
** To recover an existing database, one of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** To recover to a new database, one of the following:
** - sysadm
** - sysctrl
** 
** Required connection
** 
** To recover an existing database, a database connection is required. This API
** automatically establishes a connection to the specified database and will
** release the connection when the recover operation finishes. Instance and
** database, to recover to a new database. The instance attachment is required
** to create the database.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Recover API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pDB2RecoverStruct.
** 
** pDB2RecoverStruct
** Input. A pointer to the db2RecoverStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN
  db2Recover (
       db2Uint32 versionNumber,
       void * pDB2RecovStruct,
       struct sqlca * pSqlca);

/******************************************************************************
** db2gRecover API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Recover                     */
  db2gRecover (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2gRecoverStruct,      /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Rollforward Definitions                                                    */

/* Values for db2Rollforward - CallerAction                                   */
#define DB2ROLLFORWARD_RFWD            1         /* Rollforward to requested  */
                                                 /* point                     */
#define DB2ROLLFORWARD_STOP            2         /* End rollforward recovery  */
#define DB2ROLLFORWARD_COMPLETE        2         /* End rollforward recovery  */
#define DB2ROLLFORWARD_RFWD_STOP       3         /* Rollforward  to           */
                                                 /* requested point and end   */
                                                 /* rollforward recovery      */
#define DB2ROLLFORWARD_RFWD_COMPLETE   3         /* Rollforward  to           */
                                                 /* requested point and end   */
                                                 /* rollforward recovery      */
#define DB2ROLLFORWARD_QUERY           4         /* Query nextarclog,         */
                                                 /* firstarcdel, lastarcdel,  */
                                                 /* lastcommit                */
#define DB2ROLLFORWARD_CANCEL          8         /* Cancel current            */
                                                 /* rollforward               */
#define DB2ROLLFORWARD_PARM_CHECK      10        /* Parameter check           */
#define DB2ROLLFORWARD_LOADREC_CONT    11        /* Continue load recovery    */
#define DB2ROLLFORWARD_LOADREC_TERM    12        /* Terminate load recovery   */
#define DB2ROLLFORWARD_DEVICE_TERM     13        /* Terminate device          */

/* Values for db2Rollforward - ConnectMode                                    */
#define DB2ROLLFORWARD_OFFLINE         0         /* Offline rollforward mode  */
#define DB2ROLLFORWARD_ONLINE          1         /* Online rollforward mode   */

/* Values for db2Rollforward - iRollforwardFlags                              */
#define DB2ROLLFORWARD_EMPTY_FLAG      0         /* No flags specified        */
#define DB2ROLLFORWARD_LOCAL_TIME      1         /* Interpret stop time as    */
                                                 /* local time, not UTC       */
#define DB2ROLLFORWARD_NO_RETRIEVE     2         /* Do not attempt to         */
                                                 /* retrieve log files via    */
                                                 /* userexit                  */
#define DB2ROLLFORWARD_END_OF_BACKUP   4         /* Rollforward to the end    */
                                                 /* of the most recently      */
                                                 /* restored backup image     */

/* Values for db2Rollforward - oRollforwardFlags                              */
#define DB2ROLLFORWARD_OUT_LOCAL_TIME  0x1       /* Indicates stop time is    */
                                                 /* returned as server's      */
                                                 /* local time, not UTC       */

/* Length of arrays used by db2Rollforward                                    */
#define DB2_ISO_TIMESTAMP_LEN          26        /* Length of ISO format      */
                                                 /* timestamp                 */
#define DB2_LOGFILE_NAME_LEN           12        /* Length of logfile name    */
#define DB2_LOGPATH_LEN                242       /* Maximum length of a       */
                                                 /* logfile path              */

/* Rollforward Input Structure                                                */
/******************************************************************************
** db2RfwdInputStruct data structure
** db2RfwdInputStruct data structure parameters
** 
** iVersion
** Input. The version ID of the rollforward parameters. It is defined as
** SQLUM_RFWD_VERSION.
** 
** piDbAlias 
** Input. A string containing the database alias. This is the alias that is
** cataloged in the system database directory. 
** 
** iCallerAction
** Input. Specifies action to be taken. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** 
** - DB2ROLLFORWARD_ROLLFWD
** Rollforward to the point in time specified by the piStopTime parameter.
** For database rollforward, the database is left in
** rollforward-pending state. For table space rollforward to a
** point in time, the table spaces are left in
** rollforward-in-progress state.
** 
** - DB2ROLLFORWARD_STOP 
** End roll-forward recovery by rolling forward the database using available
** log files and then rolling it back. Uncommitted transactions are backed
** out and the rollforward-pending state of the database or table spaces is
** turned off. A synonym for this value is DB2ROLLFORWARD_RFWD_COMPLETE.
** 
** - DB2ROLLFORWARD_RFWD_STOP 
** Rollforward to the point in time specified by piStopTime, and end
** roll-forward recovery. The rollforward-pending state of the database or
** table spaces is turned off. A synonym for this value is
** DB2ROLLFORWARD_RFWD_COMPLETE.
** 
** - DB2ROLLFORWARD_QUERY
** Query values for nextarclog, firstarcdel, lastarcdel, and lastcommit. Return
** database status and a database partition number. 
** 
** - DB2ROLLFORWARD_PARM_CHECK 
** Validate parameters without performing the roll forward. 
** 
** - DB2ROLLFORWARD_CANCEL 
** Cancel the rollforward operation that is currently running. The database or
** table space are put in recovery pending state. 
** Note:
** This option cannot be used while the rollforward is actually running. It can
** be used if the rollforward is paused (that is, waiting for a STOP), or if a
** system failure occurred during the rollforward. It should be used with
** caution. Rolling databases forward may require a load recovery using
** tape devices. The rollforward API will return with a warning message
** if user intervention on a device is required. The API can be called
** again with one of the following three caller actions: 
** 
** - DB2ROLLFORWARD_LOADREC_CONT 
** Continue using the device that generated the warning message (for example,
** when a new tape has been mounted). 
** 
** - DB2ROLLFORWARD_DEVICE_TERM 
** Stop using the device that generated the warning message (for example, when
** there are no more tapes). 
** 
** - DB2ROLLFORWARD_LOAD_REC_TERM 
** Terminate all devices being used by load recovery. 
** 
** piStopTime 
** Input. A character string containing a time stamp in ISO format. Database
** recovery will stop when this time stamp is exceeded. Specify
** SQLUM_INFINITY_TIMESTAMP to roll forward as far as possible. May be NULL for
** DB2ROLLFORWARD_QUERY, DB2ROLLFORWARD_PARM_CHECK, and any of the load recovery
** (DB2ROLLFORWARD_LOADREC_xxx) caller actions. 
** 
** piUserName 
** Input. A string containing the user name of the application. Can be NULL. 
** 
** piPassword 
** Input. A string containing the password of the supplied user name (if
** any). Can be NULL.
** 
** piOverflowLogPath 
** Input. This parameter is used to specify an alternate log path to be used. In
** addition to the active log files, archived log files need to be moved (by the
** user) into the logpath before they can be used by this utility. This can
** be a problem if the database does not have sufficient space in the logpath.
** The overflow log path is provided for this reason. During roll-forward
** recovery, the required log files are searched, first in the logpath, and
** then in the overflow log path. The log files needed for table space
** roll-forward recovery can be brought into either the logpath or the
** overflow log path. If the caller does not specify an overflow log path,
** the default value is the logpath. In a partitioned database environment,
** the overflow log path must be a valid, fully qualified path; the default
** path is the default overflow log path for each database partition. In a
** single-partition database environment, the overflow log path can be relative
** if the server  is local. 
** 
** iNumChngLgOvrflw 
** Input. Partitioned database environments only. The number of changed overflow
** log paths. These new log paths override the default overflow log path for
** the specified database partition server only. 
** 
** piChngLogOvrflw 
** Input. Partitioned database environments only. A pointer to a
** structure containing the fully qualified names of changed overflow log
** paths. These new log paths override the default overflow log path for
** the specified database partition server only. 
** 
** iConnectMode 
** Input. Valid values (defined in db2ApiDf header file, located in the include
** directory) are: 
** - DB2ROLLFORWARD_OFFLINE 
** Offline roll forward. This value must be specified for database roll-forward
** recovery. 
** - DB2ROLLFORWARD_ONLINE 
** Online roll forward. 
** 
** piTablespaceList 
** Input. A pointer to a structure containing the names of the table
** spaces to be rolled forward to the end-of-logs or to a specific point
** in time. If not specified, the table spaces needing rollforward will
** be selected. 
** 
** iAllNodeFlag 
** Input. Partitioned database environments only. Indicates whether the
** rollforward operation is to be applied to all database partition servers
** defined in db2nodes.cfg. Valid values are: 
** - DB2_NODE_LIST 
** Apply to database partition servers in a list that is passed in piNodeList.
** - DB2_ALL_NODES 
** Apply to all database partition servers. This is the default value.
** The piNodeList parameter must be set to NULL, if this value is used.
** - DB2_ALL_EXCEPT 
** Apply to all database partition servers except those in a list that is passed
** in piNodeList. 
** - DB2_CAT_NODE_ONLY 
** Apply to the catalog partition only. The piNodeList parameter must be set
** to NULL, if this value is used. 
** 
** iNumNodes 
** Input. Specifies the number of database partition servers in the piNodeList
** array. 
** 
** piNodeList 
** Input. A pointer to an array of database partition server numbers on which to
** perform the roll-forward recovery. 
** 
** iNumNodeInfo 
** Input. Defines the size of the output parameter poNodeInfo, which must
** be large enough to hold status information from each database partition
** that is being rolled forward. In a single-partition database environment,
** this parameter should be set to 1. The value of this parameter should
** be the same as the number of database partition servers for which this API
** is being called. 
** 
** piDroppedTblID 
** Input. A string containing the ID of the dropped table whose recovery is
** being attempted. 
** 
** piExportDir 
** Input. The name of the directory into which the dropped table data will
** be exported. 
** 
** iRollforwardFlags 
** Input. Specifies the rollforward flags. Valid values (defined in
** db2ApiDf header file, located in the include directory) are: 
** - DB2ROLLFORWARD_EMPTY_FLAG
** No flags specified.
** - DB2ROLLFORWARD_LOCAL_TIME 
** Allows the user to rollforward to a point in time that is the server's
** local time rather than UTC time. 
** - DB2ROLLFORWARD_NO_RETRIEVE 
** Controls which log files to be rolled forward on the standby machine by
** allowing the user to disable the retrieval of archived logs. By controlling
** the log files to be rolled forward, one can ensure that the standby machine
** is X hours behind the production machine, to prevent the user affecting both
** systems. This option is useful if the standby system does not have access to
** archive, for example, if TSM is the archive, it only allows the original
** machine to retrieve the files. It will also remove the possibility that the
** standby system would retrieve an incomplete log file while the production
** system is archiving a file and the standby system is retrieving the same
** file.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RfwdInputStruct
{
  sqluint32                   iVersion;     /* Rollforward version            */
  char                        *piDbAlias;   /* Database alias                 */
  db2Uint32                   iCallerAction; /* Rollforward action            */
  char                        *piStopTime;  /* Stop time                      */
  char                        *piUserName;  /* User name to execute under     */
  char                        *piPassword;  /* Password                       */
  char                        *piOverflowLogPath; /* Overflow log path        */
  db2Uint32                   iNumChngLgOvrflw; /* Number of changed          */
                                            /* overflow log paths             */
  struct sqlurf_newlogpath    *piChngLogOvrflw; /* Changed overflow log       */
                                            /* paths                          */
  db2Uint32                   iConnectMode; /* Connect mode                   */
  struct sqlu_tablespace_bkrst_list *piTablespaceList; /* List of             */
                                            /* tablespaces to rollforward     */
  db2int32                    iAllNodeFlag; /* Flag indicating how            */
                                            /* piNodeList should be used      */
  db2int32                    iNumNodes;    /* Number of database partitions  */
                                            /* in piNodeList                  */
  SQL_PDB_NODE_TYPE           *piNodeList;  /* database partition list        */
  db2int32                    iNumNodeInfo; /* Size of piNodeInfo in          */
                                            /* db2RfwdOutput                  */
  char                        *piDroppedTblID; /* Dropped table id            */
  char                        *piExportDir; /* Dropped table export           */
                                            /* directory                      */
  db2Uint32                   iRollforwardFlags; /* Rollforward flags         */
} db2RfwdInputStruct;

/* Generic Rollforward Input Structure                                        */
/******************************************************************************
** db2gRfwdInputStruct data structure
** db2gRfwdInputStruct data structure specific parameters
** 
** iDbAliasLen
** Input. Specifies the length in bytes of the database alias.
** 
** iStopTimeLen 
** Input. Specifies the length in bytes of the stop time parameter. Set to zero
** if no stop time is provided. 
** 
** iUserNameLen 
** Input. Specifies the length in bytes of the user name. Set to zero if no
** user name is provided. 
** 
** iPasswordLen 
** Input. Specifies the length in bytes of the password. Set to zero if no
** password is provided. 
** 
** iOverflowLogPathLen 
** Input. Specifies the length in bytes of the overflow log path. Set to zero
** if no overflow log path is provided. 
** 
** iDroppedTblIDLen
** Input. Specifies the length in bytes of the dropped table ID (piDroppedTblID
** parameter). Set to zero if no dropped table ID is provided.
** 
** iExportDirLen
** Input. Specifies the length in bytes of the dropped table export
** directory (piExportDir parameter). Set to zero if no dropped table export
** directory is provided.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gRfwdInputStruct
{
  db2Uint32                   iDbAliasLen;  /* Length in bytes of piDbAlias   */
  db2Uint32                   iStopTimeLen; /* Length in bytes of piStopTime  */
  db2Uint32                   iUserNameLen; /* Length in bytes of piUserName  */
  db2Uint32                   iPasswordLen; /* Length in bytes of piPassword  */
  db2Uint32                   iOvrflwLogPathLen; /* Length in bytes of        */
                                            /* piOverflowLogPath              */
  db2Uint32                   iDroppedTblIDLen; /* Length in bytes of         */
                                            /* piDroppedTblID                 */
  db2Uint32                   iExportDirLen; /* Length in bytes of            */
                                            /* piExportDir                    */
  sqluint32                   iVersion;     /* Rollforward version            */
  char                        *piDbAlias;   /* Database alias                 */
  db2Uint32                   iCallerAction; /* Rollforward action            */
  char                        *piStopTime;  /* Stop time                      */
  char                        *piUserName;  /* User name to execute under     */
  char                        *piPassword;  /* Password                       */
  char                        *piOverflowLogPath; /* Overflow log path        */
  db2Uint32                   iNumChngLgOvrflw; /* Number of changed          */
                                            /* overflow log paths             */
  struct sqlurf_newlogpath    *piChngLogOvrflw; /* Changed overflow log       */
                                            /* paths                          */
  db2Uint32                   iConnectMode; /* Connect mode                   */
  struct sqlu_tablespace_bkrst_list *piTablespaceList; /* List of             */
                                            /* tablespaces to rollforward     */
  db2int32                    iAllNodeFlag; /* Flag indicating how piNodeist  */
                                            /* should be used                 */
  db2int32                    iNumNodes;    /* Number of database partitions  */
                                            /* in piNodeList                  */
  SQL_PDB_NODE_TYPE           *piNodeList;  /* Database partitions list       */
  db2int32                    iNumNodeInfo; /* Size of piNodeInfo in          */
                                            /* db2RfwdOutput                  */
  char                        *piDroppedTblID; /* Dropped table id            */
  char                        *piExportDir; /* Dropped table export           */
                                            /* directory                      */
  db2Uint32                   iRollforwardFlags; /* Rollforward input flags   */
} db2gRfwdInputStruct;

/* Rollforward Output Structure                                               */
/******************************************************************************
** db2RfwdOutputStruct data structure
** db2RfwdOutputStruct data structure parameters
** 
** poApplicationId
** Output. The application ID. 
** 
** poNumReplies 
** Output. The number of replies received. 
** 
** poNodeInfo 
** Output. Database partition reply information.
** 
** oRollforwardFlags 
** Output. Rollforward output flags. Valid values (defined in 
** db2ApiDf header file, located in the include directory) are: 
** - DB2ROLLFORWARD_OUT_LOCAL_TIMEIndicates to caller that the last committed transaction timestamp is 
** returned in local time rather than UTC.  Local time is based on the 
** server's local time, not on the client's.  In a partitioned database 
** environment, local time is based on the catalog partition's local time.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RfwdOutputStruct
{
  char                        *poApplicationId; /* application id             */
  sqlint32                    *poNumReplies; /* number of replies received    */
  struct sqlurf_info          *poNodeInfo;  /* database partition reply info  */
  db2Uint32                   oRollforwardFlags; /* Rollforward output flags  */
} db2RfwdOutputStruct;

/* Rollforward API Input Structure                                            */
/******************************************************************************
** db2RollforwardStruct data structure
** db2RollforwardStruct data structure parameters
** 
** piRfwdInput
** Input. A pointer to the db2RfwdInputStruct structure. 
** 
** poRfwdOutput 
** Output. A pointer to the db2RfwdOutputStruct structure. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RollforwardStruct
{
  struct db2RfwdInputStruct   *piRfwdInput; /* rollforward input structure    */
  struct db2RfwdOutputStruct  *poRfwdOutput; /* rollforward output structure  */
} db2RollforwardStruct;

/* Generic Rollforward API Structure                                          */
/******************************************************************************
** db2gRollforwardStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gRollforwardStruct
{
  struct db2gRfwdInputStruct  *piRfwdInput; /* generic rollforward input      */
                                            /* structure                      */
  struct db2RfwdOutputStruct  *poRfwdOutput; /* rollforward output structure  */
} db2gRollforwardStruct;

/******************************************************************************
** db2Rollforward API
** Recovers a database by applying transactions recorded in the database
** log files. Called after a database or a table space backup has been
** restored, or if any table spaces have been taken offline by the
** database due to a media error. The database must be recoverable
** (that is, the logarchmeth1 database configuration parameter must be
** set to on) before the database can be recovered with rollforward 
** recovery.
** 
** Scope
** 
** In a partitioned database environment, this API can only be called
** from the catalog partition. A database or table space rollforward
** call specifying a point-in-time affects all database partition
** servers that are listed in the db2nodes.cfg file. A database or
** table space rollforward call specifying end of logs affects the
** database partition servers that are specified. If no database
** partition servers are specified, it affects all database partition
** servers that are listed in the db2nodes.cfg file; if no roll
** forward is needed on a particular database partition server, that
** database partition server is ignored.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** None. This API establishes a database connection.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Rollforward API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter.
** 
** pDB2RollforwardStruct
** Input. A pointer to the db2RollforwardStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The database manager uses the information stored in the archived and
** the active log files to reconstruct the transactions performed on the
** database since its last backup.
** 
** The action performed when this API is called depends on the
** rollforward_pending flag of the database prior to the call. This can
** be queried using db2CfgGet - Get Configuration Parameters. The
** rollforward_pending flag is set to DATABASE if the database is
** in roll-forward pending state. It is set to TABLESPACE if one or
** more table spaces are in SQLB_ROLLFORWARD_PENDING or
** SQLB_ROLLFORWARD_IN_PROGRESS state. The rollforward_pending flag
** is set to NO if neither the database nor any of the table spaces
** needs to be rolled forward.
** 
** If the database is in roll-forward pending state when this API is called, the
** database will be rolled forward. Table spaces are returned to normal state
** after a successful database roll-forward, unless an abnormal state causes
** one or more table spaces to go offline. If the rollforward_pending flag
** is set to TABLESPACE, only those table spaces that are in roll-forward
** pending state, or those table spaces requested by name, will be rolled
** forward.
** 
** Note:
** If table space rollforward terminates abnormally, table spaces that
** were being rolled forward will be put in SQLB_ROLLFORWARD_IN_PROGRESS
** state. In the next invocation of ROLLFORWARD DATABASE, only those
** table spaces in SQLB_ROLLFORWARD_IN_PROGRESS state will be processed.
** If the set of selected table space names does not include all table
** spaces that are in SQLB_ROLLFORWARD_IN_PROGRESS state, the table
** spaces that are not required will be put into SQLB_RESTORE_PENDING state.
** 
** If the database is not in roll-forward pending state and no point in
** time is specified, any table spaces that are in rollforward-in-progress
** state will be rolled forward to the end of logs. If no table spaces
** are in rollforward-in-progress state, any table spaces that are in
** rollforward pending state will be rolled forward to the end of logs.
** 
** This API reads the log files, beginning with the log file that is
** matched with the backup image. The name of this log file can be
** determined by calling this API with a caller action of
** DB2ROLLFORWARD_QUERY before rolling forward any log files.
** 
** The transactions contained in the log files are reapplied to the
** database. The log is processed as far forward in time as information
** is available, or until the time specified by the stop time parameter.
** 
** Recovery stops when any one of the following events occurs:
** - No more log files are found
** - A time stamp in the log file exceeds the completion time stamp specified
** by the stop time parameter
** - An error occurs while reading the log file.
** 
** Some transactions might not be recovered. The value returned in lascommit
** indicates the time stamp of the last committed transaction that was
** applied to the database.
** 
** If the need for database recovery was caused by application or human
** error, the user may want to provide a time stamp value in piStopTime,
** indicating that recovery should be stopped before the time of the
** error. This applies only to full database roll-forward recovery,
** and to table space rollforward to a point in time. It also
** permits recovery to be stopped before a log read error occurs,
** determined during an earlier failed attempt to recover.
** 
** When the rollforward_recovery flag is set to DATABASE, the database
** is not available for use until roll-forward recovery is terminated.
** Termination is accomplished by calling the API with a caller action
** of DB2ROLLFORWARD_STOP or DB2ROLLFORWARD_RFWRD_STOP to bring the
** database out of roll-forward pending state. If the
** rollforward_recovery flag is TABLESPACE, the database is available
** for use. However, the table spaces in SQLB_ROLLFORWARD_PENDING and
** SQLB_ROLLFORWARD_IN_PROGRESS states will not be available until
** the API is called to perform table space roll-forward recovery.
** If rolling forward table spaces to a point in time, the table
** spaces are placed in backup pending state after a successful
** rollforward.
** 
** When the iRollforwardFlags input option is set to DB2ROLLFORWARD_LOCAL_TIME,
** all messages returned to the caller will also be in local time.  This will be
** indicated by the DB2ROLLFORWARD_OUT_LOCAL_TIME flag in the oRollforwardFlags
** output field. All times are converted on the server, and on the catalog
** partition, if it is a partitioned database environment. The timestamp
** string is converted to UTC on the server, so the time is local to the
** server's time zone, not the client's. If the client is in one time
** zone and the server in another, the server's local time should be
** used. This is different from the local time option from the Control
** Center, which is local to the client. If the timestamp string is
** close to the time change of the clock due to daylight savings, it is
** important to know if the stop time is before or after the clock change,
** and specify it correctly.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Rollforward                         */
  db2Rollforward (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2RollforwardStruct,   /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/******************************************************************************
** db2gRollforward API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Rollforward                 */
  db2gRollforward (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2gRollforwardStruct,  /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* High Availability Disaster Recovery (HADR) Definitions                     */

/* Values for iByForce                                                        */
#define DB2HADR_NO_FORCE               0         /* Do not perform START or   */
                                                 /* TAKEOVER HADR operation   */
                                                 /* by force                  */
#define DB2HADR_FORCE                  1         /* Do perform START or       */
                                                 /* TAKEOVER HADR operation   */
                                                 /* by force                  */
#define DB2HADR_FORCE_PEERWINDOW       2         /* Perform TAKEOVER HADR BY  */
                                                 /* FORCE PEER WINDOW ONLY    */

/* Values for iDbRole                                                         */
#define DB2HADR_DB_ROLE_PRIMARY        1         /* An HADR Primary database  */
#define DB2HADR_DB_ROLE_STANDBY        2         /* An HADR Standby database  */

/* High Availability Disaster Recovery (HADR) API Definitions                 */

/* Start HADR API Input Structure                                             */
/******************************************************************************
** db2HADRStartStruct data structure
** db2HADRStartStruct data structure parameters
** 
** piDbAlias
** Input. A pointer to the database alias.
** 
** piUserName
** Input. A pointer to the user name under which the command will be
** executed.
** 
** piPassword
** Input. A pointer to a string containing the password.
** 
** iDbRole
** Input. Specifies which HADR database role should be started on the
** specified database. Valid values are:
** - DB2HADR_DB_ROLE_PRIMARY
** Start HADR operations on the database in the primary role.
** - DB2HADR_DB_ROLE_STANDBY
** Start HADR operations on the database in the standby role.
** 
** iByForce
** Input. This argument is ignored if the iDbRole parameter is set to
** DB2HADR_DB_ROLE_STANDBY. Valid values are:
** - DB2HADR_NO_FORCE
** Specifies that HADR is started on the primary database only if a
** standby database connects to it within a prescribed time limit.
** - DB2HADR_FORCE
** Specifies that HADR is to be started by force, without waiting for
** the standby database to connect to the primary database.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HADRStartStruct
{
   char                                *piDbAlias; /* Database alias          */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   char                                *piPassword; /* Password for username  */
   db2Uint32                           iDbRole;  /* Primary db or standby     */
   db2Uint16                           iByForce; /* Start HADR by force       */
} db2HADRStartStruct;

/******************************************************************************
** db2HADRStart API
** Starts HADR operations on a database.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** Instance. The API establishes a database connection if one does not
** exist, and closes the database connection when the API completes.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HADRStart API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2HADRStartStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Start HADR                          */
  db2HADRStart (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Start HADR API Input Struct                                        */
/******************************************************************************
** db2gHADRStartStruct data structure
** db2gHADRStartStruct data structure specific parameters
** 
** iAliasLen
** Input. Specifies the length in bytes of the database alias.
** 
** iUserNameLen
** Input. Specifies the length in bytes of the user name.
** 
** iPasswordLen
** Input. Specifies the length in bytes of the password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gHADRStartStruct
{
   char                                *piDbAlias; /* Database alias          */
   db2Uint32                           iAliasLen; /* Length of database       */
                                                 /* alias string              */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   db2Uint32                           iUserNameLen; /* Length of username    */
                                                 /* field                     */
   char                                *piPassword; /* Password for username  */
   db2Uint32                           iPasswordLen; /* Length of password    */
                                                 /* field                     */
   db2Uint32                           iDbRole;  /* Primary db or standby     */
   db2Uint16                           iByForce; /* Start HADR by force       */
} db2gHADRStartStruct;

/******************************************************************************
** db2gHADRStart API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Start HADR                  */
  db2gHADRStart (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */


/* Stop HADR API Input Structure                                              */
/******************************************************************************
** db2HADRStopStruct data structure
** db2HADRStopStruct data structure parameters
** 
** piDbAlias
** Input. A pointer to the database alias.
** 
** piUserName
** Input. A pointer to the user name under which the command will be
** executed.
** 
** piPassword
** Input. A pointer to a string containing the password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HADRStopStruct
{
   char                                *piDbAlias; /* Database alias          */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   char                                *piPassword; /* Password for username  */
} db2HADRStopStruct;

/******************************************************************************
** db2HADRStop API
** Stops HADR operations on a database.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** Instance. The API establishes a database connection if one does not
** exist, and closes the database connection when the API completes.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HADRStop API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2HADRStopStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Stop HADR                           */
  db2HADRStop (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Stop HADR API Input Struct                                         */
/******************************************************************************
** db2gHADRStopStruct data structure
** db2gHADRStopStruct data structure specific parameters
** 
** iAliasLen
** Input. Specifies the length in bytes of the database alias.
** 
** iUserNameLen
** Input. Specifies the length in bytes of the user name.
** 
** iPasswordLen
** Input. Specifies the length in bytes of the password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gHADRStopStruct
{
   char                                *piDbAlias; /* Database alias          */
   db2Uint32                           iAliasLen; /* Length of database       */
                                                 /* alias string              */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   db2Uint32                           iUserNameLen; /* Length of username    */
                                                 /* field                     */
   char                                *piPassword; /* Password for username  */
   db2Uint32                           iPasswordLen; /* Length of password    */
                                                 /* field                     */
} db2gHADRStopStruct;

/******************************************************************************
** db2gHADRStop API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Stop HADR                   */
  db2gHADRStop (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */


/* Takeover HADR API Input Structure                                          */
/******************************************************************************
** db2HADRTakeoverStruct data structure
** db2HADRTakeoverStruct data structure parameters
** 
** piDbAlias
** Input. A pointer to the database alias.
** 
** piUserName
** Input. A pointer to the user name under which the command will be
** executed.
** 
** piPassword
** Input. A pointer to a string containing the password.
** 
** iByForce
** Input. Valid values are:
** - DB2HADR_NO_FORCE
** Specifies that a takeover occurs only if the two systems are in
** peer state with communication established; this results in a role
** reversal between the HADR primary and HADR standby
** databases.
** - DB2HADR_FORCE
** Specifies that the standby database takes over as the primary
** database without waiting for confirmation that the original
** primary database has been shut down. Forced takeover must be
** issued when the standby database is in either remote catchup
** pending or peer state.
** - DB2HADR_FORCE_PEERWINDOW
** Specifies that the standby database takes over as the primary
** database by force only if the peer window on standby has not 
** expired
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HADRTakeoverStruct
{
   char                                *piDbAlias; /* Database alias          */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   char                                *piPassword; /* Password for username  */
   db2Uint16                           iByForce; /* Takeover HADR by force    */
} db2HADRTakeoverStruct;

/******************************************************************************
** db2HADRTakeover API
** Instructs a standby database to take over as the primary database.
** This API can be called against a standby database only.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** Instance. The API establishes a database connection if one does not
** exist, and closes the database connection when the API completes.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2HADRTakeover API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2HADRTakeoverStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Takeover HADR                       */
  db2HADRTakeover (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Takeover HADR API Input Struct                                     */
/******************************************************************************
** db2gHADRTakeoverStruct data structure
** db2gHADRTakeoverStruct data structure specific parameters
** 
** iAliasLen
** Input. Specifies the length in bytes of the database alias.
** 
** iUserNameLen
** Input. Specifies the length in bytes of the user name.
** 
** iPasswordLen
** Input. Specifies the length in bytes of the password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gHADRTakeoverStruct
{
   char                                *piDbAlias; /* Database alias          */
   db2Uint32                           iAliasLen; /* Length of database       */
                                                 /* alias string              */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   db2Uint32                           iUserNameLen; /* Length of username    */
                                                 /* field                     */
   char                                *piPassword; /* Password for username  */
   db2Uint32                           iPasswordLen; /* Length of password    */
                                                 /* field                     */
   db2Uint16                           iByForce; /* Takeover HADR by force    */
} db2gHADRTakeoverStruct;

/******************************************************************************
** db2gHADRTakeover API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Takeover HADR               */
  db2gHADRTakeover (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Archive Active Log Definitions                                             */

/* Values for db2ArchiveLog - iAllNodeFlag                                    */
#define DB2ARCHIVELOG_NODE_LIST        DB2_NODE_LIST
#define DB2ARCHIVELOG_ALL_NODES        DB2_ALL_NODES
#define DB2ARCHIVELOG_ALL_EXCEPT       DB2_ALL_EXCEPT

/* Archive Active Log API Input Structure                                     */
/******************************************************************************
** db2ArchiveLogStruct data structure
** db2ArchiveLogStruct data structure parameters
** 
** piDatabaseAlias
** Input. A string containing the database alias (as cataloged in the system
** database directory) of the database for which the active log is to be
** archived.
** 
** piUserName
** Input. A string containing the user name to be used when attempting a
** connection.
** 
** piPassword
** Input. A string containing the password to be used when attempting a
** connection.
** 
** iAllNodeFlag
** Applicable to partitioned database environment only. Input. Flag
** indicating whether the operation should apply to all database partitions
** listed in the db2nodes.cfg file.
** Valid values are:
** - DB2ARCHIVELOG_NODE_LIST
** Apply to database partitions in a database partition list that is passed 
** in piNodeList.
** - DB2ARCHIVELOG_ALL_NODES
** Apply to all database partitionss. piNodeList should be NULL. This is the
** default value.
** - DB2ARCHIVELOG_ALL_EXCEPT
** Apply to all database partitionss except those in the database partition
** list passed in piNodeList.
** 
** iNumNodes
** Partitioned database environment only. Input. Specifies the number of
** database partitions in the piNodeList array.
** 
** piNodeList
** Partitioned database environment only. Input. A pointer to an array of 
** database partition numbers against which to apply the archive log operation.
** 
** iOptions
** Input. Reserved for future use.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ArchiveLogStruct
{
   char                                *piDatabaseAlias; /* Alias of          */
                                                 /* database to archive log   */
                                                 /* for                       */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   char                                *piPassword; /* Password for username  */
   db2Uint16                           iAllNodeFlag; /* Flag indicating how   */
                                                 /* the iNodeList should be   */
                                                 /* used                      */
   db2Uint16                           iNumNodes; /* Number of database       */
                                                 /* partitions in piNodeList  */
                                                 /* array                     */
   SQL_PDB_NODE_TYPE                   *piNodeList; /* database partitions    */
                                                 /* list                      */
   db2Uint32                           iOptions; /* Future use                */
} db2ArchiveLogStruct;

/******************************************************************************
** db2ArchiveLog API
** Closes and truncates the active log file for a recoverable database. If
** user exit is enabled, it also issues an archive request.
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
** This API automatically establishes a connection to the specified
** database. If a connection to the specified database already exists,
** the API will return an error.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2ArchiveLog API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the variable passed
** in as the second parameter, pDB2ArchiveLogStruct.
** 
** pDB2ArchiveLogStruct
** Input. A pointer to the db2ArchiveLogStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Archive Active Log                  */
  db2ArchiveLog (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2ArchiveLogStruct,    /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Archive Active Log API Input Struct                                */
/******************************************************************************
** db2gArchiveLogStruct data structure
** db2gArchiveLogStruct data structure specific parameters
** 
** iAliasLen
** Input. A 4-byte unsigned integer representing the length in bytes of the
** database alias.
** 
** iUserNameLen
** Input. A 4-byte unsigned integer representing the length in bytes of the user
** name. Set to zero if no user name is used.
** 
** iPasswordLen
** Input. A 4-byte unsigned integer representing the length in bytes of the
** password. Set to zero if no password is used.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gArchiveLogStruct
{
   db2Uint32                           iAliasLen; /* Length of database       */
                                                 /* alias field               */
   db2Uint32                           iUserNameLen; /* Length of username    */
                                                 /* field                     */
   db2Uint32                           iPasswordLen; /* Length of password    */
                                                 /* field                     */
   char                                *piDatabaseAlias; /* Alias of          */
                                                 /* database to archive log   */
                                                 /* for                       */
   char                                *piUserName; /* User name to execute   */
                                                 /* command under             */
   char                                *piPassword; /* Password for username  */
   db2Uint16                           iAllNodeFlag; /* Flag indicating how   */
                                                 /* the iNodeList should be   */
                                                 /* used                      */
   db2Uint16                           iNumNodes; /* Number of database       */
                                                 /* partitions in piNodeList  */
                                                 /* array                     */
   SQL_PDB_NODE_TYPE                   *piNodeList; /* database partitions    */
                                                 /* list                      */
   db2Uint32                           iOptions; /* Future use                */
} db2gArchiveLogStruct;

/******************************************************************************
** db2gArchiveLog API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Archive Active Log          */
  db2gArchiveLog (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2ArchiveLogStruct,    /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Asynchronous Read Log Definitions                                          */

/* Values for db2ReadLog - iCallerAction                                      */
#define DB2READLOG_READ                1         /* Read the database log     */
#define DB2READLOG_READ_SINGLE         2         /* Read a single log record  */
#define DB2READLOG_QUERY               3         /* Query the database log    */
#define DB2READLOG_READ_FROM_SPOOL     4         /* Read the database log     */
                                                 /* from the spooler          */
#define DB2READLOG_QUERY_FROM_SPOOL    5         /* Query the database log    */
                                                 /* from the spooler          */

/* Values for db2ReadLog - iFilterOption                                      */
#define DB2READLOG_FILTER_OFF          0         /* Read all log records      */
#define DB2READLOG_FILTER_ON           1         /* Read only propagatable    */
                                                 /* records                   */

/* Asynchronous Read Log API Info Output Structure                            */
/******************************************************************************
** db2TimeOfLog data structure
** db2TimeOfLog data structure parameters
** 
** seconds
** The number of seconds since Januray 1, 1970.
** 
** accuracy
** A high accuracy counter which allows callers to distinguish the order of
** events when comparing timestamps that occurred within the same second.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2TimeOfLog
{
   db2Uint32                           seconds;  /* Timestamp in seconds      */
   db2Uint32                           accuracy; /* High accuracy timestamp   */
} db2TimeOfLog;

/******************************************************************************
** db2ReadLogInfoStruct data structure
** db2ReadLogInfoStruct data structure parameters
** 
** initialLRI
** The first LRI used, or that will be used, by the database since it was
** activated.
** 
** firstReadLRI
** The first LRI present in poLogBuffer parameter.
** 
** nextStartLRI
** The start of the next log record the caller should read. Because some log
** records can be filtered and not returned in poLogBuffer parameter, using
** this LRI as the start of the next read instead of the end of the last
** log record in poLogBuffer parameter will prevent rescanning log records
** which have already been filtered.
** 
** firstReusedLRI
** The first LRI to be reused due to a database restore or rollforward
** operation.
** 
** logRecsWritten
** The number of log records written to poLogBuffer parameter.
** 
** logBytesWritten
** The total number of bytes of data written to poLogBuffer parameter.
** 
** timeOfLRIReuse
** The time at which the LRI represented by firstReusedLRI was reused.
** The time is the number of seconds since January 1, 1970.
** 
** currentTimeValue
** The current time according to the database.
** 
** futureUse1
** This field is for future functionality. The current version of DB2
** always returns a value of 0.
** 
** oldestInFlightLSN
** LSN of the oldest inflight transaction.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReadLogInfoStruct
{
   db2LRI                              initialLRI; /* Initial LRI at first    */
                                                 /* connect                   */
   db2LRI                              firstReadLRI; /* First LRI read on     */
                                                 /* call                      */
   db2LRI                              nextStartLRI; /* Next LRI caller       */
                                                 /* should read               */
   db2LRI                              firstReusedLRI; /* First LRI reused    */
                                                 /* due to restore            */
                                                 /* rollforward               */
   db2Uint32                           logRecsWritten; /* Number of log       */
                                                 /* records returned          */
   db2Uint32                           logBytesWritten; /* Number of log      */
                                                 /* bytes returned            */
   db2Uint32                           timeOfLRIReuse; /* Timestamp for when  */
                                                 /* LRI reuse occurred        */
   db2TimeOfLog                        currentTimeValue; /* Current time      */
   db2Uint32                           futureUse1; /* Field for future        */
                                                 /* functionality             */
   db2LSN                              oldestInFlightLSN; /* LSN of the       */
                                                 /* oldest inflight           */
                                                 /* transaction               */
} db2ReadLogInfoStruct;

/******************************************************************************
** db2ReadLogFilterData data structure
** db2ReadLogFilterData data structure parameters
** 
** recordLRIType1
** LRI of the log record.  This is a type 1 LRI.
** 
** recordLRIType2
** LRI of the log record.  This is a type 2 LRI.
** 
** realLogRecLen
** The physical log record length in the DB2 logs.
** 
** sqlcode
** This field will be non-zero if an error occurred while trying to
** decompress the log record. If an error occurred, it will contain the SQL
** code associated with the error. For permanent errors, SQL0204N will be returned.
** Resubmitting the API request may return with the same error. For
** transient errors, the SQL code returned will correspond to the cause of
** the error, which may or may not require user action to rectify.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReadLogFilterData
{
   db2LRI                              recordLRIType1; /* Type 1 log record   */
                                                 /* identifier                */
   db2LRI                              recordLRIType2; /* Type 2 log record   */
                                                 /* identifier                */
   db2Uint32                           realLogRecLen; /* The physical log     */
                                                 /* record length             */
   db2int32                            sqlcode;  /* SQLCODE corresponding to  */
                                                 /* the decompression error   */
} db2ReadLogFilterData;

/* Asynchronous Read Log API Input Structure                                  */
/******************************************************************************
** db2ReadLogStruct data structure
** db2ReadLogStruct data structure parameters
** 
** iCallerAction
** Input. Specifies the action to be performed.
** DB2READLOG_READ 
** Read the database log from the starting log sequence to the ending log
** sequence number and return log records within this range. 
** DB2READLOG_READ_SINGLE 
** Read a single log record (propagatable or not) identified by the
** starting log sequence number. 
** DB2READLOG_QUERY 
** Query the database log. Results of the query will be sent back via the
** db2ReadLogInfoStruct structure. 
** 
** piStartLRI 
** Input. The starting log record identifier specifies the starting position
** for the reading of the log.
** 
** piEndLRI 
** Input. The ending log record identifier specifies the ending position
** for the reading of the log. This value must be greater than
** the piStartLRI parameter, and does not need to be the end of an actual log
** record. 
** 
** poLogBuffer 
** Output. The buffer where all the propagatable log records read within the
** specified range are stored sequentially. This buffer must be large enough to
** hold a single log record. As a guideline, this buffer should be a minimum
** of 88 bytes. Its maximum size is dependent on the size of the requested
** range.
** - If the iFilterOption is ON, the db2ReadLogFilterData structure will be
** prefixed to each log record.
** - If the iFilterOption is OFF, each log record in the buffer is prefixed
** by two 24 byte LRIs. The first LRI is of type DB2READLOG_LRI_1 and the
** second LRI is of type DB2READLOG_LRI_2, both representing the LRI of the
** following log record.
** 
** iLogBufferSize 
** Input. Specifies the size, in bytes, of the log buffer. 
** 
** iFilterOption 
** Input. Specifies the level of log record filtering to be used when reading
** the log records. Valid values are: 
** - DB2READLOG_FILTER_OFF 
** Read all log records in the given LRI range. 
** - DB2READLOG_FILTER_ON 
** Reads only log records in the given LRI range marked as propagatable. This is
** the traditional behavior of the asynchronous log read API. The log records
** that are returned when this value is used are documented in the "DB2 UDB
** log records" topic. All other log records are for IBM internal use only
** and are therefore not documented.
** 
** poReadLogInfo 
** Output. A structure detailing information regarding the call and the database
** log. 
** 
** piMinRequiredLRI 
** Input. The minimum required log record indentifier specifies the point 
** in the logs in which the logs before this point are no longer required,
** and won't be read again using db2ReadLog.  This value will only be
** valid for the DB2READLOG_READ_FROM_SPOOL iCallerAction.  It will be
** ignored in all other cases.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReadLogStruct
{
   db2Uint32                           iCallerAction; /* Type of read         */
                                                 /* required                  */
   db2LRI                              *piStartLRI; /* Start read log record  */
                                                 /* identifier                */
   db2LRI                              *piEndLRI; /* End read log record      */
                                                 /* identifier                */
   char                                *poLogBuffer; /* User buffer           */
   db2Uint32                           iLogBufferSize; /* Size of user        */
                                                 /* buffer                    */
   db2Uint32                           iFilterOption; /* Set filtering level  */
   db2ReadLogInfoStruct                *poReadLogInfo; /* Read log            */
                                                 /* information structure     */
   db2LRI                              *piMinRequiredLRI; /* Minimum          */
                                                 /* required log record       */
                                                 /* identifier                */
} db2ReadLogStruct;

/******************************************************************************
** db2ReadLog API
** Extracts log records from the DB2 UDB database logs and the Log Manager
** for current log state information. This API can only be used with
** recoverable databases. A database is recoverable if the database
** configuration parameters logarchmeth1 and/or logarchmeth2 are not set
** to OFF.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - dbadm
** 
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2ReadLog API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter, pDB2ReadLogStruct.
** 
** pDB2ReadLogStruct
** Input. A pointer to the db2ReadLogStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** If the requested action is to read the log, the caller will provide a
** log record identifier range and a buffer to hold the log records. This
** API reads the log sequentially, bounded by the requested LRI range,
** and returns log records associated with tables defined with the
** DATA CAPTURE CHANGES clause, and a db2ReadLogInfoStruct structure
** with the current active log information. If the requested action is
** a query of the database log (indicated by specifying the value
** DB2READLOG_QUERY), the API returns a db2ReadLogInfoStruct structure
** with the current active log information.
** 
** To use the Asynchronous Log Reader, first query the database log for a valid
** starting LRI. Following the query call, the read log information structure
** (db2ReadLogInfoStruct) will contain a valid starting LRI (in the initialLRI
** member), to be used on a read call. The value used as the ending LRI on a
** read can be one of the following:
** 
** - A value greater than initialLRI
** - (0000 0000 0000 0001, FFFF FFFF FFFF FFFF, FFFF FFFF FFFF FFFF)
**   (lriType, part1, part2)
** which is interpreted by the asynchronous log reader as the end of the current
** log.
** 
** The propagatable log records read within the starting and ending LRI range
** are returned in the log buffer. A log record does not contain its LRI; it
** is contained in the buffer before the actual log record. Descriptions of
** the various DB2 log records returned by db2ReadLog the DB2 UDB Log Records
** section.
** 
** To read the next sequential log record after the initial read, use the
** nextStartLRI field returned in the db2ReadLogStruct structure. Resubmit
** the call, with this new starting LRI and a valid ending LRI. The next
** block of records is then read. An sqlca code of
** SQLU_RLOG_READ_TO_CURRENT means that the log reader has read to the
** end of the current active log.
** 
** This API reads data from the DB2 logs and Label-Based Access Control (LBAC)
** is not enforced on such logs. Thus, an application that calls this API can
** potentially gain access to table data if the caller has sufficient
** authority to call the API and is able to understand the log records format.
** 
** The db2ReadLog API works on the current database connection. If multiple
** database connections are created with the same process, then use the
** concurrent access APIs to manage the multiple contexts.
** 
** Calling the db2ReadLog API from an application can result in an error
** when the application disconnects from the database if a commit or rollback
** is not performed before the disconnect:
** - A CLI0116E error might be generated if the db2ReadLog API is called
** from a CLI application.
** - A SQL0428N error might be generated if the db2ReadLog API is called from
** an embedded SQL application written in C.
** Workaround 1:
** For non-embedded SQL applications, set autocommit mode on before calling
** the db2ReadLog API.
** Workaround 2:
** Issue a COMMIT or ROLLBACK statement after calling the db2ReadLog API and
** before disconnecting from the database.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Asynchronous Read Log               */
  db2ReadLog (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2ReadLogStruct,       /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */


/* Standalone Read Log API Definitions                                        */

/* Values for db2ReadLogNoConn - iRetrieveLogs                                */
#define DB2READLOG_RETRIEVE_OFF        0         /* Do not retrieve missing   */
                                                 /* logs                      */
#define DB2READLOG_RETRIEVE_LOGPATH    1         /* Retrieve logs to logpath  */
#define DB2READLOG_RETRIEVE_OVERFLOW   2         /* Retrieve logs to          */
                                                 /* overflow logpath          */

/* Standalone Read Log API Initialization Input Structure                     */
/******************************************************************************
** db2ReadLogNoConnInitStruct data structure
** db2ReadLogNoConnInitStruct data structure parameters
** 
** iFilterOption 
** Input. Specifies the level of log record filtering to be used when
** reading the log records. Valid values are: 
** - DB2READLOG_FILTER_OFF 
** Read all log records in the given LSN range. 
** - DB2READLOG_FILTER_ON 
** Reads only log records in the given LSN range marked as propagatable. This is
** the traditional behavior of the asynchronous log read API. 
** 
** piLogFilePath 
** Input. Path where the log files to be read are located. 
** 
** piOverflowLogPath 
** Input. Alternate path where the log files to be read may be located. 
** 
** iRetrieveLogs 
** Input. Option specifying if userexit should be invoked to retrieve log files
** that cannot be found in either the log file path or the overflow log path.
** Valid values are: 
** - DB2READLOG_RETRIEVE_OFF 
** Userexit should not be invoked to retrieve missing log files. 
** DB2READLOG_RETRIEVE_LOGPATH 
** Userexit should be invoked to retrieve missing log files into the specified
** log file path. 
** - DB2READLOG_RETRIEVE_OVERFLOW 
** Userexit should be invoked to retrieve missing log files into the specified
** overflow log path. 
** 
** piDatabaseName 
** Input. Name of the database that owns the recovery logs being read. This is
** required if the retrieve option above is specified. 
** 
** piDbPartitionName 
** Input. Name of the database partition that owns the recovery logs being read.
** This is required if the retrieve option, mentioned previously, is specified outside
** of a DB2® pureScale environment. 
** 
** piLogStreamNum 
** Input. Log stream number that owns the recovery logs that are being read.
** This is required if the retrieve option, mentioned previously, is specified in a
** DB2 pureScale environment. 
** 
** iReadLogMemoryLimit 
** Input. Maximum number of bytes that the API may allocate internally. 
** 
** poReadLogMemPtr 
** Output. API-allocated block of memory of size iReadLogMemoryLimit. This
** memory contains persistent data that the API requires at each
** invocation. This memory block must not be reallocated or altered in any
** way by the caller. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReadLogNoConnInitStruct
{
   db2Uint32                           iFilterOption; /* Set filtering level  */
   char                                *piLogFilePath; /* Path to log files   */
                                                 /* to be read                */
   char                                *piOverflowLogPath; /* Secondary path  */
                                                 /* to log files              */
   db2Uint32                           iRetrieveLogs; /* Retrieve logs        */
                                                 /* options                   */
   char                                *piDatabaseName; /* Name of the        */
                                                 /* source database           */
   char                                *piDbPartitionName; /* Name of the     */
                                                 /* source database           */
                                                 /* partition                 */
   db2LogStreamIDType                  *piLogStreamNum; /* Number of the log  */
                                                 /* stream owning the logs    */
   db2Uint32                           iReadLogMemoryLimit; /* Number of      */
                                                 /* bytes of memory the API   */
                                                 /* may allocate internally   */
   char                                **poReadLogMemPtr; /* Pointer to API   */
                                                 /* allocate memory           */
} db2ReadLogNoConnInitStruct;

/******************************************************************************
** db2ReadLogNoConnInit API
** Allocates the memory to be used by db2ReadLogNoConn in order to extract log
** records from the DB2 UDB database logs and query the Log Manager for current
** log state information.
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
** db2ApiDf.h
** 
** db2ReadLogNoConnInit API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pDB2ReadLogNoConnInitStruct.
** 
** pDB2ReadLogNoConnInitStruct
** Input. A pointer to the db2ReadLogNoConnInitStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The memory initialized by db2ReadLogNoConnInit must not be altered.
** 
** When db2ReadLogNoConn will no longer be used, invoke
** db2ReadLogNoConnTerm to deallocate the memory initialized by
** db2ReadLogNoConnInit.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Standalone Read Log Initialization  */
                                       /* API                                 */
  db2ReadLogNoConnInit (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2ReadLogNoConnInitStruct, /* Input parameters                */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Standalone Read Log API Info Output Structure                              */
/******************************************************************************
** db2ReadLogNoConnInfoStruct data structure
** db2ReadLogNoConnInfoStruct data structure parameters
** 
** firstAvailableLSN
** First available LSN in available logs. 
** 
** firstReadLSN 
** First LSN read on this call. 
** 
** nextStartLSN 
** Next readable LSN. 
** 
** logRecsWritten 
** Number of log records written to the log buffer field, poLogBuffer. 
** 
** logBytesWritten 
** Number of bytes written to the log buffer field, poLogBuffer. 
** 
** lastLogFullyRead 
** Number indicating the last log file that was read to completion.
** currentTimeValue
** Reserved for future use.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReadLogNoConnInfoStruct
{
   db2LSN                              firstAvailableLSN; /* First available  */
                                                 /* LSN in logpath            */
   db2LSN                              firstReadLSN; /* First LSN read on     */
                                                 /* call                      */
   db2LSN                              nextStartLSN; /* Next LSN caller       */
                                                 /* should read               */
   db2Uint32                           logRecsWritten; /* Number of log       */
                                                 /* records returned          */
   db2Uint32                           logBytesWritten; /* Number of log      */
                                                 /* bytes returned            */
   db2Uint32                           lastLogFullyRead; /* Last log read to  */
                                                 /* completion on call        */
   db2TimeOfLog                        currentTimeValue; /* Current time      */
} db2ReadLogNoConnInfoStruct;

/* Standalone Read Log API Input Structure                                    */
/******************************************************************************
** db2ReadLogNoConnStruct data structure
** db2ReadLogNoConnStruct data structure parameters
** 
** iCallerAction
** Input. Specifies the action to be performed. Valid values are:
** - DB2READLOG_READ 
** Read the database log from the starting log sequence to the ending
** log sequence number and return log records within this range. 
** - DB2READLOG_READ_SINGLE 
** Read a single log record (propagatable or not) identified by the starting log
** sequence number. 
** - DB2READLOG_QUERY 
** Query the database log. Results of the query will be sent back via the
** db2ReadLogNoConnInfoStruct structure. 
** 
** piStartLSN 
** Input. The starting log sequence number specifies the starting relative byte
** address for the reading of the log. This value must be the start of an actual
** log record. 
** 
** piEndLSN 
** Input. The ending log sequence number specifies the ending relative byte
** address for the reading of the log. This value must be greater than
** piStartLsn, and does not need to be the end of an actual log record. 
** 
** poLogBuffer 
** Output. The buffer where all the propagatable log records read within the
** specified range are stored sequentially. This buffer must be large enough to
** hold a single log record. As a guideline, this buffer should be a minimum of
** 48 bytes. Its maximum size is dependent on the size of the requested range.
** Each log record in the buffer is prefixed by an eight byte log sequence
** number (LSN), representing the LSN of the following log record. 
** 
** iLogBufferSize 
** Input. Specifies the size, in bytes, of the log buffer. 
** 
** piReadLogMemPtr 
** Input. Block of memory of size iReadLogMemoryLimit that was allocated
** in the initialization call. This memory contains persistent data that
** the API requires at each invocation. This memory block must not be
** reallocated or altered in any way by the caller. 
** 
** poReadLogInfo 
** Output. A pointer to the db2ReadLogNoConnInfoStruct structure. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReadLogNoConnStruct
{
   db2Uint32                           iCallerAction; /* Type of read         */
                                                 /* required                  */
   db2LSN                              *piStartLSN; /* Start read log         */
                                                 /* sequence number           */
   db2LSN                              *piEndLSN; /* End read log sequence    */
                                                 /* number                    */
   char                                *poLogBuffer; /* User buffer           */
   db2Uint32                           iLogBufferSize; /* Size of user        */
                                                 /* buffer                    */
   char                                *piReadLogMemPtr; /* Pointer to API    */
                                                 /* allocated memory          */
   db2ReadLogNoConnInfoStruct          *poReadLogInfo; /* Read log            */
                                                 /* information structure     */
} db2ReadLogNoConnStruct;

/******************************************************************************
** db2ReadLogNoConn API
** Extracts log records from the DB2 UDB database logs and queries the Log
** Manager for current log state information. Prior to using this API, call
** the db2ReadLogNoConnInit API to allocate the memory that is passed as
** an input parameter to this API. After calling this API, call the
** db2ReadLogNoConnTerm API to deallocate the memory.
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
** db2ApiDf.h
** 
** db2ReadLogNoConn API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter, pDB2ReadLogNoConnStruct.
** 
** pDB2ReadLogNoConnStruct
** Input. A pointer to the db2ReadLogNoConnStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The db2ReadLogNoConn API requires a memory block that must be allocated
** using the db2ReadLogNoConnInit API. The memory block must be passed as an
** input parameter to all subsequent db2ReadLogNoConn API calls, and must not be
** altered.
** 
** When requesting a sequential read of log, the API requires a log sequence
** number (LSN) range and the allocated memory . The API will return a
** sequence of log records based on the filter option specified when initialized
** and the LSN range. When requesting a query, the read log information
** structure will contain a valid starting LSN, to be used on a read call.
** The value used as the ending LSN on a read can be one of the following:
** 
** - A value greater than the caller-specified startLSN.
** - FFFF FFFF FFFF FFFF which is interpreted by the asynchronous log reader
** as the end of the available logs.
** 
** The propagatable log records read within the starting and ending LSN
** range are returned in the log buffer. A log record does not contain its
** LSN, it is contained in the buffer before the actual log record.
** Descriptions of the various DB2 UDB log records returned by
** db2ReadLogNoConn can be found in the DB2 UDB Log Records section.
** 
** After the initial read, in order to read the next sequential log record,
** use the nextStartLSN value returned in db2ReadLogNoConnInfoStruct.
** Resubmit the call, with this new starting LSN and a valid ending LSN and
** the next block of records is then read. An sqlca code of
** SQLU_RLOG_READ_TO_CURRENT means the log reader has read to the end of
** the available log files.
** 
** When the API will no longer be used, use db2ReadLogNoConnTerm to terminate
** the memory.
** 
** This API reads data from the DB2 logs and Label-Based Access Control (LBAC)
** is not enforced on such logs. Thus, an application that calls this API can
** potentially gain access to table data if the caller has sufficient
** authority to call the API and is able to understand the log records format.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Standalone Read Log API             */
  db2ReadLogNoConn (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2ReadLogNoConnStruct, /* Input parameters                    */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Standalone Read Log API Termination Input Structure                        */
/******************************************************************************
** db2ReadLogNoConnTermStruct data structure
** db2ReadLogNoConnTermStruct data structure parameters
** 
** poReadLogMemPtr
** Output. Pointer to the block of memory allocated in the initialization call.
** This pointer will be freed and set to NULL. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ReadLogNoConnTermStruct
{
   char                                **poReadLogMemPtr; /* Pointer to API   */
                                                 /* allocated memory          */
} db2ReadLogNoConnTermStruct;

/******************************************************************************
** db2ReadLogNoConnTerm API
** Deallocates the memory used by the db2ReadLogNoConn API, originally
** initialized by the db2ReadLogNoConnInit API.
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
** db2ApiDf.h
** 
** db2ReadLogNoConnTerm API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pDB2ReadLogNoConnTermStruct.
** 
** pDB2ReadLogNoConnTermStruct
** Input. A pointer to the db2ReadLogNoConnTermStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Standalone Read Log Termination     */
                                       /* API                                 */
  db2ReadLogNoConnTerm (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pDB2ReadLogNoConnTermStruct, /* Input parameters                */
       struct sqlca * pSqlca);         /* SQLCA                               */


/* Ping Database Parameter Structure                                          */
/******************************************************************************
** db2DatabasePingStruct data structure
** db2DatabasePingStruct data structure parameters
** 
** iDbAlias
** Input. Database alias name. Reserved for future use.If a value is provided,
** it is ignored.
** 
** RequestPacketSz
** Input. Size of the packet (in bytes) to be sent to the server. The size
** must be between 0 and 32767 inclusive. This parameter is only valid on
** servers running DB2 UDB for Linux, UNIX and Windows Version 8 or
** higher, or DB2 UDB for z/OS Version 8 or higher.
** 
** ResponsePacketSz
** Input. Size of the packet (in bytes) to be returned back to client. The size
** must be between 0 and 32767 inclusive. This parameter is only valid on
** servers running DB2 UDB for Linux, UNIX and Windows Version 8 or higher,
** or DB2 UDB for z/OS Version 8 or higher.
** 
** iNumIterations
** Input. Number of test request iterations. The value must be between 1 and
** 32767 inclusive.
** 
** poElapsedTime
** Output. A pointer to an array of 32-bit integers where the number of elements
** is equal to iNumIterations. Each element in the array will contain the
** elapsed time in microseconds for one test request iteration.
** Note:
** The application is responsible for allocating the memory for this array
** prior to calling this API.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DatabasePingStruct
{
   char                                iDbAlias[SQL_ALIAS_SZ + 1]; /* Input:  */
                                                 /* Database alias -          */
                                                 /* reserved                  */
   db2int32                            RequestPacketSz; /* Input: size of     */
                                                 /* request packet            */
   db2int32                            ResponsePacketSz; /* Input: size of    */
                                                 /* response packet           */
   db2Uint16                           iNumIterations; /* Input: Number of    */
                                                 /* iterations                */
   db2Uint32                           *poElapsedTime; /* Output: Array of    */
                                                 /* elapsed times             */
                                                 /* (microsec), contains      */
                                                 /* iNumIterations elements   */
} db2DatabasePingStruct;

/******************************************************************************
** db2DatabasePing API
** Tests the network response time of the underlying connectivity between
** a client and a database server. This API can be used by an application
** when a host database server is accessed via DB2 Connect either directly
** or through a gateway.
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
** db2ApiDf.h
** 
** db2DatabasePing API parameters
** 
** versionNumber
** Input. Specifies the version and release of the DB2 Universal Database or DB2
** Connect product that the application is using.
** 
** pParmStruct
** Input. A pointer to the db2DatabasePingStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** This API will not work when it is used from a DB2 Universal Database
** Version 7 client through a DB2 Connect Version 8 to a connected DB2
** host database server.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Ping Database                       */
  db2DatabasePing (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Ping Database Parameter Structure                                  */
/******************************************************************************
** db2gDatabasePingStruct data structure
** db2gDatabasePingStruct data structure specific parameters
** 
** iDbAliasLength
** Input. Length of the database alias name. Reserved for future use.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gDatabasePingStruct
{
   db2Uint16                           iDbAliasLength; /* Input: Db alias     */
                                                 /* name length - reserved    */
   char                                iDbAlias[SQL_ALIAS_SZ + 1]; /* Input:  */
                                                 /* Database alias -          */
                                                 /* reserved                  */
   db2int32                            RequestPacketSz; /* Input: size of     */
                                                 /* request packet            */
   db2int32                            ResponsePacketSz; /* Input: size of    */
                                                 /* response packet           */
   db2Uint16                           iNumIterations; /* Input: Number of    */
                                                 /* iterations                */
   db2Uint32                           *poElapsedTime; /* Output: Array of    */
                                                 /* elapsed times             */
                                                 /* (microsec), contains      */
                                                 /* iNumIterations elements   */
} db2gDatabasePingStruct;

/******************************************************************************
** db2gDatabasePing API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Ping Database               */
  db2gDatabasePing (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/******************************************************************************
** Convert LSN from internal representation to ascii hex string.
**      _inLsn  - char * that points to the LSN in db2 internal b-byte
**                binary format.
**      _outStr - char * to store the output in hex string format.  It
**                should be big enough to store at least 13 bytes.
*******************************************************************************/

#define db2LsnToString(_inLsn, _outStr) \
         sprintf(_outStr, "%016lX", (_inLsn).lsnU64)

/* Convert Monitor Data Interface Structure                                   */
/******************************************************************************
** db2ConvMonStreamData data structure
** db2ConvMonStreamData data structure parameters
** 
** poTarget
** Output. A pointer to the target monitor output structure (for example,
** sqlm_db2). A list of output types, and their corresponding input types, is
** given below.
** 
** piSource
** Input. A pointer to the logical data element being converted (for example,
** SQLM_ELM_DB2). A list of output types, and their corresponding input
** types, is given below.
** 
** iTargetType
** Input. The type of conversion being performed. Specify the value for the v5
** type in sqlmon.h for instance SQLM_DB2_SS.
** 
** iTargetSize
** Input. This parameter can usually be set to the size of the structure pointed
** to by poTarget; however, for elements that have usually been referenced by
** an offset value from the end of the structure (for example, statement text in
** sqlm_stmt), specify a buffer that is large enough to contain the sqlm_stmt
** statically-sized elements, as well as a statement of the largest size to be
** extracted; that is, SQL_MAX_STMT_SIZ plus sizeof(sqlm_stmt).
** 
** iSourceType
** Input. The type of source stream. Valid values are SQLM_STREAM_SNAPSHOT
** (snapshot stream), or SQLM_STREAM_EVMON (event monitor stream).
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ConvMonStreamData
{
   void                                *poTarget; /* Pointer to target        */
                                                 /* structure                 */
   struct sqlm_header_info             *piSource; /* Pointer to V6 stream     */
   db2Uint32                           iTargetType; /* Target structure type  */
   db2Uint32                           iTargetSize; /* Space allocated for    */
                                                 /* target                    */
   db2Uint32                           iSourceType; /* Type of source stream  */
} db2ConvMonStreamData;

/******************************************************************************
** db2ConvMonStream API
** Converts the new, self-describing format for a single logical data
** element (for example, SQLM_ELM_DB2) to the corresponding pre-version
** 6 external monitor structure (for example, sqlm_db2). When upgrading
** API calls to use the post-version 5 stream, one must traverse the
** monitor data using the new stream format (for example, the user
** must find the SQLM_ELM_DB2 element). This portion of the stream
** can then be passed into the conversion API to get the associated
** pre-version 6 data.
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
** db2ApiDf.h
** 
** db2ConvMonStream API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure
** passed in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2ConvMonStreamData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Following is a list of supported convertible data elements:
** 
** Table: Supported convertible data elements: snapshot variables
** ---------------------------------------------------------------------
** |Snapshot variable datastream type     |Structure                    |
** |--------------------------------------|-----------------------------|
** |SQLM_ELM_APPL                         |sqlm_appl                    |
** |SQLM_ELM_APPL_INFO                    |sqlm_applinfo                |
** |SQLM_ELM_DB2                          |sqlm_db2                     |
** |SQLM_ELM_FCM                          |sqlm_fcm                     |
** |SQLM_ELM_FCM_NODE                     |sqlm_fcm_node                |
** |SQLM_ELM_DBASE                        |sqlm_dbase                   |
** |SQLM_ELM_TABLE_LIST                   |sqlm_table_header            |
** |SQLM_ELM_TABLE                        |sqlm_table                   |
** |SQLM_ELM_DB_LOCK_LIST                 |sqlm_dbase_lock              |
** |SQLM_ELM_APPL_LOCK_LIST               |sqlm_appl_lock               |
** |SQLM_ELM_LOCK                         |sqlm_lock                    |
** |SQLM_ELM_STMT                         |sqlm_stmt                    |
** |SQLM_ELM_SUBSECTION                   |sqlm_subsection              |
** |SQLM_ELM_TABLESPACE_LIST              |sqlm_tablespace_header       |
** |SQLM_ELM_TABLESPACE                   |sqlm_tablespace              |
** |SQLM_ELM_ROLLFORWARD                  |sqlm_rollfwd_info            |
** |SQLM_ELM_BUFFERPOOL                   |sqlm_bufferpool              |
** |SQLM_ELM_LOCK_WAIT                    |sqlm_lockwait                |
** |SQLM_ELM_DCS_APPL                     |sqlm_dcs_appl,               |
** |                                      |sqlm_dcs_applid_info,        |
** |                                      |sqlm_dcs_appl_snap_stats,    |
** |                                      |sqlm_xid, sqlm_tpmon         |
** |SQLM_ELM_DCS_DBASE                    |sqlm_dcs_dbase               |
** |SQLM_ELM_DCS_APPL_INFO                |sqlm_dcs_applid_info         |
** |SQLM_ELM_DCS_STMT                     |sqlm_dcs_stmt                |
** |SQLM_ELM_COLLECTED                    |sqlm_collected               |
** |--------------------------------------|-----------------------------|
** 
** Table: Supported convertible data elements: event monitor variables
** |--------------------------------------|-----------------------------|
** |Event monitor variable datastream type|Structure                    |
** |--------------------------------------|-----------------------------|
** |SQLM_ELM_EVENT_DB                     |sqlm_db_event                |
** |SQLM_ELM_EVENT_CONN                   |sqlm_conn_event              |
** |SQLM_ELM_EVENT_TABLE                  |sqlm_table_event             |
** |SQLM_ELM_EVENT_STMT                   |sqlm_stmt_event              |
** |SQLM_ELM_EVENT_XACT                   |sqlm_xaction_event           |
** |SQLM_ELM_EVENT_DEADLOCK               |sqlm_deadlock_event          |
** |SQLM_ELM_EVENT_DLCONN                 |sqlm_dlconn_event            |
** |SQLM_ELM_EVENT_TABLESPACE             |sqlm_tablespace_event        |
** |SQLM_ELM_EVENT_DBHEADER               |sqlm_dbheader_event          |
** |SQLM_ELM_EVENT_START                  |sqlm_evmon_start_event       |
** |SQLM_ELM_EVENT_CONNHEADER             |sqlm_connheader_event        |
** |SQLM_ELM_EVENT_OVERFLOW               |sqlm_overflow_event          |
** |SQLM_ELM_EVENT_BUFFERPOOL             |sqlm_bufferpool_event        |
** |SQLM_ELM_EVENT_SUBSECTION             |sqlm_subsection_event        |
** |SQLM_ELM_EVENT_LOG_HEADER             |sqlm_event_log_header        |
** |--------------------------------------|-----------------------------|
** 
** The sqlm_rollfwd_ts_info structure is not converted; it only contains a table
** space name that can be accessed directly from the stream. The sqlm_agent
** structure is also not converted; it only contains the pid of the agent,
** which can also be accessed directly from the stream.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Convert monitor stream    */
  db2ConvMonStream (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gConvMonStream API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Convert monitor stream    */
  db2gConvMonStream (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Get Snapshot Data Interface Structure                                      */
/******************************************************************************
** db2GetSnapshotData data structure
** db2GetSnapshotData data structure parameters
** 
** piSqlmaData
** Input. Pointer to the user-allocated sqlma (monitor area) structure. This
** structure specifies the type or types of data to be collected.
** 
** poCollectedData
** Output. A pointer to the sqlm_collected structure into which the database
** monitor delivers summary statistics and the number of each type of data
** structure returned in the buffer area.
** Note:
** This structure is only used for pre-Version 6 data streams. However,
** if a snapshot call is made to a back-level remote server, this
** structure must be passed in for results to be processed. It is
** therefore recommended that this parameter always be passed in.
** 
** poBuffer
** Output. Pointer to the user-defined data area into which the snapshot
** information will be returned.
** 
** iVersion
** Input. Version ID of the database monitor data to collect. The database
** monitor only returns data that was available for the requested version. Set
** this parameter to one of the following constants:
** - SQLM_DBMON_VERSION1
** - SQLM_DBMON_VERSION2
** - SQLM_DBMON_VERSION5
** - SQLM_DBMON_VERSION5_2
** - SQLM_DBMON_VERSION6
** - SQLM_DBMON_VERSION7
** - SQLM_DBMON_VERSION8
** - SQLM_DBMON_VERSION9
** - SQLM_DBMON_VERSION9_5
** - SQLM_DBMON_VERSION9_7
** - SQLM_DBMON_VERSION9_7_1
** 
** Note:
** If SQLM_DBMON_VERSION1 is specified as the version, the APIs cannot be
** run remotely.
** 
** iBufferSize
** Input. The length of the data buffer. Use the db2GetSnapshotSize API to
** estimate the size of this buffer. If the buffer is not large enough, a
** warning is returned, along with the information that will fit in the
** assigned buffer. It may be necessary to resize the buffer and call the
** API again. 
** 
** iStoreResult
** Input. An indicator set to constant value TRUE or FALSE, depending on
** whether the snapshot results are to be stored at the DB2 server for
** viewing through SQL. This parameter should only be set to TRUE when
** the snapshot is being taken over a database connection, and when one
** of the snapshot types in the sqlma is SQLMA_DYNAMIC_SQL.
** 
** iNodeNumber
** Input. The database partition where the request is to be sent. Based
** on this value, the request will be processed for the current node, all
** nodes or a user specified node. Valid values are:
** - SQLM_CURRENT_NODE
** - SQLM_ALL_NODES. Only allowed when the iVersion parameter is set to
** SQLM_DBMON_VERSION7 or newer.
** - database partition number
** 
** Note:
** For standalone instances the SQLM_CURRENT_NODE value must be used.
** 
** poOutputFormat
** The format of the stream returned by the server. It will be one of the
** following:
** - SQLM_STREAM_STATIC_FORMAT
** - SQLM_STREAM_DYNAMIC_FORMAT
** 
** iSnapshotClass
** Input. The class qualifier for the snapshot. Valid values (defined in
** sqlmon header file, located in the include directory) are:
** - SQLM_CLASS_DEFAULT for a standard snapshot
** - SQLM_CLASS_HEALTH for a health snapshot
** - SQLM_CLASS_HEALTH_WITH_DETAIL for a health snapshot including
** additional details
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetSnapshotData
{
   void                                *piSqlmaData; /* Pointer to monitor    */
                                                 /* area                      */
   struct sqlm_collected               *poCollectedData; /* Pointer to        */
                                                 /* collected data            */
   void                                *poBuffer; /* Pointer to output        */
                                                 /* buffer                    */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2Uint32                           iBufferSize; /* Size of output buffer  */
   db2Uint32                           iStoreResult; /* Write to file flag    */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition number          */
   db2Uint32                           *poOutputFormat; /* Pointer to output  */
                                                 /* format indicator          */
   db2Uint32                           iSnapshotClass; /* Class qualifier     */
                                                 /* for snapshot              */
} db2GetSnapshotData;

/******************************************************************************
** db2gGetSnapshotData data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gGetSnapshotData
{
   void                                *piSqlmaData; /* Pointer to monitor    */
                                                 /* area                      */
   struct sqlm_collected               *poCollectedData; /* Pointer to        */
                                                 /* collected data            */
   void                                *poBuffer; /* Pointer to output        */
                                                 /* buffer                    */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2Uint32                           iBufferSize; /* Size of output buffer  */
   db2Uint32                           iStoreResult; /* Write to file flag    */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition number          */
   db2Uint32                           *poOutputFormat; /* Pointer to output  */
                                                 /* format indicator          */
   db2Uint32                           iSnapshotClass; /* Class qualifier     */
                                                 /* for snapshot              */
} db2gGetSnapshotData;

/******************************************************************************
** db2GetSnapshot API
** Collects database manager monitor information and returns it to a
** user-allocated data buffer. The information returned represents a
** snapshot of the database manager operational status at the time
** the API was called.
** 
** Scope
** 
** This API can return information for the database partition server
** on the instance, or all database partitions on the instance.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - sysmon
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** To obtain a snapshot from a remote instance (or a different local
** instance), it is necessary to first attach to that instance.
** 
** API include file
** 
** db2ApiDf.h
** 
** API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct. To use the structure as described above,
** specify db2Version810. If you want to use a different version of this
** structure, check the db2ApiDf.h header file in the include directory for
** the complete list of supported versions. Ensure that you use the version
** of the db2GetSnapshotData structure that corresponds to the version number
** that you specify.
** 
** pParmStruct
** Input/Output. A pointer to the db2GetSnapshotData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** If an alias for a database residing at a different instance is specified,
** an error message is returned.
** 
** To retrieve a health snapshot with full collection information, use
** the AGENT_ID field in the SQLMA data structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot              */
  db2GetSnapshot (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gGetSnapshot API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot              */
  db2gGetSnapshot (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Get Snapshot Size Data Interface Structure                                 */
/******************************************************************************
** db2GetSnapshotSizeData data structure
** db2GetSnapshotSizeData data structure parameters
** 
** piSqlmaData
** Input. Pointer to the user-allocated sqlma (monitor area) structure. This
** structure specifies the type or types of snapshot data to be collected,
** and can be reused as input to the db2GetSnapshot API.
** 
** poBufferSize
** Output. A pointer to the returned estimated buffer size needed by the
** GET SNAPSHOT API.
** 
** iVersion
** Input. Version ID of the database monitor data to collect. The database
** monitor only returns data that was available for the requested version. Set
** this parameter to one of the following symbolic constants:
** - SQLM_DBMON_VERSION1
** - SQLM_DBMON_VERSION2
** - SQLM_DBMON_VERSION5
** - SQLM_DBMON_VERSION5_2
** - SQLM_DBMON_VERSION6
** - SQLM_DBMON_VERSION7
** - SQLM_DBMON_VERSION8
** - SQLM_DBMON_VERSION9
** - SQLM_DBMON_VERSION9_5
** - SQLM_DBMON_VERSION9_7
** - SQLM_DBMON_VERSION9_7_1
** 
** Note:
** If SQLM_DBMON_VERSION1 is specified as the version, the APIs cannot be
** run remotely.
** 
** iNodeNumber
** Input. The database partition server where the request is to be sent.
** Based on this value, the request will be processed for the current
** database partition server, all database partition servers, or a user
** specified database partition server. Valid values are:
** - SQLM_CURRENT_NODE
** - SQLM_ALL_NODES. Only allowed when iVersion is set to
** SQLM_DBMON_VERSION7 or newer.
** - database partition number
** For stand-alone instances, the value, SQLM_CURRENT_NODE must be used.
** 
** iSnapshotClass
** Input. The class qualifier for the snapshot. Valid values (defined in
** sqlmon header file, located in the include directory) are:
** - SQLM_CLASS_DEFAULT for a standard snapshot
** - SQLM_CLASS_HEALTH for a health snapshot
** - SQLM_CLASS_HEALTH_WITH_DETAIL for a health snapshot including
** additional details
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetSnapshotSizeData
{
   void                                *piSqlmaData; /* Pointer to monitor    */
                                                 /* area                      */
   sqluint32                           *poBufferSize; /* Pointer to output    */
                                                 /* buffer                    */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition                 */
   db2Uint32                           iSnapshotClass; /* Class qualifier     */
                                                 /* for snapshot              */
} db2GetSnapshotSizeData;

/******************************************************************************
** db2gGetSnapshotSizeData data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gGetSnapshotSizeData
{
   void                                *piSqlmaData; /* Pointer to monitor    */
                                                 /* area                      */
   sqluint32                           *poBufferSize; /* Pointer to output    */
                                                 /* buffer                    */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition                 */
   db2Uint32                           iSnapshotClass; /* Class qualifier     */
                                                 /* for snapshot              */
} db2gGetSnapshotSizeData;

/******************************************************************************
** db2GetSnapshotSize API
** Estimates the buffer size needed by the db2GetSnapshot API.
** 
** Scope
** 
** This API can either affect the database partition server on the
** instance, or all database partitions on the instance.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - sysmon
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** To obtain information from a remote instance (or a different local
** instance), it is necessary to first attach to that instance. If an
** attachment does not exist, an implicit instance attachment is made
** to the database partition specified by the DB2INSTANCE environment variable.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2GetSnapshotSize API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct. To use the structure as described above,
** specify db2Version810. If you want to use a different version of this
** structure, check the db2ApiDf.h header file in the include directory for
** the complete list of supported versions. Ensure that you use the version
** of the db2GetSnapshotSizeStruct structure that corresponds to the version
** number that you specify.
** 
** pParmStruct
** Input. A pointer to the db2GetSnapshotSizeStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** This function generates a significant amount of overhead. Allocating
** and freeing memory dynamically for each db2GetSnapshot API call is also
** expensive. If calling db2GetSnapshot repeatedly, for example, when
** sampling data over a period of time, it may be preferable to allocate
** a buffer of fixed size, rather than call db2GetSnapshotSize.
** 
** If the database system monitor finds no active databases or
** applications, it may return a buffer size of zero (if, for example,
** lock information related to a database that is not active is
** requested). Verify that the estimated buffer size returned by
** this API is non-zero before calling db2GetSnapshot. If an error is
** returned by db2GetSnapshot because of insufficient buffer space to
** hold the output, call this API again to determine the new size
** requirements.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot size         */
  db2GetSnapshotSize (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gGetSnapshotSize API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot size         */
  db2gGetSnapshotSize (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Monitor Snapshot v9+ Request Stream Interface Structure                    */
typedef SQL_STRUCTURE db2AddSnapshotRqstData
{
   void                                *pioRequestData; /* Pointer to         */
                                                 /* snapshot request stream,  */
                                                 /* NULL on first call.       */
   db2Uint32                           iRequestType; /* Snapshot request      */
                                                 /* type e.g. SQLMA_DB2       */
   db2int32                            iRequestFlags; /* Stream construction  */
                                                 /* flags                     */
   db2Uint32                           iQualType; /* Type of the qualifier.   */
                                                 /* e.g. SQLMA_QUAL_TYPE      */
                                                 /* DBNAME                    */
   void                                *piQualData; /* Ptr to qualifier       */
                                                 /* data. e.g dbname          */
} db2AddSnapshotRqstData;

SQL_API_RC SQL_API_FN                            /* Prepare snapshot request  */
  db2AddSnapshotRequest (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

typedef SQL_STRUCTURE db2gAddSnapshotRqstData
{
   void                                *pioRequestData; /* Pointer to         */
                                                 /* snapshot request stream,  */
                                                 /* NULL on first call.       */
   db2Uint32                           iRequestType; /* Snapshot request      */
                                                 /* type e.g. SQLMA_DB2       */
   db2int32                            iRequestFlags; /* Stream construction  */
                                                 /* flags                     */
   db2Uint32                           iQualType; /* Type of the qualifier.   */
                                                 /* e.g. SQLMA_QUAL_TYPE      */
                                                 /* DBNAME                    */
   void                                *piQualData; /* Ptr to qualifier       */
                                                 /* data. e.g dbname          */
   db2Uint32                           iQualDataLen; /* Length of the         */
                                                 /* qualifier.                */
} db2gAddSnapshotRqstData;

SQL_API_RC SQL_API_FN                            /* Prepare snapshot request  */
  db2gAddSnapshotRequest (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Monitor Switches Data Interface Structure                                  */
/******************************************************************************
** db2MonitorSwitchesData data structure
** db2MonitorSwitchesData data structure parameters
** 
** piGroupStates
** Input. A pointer to the sqlm-recording-group structure (defined in sqlmon.h)
** containing a list of switches.
** 
** poBuffer
** A pointer to a buffer where the switch state data will be written.
** 
** iBufferSize
** Input. Specifies the size of the output buffer.
** 
** iReturnData
** Input. A flag specifying whether or not the current switch states should
** be written to the data buffer pointed to by poBuffer. 
** 
** iVersion
** Input. Version ID of the database monitor data to collect. The database
** monitor only returns data that was available for the requested version.
** Set this parameter to one of the following symbolic constants:
** - SQLM_DBMON_VERSION1
** - SQLM_DBMON_VERSION2
** - SQLM_DBMON_VERSION5
** - SQLM_DBMON_VERSION5_2
** - SQLM_DBMON_VERSION6
** - SQLM_DBMON_VERSION7
** - SQLM_DBMON_VERSION8
** - SQLM_DBMON_VERSION9
** - SQLM_DBMON_VERSION9_5
** - SQLM_DBMON_VERSION9_7
** - SQLM_DBMON_VERSION9_7_1
** 
** Note:
** If SQLM_DBMON_VERSION1 is specified as the version, the APIs cannot be run
** remotely.
** 
** iNodeNumber
** Input. The database partition server where the request is to be sent. Based
** on this value, the request will be processed for the current database
** partition server, all database partition servers or a user specified
** database partition server. Valid values are:
** - SQLM_CURRENT_NODE
** - SQLM_ALL_NODES
** - database partition number
** Note:
** For standalone instances SQLM_CURRENT_NODE must be used.
** 
** poOutputFormat
** The format of the stream returned by the server. It will be one of the
** following:
** SQLM_STREAM_STATIC_FORMAT
** Indicates that the switch states are returned in static, pre-Version 7 switch
** structures. 
** SQLM_STREAM_DYNAMIC_FORMAT 
** Indicates that the switches are returned in a self-describing format, similar
** to the format returned for db2GetSnapshot. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2MonitorSwitchesData
{
   struct sqlm_recording_group         *piGroupStates; /* Pointer to group    */
                                                 /* states                    */
   void                                *poBuffer; /* Pointer to output        */
                                                 /* buffer                    */
   db2Uint32                           iBufferSize; /* Size of output buffer  */
   db2Uint32                           iReturnData; /* Return data flag       */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition                 */
   db2Uint32                           *poOutputFormat; /* Pointer to output  */
                                                 /* format indicator          */
} db2MonitorSwitchesData;

/******************************************************************************
** db2gMonitorSwitchesData data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gMonitorSwitchesData
{
   struct sqlm_recording_group         *piGroupStates; /* Pointer to group    */
                                                 /* states                    */
   void                                *poBuffer; /* Pointer to output        */
                                                 /* buffer                    */
   db2Uint32                           iBufferSize; /* Size of output buffer  */
   db2Uint32                           iReturnData; /* Return data flag       */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition                 */
   db2Uint32                           *poOutputFormat; /* Pointer to output  */
                                                 /* format indicator          */
} db2gMonitorSwitchesData;

/******************************************************************************
** db2MonitorSwitches API
** Selectively turns on or off switches for groups of monitor data to be
** collected by the database manager. Returns the current state of these
** switches for the application issuing the call.
** 
** Scope
** 
** This API can return information for the database partition server on
** the instance, or all database partitions on the instance.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - sysmon
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** To display the settings for a remote instance (or a different local
** instance), it is necessary to first attach to that instance.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2MonitorSwitches API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct. To use the structure as described above,
** specify db2Version810. If you want to use a different version of this
** structure, check the db2ApiDf.h header file in the include directory
** for the complete list of supported versions. Ensure that you use the
** version of the db2MonitorSwitchesStruct structure that corresponds to
** the version number that you specify.
** 
** pParmStruct
** Input. A pointer to the db2MonitorSwitchesStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** To obtain the status of the switches at the database manager level, call
** db2GetSnapshot, specifying SQMA_DB2 for OBJ_TYPE (get snapshot for database
** manager).
** 
** The timestamp switch is unavailable if iVersion is less than
** SQLM_DBMON_VERSION8.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot size         */
  db2MonitorSwitches (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gMonitorSwitches API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot size         */
  db2gMonitorSwitches (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Monitor Reset Data Interface Structure                                     */
/******************************************************************************
** db2ResetMonitorData data structure
** db2ResetMonitorData data structure parameters
** 
** iResetAll
** Input. The reset flag. 
** 
** piDbAlias 
** Input. A pointer to the database alias. 
** 
** iVersion
** Input. Version ID of the database monitor data to collect. The
** database monitor only returns data that was available for the
** requested version. Set this parameter to one of the following
** symbolic constants: 
** - SQLM_DBMON_VERSION1 
** - SQLM_DBMON_VERSION2 
** - SQLM_DBMON_VERSION5 
** - SQLM_DBMON_VERSION5_2 
** - SQLM_DBMON_VERSION6 
** - SQLM_DBMON_VERSION7 
** - SQLM_DBMON_VERSION8
** - SQLM_DBMON_VERSION9
** - SQLM_DBMON_VERSION9_5
** - SQLM_DBMON_VERSION9_7
** - SQLM_DBMON_VERSION9_7_1
** 
** Note:
** If SQLM_DBMON_VERSION1 is specified as the version, the APIs cannot be
** run remotely.
** 
** iNodeNumber 
** Input. The database partition server where the request is to be sent. Based 
** on this value, the request will be processed for the current database
** partition server, all database partition servers or a user specified
** database partition server. Valid values are: 
** - SQLM_CURRENT_NODE 
** - SQLM_ALL_NODES 
** - database partition number
** Note:
** For standalone instances the value, SQLM_CURRENT_NODE, must be used.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ResetMonitorData
{
   db2Uint32                           iResetAll; /* Reset value flag         */
   char                                *piDbAlias; /* Database alias          */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition                 */
} db2ResetMonitorData;

/* Monitor Reset Data General Interface Structure                             */
/******************************************************************************
** db2gResetMonitorData data structure
** db2gResetMonitorData data structure specific parameters
** 
** iDbAliasLength 
** Input. Specifies the length in bytes of the piDbAlias
** parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gResetMonitorData
{
   db2Uint32                           iResetAll; /* Reset value flag         */
   char                                *piDbAlias; /* Database alias          */
   db2Uint32                           iDbAliasLength; /* Length of DB alias  */
   db2Uint32                           iVersion; /* Snapshot version          */
   db2int32                            iNodeNumber; /* Target database        */
                                                 /* partition                 */
} db2gResetMonitorData;

/******************************************************************************
** db2ResetMonitor API
** Resets the database system monitor data of a specified database, or of
** all active databases, for the application issuing the call.
** 
** Scope
** 
** This API can either affect a given database partition on the instance,
** or all database partitions on the instance.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - sysmon
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** To reset the monitor switches for a remote instance (or a different
** local instance), it is necessary to first attach to that instance.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2ResetMonitor API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2ResetMonitorData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Each process (attachment) has its own private view of the monitor
** data. If one user resets, or turns off a monitor switch, other users
** are not affected. When an application first calls any database monitor
** function, it inherits the default switch settings from the database
** manager configuration file. These settings can be overridden with
** db2MonitorSwitches - Get/Update Monitor Switches.
** 
** If all active databases are reset, some database manager information
** is also reset to maintain the consistency of the data that is
** returned.
** 
** This API cannot be used to selectively reset specific data items or
** specific monitor groups. However, a specific group can be reset by
** turning its switch off, and then on, using db2MonitorSwitches -
** Get/Update Monitor Switches.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot size         */
  db2ResetMonitor (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gResetMonitor API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Get snapshot size         */
  db2gResetMonitor (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Restart Database Structure                                                 */
/******************************************************************************
** db2RestartDbStruct data structure
** db2RestartDbStruct data structure parameters
** 
** piDatabaseName
** Input. A pointer to a string containing the alias of the database
** that is to be restarted.
** 
** piUserId
** Input. A pointer to a string containing the user name of the application.
** May be NULL.
** 
** piPassword
** Input. A pointer to a string containing a password for the specified user
** name (if any). May be NULL.
** 
** piTablespaceNames
** Input. A pointer to a string containing a list of table space names to be
** dropped during the restart operation. May be NULL.
** 
** iOption
** Input. Valid values are:
** - DB2_DB_SUSPEND_NONE
** Performs normal crash recovery.
** - DB2_DB_RESUME_WRITE
** Required to perform crash recovery on a database that has I/O writes
** suspended.
** 
*******************************************************************************/
typedef struct db2RestartDbStruct
{
   char                                *piDatabaseName; /* Database name or   */
                                                 /* alias                     */
   char                                *piUserId; /* User Id                  */
   char                                *piPassword; /* Password               */
   char                                *piTablespaceNames; /* Droppending     */
                                                 /* tablespace name list      */
   db2int32                            iOption;  /* Suspend or resume         */
} db2RestartDbStruct;

/******************************************************************************
** db2DatabaseRestart API
** Restarts a database that has been abnormally terminated and left in an
** inconsistent state. At the successful completion of this API, the application
** remains connected to the database if the user has CONNECT privilege.
** 
** Scope
** 
** This API affects only the database partition server on which it is executed.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** This API establishes a database connection.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2DatabaseRestart API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParamStruct.
** 
** pParamStruct
** Input. A pointer to the db2RestartDbStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Call this API if an attempt to connect to a database returns an error
** message, indicating that the database must be restarted. This action
** occurs only if the previous session with this database terminated
** abnormally (due to power failure, for example).
** 
** At the completion of this API, a shared connection to the database
** is maintained if the user has CONNECT privilege, and an SQL warning is
** issued if any indoubt transactions exist. In this case, the database
** is still usable, but if the indoubt transactions are not resolved
** before the last connection to the database is dropped, another call
** to the API must be completed before the database can be used again.
** 
** In the case of circular logging, a database restart operation will
** fail if there is any problem with the table spaces, such as an I/O
** error, an unmounted file system, and so on. If losing such table
** spaces is not an issue, their names can be explicitly specified;
** this will put them into drop pending state, and the restart
** operation can complete successfully.
** 
** REXX API syntax
** 
** RESTART DATABASE database_alias [USER username USING password]
** 
** REXX API parameters
** 
** database_alias
** Alias of the database to be restarted.
** 
** username
** User name under which the database is to be restarted.
** 
** password
** Password used to authenticate the user name.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Database Restart          */
  db2DatabaseRestart (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2gRestartDbStruct data structure
** db2gRestartDbStruct data structure specific parameters
** 
** iDatabaseNameLen
** Input. Length in bytes of piDatabaseName parameter.
** 
** iUserIdLen
** Input. Length in bytes of piUserId parameter.
** 
** iPasswordLen
** Input. Length in bytes of piPassword parameter.
** 
** iTablespaceNamesLen
** Input. Length in bytes of piTablespaceNames parameter.
** 
*******************************************************************************/
typedef struct db2gRestartDbStruct
{
   db2Uint32                           iDatabaseNameLen; /* Length in bytes   */
                                                 /* of piDatabaseName         */
   db2Uint32                           iUserIdLen; /* Length in bytes of      */
                                                 /* piUserId                  */
   db2Uint32                           iPasswordLen; /* Length in bytes of    */
                                                 /* piPassword                */
   db2Uint32                           iTablespaceNamesLen; /* Length in      */
                                                 /* bytes of                  */
                                                 /* piTablespaceNames         */
   char                                *piDatabaseName; /* Database name or   */
                                                 /* alias                     */
   char                                *piUserId; /* User Id                  */
   char                                *piPassword; /* Password               */
   char                                *piTablespaceNames; /* Tablespace      */
                                                 /* name list                 */
} db2gRestartDbStruct;

/******************************************************************************
** db2gDatabaseRestart API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Generic Database Restart  */
  db2gDatabaseRestart (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Administrative Message Logging Defines/Structure                           */

#define DB2LOG_SEVERE_ERROR 1
#define DB2LOG_ERROR        2
#define DB2LOG_WARNING      3
#define DB2LOG_INFORMATION  4

#define STRING_MSG          1
#define BINARY_MSG          2

/******************************************************************************
** db2AdminMsgWriteStruct data structure
** db2AdminMsgWriteStruct data structure parameters
** 
** iMsgType
** Input. Specify the type of data to be logged. Valid values are BINARY_MSG for
** binary data, and STRING_MSG for string data.
** 
** iComponent
** Input. Specify zero.
** 
** iFunction
** Input. Specify zero.
** 
** iProbeID
** Input. Specify the numeric probe point. Numeric probe point is a unique
** internal identifier that is used to locate the point in the source code that
** reported the message.
** 
** piData_title
** Input. A pointer to the title string describing the data to be logged. Can be
** set to NULL if a title is not needed.
** 
** piData
** Input. A pointer to the data to be logged. Can be set to NULL if data logging
** is not needed.
** 
** iDataLen
** Input. The number of bytes of binary data to be used for logging if iMsgType
** is BINARY_MSG. Not used if iMsgType is STRING_MSG.
** 
** iError_type
** Input. Valid values are:
** - DB2LOG_SEVERE_ERROR      (1) - Severe error has occurred
** - DB2LOG_ERROR             (2) - Error has occurred
** - DB2LOG_WARNING           (3) - Warning has occurred
** - DB2LOG_INFORMATION       (4) - Informational
** 
*******************************************************************************/
typedef struct db2AdminMsgWriteStruct
{
   db2Uint32                           iMsgType; /* Message Type              */
   db2Uint32                           iComponent; /* Component id            */
   db2Uint32                           iFunction; /* Function id              */
   db2Uint32                           iProbeID; /* Numeric probe point       */
   char                                *piData_title; /* Title describing     */
                                                 /* data                      */
   void                                *piData;  /* Data                      */
   db2Uint32                           iDataLen; /* Length of binary data     */
   db2Uint32                           iError_type; /* Severity of message    */
} db2AdminMsgWriteStruct;

/* Administrative Message Logging                                             */

/******************************************************************************
** db2AdminMsgWrite API
** Provides a mechanism for users and Replication to write information to the
** db2diag.log, and the administration notification log.
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
** db2ApiDf.h
** 
** db2AdminMsgWrite API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2AdminMsgWriteStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** This API will log to the administration notification log only if the
** specified error type is less than or equal to the value of the
** notifylevel database manager configuration parameter. It will log
** to db2diag.log only if the specified error type is less than or equal
** to the value of the diaglevel database manager configuration
** parameter. However, all information written to the administration
** notification log is duplicated in the db2diag.log unless the diaglevel
** database manager configuration parameter is set to zero.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Administrative Message    */
                                                 /* Logging                   */
  db2AdminMsgWrite (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2LdapProtocolInfo data structure
** db2LdapProtocolInfo data structure parameters
** 
** iType
** Input. Specify the protocol type that this server supports. If the server
** supports more than one protocol, multiple registrations (each with a
** different node name and protocol type) are required. Valid values are:
** - SQL_PROTOCOL_TCPIP  - For TCP/IP support
** - SQL_PROTOCOL_SOCKS  - For TCP/IP with socket security
** - SQL_PROTOCOL_NPIPE  - For Windows Named Pipe support
** 
** piHostName
** Input. Specify the TCP/IP host name or the IP address.
** 
** piServiceName
** Input. Specify the TCP/IP service name or port number.
** 
** piNetbiosName
** Input. Specify the NetBIOS workstation name. The NetBIOS name must
** be specified for NetBIOS support. 
** 
** piNetworkID
** Input. Specify the network ID. The network ID must be specified for
** APPC/APPN support.
** 
** piPartnerLU
** Input. Specify the partner LU name for the DB2 server machine. The
** partner LU must be specified for APPC/APPN support.
** 
** piTPName
** Input. Specify the transaction program name. The transaction program
** name must be specified for APPC/APPN support.
** 
** piMode
** Input. Specify the mode name. The mode must be specified for
** APPC/APPN support.
** 
** iSecurityType
** Input. Specify the APPC security level. Valid values are:
** - SQL_CPIC_SECURITY_NONE (default)
** - SQL_CPIC_SECURITY_SAME
** - SQL_CPIC_SECURITY_PROGRAM
** 
** piLanAdapterAddress
** Input. Specify the network adapter address. This parameter is only
** required for APPC support. For APPN, this parameter can be set to
** NULL.
** 
** piChangePasswordLU
** Input. Specify the name of the partner LU to use when changing the
** password for the host database server.
** 
** piIpxAddress
** Input. Specify the complete IPX address. The IPX address must be
** specified for IPX/SPX support.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapProtocolInfo
{
   char                                iType;
   char                                *piHostName;
   char                                *piServiceName;
   char                                *piNetbiosName;
   char                                *piNetworkId;
   char                                *piPartnerLU;
   char                                *piTPName;
   char                                *piMode;
   unsigned short                      iSecurityType;
   char                                *piLanAdapterAddress;
   char                                *piChangePasswordLU;
   char                                *piIpxAddress;
} db2LdapProtocolInfo;

/******************************************************************************
** db2LdapRegisterStruct data structure
** db2LdapRegisterStruct data structure parameters
** 
** piNodeName
** Input. Specify a short name (less than 8 characters) that represents the
** DB2 server in LDAP.
** 
** piComputer
** Input. Specify the name of the computer on which the DB2 server
** resides. The computer name value must be the same as the value
** specified when adding the server machine to LDAP. On Windows, this
** is the Windows computer name. On UNIX based systems, this is the TCP/IP
** host name. Specify NULL to register the DB2 server on the local
** computer.
** 
** piInstance
** Input. Specify the instance name of the DB2 server. The instance name
** must be specified if the computer name is specified to register a remote
** server. Specify NULL to register the current instance (as defined by the
** DB2SYSTEM environment variable).
** 
** iNodeType
** Input. Specify the database partition type for the database server. Valid values are:
** - SQLF_NT_SERVER
** - SQLF_NT_MPP
** - SQLF_NT_DCS
** 
** iOsType
** Input. Specifies the operating system type of the server machine.
** If an operating system type is not specified, the local operating
** system type will be used for a local server and no operating 
** system type will be used for a remote server.
** 
** iProtocol
** Input. Specify the protocol information in the db2LdapProtocolInfo
** structure.
** 
** piComment
** Input. Describes the DB2 server. Any comment that helps to describe the
** server registered in the network directory can be entered. Maximum
** length is 30 characters. A carriage return or a line feed character is not
** permitted.
** 
** piBindDN
** Input. Specify the user's LDAP distinguished name (DN). The LDAP user
** DN must have sufficient authority to create and update the object in the
** LDAP directory. If the user's LDAP DN is not specified, the credentials of
** the current logon user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapRegisterStruct
{
   char                                *piNodeName;
   char                                *piComputer;
   char                                *piInstance;
   unsigned short                      iNodeType;
   unsigned short                      iOsType;
   db2LdapProtocolInfo                 iProtocol;
   char                                *piComment;
   char                                *piBindDN;
   char                                *piPassword;
} db2LdapRegisterStruct;

/******************************************************************************
** db2LdapRegister API
** Registers the DB2 server in LDAP (Lightweight Directory Access Protocol).
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
** db2ApiDf.h
** 
** db2LdapRegister API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParamStruct.
** 
** pParamStruct
** Input. A pointer to the db2LdapRegisterStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Register the DB2 server once for each protocol that the server
** supports each time specifying a unique node name.
** 
** If any protocol configuration parameter is specified when registering a
** DB2 server locally, it will override the value specified in the
** database manager configuration file.
** 
** Only a remote DB2 server can be registered in LDAP. The computer name
** and the instance name of the remote server must be specified, along
** with the protocol communication for the remote server.
** 
** When registering a host database server, a value of SQLF_NT_DCS must
** be specified for the iNodeType parameter.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Register DB2 server       */
  db2LdapRegister (
   db2Uint32 versionNumber,                      /* Version Number            */
   void * pParmStruct,                           /* Register Info             */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2LdapUpdateStruct data structure
** db2LdapUpdateStruct data structure parameters
** 
** piNodeName
** Input. Specify the node name that represents the DB2 server in LDAP.
** 
** piComment
** Input. Specify a new description for the DB2 server. Maximum length is
** 30 characters. A carriage return or a line feed character is not permitted.
** 
** iNodeType
** Input. Specify a new node type. Valid values are:
** - SQLF_NT_SERVER
** - SQLF_NT_MPP
** - SQLF_NT_DCS
** - SQL_PARM_UNCHANGE
** 
** iProtocol
** Input. Specify the updated protocol information in the
** db2LdapProtocolInfo structure.
** 
** piBindDN
** Input. Specify the user's LDAP distinguished name (DN). The LDAP user
** DN must have sufficient authority to create and update the object in the
** LDAP directory. If the user's LDAP DN is not specified, the credentials of
** the current logon user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapUpdateStruct
{
   char                                *piNodeName;
   char                                *piComment;
   unsigned short                      iNodeType;
   db2LdapProtocolInfo                 iProtocol;
   char                                *piBindDN;
   char                                *piPassword;
} db2LdapUpdateStruct;

/******************************************************************************
** db2LdapUpdate API
** Updates the communication protocol information for the DB2 server in LDAP
** (Lightweight Directory Access Protocol).
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
** db2ApiDf.h
** 
** db2LdapUpdate API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure
** passed in as the second parameter, pParamStruct.
** 
** pParamStruct
** Input. A pointer to the db2LdapUpdateStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Update DB2 server         */
  db2LdapUpdate (
   db2Uint32 versionNumber,                      /* Version Number            */
   void * pParmStruct,                           /* Update Info               */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Update LDAP Alternate Server Parameter Structure                           */
/******************************************************************************
** db2LdapUpdateAltServerStruct data structure
** db2LdapUpdateAltServerStruct data structure parameters
** 
** piDbAlias
** Input. A string containing an alias for the database to be updated.
** 
** piNode
** Input. A string containing the alternate node name. This node name must
** exist in LDAP.
** 
** piGWNode
** Input. A string containing the alternate gateway node name. This node
** name must exist in LDAP. This is used by the runtime client to connect
** to the host via the gateway.
** 
** piBindDN
** Input. Specifies the user's LDAP distinguished name (DN). The user's
** LDAP DN must have sufficient authority to create and update objects in
** the LDAP directory. If the user's LDAP DN is not specified, the
** credentials of the current user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapUpdateAltServerStruct
{
   char                                *piDbAlias; /* Input: database alias   */
   char                                *piNode;  /* Input: node name          */
   char                                *piGWNode; /* Input: gateway node      */
                                                 /* name                      */
   char                                *piBindDN; /* Input: bind distinguish  */
                                                 /* name                      */
   char                                *piPassword; /* input: bind password   */
} db2LdapUpdateAltServerStruct;

/* Update LDAP Alternate Server API                                           */
/******************************************************************************
** db2LdapUpdateAlternateServerForDB API
** Updates the alternate server for a database in Lightweight Directory Access
** Protocol (LDAP).
** 
** Authorization
** 
** Read/write access to the LDAP server.
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** db2LdapUpdateAlternateServerForDB API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure
** passed as the second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2LdapUpdateAltServerStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Update LDAP Alternate     */
                                                 /* Server                    */
  db2LdapUpdateAlternateServerForDB (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2LdapDeregisterStruct data structure
** db2LdapDeregisterStruct data structure parameters
** 
** piNodeName
** Input. Specify a short name that represents the DB2 server in LDAP.
** 
** piBindDN
** Input. Specify the user's LDAP distinguished name (DN). The LDAP user
** DN must have sufficient authority to delete the object from the LDAP
** directory. If the user's LDAP DN is not specified, the credentials of the
** current logon user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapDeregisterStruct
{
   char                                *piNodeName;
   char                                *piBindDN;
   char                                *piPassword;
} db2LdapDeregisterStruct;

/******************************************************************************
** db2LdapDeregister API
** Deregisters the DB2 server from LDAP (Lightweight Directory Access Protocol).
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
** db2ApiDf.h
** 
** db2LdapDeregister API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParamStruct.
** 
** pParamStruct
** Input. A pointer to the db2LdapDeregisterStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Deregister DB2 server     */
  db2LdapDeregister (
   db2Uint32 versionNumber,                      /* Version Number            */
   void * pParmStruct,                           /* DeRegister Info           */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2LdapCatalogNodeStruct data structure
** db2LdapCatalogNodeStruct data structure parameters
** 
** piAlias
** Input. Specify a new alias to be used as an alternate name for the node
** entry.
** 
** piNodeName
** Input. Specify a node name that represents the DB2 server in LDAP.
** 
** piBindDN
** Input. Specify the user's LDAP distinguished name (DN). The LDAP user
** DN must have sufficient authority to create and update the object in the
** LDAP directory. If the user's LDAP DN is not specified, the credentials of
** the current logon user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapCatalogNodeStruct
{
   char                                *piAlias;
   char                                *piNodeName;
   char                                *piBindDN;
   char                                *piPassword;
} db2LdapCatalogNodeStruct;

/******************************************************************************
** db2LdapCatalogNode API
** Specifies an alternate name for the node entry in LDAP (Lightweight Directory
** Access Protocol), or a different protocol type for connecting to the database
** server.
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
** db2ApiDf.h
** 
** db2LdapCatalogNode API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure
** passed in as the second parameter, pParamStruct.
** 
** pParamStruct
** Input. A pointer to the db2LdapCatalogNodeStruct structure. 
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Catalog LDAP node         */
  db2LdapCatalogNode (
   db2Uint32 versionNumber,                      /* Version Number            */
   void * pParmStruct,                           /* Catalog Node Info         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2LdapUncatalogNodeStruct data structure
** db2LdapUncatalogNodeStruct data structure parameters
** 
** piAlias
** Input. Specify the alias of the node to uncatalog from LDAP.
** 
** piBindDN
** Input. Specify the user's LDAP distinguished name (DN). The LDAP user
** DN must have sufficient authority to delete the object from the LDAP
** directory. If the user's LDAP DN is not specified, the credentials of the
** current logon user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapUncatalogNodeStruct
{
   char                                *piAlias;
   char                                *piBindDN;
   char                                *piPassword;
} db2LdapUncatalogNodeStruct;

/******************************************************************************
** db2LdapUncatalogNode API
** Removes a node entry from LDAP (Lightweight Directory Access Protocol).
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
** db2ApiDf.h
** 
** db2LdapUncatalogNode API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParamStruct
** Input. A pointer to the db2LdapUncatalogNodeStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Uncatalog LDAP node       */
  db2LdapUncatalogNode (
   db2Uint32 versionNumber,                      /* Version Number            */
   void * pParmStruct,                           /* UnCatalog Node Info       */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2LdapCatalogDatabaseStruct data structure
** db2LdapCatalogDatabaseStruct data structure parameters
** 
** piAlias
** Input. Specify an alias to be used as an alternate name for the database
** being cataloged. If an alias is not specified, the database manager uses
** the database name as the alias name.
** 
** piDatabaseName
** Input. Specify the name of the database to catalog. This parameter is
** mandatory.
** 
** piComment
** Input. Describes the DB2 server. Any comment that helps to describe the
** server registered in the network directory can be entered. Maximum
** length is 30 characters. A carriage return or a line feed character is not
** permitted.
** 
** piNodeName
** Input. Specify the database partition name of the database server on which the
** database resides. This parameter is required if the database resides on a
** remote database server.
** 
** piGWNodename
** Input. Specify the node name of the DB2 Connect gateway server. If the
** database server node type is DCS (reserved for host database servers),
** and the client does not have DB2 Connect installed, the client will
** connect to the DB2 Connect gateway server.
** 
** piParameters
** Input. Specify a parameter string that is to be passed to the application
** requester (AR). Authentication DCE is not supported.
** 
** piARLibrary
** Input. Specify the name of the application requester (AR) library.
** 
** iAuthentication
** Input. Specifying an authentication type can result in a performance
** benefit.
** 
** piDCEPrincipalName
** Input. Specify the fully qualified DCE principal name for the target server.
** 
** piBindDN
** Input. Specify the user's LDAP distinguished name (DN). The LDAP user
** DN must have sufficient authority to create and update the object in the
** LDAP directory. If the user's LDAP DN is not specified, the credentials of
** the current logon user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapCatalogDatabaseStruct
{
   char                                *piAlias;
   char                                *piDatabaseName;
   char                                *piComment;
   char                                *piNodeName;
   char                                *piGWNodeName;
   char                                *piParameters;
   char                                *piARLibrary;
   unsigned short                      iAuthentication;
   char                                *piDCEPrincipalName;
   char                                *piBindDN;
   char                                *piPassword;
} db2LdapCatalogDatabaseStruct;

/******************************************************************************
** db2LdapCatalogDatabase API
** Catalogs a database entry in LDAP (Lightweight Directory Access Protocol).
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
** db2ApiDf.h
** 
** db2LdapCatalogDatabase API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParamStruct.
** 
** pParamStruct
** Input. A pointer to the db2LdapCatalogDatabaseStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** A database may need to be manually registered or cataloged in LDAP if: 
** 
** - The database server does not support LDAP. In this case, the administrator
** needs to manually register each database in LDAP to allow clients that
** support LDAP to access the database without having to catalog the
** database locally on each client machine.
** 
** - The application wants to use a different name to connect to the database.
** In this case, the administrator needs to catalog the database using a
** different alias name.
** 
** - During CREATE DATABASE IN LDAP, the database name already exists
** in LDAP. The database is still created on the local machine (and can be
** accessed by local applications), but the existing entry in LDAP will not be
** modified to reflect the new database. In this case, the administrator can:
** -- Remove the existing database entry from LDAP, and manually
** register the new database in LDAP.
** -- Register the new database in LDAP using a different alias name.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Catalog LDAP database     */
  db2LdapCatalogDatabase (
   db2Uint32 versionNumber,                      /* Version Number            */
   void * pParmStruct,                           /* Catalog Database Info     */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/******************************************************************************
** db2LdapUncatalogDatabaseStruct data structure
** db2LdapUncatalogDatabaseStruct data structure parameters
** 
** piAlias
** Input. Specify an alias name for the database entry. This parameter is
** mandatory.
** 
** piBindDN
** Input. Specify the user's LDAP distinguished name (DN). The LDAP user
** DN must have sufficient authority to delete the object from the LDAP
** directory. If the user's LDAP DN is not specified, the credentials of the
** current logon user will be used.
** 
** piPassword
** Input. Account password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2LdapUncatalogDatabaseStruct
{
   char                                *piAlias;
   char                                *piBindDN;
   char                                *piPassword;
} db2LdapUncatalogDatabaseStruct;

/******************************************************************************
** db2LdapUncatalogDatabase API
** Removes a database entry from LDAP (Lightweight Directory Access Protocol).
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
** db2ApiDf.h
** 
** db2LdapUncatalogDatabase API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParamStruct.
** 
** pParamStruct
** Input. A pointer to the db2LdapUncatalogDatabaseStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Uncatalog LDAP database   */
  db2LdapUncatalogDatabase (
   db2Uint32 versionNumber,                      /* Version Number            */
   void * pParmStruct,                           /* UnCatalog Database Info   */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Suspend I/O Database Structure                                             */
/******************************************************************************
** db2SetWriteDbStruct data structure
** db2SetWriteDbStruct data structure parameters
** 
** iOption
** Input. Specifies the action. Valid values are: 
** - DB2_DB_SUSPEND_WRITE 
** Suspends I/O write to disk. 
** - DB2_DB_RESUME_WRITE 
** Resumes I/O write to disk. 
** 
** piTablespaceNames 
** Input. Reserved for future use. 
** 
*******************************************************************************/
typedef struct db2SetWriteDbStruct
{
   db2int32                            iOption;  /* Suspend or resume         */
   char                                *piTablespaceNames; /* Suspending      */
                                                 /* tablespace name list:     */
                                                 /* empty for all             */
                                                 /* Tablespaces               */
} db2SetWriteDbStruct;

/******************************************************************************
** db2SetWriteForDB API
** Sets the database to be I/O write suspended, or resumes I/O writes to
** disk. I/O writes must be suspended for a database before a split
** mirror can be taken. To avoid potential problems, keep the same
** connection to do the write suspension and resumption.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2SetWriteForDB API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2SetWriteDbStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Set Write Suspend/Resume  */
                                                 /* For DB                    */
  db2SetWriteForDB (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */


/* Set Stogroup Paths Structure                                               */
/******************************************************************************
** db2StoragePath
*******************************************************************************/
typedef SQL_STRUCTURE db2StoragePath
{
  char       path[SQL_STORAGEPATH_SZ + 1];    /* Storage path                 */
} db2StoragePath;

/******************************************************************************
** db2StoragePathList data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2StoragePathList
{
  struct db2StoragePath *list;                /* List of storage paths        */
  db2Uint32  numPaths;                        /* Number of paths in the list  */
} db2StoragePathList;

/******************************************************************************
** db2SetStogroupPaths data structure
** db2SetStogroupPaths data structure parameters
** 
** iStogroupName
** Input. Specifies the storage group name.
** 
** iPaths
** Input. List of storage group paths to be used by the storage group.
** 
** iNumPaths
** Input. Number of paths in the piPath list.
** 
*******************************************************************************/
typedef struct db2SetStogroupPathsStruct
{
  char       iStogroupName[SQL_MAX_IDENT + 1]; /* Storage group name          */
  struct db2StoragePathList iPaths;           /* List of storage group paths  */
} db2SetStogroupPathsStruct;

/******************************************************************************
** db2SetStogroupPaths API
** 
** This API facilitates the provision of a redirected restore, in which the
** user is restoring a database, and a different set of storage group
** containers is desired or required.
** 
** Use this API during a database redirected restore operation, when all
** table spaces are in storage definition pending or storage definition
** allowed states, immediately prior to the restoration of database pages.
** 
** Authorization
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** Database
** 
** API include file
** db2ApiDf.h
** 
** db2SetStogroupPaths API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as
**        the second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2SetStogroupPathsStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                         /* Set Storage Group Paths      */
  db2SetStogroupPaths (
  db2Uint32 versionNumber,                    /* Database version number      */
  void * pParmStruct,                         /* In/out parameters            */
  struct sqlca * pSqlca);                     /* SQLCA                        */


/* Inspect Database Definitions                                               */

/* Inspect API structure                                                      */
/******************************************************************************
** db2InspectStruct data structure
** db2InspectStruct data structure parameters
** 
** piTablespaceName
** Input. A string containing the table space name. The table space must be
** identified for operations on a table space. If the pointer is NULL, the table
** space ID value is used as input.
** 
** piTableName
** Input. A string containing the table name. The table must be identified for
** operations on a table or a table object. If the pointer is NULL, the table
** space ID and table object ID values are used as input.
** 
** piSchemaName
** Input. A string containing the schema name.
** 
** piResultsName
** Input. A string containing the name for results output file. This input must
** be provided. The file will be written out to the diagnostic data directory
** path.
** 
** piDataFileName
** Input. Reserved for future use. Must be set to NULL.
** 
** piNodeList
** Input. A pointer to an array of database partition numbers on which to
** perform the operation.
** 
** iAction
** Input. Specifies the inspect action. Valid values are:
** - DB2INSPECT_ACT_CHECK_DB
** Inspect the entire database.
** - DB2INSPECT_ACT_CHECK_TABSPACE
** Inspect a table space.
** - DB2INSPECT_ACT_CHECK_TABLE
** Inspect a table.
** 
** iTablespaceID
** Input. Specifies the table space ID. If the table space must be identified,
** the table space ID value is used as input if the pointer to table space
** name is NULL.
** 
** iObjectID
** Input. Specifies the object ID. If the table must be identified, the
** object ID value is used as input if the pointer to table name is NULL.
** 
** iBeginCheckOption
** Input. Option for check database or check table space operation to
** indicate where operation should begin. It must be set to zero to begin
** from the normal start. Values are:
** 
** - DB2INSPECT_BEGIN_TSPID
** Use this value for check database to begin with the table space
** specified by the table space ID field, the table space ID must be set.
** 
** - DB2INSPECT_BEGIN_TSPID_OBJID
** Use this value for check database to begin with the table specified by
** the table space ID and object ID field. To use this option, the table
** space ID and object ID must be set.
** 
** - DB2INSPECT_BEGIN_OBJID
** Use this value for check table space to begin with the table specified
** by the object ID field, the object ID must be set.
** 
** iLimitErrorReported
** Input. Specifies the reporting limit of the number of pages in error for an
** object. Specify the number you want to use as the limit value or specify
** one the following values:
** - DB2INSPECT_LIMIT_ERROR_DEFAULT
** Use this value to specify that the maximum number of pages in error to
** be reported is the extent size of the object.
** - DB2INSPECT_LIMIT_ERROR_ALL
** Use this value to report all pages in error.
** 
** iObjectErrorState
** Input. Specifies whether to scan objects in error state. Valid values are:
** - DB2INSPECT_ERROR_STATE_NORMAL
** Process object only in normal state.
** - DB2INSPECT_ERROR_STATE_ALL
** Process all objects, including objects in error state.
** 
** iKeepResultfile
** Input. Specifies result file retention. Valid values are:
** - DB2INSPECT_RESFILE_CLEANUP
** If errors are reported, the result output file will be retained. Otherwise,
** the result file will be removed at the end of the operation.
** - DB2INSPECT_RESFILE_KEEP_ALWAYS
** The result output file will be retained.
** 
** iAllNodeFlag
** Input. Indicates whether the operation is to be applied to all database
** partitions defined in db2nodes.cfg. Valid values are:
** - DB2_NODE_LIST
** Apply to all database partitionss in a database partition list that is passed in pNodeList.
** - DB2_ALL_NODES
** Apply to all database partitionss. pNodeList should be NULL. This is the default value.
** - DB2_ALL_EXCEPT
** Apply to all database partitionss except those in a database partition list that is passed in
** pNodeList.
** 
** iNumNodes
** Input. Specifies the number of database partitions in the pNodeList array.
** 
** iLevelObjectData
** Input. Specifies processing level for data object. Valid values are:
** - DB2INSPECT_LEVEL_NORMAL
** Level is normal.
** - DB2INSPECT_LEVEL_LOW
** Level is low.
** - DB2INSPECT_LEVEL_NONE
** Level is none.
** 
** iLevelObjectIndex
** Input. Specifies processing level for index object. Valid values are:
** - DB2INSPECT_LEVEL_NORMAL
** Level is normal.
** - DB2INSPECT_LEVEL_LOW
** Level is low.
** - DB2INSPECT_LEVEL_NONE
** Level is none.
** 
** iLevelObjectLong
** Input. Specifies processing level for long object. Valid values are:
** - DB2INSPECT_LEVEL_NORMAL
** Level is normal.
** - DB2INSPECT_LEVEL_LOW
** Level is low.
** - DB2INSPECT_LEVEL_NONE
** Level is none.
** 
** iLevelObjectLOB
** Input. Specifies processing level for LOB object. Valid values are:
** - DB2INSPECT_LEVEL_NORMAL
** Level is normal.
** - DB2INSPECT_LEVEL_LOW
** Level is low.
** - DB2INSPECT_LEVEL_NONE
** Level is none.
** 
** iLevelObjectBlkMap
** Input. Specifies processing level for block map object. Valid values are:
** - DB2INSPECT_LEVEL_NORMAL
** Level is normal.
** - DB2INSPECT_LEVEL_LOW
** Level is low.
** - DB2INSPECT_LEVEL_NONE
** Level is none.
** 
** iLevelExtentMap
** Input. Specifies processing level for extent map. Valid values are:
** - DB2INSPECT_LEVEL_NORMAL
** Level is normal.
** - DB2INSPECT_LEVEL_LOW
** Level is low.
** - DB2INSPECT_LEVEL_NONE
** Level is none.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2InspectStruct
{
   char                                *piTablespaceName; /* Tablespace       */
                                                 /* name; null terminated     */
   char                                *piTableName; /* Table name; null      */
                                                 /* terminated                */
   char                                *piSchemaName; /* Schema name; null    */
                                                 /* terminated                */
   char                                *piResultsName; /* Results Output      */
                                                 /* file name; null           */
                                                 /* terminated                */
   char                                *piDataFileName; /* Data file name;    */
                                                 /* null terminated           */
   SQL_PDB_NODE_TYPE                   *piNodeList; /* Array of database      */
                                                 /* partitions                */
   db2Uint32                           iAction;  /* Action                    */
   db2int32                            iTablespaceID; /* Tablespace ID        */
   db2int32                            iObjectID; /* Object ID                */
   db2Uint32                           iFirstPage; /* Page number of first    */
                                                 /* page                      */
   db2Uint32                           iNumberOfPages; /* Number of pages     */
   db2Uint32                           iFormatType; /* Format type            */
   db2Uint32                           iOptions; /* Options                   */
   db2Uint32                           iBeginCheckOption; /* Begin checking   */
                                                 /* option                    */
   db2int32                            iLimitErrorReported; /* Number of      */
                                                 /* pages in error in object  */
                                                 /* to limit reporting of     */
   db2Uint16                           iObjectErrorState; /* Object error     */
                                                 /* state option              */
   db2Uint16                           iCatalogToTablespace; /* Catalog to    */
                                                 /* tablespace consistency    */
                                                 /* option                    */
   db2Uint16                           iKeepResultfile; /* Keep result file   */
   db2Uint16                           iAllNodeFlag; /* all database          */
                                                 /* partitions flag           */
   db2Uint16                           iNumNodes; /* Number of database       */
                                                 /* partitionss               */
   db2Uint16                           iLevelObjectData; /* Processing level  */
                                                 /* for Data object           */
   db2Uint16                           iLevelObjectIndex; /* Processing       */
                                                 /* level for Index object    */
   db2Uint16                           iLevelObjectLong; /* Processing level  */
                                                 /* for Long object           */
   db2Uint16                           iLevelObjectLOB; /* Processing level   */
                                                 /* for LOB object            */
   db2Uint16                           iLevelObjectBlkMap; /* Processing      */
                                                 /* level for Block map       */
                                                 /* object                    */
   db2Uint16                           iLevelExtentMap; /* Processing level   */
                                                 /* for Extent map            */
   db2Uint16                           iLevelObjectXML; /* Processing level   */
                                                 /* for XML column data       */
   db2Uint32                           iLevelCrossObject; /* Processing       */
                                                 /* level for cross object    */
                                                 /* checking                  */
   db2Uint16                           iLevelObjectCOL; /* Processing level   */
                                                 /* for column-organized      */
                                                 /* object                    */
} db2InspectStruct;


/* Generic Inspect API structure                                              */
/******************************************************************************
** db2gInspectStruct data structure
** db2gInspectStruct data structure specific parameters
** 
** iResultsNameLength
** Input. The string length of the results file name.
** 
** iDataFileNameLength
** Input. The string length of the data output file name.
** 
** iTablespaceNameLength
** Input. The string length of the table space name.
** 
** iTableNameLength
** Input. The string length of the table name.
** 
** iSchemaNameLength
** Input. The string length of the schema name.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gInspectStruct
{
   char                                *piTablespaceName; /* Tablespace name  */
   char                                *piTableName; /* Table name            */
   char                                *piSchemaName; /* Schema name          */
   char                                *piResultsName; /* Results Output      */
                                                 /* file name                 */
   char                                *piDataFileName; /* Data file name     */
   SQL_PDB_NODE_TYPE                   *piNodeList; /* Array of database      */
                                                 /* partition numbers         */
   db2Uint32                           iResultsNameLength; /* Results Output  */
                                                 /* file name length          */
   db2Uint32                           iDataFileNameLength; /* Data file      */
                                                 /* name length               */
   db2Uint32                           iTablespaceNameLength; /* Tablespace   */
                                                 /* name length               */
   db2Uint32                           iTableNameLength; /* Table name        */
                                                 /* length                    */
   db2Uint32                           iSchemaNameLength; /* Schema name      */
                                                 /* length                    */
   db2Uint32                           iAction;  /* Action                    */
   db2int32                            iTablespaceID; /* Tablespace ID        */
   db2int32                            iObjectID; /* Object ID                */
   db2Uint32                           iFirstPage; /* Page number of first    */
                                                 /* page                      */
   db2Uint32                           iNumberOfPages; /* Number of pages     */
   db2Uint32                           iFormatType; /* Format type            */
   db2Uint32                           iOptions; /* Options                   */
   db2Uint32                           iBeginCheckOption; /* Begin checking   */
                                                 /* option                    */
   db2int32                            iLimitErrorReported; /* Number of      */
                                                 /* pages in error in object  */
                                                 /* to limit reporting of     */
   db2Uint16                           iObjectErrorState; /* Object error     */
                                                 /* state option              */
   db2Uint16                           iCatalogToTablespace; /* Catalog to    */
                                                 /* tablespace consistency    */
                                                 /* option                    */
   db2Uint16                           iKeepResultfile; /* Keep result file   */
   db2Uint16                           iAllNodeFlag; /* all database          */
                                                 /* partitions flag           */
   db2Uint16                           iNumNodes; /* Number of database       */
                                                 /* partitions                */
   db2Uint16                           iLevelObjectData; /* Processing level  */
                                                 /* for Data object           */
   db2Uint16                           iLevelObjectIndex; /* Processing       */
                                                 /* level for Index object    */
   db2Uint16                           iLevelObjectLong; /* Processing level  */
                                                 /* for Long object           */
   db2Uint16                           iLevelObjectLOB; /* Processing level   */
                                                 /* for LOB object            */
   db2Uint16                           iLevelObjectBlkMap; /* Processing      */
                                                 /* level for Block map       */
                                                 /* object                    */
   db2Uint16                           iLevelExtentMap; /* Processing level   */
                                                 /* for Extent map            */
   db2Uint16                           iLevelObjectXML; /* Processing level   */
                                                 /* for XML column data       */
   db2Uint32                           iLevelCrossObject; /* Processing       */
                                                 /* level for cross object    */
                                                 /* checking                  */
   db2Uint16                           iLevelObjectCOL; /* Processing level   */
                                                 /* for column-organized      */
                                                 /* object                    */
} db2gInspectStruct;


/* Values for db2Inspect - Action constants                                   */
#define DB2INSPECT_ACTION_CHECK        1
#define DB2INSPECT_ACTION_FORMAT       65536
#define DB2INSPECT_ACTION_ROWCMPEST    131072

/* Values for db2Inspect - iAction                                            */
/* DB2INSPECT_ACT_CHECK_RESTART   - Inspect check restart                     */
/* DB2INSPECT_ACT_CHECK_DB        - Inspect DB                                */
/* DB2INSPECT_ACT_CHECK_TABSPACE  - Inspect tablespace                        */
/* DB2INSPECT_ACT_CHECK_TABLE     - Inspect table                             */
/* DB2INSPECT_ACT_CHECK_DATA      - Inspect data object                       */
/* DB2INSPECT_ACT_CHECK_INDEX     - Inspect index object                      */
/* DB2INSPECT_ACT_CHECK_BLOCKMAP  - Inspect block map object                  */
/* DB2INSPECT_ACT_CHECK_XML       - Inspect XML object                        */
/* DB2INSPECT_ACT_CHECK_XOBJ      - Inspect cross object                      */
/* DB2INSPECT_ACT_CHECK_COL       - Inspect column-organized object           */
/* DB2INSPECT_ACT_FORMAT_PAGE     - Format page in tablespace                 */
/* DB2INSPECT_ACT_FORMAT_EXT_MAP  - Format extent map                         */
/* DB2INSPECT_ACT_FORMAT_DATA     - Format data page                          */
/* DB2INSPECT_ACT_FORMAT_INDEX    - Format index page                         */
/* DB2INSPECT_ACT_FORMAT_BLOCKMAP - Format block map page                     */
/* DB2INSPECT_ACT_FORMAT_XML      - Format XML object                         */
#define DB2INSPECT_ACT_CHECK_RESTART   (DB2INSPECT_ACTION_CHECK+1) 
#define DB2INSPECT_ACT_CHECK_DB        (DB2INSPECT_ACTION_CHECK+2) 
#define DB2INSPECT_ACT_CHECK_TABSPACE  (DB2INSPECT_ACTION_CHECK+3) 
#define DB2INSPECT_ACT_CHECK_TABLE     (DB2INSPECT_ACTION_CHECK+4) 
#define DB2INSPECT_ACT_CHECK_DATA      (DB2INSPECT_ACTION_CHECK+5) 
#define DB2INSPECT_ACT_CHECK_INDEX     (DB2INSPECT_ACTION_CHECK+6) 
#define DB2INSPECT_ACT_CHECK_BLOCKMAP  (DB2INSPECT_ACTION_CHECK+7) 
#define DB2INSPECT_ACT_CHECK_XML       (DB2INSPECT_ACTION_CHECK+8) 
#define DB2INSPECT_ACT_CHECK_XOBJ      (DB2INSPECT_ACTION_CHECK+9) 
#define DB2INSPECT_ACT_CHECK_COL       (DB2INSPECT_ACTION_CHECK+10) 
#define DB2INSPECT_ACT_FORMAT_PAGE     (DB2INSPECT_ACTION_FORMAT+1) 
#define DB2INSPECT_ACT_FORMAT_EXT_MAP  (DB2INSPECT_ACTION_FORMAT+2) 
#define DB2INSPECT_ACT_FORMAT_DATA     (DB2INSPECT_ACTION_FORMAT+3) 
#define DB2INSPECT_ACT_FORMAT_INDEX    (DB2INSPECT_ACTION_FORMAT+4) 
#define DB2INSPECT_ACT_FORMAT_BLOCKMAP (DB2INSPECT_ACTION_FORMAT+5) 
#define DB2INSPECT_ACT_FORMAT_XML      (DB2INSPECT_ACTION_FORMAT+6) 
#define DB2INSPECT_ACT_FORMAT_07       (DB2INSPECT_ACTION_FORMAT+7) 
#define DB2INSPECT_ACT_FORMAT_08       (DB2INSPECT_ACTION_FORMAT+8) 
#define DB2INSPECT_ACT_FORMAT_09       (DB2INSPECT_ACTION_FORMAT+9) 
#define DB2INSPECT_ACT_FORMAT_10       (DB2INSPECT_ACTION_FORMAT+10) 
#define DB2INSPECT_ACT_ROWCMPEST_TBL   (DB2INSPECT_ACTION_ROWCMPEST+1) 

/* Values for db2Inspect - iFormatType                                        */
#define DB2INSPECT_FORMAT_TYPE_HEX     1
#define DB2INSPECT_FORMAT_TYPE_BRIEF   2
#define DB2INSPECT_FORMAT_TYPE_DETAIL  3
#define DB2INSPECT_FORMAT_TYPE_DEL     4

/* Values for db2Inspect - iOptions                                           */
#define DB2INSPECT_OPTS_PAGE_LOGICAL   0         /* Format - 1st page number  */
                                                 /* logical                   */
#define DB2INSPECT_OPTS_PAGE_PHYSICAL  1         /* Format - 1st page number  */
                                                 /* physical                  */

/* Values for db2Inspect - iBeginCheckOption                                  */
#define DB2INSPECT_BEGIN_FROM_START    0x0       /* Begin from the start.     */
#define DB2INSPECT_BEGIN_TSPID         0x1       /* Begin check on            */
                                                 /* tablespace ID.            */
#define DB2INSPECT_BEGIN_OBJID         0x2       /* Begin check on object     */
                                                 /* ID.                       */
#define DB2INSPECT_BEGIN_TSPID_OBJID   (DB2INSPECT_BEGIN_TSPID | DB2INSPECT_BEGIN_OBJID)

/* Values for db2Inspect - iLimitErrorReported                                */
#define DB2INSPECT_LIMIT_ERROR_DEFAULT 0         /* limit errors reported to  */
                                                 /* default number            */
#define DB2INSPECT_LIMIT_ERROR_ALL     -1        /* no limit to errors        */
                                                 /* reported                  */

/* Values for db2Inspect - iObjectErrorState                                  */
#define DB2INSPECT_ERROR_STATE_NORMAL  0         /* process object only in    */
                                                 /* normal state              */
#define DB2INSPECT_ERROR_STATE_ALL     1         /* process object in any     */
                                                 /* state                     */

/* Values for db2Inspect - iCatalogToTablespace                               */
#define DB2INSPECT_CAT_TO_TABSP_NONE   0         /* Catalog to tablespace     */
                                                 /* consistency not           */
                                                 /* requested                 */
#define DB2INSPECT_CAT_TO_TABSP_YES    1         /* Catalog to tablespace     */
                                                 /* consistency requested     */

/* Values for db2Inspect - iKeepResultfile                                    */
#define DB2INSPECT_RESFILE_CLEANUP     0         /* Clean up result file      */
                                                 /* when no error             */
#define DB2INSPECT_RESFILE_KEEP_ALWAYS 1         /* Always keep result file   */

/* Values for db2Inspect - Level constants                                    */
#define DB2INSPECT_LEVEL_DEFAULT       0
#define DB2INSPECT_LEVEL_NONE          1
#define DB2INSPECT_LEVEL_NORMAL        DB2INSPECT_LEVEL_DEFAULT
#define DB2INSPECT_LEVEL_LOW           16384
#define DB2INSPECT_LEVEL_HIGH          49152

/* Values for db2Inspect - Cross Object Level constants                       */
#define DB2INSPECT_LVL_XOBJ_DEFAULT    0x0
#define DB2INSPECT_LVL_XOBJ_NONE       DB2INSPECT_LVL_XOBJ_DEFAULT
#define DB2INSPECT_LVL_XOBJ_INXDAT_RID 0x1       /* Index to data checking    */
                                                 /* for rid index             */
#define DB2INSPECT_LVL_XOBJ_BLKDAT     0x2       /* Block data validation     */
                                                 /* through composite block   */
                                                 /* index                     */
#define DB2INSPECT_LVL_XOBJ_DATINX_XML 0x10000   /* Data to index checking    */
                                                 /* for XML index             */

/* Values for db2Inspect - iNumberOfPages                                     */
#define DB2INSPECT_NUMPAGES_TO_THE_END 0         /* To the last page          */

/* Inspect API                                                                */
/******************************************************************************
** db2Inspect API
** Inspects the database for architectural integrity and checks the pages of the
** database for page consistency.
** 
** Scope
** 
** In a single partition database environment, the scope is the single database
** partition only. In a partitioned database environment, it is the collection
** of all logical database partitions defined in db2nodes.cfg.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** - dbadm
** - CONTROL privilege on the table
** 
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2Inspect API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2InspectStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The online inspect processing will access database objects using
** isolation level uncommitted read. Commit processing will be done
** during the inspect processing. It is advisable to end the unit of
** work by committing or rolling back changes, by executing a COMMIT
** or ROLLBACK statement respectively, before starting the inspect
** operation.
** 
** The inspect check processing will write out unformatted inspection
** data results to the result file. The file will be written out to the
** diagnostic data directory path. If there are no errors found by the
** check processing, the result output file will be erased at the end
** of the inspect operation. If there are errors found by the check
** processing, the result output file will not be erased at the end of
** the inspect operation. To see the inspection details, format the
** inspection result output file with the db2inspf utility.
** 
** In a partitioned database environment, the extension of the result
** output file will correspond to the database partition number. The
** file is located in the database manager diagnostic data directory path.
** 
** A unique results output file name must be specified. If the result
** output file already exists, the operation will not be processed.
** 
** The processing of table spaces will process only the objects that
** reside in that table space.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* DB2 Inspect               */
  db2Inspect (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */

/* Generic Inspect API                                                        */
/******************************************************************************
** db2gInspect API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* DB2 Inspect               */
  db2gInspect (
   db2Uint32 versionNumber,                      /* Database version number   */
   void * pParmStruct,                           /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */



/* Utility Control API                                                        */

/* Utility Throttling Constants                                               */
#define UTIL_IMPACT_PRIORITY_DFLT      50        /* Default throttling        */
                                                 /* priority                  */

/* Utility Control Structure                                                  */
/******************************************************************************
** db2UtilityControlStruct data structure
** db2UtilityControlStruct data structure parameters
** 
** iId
** Input. Specifies the ID of the utility to modify.
** 
** iAttribute
** Input. Specifies the attribute to modify. Valid values (defined in
** db2ApiDf header file, located in the include directory) are:
** - DB2UTILCTRL_PRIORITY_ATTRIB
** Modify the throttling priority of the utility.
** 
** pioValue
** Input. Specifies the new attribute value associated with the iAttribute
** parameter.
** Note:
** If the iAttribute parameter is set to DB2UTILCTRL_PRIORITY_ATTRIB, then the
** pioValue parameter must point to a db2Uint32 containing the priority.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2UtilityControlStruct
{
   db2Uint32                           iID;      /* Utility id                */
   db2Uint32                           iAttribute; /* Attribute to modify     */
   void                                *pioValue; /* Attribute data           */
} db2UtilityControlStruct;

/* Valid utility attributes                                                   */
#define DB2UTILCTRL_PRIORITY_ATTRIB    1         /* Modify utility priority   */

/* Utility Control API                                                        */
/******************************************************************************
** db2UtilityControl API
** Controls the priority level of running utilities. Can be used to
** throttle and unthrottle utility invocations.
** 
** Authorization
** 
** sysadm
** 
** Required connection
** 
** Instance
** 
** API include file
** 
** db2ApiDf.h
** 
** db2UtilityControl API parameters
** 
** version
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pUtilitlyControlStruct.
** 
** pUtilityControlStruct
** Input. A pointer to the db2UtilityControlStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** SQL1153N will be returned if there is no existing utility with the
** specified iId. This may indicate that the function was invoked with
** invalid arguments or that the utility has completed.
** 
** 7SQL1154N will be returned if the utility does not support throttling.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Modify attributes of      */
                                                 /* active utilities          */
  db2UtilityControl (
   db2Uint32 version,                            /* Database version number   */
   void * pUtilityControlStruct,                 /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */


/* Generic Utility Control Structure                                          */
/******************************************************************************
** db2gUtilityControlStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gUtilityControlStruct
{
   db2Uint32                           iID;      /* Utility id                */
   db2Uint32                           iAttribute; /* Attribute to modify     */
   void                                *pioValue; /* Attribute data           */
} db2gUtilityControlStruct;


/* Generic Utility Control API                                                */
/******************************************************************************
** db2gUtilityControl API
*******************************************************************************/
SQL_API_RC SQL_API_FN                            /* Modify attributes of      */
                                                 /* active utilities          */
  db2gUtilityControl (
   db2Uint32 version,                            /* Database version number   */
   void * pgUtilityControlStruct,                /* In/out parameters         */
   struct sqlca * pSqlca);                       /* SQLCA                     */


/* Quiesce Definitions                                                        */

/* Database Quiesce Struct                                                    */
/******************************************************************************
** db2DbQuiesceStruct data structure
** db2DbQuiesceStruct data structure parameters
** 
** piDatabaseName
** Input. The database name.
** 
** iImmediate
** Input. Valid values are:
** - TRUE=1
** Force the applications immediately.
** - FALSE=0
** Deferred force. Applications will wait the number of minutes specified
** by iTimeout parameter to let their current units of work be completed,
** and then will terminate. If this deferred force cannot be completed
** within the number of minutes specified by iTimeout parameter, the
** quiesce operation will fail.
** 
** iForce
** Input. Reserved for future use.
** 
** iTimeout
** Input. Specifies the time, in minutes, to wait for applications to commit the
** current unit of work. If iTimeout is not specified, in a single-partition
** database environment, the default value is 10 minutes. In a partitioned
** database environment the value specified by the start_stop_timeout
** database manager configuration parameter will be used.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DbQuiesceStruct
{
  char              *piDatabaseName;  /* Database to be quiesced              */
  db2Uint32         iImmediate;       /* Immediate or deferred                */
  db2Uint32         iForce;           /* Force Connections                    */
  db2Uint32         iTimeout;         /* Defer timeout in minutes             */
} db2DbQuiesceStruct;


/******************************************************************************
** db2DatabaseQuiesce API
** Forces all users off the database, immediately rolls back all active
** transactions or waits for them to complete their current units of
** work within the number of minutes specified (if they cannot be
** completed within the specified number of minutes, the operation will
** fail), and puts the database into quiesce mode. This API
** provides exclusive access to the database. During this quiesced
** period, system administration can be performed on the database by
** users with appropriate authority. After administration is complete,
** you can unquiesce the database, using the db2DatabaseUnquiesce API.
** The db2DatabaseUnquiesce API allows other users to connect to the
** database, without having to shut down and perform another database
** start.
** 
** In this mode only groups or users with QUIESCE CONNECT authority and
** sysadm, sysmaint, or sysctrl will have access to the database and its
** objects.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - dbadm
** 
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2DatabaseQuiesce API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DbQuiesceStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
/* Database Quiesce API                                                       */
SQL_API_RC SQL_API_FN                        /* Database Quiesce              */
  db2DatabaseQuiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Database Quiesce Info         */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Generic Database Quiesce Struct                                            */
/******************************************************************************
** db2gDbQuiesceStruct data structure
** db2gDbQuiesceStruct data structure specific parameters
** 
** iDatabaseNameLen
** Input. Specifies the length in bytes of piDatabaseName.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gDbQuiesceStruct
{
  db2Uint32         iDatabaseNameLen; /* Database Name Length                 */
  char              *piDatabaseName;  /* Database to be quiesced              */
  db2Uint32         iImmediate;       /* Immediate or deferred                */
  db2Uint32         iForce;           /* Force Connections                    */
  db2Uint32         iTimeout;         /* Defer timeout in minutes             */
} db2gDbQuiesceStruct;


/******************************************************************************
** db2gDatabaseQuiesce API
*******************************************************************************/
/* Generic Database Quiesce API                                               */
SQL_API_RC SQL_API_FN                        /* Generic Database Quiesce      */
  db2gDatabaseQuiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Database Quiesce Info         */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Database Unquiesce Struct                                                  */
/******************************************************************************
** db2DbUnquiesceStruct data structure
** db2DbUnquiesceStruct data structure parameters
** 
** piDatabaseName
** Input. The database name.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DbUnquiesceStruct
{
             char          *piDatabaseName;  /* Database to be unquiesced     */
} db2DbUnquiesceStruct;


/******************************************************************************
** db2DatabaseUnquiesce API
** Restores user access to databases which have been quiesced for maintenance or
** other reasons. User access is restored without necessitating a shutdown and
** database restart.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - dbadm
** 
** Required connection
** 
** Database
** 
** API include file
** 
** db2ApiDf.h
** 
** db2DatabaseUnquiesce API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DbUnquiesceStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
/* Database Unquiesce API                                                     */
SQL_API_RC SQL_API_FN                        /* Database unquiesce            */
  db2DatabaseUnquiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Database Unquiesce Info       */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Generic Database Unquiesce Struct                                          */
/******************************************************************************
** db2gDbUnquiesceStruct data structure
** db2gDbUnquiesceStruct data structure specific parameters
** 
** iDatabaseNameLen
** Input. Specifies the length in bytes of piDatabaseName.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gDbUnquiesceStruct
{
             db2Uint32     iDatabaseNameLen; /* Database Name Length          */
             char          *piDatabaseName;  /* Database to be unquiesced     */
} db2gDbUnquiesceStruct;


/******************************************************************************
** db2gDatabaseUnquiesce API
*******************************************************************************/
/* Generic Database Unquiesce API                                             */
SQL_API_RC SQL_API_FN                        /* Database unquiesce            */
  db2gDatabaseUnquiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Database Unquiesce Info       */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Instance Quiesce Struct                                                    */
/******************************************************************************
** db2InsQuiesceStruct data structure
** db2InsQuiesceStruct data structure parameters
** 
** piInstanceName
** Input. The instance name.
** 
** piUserId
** Input. The name of the user who will be allowed access to the instance
** while it is quiesced.
** 
** piGroupId
** Input. The name of a group that will be allowed access to the instance
** while the instance is quiesced.
** 
** iImmediate
** Input. Valid values are:
** - TRUE=1
** Force the applications immediately.
** - FALSE=0
** Deferred force. Applications will wait the number of minutes specified
** by iTimeout parameter to let their current units of work be completed,
** and then will terminate. If this deferred force cannot be completed
** within the number of minutes specified by iTimeout parameter, the
** quiesce operation will fail.
** 
** iForce
** Input. Reserved for future use.
** 
** iTimeout
** Input. Specifies the time, in minutes, to wait for applications to commit
** the current unit of work. If iTimeout is not specified, in a single-partition
** database environment, the default value is 10 minutes. In a partitioned
** database environment the value specified by the start_stop_timeout
** database manager configuration parameter will be used.
** 
** iQOptions
** Input. Specifies instance quiesce options. Valid values (defined in sqlenv
** header file, located in the include directory) are:
** - DB2INSQUIESCE_RESTRICTEDACCESS
** The instance is quiesced with the RESTRICTED ACCESS option to prevent
** databases being activated to do authorization checking.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2InsQuiesceStruct
{
             char          *piInstanceName;  /* Instance to be quiesced       */
             char          *piUserId;        /* Quiesce User Id               */
             char          *piGroupId;       /* Quiesce Group Id              */
             db2Uint32     iImmediate;       /* Immediate or deferred         */
             db2Uint32     iForce;           /* Force Connections             */
             db2Uint32     iTimeout;         /* Defer timeout in minutes      */
             db2Uint32     iQOptions;        /* Quiesce options               */
} db2InsQuiesceStruct;


/******************************************************************************
** db2InstanceQuiesce API
** Forces all users off the instance, immediately rolls back all active
** transaction, and puts the database into quiesce mode. This API provides
** exclusive access to the instance. During this quiesced period, system
** administration can be performed on the instance. After administration
** is complete, you can unquiesce the database using the db2DatabaseUnquiesce
** API. This API allows other users to connect to the database without
** having to shut down and perform another database start.
** 
** In this mode only groups or users with QUIESCE CONNECT authority and
** sysadm, sysmaint, or sysctrl authority will have access to the database
** and its objects.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** db2InstanceQuiesce API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** 
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2InsQuiesceStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
/* Instance Quiesce API                                                       */
SQL_API_RC SQL_API_FN                        /* Instance Quiesce              */
  db2InstanceQuiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Instance Quiesce Info         */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Generic Instance Quiesce Struct                                            */
/******************************************************************************
** db2gInsQuiesceStruct data structure
** db2gInsQuiesceStruct data structure specific parameters
** 
** iInstanceNameLen
** Input. Specifies the length in bytes of piInstanceName.
** 
** iUserIdLen
** Input. Specifies the length in bytes of piUserID.
** 
** iGroupIdLen
** Input. Specifies the length in bytes of piGroupId.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gInsQuiesceStruct
{
             db2Uint32     iInstanceNameLen; /* InstanceName Length           */
             char          *piInstanceName;  /* Instance to be quiesced       */
             db2Uint32     iUserIdLen;       /* UserId Length                 */
             char          *piUserId;        /* Quiesce User Id               */
             db2Uint32     iGroupIdLen;      /* GroupId Length                */
             char          *piGroupId;       /* Quiesce Group Id              */
             db2Uint32     iImmediate;       /* Immediate or deferred         */
             db2Uint32     iForce;           /* Force Connections             */
             db2Uint32     iTimeout;         /* Defer timeout in minutes      */
             db2Uint32     iQOptions;        /* Quiesce options               */
} db2gInsQuiesceStruct;


/******************************************************************************
** db2gInstanceQuiesce API
*******************************************************************************/
/* Generic Instance Quiesce API                                               */
SQL_API_RC SQL_API_FN                        /* Generic Instance Quiesce      */
  db2gInstanceQuiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Instance Quiesce Info         */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Instance Unquiesce Struct                                                  */
/******************************************************************************
** db2InsUnquiesceStruct data structure
** db2InsUnquiesceStruct data structure parameters
** 
** piInstanceName
** Input. The instance name.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2InsUnquiesceStruct
{
             char          *piInstanceName;  /* Instance to be unquiesced     */
} db2InsUnquiesceStruct;


/******************************************************************************
** db2InstanceUnquiesce API
** Unquiesce all databases in the instance.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** db2InstanceUnquiesce API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2InsUnquiesceStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
/* Instance Unquiesce API                                                     */
SQL_API_RC SQL_API_FN                        /* Instance Unquiesce            */
  db2InstanceUnquiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Instance Unquiesce Info       */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Generic Instance Unquiesce Struct                                          */
/******************************************************************************
** db2gInsUnquiesceStruct data structure
** db2gInsUnquiesceStruct data structure specific parameters
** 
** iInstanceNameLen
** Input. Specifies the length in bytes of piInstanceName.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gInsUnquiesceStruct
{
             db2Uint32     iInstanceNameLen; /* InstanceName Length           */
             char          *piInstanceName;  /* Instance to be unquiesced     */
} db2gInsUnquiesceStruct;


/******************************************************************************
** db2gInstanceUnquiesce API
*******************************************************************************/
/* Generic Instance Unquiesce API                                             */
SQL_API_RC SQL_API_FN                        /* Generic Instance Unquiesce    */
  db2gInstanceUnquiesce (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Instance Unquiesce Info       */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* db2DasCommData                                                             */
/******************************************************************************
** db2DasCommData data structure
** db2DasCommData data structure parameters
** 
** iCommParam
** Input. An indicator set to TRUE or FALSE. This parameter should be set to
** TRUE if this is a remote start.
** 
** piNodeOrHostName
** Input. The member or hostname.
** 
** piUserId
** Input. The user name.
** 
** piUserPw
** Input. The user password.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DasCommData
{
             db2int8       iCommParam;       /* Flag for Nodename or          */
                                             /* Hostname specified            */
             char          *piNodeOrHostName; /* Member or HostName           */
             char          *piUserId;        /* User id                       */
             char          *piUserPw;        /* User password                 */
} db2DasCommData;


/* db2gDasCommData                                                            */
/******************************************************************************
** db2gDasCommData data structure
** db2gDasCommData data structure specific parameters
** 
** iNodeOrHostNameLen
** Input. Specifies the length in bytes of piNodeOrHostName.
** 
** iUserIdLen
** Input. Specifies the length in bytes of piUserId.
** 
** iUserPwLen
** Input. Specifies the length in bytes of piUserPw.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gDasCommData
{
             db2int8       iCommParam;       /* Flag for Nodename or          */
                                             /* Hostname specified            */
             db2Uint32     iNodeOrHostNameLen; /* Node or HostName            */
             char          *piNodeOrHostName; /* Node or HostName             */
             db2Uint32     iUserIdLen;       /* iUserIdLen                    */
             char          *piUserId;        /* User id                       */
             db2Uint32     iUserPwLen;       /* iUserPwLen                    */
             char          *piUserPw;        /* User password                 */
} db2gDasCommData;


/* db2QuiesceStartStruct                                                      */
/******************************************************************************
** db2QuiesceStartStruct data structure
** db2QuiesceStartStruct data structure parameters
** 
** iIsQRequested
** Input. An indicator set to TRUE or FALSE. This parameter should be set to
** TRUE if quiesce is requested.
** 
** iQOptions
** Input. Specifies any instance quiesce options. Valid values (defined in
** sqlenv header file, located in the include directory) are:
** - DB2INSQUIESCE_RESTRICTEDACCESS
** The instance is started in ADMIN MODE with the RESTRICTED ACCESS option to
** prevent databases being activated to do authorization checking.
** 
** piQUsrName
** Input. The quiesced username.
** 
** piQGrpName
** Input. The quiesced group name.
** 
** iIsQUsrGrpDef
** Input. An indicator set to TRUE or FALSE. This parameter should be set to
** TRUE if a quiesced user or quiesced group is defined.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2QuiesceStartStruct
{
             db2int8       iIsQRequested;    /* is Quiesce requested?         */
             db2int8       iQOptions;        /* Instance quiesce options      */
             char          *piQUsrName;      /* Quiesce user name             */
             char          *piQGrpName;      /* Quiesce group name            */
             db2int8       iIsQUsrGrpDef;    /* is UserGroup Defined?         */
} db2QuiesceStartStruct;


/* db2gQuiesceStartStruct                                                     */
/******************************************************************************
** db2gQuiesceStartStruct data structure
** db2gQuiesceStartStruct data structure specific parameters
** 
** iQUsrNameLen
** Input. Specifies the length in bytes of piQusrName.
** 
** iQGrpNameLen
** Input. Specifies the length in bytes of piQGrpName.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gQuiesceStartStruct
{
             db2int8       iIsQRequested;    /* is Quiesce requested?         */
             db2int8       iQOptions;        /* Instance quiesce options      */
             db2Uint32     iQUsrNameLen;     /* iQUserNameLen                 */
             char          *piQUsrName;      /* Quiesce user name             */
             db2Uint32     iQGrpNameLen;     /* iQGrpNameLen                  */
             char          *piQGrpName;      /* Quiesce group name            */
             db2int8       iIsQUsrGrpDef;    /* is UserGroup Defined?         */
} db2gQuiesceStartStruct;


/* db2StartOptionsStruct                                                      */
/******************************************************************************
** db2StartOptionsStruct data structure
** db2StartOptionsStruct data structure parameters
** 
** iIsProfile
** Input. Indicates whether a profile is specified. If this field
** indicates that a profile is not specified, the file db2profile is used.
** 
** piProfile
** Input. The name of the profile file to be executed at each member to
** define the DB2 environment (MPP only). This file is executed before any
** members are started. The default value is db2profile.
** 
** iIsNodeNum
** Input. Indicates whether a member or CF number is specified. If specified,
** 
** the start command only affects the specified member or CF.
** 
** iNodeNum
** Input. The member or CF number.
** 
** iOption
** Input. Specifies an action. Valid values for OPTION (defined in sqlenv
** header file, located in the include directory) are:
** - SQLE_NONE
** Issue the normal db2start operation.
** - SQLE_ADDNODE
** Issue the ADD NODE command.
** - SQLE_RESTART
** Issue the RESTART DATABASE command.
** - SQLE_STANDALONE
** Start the node in STANDALONE mode.
** 
** iIsHostName
** Input. Indicates whether a host name is specified.
** 
** piHostName
** Input. The system name.
** 
** iIsPort
** Input. Indicates whether a port number is specified.
** 
** iPort
** Input. The port number.
** 
** iIsNetName
** Input. Indicates whether a net name is specified.
** 
** piNetName
** Input. The network name.
** 
** iTblspaceType
** Input. Specifies the type of system temporary table space definitions to
** be used for the node being added. Valid values are:
** - SQLE_TABLESPACES_NONE
** Do not create any system temporary table spaces.
** - SQLE_TABLESPACES_LIKE_NODE
** The containers for the system temporary table spaces should be the
** same as those for the specified node.
** - SQLE_TABLESPACES_LIKE_CATALOG
** The containers for the system temporary table spaces should be the
** same as those for the catalog node of each database.
** 
** iTblspaceNode
** Input. Specifies the member number from which the system temporary table
** space definitions should be obtained. The member number must exist in the
** db2nodes.cfg configuration file, and is only used if the tblspace_type field
** is set to SQLE_TABLESPACES_LIKE_NODE.
** 
** iIsComputer
** Input. Indicates whether a computer name is specified. Valid on the
** Windows operating system only.
** 
** piComputer
** Input. Computer name. Valid on the Windows operating system only.
** 
** piUserName
** Input. Logon account user name. Valid on the Windows operating system
** only.
** 
** piPassword
** Input. The password corresponding to the logon account user name.
** 
** iQuiesceOpts
** Input. A pointer to the db2QuiesceStartStruct structure.
** 
** piKeystorePw
** Input. The password to open the keystore.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2StartOptionsStruct
{
             db2Uint32     iIsProfile;       /* is Profile specified?         */
             char          *piProfile;       /* Profile to be executed prior  */
                                             /* to a start                    */
             db2Uint32     iIsNodeNum;       /* is Node number specified?     */
             db2NodeType   iNodeNum;         /* Node number                   */
             db2Uint32     iOption;          /* Start option                  */
             db2Uint32     iIsHostName;      /* is Hostname specified?        */
             char          *piHostName;      /* Hostname                      */
             db2Uint32     iIsPort;          /* is Port specified?            */
             db2PortType   iPort;            /* Port                          */
             db2Uint32     iIsNetName;       /* is Netname specified?         */
             char          *piNetName;       /* Netname                       */
             db2Uint32     iTblspaceType;    /* Addnode tablespace type       */
             db2NodeType   iTblspaceNode;    /* Addnode tablespace node       */
             db2Uint32     iIsComputer;      /* is Computername               */
                                             /* specified(for Windows)?       */
             char          *piComputer;      /* Computer name                 */
             char          *piUserName;      /* Logon account user name       */
             char          *piPassword;      /* Logon account password        */
             db2QuiesceStartStruct  iQuiesceOpts; /* Quiesce start options    */
             char          *piKeystorePw;    /* The password for the          */
                                             /* keystore                      */
} db2StartOptionsStruct;


/* db2gStartOptionsStruct                                                     */
/******************************************************************************
** db2gStartOptionsStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gStartOptionsStruct
{
             db2Uint32     iIsProfile;       /* is Profile specified?         */
             char          *piProfile;       /* Profile to be executed prior  */
                                             /* to a start                    */
             db2Uint32     iIsNodeNum;       /* is Node number specified?     */
             db2NodeType   iNodeNum;         /* Node number                   */
             db2Uint32     iOption;          /* Start option                  */
             db2Uint32     iIsHostName;      /* is Hostname specified?        */
             char          *piHostName;      /* Hostname                      */
             db2Uint32     iIsPort;          /* is Port specified?            */
             db2PortType   iPort;            /* Port                          */
             db2Uint32     iIsNetName;       /* is Netname specified?         */
             char          *piNetName;       /* Netname                       */
             db2Uint32     iTblspaceType;    /* Addnode tablespace type       */
             db2NodeType   iTblspaceNode;    /* Addnode tablespace node       */
             db2Uint32     iIsComputer;      /* is Computername               */
                                             /* specified(for Windows)?       */
             char          *piComputer;      /* Computer name                 */
             char          *piUserName;      /* Logon account user name       */
             char          *piPassword;      /* Logon account password        */
             db2gQuiesceStartStruct  iQuiesceOpts; /* Quiesce start options   */
} db2gStartOptionsStruct;


/* db2InstanceStartStruct                                                     */
/******************************************************************************
** db2InstanceStartStruct data structure
** db2InstanceStartStruct data structure parameters
** 
** iIsRemote
** Input. An indicator set to constant integer value TRUE or
** FALSE. This parameter should be set to TRUE if this is a
** remote start.
** 
** piRemoteInstName
** Input. The name of the remote instance.
** 
** piCommData
** Input. A pointer to the db2DasCommData structure.
** 
** piStartOpts
** Input. A pointer to the db2StartOptionsStruct structure.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2InstanceStartStruct
{
             db2int8       iIsRemote;        /* is it a remote start?         */
             char          *piRemoteInstName; /* The name of the remote       */
                                             /* instance to be started.       */
             db2DasCommData * piCommData;    /* Remote start structure for    */
                                             /* DAS                           */
             db2StartOptionsStruct * piStartOpts; /* db2StartOptions          */
                                             /* structure                     */
} db2InstanceStartStruct;


/* db2gInstanceStStruct                                                       */
/******************************************************************************
** db2gInstanceStStruct data structure
** db2gInstanceStStruct data structure specific parameters
** 
** iRemoteInstLen
** Input. Specifies the length in bytes of piRemoteInstName.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gInstanceStStruct
{
             db2int8       iIsRemote;        /* is it a remote start?         */
             db2Uint32     iRemoteInstLen;   /* iRemoteInstLen                */
             char          *piRemoteInstName; /* The name of the remote       */
                                             /* instance to be started.       */
             db2gDasCommData * piCommData;   /* Remote start structure for    */
                                             /* DAS                           */
             db2gStartOptionsStruct * piStartOpts; /* db2gStartOptions        */
                                             /* structure                     */
} db2gInstanceStStruct;



/******************************************************************************
** db2InstanceStart API
** Starts a local or remote instance.
** 
** Scope
** 
** This API can be issued against a single member, list of members or globally
** against all members. In a DB2 pureScale™environment, this API may be issued
** against a specific host to start the instance services on that machine.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** db2InstanceStart API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2InstanceStartStruct structure. 
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
/* Instance Start API                                                         */
SQL_API_RC SQL_API_FN                        /* Instance Start                */
  db2InstanceStart (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Start Options                 */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2gInstanceStart API
*******************************************************************************/
/* Generic Instance Start API                                                 */
SQL_API_RC SQL_API_FN                        /* Generic Instance Start        */
  db2gInstanceStart (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Start Options                 */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* db2StopOptionsStruct                                                       */
/******************************************************************************
** db2StopOptionsStruct data structure
** db2StopOptionsStruct data structure parameters
** 
** iIsProfile
** Input. Indicates whether a profile is specified. Possible values are TRUE
** and FALSE. If this field indicates that a profile is not specified, the file
** db2profile is used.
** 
** piProfile
** Input. The name of the profile file that was executed at startup to define
** the DB2 environment for those nodes that were started (MPP only). If a
** profile for the db2InstanceStart API was specified, the same profile must
** be specified here.
** 
** iIsNodeNum
** Input. Indicates whether a node number is specified. If specified,
** the stop command only affects the specified node.
** 
** iNodeNum
** Input. The member number.
** 
** iStopOption
** Input. Option. Valid values are:
** - SQLE_NONE
** Issue the normal db2stop operation.
** - SQLE_FORCE
** Issue the FORCE APPLICATION (ALL) command.
** - SQLE_DROP
** Drop the node from the db2nodes.cfg file.
** - SQLE_QUIESCE
** Delayed version of SQLE_FORCE.  Used with iQuiesceDeferMins.
** 
** iCallerac
** Input. This field is valid only for the SQLE_DROP value of the OPTION
** field. Valid values are:
** - SQLE_DROP
** Initial call. This is the default value.
** - SQLE_CONTINUE
** Subsequent call. Continue processing after a prompt.
** - SQLE_TERMINATE
** Subsequent call. Terminate processing after a prompt.
** 
** iIsHostName
** Input. Indicates whether a host name is specified.
** 
** piHostName
** Input. The system name.
** 
** iQuiesceDeferMins
** Input. The number of minutes to wait before forcing connections for SQLE_QUIESCE
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2StopOptionsStruct
{
             db2Uint32     iIsProfile;       /* is Profile specified?         */
             char          *piProfile;       /* Profile                       */
             db2Uint32     iIsNodeNum;       /* is Node number specified?     */
             db2NodeType   iNodeNum;         /* Node number                   */
             db2Uint32     iStopOption;      /* Stop option (drop/force)      */
             db2Uint32     iCallerac;        /* if stop option is DROP NODE,  */
                                             /* this could be                 */
                                             /* DROP,CONTINUE,TERMINATE       */
             db2Uint32     iIsHostName;      /* is Hostname specified?        */
             char          *piHostName;      /* Hostname                      */
             db2int32      iQuiesceDeferMins; /* Number of minutes to wait    */
                                             /* before forcing connections    */
                                             /* for db2stop QUIESCE           */
} db2StopOptionsStruct;

/* db2InstanceStopStruct                                                      */
/******************************************************************************
** db2InstanceStopStruct data structure
** db2InstanceStopStruct data structure parameters
** 
** iIsRemote
** Input. An indicator set to TRUE or FALSE. This parameter should be set to
** TRUE if this is a remote start.
** 
** piRemoteInstName
** Input. The name of the remote instance.
** 
** piCommData
** Input. A pointer to the db2DasCommData structure.
** 
** piStopOpts
** Input. A pointer to the db2StopOptionsStruct structure.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2InstanceStopStruct
{
             db2int8       iIsRemote;        /* is it a remote start?         */
             char          *piRemoteInstName; /* The name of the remote       */
                                             /* instance to be started.       */
             db2DasCommData * piCommData;    /* Remote start structure for    */
                                             /* DAS                           */
             db2StopOptionsStruct * piStopOpts; /* db2StopOptions structure   */
} db2InstanceStopStruct;

/* db2gInstanceStopStruct                                                     */
/******************************************************************************
** db2gInstanceStopStruct data structure
** db2gInstanceStopStruct data structure specific parameters
** 
** iRemoteInstLen
** Input. Specifies the length in bytes of piRemoteInstName.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gInstanceStopStruct
{
             db2int8       iIsRemote;        /* is it a remote start?         */
             db2Uint32     iRemoteInstLen;   /* iRemoteInstLen                */
             char          *piRemoteInstName; /* The name of the remote       */
                                             /* instance to be started.       */
             db2gDasCommData * piCommData;   /* Remote start structure for    */
                                             /* DAS                           */
             db2StopOptionsStruct * piStopOpts; /* db2StopOptions structure   */
} db2gInstanceStopStruct;


/******************************************************************************
** db2InstanceStop API
** Stops the local or remote DB2 instance.
** 
** Scope
** 
** This API can be issued against a single member, list of members or, globally
** against all members. In a DB2 pureScale™environment, this API may be issued
** against a specific host to stop the instance services on that machine.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** db2InstanceStop API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2InstanceStopStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
/* Instance Stop API                                                          */
SQL_API_RC SQL_API_FN                        /* Instance Stop                 */
  db2InstanceStop (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Stop Options                  */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2gInstanceStop API
*******************************************************************************/
/* Generic Instance Stop API                                                  */
SQL_API_RC SQL_API_FN                        /* Generic Instance Stop         */
  db2gInstanceStop (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Stop Options                  */
             struct sqlca * pSqlca);         /* SQLCA                         */




/* Health Monitor Alert Configuration Structures, Constants, and Function     */
/* Prototypes                                                                 */

/* Type of DB2 objects for which one can configure health alerts              */
/* (db2GetAlertCfgData.iObjType)                                              */
#define DB2ALERTCFG_OBJTYPE_DBM         0    /* DBM alert cfg                 */
#define DB2ALERTCFG_OBJTYPE_DATABASE    1    /* Alert cfg for a DB            */
#define DB2ALERTCFG_OBJTYPE_TABLESPACE  2    /* Alert cfg for a TS            */
#define DB2ALERTCFG_OBJTYPE_TS_CONTAINER 3   /* Alert cfg for a TSC           */

#define DB2ALERTCFG_OBJTYPE_DATABASES   1001 /* Alert cfg for all DBs         */
#define DB2ALERTCFG_OBJTYPE_TABLESPACES 1002 /* Alert cfg for all TSs         */
#define DB2ALERTCFG_OBJTYPE_TS_CONTAINERS 1003 /* Alert cfg for a TSCs        */

/* Type of DB2 defaults the user wants the health alerts for                  */
/* (db2GetAlertCfgData.iDefault)                                              */
#define DB2ALERTCFG_NOT_DEFAULT         0    /* Defaults not requested.       */
                                             /* Current Settings will be      */
                                             /* returned.                     */
#define DB2ALERTCFG_CURRENT_DEFAULT     1    /* The current default settings  */
                                             /* for an object of that type    */
                                             /* will be returned.(Those are   */
                                             /* user configurable)            */

/* Types of scripts supported as alert actions                                */
/* (db2AlertScriptAction.scriptType)                                          */
#define DB2ALERTCFG_SCRIPTTYPE_DB2CMD   0x8001 /* DB2 Command script          */
#define DB2ALERTCFG_SCRIPTTYPE_OS       0x8002 /* Operating System script     */

/* Alert attributes that can be configured (db2AlertAttrib.attribID)          */
#define DB2ALERTCFG_ALARM               0    /* alarm threshold               */
#define DB2ALERTCFG_WARNING             1    /* warning threshold             */
#define DB2ALERTCFG_SENSITIVITY         2    /* Min time in threshold zone    */
#define DB2ALERTCFG_ACTIONS_ENABLED     3    /* Threshold breach actionable?  */
#define DB2ALERTCFG_THRESHOLD_CHECK     4    /* Evaluate thresholds or        */
                                             /* state?                        */

/* Script action attributes that can be configured (db2AlertAttrib.attribID)  */
#define DB2ALERTCFG_SCRIPT_TYPE         0    /* Type of action script         */
#define DB2ALERTCFG_SCRIPT_WORKINGDIR   1    /* Script's working directory    */
#define DB2ALERTCFG_SCRIPT_STMTTERMCHAR 2    /* Statement termination char    */
#define DB2ALERTCFG_SCRIPT_CMDLINEPARMS 3    /* Command-line parameters       */
#define DB2ALERTCFG_SCRIPT_USERID       4    /* Script execution userid       */
#define DB2ALERTCFG_SCRIPT_PASSWORD     5    /* Script execution password     */
#define DB2ALERTCFG_SCRIPT_NAME         6    /* Script Name                   */
#define DB2ALERTCFG_SCRIPT_CONDITION    7    /* Script condition              */
#define DB2ALERTCFG_SCRIPT_HOSTNAME     8    /* host name to run script on    */

/* Task action attributes that can be configured (db2AlertAttrib.attribID)    */
#define DB2ALERTCFG_TASK_USERID         4    /* Task execution userid         */
#define DB2ALERTCFG_TASK_PASSWORD       5    /* Task execution password       */
#define DB2ALERTCFG_TASK_NAME           6    /* Task Name                     */
#define DB2ALERTCFG_TASK_CONDITION      7    /* Task condition                */
#define DB2ALERTCFG_TASK_HOSTNAME       8    /* host name to find a task      */

/* Types of alert actions (db2AlertActionDelete.actionType)                   */
/* (db2AlertActionUpdate.actionType) (db2AlertActionNew.actionType)           */
#define DB2ALERTCFG_ACTIONTYPE_SCRIPT   0x8000 /* Alert action is a script    */
#define DB2ALERTCFG_ACTIONTYPE_TASK     0x4000 /* Alert action is a task      */

/* Conditions for scripts and tasks execution (db2AlertTaskAction.condition)  */
/* and (db2AlertScriptAction.condition). For state based health indicators,   */
/* use the states returned by the health snapshot present in sqlmon.h         */
#define DB2ALERTCFG_CONDITION_ALL       0xffffffff /* Run script/task on any  */
                                             /* alarm or non normal state     */
#define DB2ALERTCFG_CONDITION_WARNING   0xfffffffe /* Run script/task on      */
                                             /* warning                       */
#define DB2ALERTCFG_CONDITION_ALARM     0xfffffffd /* Run script/task on      */
                                             /* ALARM                         */

/* Values returned in (db2GetAlertCfgInd.oDefault) for alert configuration    */
/* default.                                                                   */
#define DB2ALERTCFG_INHERIT_DEFAULT_NO  0x0  /* Configuration not inherited   */
                                             /* from default.                 */
#define DB2ALERTCFG_INHERIT_DEFAULT_YES 0x1  /* Configuration inherited from  */
                                             /* default.                      */
#define DB2ALERTCFG_INHERIT_DEFAULT_UNKNOWN 0x2 /* Unknown if configuration   */
                                             /* is inherited from default     */
                                             /* (8.1 servers only)            */


/* Structure for returning alert configuration using the db2GetAlertCfg API   */
/******************************************************************************
** db2GetAlertCfgData data structure
** db2GetAlertCfgData data structure parameters
** 
** iObjType
** Input. Specifies the type of object for which configuration is requested.
** Valid values are:
** 
** - DB2ALERTCFG_OBJTYPE_DBM
** - DB2ALERTCFG_OBJTYPE_DATABASES
** - DB2ALERTCFG_OBJTYPE_TABLESPACES
** - DB2ALERTCFG_OBJTYPE_TS_CONTAINERS
** - DB2ALERTCFG_OBJTYPE_DATABASE
** - DB2ALERTCFG_OBJTYPE_TABLESPACE
** - DB2ALERTCFG_OBJTYPE_TS_CONTAINER
** 
** piObjName
** Input. The name of the table space or table space container when the
** object type, iObjType, is set to
** DB2ALERTCFG_OBJTYPE_TABLESPACE or
** DB2ALERTCFG_OBJTYPE_TS_CONTAINER.
** 
** iDefault
** Input. Indicates that the default installation configuration values are to be
** retrieved.
** 
** piDbname
** Input. The alias name for the database for which configuration is
** requested when object type, iObjType, is
** DB2ALERTCFG_OBJTYPE_TS_CONTAINER,
** DB2ALERTCFG_OBJTYPE_TABLESPACE, and
** DB2ALERTCFG_OBJTYPE_DATABASE.
** 
** ioNumIndicators
** This parameter can be used as either an input or output parameter.
** 
** Input. Indicates the number of pioIndicators submitted when requesting
** the settings for a subset of health indicators.
** 
** Output. Indicates the total number of health indicators returned by the
** API.
** 
** pioIndicators
** A pointer to the db2GetAlertCfgInd structure. If it is set to NULL, all
** health indicators for that object will be returned.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetAlertCfgData
{
   db2Uint32                 iObjType;      /* DB2 object type                */
   char                      *piObjName;    /* Name of DB2 object.            */
                                            /* For DB2ALERTCFG_OBJTYPE_TS     */
                                            /* CONTAINER, this name is        */
                                            /* defined as <tablespace         */
                                            /* Name>.<Table Space Container   */
                                            /* Name> .For all other objects,  */
                                            /* this name is simply the        */
                                            /* actual object name.            */
   db2Uint32                 iDefault;      /* Return default configuration   */
                                            /* for an object of type          */
                                            /* iObjType.                      */
                                            /*                                */
                                            /* To get the current             */
                                            /* configuration, set to          */
                                            /* DB2ALERTCFG_NOT_DEFAULT.       */
                                            /*                                */
                                            /* To get the default             */
                                            /* configuration, set to          */
                                            /* DB2ALERTCFG_CURRENT_DEFAULT.   */
                                            /*                                */
   char                      *piDbName;     /* Database alias                 */
   db2Uint32                 ioNumIndicators; /* Array length of pIndicators  */
   struct db2GetAlertCfgInd  *pioIndicators; /* Input:                        */
                                            /*                                */
                                            /* To get the configuration of    */
                                            /* all HI set to NULL.            */
                                            /*                                */
                                            /* To get the configuration of a  */
                                            /* specific HI, pass an array of  */
                                            /* db2GetAlertCfgInd and set the  */
                                            /* indicatorID fields to desired  */
                                            /* HIs and other fields to 0 or   */
                                            /* NULL                           */
                                            /*                                */
                                            /* Output:                        */
                                            /*                                */
                                            /* Array of cfg per indicator     */
                                            /* allocated by the API.          */
} db2GetAlertCfgData;


/* Structure for defining the parameters of a Task action                     */
/******************************************************************************
** db2AlertTaskAction data structure
** db2AlertTaskAction data structure parameters
** 
** pTaskname
** The name of the task.
** 
** condition
** The condition for which to run the action.
** 
** pUserID
** The user account under which the script will be executed. 
** 
** pPassword
** The password for the user account pUserId.
** 
** pHostName
** The host name on which to run the script. This applies for both task and
** script.
** Script
** The hostname for where the script resides and will be run.
** Task
** The hostname for where the scheduler resides.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AlertTaskAction
{
   char                      *pTaskName;    /* Name of the task.              */
                                            /* This should be a NULL          */
                                            /* terminated string of the       */
                                            /* form: <task ID Number>.<task   */
                                            /* Suffix Number>                 */
   db2Uint32                 condition;     /* Condition needed to run task   */
   char                      *pUserID;      /* User acct under which task     */
                                            /* runs                           */
   char                      *pPassword;    /* Password for pUserID           */
   char                      *pHostName;    /* Host name where to find the    */
                                            /* task                           */
} db2AlertTaskAction;


/* Structure for defining the parameters of a script action                   */
/******************************************************************************
** db2AlertScriptAction data structure
** db2AlertScriptAction data structure parameters
** 
** scriptType
** Specifies the type of script. Valid values are:
** - DB2ALERTCFG_SCRIPTTYPE_DB2CMD
** - DB2ALERTCFG_SCRIPTTYPE_OS
** 
** condition
** The condition on which to run the action. Valid values for threshold
** based health indicators are: 
** - DB2ALERTCFG_CONDITION_ALL 
** - DB2ALERTCFG_CONDITION_WARNING 
** - DB2ALERTCFG_CONDITION_ALARM
** For state based health indicators, use the numerical value defined in sqlmon.
** 
** pPathname
** The absolute pathname of the script.
** 
** pWorkingDir
** The absolute pathname of the directory in which the script is to be
** executed.
** 
** pCmdLineParms
** The command line parameters to be passed to the script when it is
** invoked. Optional for DB2ALERTCFG_SCRIPTTYPE_OS only.
** 
** stmtTermChar
** The character that is used in the script to terminate statements. Optional
** for DB2ALERTCFG_SCRIPTTYPE_DB2CMD only.
** 
** pUserID
** The user account under which the script will be executed.
** 
** pPassword
** The password for the user account pUserId.
** 
** pHostName
** The host name on which to run the script. This applies for both task and
** script.
** Script
** The hostname for where the script resides and will be run.
** Task
** The hostname for where the scheduler resides.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AlertScriptAction
{
   db2Uint32                 scriptType;    /* DB2 or OS script               */
   db2Uint32                 condition;     /* Condition needed to run        */
                                            /* script                         */
   char                      *pPathName;    /* Absolute pathname of script    */
   char                      *pWorkingDir;  /* Dir in which script runs       */
   char                      *pCmdLineParms; /* Cmd-line parms for OS         */
                                            /* scripts only                   */
   char                      stmtTermChar;  /* Char that terminates stmts in  */
                                            /* DB2 Cmd script                 */
   char                      *pUserID;      /* User acct under which script   */
                                            /* runs                           */
   char                      *pPassword;    /* Password for pUserID           */
   char                      *pHostName;    /* Host name where to find and    */
                                            /* run script                     */
} db2AlertScriptAction;


/* Structure containing configuration parameters for a single health          */
/* indicator                                                                  */
/******************************************************************************
** db2GetAlertCfgInd data structure
** db2GetAlertCfgInd data structure parameters
** 
** ioIndicatorID
** The health indicator (defined in sqlmon.h).
** 
** oAlarm
** Output. The health indicator alarm threshold setting. This setting is valid
** for threshold-based health indicators only.
** 
** oWarning
** Output. The health indicator warning threshold setting. This setting is
** valid for threshold-based health indicators only.
** 
** oSensitivity
** Output. The period of time a health indicator's value must remain within a
** threshold zone before the associated alarm or warning condition is
** registered. 
** 
** poFormula
** Output. A string representation of the formula used to compute the health
** indicator's value.
** 
** oActionEnabled
** Output. If TRUE, then any alert actions that are defined in poTaskActions
** or poScriptActions will be invoked if a threshold is breached. If FALSE,
** none of the defined actions will be invoked.
** 
** oCheckThresholds
** Output. If TRUE, the threshold breaches or state changes will be
** evaluated. If threshold breaches or states are not evaluated, then alerts
** will not be issued and alert actions will not be invoked regardless of
** whether oActionEnabled is TRUE.
** 
** oNumTaskActions
** Output. The number of task alert actions in the pTaskAction array.
** 
** poTaskActions
** A pointer to the db2AlertTaskAction structure.
** 
** oNumScriptActions
** Output. The number of script actions in the poScriptActions array.
** 
** poScriptActions
** A pointer to the db2AlertScriptAction structure.
** 
** oDefault
** Output. Indicates whether current settings are inherited from the default.
** Set to TRUE to indicate the current settings are inherited from the
** default; set to FALSE otherwise.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetAlertCfgInd
{
   db2Uint32                 ioIndicatorID; /* Health indicator identifier    */
   sqlint64                  oAlarm;        /* alarm threshold                */
   sqlint64                  oWarning;      /* warning threshold              */
   db2Uint32                 oSensitivity;  /* Min time within threshold      */
                                            /* region before alert            */
   char                      *poFormula;    /* Formula to computer health     */
                                            /* indicator                      */
   db2Uint32                 oActionEnabled; /* Alert actions enabled?        */
   db2Uint32                 oCheckThresholds; /* Threshold checking on?      */
   db2Uint32                 oNumTaskActions; /* Number of task actions       */
   struct db2AlertTaskAction *poTaskActions; /* Array of task actions         */
   db2Uint32                 oNumScriptActions; /* Number of script actions   */
   struct db2AlertScriptAction *poScriptActions; /* Array of script actions   */
   db2Uint32                 oDefault;      /* Indicate if setting returned   */
                                            /* is inherited from default.     */
} db2GetAlertCfgInd;

/* API for Getting Alert Configuration.                                       */
/* Set pParmStruct to a db2GetAlertCfgData pointer and always call            */
/* db2GetAlertCfgFree() to free the memory allocated in                       */
/* db2GetAlertCfgData.pIndicators once it is no longer needed.                */
/* To get the configuration for all health indicators:                        */
/*     - Set db2GetAlertCfgData.numIndicators to 0.    - Set                  */
/* db2GetAlertCfgData.pIndicators to NULL.                                    */
/* To get the configuration for a list of specific health indicators:         */
/*    - Set db2GetAlertCfgData.pIndicators to an array of                     */
/* db2GetAlertCfgInd which have only the indicatorID field set.               */
/*    - Set db2GetAlertCfgData.numIndicators to the length of the             */
/* pIndicators array.                                                         */
/*    In this case, the db2GetAlertCfgInd array you    submitted will be      */
/* replaced by a new array.                                                   */
/******************************************************************************
** db2GetAlertCfg API
** Returns the alert configuration settings for the health indicators.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Instance. If there is not instance attachment, a default instance
** attachment is created.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2GetAlertCfg API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2GetAlertCfgData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** If pioIndicators is left NULL, all health indicators for that object will
** be returned. This parameter can be set to an array of db2GetAlertCfgInd
** structures with the ioIndicatorID set to the health indicator we desire
** to have the configuration for. When used in this manner, be sure to set
** ioNumIndicators to the input array length and to set all other fields
** in db2GetAlertCfgInd to 0 or NULL.
** 
** All of the memory under this pointer is allocated by the engine and
** must be freed with a call to the db2GetAlertCfgFree API whenever the
** db2GetAlertCfg API returns with no error. See db2ApiDf.h, located in
** the include directory, for information about the db2GetAlertCfgFree API.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Alert Cfg                  */
  db2GetAlertCfg (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/* API for freeing memory returned by db2GetAlertCfg()  in                    */
/* db2GetAlertCfgData.pIndicators and its substructures.                      */
/******************************************************************************
** db2GetAlertCfgFree API
** Frees the memory allocated by the db2GetAlertCfg API.
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
** db2ApiDf.h
** 
** db2GetAlertCfgFree API parameters
** 
** versionNumber
** 
** Input. Specifies the version and release level of the structure
** passed in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2GetAlertCfgData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get Alert Cfg Free.            */
  db2GetAlertCfgFree (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for resetting alert configuration using the db2ResetAlertCfg     */
/* API                                                                        */
/******************************************************************************
** db2ResetAlertCfgData data structure
** db2ResetAlertCfgData data structure parameters
** 
** iObjType
** Input. Specifies the type of object for which configuration should be reset.
** Valid values (defined in db2ApiDf header file, located in the include
** directory) are:
** - DB2ALERTCFG_OBJTYPE_DBM 
** - DB2ALERTCFG_OBJTYPE_DATABASES 
** - DB2ALERTCFG_OBJTYPE_TABLESPACES 
** - DB2ALERTCFG_OBJTYPE_TS_CONTAINERS 
** - DB2ALERTCFG_OBJTYPE_DATABASE 
** - DB2ALERTCFG_OBJTYPE_TABLESPACE 
** - DB2ALERTCFG_OBJTYPE_TS_CONTAINER
** 
** piObjName 
** Input. The name of the table space or table space container when object type,
** iObjType, is set to DB2ALERTCFG_OBJTYPE_TS_CONTAINER or
** DB2ALERTCFG_OBJTYPE_TABLESPACE. The name of the tablespace container
** is defined as <tablespace-numericalID>.<tablespace-containter-name>.
** 
** piDbname 
** Input. The alias name for the database for which configuration should
** be reset when object type, iObjType, is set to
** DB2ALERTCFG_OBJTYPE_TS_CONTAINER, DB2ALERTCFG_OBJTYPE_TABLESPACE,
** and DB2ALERTCFG_OBJTYPE_DATABASE.
** 
** iIndicatorID
** Input. The health indicator for which the configuration resets are
** to apply.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ResetAlertCfgData
{
   db2Uint32                 iObjType;      /* DB2 object type                */
   char                      *piObjName;    /* Name of DB2 object             */
   char                      *piDbName;     /* Database alias                 */
   db2Uint32                 iIndicatorID;  /* Health indicator identifier.   */
                                            /* Leave 0 to reset all health    */
                                            /* indicators for the specified   */
                                            /* object.                        */
} db2ResetAlertCfgData;


/* API for Resetting Alert Configuration                                      */
/******************************************************************************
** db2ResetAlertCfg API
** Resets the health indicator settings for specific objects to the
** current defaults for that object type or resets the current default
** health indicator settings for an object type to the install defaults.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysmaint
** - sysctrl
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2ResetAlertCfg API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** 
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2ResetAlertCfgData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The current default for the object type is reset when iObjType is
** DB2ALERTCFG_OBJTYPE_DBM, DB2ALERTCFG_OBJTYPE_DATABASES,
** DB2ALERTCFG_OBJTYPE_TABLESPACES,
** DB2ALERTCFG_OBJTYPE_TS_CONTAINERS or when piObjName and
** piDbName are both NULL. If iObjType is DB2ALERTCFG_OBJTYPE_DATABASE,
** DB2ALERTCFG_OBJTYPE_TABLESPACE,
** DB2ALERTCFG_OBJTYPE_TS_CONTAINER and piDbName and piObjName (not
** needed for database) are specified, then the current settings for that
** specific object will be reset.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Reset Alert Cfg                */
  db2ResetAlertCfg (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for setting a single alert attribute using db2UpdateAlertCfg     */
/* API                                                                        */
/******************************************************************************
** db2AlertAttrib data structure
** db2AlertAttrib data structure parameters
** 
** iAttribID
** Input. Specifies the alert attribute that will be updated. Valid
** values include:
** - DB2ALERTCFG_ALARM 
** - DB2ALERTCFG_WARNING 
** - DB2ALERTCFG_SENSITIVITY 
** - DB2ALERTCFG_ACTIONS_ENABLED 
** - DB2ALERTCFG_THRESHOLD_CHECK
** 
** piAttribValue 
** Input. The new value of the alert attribute. Valid values are: 
** - DB2ALERTCFG_ALARM 
** - DB2ALERTCFG_WARNING 
** - DB2ALERTCFG_SENSITIVITY 
** - DB2ALERTCFG_ACTIONS_ENABLED 
** - DB2ALERTCFG_THRESHOLD_CHECK
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AlertAttrib
{
   db2Uint32                 iAttribID;     /* Attribute identifier           */
   char                      *piAttribValue; /* Value for the attribute       */
} db2AlertAttrib;


/* Structure for deleting an alert action                                     */
/******************************************************************************
** db2AlertActionDelete data structure
** db2AlertActionDelete data structure parameters
** 
** iActionType
** Input. Specifies the alert action. Valid values are: 
** - DB2ALERTCFG_ACTIONTYPE_SCRIPT 
** - DB2ALERTCFG_ACTIONTYPE_TASK
** 
** piName
** Input. The name of the alert action or the script action. The name of
** the script action is the absolute pathname of the script, whereas
** the name of the task action is a string in the form:
** <task-numerical-ID>.<task-numerical-suffix>.
** 
** iCondition
** The condition on which to run the action. Valid values for threshold
** based health indicators are: 
** - DB2ALERTCFG_CONDITION_ALL 
** - DB2ALERTCFG_CONDITION_WARNING 
** - DB2ALERTCFG_CONDITION_ALARM
** For state based health indicators, use the numerical value defined in sqlmon.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AlertActionDelete
{
   db2Uint32                 iActionType;   /* Type of alert action           */
   char                      *piName;       /* task name or script pathname   */
   db2Uint32                 iCondition;    /* Condition associated with      */
                                            /* task or script                 */
} db2AlertActionDelete;


/* Structure for defining an alert action update                              */
/******************************************************************************
** db2AlertActionUpdate data structure
** db2AlertActionUpdate data structure parameters
** 
** iActionType
** Input. Specifies the alert action. Valid values are: 
** - DB2ALERTCFG_ACTIONTYPE_SCRIPT 
** - DB2ALERTCFG_ACTIONTYPE_TASK
** 
** piActionName 
** Input. The alert action name. The name of a script action is the absolute
** pathname of the script. The name of a task action is a string in the form:
** <task-numberical-ID>.<task-numberical-suffix>. 
** 
** iCondition 
** The condition on which to run the action. Valid values for threshold based
** health indicators are: 
** - DB2ALERTCFG_CONDITION_ALL 
** - DB2ALERTCFG_CONDITION_WARNING 
** - DB2ALERTCFG_CONDITION_ALARM
** For state based health indicators, use the numerical value defined in sqlmon.
** 
** iNumParmUpdates 
** Input. The number of action attributes to be updated in the
** piParmUpdates array.
** 
** piParmUpdates 
** Input. A pointer to the db2AlertAttrib structure. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AlertActionUpdate
{
   db2Uint32                 iActionType;   /* Type of alert action           */
   char                      *piActionName; /* Current Task or Script name    */
                                            /* to update                      */
   db2Uint32                 iCondition;    /* Condition associated with      */
                                            /* task or script                 */
   db2Uint32                 iNumParmUpdates; /* Number of parameters to      */
                                            /* update                         */
   struct db2AlertAttrib     *piParmUpdates; /* Array of parameters to        */
                                            /* update                         */
} db2AlertActionUpdate;


/* Structure for defining a new alert action                                  */
/******************************************************************************
** db2AlertActionNew data structure
** db2AlertActionNew data structure parameters
** 
** iActionType
** Input. Specifies the alert action. Valid values are: 
** - DB2ALERTCFG_ACTIONTYPE_SCRIPT 
** - DB2ALERTCFG_ACTIONTYPE_TASK
** 
** piScriptAttribs
** Input. A pointer to the db2AlertScriptAction structure.
** 
** piTaskAttribs 
** Input. A pointer to the db2AlertTaskAction structure. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AlertActionNew
{
   db2Uint32                 iActionType;   /* Type of alert action.          */
                                            /*  Only the Attribs for that     */
                                            /* type of script will be used.   */
   struct db2AlertScriptAction *piScriptAttribs; /* Attributes of script to   */
                                            /* be created.                    */
                                            /* Use when actionType is         */
                                            /* DB2ALERTCFG_ACTIONTYPE_SCRIPT  */
   struct db2AlertTaskAction *piTaskAttribs; /* Attributes of task to be      */
                                            /* created.                       */
                                            /* Use when actionType is         */
                                            /* DB2ALERTCFG_ACTIONTYPE_TASK    */
} db2AlertActionNew;


/* Structure for Updating alert configuration using the db2UpdateAlertCfg     */
/* API                                                                        */
/******************************************************************************
** db2UpdateAlertCfgData data structure
** db2UpdateAlertCfgData data structure parameters
** 
** iObjType
** Input. Specifies the type of object for which configuration is requested.
** Valid values are:
** - DB2ALERTCFG_OBJTYPE_DBM 
** - DB2ALERTCFG_OBJTYPE_DATABASES 
** - DB2ALERTCFG_OBJTYPE_TABLESPACES 
** - DB2ALERTCFG_OBJTYPE_TS_CONTAINERS 
** - DB2ALERTCFG_OBJTYPE_DATABASE 
** - DB2ALERTCFG_OBJTYPE_TABLESPACE 
** - DB2ALERTCFG_OBJTYPE_TS_CONTAINER
** 
** piObjName 
** Input. The name of the table space or table space container when object type,
** iObjType, is set to DB2ALERTCFG_OBJTYPE_TABLESPACE or
** DB2ALERTCFG_OBJTYPE_TS_CONTAINER, otherwise set to NULL. 
** 
** piDbName 
** Input. The alias name for the database for which configuration is
** requested when object type, iObjType, is
** DB2ALERTCFG_OBJTYPE_TS_CONTAINER, DB2ALERTCFG_OBJTYPE_TABLESPACE,
** and DB2ALERTCFG_OBJTYPE_DATABASE, otherwise set to NULL. 
** 
** iIndicatorID 
** Input. The health indicator for which the configuration updates are to apply.
** 
** iNumIndAttribUpdates 
** Input. The number of alert attributes to be updated for the
** iIndicatorID health indicator. 
** 
** piIndAttribUpdates 
** Input. A pointer to the db2AlertAttrib structure array. 
** 
** iNumActionUpdates 
** Input. The number of alert actions to be updated for the iIndicatorID health
** indicator. 
** 
** piActionUpdates 
** Input. A pointer to the db2AlertActionUpdate structure array. 
** 
** iNumActionDeletes 
** Input. The number of alert actions to be deleted from the iIndicatorID health
** indicator. 
** 
** piActionDeletes 
** Input. A pointer to the db2AlertActionDelete structure array. 
** 
** iNumNewActions 
** Input. The number of new alert actions to be added to the iIndicatorID health
** indicator. 
** 
** piNewActions 
** Input. A pointer to the db2AlertActionNew structure array. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2UpdateAlertCfgData
{
   db2Uint32                 iObjType;      /* DB2 object type                */
   char                      *piObjName;    /* Name of DB2 object             */
   char                      *piDbName;     /* Database alias                 */
   db2Uint32                 iIndicatorID;  /* Health indicator to update     */
   db2Uint32                 iNumIndAttribUpdates; /* ind attrib updates      */
   struct db2AlertAttrib     *piIndAttribUpdates; /* Array of updates         */
   db2Uint32                 iNumActionUpdates; /* Num actions to update      */
   struct db2AlertActionUpdate *piActionUpdates; /* action updates            */
   db2Uint32                 iNumActionDeletes; /* Num actions to delete      */
   struct db2AlertActionDelete *piActionDeletes; /* action deletes            */
   db2Uint32                 iNumNewActions; /* Number of new actions         */
   struct db2AlertActionNew  *piNewActions; /* Array of new actions           */
} db2UpdateAlertCfgData;


/* API for setting and updating Alert Configuration                           */
/******************************************************************************
** db2UpdateAlertCfg API
** Updates the alert configuration settings for health indicators.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2UpdateAlertCfg API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2UpdateAlertCfgData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Set Alert Cfg                  */
  db2UpdateAlertCfg (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */





/* Health Monitor Recommendation Structures, Constants, and Function          */
/* Prototypes                                                                 */

/* Type of DB2 objects on which health alerts can fire                        */
/* (db2GetRecommendationsData.iObjType)                                       */
#define DB2HEALTH_OBJTYPE_DBM           0    /* DBM health indicator          */
#define DB2HEALTH_OBJTYPE_DATABASE      1    /* DB health indicator           */
#define DB2HEALTH_OBJTYPE_TABLESPACE    2    /* TS health indicator           */
#define DB2HEALTH_OBJTYPE_TS_CONTAINER  3    /* TSC health indicator          */

/* Version ID of the schema used for health recommendation XML documents.     */
/* (db2GetRecommendationsData.iSchemaVersion)                                 */
#define DB2HEALTH_RECSCHEMA_VERSION8_2  8020000 /* Health recommendation XML  */
                                             /* schema version                */

/* Structure for querying recommendations for a health indicator              */
/******************************************************************************
** db2GetRecommendationsData data structure
** db2GetRecommendationsData data structure parameters
** 
** iSchemaVersion
** Input. Version ID of the schema used to represent the XML document.
** The recommendation document will only contain elements or attributes
** that were defined for that schema version. Set this parameter to
** DB2HEALTH_RECSCHEMA_VERSION8_2
** 
** iNodeNumber
** Input. Specifies the database partition number where the health
** indicator (HI) entered an alert state. Use the constant SQLM_ALL_NODES
** to retrieve recommendations for a given object on a given HI across all
** database partitions. If the HI has the same recommendations on
** different database partitions, those recommendations will be grouped
** into a single recommendation set, where the problem is the group of HIs
** on different database partitions and the recommendations apply to all of
** these HIs. To retrieve recommendations on the current database partition,
** use the constant value SQLM_CURRENT_NODE. For standalone instances,
** SQLM_CURRENT_NODE should be used.
** 
** iIndicatorID
** Input. The health indicator that has entered an alert state and for which
** we are asking a recommendation. Values are externalized in the header file
** sqlmon.h in the include directory.
** 
** iObjType
** Input. Specifies the type of object on which the health indicator (identified
** by iIndicatorID) entered an alert state. Value values are:
** - DB2HEALTH_OBJTYPE_DBM
** - DB2HEALTH_OBJTYPE_DATABASE
** - DB2HEALTH_OBJTYPE_TABLESPACE
** - DB2HEALTH_OBJTYPE_TS_CONTAINER
** 
** piObjName
** Input. The name of the table space or table space container when the
** object type parameter, iObjType, is set to DB2HEALTH_OBJTYPE_TABLESPACE
** or DB2HEALTH_OBJTYPE_TS_CONTAINER. Specify NULL if not
** required. In the case of a table space container, the object name is
** specified as <tablespace name>.<container name>.
** 
** piDbname
** Input. The alias name for the database on which the HI entered an alert
** state when the object type parameter, iObjType, is
** DB2HEALTH_OBJTYPE_TS_CONTAINER,
** DB2HEALTH_OBJTYPE_TABLESPACE, or
** DB2HEALTH_OBJTYPE_DATABASE. Specify NULL otherwise.
** 
** poRecommendation
** Output. Character pointer that will be set to the address of a buffer in
** memory containing the recommendation text, formatted as an XML
** document according to the schema provided in
** sqllib/misc/DB2RecommendationSchema.xsd. The XML document will be
** encoded in UTF-8, and text in the document will be in the caller's locale.
** The xml:lang attribute on the DB2_HEALTH node will be set to the
** appropriate client language. The API should be considered as a trusted
** source and the XML document should not be validated. XML is used as a
** means of structuring the output data. All memory under this pointer is
** allocated by the engine and must be freed with a
** db2GetRecommendationsFree call whenever db2GetRecommendations
** returns with no error.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetRecommendationsData
{
   db2Uint32                            iSchemaVersion; /* Version ID of      */
                                             /* schema used for health        */
                                             /* recommendation XML document   */
   db2Uint32                            iNodeNumber; /* The node number       */
                                             /* where the health indicator    */
                                             /* fired                         */
   db2Uint32                            iIndicatorID; /* Health indicator     */
                                             /* identifier                    */
   db2Uint32                            iObjType; /* DB2 object type          */
   char                                 *piObjName; /* Name of DB2 object     */
   char                                 *piDbName; /* Database alias          */
   char                                 *poRecommendation; /* Health          */
                                             /* recommendation XML document   */
} db2GetRecommendationsData;

/* API for Getting Health Recommendations.                                    */
/* Set pParmStruct to a db2GetRecommendationsData pointer and always call     */
/* db2GetRecommendationsFree() to free the memory allocated in                */
/* db2GetRecommendationsData.poRecommendion once it is no longer needed.      */
/* To get recommendations on all nodes for a health indicatorthat has         */
/* entered an alter state:                                                    */
/*    - Set db2GetRecommendationsData.iNodeNumber to SQLM_ALL_NODES.          */
/* To get recommendations for a health indicator on the current node:         */
/*    - Set db2GetRecommendationsData.iNodeNumber to SQLM_CURRENT_NODE.       */
/******************************************************************************
** db2GetRecommendations API
** Retrieves a set of recommendations to resolve a health indicator in
** alert state on a particular object. The recommendations are returned
** as an XML document.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2GetRecommendations API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2GetRecommendationsData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** - Invoke this API to retrieve a set of recommendations to resolve a health
** alert on a specific DB2 object. If the input health indicator is not
** in an alert state on the object identified, an error will be returned.
** 
** - The recommendations are returned as an XML document, and contain
** information about actions and scripts that can be run to resolve the alert.
** Any scripts returned by the API must be executed on the instance on
** which the health indicator entered the alert state. For information about the
** structure and content of the recommendation XML document returned, refer
** to the schema at sqllib/misc/DB2RecommendationSchema.xsd
** 
** - All memory allocated by the engine and returned by this function (the
** recommendation document) must be freed with a
** db2GetRecommendationsFree call whenever db2GetRecommendations
** returns with no error.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Get Health Recommendations    */
  db2GetRecommendations (
   db2Uint32 versionNumber,                  /* Database version number       */
   void * pParmStruct,                       /* In/out parameters             */
   struct sqlca * pSqlca);                   /* SQLCA                         */

/* API for freeing memory returned by db2GetRecommendations()  in             */
/* db2GetRecommendationsData.poRecommendation.                                */
/******************************************************************************
** db2GetRecommendationsFree API
** Frees the memory allocated by the db2GetRecommendations API.
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
** db2ApiDf.h
** 
** db2GetRecommendationsFree API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2GetRecommendationsData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Get Health Recommendations    */
                                             /* Free.                         */
  db2GetRecommendationsFree (
   db2Uint32 versionNumber,                  /* Database version number       */
   void * pParmStruct,                       /* In/out parameters             */
   struct sqlca * pSqlca);                   /* SQLCA                         */

/* Contact Management                                                         */
/* Structures, Constants, and Function Prototypes                             */

/*  General contact macros.                                                   */
#define DB2CONTACT_MAX_SZ               128  /* maximum contact/contact       */
                                             /* group name size               */

/* Ways in which to be contacted (db2ContactData.type)                        */
#define DB2CONTACT_EMAIL                0    /* Contact via e-mail            */
#define DB2CONTACT_PAGE                 1    /* Contact via page              */

/* Contact attributes that can be configured (db2ContactAttrib.attribID)      */
#define DB2CONTACT_ADDRESS              0    /* Contact address               */
#define DB2CONTACT_TYPE                 1    /* e-mail or page                */
#define DB2CONTACT_MAXPAGELEN           2    /* max pg len in chars           */
#define DB2CONTACT_DESCRIPTION          3    /* contact description           */

/* Can either have a single contact or a group of contacts used               */
/* by(db2ContactTypeData.contactType)                                         */
#define DB2CONTACT_CONTACT              0    /* Single contact                */
#define DB2CONTACT_SINGLE               0    /* Single contact                */
#define DB2CONTACT_GROUP                1    /* Group of contacts             */


/* Structure for defining the attributes of a contact Used by                 */
/* db2GetContactsData.poContacts                                              */
/******************************************************************************
** db2ContactData data structure
** db2ContactData data structure parameters
** 
** pName
** The contact name.
** 
** type
** Specifies the type of contact. Valid values are:
** - DB2CONTACT_EMAIL
** - DB2CONTACT_PAGE
** 
** pAddress
** The address of the type parameter.
** 
** maxPageLength
** The maximum message length for when type is set to
** DB2CONTACT_PAGE.
** 
** pDescription
** User supplied description of the contact.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ContactData
{
   char                      *pName;        /* Contact name                   */
   db2Uint32                 type;          /* contact by e-mail, page        */
   char                      *pAddress;     /* e-mail or page address         */
   db2Uint32                 maxPageLength; /* Max number of characters       */
   char                      *pDescription; /* Contact description            */
} db2ContactData;

/* Structure for defining the attributes of a contact. Used by                */
/* db2AddContact.pParmStruct                                                  */
/******************************************************************************
** db2AddContactData data structure
** db2AddContactData data structure parameters
** 
** piUserid
** Input. The user name.
** 
** piPassword
** Input. The password for the user ID specified by parameter piUserid.
** 
** piName
** Input. The contact name.
** 
** iType
** Input. Specifies the type of contact. Valid values are:
** - DB2CONTACT_EMAIL
** - DB2CONTACT_PAGE
** 
** piAddress
** Input. The e-mail or pager address of the iType parameter.
** 
** iMaxPageLength
** Input. The maximum message length for when iType is set to
** DB2CONTACT_PAGE.
** 
** piDescription
** Input. User supplied description of the contact.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AddContactData
{
   char                      *piUserid;     /* User ID                        */
   char                      *piPassword;   /* Password                       */
   char                      *piName;       /* Contact name                   */
   db2Uint32                 iType;         /* contact by e-mail, page        */
   char                      *piAddress;    /* e-mail or page address         */
   db2Uint32                 iMaxPageLength; /* Max number of characters      */
   char                      *piDescription; /* Contact description           */
} db2AddContactData;


/* Structure for Getting contact information using the db2GetContacts API     */
/******************************************************************************
** db2GetContactsData data structure
** db2GetContactsData data structure parameters
** 
** ioNumContacts
** The number of poContacts.
** 
** poContacts
** Output. A pointer to the db2ContactData structure. The fields
** poContacts, pocontacts.pAddress, pocontacts.pDescription, and
** pocontacts.pName should be preallocated by the user with their
** respective maximum sizes. Call db2GetContacts with numContacts=0
** and poContacts=NULL to have the required length for poContacts
** returned in numContacts.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetContactsData
{
   db2Uint32                 ioNumContacts; /* Number of contacts gotten      */
   struct db2ContactData     *poContacts;   /* Retrieved contacts             */
} db2GetContactsData;


/* API for Getting Contacts                                                   */
/******************************************************************************
** db2GetContacts API
** Returns the list of contacts. Contacts are users to whom notification
** messages can be sent. Contacts can be either defined locally on the
** system or in a global list. The setting of the DB2 administration
** server (DAS) configuration parameter contact_host determines whether
** the list is local or global.
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
** db2ApiDf.h
** 
** db2GetContacts API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2GetContactsData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get contacts                   */
  db2GetContacts (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for specifying what contact to drop, used by db2DropContact,     */
/* db2DropContactGroup APIs                                                   */
/******************************************************************************
** db2DropContactData data structure
** db2DropContactData data structure parameters
** 
** piUserid
** Input. The user name.
** 
** piPassword
** Input. The password for piUserid.
** 
** piName
** Input. The name of the contact to be dropped.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DropContactData
{
   char                      *piUserid;     /* User ID                        */
   char                      *piPassword;   /* Password                       */
   char                      *piName;       /* Contact name                   */
} db2DropContactData;


/* API for Dropping a contact                                                 */
/******************************************************************************
** db2DropContact API
** Removes a contact from the list of contacts. Contacts are users to whom
** notification messages can be sent.
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
** db2ApiDf.h
** 
** db2DropContact API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DropContactData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Drop a contact                 */
  db2DropContact (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* API for Adding a contact                                                   */
/******************************************************************************
** db2AddContact API
** Adds a contact to the contact list. Contacts are users to whom notification
** messages can be sent. Contacts can be either defined locally on the
** system or in a global list. The setting of the DB2 administration server
** (DAS) configuration parameter, contact_host, determines whether the list
** is local or global.
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
** db2ApiDf.h
** 
** db2AddContact API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2AddContactData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Add a contact                  */
  db2AddContact (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for setting a single contact attribute using db2UpdateContact    */
/* API                                                                        */
/******************************************************************************
** db2ContactAttrib data structure
** db2ContactAttrib data structure parameters
** 
** iAttribID
** Input. Specifies the contact attribute. Valid values are: 
** - DB2CONTACT_ADDRESS 
** - DB2CONTACT_TYPE 
** - DB2CONTACT_MAXPAGELEN 
** - DB2CONTACT_DESCRIPTION
** 
** piAttribValue 
** Input. The new value of the contact attribute. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ContactAttrib
{
   db2Uint32                 iAttribID;     /* Attribute identifier           */
   char                      *piAttribValue; /* Value for the attribute       */
} db2ContactAttrib;


/* Structure for specifying contact info to update, used by db2UpdateContact  */
/* API                                                                        */
/******************************************************************************
** db2UpdateContactData data structure
** db2UpdateContactData data structure parameters
** 
** piContactName 
** Input. Specifies the name of the contact to be updated. 
** 
** iNumAttribsUpdated 
** Input. The number attributes to be updated. 
** 
** piAttribs 
** Input. A pointer to the db2ContactAttrib structure. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2UpdateContactData
{
   char                      *piUserid;     /* User ID                        */
   char                      *piPassword;   /* Password                       */
   char                      *piContactName; /* Contact name                  */
   db2Uint32                 iNumAttribsUpdated; /* contact attrib updates    */
   struct db2ContactAttrib   *piAttribs;    /* Attribute updates              */
} db2UpdateContactData;


/* API for updating a contact                                                 */
/******************************************************************************
** db2UpdateContact API
** Updates the attributes of a contact. Contacts are users to whom notification
** messages can be sent. Contacts can be either defined locally on the
** system or in a global list. The setting of the DB2 administration server
** (DAS) configuration parameter contact_host determines whether the list is
** local or global.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2UpdateContact API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2UpdateContactData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update a contact               */
  db2UpdateContact (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for specifying either a single or group contact                  */
/******************************************************************************
** db2ContactTypeData data structure
** db2ContactTypeData data structure parameters
** 
** contactType
** Specifies the type of contact. Valid values are:
** - DB2CONTACT_SINGLE
** - DB2CONTACT_GROUP
** 
** pName
** The contact group name, or the contact name if contactType is set to
** DB2CONTACT_SINGLE.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ContactTypeData
{
   db2Uint32                 contactType;   /* Contact or group               */
   char                      *pName;        /* Contact or group name          */
} db2ContactTypeData;


/* Structure for getting contact group info, used by db2GetContactGroup APIs  */
/******************************************************************************
** db2ContactGroupData data structure
** db2ContactGroupData data structure parameters
** 
** pGroupName
** Input. The name of the group to be retrieved.
** 
** pDescription
** The description of the group.
** 
** numContacts
** The number of pContacts.
** 
** pContacts
** A pointer to the db2ContactTypeData structure. The fields pGroupName,
** pDescription, pContacts, and pContacts.pName should be preallocated
** by the user with their respective maximum sizes. Call
** db2GetContactGroup with numContacts=0 and pContacts=NULL to have
** the required length for pContacts returned in numContacts.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ContactGroupData
{
   char                      *pGroupName;   /* Contact group name             */
   char                      *pDescription; /* Contact group description      */
   db2Uint32                 numContacts;   /* Number of contacts in group    */
   struct db2ContactTypeData *pContacts;    /* Contacts in group              */
} db2ContactGroupData;

/* Structure for adding contact group info, used by db2AddContactGroup APIs   */
/******************************************************************************
** db2AddContactGroupData data structure
** db2AddContactGroupData data structure parameters
** 
** piUserid
** Input. The user name.
** 
** piPassword
** Input. The password for piUserid.
** 
** piGroupName
** Input. The name of the group to be retrieved.
** 
** piDescription
** Input. The description of the group.
** 
** iNumContacts
** Input. The number of piContacts.
** 
** piContacts
** A pointer to the db2ContactTypeData structure.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2AddContactGroupData
{
   char                      *piUserid;     /* User id                        */
   char                      *piPassword;   /* Password                       */
   char                      *piGroupName;  /* Contact group name             */
   char                      *piDescription; /* Contact group description     */
   db2Uint32                 iNumContacts;  /* Number of contacts in group    */
   struct db2ContactTypeData *piContacts;   /* Contacts in group              */
} db2AddContactGroupData;


/* API for retrieving a contact group                                         */
/******************************************************************************
** db2GetContactGroup API
** Returns the contacts included in a single contact group. Contacts are
** users to whom notification messages can be sent. Contacts can be
** either defined locally on the system or in a global list. The setting
** of the DB2 administration server (DAS) configuration parameter
** contact_host determines whether the list is local or global.
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
** db2ApiDf.h
** 
** db2GetContactGroup API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2ContactGroupData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Retrieve a contact group       */
  db2GetContactGroup (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for specifying info on a contact group                           */
/******************************************************************************
** db2ContactGroupDesc data structure
** db2ContactGroupDesc data structure parameters
** 
** poName
** Output. The group name. This parameter should be preallocated by the
** caller with the respective maximum size.
** 
** poDescription
** Output. The group description. This parameter should be preallocated by
** the caller with the respective maximum size.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ContactGroupDesc
{
   char                      *poName;       /* Group name                     */
   char                      *poDescription; /* Group description             */
} db2ContactGroupDesc;


/* Structure for getting contact groups, used by db2GetContactGroups API      */
/******************************************************************************
** db2GetContactGroupsData data structure
** db2GetContactGroupsData data structure parameters
** 
** ioNumGroups
** The number of groups. If oNumGroups = 0 and poGroups = NULL, it will
** contain the number of db2ContactGroupDesc structures needed in
** poGroups.
** 
** poGroups
** Output. A pointer to the db2ContactGroupDesc structure.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetContactGroupsData
{
   db2Uint32                 ioNumGroups;   /* Number of groups gotten        */
   struct db2ContactGroupDesc *poGroups;    /* List of groups                 */
} db2GetContactGroupsData;


/* API for retrieving contact groups                                          */
/******************************************************************************
** db2GetContactGroups API
** Returns the list of contact groups. Contacts are users to whom notification
** messages can be sent. Contact groups can be either defined locally on the
** system or in a global list. The setting of the DB2 administration
** server (DAS) configuration parameter contact_host determines whether
** the list is local or global.
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
** db2ApiDf.h
** 
** db2GetContactGroups API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2GetContactGroupsData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Retrieve contact groups        */
  db2GetContactGroups (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* API for dropping a contact group                                           */
/******************************************************************************
** db2DropContactGroup API
** Removes a contact group from the list of contacts. A contact group
** contains a list of users to whom notification messages can be sent.
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
** db2ApiDf.h
** 
** db2DropContactGroup API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DropContactData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Remove a contact group         */
  db2DropContactGroup (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* API for adding a new contact group                                         */
/******************************************************************************
** db2AddContactGroup API
** Adds a new contact group to the list of contact groups. A contact group
** contains a list of users to whom notification messages can be sent.
** Contact groups can be either defined locally on the system or in a
** global list. The setting of the DB2 administration server (DAS)
** configuration parameter contact_host determines whether the list
** is local or global.
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
** db2ApiDf.h
** 
** db2AddContactGroup API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2AddContactGroupData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Add a new contact group        */
  db2AddContactGroup (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for specifying updates to a contact group, used by               */
/* db2UpdateContactGroup API                                                  */
/******************************************************************************
** db2UpdateContactGroupData data structure
** db2UpdateContactGroupData data structure parameters
** 
** piUserid
** Input. The user name. 
** 
** piPassword 
** Input. The password for piUserid. 
** 
** piGroupName 
** Input. The name of the contact group to update. 
** 
** iNumNewContacts 
** Input. The number of new contacts to be added to the group 
** 
** piNewContacts 
** Input. A pointer to the db2ContactTypeData structure. 
** 
** iNumDroppedContacts 
** Input. The number of contacts in the group to be dropped. 
** 
** piDroppedContacts 
** Input. A pointer to the db2ContactTypeData structure. 
** 
** piNewDescription 
** Input. The new description for the group. Set this parameter to NULL if 
** the old description should not be changed.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2UpdateContactGroupData
{
   char                      *piUserid;     /* User ID                        */
   char                      *piPassword;   /* Password                       */
   char                      *piGroupName;  /* Group name                     */
   db2Uint32                 iNumNewContacts; /* Number of new contacts       */
   struct db2ContactTypeData *piNewContacts; /* Contacts to be added          */
   db2Uint32                 iNumDroppedContacts; /* Number of contacts       */
                                            /* dropped                        */
   struct db2ContactTypeData *piDroppedContacts; /* Contacts to be dropped    */
   char                      *piNewDescription; /* New group description      */
} db2UpdateContactGroupData;


/* API for updating a contact group                                           */
/******************************************************************************
** db2UpdateContactGroup API
** Updates the attributes of a contact group. A contact group contains a
** list of users to whom notification messages can be sent. Contact
** groups can be either defined locally on the system or in a global
** list. The setting of the DB2 administration server (DAS)
** configuration parameter contact_host determines whether the list is
** local or global.
** 
** Authorization
** 
** None.
** 
** Required connection
** 
** None.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2UpdateContactGroup API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2ResetMonitorData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Update a contact group         */
  db2UpdateContactGroup (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */



/* Health Notification Contact List Management Structures, Constants, and     */
/* Function Prototypes                                                        */

/* Types of notification contact list updates                                 */
/* (db2HealthNotificationListUpdate.updateType)                               */
#define DB2HEALTHNOTIFICATIONLIST_ADD   0    /* add a contact                 */
#define DB2HEALTHNOTIFICATIONLIST_DROP  1    /* drop a contact                */


/* Structure for retrieving notification contact list, used by                */
/* db2GetHealthNotificationList API                                           */
/******************************************************************************
** db2GetHealthNotificationListData data structure
** db2GetHealthNotificationListData data structure parameters
** 
** ioNumContacts
** The number of contacts. If the API was called with a NULL poContact,
** then ioNumContacts will be set to the number of contacts the user
** should allocate to perform a successful call.
** 
** poContacts
** Output. A pointer to the db2ContactTypeData structure.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2GetHealthNotificationListData
{
   db2Uint32                 ioNumContacts; /* Number of contacts in list     */
   struct db2ContactTypeData *poContacts;   /* Contacts in notification list  */
} db2GetHealthNotificationListData;


/* API for retrieving health notification contact list                        */
/* The parameter pParmStruct accepts a pointer to a                           */
/* db2GetHealthNotificationListData structure which must contain a            */
/* sufficiently large array of db2ContactTypeData.                            */
/* Every db2ContactTypeData in the array must have a pre-allocated pName      */
/* buffer of size DB2CONTACT_MAX_SZ+1. If the array specified in poContacts   */
/* is too small then an error will be returned with the required array        */
/* length returned in oNumContacts. Call with poContacts = NULL and           */
/* oNumContacts = 0 to receive the current number of db2ContactTypeData to    */
/* submit.                                                                    */
/******************************************************************************
** db2GetHealthNotificationList API
** Returns the list of contacts and/or contact groups that are notified
** about the health of an instance. A contact list consists of e-mail
** addresses or pager internet addresses of individuals who are to be
** notified when non-normal health conditions are present for an
** instance or any of its database objects.
** 
** Authorization
** 
** None
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2GetHealthNotificationList API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2GetHealthNotificationListData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Retrieve Notification List     */
  db2GetHealthNotificationList (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */


/* Structure for specifying an update to the notification contact list        */
/******************************************************************************
** db2HealthNotificationListUpdate data structure
** db2HealthNotificationListUpdate data structure parameters
** 
** iUpdateType
** Input. Specifies the type of update. Valid values are: 
** - DB2HEALTHNOTIFICATIONLIST_ADD 
** - DB2HEALTHNOTIFICATIONLIST_DROP
** 
** piContact 
** Input. A pointer to the db2ContactTypeData structure. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2HealthNotificationListUpdate
{
   db2Uint32                 iUpdateType;   /* add or drop                    */
   struct db2ContactTypeData *piContact;    /* Contact to add/drop            */
} db2HealthNotificationListUpdate;


/* Structure specifying updates to the health notification contact list,      */
/* Used by db2UpdateHealthNotificationList API                                */
/******************************************************************************
** db2UpdateHealthNotificationListData data structure
** db2UpdateHealthNotificationListData data structure parameters
** 
** iNumUpdates
** Input. The number of updates. 
** 
** piUpdates 
** Input. A pointer to the db2HealthNotificationListUpdate structure. 
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2UpdateHealthNotificationListData
{
   db2Uint32                 iNumUpdates;   /* Number of list updates         */
   struct db2HealthNotificationListUpdate *piUpdates; /* List updates         */
} db2UpdateHealthNotificationListData;


/* API for updating health notification contact list.                         */
/* The parameter pParmStruct accepts a pointer to a                           */
/* db2UpdateHealthNotificationListData which in turn must contain anarray of  */
/* db2HealthNotificationListUpdate with the update information.               */
/******************************************************************************
** db2UpdateHealthNotificationList API
** Updates the contact list for notification about health alerts issued by
** an instance.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** - sysmaint
** 
** Required connection
** 
** Instance. If there is no instance attachment, a default instance
** attachment is created.
** 
** API include file
** 
** db2ApiDf.h
** 
** db2UpdateHealthNotificationList API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2UpdateHealthNotificationListData structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Updates Notification List      */
  db2UpdateHealthNotificationList (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/******************************************************************************
** db2GetNodeInfoData data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2GetNodeInfoData
{
   db2int32                  *poMyNodeNumber; /* Pointer to output node       */
                                            /* number                         */
   db2int32                  *poCurNumNodes; /* Pointer to number of nodes    */
} db2GetNodeInfoData;

/******************************************************************************
** db2GetNodeInfo API
*******************************************************************************/
SQL_API_RC SQL_API_FN                       /* Get node information           */
  db2GetNodeInfo (
   db2Uint32 versionNumber,                 /* Database version number        */
   void * pParmStruct,                      /* In/out parameters              */
   struct sqlca * pSqlca);                  /* SQLCA                          */

/* Update Alternate Server Parameter Structure                                */
/******************************************************************************
** db2UpdateAltServerStruct data structure
** db2UpdateAltServerStruct data structure parameters
** 
** piDbAlias
** Input. A string containing an alias for the database.
** 
** piHostName
** Input. A string containing the host name or the IP address of the node where
** the alternate server for the database resides. The host name is the
** name of the node that is known to the TCP/IP network. The maximum
** length of the host name is 255 characters.
** 
** piPort
** Input. The port number of the alternate server database manager instance. The
** maximum length of the port number is 14 characters.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2UpdateAltServerStruct
{
   char                      *piDbAlias;    /* Input: database alias          */
   char                      *piHostName;   /* Input: host name               */
   char                      *piPort;       /* Input: port number             */
} db2UpdateAltServerStruct;

/* Update Alternate Server API                                                */
/******************************************************************************
** db2UpdateAlternateServerForDB API
** Updates the alternate server for a database alias in the system
** database directory.
** 
** Scope
** 
** This API affects the system database directory.
** 
** Authorization
** 
** One of the following:
** - sysadm
** - sysctrl
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** db2UpdateAlternateServerForDB API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed as the
** second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2UpdateAltServerStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** The API will only be applied to the system database directory.
** 
** The API should only be used on a server. If it is issued on a client,
** it will be ignored and warning SQL1889W will be issued.
** 
** If LDAP (Lightweight Directory Access Protocol) support is enabled
** on the current machine, the alternate server for the database will
** automatically be updated in the LDAP directory.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Update Alternate Server             */
  db2UpdateAlternateServerForDB (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Update Alternate Server Structure                                  */
/******************************************************************************
** db2gUpdateAltServerStruct data structure
** db2gUpdateAltServerStruct data structure specific parameters
** 
** iDbAlias_len
** Input. The length in bytes of piDbAlias.
** 
** iHostName_len
** Input. The length in bytes of piHostName.
** 
** iPort_len
** Input. The length in bytes of piPort.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gUpdateAltServerStruct
{
   db2Uint32                 iDbAlias_len;  /* Input: database alias length   */
   char                      *piDbAlias;    /* Input: database alias          */
   db2Uint32                 iHostName_len; /* Input: host name length        */
   char                      *piHostName;   /* Input: host name               */
   db2Uint32                 iPort_len;     /* Input: port number length      */
   char                      *piPort;       /* Input: port number             */
} db2gUpdateAltServerStruct;

/* Generic Update Alternate Server API                                        */
/******************************************************************************
** db2gUpdateAlternateServerForDB API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Update Alternate Server     */
  db2gUpdateAlternateServerForDB (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Open Database Directory Scan Parameter Structure                           */
/******************************************************************************
** db2DbDirOpenScanStruct data structure
** db2DbDirOpenScanStruct data structure parameters
** 
** piPath
** Input. The name of the path on which the local database directory
** resides. If the specified path is a NULL pointer, the system database
** directory is used.
** 
** oHandle
** Output. A 2-byte area for the returned identifier. This identifier must be
** passed to the db2DbDirGetNextEntry API for scanning the database entries,
** and to the db2DbDirCloseScan API to release the resources.
** 
** oNumEntries
** Output. A 2-byte area where the number of directory entries is returned.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DbDirOpenScanStruct
{
   char                      *piPath;       /* Input: drive/path              */
   db2Uint16                 oHandle;       /* Output: handle                 */
   db2Uint16                 oNumEntries;   /* Output: count                  */
} db2DbDirOpenScanStruct;

/* Open Database Directory Scan API                                           */
/******************************************************************************
** db2DbDirOpenScan API
** Stores a copy of the system database directory or the local database
** directory in memory, and returns the number of entries. This copy
** represents a snapshot of the directory at the time the directory is
** opened. This copy is not updated, even if the directory itself is
** changed later.
** 
** Use the db2DbDirGetNextEntry API to advance through the database
** directory, examining information about the database entries. Close
** the scan using the db2DbDirCloseScan API. This removes the copy of
** the directory from memory.
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
** db2ApiDf.h
** 
** db2DbDirOpenScan API parameters
** 
** versionNumber
** 
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DbDirOpenScanStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** Storage allocated by this API is freed by the db2DbDirCloseScan API.
** 
** Multiple db2DbDirOpenScan APIs can be issued against the same directory.
** However, the results may not be the same. The directory may change between
** openings.
** 
** There can be a maximum of eight opened database directory scans per process.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Open Database Directory Scan        */
  db2DbDirOpenScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Open Database Directory Scan Parameter Structure                   */
/******************************************************************************
** db2gDbDirOpenScanStruct data structure
** db2gDbDirOpenScanStruct data structure specific parameters
** 
** iPath_len
** Input. The length in bytes of the piPath parameter.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gDbDirOpenScanStruct
{
   db2Uint32                 iPath_len;     /* Input: drive/path length       */
   char                      *piPath;       /* Input: drive/path              */
   db2Uint16                 oHandle;       /* Output: handle                 */
   db2Uint16                 oNumEntries;   /* Output: count                  */
} db2gDbDirOpenScanStruct;


/* Generic Open Database Directory Scan API                                   */
/******************************************************************************
** db2gDbDirOpenScan API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Open Database Directory     */
                                       /* Scan                                */
  db2gDbDirOpenScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Get Next Database Directory Entry Data Structure                           */
/******************************************************************************
** db2DbDirInfoV9 data structure
** db2DbDirInfoV9 data structure parameters
** 
** alias
** An alternate database name.
** 
** dbname
** The name of the database.
** 
** drive
** The local database directory path name where the database resides. This
** field is returned only if the system database directory is opened for scan.
** 
** intname
** A token identifying the database subdirectory. This field is returned only if
** the local database directory is opened for scan.
** 
** nodename
** The name of the node where the database is located. This field is
** returned only if the cataloged database is a remote database.
** 
** dbtype
** Database manager release information.
** 
** comment
** The comment associated with the database.
** 
** com_codepage
** The code page of the comment. Not used.
** 
** type
** Entry type. Valid values are:
** - SQL_INDIRECT
** Database created by the current instance (as defined by the
** value of the DB2INSTANCE environment variable).
** - SQL_REMOTE
** Database resides at a different instance.
** - SQL_HOME
** Database resides on this volume (always HOME in local
** database directory).
** - SQL_DCE
** Database resides in DCE directories.
** 
** authentication
** Authentication type. Valid values are:
** - SQL_AUTHENTICATION_SERVER
** Authentication of the user name and password takes place at the
** server.
** - SQL_AUTHENTICATION_CLIENT
** Authentication of the user name and password takes place at the
** client.
** - SQL_AUTHENTICATION_DCS
** Used for DB2 Connect.
** - SQL_AUTHENTICATION_DCE
** Authentication takes place using DCE Security Services.
** - SQL_AUTHENTICATION_KERBEROS
** Authentication takes place using Kerberos Security Mechanism.
** - SQL_AUTHENTICATION_NOT_SPECIFIED
** DB2 no longer requires authentication to be kept in the database
** directory. Specify this value when connecting to anything other
** than a down-level (DB2 V2 or less) server.
** - SQL_AUTHENTICATION_SVR_ENCRYPT
** Specifies that authentication takes place on the node containing
** the target database, and that the authentication password is to
** be encrypted.
** - SQL_AUTHENTICATION_DATAENC
** Specifies that authentication takes place on the node containing
** the target database, and that connections must use data
** encryption.
** - SQL_AUTHENTICATION_GSSPLUGIN
** Specifies that authentication takes place using an external GSS
** API-based plug-in security mechanism.
** 
** glbdbname
** The global name of the target database in the global (DCE) directory, if
** the entry is of type SQL_DCE.
** 
** dceprincipal
** The principal name if the authentication is of type DCE or KERBEROS.
** 
** cat_nodenum
** Catalog node number.
** 
** nodenum
** Node number.
** 
** althostname
** The hostname or IP address of the alternate server where the database is
** reconnected at failover time.
** 
** altportnumber
** The port number of the alternate server where the database is
** reconnected at failover time.
** 
*******************************************************************************/
SQL_STRUCTURE db2DbDirInfoV9
{
   _SQLOLDCHAR               alias[SQL_ALIAS_SZ]; /* Alias name               */
   _SQLOLDCHAR               dbname[SQL_DBNAME_SZ]; /* Database name          */
   _SQLOLDCHAR               drive[SQL_DB_PATH_SZ]; /* Drive/Path             */
   _SQLOLDCHAR               intname[SQL_INAME_SZ]; /* Database subdirectory  */
   _SQLOLDCHAR               nodename[SQL_NNAME_SZ]; /* Node name             */
   _SQLOLDCHAR               dbtype[SQL_DBTYP_SZ]; /* Release information     */
   _SQLOLDCHAR               comment[SQL_CMT_SZ]; /* Comment                  */
   short                     com_codepage;  /* Code page of comment           */
   _SQLOLDCHAR               type;          /* Entry type - defines above     */
   unsigned short            authentication; /* Authentication type           */
   char                      glbdbname[SQL_DIR_NAME_SZ]; /* Global database   */
                                            /* name                           */
   _SQLOLDCHAR               dceprincipal[SQL_DCEPRIN_SZ]; /* dce principal   */
                                            /* bin string                     */
   short                     cat_nodenum;   /* Catalog node number            */
   short                     nodenum;       /* Node number                    */
   _SQLOLDCHAR               althostname[SQL_HOSTNAME_SZ]; /* Alternate       */
                                            /* hostname                       */
   _SQLOLDCHAR               altportnumber[SQL_SERVICE_NAME_SZ]; /* Port      */
                                            /* number                         */
};

/******************************************************************************
** db2DbDirInfo data structure
** 
** db2DbDirInfo has been deprecated but is kept to preserve compatibility for
** applications that invoke the db2DbDirGetNextEntry/db2gDbDirGetNextEntry API
** with a downlevel version number of less than SQL_REL9000.  db2DbDirInfo will
** be removed in a future release.  New applications should invoke the
** db2DbDirGetNextEntry/db2gDbDirGetNextEntry API with a version number of no
** less than SQL_REL9000 and its required pParmStruct value.
** 
*******************************************************************************/
SQL_STRUCTURE db2DbDirInfo
{
   _SQLOLDCHAR               alias[SQL_ALIAS_SZ]; /* Alias name               */
   _SQLOLDCHAR               dbname[SQL_DBNAME_SZ]; /* Database name          */
   _SQLOLDCHAR               drive[SQL_DRIVE_SZ]; /* Drive/Path               */
   _SQLOLDCHAR               intname[SQL_INAME_SZ]; /* Database subdirectory  */
   _SQLOLDCHAR               nodename[SQL_NNAME_SZ]; /* Node name             */
   _SQLOLDCHAR               dbtype[SQL_DBTYP_SZ]; /* Release information     */
   _SQLOLDCHAR               comment[SQL_CMT_SZ]; /* Comment                  */
   short                     com_codepage;  /* Code page of comment           */
   _SQLOLDCHAR               type;          /* Entry type - defines above     */
   unsigned short            authentication; /* Authentication type           */
   char                      glbdbname[SQL_DIR_NAME_SZ]; /* Global database   */
                                            /* name                           */
   _SQLOLDCHAR               dceprincipal[SQL_DCEPRIN_SZ]; /* dce principal   */
                                            /* bin string                     */
   short                     cat_nodenum;   /* Catalog node number            */
   short                     nodenum;       /* Node number                    */
   _SQLOLDCHAR               althostname[SQL_HOSTNAME_SZ]; /* Alternate       */
                                            /* hostname                       */
   _SQLOLDCHAR               altportnumber[SQL_SERVICE_NAME_SZ]; /* Port      */
                                            /* number                         */
};

/* Get Next Database Directory Entry Parameter Structure                      */
/******************************************************************************
** db2DbDirNextEntryStructV9 data structure
** db2DbDirNextEntryStructV9 data structure parameters
** 
** iHandle
** Input. Identifier returned from the associated db2DbDirOpenScan API.
** 
** poDbDirEntry
** Output. A pointer to a db2DbDirInfoV9 structure. The space for the
** directory data is allocated by the API, and a pointer to that space is
** returned to the caller.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DbDirNextEntryStructV9
{
   db2Uint16                 iHandle;       /* Input: handle                  */
   struct db2DbDirInfoV9     *poDbDirEntry; /* Output: buffer                 */
} db2DbDirNextEntryStructV9;

/******************************************************************************
** db2DbDirNextEntryStruct data structure
** 
** db2DbDirNextEntryStruct has been deprecated but is kept to preserve
** compatibility for applications that invoke the db2DbDirGetNextEntry API with
** a downlevel version number of less than SQL_REL9000.  db2DbDirNextEntryStruct
** will be removed in a future release.  New applications should invoke the
** db2DbDirGetNextEntry API with a version number of no less than SQL_REL9000 and
** its required pParmStruct value.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DbDirNextEntryStruct
{
   db2Uint16                 iHandle;       /* Input: handle                  */
   struct db2DbDirInfo       *poDbDirEntry; /* Output: buffer                 */
} db2DbDirNextEntryStruct;

/* Get Next Database Directory Entry API                                      */
/******************************************************************************
** db2DbDirGetNextEntry API
** Returns the next entry in the system database directory or the local database
** directory copy returned by db2DbDirOpenScan. Subsequent calls to this API
** return additional entries.
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
** db2ApiDf.h
** 
** db2DbDirGetNextEntry API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DbDirGetNextEntryStruct structure if versionNumber
** is lower than SQL_REL9000 or a pointer to the
** db2DbDirGetNextEntryStructV9 structure otherwise.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
** Usage notes
** 
** All fields of the directory entry information buffer are padded to the
** right with blanks.
** 
** A subsequent db2DbDirGetNextEntry obtains the entry following the
** current entry.
** 
** The sqlcode value of sqlca is set to 1014 if there are no more entries
** to scan when db2DbDirGetNextEntry is called.
** 
** The count value returned by the db2DbDirOpenScan API can be used to scan
** through the entire directory by issuing db2DbDirGetNextEntry calls, one
** at a time, until the number of scans equals the count of entries.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Get Next Database Directory Entry   */
  db2DbDirGetNextEntry (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Get Next Database Directory Entry Parameter Structure              */
/******************************************************************************
** db2gDbDirNextEntryStrV9 data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gDbDirNextEntryStrV9
{
   db2Uint16                 iHandleV9;     /* Input: handle                  */
   struct db2DbDirInfoV9     *poDbDirEntryV9; /* Output: buffer               */
} db2gDbDirNextEntryStrV9;

/******************************************************************************
** db2gDbDirNextEntryStruct data structure
** 
** db2gDbDirNextEntryStruct has been deprecated but is kept to preserve
** compatibility for applications that invoke the db2gDbDirGetNextEntry API
** with a downlevel version number of less than SQL_REL9000.
** db2gDbDirNextEntryStruct will be removed in a future release.  New
** applications should invoke the db2gDbDirGetNextEntry API with a version
** number of no less than SQL_REL9000 and its required pParmStruct value.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2gDbDirNextEntryStruct
{
   db2Uint16                 iHandle;       /* Input: handle                  */
   struct db2DbDirInfo       *poDbDirEntry; /* Output: buffer                 */
} db2gDbDirNextEntryStruct;

/* Generic Get Next Database Directory Entry API                              */
/******************************************************************************
** db2gDbDirGetNextEntry API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Get Next Database           */
                                       /* Directory Entry                     */
  db2gDbDirGetNextEntry (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Close Database Directory Scan Parameter Structure                          */
/******************************************************************************
** db2DbDirCloseScanStruct data structure
** db2DbDirCloseScanStruct data structure parameters
** 
** iHandle
** Input. Identifier returned from the associated db2DbDirOpenScan API.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DbDirCloseScanStruct
{
   db2Uint16                 iHandle;       /* Input: handle                  */
} db2DbDirCloseScanStruct;

/* Close Database Directory Scan API                                          */
/******************************************************************************
** db2DbDirCloseScan API
** Frees the resources allocated by db2DbDirOpenScan.
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
** db2ApiDf.h
** 
** db2DbDirCloseScan API parameters
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** in as the second parameter, pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DbDirCloseScanStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Close Database Directory Scan       */
  db2DbDirCloseScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* Generic Close Database Directory Scan Parameter Structure                  */
/******************************************************************************
** db2gDbDirCloseScanStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2gDbDirCloseScanStruct
{
   db2Uint16                 iHandle;       /* Input: handle                  */
} db2gDbDirCloseScanStruct;

/* Generic Close Database Directory Scan API                                  */
/******************************************************************************
** db2gDbDirCloseScan API
*******************************************************************************/
SQL_API_RC SQL_API_FN                  /* Generic Close Database Directory    */
                                       /* Scan                                */
  db2gDbDirCloseScan (
       db2Uint32 versionNumber,        /* Database version number             */
       void * pParmStruct,             /* In/out parameters                   */
       struct sqlca * pSqlca);         /* SQLCA                               */

/* db2QpGetUserInformation                                                    */

/******************************************************************************
** db2QpGetUserInfoStruct data structure
*******************************************************************************/
typedef SQL_STRUCTURE db2QpGetUserInfoStruct
{
  char              *poReplyBuffer;   /* Output:Information buffer provided   */
                                      /* by caller                            */
  db2Uint32         ioReplyBufSize;   /* Input/Output: Reply buffer size      */
                                      /* Filled buffer size                   */
  db2Uint32         oStatus;          /* Output: Status of QP call            */
} db2QpGetUserInfoStruct;


/******************************************************************************
** db2QpGetUserInformation API
*******************************************************************************/
/* db2QpGetUserInformation API                                                */
SQL_API_RC SQL_API_FN                        /* Get QP user information       */
  db2QpGetUserInformation (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* db2QpGetUserInfoStruct to be  */
                                             /* returned                      */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* Converts a previous (Version 8.x or higher) version of DB2 a database to   */
/* the current version                                                        */

/* Values for upgradeFlags                                                    */
#define      DB2DBUPGRADE_NONE 0x0           /* No options                    */
#define      DB2DBUPGRADE_REBINDALL 0x1      /* Rebind invalid packages       */

/******************************************************************************
** db2DatabaseUpgradeStruct data parameters
** 
** piDbAlias
** Input. A string containing the alias of the database that is cataloged in
** the system database directory.
** 
** piUserName
** Input. A string containing the user name of the application. May be NULL.
** 
** piPassword
** Input. A string containing the password of the supplied user name (if any).
** May be NULL.
** 
** iDbAliasLen
** Input. A 2-byte unsigned integer representing the length in bytes of the 
** database alias.
** 
** iUserNameLen
** Input. A 2-byte unsigned integer representing the length in bytes of the user
** name. Set to zero when no user name is supplied.
** 
** iPasswordLen
** Input. A 2-byte unsigned integer representing the length in bytes of the 
** password. Set to zero when no password is supplied.
** 
** upgradeFlags
** Input. Database upgrade options. Valid values(defined in db2ApiDf header
**  file, located in the include directory) are: 
** - DB2DBUPGRADE_REBINDALL 
** Rebind invalid packages during database upgrade.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DatabaseUpgradeStruct
{
             char          *piDbAlias;       /* Input: the alias of the       */
                                             /* database                      */
             char          *piUserName;      /* Input: username               */
             char          *piPassword;      /* Input: password               */
             db2Uint16     iDbAliasLen;      /* Input: the length of the      */
                                             /* alias                         */
             db2Uint16     iUserNameLen;     /* Input: the length of the      */
                                             /* username                      */
             db2Uint16     iPasswordLen;     /* Input: the length of the      */
                                             /* password                      */
             db2Uint32     upgradeFlags;     /* Input: database upgrade       */
                                             /* options                       */
} db2DatabaseUpgradeStruct;


/* db2DatabaseUpgrade API                                                     */
/******************************************************************************
** db2DatabaseUpgrade API parameters
** 
** Converts a previous (Version 8.x or higher) version of DB2 a database to
** the current versions.
** 
** Authorization
** sysadm
** 
** Required connection
** This API establishes a database connection.
** 
** API include file
** db2ApiDf.h
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed 
** as the second parameter pParmStruct.
** 
** pParmStruct
** Input. A pointer to the db2DatabaseUpgradeStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* upgrade database              */
  db2DatabaseUpgrade (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* db2DatabaseUpgradeStruct      */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2DeactivateDbStruct data structure parameters
** 
** A pointer to this struct type needs to be passed as the second
** argument to the db2DeactivateDb API
** piDbAlias
** Input. The alias for the database to be deactivated
** 
** piUserName
** Input. The username with the appropriate privilege to deactivate the database
** 
** piPassword
** Input. The password for the user issuing the deactivate database
** 
** iOptions
** Input. Represents if it is a global deactivate or deactivate at a single member or
** deactivate at a member by force
** 
** iNumMembers
** Input. Number of members in pMemberList. For per-member deactivate, the value must be 1
** 
** pMemberListInput. For per-member database deactivation, this param represnets the member list
** For per-member deactivation only one member should exist in the list
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2DeactivateDbStruct
{
             char          *piDbAlias;       /* Input: the alias of the       */
                                             /* database                      */
             char          *piUserName;      /* Input: username               */
             char          *piPassword;      /* Input: password               */
             db2Uint32     iOptions;         /* Input: specifies if           */
                                             /* deactivate is per-member      */
                                             /* global or by force            */
             db2Uint32     iNumMembers;      /* Input: number of members in   */
                                             /* the member list               */
             SQL_PDB_NODE_TYPE *piMemberList; /* Member list                  */
} db2DeactivateDbStruct;


#define      DB2_DEACTIVATE_DB_MEMBER 0x1    /* Deactivate the database at a  */
                                             /* single member                 */
#define      DB2_DEACTIVATE_DB_FORCE 0x2     /* Deactivate the database at a  */
                                             /* member by force               */
/* db2DeactivateDb API                                                        */
/******************************************************************************
** db2DeactivateDb API parameters
** 
** Deactivates the specified database globally or at a specified member
** 
** Authorization
** sysadm
** 
** Required connection
** None
** 
** API include file
** db2ApiDf.h
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed
** 
** pParmStruct
** Input. A pointer to the db2DeactivateDbStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure, with the return code from the API.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* deactivate database           */
  db2DeactivateDb (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Pointer to                    */
                                             /* db2DeactivateDbStruct         */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2ActivateDbStruct data structure parameters
** 
** A pointer to this struct type needs to be passed as the second
** argument to the db2ActivateDb API
** piDbAlias
** Input. The alias for the database to be activated
** 
** piUserName
** Input. The username with the appropriate privilege to activate the database.
** piPassword
** Input. The password for the user issuing the activate databaseiOptionsInput. Activate options reserved for future use
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2ActivateDbStruct
{
             char          *piDbAlias;       /* Input: the alias of the       */
                                             /* database                      */
             char          *piUserName;      /* Input: username               */
             char          *piPassword;      /* Input: password               */
             db2Uint32     iOptions;         /* Input: reserved for future    */
                                             /* use. Initialize to zero.      */
} db2ActivateDbStruct;

/* db2ActivateDb API                                                          */
/******************************************************************************
** db2DeactivateDb API parameters
** 
** Activates the specified database globally 
** 
** Authorization
** sysadm
** 
** Required connection
** None
** 
** API include file
** db2ApiDf.h
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed 
** pParmStruct
** Input. A pointer to the db2ActivateDbStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure, with the return code from the API.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* activate database             */
  db2ActivateDb (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Pointer to                    */
                                             /* db2ActivateDbStruct           */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2CatRemStgStruct data structure parameters
** 
** piAliasName
** Input. The alias name to be cataloged.
** 
** piFileName
** Input. The file containing an alias entry to be used for cataloging.
** 
** piVendorName
** Input. The vendor name to be cataloged.
** 
** piServerName
** Input. The server name to be cataloged.
** 
** piUserID
** Input. The user ID to be cataloged.
** 
** piPassword
** Input. The password to be cataloged.
** 
** piContName
** Input. The container name to be cataloged.
** 
** piObjKeyInput. The DB2 username who owns this alias
** 
** piDBUserInput. The DB2 group who owns this alias.
** 
** piDBGroupInput. The object key to be cataloged.
** 
** iUpdDefault
** Input. A TRUE or FALSE flag that indicates whether the alias is to be
**  set as the default or not.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2CatRemStgStruct
{
             char          *piAliasName;     /* Input: alias name             */
             char          *piFileName;      /* Input: file name              */
             char          *piVendorName;    /* Input: vendor name            */
             char          *piServerName;    /* Input: server name            */
             char          *piUserID;        /* Input: user ID                */
             char          *piPassword;      /* Input: password               */
             char          *piContName;      /* Input: container name         */
             char          *piObjKey;        /* Input: object key             */
             char          *piDBUser;        /* Input: dbuser                 */
             char          *piDBGroup;       /* Input: dbgroup                */
             db2Uint16     iUpdDefault;      /* Input: set as default         */
} db2CatRemStgStruct;

/* db2CatRemStg API                                                           */
/******************************************************************************
** db2CatRemStg API parameters
** 
** Catalog a remote storage alias entry
** 
** Authorization
** sysadm
** 
** Required connection
** None
** 
** API include file
** db2ApiDf.h
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed.
** pParmStruct
** Input. A pointer to the db2CatRemStgStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Catalog Remote Storage        */
  db2CatRemStg (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* db2CatRemStgStruct Pointer    */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2UncatRemStgStruct data structure parameters
** 
** piAliasName
** Input. The alias name to be uncataloged.
** 
** iUpdDefault
** Input. A TRUE or FALSE flag that indicates whether the alias is to
**  be cleared of the default status.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2UncatRemStgStruct
{
             char          *piAliasName;     /* Input: alias name             */
             db2Uint16     iUpdDefault;      /* Input: clear default          */
} db2UncatRemStgStruct;

/* db2UncatRemStg API                                                         */
/******************************************************************************
** db2UncatRemStg API parameters
** 
** Uncatalog a remote storage alias entry
** 
** Authorization
** sysadm
** 
** Required connection
** None
** 
** API include file
** db2ApiDf.h
** 
** versionNumber
** Input. Specifies the version and release level of the structure passed.
** pParmStruct
** Input. A pointer to the db2UncatRemStgStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Uncatalog Remote Storage      */
  db2UncatRemStg (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* db2UncatRemStgStruct Pointer  */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2RemStgOpenScanStruct data structure parameters
** 
** oHandle
** Output. The returned handle.
** 
** oNumEntries
** Output. The number of alias entries returned.
** 
**  *******************************************************************************/
typedef SQL_STRUCTURE db2RemStgOpenScanStruct
{
             db2Uint16     oHandle;          /* Output: handle                */
             db2Uint16     oNumEntries;      /* Output: count                 */
} db2RemStgOpenScanStruct;

/* db2RemStgOpenScan API                                                      */
/******************************************************************************
** db2RemStgOpenScan API parameters
** 
** Open a scan for the remote storage alias and stores a copy in 
** memory and returns the number of entries.
** 
** Authorization
** 
** sysadm
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** versionNumber
** 
** Input. Specifies the version and release level of the structure passed.
** pParmStruct
** Input. A pointer to the db2RemStgOpenScanStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Open Remote Storage Scan      */
  db2RemStgOpenScan (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Pointer                       */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2RemStgEntry data structure parameters
** 
** aliasName
** The remote storage alias name entry.
** 
** vendorName
** The vendor name.
** 
** serverName
** The server name.
** 
** userID
** The user id.
** 
** contName
** The container name.
** 
** objKey
** The object key.
** 
** dbUser
** The DB2 Username.
** 
** dbGroup
** The DB2 Group name.
** 
** isDefault
** Is the alias default or not.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RemStgEntry
{
             char          aliasName[SQL_MAX_IDENT+1]; /* alias name          */
             char          vendorName[SQL_PRODNAME_SZ+1]; /* vendor name      */
             char          serverName[SQL_HOSTNAME_SZ+1]; /* server name      */
             char          userID[SQL_MAX_USERID_SZ+1]; /* user ID            */
             char          contName[SQL_DIR_NAME_SZ+1]; /* container name     */
             char          objKey[SQL_PATH_SZ+1]; /* object key               */
             char          isDefault;        /* is the default alias          */
             char          dbUser[SQL_MAX_USERID_SZ+1]; /* DB2 username       */
             char          dbGroup[SQL_SYSADM_GROUP_SZ+1]; /* DB2 group name  */
} db2RemStgEntry;

/******************************************************************************
** db2RemStgGetNextEntryStruct data structure parameters
** 
** iHandle
** Input. Identifier returned from the associated db2RemStgOpenScan API.
** 
** poRemStgEntry
** Output. Buffer to the remote storage alias entry.
** 
**  *******************************************************************************/
typedef SQL_STRUCTURE db2RemStgGetNextEntryStruct
{
             db2Uint16     iHandle;          /* Input: handle                 */
             struct db2RemStgEntry *poRemStgEntry; /* Output: entry buffer    */
} db2RemStgGetNextEntryStruct;

/* db2RemStgGetNextEntry API                                                  */
/******************************************************************************
** db2RemStgGetNextEntry API parameters
** 
** Returns the next remote storage alias entry.  Subsequent calls to 
** this API returns additional entries.
** 
** Authorization
** 
** sysadm
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** versionNumber
** 
** Input. Specifies the version and release level of the structure passed.
** pParmStruct
** Input. A pointer to the db2RemStgGetNextEntryStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Get Remote Storage Entry      */
  db2RemStgGetNextEntry (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Pointer                       */
             struct sqlca * pSqlca);         /* SQLCA                         */


/******************************************************************************
** db2RemStgCloseScanStruct data structure parameters
** 
** iHandle
** Input. Identifier returned from the associated db2RemStgOpenScan API.
** 
*******************************************************************************/
typedef SQL_STRUCTURE db2RemStgCloseScanStruct
{
             db2Uint16     iHandle;          /* Input: handle                 */
} db2RemStgCloseScanStruct;

/* db2RemStgCloseScan API                                                     */
/******************************************************************************
** db2RemStgCloseScan API parameters
** 
** Frees the resources allocated by db2RemStgOpenScan API.
** 
** Authorization
** 
** sysadm
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** versionNumber
** 
** Input. Specifies the version and release level of the structure passed.
** pParmStruct
** Input. A pointer to the db2RemStgCloseScanStruct structure.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Close Remote Storage Scan     */
  db2RemStgCloseScan (
             db2Uint32 versionNumber,        /* Version Number                */
             void * pParmStruct,             /* Pointer                       */
             struct sqlca * pSqlca);         /* SQLCA                         */


/* db2CatRemStgRotateMasterKey API                                            */
/******************************************************************************
** db2CatRemStgRotateMasterKey API parameters
** 
** Rotates the master key for remote storage alias API.
** 
** Authorization
** 
** sysadm
** 
** Required connection
** 
** None
** 
** API include file
** 
** db2ApiDf.h
** 
** versionNumber
** 
** Input. Specifies the version and release level of the structure passed.
** newMasterKeyLabel
** Input. New master key to use. If empty string, then generate new one.
** 
** pSqlca
** Output. A pointer to the sqlca structure.
** 
*******************************************************************************/
SQL_API_RC SQL_API_FN                        /* Rotate Master Key             */
  db2CatRemStgRotateMasterKey (
             db2Uint32 versionNumber,        /* Version Number                */
             char * newMasterKeyLabel,       /* Pointer                       */
             struct sqlca * pSqlca);         /* SQLCA                         */



#ifdef __cplusplus 
}
#endif

#endif /* SQL_H_DB2APIDF */
