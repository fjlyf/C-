#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//题目：一只青蛙一次只能跳一级台阶，也可以跳两级。求该青蛙上一个n级台阶总共有多少种跳法（先后次序不同算不同的结果）
//对于n个台阶来说，只能从n-1或者n-2的台阶跳上来，所以F（n）=F(n-1)+F(n-2),采用递归

int Jump_Floor(int n)
{
	if (n <= 2)
		return n;	
	else
		return Jump_Floor(n - 2) + Jump_Floor(n - 1);
		
}
int Jump_Floor1(int n)
{
	int a = 1;
	int b = 2;
	int c = a;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	printf("请输入青蛙跳台的台阶数:>");
	scanf("%d",&n);
	//int ret = Jump_Floor(n);
	int ret1 = Jump_Floor1(n);
	//printf("%d\n",&ret);
	printf("%d\n", &ret1);
	return 0;
}
