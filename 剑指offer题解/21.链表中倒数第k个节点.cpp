/*
输入一个链表，输出该链表中倒数第k个结点。

注意：
    k >= 0;
    如果k大于链表长度，则返回 NULL;

样例
输入：链表：1->2->3->4->5 ，k=2
输出：4

-------------------------------
算法
(链表) O(n)
由于单链表不能索引到前驱节点，所以只能从前往后遍历。

我们一共遍历两次：

第一次遍历得到链表总长度 n；
链表的倒数第 k 个节点，相当于正数第 n?k+1n?k+1 个节点。所以第二次遍历到第 n?k+1 个节点，就是我们要找的答案。
注意当 k>n 时要返回nullptr。

时间复杂度
链表总共遍历两次，所以时间复杂度是 O(n)。
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
};

class Solution
{
public:
    ListNode *findKthToTail(ListNode *head, int k)
    {
        int n = 0;
        auto p = head;
        while (p)
            ++n, p = p->next;
        if (k > n)
            return nullptr;
        p = head;
        for (int i = 0; i < n - k; i++)
            p = p->next;
        return p;
    }
};