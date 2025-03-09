# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 21:45:38 by nash              #+#    #+#              #
#    Updated: 2025/03/08 21:58:14 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/error.c\
		src/exec_cmd.c\
		src/here_doc.c\
		src/main.c\
		src/utils.c\
		src/wrappers.c\
		src/get_next_line.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = ./$(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean:
	rm -f $(NAME) $(OBJS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re