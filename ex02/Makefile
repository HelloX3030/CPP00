CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++11
TEST_CXXFLAGS := $(CXXFLAGS) -Wno-error=deprecated-declarations
NAME := account
NAME_TEST := test_account

# Header files
H_FILES := Account.hpp

# Source files
SRC_FILES := Account.cpp
TEST_SRC_FILES := tests.cpp

# Object directory and object files
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
TEST_OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(TEST_SRC_FILES:.cpp=.o))

# Includes
INCLUDES := -I .

# Default target
all: $(NAME)

# Link main executable
$(NAME): $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) -o $(NAME)

# Link test executable
test: $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(TEST_OBJ_FILES) -o $(NAME_TEST)

# Compile test object with relaxed warning error for deprecated
$(OBJ_DIR)/tests.o: tests.cpp $(H_FILES) | $(OBJ_DIR)
	$(CXX) $(TEST_CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compile other objects with normal flags
$(OBJ_DIR)/%.o: %.cpp $(H_FILES) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Create object directory
$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) -f $(NAME) $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean re test
