# **************************************************************************** #
#                                Dining Philosophers Makefile                  #
# **************************************************************************** #

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= $(wildcard src/*.c) philosopher.c
OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# Default rule
all: $(NAME)

# Build executable from object files
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)

# Compile source files into object files inside obj/
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)

# Create the obj directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Remove object files
clean:
	rm -rf $(OBJ_DIR)

# Remove executable and object files
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re 
