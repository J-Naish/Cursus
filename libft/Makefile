# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 21:40:43 by rnishi            #+#    #+#              #
#    Updated: 2024/05/18 18:34:13 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
ALL_SRCS := $(wildcard *.c)
BONUS_SRCS := $(wildcard *bonus.c)
MAN_SRCS := $(filter-out $(BONUS_SRCS),$(ALL_SRCS))
MAN_OBJS = $(MAN_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
HEADER = libft.h
NAME = libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(MAN_OBJS)
		ar rcs $(NAME) $(MAN_OBJS)

bonus: $(NAME) $(BONUS_OBJS)
		ar rcs $(NAME) $(MAN_OBJS) $(BONUS_OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(MAN_OBJS) $(BONUS_OBJS)

fclean:
		rm -f $(NAME) $(MAN_OBJS) $(BONUS_OBJS)

re: fclean all