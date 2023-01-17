#include "../../includes/stack.h"

bool stk_is_empty(t_stack this)
{
	if (this == NULL || this->next == NULL)
		return (true);
	return (false);
}
