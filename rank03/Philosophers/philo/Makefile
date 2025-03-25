NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c\
		thread.c\
		debug/debug.c\
		debug/log.c\
		parse/init.c\
		parse/validate.c\
		utils/deinit.c\
		utils/time.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
