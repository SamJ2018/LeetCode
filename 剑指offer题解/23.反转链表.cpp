/*

����һ������������һ�������ͷ��㣬��ת�����������ת�������ͷ��㡣

����
����:1->2->3->4->5->NULL

���:5->4->3->2->1->NULL

-------------------------------------
�㷨1
(�������������) O(n)
��ת�������нڵ��nextָ��ָ��ǰ���ڵ㡣
�����ǵ����������ڵ���ʱ����ֱ���ҵ�ǰ���ڵ㣬����������Ҫһ�������ָ�뱣��ǰ���ڵ㡣ͬʱ�ڸı䵱ǰ�ڵ��nextָ��ǰ����Ҫ���Ǳ������ĺ�̽ڵ㡣

�ռ临�Ӷȷ���������ʱֻ��3��������������Զ���Ŀռ临�Ӷ��� O(1)��
ʱ�临�Ӷȷ�����ֻ����һ������ʱ�临�Ӷ��� O(n)��
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