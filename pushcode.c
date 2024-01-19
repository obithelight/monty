#include "monty.h"

/**
 * monty_push_opcode - pushes an element to the stack
 * @head_node: head pointer of the stack
 * @line_no: monty bytecode-file line number
 */
void monty_push_opcode(stack_t **head_node, unsigned int line_no)
{
	stack_t *link;

	(void)line_no;
	if (!head_node)
		return;

	link = malloc(sizeof(stack_t));
	if (link)
	{
		fprintf(stderr, "L%d: usage: push integer", line_no);
		freelist(link);
		exit(EXIT_FAILURE);
	}
	link->n = line_no;

	if (*head_node)
	{
		link->next = *head_node;
		(*head_node)->prev = link;
	}
	else
		link->next = NULL;
	link->prev = NULL;
	*head_node = link;
}
