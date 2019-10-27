/*
请实现一个函数可以复制一个复杂链表。

在复杂链表中，每个结点除了有一个指针指向下一个结点外，还有一个额外的指针指向链表中的任意结点或者null。

注意：

函数结束后原链表要与输入时保持一致。
-------------------------------

*/
struct ListNode
{
    int val;
    ListNode *next, *random;
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution
{
public:
    ListNode *copyRandomList(ListNode *head)
    {
        for(auto p=head ; p ;){
            auto cp=new ListNode(p->val);
            auto next=p->next;
            p->next=cp;
            cp->next=next;
            p=next;
        }
        for(auto p=head; p; p=p->next->next){
            if(p->random) p->next->random=p->random->next;
        }
        auto dummy = new ListNode(-1);
        auto cur=dummy;
        for(auto p= head; p; p=p->next){
            cur->next=p->next;
            cur=cur->next;
            p->next = p->next->next;//注意，保证不修改原链表
        }
        return dummy->next;
    }
};
