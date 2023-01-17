#include "../../includes/stack.h"

int stk_size(t_stack this)
{
	return (ft_lstsize(this->next));
}
