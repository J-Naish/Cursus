NAME := convert
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98 --pedantic
SRC := src/ScalarConverter.cpp src/main.cpp
HEADERS := include/ScalarConverter.hpp
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
