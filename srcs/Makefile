CC		= gcc 
CFLAGS	= -Wall -Werror -Wextra -fsanitize=leak
INCLUDE	= -I../includes
LDFLAGS	= -L./queue -L./stack -L./libft
LIBS	= -lqueue -lstack -lft
LIBFT	= libft/libft.a
LIBSTK	= stack/libstack.a
LIBQ    = queue/libqueue.a
NAME	= push_swap checker
PS_SRCS =\
		push_swap.c\
		instructions/get_next_line.c \
		instructions/instructions.c\
		instructions/read_instructions.c\
		push_argument/push_argument.c\
		a_sort.c\
		radix_sort.c\
		insert_sort.c\
		Q_learning.c\
		to_debug.c
CK_SRCS =\
		checker.c\
		instructions/get_next_line.c \
		instructions/instructions.c\
		instructions/read_instructions.c\
		push_argument/push_argument.c
PS_OBJS = $(PS_SRCS:.c=.o)
CK_OBJS = $(CK_SRCS:.c=.o)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./stack
	$(MAKE) clean -C ./queue
	rm -rf $(PS_OBJS)
	rm -rf $(CK_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./stack
	$(MAKE) fclean -C ./queue
	rm -rf $(NAME)

re: fclean all


push_swap: $(PS_OBJS) $(LIBFT) $(LIBSTK) $(LIBQ)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(PS_OBJS) $(LIBS)	

checker: $(CK_OBJS) $(LIBFT) $(LIBSTK) $(LIBQ)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(CK_OBJS) $(LIBS)	

$(LIBQ):
	$(MAKE) -C ./queue

$(LIBSTK):
	$(MAKE) -C ./stack

$(LIBFT):
	$(MAKE) -C ./libft

.PHONY: clean fclean re all
