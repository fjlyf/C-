#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//模拟用户登录场景
//思路：进行三次循环判断密码是否正确，如果正确登陆成功，三次不正确登陆失败退出程序
//运用strcmp()函数比较两个字符串大小,string compare；不能用==比较；strcmp函数属于string库

#include <string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };//定义字符串密码，初始化
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：");
		scanf("%s", password);

		if (0 == strcmp(password, "020107"))
		{
			printf("登陆成功\n");
			break;
		}
		else
		{
			printf("密码错误\n");
		}
	}

	if (i >= 3)
	{
		printf("输入超过三次，退出程序\n");
	}
	return 0;
}
