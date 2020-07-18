#include"queue.h"

typedef struct
{
	LinkQueue q1;
	LinkQueue q2;
}MyStack;


MyStack* myStackCreate()
{
	MyStack *pst = (MyStack*)malloc(sizeof(MyStack));
	LinkQueueInit(&(pst->q1));
	LinkQueueInit(&(pst->q2));
	return pst;
}

//入栈
void myStackPush(MyStack *pst, int x)
{
	LinkQueue *pnoempty;
	if (LinkQueueEmpty(&(pst->q1)))
		pnoempty = &(pst->q2);
	else
		pnoempty = &(pst->q1);
	LinkQueueEnQue(pnoempty, x);
}

//出栈
int myStackPop(MyStack *pst)
{
	LinkQueue *pempty, *pnoempty;
	if (LinkQueueEmpty(&(pst->q1)))
	{
		pempty = &(pst->q1);
		pnoempty = &(pst->q2);
	}
	else
	{
		pempty = &(pst->q2);
		pnoempty = &(pst->q1);
	}
	ElemType val;
	while (!LinkQueueEmpty(pnoempty))
	{
		val = LinkQueueFront(pnoempty);
		LinkQueueDeQue(pnoempty);
		if (LinkQueueEmpty(pnoempty))
			break;
		LinkQueueEnQue(pempty, val);
	}
	return val;
}

//获取栈顶元素
int myStackTop(MyStack *pst)
{
	LinkQueue *pnoempty;
	if (LinkQueueEmpty(&(pst->q1)))
		pnoempty = &(pst->q2);
	else
		pnoempty = &(pst->q1);
	return LinkQueueBack(pnoempty);

}

//判空
bool myStackEmpty(MyStack *pst)
{
	return LinkQueueEmpty(&(pst->q1)) && LinkQueueEmpty(&(pst->q2));
}

//释放栈
void myStackFree(MyStack *pst)
{
	LinkQueueDestory(&(pst->q1));
	LinkQueueDestory(&(pst->q2));
	free(pst);
}
