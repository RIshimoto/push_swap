#include "../../includes/stack.h"

bool is_stk_empty(t_stack this)
{
	if (this == NULL || this->next == NULL)
		return (true);
	return (false);
}
