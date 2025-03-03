# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 04:36:51 by nash              #+#    #+#              #
#    Updated: 2025/03/03 10:00:19 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = parse/error.c\
		parse/get_next_line.c\
		parse/read_map.c\
		parse/validate_arg.c\
		parse/validate_map_chars.c\
		parse/validate_map_playability.c\
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
BONUS_SRCS = parse/error.c\
		parse/get_next_line.c\
		parse/read_map.c\
		parse/validate_arg.c\
		parse/validate_map_chars.c\
		parse/validate_map_rect.c\
		parse/validate_map_utils.c\
		parse/validate_map.c\
		bonus/begin_play_bonus.c\
		bonus/end_play_bonus.c\
		bonus/enemy_controller_bonus.c\
		bonus/game_manager_bonus.c\
		bonus/load_images_bonus.c\
		bonus/main_bonus.c\
		bonus/player_controller_bonus.c\
		bonus/render_map_bonus.c\
		bonus/tick_bonus.c
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -Lmlx_Linux -lmlx_Linux -L ./mlx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
endif
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	make all -C $(MLX_DIR)

$(LIBFT):
	make all -C libft

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make clean -C libft
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make fclean -C libft
	make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re
