#include <cstdio>
#include <stdlib.h>
#include "include/Fib.h"

int main(int argc,char* argv[])
{
	if(argc < 2) {
		fprintf(stderr,"Usage:%s <rank>\n",argv[0]);
		return 1;
	}

	int n = atoi(argv[1]);

	printf("\n--------class Fib--------------\n");
	Fib f(0);	
	
	for(int i = 0; i < n; i++,f.next())
		printf("fib(%2d) = %d\n",i,f.get());

	for(int i = 0; i <= n; i++,f.prev())
		printf("fib(%2d) = %d\n",n - i,f.get());

	printf("\n--------lteration------------\n");
	for(int i = 0; i < n; i++ ){
		printf("fib(%2d) = %d\n",i,fib1(i));
	}

	printf("\n---------Linear Recursion-----------\n");
	for(int i = 0; i < n; i++)
	{
		int64_t f;
		printf("fib(%2d) = %d\n",i , fib(i,f));
	}
	
	printf("\n---------Binary Recursion------------\n");
	for(int i = 0; i < n; i++)
		printf("fib(%2d) = %d\n",i ,fib(i));

    return 0;
}

