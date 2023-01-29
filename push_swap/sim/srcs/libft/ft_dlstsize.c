#include "../../includes/libft.h"

int	ft_dlstsize(t_dlist *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
