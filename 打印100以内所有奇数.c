#include <stdio.h>
//方法一
int main()
{
	int i = 1;
	while (i <= 100)
	{
		if (i % 2 == 1)
			printf("%d\n", i);
		i++;
	}
	return 0;
}
//方法二优化
int main()
{
	int i = 1;
	while (i <= 100)
	{
		printf("%d\n", i);
		i = i + 2;
	}
	return 0;
}
//方法三
int main()
{
	int i = 1;
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 1)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
