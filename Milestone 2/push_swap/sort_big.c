/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:41:24 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 18:40:15 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(node_t **stack_a, node_t **stack_b)
{
	int	stack_len;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	stack_len = len_stack(*stack_a);
	chunk_size = calculate_chunk_size(stack_len);
	chunk_start = stack_len - chunk_size;
	chunk_end = stack_len;
	while (in_range(*stack_a, chunk_start, chunk_end))
	{
		chunk_move(stack_a, stack_b, chunk_start, chunk_end);
		sorted_to_stack_a(stack_a, stack_b);
		chunk_end = chunk_start;
		chunk_start -= chunk_size; 
		if (chunk_start <= 0)
			chunk_start = 0;
	}
}

void	chunk_move(node_t **stack_a, node_t **stack_b, int start, int end)
{
	while (in_range(*stack_a, start, end))
	{
		if ((*stack_a)->index >= start && (*stack_a)->index <= end)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->next && (*stack_b)->index < (*stack_b)->next->index)
				sb(stack_b);
		}
		else 
			rotate_a(stack_a, start, end);
	}
}

void	sorted_to_stack_a(node_t **stack_a, node_t **stack_b)
{
	int	target_index;
	int	closest;

	while (*stack_b)
	{
		target_index = (*stack_b)->index;
		closest = closest_above(*stack_a, target_index);
		rotate_position(stack_a, closest);
		pa(stack_a, stack_b);
	}
}

int	closest_above(node_t *stack, int target_index)
{
	int		closest;
	int		smallest;
	node_t	*curr;

	closest = INT_MAX;
	smallest = INT_MAX;
	curr = stack;
	while (curr)
	{
		if (curr->index > target_index && curr->index < closest)
			closest = curr->index;
		if (curr->index < smallest)
			smallest = curr->index;
		curr = curr->next;
	}
	if (closest == INT_MAX)
		return (smallest);
	else
		return (closest);
}

int	calculate_rotations(node_t *stack, int target_index)
{
	int	len;
	int	position;
	int	rot;
	int	rev_rot;

	len = len_stack(stack);
	position = find_position(stack, target_index);
	rot = position;
	rev_rot = len - position;
	if (rot <= rev_rot)
		return (rot);
	else
		return (-rev_rot);
}

void	rotate_position(node_t **stack, int target_index)
{
	int	rotations;

	rotations = calculate_rotations(*stack, target_index);
	while (rotations > 0) 
	{
		ra(stack);
		rotations--;
	}
	while (rotations < 0)
	{
		rra(stack);
		rotations++;
	}
}
