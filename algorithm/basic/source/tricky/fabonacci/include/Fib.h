#ifndef FIB_H
#define FIB_H

#include <iostream>
#include <cstdlib>
using namespace std;

int64_t fib1(int n);  //迭代版
int64_t fib(int n);   //递归版
int64_t fib(int n,int64_t& f);  //线性递归版

//fabonacci数列类
class Fib{
private:
	int f,g;   //f = fib(k-1), g = fib(k);
public:
	Fib(int n) { 
		f = 1; g = 0; 
		while(g < n) next();
	}

	int get() { return g; }
	int next() { g += f; f = g - f; return g; }
	int prev() { f = g - f; g -= f; return g; }
};

#endif
