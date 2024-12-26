/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:31:44 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:18:10 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			m;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	m = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	if (temp_dst < temp_src)
	{
		while (m < n)
		{
			temp_dst[m] = temp_src[m];
			m++;
		}
	}
	else
	{
		while (n--)
			temp_dst[n] = temp_src[n];
	}
	return (dst);
}
