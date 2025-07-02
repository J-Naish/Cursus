NAME := ex02
CXX := c++
FLAGS := -Wall -Wextra -Werror -std=c++98 --pedantic
SRC := src/AForm.cpp\
		src/Bureaucrat.cpp\
		src/main.cpp\
		src/PresidentialPardonForm.cpp\
		src/RobotomyRequestForm.cpp\
		src/ShrubberyCreationForm.cpp
HEADERS := include/AForm.hpp\
			include/Bureaucrat.hpp\
			include/constants.hpp\
			include/PresidentialPardonForm.hpp\
			include/RobotomyRequestForm.hpp\
			include/ShrubberyCreationForm.hpp
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
	rm -f *_shrubbery

re: fclean all
