/*
�������������һ���ڵ�ָ�룬����һ��������O(1)ʱ��ɾ���ý�㡣

��������һ�����ڣ����Ҹýڵ�һ������β�ڵ㡣

����
���룺���� 1->4->6->8
      ɾ���ڵ㣺��2���ڵ㼴6��ͷ�ڵ�Ϊ��0���ڵ㣩

����������� 1->4->8

-------------------
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
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};