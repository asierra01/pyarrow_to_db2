

#include "spclient_python_common_cpp.h"


int add_module_globals_sqlenv(PyObject* m)
{
    int ret;
    ret = PyModule_AddIntMacro(m, SQL_RC_OK);// 0                          /* everything is ok */

    ret = PyModule_AddIntMacro(m, SQL_RC_INVALID_SQLCA);
    ret = PyModule_AddIntMacro(m, SQLE_RC_STILL_EXECUTING);// 16           /* Request is still executing    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INLUW);//  -752                  /* Connect to other DB not       */
                                                                           /* allowed                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_W863);//   863                   /* Only SBCS data allowed        */

    ret = PyModule_AddIntMacro(m, SQLE_RC_E953);//   -953                  /* Agent heap too small          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_E957);//   -957                  /* Requestor comm heap too       */
                                                                           /* small                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_E959);//   -959                  /* Server comm heap too small    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_E961);//   -961                  /* Rqstr remote svcs heap too    */
                                                                           /* small                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_E962);//   -962                  /* Svr remote svcs heap too      */
                                                                           /* small                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_APP_CTRL_SEG);// -987         /* Application control shared    */
                                                                           /* memory set cannot be          */
                                                                           /* allocated                     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVNEWLOGP);// 993               /* New log path is invalid       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVLOGP);// 995                  /* Current log path is invalid   */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALIAS);// -1000               /* Invalid alias                 */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVDBNAME);// -1001              /* Invalid database name         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVDRIVE);// -1002               /* Invalid drive                 */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW_DB2OS2);// -1003          /* Invalid password - OS/2       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW_DB2NT);// -1003           /* Invalid password - NT         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW_DB2DOS);// -1003          /* Invalid password - DOS        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW_DB2WIN);// -1003          /* Invalid password - Windows    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW_DB2MAC);// -1003          /* Invalid password - Mac        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW_DB2AIX);// -10002         /* Invalid password - AIX        */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW);// SQLE_RC_INVPSW_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSTOR);// -1004                /* Insuf storage on file system  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DUPALIAS);// -1005               /* Duplicate alias               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRONGCODEPG);// -1006            /* Appl code page does not       */
                                                                           /* match db                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_NEWPSW);// -1008             /* Invalid new password          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVREMOTE);// -1009              /* Invalid remote command        */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVTYPE);// -1010                /* Invalid type                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODRIVE);// -1011                /* No drive for indirect entry   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NONODE);// -1012                 /* No nodename for remote entry  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODB);//   -1013                 /* Alias or database name not    */
                                                                           /* found                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMORE);// 1014                  /* No more entries               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_RESTART);// -1015             /* Database needs restart        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVLLU);// -1016                 /* Invalid local_lu alias        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVMODE);// -1017                /* Invalid mode                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DUPNODE);// -1018                /* Duplicate node name           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVNODE);// -1019                /* Invalid node name             */

    ret = PyModule_AddIntMacro(m, SQLE_RC_MAXNODE);// -1020                /* Node could not be cataloged   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOTNODE);// -1021                /* Nodename not found            */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSYS_DB2OS2);// -1022          /* Insuf system resources - OS   */
                                                                           /* 2                             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSYS_DB2NT);// -1022           /* Insuf system resources - NT   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSYS_DB2DOS);// -1022          /* Insuf system resources - DOS  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSYS_DB2WIN);// -1022          /* Insuf system resources -      */
                                                                           /* Windows                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSYS_DB2MAC);// -1022          /* Insuf system resources -      */
                                                                           /* Macintosh                     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSYS_DB2AIX);// -10003         /* Insuf system resources - AIX  */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INSSYS);// SQLE_RC_INSSYS_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_NOCONV);// -1023                 /* Communication conversation    */
                                                                           /* failed                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOSUDB);// -1024                 /* No database connection        */
                                                                           /* exists                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DBACT);//  -1025                 /* Databases are active          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVSTRT);// -1026                /* Database manager already      */
                                                                           /* started                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NONODEDIR);// -1027              /* Node directory not found      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVRLU);// -1029                 /* Partner lu not specified      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_MAXDB);//  -1030                 /* Database directory is full    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODBDIR);// -1031                /* Database directory not found  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOSTARTG);// -1032               /* Database manager not started  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DIRBUSY);// -1033                /* Database directory being      */
                                                                           /* updated                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DBBAD);//  -1034                 /* Database is damaged           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_INUSE);// -1035               /* Database already in use       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDB);// -1036                 /* Database file error           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODE_DIR_EMPTY);// 1037          /* No entry in Node directory    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILENODE);// -1038               /* Node directory file error     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDIR_DB2OS2);// -1039         /* Directory file error - OS/2   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDIR_DB2NT);// -1039          /* Directory file error - NT     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDIR_DB2DOS);// -1039         /* Directory file error - DOS    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDIR_DB2WIN);// -1039         /* Directory file error -        */
                                                                           /* Windows                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDIR_DB2MAC);// -1039         /* Directory file error - Mac    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDIR_DB2AIX);// -10004        /* Directory file error - AIX    */

    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDIR);// SQLE_RC_FILEDIR_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_MAXAPPLS);// -1040               /* Max number of applications    */
                                                                           /* reached                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MAXDBS);// -1041                 /* Max number of databases       */
                                                                           /* started                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR);// -1042                 /* System error                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CATBOOT);// -1043                /* Catalog bootstrap failure     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRRPT);// -1044                /* Request interrupted by        */
                                                                           /* ctrl+break                    */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVINDIR);// -1045               /* Invalid level of indirection  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVAUTHID);// -1046              /* Invalid userid                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_APCONN);// -1047                 /* Appl already connect to       */
                                                                           /* another db                    */

    ret = PyModule_AddIntMacro(m, SQLE_RC_USEINVALID_DB2OS2);// -1048      /* Invalid use specified - OS/2  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_USEINVALID_DB2NT);// -1048       /* Invalid use specified - NT    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_USEINVALID_DB2DOS);// -1048      /* Invalid use specified - DOS   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_USEINVALID_DB2WIN);// -1048      /* Invalid use specified -       */
                                                                           /* Windows                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_USEINVALID_DB2MAC);// -1048      /* Invalid use specified -       */
                                                                           /* MacOS                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_USEINVALID_DB2AIX);// -10005     /* Invalid use specified - AIX   */

    ret = PyModule_AddIntMacro(m, SQLE_RC_USEINVALID);// SQLE_RC_USEINVALID_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_APPSERR);// -900                 /* Appl state in error           */

    ret = PyModule_AddIntMacro(m, SQLE_RC_UNCHOME);// -1050                /* Cannot uncatalog 'Home'       */
                                                                           /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODIRDRV);// -1051               /* Db direct. drive does not     */
                                                                           /* exist                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODBDRV);// -1052                /* Database drive does not       */
                                                                           /* exist                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INTBUSY);// -1053                /* Interrupt already in          */
                                                                           /* progress                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_COMMINP);// -1054                /* Commit in progress - no       */
                                                                           /* int's                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ROLLINP);// -1055                /* Rollback in progress - no     */
                                                                           /* int's                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOINTER);// -1360                /* Cannot be interrupted - no    */
                                                                           /* int's                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_TIMEOUT);// 1361                 /* Windows Client Execution      */
                                                                           /* Timeout                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MAXSCAN);// -1056                /* Maximum allowable scans       */
                                                                           /* exceeded                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODENTRY);// 1057                /* No entries in directory       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVHAND);// -1058                /* Invalid input handle          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOSCAN);// -1059                 /* Open scan not issued          */

    ret = PyModule_AddIntMacro(m, SQLE_RC_NOCONNECT);// -1060              /* User lacks connect privilege  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_QSNOCONNECT);// -20157           /* User lacks connect privilege  */
                                                                           /* for Quiesced Db               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_RESTART_WITH_INDOUBTS);// 1061   /* RESTART was successful, but   */
                                                                           /* indoubt transactions exist    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPATH);// -1062                /* Database path not found       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_START_OK);// -1063               /* Database manager started OK   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_STOP_OK);// -1064                /* Database manager stopped OK   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_BADBINDS);// 1065             /* N utilities not bound         */

    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMSG_DB2OS2);// -1068           /* Message file not found - OS   */
                                                                           /* 2                             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMSG_DB2NT);// -1068            /* Message file not found - NT   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMSG_DB2DOS);// -1068           /* Message file not found - DOS  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMSG_DB2WIN);// -1068           /* Message file not found -      */
                                                                           /* Windows                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMSG_DB2MAC);// -1068           /* Message file not found -      */
                                                                           /* MacOS                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMSG_DB2AIX);// -10007          /* Message file not found - AIX  */

    ret = PyModule_AddIntMacro(m, SQLE_RC_NOMSG);//  SQLE_RC_NOMSG_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVDROP);// -1069                /* DB invalid type for Drop      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVDBNAME_PTR);// -1070          /* Invalid Database Name         */
                                                                           /* pointer                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALIAS_PTR);// -1071           /* Invalid Alias pointer         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_RESOURCE_ERROR);// -1072         /* Resources in inconsistent     */
                                                                           /* state                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_ND_REL);// -1073             /* Invalid Node Directory        */
                                                                           /* release                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPSW_PTR);// -1074             /* Invalid Password pointer      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVCOMM_PTR);// -1075            /* Invalid Comment pointer       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVCNT_PTR);// -1076             /* Invalid Count pointer         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVHAND_PTR);// -1077            /* Invalid Handle pointer        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVBUFF_PTR);// -1078            /* Invalid Buffer pointer        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVNODE_PTR);// -1079            /* Invalid Node pointer          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVUSERID_PTR);// -1150          /* Invalid Userid pointer        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPARM_PTR);// -1151            /* Invalid Parms pointer         */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVLLU_PTR);// -1080             /* Invalid Local Lu pointer      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVRLU_PTR);// -1081             /* Invalid Remote Lu pointer     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVMODE_PTR);// -1082            /* Invalid Mode pointer          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_DBDB);// -1083               /* Bad Database Description      */
                                                                           /* Block                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_KSEGSFAIL);// -1084              /* Cannot Allocate Kernel        */
                                                                           /* Segments                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_APPHEAPFAIL);// -1085            /* Cannot Allocate Application   */
                                                                           /* heap                          */

    ret = PyModule_AddIntMacro(m, SQLE_RC_OS2ERROR);// -1086               /* Unexpected OS/2 error         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BIND_LIST);// 1087               /* Bind list could not be        */
                                                                           /* opened                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BIND_ERROR);// 1088              /* Error occurred during bind    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BIND_INTRRPT);// 1089            /* Binding was interrupted       */

    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_APP_REL);// -1090            /* Release number of appl is     */
                                                                           /* invalid                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_DB_REL);// -1091             /* Release number of database    */
                                                                           /* bad                           */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INSAUTH);// -1092                /* Authorization error           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOLOGON);// -1093                /* User not logged on            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NDBUSY);// -1094                 /* Node directory being updated  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MAX_NDSCAN);// -1095             /* Max node scans open           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_REQTYPE);// -1096                /* Invalid type for requester    */
                                                                           /* node                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODERR);// -1097                 /* Node not found for remote db  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_APCONN_SAME);// -1098            /* Appl is already connected to  */
                                                                           /* db                            */

    ret = PyModule_AddIntMacro(m, SQLE_RC_WRPROT_ERR_DB2OS2);// -1099      /* Write protect error on        */
                                                                           /* diskette                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRPROT_ERR_DB2NT);// -1099       /* Write protect error on        */
                                                                           /* diskette                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRPROT_ERR_DB2DOS);// -1099      /* Write protect error on        */
                                                                           /* diskette                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRPROT_ERR_DB2WIN);// -1099      /* Write protect error on        */
                                                                           /* diskette                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRPROT_ERR_DB2MAC);// -1099      /* Write protect error on        */
                                                                           /* diskette                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRPROT_ERR_DB2AIX);// -10021     /* Write protect error on        */
                                                                           /* filesystem                    */

    ret = PyModule_AddIntMacro(m, SQLE_RC_WRPROT_ERR);// SQLE_RC_WRPROT_ERR_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_NODE_WARN);// 1100               /* Node not cataloged for        */
                                                                           /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_REMCONN_ERR);// -1101            /* Remote communications error   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MIG_NODB);// -1102               /* No database name provided in  */
                                                                           /* call                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MIG_OK);// 1103                  /* Migration was successful      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPROG_PTR);// -1104            /* Invalid program name pointer  */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SPDB_DB2OS2);// -1105        /* Invalid disconnect from       */
                                                                           /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SPDB_DB2NT);// -1105         /* Invalid disconnect from       */
                                                                           /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SPDB_DB2DOS);// -1105        /* Invalid disconnect from       */
                                                                           /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SPDB_DB2WIN);// -1105        /* Invalid disconnect from       */
                                                                           /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SPDB_DB2MAC);// -1105        /* Invalid disconnect from       */
                                                                           /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SPDB_DB2AIX);// -10017       /* Invalid disconnect from       */
                                                                           /* database                      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SPDB);// SQLE_RC_INV_SPDB_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PROC_DB2OS2);// -1106    /* Function could not be         */
                                                                           /* executed                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PROC_DB2NT);// -1106     /* Function could not be         */
                                                                           /* executed                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PROC_DB2DOS);// -1106    /* Function could not be         */
                                                                           /* executed                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PROC_DB2WIN);// -1106    /* Function could not be         */
                                                                           /* executed                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PROC_DB2MAC);// -1106    /* Function could not be         */
                                                                           /* executed                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PROC_DB2AIX);// -10010   /* Function could not be         */
                                                                           /* executed                      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PROC);// SQLE_RC_INVALID_PROC_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRP_PROC_DB2OS2);// -1107      /* Program interrupted - OS/2    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRP_PROC_DB2NT);// -1107       /* Program interrupted - NT      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRP_PROC_DB2DOS);// -1107      /* Program interrupted - DOS     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRP_PROC_DB2WIN);// -1107      /* Program interrupted -         */
                                                                           /* Windows                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRP_PROC_DB2MAC);// -1107      /* Program interrupted - MacOS   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRP_PROC_DB2AIX);// -10011     /* Program interrupted - AIX     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INTRP_PROC);// SQLE_RC_INVALID_PROC_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR_PROC_DB2OS2);// -1108     /* System error on library load  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR_PROC_DB2NT);// -1108      /* System error on library load  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR_PROC_DB2DOS);// -1108     /* System error on library load  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR_PROC_DB2WIN);// -1108     /* System error on library load  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR_PROC_DB2MAC);// -1108     /* System error on library load  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR_PROC_DB2AIX);// -10012    /* System error on library load  */

    ret = PyModule_AddIntMacro(m, SQLE_RC_SYSERR_PROC);// SQLE_RC_SYSERR_PROC_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_NOFILE_PROC_DB2OS2);// -1109     /* Library could not be loaded   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOFILE_PROC_DB2NT);// -1109      /* Library could not be loaded   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOFILE_PROC_DB2DOS);// -1109     /* Library could not be loaded   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOFILE_PROC_DB2WIN);// -1109     /* Library could not be loaded   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOFILE_PROC_DB2MAC);// -1109     /* Library could not be loaded   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOFILE_PROC_DB2AIX);// -10013    /* Library could not be loaded   */

    ret = PyModule_AddIntMacro(m, SQLE_RC_NOFILE_PROC);// SQLE_RC_NOFILE_PROC_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_ERROR_PROC);// -1110             /* Program error                 */

    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPGN_PROC_DB2OS2);// -1111     /* Invalid DARI prog name        */
                                                                           /* format                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPGN_PROC_DB2NT);// -1111      /* Invalid DARI prog name        */
                                                                           /* format                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPGN_PROC_DB2DOS);// -1111     /* Invalid DARI prog name        */
                                                                           /* format                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPGN_PROC_DB2WIN);// -1111     /* Invalid DARI prog name        */
                                                                           /* format                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPGN_PROC_DB2MAC);// -1111     /* Invalid DARI prog name        */
                                                                           /* format                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPGN_PROC_DB2AIX);// -10014    /* Invalid DARI prog name        */
                                                                           /* format                        */

    ret = PyModule_AddIntMacro(m, SQLE_RC_BADPGN_PROC);// SQLE_RC_BADPGN_PROC_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_INSMEM_PROC_DB2OS2);// -1112     /* Insuf memory to load lib      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSMEM_PROC_DB2NT);// -1112      /* Insuf memory to load lib      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSMEM_PROC_DB2DOS);// -1112     /* Insuf memory to load lib      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSMEM_PROC_DB2WIN);// -1112     /* Insuf memory to load lib      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSMEM_PROC_DB2MAC);// -1112     /* Insuf memory to load lib      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSMEM_PROC_DB2AIX);// -10015    /* Insuf memory to load lib      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INSMEM_PROC);// SQLE_RC_INSMEM_PROC_DB2AIX

    ret = PyModule_AddIntMacro(m, SQLE_RC_SQLDA_DATATYPE);// -1113         /* Data type in output SQLDA     */
                                                                           /* changed                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SQLDA_LENGTH);// -1114           /* Data length in output SQLDA   */
                                                                           /* changed                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SQLDA_VARS);// -1115             /* Num of sqlvars changed in     */
                                                                           /* SQLDA                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BKP_PEND);// -1116               /* Backup pending                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ROLLFWD_PEND);// -1117           /* Roll forward pending          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BKP_INPROG);// -1118             /* Need to rerun the Backup      */
                                                                           /* process                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_RST_INPROG);// -1119             /* Need to rerun the Restore     */
                                                                           /* process                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BR_INPROG);// -1120              /* Need to rerun either Backup   */
                                                                           /* or Restore process            */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVNODESTR_PTR);// -1121         /* Invalid Node structure        */
                                                                           /* pointer                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPROTOCOL_PTR);// -1122        /* Invalid Protocol structure    */
                                                                           /* pointer                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPROTOCOL);// -1123            /* Invalid protocol type         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVRNNAME);// -1124              /* Invalid remote workstation    */
                                                                           /* name                          */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVADAPTER);// -1125             /* Invalid adapter number        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVNETID);// -1126               /* Invalid network id            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVPLU);// -1127                 /* Invalid real partner LU name  */

    ret = PyModule_AddIntMacro(m, SQLE_RC_DARI_INSSYS);// -1129            /* Insuf system resources for    */
                                                 /* DARI                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DARI_MAXDARI);// -1130           /* Max DARI process limit        */
                                                 /* reached                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DARI_ABEND);// -1131             /* DARI process abnormally       */
                                                 /* terminated                    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DARI_INV_RQST);// -1132          /* Invalid DB2 request in DARI   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DARI_VAR_POINTER_CHG);// -1133   /* SQLVAR's sqldata or sqlind    */
                                                 /* ptrs were altered             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DARI_RQST_AUTH_ERR);// -1134     /* DB2 request is not allowed    */
                                                 /* when DB auth is client        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_NUMSEGS);// -1135            /* Invalid numsegs on create db  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_EXTSIZE);// -1136            /* Invalid extSize on create db  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MOUNTED_SEGS);// -1137           /* Mounted Segment Directories   */
                                                 /* on a drop database request    */

    ret = PyModule_AddIntMacro(m, SQLE_RC_WARN_DLMON);// 1187              /* Deadlocks event monitor not   */
                                                 /* created during create db      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_WARN_DB2LK);// 1243              /* Failed to drop db2look        */
                                                 /* operation table/view          */
                                                 /* SYSTOOLS.DB2LOOK_INFO         */
                                                 /* SYSTOOLS.DB2LOOK_INOF_V       */
                                                 /* during database migration     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_VALUE);// -1197          /* API or command option has an  */
                                                 /* invalid value                 */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVOS_OBJ);// -1200              /* Invalid object specified      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVOS_STAT);// -1201             /* Invalid status specified      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVOS_NOSTAT);// -1202           /* Status has not been           */
                                                 /* collected                     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVOS_NOUSER);// -1203           /* No users connected to         */
                                                 /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_UNSUPP_CODEPG);// -1204          /* Active codepage is not        */
                                                 /* supported                     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_CNTRYINFO_DB2OS2);// -1205   /* Invalid territory             */
                                                 /* information                   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_CNTRYINFO_DB2NT);// -1205    /* Invalid territory             */
                                                 /* information                   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_CNTRYINFO_DB2DOS);// -1205   /* Invalid territory             */
                                                 /* information                   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_CNTRYINFO_DB2WIN);// -1205   /* Invalid territory             */
                                                 /* information                   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_CNTRYINFO_DB2MAC);// -1205   /* Invalid territory             */
                                                 /* information                   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_CNTRYINFO_DB2AIX);// -1205   /* Invalid territory             */
                                                 /* information                   */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_CNTRYINFO);// SQLE_RC_INV_CNTRYINFO_DB2NT

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_COMPUTERNAME);// -1211       /* Invalid Computer Name         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_INSTANCENAME);// -1212       /* Invalid Instance Name         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVCHGPWDLU);// -1213            /* Invalid Change Password LU    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVTPNAME);// -1214              /* Invalid Transaction Pgm Name  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVLANADDRESS);// -1215          /* Invalid LAN Adapter Addr      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_SHRD_SEG);// -1220            /* DB2 Shared Memory Set alloc   */
                                                 /* failed                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_ASL_HEAP);// -1221            /* ASL heap cannot be allocated  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ASL_TOO_SMALL);// -1222          /* ASL heap is too small         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_AGENT_AVAIL);// -1223         /* No more agents available      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_AGENT_GONE);// -1224             /* DB2 agent not active          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_PROC_LIMIT);// -1225             /* Op. Sys. couldn't spawn a     */
                                                 /* process                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MAXCOORDS);// -1226              /* Max number of coords reached  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DROPDB_WARN);// 1228             /* Drop database warning         */

    ret = PyModule_AddIntMacro(m, SQLE_RC_AGENT_NOT_FORCED);// 1230        /* At least one agent not        */
                                                 /* forced                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVCOUNT);// -1231               /* Invalid Force Users count     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVFRCE_MODE);// -1232           /* Invalid Force Users mode      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_TBS_DESC);// -1241           /* Invalid TableSpace            */
                                                 /* descriptor                    */

    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_SETCONNOPT);// -1246          /* Cannot set connection         */
                                                 /* options - existing            */
                                                 /* connections                   */

    ret = PyModule_AddIntMacro(m, SQLC_RC_NPIPE_BROKEN);//               -1281
    ret = PyModule_AddIntMacro(m, SQLC_RC_NPIPE_BUSY);//                 -1282
    ret = PyModule_AddIntMacro(m, SQLC_RC_NPIPE_PIPE_INUSE);//           -1283
    ret = PyModule_AddIntMacro(m, SQLC_RC_NPIPE_PIPE_NOT_FOUND);//       -1284
    ret = PyModule_AddIntMacro(m, SQLC_RC_NPIPE_INVALID_NAME);//         -1285
    ret = PyModule_AddIntMacro(m, SQLC_RC_NPIPE_NO_RESOURCE);//          -1286
    ret = PyModule_AddIntMacro(m, SQLC_RC_NPIPE_INST_NOT_FOUND);//       -1287

    ret = PyModule_AddIntMacro(m, SQLE_RC_DS_FAILED);// -1291              /* Directory Services failed     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DS_BAD_GLB_NAME);// -1292        /* Bad global name               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DS_BAD_GLB_DIR_ENTRY);// -1293   /* Bad global directory entry    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DS_BAD_DIR_PATH_NAME);// -1294   /* Bad DIR_PATH_NAME             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DS_BAD_ROUTE_NAME);// -1295      /* Bad ROUTE_OBJ_NAME            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DS_UNSUPPORTED_CMD);// -1297     /* Command not supported         */

    ret = PyModule_AddIntMacro(m, SQLE_RC_DCE_INVPN);// -1300              /* Invalid DCE principal name    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DCE_ERR_KEYTAB);// -1301         /* Error DCE keytab file         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DCE_ERR_MAPPING);// -1302        /* DCE principal and DB2 authid  */
                                                 /* mapping error                 */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SECD_ERR_RESTART);// -1303       /* Security daemon could not be  */
                                                 /* restarted                     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVSTCP);// -1304                /* Invalid security type for     */
                                                 /* TCP/IP protocol               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DCE_ERR);// -1305                /* DCE internal error            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_AUD_INV_PARM);// -1306           /* Invalid parameter to audit    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_AUD_ERR);// -1307                /* Audit error                   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DCE_INV_PRINC);// -1309          /* DCE invalid server principal  */
                                                 /* name                          */

    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEDCS);// -1310                /* DCS Directory file access     */
                                                 /* error                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DCSDIR_NF);// -1311              /* DCS Directory not found       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_ENTRY);// 1312                /* DCS Directory is empty        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MAX_ENTRY);// -1313              /* DCS Directory is full         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVENTRY_PTR);// -1314           /* Entry parameter pointer       */
                                                 /* invalid                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVLDB);// -1315                 /* Local DB name has invalid     */
                                                 /* chars                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_LDB_NF);// -1316                 /* DCS Directory entry not       */
                                                 /* found                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DUPLDB);// -1317                 /* DCS Directory duplicate       */
                                                 /* entry                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVLENGTH);// -1318              /* Invalid element length        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ENTRYNOT_COL);// -1319           /* Entries have not been         */
                                                 /* collected                     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_GDBUSY);// -1320                 /* Cannot access DCS Dir at      */
                                                 /* this time                     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVSTRUCT_ID);// -1321           /* Invalid structure ID          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_AUD_WRITE_ERR);// -1322          /* Error writing to audit log    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_AUD_CFG_FILE_ERR);// -1323       /* Error accessing db2audit.cfg  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DRDANSP);// -1325                /* Remote function not           */
                                                 /* supported                     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ACCD);//   -1326                 /* File or directory access      */
                                                 /* denied                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_IMPLCONN_INVDB);// -1327         /* Implicit connect - invalid    */
                                                 /* dbname                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_IMPLCONN_NODB);// -1328          /* Implicit connect - alias not  */
                                                 /* found                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_PATH_TOO_LONG);// -1329          /* Input path too long           */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVSDNAME);// -1330              /* Invalid symbolic destination  */
                                                 /* name                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVSTYPE);// -1331               /* Invalid CPIC security type    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_HOSTNAME);// -1332           /* Invalid Host Name             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SERNAME);// -1333            /* Invalid Service Name          */

    ret = PyModule_AddIntMacro(m, SQLE_RC_DOUBLE_REMOTE);// -1334          /* Double-hops not allowed       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVAR);//  -1335                 /* AR name has invalid chars     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_UNKNOWN_FILESERVER);// -1340     /* File server is unknown        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_FSERVER);// -1342            /* Invalid File Server           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_OBJNAME);// -1343            /* Invalid Object Name           */

    ret = PyModule_AddIntMacro(m, SQLE_RC_BR_ACTIVE);// -1350              /* Backup or Restore is active   */

    ret = PyModule_AddIntMacro(m, SQLE_RC_ALREADY_QUIESCED);// 1371        /* Quiesce already active        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_UNQUIESCE_FAILED);// 1373        /* Unquiesce failed              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_INSTANCE);// -1390           /* Invalid Instance Name         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSTANCE_USING);// -1391         /* Another Instance is using     */
                                                                           /* the DB                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_DB2PATH);// -1393            /* Invalid DB2 Path Name         */

    #ifndef SQLE_RC_SERVICE_LOGON_FAILURE
    #define SQLE_RC_SERVICE_LOGON_FAILURE -1397
    #endif
    ret = PyModule_AddIntMacro(m, SQLE_RC_SERVICE_LOGON_FAILURE);// -1397  /* The DB2 service failed to     */
                                                                           /* logon                         */

    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_AUTH);// -1400               /* Unsupported authentication    */
                                                                           /* type                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DIFF_AUTH);// -1401              /* Authentication types do not   */
                                                                           /* match                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_AUTH_ERR);// -1402               /* Authentication failed due to  */
                                                                           /* unexpected error              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_AUTH_FAILURE);// -1403           /* Invalid user name and/or      */
                                                                           /* password                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_PASSWORD_EXPIRED);// -1404       /* Password has expired          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_PASSWORD_WITHOUT_USERID);//    -1425   /* Password without        */
                                                                           /* userid                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB2INSTDFT_ERROR);// -1426       /* Error getting DB2INSTDFT      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOT_INSTANCE_ATTACHED);// -1427  /* No current attachment         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRONG_ATTACH);// -1428           /* Attached to wrong instance    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_RELPATH_NOT_ALLOWED);// -1431    /* Relative path not allowed     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_WRONG_CONNECT);// -1433          /* Connected to wrong database   */

    ret = PyModule_AddIntMacro(m, SQLE_RC_CTX_INV_PARM);// -1441           /* Ctx parm invalid              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CTX_NOTINUSE);// -1442           /* App Ctx not in use            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CTX_USING);// -1443              /* Already using Ctx             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CTX_INUSE);// -1444              /* App Ctx in use                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CTX_NO_CTX);// -1445             /* Thread does not have context  */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INVREGINFO_PTR);// -1450         /* Invalid registration info.    */
                                                                           /* ptr.                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_REG_INVNODE);// -1451            /* Reg. issued from invalid      */
                                                                           /* node                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVREGLOC);// -1452              /* Invalid registration          */
                                                                           /* location                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVCFG_FSNAME);// -1453          /* Invalid file server in DBM    */
                                                                           /* cfg.                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVCFG_OBJNAME);// -1454         /* Invalid object name in DBM    */
                                                                           /* cfg.                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVCFG_IPXSOCKET);// -1455       /* Invalid IPX socket in DBM     */
                                                                           /* cfg.                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DUPLICATE_OBJNAME);// -1456      /* Object name already exists    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NWDS_CONNEXISTS);// -1457        /* NWDS connection exists,       */
                                                                           /* cannot log into NW            */
                                                                           /* fileserver                    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_REG_NOT_NEEDED);// -1458         /* DB2 server reg./dereg. not    */
                                                                           /* needed                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVSTYPE_TCP);// -1461           /* Invalid TCP/IP Security       */

    ret = PyModule_AddIntMacro(m, SQLE_RC_ONE_BUFFERPOOL);// 1478          /* Database is started but only  */
                                                                           /* one bufferpool is started     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_SECD_FAILURE);// -1525           /* An error occured when         */
                                                                           /* starting the DB2 security     */
                                                                           /* daemon                        */

    ret = PyModule_AddIntMacro(m, SQLE_RC_VI_ERROR);// -1526               /* FCM startup error when using  */
                                                                           /* VI                            */

    ret = PyModule_AddIntMacro(m, SQLE_RC_UNSUPP_FUNCTION);// -1650        /* Function is no longer         */
                                                 /* supported                     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SERVERLVL);// -1651          /* Invalid server level for      */
                                                 /* request                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FILEIO_ERR);// -1652             /* File I/O error                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_PROFILE_PATH);// -1653       /* Invalid profile path          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INSTPATH_ERR);// -1654           /* Instance path error           */

    ret = PyModule_AddIntMacro(m, SQLE_RC_GENERATOR_FAILED);// -1660       /* Generator failed              */

    ret = PyModule_AddIntMacro(m, SQLE_RC_DSCVR_DISABLED);// -1670         /* Discover is disabled in DBM   */
                                                 /* CFG                           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SEARCH_DSCVR_FAILED);// -1671    /* Search discovery failed       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_DSCVR_ADDRLST);// -1673      /* Invalid discover address      */
                                                 /* list                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_DSCVR_ADDR);// -1674         /* Invalid discover address      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_ADMINSERVER);// -1675        /* Invalid admin. server         */

    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_SCHEMA);// -1700             /* Invalid Schema name found     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_NOT_MIGR);// -1701            /* DB cannot be migrated         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CRT_EVENT_FAIL);// -1703         /* Fail to create db2event dir   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_MIG_FAIL);// -1704            /* DB migration failed           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_UPDATE_DIR_FAIL);// 1705         /* Fail to update directory      */
                                                                           /* entry                         */
#ifndef SQLE_RC_UPGRADE_WARN
#define SQLE_RC_UPGRADE_WARN 1708
#endif
    ret = PyModule_AddIntMacro(m, SQLE_RC_UPGRADE_WARN);// 1708            /* Upgrade complete with         */
                                                                           /* warning code                  */

    #ifndef SQLE_RC_INVALID_NETMONCF
    #define SQLE_RC_INVALID_NETMONCF -1786
    #endif
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_NETMONCF);// -1786       /* The member or CF failed to    */
                                                                           /* start due to an invalid       */
                                                                           /* netmon.cf file                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_REQINFO_PTR);// -1800        /* Invalid Request Info pointer  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_REQUEST_TYPE);// -1801       /* Invalid Request Type          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_NODE_ENTRY);// -1802          /* No entry belongs to Request   */
                                                                           /* Type                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODE_EXIST);// -1803             /* Node already exists in node   */
                                                                           /* directory                     */

    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_ACTIVATED);// 1490            /* DB is already activated       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_NOT_STOPPED);// -1491         /* DB is still active            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB_NOT_UP);// -1492              /* DB is not active              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_APP_IS_CONNECTED);// -1493       /* Application is connected to   */
                                                 /* a database                    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ACT_DB_CONNECTED);// 1494        /* There is already DB           */
                                                 /* connection                    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DEACT_DB_CONNECTED);// 1495      /* There is still DB connection  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DEACT_DB_NOT_ACTIVATED);// 1496  /* DB is not activated           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ACTDEACT_ERROR);// 1497          /* Error occurs on some nodes    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DEACT_DB_IOSUSPENDED);// 1649    /* Db is in IO Suspend mode.     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVALID_PARM);// -2032           /* Invalid parameter             */

    ret = PyModule_AddIntMacro(m, SQLE_RC_QUIESCE_PENDING);// -3807        /* Quiesce is pending            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_UNQUIESCE_PENDING);// -3808      /* Unquiesce is pending          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_E4411);//  -4411                 /* Error not Admin Server        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NOADMSTART);// -4414             /* Admin Server not started      */

    ret = PyModule_AddIntMacro(m, SQLE_RC_COMM_FAILED);// 5043             /* Communications support        */
                                                                           /* failed                        */

    ret = PyModule_AddIntMacro(m, SQLE_RC_HCA_DOWN);// 1659                /* One or more CF ports failed   */

    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_VENDOR_CFG);// -5500          /* Vendor cfg file not found     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_VENDOR_CFG);// -5501         /* Vendor cfg file invalid       */

    ret = PyModule_AddIntMacro(m, SQLE_RC_SDIRERR);// -6022                /* System database directory is  */
                                                                           /* not shared by all PDB nodes   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_PATH_NOT_QUAL);// -6027          /* The path specified for the    */
                                                 /* database directory is not     */
                                                 /* valid                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_LOCALDB_NOT_FOUND);// -6028      /* Database is not found in      */
                                                 /* local database directory      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INV_PARM);// -6030               /* Invalid parameter for start   */
                                                 /* stop                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ERR_DB2NODES_CFG);// -6031       /* Error in db2nodes.cfg file    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_STARTED_PARTIALLY);// 6032       /* Some nodes have not been      */
                                                 /* started properly              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_STOPPED_PARTIALLY);// 6033       /* Some nodes have not been      */
                                                 /* stopped properly              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODE_NOT_INUSE);// 6034          /* The node is not in used by    */
                                                 /* any database                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODE_INUSE);// 6035              /* The node is used by a         */
                                                 /* database                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_START_STOP_IN_PROG);// -6036     /* Start/stop command in         */
                                                 /* progress                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODE_TIMEOUT);// -6037           /* Timeout reached for start     */
                                                 /* stop                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_INVDROP_ACTION);// -6046         /* Invalid action for DROP NODE  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_COMM_ERR);// -6048               /* Communication error in start  */
                                                 /* stop                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_NODE_NEED_STOP);// -6072         /* Need to stop the node before  */
                                                 /* starting the node with the    */
                                                 /* restart option                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADD_NODE_FAIL);// -6073          /* Add Node failed               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADD_NODE_CRDP);// -6074          /* Add Node is not allowed       */
                                                 /* because a conflicting         */
                                                 /* command is  in progress       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADD_NODE_OK);// 6075             /* Add Node operation            */
                                                 /* successful                    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ONLINEADDNODE_OPERERR);// -1483  /* Online add node failed        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADDNODE_RESTRICTED);// -1484     /* A conflicting command is not  */
                                                 /* allowed while add node is     */
                                                 /* running                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ONLINEADDNODE_STATERR);// -1485  /* State of the instance does    */
                                                 /* not allow online add node to  */
                                                 /* proceed                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADDNODE_DONEOFFLINE);// 1487     /* A node is added offline to a  */
                                                 /* single node instance          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADDNODE_DONEINCLUSTER);// 1488   /* A node is added  to an        */
                                                 /* instance managed by the DB2   */
                                                 /* Cluster Manager               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ONLINEADDNODE_DONE);// 1489      /* A node is added online        */
                                                 /* successfully                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CM_INCONSISTENT);// -1517        /* Cluster resources are         */
                                                 /* inconsistent                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_OLDVIEWAPP_EXIST);// -1524       /* An application with oldview   */
                                                 /* of the instance exists.       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_LAST_CF);// -1529                /* The last CA cat not be        */
                                                 /* dropped.                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_LAST_MEMBER);// -1541            /* The last member cat not be    */
                                                 /* dropped.                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MAXNUM_CF);// -1542              /* The maximum number of CA's    */
                                                 /* in the DB2 instance has been  */
                                                 /* reached.                      */
    ret = PyModule_AddIntMacro(m, SQLE_RC_HOST_HAS_CF);// -1543            /* The host specified for the    */
                                                 /* CA is a duplicate             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_TOPOLOGY_BACKUP);// -1544        /* Backup of a database          */
                                                 /* following a topology change   */
                                                 /* cannot be performed from a    */
                                                 /* newly added member.           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_TOPOLOGY_RESTORE);// -1545       /* Restore of a database image   */
                                                 /* from a previous topology is   */
                                                 /* not supported                 */
    ret = PyModule_AddIntMacro(m, SQLE_RC_TOPOLOGY_ROLLFORWARD);// -1546   /* Rollforward through an add    */
                                                 /* or drop member operation is   */
                                                 /* not permitted                 */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADDDROP_RECOVERY);// -1547       /* Recovery is needed for a      */
                                                                           /* previously failed add or      */
                                                                           /* drop operation.               */

#ifndef SQLE_RC_RFWD_WRONG_MEMBER
#define SQLE_RC_RFWD_WRONG_MEMBER -1714
#define SQLE_RC_TOP_NO_COMMON_MEMBER -1710
#define SQLE_RC_TOP_UPGRADE -1712
#define SQLE_RC_CF_TRANSPORT_ERROR -1721
#define SQLE_RC_10GE_CARD_RESTRICTION -1726
#endif
    ret = PyModule_AddIntMacro(m, SQLE_RC_RFWD_WRONG_MEMBER);// -1714      /* Rollforward cannot be         */
                                                                           /* initiated from a member that  */
                                                                           /* is not in the current         */
                                                                           /* database topology             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_TOP_NO_COMMON_MEMBER);// -1710   /* The operation cannot be       */
                                                                           /* performed because the source  */
                                                                           /* member topology and the       */
                                                                           /* target member topology have   */
                                                                           /* no common member              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_TOP_UPGRADE);// -1712            /* The command failed because    */
                                                                           /* the source and target member  */
                                                                           /* topologies are not at the     */
                                                                           /* same DB2 product level        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CF_TRANSPORT_ERROR);// -1721     /* Error in starting up with     */
                                                 /* the current CF_TRANSPORT      */
                                                 /* METHOD database manager       */
                                                 /* configuration parameter       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_10GE_CARD_RESTRICTION);// -1726  /* Ethernet card speed does not  */
                                                                           /* meet the 10GE minimum         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DROP_PROMPT);// 6076             /* Prompt for db2stop DROP       */
                                                                           /* NODENUM                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DROP_OK);// 6077                 /* Drop node OK. Files still     */
                                                                           /* exist                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DROP_FAILED);// -6078            /* Drop node failed              */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DROP_CANCEL);// 6079             /* Drop node cancelled           */
                                                 /* successfully                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_ADD_NODE_NODB);// 6080           /* Add Node succeeded but no     */
                                                 /* databases created on the      */
                                                 /* node                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_FORCE_TIMEOUT_ERR);// -6081      /* Timeout reached in stop       */
                                                 /* FORCE                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CLUSTER_MGR_FAILED);// -1677     /* DB2 Cluster Services failed   */
                                                 /* to update the states of       */
                                                 /* resources                     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CF_HOST_STOPPED);// 1678         /* The CF host was previously    */
                                                 /* stopped by db2stop INSTANCE   */
                                                 /* ON command                    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CF_HOST_UNREACHED);// -1679      /* The CF host can't be reached  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_GUEST_STOP_FAILED);// -1687      /* The member is performing      */
                                                 /* recovery or resolving in      */
                                                 /* doubt transaction             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MEMBER_HOST_UNREACHED);// 1680   /* The member host can't be      */
                                                 /* reached, member will be       */
                                                 /* started as guest member       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MEMBER_HOST_STOPPED);// 1681     /* The member host was           */
                                                 /* previously stopped, member    */
                                                 /* will be started as guest      */
                                                 /* member                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_CF_NOT_STOPPABLE);// -1688       /* The CF contains dirty pages   */
                                                 /* or holds locks                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MEMBER_START_LIGHT);// 1682      /* The member is started as      */
                                                 /* guest member                  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_HOME_HOST_NOT_STARTED);// 1689   /* The home host has not         */
                                                 /* started yet when the member   */
                                                 /* is stopped                    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_HOST_UNREACHED);// -1690         /* The host can't be reached     */
                                                 /* during db2stop member or CF   */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MEMBER_OR_CF_RUNNING);// -1691   /* The active member or CF is    */
                                                 /* running on the host           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_RESTART_LIGHT_FAILED);// -1683   /* Restart light animation       */
                                                 /* failed                        */
    ret = PyModule_AddIntMacro(m, SQLE_RC_IDLE_START_FAILED);// -1684      /* The idle process failed to    */
                                                 /* start                         */
    ret = PyModule_AddIntMacro(m, SQLE_RC_IDLE_STOP_FAILED);// -1692       /* The idle process failed to    */
                                                 /* stop                          */
    ret = PyModule_AddIntMacro(m, SQLE_RC_MEMBER_CF_NOT_STARTED);// -1685  /* The member failed to start    */
                                                 /* because CF failed to start    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_HOST_START_FAILED);// -1686      /* The instance on the host      */
                                                 /* failed to start               */
    ret = PyModule_AddIntMacro(m, SQLE_RC_HOST_STOP_FAILED);// -1693       /* The isntance on the host      */
                                                 /* failed to stop                */

    ret = PyModule_AddIntMacro(m, SQLE_RC_DB2_SERVER_LICENSE);// -8000     /* No DB2 license                */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DB2_LICENSE);// -8001            /* Out of DB2 client licenses    */
    ret = PyModule_AddIntMacro(m, SQLE_RC_DDCS_LICENSE);// -8002           /* Out of DDCS clients           */

    ret = PyModule_AddIntMacro(m, SQLE_RC_NO_FED_CFG);// -5180             /* Federated cfg file not found  */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_FED_CFG);// -5181            /* Federated cfg file invalid    */

    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_PORT);// -1888               /* Invalid port number           */
    ret = PyModule_AddIntMacro(m, SQLE_RC_IGNORE_UPD_ALT_SVR);// 1889      /* Update Alternate Server       */
                                                 /* Ignored                       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_HOSTNAME);// -1890           /* Invalid host name             */
    ret = PyModule_AddIntMacro(m, SQLE_RC_HOSTNAME_PTR);// -1891           /* Invalid host name pointer     */
    ret = PyModule_AddIntMacro(m, SQLE_RC_PORT_PTR);// -1892               /* Invalid port number pointer   */

    /* The following functions and symbols are obsolete and may not be            */
    /* supportedin future releases. The obsolete functions are provided for       */
    /* backward compatibilityand exported from DB2API.LIB. All applications       */
    /* should be migrated to use new APIs.Note: Some of the function parameters   */
    /* may be NO-OP.      Some structures are larger (eg. SQLEDINFO) in V2.       */
    ret = PyModule_AddIntMacro(m, SQLE_RC_BAD_SEGPAGES);// -1136           /* Invalid numsegs on create db  */

    ret = PyModule_AddIntMacro(m, SQLE_RC_CS_LICENSE);// -8003             /* No CS/6000 license            */
    ret = PyModule_AddIntMacro(m, SQLE_RC_SNA_LICENSE);// -8004            /* No SNA/6000 license           */

    ret = PyModule_AddIntMacro(m, SQL_AUTHENTICATION_UNDEF);// 255         /* Authentication Undefined      */


    return ret;
}

