#include "/usr/include/python2.7/Python.h"

static PyObject *
Extest_fac(PyObject *self,PyObject *args)
{
	int res;
	int num;
	PyObject* retval;

	res = PyArg_ParseTuple(args,"i",&num);
	if(!res)
	{
		return NULL;
	}
	res = fac(num);
	retval = (PyObject*) Py_BuildValue("i",res);
	return retval;
}



int main()
{
    printf("Hello world\n");
    return 0;
}

