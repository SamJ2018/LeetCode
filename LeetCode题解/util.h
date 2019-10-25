#pragma once
// for c++
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

//definition for binary tree node
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

//definition for Singly-linked lsit
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};//


//�������ָ�������ڵ�
struct RandomListNode
{
	int label;
	RandomListNode* next, * random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};


//�ϲ���������
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
	if (l1) pre->next = l1;
	if (l2)	pre->next = l2;
	return temp_head.next;
}
