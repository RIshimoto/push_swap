#include "../../includes/stack.h"

void stk_push(t_stack this, int value)
{
	t_list *lst;
	int *val;
	
	val = malloc(sizeof(int));
	*val = value;
	lst = ft_lstnew(val);
	lst->next = this->next; 
	this->next = lst;
}
