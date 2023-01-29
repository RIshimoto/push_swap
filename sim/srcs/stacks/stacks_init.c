#include "../../includes/simulator.h"

t_stacks *stks_init(void)
{
	t_stacks *stks;

	stks = malloc(sizeof(t_stacks));
	stk_init(&stks->stk_a);
	stk_init(&stks->stk_b);
	stks->instructions = ft_dlstnew(NULL);
	stks->instruction_num = 0;
	return stks;
}
