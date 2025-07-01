NAME := template # program name here
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98 --pedantic
SRC := src/example.cpp # source files here
HEADERS := include/example.hpp # header files here
BUILD_DIR := build
OBJ := $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) -o $(NAME) $(OBJ)

$(BUILD_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)
	$(CXX) $(FLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
