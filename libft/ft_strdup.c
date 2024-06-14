/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:57:18 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:40:01 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*des;
	size_t	m;

	if (!src)
		return (NULL);
	des = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!des)
		return (NULL);
	m = 0;
	while (src[m])
	{
		des[m] = src[m];
		m++;
	}
	des[m] = '\0';
	return (des);
}
/* {
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}*/
