NAME = push_swap

SRCS = push_swap.c print_func.c movements.c order.c median.c lists.c sorting.c

OBJS = $(SRCS:%.c=%.o)

CCFLAGS = -Wall -Werror -Wextra

CC = cc -g 

RM = rm -f


%.o:%.c 	push_swap.h Makefile
	$(CC) $(CCFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
