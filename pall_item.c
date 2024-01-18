#include "monty.h"

/**
 * monty_pall_opcode - prints all the values on the stack
 * @head_node: head pointer of the stack
 * @line_no: monty bytecode-file line number
 */
void monty_pall_opcode(stack_t **head_node, unsigned int line_no)
{
	stack_t *temp_node;
	(void)line_no;

	if (*head_node == NULL)
	{
		return;
	}

	else
	{
		temp_node = *head_node;

		while (temp_node != NULL)
		{
			printf("%d", temp_node->n);
			temp_node = temp_node->next;
		}
	}
}
