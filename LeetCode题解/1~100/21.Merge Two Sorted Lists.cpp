#include "util.h"

/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

已知两个已排序链表头节点指针l1与l2，将这两个链表合并，合并后仍为有序的，返回合并后的头节点
*/

/*C code*/
struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b) {
	if (!a || b && a->val > b->val) a += b - (b = a);
	if (a) a->next = mergeTwoLists(a->next, b);
	return a;
}

/*思路
	比较l1和l2指向的节点，将较小的节点插入到pre指针后，并向前移动较小节点对应的指针
*/
class Solution 
{
public:
	ListNode* MergeTwoLists(ListNode* l1, ListNode* l2)
	{
		//设置临时头节点temp_head
		ListNode temp_head(0);
		//使用pre指针指向temp_head
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
