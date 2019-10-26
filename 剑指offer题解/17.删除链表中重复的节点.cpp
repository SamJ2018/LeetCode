/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留。

样例1
输入：1->2->3->3->4->4->5

输出：1->2->5
样例2
输入：1->1->1->2->3

输出：2->3

---------------
算法
(线性扫描) O(n)
为了方便处理边界情况，我们定义一个虚拟元素 dummy 指向链表头节点。
然后从前往后扫描整个链表，每次扫描元素相同的一段，如果这段中的元素个数多于1个，则将整段元素直接删除。

时间复杂度
整个链表只扫描一遍，所以时间复杂度是 O(n)。
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
    ListNode *deleteDuplication(ListNode *head)
    {
        auto dummy = new ListNode(-1); //用于保证头结点不会被删掉
        dummy->next = head;

        auto p = dummy;
        while (p->next)
        {
            auto q = p->next;
            while (q && p->next->val == q->val)
                q = q->next;
            if (p->next->next == q)
                p = p->next;
            else
                p->next = q;
        }
        return dummy->next;
    }
};