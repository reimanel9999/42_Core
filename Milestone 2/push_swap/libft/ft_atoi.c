/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:36:09 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/18 18:40:03 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_atoi(const char *str, int *i, int *number)
{
	int		sign;
	long	temp_num;

	sign = 1;
	temp_num = 0;
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
		if (str[*i] == '-') {
			sign *= -1;
			(*i)++;
		}
	// if (str[*i] < '0' && str[*i] > '9')
	// 	return (1);
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		temp_num = temp_num * 10 + sign * (str[*i] - '0');
		if (temp_num > INT_MAX || temp_num < INT_MIN)
			return (1);
		(*i)++;
	}
	// Skip spaces between temp_nums
	while (str[*i] && str[*i] == ' ')
		(*i)++;
	if (str[*i] != '\0')
		return (1);
	*number = (int)(temp_num * sign);
	return (0);
}