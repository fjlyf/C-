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
//�ж������������Ĵ�С
//����һ
int main()
{
	int a = 0;
	int b = 0;

	printf("��������������");
	scanf_s("%d,%d", &a, &b);

	if (a > b)
	{
		printf("%d\n", a);
	}
	else
		printf("%d\n", b);
	return 0;
}
//������
int main()
{
	int a = 0;
	int b = 0;
	int max = 0;

	printf("��������������");
	scanf("%d,%d", &a, &b);
	//������Ŀ�����,(a>b)?(a):(b)��˼Ϊ��a>=bʱmax=a����a<bʱmax=b.
	max = a >= b ? a : b;
	printf("%d\n", max);

	return 0;
}

//�ж������������Ĵ�С
//����һ
//˼·������a,b,c;���a>b���Ƚ�a��c���a>c��aΪ���ֵ����cΪ���ֵ��else a<b����else��ǰ�������b>c��bΪ���ֵ.
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("��������������");
	scanf("%d,%d,%d", &a, &b, &c);
	if (a > b)
	{
		if (a > c)
		{
			printf("���ֵΪ%d", a);
		}
		else
			printf("���ֵΪ%d", c);
	}
	else if (b > c)
		printf("���ֵΪ%d", b);
	return 0;
}

//������
//˼·Ϊ�ж�ǰ��������С,���ϴ�������max,�ٽ�max����������Ƚ��ҵ�������
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int max = 0;
	printf("��������������");
	scanf("%d,%d,%d", &a, &b, &c);
	if (a > b)
	{
		max = a;
	}
	else max = b;
	if (max > c)
	{
		printf("���ֵΪ%d", max);
	}
	else
		printf("���ֵΪ%d", c);
	return 0;
}

//������
//������Ŀ������
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int max = 0;
	printf("��������������");
	scanf("%d,%d,%d", &a, &b, &c);
	max = a >= b ? a : b;
	max = max >= c ? max : c;
	printf("���ֵΪ%d", max);

	return 0;
}

////�жθ������������ֵ
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
	printf("���ֵΪ%d", max);
	return 0;
}


//�жθ������������ֵ
//������ľ������
int main()
{
	int i = 0;
	int max = 0;
	int arr[] = { 1, 2, 3, 9, 6, 7, 8 };
	
	for (i = 0; i < 7; i++)
	{
		max=(arr[i] >= max ? arr[i] : max);

	}
	printf("���ֵΪ%d", max);
	return 0;
}


//˵������ָ��Ͷ�����Ҳ����ʵ��
