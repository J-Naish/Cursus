# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 04:36:51 by nash              #+#    #+#              #
#    Updated: 2025/03/01 23:41:55 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = parse/error.c\
		parse/get_next_line.c\
		parse/read_map.c\
		parse/validate_arg.c\
		parse/validate_map_chars.c\
		parse/validate_map_rect.c\
		parse/validate_map_utils.c\
		parse/validate_map.c\
		begin_play.c\
		debug.c\
		end_play.c\
		game_manager.c\
		load_images.c\
		main.c\
		player_controller.c\
		render_map.c\
		tick.c
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -Lmlx_Linux -lmlx_Linux -L ./mlx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif
MLX = mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	make all -C mlx

$(LIBFT):
	make all -C libft

clean:
	rm -f $(OBJS)
	make clean -C libft
	make clean -C mlx

fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	make clean -C mlx

re: fclean all

.PHONY: all clean fclean re
