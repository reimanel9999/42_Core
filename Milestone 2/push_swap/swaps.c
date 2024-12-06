/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:50:11 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/05 10:51:41 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(node_t **root_a) {
	node_t* first;
	node_t* second;
	
	first = *root_a;
	second = (*root_a)->next;
	first->next = second->next;
	second->next = first;
	*root_a = second;
	ft_printf("sa\n");
}

void	sb(node_t **root_b) {
	node_t* first;
	node_t* second;
	
	first = *root_b;
	second = (*root_b)->next;
	first->next = second->next;
	second->next = first;
	*root_b = second;
	ft_printf("sb\n");
}

void	pa(node_t **root_a, node_t **root_b) {
	if (!*root_b)
		return ;
	node_t *first_b;

	first_b = *root_b;
	*root_b = (*root_b)->next;

	first_b->next = *root_a;
	*root_a = first_b;
	ft_printf("pa\n");
}

void	pb(node_t **root_a, node_t **root_b) {
	if (*root_a == NULL)
		return ;
	node_t *first_a;

	first_a = *root_a;
	*root_a = (*root_a)->next;

	first_a->next = *root_b;
	*root_b = first_a;
	ft_printf("pb\n");
}