/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 10:01:48 by mcarvalh          #+#    #+#             */
/*   Updated: 2025/05/30 10:02:50 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	char *needle = av[1];
	if (needle[0] == '\0')
		return 1;
	size_t needle_len = strlen(av[1]);
	char	*input_buf = NULL;
	size_t	total_zise = 0;
	char	*temp_buf[4096];
	ssize_t	read_bytes;
	while((read_bytes = read(STDIN_FILENO, temp_buf, sizeof(temp_buf))) > 0)
	{
		char *new_buf = realloc(input_buf, total_zise + read_bytes);
		if(!new_buf)
		{
			free(input_buf);
			return 1;
		}
		input_buf = new_buf;
		memmove(input_buf + total_zise, temp_buf, read_bytes);
		total_zise +=read_bytes;
	}
	if (read_bytes < 0)
	{
		free(input_buf);
		return 1;
	}
	char *buff = input_buf;
	size_t bytes = total_zise;
	while((buff = memmem(buff, bytes, needle, needle_len)) != NULL)
	{
		for(size_t i = 0; i < needle_len; i++)
			buff[i] = '*';
		size_t r_bytes = (buff - input_buf) + needle_len;
		bytes = total_zise - r_bytes;
		buff = input_buf + r_bytes;
	}
	ssize_t written = write(STDOUT_FILENO, input_buf, total_zise);
	if(written < 0)
	{
		free(input_buf);
		return 1;
	}
	free(input_buf);
	return 1;
}