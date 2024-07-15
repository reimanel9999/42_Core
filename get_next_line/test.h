#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_realloc(char *ptr, size_t size);
char	*getmyline(char *line, char *buffer, int fd, int *linelen);
char	*append_buffer(char *buffer, char *line, int *linelen);
void	*ft_memmove(void *dst, const void *src, size_t n);

#endif