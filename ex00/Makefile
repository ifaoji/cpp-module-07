CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wpedantic -std=c++98 -MMD -MP
CPPFLAGS =
LDFLAGS =
LDLIBS =

RAW_SRCS =	main \

SRC_DIR = ./
SRCS = $(RAW_SRCS:%=$(SRC_DIR)/%.cpp)

OBJ_DIR = obj
OBJS = $(RAW_SRCS:%=$(OBJ_DIR)/%.o)
OBJ_DIRS := $(sort $(dir $(OBJS)))

NAME = start_with_a_few_functions

ifeq ($(DEBUG), 1)
CXXFLAGS += -O0 -glldb
endif

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIRS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

$(OBJ_DIRS):
	mkdir -p $@

# DEBUG RULES

debug:
	$(MAKE) DEBUG=1 --no-print-directory all

redebug: fclean debug

