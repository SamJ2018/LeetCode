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
˼·������һ��O(logn) 
		    ����������˼·�������ż���򲻶ϳ�2�����Ľ����1��Ϊtrue,Ϊ0����false
			�ݹ飺˼·ͬ�ϣ������ż���򲻶ϳ�2��
			λ���㣺���ǵ�2��n�����޷Ǿ��ǣ���λΪ1����λȫΪ0�������Ҫ��n-1���������㣬����õ�����0��ɹ���
*/
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0) return false;
		while (n % 2 == 0) n /= 2;//������
		return n == 1;
		//�ݹ鷨:
		//	return n > 0 && (n == 1 || (n % 2 == 0 && isPowerOfTwo(n / 2)));
		//������:
		//	return n>0 && ((n&(n-1))==0);
	}
};