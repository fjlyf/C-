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
//函数声明
void BinTreeInit(BinTree *pbt);  //初始化
//创建
void BinTreeCreate(BinTree *pbt);  
void BinTreeCreate_1(BinTreeNode **pbt); 
BinTreeNode* BinTreeCreate_2();
//遍历
void PreOrder(BinTree *bt);     //层次遍历
void InOrder(BinTree *bt);      //先序遍历
void PostOrder(BinTree *bt);    //中序遍历
void LevelOrder(BinTree *bt);   //后序遍历

//////////////////////////////////////////////////////////////////////
//函数实现
void BinTreeInit(BinTree *pbt)
{
	pbt->root = NULL;
}

void BinTreeCreate(BinTree *pbt)
{
	//1、BinTreeCreate_1(&pbt->root);
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

//void PreOrder(BinTree *bt)
//{
//
//}

#endif /*_TREE_H_*/