/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:35:05 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/27 12:24:53 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			m;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	m = 0;
	if (n == m)
		return (0);
	while (m < n)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
		m++;
	}
	return (0);
}
