# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nash <nash@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/26 04:36:51 by nash              #+#    #+#              #
#    Updated: 2025/03/03 10:13:07 by nash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = src/parse/error.c\
		src/parse/get_next_line.c\
		src/parse/read_map.c\
		src/parse/validate_arg.c\
		src/parse/validate_map_chars.c\
		src/parse/validate_map_playability.c\
		src/parse/validate_map_rect.c\
		src/parse/validate_map_utils.c\
		src/parse/validate_map.c\
		src/begin_play.c\
		src/debug.c\
		src/end_play.c\
		src/game_manager.c\
		src/load_images.c\
		src/main.c\
		src/player_controller.c\
		src/render_map.c\
		src/tick.c
BONUS_SRCS = bonus_src/parse/error.c\
		bonus_src/parse/get_next_line.c\
		bonus_src/parse/read_map.c\
		bonus_src/parse/validate_arg.c\
		bonus_src/parse/validate_map_chars.c\
		bonus_src/parse/validate_map_playability.c\
		bonus_src/parse/validate_map_rect.c\
		bonus_src/parse/validate_map_utils.c\
		bonus_src/parse/validate_map.c\
		bonus_src/begin_play_bonus.c\
		bonus_src/end_play_bonus.c\
		bonus_src/enemy_controller_bonus.c\
		bonus_src/game_manager_bonus.c\
		bonus_src/load_images_bonus.c\
		bonus_src/main_bonus.c\
		bonus_src/player_controller_bonus.c\
		bonus_src/render_map_bonus.c\
		bonus_src/tick_bonus.c
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -L./libft -lft -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

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
