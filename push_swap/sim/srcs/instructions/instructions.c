#include "../../includes/simulator.h"

t_stacks *sa(t_stacks *src)
{
	t_stacks *dest;
	int x;
	int y;

	dest = stks_copy(src);
	if (stk_size(dest->stk_a) == 1 || is_stk_empty(dest->stk_a))
		return dest;
	x = stk_top(dest->stk_a);
	stk_pop(dest->stk_a);
	y = stk_top(dest->stk_a);
	stk_pop(dest->stk_a);
	stk_push(dest->stk_a, x);
	stk_push(dest->stk_a, y);

	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "sb"))
		dlst->content = "ss";
	else
	{
		char *s = ft_strdup("sa");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}

t_stacks *sb(t_stacks *src)
{
	t_stacks *dest;
	int x;
	int y;

	dest = stks_copy(src);
	if (stk_size(dest->stk_b) == 1 || is_stk_empty(dest->stk_b))
		return dest;
	x = stk_top(dest->stk_b);
	stk_pop(dest->stk_b);
	y = stk_top(dest->stk_b);
	stk_pop(dest->stk_b);
	stk_push(dest->stk_b, x);
	stk_push(dest->stk_b, y);

	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "sa"))
		dlst->content = "ss";
	else
	{
		char *s = ft_strdup("sb");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}

t_stacks *pa(t_stacks *src)
{
	t_stacks *dest;

	dest = stks_copy(src);
	if (is_stk_empty(dest->stk_b))
		return dest;
	stk_push(dest->stk_a, stk_top(dest->stk_b));
	stk_pop(dest->stk_b);

	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "pb"))
	{
		dlst->prev->next = NULL;
		dest->instruction_num--;
	}
	else
	{
		char *s = ft_strdup("pa");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}

t_stacks *pb(t_stacks *src)
{
	t_stacks *dest;

	dest = stks_copy(src);
	if (is_stk_empty(dest->stk_a))
		return dest;
	stk_push(dest->stk_b, stk_top(dest->stk_a));
	stk_pop(dest->stk_a);

	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "pa"))
	{
		dlst->prev->next = NULL;
		dest->instruction_num--;
	}
	else
	{
		char *s = ft_strdup("pb");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}

t_stacks *ra(t_stacks *src)
{
	t_list *lst;
	t_stacks *dest;

	dest = stks_copy(src);
	if (is_stk_empty(dest->stk_a))
		return dest;
	lst = dest->stk_a->next;
	dest->stk_a->next = lst->next;
	lst->next = NULL;
	ft_lstadd_back(&dest->stk_a, lst);

	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "rb"))
		dlst->content = "rr";
	else
	{
		char *s = ft_strdup("ra");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}

t_stacks *rb(t_stacks *src)
{
	t_list *lst;
	t_stacks *dest;

	dest = stks_copy(src);
	if (is_stk_empty(dest->stk_b))
		return dest;
	lst = dest->stk_b->next;
	dest->stk_b->next = lst->next;
	lst->next = NULL;
	ft_lstadd_back(&dest->stk_b, lst);

	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "ra"))
		dlst->content = "rr";
	else
	{
		char *s = ft_strdup("rb");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}


t_stacks *rra(t_stacks *src)
{
	t_list *lst;
	t_list *tmp;
	t_stacks *dest;

	dest = stks_copy(src);
	if (stk_size(dest->stk_a) == 1 || is_stk_empty(dest->stk_a))
		return dest;
	lst = dest->stk_a;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = dest->stk_a->next;
	lst->next->next = tmp;
	dest->stk_a->next = lst->next;
	lst->next = NULL;
	
	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "rrb"))
		dlst->content = "rrr";
	else
	{
		char *s = ft_strdup("rra");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}

t_stacks *rrb(t_stacks *src)
{
	t_list *lst;
	t_list *tmp;
	t_stacks *dest;

	dest = stks_copy(src);
	if (stk_size(dest->stk_b) == 1 || is_stk_empty(dest->stk_b))
		return dest;
	lst = dest->stk_b;
	while (lst->next->next != NULL)
		lst = lst->next;
	tmp = dest->stk_b->next;
	lst->next->next = tmp;
	dest->stk_b->next = lst->next;
	lst->next = NULL;

	t_dlist *dlst;
	dlst = ft_dlstlast(dest->instructions);
	if (dlst->content != NULL &&
		!ft_strcmp((char*)dlst->content, "rra"))
		dlst->content = "rrr";
	else	
	{
		char *s = ft_strdup("rrb");
		ft_dlstadd_back(&dest->instructions, ft_dlstnew(s));
		dest->instruction_num++;
	}
	return dest;
}
