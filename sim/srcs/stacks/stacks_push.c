#include "../../includes/simulator.h"

void stks_push(t_stacks *stks, t_list *lst)
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
