# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 05:10:22 by nash              #+#    #+#              #
#    Updated: 2025/02/16 07:06:56 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = debug.c\
		error.c\
		libft.c\
		list_management.c\
		list_operations.c\
		list_utils.c\
		main.c\
		normalize.c\
		parse_validation_utils.c\
		parse_validation.c\
		parse.c\
		push.c\
		quick_sort.c\
		reverse_rotate.c\
		rotate.c\
		sort_sm.c\
		sort_lg.c\
		swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

unit_test:
	$(CC) $(CFLAGS) $(filter-out main.c, $(SRCS))
	./a.out

.PHONY: all clean fclean re
