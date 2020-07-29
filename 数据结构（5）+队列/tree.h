#ifndef _TREE_H_
#define _TREE_H_

#include"common.h"
#include<math.h>

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
void BinTreeCreateByStr(BinTree *pbt,const char *str);//通过字符串创建
BinTreeNode* BinTreeCreateByStr_1(const char *str,int *pindex);
//递归遍历
void PreOrder(BinTree *bt);     //先序遍历
void PreOrder_1(BinTreeNode *t);
void InOrder(BinTree *bt);      //中序遍历
void InOrder_1(BinTreeNode *t);
void PostOrder(BinTree *bt);    //后序遍历
void PostOrder_1(BinTreeNode *t);
void LevelOrder(BinTree *bt);   //层次遍历
void LevelOrder_1(BinTreeNode *t);
//非递归遍历

//求二叉树的节点个数以及树的高度
int BinTreeCount(BinTree *bt);
int BinTreeCount_1(BinTreeNode *t);
int BinTreeHeight(BinTree *bt);
int BinTreeHeight_1(BinTreeNode *t);
//查询
BinTreeNode* BinTreeFind(BinTree *bt, ElemType key);
BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType key);
BinTreeNode* BinTreeParent(BinTree *bt, ElemType key);  //查询父结点
BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key);
//拷贝二叉树
void BinTreeCopy(BinTree *bt1, BinTree *bt2);   //bt2=bt1
BinTreeNode* BinTreeCopy_1(BinTreeNode *t);
//判断二叉树
bool BinTreeEqual(BinTree *bt1, BinTree *bt2);
bool BinTreeEqual_1(BinTreeNode *t1, BinTreeNode *t2);
bool BinTreeBalanced(BinTree *bt);     //是否为高度平衡二叉树（一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1）
bool BinTreeBalanced_1(BinTreeNode *t);
bool BinTreeSymmetry(BinTree *bt);     //是否为镜像对称
bool BinTreeSymmetry_1(BinTreeNode *t1, BinTreeNode *t2);
//摧毁二叉树
void BinTreeDestory(BinTree *bt);
void BinTreeDestory_1(BinTreeNode *t);
///////////////////////////////////////////////////////////////////
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

void BinTreeCreateByStr(BinTree *bt, const char *str)
{
	int index = 0;
	bt->root = BinTreeCreateByStr_1(str,&index);
}
BinTreeNode* BinTreeCreateByStr_1(const char *str,int *pindex)
{
	if (str[*pindex] == '#' || str[*pindex] == '\0')
		return NULL;
	else
	{
		BinTreeNode *t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		t->leftChild = BinTreeCreateByStr_1(str, pindex);
		(*pindex)++;
		t->rightChild = BinTreeCreateByStr_1(str, pindex);
		return t;
	}
}

//先序遍历
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
//中序遍历
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
//后序遍历
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
//查找
BinTreeNode* BinTreeFind(BinTree *bt, ElemType key)
{
	return BinTreeFind_1(bt->root, key);
}

BinTreeNode* BinTreeFind_1(BinTreeNode *t, ElemType key)
{
	BinTreeNode *p;
	if (t == NULL || t->data == key)
		return t;
	p = BinTreeFind_1(t->leftChild, key);
	if (p != NULL)
		return p;
	return BinTreeFind_1(t->rightChild, key);
}

BinTreeNode* BinTreeParent(BinTree *bt, ElemType key)
{
	return BinTreeParent_1(bt->root, key);
}

BinTreeNode* BinTreeParent_1(BinTreeNode *t, ElemType key)
{
	BinTreeNode *p;
	if (t == NULL||t->data==key)
		return NULL;
	if ((t->leftChild!=NULL&&t->leftChild->data == key) 
		|| (t->rightChild!=NULL&&t->rightChild->data == key))
		return t;
	p = BinTreeParent_1(t->leftChild, key);
	if (p != NULL)
		return p;
	return BinTreeParent_1(t->rightChild, key);
}

//求二叉树的节点数
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
//求二叉树的高度
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

//拷贝二叉树
void BinTreeCopy(BinTree *bt1, BinTree *bt2)
{
	bt2->root = BinTreeCopy_1(bt1->root);
}

BinTreeNode* BinTreeCopy_1(BinTreeNode *t)
{
	if (t == NULL)
		return NULL;
	else
	{
		BinTreeNode *tmp = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(tmp != NULL);
		tmp->data = t->data;

		tmp->leftChild = BinTreeCopy_1(t->leftChild);
		tmp->rightChild = BinTreeCopy_1(t->rightChild);
		return tmp;
	}
}

//判断二叉树
bool BinTreeEqual(BinTree *bt1, BinTree *bt2)
{
	return BinTreeEqual_1(bt1->root, bt2->root);
}
bool BinTreeEqual_1(BinTreeNode *t1, BinTreeNode *t2)
{
	if (t1 == NULL&&t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	if (t1->data == t2->data
		&&BinTreeEqual_1(t1->leftChild, t2->rightChild)
		&& BinTreeEqual_1(t1->rightChild, t2->rightChild))
		return true;
	return false;
}

//判断是否为平衡二叉树
bool BinTreeBalanced(BinTree *bt)
{
	return BinTreeBalanced_1(bt->root);
}
bool BinTreeBalanced_1(BinTreeNode *t)
{
	if (t == NULL)
		return true;
	int left_h = BinTreeHeight_1(t->leftChild);
	int right_h = BinTreeHeight_1(t->rightChild);
	return abs(left_h - right_h) < 2 && BinTreeBalanced_1(t->leftChild) && BinTreeBalanced_1(t->rightChild);
}

//判断是否为对称二叉树
bool BinTreeSymmetry(BinTree *bt)
{
	if (bt == NULL)
		return true;
	return BinTreeSymmetry_1(bt->root->leftChild,bt->root->rightChild);
}
bool BinTreeSymmetry_1(BinTreeNode *t1, BinTreeNode *t2)
{
	if (t1 == NULL&&t2 == NULL)
		return true;
	if (t1 == NULL || t2 == NULL)
		return false;
	return t1->data == t2->data
		   && BinTreeSymmetry_1(t1->leftChild, t2->rightChild)
		   && BinTreeSymmetry_1(t1->rightChild, t2->leftChild);
}


//摧毁二叉树
void BinTreeDestory(BinTree *bt)
{
	BinTreeDestory_1(bt->root);
}
void BinTreeDestory_1(BinTreeNode *t)
{
	if (t == NULL)
		return;
	BinTreeDestory_1(t->leftChild);
	BinTreeDestory_1(t->rightChild);
	free(t);
}

#endif /*_TREE_H_*/
