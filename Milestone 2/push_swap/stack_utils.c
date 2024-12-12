/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:02:50 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 21:13:56 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(node_t *root)
{
	int		m;
	node_t	*temp;

	m = 0;
	temp = root;
	while (temp != NULL)
	{
		m++;
		temp = temp->next;
	}
	return (m);
}

void	start_stack(char *str, node_t **root, int *error)
{
	int	index;
	int	num;

	index = 0;
	num = 0;
	while (str[index])
	{
		num = ft_atoi(str, &index, error);
		if (str[index] != ' ' && str[index] != '\0')
		{
			*error = 1;
			return ;
		}
		insert_end(root, num);
	}
}

void	insert_end(node_t **root, int value)
{
	node_t	*new_node;
	node_t	*curr;

	new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL)
		return ;
	new_node->x = value;
	new_node->next = NULL;
	if (*root == NULL)
	{
		*root = new_node; 
		return ;
	}
	curr = *root;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	assign_indices(node_t **root)
{
	node_t	*curr;
	int		*arr;
	int		m;
	int		stack_len;

	stack_len = len_stack(*root);
	curr = *root;
	arr = malloc(sizeof(int) * stack_len);
	m = 0;
	while (curr != NULL)
	{
		arr[m] = curr->x;
		curr = curr->next;
		m++;
	}
	ft_qsort(arr, stack_len, sizeof(int), compare);
	indices(root, arr, stack_len);
	free(arr);
}

void	indices(node_t **root, int *arr, int len)
{
	node_t	*curr;
	int		m;

	m = 0;
	curr = *root;
	while (curr != NULL)
	{
		while (m < len)
		{
			if (curr->x == arr[m])
			{
				curr->index = m;
				m = 0;
				break ;
			}
			m++;
		}
		curr = curr->next;
	}
}

bool	sort_stack(node_t *root)
{
	if (!root)
		return (1);
	while (root->next)
	{
		if (root->x > root->next->x)
			return (false);
		root = root->next;
	}
	return (true);
}

int	min(node_t *stack)
{
	int	min_val;

	if (!stack)
		return (INT_MAX);
	min_val = stack->index;
	while (stack)
	{
		if (stack->index < min_val)
			min_val = stack->index;
		stack = stack->next;
	}
	return (min_val);
}

int	max(node_t *stack)
{
	int	max_val;

	if (!stack)
		return (INT_MIN);
	max_val = stack->index;
	while (stack)
	{
		if (stack->index > max_val)
			max_val = stack->index;
		stack = stack->next;
	}
	return (max_val);
}
