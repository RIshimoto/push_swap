#include "../../includes/simulator.h"

static bool is_sorted(t_stacks *stks)
{
	t_list *lst;
	int a, b;
	
	if (!is_stk_empty(stks->stk_b))
		return false;
	lst = stks->stk_a->next;
	while (lst->next != NULL)
	{
		a = *(unsigned int*)lst->content;
		b = *(unsigned int*)lst->next->content;
		if (a > b)
			return false;
		lst = lst->next;
	}
	return true;
}

static t_stacks *sort(t_stacks *stks, unsigned int bits)
{
	int i;
	int stka_size;
	int stkb_size;
	t_stacks *sort_stks;

	sort_stks = stks_copy(stks);
	stkb_size = stk_size(stks->stk_b);
	i = -1;
	while (++i < stkb_size)
	{
		sort_stks = rrb(sort_stks);
		if (((stk_top(sort_stks->stk_b) >> bits) & 1) == 0)
			sort_stks = pa(sort_stks);
	}
	if (is_sorted(sort_stks))
		return sort_stks;

	stka_size = stk_size(stks->stk_a);
	i = -1;
	while (++i < stka_size)
	{
		sort_stks = rra(sort_stks);
		if (((stk_top(sort_stks->stk_a) >> bits) & 1) == 1)
			sort_stks = pb(sort_stks);
	}
	return sort_stks;
}

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
	int num_a;
	int num_b;

	if (stk_size(a->stk_a) != stk_size(b->stk_a) || 
		stk_size(a->stk_b) != stk_size(b->stk_b))
		return (false);

	pos_a = a->stk_a->next;
	pos_b = b->stk_a->next;
	while (pos_a != NULL && pos_b != NULL)
	{
		num_a = *(int*)pos_a->content;
		num_b = *(int*)pos_b->content;
		if (num_a != num_b)
			return (false);
		pos_a = pos_a->next;
		pos_b = pos_b->next;
	}

	pos_a = a->stk_b->next;
	pos_b = b->stk_b->next;
	while (pos_a != NULL && pos_b != NULL)
	{
		num_a = *(int*)pos_a->content;
		num_b = *(int*)pos_b->content;
		if (num_a != num_b)
			return (false);
		pos_a = pos_a->next;
		pos_b = pos_b->next;
	}
	return (true);
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
	int				h;

	h = hash(mement);
	if (search_equal_state(mement, hash_table[h]))
		return ;
	hash_table[h] = create_state(mement, hash_table[h]);
	enq(mements, mement);
	return ;
}
/*
static void optimize(t_dlist *src)
{
	t_list *lst;
	char *now, *next;

	if (ft_lstsize(src) <= 1) 
		return;
	lst = src;
	now = (char*)(lst->next->content);
	while(lst != NULL && lst->next != NULL && lst->next->next != NULL)
	{
		next = (char*)(lst->next->next->content);
		if (!ft_strcmp(now, "sa") && !ft_strcmp(next, "sb")) 
		{
			lst = lst->next;
			lst->content = "ss";
			lst->next = lst->next->next;
		}
		else if (!ft_strcmp(now, "ra") && !ft_strcmp(next, "rb")) 
		{
			lst = lst->next;
			lst->content = "rr";
			lst->next = lst->next->next;
		}
		else if (!ft_strcmp(now, "rra") && !ft_strcmp(next, "rrb")) 
		{
			lst = lst->next;
			lst->content = "rrr";
			lst->next = lst->next->next;
		}
		else if ((!ft_strcmp(now, "pa") && !ft_strcmp(next, "pb")) ||
				(!ft_strcmp(now, "pb") && !ft_strcmp(next, "pa"))) 
		{
			lst->next = lst->next->next->next;
		}
		lst = lst->next;
		now = next;
	}
	return;		
}
*/
static void emplace_queue(t_queue q)
{
	return;
	int i;
	int size;
	t_list **array;
	t_list *lst, *tmp;
	int parent, child_left, child_right;
	
	size = q_size(q);
	array = (t_list **)malloc(sizeof(t_list*) * size);
	lst = q->tail->next;
	i = 0;
	while (lst != NULL)
	{
		array[i++] = lst;
		lst = lst->next;
	}
	i = size / 2;
	while (i >= 0)
	{
		printf("%d\n", i);
		parent = ((t_stacks*)array[i]->content)->instruction_num;
		printf("parent:%d\n", parent);
		child_left = ((t_stacks*)array[2*i+1]->content)->instruction_num;
		printf("child_left:%d\n", child_left);
		child_right = ((t_stacks*)array[2*i+2]->content)->instruction_num;
		printf("child_righti:%d\n", child_right);
		if (child_left < child_right)
		{
			if (child_left < parent) 
			{
				tmp = array[i];
				array[i] = array[2 * i + 1];
				array[2 * i + 1] = tmp;

				array[2 * i + 1]->next = array[i]->next;
				array[i]->next = array[2 * i + 1];
			}
		}
		else
		{
			if (child_right < parent) 
			{
				tmp = array[i];
				array[i] = array[2 * i + 2];
				array[2 * i + 2] = tmp;

				array[2 * i + 2]->next = array[i]->next;
				array[i]->next = array[2 * i + 2];
			}
		}
		i--;
	}
	return;
}

static t_stacks *search_smart_instructions(t_stacks *src, t_stacks *target)
{
	t_queue mements;
	t_stacks *mement;


	q_init(&mements);
	save_mement(src, mements);
	enq(mements, src);
	while (!q_is_empty(mements))
	{
		emplace_queue(mements);
		mement = (t_stacks *)deq(mements);
		if (is_equal(mement, target))
			return mement;
		save_mement(pa(mement), mements);
		save_mement(pb(mement), mements);
		save_mement(sa(mement), mements);
		save_mement(sb(mement), mements);
		save_mement(ra(mement), mements);
		save_mement(rb(mement), mements);
		save_mement(rra(mement), mements);
		save_mement(rrb(mement), mements);
	}
	return target;
	//ft_lstclear(&queue_top, free);
}

t_stacks *brute_force_search(t_stacks *stks)
{
	unsigned int bits;
	t_stacks *next_stks;

	debug_stk_print(stks);
	bits = 0;
	while (!is_sorted(stks))
	{
		next_stks = sort(stks, bits);
		//getchar();
		stks = search_smart_instructions(stks, next_stks);
		debug_stk_print(stks);
		bits++;
	}
	debug_ins_print(stks);
	return stks;
}

