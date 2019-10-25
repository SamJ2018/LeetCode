/*
ʹ��C/C++����дһ��������ʵ���ַ����ķ�ת��Ҫ�������κ�ϵͳ��������ʱ�临�Ӷ���С��
����ԭ���ǣ�char *reverse_str(char *str)
*/
#include <stdio.h>

char* reverse_str(char* str)
{
	if (nullptr == str)
		return str;

	char* begin;
	char* end;
	begin = end = str;

	while (*end != '\0') //endδ���ַ���ĩβ
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
