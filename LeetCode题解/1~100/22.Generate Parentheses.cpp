/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include "util.h"

void traverse(char*** arr, int* returnSize, char* stack, int top, int leftCount, int rightCount)
{
	if (!leftCount && !rightCount)
	{
		*returnSize += 1;
		*arr = (char**)realloc(*arr, sizeof(char*) * (*returnSize));
		(*arr)[*returnSize - 1] = (char*)malloc(sizeof(char) * (top + 2));
		for (int i = 0; i <= top; i++)
			(*arr)[*returnSize - 1][i] = stack[i];
		(*arr)[*returnSize - 1][top + 1] = '\0';
		return;
	}
	if (leftCount)
	{
		stack[top + 1] = '(';
		traverse(arr, returnSize, stack, top + 1, leftCount - 1, rightCount);
	}
	if (rightCount)
	{
		stack[top + 1] = ')';
		traverse(arr, returnSize, stack, top + 1, leftCount, rightCount - 1);
	}
}

//AC - 0ms;
char** generateParenthesis(int n, int* returnSize)
{
	if (!n) return NULL;
	char** arr = (char**)malloc(sizeof(char*));
	*returnSize = 0;
	char* stack = (char*)malloc(sizeof(char) * 2 * n);
	int top = -1;
	int leftCount = n;
	int rightCount = n;
	traverse(&arr, returnSize, stack, top, leftCount, rightCount);
	return arr;
}