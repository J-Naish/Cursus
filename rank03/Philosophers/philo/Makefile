NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/parse/convert_to_sizet.c\
		src/parse/init.c\
		src/parse/validate.c\
		src/utils/deinit.c\
		src/utils/time.c\
		src/main.c
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
