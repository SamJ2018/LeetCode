/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
#include "util.h"

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		std::vector<int> dp(nums.size(), 0);
		int max_res = dp[0] = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
			if (max_res < dp[i]) {
				max_res = dp[i];
			}
		}
		return max_res;
	}
};