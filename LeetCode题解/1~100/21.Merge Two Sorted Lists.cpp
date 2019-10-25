#include "util.h"

/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

��֪��������������ͷ�ڵ�ָ��l1��l2��������������ϲ����ϲ�����Ϊ����ģ����غϲ����ͷ�ڵ�
*/

/*C code*/
struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b) {
	if (!a || b && a->val > b->val) a += b - (b = a);
	if (a) a->next = mergeTwoLists(a->next, b);
	return a;
}

/*˼·
	�Ƚ�l1��l2ָ��Ľڵ㣬����С�Ľڵ���뵽preָ��󣬲���ǰ�ƶ���С�ڵ��Ӧ��ָ��
*/
class Solution 
{
public:
	ListNode* MergeTwoLists(ListNode* l1, ListNode* l2)
	{
		//������ʱͷ�ڵ�temp_head
		ListNode temp_head(0);
		//ʹ��preָ��ָ��temp_head
		ListNode* pre = &temp_head;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				pre->next = l1;
				l1 = l1->next;
			}
			else
			{
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		if (l1)
		{
			pre->next = l1;
		}
		if (l2)
		{
			pre->next = l2;
		}
		return temp_head.next;
	}
};
