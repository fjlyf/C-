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
//单链表函数接口声明
static SListNode* _Buynode(ElemType x);
void SListInit(SList *plist);//初始化
void SListPushBack(SList *plist,ElemType x);//尾插
void SListPushFront(SList *plist, ElemType x);//头插
void SListInsertVal(SList *plist, ElemType x);//按值插入
void SListShow(SList *plist);//查看
void SListPopBack(SList *plist);//尾部删除
void SListPopFront(SList *plist);//头部删除
SListNode* SListFindVal(SList *plist, ElemType key);//按值查找
void SListDelectVal(SList *plist, ElemType key);//按值删除
void SListReverse(SList *plist);//逆置

void SListSort(SList *plist);//排序
size_t SListLength(SList *plist);//长度
void SListClear(SList *plist);//清除
void SListDestroy(SList *plist);//摧毁
////////////////////////////////////////////////////////////
//单链表函数接口实现

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

	//插入的节点为第一个节点
	if (plist->head = NULL)
	{
		plist->head = s;
		return;
	}
	//时间复杂度为O（n）
	SListNode *p = plist->head;
	while (p->next != NULL)
		p = p->next;
	p->next = s;
}

void SListPushFront(SList *plist, ElemType x)
{
	assert(plist != NULL);

	SListNode *s = _Buynode(x);
	//时间复杂度为O(1)
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
	if (prev == NULL)//需要进行头插
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
	//链表只有一个节点
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
		printf("要删除的节点不存在.\n");
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
	//断开第一个节点
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

	plist->head->next = NULL;//断开链表

	t = plist->head;
	while (p != NULL)
	{
		q = p->next;
		//把p节点摘除进行按值插入，升序
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
//定义链表节点
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}ListNode;

typedef ListNode* List;

//单链表带头结点
void ListInit(List *plist)   //ListNode **plist
{
	*plist = (ListNode*)malloc(sizeof(ListNode));
	assert(*plist!=NULL);
	(*plist)->next = NULL;
}


//尾插法创建单链表
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
		//连接节点
		p->next = s;
		p = s;
	}
}

//头插法创建单链表
void ListCreate_Head(List *plist)
{
	assert(*plist != NULL);

	for (int i = 1; i <= 10; ++i)
	{
		ListNode *s = (ListNode*)malloc(sizeof(ListNode));
		assert(s != NULL);
		s->data = i;
		//连接节点
		s->next = (*plist)->next;
		(*plist)->next = s;
	}
}

//显示链表
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
//单链表不带头结点
void ListInit(List *plist)   //ListNode **plist
{
	*plist = NULL;
}

//尾插法创建单链表
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
		//连接节点
		p->next = s;
		p = s;
	}
}

//头插法创建单链表
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
		//连接节点
		s->next = (*plist);
		(*plist) = s;
	}
}

//显示链表
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