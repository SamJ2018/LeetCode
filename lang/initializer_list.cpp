#include <initializer_list>
#include <iostream>
#include <cstddef>
using namespace std;
#define forn(n)  for(int i = 0; i < n; ++i)

// initializer_list 模拟
template<typename T>
class MyInitializerList{
public:
	using value_type = T;
	using reference = const T&;  //注意！const: initializer_list的元素是不可改变的
	using const_reference = const T&;
	using size_type = size_t;
	using iterator = const T*;
	using const_iterator = const T&;

	MyInitializerList() noexcept;

	size_t size() const noexcept; //元素个数
	const T* begin() const noexcept;  //首元素
	const T* end() const noexcept;    //尾元素
};

template < typename T>
const T* begin(MyInitializerList<T> lst) noexcept
{
	return lst.begin();
}

template < typename T>
const T* end(MyInitializerList<T> lst) noexcept
{
	return lst.end();
}

// 注意1  initializer_list 没有提供下标运算符 需要使用指针使用下标
void f(initializer_list<int> lst)
{
	forn(lst.size()) ;
		//错误 cout << lst[i] <<'\n'
	
	const int* p = lst.begin();
	forn(lst.size()) cout << p[i] <<endl;
}


void f2(initializer_list<int> lst)
{
	for(auto &x : lst) cout << x << " ";
}

int main(int args,const char* argv[])
{

	f2({1,3,5,7,9});
	
	return 0;
}


