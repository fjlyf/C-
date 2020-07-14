#ifndef _LIST_H_
#define _LIST_H_

#include"common.h"
////////////////////////////////////////////////////////
//��ͷ��˫ѭ������
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;

typedef struct DCList
{
	DCListNode *head;
}DCList;

////////////////////////////////////////////////////////////
//˫ѭ���������ӿ�����
static DCListNode* _BUYdcnode(ElemType x);//����
void DCListInit(DCList *plist);//��ʼ��
void DCListPushBack(DCList *plist, ElemType x);//β��
void DCListPushFront(DCList *plist, ElemType x);//ͷ��
void DCListPopBack(DCList *plist);//βɾ
void DCListPopFront(DCList *plist);//ͷɾ
void DCListShow(DCList *plist);//�鿴
DCListNode* DCListFind(DCList *plist, ElemType key);//��ֵ����
size_t DCListLength(DCList *plist);//�󳤶�
void DCListClear(DCList *plist);//���
void DCListDelectVal(DCList *plist, ElemType key);//��ֵɾ��
void DCListInsertVal(DCList *plist, ElemType key);//��ֵ����
void DCListSort(DCList *plist);//����
void DCListReverse(DCList *plist);//����
void DCListDestroy(DCList *plist);//�ݻ�

//////////////////////////////////////////////////////////////
//˫ѭ���������ӿ�ʵ��
static DCListNode* _BUYdcnode(ElemType x)
{
	DCListNode *s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}

void DCListInit(DCList *plist)
{
	assert(plist != NULL);
	plist->head = _BUYdcnode(0);
}

void DCListPushBack(DCList *plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *s = _BUYdcnode(x);
	s->prev = plist->head->prev;
	s->prev->next = s;
	s->next = plist->head;
	plist->head->prev = s;
}

void DCListPushFront(DCList *plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *s = _BUYdcnode(x);

	s->next = plist->head->next;
	s->prev = plist->head;
	plist->head->next = s;
	s->next->prev = s;

}

void DCListPopBack(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->prev;
	if (p == plist->head)
		printf("����Ϊ�գ�����ɾ��\n");
	plist->head->prev = p->prev;
	p->prev->next = plist->head;
	free(p);

}

void DCListPopFront(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	if (p == plist->head)
		printf("����Ϊ�գ�����ɾ��\n");
	plist->head->prev = p->next;
	p->prev->next = plist->head;
	free(p);
}

void DCListShow(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("Over.\n");
}

DCListNode* DCListFind(DCList *plist, ElemType key)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p!=plist->head&&p->data != key)
		p = p->next;
	if (p != plist->head)
		return p;
	return NULL;
}

size_t DCListLength(DCList *plist)
{
	assert(plist != NULL);
	size_t len = 0;
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		len++;
		p = p->next;
	}
	return len;
}

void DCListDelectVal(DCList *plist, ElemType key)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	if (p == NULL)
		printf("����Ϊ�գ�����ɾ��\n");
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void DCListInsertVal(DCList *plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head&&p->data < x)
		p = p->next;

	DCListNode *s = _BUYdcnode(x);
	s->next = p;
	s->prev = p->prev;
	p->prev->next = s;
	p->prev = s;
}

void DCListReverse(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	DCListNode *q = p->next;

	//�Ͽ�����
	p->next = plist->head;
	plist->head->prev = p;
	while (q != plist->head)
	{
		p = q;
		q = q->next;

		p->next = plist->head->next;
		p->prev = plist->head;
		p->next->prev = p;
		p->prev->next = p;//plist->head->next=p
	}

}

void DCListSort(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	DCListNode *q = p->next;
	
	//�Ͽ�����
	p->next = plist->head;
	plist->head->prev = p;

	while (q != plist->head)
	{
		p = q;
		q = q->next;

		//Ѱ��p�Ĳ���λ��
		DCListNode *t = plist->head->next;
		while (t != plist->head &&t->data < p->data)
			t - t->next;

		p->next = t;
		p->prev = t->prev;
		p->next->prev = p;
		p->prev->next = p;

		p = q;
	}
}

void DCListClear(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	while (p != plist->head)
	{
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);
		p = plist->head->next;
	}
}

void DCListDestroy(DCList *plist)
{
	DCListClear(plist);
	free(plist->head);
	plist->head = NULL;
}

/////////////////////////////////////////////////////////
//��ͷ������
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