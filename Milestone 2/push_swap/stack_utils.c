/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:41:24 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/18 15:27:35 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sort_stack(node_t* root) {
	if (!root)
		return (1);
	while (root->next) {
		if (root->x > root->next->x)
			return (false);
		root = root->next;
	}
	return (true);
}

int	len_stack(node_t* root) {
	int	m;
	node_t* temp;

	m = 0;
	temp = root;
	while (root != NULL) {
		m++;
		root = root->next;
	}
	return (m);
}

void	sort_three(node_t** root) {
	int	first;
	int	second;
	int	third;

	first = (*root)->x;
	second = (*root)->next->x;
	third = (*root)->next->next->x;
	if (first > second && first < third)
		sa(root);
	else if (first > second && (second < third && first > third))
		ra(root);
	else if (first > second && second > third) {
		sa(root);
		rra(root);
	}
	else if(first < second && first > third)
		ra(root);
	else if (first < second && first < third) {
		rra(root);
		sa(root);
	}
}