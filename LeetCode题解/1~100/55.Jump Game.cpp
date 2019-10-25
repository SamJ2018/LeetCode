/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
			 jump length is 0, which makes it impossible to reach the last index.


一个数组存储了非负整型数据，数组中的第i个元素a[i]，代表了可以从数组第i个
位置最多向前跳跃a[i]步；已知数组各元素的情况下，求是否可以从数组的第0
个位置跳跃到数组的最后一个元素的位置?
例如:
nums = [2, 3, 1, 1, 4] ，可以从nums[0] = 2 跳跃至 nums[4] = 4；
nums = [3, 2, 1, 0, 4] ，不可以从nums[0] = 3 跳跃至 nums[4] = 4。


思路
从第i个位置， 最远可跳nums[i]步:
nums = [2, 3, 1, 1, 4, ...];
从第i个位置， 最远可跳至第index[i]个位置:
index[i] = i + nums[i];
index = [2, 4, 3, 4, 8, ...]
若从第0位置最远可以跳至第i个位置；
则从第0位置也一定可以跳至:
第1个位置、第2个位置、 ...、第i-1个位置。
从第0个位置，应该跳至第1、第2、 ...、第i-1、第i个位置中的哪个?
应该跳至第1、 2、 ...、 i-1、 i位置中， 又可向前跳至更最远位置
(即index[1]、 index[2]、 ...、 index[i-1]、 ...、 index[i]最大的那个) 的位置！ (贪心)
*/

#include "util.h"	

class Solution
{
	bool canJump(vector<int>& nums)
	{
		vector<int> index;  //记录最远可至的位置
		for (int i = 0; i < nums.size(); i++)
		{
			//计算index数组
			index.push_back(i + nums[i]);
		}
		int jump = 0;
		//初始化jump和max_index  
		int max_index = index[0];

		//直到jump跳到数组结尾或者jump超越了当前可跳的最远位置
		while (jump < index.size() && jump <= max_index)
		{
			if (max_index < index[jump])
			{
				//如果当前可以跳的位置更远，则更新max_index
				max_index = index[jump];
			}
			jump++; //扫描jump
		}
		if (jump == index.size())
		{
			//若jump到达数组结尾，返回真
			return true;
		}
		return false; //否则返回假
	}
};