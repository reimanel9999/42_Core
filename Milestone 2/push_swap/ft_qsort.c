/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:18:13 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 21:28:06 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(void *a, void *b, size_t size)
{
	char	*temp;
	char	*swap_a;
	char	*swap_b;
	size_t	m;

	temp = (char *)malloc(size);
	if (!temp)
		return ;
	swap_a = (char *)a;
	swap_b = (char *)b;
	m = 0;
	while (m < size)
	{
		temp[m] = swap_a[m];
		swap_a[m] = swap_b[m];
		swap_b[m] = temp[m];
		m++;
	}
	free(temp);
}

size_t	partition(t_qsort *data, size_t low, size_t high)
{
	char	*array;
	void	*pivot;
	size_t	m;
	size_t	n;

	array = (char *)data->base;
	pivot = array + high * data->size;
	m = low;
	n = low;
	while (n < high)
	{
		if (data->compar(array + n * data->size, pivot) < 0)
		{
			ft_swap(array + m * data->size, array + n * data->size, data->size);
			m++;
		}
		n++;
	}
	ft_swap(array + m * data->size, array + high * data->size, data->size);
	return (m);
}

void	quicksort(t_qsort *data, size_t low, size_t high)
{
	size_t	temp;

	if (low < high)
	{
		temp = partition(data, low, high);
		if (temp > 0)
			quicksort(data, low, temp - 1);
		quicksort(data, temp + 1, high);
	}
}

void	ft_qsort(void *base, size_t len_num, \
size_t size, int (*compar)(const void *, const void *))
{
	t_qsort	data;

	if (len_num > 1)
	{
		data.base = base;
		data.size = size;
		data.compar = compar;
		quicksort(&data, 0, len_num - 1);
	}
}

int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
