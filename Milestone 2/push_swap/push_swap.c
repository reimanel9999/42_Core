/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:16 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/06 16:08:34 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int main(int argc, char *argv[]) {
	node_t *stack_a;
	node_t *stack_b;
	int		m;

	stack_a = NULL;
	stack_b = NULL;
	m = 1;
	// Parse input and build stack
	if (argc < 2 || (argc == 2 && !argv[1][0])) {
		printf("Error\n");
		return 1;
	}
	while (argv[m]) {
		start_stack(argv[m], &stack_a);
		m++;
	}
	check_duplicates(stack_a);
	assign_indices(&stack_a);
	ft_printf("after indices + dup\n");

	// Sorting the stack
	if (!sort_stack(stack_a)) {
		if (len_stack(stack_a) <= 10) {
			// printf("stack a smaller than 6; max = %d\n", INT_MAX);
			insertion_sort(&stack_a, &stack_b);  // If small enough, use insertion sort
		} else {
			printf("big stack\n");
			chunk_partition(&stack_a, &stack_b); // Partition into chunks
			printf("chunk partition good\n");
			// insert_into_stack_b_sorted(&stack_a, &stack_b); // Sort stack_b dynamically
			printf("sorted into stack a good\n");
			// sort_stack_a(&stack_a, &stack_b); // Reassemble stack_a in ascending order
	}
	}
	if (!sort_stack(stack_a))
		ft_printf("Not sorted\n");
	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
