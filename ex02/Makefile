CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

# Final executable name (will include tests)
NAME := account

# Header files
H_FILES := Account.hpp

# Source files (including tests)
SRC_FILES := Account.cpp tests.cpp

# Object directory and object files
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

# Includes
INCLUDES := -I .

# Default target builds everything (including tests)
all: $(NAME)

# Link the executable
$(NAME): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(NAME)

# Compile all objects with normal flags
$(OBJ_DIR)/%.o: %.cpp $(H_FILES) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
