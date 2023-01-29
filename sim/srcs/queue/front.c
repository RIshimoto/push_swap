#include "../../includes/queue.h"

void *front(t_queue this)
{
	if (this == NULL)
	{
		ft_putendl_fd("Queue: Please init", 2);
		exit(EXIT_FAILURE);
	}
	if (this->head == NULL || this->head->next == NULL)
	{
		printf("ininini\n");
		return NULL;
	}
	return (this->head->next->content);
}
