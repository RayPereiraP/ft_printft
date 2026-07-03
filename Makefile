# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/03 18:36:19 by rayperei          #+#    #+#              #
#    Updated: 2026/07/03 18:36:22 by rayperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a

# Cuidado aqui: mude o ft_printf_hex.c se o seu arquivo for ft_print_hex.c!
SRCS    = ft_printf.c ft_printf_utils.c ft_printf_hex.c
OBJS    = $(SRCS:.c=.o)

CC      = cc
FLAGS   = -Wall -Wextra -Werror
RM      = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h 
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re