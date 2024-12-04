# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:38:39 by mcarvalh          #+#    #+#              #
#    Updated: 2024/11/26 16:18:53 by mcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable
NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c sorting.c stack_utils.c swaps.c rotates.c free_error.c ft_qsort.c
OBJ = $(SRC:.c=.o)

# Libft configuration
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Header files
INCLUDES = -I. -I$(LIBFT_DIR)

# Rules
all: $(NAME)

# Build the executable
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compile the object files
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean up object files
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean up everything
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
