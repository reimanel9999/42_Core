/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:50 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/18 18:29:16 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_stack(char* str, node_t** root) {
	int	index;
	int num;

	index = 0;
	num = 0;
	while (str[index]) {
		if (ft_atoi(str, &index, &num))
			return (1);
		if (insert_end(root, num))
			return (1);
	}
	return (0);
}

int	insert_end(node_t** root, int value) {
	if (duplicates(root, value))
		return (1);
	node_t* new_node;

	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL)
		return (1);
	new_node->x = value;
	new_node->next = NULL;
	if (*root == NULL) 
		*root = new_node;
	node_t*	curr;
	
	curr = *root;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = new_node;
	return (0);
}
