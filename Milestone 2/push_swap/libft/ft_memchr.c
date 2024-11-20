/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:26:44 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/10 12:31:49 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	m;

	m = 0;
	if (!s)
		return (NULL);
	while (m < n)
	{
		if (*(unsigned char *)(s + m) == (unsigned char) c)
			return ((void *)(s + m));
		m++;
	}
	return (NULL);
}
