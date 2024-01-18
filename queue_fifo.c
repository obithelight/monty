#include "monty.h"

/**
 * add_node_to_queue - adds a node to queue
 * @front: head of queue
 * @data: integer value
 */
void add_node_to_queue(stack_t **front, int data)
{
	stack_t *freshnode, *link;

	link = *front;
	freshnode = malloc(sizeof(stack_t));
	if (freshnode == NULL)
		printf("Error\n");

	freshnode->n = data;
	freshnode->next = NULL;

	if (link)
	{
		while (link->next)
			link = link->next;
	}
	if (!link)
	{
		*front = freshnode;
		freshnode->prev = NULL;
	}
	else
	{
		link->next = freshnode;
		freshnode->prev = link;
	}
}

/**
 * top_queue - prints the top of queue
 * @coin: head pointer
 * @num: line_number
 */
void top_queue(stack_t *coin, unsigned int num)
{
	(void)coin;
	(void)num;
	coach.status = 1;
}
