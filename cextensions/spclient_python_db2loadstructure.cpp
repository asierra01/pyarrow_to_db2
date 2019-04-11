

#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"


my_db2load_struct::my_db2load_struct(
        db2LoadOut *LoadOut,
        db2Uint64 iRowcount,
        db2Uint32 iSavecount,
        db2Uint32 iDataBufferSize,
        const char * MESSAGE_FILE)
{
    //LOG_INFO("here");
    memset(LoadOut, 0, sizeof(db2LoadOut));
    pLoadOut = LoadOut;
    this->pLoadIn = (db2LoadIn *)malloc(sizeof(db2LoadIn));
    if (this->pLoadIn == NULL)
    {
        LOG_INFO("Error allocating pLoadIn!");
        return;
    }


    this->pLoadStruct = (db2LoadStruct *)malloc(sizeof(db2LoadStruct));
    if (this->pLoadStruct == NULL)
    {
        LOG_INFO("Error allocating pLoadStruct!");
    }

    this->pDataDescriptor = (struct sqldcol *)malloc(sizeof(struct sqldcol));
    if (this->pDataDescriptor == NULL)
    {
        LOG_INFO("Error allocating pDataDescriptor!");
    }

    this->pMessageFile = (char *)malloc(256);
    if (this->pMessageFile == NULL)
    {
        LOG_INFO("Error allocating pMessageFile!");
    }

    memset(this->pDataDescriptor, 0, sizeof(struct sqldcol));
    memset(this->pLoadIn, 0, sizeof(db2LoadIn));
    memset(this->pLoadOut, 0, sizeof(db2LoadOut));
    memset(this->pLoadStruct, 0, sizeof(db2LoadStruct));

    initialize_db2loadstructure(iRowcount, iSavecount, iDataBufferSize, MESSAGE_FILE);
    //printf("%d %s done\n", __LINE__, __FUNCTION__);
}

int my_db2load_struct::initialize_db2loadstructure(
    db2Uint64 iRowcount,
    db2Uint32 iSavecount,
    db2Uint32 iDataBufferSize,
    const char * MESSAGE_FILE)
{
    /* Allocate load structures.
    NOTE that the memory belonging to the db2LoadStruct structure used
    in setting the SQL_ATTR_LOAD_INFO attribute *MUST* be accessible
    by *ALL* functions that call CLI functions for the duration of the
    CLI LOAD.  For this reason, it is recommended that the db2LoadStruct
    structure and all its embedded pointers be allocated dynamically,
    instead of declared statically. */


    this->pLoadStruct->piSourceList = NULL;
    this->pLoadStruct->piLobPathList = NULL;
    this->pLoadStruct->piDataDescriptor = this->pDataDescriptor;
    this->pLoadStruct->piFileTypeMod = NULL;
    this->pLoadStruct->piTempFilesPath = NULL;
    this->pLoadStruct->piVendorSortWorkPaths = NULL;
    this->pLoadStruct->piCopyTargetList = NULL;
    this->pLoadStruct->piNullIndicators = NULL;
    this->pLoadStruct->piLoadInfoIn = this->pLoadIn;
    this->pLoadStruct->poLoadInfoOut = this->pLoadOut;

    this->pLoadIn->iRowcount = iRowcount;
    this->pLoadIn->iRestartphase = ' ';
    this->pLoadIn->iNonrecoverable = SQLU_NON_RECOVERABLE_LOAD;
    this->pLoadIn->iStatsOpt = (char)SQLU_STATS_NONE;
    this->pLoadIn->iSavecount = iSavecount;
    this->pLoadIn->iCpuParallelism = 0;//If the value of this parameter is zero, the load utility uses an intelligent default value at run time.
    this->pLoadIn->iDiskParallelism = 0;
    this->pLoadIn->iIndexingMode = 0;
#ifdef WIN32
    this->pLoadIn->iDataBufferSize = iDataBufferSize; //If a value is not specified, an intelligent default is calculated by the utility at run time.
    //The default is based on a percentage of the free space available in the utility heap at the instantiation time
    //of the loader, as well as some characteristics of the table.
#else
	this->pLoadIn->iDataBufferSize = 0;
#endif
    sprintf(this->pMessageFile, "%s", MESSAGE_FILE);
    this->pLoadStruct->piLocalMsgFileName = this->pMessageFile;
    this->pDataDescriptor->dcolmeth = SQL_METH_D;
    return 0;

}

my_db2load_struct::~my_db2load_struct()
{
    if (this->pLoadIn != NULL)
    {
        free(this->pLoadIn);
        this->pLoadIn = NULL;
    }

    if (this->pLoadStruct != NULL)
    {
        free(this->pLoadStruct);
        this->pLoadStruct = NULL;
    }

    if (this->pDataDescriptor != NULL)
    {
        free(this->pDataDescriptor);
        this->pDataDescriptor = NULL;
    }

    if (this->pMessageFile != NULL)
    {
        free(this->pMessageFile);
        this->pMessageFile = NULL;
    }
    //printf("done %d %s()\n", __LINE__, __FUNCTION__);

}
