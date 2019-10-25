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
int not_repeated(char* s, int left, int right) {
	if (left == right) return -1;
	while (left < right) {
		if (s[left] == s[right]) {
			return left;
		}
		left += 1;
	}
	return -1;
}


int lengthOfLongestSubstring(char* s) {
	int max = 0;
	int tmp = 0;
	int check_output = 0;
	int current = 0;
	int left = 0, right = 0;
	while (s[right] != 0 && left <= right) {
		check_output = not_repeated(s, left, right);
		if (check_output == -1) {
			right += 1;
		}
		else {
			tmp = right - left;
			if (tmp > max) {
				max = tmp;
			}
			left = check_output + 1;
			right += 1;
		}
	}
	tmp = right - left;
	if (tmp > max) max = tmp;
	return max;
}