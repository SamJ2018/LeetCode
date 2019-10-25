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

/*��֪һ�����ӵ������ڵ�����һ��ָ����������ĳ���ڵ�����ָ�루Ҳ����Ϊ�գ�
������������ȿ���(��ȿ�������������һ����ȫ�µ�������ʹԭ����ٻ�����������Ȼ�ɶ���ʹ��)*/

class Solution 
{
public:
	RandomListNode* copyRandomList(RandomListNode* head)
	{
		map<RandomListNode*, int> node_map; //��ַ�����λ�õ�map
		vector<RandomListNode*> node_vec;   //ʹ��vector���ݴ洢���λ�÷��ʵ�ַ
		RandomListNode* ptr = head;
		int i = 0;

		while (ptr)
		{
			//��������ڵ�push��node_vec,������������ڵ�λ�õ���ַ��map
			node_vec.push_back(new RandomListNode(ptr->label));
			//��¼ԭʼ�����ַ���ڵ�λ�õ�node_map
			node_map[ptr] = i;//

			ptr = ptr->next;  //��������ԭ����
			i++;              //��¼�ڵ��λ��
		}
		node_vec.push_back(0);
		ptr = head;
		i = 0;  //�ٴα���ԭ���������������nextָ�롢randomָ��

		while (ptr)
		{
			//����������nextָ��
			node_vec[i]->next = node_vec[i + 1];
			//��randomָ�벻Ϊ��ʱ
			if (ptr->random)
			{
				int id = node_map[ptr->random]; //����node_mapȷ��id��ԭ����randomָ��ָ���λ�þ���id 

				//����������randomָ��
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