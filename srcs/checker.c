#include "../includes/push_swap.h"

static bool checker(t_stack a, t_stack b)
{
	int a1;
	int a2;

	if (!stk_is_empty(b))
		return(false);
	a1 = stk_top(a);
	stk_pop(a);
	while (!stk_is_empty(a))
	{
		a2 = stk_top(a);
		stk_pop(a);
		if (a1 > a2)
			return(false);
		a1 = a2;
	}
	return(true);
}

static void push_stack(t_stacks *stks, t_list *lst)
{
	while (lst != NULL)
	{
		ft_lstadd_back(&stks->stk_a, ft_lstnew(lst->content));
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{
	t_stacks *stks;
	t_list *lst;

	stks = malloc(sizeof(t_stacks));
	stk_init(&stks->stk_a);
	stk_init(&stks->stk_b);
	stks->instructions = ft_dlstnew(NULL);

	lst = data_align(argv + 1);
	push_stack(stks, lst);
	read_instructions(&stks);
	if (checker(stks->stk_a, stks->stk_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return 0;
	(void)argc;
}
