/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:46:12 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/07/15 14:54:23 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int				len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 0;
	line = NULL;
	if (buffer[0] != '\0')
	{
		line = alloc(line, len + BUFFER_SIZE + 1);
		if (!line)
			return (NULL);
		line = concat_buf(buffer, line, &len);
	}
	if (line && line[len - 1] == '\n')
		return (line);
	return (get_line(buffer, line, fd, &len));
}