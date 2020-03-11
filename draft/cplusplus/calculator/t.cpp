using namespace std;
#include <iostream>

constexpr int isqrt_helper(int sq,int d,int a)
{
	return sq <= a ? isqrt_helper(sq + d, d + 2, a):d;
}

constexpr int isqrt(int x)
{
	return isqrt_helper(1,3,x)/2 - 1;
}
class X{
public:
	X(int);
};

class Arena{
public:
	virtual void* alloc(size_t) = 0;
	virtual void free(void *) = 0;
};

void *operator new (size_t sz,Arena *a)
{
	return a->alloc(sz);
}
#include <stdlib.h>
#include <cstring>
#include <typeinfo>
void test_array(char a[])
{
	std::cout << strlen(a);
	std::cout << typeid(strlen(a)).name();
}

template<typename T,int N>
void foo(T(&a)[N])
{
	a[0] = 97;
	for(int i : a) cout << i << endl;
	std::cout << a;
}

void add_plus(int & a, int(*p)(int ,int ))
{
	a = p(3,4);
}

[[noreturn]] void exit_code(){
	std::cout << "\n";
}

void test_static(){
	static int i;
	std::cout << i;
}

int main()
{
	int b[] = {13,4,52,3,4,5,6};
	foo(b);
    return 0;
}



