#pragma once
#include "util_c.h"

//1��bruce force T(n)=O(n^2) S(n)=O(1)
#if 0
int* twoSum(int* nums, int numsSize, int target)
{	//ret-�������
	int* ret = (int*)malloc(2 * sizeof(int)); // ��������Ԫ�صĶ�̬����
	for (ret[0] = 0; ret[0] < numsSize; ++ret[0])
		//ʹ��ret[0]����ǰһ��Ԫ���±꣬ret[1]�����һ��Ԫ���±�
		for (ret[1] = ret[0] + 1; ret[1] < numsSize; ++ret[1])
			//ÿ��ret[0]����Ҫ����n-r��ret[1],��ʱ�临�Ӷ�ΪO(n^2)
			if (nums[ret[0]] + nums[ret[1]] == target)
				return ret;
	return ret;
}//version A
#endif

//2��version B  T(n)=O(nlogn) 
void swap(int* const a, int* const b)
{   //--����--
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
//--�㷨--ͨ����������������
void sort_indexes(const int* const nums, int* const indexes, int lo, int hi)
{
	if (lo < hi)
	{
		int pivot = partition_indexes(nums, indexes, lo, hi);
		sort_indexes(nums, indexes, lo, pivot);
		sort_indexes(nums, indexes, pivot + 1, hi);
	}
}
/*˼·�����ǵ������������������ôͨ��lo��hi��ָԪ��֮����target�Ĺ�ϵ
  ���е����������׵ó��������ʱT(n)=O(n)������������Ҫ��Ԫ�ؽ�����������
  ���ſ��ԴﵽO(nlogn)��ʱ�临�Ӷȣ��������廹����ҪO(nlogn);
*/
int* twoSum(int* nums, int numsSize, int target)
{
	int* ret = (int*)malloc(2 * sizeof(int));
	int* indexes = (int*)malloc(numsSize * sizeof(int));

	//����������
	for (int i = 0; i < numsSize; ++i)
		indexes[i] = i;

	//������������
	sort_indexes(nums, indexes, 0, numsSize);

	int lo = 0, hi = numsSize - 1;
	while (nums[indexes[lo]] + nums[indexes[hi]] != target)
		nums[indexes[lo]] + nums[indexes[hi]] < target ? ++lo : --hi;

	ret[0] = indexes[lo];
	ret[1] = indexes[hi];

	free(indexes);

	return ret;
}