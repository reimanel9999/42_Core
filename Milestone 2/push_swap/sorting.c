/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:41:24 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/06 16:07:54 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(node_t* root) {
	int	m;
	node_t* temp;

	m = 0;
	temp = root;
	while (temp != NULL) {
		m++;
		temp = temp->next;
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
		rra(root);
	else if (first < second && first < third) {
		rra(root);
		sa(root);
	}
}

void chunk_partition(node_t **stack_a, node_t **stack_b) {
	int	stack_len = len_stack(*stack_a);
	int total_elements = stack_len;
	int chunk_size = calculate_chunk_size(total_elements);  // Adjust chunk size dynamically
	int chunk_start = 0;
	int chunk_end = chunk_size;
	ft_printf("Starting chunk partition...\n");
	while (chunk_start < total_elements) {
		// Push elements in the current chunk range to stack_b
		ft_printf("Before elements in range, stack_len: %d start: %d end: %d\n", total_elements, chunk_start, chunk_end);
		while (has_elements_in_range(*stack_a, chunk_start, chunk_end)) {
			int position = find_closest_index_position(*stack_a, chunk_start, chunk_end);
			if (position == -1) {
				ft_printf("position error\n");
				return ;
			}
			if (position < (stack_len / 2)) {
				// Rotate until the element is at the top
				while (position--) {
					ra(stack_a);
				}
			} else {
				// Reverse rotate until the element is at the top
				while (position++ < stack_len) {
					rra(stack_a);
				}
			}

			// Push the element to stack_b
			pb(stack_a, stack_b);
			if ((*stack_b)->next && (*stack_b)->index < (*stack_b)->next->index)
				sb(stack_b);
		}

		// Update the chunk range
		chunk_start = chunk_end;
		chunk_end += chunk_size; 
		if (chunk_end > total_elements) {
			chunk_end = total_elements;
		}
	}
	ft_printf("After chunk_partition: stack_a size = %d, stack_b size = %d\n", len_stack(*stack_a), len_stack(*stack_b));
}

void insert_into_stack_b_sorted(node_t **stack_a, node_t **stack_b) {
	while (*stack_b) {
		// Find the position in stack_b to move the largest element to stack_a
		int max_index_position = find_max_index_position(*stack_b);
		int stack_b_len = len_stack(*stack_b);

		// Rotate stack_b to bring the max index element to the top
		if (max_index_position <= stack_b_len / 2) {
			while (max_index_position--) {
				rb(stack_b);
			}
		} else {
			while (max_index_position++ < stack_b_len) {
				rrb(stack_b);
			}
		}

		// Push the top element of stack_b to stack_a
		pa(stack_a, stack_b);
		// if ((*stack_a)->next && (*stack_a)->index < (*stack_a)->next->index)
		// 	sa(stack_a);
	}
}


// void insert_into_stack_b_sorted(node_t **stack_a, node_t **stack_b) {
// 	while (*stack_b) {
// 		node_t *current_b = *stack_b;  // Get the first element of stack_b
// 		int position = find_insert_position(*stack_a, current_b->index);  // Find the position in stack_a
		
// 		// Move the element to the correct position in stack_a
// 		if (position < (len_stack(*stack_a) / 2)) {
// 			while (position--) {
// 				ra(stack_a);  // Rotate stack_a
// 			}
// 		} else {
// 			while (position++ < len_stack(*stack_a)) {
// 				rra(stack_a);  // Reverse rotate stack_a
// 			}
// 		}
		
// 		// Push the element from stack_b to stack_a
// 		pb(stack_b, stack_a);
// 	}
// }

// void sort_stack_a(node_t **stack_a, node_t **stack_b) {
//     while (*stack_b) {
//         // Find the element in stack_b with the maximum index
//         int max_index = find_max_index(*stack_b);
//         int position = find_position(*stack_b, max_index);

//         // Rotate stack_b to bring the max_index to the top
//         if (position <= len_stack(*stack_b) / 2) {
//             while (position-- > 0) {
//                 rb(stack_b);
//                 ft_printf("rb\n");
//             }
//         } else {
//             while (position++ < len_stack(*stack_b)) {
//                 rrb(stack_b);
//                 ft_printf("rrb\n");
//             }
//         }

//         // Push the largest element from stack_b to stack_a
//         pa(stack_b, stack_a);
//         ft_printf("pa\n");
//     }
// }

// vamos ver se funciona para pequenos

void insertion_sort(node_t **stack_a, node_t **stack_b) {
    int count = 0;

    // Push elements to stack_b until 3 elements are left in stack_a
    while (count < 7) {  // Keep only 3 elements in stack_a
        if ((*stack_a)->index < 7) {
            pb(stack_a, stack_b);  // Push smaller elements to stack_b
            count++;
        } else {
            ra(stack_a);  // Rotate stack_a to preserve larger elements
        }
    }

    // Sort the remaining 3 elements in stack_a
    sort_three(stack_a);

    // Sort elements in stack_b and push them back to stack_a
    while (*stack_b) {
        int target_index = (*stack_b)->index;

        // Rotate stack_b to bring the smallest element to the top
        if (target_index < (*stack_b)->index) {
            while (*stack_b && (*stack_b)->index != target_index) {
                rb(stack_b);  // Rotate stack_b upwards
            }
        } else {
            while (*stack_b && (*stack_b)->index != target_index) {
                rrb(stack_b);  // Reverse rotate stack_b
            }
        }

        pa(stack_a, stack_b);  // Push the smallest element to stack_a
    }
}




// void insertion_sort_push_swap(node_t **stack_a, node_t **stack_b) {
//     node_t *sorted = NULL; // Sorted stack will be built here
//     node_t *curr = *stack_a;
//     node_t *next;

//     // Process each element in stack_a
//     while (curr != NULL) {
//         next = curr->next;
        
//         // Insert current element in the stack_b portion by index
//         if ((*stack_b)->index >= curr->index) {
//             pb(stack_a, &stack_b);  // Move current element to stack_b
//         } else {
//             // If the element is larger than the top of sorted stack, rotate sorted
//             while (stack_b && stack_b->next && stack_b->index < curr->index) {
//                 ra(&stack_b);  // Rotate the stack_b stack
//             }
//             pb(stack_a, &stack_b);  // Push back to stack_b
//         }
        
//         curr = next;  // Move to the next element in stack_a
//     }

//     // Move elements from stack_b back to stack_a to restore the sorted order
//     while (stack_b) {
//         pa(stack_a, &stack_b);  // Push elements from stack_b to stack_a
//     }
// }