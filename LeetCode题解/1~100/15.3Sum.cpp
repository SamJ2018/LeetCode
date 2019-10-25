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

����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� *a��b��c ��*ʹ�� a + b + c = 0 ���ҳ��������������Ҳ��ظ�����Ԫ�顣

��Ŀ��Ҫ�����ҳ��������Һ�Ϊ 0 ����ô����������ȫ�� 0 �����֮�⣬�϶����и���������������һ��ʼ������ѡ��һ������Ȼ����ȥ������������������ֻҪ�ҵ��������Һ�Ϊ��һ��ѡ��������෴�������ˡ�
Ҳ����˵��Ҫö�� a �� b ���� c �Ĵ��� map ���ɡ�
��Ҫע����Ƿ��صĽ���У����������ظ��Ľ����
�����Ĵ���ʱ�临�Ӷ��� O(n^2)������������Ƚ�ԭ�����������Ȼ���ٱ������������飬�����Ϳ���ʹ��˫ָ��������ʱ�临�Ӷ����������������������������ϡ�
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