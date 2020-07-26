#ifndef _QUEUE_H
#define _QUEUE_H

#include"common.h"
//////////////////////////////////////////////////////
//˳�����
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
//�����ӿ�����

void SeqQueueInit(SeqQueue *psq);//��ʼ��
static bool _SeqQueueInc(SeqQueue *psq);//����
bool SeqQueueIsFull(SeqQueue *psq);//����
bool SeqQueueIsEmpty(SeqQueue *psq);//�п�
void SeqQueueEnque(SeqQueue *psq, ElemType x);//��ӣ������ݣ�
void SeqQueueEnque1(SeqQueue *psq,ElemType x);//��ӣ��ռ���ʱ���ݣ�
void SeqQueueDeque(SeqQueue *psq);//����
ElemType SeqQueueFront(SeqQueue *psq);//ȡ��ͷԪ��
void SeqQueuePrint(SeqQueue *psq);//��ӡ

//////////////////////////////////////////////////////
//�����ӿ�ʵ��
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
		printf("���пռ�������%d�������.\n", x);
		return;
	}
	psq->base[psq->rear++] = x;
}


void SeqQueueDeque(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�����ѿգ����ܳ���.\n");
		return;
	}
	psq->front++;
}

ElemType SeqQueueFront(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueIsEmpty(psq))
	{
		printf("�����ѿգ�����ȡ��ͷԪ��.\n");
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
//ѭ������
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
//�����ӿ�����
void CircleQueueInit(CircleQueue *psq);//��ʼ��
static bool _CircleQueueInc(CircleQueue *psq);//����
bool CircleQueueIsFull(CircleQueue *psq);//����
bool CircleQueueIsEmpty(CircleQueue *psq);//�п�
void CircleQueueEnque(CircleQueue *psq, ElemType x);//���
void CircleQueueDeque(CircleQueue *psq);//����
ElemType CircleQueueFront(CircleQueue *psq);//ȡ��ͷԪ��
void CircleQueuePrint(CircleQueue *psq);//��ӡ
//////////////////////////////////////////////////////
//�����ӿ�ʵ��
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
		printf("ѭ�����пռ�������%d�������.\n", x);
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
		printf("ѭ�������ѿգ����ܳ���.\n");
		return;
	}
	psq->front=(psq->front+1)%psq->capacity;
}

ElemType CircleQueueFront(CircleQueue *psq)
{
	assert(psq != NULL);
	if (CircleQueueIsEmpty(psq))
	{
		printf("ѭ�������ѿգ�����ȡ��ͷԪ��.\n");
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
//��ʽ����

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
//�����ӿ�����
void LinkQueueInit(LinkQueue *pq);//��ʼ��
void LinkQueueEnQue(LinkQueue *pq,ElemType x);//���
void LinkQueueDeQue(LinkQueue *pq);//����
bool LinkQueueEmpty(LinkQueue *pq);//�п�
ElemType LinkQueueFront(LinkQueue *pq);//ȡ��ͷԪ��
ElemType LinkQueueBack(LinkQueue *pq);//ȡ��βԪ��
void LinkQueuePrint(LinkQueue *pq);//��ӡ
void LinkQueueDestory(LinkQueue *pq);//�ݻ�

/////////////////////////////////////////
//�����ӿ�ʵ��
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
		printf("��ʽ�����ѿգ�����ȡ��ͷԪ��.\n");
		return;
	}
	return pq->rear->data;
}

ElemType LinkQueueBack(LinkQueue *pq)
{
	assert(pq != NULL);
	if (pq->front == pq->rear)
	{
		printf("��ʽ�����ѿգ�����ȡ��ͷԪ��.\n");
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
