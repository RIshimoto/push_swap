#include "../../includes/queue.h"

void *deq(t_queue this)
{
	t_list *top;
	
	if (this == NULL)
	{
		ft_putendl_fd("Error\nQueue: Please init", 2);
		exit(EXIT_FAILURE);
	}
	if (q_is_empty(this))
		return(NULL);
	top = this->head->next;
	this->head->next = top->next;
	if (top == this->tail)
		this->tail = this->head;
	this->size--;
	return (top->content);
}
