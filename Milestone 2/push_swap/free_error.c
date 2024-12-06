/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:58 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/05 10:51:42 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to check duplicates using a hash table
void check_duplicates(node_t *root) {
	// Hash table to track seen numbers
	bool	*hash_table;
	node_t	*curr;
	int		value;
	
	hash_table = (bool *)calloc(HASH_TABLE_SIZE, sizeof(bool));
	if (!hash_table) {
		ft_printf("Error\n");
		exit(1);
	}

	curr = root;
	while (curr) {
		value = curr->x;
		// Compute hash table index
		int index = ((value % HASH_TABLE_SIZE) + HASH_TABLE_SIZE) % HASH_TABLE_SIZE;
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
	// Free the hash table
	free(hash_table);
}

void	free_stack(node_t **root) {
	// node_t*	temp;
	
	while(*root != NULL) {
		node_t*	temp;
		temp = *root;
		*root = (*root)->next;
		free(temp);
	}
}