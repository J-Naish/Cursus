NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/parse/convert_to_sizet.c\
		src/parse/init.c\
		src/parse/validate.c\
		src/thread/actions.c\
		src/thread/helpers.c\
		src/thread/log.c\
		src/thread/monitor.c\
		src/thread/thread.c\
		src/utils/deinit.c\
		src/utils/time.c\
		src/main.c
HEADERS = include/constants.h\
			include/philo.h\
			include/types.h
BUILD_DIR = build
BUILD = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BUILD)
	$(CC) $(CFLAGS) -o $(NAME) $(BUILD)

$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(BUILD:.o=.d)
