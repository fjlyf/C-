#include<stdio.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};


int GetLength(struct ListNode *head)
{
	int len = 0;
	while (head->next != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}


struct ListNode* middleNode(struct ListNode *head)
{
	if (head == NULL || head->next == NULL)
		return NULL;
	int len = GetLength(head);
	int k = 0;
	struct ListNode *p = head->next;
	while (k < len / 2)
	{
		p = p->next;
		k++;
	}
	return p;
}