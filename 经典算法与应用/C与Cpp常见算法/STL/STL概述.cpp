/*
    STL�� �������    ����
    ����  Container
    �㷨  Algorithm
    ������ Iterator
    �º��� Function Object
    ������ Adaptor
    �ռ������� Allocator
*/

//һ���˽�STL�������
#include <algorithm>
#include <vector> //��̬����
#include <queue>
#include <iostream>
using namespace std;

int m1()
{
    vector<int> v{1, 2, 3, 4, 5};
    v.push_back(10);

    //������
    for_each(v.begin(), v.end(), [](int x) { cout << x << endl; });
    //�㷨

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

//�ص�����
void printV(int v)
{
    cout << v;
}

//STL�����﷨
void test()
{
    vector<int> v; //����һ�������������ƶ����������ŵ�Ԫ��������int
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    //ͨ��STL�ṩ��for_each�㷨
    vector<int>::iterator pBegin = v.begin(); //��ȡ������vector
    vector<int>::iterator pEnd = v.end();     //��������Ԫ�غ���
    for_each(pBegin, pEnd, printV);           //3 ��Ҫ�ص��������������ܴ�Ż������������ͣ�Ҳ���ܴ���Զ�����������
}

//����Ҳ���Դ���Զ�����������
class Person
{
public:
    int age;
    int id;
    Person(int age, int id) : age(age), id(id) {}
};

void test2()
{
    //���������������ƶ�������Ԫ��������Person
    vector<Person *> v;
    Person *p1 = new Person(10, 20);
    Person *p2 = new Person(30, 40);
    Person *p3 = new Person(50, 60);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //����
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
        cout << (*it)->age << " ";
    cout << endl;
}

main()
{
    test2();
    return 0;
}