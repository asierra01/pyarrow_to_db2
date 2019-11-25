

#include "spclient_python_common_cpp.h"
#include "arrow_table_to_db2.h"


db2load_struct::db2load_struct(
        db2LoadOut *LoadOut,
        db2Uint64 iRowcount,
        db2Uint32 iSavecount,
        db2Uint32 iDataBufferSize,
        const char * MessageFile,
        const char * TempFilesPath)
{
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
        return;
    }

    this->pDataDescriptor = (struct sqldcol *)malloc(sizeof(struct sqldcol));
    if (this->pDataDescriptor == NULL)
    {
        LOG_INFO("Error allocating pDataDescriptor!");
        return;
    }

    this->pTempFilesPath = (char *)malloc(256);
    if (this->pTempFilesPath == NULL)
    {
        LOG_INFO("Error allocating pTempFilesPath!");
        return;
    }

    this->pMessageFile = (char *)malloc(256);
    if (this->pMessageFile == NULL)
    {
        LOG_INFO("Error allocating pMessageFile!");
        return;
    }

    memset(this->pDataDescriptor, 0, sizeof(struct sqldcol));
    memset(this->pLoadIn, 0, sizeof(db2LoadIn));
    memset(this->pLoadOut, 0, sizeof(db2LoadOut));
    memset(this->pLoadStruct, 0, sizeof(db2LoadStruct));

    initialize_db2loadstructure(iRowcount,
                                iSavecount,
                                iDataBufferSize,
                                MessageFile,
                                TempFilesPath);
}

int db2load_struct::initialize_db2loadstructure(
    db2Uint64 iRowcount,
    db2Uint32 iSavecount,
    db2Uint32 iDataBufferSize,
    const char * MessageFile,
    const char * TempFilesPath)
{
    /* Allocate load structures.
    NOTE that the memory belonging to the db2LoadStruct structure used
    in setting the SQL_ATTR_LOAD_INFO attribute *MUST* be accessible
    by *ALL* functions that call CLI functions for the duration of the
    CLI LOAD.  For this reason, it is recommended that the db2LoadStruct
    structure and all its embedded pointers be allocated dynamically,
    instead of declared statically. */

    bool displgeneral_log = false;
    const char* env_general_log = std::getenv("SPCLIENT_PYTHON_LOG_GENERAL");
    if (env_general_log != nullptr)
    {
        if (string(env_general_log) == "1")
            displgeneral_log = true;
    }

    this->pLoadStruct->piSourceList = NULL;
    this->pLoadStruct->piLobPathList = NULL;
    this->pLoadStruct->piDataDescriptor = this->pDataDescriptor;
    this->pLoadStruct->piFileTypeMod = NULL;
    this->pLoadStruct->piTempFilesPath = NULL;

    if (TempFilesPath != nullptr)
    {
        if (strcmp(TempFilesPath, "") != 0)
        {
            sprintf(this->pTempFilesPath, "%s", TempFilesPath);
            if (displgeneral_log)
                LOG_INFO("\nSetting piTempFilesPath '%s'", this->pTempFilesPath);
            this->pLoadStruct->piTempFilesPath = this->pTempFilesPath;
         }
    }

    this->pLoadStruct->piVendorSortWorkPaths = NULL;
    this->pLoadStruct->piCopyTargetList = NULL;
    this->pLoadStruct->piNullIndicators = NULL;
    this->pLoadStruct->piLoadInfoIn = this->pLoadIn;
    this->pLoadStruct->poLoadInfoOut = this->pLoadOut;

    if (displgeneral_log)
    {
        LOG_INFO("\nSetting pLoadIn->iNonrecoverable=SQLU_NON_RECOVERABLE_LOAD\nSetting iStatsOpt=SQLU_STATS_NONE");
    }
    this->pLoadIn->iRowcount = iRowcount;
    this->pLoadIn->iRestartphase = ' ';
    this->pLoadIn->iNonrecoverable = SQLU_NON_RECOVERABLE_LOAD;
    this->pLoadIn->iStatsOpt = (char)SQLU_STATS_NONE;
    this->pLoadIn->iSavecount = iSavecount;
    this->pLoadIn->iCpuParallelism = 0;//If the value of this parameter is zero, the load utility uses an intelligent default value at run time.
    this->pLoadIn->iDiskParallelism = 0;
    this->pLoadIn->iIndexingMode = 0;
    this->pLoadIn->iDataBufferSize = iDataBufferSize; //If a value is not specified, an intelligent default is calculated by the utility at run time.
    //The default is based on a percentage of the free space available in the utility heap at the instantiation time
    //of the loader, as well as some characteristics of the table.

    this->pLoadStruct->piLocalMsgFileName = NULL;

    if (MessageFile != nullptr)
    {
        if (strcmp(MessageFile, "") != 0)
        {
            sprintf(this->pMessageFile, "%s", MessageFile);
            if (displgeneral_log)
            {
                LOG_INFO("\nSetting piLocalMsgFileName %s", this->pMessageFile);
            }
            this->pLoadStruct->piLocalMsgFileName = this->pMessageFile;
        }
    }

    this->pDataDescriptor->dcolmeth = SQL_METH_D;
    return 0;

}

db2load_struct::~db2load_struct()
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

    if (this->pTempFilesPath != NULL)
    {
        free(this->pTempFilesPath);
        this->pTempFilesPath = NULL;
    }
    //printf("done %d %s()\n", __LINE__, __FUNCTION__);

}
