/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manelcarvalho <manelcarvalho@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:36:24 by manelcarval       #+#    #+#             */
/*   Updated: 2025/06/16 11:21:25 by manelcarval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	temp;

	temp = (char) c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == temp)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == temp)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str [len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (char *) dest;
	s = (const char *) src;
	while (num > 0)
	{
		*d++ = *s++;
		num--;
	}
	return (dest);
}

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
