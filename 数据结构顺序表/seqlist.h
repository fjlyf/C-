#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"

#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表结构
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;
/////////////////////////////////////////////////
//声明函数接口
void SeqListInit(SeqList *pst);//初始化
bool IsFull(SeqList *pst);//判空
bool IsEmpty(SeqList *pst);//判满
void SeqListPushBack(SeqList *pst, ElemType x);//尾插
void SeqListPushFront(SeqList *pst, ElemType x);//头插
void SeqListShow(SeqList *pst);//查看
void SeqListPopBack(SeqList *pst);//尾删
void SeqListPopFront(SeqList *pst);//头删
void SeqListInsertPos(SeqList *pst, size_t pos, ElemType x);//按位置插入
void SeqListInsertVal(SeqList *pst, ElemType x);//按值插入
void SeqListDeletePos(SeqList *pst, size_t pos);//按位置删除
void SeqListDelectVal(SeqList *pst, ElemType key);//按值删除
int SeqListFindVal(SeqList *pst, ElemType key);//按值查找
size_t SeqListLength(SeqList *pst);//顺序表长度
size_t SeqListCapacity(SeqList *pst);//顺序表空间容量
void SeqListButterSort(SeqList *pst);//顺序表冒泡排序
void SeqListReverse(SeqList *pst);//顺序表逆置
void SeqListReverse(SeqList *pst);//顺序表逆置
void SeqListClear(SeqList *pst);//清除
void SeqListDestroy(SeqList *pst);//摧毁

//////////////////////////////////////////////////
//函数接口实现
void SeqListInit(SeqList *pst)
{
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType)*SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;

}

bool IsFull(SeqList *pst)
{
	assert(pst != NULL);
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList *pst)
{
	assert(pst != NULL);
	return pst->size ==0;
}

void SeqListPushBack(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入数据 %d\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}

void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入数据 %d\n", x);
		return;
	}
	for (size_t pos = pst->size; pos > 0; --pos)
		pst->base[pos] = pst->base[pos - 1];
	pst->base[0] = x;
	pst->size++;
}

void SeqListShow(SeqList *pst)
{
	assert(pst != NULL);
	for (size_t i = 0; i < pst->size; ++i)
		printf("%d", pst->base[i]);
	printf("\n");
}

void SeqListPopBack(SeqList *pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能删除元素\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList *pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能删除元素\n");
		return;
	}
	for (int i = 0; i < pst->size; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

void SeqListInsertPos(SeqList *pst, size_t pos,ElemType x)
{
	assert(pst != NULL);
	if (pos < 0 || pos>pst->size)
	{
		printf("插入的位置非法，%d不能插入\n",x);
		return;
	}
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能按位置插入数据 %d\n", x);
		return;
	}
	for (int i =pst->size; i < pst->size; --i)
		pst->base[i] = pst->base[i - 1];
	pst->base[0] = x;
	pst->size++;
}

void SeqListInsertVal(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能按值插入数据 %d\n", x);
		return;
	}
	//从前往后比较：先比较找到位置再插入
	/*
	int pos = 0;
	int i = 0;
	for (i = 0; i < pst->size; ++i)
	{
		if (x < pst->base[i])
		{
			pos = i;
			break;
		}
	}
	if (i >= pst->size)
		pos = i;
	SeqListInsertPos(pst, pos, x);*/
	//从后往前比较:边比较边移动
	int end = pst->size;
	while (end > 0 && x < pst->base[end - 1])
	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = x;
	pst->size++;
}

void SeqListDeletePos(SeqList *pst, size_t pos)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能删除数据\n");
		return;
	}
	if (pos < 0 || pos>pst->size)
	{
		printf("要删除数据的位置非法，不能按位置删除数据\n");
		return;
	}
	for (int i =pos; i < pst->size; ++i)
		pst->base[i] = pst->base[i + 1];
	pst->size--;
}

void SeqListDelectVal(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能删除数据\n");
		return;
	}
	int pos = SeqListFindVal(pst, key);
	if (pos == -1)
	{
		printf("要删除的数据不存在，不能删除\n");
		return;
	}
	SeqListDeletePos(pst, pos);
}

int SeqListFindVal(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	//二分查找
	SeqListButterSort(pst);
	SeqListShow(pst);
	int left = 0;
	int right = pst->size-1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (pst->base[mid] < key)
			left = mid + 1;
		else if (pst->base[mid]>key)
			right = mid - 1;
		else
			return mid;
	}
	//直接查找
	/*for (int i = 0; i < pst->size; ++i)
	{
		if (key == pst->base[i])
			return i;
	}*/
		return -1;
	   
}


size_t SeqListLength(SeqList *pst)
{
	assert(pst != NULL);
	return(pst->size);
}

size_t SeqListCapacity(SeqList *pst)
{
	assert(pst != NULL);
	return(pst->capacity);
}

void SeqListButterSort(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->size <= 1)
		return;
	for (int i = 0; i < pst->size; ++i)//外层循环控制趟数
	{
		for (int j = 0; j < pst->size - i - 1; ++j)
		{
			if (pst->base[j]>pst->base[j + 1])
			{
				ElemType tmp = pst->base[j];
				pst->base[j] = pst->base[j + 1];
				pst->base[j + 1] = tmp;
			}
		}
	}
}

void SeqListReverse(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->size < 2)
		return;
	int left = 0;
	int right = pst->size - 1;
	while (left < right)
	{
		Swap(&pst->base[left], &pst->base[right]);
		left++;
		right++;
	}
}

void SeqListClear(SeqList *pst)
{
	assert(pst != NULL);
	pst->size == 0;
}

void SeqListDestroy(SeqList *pst)
{
	assert(pst != NULL);
	if (pst->base)
		free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}

#endif /*_COMMON_H*/