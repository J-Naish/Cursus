NAME := template # program name here
CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := src/main.c\
				src/template.c # source files here
OBJ_DIR := obj
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_DIR := src/libft # remove this line if not authorized
LIBFT := ./$(LIBFT_DIR)/libft.a # remove this line if not authorized

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
