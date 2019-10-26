/*
���һ��֧��push��pop��top�Ȳ������ҿ�����O(1)ʱ���ڼ�������СԪ�صĶ�ջ��

push(x)�C��Ԫ��x����ջ��
pop()�C�Ƴ�ջ��Ԫ��
top()�C�õ�ջ��Ԫ��
getMin()�C�õ�ջ����СԪ��
����
MinStack minStack = new MinStack();
minStack.push(-1);
minStack.push(3);
minStack.push(-4);
minStack.getMin();   --> Returns -4.
minStack.pop();
minStack.top();      --> Returns 3.
minStack.getMin();   --> Returns -1.
-------------------------------------------
�㷨
(����ջ) O(1)
���ǳ���ά��������ջ�ṹ֮�⣬����Ҫά��һ������ջ����ʵ�ַ�����Сֵ�Ĳ�����
����������ά������ջ��

��������ջ��ѹ��һ����ʱ��������� �� ����ջ��ջ��Ԫ�أ��򽫸���ͬʱѹ�뵥��ջ�У����򣬲�ѹ�룬��������ջ�����Ƚ�������ʣ������ڸ���������֮ǰ��ջ��һֱ����һ�����ȸ���С�����Ը���һ�����ᱻ������С�������
�����Ǵ�ջ�е���һ����ʱ������������ڵ���ջ��ջ��Ԫ�أ���ͬʱ������ջ��ջ��Ԫ�ص�����
����ջ��������е����ԣ���������ջ��Ԫ�أ����ǵ�ǰջ�е���С����
ʱ�临�Ӷ�
���ֲ�����ֻ�г�������ջ��ջ����������ʱ�临�Ӷȶ��� O(1).
*/
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> stk, min_stk; //����ջ

    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        stk.push(x);
        if (min_stk.empty() || min_stk.top() >= x)
            min_stk.push(x);
    }

    void pop()
    {
        if (stk.top() == min_stk.top())
            min_stk.pop();
        stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */