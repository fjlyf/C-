#ifndef _QUEUE_H
#define _QUEUE_H

#include"common.h"
//////////////////////////////////////////////////////
//顺序队列
#define SEQ_QUEUE_DEFAULT_SIZE 6
#define SEQ_QUEUE_INC_SIZE     3

typedef struct SeqQueue
{
	ElemType *base;
	int   capacity;
	int      front;
	int      rear;
}SeqQueue;

//////////////////////////////////////////////////////
//函数接口声明

void SeqQueueInit(SeqQueue *psq);//初始化
static bool _SeqQueueInc(SeqQueue *psq);//扩容
bool SeqQueueIsFull(SeqQueue *psq);//判满
bool SeqQueueIsEmpty(SeqQueue *psq);//判空
void SeqQueueEnque(SeqQueue *psq, ElemType x);//入队（不扩容）
void SeqQueueEnque1(SeqQueue *psq,ElemType x);//入队（空间满时扩容）
void SeqQueueDeque(SeqQueue *psq);//出队
ElemType SeqQueueFront(SeqQueue *psq);//取队头元素
void SeqQueuePrint(SeqQueue *psq);//打印

//////////////////////////////////////////////////////
//函数接口实现
void SeqQueueInit(SeqQueue *psq)
{
	psq->base = (ElemType*)malloc(sizeof(ElemType)*SEQ_QUEUE_DEFAULT_SIZE);
	assert(psq != NULL);
	psq->capacity = SEQ_QUEUE_DEFAULT_SIZE;
	psq->front = psq->rear = 0;
}

static bool _SeqQueueInc(SeqQueue *psq)
{
	ElemType *new_base = (ElemType*)realloc(psq->base, sizeof(ElemType)*(psq->capacity + SEQ_QUEUE_INC_SIZE));
	if (new_base == NULL)
		return false;
	psq->base = new_base;
	psq->capacity += SEQ_QUEUE_INC_SIZE;
	return true;
}

bool SeqQueueIsFull(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->rear >= psq->capacity;
}

bool SeqQueueIsEmpty(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->front==psq->rear;
}

void SeqQueueEnque(SeqQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (SeqQueueIsFull(psq))
	{
		printf("队列空间已满，%d不能入队.\n", x);
		return;
	}
	psq->base[psq->rear++] = x;
}


void SeqQueueDeque(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("队列已空，不能出队.\n");
		return;
	}
	psq->front++;
}

ElemType SeqQueueFront(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("队列已空，不能取队头元素.\n");
		return;
	}
	return psq->base[psq->front];
}

void SeqQueuePrint(SeqQueue *psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i < psq->rear; ++i)
		printf("%d ",psq->base[i]);
	printf("\n");
}

//////////////////////////////////////////////////////
//循环队列
#define CIRCLE_QUEUE_DEFAULT_SIZE 8
#define CIRCLE_QUEUE_INC_SIZE     4

typedef struct CircleQueue
{
	ElemType *base;
	int   capacity;
	int      front;
	int      rear;
}CircleQueue;

/////////////////////////////////////////////////////
//函数接口声明
void CircleQueueInit(CircleQueue *psq);//初始化
static bool _CircleQueueInc(CircleQueue *psq);//扩容
bool CircleQueueIsFull(CircleQueue *psq);//判满
bool CircleQueueIsEmpty(CircleQueue *psq);//判空
void CircleQueueEnque(CircleQueue *psq, ElemType x);//入队
void CircleQueueDeque(CircleQueue *psq);//出队
ElemType CircleQueueFront(CircleQueue *psq);//取队头元素
void CircleQueuePrint(CircleQueue *psq);//打印
//////////////////////////////////////////////////////
//函数接口实现
void CircleQueueInit(CircleQueue *psq)
{
	psq->base = (ElemType*)malloc(sizeof(ElemType)*(CIRCLE_QUEUE_DEFAULT_SIZE+1));
	assert(psq != NULL);
	psq->capacity = CIRCLE_QUEUE_DEFAULT_SIZE+1;
	psq->front = psq->rear = 0;
}

static bool _CircleQueueInc(CircleQueue *psq)
{
	ElemType *new_base = (ElemType*)malloc(psq->base, sizeof(ElemType)*(psq->capacity + SEQ_QUEUE_INC_SIZE));
	if (new_base == NULL)
		return false;

	psq->front = psq->front % (psq->capacity + SEQ_QUEUE_INC_SIZE);
	psq->rear = (psq->rear + psq->capacity) % (psq->capacity + SEQ_QUEUE_INC_SIZE);
	psq->base = new_base;
	psq->capacity += SEQ_QUEUE_INC_SIZE;
	return true;
}

bool CircleQueueIsFull(CircleQueue *psq)
{
	assert(psq != NULL);
	return ((psq->rear + 1) % psq->capacity) == psq->front;
}

bool CircleQueueIsEmpty(CircleQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

void CircleQueueEnque(CircleQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (CircleQueueIsFull(psq) && _CircleQueueInc(psq))
	{
		printf("循环队列空间已满，%d不能入队.\n", x);
		return;
	}
	psq->base[psq->rear] = x;
	psq->rear = (psq->rear + 1) % psq->capacity;
}

void CircleQueueDeque(CircleQueue *psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("循环队列已空，不能出队.\n");
		return;
	}
	psq->front=(psq->front+1)%psq->capacity;
}

ElemType CircleQueueFront(CircleQueue *psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("循环队列已空，不能取队头元素.\n");
		return;
	}
	return psq->base[psq->front];
}

void CircleQueuePrint(CircleQueue *psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i != psq->rear;)
	{
		printf("%d ",psq->base[i]);
		i = (i + 1) % psq->capacity;
	}
	printf("\n");
}

//////////////////////////////////////////////////////
//链式队列

typedef struct LinkQueueNode
{
	ElemType data;
	struct LinkQueueNode *link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

//////////////////////////////////////////
//函数接口声明
void LinkQueueInit(LinkQueue *pq);//初始化
void LinkQueueEnQue(LinkQueue *pq,ElemType x);//入队
void LinkQueueDeQue(LinkQueue *pq);//出队
bool LinkQueueEmpty(LinkQueue *pq);//判空
ElemType LinkQueueFront(LinkQueue *pq);//取队头元素
ElemType LinkQueueBack(LinkQueue *pq);//取队尾元素
void LinkQueuePrint(LinkQueue *pq);//打印
void LinkQueueDestory(LinkQueue *pq);//摧毁

/////////////////////////////////////////
//函数接口实现
void LinkQueueInit(LinkQueue *pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}

void LinkQueueEnQue(LinkQueue *pq, ElemType x)
{
	assert(pq != NULL);
	LinkQueueNode *node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node!=NULL);
	node->data = x;
	node->link = NULL;

	if (pq->front == NULL)
		pq->front = pq->rear = node;
	else
	{
		pq->rear->link = node;
		pq->rear = node;
	}
}
void LinkQueueDeQue(LinkQueue *pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode *p = pq->front;
		pq->front = p->link;
		free(p);
	}
}

bool LinkQueueEmpty(LinkQueue *pq)
{
	assert(pq != NULL);
	return pq->front == NULL;
}

ElemType LinkQueueFront(LinkQueue *pq)
{
	assert(pq != NULL);
	if (pq->front==pq->rear)
	{
		printf("链式队列已空，不能取队头元素.\n");
		return;
	}
	return pq->rear->data;
}

ElemType LinkQueueBack(LinkQueue *pq)
{
	assert(pq != NULL);
	if (pq->front == pq->rear)
	{
		printf("链式队列已空，不能取队头元素.\n");
		return;
	}
	return pq->front->data;
}

void LinkQueuePrint(LinkQueue *pq)
{
	assert(pq != NULL);
	LinkQueueNode *p = pq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

void LinkQueueDestory(LinkQueue *pq)
{
	assert(pq != NULL);
	LinkQueueNode *p = pq->front;
	while (p != NULL)
	{
		pq->front = p->link;
		free(p);
		pq->front = pq->rear = NULL;
	}
}

#endif /*_QUEUE_H_*/
