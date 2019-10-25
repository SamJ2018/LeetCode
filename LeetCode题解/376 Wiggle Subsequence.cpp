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

一个整数序列，如果两个相邻元素的差恰好正负(负正)交替出现，则该序列被称为摇摆序列。一个小于2个元素的序列直接为摇摆序列。
例如:
序列 [1, 7, 4, 9, 2, 5]，相邻元素的差 (6, -3, 5, -7, 3)，该序列为摇摆序列。
序列 [1,4,7,2,5] (3, 3, -5, 3)、 [1,7,4,5,5] (6, -3, 1, 0)不是摇摆序列。
给一个随机序列，求这个序列满足摇摆序列定义的最长子序列的长度。
例如:
输入[1,7,4,9,2,5]，结果为6；输入[1,17,5,10,13,15,10,5,16,8]，结果为7([1,17,10,13,10,16,8])；输入[1,2,3,4,5,6,7,8,9]，结果为2。


思考：
[1, 17, 5, 10, 13, 15, 10, 5, 16, 8]， 整体不是摇摆序列:
观察该序列前6位:[1, 17, 5, 10, 13, 15...];  10，13，15上升段:
其中它有3个子序列是摇摆序列:
[1, 17, 5, 10, ...]
[1, 17, 5, 13, ...]
[1, 17, 5, 15, ...]
在不清楚原始序列的7位是什么的情况下， 只看前6位，摇摆子序列的第四位从10, 13, 15中选择1个数。
我们应该选择哪个最好呢?  选择最大那个->贪心
*/

#include "util.h"

class Solution
{
public:
	int WiggleMaxLength(vector<int>& nums)
	{
		if (nums.size() < 2)
			return nums.size(); //序列个数小于2时为摇摆序列
		
		//扫描序列时的三种状态
		static const int BEGIN = 0;
		static const int UP = 1;
		static const int DOWN = 2;
		int STATE = BEGIN;
		int max_length = 1; //摇摆序列最大长度至少为1

		for (int i = 1; i < nums.size(); i++)
		{
			switch (STATE)
			{
			case BEGIN:
				if (nums[i - 1] < nums[i]) //状态基改变
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
				if (nums[i - 1] > nums[i]) //状态基改变
				{
					STATE = DOWN;
					max_length++;
				}
				break;
			case DOWN:
				if (nums[i - 1] < nums[i]) //状态基改变
				{
					STATE = UP;
					max_length++;
				}
				break;
			}
		}
		return max_length; //返回最大摇摆序列长度
	}
};