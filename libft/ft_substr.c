/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:34:33 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:43:34 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	m;
	size_t	n;

	if (s == NULL)
		return (NULL);
	m = ft_strlen(s);
	n = 0;
	if (m <= start)
		sub = malloc(sizeof(char));
	else
	{
		if (start + len > m)
			len = m - start;
		sub = malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (NULL);
		while (n < len)
		{
			sub[n] = s[n + start];
			n++;
		}
	}
	sub[n] = '\0';
	return (sub);
}
