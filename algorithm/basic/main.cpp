#include "include/head.h"
#include <string.h>

#define cmp(x) (strcmp(argv[1],x)==0)


int main(int argc,char* argv[])
{
	if(argc == 1) cout << "参数过少！" ;
	
	//	cout << argv[1];
    //cout << typeid(argv[1]).name() << endl;
	
	if(cmp("hailstone"))
		hailstone(27);
    return 0;
}

