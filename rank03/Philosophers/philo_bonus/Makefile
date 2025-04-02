NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = deinit_bonus.c\
		init_bonus.c\
		log_bonus.c\
		main_bonus.c\
		process_bonus.c\
		time_bonus.c\
		validate_bonus.c
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
