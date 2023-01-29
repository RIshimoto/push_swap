#include "../../includes/simulator.h"

void print(void *content)
{
	if (content != NULL)
		printf("%s\n", (char *)content);
}

void debug_ins_print(t_stacks *stks)
{
	ft_dlstiter(stks->instructions, print);
}

void debug_stk_print(t_stacks *stks)
{
	stk_print("a|", stks->stk_a);
	stk_print("b|", stks->stk_b);
}
