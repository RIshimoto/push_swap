#include "../../includes/queue.h"

void q_init(t_queue *this)
{
	*this = malloc(sizeof(struct s_queue));
	(*this)->head = ft_lstnew(NULL);
	(*this)->tail = (*this)->head;
	(*this)->size = 0;
}
