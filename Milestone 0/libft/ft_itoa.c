/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:10:15 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:26:06 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_len(int m)
{
	size_t	len;

	if (m == 0)
		return (1);
	len = 0;
	if (m < 0)
		len++;
	while (m != 0)
	{
		m /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int m)
{
	size_t	len;
	char	*str;

	len = get_len(m);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (m < 0)
	{
		str[0] = '-';
		while (len-- > 1)
		{
			str[len] = '0' - (m % 10);
			m = m / 10;
		}
	}
	while (len-- > 0)
	{
		str[len] = '0' + (m % 10);
		m = m / 10;
	}
	return (str);
}
