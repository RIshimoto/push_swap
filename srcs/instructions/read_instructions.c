#include "../../includes/push_swap.h"

static void exec_instruction(char *instruction, t_stacks **stks)
{
	if (ft_strcmp(instruction, "sa") == EQUAL)
		*stks = sa(*stks);
	else if (ft_strcmp(instruction, "sb") == EQUAL)
		*stks = sb(*stks);
	else if (ft_strcmp(instruction, "ss") == EQUAL)
	{
		*stks = sa(*stks);
		*stks = sb(*stks);
	}
	else if (ft_strcmp(instruction, "pa") == EQUAL)
		*stks = pa(*stks);
	else if (ft_strcmp(instruction, "pb") == EQUAL)
		*stks = pb(*stks);
	else if (ft_strcmp(instruction, "ra") == EQUAL)
		*stks = ra(*stks);
	else if (ft_strcmp(instruction, "rb") == EQUAL)
		*stks = rb(*stks);
	else if (ft_strcmp(instruction, "rr") == EQUAL)
	{
		*stks = ra(*stks);
		*stks = rb(*stks);
	}
	else if (ft_strcmp(instruction, "rra") == EQUAL)
		*stks = rra(*stks);
	else if (ft_strcmp(instruction, "rrb") == EQUAL)
		*stks = rrb(*stks);
	else if (ft_strcmp(instruction, "rrr") == EQUAL)
	{
		*stks = rra(*stks);
		*stks = rrb(*stks);
	}
	else
		error();
}

void read_instructions(t_stacks **stks)
{
	char *line;
	int gnl;

	//animation(a, b);
	stk_print("a|", (*stks)->stk_a);
	stk_print("b|", (*stks)->stk_b);
	//ft_putstr_fd("Exec: ", 1);
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		exec_instruction(line, stks);
		free(line);
		stk_print("a|", (*stks)->stk_a);
		stk_print("b|", (*stks)->stk_b);
		//animation(a, b);
		//ft_putstr_fd("Exec: ", 1);
	}
	free(line);
}
