NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g
SRCS = main.c utils.c input_check.c init.c stack.c push.c reverse_rotate.c rotate.c swap.c simple_sort.c radix_sort.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
		-gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		-rm -f $(OBJS)

fclean : clean
		-rm -f $(NAME)

re : fclean all

.PHONY: all name clean fclean re
