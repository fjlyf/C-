#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//
////����n�Ľ׳�
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
	printf("�׳�Ϊ%d", ret);
	return 0;
}

////����1!+2!+...+10!
int main()
{
	int n = 0;
	int ret = 1;//�׳�
	int sum = 0;//���
	//forѭ��ÿ�β����Ľ׳��ڳ���n��Ϊn�Ľ׳�n!=(n-1)!*n
	for (n = 1; n <= 10; n++)
	{
		ret = ret*n;
		sum = sum + ret;
	}

	printf("��Ϊ%d", sum);

	return 0;
}



//�۰����
//�㷨˼·�������ҽ��ж��ֲ��ң����м�ֵmid=���м�λ,(leaf+right)/2���ж�arr[mid]<keyʱ����leaf=mid+1;arr[mid]>keyʱ����right=mid-1,����һ���ж�����Ϊ[0-mid];ֱ��arr[mid]=key��ʱ�ҵ�key.
//�Ա���Ϊ������key=3,
//�����ж�leaf<=right,���е�һ�β���mid=4,key<arr[mid],��ʱright=mid-1=3;
//���еڶ��β��ң��˴β�����������{1,2,3,4}������룬�ж�leaf<right,mid=2,key=arr[mid]=3,�ҵ�key��break����ѭ����
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int key = 3;
	int sz = sizeof(arr) / sizeof(arr[0]);//����Ԫ�ظ�����������/��ʾ����
	int leaf = 0;
	int right = sz - 1;//ԭ��������\0�������������һλΪsz-1;
	
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
			printf("�ҵ�key,�±���%d\n", mid);
			break;
		}
		if (leaf > right)
		{
			printf("�Ҳ���key\n");
		}
	}
	return 0;
}