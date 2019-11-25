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

#define _NO_CRT_STDIO_INLINE


#include "spclient_python_common.h"
#include <sstream>

void HandleDiagnosticsPrint(
    SQLSMALLINT htype, /* handle type identifier */
    SQLHANDLE hndl /* handle */,
    SQLRETURN cliRC,
    int line,
    const char* file,
    ERROR_VAR_PARAM_DEF);

/* outputs to screen unexpected occurrences with CLI functions */
int HandleInfoPrint(
        SQLSMALLINT htype, /* handle type identifier */
        SQLHANDLE hndl,    /* handle used by the CLI function */
        SQLRETURN cliRC,   /* return code of the CLI function */
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
#ifdef SPCLIENT_PYTHON
            LOG_INFO("\n-CLI INVALID HANDLE-----\n");
#else
            printf("\n-CLI INVALID HANDLE-----\n");
#endif
            HandleLocationPrint(cliRC, line, file);
            rc = 1;
            break;
        case SQL_ERROR:
            HandleDiagnosticsPrint(htype, hndl, cliRC, line, file, ERROR_VAR_PARAM);
            rc = 2;
            break;
        case SQL_SUCCESS_WITH_INFO:
            LOG_INFO("SQL_SUCCESS_WITH_INFO");
            HandleDiagnosticsPrint(htype, hndl, cliRC, line, file, ERROR_VAR_PARAM);
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
#ifdef SPCLIENT_PYTHON
            LOG_INFO("\n--default----------------\n");
#else
            printf("\n--default----------------\n");
#endif
            HandleLocationPrint(cliRC, line, file);
            rc = 3;
            break;
        }

        return rc;
    } /* HandleInfoPrint */

    void HandleLocationPrint(SQLRETURN cliRC, int line, const char *file)
    {

#ifdef SPCLIENT_PYTHON
        LOG_INFO("\ncliRC = %d\nline  = %d\nfile  = %s\n", cliRC, line, file);
#else
        printf("  cliRC = %d\n", cliRC);
        printf("  line  = %d\n", line);
        printf("  file  = %s\n", file);
#endif
    } /* HandleLocationPrint */

    void HandleDiagnosticsPrint(
        SQLSMALLINT htype, /* handle type identifier */
        SQLHANDLE hndl /* handle */,
        SQLRETURN cliRC, 
        int line, 
        const char *file,
        ERROR_VAR_PARAM_DEF)
    {
        SQLCHAR l_message[SQL_MAX_MESSAGE_LENGTH + 1] = {0};
        SQLCHAR l_sqlstate[SQL_SQLSTATE_SIZE + 1] = {0};
        SQLINTEGER l_sqlcode = 0;
        SQLSMALLINT length, i;
        std::ostringstream log;
        bool OK = true;
        i = 1;
        /* get multiple field settings of diagnostic record */
        while (OK == true)
        {
            memset(l_message, 0, sizeof(l_message));
            memset(l_sqlstate, 0, sizeof(l_sqlstate));
            l_sqlcode = 0;
            if (SQLGetDiagRec(htype,
                    hndl,
                    i,
                    l_sqlstate,
                    &l_sqlcode,
                    l_message,
                    SQL_MAX_MESSAGE_LENGTH,
                    &length) == SQL_SUCCESS)
                OK = true;
            else
                OK = false;

            if (OK == true)
            {
                strcpy((char *)sqlstate, (char*)l_sqlstate);
                strcpy((char *)message, (char*)l_message);
				std::string str_message = (char *)message;
                *sqlcode = l_sqlcode;
                log << "\n--CLI ERROR--------------\n";
                log << "\ncliRC = " << cliRC << "\nline  = " << line << "\nfile  = " << file;
                log << "\nSQLSTATE = '" << sqlstate;
                log << "\nNative Error Code = " << *sqlcode << "\n";
                if (str_message.length() > 80)
                {
                    log << "message = " << str_message.substr(0, 80).c_str() << "\n";
                    log << str_message.substr(80).c_str() << "\n";
                }
                else
                    log << "message = " << message << "\n";
                log << "-------------------------";

            }
            i++;
        }
#ifdef SPCLIENT_PYTHON
        LOG_INFO("HandleDiagnosticsPrint %s", log.str().c_str(), sqlstate);
#else
        printf("HandleDiagnosticsPrint  %s\n", log.str().c_str());
#endif

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
        std::ostringstream ss;

        ss << "\n  Rolling back the transaction...\n";

        /* end transactions on the connection */
        cliRC = SQLEndTran(SQL_HANDLE_DBC, hdbc, SQL_ROLLBACK);
        if (rc == 0)
            ss << " The transaction rolled back.\n";
        else
        {
            rc = HandleInfoPrint(SQL_HANDLE_DBC, hdbc, cliRC, __LINE__, __FILE__, ERROR_VAR_PARAM);
            ss << " The transaction do not rolled back.\n";
        }
#ifdef SPCLIENT_PYTHON
        LOG_INFO("%s", ss.str().c_str());
#else
        printf("%s", ss.str().c_str());
#endif
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
        char sqlInfo[1024] = {0};  /* string to store all the error information */
        char sqlInfoToken[1024] = {0}; /* string to store tokens of information */
        char sqlstateMsg[1024] = {0};  /* string to store SQLSTATE message*/
        char errorMsg[1024] = {0};  /* string to store error message */
        char sqlstate[6] = { 0 };

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

            snprintf(sqlInfoToken, sizeof(sqlInfoToken), "\napplication message = %s\n", appMsg);
            strcat(sqlInfo, sqlInfoToken);
            snprintf(sqlInfoToken, sizeof(sqlInfoToken), "line                = %d\n", line);
            strcat(sqlInfo, sqlInfoToken);
            snprintf(sqlInfoToken, sizeof(sqlInfoToken), "file                = %s\n", file);
            strcat(sqlInfo, sqlInfoToken);

            snprintf(sqlstate, sizeof(sqlstate), "%s", pSqlca->sqlstate);
            sqlstate[5] = 0;

            snprintf(sqlInfoToken, sizeof(sqlInfoToken), "SQLSTATE            = '%s'\n", sqlstate);
            strcat(sqlInfo, sqlInfoToken);


            snprintf(sqlInfoToken, sizeof(sqlInfoToken), "SQLCODE             = '%d'\n\n", pSqlca->sqlcode);
            strcat(sqlInfo, sqlInfoToken);

            /* get error message */
            rc = sqlaintp(errorMsg, 1024, 80, pSqlca);
            if (rc > 0) /* return code is the length of the errorMsg string */
            {
                snprintf(sqlInfoToken, sizeof(sqlInfoToken), "errorMsg=%s\n", errorMsg);
                strcat(sqlInfo, sqlInfoToken);
            }

            /* get SQLSTATE message */
            rc = sqlogstt(sqlstateMsg, 1024, 80, pSqlca->sqlstate);
            if (rc > 0)
            {
                snprintf(sqlInfoToken, sizeof(sqlInfoToken), "SQLSTATE=%s\n", sqlstateMsg);
                strcat(sqlInfo, sqlInfoToken);
            }

            if (pSqlca->sqlcode < 0)
            {
                sprintf(sqlInfoToken,
                    "---- end error report ------------------------\n");
                strcat(sqlInfo, sqlInfoToken);
                LOG_INFO("%s", sqlInfo);
            }
            else
            {
                sprintf(sqlInfoToken,
                    "---- end warning report ----------------------\n");
                strcat(sqlInfo, sqlInfoToken);
                LOG_INFO("%s", sqlInfo);
            } /* endif */
        } /* endif */
    } /* SqlInfoPrint */

