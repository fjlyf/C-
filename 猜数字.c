#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//��Ϸ��ʼ����
void menu()
{
	printf("********************************\n");
	printf("      ��ӭ����������Ϸ����      \n");
	printf("       1.play   2.return        \n");
	printf("********************************\n");
}

//��������һ���������ʹ��rand���������ķ���ֵ��0-32767֮����������ȱ�����Թ̶���������Ϊ���ӣ��������������
//rand��������ǰ��Ҫ�ȵ���srand����ʹ������Ϊ������ӱ�֤ÿ��ִ�г��ֲ�һ���������
//rand���������������,rand(),����stdlib��
//srand��������ʼ��������ӣ�srand��unsigned��time(null)������stdlib��,��ʹ��randǰ����һ�μ���
//time����������һ��ʱ���,����time��
//ʱ�����ָ���Ǽ�����ڵ���time����ʱ��ʱ����������ʼʱ�䣨1970.1.1.0��0��0��֮��Ĳ�ֵ����λΪ����

void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;//����100���������
	//������
	printf("��Ϸ���Ͽ�ʼ������׼��!\n");
	printf("       ready go        \n");
	while (1)
	{
		printf("������֣�\n");
		scanf("%d",&guess);
		if (guess > ret)
		{
			printf("�´���!\n");
		}
		else if (guess < ret)
		{
			printf("��С��!\n");
		}
		else
		{
			printf("��ϲ��¶���!\n");
			break;
		}
	}
}

int main()
{
	int enter = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d",&enter);
		switch (enter)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�˳���Ϸ,������ս!\n");
			break;
		default:
			printf("С����ѡ�������!\n");
			break;
		}
	} while (enter !=2);
	return 0;
}
