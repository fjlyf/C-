#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//ģ���û���¼����
//˼·����������ѭ���ж������Ƿ���ȷ�������ȷ��½�ɹ������β���ȷ��½ʧ���˳�����
//����strcmp()�����Ƚ������ַ�����С,string compare��������==�Ƚϣ�strcmp��������string��

#include <string.h>
int main()
{
	int i = 0;
	char password[20] = { 0 };//�����ַ������룬��ʼ��
	for (i = 0; i < 3; i++)
	{
		printf("���������룺");
		scanf("%s", password);

		if (0 == strcmp(password, "020107"))
		{
			printf("��½�ɹ�\n");
			break;
		}
		else
		{
			printf("�������\n");
		}
	}

	if (i >= 3)
	{
		printf("���볬�����Σ��˳�����\n");
	}
	return 0;
}
