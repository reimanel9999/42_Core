
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if (*s == (char)c)
			return (char *) s;
	}
	return NULL;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)
		((char*)dest)[n] = ((char *)src)[n];
	return dest;
}

size_t	ft_strlen(char *s)
{
	size_t len = 0;
	while(*s)
	{
		s++;
		len++;
	}
	return (len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest < src)
		return ft_memcpy(dest, src, n);
	else if (dest == src)
		return dest;
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];

	return dest;
}

int	str_alloc(char **line, char *buffer, size_t size)
{
    size_t  linelen;
    char    *temp;
    linelen = 0;
    if (*line)
        linelen = ft_strlen(*line);
    temp = malloc(linelen + size + 1);
    if (!temp)
        return (0);
    ft_memcpy(temp, *line, linelen);
    ft_memcpy(temp + linelen, buffer, size);
    temp[linelen + size] = '\0';
    free(*line);
    *line = temp;
    return (1);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1] = "";
	char *line = NULL;
	char *tmp = ft_strchr(buf, '\n');
	while (!tmp) {
		if (!str_alloc(&line, buf, BUFFER_SIZE))
			return NULL;
		int m = read(fd, buf, BUFFER_SIZE);
		if (m == -1)
		{
			free(line);
			return NULL;
		}
		buf[m] = 0;
		if (m == 0)
		{
			if (line && *line) return line;
			free(line);
			return NULL;
		}
	}
	tmp = ft_strchr(buf, '\n');
	if (!str_alloc(&line, buf, tmp - buf + 1))
	{
		free(line);
		return NULL;
	}
	ft_memmove(buf, tmp + 1, ft_strlen(tmp + 1) + 1);
	return line;
}


















