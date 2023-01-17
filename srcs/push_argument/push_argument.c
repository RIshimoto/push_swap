#include "../../includes/push_swap.h"

/*
static void print(void *content)
{
	if (content != NULL)
		printf("%d ", *(int*)content);
}
*/

void error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

/*
static bool isdup(t_list *lst, unsigned int num)
{
	while (lst->next != NULL)
	{
		if (num == *(unsigned int*)(lst->content)) 
			return (true);
		lst = lst->next;
	}
	return (false);
}
*/

t_list *check_argument(char *arg)
{
	t_list *lst;
	t_list *head;
	long int *num;
	int minus;

	while (*arg == ' ')
		arg++;
	minus = 1;
	if (*arg == '\0')
		return NULL;
	if (*arg == '-')
	{
		minus = -1;
		arg++;
	}
	lst = NULL;
	num = malloc(sizeof(unsigned int));
	*num = 0;
	while (*arg != '\0')
	{
		if (*arg == ' ')
		{
			//if (isdup(lst, *num))
			//	error();
			ft_lstadd_back(&lst, ft_lstnew(num));
			head = check_argument(arg + 1);
			ft_lstadd_back(&lst, head);
			return lst;
		}
		if (!ft_isdigit(*arg))
			error();
		*num = *num * 10 + (*arg - '0');
		if (*num * minus > INT_MAX || *num * minus < INT_MIN)
			error();
		arg++;
	}
	//if (isdup(lst, *num))
	//	error();
	ft_lstadd_back(&lst, ft_lstnew(num));
	return lst;
}

t_list *data_align(char **arg)
{
	int i;
	t_list *lst;
	t_list *head;

	lst = NULL;
	i = 0;
	while (arg[i] != NULL)
	{
		head = check_argument(arg[i]);
		ft_lstadd_back(&lst, head);
		i++;
	}
	return lst;
}
