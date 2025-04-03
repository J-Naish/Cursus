NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/parse/init_bonus.c\
		src/parse/validate_bonus.c\
		src/process/actions_bonus.c\
		src/process/log_bonus.c\
		src/process/process_bonus.c\
		src/utils/deinit_bonus.c\
		src/utils/time_bonus.c\
		src/main_bonus.c
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
