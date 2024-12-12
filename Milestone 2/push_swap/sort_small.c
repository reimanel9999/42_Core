/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:54:57 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 19:47:34 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(node_t **root)
{
	int	first;
	int	second;

	first = (*root)->x;
	second = (*root)->next->x;
	if (sort_stack(*root))
		return ;
	else if (first > second)
		sa(root);
}

void	sort_three(node_t **root)
{
	int	first;
	int	second;
	int	third;

	first = (*root)->x;
	second = (*root)->next->x;
	third = (*root)->next->next->x;
	if (sort_stack(*root))
		return ;
	else if (first > second && first < third)
		sa(root);
	else if (first > second && (second < third && first > third))
		ra(root);
	else if (first > second && second > third)
	{
		sa(root);
		rra(root);
	}
	else if (first < second && first > third)
		rra(root);
	else if (first < second && first < third)
	{
		rra(root);
		sa(root);
	}
}

void	sort_five(node_t **stack_a, node_t **stack_b)
{
	int	sm_idx;
	int	sm2_idx;

	sm_idx = find_sm_idx(*stack_a);
	sm2_idx = find_sm2_idx(*stack_a);
	while (len_stack(*stack_a) > 3)
	{
		if ((*stack_a)->index == sm_idx || (*stack_a)->index == sm2_idx)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
	small_sort_b(stack_a, stack_b);
	sm_idx = find_sm_idx(*stack_a);
	while ((*stack_a)->index != sm_idx)
	{
		if (find_index_position(*stack_a, sm_idx) <= len_stack(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	small_sort_b(node_t **stack_a, node_t **stack_b)
{
	int	index;
	int	position;

	while (*stack_b)
	{
		index = (*stack_b)->index; 
		position = find_nextbig_index_position(*stack_a, index);
		if (position <= len_stack(*stack_a) / 2)
		{
			while (position--)
				ra(stack_a);
		}
		else
		{
			while (position++ < len_stack(*stack_a))
				rra(stack_a); 
		}
		pa(stack_a, stack_b);
	}
}

int	find_nextbig_index_position(node_t *stack_a, int index)
{
	int		position; 
	int		len;
	node_t	*curr;

	position = 0;
	len = len_stack(stack_a);
	curr = stack_a;
	while (curr)
	{
		if (curr->index > index)
			return (position);
		position++;
		curr = curr->next;
	}
	return (len);
}

int	find_sm_idx(node_t *a)
{
	int		sm_idx; 
	node_t	*tmp;

	sm_idx = a->index;
	tmp = a->next;
	while (tmp)
	{
		if (tmp->index < sm_idx)
			sm_idx = tmp->index;
		tmp = tmp->next;
	}
	return (sm_idx);
}

int	find_sm2_idx(node_t *stack)
{
	int		sm_idx;
	int		sm2_idx;
	node_t	*curr;

	sm_idx = find_sm_idx(stack);
	sm2_idx = INT_MAX;
	curr = stack;
	while (curr)
	{
		if (curr->index != sm_idx && curr->index < sm2_idx)
			sm2_idx = curr->index;
		curr = curr->next;
	}
	return (sm2_idx);
}

int	find_index_position(node_t *a, int index)
{
	int		pos;
	node_t	*tmp;

	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}
