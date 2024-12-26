# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manel_9999 <manel_9999@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 16:23:14 by manel_9999        #+#    #+#              #
#    Updated: 2024/12/22 20:56:33 by manel_9999       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_SRCS = client.c
SERVER_SRC = server.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) -L$(LIBFT_DIR) -lft

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRC) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
