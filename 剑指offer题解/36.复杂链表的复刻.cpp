/*
��ʵ��һ���������Ը���һ����������

�ڸ��������У�ÿ����������һ��ָ��ָ����һ������⣬����һ�������ָ��ָ�������е����������null��

ע�⣺

����������ԭ����Ҫ������ʱ����һ�¡�
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
            p->next = p->next->next;//ע�⣬��֤���޸�ԭ����
        }
        return dummy->next;
    }
};
