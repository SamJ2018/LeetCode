/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
#include "util.h"

/*
��֪����ָ��head����ֵX��������С��x�Ľڵ���ڴ��ڻ����x�Ľڵ�ǰ��
�ұ�����Щ�ڵ��ԭ�������λ��
˼·��
	����������ʱͷ���less_head��more_head�������ڵ���3�Ľڵ��������ӵ�more_head����
	Ȼ��С��3��x�Ľڵ���������ӵ�less_head���棬less_ptr�ǹ���ָ�룬���less_ptr��nextָ�����ӵ�more_head��nextָ����
*/

class Solution 
{
public:
	ListNode* partition(ListNode* head, int x)
	{
		//����������ʱ��ͷ�ڵ�
		ListNode less_head(0),more_head(0);

		//��������ָ��
		ListNode* less_ptr = &less_head;
		ListNode* more_ptr = &more_head;

		while (head)
		{
			//����ڵ�ֵС��x���򽫸ýڵ���뵽less_ptr��
			if (head->val < x)
			{
				less_ptr->next = head;
				less_ptr = head; //�������less_ptr����ƶ���ָ��head
			}
			else
			{
				//������뵽more_ptr��
				more_ptr->next = head;
				more_ptr = head;
			}
			//������������
			head = head->next;
		}
		less_ptr->next = more_head.next;//��less����β����more����ͷ����
		more_ptr->next = NULL; //��more_ptr(��Ϊ����β�ڵ�)next�ÿ�
		return less_head.next; //less_head��next�ڵ㼴Ϊ������ͷ��㣬���ؼ���
	}
};


//for test
int main_1()
{
	ListNode a(1), b(4), c(3), d(2), e(5), f(2);
	a.next = &b;  b.next = &c;  c.next = &d;   d.next = &e;  e.next = &f;

	Solution solve;
	ListNode* head = solve.partition(&a, 3);
	
	while (head)
	{
		cout << head->val;
		head = head->next;
	}

	return EXIT_SUCCESS;
}