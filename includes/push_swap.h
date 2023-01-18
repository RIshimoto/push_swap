#ifndef PUSH_SWAP_H 
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "get_next_line.h"
#include "stack.h"
#include "queue.h"
#include "libft.h"

#define EQUAL 0
#define HASHSIZE 29999

typedef struct s_stacks
{
	t_stack stk_a;
	t_stack stk_b;
	t_dlist	*instructions;
	int		instruction_num;
}	t_stacks;

typedef struct s_state
{
	t_stacks		*stacks;
	struct s_state *hash_link;
}				t_state;

t_stacks *copy(t_stacks *src);
t_stacks *sa(t_stacks *stks);
t_stacks *sb(t_stacks *stks);
t_stacks *pa(t_stacks *stks);
t_stacks *pb(t_stacks *stks);
t_stacks *ra(t_stacks *stks);
t_stacks *rb(t_stacks *stks);
t_stacks *rra(t_stacks *stks);
t_stacks *rrb(t_stacks *stks);
void	read_instructions(t_stacks **stks);
t_list	*data_align(char **arg);

t_stacks *a_sort(t_stacks *stks);
t_stacks *radix_sort(t_stacks *stks);
t_stacks *insert_sort(t_stacks *stks);
//t_stacks *q_learning(t_stacks *stks);
void	error(void);

// to debug
void debug_stk_print(t_stacks *stks);
void debug_ins_print(t_stacks *stks);

#endif
