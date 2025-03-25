NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
		thread.c\
		debug.c\
		log.c\
		parse/init.c\
		parse/validate.c\
		utils/deinit.c\
		utils/time.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
