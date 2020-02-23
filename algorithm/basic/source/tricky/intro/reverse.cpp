#include <iostream>
#include <cstdlib>

enum{ concise,tricky,complicate } ;

//减而知治策略
void reverse(int *A, int lo, int hi)
{
	//1
	if(lo < hi) 
	{
		std::swap(A[lo],A[hi]);
		reverse(A,lo + 1,hi -1);
	}

#if complicate
	while(lo < hi) std::swap(A[lo++],A[hi--]);
#endif
	
}

//分而治之策略
int32_t sum(int A[], int lo, int hi) 
{
	if(lo == hi) return A[lo] ;
	int mi = (lo + hi) >> 1;
	return sum(A,lo,mi) + sum(A, mi + 1, hi);
}

//找出最大元素和次大元素
//1
void max2(int A[], int lo, int hi, int& x1 ,int& x2)
{
	if(A[x1 = lo] < A[x2 = lo + 1]) std::swap(x1,x2);
	for(int i = lo + 2;i < hi; i++)
		if(A[x2] < A[i])
			if(A[x1] < A[x2 = i])
				std::swap(x1,x2);
}
//2
void max2_2(int A[],int lo,int hi,int& x1,int& x2)
{
	if(lo + 2 == hi) { /**/ return ;}
	if(lo + 3 == hi) { /**/ return ; }

	int mi = (lo + hi) >> 1;
	int x1L,x2L; max2_2(A,lo,mi,x1L,x2L);
	int x1R,x2R; max2_2(A,mi,hi,x1R,x2R);

	if(A[x1L] > A[x1R]){
		x1 = x1L; x2 = (A[x2L] > A[x1R]) ? x2L : x1R;
	} else{
		x1 = x1R; x2 = (A[x1L] > A[x2R]) ? x1L : x2R;
	}
} // 2*T(n/2) +2 <=  5n/3 -2

int main()
{
	int arr[] = {13,24,12,34,53,12,33,4,12};
	reverse(arr,0,8);
	int x1, x2;
   // max2(arr,0,9,x1,x2);
   // std::cout << x1 << ", " << x2 << std::endl;

	std::cout << sum(arr,0,8) << std::endl;
	for(int i  = 0; i < 9; i++ ) std::cout << arr[i] << " " ;
    return 0;
}




