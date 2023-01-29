CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libqueue.a
SRCS = \
	enq.c \
	deq.c\
	front.c\
	is_empty.c\
	size.c\
	init.c
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
