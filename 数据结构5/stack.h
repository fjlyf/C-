#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"

/////////////////////////////////////////////////////////
//顺序栈

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE     3

typedef struct SeqStack
{
	ElemType *base;
	size_t   capacity;
	int       top;
}SeqStack;

/////////////////////////////////////////////////////////
//函数接口声明
static bool _StackInc(SeqStack *pst);//扩容
void SeqStackInit(SeqStack *pst);//初始化
bool SeqStackIsFull(SeqStack *pst);//判满
bool SeqStackIsEmpty(SeqStack *pst);//判空
void SeqStackPush(SeqStack *pst,ElemType x);//入栈
void SeqStackPop(SeqStack *pst);//出栈
ElemType SeqStackTop(SeqStack *pst);//取栈顶元素
void SeqStackPrint(SeqStack *pst);//打印
void SeqStackDestory(SeqStack *pst);//摧毁

/////////////////////////////////////////////////////////
//函数接口实现

static bool _StackInc(SeqStack *pst)
{
	ElemType *new_base = (ElemType*)realloc(pst->base, sizeof(ElemType)*(pst->capacity+SEQ_STACK_INC_SIZE));
	if (new_base == NULL)
		return false;
	pst->base = new_base;
	pst->capacity += SEQ_STACK_INC_SIZE;
	return true;
}

void SeqStackInit(SeqStack *pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base != NULL);
	pst->capacity = SEQ_STACK_DEFAULT_SIZE;
	pst->top = 0;  //-1
}

bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}

bool SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}

void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst) && !_StackInc(pst))
	{
		printf("栈空间已满，%d不能入栈.\n",x);
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	pst->top--;
}

ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能取栈顶元素.\n");
		return;
	}
	return pst->base[pst->top - 1];
}

void SeqStackPrint(SeqStack *pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0;--i)
		printf("%d\n",pst->base[i]);
	printf("\n");

}

void SeqStackDestory(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->top = 0;
}

/////////////////////////////////////////////////////////
//链栈
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *link;
}LinkStackNode;

typedef struct LinkStack
{
	LinkStackNode *top;
}LinkStack;

//////////////////////////////////////////////////////////
//函数接口声明
void LinkStackInit(LinkStack *pst);//初始化
void LinkStackPush(LinkStack *pst,ElemType x);//入栈
void LinkStackPop(LinkStack *pst);//出栈
ElemType LinkStackTop(LinkStack *pst);//取栈顶元素
void LinkStackPrint(LinkStack *pst);//打印
void LinkStackDestory(LinkStack *pst);//摧毁



/////////////////////////////////////////////////////////
//函数接口实现
void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	pst->top = NULL;
}

void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;
	node->link = pst->top;
	pst->top = node;
}

void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	pst->top = p->link;
	free(p);
}

ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL);
	if (pst->top == NULL)
	{
		printf("栈已空，不能出栈.\n");
		return;
	}
	return pst->top->data;
}

void LinkStackPrint(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = pst->top;
	while (p != NULL)
	{
		printf("%d\n",p->data);
		p = p->link;
	}
	printf("\n");
}

void LinkStackDestory(LinkStack *pst)
{
	assert(pst != NULL);
	while (pst->top != NULL)
	{
		LinkStackNode *p = pst->top;
		pst->top = p->link;
		free(p);
	}
}

#endif /*_STACK_H_*/