# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 21:45:38 by nash              #+#    #+#              #
#    Updated: 2025/02/18 00:00:14 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = error.c\
		exec_cmd.c\
		ft_split.c\
		ft_strdup.c\
		ft_substr.c\
		main.c\
		parse.c\
		utils.c
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

.PHONY: all clean fclean re