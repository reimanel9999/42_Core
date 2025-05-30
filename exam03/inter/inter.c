/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:47:46 by manelcarval       #+#    #+#             */
/*   Updated: 2025/05/26 18:48:16 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "nothing" "This sentence hides nothing" | cat -e
// nothig$
// $>./inter | cat -e

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i = 0;

	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_check(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
void	ft_inter(char *s1, char *s2)
{
	char	ret[999];
	int		y = 0;

	if (s1 && s2)
	{
		while (*s1)
		{
			//if s1 char is in s2 and if s1 char is not in ret
			if (ft_check(*s1, s2) && ft_check(*s1, ret) == 0)
				ret[y++] = *s1;
			s1++;
		}
	}
	ret[y] = '\0';
	ft_putstr(ret);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}