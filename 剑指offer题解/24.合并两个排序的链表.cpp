/*
����������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ��յ�������ġ�

����
���룺1->3->5 , 2->4->5

�����1->2->3->4->5->5
=--------------------
�㷨
(��·�鲢) O(n)
�½�ͷ���ı������dummy������curָ��ָ��dummy��
����ǰl1ָ��ָ��Ľ���ֵval��l2ָ��ָ��Ľ���ֵvalС������cur��nextָ��ָ��l1����l1���ƣ�����ָ��l2����l2���ơ�
Ȼ��curָ�밴����һ�����úõ�λ�ú��ơ�
ѭ�����ϲ���ֱ��l1��l2Ϊ�ա�
��ʣ���l1��l2�ӵ�curָ���ߡ�
ʱ�临�Ӷ�
�������������һ�Σ�����ʱ�临�Ӷ�ΪO(n)
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;
        return dummy->next;
    }
};
