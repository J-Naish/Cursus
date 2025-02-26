# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 04:36:51 by nash              #+#    #+#              #
#    Updated: 2025/02/27 06:27:00 by nash             ###   ########.fr        #
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
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLXFLAGS = -Lmlx_Linux -lmlx_Linux -L ./mlx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
	MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME)

$(NAME): $(OBJS)
	make all -C libft
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

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