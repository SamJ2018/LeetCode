#include <iostream>
#include <time.h>
#include <algorithm>
#include <stack>
using namespace std;
#define NUM 100

//一、版本1
void bubbleSort1(int arr[],int n)
{
	bool flag = true;
	for (int i = 0; flag && i < n - 1; i++)
	{
		flag = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = true;
				swap(arr[j], arr[j + 1]);
				//printf("%d", arr[j]);
			}
		}
	}
}

//版本2
template <typename T>
void bubbleSortBothWay(T& arr)
{
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 0, i, j;
	bool unsorted;

	do {
		for (i = k, unsorted = false; i < len -1- k; ++i) {
			if (arr[i + 1] < arr[i])
			{
				swap(arr[i + 1], arr[i]);
				unsorted = true;
			}
		}

		if (!unsorted)
			break;

		for (j = i - 1, unsorted = false; j >= k + 1; --j)
		{
			if (arr[j] < arr[j - 1])
			{
				swap(arr[j], arr[j - 1]);
				unsorted = true;
			}
		}
		k++;
	} while (unsorted);
}

//冒泡终极版
template <typename T>
void bubbleSortUpgrade(T& arr)
{
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int m; 1 < len; len = m)
	{
		for (int i = m = 1; i < len; ++i)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i - 1], arr[i]);
				m = i;
			}
		}
	}
}

//二、快排
template <typename T>
int partition(T& arr,int lo,int hi)
{
	T pivot = arr[lo];

	while (lo < hi)
	{
		while (lo < hi && arr[hi] > pivot) --hi;
		arr[lo] = arr[hi];

		while (lo < hi && arr[lo] < pivot) ++lo;
		arr[hi] = arr[lo];
	}
	arr[lo] = pivot;
	return lo;
}

//快排版本2  随机+
template <typename T>
int partition2(T& arr, int lo, int hi) {
	swap(arr[lo], arr[lo + rand() % (hi - lo + 1)]);
	T pivot = arr[lo];
	int mi = lo;

	for (int k = lo + 1; k <= hi; k++)
		if (arr[k] < pivot)
			swap(arr[++mi], arr[k]);

	swap(arr[lo], arr[mi]);
	return mi;
}
//快排2
void quickSort(int arr[],int lo, int hi)
{
	int pivot;
	if (lo < hi)
	{
		pivot = partition2(arr, lo, hi);
		quickSort(arr, lo, pivot - 1);
		quickSort(arr, pivot + 1, hi);
	}
}

//快排（非递归）
template <class T>
void quickSort(T& a, int lo, int hi)
{
	stack<T> st;
	if (lo < hi)
	{
		T pivot = partition2(a, lo, hi);
		if (lo < pivot - 1)
		{
			st.push(lo);
			st.push(pivot - 1);
		}

		if (pivot + 1 < hi)
		{
			st.push(pivot + 1);
			st.push(hi);
		}

		while (!st.empty)
		{
			T q = st.top();
			st.pop();

			T p = st.top();
			st.pop();

			pivot = partition2(a, p, q);

			if (p < pivot - 1)
			{
				st.push(p);
				st.push(pivot - 1);
			}
			if (pivot + 1 < q)
			{
				st.push(pivot + 1);
				st.push(q);
			}
		}
	}
}

//三、归并（紧凑版）
void merge(int lo, int hi, int arr[], int mi)
{
	int* A = arr + lo; //整个向量
	int lb = mi - lo;

	int* B = new int[lb];

	for (int i = 0; i < lb; B[i] = A[i++]);//复制子向量

	int lc = hi - mi;
	int* C = arr + mi; //后半向量

	for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc);)
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k]))) A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] < B[j])))  A[i++] = C[k++];
	}
	delete B;
}

void mergeSort(int lo, int hi, int arr[])
{
	if (hi - lo < 2) return;
	int mi = (lo + hi) >> 1;
	mergeSort(lo, mi, arr);
	mergeSort(mi, hi, arr);
	merge(lo, hi, arr, mi);
}



//四、选择排序
int max(int arr[], int lo, int hi)
{
	int mx = hi;
	while (lo < hi--)
	{
		if (arr[hi] > arr[mx])
			mx = hi;
	}
	return mx;
}
void selectionSort(int arr[],int lo, int hi)//assert 0<lo<=hi<=size
{
	while (lo < --hi)
		swap(arr[max(arr, lo, hi)], arr[hi]);
}

//五、插入排序

//六、希尔排序
void shellSort(int arr[],int len)
{
	for (int gap = len / 2; gap > 0; gap /= 2)//增量
	{
		for (int i = gap; i < len; i++)
		{
			int j = i;
			int temp = arr[j];

			if (arr[j] < arr[j - gap]) {
				while (j - gap >= 0 && temp < arr[j - gap])
				{
					arr[j] = arr[j - gap];
					j -= gap;
				}
				arr[j] = temp;
			}
		}
	}
}

//七、基数排序
void radixSort(int arr[],int len)
{
	//1、找到数组中最大数的位数
	int mx = len;
	while (0 < len--)
	{
		if (arr[mx] < arr[len])
			mx = len;
	}

	int sum = 0;
	while (arr[mx])
	{
		sum++;
		arr[mx] /= 10;
	}

	const int num = 30;
	//基数排序是利用空间换时间
	
 }


void swap(int &n1,int &n2)
{
	n1 = n1 ^ n2;
	n2 = n1 ^ n2;
	n1 = n1 ^ n2;
}

int main(int argc, const char** argv)
{
	//cout << "helloword\n";
	int arr[NUM];
	for (int i = 0; i < NUM; i++)
	{
		arr[i] = rand() % NUM;
	}


	shellSort(arr, NUM);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d\n", arr[i]);
	}
	return EXIT_SUCCESS;
}