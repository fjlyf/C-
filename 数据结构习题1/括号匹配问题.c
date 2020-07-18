#include"stack.h"

//括号匹配问题
bool isValid(char *s)
{
	LinkStack st;
	if (s == NULL)
		return false;
	if (*s == '\0')
		return true;
	LinkStackInit(&st);
	while (*s != '\0')
	{
		if (*s == '{' || *s == '[' || *s == '(')
			LinkStackPush(&st, *s);
		else
		{
			if (LinkStackEmpty(&st))
				printf("字符串不匹配，括号不合法！\n");
				
			char top = LinkStackTop(&st);
			if ((*s == '}'&&top != '{') || (*s == ']'&&top != '[') || (*s == ')'&&top != '('))
				printf("字符串不匹配，括号不合法！\n");
				
			LinkStackPop(&st);
		}
		s++;
	}
	if (LinkStackEmpty(&st))
		printf("字符串匹配，括号合法！\n");
	else
		printf("字符串不匹配，括号不合法！\n");
	LinkStackDestory(&st);
	return 0;
}

int main()
{
	char *s1="{[()]}";   //匹配
	char *s2 = "{[()}";  //左括号多于右括号
	char *s3 = "[]}";    //右括号多于左括号
	char *s4 = "{[(";    //只有左括号
	char *s5 = ")]}";    //只有右括号
	isValid(s1);
	isValid(s2);
	isValid(s3);
	isValid(s4);
	isValid(s5);

	return 0;
}
