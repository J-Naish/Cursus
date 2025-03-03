# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 21:45:38 by nash              #+#    #+#              #
#    Updated: 2025/03/03 11:24:05 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/error.c\
		src/exec_cmd.c\
		src/main.c\
		src/utils.c\
		src/wrappers.c\
		src/get_next_line.c
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)

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

.PHONY: all clean fclean re