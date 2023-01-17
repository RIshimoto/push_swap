CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libstack.a
SRCS = \
	init.c\
	push.c \
	pop.c\
	top.c\
	size.c\
	is_empty.c\
	print.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

.PHONY: all clean fclean re .c.o
