#include <iostream>
using namespace std;


//版本1
template<typename T>
void bubblesort(T A[],int n){
	for(bool sorted = false; sorted = !sorted; --n)
	{
		for(int i = 1; i < n; ++i)
			if(A[i-1] > A[i])
			{
				swap(A[i-1],A[i]);
				sorted = false;
			}	
	}
	for(int i = 0; i < n; i++) cout << A[i] << " ";
}




int main()
{
	int arr[] = {2,8,3,12,34,12,34,9,23,65,12,33,43};
	bubblesort(arr,13);
    return 0;
}

