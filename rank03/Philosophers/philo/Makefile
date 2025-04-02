NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = debug.c\
		deinit.c\
		log.c\
		main.c\
		monitor.c\
		routine.c\
		thread.c\
		utils.c\
		init.c\
		validate.c
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

