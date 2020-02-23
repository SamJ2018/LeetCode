#ifndef HAILSTONE_CPP
#define HAILSTONE_CPP

/*
	hailstone序列
		证明有穷性
*/


#include "../include/head.h"

int hailstone(int n){
	int length = 1;
	cout << n << ",";
	while( 1 < n ) {
		(n % 2) ? n = 3 * n + 1 : n /= 2; 
		cout << n ;
		if(n != 1)
			cout << "," ;
		length ++;
	}
	cout << endl;
	cout << length << endl;
}

#endif
