#include "../../includes/simulator.h"

bool checker(t_stacks *stks)
{
	t_stacks *_stks;
	t_stack a, b;
	int a1;
	int a2;

	_stks = stks_copy(stks);
	a = _stks->stk_a;
	b = _stks->stk_b;
	if (!is_stk_empty(b))
		return(false);
	a1 = stk_top(a);
	stk_pop(a);
	while (!is_stk_empty(a))
	{
		a2 = stk_top(a);
		stk_pop(a);
		if (a1 > a2)
			return(false);
		a1 = a2;
	}
	return(true);
}
