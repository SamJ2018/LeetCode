/*
There are a number of spherical balloons spread in two-dimensional space.
For each balloon, provided input is the start and end coordinates of the horizontal diameter. 
Since it's horizontal, y-coordinates don't matter and hence the x-coordinates of start and end of the diameter suffice. 
Start is always smaller than end. There will be at most 104 balloons.
An arrow can be shot up exactly vertically from different points along the x-axis. 
A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. 
There is no limit to the number of arrows that can be shot. An arrow once shot keeps travelling up infinitely. 
The problem is to find the minimum number of arrows that must be shot to burst all balloons.

Example:

Input:
[[10,16], [2,8], [1,6], [7,12]]

Output:
2

Explanation:
One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).

已知在一个平面上有一定数量的气球，平面可以看作一个坐标系，在平面的x轴的不同位置安排弓箭手向y轴方向射箭，弓箭可以向y轴走无穷远；
给定气球的宽度 xstart ≤ x ≤ xend，问至少需要多少弓箭手，将全部气球打爆?
例如: 四个气球 : [[10,16], [2,8], [1,6], [7,12]]，至少需要2个弓箭手。


贪心规律:
1.对于某个气球， 至少需要使用1只弓箭将它击穿。
2.在这只气球将其击穿的同时，尽可能击穿其他更多的气球！ (贪心!)
*/

#include "util.h"

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;  //无需考虑左端点相同时的排序
}

class Solution
{
public:
	int findMinArrowShots(vector<pair<int, int>>& points)
	{
		//传入的数据为空，直接返回0
		if (points.size() == 0)
			return 0;

		sort(points.begin(), points.end(), cmp);  //对气球按照左端点从小到大排序

		int shoot_num = 1;  //初始化弓箭手数量为1
		int shoot_begin = points[0].first;  
		int shoot_end = points[0].second;   //初始化射击区间，即为第一个气球的两个端点

		for (int i = 0; i < points.size(); i++)
		{
			//当射击区间的左端点小于等于气球右端点 ，更新当前的射击区间
			if (points[i].first <= shoot_end)
			{
				shoot_begin = points[i].first; //更新射击区间的左端点即为气球的左端点
				if (shoot_end > points[i].second) //当射击区间右端点大于新气球右端点时
				{
					shoot_end = points[i].second;
				}
			}
			else
			{
				shoot_num++; 
				shoot_begin = points[i].first; //再保证当前气球被射穿的条件下，射击区间不能再更新了，需要增加一个新的射击区间
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