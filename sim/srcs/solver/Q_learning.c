#include "../../includes/simulator.h"

static bool is_sorted(t_stacks *stks)
{
	t_list *lst;
	int a, b;
	
	if (!is_stk_empty(stks->stk_b))
		return false;
	lst = stks->stk_a->next;
	while (lst->next != NULL)
	{
		a = *(unsigned int*)lst->content;
		b = *(unsigned int*)lst->next->content;
		if (a > b)
			return false;
		lst = lst->next;
	}
	return true;
}


static void init(t_agent *self, t_stacks *stk)
{
	self->stack = stk;
	self->state = 10000;
	self->actions[0] = "sa";
	self->actions[1] = "sb";
	self->actions[2] = "ss";
	self->actions[3] = "pa";
	self->actions[4] = "pb";
	self->actions[5] = "ra";
	self->actions[6] = "rb";
	self->actions[7] = "rr";
	self->actions[8] = "rra";
	self->actions[9] = "rrb";
	self->actions[10] = "rrr";
	self->actions_size = 11;
	self->policy[];
}


static t_stacks *policy_udpate(t_agent *agent)
{
	double q_max;
	int a, a_best;
	for (a = 0; a < agent->action_size; a++)
	{
		if (agent->q[][a] > q_max)
		{
			q_max = agent->q[][a];
			a_best = a;
		}
	}
	agent->policy[] = a_best;
}

static t_stacks *get_episode(t_stacks *stks)
{
}
static t_stacks *train(t_agent *agent, double epsilon, int num)
{
	t_list *episode, *episode_length, *tmp;
	int c;
	int data_length;
	int *content;

	c = 0;
	while (c < num)
	{
		episode = get_episode(agent);
		data_length = 0;
		while (episode != NULL)
		{
			data_length;
			episode = episode->next;
		}
		content = malloc(sizeof(int));
		*content = data_length;
		ft_lstadd_back(&episode_lengths, content);
		c++;
	}
	return episode_lenghts;
}

t_stacks *q_learning(t_stacks *stks)
{
	t_agent *agent;
	t_stacks *stk;

	init(&agent, stk);
	episode_lengths = train(&agent, 0.1, 100000);
	return get_episode(&agent, 0, false);
}

