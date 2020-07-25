#include"list.h"

SListNode* Remove(SList *pst, int key)
{
	SListNode *fast, *slow;
	if (pst->head == NULL)
		return NULL;
	fast = slow = pst->head;
	while (key-- > 0)
	{
		if (fast == NULL)
			return NULL;
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->data;
}

void main()
{
	SList p;
	SListInit(&p);
	SListPushFront(&p, 1);
	SListPushFront(&p, 2);
	SListPushFront(&p, 3);
	SListPushFront(&p, 6);
	SListPushFront(&p, 4);
	SListPushFront(&p, 5);
	SListPushFront(&p, 6);
	SListShow(&p);
	printf("%d\n", Remove(&p, 3));
}
