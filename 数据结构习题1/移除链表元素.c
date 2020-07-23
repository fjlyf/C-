#include"list.h"



void RemoveAll(SList *plist, int val)
{
	assert(plist != NULL);
	SListNode *p = plist->head;
	SListNode *prev = NULL;
	if (p== NULL)
		return;
	while (p != NULL)
	{
		if (p->data == val)
		{
			SListNode *next = p->next;   //保存p->next
			//第一个节点值为val
			if (prev == NULL)
				plist->head = p->next;
			else
				prev->next = p->next;
			free(p);
			p = next;
		}
		else
		{
			prev = p;
			p = p->next;
		}
	}
	return;
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
	RemoveAll(&p, 6);
	SListShow(&p);

}

