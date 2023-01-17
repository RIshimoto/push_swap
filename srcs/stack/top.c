#include "../../includes/stack.h"

int stk_top(t_stack this)
{
	int *val;

	if (this->next == NULL)
		return -1;
	val = (int *)(this->next->content);
	return (*val);
}
