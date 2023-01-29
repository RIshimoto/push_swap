#include "../../includes/stack.h"

void stk_free(t_stack *this)
{
	ft_lstclear(this, free);
	*this = NULL;
}
