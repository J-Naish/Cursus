# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 05:10:22 by nash              #+#    #+#              #
#    Updated: 2025/03/01 19:58:40 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = debug.c\
		error.c\
		main.c\
		op_push.c\
		op_reverse_rotate.c\
		op_rotate.c\
		op_swap.c\
		parse_validation_sort.c\
		parse_validation_utils.c\
		parse_validation.c\
		parse.c\
		sort_lg_utils1.c\
		sort_lg_utils2.c\
		sort_lg_utils3.c\
		sort_lg_utils4.c\
		sort_lg_utils5.c\
		sort_lg_utils6.c\
		sort_lg.c\
		sort_sm_utils.c\
		sort_sm.c\
		sort_utils.c\
		stack_normalize.c\
		stack_operations.c\
		stack_utils.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make all -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean:
	rm -f $(NAME) $(OBJS)
	make fclean -C libft

re: fclean all

unit_test:
	$(CC) $(CFLAGS) $(filter-out main.c, $(SRCS))
	./a.out

.PHONY: all clean fclean re
