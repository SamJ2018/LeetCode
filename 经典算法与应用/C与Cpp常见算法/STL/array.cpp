#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

/*
序列式容器
    vs    
关联式容器
*/

int main()
{
    //任何容器都有配套的迭代器
    array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; //在栈区，不能动态地增加
    for (auto ib = arr.begin(), ie = arr.end(); ib != ie; ++ib)
    {
        cout << typeid(ib).name() << endl;
        cout << *ib << endl;
    }

    for (auto i : arr)
        cout << i << endl;

    for_each(arr.begin(), arr.end(), [](int &x) { x += 1; });
    for_each(arr.begin(), arr.end(), [](int x) { cout << x << endl; });

    return 0;
}