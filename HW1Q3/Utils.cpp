#include <stdio.h>
#include "Utils.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void reverse(int* nums, unsigned int size)
{
	Stack* s = new Stack;
	initStack(s);
	for (int i = 0; i < size; i)
	{
		push(s, nums[i]);
	}
	for (int i = 0; i < size; i++)
	{
		nums[i] = pop(s);
	}
}

int* reverse10()
{
	int* nums = new int[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> nums[i];
	}
	reverse(nums, 10);
	return nums;
}
