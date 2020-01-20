/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

假设字符串中只包含从’a’到’z’的字符。

样例
输入："abcabc"

输出：3
*/

#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int longestSubstringWithoutDuplication(string s)
    {
        unordered_map<char, int> count;
        int res = 0;
        for (int i = 0, j = 0; j < s.size(); j++)
        {
            if (++count[s[j]] > 1)
            {
                while (count[s[i]] == 1)
                    count[s[i++]]--;
                count[s[i++]]--;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};