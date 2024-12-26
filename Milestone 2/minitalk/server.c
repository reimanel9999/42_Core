/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manel_9999 <manel_9999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:02:51 by manel_9999        #+#    #+#             */
/*   Updated: 2024/12/24 12:54:00 by manel_9999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <limits.h>

void	signal_handler(int signal)
{
	static unsigned char	curr_char;
	static int				bit_idx;

	curr_char |= (signal == SIGUSR1);
	bit_idx++;
	if (bit_idx == 8)
	{
		if (curr_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", curr_char);
		bit_idx = 0;
		curr_char = 0;
	}
	else
		curr_char <<= 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
