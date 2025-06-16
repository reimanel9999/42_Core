/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:01:42 by manelcarval       #+#    #+#             */
/*   Updated: 2025/06/16 11:23:54 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Appends 'size' bytes from 'buffer' to '*line'. Returns 1 on success, 0 on failure.
static int	ft_strjoin(char **line, char *buffer, size_t size)
{
	size_t	linelen;
	char	*temp;

	linelen = 0;
	if (*line)
		linelen = ft_strlen(*line); // Get current length of line
	temp = malloc(linelen + size + 1); // +1 for null terminator
	if (!temp)
		return (0); // Allocation failed
	ft_memcpy(temp, *line, linelen); // Copy existing content
	ft_memcpy(temp + linelen, buffer, size); // Append new content
	temp[linelen + size] = '\0'; // Null-terminate
	free(*line); // Free old string
	*line = temp; // Update pointer to new string
	return (1);
}

static char	*buffer_process(int fd, char **line, char *buffer)
{
	char	*temp;
	int		m;

	temp = ft_strchr(buffer, '\n');
	while (temp == NULL)
	{
		if (!ft_strjoin(line, buffer, BUFFER_SIZE))
			return (NULL);
		if ((m = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(*line);
			*line = NULL;
			return (NULL);
		}
		buffer[m] = '\0';
		if (m == 0)
			return (NULL);
		temp = ft_strchr(buffer, '\n');
	}
	return (temp);
}


char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line = NULL;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	temp = buffer_process(fd, &line, buffer);
	if (temp == NULL)
	{
		if (line && *line)
			return (line);
		free(line);
		return (NULL);
	}
	if (!ft_strjoin(&line, buffer, temp - buffer + 1))
	{
		free(line);
		return NULL;
	}
	ft_memmove(buffer, temp + 1, ft_strlen(temp + 1) + 1);
	return (line);
}




// static char	*mem_alloc(char *line, int size)
// {
//     char    *temp;
//     int     m;
	
//     temp = NULL;
//     m = 0;
//     temp = (char *)malloc(size);
//     if (line)
// 	{
// 		while (m < size - 1 && line)
// 		{
// 			temp[m] = line[m];
// 			m++;
// 		}
// 		free(line);
// 	}
// 	return (temp);
// }
// static char	*ft_strjoin(char *line, char *buffer, int *len)
// {
// 	int	m;

// 	m = 0;
// 	while (buffer[m])
// 	{
// 		line[*len] = buffer[m];
// 		(*len)++;
// 		if (buffer[m] == '\n')
// 		{
// 			line[*len] = '\0';
// 			ft_memcpy(buffer, buffer + m + 1, m);
// 			return (line);
// 		}
// 		m++;
// 	}
// 	buffer[m] = '\0';
// 	line[*len] = '\0';
// 	return (line);
	
// }

// char    *get_next_line(int fd)
// {
//     static char  buffer[BUFFER_SIZE + 1];
//     char    *line;
//     int     m;
//     int     len;
    
//     line = NULL;
// 	len = 0;
//     if (fd <= 0)
//         return (NULL);
//     while ((m = read(fd, buffer, BUFFER_SIZE)) > 0)
//     {
//         buffer[m] = '\0';
//         if (m <= 0)
//             break;
//         // len = ft_strlen(line);
//         line = mem_alloc(line, BUFFER_SIZE + len);
//         line = ft_strjoin(line, buffer, &len);
// 		if (line && line[len - 1] == '\n')
// 			return (line);
//     }
// 	if (m == 0 && len > 0)
// 		return (line);
// 	free(line);
// 	return (NULL);
// }
