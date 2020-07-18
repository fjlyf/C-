#include"stack.h"

typedef struct
{
	LinkStack instack;
	LinkStack outstack;
}MyQueue;

//��������
MyQueue* myQueueCreate()
{
	MyQueue *pq = (MyQueue*)malloc(sizeof(MyQueue));
	LinkStackInit(&(pq->instack));
	LinkStackInit(&(pq->outstack));
	return pq;
}

//���
void myQueuePush(MyQueue *pq, int x)
{
	LinkStackPush(&(pq->instack), x);
}

//����
int myQueuePop(MyQueue *pq)
{
	if (LinkStackEmpty(&(pq->outstack)))
	{
		while (!LinkStackEmpty(&(pq->instack)))
		{
			LinkStackPush(&(pq->outstack), LinkStackTop(&(pq->instack)));
			LinkStackPop(&(pq->instack));
		}
	}
	ElemType val = LinkStackTop(&(pq->outstack));
	LinkStackPop(&(pq->outstack));
	return val;
}

//ȡ��ͷԪ��
int myQueueFront(MyQueue *pq)
{
	if (LinkStackEmpty(&(pq->outstack)))
	{
		while (!LinkStackEmpty(&(pq->instack)))
		{
			LinkStackPush(&(pq->outstack), LinkStackTop(&(pq->instack)));
			LinkStackPop(&(pq->instack));
		}
	}
	ElemType val = LinkStackTop(&(pq->outstack));
	return val;
}

//�п�
bool myQueueEmpty(MyQueue *pq)
{
	return LinkStackEmpty(&(pq->instack)) && LinkStackEmpty(&(pq->outstack));
}

//�ͷ�
void myQueueFree(MyQueue *pq)
{
	LinkStackDestory(&(pq->instack));
	LinkStackDestory(&(pq->outstack));
	free(pq);
}

