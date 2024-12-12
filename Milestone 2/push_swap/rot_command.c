/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:55:07 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 20:56:28 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(node_t **root_a)
{
	node_t	*first;
	node_t	*temp;

	first = *root_a;
	temp = *root_a;
	*root_a = (*root_a)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	rb(node_t **root_b)
{
	node_t	*first;
	node_t	*temp;

	first = *root_b;
	temp = *root_b;
	*root_b = (*root_b)->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

void	rra(node_t **root_a)
{
	node_t	*second_last;
	node_t	*temp;

	temp = *root_a;
	second_last = NULL;
	while (temp->next != NULL)
	{
		second_last = temp;
		temp = temp->next;
	}
	second_last->next = NULL;
	temp->next = *root_a;
	*root_a = temp;
	ft_printf("rra\n");
}

void	rrb(node_t **root_b)
{
	node_t	*second_last;
	node_t	*temp;

	temp = *root_b;
	second_last = NULL;
	while (temp->next != NULL)
	{
		second_last = temp;
		temp = temp->next;
	}
	second_last->next = NULL;
	temp->next = *root_b;
	*root_b = temp;
	ft_printf("rrb\n");
}
