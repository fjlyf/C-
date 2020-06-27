#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//冒泡排序
//算法思想：两两相邻的元素比较，（以升序为例）较大者后移
//一趟冒泡排序：（以54321为例）
//54321
//45321
//43521
//43251
//43215
//一趟冒泡排序结束

//void BubbleSort(int* arr, int sz)
//{
//	int i = 0;
//	//确定排序趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		//一趟冒泡排序
//		int j = 0;
//		for (j = 0; j <sz-1-i ; j++)//i=0时共有sz-1个元素需要排序，i=1时共有sz-1-1个元素需要排序，i=2时共有sz-1-2个元素需要排序；所以j<sz-1-i
//		{
//			if (arr[j]>arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}

//优化
//如果元素没有交换说明数组有序，元素不需要交换。设置一个变量flag=1，如果元素交换将flag=0，没有交换就跳出循环
void BubbleSort(int* arr, int sz)
{
	int i = 0;
	//确定排序趟数
	for (i = 0; i < sz - 1; i++)
	{
		//一趟冒泡排序
		int flag = 1;
		int j = 0;
		for (j = 0; j <sz - 1 - i; j++)//i=0时共有sz-1个元素需要排序，i=1时共有sz-1-1个元素需要排序，i=2时共有sz-1-2个元素需要排序；所以j<sz-1-i
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag = 1)
		{
			break;
		}
	}
}


//打印函数
void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz ; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
}


int main()
{
	int arr[6] = { 9, 1, 3, 5, 7, 8};
	int sz = sizeof(arr) / sizeof(arr[0]);

	//写一个冒泡函数使得数组arr排成升序
	print(arr, sz);//打印函数，打印排序前的arr
	BubbleSort(arr, sz);//冒泡函数
	print(arr, sz);//打印函数，打印排序后的arr

	return 0;
}
