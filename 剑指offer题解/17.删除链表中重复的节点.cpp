/*
��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻������

����1
���룺1->2->3->3->4->4->5

�����1->2->5
����2
���룺1->1->1->2->3

�����2->3

---------------
�㷨
(����ɨ��) O(n)
Ϊ�˷��㴦��߽���������Ƕ���һ������Ԫ�� dummy ָ������ͷ�ڵ㡣
Ȼ���ǰ����ɨ����������ÿ��ɨ��Ԫ����ͬ��һ�Σ��������е�Ԫ�ظ�������1����������Ԫ��ֱ��ɾ����

ʱ�临�Ӷ�
��������ֻɨ��һ�飬����ʱ�临�Ӷ��� O(n)��
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
        auto dummy = new ListNode(-1); //���ڱ�֤ͷ��㲻�ᱻɾ��
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