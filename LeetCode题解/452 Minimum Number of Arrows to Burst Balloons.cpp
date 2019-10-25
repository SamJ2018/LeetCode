/*
There are a number of spherical balloons spread in two-dimensional space.
For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. 
Start is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the x-axis. 
A balloon with xstart and xend bursts by an arrow shot at x if xstart �� x �� xend. 
There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. 
The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).

��֪��һ��ƽ������һ������������ƽ����Կ���һ������ϵ����ƽ���x��Ĳ�ͬλ�ð��Ź�������y�᷽�����������������y��������Զ��
��������Ŀ�� xstart �� x �� xend����������Ҫ���ٹ����֣���ȫ�������?
����: �ĸ����� : [[10,16], [2,8], [1,6], [7,12]]��������Ҫ2�������֡�


̰�Ĺ���:
1.����ĳ������ ������Ҫʹ��1ֻ��������������
2.����ֻ�����������ͬʱ�������ܻ���������������� (̰��!)
*/

#include "util.h"

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;  //���迼����˵���ͬʱ������
}

class Solution
{
public:
	int findMinArrowShots(vector<pair<int, int>>& points)
	{
		//���������Ϊ�գ�ֱ�ӷ���0
		if (points.size() == 0)
			return 0;

		sort(points.begin(), points.end(), cmp);  //����������˵��С��������

		int shoot_num = 1;  //��ʼ������������Ϊ1
		int shoot_begin = points[0].first;  
		int shoot_end = points[0].second;   //��ʼ��������䣬��Ϊ��һ������������˵�

		for (int i = 0; i < points.size(); i++)
		{
			//������������˵�С�ڵ��������Ҷ˵� �����µ�ǰ���������
			if (points[i].first <= shoot_end)
			{
				shoot_begin = points[i].first; //��������������˵㼴Ϊ�������˵�
				if (shoot_end > points[i].second) //����������Ҷ˵�����������Ҷ˵�ʱ
				{
					shoot_end = points[i].second;
				}
			}
			else
			{
				shoot_num++; 
				shoot_begin = points[i].first; //�ٱ�֤��ǰ�����䴩�������£�������䲻���ٸ����ˣ���Ҫ����һ���µ��������
				shoot_begin = points[i].second;
			}
		}
		return shoot_num;
	}
};


int comp(const void* a, const void* b)
{
	return ((int**)a)[0][0] - ((int**)b)[0][0];
}
int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize) {
	qsort(points, pointsRowSize, sizeof(points[0]), comp);
	int start = 0;
	int end = 0;
	int ret = 0;
	int count = 0;
	while (count < pointsRowSize) {
		ret++;
		int tamp = 0;
		start = points[count][0];
		end = points[count][1];
		for (int i = count;; i++) {
			tamp = i;
			if (i >= pointsRowSize
				|| points[i][0] > end) {
				break;
			}
			start = points[i][0];
			if (points[i][1] < end) {
				end = points[i][1];
			}
		}
		count = tamp;
	}
	return ret;
}