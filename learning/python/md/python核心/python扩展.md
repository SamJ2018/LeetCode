## python扩展知识

1. Python 中一个非常好的特性是，无论是扩展还是普通 Python 模块，解释器与其交互方式
   完全相同。这样设计的目的是对导入的模块进行抽象，隐藏扩展中底层代码的实现细节。  
2. 编译过的文件相对来说不易进行逆向工程，这样就将源码隐藏起来了。在涉及特殊算法、加密或软件安全性时这，这就显得十分重要。  

## 编写python扩展 3个步骤

> 1. 创建应用代码。
> 2. 根据样板编写封装代码。
> 3. 编译并测试  

### 一、创建应用代码  

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
```

### 二、根据样板编写封装代码  

> 开发者需要精心设计扩展代码，无缝连接 Python 和相应的扩展实现语言。这种接口代码通常称为样板（boilerplate）代码  

样板代码主要含有四部分。
1．包含 Python 头文件。
2．为每一个模块函数添加形如 PyObject*Module_func()的封装函数。
3．为每一个模块函数添加一个 PyMethodDef ModuleMethods[]数组/表。
4．添加模块初始化函数 void initModule()。  

```c
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
```

### 编译并测试

```python
#!/usr/bin/env python
# coding=utf-8
from distutils.core import setup,Extension
MOD = 'Extest'
setup(name =MOD, ext_modules=[
    Extension(MOD,sources=['Extest1.c'])
])
```

> 执行命令：
>
> python setup.py install 