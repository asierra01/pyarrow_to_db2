
#include "spclient_python_common_cpp.h"


PYOBJ_PTR python_create_dummy_exception(PYOBJ_PTR self, PYOBJ_PTR args)
{
    PYOBJ_PTR p1;
    PYOBJ_PTR str;

    if (!PyArg_ParseTuple(args, "O", &p1))
    {
        Py_RETURN_NONE;
    }
    #if PY_MAJOR_VERSION == 2
        str = PyObject_Str(p1); //Return value: New reference.
    #else
        str = PyUnicode_AsEncodedString(p1, "utf-8", "~E~"); //Return value: New reference.
    #endif

    PyErr_Format(SpClientError, "dummy_exception ...dummy_error '%s'", PyBytes_AS_STRING(str));
    Py_XDECREF(str);

    return NULL;
}

