#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"

void menu()
{
	printf("********************************\n");
	printf("      欢迎来到扫雷小游戏        \n");
	printf("       1.play   0.return        \n");
	printf("********************************\n");
}

void game()
{
	//存放布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//存放排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化扫雷棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//布置雷
	SetMine(mine,ROW,COL);
	//打印棋盘
	DisplayBoard(show,ROW,COL);
	//扫雷
	FindMine(mine,show,ROW,COL);

}


int main()
{
	int enter = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &enter);
		switch (enter)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏,改日再战!\n");
			break;
		default:
			printf("小笨蛋选择错误了!\n");
			break;
		}
	} while (enter);
	return 0;
}
