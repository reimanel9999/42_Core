/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:50 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/20 17:35:10 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_stack(char* str, node_t** root) {
	int	index;
	int num;

	index = 0;
	num = 0;
	while (str[index]) {
		num = ft_atoi(str, &index);
		insert_end(root, num);
	}
}

void	insert_end(node_t** root, int value) {
	node_t* new_node;

	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL)
		return ;
	new_node->x = value;
	new_node->next = NULL;
	// Initialize root if list is empty
	if (*root == NULL) {
		*root = new_node; 
		return ;
	}
	node_t*	curr;
	
	curr = *root;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = new_node;
}
