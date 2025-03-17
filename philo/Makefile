# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alba <alba@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 12:52:14 by alba              #+#    #+#              #
#    Updated: 2025/03/17 19:45:48 by alba             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	philo.c \
		check.c \
		init.c \
		utils.c \
		error.c

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INC_DIR = include
HEADERS := -I $(INC_DIR)

FLAGS = -Wall -Wextra -Werror -g 
# -fsanitize=address
# -fsanitize=thread
# valgrind --tool=helgrind
CC = cc

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -o $@ -c $< $(HEADERS)
	@echo "Compiling $(notdir $<)"

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(HEADERS) -o $(NAME)
	@echo "Compiled"

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re