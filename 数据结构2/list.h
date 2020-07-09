#ifndef _LIST_H_
#define _LIST_H_

#include"common.h"

//��������ڵ�
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

//�������ͷ���
void ListInit(List *plist)   //ListNode **plist
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist!=NULL);
	(*plist)->next = NULL;
}


//β�巨����������
void ListCreate_Tail(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;

	ListNode *p = *plist;
	for (int i = 1; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		//���ӽڵ�
		p->next = s;
		p = s;
	}
}

//ͷ�巨����������
void ListCreate_Head(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->next = NULL;

	for (int i = 1; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		//���ӽڵ�
		s->next = (*plist)->next;
		(*plist)->next = s;
	}
	
}

//��ʾ����
void ListShow(List plist)
{
	ListNode *p = plist;

	p = p->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}

/*
//��������ͷ���
void ListInit(List *plist)   //ListNode **plist
{
	*plist = NULL;
}

//β�巨����������
void ListCreate_Tail(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist!=NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	ListNode *p = *plist;
	for (int i = 2; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		s->next = NULL;
		//���ӽڵ�
		p->next = s;
		p = s;
	}
}

//ͷ�巨����������
void ListCreate_Head(List *plist)
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist != NULL);
	(*plist)->data = 1;
	(*plist)->next = NULL;

	for (int i = 2; i < 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s!=NULL);
		s->data = i;
		//���ӽڵ�
		s->next = (*plist);
		(*plist) = s;
	}
}

//��ʾ����
void ListShow(List plist)
{
	ListNode *p = plist;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
*/

#endif /*_LIST_H_*/