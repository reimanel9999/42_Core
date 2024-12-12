/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:17:30 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 20:55:59 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cal_pos(int top_pos, int bottom_pos, int stack_len)
{
	if (top_pos < stack_len - bottom_pos)
		return (top_pos);
	return (bottom_pos);
}

void	perform_rotation(node_t **stack_a, int best_pos, \
int stack_len, int top_pos)
{
	if (best_pos == top_pos)
	{
		while (best_pos > 0)
		{
			ra(stack_a);
			best_pos--;
		}
	}
	else
	{
		while (best_pos < stack_len)
		{
			rra(stack_a);
			best_pos++;
		}
	}
}

void	rotate_a(node_t **stack_a, int start, int end)
{
	int	top_pos;
	int	bottom_pos;
	int	stack_len;
	int	best_pos;

	top_pos = find_from_top(*stack_a, start, end);
	bottom_pos = find_from_bottom(*stack_a, start, end);
	stack_len = len_stack(*stack_a);
	best_pos = cal_pos(top_pos, bottom_pos, stack_len);
	perform_rotation(stack_a, best_pos, stack_len, top_pos);
}

void	rotate_target(node_t **stack_a, int target_index)
{
	int	top_pos;
	int	bottom_pos;
	int	stack_len;
	int	best_pos;

	top_pos = find_top_target(*stack_a, target_index);
	bottom_pos = find_bottom_target(*stack_a, target_index);
	stack_len = len_stack(*stack_a);
	best_pos = cal_pos(top_pos, bottom_pos, stack_len);
	perform_rotation(stack_a, best_pos, stack_len, top_pos);
}
