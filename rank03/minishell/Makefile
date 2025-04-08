NAME := minishell
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := src/commands/echo.c\
		src/debug/bool_to_str.c\
		src/debug/print_str_arr.c\
		src/utils/free.c\
		src/utils/is_same_str.c\
		src/main.c
HEADERS = include/commands.h\
			include/constants.h\
			include/debug.h\
			include/minishell.h\
			include/types.h\
			include/utils.h
TEST_SRC := $(filter-out %main.c, $(SRC))
BUILD_DIR := build
BUILD := $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
LIBFT_DIR := libft
LIBFT := ./$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re submit

all: $(NAME)

$(NAME): $(BUILD)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(BUILD) $(LIBFT) -o $(NAME) -lreadline

$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

unit-test: $(TEST_SRC)
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(TEST_SRC) $(LIBFT)
	@./a.out
	@rm -f a.out

-include $(BUILD:.o=.d)
