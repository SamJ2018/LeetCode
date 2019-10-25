/*
请用栈实现一个队列，支持如下四种操作：

push(x) – 将元素x插到队尾；
pop() – 将队首的元素弹出，并返回该元素；
peek() – 返回队首元素；
empty() – 返回队列是否为空；
注意：

你只能使用栈的标准操作：push to top，peek/pop from top, size 和 is empty；
如果你选择的编程语言没有栈的标准库，你可以使用list或者deque等模拟栈的操作；
输入数据保证合法，例如，在队列为空时，不会进行pop或者peek等操作；
样例
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

-------------------------------------------------------------
算法
(栈，队列) O(n)
这是一道基础题，只要把功能实现对就可以，不需要考虑运行效率。

我们用两个栈来做，一个主栈，用来存储数据；一个辅助栈，用来当缓存。

push(x)，我们直接将x插入主栈中即可。
pop()，此时我们需要弹出最先进入栈的元素，也就是栈底元素。我们可以先将所有元素从主栈中弹出，压入辅助栈中。则辅助栈的栈顶元素就是我们要弹出的元素，将其弹出即可。然后再将辅助栈中的元素全部弹出，压入主栈中。
peek()，可以用和pop()操作类似的方式，得到最先压入栈的元素。
empty()，直接判断主栈是否为空即可。
时间复杂度分析
push()：O(1)；
pop(): 每次需要将主栈元素全部弹出，再压入，所以需要 O(n) 的时间；
peek()：类似于pop()，需要 O(n) 的时间；
empty()：O(1)；

--------------------------------------------------------
*/
#include <stack>
#include <iostream>
using namespace std;

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (empty())
            cerr << "error";
        int res;
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        res = stack2.top();
        stack2.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stack1.empty()&& stack2.empty();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
