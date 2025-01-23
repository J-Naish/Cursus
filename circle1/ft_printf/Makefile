# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 18:38:32 by nash              #+#    #+#              #
#    Updated: 2025/01/23 17:57:52 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
SRCS := src/ft_printf.c\
			src/ft_putaddr.c\
			src/ft_putchar.c\
			src/ft_puthex_lower.c\
			src/ft_puthex_upper.c\
			src/ft_putint.c\
			src/ft_putstr.c\
			src/ft_putuint.c\
			utils/ft_hex.c
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re