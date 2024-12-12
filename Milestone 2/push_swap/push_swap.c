/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarvalh <mcarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:40:16 by mcarvalh          #+#    #+#             */
/*   Updated: 2024/12/12 21:13:55 by mcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	node_t	*stack_a;
	node_t	*stack_b;
	int		m;
	int		error;

	stack_a = NULL;
	stack_b = NULL;
	m = 1;
	error = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (error_handler(argc));
	while (argv[m])
		start_stack(argv[m++], &stack_a, &error);
	if (error || !check_duplicates(stack_a))
		error_handler(0);
	else
	{
		assign_indices(&stack_a);
		process(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

void	process(node_t **stack_a, node_t **stack_b)
{
	if (!sort_stack(*stack_a))
	{
		if (len_stack(*stack_a) == 2)
			sort_two(stack_a);
		else if (len_stack(*stack_a) <= 5)
			sort_five(stack_a, stack_b);
		else
			sort_big(stack_a, stack_b);
	}
}
