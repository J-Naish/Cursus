# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 18:38:32 by nash              #+#    #+#              #
#    Updated: 2025/01/11 23:56:18 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = ./includes
SRCS := $(wildcard src/*.c utils/*.c)
OBJS := $(SRCS:.c=.o)
TEST_SRCS := test/test.c
TEST_OBJS := $(TEST_SRCS:.c=.o)
TEST_EXE := test/test

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

test: $(NAME) $(TEST_OBJS)
	$(CC) $(CFLAGS) -I $(INCLUDES) $(TEST_OBJS) $(NAME) -o $(TEST_EXE)
	@echo "\n\nRunning test:\n"
	./$(TEST_EXE)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean:
	rm -f $(NAME) $(OBJS) $(TEST_EXE) $(TEST_OBJS)

re: fclean all