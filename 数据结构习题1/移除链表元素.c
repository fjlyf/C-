#include<stdio.h>


struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (head == NULL)
		return NULL;
	struct ListNode *p = head;
	struct ListNode *prev = NULL;
	while (p != NULL)
	{
		if (p->val == val)
		{
			struct ListNode *next = p->next;
			if (prev == NULL)
				head = head->next;
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
	return head;
}
