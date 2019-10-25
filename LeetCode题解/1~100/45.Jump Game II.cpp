/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
	Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.

һ������洢�˷Ǹ��������ݣ������еĵ�i��Ԫ��a[i]�������˿��Դ������i��λ�������ǰ��Ծa[i]����
��֪�����Ԫ�ص�����£� ȷ�Ͽ��Դӵ�0λ����Ծ���������һ��λ�ã���������Ҫ��Ծ����?
����:
nums = [2, 3, 1, 1, 4] ���ӵ�0λ��������1λ�ã��ӵ�1λ���������һ��λ�á�


�ڵ���ĳ��ǰ��һֱ����Ծ�����ִӸõ㲻��������Զ�ĵط��ˣ�����֮ǰ�϶��дα�Ҫ����Ծ��
����:���޷������Զ�ĵط�ʱ������֮ǰӦ������һ�����Ե����Զλ�õ�λ�ã�

˼·
1.����current_max_indexΪ��ǰ�ɴﵽ����Զλ��;
2.����pre_max_max_indexΪ�ڱ�������λ�õĹ����У�����λ�ÿɴﵽ����Զλ��;
3.����jump_minΪ������Ծ�Ĵ�����
4.����i����nums���飬��i����current_max_index�� jump_min��1�� current_max_index =pre_max_max_index
5.���������У���nums[i]+i (index[i])���������pre_max_max_index = nums[i] + i��
*/
#include "util.h"

class Solution
{
public:
	int jump(vector<int>& nums)
	{
		//������鳤��С��2����˵��������Ծ������0
		if (nums.size() < 2)
			return 0;

		int current_max_index = nums[0];//��ǰ�ɵ������Զλ��
		int pre_max_max_index = nums[0];//��������λ�ù����У��ɵ������Զλ��
		int jump_min = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (i > current_max_index)//����޷�����ǰ�ƶ��ˣ��Ž�����Ծ
			{
				jump_min++;
				//���µ�ǰ�ɵ������Զλ��
				current_max_index = pre_max_max_index;
			}
			if (pre_max_max_index < nums[i] + i)
			{
				//����pre_max_max_index
				pre_max_max_index = nums[i] + i;
			}
		}
		return jump_min;
	}
};