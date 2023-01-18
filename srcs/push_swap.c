#include "../includes/push_swap.h"

static void print(void *content)
{
	if (content != NULL)
		printf("%s\n", (char *)content);
}

static void push_stack(t_stacks *stks, t_list *lst)
{
	unsigned int s, t;
	int *tab;
	int size;
	int i;
	t_list *a;
	t_list *b;

	size = ft_lstsize(lst);
	tab = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		tab[i] = 0;

	i = 0;
	a = lst;
	while (a != NULL)
	{
		s = *(unsigned int*)(a->content);
		b = lst;
		while (b != NULL)
		{
			t = *(unsigned int*)(b->content);
			if (a != b && s > t)
				tab[i]++;
			b = b->next;
		}
		a = a->next;
		i++;
	}
	i = size;
	while (--i >= 0)
		stk_push(stks->stk_a, tab[i]);
}

int main(int argc, char **argv)
{
	t_stacks *stks;
	t_list *lst;
	t_stacks *tmp, *min;
	int i;
	t_stacks *(*sorts[])(t_stacks *) = {
		//q_learning,
		//radix_sort,
		a_sort,
		//insert_sort,
		//brute_force_search,
		NULL
	};

	if (argc <= 1)
		error();
	stks = malloc(sizeof(t_stacks));
	stk_init(&stks->stk_a);
	stk_init(&stks->stk_b);
	stks->instructions = ft_dlstnew(NULL);
	stks->instruction_num = 0;

	lst = data_align(argv + 1);
	push_stack(stks, lst);

	i = 0;
	min = sorts[i++](stks);
	while (sorts[i] != NULL)
	{
		tmp = sorts[i++](stks);
		if (tmp->instruction_num < min->instruction_num)
			min = tmp;
	}
	ft_dlstiter(min->instructions, print);
	return 0;
}
