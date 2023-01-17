#include "../includes/push_swap.h"

static int		hash(t_stacks *stks)
{
	int		hash;
	t_list	*lst;

	hash = 0;
	lst = stks->stk_b->next;
	while (lst != NULL)
	{
		hash += *(int*)(lst->content) * 10;
		hash %= HASHSIZE;
		lst = lst->next;
	}
	lst = stks->stk_a->next;
	while (lst != NULL)
	{
		hash += *(int*)(lst->content);
		hash %= HASHSIZE;
		lst = lst->next;
	}
	return (hash);
}

static bool		is_equal(t_stacks *a, t_stacks *b)
{
	t_list *pos_a;
	t_list *pos_b;

	if (stk_size(a->stk_a) != stk_size(b->stk_a))
		return (false);

	pos_a = a->stk_a->next;
	pos_b = b->stk_a->next;
	while (pos_a != NULL && pos_b != NULL)
	{
		if (*(int*)pos_a->content != *(int*)pos_b->content)
			return (false);
		pos_a = pos_a->next;
		pos_b = pos_b->next;
	}
	return (true);
}

static int		evaluate(t_stacks *stks)
{
	int		eval;
	int		now, next;
	t_list *lst;

	eval = 1;
	lst = stks->stk_a->next;
	while (lst->next != NULL)
	{
		now = *(int*)lst->content;
		next = *(int*)lst->next->content;
		if (next - now != 1)
			eval++;
		lst = lst->next;
	}
	return (eval);
}

static bool		search_equal_state(t_stacks *stks, t_state *state_pos)
{
	int a, b;

	a = stks->instruction_num;
	while (state_pos != NULL)
	{
		if (is_equal(stks, state_pos->stacks))
		{
			b = state_pos->stacks->instruction_num;
			if (b < a)
				stks->instructions = state_pos->stacks->instructions;
			return true;
		}
		state_pos = state_pos->hash_link;
	}	
	return (false);
}

static t_state *create_state(t_stacks *stacks, t_state *link)
{
	t_state *new;

	new = (t_state*)malloc(sizeof(t_state));
	new->stacks = stacks;
	new->hash_link = link;
	return new;
}

static void save_mement(t_stacks *mement, t_queue mements)
{
	static t_state *hash_table[HASHSIZE];
	static	int		min_eval=100;
	int				h;
	int				eval;

	h = hash(mement);
	if (search_equal_state(mement, hash_table[h]))
		return ;
	hash_table[h] = create_state(mement, hash_table[h]);

	eval = evaluate(mement);
	//printf("eval:%d (min:%d)\n", eval, min_eval);
	//debug_stk_print(mement);
	if (eval > min_eval)
		return;
	min_eval = eval;
	enq(mements, mement);
	return;
}

static t_stacks *search_smart_instructions(t_stacks *src, t_stacks *target)
{
	t_queue mements;
	t_stacks *mement;
	t_dlist *last;

	int cnt = 0;
	if (is_equal(src, target))
		return target;
	q_init(&mements);
	save_mement(sa(src), mements);
	save_mement(ra(src), mements);
	save_mement(rra(src), mements);
	while (!q_is_empty(mements))
	{
		mement = (t_stacks *)deq(mements);
		cnt++;
		if (is_equal(mement, target))
		{
	printf("Search success: %d\n", cnt);
			return mement;
		}
		last = ft_dlstlast(mement->instructions);
		if (!ft_strcmp(last->content, "ra"))
		{
			save_mement(sa(mement), mements);
			save_mement(ra(mement), mements);
		}	
		else if (!ft_strcmp(last->content, "sa"))
		{
			save_mement(ra(mement), mements);
			save_mement(rra(mement), mements);
		}
		else if (!ft_strcmp(last->content, "rra"))
		{
			save_mement(sa(mement), mements);
			save_mement(rra(mement), mements);
		}
	}
	printf("Search failure: %d\n", cnt);
	return target;
	//ft_lstclear(&queue_top, free);
}

static t_stacks *sort(t_stacks *stks)
{
	t_stacks *ret;
	int n;
	
	ret = malloc(sizeof(t_stacks));
	stk_init(&ret->stk_a);
	stk_init(&ret->stk_b);
	ret->instructions = ft_dlstnew(NULL);
	ret->instruction_num = -1;

	n = stk_size(stks->stk_a);
	while (--n >= 0)
	{
		stk_push(ret->stk_a, n);
	}
	return ret;
}

t_stacks *a_sort(t_stacks *stks)
{
	return search_smart_instructions(stks, sort(stks));
}

