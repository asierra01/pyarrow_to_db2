/******************************************************************************
 *
 * Source File Name = SQLADEF.H
 *
 * (C) COPYRIGHT International Business Machines Corp. 1993, 2017
 * All Rights Reserved
 * Licensed Materials - Property of IBM
 *
 * US Government Users Restricted Rights - Use, duplication or
 * disclosure restricted by GSA ADP Schedule Contract with IBM Corp.
 *
 * Function = Include File defining:
 *              Information for Precompiler Generated C Files
 *
 * Operating System = Common C Include File
 *
 *****************************************************************************/

#ifndef SQL_H_SQLADEF
   #define SQL_H_SQLADEF           /* Permit duplicate Includes */

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>                /* Required when using DBCLOBs */
#include "sqlsystm.h"              /* System dependent defines  */

#if defined(DB2NT)
#if defined _WIN64
#pragma pack(8)
#else
#pragma pack(4)
#endif
#elif (defined(DB2AIX) && defined(__64BIT__))
#pragma options align=natural
#elif (defined(DB2AIX))
#pragma options align=power
#endif

/* Macros for initializing LOB declarations. */
#define SQL_BLOB_INIT(s)   { sizeof(s)-1,     s }
#define SQL_CLOB_INIT(s)   { sizeof(s)-1,     s }
#define SQL_DBCLOB_INIT(s) { (sizeof(s)/2)-1, s }

#ifndef SQL_SQLDBCHAR_DEFN
#define SQL_SQLDBCHAR_DEFN
  typedef unsigned short sqldbchar;
#endif

/* unused[0] in below structure to indicate runtime 
   that UNSAFENULL PRECOMPILE option is set to YES. The
   other bits unsed[1], unsed[2], unsed[3] are set to space. */
struct sqla_runtime_info
{
  char           id[8];
  unsigned short wc_size;
  unsigned short wc_type;
  char           unused[4]; /* See comments above the structure */ 
};

/* Below macro used to maintain sqlacall_spare_info structure version info. */
#define SQLA_SQLACALL_SPARE_RTINFO_VERSION_1 1

/* Below structure will be passed to sqlacall spare parameter to intimate
   it's array with IUD statements. */
typedef struct sqla_set_array_info
{
  sqluint32 uiArraySize;  /* Array size of host variable in IUD statement */
  sqluint32 uiStructSize; /* Structure size for array iteration */
  sqluint16 bIsStruct;    /* This flag is set to 1 if host variable 
                             is structure */
  sqluint16 bIsStructInd; /* This flag is set to 1 if indicator 
                             variable is structure */
}sqla_set_array_info;

struct sqlacall_spare_info
{
  sqluint32 uiVersion;  /* To maintain compatibility to lower version */
  sqla_set_array_info arrayInfo;  
};

struct sqlca;

struct sqlda;

struct sqla_setd_list
{
  unsigned short sqltype;           /* SQL data type   */
  sqluint32       sqllen;           /* declared length */
  void          *sqldata;           /* address of host var */
  short          *sqlind;           /* address of ind. var */
};
#define SQLSETDSIZE(n) ( (n) * sizeof(struct sqla_setd_list))

/* Introduce aligned structure */                            
struct sqla_setdata_list
{
  void           *sqldata;          /* address of host var */
  short          *sqlind;           /* address of ind. var */
  sqluint32       sqltype;          /* SQL data type   */
  sqluint32       sqllen;           /* declared length */
};

#define SQLSETDATASIZE(n) ( (n) * sizeof(struct sqla_setdata_list))

struct sqla_setds_list
{
  sqluint32    sqldslen;           /* length of ADT         */
  void       *sqldsname;           /* address of type name  */
};

#define SQLSETDSSIZE(n) ( (n) * sizeof(struct sqla_setds_list))

#define SQL_IS_LITERAL         1
#define SQL_IS_INPUT_HVAR      2

/* Prototypes for Runtime API's */

SQL_API_RC SQL_API_FN  sqlaaloc(unsigned short,
                                unsigned short,
                                unsigned short,
                                void *);

SQL_API_RC SQL_API_FN  sqlaAllocateCursorRS (
                                sqluint16,      
                                sqluint32,         
                                void *);

SQL_API_RC SQL_API_FN  sqlaAssociateLocatorRS (
                                sqluint32,      
                                int,         
                                char *,           
                                int,            
                                void *);

SQL_API_RC SQL_API_FN  sqlaAssocLocatorRS (
                                sqluint32 *,      
                                int,         
                                char *,           
                                int,            
                                void *);

SQL_API_RC SQL_API_FN  sqlacall(unsigned short,
                                unsigned short,
                                unsigned short,
                                unsigned short,
                                void *);

SQL_API_RC SQL_API_FN  sqlacmpd(unsigned short,
                                unsigned short,
                                unsigned short,
                                unsigned short,
                                void *);

SQL_API_RC SQL_API_FN  sqladloc(unsigned short,
                                void *);

SQL_API_RC SQL_API_FN  sqlasetd(unsigned short,
                                unsigned short,
                                unsigned short,
                                struct sqla_setd_list *,
                                void *);

SQL_API_RC SQL_API_FN  sqlasetda(unsigned short,
                                unsigned short,
                                unsigned short,
                                struct sqla_setd_list *,
                                struct sqla_setds_list *,
                                void *);

SQL_API_RC SQL_API_FN  sqlasetdata(unsigned short,
                                   unsigned short,
                                   unsigned short,
                                   struct sqla_setdata_list *,
                                   struct sqla_setds_list *,
                                   void *);
/*
 ** sqlasetcard is used to set cardinality of the IN/ INOUT/ OUT 
 ** variables in call statement. 
 */
SQL_API_RC SQL_API_FN  sqlasetcard(unsigned short,
                                   unsigned short,
                                   unsigned short,
                                   sqlint32 *,
                                   struct sqla_setds_list *,
                                   void *);
/*
** NOTE: sqlasets has been obsoleted in favor of sqlastls, and will
** be going away in a future release.
*/
SQL_API_RC SQL_API_FN  sqlasets(unsigned short,
                                const void *,
                                void *);

SQL_API_RC SQL_API_FN  sqlastls(sqluint32,
                                const void *,
                                void *);

/*
** NOTE: sqlasetv has been obsoleted in favor of sqlastlv, and will
** be going away in a future release.
*/
SQL_API_RC SQL_API_FN  sqlasetv(unsigned short,
                                unsigned short,
                                unsigned short,
                                unsigned short,
                                void  *,
                                short *,
                                void  *);

SQL_API_RC SQL_API_FN  sqlastlv(unsigned short,
                                unsigned short,
                                unsigned short,
                                sqluint32,
                                void *,
                                short *,
                                void *);

SQL_API_RC SQL_API_FN  sqlastlva(unsigned short,
                                unsigned short,
                                unsigned short,
                                sqluint32,
                                void *,
                                sqluint32,
                                void *,
                                short *,
                                void *);

SQL_API_RC SQL_API_FN  sqlastvr(unsigned short,
                                unsigned short,
                                unsigned short,
                                sqluint32,
                                sqlint32 *,
                                void *,
                                short *,
                                void *);

SQL_API_RC SQL_API_FN  sqlastsize(unsigned short,
                                  sqluint32,
                                  sqluint32,
                                  unsigned short,
                                  sqluint32,
                                  unsigned short);

SQL_API_RC SQL_API_FN  sqlastvra(unsigned short,
                                unsigned short,
                                unsigned short,
                                sqluint32,
                                sqlint32 *,
                                void *,
                                sqluint32,
                                void *,
                                short *,
                                void *);

SQL_API_RC SQL_API_FN  sqlastop(void *);

SQL_API_RC SQL_API_FN  sqlastrt(char *,
                                struct sqla_runtime_info *,
                                struct sqlca *);

SQL_API_RC SQL_API_FN  sqlausda(unsigned short,
                                struct sqlda *,
                                void *);

SQL_API_RC SQL_API_FN  sqlglm(char *,
                              int *,
                              int *);

#if defined(DB2NT)
#pragma pack()
#elif defined(DB2AIX)
#pragma options align=reset
#endif

#ifdef __cplusplus
}
#endif

#endif  /* SQL_H_SQLADEF */
