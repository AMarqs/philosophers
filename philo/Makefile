# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albmarqu <albmarqu@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 12:52:14 by albmarqu          #+#    #+#              #
#    Updated: 2025/04/02 20:20:17 by albmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	main.c \
		check.c \
		init.c \
		thread.c \
		routine.c \
		monitors.c \
		utils.c \
		basic_functions.c \
		errors.c

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INC_DIR = include
HEADERS := -I $(INC_DIR)

FLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
# 
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