#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void menu()
{
	printf("********************************\n");
	printf("      ��ӭ����ɨ��С��Ϸ        \n");
	printf("       1.play   0.return        \n");
	printf("********************************\n");
}

void game()
{
	//��Ų��úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//����Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��ɨ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//������
	SetMine(mine,ROW,COL);
	//��ӡ����
	DisplayBoard(show,ROW,COL);
	//ɨ��
	FindMine(mine,show,ROW,COL);

}


int main()
{
	int enter = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &enter);
		switch (enter)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ,������ս!\n");
			break;
		default:
			printf("С����ѡ�������!\n");
			break;
		}
	} while (enter);
	return 0;
}
