# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnishi <rnishi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 21:40:43 by rnishi            #+#    #+#              #
#    Updated: 2024/05/15 14:26:45 by rnishi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
ALL_SRCS := $(wildcard *.c)
BONUS_SRCS := $(wildcard *bonus.c)
SRCS := $(filter-out $(BONUS_SRCS),$(ALL_SRCS))
OBJS = $(SRCS:.c=.o)
ALL_OBJS = $(ALL_SRCS:.c=.o)
HEADER = libft.h
NAME = libft.a

.PHONY: all clean fclean re bonus $(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS)

fclean:
	rm -f $(NAME) $(ALL_OBJS)

re: fclean all

bonus: $(ALL_OBJS)
	ar rcs $(NAME) $(ALL_OBJS)

$(ALL_OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@