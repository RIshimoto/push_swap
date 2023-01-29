NAME	= push_swap checker
CC		= gcc 
CFLAGS	= -Wall -Werror -Wextra # -fsanitize=leak
INCLUDE	= -I../includes
LDFLAGS	= -L./srcs/queue -L./srcs/stack -L./srcs/libft
LIBS	= -lqueue -lstack -lft
LIBFT	= ./srcs/libft/libft.a
LIBSTK	= ./srcs/stack/libstack.a
LIBQ    = ./srcs/queue/libqueue.a
PS_SRCS =\
		./srcs/pushswap_main.c\
		./srcs/instructions/get_next_line.c\
		./srcs/instructions/instructions.c\
		./srcs/instructions/read_instructions.c\
		./srcs/push_argument/push_argument.c\
		./srcs/solver/a_sort.c\
		./srcs/solver/radix_sort.c\
		./srcs/solver/insert_sort.c\
		./srcs/solver/to_debug.c \
		./srcs/stacks/stacks_init.c\
		./srcs/stacks/stacks_print.c\
		./srcs/stacks/stacks_push.c \
		./srcs/stacks/stacks_copy.c\
		./srcs/stacks/stacks_free.c
CK_SRCS =\
		./srcs/checker_main.c\
		./srcs/checker/checker.c\
		./srcs/stacks/stacks_push.c\
		./srcs/stacks/stacks_print.c\
		./srcs/stacks/stacks_copy.c\
		./srcs/stacks/stacks_init.c\
		./srcs/stacks/stacks_free.c \
		./srcs/instructions/get_next_line.c \
		./srcs/instructions/instructions.c\
		./srcs/instructions/read_instructions.c\
		./srcs/push_argument/push_argument.c
PS_OBJS = $(PS_SRCS:.c=.o)
CK_OBJS = $(CK_SRCS:.c=.o)

all: $(NAME)

clean:
	$(MAKE) clean -C ./srcs/libft
	$(MAKE) clean -C ./srcs/stack
	$(MAKE) clean -C ./srcs/queue
	rm -rf $(PS_OBJS)
	rm -rf $(CK_OBJS)


fclean: clean
	$(MAKE) fclean -C ./srcs/libft
	$(MAKE) fclean -C ./srcs/stack
	$(MAKE) fclean -C ./srcs/queue
	rm -rf $(NAME)
	rm -rf simulator.cpython-37m-x86_64-linux-gnu.so
	rm -rf build

re: fclean all


push_swap: $(PS_OBJS) $(LIBFT) $(LIBSTK) $(LIBQ)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(PS_OBJS) $(LIBS)	
	python setup.py build_ext --inplace

checker: $(CK_OBJS) $(LIBFT) $(LIBSTK) $(LIBQ)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(CK_OBJS) $(LIBS)	

$(LIBQ):
	$(MAKE) -C ./srcs/queue

$(LIBSTK):
	$(MAKE) -C ./srcs/stack

$(LIBFT):
	$(MAKE) -C ./srcs/libft

.PHONY: clean fclean re all
