/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:00:56 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 18:37:31 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk_size(int len)
{
	if (len <= 20)
		return (2);
	return (len / 5);
}

int	in_range(node_t *stack, int start, int end)
{
	node_t	*curr;

	curr = stack;
	while (curr)
	{
		if (curr->index >= start && curr->index < end)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	find_closest_index_position(node_t *stack, int start, int end)
{
	int	len;

	len = len_stack(stack);
	return (find_closest_position(stack, start, end, len));
}

int	find_closest_position(node_t *stack, int start, int end, int len)
{
	int		position;
	int		closest_position;
	int		closest_distance;
	node_t	*curr;
	int		distance;

	position = 0;
	closest_position = -1;
	closest_distance = INT_MAX;
	curr = stack;
	while (curr)
	{
		if (curr->index >= start && curr->index < end)
		{
			distance = calculate_distance(position, len);
			if (distance < closest_distance)
			{
				closest_distance = distance;
				closest_position = position;
			}
		}
		curr = curr->next;
		position++;
	}
	return (closest_position);
}

int	calculate_distance(int position, int len)
{
	if (position <= (len / 2))
		return (position);
	return (len - position);
}

void	move_min_or_max_to_top(node_t **stack_b)
{
	int	min_position;
	int	max_position;
	int	stack_len;
	int	optimal_position;

	min_position = find_from_top(*stack_b, min(*stack_b), max(*stack_b));
	max_position = find_from_bottom(*stack_b, min(*stack_b), max(*stack_b));
	stack_len = len_stack(*stack_b);
	if (min_position < stack_len - max_position)
		optimal_position = min_position;
	else
		optimal_position = max_position;
	if (optimal_position == min_position)
	{
		while (optimal_position--)
			rb(stack_b);
	}
	else 
	{
		while (optimal_position++ < stack_len)
			rrb(stack_b);
	}
}

void	put_in_position(node_t **stack_a, node_t **stack_b)
{
	int	top_b;
	int	closest;
	int	stack_len_a;

	top_b = (*stack_b)->index;
	closest = closest_above(*stack_a, top_b);
	stack_len_a = len_stack(*stack_a);
	if (closest == INT_MAX && stack_len_a > 0)
		closest = min(*stack_a);
	rotate_target(stack_a, closest);
	pa(stack_a, stack_b);
}

int	find_position(node_t *stack, int target_index)
{
	int		position;
	node_t	*curr;

	position = 0;
	curr = stack;
	while (curr)
	{
		if (curr->index == target_index)
			return (position);
		position++;
		curr = curr->next;
	}
	return (-1);
}
