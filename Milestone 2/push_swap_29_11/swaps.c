/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:50:11 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/14 18:08:04 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(node_t** root_a) {
	node_t* first;
	node_t* second;
	
	first = *root_a;
	second = (*root_a)->next;
	first->next = second->next;
	second->next = first;
	*root_a = second;
	ft_printf("sa\n");
}

void	sb(node_t** root_b) {
	node_t* first;
	node_t* second;
	
	first = *root_b;
	second = (*root_b)->next;
	first->next = second->next;
	second->next = first;
	*root_b = second;
	ft_printf("sb\n");
}