/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (49.40%)
 * Likes:    9154
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 10
 * 所以返回 [0, 1]
 * 
 * 
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash{};
        for(int i = 0; i < nums.size(); i++){
            int idx = target - nums[i];
            if(hash.count(idx)) return {hash[idx], i};
            hash[nums[i]] = i;
        }
        return {}; 
    }
};
// @lc code=end
