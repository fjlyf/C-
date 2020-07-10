#ifndef _LIST_H_
#define _LIST_H_

#include"common.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef struct SList
{
	SListNode *head;
}SList;

////////////////////////////////////////////////////////////
//���������ӿ�����
static SListNode* _Buynode(ElemType x);
void SListInit(SList *plist);//��ʼ��
void SListPushBack(SList *plist,ElemType x);//β��
void SListPushFront(SList *plist, ElemType x);//ͷ��
void SListInsertVal(SList *plist, ElemType x);//��ֵ����
void SListShow(SList *plist);//�鿴
void SListPopBack(SList *plist);//β��ɾ��
void SListPopFront(SList *plist);//ͷ��ɾ��
SListNode* SListFindVal(SList *plist, ElemType key);//��ֵ����
void SListDelectVal(SList *plist, ElemType key);//��ֵɾ��
void SListReverse(SList *plist);//����

void SListSort(SList *plist);//����
size_t SListLength(SList *plist);//����
void SListClear(SList *plist);//���
void SListDestroy(SList *plist);//�ݻ�
////////////////////////////////////////////////////////////
//���������ӿ�ʵ��

static SListNode* _Buynode(ElemType x)
{
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}

void SListInit(SList *plist)
{
	plist->head = NULL;
}

void SListPushBack(SList *plist, ElemType x)
{
	assert(plist!= NULL);
	
	SListNode *s = _Buynode(x);

	//����Ľڵ�Ϊ��һ���ڵ�
	if (plist->head = NULL)
	{
		plist->head = s;
		return;
	}
	//ʱ�临�Ӷ�ΪO��n��
	SListNode *p = plist->head;
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}

void SListPushFront(SList *plist, ElemType x)
{
	assert(plist != NULL);

	SListNode *s = _Buynode(x);
	//ʱ�临�Ӷ�ΪO(1)
	s->next = plist->head;
	plist->head = s;
}

void SListInsertVal(SList *plist, ElemType x)
{
	assert(plist != NULL);
	SListNode *prev = NULL;
	SListNode *p = plist->head;
	SListNode *s = _Buynode(x);
	while (p != NULL&&x > p->data)
	{
		prev = p;
		p = p->next;
	}
	if (prev == NULL)//��Ҫ����ͷ��
	{
		s->next = p;
		prev->next = s;
	}
	else
	{
		s->next = prev->next;
		prev->next = s;
	}
}

void SListShow(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("Over.\n");
}

void SListPopBack(SList *plist)
{
	assert(plist != NULL);
	SListNode *p=NULL,*prev=NULL;
	if (plist->head = NULL)
		return;
	p = plist->head;
	//����ֻ��һ���ڵ�
	if (p->next = NULL)
		plist->head = NULL;
	else
	{
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		prev->next = NULL;
	}
	free(p);
}

void SListPopFront(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	if (plist->head = NULL)
		return;

	plist->head = p->next;
	free(p);
}

SListNode* SListFindVal(SList *plist,ElemType key)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	while (p != NULL&&p->data == key)
		p = p->next;
	return p;
}

void SListDelectVal(SList *plist, ElemType key)
{
	assert(plist != NULL);
	SListNode *prev=NULL;
	SListNode *p = SListFindVal(plist, key);
	if (p == NULL)
	{
		printf("Ҫɾ���Ľڵ㲻����.\n");
		return;
	}

	if (p = plist->head)
		plist->head = p->next;
	else
	{
		prev = p->next;
		while (prev->next != p)
			prev = prev->next;
		prev->next = p->next;
	}
	free(p);
}

void SListReverse(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head->next;
	SListNode *q;
	if (p->next == NULL)
		return;
	//�Ͽ���һ���ڵ�
	plist->head->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = plist->head;
		plist->head = p;
		p = q;
	}
}

void SListSort(SList *plist)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	SListNode *q,*t,*prev=NULL;

	plist->head->next = NULL;//�Ͽ�����

	t = plist->head;
	while (p != NULL)
	{
		q = p->next;
		//��p�ڵ�ժ�����а�ֵ���룬����
		while (t!=NULL&&p->data > t->data)
		{
			prev = t;
			t = t->next;
		}
		if (prev == NULL)
		{
			p->next = plist->head;
			plist->head = p;
		}
		else
		{
			p->next = prev->next;
			prev->next = p;
		}
		p = q;
		t = plist->head;
	}
}

size_t SListLength(SList *plist)
{
	assert(plist != NULL);
	size_t len = 0;
	SListNode *p = plist->head;

	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

void SListClear(SList *plist)
{
	assert(plist != NULL);
	SListNode *p=plist->head;

	while (p != NULL)
	{
		plist->head = p->next;
		free(p);
		p = plist->head;
	}
}

void SListDestroy(SList *plist)
{
	SListClear(plist);
	plist->head = NULL;
}

/*
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
	assert(plist != NULL);

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
	assert(*plist != NULL);

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
	ListNode *p = plist->next;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}*/

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