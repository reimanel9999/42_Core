
#include "push_swap.h"

void	insert_node(node_t** root, int value) {
	node_t* new_node;
	new_node = malloc(sizeof(int));
	if (new_node == NULL)
		exit (1);
	new_node->x = value;
	new_node->next = NULL; 
}

void	create_list(char** argv) {
	// create head of stack
	node_t* head;
	head = NULL;
	head = malloc(sizeof(node_t));
	head->x = *argv[1];
	head->next = NULL;

	//iterate over argc and add to the end 
	int	n;
	n = 2;
	while (*argv[n]) {
		push(head, argv[n]);
		n++;
	}
	free(head);
}

void	push(node_t *node, int value) {

	/*Add an element to the end of the list 
	
	node - any node in the list
	value - value to add at the end of the list
	*/ 

	// Let´s use current to iterate over the list
	node_t* current;
	current = node;
	// while next isn`t null lets keep advancing
	while (current->next != NULL) {

		/* next_node = current->next;
		current = next_node; */
		current = current->next;
	}

	// we have reached the null aka the end
	// let`s create the new node redefining the end
	node_t *end_node;
	end_node = malloc(sizeof(node_t));
	current->next = end_node;
	end_node->next = NULL;
	end_node->x = value;
}