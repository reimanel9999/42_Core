/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:58:20 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:28:24 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*arr;

	if (num == 0 || size == 0)
		return (malloc(0));
	if (size > SIZE_MAX / num)
		return (NULL);
	arr = malloc(size * num);
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, size * num);
	return (arr);
}
