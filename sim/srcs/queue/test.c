#include "../../includes/queue.h"

void func(t_queue q)
{
	char *s;

	s = ft_strdup("world");
	enq(q, s);
}

int main(void)
{
	t_queue q;
	char *s;

	q_init(&q);
	s = ft_strdup("hello");
	enq(q, s);
	deq(q);
	s = ft_strdup("aaa");
	enq(q, s);
	printf("%s\n", deq(q));
	return 0;
}
