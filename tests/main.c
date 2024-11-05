/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:17:46 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/07/15 16:38:54 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h" 

// int main()
// {
//   int    fd;
//   char  *next_line;
//   int  count;

//   count = 0;
//   fd = open("example.txt", O_RDONLY);
//   while (1)
//   {
//     next_line = get_next_line(fd);
//     if (next_line == NULL)
//       break ;
//     count++;
//     printf("[%d]:%s\n", count, next_line);
//     next_line = NULL;
//   }
//   close(fd);
//   return (0);
// }

int main()
{
	int fd;
	char *line;
	int m = 6;

	fd = open("example.txt", O_RDONLY);
	while (m > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
		m--;
	}
	close(fd);
	return 0;
}