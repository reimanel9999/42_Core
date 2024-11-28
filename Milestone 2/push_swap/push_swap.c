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

int	main(int argc, char* argv[]) {
	node_t*	stack_a;
	// node_t*	stack_b;
	
	stack_a = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0])) {
		ft_printf("Error\n");
	 	return (1);
	}
	else if (argc >= 2) {
		int	m;
		
		m = 1;
		while (m < argc) { 
			start_stack(argv[m], &stack_a);
			m++;
		}
	}
	if (!sort_stack(stack_a)) {
		if (len_stack(stack_a) == 2)
			sa(&stack_a);
		else if(len_stack(stack_a) == 3)
			sort_three(&stack_a);
	}
	
// 		print out nodes:
	free_stack(&stack_a);
    //     while (temp != NULL) {
    //         printf("%d -> ", temp->x);
    //         temp = temp->next;
	// 	}
	// 	printf("NULL\n");
	
	return (0);
}