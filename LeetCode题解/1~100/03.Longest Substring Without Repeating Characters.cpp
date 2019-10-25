/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
			 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include "util.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		map<char, int> charMap;
		int start = -1;
		int maxLen = 0;

		for (int i = 0; i < s.size(); i++) {
			if (charMap.count(s[i]) != 0) {
				start = max(start, charMap[s[i]]);
			}
			charMap[s[i]] = i;
			maxLen = max(maxLen, i - start);
		}

		return maxLen;
	}
};