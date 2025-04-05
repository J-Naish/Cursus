NAME := minishell
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := src/example/example.c\
		src/main.c
TEST_SRC := $(filter-out %main.c, $(SRC))
OBJ_DIR := obj
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_DIR := libft
LIBFT := ./$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re submit

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
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
