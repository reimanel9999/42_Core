/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:34:58 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 20:59:29 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(node_t *root)
{
	bool	*hash_table;
	node_t	*curr;
	int		value;
	int		index;

	hash_table = (bool *)calloc(HASH_TABLE_SIZE, sizeof(bool));
	if (!hash_table)
		return (0);
	curr = root;
	while (curr)
	{
		value = curr->x;
		index = ((value % HASH_TABLE_SIZE) + HASH_TABLE_SIZE) % HASH_TABLE_SIZE;
		if (hash_table[index])
		{
			free(hash_table);
			return (0);
		}
		hash_table[index] = true;
		curr = curr->next;
	}
	free(hash_table);
	return (1);
}

void	free_stack(node_t **root)
{
	node_t	*temp;

	while (*root != NULL)
	{
		temp = *root;
		*root = (*root)->next;
		free(temp);
	}
}

int	error_handler(int m)
{
	if (m == 1)
		return (1);
	printf("Error\n");
	return (1);
}
