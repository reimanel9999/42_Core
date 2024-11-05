/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:53:12 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/10 14:41:59 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	m;

	m = 0;
	while (str[m])
	{
		if (str[m] == (char)c)
			return ((char *)(str + m));
		m++;
	}
	if ((char) c == '\0')
		return ((char *)(str + m));
	return (NULL);
}
