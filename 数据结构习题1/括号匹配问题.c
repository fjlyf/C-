#include"stack.h"

//����ƥ������
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
				printf("�ַ�����ƥ�䣬���Ų��Ϸ���\n");
				
			char top = LinkStackTop(&st);
			if ((*s == '}'&&top != '{') || (*s == ']'&&top != '[') || (*s == ')'&&top != '('))
				printf("�ַ�����ƥ�䣬���Ų��Ϸ���\n");
				
			LinkStackPop(&st);
		}
		s++;
	}
	if (LinkStackEmpty(&st))
		printf("�ַ���ƥ�䣬���źϷ���\n");
	else
		printf("�ַ�����ƥ�䣬���Ų��Ϸ���\n");
	LinkStackDestory(&st);
	return 0;
}

int main()
{
	char *s1="{[()]}";   //ƥ��
	char *s2 = "{[()}";  //�����Ŷ���������
	char *s3 = "[]}";    //�����Ŷ���������
	char *s4 = "{[(";    //ֻ��������
	char *s5 = ")]}";    //ֻ��������
	isValid(s1);
	isValid(s2);
	isValid(s3);
	isValid(s4);
	isValid(s5);

	return 0;
}
