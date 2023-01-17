#include "../../includes/queue.h"

void	enq(t_queue this, void *value)
{
	t_list *lst;

	if (this == NULL)
	{
		ft_putendl_fd("Error\nQueue: Please init", 2);
		exit(EXIT_FAILURE);
	}
	lst = ft_lstnew(value);
	this->tail->next = lst;
	this->tail = lst;
	this->size++;
}
