#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//
////计算n的阶乘
int main()
{
	int i = 1;
	int n = 1;
	int ret = 1;
	scanf("%d", &n);
	for (i=1; i <= n; i++)
	{
		ret = ret*i;
	}
	printf("阶乘为%d", ret);
	return 0;
}

////计算1!+2!+...+10!
int main()
{
	int n = 0;
	int ret = 1;//阶乘
	int sum = 0;//求和
	//for循环每次产生的阶乘在乘以n即为n的阶乘n!=(n-1)!*n
	for (n = 1; n <= 10; n++)
	{
		ret = ret*n;
		sum = sum + ret;
	}

	printf("和为%d", sum);

	return 0;
}



//折半查找
//算法思路：由左到右进行二分查找，令中间值mid=（中间位,(leaf+right)/2）判断arr[mid]<key时，令leaf=mid+1;arr[mid]>key时，令right=mid-1,即下一次判断区间为[0-mid];直到arr[mid]=key此时找到key.
//以本题为例查找key=3,
//首先判断leaf<=right,进行第一次查找mid=4,key<arr[mid],此时right=mid-1=3;
//进行第二次查找，此次查找区间变成了{1,2,3,4}区间减半，判断leaf<right,mid=2,key=arr[mid]=3,找到key，break跳出循环。
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int key = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);//计算元素个数，操作符/表示除法
	int leaf = 0;
	int right = sz - 1;//原因：数组以\0结束，所以最后一位为sz-1;
	
	while (leaf <= right)
	{
		int mid = (leaf + right) / 2;
		if (arr[mid] < key)
		{
			leaf = mid + 1;
		}
		else if (arr[mid]>key)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到key,下标是%d\n", mid);
			break;
		}
		if (leaf > right)
		{
			printf("找不到key\n");
		}
	}
	return 0;
}