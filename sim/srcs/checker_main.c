#include "../includes/simulator.h"

int main(int argc, char **argv)
{
	t_stacks *stks;
	t_list *lst;

	stks = stks_init();
	lst = shape_data(argv + 1);
	stks_push(stks, lst);
	read_instructions(&stks);
	if (checker(stks))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
    stks_free(&stks);
	return 0;
	(void)argc;
}
