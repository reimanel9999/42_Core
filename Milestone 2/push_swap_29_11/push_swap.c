/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:16 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/11/20 17:06:05 by mcarvalh         ###   ########.fr       */
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
	// printf("now dup\n");
	// check_duplicates(stack_a);
	// printf("just dup\n");
	assign_indices(&stack_a);
	printf("dup + indices min = %d\n", INT_MIN);
	// Sorting the stack
	if (len_stack(stack_a) <= 5) {
		printf("stack a smaller than 6; max = %d\n", INT_MAX);
		// insertion_sort(&stack_a);  // If small enough, use insertion sort
	} else {
		printf("stack a bigger than 6\n");
		// chunk_partition(&stack_a, &stack_b);  // Partition into chunks
	}

	free_stack(&stack_a);
	free_stack(&stack_b);

	return 0;
}
