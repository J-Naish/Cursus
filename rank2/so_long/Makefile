# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 04:36:51 by nash              #+#    #+#              #
#    Updated: 2025/02/27 06:10:05 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
		parse/error.c\
		parse/get_next_line.c\
		parse/read_map.c\
		parse/validate_arg.c\
		parse/validate_map_chars.c\
		parse/validate_map_rect.c\
		parse/validate_map_utils.c\
		parse/validate_map.c
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
INCLUDES = -I/opt/X11/include -Imlx
# INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
# MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	make all -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re

$(LIBFT):
	make all -C libft

unit_test: $(LIBFT)
	$(CC) $(CFLAGS) $(filter-out main.c, $(SRCS)) $(LIBFT)
	./a.out
	rm -f a.out