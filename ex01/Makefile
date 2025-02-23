CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98

SRCS := Fixed.cpp main.cpp
OBJS_DIR := objects
OBJS := $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

NAME := main

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "Created" $(NAME)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Created" $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME).exe

re: fclean all
