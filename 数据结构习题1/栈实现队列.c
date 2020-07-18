#include"stack.h"

typedef struct
{
	LinkStack instack;
	LinkStack outstack;
}MyQueue;

//创建队列
MyQueue* myQueueCreate()
{
	MyQueue *pq = (MyQueue*)malloc(sizeof(MyQueue));
	LinkStackInit(&(pq->instack));
	LinkStackInit(&(pq->outstack));
	return pq;
}

//入队
void myQueuePush(MyQueue *pq, int x)
{
	LinkStackPush(&(pq->instack), x);
}

//出队
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

//取队头元素
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

//判空
bool myQueueEmpty(MyQueue *pq)
{
	return LinkStackEmpty(&(pq->instack)) && LinkStackEmpty(&(pq->outstack));
}

//释放
void myQueueFree(MyQueue *pq)
{
	LinkStackDestory(&(pq->instack));
	LinkStackDestory(&(pq->outstack));
	free(pq);
}

