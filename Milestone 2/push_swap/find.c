/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:58:27 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 21:13:54 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_from_top(node_t *stack, int start, int end)
{
	int		position;
	node_t	*curr;

	position = 0;
	curr = stack;
	while (curr)
	{
		if (curr->index >= start && curr->index <= end)
			return (position);
		curr = curr->next;
		position++;
	}
	return (-1);
}

int	find_from_bottom(node_t *stack, int start, int end)
{
	int		position;
	node_t	*curr;

	position = len_stack(stack) - 1;
	curr = stack;
	while (curr)
	{
		if (curr->index >= start && curr->index <= end)
			return (position);
		curr = curr->next;
		position--;
	}
	return (-1);
}

int	find_top_target(node_t *stack, int target)
{
	int		position;
	node_t	*curr;

	position = 0;
	curr = stack;
	while (curr)
	{
		if (curr->index == target)
			return (position);
		curr = curr->next;
		position++;
	}
	return (-1);
}

int	find_bottom_target(node_t *stack, int target)
{
	int		position;
	node_t	*curr;

	position = len_stack(stack) - 1;
	curr = stack;
	while (curr)
	{
		if (curr->index == target)
			return (position);
		curr = curr->next;
		position--;
	}
	return (-1);
}
