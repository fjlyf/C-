#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//��Ŀ��һֻ����һ��ֻ����һ��̨�ף�Ҳ���������������������һ��n��̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ����
//����n��̨����˵��ֻ�ܴ�n-1����n-2��̨��������������F��n��=F(n-1)+F(n-2),���õݹ�

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
	printf("������������̨��̨����:>");
	scanf("%d",&n);
	//int ret = Jump_Floor(n);
	int ret1 = Jump_Floor1(n);
	//printf("%d\n",&ret);
	printf("%d\n", &ret1);
	return 0;
}
