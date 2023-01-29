# include "../../includes/simulator.h"

void stks_free(t_stacks **stks)
{
    stk_free(&((*stks)->stk_a));
    stk_free(&((*stks)->stk_b));
    ft_dlstclear(&((*stks)->instructions), free);
    free(*stks);
    *stks = NULL;
}
