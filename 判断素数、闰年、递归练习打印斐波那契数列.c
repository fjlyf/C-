#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//
////写一个函数判断一个数是不是素数
//
//#include <math.h>
//
//int is_prime(int n)
//{
//	int i = 2;
//
//	for (i = 2; i <= sqrt(n); i++)//sqrt函数为计算算数平方根
//	{
//		if (n%i == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 1;
//	scanf("%d",&i);
//
//	if (is_prime(i) == 1)
//	{
//		printf("%d是素数", i);
//	}
//	else
//		printf("%d不是素数",i);
//	return 0;
//}
//
//
//
////写一个函数判断一年是不是闰年
//
//int is_leap_year(int year)
//{
//	return((year%4==0&&year%100!=0)||(year%400==0));
//}
//
//
//int main()
//{
//	int i = 0;
//	scanf("%d", &i);
//	if (is_leap_year(i) == 1)
//	{
//		printf("%d是闰年", i);
//	}
//	else
//		printf("%d不是闰年", i);
//
//	return 0;
//}
//
//
////写一个函数实现整形有序数组的二分查找
//
//int binary_search(int key, int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//		}
//		else if(arr[mid]>key)
//		{
//			right = mid-1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//
//int main()
//{
//	int arr[] = {1,3,5,6,7,8,9,11,23};
//	int key = 0;
//	int sz = (sizeof arr) / (sizeof arr[0]);
//	scanf("%d", &key);
//	int ret = binary_search(key, arr, sz);
//
//	//能找到key不能显示位置
//	/*if (binary_search(key, arr, sz) == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//		printf("找到了%d\n", key);*/
//
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//		printf("找到了%d,下标为%d\n",key, ret);
//	return 0;
//}
//
//
////写一个函数，每调用一次函数，就会将num增加1；
//
//void add(int *p)
//{
//	*p =*p+1;//或者(*p)++;
//}
//
//int main()
//{
//	int i = 0;
//	int num = 0;
//	//指定循环11次，函数调用11次
//	for (i = 0; i < 11; i++)
//	{
//		add(&num);
//		printf("%d\n", num);
//	}
//	/*add(&num);
//	printf("%d\n", num);
//	add(&num);
//	printf("%d\n", num);*/
//
//	return 0;
//}
//
//
////递归练习
////接受一个整型值（无符号），按照顺序打印它的每一位。例如：输入1234，输出1 2 3 4
////思路：每次分别打印1234%10=4,123%10=3,12%10=2,1%10=1;按照这种思路定义一个打印函数进行递归运算使得打印为1 2 3 4
////printf函数的返回值为字符的个数
//
//void print(unsigned int num)
//{
//	if (num > 9)
//	{
//		print(num / 10);//改变每次print的数
//	}
//	printf("%d ",num%10 );//打印余数
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%d", &num);//12345
//	print(num);
//	//过程
//	//print(12345)
//	//print(1234) + 5
//	//print(123) + 4 + 5
//	//printf(12) + 3 + 4 + 5
//	//print(1) + 2 + 3 + 4 + 5
//	//1 2 3 4 5 
//
//	return 0;
//}
//
//
////编写函数不允许创建临时变量，求字符串的长度
////思路：字符串结束标志标志为\0，我们只需遍历字符串各位直到出现\0为止
//
////运用循环
//int my_strlen1(char *p)
//{
//	int count = 0;
//	while (*p != '\0')
//	{
//		count++;
//		p++;
//	}
//	return count;
//}
//
////运用函数递归
//int my_strlen2(char *p)
//{
//	if (*p != '\0')
//	{
//		return 1 + my_strlen2(p + 1);//运用函数递归代替循环 
//	}
//	
//	return 0;
//}
//
//int main()
//{
//	char arr[7];//定义字符串大小<=7,也就是说这个代码只能求<7的字符串大小
//	scanf("%s", &arr);
//	int len1 = my_strlen1(arr);//定义变量len为字符串arr的长度
//	int len2 = my_strlen2(arr);
//	printf("字符串长度为%d\n",len1 );
//	printf("字符串长度为%d\n", len2);
//
//	return 0;
//}
//
////求n!不考虑溢出
//
//int fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n*fac(n - 1);//运用函数递归
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//
//	int ret = fac(n);
//	printf("%d的阶乘为%d", n, ret);
//
//	return 0;
//}
//
//
////求第n个斐波那契数
////斐波拉契数列
////1 1 2 3 5 8 13 21 34 55 ...
//
//int fib(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fib(n);
//	printf("%d\n", ret);
//
//	return 0;
//}
//

