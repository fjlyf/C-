#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

////�ж�һ�����Ƿ�Ϊ����
int main()
{
	int i=0;
	printf("���������֣�");
	scanf("%d", &i);
	if (i % 2 == 1)
		printf("%dΪ����", i);
	else
		printf("%dΪż��", i);
	return 0;
}

//���1-100֮�������
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

//��ϰ��ӡ0-9��whileѭ��
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

//������������С���
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int i = 0;
	printf("�����룺");
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

��ӡ1-100֮������3�ı���������
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

////���������������������������Լ��
int main()
{
	//շת�����
	int a = 28;
	int b = 70;
	int c = 0;
	while (c=a%b)
	{
		a = b;
		b = c;
	}
	printf("���Լ��Ϊ%d", b);
	return 0;
}


//��ӡ1000��2000��֮�������
int main()
{
	int year = 1000;
	int count = 0;//����
	while (year <= 2000)
	{
		//�����жϹ���
		//1.�ܱ�4���������ܱ�100����
		//2.�ܱ�400����
		if (((year % 4 == 0) && (year % 100 == 0)) || (year % 400 == 0))//&&�߼��룬||�߼���
		{
			printf("%d\n", year);
			count++;
		}
			year++;
	}
	printf("\ncount=%d\n", count);
	return 0;
}


//��ӡ100��200֮�������
int main()
{
	//�ж�i�Ƿ�Ϊ����
	//����ֻ�ܱ������1����
	//����2->i-1֮������֣��ò����������Գ�1�������������˵��i�������������2->i-1֮��û��һ��������i����˵��i������
	int i = 100;
	int count = 0;
	while (i <= 200)
	{
		int j = 2;
		while (j < i)
		{
			//��j�Գ�i
			if (i%j == 0)
			{
				//��������
				break;
			}
			j++;
		}
		if (i == j)
		{
			//������
			printf("%d\n", i);
			count++;
		}
		i++;
	}
	printf("\ncount=%d\n", count);
	return 0;
}