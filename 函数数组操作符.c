#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//打印乘法口诀表
void print(int i)
{
	//循环每行(j表示行)
	int j = 0;
	for (j = 1; j <= i; j++)
	{
		//循环每列（n表示列）
		int n = 0;
		for (n = 1; n <= j; n++)
		{
			printf("%d*%d=%-2d  ",j,n,j*n);
		}
		printf("\n");
	}
}

int main()
{
	int i = 0;
	scanf("%d",&i);
	print(i);

	return 0;
}


//用函数递归将参数字符串中的字符反向排列
//
#include <string.h>

//不用库函数
//思想：遍历字符串当遍历到'\0'时表示字符串结束；运用指针是因为实参不能被改变需要传递地址
int my_strlen(char *arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		*arr++;
	}
	return count;
}
//思路：
//（1）将'\0'前一元素与字符串第一元素交换。举例：'hello\0'变为'oell \0'
//（2）将'\0'赋给第一步'\0'前一元素，改变字符串长度使得交换循环进行。此时'oell \0'变成'oell\0\0'此时倒数第二个'\0'占的是h的位
//（3）判断字符串长度是否>=2如果是，运用函数递归调用reversion_print函数函数参数为arr+1;
//（4）递归过程为：'oell\0\0'变成'oll\0\0\0'；此时倒数第三个'\0'占的e的位，倒数第二个'\0'占的是h的位；字符串长度<2,函数递归调用结束。
//（5）交换'\0'：'oll\0\0\0'变成'olle\0\0','olle\0\0'变成'olleh\0';此时字符串已全部交换，此时'hello\0'变为'olleh\0'

void reversion_print(char *arr)
{
	int left = 0;
	int right = my_strlen(arr) - 1;
	char tmp = arr[left];//(1)
	arr[left] = arr[right];
	arr[right] = '\0';//(2)
	if (my_strlen(arr + 1) >= 2)//(3)
		reversion_print(arr + 1); //(4)
	arr[right] = tmp;//(5)
}
//不用库函数


int main()
{
	char arr[20] = " ";
	scanf("%s",&arr);
	reversion_print(arr);
	printf("%s", arr);
}


//计算一个数的每位之和

//循环
int add1(int i)
{
	int j = 0;
	int sum = 0;
	while(i>9)
	{
		j = i % 10;
		i = i / 10;
		sum = sum + j;
	}
	sum = sum + i;
	return sum;
}

//递归
int add2(int i)
{
	if (i > 9)
	{
		return (add2(i / 10) + i % 10);
	}
	else
		return i;
}

int main()
{
	int i = 0;
	scanf("%d",&i);
	int tmp1 = add1(i);
	int tmp2 = add2(i);
	printf("%d每位相加和为%d\n",i,tmp1);
	printf("%d每位相加和为%d\n",i,tmp2);

	return 0;
}

//递归实现n的k次方
//使用库函数
//pow函数属于math库作用为求n的k次方
#include <math.h>
//创建递归函数

double Pow(int n, int k)
{
	if (k > 0)
	{
		return n*Pow(n, k - 1);
	}
	else if (k == 0)
	{
		return 1;
	}
	else
	{
		return 1.0 / Pow(n, -k);
	}
}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d,%d",&n,&k);//注意附多个值时一定注意语法%d%d输入后编译器无法识别，%d %d或者%d,%d可以识别。
	//注意：scanf在输入带空格的字符串时会默认空格为结束符所以输入字符串一般用gets(),输入字符用getchar().
	double d = Pow(n, k);
	printf("d =%lf\n",d);
	return 0;
}


//运行结果为6385
int  main()
{
	char c[2][5] = { "6938", "8254" }, *p[2];
	int i, j, s = 0;
	for (i = 0; i < 2; i++)
		p[i] = c[i];
	for (i = 0; i < 2; i++)
	for (j = 0; p[i][j] > 0; j+=2)
		s = 10 * s + p[i][j] - '0';
	printf(" %d \n ", s);
}

//创建整型数组进行初始化，打印数组每个元素，实现数组元素逆置
//创建函数完成
//
//初始化函数
void Init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
}
//打印函数
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
//
//逆置函数
void reserve(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left<right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
//
int main()
{
	int arr[20] = { 1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Init(arr, sz);
	print(arr,sz);
	reserve(arr, sz);
	print(arr, sz);
	return 0;
}

//将数组A当中的内容和数组B交换，两个数组一样大

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 6, 7, 8, 9, 10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int tmp = 0;
	int i = 0;
	
	for (i = 0; i < sz; i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	print(arr1,sz);
	print(arr2, sz);
	return 0;
}

//求两个二进制中不同位的个数
//思路：按位异或（异或相同为0，相异为1）确定不同位；第i位和第i-1与，同真为真，其余为假。

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d,%d",&a,&b);
	int tmp = a^b;
	int count = 0;
	int i = 1;
	while(tmp)
	{
		tmp = tmp&(tmp - 1);
		count++;
	}
	printf("%d",count);
	return 0;
}


//打印整数二进制的奇数位和偶数位
//思路：右移到最低位按位与1就可以得到这一位
int main()
{
	int a = 0;
	scanf("%d", &a);
	int i = 0;
	//打印奇数
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d", (a >> i) & 1);
	}
	printf("\n");
	//打印偶数
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d", (a >> i) & 1);
	}
	printf("\n");
	return 0;
}

#include <string.h>

//字符串逆置函数
void reserve1(char* arr)//注意指针的写法
{
	int len = strlen(arr);
	char* left=arr;//字符串地址为首元素地址
	char* right=arr+len-1;
	int tmp = 0;
	while (left<right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main()
{
	char arr[20] = { 0 };
	gets(arr);
	reserve1(arr);
	printf("%s\n",arr);
	return 0;
}

//计算求和sn=a+aa+aaa+aaaa+aaaaa的前五项之和a为一个数字

int main()
{
	int a = 0;
	int n = 0;
	scanf("%d,%d",&a,&n);
	int i = 0;
	int sum = 0;
	int sn = 0;
	for (i = 0; i < n; i++)
	{

		sum = 10*sum+a;
		sn = sn + sum;/*sn += sum;*/
	}
	printf("tmp=%d\n",sn);
	return 0;
}


//打印1-10000的水仙花数
#include <math.h>
int main()
{
	int i = 0;
	for (i = 0; i < 10000; i++)
	{
		int sum = 0;
		int count = 1;//任何数最少1位
		//判断i是否为水仙花数
		//1.计算i的位数
		int tmp = i;
		while (tmp /= 10)
		{
			count++;
		}
		//2.得到i的每一位，计算每一位的位数次方和
		tmp = i;
		while (tmp)
		{
			sum = sum + pow(tmp % 10, count);//sum +=pow(tmp % 10, count);
			tmp = tmp / 10;//tmp /=10;
		}
		//3.判断
		if (sum == i)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}

//打印菱形
int main()
{
	int n = 0;
	scanf("%d",&n);
	//打印上半部分
	int i = 0;
	for (i = 0; i < n; i++)
	{
		//打印一行
		//先打印空格
		int j = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * i + 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分
	for (i = 0; i < n-1; i++)
	{
		//打印一行
		//先打印空格
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf(" ");
		}
		//打印*
		for (j = 0; j < 2 * (n-1-i)-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
