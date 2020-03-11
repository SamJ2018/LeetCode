#include <iostream>
#include "vector.h"

void visit(double);

int main()
{
	double arr[] = { 3,5,2,9,23,12,7,34,12,2,34,25,29 };
	Vector<double> v(arr,0,13);
	//v.traverse(visit);
	//v.sort(0,13);
	//v.traverse(visit);

    return 0;
}

void visit(double x)
{

	cout << x << " ";
}


