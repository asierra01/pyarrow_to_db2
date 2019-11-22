

#include "spclient_python_common_cpp.h"

int TbLoadQuery(char* tableName, struct sqlca& sqlca);

/*  wrapped python_monitor_load  */

PYOBJ_PTR  python_monitor_load(
        PYOBJ_PTR  self,
        PYOBJ_PTR  args)

{
    PyObject* py_tablename;
    int ret;
    int rc;
    char      tablename[255] = {};
    char      errorMsg[1024] = {};
    struct sqlca sqlca = {};

    /*

        possible Python call : monitor_load("TABLE_T1")
    */
    if (!PyArg_ParseTuple(args, "O", &py_tablename))
    {
        PyErr_Format(PyExc_ValueError,
            "parameters count must be 1, table_name");
        return NULL;
    }

    if (py_tablename != Py_None)
    {
        py11::str py_str_tablename= py11::reinterpret_borrow<py11::str>(py_tablename);
        strcpy_s(tablename, 255, ((string)py_str_tablename).c_str());
    }

    ret = TbLoadQuery(tablename, sqlca);
    if (ret != 0)
        SPCLIENT_ERROR;

    Py_RETURN_NONE;
}

int TbLoadQuery(
    char * tableName,
    struct sqlca& sqlca)
{
    int rc;
    
    //char tableName[128];
    char loadMsgFileName[128] = {};
    db2LoadQueryStruct loadQueryParameters;
    db2LoadQueryOutputStruct loadQueryOutputStructure;

    cout << "\n-----------------------------------------------------------";
    cout << "\nUSE THE DB2 API:" << endl;
    cout << "  db2LoadQuery -- Load Query" << endl;
    cout << "TO CHECK THE STATUS OF A LOAD OPERATION." << endl;

  // Initialize structures
  memset(&loadQueryParameters, 0, sizeof(db2LoadQueryStruct));
  memset(&loadQueryOutputStructure, 0, sizeof(db2LoadQueryOutputStruct));

  // Set up the tablename to query.
  loadQueryParameters.iStringType = DB2LOADQUERY_TABLENAME;
  loadQueryParameters.piString = tableName;

  // Specify that we want all LOAD messages to be reported.
  loadQueryParameters.iShowLoadMessages = DB2LOADQUERY_SHOW_ALL_MSGS;

  // LOAD summary information goes here.
  loadQueryParameters.poOutputStruct = &loadQueryOutputStructure;

  // Set up the local message file.
  loadQueryParameters.piLocalMessageFile = loadMsgFileName;

  // call the DB2 API
  //strcpy(tableName, "ORG");
  strcpy(loadMsgFileName, "tbldqry.MSG");

  // load query
  cout << "READY." << endl;
  cout << tableName << endl;
  rc = db2LoadQuery(db2Version1010, &loadQueryParameters, &sqlca);

  cout << "rc = " << rc;
  cout << "\n  Note: the table load for '" << tableName
       << "' is NOT in progress." << endl;
  cout << "  So an empty message file '" << loadMsgFileName
       << "' will be created," << endl;
  cout << "  and the following values will be zero." << endl;

  DB2_API_CHECK("status of load operation -- check");

  cout << "\n  Load status has been written to local file "
       << loadMsgFileName << endl;
  cout << "    Number of rows read      = "
       << loadQueryOutputStructure.oRowsRead << endl;
  cout << "    Number of rows skipped   = "
       << loadQueryOutputStructure.oRowsSkipped << endl;
  cout << "    Number of rows loaded    = "
       << loadQueryOutputStructure.oRowsLoaded << endl;
  cout << "    Number of rows rejected  = "
       << loadQueryOutputStructure.oRowsRejected << endl;
  cout << "    Number of rows deleted   = "
       << loadQueryOutputStructure.oRowsDeleted << endl;
  cout << "    Number of rows committed = "
       << loadQueryOutputStructure.oRowsCommitted << endl;
  cout << "    Number of warnings       = "
       << loadQueryOutputStructure.oWarningCount << endl;

  return 0;
} //TbMove::TbLoadQuery
