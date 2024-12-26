/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:55:59 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/10 15:23:02 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	m;

	src_len = 0;
	m = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (m < size - 1 && src[m])
	{
		dest[m] = src[m];
		m++;
	}
	dest[m] = '\0';
	return (src_len);
}
