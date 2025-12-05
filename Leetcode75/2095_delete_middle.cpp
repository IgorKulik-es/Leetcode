#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteMiddle(struct ListNode* head)
{
		struct ListNode*	middle;
		struct ListNode*	current;
		bool		isEven = true;

		current = head;
		middle = head;
		if (current->next == NULL)
			return NULL;
		current = current->next;
		while (current->next)
		{
			current = current->next;
			isEven ^= true;
			if (isEven)
				middle = middle->next;
		}
		middle->next = middle->next->next;
		return (head);
}