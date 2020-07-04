#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

//模拟实现库函数strlen（计算字符长度）

int my_strlen(char *p)
{
	assert(p != NULL);
	int count = 0;

	while (*p != '\0')
	{
		p++;
		count++;
	}
	return count;
}

int main()
{
char arr[256] = "h";
scanf("%s",&arr);
int ret = my_strlen(arr);
printf("%d\n", ret);
return 0;
}



//模拟实现库函数strcpy(实现字符拷贝)

char *my_strcpy(char *p1, const char *p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	while (*(p1++ )= *(p2++))
	{
		;
	}
	return p1;
}

int main()
{
	char arr[20] = "hello";
	printf("%s\n", arr);
	my_strcpy(arr,"how");
	printf("%s\n", arr);
	return 0;
}


/*
调整数组使奇数全部都位于偶数前面。
题目：
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。
*/

void adjust(int arr[], int sz)
{
	int *left = arr;
	int *right = arr + sz - 1;
	int tmp = 0;
	int rep = 0;

	/*思路：将整个数组分为左边和右边，每判断一个left,随之判断一个right。如果left为偶数且right 为奇数两者交换。
	1、判断左边元素是否有奇数，如果有left++跳过下面的语句保证此元素位置不变。
	2、判断左边下一个元素是否为奇数，如果为偶数进行下一步操作。
	   2.1、如果右边元素为奇数，保存此时的left和right值并且将right与left交换。
	   2.2、如果右边元素为偶数，right++，进行第二次循环。*/

	while (left < right)//保证左右部分不重合
	{
		while ((left < right) && (*left % 2 == 1))
		{
			left++;
			continue;
		}
		if (*right % 2 == 1)
		{
			tmp = *left;
			rep = *right;
			*left = rep;
			*right = tmp;
			left++;
			right--;
		}
		else
		{
			right--;
		}
	}
}	


int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz ; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	adjust(arr,sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}