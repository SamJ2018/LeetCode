/*
�������������ҳ����ǵĵ�һ��������㡣

�������ڹ����ڵ�ʱ�����ؿսڵ㡣

����
������������������ʾ��
A��        a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3

�����һ�������ڵ�c1
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
  ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB)
  {
    auto p = headA, q = headB;
    while (p != q)
    {
      if (p)
        p = p->next;
      else
        p = headB;
      if (q)
        q = q->next;
      else
        q = headA;
    }
    return p;
  }
};