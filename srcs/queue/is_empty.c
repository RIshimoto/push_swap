#include "../../includes/queue.h"

bool q_is_empty(t_queue this)
{
	if (q_size(this) > 0)
		return (false);
	return (true);
}
