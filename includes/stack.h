#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include "libft.h"

typedef t_list* t_stack;

void	stk_init(t_stack *this);
void	stk_push(t_stack this, int value);
int		stk_pop(t_stack this);
int		stk_top(t_stack this);
int		stk_size(t_stack this);
bool	stk_is_empty(t_stack this);
void	stk_print(char *s, t_stack this);
void	animation(t_stack a, t_stack b);

#endif
