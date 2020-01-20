/*
输入两个链表，找出它们的第一个公共结点。

当不存在公共节点时，返回空节点。

样例
给出两个链表如下所示：
A：        a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

输出第一个公共节点c1
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