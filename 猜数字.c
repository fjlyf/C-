#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//游戏开始界面
void menu()
{
	printf("********************************\n");
	printf("      欢迎来到数字游戏世界      \n");
	printf("       1.play   2.return        \n");
	printf("********************************\n");
}

//电脑生成一个随机数，使用rand函数，它的返回值在0-32767之间的随机数，缺点是以固定的数字作为种子，返回数不够随机
//rand函数调用前需要先调用srand函数使得种子为随机种子保证每次执行出现不一样的随机数
//rand函数：产生随机数,rand(),属于stdlib库
//srand函数：初始化随机种子，srand（unsigned）time(null)，属于stdlib库,在使用rand前调用一次即可
//time函数：返回一个时间戳,属于time库
//时间戳：指的是计算机在调用time函数时的时间与计算机起始时间（1970.1.1.0：0：0）之间的差值，单位为毫秒

void game()
{
	int guess = 0;
	int ret = rand() % 100 + 1;//产生100以内随机数
	//猜数字
	printf("游戏马上开始请做好准备!\n");
	printf("       ready go        \n");
	while (1)
	{
		printf("请猜数字：\n");
		scanf("%d",&guess);
		if (guess > ret)
		{
			printf("猜大了!\n");
		}
		else if (guess < ret)
		{
			printf("猜小了!\n");
		}
		else
		{
			printf("恭喜你猜对了!\n");
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
		printf("请选择：\n");
		scanf("%d",&enter);
		switch (enter)
		{
		case 1:
			game();
			break;
		case 2:
			printf("退出游戏,改日再战!\n");
			break;
		default:
			printf("小笨蛋选择错误了!\n");
			break;
		}
	} while (enter !=2);
	return 0;
}
