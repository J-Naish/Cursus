NAME := template # program name here
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := src/example.c # source files here
HEADERS := include/example.h # header files here
BUILD_DIR := build
OBJ := $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
LIBFT_DIR := libft # remove this line if not authorized
LIBFT := ./$(LIBFT_DIR)/libft.a # remove this line if not authorized

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make all -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	make fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
