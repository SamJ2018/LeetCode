/*
    STL： 六大组件    抽象
    容器  Container
    算法  Algorithm
    迭代器 Iterator
    仿函数 Function Object
    适配器 Adaptor
    空间配置器 Allocator
*/

//一、了解STL六大组件
#include <algorithm>
#include <vector> //动态数组
#include <queue>
#include <iostream>
using namespace std;

int m1()
{
    vector<int> v{1, 2, 3, 4, 5};
    v.push_back(10);

    //迭代器
    for_each(v.begin(), v.end(), [](int x) { cout << x << endl; });
    //算法

    // find_if();
    for (auto ib = v.begin(), ie = v.end(); ib != ie; ib++)
        cout << *ib << endl;
    cin.get();
    return 0;
}

int cnt(int *start, int *end, int val)
{
    int num = 0;
    while (start++ != end)
        if (*start == val)
            ++num;
    return num;
}

int m2()
{
    int arr[] = {0, 7, 5, 4, 9, 2, 0};
    int *pBegin = arr;
    int *pEnd = &(arr[sizeof(arr) / sizeof(arr[0])]);
    int count = cnt(pBegin, pEnd, 0);
    cout << "count:" << count;
}

//回调函数
void printV(int v)
{
    cout << v;
}

//STL基本语法
void test()
{
    vector<int> v; //定义一个容器，并且制定这个容器存放的元素类型是int
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //通过STL提供的for_each算法
    vector<int>::iterator pBegin = v.begin(); //获取迭代器vector
    vector<int>::iterator pEnd = v.end();     //数组最后个元素后面
    for_each(pBegin, pEnd, printV);           //3 需要回调函数，容器可能存放基础的数据类型，也可能存放自定义数据类型
}

//容器也可以存放自定义数据类型
class Person
{
public:
    int age;
    int id;
    Person(int age, int id) : age(age), id(id) {}
};

void test2()
{
    //创建容器，并且制定容器的元素类型是Person
    vector<Person *> v;
    Person *p1 = new Person(10, 20);
    Person *p2 = new Person(30, 40);
    Person *p3 = new Person(50, 60);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //遍历
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
        cout << (*it)->age << " ";
    cout << endl;
}

main()
{
    test2();
    return 0;
}