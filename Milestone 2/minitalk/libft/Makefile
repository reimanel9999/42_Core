# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 16:53:43 by mcarvalh          #+#    #+#              #
#    Updated: 2024/11/20 15:55:49 by mcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC = ft_memset ft_strdup ft_strnstr ft_calloc ft_strlcpy ft_strlcat ft_bzero ft_memchr ft_strchr ft_memcmp ft_memcpy ft_memmove ft_strlen ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_strrchr ft_strncmp ft_atoi ft_strcpy ft_strcat ft_substr ft_strjoin ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_printf ft_utils
SRCS = $(addsuffix .c, ${SRC})
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I./libft

clean:
	rm -f $(OBJS) *~ .*.swp
fclean: clean
	rm -f $(NAME) .*.un~

re: fclean all

.PHONY: all clean fclean re
