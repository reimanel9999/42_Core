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

// Function to check duplicates using a hash table
void check_duplicates(node_t *root) {
	// Hash table to track seen numbers
	bool	*hash_table;
	node_t	*curr;
	int		value;
	printf("start hash\n");
	hash_table = (bool *)calloc(HASH_TABLE_SIZE, sizeof(bool));
	if (!hash_table) {
		ft_printf("Error\n");
		exit(1);
	}

	curr = root;
	while (curr) {
		value = curr->x;
		// Compute hash table index
		int index = value - INT_MIN;
		// Check if the value is already in the hash table
		if (hash_table[index]) {
			printf("Error\n");
			free(hash_table);
			exit(1);
		}
		// Mark the value as seen
		hash_table[index] = true;
		curr = curr->next;
	}
	printf("before free dup hash\n");

	// Free the hash table
	free(hash_table);
}

void assign_indices(node_t **root) {
	node_t *curr;
	int *arr;
	int m;
	
	curr = *root;
	arr  = malloc(sizeof(int) * len_stack(*root));
	m = 0;
	while (curr != NULL) {
		arr[m] = curr->x;
		curr = curr->next;
		m++;
	}

	ft_qsort(arr, len_stack(*root), sizeof(int), compare); // Sorting numbers
	
	// Assigning indices based on sorted order
	curr = *root;
	m = 0;
	while (curr != NULL) {
		// for (int i = 0; i < len_stack(*root); i++) 
		while (m < len_stack(*root)) {
			if (curr->x == arr[m]) {
				curr->index = m;
				break;
			}
			m++;
		}
		curr = curr->next;
	}

	free(arr);
}