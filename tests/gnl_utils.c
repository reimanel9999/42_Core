/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:36:35 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/07/15 14:55:26 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buffer, char *line, int fd, int *len)
{
	int	bytes_read;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = alloc(line, *len + BUFFER_SIZE + 1);
		line = concat_buf(buffer, line, len);
		if (line && line[*len - 1] == '\n' )
			return (line);
	}
	if (bytes_read == 0 && *len > 0)
		return (line);
	free(line);
	return (NULL);
}

char	*concat_buf(char *buffer, char *line, int *len)
{
	int	m;

	m = 0;
	while (buffer[m] != '\0')
	{
		line[*len] = buffer[m];
		(*len)++;
		if (buffer[m] == '\n')
		{
			line[*len] = '\0';
			ft_memmove(buffer, buffer + m + 1, BUFFER_SIZE - m);
			return (line);
		}
		m++;
	}
	buffer[0] = '\0';
	line[*len] = '\0';
	return (line);
}

char	*alloc(char *ptr, size_t size)
{
	char	*temp;
	size_t	i;

	temp = (char *)malloc(size);
	if (!temp)
	{
		free(temp);
		return (NULL);
	}
	if (ptr)
	{
		i = 0;
		while (i < size - 1 && ptr[i] != '\0')
		{
			temp[i] = ptr[i];
			i++;
		}
		free(ptr);
	}
	return (temp);
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