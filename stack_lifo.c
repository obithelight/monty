#include "monty.h"

/**
 * add_node_to_stack - add node to the head stack
 * @front: head of the stack
 * @data: new_value
 */
void add_node_to_stack(stack_t **front, int data)
{

	stack_t *freshnode, *link;

	link = *front;
	freshnode = malloc(sizeof(stack_t));
	if (freshnode == NULL)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (link)
		link->prev = freshnode;
	freshnode->n = data;
	freshnode->next = *front;
	freshnode->prev = NULL;
	*front = freshnode;
}

/**
 * top_stack - prints the top of stack
 * @coin: head pointer
 * @num: line_number
 */
void top_stack(stack_t *coin, unsigned int num)
{
	(void)coin;
	(void)num;
	coach.status = 0;
}
