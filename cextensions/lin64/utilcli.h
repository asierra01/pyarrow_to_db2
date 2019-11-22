/****************************************************************************
** (c) Copyright IBM Corp. 2007 All rights reserved.
** 
** The following sample of source code ("Sample") is owned by International 
** Business Machines Corporation or one of its subsidiaries ("IBM") and is 
** copyrighted and licensed, not sold. You may use, copy, modify, and 
** distribute the Sample in any form without payment to IBM, for the purpose of 
** assisting you in the development of your applications.
** 
** The Sample code is provided to you on an "AS IS" basis, without warranty of 
** any kind. IBM HEREBY EXPRESSLY DISCLAIMS ALL WARRANTIES, EITHER EXPRESS OR 
** IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
** MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Some jurisdictions do 
** not allow for the exclusion or limitation of implied warranties, so the above 
** limitations or exclusions may not apply to you. IBM shall not be liable for 
** any damages you suffer as a result of using, copying, modifying or 
** distributing the Sample, even if IBM has been advised of the possibility of 
** such damages.
*****************************************************************************
**
** SOURCE FILE NAME: utilcli.h
**
** SAMPLE: Declaration of utility functions used by DB2 CLI samples
*****************************************************************************
**
** For more information on the sample programs, see the README file.
**
** For information on developing CLI applications, see the CLI Guide
** and Reference.
**
** For information on using SQL statements, see the SQL Reference.
**
** For the latest information on programming, building, and running DB2 
** applications, visit the DB2 application development website: 
**     http://www.software.ibm.com/data/db2/udb/ad
****************************************************************************/

#ifndef UTILCLI_H
#define UTILCLI_H

#define MAX_UID_LENGTH 18
#define MAX_PWD_LENGTH 30
#define MAX_STMT_LEN 255
#define MAX_COLUMNS 255
#ifdef DB2WIN
#define MAX_TABLES 50
#else
#define MAX_TABLES 255
#endif

#ifndef max
#define max(a,b) (a > b ? a : b)
#endif

#define ERROR_VAR \
    SQLCHAR message[SQL_MAX_MESSAGE_LENGTH + 1] = {0}; \
    SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1] = {0};\
    SQLINTEGER sqlcode = 0;

#define ERROR_VAR_PARAM message, sqlstate, sqlcode
#define ERROR_VAR_PARAM_1 message, sqlstate, &sqlcode
#define ERROR_VAR_PARAM_DEF SQLCHAR *message, SQLCHAR *sqlstate, SQLINTEGER *sqlcode

/* macro for environment handle checking */
#define ENV_HANDLE_CHECK(henv, cliRC)              \
if (cliRC != SQL_SUCCESS)                          \
{                                                  \
  rc = HandleInfoPrint(SQL_HANDLE_ENV, henv,       \
                       cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM); \
  if (rc != 0) return rc;                          \
}

/* macro for connection handle checking */
#define DBC_HANDLE_CHECK(hdbc, cliRC)              \
if (cliRC != SQL_SUCCESS)                          \
{                                                  \
  rc = HandleInfoPrint(SQL_HANDLE_DBC, hdbc,       \
                       cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM); \
  if (rc != 0) return rc;                          \
}

/* macro for statement handle checking */
#define STMT_HANDLE_CHECK(hstmt, hdbc, cliRC)      \
if (cliRC != SQL_SUCCESS)                          \
{                                                  \
  rc = HandleInfoPrint(SQL_HANDLE_STMT, hstmt,     \
                       cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM); \
  if (rc == 2) StmtResourcesFree(hstmt, ERROR_VAR_PARAM);           \
  if (rc != 0) TransRollback(hdbc, ERROR_VAR_PARAM);                \
  if (rc != 0) return rc;                          \
}

/* macro for statement handle checking in
   applications with multiple connections */
#define MC_STMT_HANDLE_CHECK(hstmt, henv, cliRC)   \
if (cliRC != SQL_SUCCESS)                          \
{                                                  \
  rc = HandleInfoPrint(SQL_HANDLE_STMT, hstmt,     \
                       cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM); \
  if (rc == 2) StmtResourcesFree(hstmt, ERROR_VAR_PARAM);           \
  if (rc != 0) MultiConnTransRollback(henv, ERROR_VAR_PARAM);       \
  if (rc != 0) return rc;                          \
}

/* macro for DB2_API checking */
#define DB2_API_CHECK(MSG_STR)                     \
SqlInfoPrint(MSG_STR, &sqlca, __LINE__, __FILE__); \
if (sqlca.sqlcode < 0)                             \
{                                                  \
  return 1;                                        \
}

/* macro for expected error checking checking */
#define EX_STMT_HANDLE_CHECK(hstmt, hdbc, cliRC)   \
if (cliRC != SQL_SUCCESS)                          \
{                                                  \
  rc = HandleInfoPrint(SQL_HANDLE_STMT, hstmt,     \
                       cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM); \
  if (rc == 2) StmtResourcesFree(hstmt, ERROR_VAR_PARAM);           \
}



    /* functions used in ...CHECK_HANDLE macros */
    int HandleInfoPrint(SQLSMALLINT htype, /* handle type identifier */
        SQLHANDLE hndl, /* handle used by the CLI function */
        SQLRETURN cliRC, /* return code of the CLI function */
        int line,
        const char* file,
        ERROR_VAR_PARAM_DEF);

    //void CLIAppCleanUp(SQLHANDLE *, SQLHANDLE a_hdbc[], int);
    int StmtResourcesFree(SQLHANDLE, ERROR_VAR_PARAM_DEF);
    void TransRollback(SQLHANDLE, ERROR_VAR_PARAM_DEF);
    void MultiConnTransRollback(SQLHANDLE, ERROR_VAR_PARAM_DEF);
    void HandleLocationPrint(SQLRETURN cliRC, int line, const char* file);




#endif

