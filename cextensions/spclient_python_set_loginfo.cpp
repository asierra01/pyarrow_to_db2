
#include "spclient_python_common_cpp.h"



/*  wrapped python_set_mylog function  */
PYOBJ_PTR python_set_mylog(PYOBJ_PTR self, PYOBJ_PTR args)
{

    /*

        possible Python call : set_mylog(mylog.info)
    */
    if (!PyArg_ParseTuple(args, "O", &mylog_info))
    {
        PyErr_Format(PyExc_ValueError,
            "parameters count must be 1, mylog.info ");
        return NULL;
    }
    //printf("mylog_info '%s'\n", Py_TYPE(mylog_info)->tp_name);
    //LOG_INFO("here");
    Py_XINCREF(mylog_info);
    Py_RETURN_NONE;
}

