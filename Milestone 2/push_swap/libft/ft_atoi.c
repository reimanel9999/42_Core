/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:36:09 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/20 17:06:09 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str, int *index)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (str[*index] && (str[*index] == ' ' || (str[*index] >= 9 && str[*index] <= 13)))
		(*index)++;
	if (str[*index] == '+' || str[*index] == '-') {
		if (str[*index] == '-')
			sign *= -1;
		(*index)++;
	}
	// if (str[*index] < '0' && str[*index] > '9')
	// 	return (1);
	while (str[*index] >= '0' && str[*index] <= '9') {
		result = result * 10 + (str[*index] - '0');
		if (sign * result > INT_MAX || sign * result < INT_MIN)
			return (1);
		(*index)++;
	}
	// Skip spaces between results
	while (str[*index] && str[*index] == ' ')
		(*index)++;
	// if (*index == *index || (str[*index] < '0' || str[*index] > '9'))
    //     return 1;
	return ((int)(result * sign));
}