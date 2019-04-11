
#include "arrow_table_to_db2.h"


int TbLoadQuery()
{
  int rc = 0;
  struct sqlca sqlca = {0};
  char tableName[128];
  char loadMsgFileName[128];
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
  strcpy(tableName, "ORG");
  strcpy(loadMsgFileName, "tbldqry.MSG");

  // load query
  db2LoadQuery(db2Version1010, &loadQueryParameters, &sqlca);

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
