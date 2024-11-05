# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/23 16:53:43 by mcarvalh          #+#    #+#              #
#    Updated: 2024/06/14 15:19:03 by mcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRC = ft_printf ft_utils
SRCS = $(addsuffix .c, ${SRC})
OBJS = $(SRCS:.c=.o)
# MAIN_OBJ = main.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I.

# ft_exe: $(MAIN_OBJ) $(NAME)
# 	cc $(CFLAGS) $(MAIN_OBJ) -L. -lftprintf -o ft_exe
clean:
	rm -f $(OBJS) *~ .*.swp
fclean: clean
	rm -f $(NAME) .*.un~ *.gch
re: fclean all

.PHONY: all clean fclean re
