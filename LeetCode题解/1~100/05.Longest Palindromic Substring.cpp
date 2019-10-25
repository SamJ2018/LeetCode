/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/
#include "util.h"

string longestPalindrome(string s) {
	int len = s.size();
	if (len <= 1) return s;
	int lpos = 0, lm = 0; // position of first letter and length
	for (int i = 0; i < len - 1; i++) {
		if (lm >= (len - i) * 2) return s.substr(lpos, lm);
		int count = 0;
		while (s[i + 1] == s[i] && i++ < len - 1)
			count++;
		int end = i;
		int first = i - count;
		while (s[--first] == s[++end] && first >= 0 && end < len);
		end--;
		first++;
		if (lm < end - first + 1) {
			lpos = first;
			lm = end - first + 1;
		}
	}
	return s.substr(lpos, lm);
}