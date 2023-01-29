#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include "libft.h"

struct s_queue
{
	t_list *	tail;
	t_list *	head;
	int			size;
};

typedef struct s_queue* t_queue;

void	enq(t_queue this, void *value);
void	*deq(t_queue this);
void	*front(t_queue this);
void	q_init(t_queue *this);
int		q_size(t_queue this);
bool	q_is_empty(t_queue this);

#endif
