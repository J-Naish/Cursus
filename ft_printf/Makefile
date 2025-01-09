# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/18 18:38:32 by nash              #+#    #+#              #
#    Updated: 2025/01/10 02:37:18 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
TEST_SRCS := test/test.c
TEST_OBJS := $(TEST_SRCS:.c=.o)
TEST_EXE := test/test

.PHONY: all clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME) $(TEST_OBJS)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(NAME) -o $(TEST_EXE)
	@echo "Running test:"
	@./$(TEST_EXE)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean:
	rm -f $(NAME) $(OBJS) $(TEST_EXE) $(TEST_OBJS)

re: fclean all