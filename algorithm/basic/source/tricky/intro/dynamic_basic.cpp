#include <iostream>
using namespace std;

//递归 -> 迭代   将递归本质抽象出来 化为迭代

int fib(int n) {
	return (2 > n) ? n : fib(n - 1) + fib(n - 2) ;
}




int main()
{
	cout << fib(45) ;
    return 0;

}

