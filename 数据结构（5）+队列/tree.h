#ifndef _TREE_H_
#define _TREE_H_

#include"common.h"

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode *leftChild;
	struct BinTreeNode *rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode *root;
}BinTree;

//////////////////////////////////////////////////////////////////////
//��������
void BinTreeInit(BinTree *pbt);  //��ʼ��
//����
void BinTreeCreate(BinTree *pbt);  
void BinTreeCreate_1(BinTreeNode **pbt); 
BinTreeNode* BinTreeCreate_2();
//����
void PreOrder(BinTree *bt);     //�������
void PreOrder_1(BinTreeNode *t);
void InOrder(BinTree *bt);      //�������
void InOrder_1(BinTreeNode *t);
void PostOrder(BinTree *bt);    //�������
void PostOrder_1(BinTreeNode *t);
void LevelOrder(BinTree *bt);   //��α���
void LevelOrder_1(BinTreeNode *t);
//��������Ľڵ�����Լ����ĸ߶�
int BinTreeCount(BinTree *bt);
int BinTreeCount_1(BinTreeNode *t);
int BinTreeHeight(BinTree *bt);
int BinTreeHeight_1(BinTreeNode *t);
//��ѯ
BinTreeNode* BinTreeFind(BinTree *bt, ElemType key);
BinTreeNode* BinTreeParent(BinTree *bt, ElemType key);  //��ѯ�����
//����������
BinTreeNode* BinTreeCopy(BinTree *bt);
//�ж϶�����
bool BinTreeEqual(BinTree *bt1, BinTree *bt2);

///////////////////////////////////////////////////////////////////
//����ʵ��
void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}

void BinTreeCreate(BinTree *pbt)
{
	//1��BinTreeCreate_1(&pbt->root);
	pbt->root = BinTreeCreate_2();
}

void BinTreeCreate_1(BinTreeNode **pbt)
{
	ElemType item;
	scanf("%c",&item);
	if (item == '#')
		*pbt = NULL;
	else
	{
		*pbt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*pbt != NULL);
		(*pbt)->data = item;
		BinTreeCreate_1(&(*pbt)->leftChild);
		BinTreeCreate_1(&(*pbt)->rightChild);
	}
}

BinTreeNode* BinTreeCreate_2()
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode *bt = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(bt != NULL);
		bt->data = item;
		bt->leftChild = BinTreeCreate_2();
		bt->rightChild = BinTreeCreate_2();
		return bt;
	}
}

//�������
void PreOrder(BinTree *bt)
{
	PreOrder_1(bt->root);
}
void PreOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		printf("%c", t->data);
		PreOrder_1(t->leftChild);
		PreOrder_1(t->rightChild);
	}
}
//�������
void InOrder(BinTree *bt)
{
	InOrder_1(bt->root);
}
void InOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		InOrder_1(t->leftChild);
		printf("%c", t->data);
		InOrder_1(t->rightChild);
	}
}
//�������
void PostOrder(BinTree *bt)
{
	PostOrder_1(bt->root);
}
void PostOrder_1(BinTreeNode *t)
{
	if (t != NULL)
	{
		PostOrder_1(t->leftChild);
		PostOrder_1(t->rightChild);
		printf("%c", t->data);
	}
}
//����
BinTreeNode* BinTreeFind(BinTree *bt, ElemType key)
{

}
//��������Ľڵ���
int BinTreeCount(BinTree *bt)
{
	return BinTreeCount_1(bt->root);
}
int BinTreeCount_1(BinTreeNode *t)
{
	if (t == NULL)
		return 0;
	else
		return BinTreeCount_1(t->leftChild) + BinTreeCount_1(t->rightChild) + 1;
}
//��������ĸ߶�
int BinTreeHeight(BinTree *bt)
{
	return BinTreeHeight_1(bt->root);
}
int BinTreeHeight_1(BinTreeNode *t)
{

	if (t == NULL)
		return 0;
	else
	{
		int left_h = BinTreeHeight_1(t->leftChild);
		int right_h = BinTreeHeight_1(t->rightChild);
		return(left_h > right_h ? left_h : right_h);
	}
}

#endif /*_TREE_H_*/
