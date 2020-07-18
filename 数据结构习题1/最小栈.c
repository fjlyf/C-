#include"stack.h"

typedef struct
{
	LinkStack st;
	LinkStack min_st;
}MinStack;

MinStack* minStackCreate()
{
	MinStack *pmst = (MinStack*)malloc(sizeof(MinStack));
	LinkStackInit(&(pmst->st));
	LinkStackInit(&(pmst->min_st));
	return pmst;
}


void minStackPush(MinStack *pmst, int x)
{
	LinkStackPush(&(pmst->st), x);
	if (LinkStackEmpty(&(pmst->min_st)) && x <= LinkStackTop(&(pmst->min_st)))
		LinkStackPush(&(pmst->min_st), x);
}

void minStackPop(MinStack *pmst)
{
	ElemType topval = LinkStackTop(&(pmst->st));
	LinkStackPop(&(pmst->st));
	if (topval < LinkStackTop(&(pmst->min_st)))
		LinkStackPop(&(pmst->min_st));
}

int minStackTop(MinStack *pmst)
{
	return LinkStackTop(&(pmst->st));
}

int minStackGetMin(MinStack *pmst)
{
	return LinkStackTop(&(pmst->min_st));
}

//ÊÍ·Å
void minStackFree(MinStack *pmst)
{
	LinkStackDestory(&(pmst->st));
	LinkStackDestory(&(pmst->min_st));
	free(pmst);
}
