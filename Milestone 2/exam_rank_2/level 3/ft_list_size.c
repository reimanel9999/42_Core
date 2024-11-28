#include <stdio.h>
#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                t_list;

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == NULL)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

// Helper function to create a new node
t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int main()
{
    // Create a linked list: node1 -> node2 -> node3
    t_list *node1 = create_node("Data1");
    t_list *node2 = create_node("Data2");
    t_list *node3 = create_node("Data3");

    node1->next = node2;
    node2->next = node3;

    // Calculate the size of the linked list
    int size = ft_list_size(node1);
    printf("The size of the linked list is: %d\n", size);

    // Free the linked list
    free(node1);
    free(node2);
    free(node3);

    return 0;
}

