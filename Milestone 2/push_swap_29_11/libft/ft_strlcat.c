/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 16:10:04 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:48:20 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	m;
	size_t	n;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	m = dst_len;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	n = 0;
	while (m < dstsize - 1 && src[n])
	{
		dst[m] = src[n];
		n++;
		m++;
	}
	dst[m] = '\0';
	return (dst_len + src_len);
}

/* size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dst && i < dstsize)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, dstsize - i);
	return (ret + i);
} */
