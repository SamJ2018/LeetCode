/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 *a，b，c ，*使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

题目需要我们找出三个数且和为 0 ，那么除了三个数全是 0 的情况之外，肯定会有负数和正数，所以一开始可以先选择一个数，然后再去找另外两个数，这样只要找到两个数且和为第一个选择的数的相反数就行了。
也就是说需要枚举 a 和 b ，将 c 的存入 map 即可。
需要注意的是返回的结果中，不能有有重复的结果。
这样的代码时间复杂度是 O(n^2)。在这里可以先将原数组进行排序，然后再遍历排序后的数组，这样就可以使用双指针以线性时间复杂度来遍历所有满足题意的两个数组合。
*/

#include "util.h"

vector<vector<int> > threeSum(vector<int>& num) {

	vector<vector<int> > res;

	std::sort(num.begin(), num.end());

	for (int i = 0; i < num.size(); i++) {

		int target = -num[i];
		int front = i + 1;
		int back = num.size() - 1;

		if (target < 0)
		{
			break;
		}

		while (front < back) {

			int sum = num[front] + num[back];

			// Finding answer which start from number num[i]
			if (sum < target)
				front++;

			else if (sum > target)
				back--;

			else {
				vector<int> triplet(3, 0);
				triplet[0] = num[i];
				triplet[1] = num[front];
				triplet[2] = num[back];
				res.push_back(triplet);

				// Processing duplicates of Number 2
				// Rolling the front pointer to the next different number forwards
				while (front < back && num[front] == triplet[1]) front++;

				// Processing duplicates of Number 3
				// Rolling the back pointer to the next different number backwards
				while (front < back && num[back] == triplet[2]) back--;
			}

		}

		// Processing duplicates of Number 1
		while (i + 1 < num.size() && num[i + 1] == num[i])
			i++;

	}

	return res;

}