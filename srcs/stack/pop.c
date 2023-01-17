#include "../../includes/stack.h"

int stk_pop(t_stack this)
{
	t_stack head;
	int *val;

	head = this->next;
	val = (int *)(head->content);
	this->next = head->next;
	//ft_lstdelone(head, free);
	return (*val);
}
