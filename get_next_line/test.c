
#include "test.h"

char	*getmyline(char *line, char *buffer, int fd, int *linelen)
{
	int	b;

	b = read(fd, buffer, BUFFER_SIZE);
	while (b > 0)
	{
		(buffer)[b] = '\0';
		line = ft_realloc(line, (*linelen) + BUFFER_SIZE + 1);
		line = append_buffer(buffer, line, linelen);
		if (line && line[*linelen - 1] == '\n')
			return (line);
		b = read(fd, buffer, BUFFER_SIZE);
	}
	if (b == 0 && *linelen > 0)
	{
		return (line);
	}
	free(line);
	return NULL;
}

char	*append_buffer(char *buffer, char *line, int *linelen)
{
    int m = 0;
    while (buffer[m] != '\0')
    {
        line[*linelen] = buffer[m];
        (*linelen)++;
        if (buffer[m] == '\n')
        {
            line[*linelen] = '\0';
            ft_memmove(buffer, buffer + m + 1, BUFFER_SIZE - m);
            return line;
        }
        m++;
    }
    buffer[0] = '\0';
    line[*linelen] = '\0';
    return line;
}

char	*ft_realloc(char *ptr, size_t size)
{
	char	*newptr;
	size_t	i;

	newptr = (char *)malloc(size);
	if (!newptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr)
	{
		i = 0;
		while (i < size - 1 && ptr[i] != '\0')
		{
			newptr[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (newptr);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			linelen;

	linelen = 0;
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[0] != '\0')
	{
		line = ft_realloc(line, (linelen) + BUFFER_SIZE + 1);
		line = append_buffer(buffer, line, &linelen);
	}
	if (line && line[linelen - 1] == '\n')
		return (line);
	line = getmyline(line, buffer, fd, &linelen);
	return (line);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			m;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	m = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst < temp_src)
	{
		while (m < n)
		{
			temp_dst[m] = temp_src[m];
			m++;
		}
	}
	else
	{
		while (n--)
			temp_dst[n] = temp_src[n];
	}
	return (dst);
}