NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = debug.c\
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

test:
	@chmod +x test.sh
	./test.sh

.PHONY: all clean fclean re
