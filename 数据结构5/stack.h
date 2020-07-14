#ifndef _STACK_H_
#define _STACK_H_

#include"common.h"

/////////////////////////////////////////////////////////
//˳��ջ

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE     3

typedef struct SeqStack
{
	ElemType *base;
	size_t   capacity;
	int       top;
}SeqStack;

/////////////////////////////////////////////////////////
//�����ӿ�����
static bool _StackInc(SeqStack *pst);//����
void SeqStackInit(SeqStack *pst);//��ʼ��
bool SeqStackIsFull(SeqStack *pst);//����
bool SeqStackIsEmpty(SeqStack *pst);//�п�
void SeqStackPush(SeqStack *pst,ElemType x);//��ջ
void SeqStackPop(SeqStack *pst);//��ջ
ElemType SeqStackTop(SeqStack *pst);//ȡջ��Ԫ��
void SeqStackPrint(SeqStack *pst);//��ӡ
void SeqStackDestory(SeqStack *pst);//�ݻ�

/////////////////////////////////////////////////////////
//�����ӿ�ʵ��

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
		printf("ջ�ռ�������%d������ջ.\n",x);
		return;
	}
	pst->base[pst->top++] = x;
}

void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿգ����ܳ�ջ.\n");
		return;
	}
	pst->top--;
}

ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿգ�����ȡջ��Ԫ��.\n");
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
//��ջ
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
//�����ӿ�����
void LinkStackInit(LinkStack *pst);//��ʼ��
void LinkStackPush(LinkStack *pst,ElemType x);//��ջ
void LinkStackPop(LinkStack *pst);//��ջ
ElemType LinkStackTop(LinkStack *pst);//ȡջ��Ԫ��
void LinkStackPrint(LinkStack *pst);//��ӡ
void LinkStackDestory(LinkStack *pst);//�ݻ�



/////////////////////////////////////////////////////////
//�����ӿ�ʵ��
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
		printf("ջ�ѿգ����ܳ�ջ.\n");
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