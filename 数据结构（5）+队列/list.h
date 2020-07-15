#ifndef _LIST_H_
#define _LIST_H_

#include"common.h"
////////////////////////////////////////////////////////
//带头的双循环链表
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
//双循环链表函数接口声明
static DCListNode* _BUYdcnode(ElemType x);//购买
void DCListInit(DCList *plist);//初始化
void DCListPushBack(DCList *plist, ElemType x);//尾插
void DCListPushFront(DCList *plist, ElemType x);//头插
void DCListPopBack(DCList *plist);//尾删
void DCListPopFront(DCList *plist);//头删
void DCListShow(DCList *plist);//查看
DCListNode* DCListFind(DCList *plist, ElemType key);//按值查找
size_t DCListLength(DCList *plist);//求长度
void DCListClear(DCList *plist);//清除
void DCListDelectVal(DCList *plist, ElemType key);//按值删除
void DCListInsertVal(DCList *plist, ElemType key);//按值插入
void DCListSort(DCList *plist);//排序
void DCListReverse(DCList *plist);//逆置
void DCListDestroy(DCList *plist);//摧毁

//////////////////////////////////////////////////////////////
//双循环链表函数接口实现
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
		printf("链表为空，不能删除\n");
	plist->head->prev = p->prev;
	p->prev->next = plist->head;
	free(p);

}

void DCListPopFront(DCList *plist)
{
	assert(plist != NULL);
	DCListNode *p = plist->head->next;
	if (p == plist->head)
		printf("链表为空，不能删除\n");
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
		printf("链表为空，不能删除\n");
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

	//断开链表
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
	
	//断开链表
	p->next = plist->head;
	plist->head->prev = p;

	while (q != plist->head)
	{
		p = q;
		q = q->next;

		//寻找p的插入位置
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
//无头单链表
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