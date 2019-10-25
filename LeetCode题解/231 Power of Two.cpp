/*
Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true
Explanation: 2^0 = 1
Example 2:

Input: 16
Output: true
Explanation: 2^4 = 16
Example 3:

Input: 218
Output: false
*/
#include "util.h"

/*
思路：方法一：O(logn) 
		    迭代：常规思路，如果是偶数则不断除2，最后的结果是1则为true,为0返回false
			递归：思路同上，如果是偶数则不断除2。
			位运算：考虑到2的n次幂无非就是，高位为1，低位全为0。因此这要与n-1进行与运算，如果得到的是0则成功。
*/
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0) return false;
		while (n % 2 == 0) n /= 2;//迭代法
		return n == 1;
		//递归法:
		//	return n > 0 && (n == 1 || (n % 2 == 0 && isPowerOfTwo(n / 2)));
		//与运算:
		//	return n>0 && ((n&(n-1))==0);
	}
};