/*
使用C/C++语言写一个函数，实现字符串的反转，要求不能用任何系统函数，且时间复杂度最小。
函数原型是：char *reverse_str(char *str)
*/
#include <stdio.h>

char* reverse_str(char* str)
{
	if (nullptr == str)
		return str;

	char* begin;
	char* end;
	begin = end = str;

	while (*end != '\0') //end未到字符串末尾
		end++;

	--end;
	char temp;

	while (begin < end)
	{
		temp = *begin;
		*begin = *end;
		*end = temp;

		begin++; end--;
	}
	return str;
}
