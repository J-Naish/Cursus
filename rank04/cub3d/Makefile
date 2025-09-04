NAME := cub3D
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := src/debug/level.c \
		src/debug/map.c \
		src/game/game.c \
		src/game/game_loop.c \
		src/game/init_player.c \
		src/game/load_textures.c \
		src/game/input.c \
		src/game/rotation.c \
		src/render/raycasting.c \
		src/render/render.c \
		src/render/render_frame.c \
		src/input/parse/get_color.c \
		src/input/parse/get_level.c \
		src/input/parse/get_map.c \
		src/input/validation/ends_with_map.c \
		src/input/validation/includes_no_extraneous_line.c \
		src/input/validation/includes_valid_colors.c \
		src/input/validation/includes_valid_map.c \
		src/input/validation/includes_valid_texture_paths.c \
		src/input/validation/is_config_line.c \
		src/input/validation/is_map_line.c \
		src/input/validation/is_valid_map.c \
		src/input/validation/validate_arg.c \
		src/input/validation/validate_cub.c \
		src/input/extract_map_lines.c \
		src/input/get_lines.c \
		src/input/identifier.c \
		src/input/read_file.c \
		src/utils/error.c \
		src/utils/level.c \
		src/utils/map.c \
		src/utils/string_array.c \
		src/utils/string.c \
		src/main.c
BUILD_DIR := build
OBJ := $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

LIB_DIR := lib
LIBFT_DIR := $(LIB_DIR)/libft
GNL_DIR := $(LIB_DIR)/gnl
MLX_DIR := $(LIB_DIR)/minilibx

LIBFT := $(LIBFT_DIR)/libft.a
LIBGNL := $(GNL_DIR)/libgnl.a
LIBMLX := $(MLX_DIR)/libmlx.a

INCLUDES := -I./include -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)

LIBS := $(LIBGNL) $(LIBFT) $(LIBMLX)

FRAMEWORKS := -framework OpenGL -framework AppKit

.PHONY: all clean fclean re libs

all: libs $(NAME)

libs:
	make -C $(LIBFT_DIR)
	make -C $(GNL_DIR)
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(FRAMEWORKS) -o $(NAME)

$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(GNL_DIR)
	make clean -C $(MLX_DIR)

re: fclean all

TEST_NAME := test
TEST_SRC := $(filter-out src/main.c, $(SRC))
TEST_OBJ := $(addprefix $(BUILD_DIR)/test/, $(TEST_SRC:.c=.o))

.PHONY: test

test: libs $(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(LIBS) $(FRAMEWORKS) -o $(TEST_NAME)
	./$(TEST_NAME)

$(BUILD_DIR)/test/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@
