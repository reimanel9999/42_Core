#ifndef GNL_H
# define GNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);

#endif