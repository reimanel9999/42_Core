# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 13:44:03 by mcarvalh          #+#    #+#              #
#    Updated: 2024/06/26 14:00:50 by mcarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra
NAME = myprogram
SRC = get_next_line get_next_line_utils
SRCS = $(addsuffix .c, ${SRC})
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -Iget_next_line.h

clean:
	rm -f $(OBJS) *~ .*.swp
fclean: clean
	rm -f $(NAME) .*.un

re: fclean all

.PHONY: all clean fclean re
