/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:44:18 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/05/23 14:37:23 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_substr(char const *s, char c)
{
	int	count;
	int	in_substr;

	count = 0;
	in_substr = 0;
	while (*s)
	{
		if (*s == c)
			in_substr = 0;
		else if (!in_substr)
		{
			count++;
			in_substr = 1;
		}
		s++;
	}
	return (count);
}

char	*copy_substr(char const *start, int len)
{
	char	*substr;

	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, start, len + 1);
	return (substr);
}

char	**free_mem(char **str)
{
	int	m;

	m = 0;
	if (!str)
		return (NULL);
	while (str[m])
		free(str[m++]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			num_sub;
	int			m;
	char		**split;
	const char	*start;

	num_sub = count_substr(s, c);
	split = (char **)malloc(sizeof(char *) * (num_sub + 1));
	m = 0;
	while (*s && m < num_sub)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s && *s != c)
			s++;
		split[m] = copy_substr(start, s - start);
		if (!split[m])
			return (free_mem(split));
		m++;
	}
	split[m] = NULL;
	return (split);
}
