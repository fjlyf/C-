#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////判断一个数是否为奇数
int main()
{
	int i=0;
	printf("请输入数字：");
	scanf("%d", &i);
	if (i % 2 == 1)
		printf("%d为奇数", i);
	else
		printf("%d为偶数", i);
	return 0;
}

//输出1-100之间的奇数
int main()
{
	int i = 0;
	for (i = 0; i < 100; i++)
	{
		if (i % 2 == 1)
			printf("%d\n", i);
	}
	return 0;
}

//练习打印0-9用while循环
int main()
{
	int i = 0;
	while ( i < 10)
	{
		printf("%d\n", i);
		i++;
	}
	return 0;
}

//将三个数按大到小输出
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int i = 0;
	printf("请输入：");
	scanf("\n%d,%d,%d", &a, &b, &c);
	if (a < b)
	{
		i = a;
		a = b;
		b = i;
	}
	if (a < c)
	{
		i = a;
		a = c;
		c = i;
	}
	if (b < c)
	{
		i = b;
		b = c;
		c = i;
	}
	printf("%d,%d,%d", a, b, c);

	return 0;
}

打印1-100之间所有3的倍数的数字
int main()
{
	int i = 1;
	for (i = 1; i < 100;i++)
	{
		if (i%3==0)
		printf("%d\n", i);
	}
	return 0;
}

////给定两个数，求这两个数的最大公约数
int main()
{
	//辗转相除法
	int a = 28;
	int b = 70;
	int c = 0;
	while (c=a%b)
	{
		a = b;
		b = c;
	}
	printf("最大公约数为%d", b);
	return 0;
}


//打印1000到2000年之间的闰年
int main()
{
	int year = 1000;
	int count = 0;//计数
	while (year <= 2000)
	{
		//闰年判断规则
		//1.能被4整除并且能被100整除
		//2.能被400整除
		if (((year % 4 == 0) && (year % 100 == 0)) || (year % 400 == 0))//&&逻辑与，||逻辑或
		{
			printf("%d\n", year);
			count++;
		}
			year++;
	}
	printf("\ncount=%d\n", count);
	return 0;
}


//打印100到200之间的素数
int main()
{
	//判断i是否为素数
	//素数只能被本身和1整除
	//产生2->i-1之间的数字，拿产生的数字试除1，如果被整除，说明i不是素数，如果2->i-1之间没有一个能整除i，则说明i是素数
	int i = 100;
	int count = 0;
	while (i <= 200)
	{
		int j = 2;
		while (j < i)
		{
			//拿j试除i
			if (i%j == 0)
			{
				//不是素数
				break;
			}
			j++;
		}
		if (i == j)
		{
			//是素数
			printf("%d\n", i);
			count++;
		}
		i++;
	}
	printf("\ncount=%d\n", count);
	return 0;
}