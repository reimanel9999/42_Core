/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manel_9999 <manel_9999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:02:55 by manel_9999        #+#    #+#             */
/*   Updated: 2024/12/24 12:53:39 by manel_9999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <limits.h>

void	send_signal(int pid, unsigned char character)
{
	int	bit_idx;
	unsigned char	temp_char;

	bit_idx = 8;
	while (bit_idx > 0)
	{
		bit_idx--;
		temp_char = character;
		if ((temp_char >> bit_idx) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t		pid_server;
	const char	*message;
	int			m;

	m = 0;
	if (argc != 3 || !argv[2])
	{
		ft_putendl_fd("Usage: ./minitalk <PID> <message>", 1);
		return (0);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	while (message[m])
		send_signal(pid_server, message[m++]);
	send_signal(pid_server, '\0');
	return (0);
}