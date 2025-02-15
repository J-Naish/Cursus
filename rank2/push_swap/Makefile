# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 05:10:22 by nash              #+#    #+#              #
#    Updated: 2025/02/16 07:41:28 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = debug.c\
		error.c\
		libft.c\
		main.c\
		op_push.c\
		op_reverse_rotate.c\
		op_rotate.c\
		op_swap.c\
		sort_validation_sort.c\
		parse_validation_utils.c\
		parse_validation.c\
		parse.c\
		sort_sm_utils.c\
		sort_sm.c\
		sort_lg_utils.c\
		sort_lg.c\
		stack_operations.c\
		stack_utils.c\
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
