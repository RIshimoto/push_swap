#include "../includes/simulator.h"

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
	stks = stks_init();
	lst = shape_data(argv + 1);
	stks_push(stks, lst);

	i = 0;
	min = sorts[i++](stks);
	while (sorts[i] != NULL)
	{
		tmp = sorts[i++](stks);
		if (tmp->instruction_num < min->instruction_num)
			min = tmp;
	}
	ft_dlstiter(min->instructions, print);
    stks_free(&stks);
	return 0;
}
