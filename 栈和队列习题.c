

#include<stdio.h>
#include<assert.h>
#include<stdbool.h>

typedef int ElemType;


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
void LinkStackPush(LinkStack *pst, ElemType x);//��ջ
void LinkStackPop(LinkStack *pst);//��ջ
bool LinkStackEmpty(LinkStack *pst);//�п�
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
		printf("ջ�ѿգ�����ȡջ��Ԫ��.\n");
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

