/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:50 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/06 16:07:07 by mcarvalh         ###   ########.fr       */
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

void assign_indices(node_t **root) {
	node_t *curr;
	int *arr;
	int m;
	int	stack_len;
	
	stack_len = len_stack(*root);
	curr = *root;
	arr  = malloc(sizeof(int) * stack_len);
	m = 0;
	while (curr != NULL) {
		arr[m] = curr->x;
		curr = curr->next;
		m++;
	}

	ft_qsort(arr, stack_len, sizeof(int), compare); // Sorting numbers
	
	// Assigning indices based on sorted order
	curr = *root;
	m = 0;
	while (curr != NULL) {
		while (m < stack_len) {
			if (curr->x == arr[m]) {
				curr->index = m;
				m = 0;
				break;
			}
			m++;
		}
		curr = curr->next;
	}

	free(arr);
}