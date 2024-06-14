/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:35:45 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:23:17 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	m;
	size_t	n;

	if (!big)
		return (NULL);
	if (!little || !little[0])
		return ((char *)big);
	m = 0;
	while (big[m] && m < len)
	{
		n = 0;
		while (big[m + n] && big[m + n] == little[n] && (m + n) < len)
		{
			n++;
			if (little[n] == '\0')
				return ((char *)(big + m));
		}
		m++;
	}
	return (NULL);
}
