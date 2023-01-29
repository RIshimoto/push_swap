cdef extern from "stdlib.h":
    void            *malloc(size_t size)
    void            free(void *ptr)

cdef extern from "../includes/libft.h":
    struct _del "del"
    ctypedef struct t_list:
        void        *content
        t_list      *next

    ctypedef struct t_dlist:
        void        *content
        t_dlist     *next
        t_dlist     *prev

    char        *ft_strdup(const char *s)
    void        *ft_memmove(void *dest, const void *src, size_t n)
    void        *ft_memcpy(void *dest, const void *src, size_t n)
    size_t      ft_strlen(const char *s)
    int         ft_strcmp(const char *s1, const char *s2)
    void        ft_putchar_fd(char c, int fd)
    void        ft_putnbr_fd(int n, int fd)
    void        ft_putstr_fd(char *s, int fd)
    
    int         ft_lstsize(t_list *lst)
    t_list      *ft_lstnew(void *content)
    t_list      *ft_lstlast(t_list *lst)
    void        ft_lstiter(t_list *lst, void (*f)(void *))
    void        ft_lstadd_back(t_list **lst, t_list *new)
    void        ft_lstclear(t_list **lst, void (*_del)(void *))
    void        ft_lstdelone(t_list *lst, void (*_del)(void *))

    t_dlist     *ft_dlstnew(void *content)
    t_dlist     *ft_dlstlast(t_dlist *lst)
    void        ft_dlstclear(t_dlist **lst, void (*_del)(void *))
    void        ft_dlstdelone(t_dlist *lst, void (*_del)(void *))
    void        ft_dlstadd_back(t_dlist **lst, t_dlist *new)

cdef extern from "../includes/get_next_line.h":
    int     BUFFER_SIZE=1024
    int     SUCESS=1
    int     END=0
    int     ERROR=-1

    int     get_next_line(int fd, char **line)

cdef extern from "../includes/stack.h":
    ctypedef t_list* t_stack

    void        stk_init(t_stack *this)
    void        stk_free(t_stack *this)
    void        stk_push(t_stack this, int value)
    void        stk_print(char *s, t_stack this)
    int         is_stk_empty(t_stack this)
    void        stk_init(t_stack *this)
    void        stk_push(t_stack this, int value)
    void        stk_print(char *s, t_stack this)
    int         stk_pop(t_stack this)
    int         stk_top(t_stack this)
    int	        stk_size(t_stack this)


cdef extern from "../includes/simulator.h":
    ctypedef struct t_stacks:
        t_stack stk_a
        t_stack stk_b
        t_dlist	*instructions
        int		instruction_num

    t_stacks    *stks_init()
    t_stacks    *stks_copy(t_stacks *stks)
    void        stks_print(t_stacks *stks)
    void        stks_free(t_stacks **stks)
    void        stks_push(t_stacks *stks, t_list *lst)
    void        exec_instruction(char *instruction, t_stacks **stks)
    t_stacks    *stks_copy(t_stacks *src)
    t_stacks    *sa(t_stacks *stks)
    t_stacks    *sb(t_stacks *stks)
    t_stacks    *pa(t_stacks *stks)
    t_stacks    *pb(t_stacks *stks)
    t_stacks    *ra(t_stacks *stks)
    t_stacks    *rb(t_stacks *stks)
    t_stacks    *rra(t_stacks *stks)
    t_stacks    *rrb(t_stacks *stks)
    int         checker(t_stacks *stks)
