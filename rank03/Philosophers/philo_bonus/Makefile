NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = src/parse/convert_to_sizet_bonus.c\
		src/parse/init_bonus.c\
		src/parse/validate_bonus.c\
		src/process/actions_bonus.c\
		src/process/destroy_processes_bonus.c\
		src/process/log_bonus.c\
		src/process/monitor_process_bonus.c\
		src/process/monitor_thread_bonus.c\
		src/process/process_bonus.c\
		src/utils/deinit_bonus.c\
		src/utils/time_bonus.c\
		src/utils/unlink_sems_bonus.c\
		src/main_bonus.c
HEADERS = include/philo_bonus.h
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
