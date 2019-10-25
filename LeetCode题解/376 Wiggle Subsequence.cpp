/*
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. 
The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. 
In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?

һ���������У������������Ԫ�صĲ�ǡ������(����)������֣�������б���Ϊҡ�����С�һ��С��2��Ԫ�ص�����ֱ��Ϊҡ�����С�
����:
���� [1, 7, 4, 9, 2, 5]������Ԫ�صĲ� (6, -3, 5, -7, 3)��������Ϊҡ�����С�
���� [1,4,7,2,5] (3, 3, -5, 3)�� [1,7,4,5,5] (6, -3, 1, 0)����ҡ�����С�
��һ��������У��������������ҡ�����ж����������еĳ��ȡ�
����:
����[1,7,4,9,2,5]�����Ϊ6������[1,17,5,10,13,15,10,5,16,8]�����Ϊ7([1,17,10,13,10,16,8])������[1,2,3,4,5,6,7,8,9]�����Ϊ2��


˼����
[1, 17, 5, 10, 13, 15, 10, 5, 16, 8]�� ���岻��ҡ������:
�۲������ǰ6λ:[1, 17, 5, 10, 13, 15...];  10��13��15������:
��������3����������ҡ������:
[1, 17, 5, 10, ...]
[1, 17, 5, 13, ...]
[1, 17, 5, 15, ...]
�ڲ����ԭʼ���е�7λ��ʲô������£� ֻ��ǰ6λ��ҡ�������еĵ���λ��10, 13, 15��ѡ��1������
����Ӧ��ѡ���ĸ������?  ѡ������Ǹ�->̰��
*/

#include "util.h"

class Solution
{
public:
	int WiggleMaxLength(vector<int>& nums)
	{
		if (nums.size() < 2)
			return nums.size(); //���и���С��2ʱΪҡ������
		
		//ɨ������ʱ������״̬
		static const int BEGIN = 0;
		static const int UP = 1;
		static const int DOWN = 2;
		int STATE = BEGIN;
		int max_length = 1; //ҡ��������󳤶�����Ϊ1

		for (int i = 1; i < nums.size(); i++)
		{
			switch (STATE)
			{
			case BEGIN:
				if (nums[i - 1] < nums[i]) //״̬���ı�
				{
					STATE = UP;
					max_length++;
				}
				else if (nums[i - 1] > nums[i])
				{
					STATE = DOWN;
					max_length++;
				}
				break;
			case UP: 
				if (nums[i - 1] > nums[i]) //״̬���ı�
				{
					STATE = DOWN;
					max_length++;
				}
				break;
			case DOWN:
				if (nums[i - 1] < nums[i]) //״̬���ı�
				{
					STATE = UP;
					max_length++;
				}
				break;
			}
		}
		return max_length; //�������ҡ�����г���
	}
};