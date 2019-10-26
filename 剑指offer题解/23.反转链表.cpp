/*

定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。

样例
输入:1->2->3->4->5->NULL

输出:5->4->3->2->1->NULL

-------------------------------------
算法1
(链表操作，迭代) O(n)
翻转即将所有节点的next指针指向前驱节点。
由于是单链表，我们在迭代时不能直接找到前驱节点，所以我们需要一个额外的指针保存前驱节点。同时在改变当前节点的next指针前，不要忘记保存它的后继节点。

空间复杂度分析：遍历时只有3个额外变量，所以额外的空间复杂度是 O(1)。
时间复杂度分析：只遍历一次链表，时间复杂度是 O(n)。
*/
#include <cstdlib>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr;
        auto cur = head;
        while (cur)
        {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};