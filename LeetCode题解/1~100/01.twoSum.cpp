/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include "util.h"
//出于方便头文件统一放入utility,测试案例/对数器放入my_test.cpp、check_.h

//1、c++解法 使用hash table   T(n)=0(n)

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, size_t> temp;
	for (size_t i = 0; i < nums.size(); ++i)
	{
		if (temp.count(target - nums[i]))
			return { (int)temp[target - nums[i]],(int)i };
		temp[nums[i]] = i;
	}
	return { (int)nums.size(),(int)nums.size() };
}



