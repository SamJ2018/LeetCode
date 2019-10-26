/*
����һ����������������е�����k����㡣

ע�⣺
    k >= 0;
    ���k���������ȣ��򷵻� NULL;

����
���룺����1->2->3->4->5 ��k=2
�����4

-------------------------------
�㷨
(����) O(n)
���ڵ�������������ǰ���ڵ㣬����ֻ�ܴ�ǰ���������

����һ���������Σ�

��һ�α����õ������ܳ��� n��
����ĵ����� k ���ڵ㣬�൱�������� n?k+1n?k+1 ���ڵ㡣���Եڶ��α������� n?k+1 ���ڵ㣬��������Ҫ�ҵĴ𰸡�
ע�⵱ k>n ʱҪ����nullptr��

ʱ�临�Ӷ�
�����ܹ��������Σ�����ʱ�临�Ӷ��� O(n)��
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