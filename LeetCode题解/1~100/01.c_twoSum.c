#pragma once
#include "util_c.h"

//1、bruce force T(n)=O(n^2) S(n)=O(1)
#if 0
int* twoSum(int* nums, int numsSize, int target)
{	//ret-结果数组
	int* ret = (int*)malloc(2 * sizeof(int)); // 创建两个元素的动态数组
	for (ret[0] = 0; ret[0] < numsSize; ++ret[0])
		//使用ret[0]保存前一个元素下标，ret[1]保存后一个元素下标
		for (ret[1] = ret[0] + 1; ret[1] < numsSize; ++ret[1])
			//每个ret[0]都需要遍历n-r次ret[1],故时间复杂度为O(n^2)
			if (nums[ret[0]] + nums[ret[1]] == target)
				return ret;
	return ret;
}//version A
#endif

//2、version B  T(n)=O(nlogn) 
void swap(int* const a, int* const b)
{   //--交换--
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition_indexes(const int* const nums, int* const indexes, int lo, int hi)
{
	int pivot = lo++;
	int pivot_val = nums[indexes[pivot]];
	int idx = pivot;

	int tmp;
	for (; lo < hi; ++lo)
		if (nums[indexes[lo]] <= pivot_val)
			swap(indexes + lo, indexes + ++idx);
	swap(indexes + pivot, indexes + idx);
	return idx;
}
//--算法--通过索引将数组排序
void sort_indexes(const int* const nums, int* const indexes, int lo, int hi)
{
	if (lo < hi)
	{
		int pivot = partition_indexes(nums, indexes, lo, hi);
		sort_indexes(nums, indexes, lo, pivot);
		sort_indexes(nums, indexes, pivot + 1, hi);
	}
}
/*思路：考虑到如果数组整体有序，那么通过lo和hi所指元素之和与target的关系
  进行调整，很容易得出结果，此时T(n)=O(n)。但是我们需要对元素进行排序，利用
  快排可以达到O(nlogn)的时间复杂度，所以总体还是需要O(nlogn);
*/
int* twoSum(int* nums, int numsSize, int target)
{
	int* ret = (int*)malloc(2 * sizeof(int));
	int* indexes = (int*)malloc(numsSize * sizeof(int));

	//建立索引表
	for (int i = 0; i < numsSize; ++i)
		indexes[i] = i;

	//将索引表排序
	sort_indexes(nums, indexes, 0, numsSize);

	int lo = 0, hi = numsSize - 1;
	while (nums[indexes[lo]] + nums[indexes[hi]] != target)
		nums[indexes[lo]] + nums[indexes[hi]] < target ? ++lo : --hi;

	ret[0] = indexes[lo];
	ret[1] = indexes[hi];

	free(indexes);

	return ret;
}