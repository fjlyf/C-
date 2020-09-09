#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	int a = 10;
	int b = 20;
	int max = 0;
	if (a > b)
	{
		max = a;
		printf("max=a%d\n", a);
	}
	else
		printf("max=b%d\n", b);
	return 0;
}
//判断任意两个数的大小
//方法一
int main()
{
	int a = 0;
	int b = 0;

	printf("请输入两个数：");
	scanf_s("%d,%d", &a, &b);

	if (a > b)
	{
		printf("%d\n", a);
	}
	else
		printf("%d\n", b);
	return 0;
}
//方法二
int main()
{
	int a = 0;
	int b = 0;
	int max = 0;

	printf("请输入两个数：");
	scanf("%d,%d", &a, &b);
	//运用三目运算符,(a>b)?(a):(b)意思为当a>=b时max=a；当a<b时max=b.
	max = a >= b ? a : b;
	printf("%d\n", max);

	return 0;
}

//判断任意三个数的大小
//方法一
//思路三个数a,b,c;如果a>b，比较a和c如果a>c则a为最大值否则c为最大值；else a<b，在else的前提下如果b>c则b为最大值.
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入三个数：");
	scanf("%d,%d,%d", &a, &b, &c);
	if (a > b)
	{
		if (a > c)
		{
			printf("最大值为%d", a);
		}
		else
			printf("最大值为%d", c);
	}
	else if (b > c)
		printf("最大值为%d", b);
	return 0;
}

//方法二
//思路为判断前两个数大小,将较大数赋给max,再将max与第三个数比较找到最大的数
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int max = 0;
	printf("请输入三个数：");
	scanf("%d,%d,%d", &a, &b, &c);
	if (a > b)
	{
		max = a;
	}
	else max = b;
	if (max > c)
	{
		printf("最大值为%d", max);
	}
	else
		printf("最大值为%d", c);
	return 0;
}

//方法三
//运用三目操作符
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int max = 0;
	printf("请输入三个数：");
	scanf("%d,%d,%d", &a, &b, &c);
	max = a >= b ? a : b;
	max = max >= c ? max : c;
	printf("最大值为%d", max);

	return 0;
}

////判段给定数组中最大值
int main()
{
	int i = 1;
	int arr[] = { 1, 2, 3, 9, 6, 7, 8};
	int max = 0;
	for (i = 1; i < 10;i++)
	{
		if (max <= arr[i])
		{
			max = arr[i];
		}
		else
		{
			max = max;
		}
	}
	printf("最大值为%d", max);
	return 0;
}


//判段给定数组中最大值
//运用三木操作符
int main()
{
	int i = 0;
	int max = 0;
	int arr[] = { 1, 2, 3, 9, 6, 7, 8 };
	
	for (i = 0; i < 7; i++)
	{
		max=(arr[i] >= max ? arr[i] : max);

	}
	printf("最大值为%d", max);
	return 0;
}


//说明运用指针和二叉树也可以实现
