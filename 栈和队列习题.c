

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef int ElemType;


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
void LinkStackPush(LinkStack *pst, ElemType x);//入栈
void LinkStackPop(LinkStack *pst);//出栈
bool LinkStackEmpty(LinkStack *pst);//判空
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

bool LinkStackEmpty(LinkStack *pst)
{
	assert(pst != NULL);
	return pst->top == NULL;
}


ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL);
	if (pst->top == NULL)
	{
		printf("栈已空，不能取栈顶元素.\n");
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
		printf("%d\n", p->data);
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

bool inValid(char *s)
{
	if (s == NULL)
		return false;
	if (*s == '\0')
		return true;
	LinkStack st;
	LinkStackInit(&st);

	while (*s != '\0')
	{
		if (*s == '{' || *s == '[' || *s == '(')
			LinkStackPush(&st, *s);
		else
		{
			if (LinkStackEmpty(&st))
				return false;

			char top = LinkStackTop(&st);
			if ((*s == '}'&&top != '{') || (*s == ']'&&top != '[') || (*s == ')'&&top != '('))
				return false;
			LinkStackPop(&st);
		}
		s++;
	}
	bool flag = LinkStackEmpty(&st);
	LinkStackDestory(&st);
	return flag;
}

