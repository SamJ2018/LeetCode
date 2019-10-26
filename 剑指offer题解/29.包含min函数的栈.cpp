/*
设计一个支持push，pop，top等操作并且可以在O(1)时间内检索出最小元素的堆栈。

push(x)–将元素x插入栈中
pop()–移除栈顶元素
top()–得到栈顶元素
getMin()–得到栈中最小元素
样例
MinStack minStack = new MinStack();
minStack.push(-1);
minStack.push(3);
minStack.push(-4);
minStack.getMin();   --> Returns -4.
minStack.pop();
minStack.top();      --> Returns 3.
minStack.getMin();   --> Returns -1.
-------------------------------------------
算法
(单调栈) O(1)
我们除了维护基本的栈结构之外，还需要维护一个单调栈，来实现返回最小值的操作。
下面介绍如何维护单调栈：

当我们向栈中压入一个数时，如果该数 ≤ 单调栈的栈顶元素，则将该数同时压入单调栈中；否则，不压入，这是由于栈具有先进后出性质，所以在该数被弹出之前，栈中一直存在一个数比该数小，所以该数一定不会被当做最小数输出。
当我们从栈中弹出一个数时，如果该数等于单调栈的栈顶元素，则同时将单调栈的栈顶元素弹出。
单调栈由于其具有单调性，所以它的栈顶元素，就是当前栈中的最小数。
时间复杂度
四种操作都只有常数次入栈出栈操作，所以时间复杂度都是 O(1).
*/
#include <stack>
using namespace std;

class MinStack
{
public:
    stack<int> stk, min_stk; //辅助栈

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