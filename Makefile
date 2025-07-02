# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keteo <keteo@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/04 22:26:34 by alechin           #+#    #+#              #
#    Updated: 2025/07/01 15:01:37 by keteo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


CC = cc
CFLAGS = -Wall -Wextra -Werror  -g -I$(HEADER) -fsanitize=thread
RM = rm -rf

#/*		Checker		*/#
# -fsanitize=address  #
# -fsanitize=thread   #

SOURCE_DIR = src
HEADER_DIR = include
OBJECT_DIR = object


HEADER = philosophers.h


SOURCE = \
	src/init.c			src/time.c			src/routine_utils.c			\
	src/monitor.c		philosopher.c		src/routine.c				\
	src/init_utils.c


OBJECT = $(SOURCE:$(SOURCE_DIR)/%.c=$(OBJECT_DIR)/%.o)


DEFAULT := \033[1;39m
RESET := \033[0m
GREEN := \033[1;92m
YELLOW := \033[1;93m
CYAN := \033[1;96m
MAGENTA := \033[1;95m


all: $(NAME)


$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c | $(OBJECT_DIR)
	@echo "\n$(YELLOW)Compiling .c files into .o files$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJECT_DIR):
	@mkdir -p $(OBJECT_DIR)

$(NAME): $(OBJECT)
	@echo "$(MAGENTA)\nCompiling Philosophers.c...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECT) -o $(NAME)
	@echo "$(GREEN)\nSuccessfully compiled Philosophers.c...$(RESET)"

clean:
	@clear
	@$(RM) $(OBJECT_DIR)
	@echo "$(CYAN)\nSuccessfully cleaned all object & executable files...$(RESET)"

fclean: clean
	@clear
	@$(RM) $(NAME)
	@echo "$(CYAN)\nSuccessfully cleaned all object & executable files...$(RESET)"

re: clear fclean all

clear:
	@clear

valgrind:
	valgrind --leak-check=full ---show-leak-kinds=all --track-origin=yes

.PHONY: all clean fclean re clear valgrind