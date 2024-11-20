/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:28:32 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:32:15 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trim;
	int		m;
	int		n;

	trim = NULL;
	if (!s1 || !set)
		return (NULL);
	m = 0;
	n = ft_strlen(s1) - 1;
	while (s1[m] && ft_strchr(set, s1[m]))
		m++;
	while (s1[n] && ft_strchr(set, s1[n]) && n > m)
		n--;
	trim = (char *)malloc(sizeof(char) * (n - m + 2));
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[m], n - m + 2);
	return (trim);
}
