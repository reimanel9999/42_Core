/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:54:21 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/10 14:49:20 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	m;

	m = 0;
	while (str[m])
		m++;
	while (m > -1)
	{
		if (str[m] == (char) c)
			return ((char *)&str[m]);
		m--;
	}
	if ((char) c == '\0')
		return ((char *)(str + m));
	return (NULL);
}
