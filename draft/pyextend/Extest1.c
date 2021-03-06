#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/usr/include/python2.7/Python.h"

int fac(int n)
{
	if (n < 2)
		return 1;
	return n * fac(n -1);
}

char *reverse(char *s)
{
	char t, *p = s, *q = (s + (strlen(s) - 1));
	while(p < q)
	{
		t = *p;
		*p++ = *q;
		*q-- = t;
	}

	return s;
}


/*
   static PyObject*
   Extest_fac(PyObject *self,PyObject *args)
   {
   int res;
   int num;

   PyObject* retval;
   res = PyArg_Parse(args,"i",&num);
   if(!res)
   {
   return NULL;
   }
   res = fac(num);
   retval = (PyObject*) Py_BuildValue("i",res);
   return retval;
   }
 */

	static PyObject *
Extest_fac(PyObject *self,PyObject *args)
{
	int num;
	if(!PyArg_ParseTuple(args,"i",&num))
		return NULL;
	return (PyObject*) Py_BuildValue("i",fac(num));
}

	static PyObject *
Extest_doppel(PyObject *self,PyObject *args)
{
	char *orig_str;
	//防止内存泄漏
	char *dupe_str;
	PyObject* retval;
	if(!PyArg_ParseTuple(args,"s",&orig_str))
		return NULL;
	retval =(PyObject*)Py_BuildValue("ss",orig_str,\ 
									 dupe_str = reverse(strdup(orig_str)));
	free(dupe_str);
	return retval;
}

static PyMethodDef
ExtestMethods[] = {
	{ "fac", Extest_fac, METH_VARARGS  },
	{ "doppel", Extest_doppel, METH_VARARGS  },
	{ NULL, NULL  },
	
};

//添加模块初始化函数 void initModule()
//第一个参数是模块名称，第二个是 ModuleMethods[]数组
void initExtest() {
	Py_InitModule("Extest", ExtestMethods);
	
}

int main()
{
	char s[BUFSIZ];
	printf("4! == %d\n",fac(4));	
	printf("8! == %d\n",fac(8));	
	printf("12! == %d\n",fac(12));	
	strcpy(s, "abcdef");
	printf("reversing 'abcdef',we get '%s'\n" ,\
		   reverse(s));
	strcpy(s,"madam");
	printf("reversing 'madam' we get '%s' \n",\
		   reverse(s));
	return 0;
}



