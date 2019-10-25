#include "util.h"

/*
A linked list is given such that each node contains an additional random pointer 
which could point to any node in the list or null.
Return a deep copy of the list.

Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.


Note:
You must return the copy of the given head as a reference to the cloned list.
*/

/*已知一个复杂的链表，节点中有一个指向本链表任意某个节点的随机指针（也可以为空）
求这个链表的深度拷贝(深度拷贝：构造生成一个完全新的链表，即使原链表毁坏，新链表依然可独立使用)*/

class Solution 
{
public:
	RandomListNode* copyRandomList(RandomListNode* head)
	{
		map<RandomListNode*, int> node_map; //地址到结点位置的map
		vector<RandomListNode*> node_vec;   //使用vector根据存储结点位置访问地址
		RandomListNode* ptr = head;
		int i = 0;

		while (ptr)
		{
			//将新链表节点push进node_vec,生成了新链表节点位置到地址的map
			node_vec.push_back(new RandomListNode(ptr->label));
			//记录原始链表地址到节点位置的node_map
			node_map[ptr] = i;//

			ptr = ptr->next;  //继续遍历原链表
			i++;              //记录节点的位置
		}
		node_vec.push_back(0);
		ptr = head;
		i = 0;  //再次遍历原链表，链接新链表的next指针、random指针

		while (ptr)
		{
			//链接新链表next指针
			node_vec[i]->next = node_vec[i + 1];
			//当random指针不为空时
			if (ptr->random)
			{
				int id = node_map[ptr->random]; //根据node_map确认id，原链表random指针指向的位置就是id 

				//链接新链表random指针
				node_vec[i]->random = node_vec[id];
			}
			ptr = ptr->next;
			i++;
		}
		return node_vec[0];
	}
};

int main_138()
{
	RandomListNode a(1), b(2), c(3), d(4), e(5);
	a.next = &b;  b.next = &c;  c.next = &d;  d.next = &e;
	a.random = &c;  b.random = &d;  c.random = &c;  e.random = &d;
	Solution solve;

	RandomListNode* head = solve.copyRandomList(&a);

	while (head)
	{
		printf("label=%d", head->label);
		if (head->random)
		{
			printf("rand=%d\n", head->random->label);
		}
		else
		{
			printf("rand=NULL\n");
		}
		head = head->next;
	}

	return EXIT_SUCCESS;
}