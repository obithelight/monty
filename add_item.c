#include "monty.h"

/**
 * add_item - adds the top two elements of the stack
 * @top: pointer to the top element
 * @item: line number of opcode
 */
void add_item(stack_t **top, unsigned int item)
{
	int output = 0;

	if ((*top) == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", item);
		freelist(*top);
		exit(EXIT_FAILURE);
	}

	output = (*top)->n;

	pop_item(&*top, item);
	(*top)->n += output;
}
