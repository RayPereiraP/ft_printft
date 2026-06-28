NAME	= libftprint.a

SRCS	= ft_printf.c ft_printf_utils.c ft_print_hex.c
OBJS	= $(SRCS:.c=.o)

CC		= cc
FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

&(NAME): &(OBJS)
	ar rcs $(name) $(OBJS)

%.o: %.c ft_printf.h 
	$(CC) &(FLAGS) -c $< -o $@

clean:
	&(RM) &(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re