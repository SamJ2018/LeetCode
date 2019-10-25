/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
	Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.

一个数组存储了非负整型数据，数组中的第i个元素a[i]，代表了可以从数组第i个位置最多向前跳跃a[i]步；
已知数组各元素的情况下， 确认可以从第0位置跳跃到数组最后一个位置，求最少需要跳跃几次?
例如:
nums = [2, 3, 1, 1, 4] ，从第0位置跳到第1位置，从第1位置跳至最后一个位置。


在到达某点前若一直不跳跃，发现从该点不能跳到更远的地方了，在这之前肯定有次必要的跳跃！
结论:在无法到达更远的地方时，在这之前应该跳到一个可以到达更远位置的位置！

思路
1.设置current_max_index为当前可达到的最远位置;
2.设置pre_max_max_index为在遍历各个位置的过程中，各个位置可达到的最远位置;
3.设置jump_min为最少跳跃的次数。
4.利用i遍历nums数组，若i超过current_max_index， jump_min加1， current_max_index =pre_max_max_index
5.遍历过程中，若nums[i]+i (index[i])更大，则更新pre_max_max_index = nums[i] + i。
*/
#include "util.h"

class Solution
{
public:
	int jump(vector<int>& nums)
	{
		//如果数组长度小于2，则说明不用跳跃，返回0
		if (nums.size() < 2)
			return 0;

		int current_max_index = nums[0];//当前可到达的最远位置
		int pre_max_max_index = nums[0];//遍历各个位置过程中，可到达的最远位置
		int jump_min = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (i > current_max_index)//如果无法再向前移动了，才进行跳跃
			{
				jump_min++;
				//更新当前可到达的最远位置
				current_max_index = pre_max_max_index;
			}
			if (pre_max_max_index < nums[i] + i)
			{
				//更新pre_max_max_index
				pre_max_max_index = nums[i] + i;
			}
		}
		return jump_min;
	}
};