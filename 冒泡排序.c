#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


//ð������
//�㷨˼�룺�������ڵ�Ԫ�رȽϣ���������Ϊ�����ϴ��ߺ���
//һ��ð�����򣺣���54321Ϊ����
//54321
//45321
//43521
//43251
//43215
//һ��ð���������

//void BubbleSort(int* arr, int sz)
//{
//	int i = 0;
//	//ȷ����������
//	for (i = 0; i < sz - 1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		for (j = 0; j <sz-1-i ; j++)//i=0ʱ����sz-1��Ԫ����Ҫ����i=1ʱ����sz-1-1��Ԫ����Ҫ����i=2ʱ����sz-1-2��Ԫ����Ҫ��������j<sz-1-i
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

//�Ż�
//���Ԫ��û�н���˵����������Ԫ�ز���Ҫ����������һ������flag=1�����Ԫ�ؽ�����flag=0��û�н���������ѭ��
void BubbleSort(int* arr, int sz)
{
	int i = 0;
	//ȷ����������
	for (i = 0; i < sz - 1; i++)
	{
		//һ��ð������
		int flag = 1;
		int j = 0;
		for (j = 0; j <sz - 1 - i; j++)//i=0ʱ����sz-1��Ԫ����Ҫ����i=1ʱ����sz-1-1��Ԫ����Ҫ����i=2ʱ����sz-1-2��Ԫ����Ҫ��������j<sz-1-i
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


//��ӡ����
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

	//дһ��ð�ݺ���ʹ������arr�ų�����
	print(arr, sz);//��ӡ��������ӡ����ǰ��arr
	BubbleSort(arr, sz);//ð�ݺ���
	print(arr, sz);//��ӡ��������ӡ������arr

	return 0;
}
