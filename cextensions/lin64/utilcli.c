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
** SOURCE FILE NAME: utilcli.c   
**
** SAMPLE: Utility functions used by DB2 CLI samples
**
** CLI FUNCTIONS USED:
**         SQLAllocHandle -- Allocate Handle
**         SQLBindCol -- Bind a Column to an Application Variable or
**                       LOB locator
**         SQLColAttribute -- Return a Column Attribute
**         SQLConnect -- Connect to a Data Source
**         SQLDescribeCol -- Return a Set of Attributes for a Column
**         SQLDisconnect -- Disconnect from a Data Source
**         SQLEndTran -- End Transactions of a Connection
**         SQLFetch -- Fetch Next Row
**         SQLFreeHandle -- Free Handle Resources
**         SQLFreeStmt -- Free (or Reset) a Statement Handle
**         SQLGetDiagRec -- Get Multiple Field Settings of Diagnostic Record
**         SQLNumResultCols -- Get Number of Result Columns
**         SQLSetConnectAttr -- Set Connection Attributes
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlcli1.h>
#include <sqlutil.h>
#include <sqlenv.h>
#include "utilcli.h"

/* local functions for utilcli.c */
//void HandleLocationPrint(SQLRETURN, int, const char *);
//void HandleDiagnosticsPrint(SQLSMALLINT, SQLHANDLE);

/* funtion used in DB2_API_CHECK */
//void SqlInfoPrint(const char *, struct sqlca*, int, const char*);

/* outputs to screen unexpected occurrences with CLI functions */
int HandleInfoPrint(SQLSMALLINT htype, /* handle type identifier */
                    SQLHANDLE hndl, /* handle used by the CLI function */
                    SQLRETURN cliRC, /* return code of the CLI function */
                    int line,
                    const char *file,
                    ERROR_VAR_PARAM_DEF)
{
  int rc = 0;

  switch (cliRC)
  {
    case SQL_SUCCESS:
      rc = 0;
      break;
    case SQL_INVALID_HANDLE:
      printf("\n-CLI INVALID HANDLE-----\n");
      HandleLocationPrint(cliRC, line, file);
      rc = 1;
      break;
    case SQL_ERROR:
      printf("\n--CLI ERROR--------------\n");
      HandleLocationPrint(cliRC, line, file);
      HandleDiagnosticsPrint(htype, hndl, ERROR_VAR_PARAM);
      rc = 2;
      break;
    case SQL_SUCCESS_WITH_INFO:
      rc = 0;
      break;
    case SQL_STILL_EXECUTING:
      rc = 0;
      break;
    case SQL_NEED_DATA:
      rc = 0;
      break;
    case SQL_NO_DATA_FOUND:
      rc = 0;
      break;
    default:
      printf("\n--default----------------\n");
      HandleLocationPrint(cliRC, line, file);
      rc = 3;
      break;
  }

  return rc;
} /* HandleInfoPrint */

void HandleLocationPrint(SQLRETURN cliRC, int line, const char *file)
{
  printf("  cliRC = %d\n", cliRC);
  printf("  line  = %d\n", line);
  printf("  file  = %s\n", file);
} /* HandleLocationPrint */

void HandleDiagnosticsPrint(SQLSMALLINT htype, /* handle type identifier */
                            SQLHANDLE hndl /* handle */ , ERROR_VAR_PARAM_DEF)
{
  //SQLCHAR message[SQL_MAX_MESSAGE_LENGTH + 1];
  //SQLCHAR sqlstate[SQL_SQLSTATE_SIZE + 1];
  //SQLINTEGER sqlcode;
  SQLSMALLINT length, i;

  i = 1;

  /* get multiple field settings of diagnostic record */
  while (SQLGetDiagRec(htype,
                       hndl,
                       i,
                       sqlstate,
                       sqlcode,
                       message,
                       SQL_MAX_MESSAGE_LENGTH + 1,
                       &length) == SQL_SUCCESS)
  {
    printf("\n  SQLSTATE          = %s\n", sqlstate);
    printf("  Native Error Code = %d\n", *sqlcode);
    printf("%s\n", message);
    i++;
  }

  printf("-------------------------\n");
} /* HandleDiagnosticsPrint */

/* free statement handles and print unexpected occurrences */
/* this function is used in STMT_HANDLE_CHECK */
int StmtResourcesFree(SQLHANDLE hstmt, ERROR_VAR_PARAM_DEF)
{
  SQLRETURN cliRC = SQL_SUCCESS;
  int rc = 0;

  /* free the statement handle */
  cliRC = SQLFreeStmt(hstmt, SQL_UNBIND);
  rc = HandleInfoPrint(SQL_HANDLE_STMT, hstmt, cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);
  if (rc != 0)
  {
    return 1;
  }

  /* free the statement handle */
  cliRC = SQLFreeStmt(hstmt, SQL_RESET_PARAMS);
  rc = HandleInfoPrint(SQL_HANDLE_STMT, hstmt, cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);
  if (rc != 0)
  {
    return 1;
  }

  /* free the statement handle */
  cliRC = SQLFreeStmt(hstmt, SQL_CLOSE);
  rc = HandleInfoPrint(SQL_HANDLE_STMT, hstmt, cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);
  if (rc != 0)
  {
    return 1;
  }

  return 0;
} /* StmtResourcesFree */

/* rollback transactions on a single connection */
/* this function is used in HANDLE_CHECK */
void TransRollback(SQLHANDLE hdbc, ERROR_VAR_PARAM_DEF)
{
  SQLRETURN cliRC = SQL_SUCCESS;
  int rc = 0;

  printf("\n  Rolling back the transaction...\n");

  /* end transactions on the connection */
  cliRC = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_ROLLBACK);
  rc = HandleInfoPrint(SQL_HANDLE_DBC, hdbc, cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);
  if (rc == 0)
  {
    printf("  The transaction rolled back.\n");
  }
} /* TransRollback */

/* rollback transactions on mutiple connections */
/* this function is used in HANDLE_CHECK */
void MultiConnTransRollback(SQLHANDLE henv, ERROR_VAR_PARAM_DEF)
{
  SQLRETURN cliRC = SQL_SUCCESS;
  int rc = 0;

  printf("\n  Rolling back the transactions...\n");

  /* end transactions on the connection */
  cliRC = SQLEndTran(SQL_HANDLE_ENV, henv, SQL_ROLLBACK);
  rc = HandleInfoPrint(SQL_HANDLE_ENV, henv, cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);
  if (rc == 0)
  {
    printf("  The transactions are rolled back.\n");
  }
} /* MultiConnTransRollback */



/* prints the warning/error details including file name, line number,
   sqlcode and SQLSTATE. */
void SqlInfoPrint(const char *appMsg, struct sqlca *pSqlca, int line, const char *file)
{
  int rc = 0;
  char sqlInfo[1024];  /* string to store all the error information */
  char sqlInfoToken[1024]; /* string to store tokens of information */
  char sqlstateMsg[1024];  /* string to store SQLSTATE message*/
  char errorMsg[1024];  /* string to store error message */

  if (pSqlca->sqlcode != 0 && pSqlca->sqlcode != 100)
  {
    strcpy(sqlInfo, "");

    if (pSqlca->sqlcode < 0)
    {
      sprintf(sqlInfoToken,
              "\n---- error report -----------------------------\n");
      strcat(sqlInfo, sqlInfoToken);
    }
    else
    {
      sprintf(sqlInfoToken,
              "\n---- warning report ---------------------------\n");
      strcat(sqlInfo, sqlInfoToken);
    } /* endif */

    sprintf(sqlInfoToken, "\napplication message = %s\n", appMsg);
    strcat(sqlInfo, sqlInfoToken);
    sprintf(sqlInfoToken, "line                = %d\n", line);
    strcat(sqlInfo, sqlInfoToken);
    sprintf(sqlInfoToken, "file                = %s\n", file);
    strcat(sqlInfo, sqlInfoToken);
    sprintf(sqlInfoToken, "SQLCODE             = %d\n\n", pSqlca->sqlcode);
    strcat(sqlInfo, sqlInfoToken);

    /* get error message */
    rc = sqlaintp(errorMsg, 1024, 80, pSqlca);
    if (rc > 0) /* return code is the length of the errorMsg string */
    {
      sprintf(sqlInfoToken, "%s\n", errorMsg);
      strcat(sqlInfo, sqlInfoToken);
    }

    /* get SQLSTATE message */
    rc = sqlogstt(sqlstateMsg, 1024, 80, pSqlca->sqlstate);
    if (rc > 0)
    {
      sprintf(sqlInfoToken, "%s\n", sqlstateMsg);
      strcat(sqlInfo, sqlInfoToken);
    }

    if (pSqlca->sqlcode < 0)
    {
      sprintf(sqlInfoToken,
              "---- end error report ------------------------\n");
      strcat(sqlInfo, sqlInfoToken);
      printf("%s", sqlInfo);
    }
    else
    {
      sprintf(sqlInfoToken,
              "---- end warning report ----------------------\n");
      strcat(sqlInfo, sqlInfoToken);
      printf("%s", sqlInfo);
    } /* endif */
  } /* endif */
} /* SqlInfoPrint */
