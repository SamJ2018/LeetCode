/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

#include "util.h"



class Solution 
{
public:
	//测试有问题，少了末尾的结点？？？ fix！
	#if 0
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		int change_len = n - m + 1;  //需要逆置的结点个数？
		ListNode* pre_head = NULL;   //初始化开始逆置的结点前驱
		ListNode* result = head;     //最终转换后的链表头结点，非特殊情况为head

		while (head && --m)   //将head向前移动m-1个位置
		{
			pre_head = head;  //前驱指向head
			head = head->next;
		}
		ListNode* modify_list_tail = head;  //将modify_list_tail指向当前的head,即逆置后的链表尾
		ListNode* new_head = NULL;

		while (head && change_len)
		{
			//需要逆置change_len个节点
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
			
			change_len--;  //每完成一个节点逆置，change_len--
		}
		modify_list_tail = head;  //连接逆置后的链表尾与逆置段的后一个节点
		if (pre_head) {  //如果pre_head不空，说明不是从第一个节点开始逆置的m>1
			pre_head->next = new_head;  //将逆置链表的开始的节点前驱和与逆置后的头节点链接
		}
		else {
			result = new_head;  //如果pre_head为空，说明m==1是从第一个节点开始逆置，结果即为逆置后的头节点
		}
		return result;
	}
	#endif

	//
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (m == n) return head;
		n -= m;
		ListNode prehead(0);
		prehead.next = head;
		ListNode* pre = &prehead;
		while (--m) pre = pre->next;
		ListNode* pstart = pre->next;
		while (n--)
		{
			ListNode* p = pstart->next;
			pstart->next = p->next;
			p->next = pre->next;
			pre->next = p;
		}
		return prehead.next;
	}
};