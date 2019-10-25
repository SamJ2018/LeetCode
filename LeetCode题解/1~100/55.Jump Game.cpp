/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
			 jump length is 0, which makes it impossible to reach the last index.


һ������洢�˷Ǹ��������ݣ������еĵ�i��Ԫ��a[i]�������˿��Դ������i��
λ�������ǰ��Ծa[i]������֪�����Ԫ�ص�����£����Ƿ���Դ�����ĵ�0
��λ����Ծ����������һ��Ԫ�ص�λ��?
����:
nums = [2, 3, 1, 1, 4] �����Դ�nums[0] = 2 ��Ծ�� nums[4] = 4��
nums = [3, 2, 1, 0, 4] �������Դ�nums[0] = 3 ��Ծ�� nums[4] = 4��


˼·
�ӵ�i��λ�ã� ��Զ����nums[i]��:
nums = [2, 3, 1, 1, 4, ...];
�ӵ�i��λ�ã� ��Զ��������index[i]��λ��:
index[i] = i + nums[i];
index = [2, 4, 3, 4, 8, ...]
���ӵ�0λ����Զ����������i��λ�ã�
��ӵ�0λ��Ҳһ����������:
��1��λ�á���2��λ�á� ...����i-1��λ�á�
�ӵ�0��λ�ã�Ӧ��������1����2�� ...����i-1����i��λ���е��ĸ�?
Ӧ��������1�� 2�� ...�� i-1�� iλ���У� �ֿ���ǰ��������Զλ��
(��index[1]�� index[2]�� ...�� index[i-1]�� ...�� index[i]�����Ǹ�) ��λ�ã� (̰��)
*/

#include "util.h"	

class Solution
{
	bool canJump(vector<int>& nums)
	{
		vector<int> index;  //��¼��Զ������λ��
		for (int i = 0; i < nums.size(); i++)
		{
			//����index����
			index.push_back(i + nums[i]);
		}
		int jump = 0;
		//��ʼ��jump��max_index  
		int max_index = index[0];

		//ֱ��jump���������β����jump��Խ�˵�ǰ��������Զλ��
		while (jump < index.size() && jump <= max_index)
		{
			if (max_index < index[jump])
			{
				//�����ǰ��������λ�ø�Զ�������max_index
				max_index = index[jump];
			}
			jump++; //ɨ��jump
		}
		if (jump == index.size())
		{
			//��jump���������β��������
			return true;
		}
		return false; //���򷵻ؼ�
	}
};