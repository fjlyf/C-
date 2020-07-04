#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

//ģ��ʵ�ֿ⺯��strlen�������ַ����ȣ�

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



//ģ��ʵ�ֿ⺯��strcpy(ʵ���ַ�����)

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
��������ʹ����ȫ����λ��ż��ǰ�档
��Ŀ��
����һ���������飬ʵ��һ��������
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�
*/

void adjust(int arr[], int sz)
{
	int *left = arr;
	int *right = arr + sz - 1;
	int tmp = 0;
	int rep = 0;

	/*˼·�������������Ϊ��ߺ��ұߣ�ÿ�ж�һ��left,��֮�ж�һ��right�����leftΪż����right Ϊ�������߽�����
	1���ж����Ԫ���Ƿ��������������left++�����������䱣֤��Ԫ��λ�ò��䡣
	2���ж������һ��Ԫ���Ƿ�Ϊ���������Ϊż��������һ��������
	   2.1������ұ�Ԫ��Ϊ�����������ʱ��left��rightֵ���ҽ�right��left������
	   2.2������ұ�Ԫ��Ϊż����right++�����еڶ���ѭ����*/

	while (left < right)//��֤���Ҳ��ֲ��غ�
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