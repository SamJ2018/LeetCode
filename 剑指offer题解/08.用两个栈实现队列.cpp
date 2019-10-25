/*
����ջʵ��һ�����У�֧���������ֲ�����

push(x) �C ��Ԫ��x�嵽��β��
pop() �C �����׵�Ԫ�ص����������ظ�Ԫ�أ�
peek() �C ���ض���Ԫ�أ�
empty() �C ���ض����Ƿ�Ϊ�գ�
ע�⣺

��ֻ��ʹ��ջ�ı�׼������push to top��peek/pop from top, size �� is empty��
�����ѡ��ı������û��ջ�ı�׼�⣬�����ʹ��list����deque��ģ��ջ�Ĳ�����
�������ݱ�֤�Ϸ������磬�ڶ���Ϊ��ʱ���������pop����peek�Ȳ�����
����
MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false

-------------------------------------------------------------
�㷨
(ջ������) O(n)
����һ�������⣬ֻҪ�ѹ���ʵ�ֶԾͿ��ԣ�����Ҫ��������Ч�ʡ�

����������ջ������һ����ջ�������洢���ݣ�һ������ջ�����������档

push(x)������ֱ�ӽ�x������ջ�м��ɡ�
pop()����ʱ������Ҫ�������Ƚ���ջ��Ԫ�أ�Ҳ����ջ��Ԫ�ء����ǿ����Ƚ�����Ԫ�ش���ջ�е�����ѹ�븨��ջ�С�����ջ��ջ��Ԫ�ؾ�������Ҫ������Ԫ�أ����䵯�����ɡ�Ȼ���ٽ�����ջ�е�Ԫ��ȫ��������ѹ����ջ�С�
peek()�������ú�pop()�������Ƶķ�ʽ���õ�����ѹ��ջ��Ԫ�ء�
empty()��ֱ���ж���ջ�Ƿ�Ϊ�ռ��ɡ�
ʱ�临�Ӷȷ���
push()��O(1)��
pop(): ÿ����Ҫ����ջԪ��ȫ����������ѹ�룬������Ҫ O(n) ��ʱ�䣻
peek()��������pop()����Ҫ O(n) ��ʱ�䣻
empty()��O(1)��

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
