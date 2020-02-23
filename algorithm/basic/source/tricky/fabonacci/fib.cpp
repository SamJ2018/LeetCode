#include "include/Fib.h"

//迭代版
int64_t fib1(int n) 
{
	int64_t f = 1, g = 0;
	while(n-- > 0) g += f,f = g - f;
	return g;
}

//二分递归(2^n)
int64_t fib(int n){
	return (n < 2) ? (int64_t) n : fib(n - 1) + fib(n - 2);
}

//线性递归版
int64_t fib(int n,int64_t& prev)
{
	if(0 == n)
	{
		prev = 1;
		return 0;
	}
	else
	{
		int64_t prevPrev;
		prev = fib(n - 1, prevPrev); //递归计算前两项
		return prevPrev + prev;
	}
}//用辅助变量记录前一项，返回数列当前项, O(n)


