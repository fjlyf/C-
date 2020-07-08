#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include"common.h"

#define SEQLIST_DEFAULT_SIZE 8

//����˳���ṹ
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;
/////////////////////////////////////////////////
//���������ӿ�
void SeqListInit(SeqList *pst);//��ʼ��
bool IsFull(SeqList *pst);//�п�
bool IsEmpty(SeqList *pst);//����
void SeqListPushBack(SeqList *pst, ElemType x);//β��
void SeqListPushFront(SeqList *pst, ElemType x);//ͷ��
void SeqListShow(SeqList *pst);//�鿴
void SeqListPopBack(SeqList *pst);//βɾ
void SeqListPopFront(SeqList *pst);//ͷɾ
void SeqListInsertPos(SeqList *pst, size_t pos, ElemType x);//��λ�ò���
void SeqListInsertVal(SeqList *pst, ElemType x);//��ֵ����
void SeqListDeletePos(SeqList *pst, size_t pos);//��λ��ɾ��
void SeqListDelectVal(SeqList *pst, ElemType key);//��ֵɾ��
int SeqListFindVal(SeqList *pst, ElemType key);//��ֵ����
size_t SeqListLength(SeqList *pst);//˳�����
size_t SeqListCapacity(SeqList *pst);//˳���ռ�����
void SeqListButterSort(SeqList *pst);//˳���ð������
void SeqListReverse(SeqList *pst);//˳�������
void SeqListReverse(SeqList *pst);//˳�������
void SeqListClear(SeqList *pst);//���
void SeqListDestroy(SeqList *pst);//�ݻ�

//////////////////////////////////////////////////
//�����ӿ�ʵ��
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
		printf("˳���ռ����������ܲ������� %d\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}

void SeqListPushFront(SeqList *pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܲ������� %d\n", x);
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
		printf("˳���Ϊ�գ�����ɾ��Ԫ��\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList *pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ�����ɾ��Ԫ��\n");
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
		printf("�����λ�÷Ƿ���%d���ܲ���\n",x);
		return;
	}
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܰ�λ�ò������� %d\n", x);
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
		printf("˳���ռ����������ܰ�ֵ�������� %d\n", x);
		return;
	}
	//��ǰ����Ƚϣ��ȱȽ��ҵ�λ���ٲ���
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
	//�Ӻ���ǰ�Ƚ�:�߱Ƚϱ��ƶ�
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
		printf("˳���Ϊ�գ�����ɾ������\n");
		return;
	}
	if (pos < 0 || pos>pst->size)
	{
		printf("Ҫɾ�����ݵ�λ�÷Ƿ������ܰ�λ��ɾ������\n");
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
		printf("˳���Ϊ�գ�����ɾ������\n");
		return;
	}
	int pos = SeqListFindVal(pst, key);
	if (pos == -1)
	{
		printf("Ҫɾ�������ݲ����ڣ�����ɾ��\n");
		return;
	}
	SeqListDeletePos(pst, pos);
}

int SeqListFindVal(SeqList *pst, ElemType key)
{
	assert(pst != NULL);
	//���ֲ���
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
	//ֱ�Ӳ���
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
	for (int i = 0; i < pst->size; ++i)//���ѭ����������
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