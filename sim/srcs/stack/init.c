#include "../../includes/stack.h"

void stk_init(t_stack *this)
{
	*this = ft_lstnew(NULL);
}
