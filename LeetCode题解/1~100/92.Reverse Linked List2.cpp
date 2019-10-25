/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 �� m �� n �� length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

#include "util.h"



class Solution 
{
public:
	//���������⣬����ĩβ�Ľ�㣿���� fix��
	#if 0
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		int change_len = n - m + 1;  //��Ҫ���õĽ�������
		ListNode* pre_head = NULL;   //��ʼ����ʼ���õĽ��ǰ��
		ListNode* result = head;     //����ת���������ͷ��㣬���������Ϊhead

		while (head && --m)   //��head��ǰ�ƶ�m-1��λ��
		{
			pre_head = head;  //ǰ��ָ��head
			head = head->next;
		}
		ListNode* modify_list_tail = head;  //��modify_list_tailָ��ǰ��head,�����ú������β
		ListNode* new_head = NULL;

		while (head && change_len)
		{
			//��Ҫ����change_len���ڵ�
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
			
			change_len--;  //ÿ���һ���ڵ����ã�change_len--
		}
		modify_list_tail = head;  //�������ú������β�����öεĺ�һ���ڵ�
		if (pre_head) {  //���pre_head���գ�˵�����Ǵӵ�һ���ڵ㿪ʼ���õ�m>1
			pre_head->next = new_head;  //����������Ŀ�ʼ�Ľڵ�ǰ���������ú��ͷ�ڵ�����
		}
		else {
			result = new_head;  //���pre_headΪ�գ�˵��m==1�Ǵӵ�һ���ڵ㿪ʼ���ã������Ϊ���ú��ͷ�ڵ�
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