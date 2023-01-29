#include "../../includes/simulator.h"

t_stacks *stks_copy(t_stacks *stks)
{
	t_stacks	*new;
	t_list		*lst;
	t_dlist		*dlst;

	new = malloc(sizeof(t_stacks));
	stk_init(&new->stk_a);
	stk_init(&new->stk_b);
	new->instructions = ft_dlstnew(NULL);

	lst = stks->stk_a->next;
	while (lst != NULL)
	{
		ft_lstadd_back(&new->stk_a, ft_lstnew(lst->content));
		lst = lst->next;
	}
	
	lst = stks->stk_b->next;
	while (lst != NULL)
	{
		ft_lstadd_back(&new->stk_b, ft_lstnew(lst->content));
		lst = lst->next;
	}

	dlst = stks->instructions->next;
	while (dlst != NULL)
	{
		char *s = ft_strdup((char*)dlst->content);
		ft_dlstadd_back(&new->instructions, ft_dlstnew(s));
		dlst = dlst->next;
	}

	new->instruction_num = stks->instruction_num;
	return new;
}
