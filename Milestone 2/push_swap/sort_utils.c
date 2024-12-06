/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:00:56 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/05 16:57:04 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk_size(int total) {
	if (total <= 10)
		return (total);
	
	int	size;
	size = 0;
	while (total * size > size * size) {
		if (total <= size * size)
			return (size);
		size++;
	}
	if (size < 10)
		return (10);
	if (size > total / 2)
		size = total / 2;
	return (size);
}

int has_elements_in_range(node_t *stack, int start, int end) {
	while (stack) {
        if (stack->index >= start && stack->index < end)
            return 1;
        stack = stack->next;
    }
    return 0;
}

int find_closest_index_position(node_t *stack, int start, int end) {
	int position = 0;
	int closest_position = -1;
	int closest_distance = INT_MAX;
	int len = len_stack(stack);

	node_t *curr = stack;
	while (curr) {
		if (curr->index >= start && curr->index < end) {
			int distance;
			if (position <= (len / 2)) {
				distance = position;
			} else {
				distance = len - position;
			}

			if (distance < closest_distance) {
				closest_distance = distance;
				closest_position = position;
			}
		}
		curr = curr->next;
		position++;
	}

	return closest_position;
}

int find_max_index_position(node_t *stack_b) {
    int position = 0;
    int max_position = 0;
    int max_index = INT_MIN;

    node_t *current = stack_b;
    while (current) {
        if (current->index > max_index) {
            max_index = current->index;
            max_position = position;
        }
        current = current->next;
        position++;
    }
    return max_position;
}

int find_max_index(node_t *stack) {
    int max_index = stack->index;
    node_t *curr = stack;

    while (curr) {
        if (curr->index > max_index) {
            max_index = curr->index;
        }
        curr = curr->next;
    }
    return max_index;
}

int find_position(node_t *stack, int target_index) {
    int position;
    node_t *curr;
    
	position = 0;
	curr = stack;
	while (curr && curr->index != target_index) {
        position++;
        curr = curr->next;
    }
    return position;
}
