/*
请实现一个函数可以复制一个复杂链表。

在复杂链表中，每个结点除了有一个指针指向下一个结点外，还有一个额外的指针指向链表中的任意结点或者null。

注意：

函数结束后原链表要与输入时保持一致。
-------------------------------

*/
struct ListNode
{
    int val;
    ListNode *next, *random;
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
    }
};
