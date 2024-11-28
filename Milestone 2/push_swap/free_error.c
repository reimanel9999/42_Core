/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:58 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/20 17:06:06 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(node_t **root) {
	// node_t*	temp;
	
	while(*root != NULL) {
		node_t*	temp;
		temp = *root;
		*root = (*root)->next;
		free(temp);
	}
}

// int duplicates(node_t** root, int value) {
// 	node_t* curr;

// 	curr = *root;
// 	while (curr != NULL) {
// 		if (curr->x == value)
// 			return 1;
// 		curr = curr->next;
// 	}
// 	return (0);
// }